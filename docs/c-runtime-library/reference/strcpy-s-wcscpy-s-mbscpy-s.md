---
title: "strcpy_s, wcscpy_s, _mbscpy_s | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "wcscpy_s"
  - "_mbscpy_s"
  - "strcpy_s"
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
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "strcpy_s"
  - "_mbscpy_s"
  - "_tcscpy_s"
  - "wcscpy_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função strcpy_s"
  - "Função _tcscpy_s"
  - "Função _mbscpy_s"
  - "copiando cadeias de caracteres"
  - "cadeias de caracteres [C++], copiando"
  - "Função tcscpy_s"
  - "Função wcscpy_s"
ms.assetid: 611326f3-7929-4a5d-a465-a4683af3b053
caps.latest.revision: 41
caps.handback.revision: 41
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strcpy_s, wcscpy_s, _mbscpy_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Copia uma cadeia de caracteres. Essas versões do [strcpy, wcscpy, \_mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  `_mbscpy_s` não pode ser usado em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
errno_t strcpy_s(  
   char *strDestination,  
   size_t numberOfElements,  
   const char *strSource   
);  
errno_t wcscpy_s(  
   wchar_t *strDestination,  
   size_t numberOfElements,  
   const wchar_t *strSource   
);  
errno_t _mbscpy_s(  
   unsigned char *strDestination,  
   size_t numberOfElements,  
   const unsigned char *strSource   
);  
template <size_t size>  
errno_t strcpy_s(  
   char (&strDestination)[size],  
   const char *strSource   
); // C++ only  
template <size_t size>  
errno_t wcscpy_s(  
   wchar_t (&strDestination)[size],  
   const wchar_t *strSource   
); // C++ only  
template <size_t size>  
errno_t _mbscpy_s(  
   unsigned char (&strDestination)[size],  
   const unsigned char *strSource   
); // C++ only  
```  
  
#### Parâmetros  
 `strDestination`  
 Local do buffer de cadeia de caracteres de destino.  
  
 `numberOfElements`  
 Tamanho do buffer de cadeia de caracteres de destino em `char` unidades para funções estreitas e de vários bytes, e `wchar_t` unidades para funções amplas.  
  
 `strSource`  
 Buffer de cadeia de caracteres de origem com terminação nula.  
  
## Valor de retorno  
 Zero se tiver êxito; Caso contrário, um erro.  
  
### Condições de erro  
  
|`strDestination`|`numberOfElements`|`strSource`|Valor de retorno|Conteúdo de `strDestination`|  
|----------------------|------------------------|-----------------|----------------------|----------------------------------|  
|`NULL`|qualquer|qualquer|`EINVAL`|não modificado|  
|qualquer|qualquer|`NULL`|`EINVAL`|`strDestination`\[0\] definido como 0|  
|qualquer|0 ou muito pequeno|qualquer|`ERANGE`|`strDestination`\[0\] definido como 0|  
  
## Comentários  
 O `strcpy_s` função copia o conteúdo no endereço do `strSource`, incluindo o caractere de terminação nula, para o local especificado pelo `strDestination`. A cadeia de caracteres de destino deve ser grande o suficiente para manter a cadeia de caracteres de origem e o caractere de terminação nula. O comportamento de `strcpy_s` é indefinido se sobreponham as cadeias de caracteres de origem e de destino.  
  
 `wcscpy_s` é a versão de caractere largo de `strcpy_s`, e `_mbscpy_s` é a versão de caracteres multibyte. O valor de retorno e argumentos `wcscpy_s` são caracteres largos cadeias de caracteres; desses `_mbscpy_s` são cadeias de caracteres multibyte. Essas três funções se comportam de forma idêntica caso contrário.  
  
 Se `strDestination` ou `strSource` é um ponteiro nulo, ou se a cadeia de caracteres de destino é muito pequena, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornam `EINVAL` e defina `errno` para `EINVAL` quando `strDestination` ou `strSource` é um ponteiro nulo, e retornam `ERANGE` e defina `errno` para `ERANGE` quando a cadeia de caracteres de destino é muito pequena.  
  
 Após a execução bem\-sucedida, a cadeia de caracteres de destino é sempre terminada em nulo.  
  
 Em C\+\+, uso dessas funções é simplificado pela sobrecargas de modelo que podem inferir o comprimento do buffer automaticamente para que você não precisa especificar um argumento de tamanho e eles podem substituir automaticamente funções mais antigas e menos seguras com suas contrapartes mais recentes e mais seguros. Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 As versões de depuração dessas funções primeiro preenchem o buffer com 0xFE. Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tcscpy_s`|`strcpy_s`|`_mbscpy_s`|`wcscpy_s`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strcpy_s`|\< h \>|  
|`wcscpy_s`|\< h \> ou \< WCHAR \>|  
|`_mbscpy_s`|\< mbstring.h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strcpy_s.cpp  
// This program uses strcpy_s and strcat_s  
// to build a phrase.  
//  
  
#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( void )  
{  
   char string[80];  
   // using template versions of strcpy_s and strcat_s:  
   strcpy_s( string, "Hello world from " );  
   strcat_s( string, "strcpy_s " );  
   strcat_s( string, "and " );  
   // of course we can supply the size explicitly if we want to:  
   strcat_s( string, _countof(string), "strcat_s!" );  
  
   printf( "String = %s\n", string );  
}  
```  
  
```Output  
Cadeia de caracteres = Olá mundo de strcpy_s e strcat_s!  
```  
  
## Equivalência do .NET Framework  
 [System::String::Copy](https://msdn.microsoft.com/en-us/library/system.string.copy.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [strcat, wcscat, \_mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strncat\_s, \_strncat\_s\_l, wcsncat\_s, \_wcsncat\_s\_l, \_mbsncat\_s, \_mbsncat\_s\_l](../../c-runtime-library/reference/strncat-s-strncat-s-l-wcsncat-s-wcsncat-s-l-mbsncat-s-mbsncat-s-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [strncpy\_s, \_strncpy\_s\_l, wcsncpy\_s, \_wcsncpy\_s\_l, \_mbsncpy\_s, \_mbsncpy\_s\_l](../Topic/strncpy_s,%20_strncpy_s_l,%20wcsncpy_s,%20_wcsncpy_s_l,%20_mbsncpy_s,%20_mbsncpy_s_l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)