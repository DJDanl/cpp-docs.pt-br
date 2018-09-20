---
title: Fechar a caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC dialog boxes [MFC], closing
- dialog boxes [MFC], closing
ms.assetid: 946f5675-c482-46a4-a5dd-34fe138ffae5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e9ad4b8af63b68912c232767bf1fd14070fda261
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46409045"
---
# <a name="closing-the-dialog-box"></a>Fechando a caixa de diálogo

Caixa de diálogo modal fecha quando o usuário escolhe um dos seus botões, normalmente no botão Okey ou o botão Cancelar. Escolher o botão Okey ou Cancelar faz com que o Windows enviar o objeto de caixa de diálogo uma **BN_CLICKED** mensagem de notificação de controle com o botão ou a ID do, do **IDOK** ou **IDCANCEL**. `CDialog` fornece funções de manipulador de padrão para essas mensagens: `OnOK` e `OnCancel`. A chamada de manipuladores padrão a `EndDialog` a função de membro para fechar a janela da caixa de diálogo. Você também pode chamar `EndDialog` de seu próprio código. Para obter mais informações, consulte o [EndDialog](../mfc/reference/cdialog-class.md#enddialog) função de membro da classe `CDialog` no *referência da MFC*.

Para organizar para fechar e excluir uma caixa de diálogo sem janela restrita, substituir `PostNcDestroy` e chamar o **exclua** operador no **isso** ponteiro. [Destruindo a caixa de diálogo](../mfc/destroying-the-dialog-box.md) explica o que acontece em seguida.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

