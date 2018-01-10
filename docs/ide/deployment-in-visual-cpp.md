---
title: "Implantação em Visual C++ | Microsoft Docs"
ms.custom: 
ms.date: 9/21/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- deploying applications [C++]
- application deployment [C++]
ms.assetid: d4b4ffc0-d2bd-4e4a-84a6-62f1c26f6a09
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: eda9c4a1a173087688c1fd3182845d6517f27ba6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="deployment-in-visual-c"></a>Implantação no Visual C++

Instalação do seu aplicativo em um computador diferente do computador de desenvolvimento é conhecida como *implantação*. Quando você implanta um aplicativo Visual C++ para outro computador, você deve instalar o aplicativo e os arquivos de biblioteca depende. O Visual Studio permite três maneiras de implantar as bibliotecas do Visual C++ junto com seu aplicativo: *implantação central*, *implantação local*, e *vinculação estática*. Implantação central coloca os arquivos de biblioteca no diretório do Windows, onde o serviço Windows Update pode atualizá-los automaticamente. Implantação local coloca os arquivos de biblioteca no mesmo diretório do seu aplicativo. Você deve reimplantar todas as bibliotecas implantadas localmente para atualizá-los. Vinculação estática associa o código de biblioteca em seu aplicativo. Você deve recompilar e reimplantar o aplicativo para tirar proveito de todas as atualizações para as bibliotecas quando você usa a vinculação estática.

## <a name="central-deployment"></a>Implantação central

Implantação central, arquivos DLL de biblioteca são instalados na pasta Windows\System32, ou para arquivos de biblioteca de 32 bits em x64 de sistemas, o diretório Windows\SysWow64. A Microsoft atualiza automaticamente as bibliotecas que são implantadas centralmente. Para bibliotecas do Visual C++ que são implantadas localmente ou estaticamente vinculadas, você deve fornecer as atualizações.

Para implantar centralmente as bibliotecas do Visual C++, você pode usar uma dessas duas fontes para os arquivos para instalar:

- *Pacote redistribuível* arquivos, que são executáveis de linha de comando autônoma que contêm todas as bibliotecas do Visual C++ redistribuíveis em formato compactado, ou

- *Módulos de mesclagem redistribuíveis* (arquivos. msm), que você pode usar para implantar bibliotecas específicas, e que você incluir no arquivo do Windows Installer (. msi) do seu aplicativo.

Um arquivo de pacote redistribuível instala todas as bibliotecas do Visual C++ para uma arquitetura de sistema específica. Por exemplo, se seu aplicativo é criado para x64, você pode usar o pacote redistribuível vcredist_x64.exe para instalar todas as bibliotecas do Visual C++ que seu aplicativo usa. Você pode programar o instalador de seu aplicativo para executar o pacote redistribuível como pré-requisito antes de instalar o aplicativo.

Um módulo de mesclagem permite a inclusão de lógica de instalação para uma biblioteca específica do Visual C++ em um arquivo de configuração de aplicativo do Windows Installer. Você pode incluir os módulos de mesclagem como muitas ou poucas como seu aplicativo requer. Use módulos de mesclagem quando você precisa para minimizar o tamanho de seus binários de implantação.

Como a implantação central usando um pacote redistribuível ou módulos de mesclagem permite que o Windows Update atualizar automaticamente as bibliotecas do Visual C++, é recomendável que você usa a biblioteca de DLLs em seu aplicativo em vez de bibliotecas estáticas e usa central implantação em vez de implantação local.

## <a name="local-deployment"></a>Implantação local

Implantação local, arquivos de biblioteca são instalados na pasta de seu aplicativo junto com o arquivo executável. Versões diferentes de bibliotecas do Visual C++ redistribuíveis podem ser instaladas na mesma pasta porque o nome do arquivo de cada versão inclui seu número de versão. Por exemplo, a versão 12 da biblioteca de tempo de execução C++ é msvcp120.dll e a versão 14 é msvcp140.dll.

Como a Microsoft não é automaticamente localmente Atualização implantada bibliotecas do Visual C++, não recomendamos a implantação local dessas bibliotecas. Se você decidir usar a implantação local de bibliotecas redistribuíveis, recomendamos implementar seu próprio método de atualização automática das bibliotecas localmente implantadas.

## <a name="static-linking"></a>Vinculação estática

Além das bibliotecas de vínculos dinâmicos, o Visual Studio fornece a maioria de suas bibliotecas como bibliotecas estáticas. Estaticamente, você pode vincular uma biblioteca estática para seu aplicativo, ou seja, vincular o código de objeto de biblioteca diretamente no aplicativo. Isso cria um único binário sem uma dependência DLL, para que você não precisa implantar arquivos de biblioteca do Visual C++ separadamente. No entanto, não recomendamos essa abordagem porque as bibliotecas vinculadas estaticamente não podem ser atualizadas no local. Se você usar a vinculação estática e quiser atualizar uma biblioteca vinculada, precisará recompilar e reimplantar seu aplicativo.

## <a name="troubleshooting-deployment-issues"></a>Solucionando problemas de implantação

A ordem de carregamento das bibliotecas do Visual C++ é dependente do sistema. Para diagnosticar problemas do carregador, use depends.exe ou where.exe. Para obter mais informações, consulte [ordem de pesquisa de biblioteca de vínculo dinâmico (Windows)](http://msdn.microsoft.com/library/windows/desktop/ms682586.aspx).

## <a name="see-also"></a>Consulte também

[Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)