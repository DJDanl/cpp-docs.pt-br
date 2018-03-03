---
title: "Introdução às Classes de janela ATL | Microsoft Docs"
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
- window classes
ms.assetid: 503efc2c-a269-495d-97cf-3fb300d52f3d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 636fe8aa87b6880f5cda77fb46fc481d99d78a81
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="introduction-to-atl-window-classes"></a>Introdução às Classes de janela ATL
As seguintes classes ATL são projetadas para implementar e manipular windows:  
  
-   [CWindow](../atl/reference/cwindow-class.md) permite que você anexe um identificador de janela para o `CWindow` objeto. Em seguida, chamar `CWindow` métodos para manipular a janela.  
  
-   [CWindowImpl](../atl/reference/cwindowimpl-class.md) permite implementar uma nova janela e processar mensagens com um mapa de mensagem. Você pode criar uma janela com base em um novo Windows classe, superclasse uma classe existente ou subclasse de uma janela existente.  
  
-   [CDialogImpl](../atl/reference/cdialogimpl-class.md) permite que você implemente um modal ou uma caixa de diálogo sem janela restrita e processar mensagens um mapa de mensagem.  
  
-   [CContainedWindowT](../atl/reference/ccontainedwindowt-class.md) é uma classe predefinida que implementa uma janela cujo mapa da mensagem está contido em outra classe. Usando `CContainedWindowT` permite que você centralize o processamento de mensagem em uma classe.  
  
-   [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) permite que você implemente uma caixa de diálogo (modal ou sem janela restrita) que hospeda os controles ActiveX.  
  
-   [CSimpleDialog](../atl/reference/csimpledialog-class.md) permite que você implemente uma caixa de diálogo modal com a funcionalidade básica.  
  
-   [CAxWindow](../atl/reference/caxwindow-class.md) permite que você implemente uma janela que hospeda um controle ActiveX.  
  
-   [CAxWindow2T](../atl/reference/caxwindow2t-class.md) permite que você implemente uma janela que hospeda um controle ActiveX licenciado.  
  
 Além das classes de janela específico, ATL fornece várias classes projetados para facilitar a implementação de um objeto de janela ATL. Elas são as seguintes:  
  
-   [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) gerencia as informações de uma nova classe de janela.  
  
-   [CWinTraits](../atl/reference/cwintraits-class.md) e [CWinTraitsOR](../atl/reference/cwintraitsor-class.md) fornecem um método simple de padronização as características de um objeto de janela ATL.  
  
## <a name="see-also"></a>Consulte também  
 [Classes de janela](../atl/atl-window-classes.md)

