---
title: Criando caixas de diálogo sem janela restrita | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
ms.assetid: 70d78c7f-3d40-477b-9f78-0f33c359f88b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 77b80f66f2956e71b90e4d939a0fb74aef28edb1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407030"
---
# <a name="creating-modeless-dialog-boxes"></a>Criando caixas de diálogo sem janela restrita

Para uma caixa de diálogo sem janela restrita, você deve fornecer seu próprio construtor público em sua classe de caixa de diálogo. Para criar uma caixa de diálogo sem janela restrita, chame o construtor público e, em seguida, chamar o objeto de caixa de diálogo [criar](../mfc/reference/cdialog-class.md#create) função de membro para carregar o recurso de caixa de diálogo. Você pode chamar **criar** durante ou após a chamada do construtor. Se o recurso de caixa de diálogo tem a propriedade **WS_VISIBLE**, a caixa de diálogo será exibida imediatamente. Se não, você deve chamar seu [ShowWindow](../mfc/reference/cwnd-class.md#showwindow) função de membro.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

