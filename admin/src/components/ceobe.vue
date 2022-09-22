<template>
    <div class="relative">
        <div @click="ceobePlay"
            class="grid absolute bottom-0 -right-[3%] w-[330px] h-64 cursor-pointer overflow-hidden">
            <div class="absolute place-self-center top-0 mr-6" :class="ceobeSwitch ? 'text-black' : 'text-white'">
                <!-- {{ ceobeSwitch ? '小刻关灯' : '小刻开灯' }} -->
                <Transition>
                    <svg v-if="ceobeSwitch" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24"
                        stroke-width="1.5" stroke="currentColor" class="w-6 h-6">
                        <path stroke-linecap="round" stroke-linejoin="round"
                            d="M21.752 15.002A9.718 9.718 0 0118 15.75c-5.385 0-9.75-4.365-9.75-9.75 0-1.33.266-2.597.748-3.752A9.753 9.753 0 003 11.25C3 16.635 7.365 21 12.75 21a9.753 9.753 0 009.002-5.998z" />
                    </svg>

                    <!-- <svg v-else="ceobeSwitch" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24"
                        stroke-width="1.5" stroke="currentColor" class="w-6 h-6">
                        <path stroke-linecap="round" stroke-linejoin="round"
                            d="M12 3v2.25m6.364.386l-1.591 1.591M21 12h-2.25m-.386 6.364l-1.591-1.591M12 18.75V21m-4.773-4.227l-1.591 1.591M5.25 12H3m4.227-4.773L5.636 5.636M15.75 12a3.75 3.75 0 11-7.5 0 3.75 3.75 0 017.5 0z" />
                    </svg> -->
                </Transition>
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