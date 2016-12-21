---
title: "Suporte de vinculador para DLLs carregadas com atraso | Microsoft Docs"
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
  - "carregamento atrasado de DLLs, suporte ao vinculador"
ms.assetid: b2d7e449-2809-42b1-9c90-2c0ca5e31a14
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Suporte de vinculador para DLLs carregadas com atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O vinculador Visual C\+\+ agora oferece suporte depois de carregar a DLL.  Isso alivia\-o da necessidade de usar as funções **LoadLibrary** e **GetProcAddress** de [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)] para implementar atrasado carregar a DLL.  
  
 Antes do Visual C\+\+ 6.0, a única maneira de carregar uma DLL estava em tempo de execução usando **LoadLibrary** e **GetProcAddress**; o sistema operacional carrega o DLL quando o executável ou a DLL que usam o foram carregados.  
  
 A partir do Visual C\+\+ 6.0, estaticamente ao vincular a uma DLL, o vinculador fornece opções para atrasar ao carregar a DLL até que o programa chamar uma função em que o DLL.  
  
 Um aplicativo pode retardar a carga uma DLL usando a opção do vinculador de [\/DELAYLOAD \(Importação de carga de atraso\)](../../build/reference/delayload-delay-load-import.md) com uma função auxiliar \(implementação padrão fornecida pelo Visual C\+\+\).  A função auxiliar carregará a DLL em tempo de execução chamando **LoadLibrary** e **GetProcAddress** para você.  
  
 Você deve considerar o atraso que carrega um DLL se:  
  
-   O programa não pode chamar uma função na DLL.  
  
-   Uma função na DLL não pode obter chamado até depois da execução do programa.  
  
 Depois de carregar uma DLL pode ser especificado durante a criação de um projeto de .EXE ou de .DLL.  Um projeto de .DLL que atrasa a carga de um ou mais DLL não devem própria chamada um ponto de entrada atraso\- carregado em Dllmain.  
  
 Os tópicos a seguir descrevem DLL de carga de atraso:  
  
-   [Especificando DLL para reter a carga](../../build/reference/specifying-dlls-to-delay-load.md)  
  
-   [Descarregando DLL explicitamente um Atraso\- carregado](../../build/reference/explicitly-unloading-a-delay-loaded-dll.md)  
  
-   [Carregando todas as importações para uma DLL Atraso\- carregado](../../build/reference/loading-all-imports-for-a-delay-loaded-dll.md)  
  
-   [Associando importações](../../build/reference/binding-imports.md)  
  
-   [Tratamento de erros e notificação](../../build/reference/error-handling-and-notification.md)  
  
-   [Despejando importa Atraso\- carregadas](../../build/reference/dumping-delay-loaded-imports.md)  
  
-   [Restrições de DLL de carga de atraso](../../build/reference/constraints-of-delay-loading-dlls.md)  
  
-   [Compreendendo a função auxiliar](http://msdn.microsoft.com/pt-br/6279c12c-d908-4967-b0b3-cabfc3e91d3d)  
  
-   [Desenvolvendo sua própria função auxiliar](../../build/reference/developing-your-own-helper-function.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../../build/dlls-in-visual-cpp.md)   
 [Vinculando](../Topic/Linking.md)