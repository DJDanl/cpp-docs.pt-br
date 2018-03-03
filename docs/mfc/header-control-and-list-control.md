---
title: "Controle de cabeçalho e lista | Microsoft Docs"
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
- CListCtrl class [MFC], with CHeaderCtrl
- CListCtrl class [MFC], header controls
- CHeaderCtrl class [MFC], with CListCtrl
- controls [MFC], header
- header controls [MFC]
- header controls [MFC], list controls used with
ms.assetid: b20194b1-1a6b-4e2f-b890-1b3cca6650bc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 213d2eeec7628c54d68bbd8f636ae85d90e7e8de
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="header-control-and-list-control"></a>Controle de cabeçalho e de lista
Na maioria dos casos, você usará o controle de cabeçalho que é inserido em uma [CListCtrl](../mfc/reference/clistctrl-class.md) ou [CListView](../mfc/reference/clistview-class.md) objeto. No entanto, há casos em que um objeto de controle de cabeçalho separado é desejável, como a manipulação de dados, organizados em colunas ou linhas, em uma [CView](../mfc/reference/cview-class.md)-objeto derivado. Nesses casos, é necessário ter maior controle sobre a aparência e o comportamento padrão de um controle de cabeçalho incorporado.  
  
 No caso comum que você deseja que um controle de cabeçalho para fornecer padrão, comportamento padrão, você talvez queira usar [CListCtrl](../mfc/reference/clistctrl-class.md) ou [CListView](../mfc/reference/clistview-class.md) em vez disso. Use `CListCtrl` quando você desejar a funcionalidade de um controle de cabeçalho padrão, incorporado em um controle comum do modo de exibição de lista. Use [CListView](../mfc/reference/clistview-class.md) quando você desejar a funcionalidade de um controle de cabeçalho padrão, incorporado em um objeto de exibição.  
  
> [!NOTE]
>  Esses controles incluem um controle de cabeçalho interno somente se o controle de exibição de lista é criado usando o `LVS_REPORT` estilo.  
  
 Na maioria dos casos, a aparência do controle de cabeçalho inserido pode ser modificada alterando os estilos de controle de exibição de lista que contém. Além disso, informações sobre o controle de cabeçalho podem ser obtidas por meio de funções de membro do controle de exibição de lista pai. No entanto, para controle total e acesso para os atributos e estilos de controle de cabeçalho incorporado, é recomendável que um ponteiro para o objeto de controle de cabeçalho ser obtido.  
  
 O objeto de controle de cabeçalho inserido pode ser acessado do **CListCtrl** ou `CListView` com uma chamada para a classe do respectiva `GetHeaderCtrl` função de membro. O código a seguir demonstra isso:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#14](../mfc/codesnippet/cpp/header-control-and-list-control_1.cpp)]  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Usando listas de imagens com controles de cabeçalho](../mfc/using-image-lists-with-header-controls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

