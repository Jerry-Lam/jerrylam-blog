import { createRouter, createWebHistory, type RouteRecordRaw } from 'vue-router'

import LoadingComponent from '../views/LoadingComponent.vue'
import ErrorComponent from '../views/ErrorComponent.vue'

const UserDetails = () =>
  Promise.resolve({
    
  })

const routes: Array<RouteRecordRaw> = [
  {
    path: "/",
    name: "Login",
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
