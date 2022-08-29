import { sakanaLoadingStore } from '@/stores/sakanaLoadingStore';
import { createRouter, createWebHistory, type RouteRecordRaw } from 'vue-router'

const routes: Array<RouteRecordRaw> = [
  {
    path: "/",
    name: "Login",
    beforeEnter(to, from) {
      const sakanaLoading = sakanaLoadingStore();
      sakanaLoading.openLoading();
    },
    component: () => import('../views/Login.vue')
  },
  {
    path: "/reg",
    name: "Reg",
    component: () => import('../views/Reg.vue')
  }
]

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes
})

export default router
function useStore() {
  throw new Error('Function not implemented.')
}

