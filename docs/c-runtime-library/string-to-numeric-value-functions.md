---
title: Funções de cadeia de caracteres para valores numéricos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apilocation:
- msvcr80.dll
- msvcr110.dll
- msvcr120.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr90.dll
apitype: DLLExport
f1_keywords:
- _tcstoui64
- _tcstoi64
dev_langs:
- C++
helpviewer_keywords:
- parsing, numeric strings
- string conversion, to numeric values
ms.assetid: 11cbd9ce-033b-4914-bf66-029070e7e385
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2b65ceb18eb6b8f24db0a85ba2ed13277b13f657
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46117486"
---
# <a name="string-to-numeric-value-functions"></a>Funções de valor da cadeia de caracteres para numérico

- [strtod, _strtod_l, wcstod, _wcstod_l](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)

- [strtol, wcstol, _strtol_l, _wcstol_l](../c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l.md)

- [strtoul, _strtoul_l, wcstoul, _wcstoul_l](../c-runtime-library/reference/strtoul-strtoul-l-wcstoul-wcstoul-l.md)

- [_strtoi64, _wcstoi64, _strtoi64_l, _wcstoi64_l](../c-runtime-library/reference/strtoi64-wcstoi64-strtoi64-l-wcstoi64-l.md)

- [_strtoui64, _wcstoui64, _strtoui64_l, _wcstoui64_l](../c-runtime-library/reference/strtoui64-wcstoui64-strtoui64-l-wcstoui64-l.md)

## <a name="remarks"></a>Comentários

Cada função no **strtod** família converte uma cadeia de caracteres terminada em nulo como um valor numérico. As funções disponíveis estão listadas na tabela a seguir.

|Função|Descrição|
|--------------|-----------------|
|`strtod`|Converter cadeia de caracteres no valor de ponto flutuante de precisão dupla|
|`strtol`|Converter a cadeia de caracteres em inteiro longo|
|`strtoul`|Converter cadeia de caracteres em inteiro longo unsigned|
|`_strtoi64`|Converter a cadeia de caracteres para inteiro `__int64` de 64 bits|
|`_strtoui64`|Converter cadeia de caracteres em inteiro `__int64` de 64 bits|

`wcstod`, `wcstol`, `wcstoul` e `_wcstoi64` são versões de caractere largo de `strtod`, `strtol`, `strtoul` e `_strtoi64`, respectivamente. O argumento de cadeia de caracteres para cada uma dessas funções de caractere largo é uma cadeia de caracteres largos. Cada função comporta-se identicamente para sua equivalente de único caractere de byte, caso contrário.

O `strtod` função leva dois argumentos: o primeiro é a cadeia de caracteres de entrada e o segundo um ponteiro para o caractere que termina o processo de conversão. `strtol`, `strtoul`, **strtoi64** e **strtoui64** usam um terceiro argumento como o número base a ser usado no processo de conversão.

A cadeia de caracteres de entrada é uma sequência de caracteres que pode ser interpretada como um valor numérico do tipo especificado. Cada função interrompe a leitura da cadeia de caracteres no primeiro caractere que ele não reconhece como parte de um número. Este pode ser o caractere nulo de terminação. Para `strtol`, `strtoul`, `_strtoi64`, e `_strtoui64`, esse caractere de terminação também pode ser o primeiro caractere numérico maior ou igual ao número fornecido pelo usuário base.

Se o ponteiro fornecido pelo usuário para um caractere de final de conversão não for definido como **nulo** durante a chamada, um ponteiro para o caractere que parou a verificação será armazenado nele e em vez disso. Se nenhuma conversão puder ser executada (nenhum dígito válido foi encontrado ou uma base inválida foi especificada), o valor do ponteiro de cadeia de caracteres estará armazenado nesse endereço.

`strtod` espera uma cadeia de caracteres com o seguinte formato:

[*whitespace*] [*sign*] [`digits`] [**.**`digits`] [ {**d** &#124; **D** &#124; **e** &#124; **E**}[*sign*]`digits`]

Um *espaço em branco* pode consistir em caracteres de espaço ou de tabulação, que são ignorados; *sign* é um mais (**+**) ou um menos (**-**); e `digits` é composto por um ou mais dígitos decimais. Se nenhum dígito aparecer antes do caractere fracionário, pelo menos um deverá aparecer após o caractere fracionário. Os dígitos decimais podem ser seguidos por um expoente, que consiste em uma letra de apresentação (**d**, **D**, **e** ou **E**) e um inteiro opcionalmente com sinal. Se nem um expoente nem um caractere fracionário aparecer, supõe-se que um caractere fracionário siga o último dígito na cadeia de caracteres. O primeiro caractere que não é adequado a esse formato interrompe o exame.

As funções `strtol`, `strtoul`, `_strtoi64` e `_strtoui64` esperam uma cadeia de caracteres com o seguinte formato:

[*whitespace*] [{**+** &#124; **-**}] [**0** [{ **x** &#124; **X** }]] [`digits`]

Se o argumento base estiver entre 2 e 36, ele será usado como a base do número. Se for 0, os caracteres iniciais referenciados pelo ponteiro final de conversão são usados para determinar a base. Se o primeiro caractere é 0 e o segundo caractere não for 'x' ou 'X', a cadeia de caracteres é interpretada como um inteiro octal; Caso contrário, ele será interpretado como um número decimal. Se o primeiro caractere for '0' e o segundo caractere for 'x' ou 'X', a cadeia de caracteres será interpretada como um inteiro hexadecimal. Se o primeiro caractere for de '1' até '9', a cadeia de caracteres será interpretada como um inteiro hexadecimal. As letras 'a' a 'z' (ou 'A' a 'Z') recebem os valores 10 a 35; somente são permitidas letras cujos valores atribuídos são menores que *base*. `strtoul` e `_strtoui64` permitem um prefixo com sinal de mais (**+**) ou de menos (**-**). Um sinal de subtração à esquerda indica que o valor retornado é negado.

O valor de saída é afetado pela configuração da categoria `LC_NUMERIC` da localidade; consulte [setlocale](../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo **_l** usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo **_l** são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar.

Quando o valor retornado por essas funções poderia causar um estouro ou estouro negativo, ou quando a conversão não for possível, os valores especiais são retornados como mostrado:

|Função|Condição|Valor retornado|
|--------------|---------------|--------------------|
|`strtod`|Estouro|+/- `HUGE_VAL`|
|`strtod`|Estouro negativo ou sem conversão|0|
|`strtol`|+ Estouro|**LONG_MAX**|
|`strtol`|- Estouro|**LONG_MIN**|
|`strtol`|Estouro negativo ou sem conversão|0|
|`_strtoi64`|+ Estouro|**_I64_MAX**|
|`_strtoi64`|- Estouro|**_I64_MIN**|
|`_strtoi64`|Sem conversão|0|
|`_strtoui64`|Estouro|**_UI64_MAX**|
|`_strtoui64`|Sem conversão|0|

 **_I64_MAX**, _**I64_MIN** e **_UI64_MAX** são definidos em LIMITS.H.

`wcstod`, `wcstol`, `wcstoul`, `_wcstoi64`, e `_wcstoui64` são versões de caractere largo de `strtod`, `strtol`, `strtoul`, `_strtoi64`, e `_strtoui64`, respectivamente; o ponteiro para um argumento de final de conversão para cada uma dessas funções de caractere largo é uma cadeia de caracteres largos. Caso contrário, cada uma dessas funções de caractere largo se comporta de forma idêntica à sua equivalente de caractere de byte único.

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../c-runtime-library/data-conversion.md)<br/>
[Localidade](../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[Suporte a ponto flutuante](../c-runtime-library/floating-point-support.md)<br/>
[atof, _atof_l, _wtof, _wtof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)