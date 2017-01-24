---
title: "Um aplicativo multithread pode acessar uma DLL MFC em threads diferentes? | Microsoft Docs"
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
ms.assetid: e3452e62-021e-4d23-9cce-cff41eb8b46b
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Um aplicativo multithread pode acessar uma DLL MFC em threads diferentes?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os aplicativos multi\-threaded podem acessar as dlls regulares que vinculam dinamicamente ao MFC e a DLL de extensão de threads diferentes.  E a partir da versão 4,2 do Visual C\+\+, um aplicativo pode acessar as dlls regulares que vinculam estaticamente ao MFC de vários threads criados no aplicativo.  
  
 Antes do versão 4,2, apenas um thread externo pode anexar a uma DLL normal que vinculasse estaticamente MFC ao.  Para obter mais informações sobre as limitações que acessam as dlls regulares que vinculam estaticamente ao MFC de vários threads \(a versão 4,2 do Visual C\+\+\), consulte o artigo da Base de Dados de Conhecimento, os “vários threads e os \_USRDLLs MFC” \(Q122676\).  
  
 Observe que o termo está USRDLL mais utilizado na documentação do Visual C\+\+.  Uma DLL normal que é vinculado ao estaticamente MFC tem as mesmas características do USRDLL antigo.  
  
## Consulte também  
 [Perguntas frequentes sobre DLL](../build/dll-frequently-asked-questions.md)