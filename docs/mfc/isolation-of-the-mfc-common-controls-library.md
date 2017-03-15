---
title: "Isolamento da biblioteca de controles comuns MFC | Microsoft Docs"
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
  - "MFC, Biblioteca Controles Comuns"
ms.assetid: 7471e6f0-49b0-47f7-86e7-8d6bc3541694
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Isolamento da biblioteca de controles comuns MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de controles comum é isolada agora em MFC, permitindo que os módulos diferentes \(como DLL do usuário\) usem versões diferentes da biblioteca de controles comuns especificando a versão em seus manifestos.  
  
 Um aplicativo MFC \(ou o código de usuário chamado por MFC\) fazem chamadas às APIs da biblioteca de controles comuns com as funções de invólucro nomeadas `Afx`*FunctionName*, onde *FunctionName* é o nome de controles comuns API.  As funções de invólucro são definidas em afxcomctl32.h e em afxcomctl32.inl.  
  
 Você pode usar macros de [AFX\_COMCTL32\_IF\_EXISTS](../Topic/AFX_COMCTL32_IF_EXISTS.md) e de [AFX\_COMCTL32\_IF\_EXISTS2](../Topic/AFX_COMCTL32_IF_EXISTS2.md) \(definidas em afxcomctl32.h\) para determinar se a biblioteca de controles comuns determinado implementa API em vez de chamar [GetProcAddress](../build/getprocaddress.md).  
  
 Tecnicamente, você faz chamadas às APIs por uma classe de invólucro, `CComCtlWrapper` da biblioteca de controles comum \(definido em afxcomctl32.h\).  `CComCtlWrapper` também é responsável para carregamento e descarregamento do comctl32.dll.  O estado do módulo MFC contém um ponteiro para uma instância de `CComCtlWrapper`.  Você pode acessar a classe de invólucro que usa a macro de `afxComCtlWrapper` .  
  
 Observe que chame a API \(controla diretamente \(não usar o wrapper MFC funções\) de um aplicativo de MFC ou de uma DLL do usuário funcionará na maioria dos casos, pois o aplicativo MFC ou a DLL do usuário são associados à biblioteca de controles comuns no manifesto solicitado\).  Porém, o código próprio MFC tem que usar os wrappers, porque o código de MFC pode ser chamado de DLL do usuário com versões diferentes da biblioteca de controles comuns.