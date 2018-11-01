---
title: Acesso fortemente tipado a controles sem assistentes de código
ms.date: 11/04/2016
helpviewer_keywords:
- dialog boxes [MFC], accessing controls
- dialog box controls [MFC], accessing
ms.assetid: 325b4927-d49b-42b4-8e0b-fc84f31fb059
ms.openlocfilehash: 2b337aa28d5fdf061d1db4b5cf66303688ef5bf3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501706"
---
# <a name="type-safe-access-to-controls-without-code-wizards"></a>Acesso fortemente tipado a controles sem assistentes de código

A primeira abordagem para criar acesso fortemente tipado a controles usa uma função de membro embutida para converter o tipo de retorno da classe `CWnd`do `GetDlgItem` a função de membro para o tipo apropriado de controle do C++, como neste exemplo:

[!code-cpp[NVC_MFCControlLadenDialog#50](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_1.cpp)]

Em seguida, você pode usar essa função de membro para o controle de acesso de maneira fortemente tipada, com um código semelhante ao seguinte:

[!code-cpp[NVC_MFCControlLadenDialog#51](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_2.cpp)]

## <a name="see-also"></a>Consulte também

[Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)<br/>
[Acesso fortemente tipado a controles com assistentes de código](../mfc/type-safe-access-to-controls-with-code-wizards.md)

