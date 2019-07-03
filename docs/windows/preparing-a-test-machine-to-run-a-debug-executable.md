---
title: Preparando uma máquina de teste para executar um executável de depuração
ms.date: 07/02/2019
helpviewer_keywords:
- debug executable, preparing a test machine to run
ms.assetid: f0400989-cc2e-4dce-9788-6bdbe91c6f5a
ms.openlocfilehash: 87d2bf434aef3a85bf7fa19f5886bec106515809
ms.sourcegitcommit: 9b904e490b1e262293a602bd1291a8f3045e755b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/03/2019
ms.locfileid: "67552334"
---
# <a name="preparing-a-test-machine-to-run-a-debug-executable"></a>Preparando uma máquina de teste para executar um executável de depuração

Para preparar um computador para testar a versão de depuração de um aplicativo compilado com o Visual C++, é necessário implantar versões de depuração das DLLs da biblioteca do Visual C++ das quais o aplicativo depende. Para identificar quais DLLs devem ser implantadas, siga as etapas de [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md). Normalmente, as versões de depuração das DLLs da biblioteca do Visual C++ têm nomes que terminam com "d"; por exemplo, a versão de depuração de msvcr100.dll é chamada msvcr100d.dll.

> [!NOTE]
>  As versões de depuração de um aplicativo não são redistribuíveis, assim como as versões de depuração das DLLs da biblioteca do Visual C++. Você pode implantar versões de depuração de aplicativos e DLLs do Visual C++ apenas em outros computadores, para a única finalidade de depuração e teste dos aplicativos em um computador que não tenha o Visual Studio instalado. Para obter mais informações, consulte [Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md).

Há três maneiras de implantar versões de depuração de DLLs da biblioteca do Visual C++ junto com a versão de depuração de um aplicativo.

- Use a implantação central para instalar uma versão de depuração de uma DLL específica do Visual C++ no diretório %windir%\system32\ usando um projeto de Instalação que inclua módulos de mesclagem para a versão da biblioteca e a arquitetura corretas do aplicativo. Os módulos de mesclagem são encontrados no diretório Arquivos de Programas ou Arquivos de Programas (x86) em \Common Files\Merge Modules\\. A versão de depuração de um módulo de mesclagem tem Depuração no nome, por exemplo, Microsoft_VC110_DebugCRT_x86.msm. Um exemplo dessa implantação pode ser encontrado em [Passo a passo: Implantando um aplicativo em Visual C++ usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).

- Use a implantação local para instalar uma versão de depuração de uma DLL específica do Visual C++ no diretório de instalação do aplicativo usando os arquivos fornecidos no diretório Arquivos de Programas ou Arquivos de Programas (x86) em \Microsoft Visual Studio \<versão>\VC\redist\Debug_NonRedist\\.

    > [!NOTE]
    >  Para depuração remota de seu aplicativo criado usando o Visual Studio 2005 ou Visual Studio 2008 em outro computador, você deve implantar versões de depuração do Visual C++ biblioteca de DLLs como assemblies lado a lado a lado compartilhados. Use um projeto de Instalação ou o Windows Installer para instalar os módulos de mesclagem correspondentes.

- Use a opção _**Deploy** na caixa de diálogo **Configuration Manager** do Visual Studio para copiar a saída do projeto e outros arquivos para o computador remoto.

Após a instalação das DLLs do Visual C++, execute um depurador remoto em um compartilhamento de rede. Para obter mais informações sobre a depuração remota, confira [Depuração remota](/visualstudio/debugger/remote-debugging).

## <a name="see-also"></a>Consulte também

[Implantação no Visual C++](deployment-in-visual-cpp.md)<br>
[Opções de linha de comando do Windows Installer](/windows/desktop/Msi/command-line-options)<br>
[Exemplos de implantação](deployment-examples.md)<br>
[Depuração remota](/visualstudio/debugger/remote-debugging)
