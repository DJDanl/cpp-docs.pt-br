---
title: Fechando a caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], closing
- dialog boxes [MFC], closing
ms.assetid: 946f5675-c482-46a4-a5dd-34fe138ffae5
ms.openlocfilehash: a695a8e331eb8a4f22394deb65857bf93ecab41e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617204"
---
# <a name="closing-the-dialog-box"></a>Fechando a caixa de diálogo

Uma caixa de diálogo modal é fechada quando o usuário escolhe um de seus botões, normalmente o botão OK ou o botão Cancelar. Escolher o botão OK ou cancelar faz com que o Windows envie o objeto da caixa de diálogo um **BN_CLICKED** mensagem de notificação de controle com a ID do botão, **IDOK** ou **IDCANCEL**. `CDialog`fornece funções de manipulador padrão para essas mensagens: `OnOK` e `OnCancel` . Os manipuladores padrão chamam a `EndDialog` função de membro para fechar a janela da caixa de diálogo. Você também pode chamar `EndDialog` de seu próprio código. Para obter mais informações, consulte a função membro [EndDialog](reference/cdialog-class.md#enddialog) da classe `CDialog` na *referência do MFC*.

Para organizar o fechamento e a exclusão de uma caixa de diálogo sem janela restrita, substitua `PostNcDestroy` e invoque o **this** operador **delete** no ponteiro. [A destruição da caixa de diálogo](destroying-the-dialog-box.md) explica o que acontece em seguida.

## <a name="see-also"></a>Consulte também

[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
