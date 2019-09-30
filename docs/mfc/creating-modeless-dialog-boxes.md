---
title: Criando caixas de diálogo sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
ms.assetid: 70d78c7f-3d40-477b-9f78-0f33c359f88b
ms.openlocfilehash: 7da6d82257d1407dfcf4d6d3c15cdadbb8c0fa30
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685662"
---
# <a name="creating-modeless-dialog-boxes"></a>Criando caixas de diálogo sem janela restrita

Para uma caixa de diálogo sem janela restrita, você deve fornecer seu próprio construtor público em sua classe de caixa de diálogo. Para criar uma caixa de diálogo sem janela restrita, chame seu construtor público e, em seguida, chame a função de membro [Create](../mfc/reference/cdialog-class.md#create) do objeto Dialog para carregar o recurso de caixa de diálogo. Você pode chamar **Create** durante ou após a chamada de construtor. Se o recurso de caixa de diálogo tiver a propriedade **WS_VISIBLE**, a caixa de diálogo será exibida imediatamente. Caso contrário, você deve chamar sua função de membro de [janela](../mfc/reference/cwnd-class.md#showwindow) .

## <a name="see-also"></a>Consulte também

[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
