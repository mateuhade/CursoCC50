import {
  FaceLandmarker,
  FilesetResolver
} from "https://cdn.jsdelivr.net/npm/@mediapipe/tasks-vision@0.10.35/vision_bundle.mjs";

const BLINK_THRESHOLD = 0.55;
const IMAGE_TITLES = ["phos1", "cinnabar", "phos2", "antarcticite", "phos3", "padpa", "phos4", "ghost", "phos5", "lapis", "phos6", "vent", "phos7"]
const SONG_TITLES = ["Dark Beach - Pastel Ghost", "Exit Music - Radiohead", "Feeling Nothing - Diedlonely", "Give Me Hope - One Heart",
    "How To Disappear Completely - Radiohead", "How To Disappear Into Strings - Radiohead", "Ill Wind - Radiohead", "Insomniac - Memo Boy",
    "Motion Picture Soundtrack- Radiohead", "No Surprises - Radiohead", "Nude - Radiohead", "Sail To The Moon - Radiohead", "Sometimes - alex_g_offline", 
    "Spectre - Radiohead", "Stay Safe - Aurenth", "Street Spirit - Radiohead", "Stuck Inside My Thoughts - Futureville", "Suffocation - Crystal Castles", 
    "True Love Waits - Radiohead", "Unknown Feelings - Novulent", "Videotape - Radiohead"
]

let blinks = 0;
let faceLandmarker;
let lastVideoTime = -1;
let wasBlinking = false;
const userAgent = navigator.userAgent.toLowerCase();
const imageElement = document.getElementById("lotlImage");
const audioElement = document.getElementById("lotlAudio");
const textElement = document.getElementById("audioStatus");

if (userAgent.includes("mozilla")) {
    audioElement.classList = "";
}
audioElement.volume = 0.15;

document.addEventListener("DOMContentLoaded", loadCamera);

async function loadCamera() {
    try {
        const stream = await navigator.mediaDevices.getUserMedia({ video: true });
        const userCamera = document.getElementById("camera");
        userCamera.srcObject = stream;

        userCamera.addEventListener("loadeddata", () => startBlinkDetection(userCamera));
    } catch (error) {
        console.error("Failed to access webcam", error);
        alert("Failed to access camera. Please check permissions.");
    }
}

async function startBlinkDetection(userCamera) {
    const vision = await FilesetResolver.forVisionTasks(
        "https://cdn.jsdelivr.net/npm/@mediapipe/tasks-vision@0.10.35/wasm"
    );

    faceLandmarker = await FaceLandmarker.createFromOptions(vision, {
        baseOptions: {
            modelAssetPath:
                "https://storage.googleapis.com/mediapipe-models/face_landmarker/face_landmarker/float16/1/face_landmarker.task",
            delegate: "GPU"
        },
        outputFaceBlendshapes: true,
        runningMode: "VIDEO",
        numFaces: 1
    });

    predict(userCamera);
}

function predict(userCamera) {
    if (userCamera.currentTime !== lastVideoTime) {
        lastVideoTime = userCamera.currentTime;
        const result = faceLandmarker.detectForVideo(userCamera, performance.now());
        handleBlinkResult(result);
    }
    requestAnimationFrame(() => predict(userCamera));
}

async function handleBlinkResult(result) {
    if (!result.faceBlendshapes || result.faceBlendshapes.length === 0) return;

    const shapes = result.faceBlendshapes[0].categories;
    const leftBlink = shapes.find(s => s.categoryName === "eyeBlinkLeft")?.score ?? 0;
    const rightBlink = shapes.find(s => s.categoryName === "eyeBlinkRight")?.score ?? 0;
    const isBlinking = leftBlink > BLINK_THRESHOLD && rightBlink > BLINK_THRESHOLD;

    if (isBlinking && !wasBlinking) {
        blinks++;
        if (blinks == IMAGE_TITLES.length) {
            blinks = 0;
        }

        imageElement.setAttribute('src', `../static/images/lotl/${IMAGE_TITLES[blinks]}.jpg`);
        audioElement.setAttribute('src', `../static/audios/lotl/${getRandomSong()}.mp3`);
    }
    wasBlinking = isBlinking;   
}

function getRandomSong() {
    let songIndex = Math.floor(Math.random() * SONG_TITLES.length);
    let song = SONG_TITLES[songIndex].replaceAll(" ", "");
    textElement.textContent = `Now Playing: ${SONG_TITLES[songIndex]}`;
    return song;
}