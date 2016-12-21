---
title: "Compilando aplicativos isolados do C/C++ e assemblies lado a lado | Microsoft Docs"
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
  - "WinSxS [C++]"
  - "cache de assembly nativo [C++]"
  - "compilações [C++], isoladas de aplicativos"
  - "aplicativos lado a lado [C++]"
  - "compilações [C++], assemblies lado a lado"
ms.assetid: 9465904e-76f7-48bd-bb3f-c55d8f1699b6
caps.latest.revision: 20
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilando aplicativos isolados do C/C++ e assemblies lado a lado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ oferece suporte a um modelo de implantação para aplicativos de cliente do Windows com base na ideia de [aplicativos isolados](http://msdn.microsoft.com/library/aa375190) e [assemblies lado a lado](_win32_side_by_side_assemblies). Por padrão, o Visual C\+\+ compila todos os aplicativos C\/C\+\+ nativos como aplicativos isolados que usam [manifestos](http://msdn.microsoft.com/library/aa375365) para descrever suas dependências em bibliotecas do Visual C\+\+.  
  
 Criação de programas do C\/C\+\+ como aplicativos isolados apresenta muitas vantagens. Por exemplo, um aplicativo isolado é afetado quando outros aplicativos C\/C\+\+ instalar ou desinstalar as bibliotecas do Visual C\+\+. Bibliotecas do Visual C\+\+ usadas por aplicativos isolados ainda podem ser redistribuídas na pasta local do aplicativo ou pela instalação para o cache de assembly nativo \(WinSxS\); No entanto, manutenção das bibliotecas do Visual C\+\+ para aplicativos já implantados podem ser simplificados usando um [arquivo de configuração do publicador](http://msdn.microsoft.com/library/aa375680). O modelo de implantação de aplicativo isolado facilita garantir que aplicativos C\/C\+\+ em execução em um computador específico usam a versão mais recente das bibliotecas do Visual C\+\+, enquanto ainda deixa aberta a possibilidade dos administradores de sistema e autores de aplicativos para controlar a associação de versão explícita dos aplicativos para suas DLLs dependentes.  
  
 Esta seção discute como você pode criar seu aplicativo C\/C\+\+ como um aplicativo isolado e certifique\-se de que ele é ligado às bibliotecas do Visual C\+\+ usando um manifesto. As informações nesta seção se aplica principalmente para aplicativos do Visual C\+\+ nativos ou gerenciados. Para obter informações sobre como implantar aplicativos nativos compilados com o Visual C\+\+, consulte [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md).  
  
## Nesta seção  
 [Conceitos de aplicativos isolados e assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)  
  
 [Compilando aplicativos isolados do C\/C\+\+](../build/building-c-cpp-isolated-applications.md)  
  
 [Compilando assemblies lado a lado do C\/C\+\+](../build/building-c-cpp-side-by-side-assemblies.md)  
  
 [Como compilar componentes COM sem registro](../build/how-to-build-registration-free-com-components.md)  
  
 [Como compilar aplicativos isolados para consumir componentes COM](../Topic/How%20to:%20Build%20Isolated%20Applications%20to%20Consume%20COM%20Components.md)  
  
 [Noções básicas sobre geração de manifesto para programas do C\/C\+\+](../Topic/Understanding%20Manifest%20Generation%20for%20C-C++%20Programs.md)  
  
 [Solução de problemas](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md)  
  
## Seções relacionadas  
 [Aplicativos isolados e Assemblies lado a lado](http://msdn.microsoft.com/library/dd408052)  
  
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)