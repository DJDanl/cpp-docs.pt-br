---
title: Especificações de caractere octa e hexadecimal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- octal characters
- hexadecimal characters
ms.assetid: 9264f3ec-46b8-41a5-b21a-8f7ed0a11871
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eeb1f8e08fbb1d4f30517485c9296febab5a0de0
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43198750"
---
# <a name="octal-and-hexadecimal-character-specifications"></a>Especificações de caractere octa e hexadecimal
A sequência **\\**<em>ooo</em> significa que é possível especificar qualquer caractere no conjunto de caracteres ASCII como um código de caracteres octal de três dígitos. O valor numérico inteiro octal especifica o valor de caractere desejado ou do caractere largo.  
  
 De maneira semelhante, a sequência **\x**<em>hhh</em> permite especificar qualquer caractere ASCII como um código de caracteres hexadecimal. Por exemplo, o caractere de backspace ASCII pode ser atribuído como a sequência de escape C normal (**\b**) ou codificado como **\010** (octal) ou **\x008** (hexadecimal).  
  
 Você pode usar somente os dígitos de 0 a 7 em uma sequência de escape octal. As sequências de escape octais nunca poderão ser maiores do que três dígitos e são encerradas pelo primeiro caractere que não seja um dígito octal. Embora não seja necessário usar todos os três dígitos, você deve usar pelo menos um. Por exemplo, a representação octal é **\10** para o caractere de backspace ASCII e **\101** para a letra A, conforme indicado em um gráfico ASCII.  
  
 De maneira semelhante, você deve usar pelo menos um dígito para uma sequência de escape hexadecimal, mas você pode omitir o segundo e o terceiro dígitos. Portanto, é possível especificar a sequência de escape hexadecimal para o caractere de backspace como **\x8**, **\x08** ou **\x008**.  
  
 O valor da sequência de escape octal ou hexadecimal deve estar no intervalo de valores representáveis para o tipo **unsigned char** para uma constante de caractere e o tipo `wchar_t` para uma constante de caractere amplo. Consulte [Caracteres multibytes e largos](../c-language/multibyte-and-wide-characters.md) para obter informações sobre constantes de caractere largo.  
  
 Ao contrário das constantes de escape octal, o número de dígitos hexadecimais em uma sequência de escape é ilimitado. Uma sequência de escape hexadecimal é encerrada no primeiro caractere que não seja um dígito hexadecimal. Como os dígitos hexadecimais incluem as letras **a** a **f**, é preciso tomar cuidado para garantir que a sequência de escape seja encerrada no dígito pretendido. Para evitar confusão, você pode colocar definições octais ou hexadecimais de caracteres em uma definição de macro:  
  
```  
#define Bell '\x07'  
```  
  
 Para valores hexadecimais, você pode dividir a cadeia de caracteres para mostrar claramente o valor correto:  
  
```  
"\xabc"    /* one character  */  
"\xab" "c" /* two characters */  
```  
  
## <a name="see-also"></a>Consulte também  
 [Constantes de caractere C](../c-language/c-character-constants.md)