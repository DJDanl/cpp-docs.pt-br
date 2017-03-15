---
title: "Conceitos de implanta&#231;&#227;o | Microsoft Docs"
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
  - "implantação de aplicativos [C++], sobre implantação de aplicativos"
  - "dependências [C++], implantação de aplicativos e"
  - "implantando aplicativos [C++], sobre a implantação de aplicativos"
  - "bibliotecas [C++], problemas de implantação de aplicativos"
  - "Windows Installer [C++]"
ms.assetid: ebd7f246-ab54-40e8-87fa-dac02c0047b3
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Conceitos de implanta&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta seção aborda considerações chave para implantar aplicativos de C\+\+.  
  
## Implantação do Windows Installer em C\+\+  
 Os projetos Visual C\+\+ normalmente usam a configuração do Windows Installer tradicional para implantação.  Para preparar uma implantação do Windows Installer, você compactar seu aplicativo em um arquivo setup.exe e distribui esse arquivo, junto com um pacote de instalação \(.msi\).  Os usuários executam em setup.exe para instalar o aplicativo.  
  
 Você compactar seu aplicativo adicionando um projeto de configuração à sua solução; quando compilada, cria arquivos de pacote de configuração e installer que você distribui aos usuários.  Para obter mais informações, consulte [Escolhendo uma método de implantação](../ide/choosing-a-deployment-method.md).  
  
## Dependências de biblioteca  
 Quando o aplicativo de energia AC \/C \+\+ é compilado usando a funcionalidade fornecida pelas bibliotecas de Visual C\+\+, ele fica dependente da presença dessas bibliotecas em tempo de execução.  Para que o aplicativo seja executado, ele deve vincular, estaticamente ou dinamicamente, a bibliotecas necessárias do Visual C\+\+.  Se um aplicativo links dinamicamente ao Visual C\+\+ uma biblioteca, então quando executa que a biblioteca deve estar presente o que pode ser carregado.  Por outro lado, se o aplicativo tem estaticamente ao Visual C\+\+ uma biblioteca, então ele não precisa dlls correspondentes estão presentes no computador do usuário.  Vincular estático, no entanto, tem alguns efeitos negativos, como o aumentar o tamanho dos arquivos de aplicativo, e a feitura de manutenção possivelmente mais difícil.  Para obter mais informações, consulte [Vantagens de usar DLLs](../build/advantages-of-using-dlls.md).  
  
## Empacotamento e redistribuir  
 As bibliotecas do Visual C\+\+ são empacotadas como DLL, e todas as bibliotecas necessárias para aplicativos de C\/C\+\+ são instalados pelo Visual Studio no computador do desenvolvedor.  Entretanto, ao implantar seu aplicativo para os usuários, não é viável na maioria dos casos exigir instalar o Visual Studio para executar o aplicativo.  É importante poder redistribuir apenas as partes do Visual C\+\+ exigidas por seu aplicativo executar corretamente.  
  
 Para obter mais informações sobre de empacotamento e de redistribuir, consulte os seguintes tópicos:  
  
-   [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md).  
  
-   [Escolhendo uma método de implantação](../ide/choosing-a-deployment-method.md).  
  
 Para exemplos de implantação e sugestões sobre a solução de problemas, consulte:  
  
-   [Exemplos de implantação](../ide/deployment-examples.md).  
  
-   [Solução de problemas](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md).  
  
## Consulte também  
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)   
 [Noções básicas sobre as dependências de um aplicativo do Visual C\+\+](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md)   
 [Windows Installer Deployment](http://msdn.microsoft.com/pt-br/121be21b-b916-43e2-8f10-8b080516d2a0)