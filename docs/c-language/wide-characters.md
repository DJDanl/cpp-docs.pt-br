---
title: Caracteres largos
ms.date: 11/04/2016
helpviewer_keywords:
- wide characters
ms.assetid: 165c4a12-8ab9-45fb-9964-c55e9956194c
ms.openlocfilehash: 619adfd398f3955708df3267613de40e71e15fa6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452059"
---
# <a name="wide-characters"></a>Caracteres largos

**ANSI 3.1.3.4** O valor de uma constante de caractere de inteiro que contém mais de um caractere ou uma constante de caractere largo que contém mais de um caractere multibyte

A constante de caractere comum, 'ab' tem o valor inteiro (int)0x6162. Quando houver mais de um byte, os bytes lidos anteriormente são deslocados para a esquerda pelo valor de **CHAR_BIT** e o próximo byte é comparado usando o operador bitwise-OR com baixos bits **CHAR_BIT**. O número de bytes na constante de caracteres multibyte não pode exceder sizeof(int), que é 4 para o código de 32 bits de destino.

A constante de caracteres multibyte é lida como acima e é convertida em uma constante de caractere largo usando a função de tempo de execução `mbtowc`. Se o resultado não for uma constante de caractere largo válida, um erro será emitido. Em todo caso, o número de bytes examinados pela função `mbtowc` é limitado ao valor de `MB_CUR_MAX`.

## <a name="see-also"></a>Consulte também

[Caracteres](../c-language/characters.md)