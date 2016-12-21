---
title: "_strtime_s, _wstrtime_s | Microsoft Docs"
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
  - "_wstrtime_s"
  - "_strtime_s"
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
  - "_wstrtime_s"
  - "strtime_s"
  - "wstrtime_s"
  - "_strtime_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _strtime_s"
  - "Função _wstrtime_s"
  - "copiando a hora em buffers"
  - "Função strtime_s"
  - "hora, copiando"
  - "Função wstrtime_s"
ms.assetid: 42acf013-c334-485d-b610-84c0af8a46ec
caps.latest.revision: 25
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strtime_s, _wstrtime_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Copie a hora atuais para um buffer.  Essas são versões de [\_strtime, \_wstrtime](../Topic/_strtime,%20_wstrtime.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _strtime_s(  
   char *buffer,  
   size_t numberOfElements  
);  
errno_t _wstrtime_s(  
   wchar_t *buffer,  
   size_t numberOfElements  
);  
template <size_t size>  
errno_t _strtime_s(  
   char (&buffer)[size]  
); // C++ only  
template <size_t size>  
errno_t _wstrtime_s(  
   wchar_t (&buffer)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `buffer`  
 Um buffer, pelo menos 10 bytes, onde a hora serão gravados.  
  
 \[entrada\] `numberOfElements`  
 O tamanho do buffer.  
  
## Valor de retorno  
 Nulo se com êxito.  
  
 Se uma condição de erro ocorrer, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  O valor de retorno é um código de erro se houver uma falha.  Os códigos de erro são definidos em ERRNO.H; consulte a tabela a seguir para erros exatos gerados por essa função.  Para obter mais informações sobre códigos de erro, consulte [constantes de errno](../../c-runtime-library/errno-constants.md).  
  
### Condições de erro  
  
|`buffer`|`numberOfElements`|Return|Conteúdo de `buffer`|  
|--------------|------------------------|------------|--------------------------|  
|`NULL`|\(nenhum\)|`EINVAL`|Não modificados|  
|Não `NULL` \(que aponta para o buffer válido\)|0|`EINVAL`|Não modificados|  
|Não `NULL` \(que aponta para o buffer válido\)|0 \< tamanhos \< 9|`EINVAL`|Cadeia de caracteres vazia|  
|Não `NULL` \(que aponta para o buffer válido\)|Tamanho \> 9|0|Hora atuais formatadas conforme especificado em comentários|  
  
## Problemas de segurança  
 Passar um valor não nulo inválido para o buffer resultará em uma violação de acesso se o parâmetro de `numberOfElements` é maior que 9.  
  
 Passe um valor para `numberOfElements` que seja maior que o tamanho real do buffer resultará em excesso de buffer.  
  
## Comentários  
 Essas funções fornecem versões mais seguro de `_strtime` e de `_wstrtime`.  A função de `_strtime_s` copia a hora local atual no buffer apontado por `timestr`*.* A hora é formatada como `hh:mm:ss` onde `hh` são dois dígitos que representam a hora na notação de 24 horas, `mm` são dois dígitos que representam os minutos depois da hora, e `ss` são dois dígitos que representam segundos.  Por exemplo, a cadeia de caracteres `18:23:44` representa 23 minutos e 44 segundos depois de 6 PM. O buffer deve ser pelo menos 9 bytes; o tamanho real é especificado pelo segundo parâmetro.  
  
 `_wstrtime` é uma versão de ampla caractere de `_strtime`; o argumento e o valor de retorno de `_wstrtime` são cadeias de caracteres de ampla caractere.  Essas funções se comportam exatamente o contrário.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamento de rotina de Genérico\- texto:  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tstrtime_s`|`_strtime_s`|`_strtime_s`|`_wstrtime_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strtime_s`|\<time.h\>|  
|`_wstrtime_s`|\<time.h ou\> wchar.h \<\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// strtime_s.c  
  
#include <time.h>  
#include <stdio.h>  
  
int main()  
{  
    char tmpbuf[9];  
    errno_t err;  
  
    // Set time zone from TZ environment variable. If TZ is not set,  
    // the operating system is queried to obtain the default value   
    // for the variable.   
    //  
    _tzset();  
  
    // Display operating system-style date and time.   
    err = _strtime_s( tmpbuf, 9 );  
    if (err)  
    {  
       printf("_strdate_s failed due to an invalid argument.");  
      exit(1);  
    }  
    printf( "OS time:\t\t\t\t%s\n", tmpbuf );  
    err = _strdate_s( tmpbuf, 9 );  
    if (err)  
    {  
       printf("_strdate_s failed due to an invalid argument.");  
       exit(1);  
    }  
    printf( "OS date:\t\t\t\t%s\n", tmpbuf );  
  
}  
```  
  
  **Hora do sistema operacional:            14:37: 49**  
**Data do sistema operacional:            04\/25\/03**   
## Equivalência do .NET Framework  
  
-   [System::DateTime::ToLongDateString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongdatestring.aspx)  
  
-   [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx)  
  
-   [System::DateTime::ToShortDateString](https://msdn.microsoft.com/en-us/library/system.datetime.toshortdatestring.aspx)  
  
-   [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx)  
  
-   [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [\_tzset](../Topic/_tzset.md)