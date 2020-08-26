---
title: Como executar programas do Linux no Windows
ms.date: 07/31/2019
helpviewer_keywords:
- Linux [C++], porting to Win32
ms.assetid: 3837e4fe-3f96-4f24-b2a1-7be94718a881
ms.openlocfilehash: f13777c1c366d2f6b9497296f8819454dda7647e
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837041"
---
# <a name="running-linux-programs-on-windows"></a>Como executar programas do Linux no Windows

Para executar um programa do Linux no Windows, você tem estas opções:

- Execute o programa no estado em que se encontra no WSL (Subsistema do Windows para Linux). No WSL, o programa é executado diretamente no hardware do computador e não em uma máquina virtual. O WSL também permite chamadas diretas de sistema de arquivos entre sistemas Windows e Linux, eliminando a necessidade de transporte SSL. O WSL é projetado como um ambiente de linha de comando e não é recomendado para aplicativos com uso intensivo de gráficos. Para obter mais informações, confira [Documentação do Subsistema do Windows para Linux](/windows/wsl/about).
- Execute o programa no estado em que se encontra em uma máquina virtual do Linux ou em um contêiner do Docker, seja no computador local ou no Azure. Para obter mais informações, confira [Máquinas Virtuais](https://azure.microsoft.com/services/virtual-machines/) e [Docker no Azure](/azure/docker/).
- Compile o programa usando a GCC ou o Clang nos ambientes [MinGW](http://MinGW.org/) ou [MinGW-w64](https://sourceforge.net/p/mingw-w64/wiki2/Home/), que fornecem uma camada de conversão do Linux para chamadas de sistema do Windows.
- Compile e execute o programa usando a GCC ou o Clang no ambiente [Cygwin](https://www.cygwin.com/), que fornece um ambiente Linux mais completo no Windows em comparação com o MinGW ou o MinGW-w64.
- Porte manualmente seu código do Linux e compile para Windows usando o MSVC (Microsoft C++). Isso envolve refatorar o código independente da plataforma em bibliotecas separadas e, em seguida, reescrever o código específico do Linux para usar código específico do Windows (por exemplo, APIs do Win32 ou do DirectX). Para aplicativos que exigem gráficos de alto desempenho, essa é provavelmente a melhor opção.
