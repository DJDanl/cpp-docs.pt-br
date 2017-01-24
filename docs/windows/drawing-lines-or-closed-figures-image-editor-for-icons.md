---
title: "Desenhando linhas ou figuras fechadas (editor de imagens para &#237;cones) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "figuras fechadas, desenho"
  - "Editor de imagem [C++], desenhando linhas"
  - "linhas [C++], desenho"
  - "linhas [C++], pintura"
  - "formas, desenho"
ms.assetid: 7edd86db-77b1-451f-8001-bbfed9c6304f
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Desenhando linhas ou figuras fechadas (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As ferramentas do editor de Imagem para desenhar linhas e figuras fechadas, funcionam da mesma maneira: você coloca o ponto de inserção em um ponto e arrasta para outro.  Para linhas, esses pontos são os pontos de extremidade.  Para figuras fechadas, esses pontos são cantos opostos de um retângulo delimitadora a figura.  
  
 As linhas são desenhadas em uma largura de determinado pela seleção atual do pincel e figuras com quadros são desenhadas em uma largura de determinado pela seleção largura atual.  Linhas e todas as figuras, ambas enquadradas e preenchidas, são desenhados na cor do primeiro plano atual se você pressionar o botão esquerdo do mouse, ou na cor do plano de fundo atual se você pressionar o botão direito do mouse.  
  
### Para desenhar uma linha  
  
1.  No  [barra de ferramentas do Editor de imagens](../mfc/toolbar-image-editor-for-icons.md) \(ou a partir do  **imagem** menu,  **Ferramentas** comando\), clique no  **linha** ferramenta.  
  
2.  Se necessário, selecione um pincel e cores:  
  
    -   No  [a paleta de cores](../Topic/Colors%20Window%20\(Image%20Editor%20for%20Icons\).md), clique no botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.  
  
    -   No  [o seletor de opções](../mfc/toolbar-image-editor-for-icons.md), clique em uma forma que representa o pincel que deseja usar.  
  
3.  Coloque o ponteiro no ponto de partida da linha.  
  
4.  Arraste o ponto de extremidade da linha.  
  
### Para desenhar figuras fechadas  
  
1.  No  **Editor de imagens** barra de ferramentas \(ou o  **imagem** menu,  **Ferramentas** comando\), clique em um  **Fechado\-figura de desenho** ferramenta.  
  
     O  **O desenho de figura de Closed** ferramentas para criar figuras conforme indicado em seus respectivos botões.  
  
2.  Se necessário, selecione uma largura de linha e de cores.  
  
3.  Mova o ponteiro para um canto da área retangular na qual você deseja desenhar a figura.  
  
4.  Arraste o ponteiro para o canto diagonal oposto.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../mfc/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../mfc/image-editor-for-icons.md)   
 [Trabalhando com cor](../mfc/working-with-color-image-editor-for-icons.md)