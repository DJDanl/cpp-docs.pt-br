---
title: "Configura&#231;&#245;es para o controle da barra de ferramentas | Microsoft Docs"
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
  - "Classe CToolBarCtrl, configurações"
  - "controles de barra de ferramentas [MFC], sobre controles de barra de ferramentas"
ms.assetid: 025ba920-b3ee-4d82-9367-e652cd7875b9
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es para o controle da barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os botões em uma barra de ferramentas do podem exibir um bitmap, uma cadeia de caracteres, ou ambos.  Por padrão, o tamanho da imagem é definido nas dimensões de 16 por 15 pixels.  Todos os botões têm a mesma largura, por padrão 24 por 22 pixels.  A altura de uma barra de ferramentas é determinada pela altura dos botões, e a largura de uma barra de ferramentas é a mesma que a largura da área da janela pai do cliente, também por padrão.  
  
 Uma barra de ferramentas pode ter os recursos internos de personalização do, incluindo uma caixa de diálogo definida pelo sistema de personalização, o que permite ao usuário inserir, excluir, ou reorganizar os botões da barra de ferramentas.  Um aplicativo determina se os recursos de personalização estão disponíveis para o usuário e controla a extensão até a qual o usuário pode personalizar a barra de ferramentas.  Para obter mais informações sobre como personalizar a barra de ferramentas, consulte a classe [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)*na referência de MFC*.  
  
## Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)