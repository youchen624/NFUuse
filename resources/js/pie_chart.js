// 獲取點擊次數，若不存在則初始化
let button1Count = parseInt(localStorage.getItem('button1Count')) || 1;
let button2Count = parseInt(localStorage.getItem('button2Count')) || 1;
let button3Count = parseInt(localStorage.getItem('button3Count')) || 1;

// 初始化圖表
const ctx = document.getElementById('myPieChart').getContext('2d');
const myPieChart = new Chart(ctx, {
    type: 'pie',
    data: {
        labels: ['品項1', '品項2', '品項3'],
        datasets: [{
            data: [button1Count, button2Count, button3Count],
            backgroundColor: ['#36a2eb', '#ff6384', '#ffce56']
        }]
    },
    options: {
        responsive: true,
        maintainAspectRatio: false
    }
});

// 增加按鈕點擊事件
document.getElementById('button1').addEventListener('click', function() {
    button1Count++;
    localStorage.setItem('button1Count', button1Count);
    updateChart();
});

document.getElementById('button2').addEventListener('click', function() {
    button2Count++;
    localStorage.setItem('button2Count', button2Count);
    updateChart();
});

document.getElementById('button3').addEventListener('click', function() {
    button3Count++;
    localStorage.setItem('button3Count', button3Count);
    updateChart();
});

// 減少按鈕點擊事件
document.getElementById('button1Decrease').addEventListener('click', function() {
    if (button1Count > 0) {
        button1Count--;
        localStorage.setItem('button1Count', button1Count);
        updateChart();
    }
});

document.getElementById('button2Decrease').addEventListener('click', function() {
    if (button2Count > 0) {
        button2Count--;
        localStorage.setItem('button2Count', button2Count);
        updateChart();
    }
});

document.getElementById('button3Decrease').addEventListener('click', function() {
    if (button3Count > 0) {
        button3Count--;
        localStorage.setItem('button3Count', button3Count);
        updateChart();
    }
});

// 重置按鈕事件
document.getElementById('resetButton').addEventListener('click', function() {
    // 將所有計數歸零
    button1Count = 1;
    button2Count = 1;
    button3Count = 1;
    // 更新 Local Storage
    localStorage.setItem('button1Count', button1Count);
    localStorage.setItem('button2Count', button2Count);
    localStorage.setItem('button3Count', button3Count);
    // 更新圖表
    updateChart();
});

// 更新圓餅圖
function updateChart() {
    myPieChart.data.datasets[0].data = [button1Count, button2Count, button3Count];
    myPieChart.update(); // 更新圖表
}