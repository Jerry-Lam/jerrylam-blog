<template>
  <div class="overflow-hidden w-screen h-screen flex flex-col justify-center items-center bg-[url('@/assets/skadi.png')] bg-cover dark:bg-slate-800 dark:bg-none">
    <div class="grid place-items-center text-black dark:text-white">
      <validateInputVue></validateInputVue>
    </div>
  </div>
</template>
    
<script setup lang='ts'>
import { sakanaLoadingStore } from '@/stores/sakanaLoadingStore';
import validateInputVue from '@/components/validateInput.vue';
import { onMounted } from 'vue';

const sakanaLoading = sakanaLoadingStore();

onMounted(() => {
  setTimeout(() => {
    sakanaLoading.closeLoading();
    // console.log(load.loading)
  }, 2000)
  // sakanaLoading.closeLoading();
})
</script>
    
<style>
</style>