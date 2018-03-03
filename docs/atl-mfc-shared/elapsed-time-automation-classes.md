---
title: "Tempo decorrido: Classes de automação | Microsoft Docs"
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
- elapsed time, calculating in Automation
- Automation classes, elapsed time
- time, elapsed
- intervals, date and time
- calculations, date and time
ms.assetid: 26b34b37-c10e-4b91-82c3-1dc5ffb5361f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0e4cf7fef17499910d9664ab26fa1b07438e7900
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="elapsed-time-automation-classes"></a>Tempo decorrido: Classes de automação
Este procedimento mostra como calcular a diferença entre dois `CTime` objetos e obter um `CTimeSpan` resultados.  
  
#### <a name="to-calculate-elapsed-time"></a>Para calcular o tempo decorrido  
  
1.  Criar dois `COleDateTime` objetos.  
  
2.  Definir um o `COleDateTime` objetos para a hora atual.  
  
3.  Execute uma tarefa demorada.  
  
4.  As outras `COleDateTime` objeto para a hora atual.  
  
5.  Calcule a diferença entre as duas horas.  
  
     [!code-cpp[NVC_ATLMFC_Utilities#178](../atl-mfc-shared/codesnippet/cpp/elapsed-time-automation-classes_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Data e hora: suporte a automação](../atl-mfc-shared/date-and-time-automation-support.md)

