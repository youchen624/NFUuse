using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

using prj41343131.Models;

namespace prj41343131.Controllers
{
    public class HomeController : Controller
    {
        DB41343131Entities db = new DB41343131Entities();
        public ActionResult Index()
        {
            var todos = db.tToDo.OrderByDescending(m=>m.fDate).ToList();
            return View(todos);
        }

        public ActionResult Create() {
            return View();
        }

        [HttpPost]
        public ActionResult Create(string fTitle, string fLevel, DateTime fDate)
        {
            tToDo todo = new tToDo();
            todo.fTitle = fTitle;
            todo.fLevel = fLevel;
            todo.fDate = fDate;
            db.tToDo.Add(todo);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        public ActionResult Delete(int id) {
            var todo = db.tToDo.Where(m => m.fId == id).FirstOrDefault();
            db.tToDo.Remove(todo);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        public ActionResult Edit(int id) {
            var todo = db.tToDo.Where(m => m.fId == id).FirstOrDefault();
            return View(todo);
        }

        [HttpPost]
        public ActionResult Edit(int fId, string fTitle, string fLevel, DateTime fDate) {
            var todo = db.tToDo.Where(m => m.fId == fId).FirstOrDefault();
            todo.fTitle = fTitle;
            todo.fLevel = fLevel;
            todo.fDate = fDate;
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        //public ActionResult About()
        //{
        //    ViewBag.Message = "Your application description page.";

        //    return View();
        //}

        //public ActionResult Contact()
        //{
        //    ViewBag.Message = "Your contact page.";

        //    return View();
        //}
    }
}