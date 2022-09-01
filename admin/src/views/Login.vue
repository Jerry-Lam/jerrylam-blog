<template>
  <div>
    <validateInputVue></validateInputVue>
  </div>
</template>
    
<script setup lang='ts'>
import { sakanaLoadingStore } from '@/stores/sakanaLoadingStore';
import validateInputVue from '@/components/validateInput.vue';
import { onMounted } from 'vue';
import { useRouter } from 'vue-router';

const router = useRouter();

const sakanaLoading = sakanaLoadingStore();

// const toPage = (url: string) => {
//   router.push({
//     name: url
//   })
// }

onMounted(() => {
  // setTimeout(() => {
  //   sakanaLoading.closeLoading();
  //   // console.log(load.loading)
  // }, 2000)
  sakanaLoading.closeLoading();
})
</script>
    
<style>
</style>