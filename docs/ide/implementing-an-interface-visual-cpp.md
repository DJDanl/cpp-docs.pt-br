---
title: "Implementando uma interface (Visual C++) | Microsoft Docs"
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
  - "interfaces, implementando"
ms.assetid: 72f8731b-7e36-45db-8b10-7ef211a773cd
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando uma interface (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para implementar uma interface, você deve ter criado um projeto como um aplicativo COM ATL ou como um aplicativo MFC que contém suporte ATL.  Você pode usar o  [ATL Project Wizard](../Topic/ATL%20Project%20Wizard.md) para criar um aplicativo ATL, ou  [Adicionar um objeto ATL para seu aplicativo MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo MFC.  
  
 Depois de criar o projeto, para implementar uma interface, você deve adicionar um objeto ATL.  Consulte  [adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionar objetos ao seu projeto ATL.  
  
> [!NOTE]
>  O assistente não oferece suporte a caixas de diálogo do ATL, XML Web services usando ATL, objetos de desempenho ou contadores de desempenho.  
  
 Se você  [Adicionar um controle ATL](../atl/reference/adding-an-atl-control.md), você pode especificar se deseja implementar interfaces padrão, listados na  [Interfaces](../atl/reference/interfaces-atl-control-wizard.md) página de nesse assistente e definido em atlcom.h.  
  
 Depois de adicionar o objeto ou controle, você pode implementar outras interfaces, localizados em qualquer biblioteca de tipos disponíveis, usando o Assistente para implementar a Interface.  
  
 Se você estiver adicionando uma nova interface, você deve adicioná\-lo manualmente para o arquivo do projeto. idl.  Consulte  [Adicionando uma nova Interface em um projeto do ATL](../Topic/Adding%20a%20New%20Interface%20in%20an%20ATL%20Project.md) para obter mais informações.  
  
### Para implementar uma interface  
  
1.  No modo de exibição de classe, com o botão direito no nome da classe para seu objeto ATL.  
  
2.  Clique em  **Add** partir no menu de atalho e, em seguida, clique  **Implementar Interface** para exibir o  [O Assistente de Interface de implementar](../Topic/Implement%20Interface%20Wizard.md).  
  
3.  Selecione as interfaces para implementar das bibliotecas do tipo apropriado e clique em  **Concluir**.  
  
4.  No modo de exibição de classe, expanda Bases do objeto e nó de interfaces para ver a interface que você tenha implementado e, em seguida, expanda o nó da interface para ver suas propriedades disponíveis, métodos e eventos.  
  
    > [!NOTE]
    >  Você também pode usar o  [Pesquisador de objetos](http://msdn.microsoft.com/pt-br/f89acfc5-1152-413d-9f56-3dc16e3f0470) para examinar os membros da interface.  
  
## Consulte também  
 [Criando uma interface COM](../ide/creating-a-com-interface-visual-cpp.md)   
 [Editando uma interface COM](../ide/editing-a-com-interface.md)