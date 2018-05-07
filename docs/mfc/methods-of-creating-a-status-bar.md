---
title: Métodos de criação de uma barra de Status | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CStatusBar class [MFC], vs. CStatusBarCtrl
- methods [MFC], creating status bars
- CStatusBarCtrl class [MFC], vs. CStatusBar
- CStatusBarCtrl class [MFC], creating
- methods [MFC]
- status bars [MFC], creating
ms.assetid: 9aeaf290-7099-4762-a5ba-9c26705333c9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b0428bfc906ba6e8a1ecc7bd7c198327e8c31505
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="methods-of-creating-a-status-bar"></a>Métodos de criação de uma barra de status
MFC fornece classes para criar barras de status: [CStatusBar](../mfc/reference/cstatusbar-class.md) e [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) (que encapsula a API de controle comum do Windows). `CStatusBar` fornece todas as funcionalidades da barra de controle comum de status, ele automaticamente interage com menus e barras de ferramentas e trata muitas das configurações de controle comuns necessárias e estruturas. No entanto, o executável resultante geralmente será maior do que é criado usando `CStatusBarCtrl`.  
  
 `CStatusBarCtrl` geralmente resulta em um executável menor e você pode optar por usar `CStatusBarCtrl` se você não pretende integrar a barra de status na arquitetura do MFC. Se você planeja usar `CStatusBarCtrl` e integrar a barra de status na arquitetura do MFC, você deve tomar cuidado adicional para comunicar o status barra manipulações de controle para MFC. Essa comunicação não é difícil; No entanto, é trabalho adicional é desnecessário quando você usar `CStatusBar`.  
  
 Visual C++ fornece duas maneiras de aproveitar o controle de barra de status comuns.  
  
-   Criar o status barra usando `CStatusBar`e, em seguida, chame [CStatusBar::GetStatusBarCtrl](../mfc/reference/cstatusbar-class.md#getstatusbarctrl) para obter acesso ao `CStatusBarCtrl` funções de membro.  
  
-   Criar o status barra usando [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)do construtor.  
  
 O método lhe dará acesso a funções de membro de controle da barra de status. Quando você chama `CStatusBar::GetStatusBarCtrl`, ele retorna uma referência a um `CStatusBarCtrl` , você pode usar um conjunto de funções de membro de objeto. Consulte [CStatusBar](../mfc/reference/cstatusbar-class.md) para obter informações sobre como construir e criando um status barra usando `CStatusBar`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

