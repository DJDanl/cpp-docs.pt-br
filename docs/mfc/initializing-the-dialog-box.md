---
title: Inicializando a caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- initializing dialog boxes [MFC]
- OnInitDialog method [MFC]
- modal dialog boxes [MFC], initializing
- modeless dialog boxes [MFC], initializing
- MFC dialog boxes [MFC], initializing
ms.assetid: 968142f5-19f9-4b34-a1d4-8e6412d4379b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7918180a437687eded090b3d014e4affe38fe8f9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344705"
---
# <a name="initializing-the-dialog-box"></a>Inicializando a caixa de diálogo
Depois da caixa de diálogo caixa e todos os seus controles são criados, mas antes da caixa de diálogo caixa (de qualquer tipo) é exibida na tela, o objeto de caixa de diálogo [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) é chamada de função de membro. Para uma caixa de diálogo modal, isso ocorre durante o `DoModal` chamar. Para uma caixa de diálogo sem janela restrita `OnInitDialog` é chamado quando **criar** é chamado. Você normalmente substitui `OnInitDialog` para inicializar os controles da caixa de diálogo, como definir o texto inicial de uma caixa de edição. Você deve chamar o `OnInitDialog` a função de membro da classe base, `CDialog`, do seu `OnInitDialog` substituir.  
  
 Se você deseja definir a cor de plano de fundo da caixa de diálogo (e que todas as outras caixas de diálogo em seu aplicativo), consulte [definindo a cor de plano de fundo da caixa de diálogo](../mfc/setting-the-dialog-boxs-background-color.md).  
  
## <a name="see-also"></a>Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

