---
title: Classes (ATL) de suporte do Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.atl.windows
dev_langs:
- C++
helpviewer_keywords:
- ATL, windows
- windows [C++], ATL
ms.assetid: 750b14d5-d787-4d2b-9728-ac199ccad489
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 40521ce5b7ec192781e1496590fdd42b36e132e1
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37848383"
---
# <a name="windows-support-classes"></a>Classes de suporte do Windows
As classes a seguir fornecem suporte para windows:  
  
-   [U_menuorid](../atl/reference/u-menuorid-class.md) fornece wrappers `CreateWindow` e `CreateWindowEx`.  
  
-   [CWindow](../atl/reference/cwindow-class.md) contém métodos para manipular uma janela. `CWindow` é a classe base para `CWindowImpl`, `CDialogImpl`, e `CContainedWindow`.  
  
-   [CWindowImpl](../atl/reference/cwindowimpl-class.md) implementa uma janela com base em uma nova classe de janela. Também permite a superclasse ou de subclasse de janela.  
  
-   [CDialogImpl](../atl/reference/cdialogimpl-class.md) implementa uma caixa de diálogo.  
  
-   [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) implementa uma caixa de diálogo (modal ou sem-modo) que hospeda controles ActiveX.  
  
-   [CSimpleDialog](../atl/reference/csimpledialog-class.md) implementa uma caixa de diálogo (modal ou sem janela restrita) com a funcionalidade básica.  
  
-   [CAxWindow](../atl/reference/caxwindow-class.md) manipula uma janela que hospeda um controle ActiveX.  
  
-   [CAxWindow2T](../atl/reference/caxwindow2t-class.md) fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedagem de controles do ActiveX licenciados.  
  
-   [CContainedWindowT](../atl/reference/ccontainedwindowt-class.md) implementa uma janela contida dentro de outro objeto.  
  
-   [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) gerencia as informações de uma nova classe de janela.  
  
-   [CDynamicChain](../atl/reference/cdynamicchain-class.md) dá suporte a encadeamento dinâmico de mapas de mensagem.  
  
-   [CMessageMap](../atl/reference/cmessagemap-class.md) permite que um objeto exponha sua mensagem é mapeado para outros objetos.  
  
-   [CWinTraits](../atl/reference/cwintraits-class.md) fornece um método simples de padronização as características de um objeto de janela ATL.  
  
-   [CWinTraitsOR](../atl/reference/cwintraitsor-class.md) fornece valores padrão para estilos de janela e estilos estendidos usados para criar uma janela. Esses valores são adicionados, usando o operador OR lógico, para valores fornecidos durante a criação de uma janela.  
  
## <a name="related-articles"></a>Artigos relacionados  
 [Classes de janela da ATL](../atl/atl-window-classes.md)  
  
 [Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../atl/atl-class-overview.md)   
 [Macros de Mapa de Mensagens](../atl/reference/message-map-macros-atl.md)   
 [Macros de classe de janela](../atl/reference/window-class-macros.md)

