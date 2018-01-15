---
title: "Windows dá suporte a Classes (ATL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.atl.windows
dev_langs: C++
helpviewer_keywords:
- ATL, windows
- windows [C++], ATL
ms.assetid: 750b14d5-d787-4d2b-9728-ac199ccad489
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 308f9deada47998c2f639d01ea5b9fdc9d04faa5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="windows-support-classes"></a>Classes de suporte do Windows
As classes a seguir fornecem suporte para windows:  
  
-   [_U_MENUorID](../atl/reference/u-menuorid-class.md) fornece wrappers para **CreateWindow** e **CreateWindowEx**.  
  
-   [CWindow](../atl/reference/cwindow-class.md) contém métodos para manipular uma janela. `CWindow`é a classe base para `CWindowImpl`, `CDialogImpl`, e `CContainedWindow`.  
  
-   [CWindowImpl](../atl/reference/cwindowimpl-class.md) implementa uma janela com base em uma nova classe de janela. Também permite a subclasse ou superclasse a janela.  
  
-   [CDialogImpl](../atl/reference/cdialogimpl-class.md) implementa uma caixa de diálogo.  
  
-   [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) implementa uma caixa de diálogo (modal ou sem janela restrita) que hospeda os controles ActiveX.  
  
-   [CSimpleDialog](../atl/reference/csimpledialog-class.md) implementa uma caixa de diálogo (modal ou sem janela restrita) com a funcionalidade básica.  
  
-   [CAxWindow](../atl/reference/caxwindow-class.md) manipula uma janela que hospeda um controle ActiveX.  
  
-   [CAxWindow2T](../atl/reference/caxwindow2t-class.md) fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedagem de controles ActiveX licenciados.  
  
-   [CContainedWindowT](../atl/reference/ccontainedwindowt-class.md) implementa uma janela contida dentro de outro objeto.  
  
-   [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) gerencia as informações de uma nova classe de janela.  
  
-   [CDynamicChain](../atl/reference/cdynamicchain-class.md) oferece suporte ao encadeamento dinâmico de mapas de mensagem.  
  
-   [CMessageMap](../atl/reference/cmessagemap-class.md) permite que um objeto expor sua mensagem mapeia a outros objetos.  
  
-   [CWinTraits](../atl/reference/cwintraits-class.md) fornece um método simple de padronização as características de um objeto de janela ATL.  
  
-   [CWinTraitsOR](../atl/reference/cwintraitsor-class.md) fornece valores padrão para os estilos de janela e estendidos usado para criar uma janela. Esses valores são adicionados, usando o operador OR lógico, para valores fornecidos durante a criação de uma janela.  
  
## <a name="related-articles"></a>Artigos relacionados  
 [Classes de janela da ATL](../atl/atl-window-classes.md)  
  
 [Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../atl/atl-class-overview.md)   
 [Macros de mapa de mensagem](../atl/reference/message-map-macros-atl.md)   
 [Macros de classe de janela](../atl/reference/window-class-macros.md)

