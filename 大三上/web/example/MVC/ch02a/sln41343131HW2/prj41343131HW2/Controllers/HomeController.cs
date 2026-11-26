using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

using prj41343131HW2.Models;

namespace prj41343131HW2.Controllers
{
    public class HomeController : Controller
    {
        //user db = new user();
        Entities db = new Entities();
        public ActionResult Index()
        {
            var todos = db.user.OrderByDescending(m => m.fId).ToList();
            return View(todos);
        }

        public ActionResult Create() {
            return View();
        }
        [HttpPost]
        public ActionResult Create(string fAccount, string fPassword, string fEmail, DateTime fDate) {
            user u = new user();
            u.fAccount = fAccount;
            u.fPassword = fPassword;
            u.fEmail = fEmail;
            u.fDate = fDate;
            db.user.Add(u);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        public ActionResult Delete(int id)
        {
            var user = db.user.Where(m => m.fId == id).FirstOrDefault();
            db.user.Remove(user);
            db.SaveChanges();
            return RedirectToAction("Index");
        }


        public ActionResult Edit(int id)
        {
            var user = db.user.Where(m => m.fId == id).FirstOrDefault();
            return View(user);
        }

        [HttpPost]
        public ActionResult Edit(int fId, string fAccount, string fPassword, string fEmail, DateTime fDate)
        {
            var user = db.user.Where(m => m.fId == fId).FirstOrDefault();
            user.fAccount = fAccount;
            user.fPassword = fPassword;
            user.fEmail = fEmail;
            user.fDate = fDate;
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