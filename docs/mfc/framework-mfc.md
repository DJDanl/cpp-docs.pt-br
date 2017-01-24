---
title: "Framework (MFC) | Microsoft Docs"
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
  - "APIs [C++], encapsulamento por MFC Win32"
  - "estrutura de aplicativo [C++], sobre estrutura de aplicativo MFC"
  - "API de Win32 encapsulada"
  - "encapsulamento [C++]"
  - "encapsulamento [C++], API de Win32"
  - "MFC [C++], estrutura de aplicativo"
  - "Win32 [C++], encapsulamento de API por MFC"
  - "API do Windows [C++], encapsulamento por MFC"
  - "classes wrapper, explicado"
ms.assetid: 3be0fec8-9843-4119-ae42-ece993ef500b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Framework (MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Seu trabalho com a estrutura de \(MFC\) da biblioteca de classes do Microsoft foundation é baseado em grande parte em algumas classes principais e em várias ferramentas do Visual C\+\+.  Algumas classes encapsulam uma grande parte da interface de programação de aplicativo \(API\) do Win32.  Outras classes encapsulam os conceitos de aplicativo como documentos, exibições, e o próprio aplicativo.  Ainda outros encapsulam a funcionalidade OLE de recursos e de acesso a dados ODBC e de DAO.  
  
 Por exemplo, o conceito do Win32 da janela é encapsulado pela classe `CWnd`MFC.  Isto é, a c criando `CWnd` chamado classe encapsula “ou” envolve a alça de `HWND` que representa uma janela do windows.  Também, a classe `CDialog` encapsula caixas de diálogo do Win32.  
  
 Encapsulamento significa que a classe `CWnd`C\+\+, por exemplo, contém uma variável de membro do tipo `HWND`, e as funções de membro da classe encapsulam as chamadas ao Win32 funções que têm `HWND` como um parâmetro.  As funções de membro da classe normalmente têm o mesmo nome da função do Win32 ele encapsula.  
  
## Nesta seção  
 [SDI e MDI](../mfc/sdi-and-mdi.md)  
  
 [Documentos, exibições, e a estrutura](../mfc/documents-views-and-the-framework.md)  
  
 [Assistentes e editores de recursos](../Topic/Wizards%20and%20the%20Resource%20Editors.md)  
  
## Em seções relacionadas  
 [Criar a estrutura](../mfc/building-on-the-framework.md)  
  
 [Como a estrutura chama seu código](../mfc/how-the-framework-calls-your-code.md)  
  
 [CWinApp: A classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md)  
  
 [Modelos do documento e o processo de criação do documento\/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)  
  
 [Manipulação e Mapeamento de Mensagem](../mfc/message-handling-and-mapping.md)  
  
 [Objetos da janela](../mfc/window-objects.md)  
  
## Consulte também  
 [Usando as classes para escrever aplicativos para Windows](../Topic/Using%20the%20Classes%20to%20Write%20Applications%20for%20Windows.md)