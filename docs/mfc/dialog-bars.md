---
title: Barras da caixa de diálogo
ms.date: 11/19/2018
helpviewer_keywords:
- MFC, control bars
- CDialogBar class [MFC], dialog bars
- control bars [MFC], dialog bars
- dialog bars
- dialog bars [MFC], about dialog bars
ms.assetid: 485c8055-6bb0-4051-8417-dd2971499321
ms.openlocfilehash: 800cc208df7299cf440508c2705b0b0ddb9ae665
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175347"
---
# <a name="dialog-bars"></a>Barras da caixa de diálogo

Uma barra de diálogo é uma barra de ferramentas, um tipo de [barra de controle](../mfc/control-bars.md) que pode conter qualquer tipo de controle. Porque ele tem as características de uma caixa de diálogo sem janela restrita, uma [CDialogBar](../mfc/reference/cdialogbar-class.md) objeto fornece uma barra de ferramentas mais poderosa.

Há várias diferenças importantes entre uma barra de ferramentas e um `CDialogBar` objeto. Um `CDialogBar` objeto é criado a partir de um recurso de modelo de caixa de diálogo, que pode ser criado com o editor de caixa de diálogo do Visual C++ e que pode conter qualquer tipo de controle do Windows. O usuário pode usar tab do controle ao controle. E você pode especificar um estilo de alinhamento para alinhar a barra da caixa de diálogo com qualquer parte da janela do quadro pai ou até mesmo para deixá-lo onde se o pai for redimensionado. A figura a seguir mostra uma barra de diálogo com uma variedade de controles.

![Barra de diálogo do VC](../mfc/media/vc378t1.gif "barra de diálogo do VC") <br/>
Uma barra da caixa de diálogo

Em outros aspectos, trabalhando com um `CDialogBar` objeto é semelhante a trabalhar com uma caixa de diálogo sem janela restrita. Use o editor de caixa de diálogo para projetar e criar o recurso de caixa de diálogo.

Um das virtudes de barras da caixa de diálogo é que eles podem incluir controles diferentes dos botões.

Embora seja normal para derivar suas próprias classes de caixa de diálogo de `CDialog`, você normalmente não derivar sua própria classe de uma barra de diálogo. Barras da caixa de diálogo são extensões para uma janela principal e qualquer mensagem de notificação de controle de barra de diálogo, como **BN_CLICKED** ou **eventos EN_CHANGE**, serão enviadas para o pai da caixa de diálogo de barras, a janela principal.

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Amostra](../visual-cpp-samples.md)

