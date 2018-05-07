---
title: Usando um controle comum como uma janela filho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [MFC], using as child windows
- windows [MFC], common controls as
- child windows [MFC], common controls as
- common controls [MFC], child windows
- Windows common controls [MFC], child windows
ms.assetid: 608f7d47-7854-4fce-bde9-856c51e76753
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 50d21675d913211026a2077a0830b7d8ed1225c9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-a-common-control-as-a-child-window"></a>Usando um controle comum como uma janela filho
Qualquer um dos controles comuns do Windows pode ser usado como uma janela filho de qualquer outra janela. O procedimento a seguir descreve como criar um controle comum dinamicamente e, em seguida, trabalhar com ele.  
  
### <a name="to-use-a-common-control-as-a-child-window"></a>Para usar um controle comum como uma janela filho  
  
1.  Defina o controle na classe relacionado ou manipulador.  
  
2.  Use a substituição do controle do [CWnd::Create](../mfc/reference/cwnd-class.md#create) método para criar o controle do Windows.  
  
3.  Depois que o controle foi criado (como antecipada como o `OnCreate` manipulador se subclasse de controle), você pode manipular o controle usando suas funções de membro. Consulte as descrições dos controles individuais em [controles](../mfc/controls-mfc.md) para obter detalhes sobre métodos.  
  
4.  Quando tiver terminado com o controle, use [CWnd::DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow) para destruir o controle.  
  
## <a name="see-also"></a>Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)

