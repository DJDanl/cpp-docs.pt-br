---
title: Criando caixas de diálogo modais | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- modal dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- MFC dialog boxes [MFC], modal
ms.assetid: 26c7a68c-79f6-4862-a5a8-6024984644d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2a8bc947dbaf9cecc680f3cdbd8e6b429d2bcd5f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33342423"
---
# <a name="creating-modal-dialog-boxes"></a>Criando caixas de diálogo modais
Para criar uma caixa de diálogo modal, chamar um dos dois construtores públicos declarados em [CDialog](../mfc/reference/cdialog-class.md). Em seguida, chame o objeto de caixa de diálogo [DoModal](../mfc/reference/cdialog-class.md#domodal) função de membro para exibir a caixa de diálogo e gerenciar a interação com ele até que o usuário escolhe Okey ou em Cancelar. Este gerenciamento por `DoModal` faz com que a caixa de diálogo modal. Para caixas de diálogo modais `DoModal` carrega o recurso de caixa de diálogo.  
  
## <a name="see-also"></a>Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

