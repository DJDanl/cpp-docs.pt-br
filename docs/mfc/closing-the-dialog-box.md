---
title: Fechando a caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], closing
- dialog boxes [MFC], closing
ms.assetid: 946f5675-c482-46a4-a5dd-34fe138ffae5
ms.openlocfilehash: 48ea954552b3ea9aa7193a47fc2a66d731312d77
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685380"
---
# <a name="closing-the-dialog-box"></a>Fechando a caixa de diálogo

Uma caixa de diálogo modal é fechada quando o usuário escolhe um de seus botões, normalmente o botão OK ou o botão Cancelar. Escolher o botão OK ou cancelar faz com que o Windows envie o objeto da caixa de diálogo uma mensagem de notificação de controle **BN_CLICKED** com a ID do botão, **IDOK** ou **IDCANCEL**. `CDialog` fornece funções de manipulador padrão para essas mensagens: `OnOK` e `OnCancel`. Os manipuladores padrão chamam a função de membro `EndDialog` para fechar a janela de diálogo. Você também pode chamar `EndDialog` de seu próprio código. Para obter mais informações, consulte a função membro [EndDialog](../mfc/reference/cdialog-class.md#enddialog) da classe `CDialog` na *referência do MFC*.

Para organizar o fechamento e a exclusão de uma caixa de diálogo sem janela restrita, substitua `PostNcDestroy` e invoque o operador **delete** **no ponteiro.** [A destruição da caixa de diálogo](../mfc/destroying-the-dialog-box.md) explica o que acontece em seguida.

## <a name="see-also"></a>Consulte também

[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
