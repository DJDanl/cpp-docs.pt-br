---
title: "strtol, wcstol, _strtol_l, _wcstol_l | Microsoft Docs"
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
  - "strtol"
  - "wcstol"
  - "_strtol_l"
  - "_wcstol_l"
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
  - "_wcstol_l"
  - "strtol"
  - "_tcstol"
  - "wcstol"
  - "_strtol_l"
  - "_tcstol_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _strtol_l"
  - "Função _tcstol"
  - "Função _wcstol_l"
  - "conversão de cadeia de caracteres, para inteiros"
  - "Função strtol"
  - "Função strtol_l"
  - "Função tcstol"
  - "Função wcstol"
  - "Função wcstol_l"
ms.assetid: 1787c96a-f283-4a83-9325-33cfc1c7e240
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strtol, wcstol, _strtol_l, _wcstol_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter cadeias de caracteres em um valor de manga inteiro.  
  
## Sintaxe  
  
```  
long strtol(  
   const char *nptr,  
   char **endptr,  
   int base   
);  
long wcstol(  
   const wchar_t *nptr,  
   wchar_t **endptr,  
   int base   
);  
long _strtol_l(  
   const char *nptr,  
   char **endptr,  
   int base,  
   _locale_t locale  
);  
long _wcstol_l(  
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
 Localidade a ser usada.  
  
## Valor de retorno  
 `strtol` retorna o valor representado na cadeia de caracteres `nptr`, exceto quando a representação provocará um estouro, caso em que retorna `LONG_MAX` ou `LONG_MIN`.  `strtol` retorna 0 se nenhuma conversão puder ser executada.  Valores de retornos do `wcstol` análogos a `strtol`.  Para ambas as funções, `errno` é definido como `ERANGE` se o estouro ou o estouro negativo ocorrerem.  
  
 Consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esses e outros códigos de retorno.  
  
## Comentários  
 A função `strtol` converte `nptr` para um `long`.  `strtol` deixa de ler a cadeia de caracteres `nptr` no primeiro caractere que ela não reconhece ser parte de um número.  Pode ser o caractere nulo de terminação,ou o primeiro caractere numérico maior ou igual a `base`.  
  
 `wcstol` é uma versão de caractere amplo de `strtol`; seu argumento `nptr` é uma cadeira de caractere longo.  Essas funções se comportam exatamente o contrário.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcstol`|`strtol`|`strtol`|`wcstol`|  
|`_tcstol_l`|`_strtol_l`|`_strtol_l`|`_wcstol_l`|  
  
 A configuração atual da categoria de `LC_NUMERIC` de localidade determina o reconhecimento de caracteres raiz em `nptr`*;* para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As funções sem o sufixo de `_l` usam a localidade atual; `_strtol_l` e `_wcstol_l` é idêntico a funções correspondentes sem o sufixo de `_l` exceto que usa a localidade passada por vez.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Se `endptr` não for `NULL`, um ponteiro para o caractere que interrompeu a verificação é armazenado no local apontado por `endptr`.  Se nenhuma conversão puder ser executada \(nenhum dígito válido foi encontrado ou uma base inválida foi especificada\), o valor de `nptr` será armazenado no local apontado por `endptr`.  
  
 `strtol` espera `nptr` apontar para uma cadeia de caracteres da seguinte forma:  
  
 \[`whitespace`\] \[{`+` &#124; `–`}\] \[`0` \[{ `x` &#124; `X` }\]\] \[`digits`\]  
  
 Um `whitespace` pode conter os caracteres de espaço e de tabulação, que são ignorados; `digits` são um ou mais dígitos decimais.  O primeiro caractere que não se ajusta a este formulário interrompe o exame.  Se `base` estiver entre 2 e 36, então será usado como a base do número.  Se `base` é 0, os caracteres iniciais da cadeia de caracteres apontada por `nptr` são usados para determinar a base.  Se o primeiro caractere for 0 e o segundo não for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro octal.  Se o primeiro caractere for “0 " e o segundo caractere for “x” ou “X”, a cadeia de caracteres será interpretada como um inteiro hexadecimal.  Se o primeiro caractere for “1 " a “9 ", a cadeia de caracteres será interpretada como um número decimal.  As letras ”a" a “z” \(ou “A” a “Z "\) são atribuídas aos valores de 10 a 35; somente letras cujos valores atribuídos são menores que `base` são permitidas.  O primeiro caractere fora do intervalo de base para o exame.  Por exemplo, se `base` for 0 e o primeiro caractere verificado for "0", um número inteiro octal será assumido e um caractere "8" ou "9" interromperá a verificação.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strtol`|\<stdlib.h\>|  
|`wcstol`|\<stdlib.h\> ou \<wchar.h\>|  
|`_strtol_l`|\<stdlib.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [strtod](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md).  
  
## Equivalência do .NET Framework  
 [System::Convert::ToInt64](https://msdn.microsoft.com/en-us/library/system.convert.toint64.aspx)  
  
## Consulte também  
 [Conversão de dados](../../c-runtime-library/data-conversion.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [Funções de valor da cadeia de caracteres para numérico](../../c-runtime-library/string-to-numeric-value-functions.md)   
 [strtod, \_strtod\_l, wcstod, \_wcstod\_l](../../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)   
 [strtoul, \_strtoul\_l, wcstoul, \_wcstoul\_l](../../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)