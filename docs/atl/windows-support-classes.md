---
title: "Classes de suporte do windows | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.atl.windows"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, o windows"
  - "windows [C++], ATL"
ms.assetid: 750b14d5-d787-4d2b-9728-ac199ccad489
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de suporte do windows
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes classes oferecem suporte a windows:  
  
-   Fornece[\_U\_MENUorID](../atl/reference/u-menuorid-class.md) wrappers para **CreateWindow** e **CreateWindowEx**.  
  
-   [CWindow](../atl/reference/cwindow-class.md) contém métodos para manipular uma janela.  `CWindow` é a classe base para `CWindowImpl`, `CDialogImpl`, e `CContainedWindow`.  
  
-   [CWindowImpl](../Topic/CWindowImpl%20Class.md) implementa uma janela com base em uma classe de nova janela.  Também permite que você subclasse para ou para superclass a janela.  
  
-   [CDialogImpl](../Topic/CDialogImpl%20Class.md) implementa uma caixa de diálogo.  
  
-   [CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md) implementa uma caixa de diálogo ou sem janela restrita \(modal\) que controles ActiveX de host.  
  
-   [CSimpleDialog](../atl/reference/csimpledialog-class.md) implementa uma caixa de diálogo ou sem janela restrita \(modal\) com funcionalidade básica.  
  
-   [CAxWindow](../atl/reference/caxwindow-class.md) manipula a janela que hospeda um controle ActiveX.  
  
-   [CAxWindow2T](../Topic/CAxWindow2T%20Class.md) fornece métodos para manipular uma janela que hospeda um controle ActiveX e também têm suporte para hospedar controles ActiveX licenciadas.  
  
-   [CContainedWindowT](../Topic/CContainedWindowT%20Class.md) implementa uma janela contida dentro de outro objeto.  
  
-   [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) gerencia informações de uma classe de nova janela.  
  
-   Encadeamento dinâmicos de suporte de[CDynamicChain](../atl/reference/cdynamicchain-class.md) de mapas de mensagem.  
  
-   [CMessageMap](../atl/reference/cmessagemap-class.md) permite que um objeto expõe seus mapeamentos de mensagem para outros objetos.  
  
-   [CWinTraits](../atl/reference/cwintraits-class.md) fornece um método simples de padronizar os traços de um objeto da janela de ATL.  
  
-   [CWinTraitsOR](../atl/reference/cwintraitsor-class.md) fornece valores padrão para os estilos de janela e os estilos estendidos usados para criar uma janela.  Esses valores são adicionados, usando o operador OR lógico, os valores fornecidos durante a criação de uma janela.  
  
## Artigos relacionados  
 [Classes da janela de ATL](../Topic/ATL%20Window%20Classes.md)  
  
 [Tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md)  
  
## Consulte também  
 [Visão geral de classe](../atl/atl-class-overview.md)   
 [Macros do mapa de mensagem](../atl/reference/message-map-macros-atl.md)   
 [Macros de classe de janela](../atl/reference/window-class-macros.md)