---
title: 'Tempo decorrido: Classes de finalidade geral | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 98e3c07522ead22467455ce2d601270e7b624be0
ms.sourcegitcommit: f7703076b850c717c33d72fb0755fbb2215c5ddc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2018
ms.locfileid: "43131608"
---
# <a name="elapsed-time-general-purpose-classes"></a>Tempo decorrido: Classes de uso geral
O procedimento a seguir mostra como calcular a diferença entre dois `CTime` objetos e obtenha um `CTimeSpan` resultado. Use o `CTime` e `CTimeSpan` objetos para calcular o tempo decorrido, da seguinte maneira:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#174](../atl-mfc-shared/codesnippet/cpp/elapsed-time-general-purpose-classes_1.cpp)]  
  
Após você ter calculado `elapsedTime`, você pode usar as funções de membro de `CTimeSpan` para extrair os componentes de valor de tempo decorrido.  

