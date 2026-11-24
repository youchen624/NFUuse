using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace prj41343131FileUpload.Controllers
{
    public class MultiFileUploadController : Controller
    {
        // GET: MultiFileUpload
        public ActionResult Index()
        {
            return View();
        }
        // GET: MultiFileUpload

        public ActionResult Create()

        { return View(); }



        [HttpPost]

        public ActionResult Create(HttpPostedFileBase[] photos)

        {

            string fileName = "";

            // 使用for 迴圈取得所有上傳的檔案

            for (int i = 0; i < photos.Length; i++)

            {

                // 取得目前檔案上傳的HttpPostedFileBase物件

                // 即虛引數的photos[i]可以取得第i 個所上傳的檔案

                HttpPostedFileBase f = (HttpPostedFileBase)photos[i];

                // 若目前檔案上傳的HttpPostedFileBase物件的檔案名稱為不為空白

                // 即表示第 i 個f物件有指定上傳檔案

                if (f != null)

                {

                    //取得圖檔名稱

                    fileName = Path.GetFileName(f.FileName);

                    //將檔案儲存到網站的Photos資料夾下

                    var path = Path.Combine

                    (Server.MapPath("~/Photos"), fileName);

                    f.SaveAs(path);

                }

            }

            return RedirectToAction("ShowPhotos");

        }
        // ShowPhotos方法使用ContentResult傳回HTML

        // 可顯示Photos資料夾下所有圖檔

        public ContentResult ShowPhotos()

        {

            string strHtml = "";

            // 建立可操作Photos資料夾的dir物件

            DirectoryInfo dir =

            new DirectoryInfo(Server.MapPath("~/Photos"));

            //取得dir物件下的所有檔案(即photos資料夾下)並放入finfo檔案資訊陣列

            FileInfo[] fInfo = dir.GetFiles();

            // 逐一將finfo檔案資訊陣列內的所有圖檔指定給strHtml變數

            foreach (FileInfo result in fInfo)

            {

                // 將顯示圖的HTML字串指定給strHtml

                strHtml += $"<a href='../Photos/{result.Name}' target='_blank'>" +

                $"<img src='../Photos/{result.Name}' width='150' height='120' border='0'>" +

                $"</a>　";

            }

            // strHtml變數再加上 '返回' Create動作方法的連結

            strHtml += "<p><a href='Create'>返回</a></p>";

            return Content(strHtml, "text/html", System.Text.Encoding.UTF8);

        }


    }
}