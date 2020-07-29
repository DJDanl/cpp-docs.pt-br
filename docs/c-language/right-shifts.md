---
title: Deslocamentos para a direita
ms.date: 11/04/2016
ms.assetid: c878e97d-ea3c-4c6b-90a8-b1b24b2d5b19
ms.openlocfilehash: 4b83aa231e6e7904fe5682b32a861ffe301b9747
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87199406"
---
# <a name="right-shifts"></a>Deslocamentos para a direita

O resultado de um deslocamento à direita de um valor negativo tipo integral com sinal

O deslocamento de um valor negativo para a direita gera metade do valor absoluto, arredondado para baixo. Por exemplo, um **`signed short`** valor de-253 (Hex 0xFF03, binary 11111111 00000011) foi deslocado para a direita um bit produz-127 (Hex 0xFF81, binary 11111111 10000001). Um 253 positivo deslocado à direita gera + 126.

Deslocamentos para a direita preservam o bit de sinal de tipos integrais com sinal. Quando um inteiro assinado é deslocado para a direita, o bit mais significativo permanece definido. Por exemplo, se 0xF0000000 for assinado **`int`** , um deslocamento à direita produzirá 0xF8000000. A mudança de um **`int`** à direita negativo de 32 vezes produz 0xFFFFFFFF.

Quando um inteiro não assinado é deslocado para a direita, o bit mais significativo é limpo. Por exemplo, se 0xF000 não tiver sinal, o resultado será 0x7800. A mudança de um **`unsigned`** or positivo para a **`int`** direita 32 vezes produz 0x00000000.

## <a name="see-also"></a>Confira também

[Inteiros](../c-language/integers.md)
