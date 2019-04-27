---
title: Acesso fortemente tipado a controles sem assistentes de código
ms.date: 11/04/2016
helpviewer_keywords:
- dialog boxes [MFC], accessing controls
- dialog box controls [MFC], accessing
ms.assetid: 325b4927-d49b-42b4-8e0b-fc84f31fb059
ms.openlocfilehash: 5b4b604bf42a327edf3ac7a83dcfc42a5e0d8c54
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62180805"
---
# <a name="type-safe-access-to-controls-without-code-wizards"></a>Acesso fortemente tipado a controles sem assistentes de código

A primeira abordagem para criar acesso fortemente tipado a controles usa uma função de membro embutida para converter o tipo de retorno da classe `CWnd`do `GetDlgItem` a função de membro para o tipo apropriado de controle do C++, como neste exemplo:

[!code-cpp[NVC_MFCControlLadenDialog#50](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_1.cpp)]

Em seguida, você pode usar essa função de membro para o controle de acesso de maneira fortemente tipada, com um código semelhante ao seguinte:

[!code-cpp[NVC_MFCControlLadenDialog#51](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_2.cpp)]

## <a name="see-also"></a>Consulte também

[Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)<br/>
[Acesso fortemente tipado a controles com assistentes de código](../mfc/type-safe-access-to-controls-with-code-wizards.md)
