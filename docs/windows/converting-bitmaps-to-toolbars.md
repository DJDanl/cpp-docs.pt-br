---
title: "Convertendo bitmaps em barras de ferramentas | Microsoft Docs"
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
  - "bitmaps [C++], convertendo em barras de ferramentas"
  - "Editor da barra de ferramentas, convertendo bitmaps"
  - "barras de ferramentas [C++], convertendo bitmaps"
ms.assetid: 971c181b-40f5-44be-843d-677a7c235667
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convertendo bitmaps em barras de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar uma nova barra de ferramentas, convertendo um bitmap.  O elemento gráfico de bitmap converte as imagens do botão para uma barra de ferramentas.  Geralmente, o bitmap contém várias imagens de botão em um único bitmap, com uma imagem para cada botão.  Imagens podem ser de qualquer tamanho. o padrão é 16 pixels de largura e a altura da imagem.  Você pode especificar o tamanho das imagens no botão a  [caixa de diálogo novo recurso da barra de ferramentas](../mfc/new-toolbar-resource-dialog-box.md) quando você escolher o Editor de barra de ferramentas do  **imagem** menu enquanto estiver no editor de imagens.  
  
### Converter bitmaps em uma barra de ferramentas.  
  
1.  Abrir um recurso de bitmap existente no  [editor de imagens](../mfc/image-editor-for-icons.md).  \(Se o bitmap não ainda estiver no seu arquivo. rc, clique com o botão direito no arquivo. rc, escolha  **importação** no menu de atalho, navegue até o bitmap que você deseja adicionar ao seu arquivo. rc e clique em  **Abrir**.\)  
  
2.  Do  **imagem** menu, escolha  **O Editor de barra de ferramentas**.  
  
     O  [caixa de diálogo novo recurso da barra de ferramentas](../mfc/new-toolbar-resource-dialog-box.md) é exibida.  Você pode alterar a largura e altura das imagens de ícone para coincidir com o bitmap.  A imagem da barra de ferramentas é exibida no editor de barra de ferramentas.  
  
3.  Para concluir a conversão, altere o comando  **ID** do botão usando o  [janela Propriedades do](../Topic/Properties%20Window.md).  Digite o novo  **ID** ou selecione um  **ID** na lista suspensa.  
  
    > [!TIP]
    >  A janela de propriedades contém um botão na barra de título de anotação.  Este botão ativa ou desativa ocultar automaticamente para a janela.  Para percorrer rapidamente todas as propriedades do botão de barra de ferramentas sem precisar reabrir as janelas de propriedade individual, desative Auto ocultar para que a janela de propriedades permanece imóvel.  
  
 Você também pode alterar as IDs de comando dos botões na barra de ferramentas novo usando o  [janela Propriedades do](../Topic/Properties%20Window.md).  Para obter informações sobre a nova barra de ferramentas de edição, consulte  [Criando, movimento e botões de barra de ferramentas de edição](../mfc/creating-moving-and-editing-toolbar-buttons.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 MFC ou ATL  
  
## Consulte também  
 [Criando novas barras de ferramentas](../mfc/creating-new-toolbars.md)   
 [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)