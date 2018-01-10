---
title: "Criando caixas de diálogo sem janela restrita | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
ms.assetid: 70d78c7f-3d40-477b-9f78-0f33c359f88b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0549f898a076b140e7b5bed23c1c1e8c60d6adba
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-modeless-dialog-boxes"></a>Criando caixas de diálogo sem janela restrita
Para uma caixa de diálogo sem janela restrita, você deve fornecer seu próprio construtor público em sua classe de caixa de diálogo. Para criar uma caixa de diálogo sem janela restrita, o construtor público e, em seguida, chamar o objeto de caixa de diálogo [criar](../mfc/reference/cdialog-class.md#create) função de membro para carregar o recurso de caixa de diálogo. Você pode chamar **criar** durante ou após a chamada de construtor. Se o recurso de caixa de diálogo tem a propriedade **WS_VISIBLE**, a caixa de diálogo será exibida imediatamente. Se não, você deve chamar o [ShowWindow](../mfc/reference/cwnd-class.md#showwindow) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

