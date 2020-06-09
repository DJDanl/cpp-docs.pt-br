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
ms.openlocfilehash: 1f8f8f7e40b1c873c4428542c628d02e250f14b4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626334"
---
# <a name="initializing-the-dialog-box"></a>Inicializando a caixa de diálogo

Depois que a caixa de diálogo e todos os seus controles são criados, mas logo antes da caixa de diálogo (de qualquer tipo) aparecer na tela, a função de membro [OnInitDialog](reference/cdialog-class.md#oninitdialog) do objeto Dialog é chamada. Para uma caixa de diálogo modal, isso ocorre durante a `DoModal` chamada. Para uma caixa de diálogo sem janela restrita, `OnInitDialog` é chamado quando `Create` é chamado. Normalmente, você substitui `OnInitDialog` para inicializar os controles da caixa de diálogo, como definir o texto inicial de uma caixa de edição. Você deve chamar a `OnInitDialog` função de membro da classe base, `CDialog` , de sua `OnInitDialog` substituição.

Se você quiser definir a cor do plano de fundo da caixa de diálogo (e a de todas as outras caixas de diálogo em seu aplicativo), consulte [definindo a cor de fundo da caixa de diálogo](setting-the-dialog-boxs-background-color.md).

## <a name="see-also"></a>Consulte também

[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
