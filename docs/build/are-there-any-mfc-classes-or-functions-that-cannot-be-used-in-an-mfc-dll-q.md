---
title: "Existe alguma classe ou fun&#231;&#227;o MFC que n&#227;o possa ser usada em uma DLL MFC? | Microsoft Docs"
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
  - "DLLs [C++], MFC"
  - "DLLs [C++], restrições"
  - "DLLs MFC [C++], restrições"
ms.assetid: 18e2f1cb-4f72-4d3a-a951-3488208872c7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Existe alguma classe ou fun&#231;&#227;o MFC que n&#227;o possa ser usada em uma DLL MFC?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Dlls de extensão usarão `CWinApp`\- classe derivada do aplicativo cliente.  Não devem ter seu próprio `CWinApp`\- classe derivada.  
  
 Dlls normais devem ter `CWinApp`\- classe derivada e um único objeto dessa classe do aplicativo, como faz um aplicativo MFC.  Ao contrário do objeto de `CWinApp` de um aplicativo, o objeto de `CWinApp` da DLL não tiver uma bomba principal da mensagem.  
  
 Observe que porque o mecanismo de `CWinApp::Run` não se aplica a uma DLL, o aplicativo possuir a bomba principal da mensagem.  Se a DLL abre caixas de diálogo modeless ou tem uma janela principal do quadro de sua escolha, a bomba principal da mensagem de aplicativo deve chamar uma rotina exportada pela DLL, que por sua vez a função de membro de `CWinApp::PreTranslateMessage` do objeto de aplicativo da DLL.  
  
## Consulte também  
 [Perguntas frequentes sobre DLL](../build/dll-frequently-asked-questions.md)