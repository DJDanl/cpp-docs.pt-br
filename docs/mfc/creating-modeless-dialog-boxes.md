---
title: Criando caixas de diálogo sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
ms.assetid: 70d78c7f-3d40-477b-9f78-0f33c359f88b
ms.openlocfilehash: 7a6125e84438b0ef2ad541c26bda33051d483c8d
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619634"
---
# <a name="creating-modeless-dialog-boxes"></a>Criando caixas de diálogo sem janela restrita

Para uma caixa de diálogo sem janela restrita, você deve fornecer seu próprio construtor público em sua classe de caixa de diálogo. Para criar uma caixa de diálogo sem janela restrita, chame seu construtor público e, em seguida, chame a função de membro [Create](reference/cdialog-class.md#create) do objeto Dialog para carregar o recurso de caixa de diálogo. Você pode chamar **Create** durante ou após a chamada de construtor. Se o recurso de caixa de diálogo tiver a propriedade **WS_VISIBLE**, a caixa de diálogo será exibida imediatamente. Caso contrário, você deve chamar sua função de membro de [janela](reference/cwnd-class.md#showwindow) .

## <a name="see-also"></a>Consulte também

[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
