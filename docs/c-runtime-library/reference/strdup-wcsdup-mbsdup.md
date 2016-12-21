---
title: "_strdup, _wcsdup, _mbsdup | Microsoft Docs"
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
  - "_strdup"
  - "_mbsdup"
  - "_wcsdup"
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
  - "_tcsdup"
  - "mbsdup"
  - "_mbsdup"
  - "_strdup"
  - "_ftcsdup"
  - "_wcsdup"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função wcsdup"
  - "Função ftcsdup"
  - "Função _ftcsdup"
  - "Função mbsdup"
  - "Função strdup"
  - "Função _strdup"
  - "Função _wcsdup"
  - "copiando cadeias de caracteres"
  - "duplicando cadeias de caracteres"
  - "cadeias de caracteres [C++], copiando"
  - "Função _mbsdup"
  - "cadeias de caracteres [C++], duplicando"
  - "Função tcsdup"
  - "Função _tcsdup"
ms.assetid: 8604f8bb-95e9-45d3-93ef-20397ebf247a
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strdup, _wcsdup, _mbsdup
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cadeias de caracteres de duplicatas.  
  
> [!IMPORTANT]
>  `_mbsdup` não pode ser usado em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *_strdup(  
   const char *strSource   
);  
wchar_t *_wcsdup(  
   const wchar_t *strSource   
);  
unsigned char *_mbsdup(  
   const unsigned char *strSource   
);  
```  
  
#### Parâmetros  
 `strSource`  
 Cadeia de caracteres de origem com terminação nula.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o local de armazenamento para a cadeia de caracteres copiada ou `NULL` se o armazenamento não pode ser alocado.  
  
## Comentários  
 O `_strdup` chamadas de função [malloc](../../c-runtime-library/reference/malloc.md) para alocar espaço de armazenamento para uma cópia de `strSource` e, em seguida, copia `strSource` para o espaço alocado.  
  
 `_wcsdup` e `_mbsdup` são versões de caractere largo e caracteres multibyte `_strdup`. O valor de retorno e argumentos `_wcsdup` são caracteres largos cadeias de caracteres; desses `_mbsdup` são cadeias de caracteres multibyte. Essas três funções se comportam de forma idêntica caso contrário.  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tcsdup`|`_strdup`|`_mbsdup`|`_wcsdup`|  
  
 Porque `_strdup` chamadas `malloc` para alocar espaço de armazenamento para a cópia do `strSource`, é recomendável sempre para liberar essa memória chamando o [livre](../../c-runtime-library/reference/free.md) rotina no ponteiro retornado pela chamada para `_strdup`.  
  
 Se `_DEBUG` e `_CRTDBG_MAP_ALLOC` são definidos, `_strdup` e `_wcsdup` são substituídos por chamadas para `_strdup_dbg` e `_wcsdup_dbg` para permitir a depuração de alocações de memória. Para obter mais informações, consulte [\_strdup\_dbg, \_wcsdup\_dbg](../Topic/_strdup_dbg,%20_wcsdup_dbg.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strdup`|\< h \>|  
|`_wcsdup`|\< h \> ou \< WCHAR \>|  
|`_mbsdup`|\< mbstring.h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strdup.c  
  
#include <string.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char buffer[] = "This is the buffer text";  
   char *newstring;  
   printf( "Original: %s\n", buffer );  
   newstring = _strdup( buffer );  
   printf( "Copy:     %s\n", newstring );  
   free( newstring );  
}  
```  
  
```Output  
Original: É o texto de buffer cópia: esse é o texto de buffer  
```  
  
## Equivalência do .NET Framework  
 [System::String::clone](https://msdn.microsoft.com/en-us/library/system.string.clone.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [memset, wmemset](../../c-runtime-library/reference/memset-wmemset.md)   
 [strcat, wcscat, \_mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strncat, \_strncat\_l, wcsncat, \_wcsncat\_l, \_mbsncat, \_mbsncat\_l](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [strncpy, \_strncpy\_l, wcsncpy, \_wcsncpy\_l, \_mbsncpy, \_mbsncpy\_l](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)