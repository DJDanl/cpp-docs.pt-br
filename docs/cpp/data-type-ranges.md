---
title: Intervalos de tipos de dados
ms.date: 11/04/2016
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
ms.openlocfilehash: 88fbb128d995338e5976fbb3df939524f3ef8b63
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50495024"
---
# <a name="data-type-ranges"></a>Intervalos de tipos de dados

Os compiladores de 32 bits e 64 bits do Visual C++ reconhecem os tipos na tabela mais adiante neste artigo.

- `int` (`unsigned int`)

- `__int8` (`unsigned __int8`)

- `__int16` (`unsigned __int16`)

- `__int32` (`unsigned __int32`)

- `__int64` (`unsigned __int64`)

- `short` (`unsigned short`)

- `long` (`unsigned long`)

- `long` `long` (`unsigned long long`)

Se o nome começa com sublinhados duplos (`__`), um tipo de dados é diferente do padrão.

Os intervalos especificados na tabela a seguir são inclusivo-inclusivo.

|Nome do tipo|Bytes|Outros nomes|Intervalo de valores|
|---------------|-----------|-----------------|---------------------|
|**int**|4|**signed**|-2.147.483.648 a 2.147.483.647|
|**unsigned int**|4|**unsigned**|0 a 4.294.967.295|
|**__int8**|1|**char**|-128 a 127|
|**__int8 sem sinal**|1|**unsigned char**|0 a 255|
|**__int16**|2|**curto**, **short int**, **assinado int curto**|-32.768 a 32.767|
|**__int16 sem sinal**|2|**unsigned short**, **unsigned int curto**|0 a 65.535|
|**__int32**|4|**assinado**, **assinado int**, **int**|-2.147.483.648 a 2.147.483.647|
|**__int32 sem sinal**|4|**sem sinal**, **int sem sinal**|0 a 4.294.967.295|
|**__int64**|8|**longo longo**, **assinado longo longo**|-9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|
|**unsigned __int64**|8|**longo longo sem sinal**|0 a 18.446.744.073.709.551.615|
|**bool**|1|nenhum|**False** ou **true**|
|**char**|1|nenhum|-128 a 127 por padrão<br /><br /> 0 a 255 quando compilado usando [/J](../build/reference/j-default-char-type-is-unsigned.md)|
|**char assinada**|1|nenhum|-128 a 127|
|**unsigned char**|1|nenhum|0 a 255|
|**short**|2|**int curto**, **assinado int curto**|-32.768 a 32.767|
|**unsigned short**|2|**unsigned short int**|0 a 65.535|
|**long**|4|**Long int**, **assinado long int**|-2.147.483.648 a 2.147.483.647|
|**unsigned long**|4|**unsigned long int**|0 a 4.294.967.295|
|**long long**|8|None (mas equivalente a **__int64**)|-9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|
|**longo longo sem sinal**|8|None (mas equivalente a **unsigned __int64**)|0 a 18.446.744.073.709.551.615|
|**enum**|varia|nenhum| |
|**float**|4|nenhum|3.4E +/- 38 (7 dígitos)|
|**double**|8|nenhum|1.7E +/- 308 (15 dígitos)|
|**long double**|mesmo que **duplo**|nenhum|mesmo que **duplo**|
|**wchar_t**|2|**wchar_t**|0 a 65.535|

Dependendo de como ele é usado, uma variável de **wchar_t** designa um tipo de caractere largo ou o tipo de caractere multibyte. Use o prefixo `L` antes de uma constante de caractere ou de cadeia de caracteres para designar a constante de tipo de caractere largo.

**assinado** e **não assinados** são os modificadores que você pode usar com qualquer tipo integral exceto **bool**. Observe que **char**, **assinado char**, e **unsigned char** são três tipos distintos para fins de mecanismos como sobrecarga e modelos.

O **int** e **unsigned int** tipos têm um tamanho de quatro bytes. No entanto, um código portátil não deve depender do tamanho do **int** porque a linguagem padrão permite que ele seja específico da implementação.

C/C++ no Visual Studio também tem suporte para tipos de inteiros dimensionados. Para obter mais informações, consulte [__int8, \__int16, \__int32, \__int64](../cpp/int8-int16-int32-int64.md) e [limites de inteiro](../cpp/integer-limits.md).

Para obter mais informações sobre as restrições de tamanhos de cada tipo, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).

O intervalo dos tipos enumerados varia dependendo do contexto de linguagem e dos sinalizadores de compilador especificados. Para obter mais informações, consulte [declarações de enumeração C](../c-language/c-enumeration-declarations.md) e [enumerações](../cpp/enumerations-cpp.md).

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos fundamentais](../cpp/fundamental-types-cpp.md)