---
title: "Trabalhando com cor (editor de imagens para &#237;cones) | Microsoft Docs"
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
  - "vc.editors.image.color"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cores [C++]"
  - "cores [C++], imagem"
  - "Paleta de Cores, Editor de imagem"
  - "cores do primeiro plano, Editor de imagem"
  - "Editor de imagem [C++], Paleta de Cores"
  - "imagens [C++], cores de plano de fundo"
  - "paletas, cores do Editor de imagem"
ms.assetid: d34ff96f-241d-494f-abdd-13811ada8cd3
caps.latest.revision: 11
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Trabalhando com cor (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O editor de imagens contém muitos recursos que especificamente a manipulam e personalizar as cores.  Você pode definir uma cor de primeiro plano ou plano de fundo, preencher áreas limitadas com cor ou selecione uma cor em uma imagem para usar como a cor de primeiro plano ou plano de fundo atual.  Você pode usar ferramentas do  [barra de ferramentas do Editor de imagens](../mfc/toolbar-image-editor-for-icons.md) juntamente com a paleta de cores a  [janela de cores](../Topic/Colors%20Window%20\(Image%20Editor%20for%20Icons\).md) para criar imagens.  
  
 Todas as cores para imagens de 16 cores e monocromáticas são mostradas na paleta de cores na janela de cores.  Além de 16 cores padrão, você pode criar suas próprias cores personalizadas.  A alteração de qualquer uma das cores na paleta imediatamente alterará a cor correspondente na imagem.  
  
 Quando o trabalho com o ícone de 256 cores e o cursor imagens, a propriedade de cores na  [janela Propriedades do](../Topic/Properties%20Window.md) é usado.  Para obter mais informações, consulte  [criar um ícone de 256 cores ou cursor](../mfc/creating-a-256-color-icon-or-cursor-image-editor-for-icons.md).  
  
> [!NOTE]
>  Usando o Editor de imagem, você pode exibir imagens de 32 bits, mas não é possível editá\-los.  
  
 Images True\-color também podem ser criados.  No entanto, amostras de true color não aparecem na paleta completa na janela de cores. eles aparecem somente na área de indicador de cor primeiro ou segundo plano.  As True colors são criadas usando o  [caixa de diálogo Seletor de cores personalizado](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md).  Para obter mais informações, consulte  [Personalizando ou alterar as cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md).  
  
 Você pode salvar paletas de cores personalizada no disco e recarregá\-las conforme necessário.  A paleta de cores que você utilizou mais recentemente é salva no registro e carregada automaticamente na próxima vez que iniciar o Visual Studio.  
  
-   [A seleção do primeiro plano ou cores de plano de fundo](../windows/selecting-foreground-or-background-colors-image-editor-for-icons.md)  
  
-   [Uma área limitada de uma imagem com uma cor de preenchimento.](../windows/filling-a-bounded-area-of-an-image-with-a-color-image-editor-for-icons.md)  
  
-   [Pegar uma cor de uma imagem para uso em outro lugar](../Topic/Picking%20up%20a%20Color%20from%20an%20Image%20to%20Use%20Elsewhere%20\(Image%20Editor%20for%20Icons\).md)  
  
-   [Escolher um plano de fundo transparente ou opaco](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md)  
  
-   [Invertendo as cores em uma seleção](../windows/inverting-the-colors-in-a-selection-image-editor-for-icons.md)  
  
-   [Personalizar ou alterar as cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md)  
  
-   [Salvando e carregando paletas de cores diferente](../windows/saving-and-loading-different-color-palettes-image-editor-for-icons.md)  
  
-   [Janela de cores](../Topic/Colors%20Window%20\(Image%20Editor%20for%20Icons\).md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Nenhum  
  
## Consulte também  
 [Teclas de aceleração](../mfc/accelerator-keys-image-editor-for-icons.md)   
 [Recursos](_win32_Resources)