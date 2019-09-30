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
ms.openlocfilehash: 8b407c6e832dde7a5865146e7cc12d1840d3234a
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685850"
---
# <a name="destroying-the-dialog-box"></a>Destruindo a caixa de diálogo

As caixas de diálogo modais normalmente são criadas no quadro de pilhas e destruídas quando a função que as criou termina. O destruidor do objeto da caixa de diálogo é chamado quando o objeto sai do escopo.

As caixas de diálogo sem janela restrita normalmente são criadas e pertencem a uma janela de exibição ou quadro pai – a janela do quadro principal do aplicativo ou uma janela de quadro do documento. O manipulador [fechamento](../mfc/reference/cwnd-class.md#onclose) padrão chama [DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow), que destrói a janela da caixa de diálogo. Se a caixa de diálogo for autônoma, sem ponteiros para ela ou outra semântica de propriedade especial, você deverá substituir [PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy) para destruir C++ o objeto da caixa de diálogo. Você também deve substituir [OnCancel](../mfc/reference/cdialog-class.md#oncancel) e chamar `DestroyWindow` de dentro dele. Caso contrário, o proprietário da caixa de diálogo deverá destruir o C++ objeto quando ele não for mais necessário.

## <a name="see-also"></a>Consulte também

[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
