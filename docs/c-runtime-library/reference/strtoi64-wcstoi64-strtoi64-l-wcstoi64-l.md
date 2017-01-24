---
title: "_strtoi64, _wcstoi64, _strtoi64_l, _wcstoi64_l | Microsoft Docs"
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
  - "_strtoi64"
  - "_strtoi64_l"
  - "_wcstoi64_l"
  - "_wcstoi64"
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
  - "_strtoi64"
  - "strtoi64"
  - "_stroi64_l"
  - "_wcstoi64_l"
  - "wcstoi64_l"
  - "_wcstoi64"
  - "wcstoi64"
  - "strtoi64_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _strtoi64"
  - "Função _strtoi64_l"
  - "Função _wcstoi64"
  - "Função _wcstoi64_l"
  - "conversão de cadeia de caracteres, para inteiros"
  - "Função strtoi64"
  - "Função strtoi64_l"
  - "Função wcstoi64"
  - "Função wcstoi64_l"
ms.assetid: ea2abc50-7bfe-420e-a46b-703c3153593a
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _strtoi64, _wcstoi64, _strtoi64_l, _wcstoi64_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte uma cadeia de caracteres em um valor `__int64`.  
  
## Sintaxe  
  
```  
__int64 _strtoi64(  
   const char *nptr,  
   char **endptr,  
   int base   
);  
__int64 _wcstoi64(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base   
);  
__int64 _strtoi64_l(  
   const char *nptr,  
   char **endptr,  
   int base,  
   _locale_t locale  
);  
__int64 _wcstoi64_l(  
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
 `_strtoi64` retorna o valor representado na cadeia de caracteres `nptr`, exceto quando a representação resultaria em estouro, nesse caso, retornaria `_I64_MAX` ou `_I64_MIN`.  A função retornará 0, se nenhuma conversão puder ser executada.  Valores de retornos do `_wcstoi64` análogos a `strtoi64`.  
  
 `_I64_MAX` e `_I64_MIN` são definidos em LIMITS.H.  
  
 Se `nptr` for `NULL` ou `base` for diferente de zero e menor que 2 ou maior que 36, `errno` será definido como `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `_strtoi64`converte `nptr` para um `__int64`.  Ambas as funções deixam de ler a cadeia de caracteres `nptr` no primeiro caractere que não reconhecem como parte de um número.  Pode ser o caractere nulo de terminação,ou o primeiro caractere numérico maior ou igual a `base`.  `_wcstoi64` é uma versão de caractere amplo de `_strtoi64`; seu argumento `nptr` é uma cadeira de caractere longo.  Essas funções se comportam exatamente o contrário.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcstoi64`|`_strtoi64`|`_strtoi64`|`_wcstoi64`|  
|`_tcstoi64_l`|`_strtoi64_l`|`_strtoi64_l`|`_wcstoi64_l`|  
  
 A configuração de categoria `LC_NUMERIC` de local determina o reconhecimento do caractere raiz em `nptr`*;* para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As funções sem o sufixo \_l usam a localidade atual; `_strtoi64_l` e`_wcstoi64_l` são idênticas à função correspondente sem o sufixo `_l`, exceto que elas usam a localidade informada no lugar.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não for `NULL`, um ponteiro para o caractere que interrompeu a verificação é armazenado no local apontado por `endptr`.  Se nenhuma conversão puder ser executada \(nenhum dígito válido foi encontrado ou uma base inválida foi especificada\), o valor de `nptr` será armazenado no local apontado por `endptr`.  
  
 `_strtoi64` espera `nptr` apontar para uma cadeia de caracteres da seguinte forma:  
  
 \[`whitespace`\] \[{`+` &#124; `–`}\] \[`0` \[{ `x` &#124; `X` }\]\] \[`digits`\]  
  
 Um `whitespace` pode conter os caracteres de espaço e de tabulação, que são ignorados; `digits` são um ou mais dígitos decimais.  O primeiro caractere que não se ajusta a este formulário interrompe o exame.  Se `base` estiver entre 2 e 36, então será usado como a base do número.  Se `base` é 0, os caracteres iniciais da cadeia de caracteres apontada por `nptr` são usados para determinar a base.  Se o primeiro caractere for 0 e o segundo não for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro octal.  Se o primeiro caractere for “0 " e o segundo caractere for “x” ou “X”, a cadeia de caracteres será interpretada como um inteiro hexadecimal.  Se o primeiro caractere for “1 " a “9 ", a cadeia de caracteres será interpretada como um número decimal.  As letras ”a" a “z” \(ou “A” a “Z "\) são atribuídas aos valores de 10 a 35; somente letras cujos valores atribuídos são menores que `base` são permitidas.  O primeiro caractere fora do intervalo de base para o exame.  Por exemplo, se `base` for 0 e o primeiro caractere verificado for "0", um número inteiro octal será assumido e um caractere "8" ou "9" interromperá a verificação.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_strtoi64`, `_strtoi64_l`|\<stdlib.h\>|  
|`_wcstoi64`, `_wcstoi64_l`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, \_strtod\_l, wcstod, \_wcstod\_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtoul, \_strtoul\_l, wcstoul, \_wcstoul\_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)