---
title: "Fun&#231;&#245;es de valor da cadeia de caracteres para num&#233;rico | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr80.dll"
  - "msvcr110.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr90.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_tcstoui64"
  - "_tcstoi64"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "analisando, cadeias de caracteres numéricas"
  - "conversão de cadeia de caracteres, para valores numéricos"
ms.assetid: 11cbd9ce-033b-4914-bf66-029070e7e385
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es de valor da cadeia de caracteres para num&#233;rico
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

-   [strtod, \_strtod\_l, wcstod, \_wcstod\_l](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)  
  
-   [strtol, wcstol, \_strtol\_l, \_wcstol\_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)  
  
-   [strtoul, \_strtoul\_l, wcstoul, \_wcstoul\_l](../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)  
  
-   [\_strtoi64, \_wcstoi64, \_strtoi64\_l, \_wcstoi64\_l](../c-runtime-library/reference/strtoi64-wcstoi64-strtoi64-l-wcstoi64-l.md)  
  
-   [\_strtoui64, \_wcstoui64, \_strtoui64\_l, \_wcstoui64\_l](../c-runtime-library/reference/strtoui64-wcstoui64-strtoui64-l-wcstoui64-l.md)  
  
## Comentários  
 Cada função da família de **strtod** converte uma cadeia de caracteres com terminação nula para um valor numérico.  As funções disponíveis são listadas na tabela a seguir.  
  
|Função|Descrição|  
|------------|---------------|  
|`strtod`|Cadeia de caracteres de conversão ao valor de ponto flutuante de precisão dupla|  
|`strtol`|Cadeia de caracteres de conversão ao inteiro longo|  
|`strtoul`|Cadeia de caracteres de conversão ao inteiro longo não assinados|  
|`_strtoi64`|Cadeia de caracteres de conversão em inteiro de 64 bits de `__int64`|  
|`_strtoui64`|Cadeia de caracteres de conversão em inteiro não assinado de 64 bits de `__int64`|  
  
 `wcstod`, `wcstol`, `wcstoul`, e `_wcstoi64` são versões de ampla caractere de `strtod`, de `strtol`, de `strtoul`, e de `_strtoi64`, respectivamente.  O argumento de cadeia de caracteres a cada uma dessas funções de ampla caractere é uma cadeia de caracteres de ampla caractere; cada função se comporta idêntica à sua contraparte de único\-byte\- caractere de outra forma.  
  
 A função de `strtod` usa dois argumentos: o primeiro é a cadeia de caracteres de entrada, e a segunda um ponteiro para o caractere que encerra o processo de conversão.  `strtol`, `strtoul`, **\_strtoi64** e **\_strtoui64** aceitam um terceiro argumento como a base de número a ser usado no processo de conversão.  
  
 A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretados como um valor numérico do tipo especificado.  Cada função para leitura da cadeia de caracteres no primeiro caractere que pode não reconhecer como parte de um número.  Isso pode ser o caractere de terminação zero.  Para `strtol`, `strtoul`, `_strtoi64`, e `_strtoui64`, esse caractere terminador também pode ser o primeiro caractere numérico maior ou igual à base de número fornecida pelo usuário.  
  
 Se o ponteiro fornecido a um caractere de participante de conversão não é definido como **nulo** no tempo da chamada, um ponteiro para o caractere que interrompeu a auditoria será armazenado no lugar.  Se nenhuma conversão pode ser executada \(nenhum dígito válido esteve encontrado ou uma base inválido foi especificada\), o valor do ponteiro de cadeia de caracteres é armazenado no endereço.  
  
 `strtod` espera uma cadeia de caracteres da seguinte forma:  
  
 *o espaço em branco*\[\] \[\] \[*sinal*`digits`\] \[**.**`digits`\] \[{**d** &#124; **D** &#124; **e** &#124; **E**} \[\]*sinal*`digits`\]  
  
 *Um espaço em branco* pode consistir no espaço ou nos caracteres de tabulação, que são ignorados; é *o sinal* de mais \(**\+**\) ou menos \(**–**\); e `digits` é um ou mais dígitos decimais.  Se nenhum dígito aparece antes do caractere raiz, pelo menos um deve aparecer após o caractere raiz.  Os dígitos decimais podem ser seguido por um expoente, que consiste em uma letra introdutória \(**d**, **D**, **e**, ou **E**\) e opcionalmente um inteiro com sinal.  Se uma parte do expoente ou um caractere raiz não aparecem, um caractere de raiz seguirá o último dígito da cadeia de caracteres.  O primeiro caractere que não se ajusta a este formulário interrompe o exame.  
  
 `strtol`, `strtoul`, `_strtoi64`, e as funções de `_strtoui64` esperam uma cadeia de caracteres da seguinte forma:  
  
 *o espaço em branco*\[\] \[{**\+** &#124; **–**}\] \[**0** \[{ **x** &#124; **X** }\]\] \[`digits`\]  
  
 Se o argumento de base estiver entre 2 e 36, então será usado como a base do número.  Se for 0, os caracteres iniciais referenciados pelo ponteiro de participante de conversão são usados para determinar a base.  Se o primeiro caractere for 0 e o segundo caractere não é “x” ou “X”, a cadeia de caracteres será interpretada como um inteiro octal; caso contrário, será interpretada como um número decimal.  Se o primeiro caractere for “0 " e o segundo caractere for “x” ou “X”, a cadeia de caracteres será interpretada como um inteiro hexadecimal.  Se o primeiro caractere for “1 " a “9 ", a cadeia de caracteres será interpretada como um número decimal.  As letras” por “z” \(ou “A” por “Z "\) são atribuídas valores de 10 a 35; somente as letras cujos valores são atribuídos menor do que *a base* são permitidas.  `strtoul` e `_strtoui64` permitem a**\+**mais \(\) ou menos o prefixo de sinal \(de**–**\); um sinal de menos principal indica que o valor de retorno será negado.  
  
 O valor de saída é afetado pela configuração da categoria `LC_NUMERIC` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo **\_l** usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo **\_l** são idênticas, exceto que elas usam o parâmetro de localidade informado.  
  
 Quando o valor retornado por essas funções provocará um estouro ou um estouro negativo, ou quando a conversão não é possível, os valores dos casos especiais são retornados como mostrado:  
  
|Função|Condição|Valor retornado|  
|------------|--------------|---------------------|  
|`strtod`|Estouro|\+\/\- `HUGE_VAL`|  
|`strtod`|Estouro negativo ou nenhuma conversão|0|  
|`strtol`|\+ Estouro|**LONG\_MAX**|  
|`strtol`|\- Estouro|**LONG\_MIN**|  
|`strtol`|Estouro negativo ou nenhuma conversão|0|  
|`_strtoi64`|\+ Estouro|**\_I64\_MAX**|  
|`_strtoi64`|\- Estouro|**\_I64\_MIN**|  
|`_strtoi64`|Nenhuma conversão|0|  
|`_strtoui64`|Estouro|**\_UI64\_MAX**|  
|`_strtoui64`|Nenhuma conversão|0|  
  
 **\_I64\_MAX**, \_**I64\_MIN**, e **\_UI64\_MAX** são definidos em LIMITS.H.  
  
 `wcstod`, `wcstol`, `wcstoul`, `_wcstoi64`, e `_wcstoui64` são versões de ampla caractere de `strtod`, de `strtol`, de `strtoul`, de `_strtoi64`, e de `_strtoui64`, respectivamente; o ponteiro para um argumento de participante de conversão para cada uma dessas funções de ampla caractere é uma cadeia de caracteres de ampla caractere.  Se não, cada uma dessas funções ampla de caracteres se comporta idêntica à sua contraparte de único\-byte\- caractere.  
  
## Consulte também  
 [Conversão de dados](../c-runtime-library/data-conversion.md)   
 [Localidade](../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Suporte de ponto flutuante](../c-runtime-library/floating-point-support.md)   
 [atof, \_atof\_l, \_wtof, \_wtof\_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)