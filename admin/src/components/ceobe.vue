<template>
    <div class="relative">
        <div @click="ceobePlay"
            class="grid absolute bottom-0 -right-[3%] w-[330px] h-64 cursor-pointer overflow-hidden">
            <div class="absolute place-self-center top-0 z-10" :class="ceobeSwitch ? 'text-black' : 'text-white'">
                {{  ceobeSwitch ? '小刻关灯' : '小刻开灯'  }}
            </div>
            <div class="w-[500px] h-[550px] absolute place-self-center">
                <video ref="ceobe" width="500">
                    <source src="@/assets/CEOBE.webm" type="video/webm">
                </video>
            </div>
        </div>
    </div>
</template>
    
<script setup lang='ts'>
import { ceobeSwitchStore } from '@/stores/ceobeSwitchStore';
import throttle from '@/utils/throttle';
import { storeToRefs } from 'pinia';
import { ref, type Ref } from 'vue';

const { ceobeSwitch } = storeToRefs(ceobeSwitchStore());

const ceobe: Ref<HTMLVideoElement | null> = ref(null);

const ceobePlay = throttle(() => {
    ceobe.value?.play();
    setTimeout(() => {
        if (ceobeSwitch.value) {
            console.log('小刻关灯');
        } else {
            console.log('小刻开灯');
        }
        ceobeSwitch.value = !ceobeSwitch.value;
    }, 1050)
}, 1929)
// 1.929
</script>
    
<style>
</style>