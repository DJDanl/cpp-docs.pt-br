---
title: "Compilando aplicativos isolados do C/C++ | Microsoft Docs"
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
  - "aplicativos isolados [C++]"
ms.assetid: 8a2fe4fa-0489-433e-bfc6-495844d8d73a
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilando aplicativos isolados do C/C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um aplicativo isolado depende apenas os assemblies lado a lado de e associa a suas dependências usando um manifesto.  Não é necessário para que o aplicativo está isolado completamente para executar corretamente no windows; no entanto, em investindo fazer seu aplicativo isolado completamente, você poderá economizar tempo se você precisa atender no futuro ao aplicativo.  Para obter mais informações sobre as vantagens de fazer seu aplicativo completamente isoladas, consulte [Aplicativos isolados](http://msdn.microsoft.com/library/aa375190).  
  
 Quando você cria seu aplicativo nativo C\/C\+\+ usando o Visual C\+\+, por padrão o sistema de projeto do Visual Studio gerencia um arquivo de manifesto que descreve as dependências do seu aplicativo em bibliotecas Visual C\+\+.  Se essas são as únicas dependências seu aplicativo tiver, ele se tornará um aplicativo isolado assim que for reconstruído com o Visual Studio.  Se o seu aplicativo estiver usando outras bibliotecas em tempo de execução, você pode precisar recriar essas bibliotecas como assemblies lado a lado seguindo as etapas descritas em [Compilando assemblies lado a lado do C\/C\+\+](../build/building-c-cpp-side-by-side-assemblies.md).  
  
## Consulte também  
 [Conceitos de aplicativos isolados e assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)   
 [Compilando aplicativos isolados do C\/C\+\+ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)