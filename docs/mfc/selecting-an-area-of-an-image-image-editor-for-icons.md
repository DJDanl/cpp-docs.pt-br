---
title: "Selecionando uma &#225;rea de uma imagem (editor de imagens para &#237;cones) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.image.editing"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "cursores [C++], selecionando áreas de"
  - "Editor de imagem [C++], seleção de imagem"
  - "Editor de imagem [C++], selecionando imagens"
  - "imagens [C++], selecionando"
ms.assetid: 8b6ce4ad-eba1-4ece-86ba-cea92c3edff2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Selecionando uma &#225;rea de uma imagem (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar ferramentas de seleção para definir uma área de uma imagem que você deseja recortar, copiar, limpar, redimensionar, inverter ou mover.  Com o  **Retângulo de seleção** ferramenta você pode definir e selecionar uma região retangular da imagem.  Com o  **Seleção Irregular** ferramenta você pode desenhar um contorno à mão livre da área que deseja selecionar o recorte, cópia ou outra operação.  
  
> [!NOTE]
>  Consulte o  **Retângulo de seleção** e  **Seleção Irregular** ferramentas mostrado na  [barra de ferramentas do Editor de imagens](../mfc/toolbar-image-editor-for-icons.md) ou exiba as dicas de ferramenta associadas a cada botão no  **Editor de imagens** barra de ferramentas.  
  
 Você também pode criar um pincel personalizado a partir de uma seleção.  Para obter mais informações, consulte  [criar um pincel personalizado](../Topic/Creating%20a%20Custom%20Brush%20\(Image%20Editor%20for%20Icons\).md).  
  
### Para selecionar uma área de uma imagem  
  
1.  No  **Editor de imagens** barra de ferramentas \(ou a partir do  **imagem** menu,  **Ferramentas** comando\), clique na ferramenta de seleção que você deseja.  
  
2.  Mova o ponto de inserção para um canto da área de imagem que você deseja selecionar.  Mira aparecer quando o ponto de inserção estiver sobre a imagem.  
  
3.  Arraste o ponto de inserção até o canto oposto da área que deseja selecionar.  Um retângulo mostra quais pixels serão selecionados.  Todos os pixels dentro do retângulo, incluindo aqueles sob o retângulo, estão incluídos na seleção.  
  
4.  Solte o botão do mouse.  A borda de seleção delimita a área selecionada.  
  
### Para selecionar uma imagem inteira  
  
1.  Clique na imagem fora da seleção atual.  A borda de seleção altera o foco e abrange a imagem inteira novamente.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Editando recursos gráficos](../mfc/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../mfc/image-editor-for-icons.md)