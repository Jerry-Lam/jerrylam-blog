import { sakanaLoadingStore } from '@/stores/sakanaLoadingStore';
import { createRouter, createWebHistory, type RouteRecordRaw } from 'vue-router'

const routes: Array<RouteRecordRaw> = [
  {
    path: "/",
    name: "Dashboard",
    component: () => import('../views/Dashboard.vue')
  },
  {
    path: "/login",
    name: "Login",
    meta: { isPublic: true },
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

router.beforeEach((to, from, next) => {
  if (!to.meta.isPublic && !localStorage.token)
    next('/login');

    
  next();
})

export default router
// function useStore() {
//   throw new Error('Function not implemented.')
// }

