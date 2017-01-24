---
title: "Como criar um recurso | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "barras de ferramentas [C++], recursos"
  - "barras de ferramentas de recursos"
  - "recursos [Visual Studio], criando"
ms.assetid: aad44914-9145-45a3-a7d8-9de89b366716
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar um recurso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Não há suporte para o modo de exibição de recursos em edições Express.  
  
### Para criar um novo recurso no modo de exibição de recurso  
  
1.  Com foco em seu arquivo. rc [exibição recursos](../windows/resource-view-window.md), clique o **Editar** menu e escolha **Add Resource** \(ou com o botão direito no arquivo. rc no modo de exibição de recurso e escolha **Add Resource** no menu de atalho\).  
  
     **Observação** se seu projeto ainda não contém um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No [caixa de diálogo Adicionar recurso](../Topic/Add%20Resource%20Dialog%20Box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### Para criar um novo recurso no Gerenciador de soluções  
  
1.  Em **Solution Explorer**, clique na pasta do projeto e escolha **Add**, em seguida, clique em **Add Resource** no menu de atalho.  
  
     Se você ainda não tiver um arquivo. rc no seu projeto, esta etapa criará um. Em seguida, você pode repetir esta etapa para adicionar tipos específicos de recursos para o novo arquivo. rc.  
  
2.  No [caixa de diálogo Adicionar recurso](../Topic/Add%20Resource%20Dialog%20Box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### Para criar um novo recurso no modo de exibição de classe  
  
1.  No [Class View](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique em sua classe e escolha **Add**, em seguida, clique em **Add Resource** no menu de atalho.  
  
2.  No [caixa de diálogo Adicionar recurso](../Topic/Add%20Resource%20Dialog%20Box.md), escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
### Para criar um novo recurso no menu projeto  
  
1.  Do **projeto** menu, escolha **Adicionar recurso**.  
  
 Quando você cria um novo recurso, o Visual C\+\+ atribui um nome exclusivo a ele, por exemplo, IDD\_Dialog1. Você pode personalizar essa ID de recurso, editando as propriedades do recurso no editor de recursos associado ou no [janela propriedades](../Topic/Properties%20Window.md).  
  
 Você pode criar um recurso como um novo recurso padrão \(um recurso que não esteja baseado em um modelo\) ou como um recurso em conformidade com um [modelo](../Topic/How%20to:%20Use%20Resource%20Templates.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.*  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)   
 [Caixa de diálogo Adicionar Recurso](../Topic/Add%20Resource%20Dialog%20Box.md)