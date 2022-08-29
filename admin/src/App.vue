<template>
  <div :class="ceobeSwitch ? '' : 'dark'">
    <div class="dark:bg-slate-800 bg-slate-100">
      <div class="w-screen h-screen overflow-hidden">
        <div class="relative w-screen h-screen">
          <transition>
            <div class="absolute z-10" v-show="sakanaLoading">
              <sakana></sakana>
            </div>
          </transition>
          <div v-show="!sakanaLoading">
            <router-view></router-view>
          </div>
          <button class="shadow" @click="toPage('Login')">login</button>
          <button class="shadow ml-2.5" @click="toPage('Reg')">reg</button>
        </div>
        <ceobe></ceobe>
      </div>
    </div>
  </div>

</template>

<script setup lang='ts'>
import { storeToRefs } from 'pinia';
import { useRouter } from 'vue-router';
import sakana from './components/sakana.vue';

import Ceobe from './components/ceobe.vue';
import { sakanaLoadingStore } from './stores/sakanaLoadingStore';
import { ceobeSwitchStore } from './stores/ceobeSwitchStore';

const { sakanaLoading } = storeToRefs(sakanaLoadingStore());

const { ceobeSwitch } = storeToRefs(ceobeSwitchStore());

const router = useRouter();

const toPage = (url: string) => {
  router.push({
    name: url
  })
}

</script>
  
<style lang="postcss" scoped>
.v-enter-active,
.v-leave-active {
  transition: opacity 1s ease;
}

.v-enter-from,
.v-leave-to {
  opacity: 0;
}
</style>