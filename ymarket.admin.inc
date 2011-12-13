<?php

function ymarket_settings_form($form_state){
  $values = variable_get('ymarket_settings', array());

  if (empty($values)) {
    drupal_set_message('Отсутствуют настройки Яндекс.Маркет. Сохраните настройки.', 'error');
  }

  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Информация о магизине'),
  );
  $form['fieldset']['name'] = array(
    '#type' => 'textfield',
    '#title' => 'Название магазина',
    '#description' => 'Короткое название магазина (название, которое выводится в списке найденных на Яндекс.Маркете товаров. Не должно содержать более 20 символов). Нельзя использовать слова, не имеющие отношения к наименованию магазина ("лучший", "дешевый"), указывать номер телефона и т.п. Название магазина, должно совпадать с фактическим названием магазина, которое публикуется на сайте. При несоблюдении данного требования наименование может быть изменено Яндексом самостоятельно без уведомления Клиента.',
    '#size' => '25',
    '#maxlength' => '20',
    '#default_value' => empty($values['name']) ? variable_get('site_name', '') : $values['name'],
    '#required' => TRUE,
  );
  $form['fieldset']['company'] = array(
    '#type' => 'textfield',
    '#title' => 'Компания',
    '#description' => 'Полное наименование компании, владеющей магазином. Не публикуется, используется для внутренней идентификации.',
    '#default_value' => empty($values['company']) ?  variable_get('site_name', '') : $values['company'],
  );
  $form['fieldset']['url'] = array(
    '#type' => 'textfield',
    '#title' => 'URL-адрес',
    '#description' => 'URL-адрес главной страницы магазина',
    '#default_value' => empty($values['url']) ? 'http://' . $_SERVER['HTTP_HOST'] : $values['url'],
    '#required' => TRUE,
  );
  $form['fieldset']['platform'] = array(
    '#type' => 'textfield',
    '#title' => 'CMS',
    '#description' => 'Система управления контентом, на основе которой работает магазин (CMS).',
    '#default_value' => empty($values['platform']) ? 'Drupal' : $values['platform'],
  );
  $form['fieldset']['version'] = array(
    '#type' => 'textfield',
    '#title' => 'Версия CMS',
    '#size' => '10',
    '#maxlength' => '10',
    '#default_value' => empty($values['version']) ? '6.x' : $values['version'],
  );
  $form['fieldset']['agency'] = array(
    '#type' => 'textfield',
    '#title' => 'Агенство',
    '#description' => 'Наименование агентства, которое оказывает техническую поддержку интернет-магазину и отвечает за работоспособность сайта.',
    '#default_value' => empty($values['agency']) ? '' : $values['agency'],
  );
  $form['fieldset']['email'] = array(
    '#type' => 'textfield',
    '#title' => 'Электронный адрес',
    '#description' => 'Контактный адрес разработчиков CMS или агентства, осуществляющего техподдержку.',
    '#default_value' => empty($values['email']) ? variable_get('site_mail', '') : $values['email'],
    '#required' => TRUE,
  );

  // Все словари
  $vocabs_data = taxonomy_get_vocabularies();
  $vocabs_options = array('' => 'Выберите...');
  foreach ($vocabs_data as $vid => $vocab) {
    $vocabs_options[$vid] = $vocab->name;
  }

  // Словарь категорий
  $form['fieldset']['vid'] = array(
    '#type' => 'select',
    '#title' => 'Словарь категорий каталога',
    '#description' => 'Выберите словарь, который представляет категории товаров, публикуемых в маркете.',
    '#options' => $vocabs_options,
    '#default_value' => empty($values['vid']) ? '' : $values['vid'],
    '#required' => TRUE,
  );

  // Словарь производителей
  $vocabs_options[''] = 'Нет производителя';
  $form['fieldset']['vendor_vid'] = array(
    '#type' => 'select',
    '#title' => 'Словарь производителей',
    '#description' => 'Выберите словарь, который содержит производителей публикуемого товара.',
    '#options' => $vocabs_options,
    '#default_value' => empty($values['vendor_vid']) ? '' : $values['vendor_vid'],
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function ymarket_settings_form_validate(&$form, $form_state){

}

function ymarket_settings_form_submit(&$form, $form_state){
  variable_set('ymarket_settings', $form_state['values']);
  drupal_set_message('Настройки сохранены.');
}
