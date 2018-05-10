---
title: Deslocamentos para a direita | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: c878e97d-ea3c-4c6b-90a8-b1b24b2d5b19
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c2eac057bbf8164915ff645cca098bbbf7c1995a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="right-shifts"></a>Deslocamentos para a direita
O resultado de um deslocamento à direita de um valor negativo tipo integral com sinal  
  
 O deslocamento de um valor negativo para a direita gera metade do valor absoluto, arredondado para baixo. Por exemplo, um valor `short` de -253 com sinal (hexadecimal 0xFF03, binário 11111111 00000011) deslocado à direita de um bit produz -127 (hexadecimal 0xFF81, binário 11111111 10000001). Um 253 positivo deslocado à direita gera + 126.  
  
 Deslocamentos para a direita preservam o bit de sinal de tipos integrais com sinal. Quando um inteiro assinado é deslocado para a direita, o bit mais significativo permanece definido. Por exemplo, se 0xF0000000 for um `int` com sinal, um deslocamento à direita produz 0xF8000000. Deslocar um `int` negativo para a direita 32 vezes produz 0xFFFFFFFF.  
  
 Quando um inteiro não assinado é deslocado para a direita, o bit mais significativo é limpo. Por exemplo, se 0xF000 não tiver sinal, o resultado será 0x7800. Deslocar um `unsigned` ou `int` positivo à direita 32 vezes produz 0x00000000.  
  
## <a name="see-also"></a>Consulte também  
 [Inteiros](../c-language/integers.md)