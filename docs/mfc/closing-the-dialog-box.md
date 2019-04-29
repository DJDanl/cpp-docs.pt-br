---
title: Fechando a caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], closing
- dialog boxes [MFC], closing
ms.assetid: 946f5675-c482-46a4-a5dd-34fe138ffae5
ms.openlocfilehash: 07e4159eccde1fab89d4a5ffadee4e6d11fc20f0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326840"
---
# <a name="closing-the-dialog-box"></a>Fechando a caixa de diálogo

Caixa de diálogo modal fecha quando o usuário escolhe um dos seus botões, normalmente no botão Okey ou o botão Cancelar. Escolher o botão Okey ou Cancelar faz com que o Windows enviar o objeto de caixa de diálogo uma **BN_CLICKED** mensagem de notificação de controle com o botão ou a ID do, do **IDOK** ou **IDCANCEL**. `CDialog` fornece funções de manipulador de padrão para essas mensagens: `OnOK` e `OnCancel`. A chamada de manipuladores padrão a `EndDialog` a função de membro para fechar a janela da caixa de diálogo. Você também pode chamar `EndDialog` de seu próprio código. Para obter mais informações, consulte o [EndDialog](../mfc/reference/cdialog-class.md#enddialog) função de membro da classe `CDialog` no *referência da MFC*.

Para organizar para fechar e excluir uma caixa de diálogo sem janela restrita, substituir `PostNcDestroy` e chamar o **exclua** operador no **isso** ponteiro. [Destruindo a caixa de diálogo](../mfc/destroying-the-dialog-box.md) explica o que acontece em seguida.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
