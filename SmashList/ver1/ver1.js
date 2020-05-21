characters = [
'Characters/1.png',
'Characters/2.png',
'Characters/3.png',
'Characters/4.png',
'Characters/5.png',
'Characters/6.png',
'Characters/7.png',
'Characters/8.png',
'Characters/9.png',
'Characters/10.png',
'Characters/11.png',
'Characters/12.png',
'Characters/13.png',
'Characters/14.png',
'Characters/15.png',
'Characters/16.png',
'Characters/17.png',
'Characters/18.png',
'Characters/19.png',
'Characters/20.png',
'Characters/21.png',
'Characters/22.png',
'Characters/23.png',
'Characters/24.png',
'Characters/25.png',
'Characters/26.png',
'Characters/27.png',
'Characters/28.png',
'Characters/29.png',
'Characters/30.png',
'Characters/31.png',
'Characters/32.png',
'Characters/33.png',
'Characters/34.png',
'Characters/35.png',
'Characters/36.png',
'Characters/37.png',
'Characters/38.png',
'Characters/39.png',
'Characters/40.png',
'Characters/41.png',
'Characters/42.png',
'Characters/43.png',
'Characters/44.png',
'Characters/45.png',
'Characters/46.png',
'Characters/47.png',
'Characters/48.png',
'Characters/49.png',
'Characters/50.png',
'Characters/51.png',
'Characters/52.png',
'Characters/53.png',
'Characters/54.png',
'Characters/55.png',
'Characters/56.png',
'Characters/57.png',
'Characters/58.png',
'Characters/59.png',
'Characters/60.png',
'Characters/61.png',
'Characters/62.png',
'Characters/63.png',
'Characters/64.png',
'Characters/65.png',
'Characters/66.png',
'Characters/67.png',
'Characters/68.png',
'Characters/69.png',
'Characters/70.png',
'Characters/71.png',
'Characters/72.png',
'Characters/73.png',
'Characters/74.png',
'Characters/75.png',
'Characters/76.png',
'Characters/77.png',
'Characters/78.png',
'Characters/79.png'
];
var temp = 0;
var curImg1 = 1;
var curImg2 = 0;
function changeImg(i){ 
	do{
		temp = Math.floor(Math.random()*characters.length); 
	}while(temp==curImg1 || temp==curImg2);
	i.src = characters[temp];
	if(i.id == "img1"){
		curImg1 = temp;
	}else{
		curImg2 = temp;
	}
}
function changeImage(){
	changeImg(img1);
	changeImg(img2);
}

