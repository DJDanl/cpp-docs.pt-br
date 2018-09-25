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
ms.openlocfilehash: ee823d7b37428ea335d5d789a4fcfb4caa673dda
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378041"
---
# <a name="running-a-c-clr-application-on-a-previous-runtime-version"></a>Executando um aplicativo C++ /clr em uma versão de tempo de execução anterior

A menos que especificado de outro modo, um aplicativo .NET Framework do C++ é criado para ser executado na versão CLR (Common Language Runtime) usada pelo compilador para compilar o aplicativo. No entanto, é possível que um aplicativo .exe criado para uma versão do tempo de execução seja executado em qualquer outra versão que forneça a funcionalidade necessária.

Para fazer isso, forneça um arquivo app.config que contém informações de versão de tempo de execução na marcação `supportedRuntime`.

Em tempo de execução, o arquivo app.config precisa ter um nome no formato *nome _do_arquivo.ext*.config, em que *nome_do_arquivo.ext* é o nome do executável que iniciou o aplicativo, e precisa estar no mesmo diretório do executável. Por exemplo, se o aplicativo for nomeado TestApp.exe, o arquivo app.config será nomeado TestApp.exe.config.

Se você especificar mais de uma versão de tempo de execução e o aplicativo for executado em um computador que tenha mais de uma versão de tempo de execução instalada, o aplicativo usará a primeira versão especificada no arquivo de configuração e ela será instalada.

## <a name="see-also"></a>Consulte também

[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)