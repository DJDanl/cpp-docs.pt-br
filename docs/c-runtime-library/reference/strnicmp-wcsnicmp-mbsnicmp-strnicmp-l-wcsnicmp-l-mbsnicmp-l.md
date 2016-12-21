---
title: "_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l | Microsoft Docs"
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
  - "_wcsnicmp"
  - "_strnicmp_l"
  - "_wcsnicmp_l"
  - "_strnicmp"
  - "_mbsnicmp"
  - "_mbsnicmp_l"
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
  - "wcsnicmp_l"
  - "_strnicmp"
  - "_ftcsnicmp"
  - "mbsnicmp_l"
  - "_ftcsncicmp"
  - "mbsnicmp"
  - "_tcsncicmp"
  - "_mbsnicmp"
  - "_tcsnicmp"
  - "strnicmp_l"
  - "_wcsnicmp"
  - "_wcsnicmp_l"
  - "CORECRT_WSTRING/_wcsnicmp"
  - "CORECRT_WSTRING/_wcsnicmp_l"
  - "string/_strnicmp"
  - "string/_strnicmp_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftcsncicmp"
  - "Função _ftcsnicmp"
  - "Função _mbsnicmp"
  - "Função _mbsnicmp_l"
  - "Função _strnicmp"
  - "Função _strnicmp_l"
  - "Função _tcsncicmp"
  - "Função _tcsnicmp"
  - "Função _wcsnicmp"
  - "Função _wcsnicmp_l"
  - "caracteres [C++], comparando"
  - "Função ftcsncicmp"
  - "Função ftcsnicmp"
  - "Função mbsnicmp"
  - "Função mbsnicmp_l"
  - "comparação de cadeias de caracteres [C++], minúsculas"
  - "comparação de cadeias de caracteres [C++], Função strncmp"
  - "cadeias de caracteres [C++], comparando caracteres de"
  - "Função strncmp"
  - "Função strnicmp_l"
  - "Função tcsncicmp"
  - "Função tcsnicmp"
  - "Função wcsnicmp"
  - "Função wcsnicmp_l"
ms.assetid: df6e5037-4039-4c85-a0a6-21d4ef513966
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara o número especificado de caracteres de duas cadeias de caracteres sem considerar o caso.  
  
> [!IMPORTANT]
>  `_mbsnicmp` e `_mbsnicmp_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _strnicmp(  
   const char *string1,  
   const char *string2,  
   size_t count   
);  
int _wcsnicmp(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count   
);  
int _mbsnicmp(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _strnicmp_l(  
   const char *string1,  
   const char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _wcsnicmp_l(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count,  
   _locale_t locale  
);  
int _mbsnicmp_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `string1, string2`  
 Caracteres de terminação nula para comparar.  
  
 `count`  
 Número de caracteres a ser comparado.  
  
 `locale`  
 Localidade a usar.  
  
## Valor de retorno  
 Indica a relação entre as subcadeias de caracteres, da seguinte maneira.  
  
|Valor de retorno|Descrição|  
|----------------------|---------------|  
|\< 0|`string1` subcadeia de caracteres é menor que `string2` subcadeia de caracteres.|  
|0|`string1` subcadeia de caracteres é idêntica à `string2` subcadeia de caracteres.|  
|\> 0|`string1` subcadeia de caracteres é maior que `string2` subcadeia de caracteres.|  
  
 Em um erro de validação de parâmetro, essas funções retornam `_NLSCMPERROR`, que é definido em \< String. h \> e \< mbstring.h \>.  
  
## Comentários  
 O `_strnicmp` função ordinalmente compara, no máximo, o primeiro `count` caracteres de `string1` e `string2`.  A comparação é executada sem considerar o caso, convertendo cada caractere em minúsculas.  `_strnicmp` é uma versão de maiúsculas e minúsculas do `strncmp`.  A comparação termina se um caractere nulo de terminação for atingido na cadeia de caracteres antes de `count` caracteres são comparados.  Se as cadeias de caracteres são iguais quando um caractere nulo de terminação for alcançado na cadeia de caracteres antes de `count` caracteres são comparados, a cadeia de caracteres mais curta é menor.  
  
 Os caracteres de 91 a 96 na tabela ASCII \('\[', ' \\', '\]', ' ^', '\_' e ' '\) avaliar como menor que qualquer caractere alfabético.  Essa ordem é idêntico de `stricmp`.  
  
 `_wcsnicmp` e `_mbsnicmp` são versões de caractere largo e caracteres multibyte `_strnicmp`.  Os argumentos de `_wcsnicmp` são caracteres largos cadeias de caracteres; desses `_mbsnicmp` são cadeias de caracteres multibyte.  `_mbsnicmp` reconhece sequências de caracteres multibyte de acordo com a página de código multibyte atual e retorna `_NLSCMPERROR` em caso de erro.  Para obter mais informações, consulte [Páginas de código](../../c-runtime-library/code-pages.md).  Essas três funções comportam idêntico caso contrário.  Essas funções são afetadas pela configuração da localidade — as versões que não têm o `_l` usam a localidade atual do sufixo para seu comportamento depende da localidade; as versões que têm o `_l` sufixo em vez disso, use o `locale` que é passado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Todas essas funções validam seus parâmetros.  Se `string1` ou `string2` é um ponteiro nulo, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsncicmp`|`_strnicmp`|`_mbsnicmp`|`_wcsnicmp`|  
|`_tcsnicmp`|`_strnicmp`|`_mbsnbicmp`|`_wcsnicmp`|  
|`_tcsncicmp_l`|`_strnicmp_l`|`_mbsnicmp_l`|`_wcsnicmp_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strnicmp`, `_strnicmp_l`|\<string.h\>|  
|`_wcsnicmp`, `_wcsnicmp_l`|\<string.h\> ou \<wchar.h\>|  
|`_mbsnicmp`, `_mbsnicmp_l`|\<mbstring.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Veja o exemplo de [strncmp](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md).  
  
## Equivalência do .NET Framework  
 [System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [strcat, wcscat, \_mbscat](../../c-runtime-library/reference/strcat-wcscat-mbscat.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [strcpy, wcscpy, \_mbscpy](../../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)   
 [strncat, \_strncat\_l, wcsncat, \_wcsncat\_l, \_mbsncat, \_mbsncat\_l](../../c-runtime-library/reference/strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [strncpy, \_strncpy\_l, wcsncpy, \_wcsncpy\_l, \_mbsncpy, \_mbsncpy\_l](../../c-runtime-library/reference/strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)   
 [strrchr, wcsrchr, \_mbsrchr, \_mbsrchr\_l](../../c-runtime-library/reference/strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)   
 [\_strset, \_strset\_l, \_wcsset, \_wcsset\_l, \_mbsset, \_mbsset\_l](../../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)