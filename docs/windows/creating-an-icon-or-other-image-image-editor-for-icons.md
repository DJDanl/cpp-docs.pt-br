---
title: "Criando um &#237;cone ou outra imagem (editor de imagens para &#237;cones) | Microsoft Docs"
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
  - "vc.editors.bitmap"
dev_langs: 
  - "C++"
  - "C++"
helpviewer_keywords: 
  - "bitmaps [C++]"
  - "bitmaps [C++], criando"
  - "gráficos [C++], criando"
  - "Editor de imagem [C++], criando imagens"
  - "imagens [C++], criando"
  - "barras de ferramentas de recursos"
  - "recursos [Visual Studio], criando imagens"
ms.assetid: 66db3fb2-cfc1-48a2-9bdd-53f61eb7ee30
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um &#237;cone ou outra imagem (editor de imagens para &#237;cones)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar uma nova imagem \(bitmap, ícone, cursor ou barra de ferramentas\) e usar o editor de imagens para personalizar sua aparência.  Você também pode criar um novo bitmap em conformidade com um  [modelo](../Topic/How%20to:%20Use%20Resource%20Templates.md).  
  
### Para adicionar um novo recurso de imagem a um projeto de C\+\+ não gerenciado  
  
1.  Em  [Exibição de recurso](../windows/resource-view-window.md), seu arquivo. rc com o botão direito e escolha  **Inserir recursos** no menu de atalho.  \(Se você já tiver um recurso de imagem existente no seu arquivo. rc, como, por exemplo, um cursor, você pode simplesmente direito a  **Cursor** pasta e selecione  **Inserir o Cursor** no menu de atalho.\)  
  
    > [!NOTE]
    >  **Nota** se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No  [caixa de diálogo Inserir recurso](../Topic/Add%20Resource%20Dialog%20Box.md), selecione o tipo de recurso de imagem que você deseja criar \(**Bitmap**, por exemplo\), em seguida, clique em  **New**.  
  
     Se um sinal de adição \(**\+**\) é exibido ao lado do tipo de recurso de imagem na  **Inserir recursos** caixa de diálogo, significa que os modelos de barra de ferramentas estão disponíveis.  Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em  **New**.  
  
### Para adicionar um novo recurso de imagem a um projeto em um.NET favorita  
  
1.  Em  **Solution Explorer**, clique com o botão direito na pasta do projeto \(por exemplo,  **WindowsApplication1**\).  
  
2.  No menu de atalho, clique em  **Add**, em seguida, escolha  **Add New Item**.  
  
3.  No  **categorias** painel, expanda o  **Itens de projeto Local**  pasta, em seguida, escolha  **recursos**.  
  
4.  No  **modelos de** painel, escolha o tipo de recurso que você gostaria de adicionar ao seu projeto.  
  
     O recurso é adicionado ao seu projeto no Solution Explorer e o recurso abre no  [editor de imagens](../mfc/image-editor-for-icons.md).  Agora você pode usar todas as ferramentas disponíveis no editor de imagem para modificar sua imagem.  Para obter mais informações sobre como adicionar imagens a um projeto gerenciado, consulte  [carregar uma imagem no tempo de Design](../Topic/How%20to:%20Load%20a%20Picture%20Using%20the%20Designer%20\(Windows%20Forms\).md).  
  
    > [!NOTE]
    >  Quaisquer recursos gerenciados que você deseja editar devem ser recursos vinculados.  Os editores de recursos de Visual Studio não têm suporte para a edição de recursos incorporados.  Para obter mais informações, consulte  [Arquivos de recurso de criação de](../Topic/Creating%20Resource%20Files%20for%20Desktop%20Apps.md) na  *.Guia do desenvolvedor do NET Framework*.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Nenhum  
  
## Consulte também  
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../mfc/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)   
 [Convertendo bitmaps em barras de ferramentas](../mfc/converting-bitmaps-to-toolbars.md)   
 [Criando novas barras de ferramentas](../mfc/creating-new-toolbars.md)   
 [Editando recursos gráficos](../mfc/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../mfc/image-editor-for-icons.md)