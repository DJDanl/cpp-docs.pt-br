---
title: "Dom&#237;nios de aplicativo e Visual C++ | Microsoft Docs"
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
  - "Opção de compilador /clr [C++], domínios do aplicativo"
  - "domínios do aplicativo [C++], C++"
  - "interoperabilidade [C++], domínios do aplicativo"
  - "interoperabilidade [C++], domínios do aplicativo"
  - "assemblies mistos [C++], domínios do aplicativo"
ms.assetid: 75a08efc-9b02-40ba-99b7-dcbd71010bbf
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Dom&#237;nios de aplicativo e Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você tiver uma função virtual de `__clrcall` , o será vtable pelo domínio de aplicativo \(appdomain\).  Se você criar um objeto em um appdomain, você só poderá chamar a função virtual de dentro desse appdomain.  Todas as funções definidas em compilands de **\/clr:pure** usam `__clrcall` que chama a convenção.  Em virtude disso, todos os vtables definidos em compilands de **\/clr:pure** são por appdomain.  No modo misto \(\)**\/clr**você terá por vtables do processo se seu tipo não tem nenhuma função virtual de `__clrcall` .  
  
 Para obter mais informações, consulte  
  
-   [appdomain](../Topic/appdomain.md)  
  
-   [\_\_clrcall](../cpp/clrcall.md)  
  
-   [Como migrar para \/clr:pure](../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md)  
  
-   [process](../cpp/process.md)  
  
## Consulte também  
 [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md)