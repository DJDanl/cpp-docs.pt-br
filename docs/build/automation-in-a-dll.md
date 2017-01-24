---
title: "Automa&#231;&#227;o em um DLL | Microsoft Docs"
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
  - "Automação [C++], DLLs"
  - "DLLs [C++], Automação"
ms.assetid: 2728ecd1-14e2-4ae0-a946-e749e11dbb74
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Automa&#231;&#227;o em um DLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você escolhe a opção de automação no assistente da DLL MFC, o assistente fornece com o seguinte:  
  
-   Um arquivo de linguagem de descrição do objeto do acionador inicial \(.ODL\)  
  
-   Uma política incluir no arquivo de STDAFX.h para Afxole.h  
  
-   Uma implementação da função de `DllGetClassObject` , que chama a função de **AfxDllGetClassObject**  
  
-   Uma implementação da função de `DllCanUnloadNow` , que chama a função de **AfxDllCanUnloadNow**  
  
-   Uma implementação da função de `DllRegisterServer` , que chama a função de [COleObjectFactory::UpdateRegistryAll](../Topic/COleObjectFactory::UpdateRegistryAll.md)  
  
## Que você deseja saber mais?  
  
-   [Servidores de automação](../mfc/automation-servers.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)