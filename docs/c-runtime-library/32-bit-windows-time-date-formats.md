---
title: Formatos de data/hora do Windows de 32 bits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.time
dev_langs:
- C++
helpviewer_keywords:
- 32-bit Windows
ms.assetid: ef1589db-84d7-4b24-8799-7c7a22cfe2bf
caps.latest.revision: 6
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
ms.translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: bd00adddbf728aae66120fede63e0b6a0c5439a7
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="32-bit-windows-timedate-formats"></a>Formatos de data/hora do Windows de 32 bits
A data e a hora do arquivo são armazenadas individualmente, usando inteiros sem sinal como campos de bits. A data e a hora do arquivo são incluídas como segue:  
  
### <a name="time"></a>Hora  
  
|Posição de bit:|0   1   2   3   4|5   6   7   8   9   A|B   C   D   E   F|  
|-------------------|-----------------------|---------------------------|-----------------------|  
|Comprimento:|5|6|5|  
|Conteúdo:|horas|minutos|incrementos de 2 segundos|  
|Alcance de valores:|0-23|0-59|0-29 em intervalos de 2 segundos|  
  
### <a name="date"></a>Date  
  
|Posição de bit:|0   1   2   3   4   5   6|7   8   9   A|B   C   D   E   F|  
|-------------------|-------------------------------|-------------------|-----------------------|  
|Comprimento:|7|4|5|  
|Conteúdo:|ano|mês|dia|  
|Alcance de valores:|0-119|1-12|1-31|  
||(relativo a 1980)|||  
  
## <a name="see-also"></a>Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)
