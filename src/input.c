
  /*!
  @file input.c
  @{

  \brief
  Файл отвечает за регистрацию пользователей
  *
  *
    *@author Батов Юрий email - batov1998@list.ru\n
    *@author Ильченко Никита email - wunted7@gmail.com
  */
  /** Регистрирует новых пользователей и записывает их имена в файл, создает файл с их персональными данными
  */
  /**
    ##Функция определяет время удержания клавиши и определяет , что за буква была нажата пользователем
    ##Происходит обработка полученных значений (подсчет погрешностей)
  */
  double A[MAX_LETTER][MAX_SIZE];
  int input()
  {
    setlocale(LC_ALL, "Rus");
    //Переменные
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    FILE *C =  NULL, *X = NULL, *NAME = NULL;
    double B[MAX_LETTER][COLUMS_IN_FILE1];
    unsigned int j = 0, i = 0, k = 0;
    double time_of_press = 0.0, sr_zn = 0.0, interrval = 0, sum = 0, time_of_release = 0.0;
    char name[LEN_NAME_FILE]={0};
    printf("Введите свое имя и фамилию без пробелов на английском не более 20 символов: ");
    scanf("%s", name);
    NAME = fopen("NAME", "a");
    if (NAME == NULL)
        {
          puts("Проблемы с открытием файла , попробуйте снова");
          return 0;
        }
    fprintf(NAME, "%s\n", name);
    fclose(NAME);
    C = fopen(name, "r");
    if (C != NULL)
    {
        for (i = 0; i < MAX_LETTER; i++)
        {
          for (j = 0; j < MAX_SIZE; j++)
          {
            fscanf(C, "%lf", &A[i][j]);
          }
        }
    }
    else
    {
        C = fopen(name, "w");
    }
    fclose(C);
    bool quit = false;
    if (!al_init())
    {
        puts("Проблемы с загрузкой ALLEGRO, попробуйте снова");
        return EXIT_FAILURE;
    }
    if (!al_install_keyboard())
    {
        puts("Проблемы с клавиатурой ALLEGRO, попробуйте снова");
        return EXIT_FAILURE;
    }
    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    display = al_create_display(SCREEN_HEIGHT, SCREEN_WIDTH);
    if (!display)
    {
        puts("Проблемы с дисплеем, попробуйте снова");
        al_destroy_display(display);
        return EXIT_FAILURE;
  	}

  	ALLEGRO_FONT* font = al_create_builtin_font();
  	ALLEGRO_USTR* str = al_ustr_new("Please enter this sentence 13 times , than enter Escape: pack my box with five dozen liquor jugs.");
  	ALLEGRO_USTR* tab = al_ustr_new("");
  	int position = (int)al_ustr_size(tab);
  	//Инициализация
  	event_queue = al_create_event_queue();

  	al_register_event_source(event_queue, al_get_keyboard_event_source());
  	al_register_event_source(event_queue, al_get_display_event_source(display));
  	while (!quit)
  	{
  		al_clear_to_color(al_map_rgb_f(0, 0, 0));
  		al_draw_ustr(font, al_map_rgb_f(1, 1, 1), 0, 0, 0, str);
  		al_draw_multiline_ustr(font, al_map_rgb_f(1, 1, 1), 0, 20, 400, 20, 0, tab);
  		al_flip_display();

  		ALLEGRO_EVENT ev;
  		al_wait_for_event(event_queue, &ev);

  		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
  			quit = true;
  		}
  		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
  		{
  			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
  			{
  				quit = true;
  			}
  			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
  			{
  				al_ustr_append_cstr(tab, "\n");
  			}
  			time_of_press = al_get_time();
  		}
  		if (ev.type == ALLEGRO_EVENT_KEY_UP)
  		{
  			if (ev.keyboard.keycode > 27)
  			{
  				continue;
  			}
  			else
  			{
  				time_of_release = al_get_time();
  				while (A[ev.keyboard.keycode - 1][k] != 0)
  				{
  					k++;
  				}
  				if(k <= MAX_SIZE)
            {
                A[ev.keyboard.keycode - 1][k] = time_of_release - time_of_press;
  				}
  				for (i = 0; i < k; i++)
  				{
  					sum = sum + A[ev.keyboard.keycode - 1][i];
  				}
  				sr_zn = sum / k;
  				if (k != 1)
  				{
  					interrval = delta(k, A[ev.keyboard.keycode - 1], sr_zn);
  				}
  				k = 0;
  				sum = 0;
  				B[ev.keyboard.keycode - 1][0] = sr_zn;
  				B[ev.keyboard.keycode - 1][1] = t;
  			}
  		}
  		if (ev.type == ALLEGRO_EVENT_KEY_CHAR)
  		{
  			if (ev.keyboard.unichar >= 32)
  			{
  				pos1 += al_ustr_append_chr(tab, ev.keyboard.unichar);
  			}
  			else if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE)
  			{
  				if (al_ustr_prev(tab, &position))
  					al_ustr_truncate(tab, position);
  			}
  		}


  	}
  	C = fopen(name, "w");
  	if (C == NULL)
        {
            puts("Проблемы с открытием файла, попробуйте снова");
            return EXIT_FAILURE;
        }
  	for (i = 0; i<MAX_LETTER; i++)
        {
  		for (j = 0; j<MAX_SIZE; j++)
  		{
  			fprintf(C, "%.8lf ", A[i][j]);
  		}
  		fprintf(C, "\n");
  	}
  	fclose(C);
  	strncat1(name);
  	X = fopen(name, "w");
  	if (X == NULL)
        {
            puts("Проблемы с открытием файла, попробуйте снова");
            return EXIT_FAILURE;
        }
  	for (i = 0; i<MAX_LETTER; i++)
  	{
  		for (j = 0; j<2; j++)
  		{
  			fprintf(X, "%.8lf ", B[i][j]);
  		}
  		fprintf(X, "\n");
  	}
  	fclose(X);
  	al_destroy_display(display);
  	al_destroy_event_queue(event_queue);
  	return 0;
  }
  /**
  @}
  */
