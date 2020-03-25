---
title: Intervalos de tipos de dados
ms.date: 05/07/2019
helpviewer_keywords:
- float keyword [C++]
- char keyword [C++]
- unsigned long
- __wchar_t keyword [C++]
- unsigned short int [C++]
- enum keyword [C++]
- unsigned char keyword [C++]
- integer data type [C++], data type ranges
- int data type
- data types [C++], ranges
- unsigned int [C++]
- short data type
- short int data
- signed types [C++], data type ranges
- long long keyword [C++]
- long double keyword [C++]
- double data type [C++], data type ranges
- signed short int [C++]
- unsigned short
- sized integer types
- signed int [C++]
- signed long int [C++]
- signed char keyword [C++]
- wchar_t keyword [C++]
- long keyword [C++]
- ranges [C++]
- unsigned types [C++], data type ranges
- floating-point numbers [C++]
- data type ranges
- ranges [C++], data types
- long int keyword [C++]
- unsigned long int [C++]
ms.assetid: 3691ceca-05fb-4b82-b1ae-5c4618cda91a
ms.openlocfilehash: 8b4031eccccb432342790fef4da809542e77d669
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180258"
---
# <a name="data-type-ranges"></a>Intervalos de tipos de dados

Os compiladores Microsoft C++ 32 bits e 64 bits reconhecem os tipos na tabela mais adiante neste artigo.

- `int` (`unsigned int`)

- `__int8` (`unsigned __int8`)

- `__int16` (`unsigned __int16`)

- `__int32` (`unsigned __int32`)

- `__int64` (`unsigned __int64`)

- `short` (`unsigned short`)

- `long` (`unsigned long`)

- `long` de `long` (`unsigned long long`)

Se o nome começa com sublinhados duplos (`__`), um tipo de dados é diferente do padrão.

Os intervalos especificados na tabela a seguir são inclusivo-inclusivo.

|Nome do Tipo|Bytes|Outros nomes|Intervalo de valores|
|---------------|-----------|-----------------|---------------------|
|**int**|4|**signed**|-2.147.483.648 a 2.147.483.647|
|**unsigned int**|4|**unsigned**|0 a 4.294.967.295|
|**__int8**|1|**char**|-128 a 127|
|**__int8 não assinado**|1|**unsigned char**|0 a 255|
|**__int16**|2|**breve**, **int curto**, com **sinal int curto**|-32.768 a 32.767|
|**__int16 não assinado**|2|**não assinado curto**, **inteiro curto não assinado**|0 a 65.535|
|**__int32**|4|**assinado**, **int assinado**, **int**|-2.147.483.648 a 2.147.483.647|
|**__int32 não assinado**|4|int não **assinado**, **sem sinal**|0 a 4.294.967.295|
|**__int64**|8|**longa longa, com** **sinal** demorado|-9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|
|**unsigned __int64**|8|**longo longo sem sinal**|0 a 18.446.744.073.709.551.615|
|**bool**|1|none|**false** ou **true**|
|**char**|1|none|-128 a 127 por padrão<br /><br /> 0 a 255 quando compilado usando [/j](../build/reference/j-default-char-type-is-unsigned.md)|
|**caractere assinado**|1|none|-128 a 127|
|**unsigned char**|1|none|0 a 255|
|**short**|2|**int curto**, com **sinal int curto**|-32.768 a 32.767|
|**unsigned short**|2|**unsigned short int**|0 a 65.535|
|**long**|4|**int Long**, **int longo assinado**|-2.147.483.648 a 2.147.483.647|
|**unsigned long**|4|**unsigned long int**|0 a 4.294.967.295|
|**long long**|8|Nenhum (mas equivalente a **__int64**)|-9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|
|**longo longo sem sinal**|8|Nenhum (mas equivalente a **__int64 não assinados**)|0 a 18.446.744.073.709.551.615|
|**enum**|varia|none| |
|**float**|4|none|3.4E +/- 38 (7 dígitos)|
|**double**|8|none|1.7E +/- 308 (15 dígitos)|
|**long double**|Igual ao **duplo**|none|Igual ao **duplo**|
|**wchar_t**|2|**__wchar_t**|0 a 65.535|

Dependendo de como é usado, uma variável de **__wchar_t** designa um tipo de caractere largo ou um tipo de caractere multibyte. Use o prefixo `L` antes de uma constante de caractere ou de cadeia de caracteres para designar a constante de tipo de caractere largo.

**assinada** e **não** assinado são modificadores que você pode usar com qualquer tipo integral, exceto **bool**. Observe que **Char, Char** **assinado**e **caracteres não assinados** são três tipos distintos para fins de mecanismos como sobrecarregamentos e modelos.

Os **tipos int e** **não assinado int** têm um tamanho de quatro bytes. No entanto, o código portátil não deve depender do tamanho de **int** porque o padrão de idioma permite que isso seja específico da implementação.

C/C++ no Visual Studio também tem suporte para tipos de inteiros dimensionados. Para obter mais informações, consulte [__int8, \__int16, \__int32, \__int64](../cpp/int8-int16-int32-int64.md) e [limites de inteiro](../cpp/integer-limits.md).

Para obter mais informações sobre as restrições dos tamanhos de cada tipo, consulte [tipos internos](../cpp/fundamental-types-cpp.md).

O intervalo dos tipos enumerados varia dependendo do contexto de linguagem e dos sinalizadores de compilador especificados. Para obter mais informações, consulte declarações e [enumerações](../cpp/enumerations-cpp.md)de [enumeração de C](../c-language/c-enumeration-declarations.md) .

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos internos](../cpp/fundamental-types-cpp.md)
