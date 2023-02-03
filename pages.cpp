#include "page.h"

Page::Page(bool isLast, std::string question, Page* PY, Page* PN){
    this->isLast = isLast;
    this->question = question;
    this->PageYes = PY;
    this->PageNo = PN;
}

Page::Page(bool isLast, std::string question, std::string photo, std::string description, std::string wiki){
    this->isLast = isLast;
    this->question = question;
    this->photoPath = photo;
    this->description = description;
    this->wikiLink = wiki;
}


Page Q5L(true, "Тогда это Екатерина I!", "img/Katya.jpg", "А вы знали, что она была женой Петра I?", "https://ru.wikipedia.org/wiki/%D0%95%D0%BA%D0%B0%D1%82%D0%B5%D1%80%D0%B8%D0%BD%D0%B0_I");  // DONE
Page Q5R(true, "Значит, это Екатерина II Великая!", "img/Katya2.jpg", "А вы знали, что она была немкой?", "https://ru.wikipedia.org/wiki/%D0%95%D0%BA%D0%B0%D1%82%D0%B5%D1%80%D0%B8%D0%BD%D0%B0_II"); // DONE

Page Q6L(true, "Я думаю, что это Елизавета Петровна!", "img/Liza.jpg", "А вы знали, что она дочь Петра I?", "https://ru.wikipedia.org/wiki/%D0%95%D0%BB%D0%B8%D0%B7%D0%B0%D0%B2%D0%B5%D1%82%D0%B0_%D0%9F%D0%B5%D1%82%D1%80%D0%BE%D0%B2%D0%BD%D0%B0"); // DONE
Page Q6R(true, "Ну конечно же это Анна Иоанновна!", "img/Anya.jpg", "А вы знали, что уже через несколько месяцев после свадьбы она стала вдовой?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BD%D0%BD%D0%B0_%D0%98%D0%BE%D0%B0%D0%BD%D0%BD%D0%BE%D0%B2%D0%BD%D0%B0"); // DONE

Page Q4L(false, "Была замужем за немца?", &Q6R, &Q6L);
Page Q4R(false, "Присоединила Крым к России?", &Q5R, &Q5L);

Page Q3L(false, "Её имя - Екатерина?", &Q4R, &Q4L);
Page Q3R(true, "Кажется, вы загадали княгиню Ольгу!", "img/Olga.jpg", "А вы знали, что она любила зажечь с огоньком?", "https://ru.wikipedia.org/wiki/%D0%9E%D0%BB%D1%8C%D0%B3%D0%B0_(%D0%BA%D0%BD%D1%8F%D0%B3%D0%B8%D0%BD%D1%8F_%D0%BA%D0%B8%D0%B5%D0%B2%D1%81%D0%BA%D0%B0%D1%8F)"); // DONE

Page Q10L(true, "Кажется, это Лжедмитрий II \"Тушинский вор\"", "img/Lzhe2.jpg", "А вы знали, что он на самом деле не был вором?", "https://ru.wikipedia.org/wiki/%D0%9B%D0%B6%D0%B5%D0%B4%D0%BC%D0%B8%D1%82%D1%80%D0%B8%D0%B9_II"); // done
Page Q10R(true, "Я думаю, это Лжедмитрий I", "img/Lzhe.jpg", "А вы знали, что у него одна рука была короче другой?", "https://ru.wikipedia.org/wiki/%D0%9B%D0%B6%D0%B5%D0%B4%D0%BC%D0%B8%D1%82%D1%80%D0%B8%D0%B9_I"); // done

Page Q12L(true, "Кажется, вы загадали Бориса Годунова!", "img/BGod.jpg", "А вы знали, что Годунов был первым царем, который победил на выборах?)", "https://ru.wikipedia.org/wiki/%D0%91%D0%BE%D1%80%D0%B8%D1%81_%D0%93%D0%BE%D0%B4%D1%83%D0%BD%D0%BE%D0%B2"); // done
Page Q12R(true, "Вы загадали Василия Шуйского!", "img/VasSh.jpg", "А вы знали, что он умер в польском плену?", "https://ru.wikipedia.org/wiki/%D0%92%D0%B0%D1%81%D0%B8%D0%BB%D0%B8%D0%B9_IV_%D0%A8%D1%83%D0%B9%D1%81%D0%BA%D0%B8%D0%B9"); // done

Page Q11L(false, "Тогда, может быть, он руководил восстанием в Москве?", &Q12R, &Q12L);
Page Q11R(true, "Я думаю, что это Федор 2 Годунов!", "img/Fed2G.png", "А вы знали, что он стал царем в 16 лет?", "https://ru.wikipedia.org/wiki/%D0%A4%D1%91%D0%B4%D0%BE%D1%80_II_%D0%93%D0%BE%D0%B4%D1%83%D0%BD%D0%BE%D0%B2"); // done

Page Q9L(false, "А правил меньше всех других российских правителей?", &Q11R, &Q11L);
Page Q9R(false, "Исполнял роль снаряда для пушки?", &Q10R, &Q10L);

Page Q16L(true, "Это точно Михаил Горбачев!", "img/Gorb.png", ":)", "https://ru.wikipedia.org/wiki/%D0%93%D0%BE%D1%80%D0%B1%D0%B0%D1%87%D1%91%D0%B2,_%D0%9C%D0%B8%D1%85%D0%B0%D0%B8%D0%BB_%D0%A1%D0%B5%D1%80%D0%B3%D0%B5%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q16R(true, "Я думаю, это Борис Ельцин!", "img/Elc.jpg", "А вы знали, что он прожил меньше всех других российских Президентов?", "https://ru.wikipedia.org/wiki/%D0%95%D0%BB%D1%8C%D1%86%D0%B8%D0%BD,_%D0%91%D0%BE%D1%80%D0%B8%D1%81_%D0%9D%D0%B8%D0%BA%D0%BE%D0%BB%D0%B0%D0%B5%D0%B2%D0%B8%D1%87"); // done

Page Q15L(true, "Ну конечно же это Дмитрий Медведев!", "img/Med.jpg", ":)", "https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D0%B4%D0%B2%D0%B5%D0%B4%D0%B5%D0%B2,_%D0%94%D0%BC%D0%B8%D1%82%D1%80%D0%B8%D0%B9_%D0%90%D0%BD%D0%B0%D1%82%D0%BE%D0%BB%D1%8C%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q15R(true, "Вы точно загадали Владимира Владимировича!", "img/Putin.png", "Вы знали, что у нашего президента есть 2 дочери?", "https://ru.wikipedia.org/wiki/%D0%9F%D1%83%D1%82%D0%B8%D0%BD,_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q14L(false, "Загаданный вами правитель стоял на танке?", &Q16R, &Q16L); 
Page Q14R(false, "Загаданный вами правитель - лысый?", &Q15R, &Q15L); 

Page Q19L(true, "Разумеется, это Георгий Львов!", "img/Lvov.jpg", ":)", "https://ru.wikipedia.org/wiki/%D0%9B%D1%8C%D0%B2%D0%BE%D0%B2,_%D0%93%D0%B5%D0%BE%D1%80%D0%B3%D0%B8%D0%B9_%D0%95%D0%B2%D0%B3%D0%B5%D0%BD%D1%8C%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q19R(true, "Ну конечно это Александр Керенский!", "img/Kerensky.jpg", "А вы знали, что наряжался он не только в платья, но и в парики..", "https://ru.wikipedia.org/wiki/%D0%9A%D0%B5%D1%80%D0%B5%D0%BD%D1%81%D0%BA%D0%B8%D0%B9,_%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_%D0%A4%D1%91%D0%B4%D0%BE%D1%80%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q18L(true, "Кажется, это Александр Колчак!", "img/Kolch.jpg", "А вы знали, что во время Русско-Японской он был ранен и попал в плен?", "https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%BB%D1%87%D0%B0%D0%BA,_%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_%D0%92%D0%B0%D1%81%D0%B8%D0%BB%D1%8C%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q18R(false, "Этот правитель наряжался в женские платья?", &Q19R, &Q19L); 

Page Q22L(true, "Тогда, наверное, это Юрий Андропов!", "img/Andropov.jpg", "А вы знали, что у него был сахарный диабет?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BD%D0%B4%D1%80%D0%BE%D0%BF%D0%BE%D0%B2,_%D0%AE%D1%80%D0%B8%D0%B9_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B8%D1%87"); // done
Page Q22R(true, "Ну конечно же это Никита Сергеевич Хрущев!", "img/Khrysch.jpg", "А вы знали, что он очень любил кукурузу?", "https://ru.wikipedia.org/wiki/%D0%A5%D1%80%D1%83%D1%89%D1%91%D0%B2,_%D0%9D%D0%B8%D0%BA%D0%B8%D1%82%D0%B0_%D0%A1%D0%B5%D1%80%D0%B3%D0%B5%D0%B5%D0%B2%D0%B8%D1%87"); // done 

Page Q21L(false, "Стучал ботинком по столу на заседании ООН?", &Q22R, &Q22L); 
Page Q21R(true, "Кажется, вы загадали Владимира Ильича!", "img/Lenin.jpg", "А вы знали, что его настоящая фамилия - Ульянов?", "https://ru.wikipedia.org/wiki/%D0%9B%D0%B5%D0%BD%D0%B8%D0%BD,_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80_%D0%98%D0%BB%D1%8C%D0%B8%D1%87"); // done 

Page Q25L(true, "Наверное, вы загадали Константина Черненко!", "img/Chern.jpg", "А вы знали, что значительную часть своего правления он провел в больнице?", "https://ru.wikipedia.org/wiki/%D0%A7%D0%B5%D1%80%D0%BD%D0%B5%D0%BD%D0%BA%D0%BE,_%D0%9A%D0%BE%D0%BD%D1%81%D1%82%D0%B0%D0%BD%D1%82%D0%B8%D0%BD_%D0%A3%D1%81%D1%82%D0%B8%D0%BD%D0%BE%D0%B2%D0%B8%D1%87"); // done
Page Q25R(true, "Совершенно ясно, что это Георгий Маленков!", "img/Mal.jpg", "А вы знали, что при нём стали массово выпускать всем известные гранёные стаканы?", "https://ru.wikipedia.org/wiki/%D0%9C%D0%B0%D0%BB%D0%B5%D0%BD%D0%BA%D0%BE%D0%B2,_%D0%93%D0%B5%D0%BE%D1%80%D0%B3%D0%B8%D0%B9_%D0%9C%D0%B0%D0%BA%D1%81%D0%B8%D0%BC%D0%B8%D0%BB%D0%B8%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q24L(false, "Он участвовал в борьбе за власть с Хрущевым?", &Q25R, &Q25L); 
Page Q24R(true, "Ну конечно же это Леонид Брежнев!", "img/Brezhnev.jpg", "А вы знали, что Леонид Ильич - участик Великой Отечественной?", "https://ru.wikipedia.org/wiki/%D0%91%D1%80%D0%B5%D0%B6%D0%BD%D0%B5%D0%B2,_%D0%9B%D0%B5%D0%BE%D0%BD%D0%B8%D0%B4_%D0%98%D0%BB%D1%8C%D0%B8%D1%87"); // done 

Page Q23L(false, "Но, наверное, любил целоваться с политиками?", &Q24R, &Q24L); 
Page Q23R(true, "Вы загадали Иосифа Виссарионовича!", "img/Stalin.jpg", "А вы знали, что Сталин очень любил детей?", "https://ru.wikipedia.org/wiki/%D0%A1%D1%82%D0%B0%D0%BB%D0%B8%D0%BD,_%D0%98%D0%BE%D1%81%D0%B8%D1%84_%D0%92%D0%B8%D1%81%D1%81%D0%B0%D1%80%D0%B8%D0%BE%D0%BD%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q20L(false, "Этот правитель - этический грузин?", &Q23R, &Q23L); 
Page Q20R(false, "Он стоял на броневике?", &Q21R, &Q21L); 

Page Q17L(false, "Он был главой Временного Правительства?", &Q18R, &Q18L); 
Page Q17R(false, "Он был лысым?", &Q20R, &Q20L); 

Page Q13L(false, "Он был коммунистом?", &Q17R, &Q17L); 
Page Q13R(false, "Загаданный вами правитель сейчас жив?", &Q14R, &Q14L); 

Page Q8L(false, "Был женат на полячке?", &Q9R, &Q9L); 
Page Q8R(false, "Был президентом?", &Q13R, &Q13L); 

Page Q29L(true, "Кажется, вы загадали Федора 3 Романова!", "img/Fedor.jpg", "А вы знали, что за свою жизнь он успел 2 раза жениться?", "https://ru.wikipedia.org/wiki/%D0%A4%D1%91%D0%B4%D0%BE%D1%80_III_%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B5%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q29R(true, "Наверное, это Алексей Романов!", "img/Alex.jpg", "А вы знали, что при нем было принято решение о присоединении Левобережной Украины к России?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B5%D0%B9_%D0%9C%D0%B8%D1%85%D0%B0%D0%B9%D0%BB%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q28L(false, "Носил прозвище \"Тишайший\"?", &Q29R, &Q29L); 
Page Q28R(true, "Определенно, это Михаил Романов!", "img/Mikhail.jpg", "А вы знали, что он правил совместно со своим отцом - патриархом Филаретом?", "https://ru.wikipedia.org/wiki/%D0%9C%D0%B8%D1%85%D0%B0%D0%B8%D0%BB_%D0%A4%D1%91%D0%B4%D0%BE%D1%80%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q31L(true, "Возможно, это Петр III", "img/Petr3.jpg", "А вы знали, что он был мужем Екатерины II?", "https://ru.wikipedia.org/wiki/%D0%9F%D1%91%D1%82%D1%80_III"); // done
Page Q31R(true, "Ну конечно же это Петр I Великий!", "img/Petr1.jpg", "А вы знали, что Петр I был очень высоким?", "https://ru.wikipedia.org/wiki/%D0%9F%D1%91%D1%82%D1%80_I"); // done

Page Q34L(true, "Очевидно, что это Николай II!", "img/Kol2.jpg", "А вы знали, что он хотел перенести столицу России в Ялту?", "https://ru.wikipedia.org/wiki/%D0%9D%D0%B8%D0%BA%D0%BE%D0%BB%D0%B0%D0%B9_II"); // done
Page Q34R(true, "Очевидно, что это Николай I Романов!", "img/Kol1.jpg", "А вы знали, что он, как и Петр I, был очень высоким?", "https://ru.wikipedia.org/wiki/%D0%9D%D0%B8%D0%BA%D0%BE%D0%BB%D0%B0%D0%B9_I"); // done

Page Q37L(true, "Возможно, вы загадали Александра I", "img/Alex1.jpg", "А вы знали, что он был глух на левое ухо?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_I"); // done
Page Q37R(true, "Ну конечно же это Петр II!", "img/Petr2.jpg", "А вы знали, что он погиб от оспы?", "https://ru.wikipedia.org/wiki/%D0%9F%D1%91%D1%82%D1%80_II"); //done

Page Q36L(false, "Загаданный вами правитель умер до 18-ти лет?", &Q37R, &Q37L); 
Page Q36R(true, "Определенно, это Александр II!?", "img/Alex2.jpg", "А вы знали, что он погиб от рук террористов?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_II"); // done

Page Q35L(false, "Отменил крепостное право?", &Q36R, &Q36L); 
Page Q35R(true, "Определенно, это Александр III!", "img/Alex3.jpg", "А вы знали, что при нём Россия не участвовала ни в одной войне?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_III"); //done

Page Q33L(false, "Он держал упавшую крышу поезда?", &Q35R, &Q35L); 
Page Q33R(false, "А всегда ли успешно?", &Q34R, &Q34L); 

Page Q32L(false, "Загаданный вами правитель подавлял восстания или революции в своей стране?", &Q33R, &Q33L); 
Page Q32R(true, "Наверное, вы загадали Павла I!", "img/Pavel.png", "А вы знали, что, возможно, его сын Александр I знал о заговоре против Павла?", "https://ru.wikipedia.org/wiki/%D0%9F%D0%B0%D0%B2%D0%B5%D0%BB_I"); // done 

Page Q30L(false, "Известен законом о престолонаследии?", &Q32R, &Q32L); 
Page Q30R(false, "Построил самый красивый город в Росии?", &Q31R, &Q31L); 

Page Q27L(false, "Жил во время смуты?", &Q28R, &Q28L); 
Page Q27R(false, "Играл \"в солдатиков\"?", &Q30R, &Q30L); 

Page Q39L(true, "Кажется, вы загадали Ивана IV Грозного!", "img/Ivan4.jpg", "А вы знали, что именно он ввел Юрьев день?", "https://ru.wikipedia.org/wiki/%D0%98%D0%B2%D0%B0%D0%BD_%D0%93%D1%80%D0%BE%D0%B7%D0%BD%D1%8B%D0%B9"); // done
Page Q39R(true, "Определенно, это Федр I?", "img/Fed1.jpg", "А вы знали, что он был последним царем из династии Рюриковичей?", "https://ru.wikipedia.org/wiki/%D0%A4%D1%91%D0%B4%D0%BE%D1%80_%D0%98%D0%B2%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q42L(true, "Наверное, вы загадали Дмитрия Донского", "img/DDon.jpg", "А вы знали, что при нем московский Кремль стал каменным?", "https://ru.wikipedia.org/wiki/%D0%94%D0%BC%D0%B8%D1%82%D1%80%D0%B8%D0%B9_%D0%98%D0%B2%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D1%87_%D0%94%D0%BE%D0%BD%D1%81%D0%BA%D0%BE%D0%B9"); // done
Page Q42R(true, "Возможно, вы загадали Александра Невского", "img/AlexN.jpg", "А вы знали, что Александр Невский не проиграл ни одного сражения?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_%D0%AF%D1%80%D0%BE%D1%81%D0%BB%D0%B0%D0%B2%D0%B8%D1%87_%D0%9D%D0%B5%D0%B2%D1%81%D0%BA%D0%B8%D0%B9"); // done

Page Q44L(true, "Возможно. это Иван III Великий", "img/Ivan3.jpg", "А вы знали, что при нём Россия освободилась от Татаро-монгольского ига?", "https://ru.wikipedia.org/wiki/%D0%98%D0%B2%D0%B0%D0%BD_III_%D0%92%D0%B0%D1%81%D0%B8%D0%BB%D1%8C%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q44R(true, "Ну конечно же это Иван Калита!", "img/IvanK.jpg", "А вы знали, что Калита получил право собирать дань с русских земель за то, что подавил восстание против татар в Твери?", "https://ru.wikipedia.org/wiki/%D0%98%D0%B2%D0%B0%D0%BD_I_%D0%94%D0%B0%D0%BD%D0%B8%D0%BB%D0%BE%D0%B2%D0%B8%D1%87_%D0%9A%D0%B0%D0%BB%D0%B8%D1%82%D0%B0"); // done

Page Q43L(true, "Скорее всего, вы загадали Василия II Темного", "img/Vas2t.jpg", "Вы знали, что он получил такое прозвище, потому что был слепым?", "https://ru.wikipedia.org/wiki/%D0%92%D0%B0%D1%81%D0%B8%D0%BB%D0%B8%D0%B9_II_%D0%A2%D1%91%D0%BC%D0%BD%D1%8B%D0%B9"); // done
Page Q43R(false, "Он обманывал татар на деньги?", &Q44R, &Q44L); 

Page Q41L(false, "Его имя - Иван?", &Q43R, &Q43L);
Page Q41R(false, "Князь Новгородский?", &Q42R, &Q42L); 

Page Q47L(true, "Наверное, это Всеволод Большое Гнездо", "img/VseBG.jpg", "А вы знали, что он получил свое прозвище из-за того, что  у него было 12 детей?", "https://ru.wikipedia.org/wiki/%D0%92%D1%81%D0%B5%D0%B2%D0%BE%D0%BB%D0%BE%D0%B4_%D0%AE%D1%80%D1%8C%D0%B5%D0%B2%D0%B8%D1%87_%D0%91%D0%BE%D0%BB%D1%8C%D1%88%D0%BE%D0%B5_%D0%93%D0%BD%D0%B5%D0%B7%D0%B4%D0%BE"); // done
Page Q47R(true, "Очевидно, это Юрий Долгорукий!", "img/UriiDolg.png", "А вы знали, что его так прозвали за стремление править в разных русских княжествах?", "https://ru.wikipedia.org/wiki/%D0%AE%D1%80%D0%B8%D0%B9_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B8%D1%87_%D0%94%D0%BE%D0%BB%D0%B3%D0%BE%D1%80%D1%83%D0%BA%D0%B8%D0%B9"); // done 

Page Q48L(true, "Скорее всего, это Владимир Мономах", "img/VMon.jpg", "А вы знали, что он носил прикольную шапку?", "https://ru.wikipedia.org/wiki/%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80_%D0%92%D1%81%D0%B5%D0%B2%D0%BE%D0%BB%D0%BE%D0%B4%D0%BE%D0%B2%D0%B8%D1%87_%D0%9C%D0%BE%D0%BD%D0%BE%D0%BC%D0%B0%D1%85"); //done
Page Q48R(true, "Наверное, это Андрей Боголюбский", "img/ABog.jpg", "А вы знали, что он был глубоко верующим человеком?", "https://ru.wikipedia.org/wiki/%D0%90%D0%BD%D0%B4%D1%80%D0%B5%D0%B9_%D0%AE%D1%80%D1%8C%D0%B5%D0%B2%D0%B8%D1%87_%D0%91%D0%BE%D0%B3%D0%BE%D0%BB%D1%8E%D0%B1%D1%81%D0%BA%D0%B8%D0%B9"); //done

Page Q46L(false, "Он основал Москву?", &Q47R, &Q47L); 
Page Q46R(false, "Он ходил в походы на Булгарию?", &Q48R, &Q48L);

Page Q50L(true, "Наверное, это Ярослав Мудрый", "img/Yam.jpg", "А вы знали, что именно с него началось раздробление Руси?", "https://ru.wikipedia.org/wiki/%D0%AF%D1%80%D0%BE%D1%81%D0%BB%D0%B0%D0%B2_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B8%D1%87_%D0%9C%D1%83%D0%B4%D1%80%D1%8B%D0%B9"); // done
Page Q50R(true, "Это же Владимир Красное Солнышко!", "img/Vsv.jpg", "А вы знали, что крещение Руси произошло в 988 году н.э.?", "https://ru.wikipedia.org/wiki/%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80_%D0%A1%D0%B2%D1%8F%D1%82%D0%BE%D1%81%D0%BB%D0%B0%D0%B2%D0%B8%D1%87"); // done

Page Q52L(true, "Вы загадали князя Игоря!", "img/Igor.png", "А вы знали, что нельзя собирать дань с древлян 2 раза подряд?", "https://ru.wikipedia.org/wiki/%D0%98%D0%B3%D0%BE%D1%80%D1%8C_%D0%A0%D1%8E%D1%80%D0%B8%D0%BA%D0%BE%D0%B2%D0%B8%D1%87"); // done
Page Q52R(true, "Вы загадали Вещего Олега!", "img/Oleg.jpg", "А вы знали, что Олег подарил воротам Византии свой щит?", "https://ru.wikipedia.org/wiki/%D0%9E%D0%BB%D0%B5%D0%B3_%D0%92%D0%B5%D1%89%D0%B8%D0%B9"); // done

Page Q51L(false, "Умер от укуса змеи?", &Q52R, &Q52L); 
Page Q51R(true, "Кажется, это Рюрик!", "img/Rurik.jpg", "А вы знали, что у него было 2 брата?", "https://ru.wikipedia.org/wiki/%D0%A0%D1%8E%D1%80%D0%B8%D0%BA"); // done 

Page Q49L(false, "Приехал из Скандинавии?", &Q51R, &Q51L); 
Page Q49R(false, "Он крестил Русь?", &Q50R, &Q50L); 

Page Q45L(false, "Пытался объединить Русь?", &Q46R, &Q46L); 
Page Q45R(false, "Он был православным?", &Q49R, &Q49L); 

Page Q40L(false, "Он жил до раздробленности Руси?", &Q45R, &Q45L); 
Page Q40R(false, "Известен благодаря битвам?", &Q41R, &Q41L); 

Page Q38L(false, "Он застал Татаро-монгольское иго?", &Q40R, &Q40L); 
Page Q38R(false, "Был эпилептиком?", &Q39R, &Q39L); 

Page Q26L(false, "Был императором?", &Q27R, &Q27L); 
Page Q26R(false, "Носил титул царя?", &Q38R, &Q38L); 

Page Q7L(false, "Предствитель XX века?", &Q8R, &Q8L);
Page Q7R(false, "И он из рода Рюриковичей?", &Q26R, &Q26L);

Page Q2L(false, "Она из рода рюриковичей?", &Q3R, &Q3L);
Page Q2R(false, "Он - представитель одной из основных правящих династий России (Рюриковичи, Романовы)?", &Q7R, &Q7L);

Page Q1(false, "Загадайте любого правителя России (от Рюрика до Путина)\nЗагаданный Вами правитель - мужчина?", &Q2R, &Q2L);

Page CURRENT = Q1;