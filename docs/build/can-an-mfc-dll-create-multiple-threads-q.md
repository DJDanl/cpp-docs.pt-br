---
title: "Uma DLL MFC pode criar v&#225;rios threads? | Microsoft Docs"
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
  - "DLLs [C++], multithreading"
  - "DLLs MFC [C++], multithreading"
  - "multithreading [C++], DLLs"
  - "threading [MFC], DLLs"
ms.assetid: 41d5b5e6-a7d3-42bf-b641-f1245abd1c59
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Uma DLL MFC pode criar v&#225;rios threads?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Exceto durante a inicialização, uma DLL MFC pode seguramente criar vários threads como usar as funções de \(TLS\) local de armazenamento de thread Win32 como **TlsAlloc** para atribuir o armazenamento de thread local.  No entanto, se uma DLL MFC usa **\_\_declspec\(thread\)** para atribuir o armazenamento de thread local, o aplicativo cliente deve ser implicitamente vinculado à DLL.  Se o aplicativo cliente vincula explicitamente a DLL, a chamada para **LoadLibrary** não carregará com êxito a DLL.  Para obter mais informações sobre como criar vários threads dentro da DLL MFC, consulte o artigo da Base de Dados de Conhecimento, “PRB: LoadLibrary\(\) chamada para carregar uma DLL que tem o TLS estático” \(Q118816\).  
  
 Uma DLL MFC que cria um novo thread de MFC durante a inicialização parará de responder quando é carregado por um aplicativo.  Isso inclui sempre que um thread é criado chamando `AfxBeginThread` ou o interior de `CWinThread::CreateThread` :  
  
-   `InitInstance` de `CWinApp`\- objeto derivada em uma DLL normal.  
  
-   `DllMain` ou uma função de **RawDllMain** fornecida em uma DLL normal.  
  
-   `DllMain` ou uma função de **RawDllMain** fornecida em uma DLL da extensão.  
  
 Para obter mais informações sobre como criar threads durante a inicialização, consulte o artigo da Base de Dados de Conhecimento, “PRB: Não é possível criar um thread de MFC durante a inicialização da DLL” \(Q142243\).  
  
## Consulte também  
 [Perguntas frequentes sobre DLL](../build/dll-frequently-asked-questions.md)