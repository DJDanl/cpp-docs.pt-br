---
title: "Como adicionar suporte ao gerenciador de reinicializa&#231;&#227;o | Microsoft Docs"
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
  - "Gerenciador de Reinicialização"
  - "C++, suporte a falha de aplicativo"
ms.assetid: 7f3f5867-d4bc-4ba8-b3c9-dc1e7be93642
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como adicionar suporte ao gerenciador de reinicializa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Gerenciador de reinicialização é um recurso adicionado ao [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] para [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)]. O Gerenciador de reinicialização adiciona suporte para o seu aplicativo se ele fecha inesperadamente ou reinicia. O comportamento do Gerenciador de reinicialização depende do tipo do seu aplicativo. Se seu aplicativo for um editor de documento, seu aplicativo para salvar automaticamente o estado habilitado para o Gerenciador de reinicialização e conteúdo de qualquer abrir documentos e reinicia seu aplicativo após um encerramento inesperado. Se seu aplicativo não é um editor de documento, o Gerenciador de reinicialização irá reiniciar o aplicativo, mas ele não é possível salvar o estado do aplicativo por padrão.  
  
 Após a reinicialização, o aplicativo exibe uma caixa de diálogo de tarefa, se o aplicativo é Unicode. Se for um aplicativo ANSI, o aplicativo exibe uma caixa de mensagem do Windows. Neste ponto, o usuário escolhe se deseja restaurar os documentos salvos automaticamente. Se o usuário não restaura os documentos salvos automaticamente, o Gerenciador de reinicialização descartará os arquivos temporários.  
  
> [!NOTE]
>  Você pode substituir o comportamento padrão do Gerenciador de reinicialização para salvar dados e reiniciar o aplicativo.  
  
 Por padrão, os aplicativos MFC criado usando o Assistente de projeto em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] suporta o Gerenciador de reinicialização quando os aplicativos são executados em um computador que tenha [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)]. Se você não quiser que seu aplicativo para suportar o Gerenciador de reinicialização, você pode desabilitar o Gerenciador de reinicialização no Assistente de novo projeto.  
  
### Para adicionar suporte para o Gerenciador de reinicialização para um aplicativo existente  
  
1.  Abra um aplicativo MFC existente em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
2.  Abra o arquivo de origem para o seu aplicativo principal. Por padrão, esse é o arquivo. cpp que tem o mesmo nome de seu aplicativo. Por exemplo, o arquivo de origem do aplicativo principal para MyProject é MyProject.cpp.  
  
3.  Encontre o construtor para o aplicativo principal. Por exemplo, se seu projeto for MyProject, o construtor é `CMyProjectApp::CMyProjectApp()`.  
  
4.  Adicione a seguinte linha de código para o construtor.  
  
    ```  
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;  
    ```  
  
5.  Verifique se o `InitInstance` método do seu aplicativo chama seu pai `InitInstance` método: [CWinApp::InitInstance](../Topic/CWinApp::InitInstance.md) ou `CWinAppEx::InitInstance`. O `InitInstance` método é responsável por verificar a `m_dwRestartManagerSupportFlags` parâmetro.  
  
6.  Compile e execute seu aplicativo.  
  
## Consulte também  
 [Classe de CDataRecoveryHandler](../mfc/reference/cdatarecoveryhandler-class.md)   
 [CWinApp::m\_dwRestartManagerSupportFlags](../Topic/CWinApp::m_dwRestartManagerSupportFlags.md)   
 [Classe de CWinApp](../mfc/reference/cwinapp-class.md)   
 [CWinApp::m\_nAutosaveInterval](../Topic/CWinApp::m_nAutosaveInterval.md)   
 [CDocument::OnDocumentEvent](../Topic/CDocument::OnDocumentEvent.md)