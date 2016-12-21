---
title: "Usando exibi&#231;&#245;es | Microsoft Docs"
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
  - "Classe CView, exibir arquitetura"
  - "desenho, dados"
  - "interagindo com usuários e função de classe de exibição"
  - "MFC, modos de exibição"
  - "pintando dados"
  - "renderizando dados"
  - "entrada do usuário, interpretando por meio de classe de exibição"
  - "classes de exibição, função na exibição de dados de aplicativo"
  - "classes de exibição, função no gerenciamento da interação do usuário"
  - "modos de exibição, usando"
ms.assetid: dc3de6ad-5c64-4317-8f10-8bdcc38cdbd5
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando exibi&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As responsabilidades de exibição são exibir graficamente os dados de documento para o usuário e aceitar e interpretar a entrada do usuário como operações no documento.  As tarefas em escrever sua classe de exibição são:  
  
-   Escreva a função de membro de [OnDraw](../Topic/CView::OnDraw.md) da sua classe da exibição, que renderiza os dados de documento.  
  
-   Conectar mensagens apropriadas e objetos de interface do usuário do windows como itens de menu às funções de membro retornadas a classe na exibição.  
  
-   Implementar esses manipuladores para interpretar a entrada do usuário.  
  
 Além disso, você pode precisar substituir outras funções de membro de `CView` em sua classe derivada da exibição.  Em particular, talvez você queira substituir [OnInitialUpdate](../Topic/CView::OnInitialUpdate.md) para executar a inicialização especial para que a exibição e [OnUpdate](../Topic/CView::OnUpdate.md) faça qualquer processamento especial necessário imediatamente antes que a exibição se redesenha.  Para documentos de várias páginas, você também deve substituir [OnPreparePrinting](../Topic/CView::OnPreparePrinting.md) para inicializar a caixa de diálogo imprimir com o número de páginas para imprimir e outras informações.  Para obter mais informações sobre como anular as funções de membro de `CView` , consulte a classe [CView](../Topic/CView%20Class.md)*na referência de MFC*.  
  
## Que você deseja saber mais?  
  
-   [Classes derivadas de exibição disponíveis em MFC](../mfc/derived-view-classes-available-in-mfc.md)  
  
-   [Desenhar em uma exibição](../mfc/drawing-in-a-view.md)  
  
-   [Interpretando a entrada do usuário através de uma exibição](../mfc/interpreting-user-input-through-a-view.md)  
  
-   [A função de exibição na impressão](../mfc/role-of-the-view-in-printing.md)  
  
-   [Exibições de rolagem e de escala secundária](../mfc/scrolling-and-scaling-views.md)  
  
-   [Inicializar e limpar a documentação e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)  
  
## Consulte também  
 [Arquitetura de documento\/exibição](../Topic/Document-View%20Architecture.md)   
 [Classe de CFormView](../mfc/reference/cformview-class.md)   
 [Exibição de registro \(Acesso a dados MFC\)](../data/record-views-mfc-data-access.md)   
 [Fazendo bypass do mecanismo de serialização](../mfc/bypassing-the-serialization-mechanism.md)