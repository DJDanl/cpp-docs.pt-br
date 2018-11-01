---
title: 'Tempo decorrido: Classes de uso geral'
ms.date: 11/04/2016
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
ms.openlocfilehash: ebaf77b34411cd55cb3a028bcce9109613b63ed9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50676714"
---
# <a name="elapsed-time-general-purpose-classes"></a>Tempo decorrido: Classes de uso geral

O procedimento a seguir mostra como calcular a diferença entre dois `CTime` objetos e obtenha um `CTimeSpan` resultado. Use o `CTime` e `CTimeSpan` objetos para calcular o tempo decorrido, da seguinte maneira:

   [!code-cpp[NVC_ATLMFC_Utilities#174](../atl-mfc-shared/codesnippet/cpp/elapsed-time-general-purpose-classes_1.cpp)]

Após você ter calculado `elapsedTime`, você pode usar as funções de membro de `CTimeSpan` para extrair os componentes de valor de tempo decorrido.

