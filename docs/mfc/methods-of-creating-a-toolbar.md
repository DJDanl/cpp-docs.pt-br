---
title: "Métodos de criação de uma barra de ferramentas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CToolBarCtrl class [MFC], and CToolBar class [MFC]
- CToolBar class [MFC], creating toolbars
- MFC toolbars
- toolbar controls [MFC]
- toolbar controls [MFC], creating
- CToolBarCtrl class [MFC], creating toolbars
ms.assetid: f19d8d65-d49f-445c-abe8-d47d3e4101c8
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6d93f8e43c933e9c8054e798c11754cc48bf54a5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="methods-of-creating-a-toolbar"></a>Métodos de criação de uma barra de ferramentas
MFC fornece classes para criar barras de ferramentas: [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) (que encapsula a API de controle comum do Windows). `CToolBar`fornece todas as funcionalidades do controle da barra de ferramentas comuns, e trata muitas das configurações de controle comuns necessárias e estruturas. No entanto, o executável resultante geralmente será maior do que é criado usando `CToolBarCtrl`.  
  
 `CToolBarCtrl`geralmente resulta em um executável menor e você pode optar por usar `CToolBarCtrl` se você não pretende integrar a barra de ferramentas na arquitetura do MFC. Se você planeja usar `CToolBarCtrl` e integrar a barra de ferramentas na arquitetura do MFC, você deve tomar cuidado adicional para se comunicar manipulações de controle de barra de ferramentas para MFC. Essa comunicação não é difícil; No entanto, é trabalho adicional é desnecessário quando você usar `CToolBar`.  
  
 Visual C++ fornece duas maneiras de tirar proveito do controle da barra de ferramentas comuns.  
  
-   Criar a barra de ferramentas usando `CToolBar`e, em seguida, chame [CToolBar::GetToolBarCtrl](../mfc/reference/ctoolbar-class.md#gettoolbarctrl) para obter acesso ao `CToolBarCtrl` funções de membro.  
  
-   Criar a barra de ferramentas usando [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)do construtor.  
  
 O método lhe dará acesso a funções de membro do controle de barra de ferramentas. Quando você chama `CToolBar::GetToolBarCtrl`, ele retorna uma referência a um `CToolBarCtrl` , você pode usar um conjunto de funções de membro de objeto. Consulte [CToolBar](../mfc/reference/ctoolbar-class.md) para obter informações sobre como construir e criação de uma barra de ferramentas usando `CToolBar`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

