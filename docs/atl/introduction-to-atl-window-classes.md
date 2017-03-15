---
title: "Introdu&#231;&#227;o &#224;s classes da janela de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de janela"
ms.assetid: 503efc2c-a269-495d-97cf-3fb300d52f3d
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Introdu&#231;&#227;o &#224;s classes da janela de ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes classes de ATL são criadas para implementar e manipular janelas:  
  
-   [CWindow](../atl/reference/cwindow-class.md) permite que você anexe um identificador de janela para o objeto de `CWindow` .  Você então chama métodos de `CWindow` para manipular a janela.  
  
-   [CWindowImpl](../Topic/CWindowImpl%20Class.md) permite que você implemente mensagens de uma nova janela e do processo com um mapa de mensagem.  Você pode criar uma janela com base no windows classe, superclass uma classe existente, ou subclasse uma janela existente.  
  
-   [CDialogImpl](../Topic/CDialogImpl%20Class.md) permite que você implemente uma caixa de diálogo modal ou sem janela restrita e processar mensagens com um mapa de mensagem.  
  
-   [CContainedWindowT](../Topic/CContainedWindowT%20Class.md) é uma classe que implementa prebuilt de uma janela cujo mapa de mensagem está contido em outra classe.  Usar `CContainedWindowT` permite que você centralizar o processamento de mensagem em uma classe.  
  
-   [CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md) permite que você implemente uma caixa de diálogo ou sem janela restrita \(modal\) que controles ActiveX de host.  
  
-   [CSimpleDialog](../atl/reference/csimpledialog-class.md) permite que você implemente uma caixa de diálogo modal com funcionalidade básica.  
  
-   [CAxWindow](../atl/reference/caxwindow-class.md) permite que você implemente uma janela que hospeda um controle ActiveX.  
  
-   [CAxWindow2T](../Topic/CAxWindow2T%20Class.md) permite que você implemente uma janela que hospeda um controle ActiveX licenciado.  
  
 Além de classes específicas da janela, ATL fornece várias classes criadas para facilitar a implementação de um objeto da janela de ATL.  São:  
  
-   [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) gerencia informações de uma classe de nova janela.  
  
-   [CWinTraits](../atl/reference/cwintraits-class.md) e [CWinTraitsOR](../atl/reference/cwintraitsor-class.md) fornecem um método simples de padronizar os traços de um objeto da janela de ATL.  
  
## Consulte também  
 [Classes de janela](../Topic/ATL%20Window%20Classes.md)