import axios from "axios";

const Service = axios.create({
    baseURL: import.meta.env.VITE_BASE_API,
    headers: {
        "Content-type": "application/json;charset=UTF-8"
    },
    timeout: 50000
})

export default Service