---
title: Destruindo a caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- dialog boxes [MFC], deleting
- destruction, dialog box
- dialog boxes [MFC], destroying
- dialog boxes [MFC], removing
- modeless dialog boxes [MFC], destroying
- MFC dialog boxes [MFC], destroying
- modal dialog boxes [MFC], destroying
ms.assetid: dabceee7-3639-4d85-bf34-73515441b3d0
ms.openlocfilehash: 84ae5b336bb8eeac4f8ab7b6e5b9f00246f9ca15
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57261993"
---
# <a name="destroying-the-dialog-box"></a>Destruindo a caixa de diálogo

Caixas de diálogo modal normalmente são criadas no quadro da pilha e destruídas quando termina a função que os criou. Destruidor do objeto de caixa de diálogo é chamado quando o objeto sai do escopo.

Caixas de diálogo sem janela restrita normalmente são criadas e pertencentes a uma janela de exibição ou o quadro pai — janela do quadro principal do aplicativo ou em uma janela de quadro do documento. O padrão [OnClose](../mfc/reference/cwnd-class.md#onclose) chamadas do manipulador [DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow), que destrói a janela da caixa de diálogo. Se a caixa de diálogo é a única, com nenhum ponteiros para ele ou outras semânticas especiais de propriedade, você deve substituir [PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy) para destruir o objeto de caixa de diálogo do C++. Você também deve substituir [OnCancel](../mfc/reference/cdialog-class.md#oncancel) e chame `DestroyWindow` de dentro dele. Caso contrário, o proprietário da caixa de diálogo deve destruir o objeto de C++ quando ele não é mais necessário.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
