---
title: "Fun&#231;&#227;o de membro InitInstance | Microsoft Docs"
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
  - "InitInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicativos [MFC], inicializando"
  - "inicializando aplicativos MFC"
  - "Método InitInstance"
  - "MFC [C++], inicializando"
ms.assetid: 4ef09267-ff7f-4c39-91a0-57454a264f83
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de membro InitInstance
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O sistema operacional Windows permite que você execute mais de uma cópia, ou “,” instância do mesmo aplicativo.  `WinMain` chama [InitInstance](../Topic/CWinApp::InitInstance.md) cada vez que uma nova instância do for iniciada do aplicativo.  
  
 A implementação de `InitInstance` do padrão criada pelo assistente de aplicativo MFC executa as seguintes tarefas:  
  
-   Como a ação central, cria modelos de documento que criam por sua vez, exibições, documentos e janelas do quadro.  Para obter uma descrição desse processo, consulte [Criação de modelo de documento](../Topic/Document%20Template%20Creation.md).  
  
-   Opções de arquivo padrão das cargas de um arquivo .ini ou do Registro do Windows, incluindo os nomes dos arquivos usados recentemente.  
  
-   Registra um ou mais modelos do documento.  
  
-   Para um aplicativo MDI, cria uma janela principal do quadro.  
  
-   Processa a linha de comando para abrir um documento especificado na linha de comando ou para abrir um novo documento, vazio.  
  
 Você pode adicionar seu próprio código de inicialização ou alterar o código escrito pelo assistente.  
  
> [!NOTE]
>  Os aplicativos MFC devem ser inicializados como apartment de thread único \(STA\).  Se você chamar [CoInitializeEx](http://msdn.microsoft.com/library/windows/desktop/ms695279) na substituição de `InitInstance` , especifique `COINIT_APARTMENTTHREADED` \(em vez de `COINIT_MULTITHREADED`\).  Para obter mais informações, consulte PRB: O aplicativo MFC para de responder quando você iniciar o aplicativo multi\-threaded STA. como um \(828643\) em [http:\/\/support.microsoft.com\/default.aspx?scid\=kb;en\-us;828643](http://support.microsoft.com/default.aspx?scid=kb;en-us;828643).  
  
## Consulte também  
 [CWinApp: a classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md)