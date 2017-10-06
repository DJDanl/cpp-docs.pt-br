---
title: Intervalos de tipos de dados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
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
caps.latest.revision: 25
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 372d65a3d862fee4fddc2c9ba67c94341d1a6c87
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="data-type-ranges"></a>Intervalos de tipos de dados
Os compiladores de 32 bits e 64 bits do Visual C++ reconhecem os tipos na tabela mais adiante neste artigo.  
  
-   `int` (`unsigned int`)  
  
-   `__int8` (`unsigned __int8`)  
  
-   `__int16` (`unsigned __int16`)  
  
-   `__int32` (`unsigned __int32`)  
  
-   `__int64` (`unsigned __int64`)  
  
-   `short` (`unsigned short`)  
  
-   `long` (`unsigned long`)  
  
-   `long` `long` (`unsigned long long`)  
  
 Se o nome começa com sublinhados duplos (`__`), um tipo de dados é diferente do padrão.  
  
 Os intervalos especificados na tabela a seguir são inclusivo-inclusivo.  
  
|Nome do tipo|Bytes|Outros nomes|Intervalo de valores|  
|---------------|-----------|-----------------|---------------------|  
|int|4|signed|-2.147.483.648 a 2.147.483.647|  
|unsigned int|4|sem sinal|0 a 4.294.967.295|  
|__int8|1|char|-128 a 127|  
|unsigned __int8|1|unsigned char|0 a 255|  
|__int16|2|short, short int, signed short int|-32.768 a 32.767|  
|unsigned __int16|2|unsigned short, unsigned short int|0 a 65.535|  
|__int32|4|signed, signed int, int|-2.147.483.648 a 2.147.483.647|  
|unsigned __int32|4|unsigned, unsigned int|0 a 4.294.967.295|  
|__int64|8|long long, signed long long|-9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|  
|unsigned __int64|8|unsigned long long|0 a 18.446.744.073.709.551.615|  
|bool|1|nenhum|false ou true|  
|char|1|nenhum|-128 a 127 por padrão<br /><br /> 0 a 255 quando compilado usando [/J](../build/reference/j-default-char-type-is-unsigned.md)|  
|signed char|1|nenhum|-128 a 127|  
|unsigned char|1|nenhum|0 a 255|  
|short|2|short int, signed short int|-32.768 a 32.767|  
|unsigned short|2|unsigned short int|0 a 65.535|  
|long|4|long int, signed long int|-2.147.483.648 a 2.147.483.647|  
|unsigned long|4|unsigned long int|0 a 4.294.967.295|  
|long long|8|none (mas equivalente a __int64)|-9.223.372.036.854.775.808 a 9.223.372.036.854.775.807|  
|unsigned long long|8|none (mas equivalente a unsigned __int64)|0 a 18.446.744.073.709.551.615|  
|enum|varia|nenhum| |  
|float|4|nenhum|3.4E +/- 38 (7 dígitos)|  
|double|8|nenhum|1.7E +/- 308 (15 dígitos)|  
|long double|igual a double|nenhum|Igual a double|  
|wchar_t|2|__wchar_t|0 a 65.535|  
  
 Dependendo de como é usada, uma variável de `__wchar_t` designa um tipo de caractere largo ou um tipo de caractere multibyte. Use o prefixo `L` antes de uma constante de caractere ou de cadeia de caracteres para designar a constante de tipo de caractere largo.  
  
 `signed` e `unsigned` são os modificadores que você pode usar com qualquer tipo integral, exceto `bool`. Observe que `char`, `signed char` e `unsigned char` são três tipos distintos para fins de mecanismos como sobrecarga e modelos.  
  
 O `int` e `unsigned int` tipos têm um tamanho de quatro bytes. No entanto, o código portátil não deve depender do tamanho de `int` porque o padrão de linguagem permite que ele seja específico da implementação.  
  
 C/C++ no Visual Studio também tem suporte para tipos de inteiros dimensionados. Para obter mais informações, consulte [int8, \__int16, \__int32, \__int64](../cpp/int8-int16-int32-int64.md) e [limites de inteiro](../cpp/integer-limits.md).  
  
 Para obter mais informações sobre as restrições dos tamanhos de cada tipo, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
 O intervalo dos tipos enumerados varia dependendo do contexto de linguagem e dos sinalizadores de compilador especificados. Para obter mais informações, consulte [declarações de enumeração C](../c-language/c-enumeration-declarations.md) e [enumerações](../cpp/enumerations-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)
