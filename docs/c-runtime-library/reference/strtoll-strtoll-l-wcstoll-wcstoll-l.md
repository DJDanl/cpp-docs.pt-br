---
title: "strtoll, _strtoll_l, wcstoll, _wcstoll_l | Microsoft Docs"
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
  - "strtoll"
  - "wcstoll"
  - "_strtoll_l"
  - "_wcstoll_l"
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
  - "api-ms-win-crt-convert-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_strtoll_l"
  - "_tcstoll_l"
  - "_tcstoll"
  - "_wcstoll_l"
  - "strtoll"
  - "wcstoll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _strtoll_l"
  - "Função _tcstoll"
  - "Função _tcstoll_l"
  - "Função _wcstoll_l"
  - "Função strtoll"
  - "Função wcstoll"
ms.assetid: e2d05dcf-d3b2-4291-9e60-dee77e540fd7
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strtoll, _strtoll_l, wcstoll, _wcstoll_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma cadeia de caracteres em valor de `long long`.  
  
## Sintaxe  
  
```  
long long strtoll(  
   const char *nptr,  
   char **endptr,  
   int base   
);  
long long wcstoll(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base   
);  
long long _strtoll_l(  
   const char *nptr,  
   char **endptr,  
   int base,  
   _locale_t locale  
);  
long long _wcstoll_l(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `nptr`  
 Cadeia de caracteres nula a ser convertida.  
  
 `endptr`  
 Ponteiro para o caractere que para o exame.  
  
 `base`  
 Número base a ser usado.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 `strtoll` retorna o valor que é representado na cadeia de caracteres `nptr`, a não ser quando a representação resultaria em estouro, neste caso, retornaria `LLONG_MAX` ou `LLONG_MIN`.  A função retorna 0, se nenhuma conversão puder ser executada.  Valores de retornos do `wcstoll` análogos a `strtoll`.  
  
 `LLONG_MAX` e `LLONG_MIN` são definidos em LIMITS.H.  
  
 Se `nptr` for `NULL` ou `base` for diferente de zero e menor que 2 ou maior que 36, `errno` será definido como `EINVAL`.  
  
 Para obter mais informações sobre códigos de retorno, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `strtoll` converte `nptr` para um `long long`.  Ambas as funções deixam de ler a cadeia de caracteres `nptr` no primeiro caractere que não reconhecem como parte de um número.  Pode ser o caractere nulo de terminação, ou pode ser o primeiro caractere numérico que é maior ou igual a `base`.  `wcstoll` é uma versão de caractere amplo de `strtoll`; seu argumento `nptr` é uma cadeira de caractere longo.  Do contrário, essas funções se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcstoll`|`strtoll`|`strtoll`|`wcstoll`|  
|`_tcstoll_l`|`_strtoll_l`|`_strtoll_l`|`_wcstoll_l`|  
  
 A configuração de categoria `LC_NUMERIC` da localidade determina o reconhecimento do caractere raiz em `nptr`; para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md).  As funções que não têm o sufixo `_l` usam a localidade atual; `_strtoll_l` e `_wcstoll_l` são idênticas às versões correspondentes que não têm o sufixo , com exceção que aquelas, em vez disso, usam a localidade informada.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não for `NULL`, um ponteiro para o caractere que parou a verificação é armazenado no local que é apontado por `endptr`.  Se nenhuma conversão puder ser executada \(nenhum dígito válido foi encontrado ou uma base inválida foi especificado\), o valor de `nptr` será armazenado no local que é apontado por `endptr`.  
  
 `strtoll` espera `nptr` apontar para uma cadeia de caracteres de seguinte forma:  
  
 \[`whitespace`\] \[{`+` &#124; `–`}\] \[`0` \[{ `x` &#124; `X` }\]\] \[`digits` &#124; `letters`\]  
  
 Um `whitespace` pode consistir do espaço e em caracteres de tabulação, que são ignorados; `digits` é um ou mais dígitos decimais; `letters` é uma ou mais das letras "a" a "z" \(ou "A" a "Z"\).  O primeiro caractere que não se ajusta a este formulário interrompe o exame.  Se `base` estiver entre 2 e 36, então será usado como a base do número.  Se `base` é 0, os caracteres iniciais da cadeia de caracteres apontada por `nptr` são usados para determinar a base.  Se o primeiro caractere for “0 " e o segundo caractere não for “x” ou “X”, a cadeia de caracteres será interpretada como um inteiro octal.  Se o primeiro caractere for “0 " e o segundo caractere for “x” ou “X”, a cadeia de caracteres será interpretada como um inteiro hexadecimal.  Se o primeiro caractere for “1 " a “9 ", a cadeia de caracteres será interpretada como um número decimal.  As letras ”a" a “z” \(ou “A” a “Z "\) são atribuídas aos valores de 10 a 35; somente letras cujos valores atribuídos são menores que `base` são permitidas.  O primeiro caractere fora do intervalo de base para o exame.  Por exemplo, se `base` é 0 e o primeiro caractere verificado é “0", um número inteiro octal é assumido e um caractere “8" ou “9" para a verificação.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strtoll`, `_strtoll_l`|\<stdlib.h\>|  
|`wcstoll`, `_wcstoll_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, \_strtod\_l, wcstod, \_wcstod\_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtol, wcstol, \_strtol\_l, \_wcstol\_l](../../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)   
 [strtoul, \_strtoul\_l, wcstoul, \_wcstoul\_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)