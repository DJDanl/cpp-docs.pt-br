---
title: Comunicação com um controle de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- tree controls [MFC], communicating with
- CTreeCtrl class [MFC], calling member functions
- communications, tree controls
- tree controls
ms.assetid: 680ad9ee-b11f-452d-93fa-501ca7d7e069
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: af0b248d5e32b535c23cc17b48efdd551dad7a2c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33341991"
---
# <a name="communicating-with-a-tree-control"></a>Comunicando-se com um controle de árvore
Usar métodos diferentes para chamar funções de membro uma [CTreeCtrl](../mfc/reference/ctreectrl-class.md) objeto dependendo de como o objeto foi criado:  
  
-   Se o controle de árvore está em uma caixa de diálogo, use uma variável de membro de tipo `CTreeCtrl` que você criar na classe de caixa de diálogo.  
  
-   Se o controle de árvore é uma janela filho, use o `CTreeCtrl` objeto (ou ponteiro) é usado para construir o objeto.  
  
-   Se você estiver usando um `CTreeView` de objeto, use a função [CTreeView::GetTreeCtrl](../mfc/reference/ctreeview-class.md#gettreectrl) para obter uma referência para o controle de árvore. Você pode inicializar outra referência com esse valor ou atribuir o endereço da referência a um `CTreeCtrl` ponteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

