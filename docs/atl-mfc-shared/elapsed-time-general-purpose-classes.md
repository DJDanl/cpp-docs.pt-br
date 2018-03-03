---
title: 'Tempo decorrido: Classes de uso geral | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- adding dates
- calculating dates and times
- dates, calculating intervals
- elapsed time, calculating
- elapsed time
- time, elapsed
- intervals, date and time
- calculations, date and time
ms.assetid: e5c5d3d2-ce1d-409e-875c-98848434e716
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 51eea60669fb7ad35525d65013ffc8420649349b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="elapsed-time-general-purpose-classes"></a>Tempo decorrido: Classes de uso geral
O procedimento a seguir mostra como calcular a diferença entre dois `CTime` objetos e obter um `CTimeSpan` resultados.  
  
#### <a name="to-calculate-elapsed-time"></a>Para calcular o tempo decorrido  
  
1.  Use o `CTime` e `CTimeSpan` objetos para calcular o tempo decorrido, da seguinte maneira:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#174](../atl-mfc-shared/codesnippet/cpp/elapsed-time-general-purpose-classes_1.cpp)]  
  
     Depois que você calculou `elapsedTime`, você pode usar as funções de membro de `CTimeSpan` para extrair os componentes de valor de tempo decorrido.  
  
## <a name="see-also"></a>Consulte também  
 [Data e hora: classes de uso geral](../atl-mfc-shared/date-and-time-general-purpose-classes.md)

