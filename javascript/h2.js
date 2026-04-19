const audioEle = document.querySelector('audio');
const cvs = document.querySelector('canvas');
const ctx = cvs.getContext('2d');

function initCvs(){

}

initCvs();

let isInit = false;
let dataArray,analyser;


audioEle.onplay = function(){
    if(isInit){
        return;
    }
    const audCtx = new AudioContext();
    const souce = audCtx.createMediaElementSource(audioEle);
    analyser = audCtx.createAnalyser();
    analyser.fftSize = 512;

    dataArray = new Uint8Array(512/2);//analyser.frequencyBinCount;


    souce.connect(analyser);
    analyser.connect(audCtx.destination);

    isInit = true;
}

function draw(){
    requestAnimationFrame(draw);

    const {width,height} = cvs;
    ctx.clearRect(0,0,width,height);

    if(!isInit){
        return;
    }

    analyser.getByteFrequencyData(dataArray);
    // console.log(dataArray);

    const len = dataArray.length/2;
    const barWidth = width/len;
    ctx.fillStyle = '#000000';
    for(let i=0;i<len;i++){
        const data = dataArray[i];//<256
        const barHeight = data /255*height;
        const x = i*barWidth;
        const y = height - barHeight;
        ctx.fillRect(x,y,barWidth,barHeight);
    }
}

draw();