<template>
	<div class="w-screen h-screen bg-[url('@/assets/sea.jpg')] bg-cover flex flex-col justify-center overflow-hidden">
		<div ref="sakana">
			<img class="animate-bounce w-80 h-80 transform-gpu" src="@/assets/sakana.png" alt="sakana">
		</div>
		<div class="percent">
			<div class="text-center text-6xl text-white">{{percent + `%`}}</div>
			<div v-if="!done" class="text-center text-white">
				资源加载中
				<span>
					<span v-if="one" class="dot"></span>
					<span v-if="two" class="dot"></span>
					<span v-if="three" class="dot"></span>
					<span v-if="four" class="dot"></span>
				</span>
			</div>
			<div v-else class="text-center text-white">
				加载完成
			</div>
		</div>
	</div>
</template>
    
<script setup lang='ts'>
import { sakanaLoadingStore } from '@/stores/sakanaLoadingStore';
import { storeToRefs } from 'pinia';
import { onMounted, ref, watchEffect } from 'vue';

const { sakanaLoading } = storeToRefs(sakanaLoadingStore());

//控制sakana~加载动画
let sakana = ref<HTMLElement>();
let speed = ref<number>(0);
let timer = ref<number>(0);

//控制加载百分比
let percent = ref<number>(0);
let percentTimer = ref<number>(0);

//控制加载小圆点
let one = ref<boolean>(false);
let two = ref<boolean>(false);
let three = ref<boolean>(false);
let four = ref<boolean>(false);
let dotTimer = ref<boolean>(false);

let done = ref<boolean>(false);

const dot = () => {
	one.value = true;
	setTimeout(() => {
		two.value = true;
	}, 1000)
	setTimeout(() => {
		three.value = true;
	}, 2000)
	setTimeout(() => {
		four.value = true;
	}, 3000)
	setTimeout(() => {
		one.value = false;
		two.value = false;
		three.value = false;
		four.value = false;
		dotTimer.value = true;
	}, 4000)
}


const startLoading = () => {
	dotTimer.value = true;
	setInterval(() => {
		if (dotTimer.value) {
			dotTimer.value = false;
			dot();
		}
	}, 1000);
	let dom = sakana.value as HTMLElement;
	speed.value = 0;
	percent.value = 0;
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
	percentTimer.value = window.requestAnimationFrame(function fn() {
		if (percent.value < 90) {
			percent.value += 1;
			percentTimer.value = window.requestAnimationFrame(fn)
		} else {
			// percent.value = 0;
			window.cancelAnimationFrame(percentTimer.value)
		}
	})
}

const endLoading = () => {
	let dom = sakana.value as HTMLElement;
	window.requestAnimationFrame(() => {
		speed.value = 83;
		percent.value = 100;
		done.value = !done.value;
		dom.style.transform = `translateX(${speed.value}%)`;
	})
}

onMounted(() => {
	startLoading();
})

watchEffect(() => {
	if (!sakanaLoading.value) {
		endLoading();
	}
})


</script>
    
<style lang="postcss" scoped>
@font-face {
	font-family: 'butterfly';
	src: url('@/assets/by_aqqxs.woff2');
}

.percent {
	font-family: butterfly;
}

.dot {
	width: 5px;
	height: 5px;
	margin-left: 3px;
	display: inline-block;
	background-color: white;
}
</style>
<!-- 83就满了 -->
<!-- class="translate-x-3/4" -->