/**
 * Валидация XML документов.
 *
 * @param xmlFile
 *   Абсолютный путь к файлу.
*/
function validateXML(xmlFile) {
  var message;
  var result = false;

  if (document.implementation.createDocument) {
      // Mozilla, Firefox, Opera, etc.
      message  = "Ваш браузер не поддерживает валидацию XML документов.\n";
      message += "Откройте страницу в Microsoft Internet Explorer.";
  }
  else {
      // MSIE
      if (xmlFile) {
          var xmlDoc = new ActiveXObject("Microsoft.XMLDOM");

          with (xmlDoc) {
              xmlDoc.async = false;
              xmlDoc.validateOnParse = true;
              xmlDoc.load(xmlFile);
          }

          with (document) {
              if ( xmlDoc.parseError.errorCode ) {
                  message  = "XML документ не соответсвует DTD.\n";
                  message += "Ошибка: " + "cтрока: " + xmlDoc.parseError.line + ", колонка: " + xmlDoc.parseError.linepos + ". Перед " + xmlDoc.parseError.srcText + "\n";
                  message += "Причина: " + xmlDoc.parseError.reason + "\n";
              }
              else {
                  result  = true;
                  message = "XML документ \"" + xmlFile + "\" соответствует DTD.";
              }
          }
      }
      else {
          message = "Не удаётся открыть файл.";
      }
  }

  return {
    "result" : result,
    "message": message
  };
}

function executeValidation(xmlFile, target) {
  var data      = validateXML(xmlFile);
  var className = data.result ? "status" : "error";
  (function($) {
    target = $(target);
    target.addClass(className);
    target.text(data.message);
  })(jQuery);
}
