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
Page Q6R(true, "Ну конечно же это Анна Иоанновна!", "img/Anya.jpg", ":)", "https://ru.wikipedia.org/wiki/%D0%90%D0%BD%D0%BD%D0%B0_%D0%98%D0%BE%D0%B0%D0%BD%D0%BD%D0%BE%D0%B2%D0%BD%D0%B0"); // DONE

Page Q4L(false, "Была жената на Немце?", &Q6R, &Q6L);
Page Q4R(false, "Присоединила Крым к России?", &Q5R, &Q5L);

Page Q3L(false, "Её имя - Екатерина?", &Q4R, &Q4L);
Page Q3R(true, "Кажется, вы загадали княгиню Ольгу!", "img/Olga.jpg", "А вы знали, что она любила зажечь с огоньком?", "https://ru.wikipedia.org/wiki/%D0%9E%D0%BB%D1%8C%D0%B3%D0%B0_(%D0%BA%D0%BD%D1%8F%D0%B3%D0%B8%D0%BD%D1%8F_%D0%BA%D0%B8%D0%B5%D0%B2%D1%81%D0%BA%D0%B0%D1%8F)"); // DONE

Page Q10L(true, "Кажется, это Лжедмитрий II", "img/Lzhe2.jpg", "А вы знали, что он на самом деле не был вором?", "https://ru.wikipedia.org/wiki/%D0%9B%D0%B6%D0%B5%D0%B4%D0%BC%D0%B8%D1%82%D1%80%D0%B8%D0%B9_II"); // done
Page Q10R(true, "Я думаю, это Лжедмитрий I", "img/Lzhe.jpg", "А вы знали, что у него одна рука была короче другой?", "https://ru.wikipedia.org/wiki/%D0%9B%D0%B6%D0%B5%D0%B4%D0%BC%D0%B8%D1%82%D1%80%D0%B8%D0%B9_I"); // done

Page Q12L(true, "Кажется, вы загадали Бориса Годунова!", "img/BGod.jpg", "А вы знали, что Годунов был первым царем, который победил на выборах?)", "https://ru.wikipedia.org/wiki/%D0%91%D0%BE%D1%80%D0%B8%D1%81_%D0%93%D0%BE%D0%B4%D1%83%D0%BD%D0%BE%D0%B2"); // done
Page Q12R(true, "Вы загадали Василия Шуйского!", "img/VasSh.jpg", "А вы знали, что он умер в польском плену?", "https://ru.wikipedia.org/wiki/%D0%92%D0%B0%D1%81%D0%B8%D0%BB%D0%B8%D0%B9_IV_%D0%A8%D1%83%D0%B9%D1%81%D0%BA%D0%B8%D0%B9"); // done

Page Q11L(false, "Тогда, может быть, он руководил восстанием в Мосвке?", &Q12R, &Q12L);
Page Q11R(true, "Я думаю, что это Федор 2 Годунов!", "img/Fed2G.png", "А вы знали, что он стал царем в 16 лет?", "https://ru.wikipedia.org/wiki/%D0%A4%D1%91%D0%B4%D0%BE%D1%80_II_%D0%93%D0%BE%D0%B4%D1%83%D0%BD%D0%BE%D0%B2"); // done

Page Q9L(false, "А правил меньше всех других российских правителей?", &Q11R, &Q11L);
Page Q9R(false, "Исполнял роль снаряда для пушки?", &Q10R, &Q10L);

Page Q16L(true, "Это точно Михаил Горбачев!", "img/Gorb.png", ":)", "https://ru.wikipedia.org/wiki/%D0%93%D0%BE%D1%80%D0%B1%D0%B0%D1%87%D1%91%D0%B2,_%D0%9C%D0%B8%D1%85%D0%B0%D0%B8%D0%BB_%D0%A1%D0%B5%D1%80%D0%B3%D0%B5%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q16R(true, "Я думаю, это Борис Ельцин!", "img/Elc.jpg", "А вы знали, что он прожил меньше всех других российских Президентов?", "https://ru.wikipedia.org/wiki/%D0%95%D0%BB%D1%8C%D1%86%D0%B8%D0%BD,_%D0%91%D0%BE%D1%80%D0%B8%D1%81_%D0%9D%D0%B8%D0%BA%D0%BE%D0%BB%D0%B0%D0%B5%D0%B2%D0%B8%D1%87"); // done

Page Q15L(true, "Ну конечно же это Дмитрий Медведев!", "img/Med.jpg", ":)", "https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D0%B4%D0%B2%D0%B5%D0%B4%D0%B5%D0%B2,_%D0%94%D0%BC%D0%B8%D1%82%D1%80%D0%B8%D0%B9_%D0%90%D0%BD%D0%B0%D1%82%D0%BE%D0%BB%D1%8C%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q15R(true, "Вы точно загадали Владимира Владимировича!", "img/Putin.png", "Вы знали, что у нашего президента есть 2 дочери?", "https://ru.wikipedia.org/wiki/%D0%9F%D1%83%D1%82%D0%B8%D0%BD,_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80_%D0%92%D0%BB%D0%B0%D0%B4%D0%B8%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q14L(false, "Загаданный вами правитель стоял на танке?", &Q16R, &Q16L); 
Page Q14R(false, "Загаданный вами правитель - лысый?", &Q15R, &Q15L); 

Page Q19L(true, "Разумеется это Георгий Львов!", "img/Lvov.jpg", ":)", "https://ru.wikipedia.org/wiki/%D0%9B%D1%8C%D0%B2%D0%BE%D0%B2,_%D0%93%D0%B5%D0%BE%D1%80%D0%B3%D0%B8%D0%B9_%D0%95%D0%B2%D0%B3%D0%B5%D0%BD%D1%8C%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q19R(true, "Ну конечно это Александр Керенский!", "img/Kerensky.jpg", "А вы знали, что наряжался он не только в платья, но и в парики..", "https://ru.wikipedia.org/wiki/%D0%9A%D0%B5%D1%80%D0%B5%D0%BD%D1%81%D0%BA%D0%B8%D0%B9,_%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_%D0%A4%D1%91%D0%B4%D0%BE%D1%80%D0%BE%D0%B2%D0%B8%D1%87"); // done

Page Q18L(true, "Кажется, это Александр Колчак!", "img/Kolch.jpg", "А вы знали, что во время Русско-Японской он был ранен и попал в плен?", "https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%BB%D1%87%D0%B0%D0%BA,_%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80_%D0%92%D0%B0%D1%81%D0%B8%D0%BB%D1%8C%D0%B5%D0%B2%D0%B8%D1%87"); // done
Page Q18R(false, "Этот правитель наряжался в женские платья?", &Q19R, &Q19L); 

Page Q21L(false, "Этот правитель - Этический грузин?", &Q17R, &Q17L); 
Page Q21R(true, "Кажется, вы загадали Владимира Ильича!", "img/Lenin.jpg", ":)", ""); // done 

Page Q20L(false, "Этот правитель - Этический грузин?", &Q17R, &Q17L); // todo: ussr communists
Page Q20R(false, "Он стоял на броневике?", &Q21R, &Q21L); 

Page Q17L(false, "Он был главой Временного Правительства?", &Q18R, &Q18L); 
Page Q17R(false, "Он был лысым?", &Q20R, &Q20L); 

Page Q13L(false, "Он был коммунистом?", &Q17R, &Q17L); 
Page Q13R(false, "Загаданный вами правитель сейчас жив?", &Q14R, &Q14L); 

Page Q8L(false, "Был женат на полячке?", &Q9R, &Q9L); 
Page Q8R(false, "Был президентом?", &Q13R, &Q13L); 

Page Q7L(false, "Предствитель XX века?", &Q8R, &Q8L);
Page Q7R(false, "Присоединила Крым к России", &Q5R, &Q5L); // TODO: MONARCH

Page Q2L(false, "Она из рода рюриковичей?", &Q3R, &Q3L);
Page Q2R(false, "Он - представитель одной из основных правящих династий России?", &Q7R, &Q7L);

Page Q1(false, "Загаданный Вами правитель - мужчина?", &Q2R, &Q2L);

Page CURRENT = Q1;