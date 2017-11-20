---
title: "Suporte de ponto flutuante para código anterior (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: a2a26b96-7bc2-418a-981a-51aa1a0294a2
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 3ddc151a2a0f74c6f77be68cd026147a318a595a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="floating-point-support-for-older-code-visual-c"></a>Suporte de ponto flutuante para código anterior (Visual C++)
Os registros de pilha de ponto flutuante (MM0-MM7/ST0-ST7) e MMX são preservados em alternâncias de contexto.  Não há nenhum convenção de chamada explícita para esses registros.  O uso de um desses registros é proibido no código em modo kernel.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)