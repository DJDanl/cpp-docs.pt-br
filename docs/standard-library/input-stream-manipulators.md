---
title: Manipuladores de Fluxo de Entrada | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- input streams, manipulators
- input stream objects
ms.assetid: 0addcacb-7b7b-4d70-9775-a59abc400fb3
caps.latest.revision: 8
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 3b5f43364e0cfb286ead62f1c38d4d30aec707fc
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="input-stream-manipulators"></a>Manipuladores de Fluxo de Entrada
Muitos manipuladores, como [setprecision]--brokenlink--(../Topic/not%20found:3ddde610-70cc-4cfa-8a89-3e83d1d356a8.md#setprecision), são definidos para a classe `ios` e, assim, se aplicam a fluxos de entrada. No entanto, alguns manipuladores de fato afetam objetos de fluxo de entrada. Ente aqueles que o fazem, os mais importantes são os manipuladores base, `dec`, `oct` e `hex`, que determinam a base de conversão usada com números do fluxo de entrada.  
  
 Na extração, o manipulador `hex` habilita o processamento de vários formatos de entrada. Por exemplo, c, C, 0xc, 0xC, 0Xc e 0XC são interpretados como o inteiro decimal 12. Qualquer caractere que não estiver nos intervalos de 0-9, A-F e a-f e que não seja x e X finaliza a conversão numérica. Sendo assim, a sequência `"124n5"` é convertida no número 124 com o conjunto de bits [basic_ios::fail](../standard-library/basic-ios-class.md#fail).  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)


