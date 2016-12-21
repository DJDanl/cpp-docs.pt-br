---
title: "strerror_s, _strerror_s, _wcserror_s, __wcserror_s | Microsoft Docs"
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
  - "__wcserror_s"
  - "_strerror_s"
  - "_wcserror_s"
  - "strerror_s"
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
  - "wcserror_s"
  - "__wcserror_s"
  - "_tcserror_s"
  - "_wcserror_s"
  - "tcserror_s"
  - "strerror_s"
  - "_strerror_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função __wcserror_s"
  - "Função _strerror_s"
  - "Função _tcserror_s"
  - "Função _wcserror_s"
  - "mensagens de erro, obtendo"
  - "mensagens de erro, imprimindo"
  - "imprimindo mensagens de erro"
  - "Função strerror_s"
  - "Função tcserror_s"
  - "Função wcserror_s"
ms.assetid: 9e5b15a0-efe1-4586-b7e3-e1d7c31a03d6
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strerror_s, _strerror_s, _wcserror_s, __wcserror_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Receber uma mensagem de erro do sistema \(`strerror_s`, `_wcserror_s`\) ou imprimir uma mensagem de erro fornecida pelo usuário \(`_strerror_s`, `__wcserror_s`\).  Essas são as versões de [strerror, \_strerror, \_wcserror, \_\_wcserror](../../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md) com aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t strerror_s(  
   char *buffer,  
   size_t numberOfElements,  
   int errnum   
);  
errno_t _strerror_s(  
   char *buffer,  
   size_t numberOfElements,  
   const char *strErrMsg   
);  
errno_t _wcserror_s(  
   wchar_t *buffer,  
   size_t numberOfElements,  
   int errnum   
);  
errno_t __wcserror_s(  
   wchar_t *buffer,  
   size_t numberOfElements,  
   const wchar_t *strErrMsg   
);  
template <size_t size>  
errno_t strerror_s(  
   char (&buffer)[size],  
   int errnum   
); // C++ only  
template <size_t size>  
errno_t _strerror_s(  
   char (&buffer)[size],  
   const char *strErrMsg   
); // C++ only  
template <size_t size>  
errno_t _wcserror_s(  
   wchar_t (&buffer)[size],  
   int errnum   
); // C++ only  
template <size_t size>  
errno_t __wcserror_s(  
   wchar_t (&buffer)[size],  
   const wchar_t *strErrMsg   
); // C++ only  
```  
  
#### Parâmetros  
 `buffer`  
 Buffer para armazenar a cadeia de caracteres de erro.  
  
 `numberOfElements`  
 Tamanho do buffer.  
  
 `errnum`  
 Número de erro.  
  
 `strErrMsg`  
 Mensagem fornecida pelo usuário.  
  
## Valor de retorno  
 Zero se tiver êxito, um código de erro ou falha.  
  
### Condições de erro  
  
|`buffer`|`numberOfElements`|`strErrMsg`|Conteúdo de `buffer`|  
|--------------|------------------------|-----------------|--------------------------|  
|`NULL`|any|any|n\/d|  
|any|0|any|não modificado|  
  
## Comentários  
 A função `strerror_s` é mapeada `errnum` para uma cadeia de caracteres de mensagem de erro, retornando a cadeia de caracteres em `buffer`.  `_strerror_s` não recebe o número do erro; usa o valor atual de `errno` para determinar a mensagem apropriada.  Nem `strerror_s` ou `_strerror_s` realmente imprime a mensagem: Para isso, você precisará chamar uma função de saída como [fprintf](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md):  
  
```  
if (( _access( "datafile",2 )) == -1 )  
{  
   _strerror_s(buffer, 80);  
   fprintf( stderr, buffer );  
}  
```  
  
 Se `strErrMsg` for `NULL`, `_strerror_s` retorna uma cadeia de caracteres em `buffer` que contém a mensagem de erro do sistema para a última chamada da biblioteca que gerou um erro.  A cadeia de caracteres da mensagem de erro é finalizada pelo caractere de nova linha \('\\n'\).  Se `strErrMsg` não é igual a `NULL`, então `_strerror_s` retorna uma cadeia de caracteres em `buffer` que contém \(em ordem\) sua mensagem de cadeia de caracteres, dois\-pontos, um espaço, a mensagem de erro do sistema para a última chamada de biblioteca gerando um erro, e um caractere de nova linha.  A mensagem de cadeia de caracteres pode ter, no máximo, 94 caracteres.  
  
 Essas funções truncarão a mensagem de erro se seu tamanho exceder `numberOfElements` \-1.  A cadeia de caracteres resultante em `buffer` sempre termina em nulo.  
  
 O número do erro real para `_strerror_s` é armazenado na variável [errno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  As mensagens de erro do sistema são acessadas por meio da variável [\_sys\_errlist](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md), que é uma matriz de mensagens ordenadas pelo número do erro.  `_strerror_s` acessa a mensagem de erro apropriada usando o valor de `errno` como um índice para a variável `_sys_errlist`.  O valor da variável [\_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) é definido como o número máximo de elementos na matriz `_sys_errlist`.  Para produzir resultados precisos, chame `_strerror_s` imediatamente depois que uma rotina de biblioteca é retornada com um erro.  Do contrário, as chamadas subsequentes para `strerror_s` ou `_strerror_s` poderão substituir o valor `errno`.  
  
 `_wcserror_s` e `__wcserror_s`são versões de caracteres largos de `strerror_s`e `_strerror_s`, respectivamente.  
  
 Essas funções validam seus parâmetros.  Se o buffer for `NULL` ou se o parâmetro de tamanho for 0, o manipulador de parâmetros inválidos será invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, as funções retornarão `EINVAL` e definirão `errno` como `EINVAL`.  
  
 `_strerror_s, _wcserror_s,` e `__wcserror_s` não fazem parte da definição de ANSI, mas são extensões da Microsoft.  Não use\-os onde a portabilidade é desejada; para compatibilidade ANSI, use `strerror_s` em vez disso.  
  
 No C\+\+, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD.  Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcserror_s`|`strerror_s`|`strerror_s`|`_wcserror_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strerror_s`, `_strerror_s`|\<string.h\>|  
|`_wcserror_s`, `__wcserror_s`|\<string.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [perror](../../c-runtime-library/reference/perror-wperror.md).  
  
## Equivalência do .NET Framework  
 [System::Exception::Message](https://msdn.microsoft.com/en-us/library/system.exception.message.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [clearerr](../../c-runtime-library/reference/clearerr.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [perror, \_wperror](../../c-runtime-library/reference/perror-wperror.md)