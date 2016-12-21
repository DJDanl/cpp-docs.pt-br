---
title: "strerror, _strerror, _wcserror, __wcserror | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "strerror"
  - "_strerror"
  - "_wcserror"
  - "__wcserror"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "__sys_errlist"
  - "wcserror"
  - "_strerror"
  - "__wcserror"
  - "strerror"
  - "__sys_nerr"
  - "_tcserror"
  - "_wcserror"
  - "tcserror"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "__sys_errlist"
  - "__sys_nerr"
  - "Função __wcserror"
  - "Função _strerror"
  - "Função _tcserror"
  - "Função _wcserror"
  - "mensagens de erro, obtendo"
  - "mensagens de erro, imprimindo"
  - "imprimindo mensagens de erro"
  - "Função strerror"
  - "Função tcserror"
  - "Função wcserror"
ms.assetid: 27b72255-f627-43c0-8836-bcda8b003e14
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strerror, _strerror, _wcserror, __wcserror
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém uma cadeia de caracteres de mensagens de erro do sistema \(`strerror`, `_wcserror`\) ou formata uma cadeia caracteres de mensagens de erro fornecida pelo usuário \(`_strerror`, `__wcserror`\).  Estão disponíveis versões mais seguras dessas funções; consulte [strerror\_s, \_strerror\_s, \_wcserror\_s, \_\_wcserror\_s](../../c-runtime-library/reference/strerror-s-strerror-s-wcserror-s-wcserror-s.md).  
  
## Sintaxe  
  
```  
char *strerror(    int errnum  ); char *_strerror(    const char *strErrMsg  ); wchar_t * _wcserror(    int errnum  ); wchar_t * __wcserror(    const wchar_t *strErrMsg  );  
```  
  
#### Parâmetros  
 `errnum`  
 Número do erro.  
  
 `strErrMsg`  
 Mensagem fornecida pelo usuário.  
  
## Valor de retorno  
 Todas essas funções retornam um ponteiro para a cadeia de caracteres de mensagens de erro.  Chamadas subsequentes podem substituir a cadeia de caracteres.  
  
## Comentários  
 A função `strerror` mapeia `errnum` para uma cadeia de caracteres de mensagens de erro e retorna um ponteiro para a cadeia de caracteres.  O `strerror` nem `_strerror` imprimem a mensagem: Para isso, é preciso chamar uma função de saída como [fprintf](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md):  
  
```  
if (( _access( "datafile",2 )) == -1 )  
   fprintf( stderr, _strerror(NULL) );  
```  
  
 Se `strErrMsg` for passado como `NULL`, `_strerror` retorna um ponteiro para uma cadeia de caracteres que contém a mensagem de erro do sistema para a última chamada da biblioteca que produziu um erro.  A cadeia de caracteres de mensagens de erro é encerrada pelo caractere newline \('\\n'\).  Se `strErrMsg` não for igual a `NULL`, então `_strerror` retorna um ponteiro para uma cadeia de caracteres que contém \(nessa ordem\) sua mensagem de cadeia de caracteres, dois\-pontos, um espaço, a mensagem de erro do sistema para a última chamada da biblioteca que produz um erro e um caractere newline.  Sua mensagem da cadeia de caracteres pode ter, no máximo, 94 caracteres de comprimento.  
  
 O número do erro real para `_strerror` é armazenado na variável [errno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  Para produzir resultados precisos, chame `_strerror` imediatamente após uma rotina da biblioteca retornar um erro.  Caso contrário, chamadas subsequentes para `strerror` ou `_strerror` podem substituir o valor `errno`.  
  
 `_wcserror` e `__wcserror` são versões de caractere largo de `strerror` e `_strerror`, respectivamente.  
  
 `_strerror`, `_wcserror` e `__wcserror` não fazem parte da definição de ANSI; elas são extensões da Microsoft e recomendamos que não sejam utilizadas onde você deseja usar código portátil.  No caso de compatibilidade com ANSI, ao invés disso, use `strerror`.  
  
 Para obter cadeias de caracteres de erros, recomendamos `strerror` ou `_wcserror` ao invés dos macros preteridos [\_sys\_errlist](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) e [\_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) e das funções internas preteridas `__sys_errlist` e `__sys_nerr`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcserror`|`strerror`|`strerror`|`_wcserror`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strerror`|\<string.h\>|  
|`_strerror`|\<string.h\>|  
|`_wcserror`, `__wcserror`|\<string.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Veja o exemplo de [perror](../../c-runtime-library/reference/perror-wperror.md).  
  
## Equivalência do .NET Framework  
 [System::Exception::Message](https://msdn.microsoft.com/en-us/library/system.exception.message.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [clearerr](../../c-runtime-library/reference/clearerr.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [perror, \_wperror](../../c-runtime-library/reference/perror-wperror.md)