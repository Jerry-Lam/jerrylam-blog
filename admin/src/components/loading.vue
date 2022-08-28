<template>
	<div
		class="relative w-screen h-screen bg-[url('@/assets/sea.jpg')] bg-cover flex flex-col justify-center overflow-hidden">
		<div ref="sakana">
			<img class="animate-bounce w-80 h-80 transform-gpu" src="@/assets/sakana.png" alt="sakana">
		</div>
		<!-- <div class="w-[90vw] h-28 bg-slate-300 rounded overflow-hidden">
			<div ref="progress" class="w-0 progress h-full flex justify-end items-center bg-[cornflowerblue] rounded">
			</div>
		</div> -->
	</div>
	<div class="absolute bottom-0 w-screen flex justify-center text-6xl">
		<div>
			100%
		</div>
	</div>
</template>
    
<script setup lang='ts'>
import { useCounterStore } from '@/stores/counter';
import { onMounted, ref, watchEffect } from 'vue';
const load = useCounterStore();
let sakana = ref<HTMLElement>();
// let progress = ref<HTMLElement>();
let speed = ref<number>(0);
// let speedbar = ref<number>(0);
let timer = ref<number>(0);
// let progressNumber = ref<number>(0);


const startLoading = () => {
	let dom = sakana.value as HTMLElement;
	// let progressBar = progress.value as HTMLElement;
	speed.value = 0;
	// speedbar.value = 0;
	timer.value = window.requestAnimationFrame(function fn() {
		if (speed.value < 70) {
			speed.value += 1;
			dom.style.transform = `translateX(${speed.value}%)`;
			timer.value = window.requestAnimationFrame(fn)
		} else {
			speed.value = 0;
			window.cancelAnimationFrame(timer.value)
		}
	})
	// progressNumber.value = window.requestAnimationFrame(function fn() {
	// 	if (speedbar.value < 90) {
	// 		speedbar.value += 1;
	// 		progressBar.style.width = speedbar.value + '%';
	// 		progressNumber.value = window.requestAnimationFrame(fn)
	// 	} else {
	// 		speedbar.value = 0;
	// 		window.cancelAnimationFrame(progressNumber.value)
	// 	}
	// })
}

const endLoading = () => {
	let dom = sakana.value as HTMLElement;
	// let progressBar = progress.value as HTMLElement;
	window.requestAnimationFrame(() => {
		speed.value = 83;
		dom.style.transform = `translateX(${speed.value}%)`;
		// speedbar.value = 100;
		// progressBar.style.width = speedbar.value + '%';
	})
}

onMounted(() => {
	startLoading();
})

watchEffect(() => {
	if (!load.loading) {
		endLoading();
	}
})


</script>
    
<style lang="postcss" scoped>
.progress {
	background-image: linear-gradient(45deg, rgba(255, 255, 255, .15) 25%, transparent 25%, transparent 50%, rgba(255, 255, 255, .15) 50%, rgba(255, 255, 255, .15) 75%, transparent 75%, transparent);
	background-size: 40px 40px;
	/* transition: width .6s ease; */
}
</style>
<!-- 83就满了 -->
<!-- class="translate-x-3/4" -->