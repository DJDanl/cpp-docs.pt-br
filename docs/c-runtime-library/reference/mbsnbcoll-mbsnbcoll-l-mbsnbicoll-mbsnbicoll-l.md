---
title: "_mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l | Microsoft Docs"
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
  - "_mbsnbicoll_l"
  - "_mbsnbcoll_l"
  - "_mbsnbcoll"
  - "_mbsnbicoll"
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
apitype: "DLLExport"
f1_keywords: 
  - "mbsnbicoll"
  - "mbsnbcoll"
  - "mbsnbicoll_l"
  - "_mbsnbcoll"
  - "_mbsnbicoll"
  - "_ftcsnicoll"
  - "_ftcsncoll"
  - "mbsnbcoll_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbsnbcoll"
  - "Função _mbsnbcoll_l"
  - "Função _mbsnbicoll"
  - "Função _mbsnbicoll_l"
  - "Função _tcsncoll"
  - "Função _tcsnicoll"
  - "Função mbsnbcoll"
  - "Função mbsnbcoll_l"
  - "Função mbsnbicoll"
  - "Função mbsnbicoll_l"
  - "Função tcsncoll"
  - "Função tcsnicoll"
ms.assetid: d139ed63-ccba-4458-baa2-61cbcef03e94
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _mbsnbcoll, _mbsnbcoll_l, _mbsnbicoll, _mbsnbicoll_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Compara bytes de `n` de duas cadeias de caracteres multibyte usando informações da página de código multibyte.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _mbsnbcoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _mbsnbcoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
int _mbsnbicoll(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count   
);  
int _mbsnbicoll_l(  
   const unsigned char *string1,  
   const unsigned char *string2,  
   size_t count,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `string1, string2`  
 Cadeias de caracteres a serem comparadas.  
  
 `count`  
 Número de bytes a serem comparados.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 O valor de retorno indica a relação das subcadeias de caracteres de `string1` e `string2`.  
  
|Valor de retorno|Descrição|  
|----------------------|---------------|  
|\< 0|Subcadeia de caracteres `string1` menor que a subcadeia de caracteres `string2`.|  
|0|Subcadeia de caracteres `string1` idêntica à subcadeia de caracteres `string2`.|  
|\> 0|Subcadeia de caracteres `string1` maior que a subcadeia de caracteres `string2`.|  
  
 Se `string1` ou `string2` for `NULL` ou `count` for maior que `INT_MAX`, o manipulador de parâmetro inválido será chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `_NLSCMPERROR` e definirão `errno` para `EINVAL`.  Para usar `_NLSCMPERROR`, inclua String.h ou Mbstring.h.  
  
## Comentários  
 Cada uma dessas funções suporta, no máximo, os primeiros bytes de `count` em `string1` e em `string2` e retorna um valor que indica a relação entre as subcadeias de caracteres resultantes de `string1` e `string2`.  Se o byte final na subcadeia de caracteres de `string1` ou de `string2` for um byte inicial, não é incluído na comparação; essas funções comparam somente caracteres completos nas subcadeias de caracteres.  `_mbsnbicoll` é uma versão que diferencia maiúsculas e minúsculas de `_mbsnbcoll`.  Assim como `_mbsnbcmp` e `_mbsnbicmp`, `_mbsnbcoll` e `_mbsnbicoll` ordenam as duas cadeias de caracteres multibyte de acordo com a ordem lexicográfica especificada pela [página de código](../../c-runtime-library/code-pages.md) atualmente em uso.  
  
 Para algumas páginas de código e conjuntos de caracteres correspondentes, a ordem dos caracteres no conjunto de caracteres pode diferir de ordem lexicográfica dos caracteres.  Na localidade de C, este é não o casos: a ordem dos caracteres no conjunto de caracteres ASCII é a mesma que a ordem lexicográfica de caracteres.  No entanto, em determinadas páginas de código europeias, por exemplo, o caractere "a" \(valor 0x61\) precede o caractere "ä" \(valor 0xE4\) no conjunto de caracteres, mas o caractere "ä" precede o caractere "a" lexicograficamente.  Para realizar uma comparação lexicográfica de cadeias de caracteres por bytes em uma instância, use `_mbsnbcoll` em vez de `_mbsnbcmp`; para verificar somente a existência de igualdade de cadeia de caracteres, use `_mbsnbcmp`.  
  
 Como as funções de `coll` suportam cadeias de caracteres graficamente léxicas para comparação e as funções de `cmp` simplesmente testam a igualdade da cadeia de caracteres, as funções de `coll` são muito mais lentas que as versões correspondentes de `cmp`.  Portanto, as funções `coll` devem ser usadas somente quando há uma diferença entre a ordem do conjunto de caracteres e a ordem de caracteres lexicográficos na página de código atual, e essa diferença é interessante para comparação.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcsncoll`|[\_strncoll](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|`_mbsnbcoll`|[\_wcsncoll](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|  
|`_tcsncoll_l`|[\_strncoll, \_wcsncoll, \_mbsncoll, \_strncoll\_l, \_wcsncoll\_l, \_mbsncoll\_l](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|`_mbsnbcoll_l`|[\_wcsncoll\_l](../../c-runtime-library/reference/strncoll-wcsncoll-mbsncoll-strncoll-l-wcsncoll-l-mbsncoll-l.md)|  
|`_tcsnicoll`|[\_strnicoll](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|`_mbsnbicoll`|[\_wcsnicoll](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|  
|`_tcsnicoll_l`|[\_strnicoll\_l](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|`_mbsnbicoll_l`|[\_wcsnicoll\_l](../../c-runtime-library/reference/strnicoll-wcsnicoll-mbsnicoll-strnicoll-l-wcsnicoll-l-mbsnicoll-l.md)|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_mbsnbcoll`|\<mbstring.h\>|  
|`_mbsnbcoll_l`|\<mbstring.h\>|  
|`_mbsnbicoll`|\<mbstring.h\>|  
|`_mbsnbicoll_l`|\<mbstring.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [\_mbsnbcat, \_mbsnbcat\_l](../../c-runtime-library/reference/mbsnbcat-mbsnbcat-l.md)   
 [\_mbsnbcmp, \_mbsnbcmp\_l](../../c-runtime-library/reference/mbsnbcmp-mbsnbcmp-l.md)   
 [\_mbsnbicmp, \_mbsnbicmp\_l](../../c-runtime-library/reference/mbsnbicmp-mbsnbicmp-l.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strncmp, wcsncmp, \_mbsncmp, \_mbsncmp\_l](../../c-runtime-library/reference/strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)   
 [\_strnicmp, \_wcsnicmp, \_mbsnicmp, \_strnicmp\_l, \_wcsnicmp\_l, \_mbsnicmp\_l](../../c-runtime-library/reference/strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)