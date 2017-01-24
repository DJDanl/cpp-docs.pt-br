---
title: "Usando uma lista de imagens com um controle rebar | Microsoft Docs"
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
  - "listas de imagens [C++], controles rebar"
  - "controles rebar, listas de imagens"
ms.assetid: 1a5836ac-019a-46aa-8741-b35c3376b839
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando uma lista de imagens com um controle rebar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada a faixa de rebar pode conter, entre outros coisas, uma imagem de uma lista de imagem associado.  O procedimento a seguir detalha as etapas necessárias para exibir uma imagem em uma faixa de rebar.  
  
### Para exibir imagens em uma faixa de rebar  
  
1.  Anexar uma lista de imagem em seu objeto de controle de rebar fazendo uma chamada a [SetImageList](../Topic/CReBarCtrl::SetImageList.md), passando um ponteiro para uma lista existente da imagem.  
  
2.  Modificar a estrutura de **REBARBANDINFO** para atribuir uma imagem para uma faixa de rebar:  
  
    -   Definir o membro de **fMask** a **RBBIM\_IMAGE**, usando o operador OR bit a bit para incluir conforme necessário sinalizadores extras.  
  
    -   Definir o membro de `iImage` ao índice da lista da imagem da imagem a ser exibida.  
  
3.  Inicializar todos os membros de dados restantes, como tamanho, o texto, e o identificador da janela filho contida, as informações necessárias.  
  
4.  Inserir a nova faixa \(com a imagem\) com uma chamada a [CReBarCtrl::InsertBand](../Topic/CReBarCtrl::InsertBand.md), passando a estrutura de **REBARBANDINFO** .  
  
 O exemplo a seguir supõe que um objeto existente na lista de imagem com duas imagens esteve anexado ao objeto de controle de rebar \(`m_wndReBar`\).  Uma nova faixa de rebar \(definida por `rbi`\), contendo a primeira imagem, é adicionada com uma chamada a `InsertBand`:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#28](../mfc/codesnippet/CPP/using-an-image-list-with-a-rebar-control_1.cpp)]  
  
## Consulte também  
 [Usando CReBarCtrl](../Topic/Using%20CReBarCtrl.md)   
 [Controles](../mfc/controls-mfc.md)