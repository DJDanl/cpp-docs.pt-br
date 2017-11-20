---
title: Deslocamentos para a direita | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: c878e97d-ea3c-4c6b-90a8-b1b24b2d5b19
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cee551dfd0dbac11110a945edee21af6636138bc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="right-shifts"></a>Deslocamentos para a direita
O resultado de um deslocamento à direita de um valor negativo tipo integral com sinal  
  
 O deslocamento de um valor negativo para a direita gera metade do valor absoluto, arredondado para baixo. Por exemplo, um valor `short` de -253 com sinal (hexadecimal 0xFF03, binário 11111111 00000011) deslocado à direita de um bit produz -127 (hexadecimal 0xFF81, binário 11111111 10000001). Um 253 positivo deslocado à direita gera + 126.  
  
 Deslocamentos para a direita preservam o bit de sinal de tipos integrais com sinal. Quando um inteiro assinado é deslocado para a direita, o bit mais significativo permanece definido. Por exemplo, se 0xF0000000 for um `int` com sinal, um deslocamento à direita produz 0xF8000000. Deslocar um `int` negativo para a direita 32 vezes produz 0xFFFFFFFF.  
  
 Quando um inteiro não assinado é deslocado para a direita, o bit mais significativo é limpo. Por exemplo, se 0xF000 não tiver sinal, o resultado será 0x7800. Deslocar um `unsigned` ou `int` positivo à direita 32 vezes produz 0x00000000.  
  
## <a name="see-also"></a>Consulte também  
 [Inteiros](../c-language/integers.md)