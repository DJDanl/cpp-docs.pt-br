---
title: "Executando um aplicativo em C++ - clr em uma versão anterior do tempo de execução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- applications [C++], runtime version specified
- versions [C++]
- app.config files, runtime version specified
- compatibility [C++], runtime version specified
- backward compatibility [C++], runtime version specified
- application deployment [C++], runtime version specified
- common language runtime [C++], version specified
- deploying applications [C++], runtime version specified
ms.assetid: 940171b7-6937-4b14-8e87-c199e23f4f2e
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1f64c0dc31be260332d4d79e8fa38d63bbf6357c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="running-a-c-clr-application-on-a-previous-runtime-version"></a>Executando um aplicativo C++ /clr em uma versão de tempo de execução anterior
A menos que especificado o contrário, um aplicativo C++ .NET Framework é criado para ser executado na versão do tempo de execução (CLR) comum do idioma que o compilador usa para criar o aplicativo. No entanto, é possível que um aplicativo de .exe é criado para uma versão do tempo de execução para executar em qualquer outra versão que fornece a funcionalidade necessária.  
  
 Para fazer isso, forneça um arquivo App. config que contém informações de versão de tempo de execução no `supportedRuntime` marca.  
  
 Em tempo de execução, o arquivo App. config deve ter um nome no formato *filename. ext*. config, onde *filename. ext* é o nome do executável que iniciou o aplicativo e ele deve estar no mesmo diretório o executável. Por exemplo, se seu aplicativo é denominado TestApp.exe, o arquivo App. config será chamado TestApp.exe.config.  
  
 Se você especificar mais de uma versão de tempo de execução e o aplicativo é executado em um computador que tem mais de uma versão de tempo de execução instalado, o aplicativo usa a primeira versão que é especificada no arquivo de configuração e é instalada.  
  
 Para obter mais informações, consulte [como: configurar um aplicativo para uma versão do .NET Framework de destino](http://msdn.microsoft.com/en-us/5247b307-89ca-417b-8dd0-e8f9bd2f4717).  
  
 Para ser executado na versão 1.0 ou 1.1 do CLR, um aplicativo que é criado com o Visual C++ o compilador deve ser compilado usando [/clr:initialAppDomain](../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="see-also"></a>Consulte também  
 [Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)