---
title: Criando caixas de diálogo sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
ms.assetid: 70d78c7f-3d40-477b-9f78-0f33c359f88b
ms.openlocfilehash: 71cca82e667ddbf5cfc4c2abb5880cd69c7fafae
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57266348"
---
# <a name="creating-modeless-dialog-boxes"></a>Criando caixas de diálogo sem janela restrita

Para uma caixa de diálogo sem janela restrita, você deve fornecer seu próprio construtor público em sua classe de caixa de diálogo. Para criar uma caixa de diálogo sem janela restrita, chame o construtor público e, em seguida, chamar o objeto de caixa de diálogo [criar](../mfc/reference/cdialog-class.md#create) função de membro para carregar o recurso de caixa de diálogo. Você pode chamar **criar** durante ou após a chamada do construtor. Se o recurso de caixa de diálogo tem a propriedade **WS_VISIBLE**, a caixa de diálogo será exibida imediatamente. Se não, você deve chamar seu [ShowWindow](../mfc/reference/cwnd-class.md#showwindow) função de membro.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
