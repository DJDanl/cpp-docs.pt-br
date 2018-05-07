---
title: Destruindo o controle de lista | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- list controls [MFC], destroying
- CListCtrl class [MFC], destroying controls
ms.assetid: 513ec820-3a02-49d2-b073-a6a7a3fc91b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: edb26671ba775cfa7daf98d39c7eccc9fd4111bd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="destroying-the-list-control"></a>Destruindo o controle List
Se você inserir o [CListCtrl](../mfc/reference/clistctrl-class.md) de objeto como um membro de dados de uma classe de exibição ou a caixa de diálogo, ele é destruído quando seu proprietário é destruído. Se você usar um [CListView](../mfc/reference/clistview-class.md), o framework destrói o controle quando ele destrói o modo de exibição.  
  
 Se você organizar para alguns dos seus dados de lista a ser armazenado no aplicativo em vez do controle de lista, você precisará providenciar seu desalocação. Para obter mais informações, consulte [itens e máscara de retorno de chamada](http://msdn.microsoft.com/library/windows/desktop/bb774736) no SDK do Windows.  
  
 Além disso, você é responsável por desalocando quaisquer listas de imagens criado e associado ao objeto de controle de lista.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

