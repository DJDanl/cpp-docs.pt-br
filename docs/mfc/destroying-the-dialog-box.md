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
ms.openlocfilehash: 9b1244b03dc3f6f418730dd782050448f3bf8934
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621912"
---
# <a name="destroying-the-dialog-box"></a>Destruindo a caixa de diálogo

As caixas de diálogo modais normalmente são criadas no quadro de pilhas e destruídas quando a função que as criou termina. O destruidor do objeto da caixa de diálogo é chamado quando o objeto sai do escopo.

As caixas de diálogo sem janela restrita normalmente são criadas e pertencem a uma janela de exibição ou quadro pai – a janela do quadro principal do aplicativo ou uma janela de quadro do documento. O manipulador [fechamento](reference/cwnd-class.md#onclose) padrão chama [DestroyWindow](reference/cwnd-class.md#destroywindow), que destrói a janela da caixa de diálogo. Se a caixa de diálogo for autônoma, sem ponteiros para ela ou outra semântica de propriedade especial, você deverá substituir [PostNcDestroy](reference/cwnd-class.md#postncdestroy) para destruir o objeto da caixa de diálogo C++. Você também deve substituir [OnCancel](reference/cdialog-class.md#oncancel) e chamar `DestroyWindow` de dentro dele. Caso contrário, o proprietário da caixa de diálogo deverá destruir o objeto C++ quando ele não for mais necessário.

## <a name="see-also"></a>Consulte também

[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
