---
title: 'Tempo decorrido: Classes de automação | Microsoft Docs'
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
- elapsed time, calculating in Automation
- Automation classes, elapsed time
- time, elapsed
- intervals, date and time
- calculations, date and time
ms.assetid: 26b34b37-c10e-4b91-82c3-1dc5ffb5361f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dcde08e8ffdb30f9ebf0ae7577bf836e84513a07
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43751671"
---
# <a name="elapsed-time-automation-classes"></a>Tempo decorrido: Classes de automação

Este procedimento mostra como calcular a diferença entre dois `CTime` objetos e obtenha um `CTimeSpan` resultado.

#### <a name="to-calculate-elapsed-time"></a>Para calcular o tempo decorrido

1. Crie duas `COleDateTime` objetos.

2. Definir uma da `COleDateTime` objetos a hora atual.

3. Execute uma tarefa demorada.

4. As outras `COleDateTime` objeto para a hora atual.

5. Calcule a diferença entre as duas horas.

   [!code-cpp[NVC_ATLMFC_Utilities#178](../atl-mfc-shared/codesnippet/cpp/elapsed-time-automation-classes_1.cpp)]

## <a name="see-also"></a>Consulte também

[Data e hora: suporte a automação](../atl-mfc-shared/date-and-time-automation-support.md)

