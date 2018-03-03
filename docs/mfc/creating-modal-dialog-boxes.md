---
title: "Criando caixas de diálogo modais | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- modal dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- MFC dialog boxes [MFC], modal
ms.assetid: 26c7a68c-79f6-4862-a5a8-6024984644d2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 815db891514eb03169dac2ad29e50469d74dcfee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-modal-dialog-boxes"></a>Criando caixas de diálogo modais
Para criar uma caixa de diálogo modal, chamar um dos dois construtores públicos declarados em [CDialog](../mfc/reference/cdialog-class.md). Em seguida, chame o objeto de caixa de diálogo [DoModal](../mfc/reference/cdialog-class.md#domodal) função de membro para exibir a caixa de diálogo e gerenciar a interação com ele até que o usuário escolhe Okey ou em Cancelar. Este gerenciamento por `DoModal` faz com que a caixa de diálogo modal. Para caixas de diálogo modais `DoModal` carrega o recurso de caixa de diálogo.  
  
## <a name="see-also"></a>Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

