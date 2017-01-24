---
title: "Criando um novo bot&#227;o da barra de ferramentas | Microsoft Docs"
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
  - "vc.editors.toolbar"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "botões de barra de ferramentas (no Editor de barra de ferramentas)"
  - "botões de barra de ferramentas (no Editor de barra de ferramentas), imagem de botão"
  - "botões de barra de ferramentas (no Editor de barra de ferramentas), criando"
  - "Editor da barra de ferramentas, criando botões"
ms.assetid: 46c120fe-4f2a-4887-a08f-bd1fea04b3f4
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um novo bot&#227;o da barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para criar um novo botão da barra de ferramentas  
  
1.  Em  [exibição de recurso](../windows/resource-view-window.md) expanda a pasta de recursos \(por exemplo, Project1.rc\).  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Expanda o  **barra de ferramentas** pasta e selecione uma barra de ferramentas para editar.  
  
3.  Atribua uma ID do botão em branco na extremidade direita da barra de ferramentas.  Você pode fazê\-lo editando o  **ID** propriedade no  [Janela Propriedades do](../Topic/Properties%20Window.md).  Por exemplo, você poderá dar a mesma ID de uma opção de menu de um botão da barra de ferramentas.  Nesse caso, use a caixa de listagem drop\-down para selecionar o  **ID** da opção de menu.  
  
     \- ou \-  
  
     Selecione o botão branco na extremidade direita da barra de ferramentas \(no painel de exibição da barra de ferramentas\) e começar a desenhar.  Uma ID de comando do botão padrão é atribuída \(ID\_BUTTON \<n\>\).  
  
 Você também pode copiar e colar uma imagem em uma barra de ferramentas como um novo botão.  
  
#### Para adicionar uma imagem a uma barra de ferramentas como um botão  
  
1.  Em  [Exibição de recurso](../windows/resource-view-window.md), abra a barra de ferramentas clicando duas vezes nele.  
  
2.  Em seguida, abra a imagem que você gostaria de adicionar à barra de ferramentas.  
  
    > [!NOTE]
    >  Se você abrir a imagem no Visual Studio, ele será aberto no editor de imagem.  Você também pode abrir a imagem em outros programas gráficos.  
  
3.  Do  **Editar** menu, escolha  **Copy**.  
  
4.  Alterne para sua barra de ferramentas clicando na respectiva guia na parte superior da janela de origem.  
  
5.  Do  **Editar** menu, escolha  **Colar**.  
  
     A imagem aparecerá na barra de ferramentas como um novo botão.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
### Requisitos  
 MFC ou ATL  
  
## Consulte também  
 [Propriedades do botão da barra de ferramentas](../mfc/toolbar-button-properties.md)   
 [Criando, movendo e editando botões da barra de ferramentas](../mfc/creating-moving-and-editing-toolbar-buttons.md)   
 [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)