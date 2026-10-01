(async () => {
    const arr = [
        "#heart-button",
        "#like-button",
        "#applause-button",
        "#laugh-button",
        "#surprised-button"
    ];
    for (let i = 0; i < 100; i++) {
        for (let i = 0; i < 10; i++) {
            for (let i = 0; i < 5; i++) {
                document.querySelector('#reaction-menu-button').click();
                document.querySelector(arr[i]).click();
            }
        }
        await new Promise((resolve, reject) => {
            setTimeout(() => {
                resolve();
            }, 5000);
        });
    }
})();