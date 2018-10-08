---
title: 'Hora atual: Classes de automação | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- time, setting current
- current time, COleDateTime object
- procedures, getting current time
- Automation classes, current time
- time, getting current
ms.assetid: cc967f17-1189-4cf3-85f9-1969462d5f72
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8ead35da3c20630e93757787f54755dd383264d2
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48860609"
---
# <a name="current-time-automation-classes"></a>Hora atual: Classes de automação

O procedimento a seguir mostra como criar um `COleDateTime` do objeto e inicializá-lo com a hora atual.

## <a name="to-get-the-current-time"></a>Para obter a hora atual

1. Crie um objeto `COleDateTime`.

1. Chamar `GetCurrentTime`.

   [!code-cpp[NVC_ATLMFC_Utilities#177](../atl-mfc-shared/codesnippet/cpp/current-time-automation-classes_1.cpp)]

## <a name="see-also"></a>Consulte também

[Data e hora: suporte a automação](../atl-mfc-shared/date-and-time-automation-support.md)
