---
title: "_strnicoll, _wcsnicoll, _mbsnicoll, _strnicoll_l, _wcsnicoll_l, _mbsnicoll_l | Microsoft Docs"
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
  - "_mbsnicoll_l"
  - "_mbsnicoll"
  - "_wcsnicoll_l"
  - "_strnicoll"
  - "_strnicoll_l"
  - "_wcsnicoll"
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
  - "wcshicoll_l"
  - "_ftcsncicoll"
  - "strnicoll_l"
  - "_wcsnicoll"
  - "mbsnicoll_l"
  - "_strnicoll"
  - "mbsnicoll"
  - "_ftcsnicoll"
  - "wcsnicoll"
  - "_tcsnicoll"
  - "_mbsnicoll"
  - "strinicoll"
  - "_tcsncicoll"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftcsncicoll"
  - "Função _ftcsnicoll"
  - "Função _mbsnicoll"
  - "Função _mbsnicoll_l"
  - "Função _strnicoll"
  - "Função _strnicoll_l"
  - "Função _tcsncicoll"
  - "Função _tcsnicoll"
  - "Função _wcsnicoll"
  - "Função _wcsnicoll_l"
  - "páginas de código, usando para comparações de cadeias de caracteres"
  - "Função ftcsncicoll"
  - "Função ftcsnicoll"
  - "Função mbsnicoll"
  - "Função mbsnicoll_l"
  - "cadeias de caracteres [C++], comparando por página de código"
  - "Função strnicoll"
  - "Função strnicoll_l"
  - "Função tcsncicoll"
  - "Função tcsnicoll"
  - "Função wcsnicoll"
  - "Função wcsnicoll_l"
ms.assetid: abf0c569-725b-428d-9ff2-924f430104b4
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strnicoll, _wcsnicoll, _mbsnicoll, _strnicoll_l, _wcsnicoll_l, _mbsnicoll_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara as cadeias de caracteres usando informações específicas da localidade.  
  
> [!IMPORTANT]
>  `_mbsnicoll` e `_mbsnicoll_l` não podem ser usados em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _strnicoll(  
   const char *string1,  
   const char *string2,  
   size_t count   
);  
int _wcsnicoll(  
   const wchar_t *string1,  
   const wchar_t *string2 ,  
   size_t count   
);  
int _mbsnicoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _strnicoll_l(  
   const char *string1,  
   const char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _wcsnicoll_l(  
   const wchar_t *string1,  
   const wchar_t *string2 ,  
   size_t count,  
   _locale_t locale  
);  
int _mbsnicoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `string1, string2`  
 Cadeias de caracteres terminadas com Null para comparação  
  
 `count`  
 Número de caracteres para comparação.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um valor que indica a relação de subcadeias de `string1` e `string2`*,* conforme a seguir  
  
|Valor de retorno|Relação de string1 com string2|  
|----------------------|------------------------------------|  
|\< 0|`string1` menor que `string2`|  
|0|`string1` idêntico a `string2`|  
|\> 0|`string1` maior que `string2`|  
  
 Cada uma dessas funções retorna `_NLSCMPERROR`.  Para usar `_NLSCMPERROR`, inclua STRING.H ou MBSTRING.H.  `_wcsnicoll` pode falhar se `string1` ou `string2` contiver código de caracteres largos fora do domínio da sequência de agrupamento.  Quando ocorre um erro, `_wcsnicoll` pode definir `errno` como `EINVAL`.  Para verificar se há um erro em uma chamada a `_wcsnicoll`, defina `errno` para 0 e verifique `errno` após a chamada a `_wcsnicoll`**.**  
  
## Comentários  
 Cada uma dessas funções executa uma comparação que não diferencia maiúsculas de minúsculas dos primeiros caracteres de `count` em `string1` e `string2` de acordo com a página de código.  Essas funções devem ser usadas somente quando há uma diferença entre a ordem do conjunto de caracteres e a ordem de caracteres lexicográficos na página de código, e essa diferença é interessante para comparação de cadeia de caracteres.  As versões dessas funções sem o sufixo `_l` usam a localidade atual e a página de código.  As versões com o sufixo `_l` são idênticas, exceto pelo fato de que usam a localidade informada.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Todas essas funções validam seus parâmetros.  Se `string1` ou `string2` for um ponteiro nulo, ou se a contagem for maior que `INT_MAX`, o manipulador de parâmetro inválido será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` como `EINVAL`**.**  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcsncicoll`|`_strnicoll`|`_mbsnbicoll`|`_wcsnicoll`|  
|`_tcsnicoll`|`_strnicoll`|[\_mbsnbicoll](../../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)|`_wcsnicoll`|  
|`_tcsnicoll_l`|`_strnicoll_l`|`_mbsnbicoll_l`|`_wcsnicoll_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strnicoll`, `_strnicoll_l`|\<string.h\>|  
|`_wcsnicoll`, `_wcsnicoll_l`|\<wchar.h\> ou \<string.h\>|  
|`_mbsnicoll`, `_mbsnicoll_l`|\<mbstring.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 [System::String::Compare](https://msdn.microsoft.com/en-us/library/system.string.compare.aspx)  
  
## Consulte também  
 [Localidade](../../c-runtime-library/locale.md)   
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [\_mbsnbcoll, \_mbsnbcoll\_l, \_mbsnbicoll, \_mbsnbicoll\_l](../../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [strcmp, wcscmp, \_mbscmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)   
 [\_stricmp, \_wcsicmp, \_mbsicmp, \_stricmp\_l, \_wcsicmp\_l, \_mbsicmp\_l](../../c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)   
 [strxfrm, wcsxfrm, \_strxfrm\_l, \_wcsxfrm\_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)