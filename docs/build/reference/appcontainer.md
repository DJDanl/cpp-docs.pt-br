---
title: "-APPCONTAINER | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/APPCONTAINER"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "APPCONTAINER editbin - opção"
  - "-APPCONTAINER editbin - opção"
  - "/APPCONTAINER editbin - opção"
ms.assetid: 0ca4f1ec-c8de-4a37-b3e2-deda7af0bb88
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /APPCONTAINER
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Marca um executável que deve ser executado em um contêiner de aplicativos — por exemplo, um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] ou aplicativo Universal do Windows.  
  
```  
  
/APPCONTAINER[:NO]  
```  
  
## Comentários  
 Um executável que tem o **\/APPCONTAINER** conjunto de opções só pode ser executado em um contêiner de aplicativos, que é o ambiente de isolamento do processo introduzido no Windows 8. Para [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] e aplicativos universais do Windows, essa opção deve ser definida.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)   
 [O que é um aplicativo Universal do Windows?](http://go.microsoft.com/fwlink/p/?LinkID=522074)