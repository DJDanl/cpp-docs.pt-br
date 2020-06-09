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
ms.openlocfilehash: 052e0b8a085c052f73d3c6540521f57fdfbb9c51
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624894"
---
# <a name="dialog-bars"></a>Barras da caixa de diálogo

Uma barra de diálogo é uma barra de ferramentas, um tipo de [barra de controle](control-bars.md) que pode conter qualquer tipo de controle. Como ele tem as características de uma caixa de diálogo sem janela restrita, um objeto [CDialogBar](reference/cdialogbar-class.md) fornece uma barra de ferramentas mais potente.

Há várias diferenças importantes entre uma barra de ferramentas e um `CDialogBar` objeto. Um `CDialogBar` objeto é criado a partir de um recurso de modelo de caixa de diálogo, que você pode criar com o Visual C++ editor de diálogo e que pode conter qualquer tipo de controle do Windows. O usuário pode fazer a Tabulação do controle para o controle. E você pode especificar um estilo de alinhamento para alinhar a barra de diálogo com qualquer parte da janela do quadro pai ou até mesmo para deixá-la em vigor se o pai for redimensionado. A figura a seguir mostra uma barra de diálogo com uma variedade de controles.

![Barra de diálogo do VC](../mfc/media/vc378t1.gif "Barra de diálogo do VC") <br/>
Uma barra de diálogo

Em outros aspectos, trabalhar com um `CDialogBar` objeto é como trabalhar com uma caixa de diálogo sem janela restrita. Use o editor de caixa de diálogo para projetar e criar o recurso de caixa de diálogo.

Uma das virtudes das barras de diálogo é que elas podem incluir controles diferentes de botões.

Embora seja normal derivar suas próprias classes de caixa de diálogo `CDialog` , você normalmente não deriva sua própria classe para uma barra de diálogo. As barras de diálogo são extensões para uma janela principal e quaisquer mensagens de notificação de controle de barra de diálogo, como **BN_CLICKED** ou **EN_CHANGE**, serão enviadas ao pai da barra de diálogo, a janela principal.

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](user-interface-elements-mfc.md)<br/>
[Amostra](../overview/visual-cpp-samples.md)
