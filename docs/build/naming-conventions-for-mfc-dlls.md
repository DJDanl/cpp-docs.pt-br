---
title: "Conven&#231;&#245;es de nomenclatura para DLLs MFC | Microsoft Docs"
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
  - "DLLs [C++], nomes de bibliotecas"
  - "DLLs [C++], convenções de nomenclatura"
  - "bibliotecas [C++], Nomes de DLL MFC"
  - "DLLs MFC [C++], convenções de nomenclatura"
  - "Bibliotecas MFC [C++], convenções de nomenclatura"
  - "convenções de nomenclatura [C++], DLLs MFC"
  - "versões de DLLs compartilhadas [C++]"
ms.assetid: 0db9c3f3-87d3-40e8-8964-250f9d2a2209
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Conven&#231;&#245;es de nomenclatura para DLLs MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Dlls e bibliotecas incluídos no MFC seguem uma convenção de nomenclatura estruturados.  Isso facilita saber quais DLL ou biblioteca você deve usar para a finalidade.  
  
 As bibliotecas de importação necessárias para criar aplicativos ou DLL de extensão que usam esses DLL tiverem o mesmo nome de base que o DLL mas ter uma extensão de nome de arquivo .lib.  
  
### Convenção de nomenclatura compartilhada da DLL  
  
|Dlls|Descrição|  
|----------|---------------|  
|MFCx0.DLL|DLL MFC, a versão do ANSI|  
|MFCx0U.DLL|DLL MFC, a versão do Unicode|  
|MFCx0D.DLL|DLL MFC, versão de depuração ANSI|  
|MFCx0UD.DLL|DLL MFC, versão de depuração Unicode|  
  
 Se você estiver vinculando dinamicamente à versão da DLL compartilhada MFC, se for de um aplicativo ou de uma DLL da extensão, você deve incluir MFCx0.DLL com seu produto.  Se você precisar o suporte de Unicode em seu aplicativo, inclua MFCx0U.DLL em vez disso.  
  
 Se você estiver vinculando estaticamente o DLL para o MFC, você deve link com uma das bibliotecas de MFC estáticos.  Essas versões são nomeadas de acordo com a convenção \[N&#124;U \]\[\] AFXCW D .LIB.  Para obter mais informações, consulte a tabela de “convenções de nomenclatura de biblioteca Estática\- link” em [Convenções de nomenclatura de biblioteca](../Topic/Library%20Naming%20Conventions.md) \(MFC\).  
  
 Para obter uma lista de DLL do Visual C\+\+ que podem ser distribuídos com seus aplicativos, consulte Redist.txt na instalação do Visual Studio.  
  
## Que você deseja saber mais?  
  
-   [A convenção de nomenclatura para bibliotecas](../Topic/Library%20Naming%20Conventions.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)