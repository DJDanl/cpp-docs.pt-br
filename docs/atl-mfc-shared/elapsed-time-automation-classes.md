---
title: 'Tempo decorrido: Classes de automação'
ms.date: 11/04/2016
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
ms.openlocfilehash: d6a77d57a88166354fcb222c0da09690426108e9
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57750043"
---
# <a name="elapsed-time-automation-classes"></a>Tempo decorrido: Classes de automação

Este procedimento mostra como calcular a diferença entre dois `CTime` objetos e obtenha um `CTimeSpan` resultado.

## <a name="to-calculate-elapsed-time"></a>Para calcular o tempo decorrido

1. Crie duas `COleDateTime` objetos.

1. Definir uma da `COleDateTime` objetos a hora atual.

1. Execute uma tarefa demorada.

1. As outras `COleDateTime` objeto para a hora atual.

1. Calcule a diferença entre as duas horas.

   [!code-cpp[NVC_ATLMFC_Utilities#178](../atl-mfc-shared/codesnippet/cpp/elapsed-time-automation-classes_1.cpp)]

## <a name="see-also"></a>Consulte também

[Data e hora: Suporte de automação](../atl-mfc-shared/date-and-time-automation-support.md)
