---
title: "Relacionamentos entre objetos MFC | Microsoft Docs"
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
  - "relações de objetos MFC"
  - "MFC, relações entre objetos de chave"
  - "objetos [C++], relacionamentos"
  - "relacionamentos, Objetos MFC"
ms.assetid: 6e8f3b51-e80f-4d88-94c8-4c1e4ee163ad
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Relacionamentos entre objetos MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para ajudar colocar o processo de criação do documento\/exibição na perspectiva, consulte um programa em execução: um documento, a janela do quadro usada para conter a exibição, e a exibição associada ao documento.  
  
-   Um documento mantém uma lista das exibições desse documento e um ponteiro para o modelo de documento que criou o documento.  
  
-   Uma exibição mantém um ponteiro para o documento e é um filho da janela pai do quadro.  
  
-   Uma janela do quadro do documento mantém um ponteiro para a exibição ativa atual.  
  
-   Um modelo de documento mantém uma lista dos documentos abertos.  
  
-   O aplicativo mantém uma lista dos modelos do documento.  
  
-   As janelas controlam de todas as janelas abertas para que possa enviar\-lhes mensagens.  
  
 Essas relações são estabelecidas durante a criação do documento\/exibição.  A tabela a seguir mostra como os objetos em um programa em execução podem acessar outros objetos.  Qualquer objeto pode obter um ponteiro para o objeto do aplicativo chamando a função global [AfxGetApp](../Topic/AfxGetApp.md).  
  
### Obter acesso a outros objetos em seu aplicativo  
  
|Do objeto|Como acessar outros objetos|  
|---------------|---------------------------------|  
|Documento|Use [GetFirstViewPosition](../Topic/CDocument::GetFirstViewPosition.md) e [GetNextView](../Topic/CDocument::GetNextView.md) para acessar a lista de exibição do documento.<br /><br /> Chame [GetDocTemplate](../Topic/CDocument::GetDocTemplate.md) para obter o modelo de documento.|  
|View|Chame [GetDocument](../Topic/CView::GetDocument.md) para obter o documento.<br /><br /> Chame [GetParentFrame](../Topic/CWnd::GetParentFrame.md) para obter a janela do quadro.|  
|Janela do quadro do documento|Chame [GetActiveView](../Topic/CFrameWnd::GetActiveView.md) para obter a exibição atual.<br /><br /> Chame [GetActiveDocument](../Topic/CFrameWnd::GetActiveDocument.md) para obter o documento associado à exibição atual.|  
|Janela do quadro MDI|Chame [MDIGetActive](../Topic/CMDIFrameWnd::MDIGetActive.md) para obter [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md)atualmente ativo.|  
  
 Normalmente, uma janela do quadro tem uma exibição, mas às vezes, como no windows do divisor, a mesma janela do quadro contém várias exibições.  A janela do quadro mantém um ponteiro para a exibição atualmente ativo; o ponteiro é atualizado enquanto outra exibição é ativada.  
  
> [!NOTE]
>  Um ponteiro para a janela do quadro principal é armazenado na variável de membro de [m\_pMainWnd](../Topic/CWinThread::m_pMainWnd.md) do objeto do aplicativo.  Uma chamada para `OnFileNew` na substituição da função de membro de `InitInstance` de `CWinApp` define `m_pMainWnd` para você.  Se você não chama `OnFileNew`, você deve definir o valor da variável em `InitInstance` você mesmo. \(Os aplicativos do componente através de SDI \(servidor\) não podem definir a variável \/Embedding se estiver na linha de comando.\) Observe que `m_pMainWnd` agora é um membro da classe `CWinThread` em vez de `CWinApp`.  
  
## Consulte também  
 [Modelos de documento e o processo de criação de documento\/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)   
 [Criação do modelo de documento](../Topic/Document%20Template%20Creation.md)   
 [Criação de documento\/exibição](../mfc/document-view-creation.md)   
 [Criando novos documentos, janelas e exibições](../Topic/Creating%20New%20Documents,%20Windows,%20and%20Views.md)