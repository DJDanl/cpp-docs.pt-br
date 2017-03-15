---
title: "Criando novas barras de ferramentas | Microsoft Docs"
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
helpviewer_keywords: 
  - "Inserir Recurso"
  - "Editor da barra de ferramentas, criando novas barras de ferramentas"
  - "barras de ferramentas [C++], criando"
ms.assetid: 1b28264b-0718-4df8-9f65-979805d2efef
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando novas barras de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para criar uma nova barra de ferramentas  
  
1.  Em  **recurso** exibir, seu arquivo. rc com o botão direito e escolha  **Add Resource** no menu de atalho.  \(Se você tiver uma barra de ferramentas em seu arquivo. rc, você pode simplesmente direito a  **barra de ferramentas** pasta e selecione  **Inserir barra de ferramentas** no menu de atalho.\)  
  
     **Nota** se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No  **Add Resource** caixa de diálogo, selecione  **barra de ferramentas** na  **Tipo de recurso** lista, em seguida clique em  **New**.  
  
     Se um sinal de adição \(\+\) será exibido ao lado do  **barra de ferramentas** tipo de recurso, isso significa que os modelos de barra de ferramentas estão disponíveis.  Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em  **New**.  
  
     \- ou \-  
  
3.  [Converter um bitmap existente em uma barra de ferramentas](../mfc/converting-bitmaps-to-toolbars.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 MFC ou ATL  
  
## Consulte também  
 [Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)