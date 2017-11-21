---
title: "Preparando uma máquina de teste para executar um executável de depuração | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: debug executable, preparing a test machine to run
ms.assetid: f0400989-cc2e-4dce-9788-6bdbe91c6f5a
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1b8b675f6125ce6449dc1627e8ba1f375f87aade
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="preparing-a-test-machine-to-run-a-debug-executable"></a>Preparando uma máquina de teste para executar um executável de depuração
Para preparar o computador para testar a versão de depuração de um aplicativo que é criado com o Visual C++, você precisa implantar versões de depuração da biblioteca do Visual C++ DLLs que o aplicativo depende. Para identificar quais DLLs devem ser desenvolvidos, siga as etapas em [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md). Normalmente, as versões de depuração do Visual C++ biblioteca DLLs têm nomes que terminam em "d". Por exemplo, a versão de depuração de msvcr100.dll é denominada msvcr100d.dll.  
  
> [!NOTE]
>  As versões de depuração de um aplicativo não são redistribuíveis e não são versões de depuração as DLLs de biblioteca do Visual C++ redistribuíveis. Você pode implantar versões de depuração de aplicativos e DLLs do Visual C++ apenas para outros computadores, o único propósito de depuração e teste os aplicativos em um computador que não tenha instalado o Visual Studio. Para obter mais informações, consulte [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md).  
  
 Há três maneiras de implantar versões de depuração de DLLs de biblioteca do Visual C++ junto com a versão de depuração de um aplicativo.  
  
-   Use implantação central para instalar uma versão de depuração de um DLL específico do Visual C++ para o diretório %windir%\system32\ usando um projeto de instalação que inclui módulos de mesclagem para a versão da biblioteca correta e a arquitetura do seu aplicativo. Módulos de mesclagem são encontrados no diretório de arquivos de programa (x86) em \Common Files\Merge módulos ou arquivos de programa\\. A versão de depuração de um módulo de mesclagem tem depuração no nome para exemplo, Microsoft_VC110_DebugCRT_x86.msm. Um exemplo desta implantação pode ser encontrado no [passo a passo: Implantando um Visual C++ aplicativo usando um projeto de instalação](../ide/walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).  
  
-   Usar a implantação local para instalar uma versão de depuração de um DLL específico do Visual C++ no diretório de instalação do aplicativo por meio de arquivos que são fornecidos no diretório de arquivos de programa (x86) em \Microsoft Visual Studio ou arquivos de programa \<versão > \VC\redist\Debug_NonRedist\\.  
  
    > [!NOTE]
    >  Para depuração remota de seu aplicativo criado usando o Visual C++ 2005 ou do Visual C++ 2008 em outro computador, você precisa implantar versões de depuração da biblioteca do Visual C++ DLLs como assemblies lado a lado compartilhados. Você pode usar um projeto de instalação ou o Windows Installer para instalar os módulos de mesclagem correspondente.  
  
-   Use the_**implantar** opção o **do Configuration Manager** caixa de diálogo no Visual Studio para copiar a saída do projeto e outros arquivos para o computador remoto. 
  
 Após a instalação DLLs do Visual C++, você pode executar um depurador remoto em um compartilhamento de rede. Para obter mais informações sobre a depuração remota, consulte [depuração remota](/visualstudio/debugger/remote-debugging.md).  
  
## <a name="see-also"></a>Consulte também  
 
 [Implantação em Visual C++](../ide/deployment-in-visual-cpp.md)   
 [Opções de linha de comando do Windows Installer](http://msdn.microsoft.com/library/windows/desktop/aa367988.aspx)   
 [Exemplos de implantação](../ide/deployment-examples.md) [depuração remota](/visualstudio/debugger/remote-debugging.md)