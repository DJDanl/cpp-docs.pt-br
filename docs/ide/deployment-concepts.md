---
title: "Conceitos de implantação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows Installer [C++]
- dependencies [C++], application deployment and
- application deployment [C++], about application deployment
- deploying applications [C++], about deploying applications
- libraries [C++], application deployment issues
ms.assetid: ebd7f246-ab54-40e8-87fa-dac02c0047b3
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b40865266548067e2dda3782e66802c0dbe2844e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="deployment-concepts"></a>Conceitos de implantação
Esta seção aborda as considerações principais para implantar aplicativos do C++.  
  
## <a name="windows-installer-deployment-in-c"></a>Implantação do Windows Installer em C++  
 Projetos Visual C++ geralmente usam a instalação tradicional do Windows Installer para implantação. Para preparar uma implantação do Windows Installer, você pode empacotar seu aplicativo em um arquivo setup.exe e distribuí-lo, junto com um pacote do instalador (. msi). Os usuários, em seguida, executam o setup.exe para instalar o aplicativo.  
  
 Empacotar seu aplicativo adicionando um projeto de instalação para sua solução; Quando criado, ele cria a instalação e o instalador arquivos de pacote que você distribui para os usuários. Para obter mais informações, consulte [escolhendo um método de implantação](../ide/choosing-a-deployment-method.md).  
  
## <a name="library-dependencies"></a>Dependências de biblioteca  
 Quando um aplicativo C/C++ é criado usando a funcionalidade fornecida pelas bibliotecas do Visual C++, ela se torna dependente a presença dessas bibliotecas em tempo de execução. Em ordem para o aplicativo seja executado, ele deve vincular, estática ou dinamicamente, para as bibliotecas necessárias do Visual C++. Se um aplicativo dinamicamente links em uma biblioteca do Visual C++, em seguida, quando ele é executado biblioteca deve estar presente para que possam ser carregados. Por outro lado, se o aplicativo estiver vinculado estaticamente em uma biblioteca do Visual C++, em seguida, ele não precisa as DLLs correspondentes esteja presente no computador do usuário. No entanto, a vinculação estática, tem alguns efeitos negativos, como o aumento do tamanho dos arquivos do aplicativo e fazendo manutenção potencialmente mais difícil. Para obter mais informações, consulte [as vantagens de usar DLLs](../build/dlls-in-visual-cpp.md#advantages-of-using-dlls).  
  
## <a name="packaging-and-redistributing"></a>Empacotamento e redistribuir  
 Bibliotecas do Visual C++ são empacotadas como DLLs e todas as bibliotecas necessárias para aplicativos C/C++ são instaladas pelo Visual Studio no computador do desenvolvedor. No entanto, ao implantar seu aplicativo para seus usuários, não é viável na maioria dos casos para necessárias para instalar o Visual Studio para executar seu aplicativo. É importante poder redistribuir apenas as partes do Visual C++ que são exigidas por seu aplicativo seja executado corretamente.  
  
 Para obter mais informações sobre a redistribuição e pacotes, consulte os tópicos a seguir:  
  
-   [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md).  
  
-   [Escolhendo um método de implantação](../ide/choosing-a-deployment-method.md).  
  
 Para obter exemplos de implantação e sugestões sobre como solucionar problemas, consulte:  
  
-   [Exemplos de implantação](../ide/deployment-examples.md).  
  
-   [Solucionando problemas do C/C++ aplicativos isolados e Assemblies lado a lado](../build/troubleshooting-c-cpp-isolated-applications-and-side-by-side-assemblies.md).  
  
## <a name="see-also"></a>Consulte também  
 [Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)   
 [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md)   
 [implantação do Windows Installer](http://msdn.microsoft.com/en-us/121be21b-b916-43e2-8f10-8b080516d2a0)