<template>
  <div class="a relative">
    <div class="b absolute top-[25px] left-[25px] z-10"></div>
    <div class="c absolute top-[25px] left-[25px]"></div>
  </div>
  <div>
    <button class="shadow" @click="toPage('Login')">login</button>
    <button class="shadow ml-2.5" @click="toPage('Reg')">reg</button>
  </div>
  <div class="relative">
    <transition>
      <div class="absolute z-10" v-show="loading">
        <loading></loading>
      </div>
    </transition>
    <div class="absolute" v-show="!loading">
      <router-view></router-view>
    </div>
  </div>
  <div>
    <img src="@/assets/prpr.gif" alt="" srcset="">
    <img src="@/assets/sax.gif" alt="">
  </div>
</template>

<script setup lang='ts'>
import { storeToRefs } from 'pinia';
import { useRouter } from 'vue-router'
import Loading from './components/loading.vue';

import { useCounterStore } from './stores/counter';
const load = useCounterStore();
const { loading } = storeToRefs(load);

const router = useRouter();


const toPage = (url: string) => {
  router.push({
    name: url
  })
}

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
  transition: opacity 0.5s ease;
}

.v-enter-from,
.v-leave-to {
  opacity: 0;
}
</style>