---
title: "_strdate_s, _wstrdate_s | Microsoft Docs"
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
  - "_strdate_s"
  - "_wstrdate_s"
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
  - "api-ms-win-crt-time-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_strdate_s"
  - "wstrdate_s"
  - "_wstrdate_s"
  - "strdate_s"
  - "_tstrdate_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "datas, copiando"
  - "Função tstrdate_s"
  - "Função wstrdate_s"
  - "Função _tstrdate_s"
  - "Função strdate_s"
  - "copiando datas"
  - "Função _strdate_s"
  - "Função _wstrdate_s"
ms.assetid: d41d8ea9-e5ce-40d4-864e-1ac29b455991
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strdate_s, _wstrdate_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Copie a data atual do sistema para um buffer.  Essas são versões de [\_strdate, \_wstrdate](../../c-runtime-library/reference/strdate-wstrdate.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _strdate_s(  
   char *buffer,  
   size_t numberOfElements  
);  
errno_t _wstrdate_s(  
   wchar_t *buffer,  
   size_t numberOfElements  
);  
template <size_t size>  
errno_t _strdate_s(  
   char (&buffer)[size]  
); // C++ only  
template <size_t size>  
errno_t _wstrdate_s(  
   wchar_t (&buffer)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `buffer`  
 Um ponteiro para um buffer que é preenchido com a cadeia de caracteres de data formatada.  
  
 \[entrada\] `numberOfElements`  
 O tamanho do buffer.  
  
## Valor de retorno  
 Nulo se com êxito.  O valor de retorno é um código de erro se houver uma falha.  Os códigos de erro são definidos em ERRNO.H; consulte a tabela abaixo para erros exatos gerados por essa função.  Para obter mais informações sobre códigos de erro, consulte [errno](../../c-runtime-library/errno-constants.md).  
  
## Condições de erro  
  
|`buffer`|`numberOfElements`|Return|Conteúdo de `buffer`|  
|--------------|------------------------|------------|--------------------------|  
|`NULL`|\(nenhum\)|`EINVAL`|Não modificados|  
|Não `NULL` \(que aponta para o buffer válido\)|0|`EINVAL`|Não modificados|  
|Não `NULL` \(que aponta para o buffer válido\)|0 \< `numberOfElements` \< 9|`EINVAL`|Cadeia de caracteres vazia|  
|Não `NULL` \(que aponta para o buffer válido\)|`numberOfElements` \>\= 9|0|Data atual formatada como especificado em comentários|  
  
## Problemas de segurança  
 Passe não em um valor inválido de `NULL` para o buffer resultará em uma violação de acesso se o parâmetro de `numberOfElements` é maior que 9.  
  
 Passar valores para o tamanho que seja maior que o tamanho real de `buffer` resultará em excesso de buffer.  
  
## Comentários  
 Essas funções fornecem versões mais seguro de `_strdate` e de `_wstrdate`.  A função de `_strdate_s` copia a data atual do sistema ao buffer apontado por `buffer`, formatada `mm`\/`dd`\/`yy`, onde `mm` são dois dígitos que representam o mês, `dd` são dois dígitos que representam o dia, e `yy` é os últimos dois dígitos do ano.  Por exemplo, a cadeia de caracteres `12/05/99` representa o 5 de dezembro de 1999.  O buffer deve ser pelo menos 9 caracteres por muito tempo.  
  
 `_wstrdate_s` é uma versão de ampla caractere de `_strdate_s`; o argumento e o valor de retorno de `_wstrdate_s` são cadeias de caracteres de ampla caractere.  Essas funções se comportam exatamente o contrário.  
  
 Se `buffer` é um ponteiro de `NULL` , ou se `numberOfElements` for menor que 9 caracteres, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, essas funções retornam \-1 e `errno` definido como `EINVAL` se o buffer é `NULL` ou se `numberOfElements` é menor ou igual a 0, ou o conjunto `errno` a `ERANGE` se `numberOfElements` for menor que 9.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamento de rotina de Genérico\- texto:  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tstrdate_s`|`_strdate_s`|`_strdate_s`|`_wstrdate_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strdate`|\<time.h\>|  
|`_wstrdate`|\<time.h ou\> wchar.h \<\>|  
|`_strdate_s`|\<time.h\>|  
  
## Exemplo  
 Consulte o exemplo de [hora](../Topic/time,%20_time32,%20_time64.md).  
  
## Equivalência do .NET Framework  
 [System::DateTime::Parse](https://msdn.microsoft.com/en-us/library/system.datetime.parse.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [\_tzset](../Topic/_tzset.md)