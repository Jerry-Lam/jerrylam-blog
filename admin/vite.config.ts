import { fileURLToPath, URL } from 'node:url'

import { defineConfig, loadEnv } from 'vite'
import vue from '@vitejs/plugin-vue'
import vueJsx from '@vitejs/plugin-vue-jsx'


// https://vitejs.dev/config/
export default ({ mode }: any) => {
  // console.log(mode, 'mode') //development
  // console.log(typeof (mode))
  // console.log(loadEnv(mode, process.cwd()), 'cwd')
  // console.log(loadEnv(mode, process.cwd()));
  const env = loadEnv(mode, process.cwd())
  // console.log(env.VITE_BASE_API);
  return defineConfig({
    plugins: [vue(), vueJsx()],
    resolve: {
      alias: {
        '@': fileURLToPath(new URL('./src', import.meta.url))
      }
    },
    server: {
      proxy: {
        '/api': {
          target: env.VITE_BASE_API,
          changeOrigin: true,
          rewrite: (path) => path.replace(/^\/api/, '')
        },
      }
    }
  })
}
