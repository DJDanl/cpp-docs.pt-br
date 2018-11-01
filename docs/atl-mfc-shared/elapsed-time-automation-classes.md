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
ms.openlocfilehash: fbd01a4e7268456af342293d77ef74d372d2e639
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50583905"
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

[Data e hora: suporte a automação](../atl-mfc-shared/date-and-time-automation-support.md)
