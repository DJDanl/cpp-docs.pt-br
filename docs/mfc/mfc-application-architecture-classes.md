---
title: "Classes de arquitetura do aplicativo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.mfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de arquitetura de aplicativo"
  - "classes [C++], MFC"
  - "MFC [C++], desenvolvimento de aplicativo"
  - "MFC [C++], Classes "
ms.assetid: 71b2de54-b44d-407e-9c71-9baf954e18d9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de arquitetura do aplicativo MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes nesta categoria contribuem para a arquitetura de um aplicativo da estrutura.  Fornecem a funcionalidade comum da maioria dos aplicativos.  Você preenche a estrutura para adicionar funcionalidade de aplicativo específico.  Normalmente, você faz isso com novas classes das classes de arquitetura do, e adicionar novos membros ou substituindo as funções de membro existentes.  
  
 [Assistentes do aplicativo](../Topic/MFC%20Application%20Wizard.md) gerencia vários tipos de aplicativos, que usam a estrutura de aplicativo de modos diferentes de.  Os aplicativos de SDI \(interface de um único documento\) e \(interface de documentos múltiplos \(MDI\) faz uso completo de uma parte da estrutura chamada arquitetura do documento\/exibição.  Outros tipos de aplicativos, como aplicativos baseados diálogo\-, autenticação com base aplicativos, e as dlls, usam apenas alguns dos recursos da arquitetura do documento\/exibição.  
  
 Os aplicativos do documento\/exibição contêm um ou mais conjuntos de documentos, exibições, e do windows do quadro.  Um objeto de documento modelo associa as classes para cada conjunto de documento\/exibição\/quadro.  
  
 Embora não seja necessário usar a arquitetura do documento\/exibição em seu aplicativo MFC, há várias vantagens da fazer isso.  O suporte OLE do contêiner e de servidor MFC se baseia na arquitetura do documento\/exibição, como é suporte para imprimir e visualização de impressão.  
  
 Todos os aplicativos de MFC têm pelo menos dois objetos: um objeto do aplicativo derivado de [CWinApp](../mfc/reference/cwinapp-class.md), e alguma mídia objeto da janela principal, derivada \(normalmente indiretamente\) de [CWnd](../Topic/CWnd%20Class.md). \(O mais frequentemente, a janela principal é derivada de [CFrameWnd](../mfc/reference/cframewnd-class.md), de [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md), ou de [CDialog](../mfc/reference/cdialog-class.md), que são derivados de `CWnd`.\)  
  
 Os aplicativos que usam a arquitetura do documento\/exibição contêm objetos adicionais.  Os objetos principais são:  
  
-   Um objeto do aplicativo derivado da classe [CWinApp](../mfc/reference/cwinapp-class.md), como mencionado acima.  
  
-   Um ou mais objetos da classe do documento derivados da classe [CDocument](../Topic/CDocument%20Class.md).  Os objetos da classe do documento são responsáveis pela representação interna de dados coluna na exibição.  Podem ser associados a um arquivo de dados.  
  
-   Um ou mais objetos de exibição derivados da classe [CView](../Topic/CView%20Class.md).  Cada exibição é uma janela que é anexada a um documento e associadas com uma janela do quadro.  As exibições mostram e manipulam os dados contidos em um objeto da classe do documento.  
  
 Os aplicativos do documento\/exibição também contêm as janelas do quadro \(derivadas de [CFrameWnd](../mfc/reference/cframewnd-class.md)\) e os modelos de documento \(derivados de [CDocTemplate](../mfc/reference/cdoctemplate-class.md)\).  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)