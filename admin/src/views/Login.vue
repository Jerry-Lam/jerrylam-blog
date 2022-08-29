<template>
<div class="w-80 h-80 bg-cyan-600">
  login
</div>
</template>
    
<script setup lang='ts'>
import { sakanaLoadingStore } from '@/stores/sakanaLoadingStore';
import { onMounted } from 'vue';

const sakanaLoading = sakanaLoadingStore();

onMounted(() => {
  // setTimeout(() => {
    
  //   // console.log(load.loading)
  // }, 2000)
  sakanaLoading.closeLoading();
})
</script>
    
<style>
    
</style>