---
title: "Aviso LNK4104 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4104"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4104"
ms.assetid: ca6728db-d616-419a-a570-65e8445c6079
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4104 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a exportação do símbolo “símbolo” deve ser PRIVADA  
  
 `symbol` pode ser um dos seguintes:  
  
-   `DllCanUnloadNow`  
  
-   `DllGetClassObject`  
  
-   `DllGetClassFactoryFromClassString`  
  
-   `DllGetDocumentation`  
  
-   `DllInitialize`  
  
-   `DllInstall`  
  
-   `DllRegisterServer`  
  
-   `DllRegisterServerEx`  
  
-   `DllRegisterServerExW`  
  
-   `DllUnload`  
  
-   `DllUnregisterServer`  
  
-   `RasCustomDeleteEntryNotify`  
  
-   `RasCustomDial`  
  
-   `RasCustomDialDlg`  
  
-   `RasCustomEntryDlg`  
  
 Esse aviso é emitido quando você está criando uma biblioteca de importação para uma DLL e exporta uma das funções anteriores sem especificar como PRIVADA no arquivo de definição.  Geralmente, essas funções são exportadas para uso apenas pelo OLE.  Coloca na biblioteca de importação pode resultar em comportamento incomum quando um programa vinculado à biblioteca que faz chamadas incorretamente.  Para obter mais informações sobre a palavra\-chave PRIVADO, consulte [EXPORTAÇÕES](../Topic/EXPORTS.md).