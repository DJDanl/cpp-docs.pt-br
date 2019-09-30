---
title: Inicializando a caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- initializing dialog boxes [MFC]
- OnInitDialog method [MFC]
- modal dialog boxes [MFC], initializing
- modeless dialog boxes [MFC], initializing
- MFC dialog boxes [MFC], initializing
ms.assetid: 968142f5-19f9-4b34-a1d4-8e6412d4379b
ms.openlocfilehash: 14cdf94bef79f254b4aaa2c1c0dfba6c88b7498b
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685622"
---
# <a name="initializing-the-dialog-box"></a>Inicializando a caixa de diálogo

Depois que a caixa de diálogo e todos os seus controles são criados, mas logo antes da caixa de diálogo (de qualquer tipo) aparecer na tela, a função de membro [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) do objeto Dialog é chamada. Para uma caixa de diálogo modal, isso ocorre durante a chamada `DoModal`. Para uma caixa de diálogo sem janela restrita, `OnInitDialog` é chamado quando `Create` é chamado. Normalmente, você substitui `OnInitDialog` para inicializar os controles da caixa de diálogo, como definir o texto inicial de uma caixa de edição. Você deve chamar a função de membro `OnInitDialog` da classe base, `CDialog`, da substituição `OnInitDialog`.

Se você quiser definir a cor do plano de fundo da caixa de diálogo (e a de todas as outras caixas de diálogo em seu aplicativo), consulte [definindo a cor de fundo da caixa de diálogo](../mfc/setting-the-dialog-boxs-background-color.md).

## <a name="see-also"></a>Consulte também

[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
