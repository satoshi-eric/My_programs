const game = {
    divs: [],
    createDivs: function() {
        const section = document.querySelector(".container > section") 
        let div = []
        
        for (let i=0; i<200; i++) {
            div.push(document.createElement("div"))
            section.appendChild(div[i])
        }
    },
    classDefine: function() {
        const divs = document.querySelectorAll(".container > section div")
        divs.forEach((value) => {
            value.classList.add("squares")
        })
    },
    classRemove: function() {
        const divs = document.querySelectorAll(".container > section div")
        divs.forEach((value) => {
            value.classList.remove("squares")
        })
    }
}