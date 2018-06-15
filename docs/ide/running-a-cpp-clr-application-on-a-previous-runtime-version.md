---
title: Executando um aplicativo do C++ -clr em uma versão de tempo de execução anterior | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4f8e76930eb9191d27085d92a9d3a678812715fc
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33323609"
---
# <a name="running-a-c-clr-application-on-a-previous-runtime-version"></a>Executando um aplicativo C++ /clr em uma versão de tempo de execução anterior
A menos que especificado de outro modo, um aplicativo .NET Framework do C++ é criado para ser executado na versão CLR (Common Language Runtime) usada pelo compilador para compilar o aplicativo. No entanto, é possível que um aplicativo .exe criado para uma versão do tempo de execução seja executado em qualquer outra versão que forneça a funcionalidade necessária.  
  
 Para fazer isso, forneça um arquivo app.config que contém informações de versão de tempo de execução na marcação `supportedRuntime`.  
  
 Em tempo de execução, o arquivo app.config precisa ter um nome no formato *nome _do_arquivo.ext*.config, em que *nome_do_arquivo.ext* é o nome do executável que iniciou o aplicativo, e precisa estar no mesmo diretório do executável. Por exemplo, se o aplicativo for nomeado TestApp.exe, o arquivo app.config será nomeado TestApp.exe.config.  
  
 Se você especificar mais de uma versão de tempo de execução e o aplicativo for executado em um computador que tenha mais de uma versão de tempo de execução instalada, o aplicativo usará a primeira versão especificada no arquivo de configuração e ela será instalada.  
  
 Para obter mais informações, confira [Como configurar um aplicativo para que ele seja direcionado a uma versão do .NET Framework](http://msdn.microsoft.com/en-us/5247b307-89ca-417b-8dd0-e8f9bd2f4717).  
  
 Para ser executado na versão 1.0 ou 1.1 do CLR, um aplicativo criado pelo compilador do Visual C++ precisa ser compilado usando [/clr:initialAppDomain](../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="see-also"></a>Consulte também  
 [Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)