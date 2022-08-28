<template>
  <div :class="ceobeSwitch ? '' : 'dark'">
    <div class="dark:bg-slate-800 bg-slate-100">
      <div class="w-screen h-screen">
        <div class="relative">
          <transition>
            <div class="absolute z-10" v-show="loading">
              <loading></loading>
            </div>
          </transition>
          <div v-show="!loading">
            <router-view></router-view>
          </div>
          <button class="shadow" @click="toPage('Login')">login</button>
          <button class="shadow ml-2.5" @click="toPage('Reg')">reg</button>
        </div>
        <!-- <div class="relative">
        <img src="@/assets/prpr.gif" alt="" srcset="">
        <img src="@/assets/sax.gif" alt="">
        <img src="@/assets/sax.gif" alt="">
        <div @click="ceobePlay" class="grid absolute bottom-0 right-0 w-[330px] h-64 overflow-hidden">
          <div class="absolute place-self-center top-0 z-10" :class="ceobeSwitch ? 'text-black' : 'text-white'">
            {{ ceobeSwitch ? '小刻关灯' : '小刻开灯' }}
          </div>
          <div class="w-[500px] h-[550px] absolute place-self-center">
            <video ref="ceobe" width="500" @canplay="getDuration">
              <source src="@/assets/CEOBE.webm" type="video/webm">
            </video>
          </div>
        </div>
      </div> -->
      </div>
    </div>
  </div>

</template>

<script setup lang='ts'>
import { storeToRefs } from 'pinia';
import { onMounted, ref, type Ref } from 'vue';
import { useRouter } from 'vue-router'
import Loading from './components/loading.vue';

import { useCounterStore } from './stores/counter';
import throttle from '@/utils/throttle';

const load = useCounterStore();
const { loading } = storeToRefs(load);

const router = useRouter();

const ceobe: Ref<HTMLVideoElement | null> = ref(null);
let ceobeSwitch: Ref<boolean> = ref(true);

const toPage = (url: string) => {
  router.push({
    name: url
  })
}

onMounted(() => {
  console.log(ceobe.value);
})

const getDuration = () => {
  console.log(ceobe.value?.duration);
}

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
  
<style lang="postcss" scoped>
.a {
  width: 100px;
  height: 100px;
  background-color: green;

  .b {
    width: 50px;
    height: 50px;
    background-color: white;
  }

  .c {
    width: 50px;
    height: 50px;
    background-color: yellow;
  }
}

.v-enter-active,
.v-leave-active {
  transition: opacity 1s ease;
}

.v-enter-from,
.v-leave-to {
  opacity: 0;
}
</style>