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
ms.openlocfilehash: 01cdbc0f404c34a8c5ebc3ae09adf30e0cea0851
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215036"
---
# <a name="destroying-the-list-control"></a>Destruindo o controle List
Se você inserir seus [CListCtrl](../mfc/reference/clistctrl-class.md) do objeto como um membro de dados de uma classe de exibição ou a caixa de diálogo, ele é destruído quando seu proprietário é destruído. Se você usar um [CListView](../mfc/reference/clistview-class.md), o framework destrói o controle quando ele destrói o modo de exibição.  
  
 Se você organizar para alguns dos seus dados de lista a ser armazenado no aplicativo, em vez do controle de lista, você precisará fazer com que seu desalocação. Para obter mais informações, consulte [itens de retorno de chamada e a máscara de retorno de chamada](/windows/desktop/Controls/using-list-view-controls) no SDK do Windows.  
  
 Além disso, você é responsável por desalocando quaisquer listas de imagens criado e associado ao objeto de controle de lista.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

