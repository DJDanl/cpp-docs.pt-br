---
title: "Escolhendo um plano de fundo transparente ou opaco (editor de imagens para &#237;cones) | Microsoft Docs"
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
helpviewer_keywords: 
  - "cores de plano de fundo, imagens"
  - "imagens de plano de fundo"
  - "cores [C++], imagem"
  - "Editor de imagem [C++], planos de fundo transparentes ou opacos"
  - "imagens [C++], plano de fundo opaco"
  - "imagens [C++], transparência"
  - "planos de fundo opacos"
  - "transparência, plano de fundo"
  - "planos de fundo transparentes"
  - "planos de fundo transparentes, imagens"
ms.assetid: 61b743d9-c86b-405d-9a81-0806431b4363
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Escolhendo um plano de fundo transparente ou opaco (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você mover ou copia uma seleção a partir de uma imagem, os pixels na seleção que correspondem a cor de plano de fundo atual são, por padrão, transparente; eles não oculte os pixels no local de destino.  
  
 Você pode alternar de um plano de fundo transparente \(padrão\) para um fundo opaco e vice\-versa.  Quando você usa uma ferramenta de seleção, o  **Plano de fundo transparente** e  **Plano de fundo opaco** opções aparecerão no seletor de opção à  **Editor de imagens** barra de ferramentas \(como visto abaixo\).  
  
 ![Opções de opacas ou transparentes](../Image/vcImageEditorOpaqTranspBack.gif "vcImageEditorOpaqTranspBack")  
Opções transparentes e opacas na barra de ferramentas do Editor de imagens  
  
### Para alternar entre um plano de fundo transparente e opaco  
  
1.  No  **Editor de imagens** barra de ferramentas, clique no  **opção** seletor e então clique em plano de fundo apropriado:  
  
    -   **Plano de fundo opaco \(O\)**: imagem existente está obscurecida por todas as partes da seleção.  
  
    -   **Plano de fundo transparente \(T\)**: imagem existente mostra através de partes da seleção que correspondem a cor de plano de fundo atual.  
  
 \- ou \-  
  
-   Sobre o  **imagem** menu, marque ou desmarque  **Desenho opaco**.  
  
 Você pode alterar a cor de plano de fundo enquanto uma seleção já estiver em vigor para alterar quais partes da imagem são transparentes.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Trabalhando com cor](../mfc/working-with-color-image-editor-for-icons.md)