---
title: Intervalo de valores inteiros | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 0e9c6161-8f3f-4bfb-9fcc-a6c8dc97d702
caps.latest.revision: 6
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: e8bc31699773cee0a0694a9ef58c274c016b1136
ms.lasthandoff: 02/25/2017

---
# <a name="range-of-integer-values"></a>Intervalo de valores inteiros
**ANSI 3.1.2.5** As representações e os conjuntos de valores de vários tipos de inteiros  
  
 Inteiros contêm 32 bits (quatro bytes). Os inteiros com sinal são representados no formato de dois complementos. O bit mais significativo contém o sinal: 1 para o negativo, 0 para o sinal positivo e zero. Os valores são listados abaixo:  
  
|Tipo|Mínimo e máximo|  
|----------|-------------------------|  
|**unsigned short**|0 a 65535|  
|`signed short`|–32768 a 32767|  
|`unsigned long`|0 a 4294967295|  
|**signed long**|–2147483648 a 2147483647|  
  
## <a name="see-also"></a>Consulte também  
 [Inteiros](../c-language/integers.md)
