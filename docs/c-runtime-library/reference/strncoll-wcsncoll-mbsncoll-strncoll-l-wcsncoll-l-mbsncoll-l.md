---
title: "_strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l | Microsoft Docs"
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
  - "_strncoll"
  - "_mbsncoll_l"
  - "_wcsncoll"
  - "_wcsncoll_l"
  - "_mbsncoll"
  - "_strncoll_l"
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
  - "mbsncoll_l"
  - "strncoll"
  - "_wcsncoll"
  - "_tcsnccoll"
  - "_ftcsnccoll"
  - "wcsncoll"
  - "_mbsncoll"
  - "wcsncoll_l"
  - "strncoll_l"
  - "_ftcsncoll"
  - "_strncoll"
  - "_tcsncoll"
  - "mbsncoll"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftcsnccoll"
  - "Função _ftcsncoll"
  - "Função _mbsncoll"
  - "Função _mbsncoll_l"
  - "Função _strncoll"
  - "Função _strncoll_l"
  - "Função _tcsnccoll"
  - "Função _tcsncoll"
  - "Função _wcsncoll"
  - "Função _wcsncoll_l"
  - "páginas de código, usando para comparações de cadeias de caracteres"
  - "Função ftcsnccoll"
  - "Função ftcsncoll"
  - "Função mbsncoll"
  - "Função mbsncoll_l"
  - "cadeias de caracteres [C++], comparando por página de código"
  - "Função strncoll"
  - "Função strncoll_l"
  - "Função tcsnccoll"
  - "Função tcsncoll"
  - "Função wcsncoll"
  - "Função wcsncoll_l"
ms.assetid: e659a5a4-8afe-4033-8e72-17ffd4bdd8e9
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strncoll, _wcsncoll, _mbsncoll, _strncoll_l, _wcsncoll_l, _mbsncoll_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara cadeias de caracteres usando informações específicas de localidade.  
  
> [!IMPORTANT]
>  `_mbsncoll` e `_mbsncoll_l` não podem ser usados em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _strncoll(  
   const char *string1,  
   const char *string2,  
   size_t count   
);  
int _wcsncoll(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count   
);  
int _mbsncoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _strncoll_l(  
   const char *string1,  
   const char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _wcsncoll_l(  
   const wchar_t *string1,  
   const wchar_t *string2,  
   size_t count,  
   _locale_t locale  
);  
int _mbsncoll_l(  
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
 O número de caracteres a ser comparado.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um valor que indica a relação entre as subcadeias de caracteres de `string1` e `string2`, da seguinte maneira.  
  
|Valor de retorno|Relação da string1 a string2|  
|----------------------|----------------------------------|  
|\< 0|`string1` é menor que `string2`.|  
|0|`string1` é idêntico ao `string2`.|  
|\> 0|`string1` é maior que `string2`.|  
  
 Cada uma dessas funções retornará `_NLSCMPERROR`.  Para usar `_NLSCMPERROR`, incluem String. h ou MBSTRING.h.  `_wcsncoll` pode falhar se `string1` ou `string2` contém códigos de caractere largo que estão fora do domínio da sequência de agrupamento.  Quando ocorre um erro, `_wcsncoll` pode definir `errno` para `EINVAL`.  Para verificar se há um erro em uma chamada para `_wcsncoll`, defina `errno` como 0 e, em seguida, verifique `errno` depois de chamar `_wcsncoll`.  
  
## Comentários  
 Cada uma dessas funções executa uma comparação diferenciando maiúsculas de minúsculas da primeira `count` caracteres `string1` e `string2`, de acordo com a página de código que está sendo usado.  Use essas funções somente quando há uma diferença entre a ordem de conjunto de caracteres e a ordem dos caracteres lexicográfica na página de código, e quando essa diferença é de interesse para a comparação de cadeia de caracteres.  A ordem do conjunto de caracteres é dependente de localidade.  As versões dessas funções que não têm o `_l` uso de sufixo a localidade atual, mas as versões que têm o `_l` sufixo usam a localidade que é passada.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Todas essas funções validam seus parâmetros.  Se `string1` ou `string2` é um ponteiro nulo, ou `count` é maior do que `INT_MAX`, o manipulador de parâmetro inválido é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsnccoll`|`_strncoll`|`_mbsncoll`|`_wcsncoll`|  
|`_tcsncoll`|`_strncoll`|[mbsnbcoll](../../c-runtime-library/reference/mbsnbcoll-mbsnbcoll-l-mbsnbicoll-mbsnbicoll-l.md)|`_wcsncoll`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strncoll`, `_strncoll_l`|\<string.h\>|  
|`_wcsncoll`, `_wcsncoll_l`|\< WCHAR. h \> ou \< String. h \>|  
|`_mbsncoll`, `_mbsncoll_l`|\<mbstring.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
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