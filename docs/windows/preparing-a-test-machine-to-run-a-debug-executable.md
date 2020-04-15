---
title: Preparando uma máquina de teste para executar um executável de depuração
ms.date: 07/02/2019
helpviewer_keywords:
- debug executable, preparing a test machine to run
ms.assetid: f0400989-cc2e-4dce-9788-6bdbe91c6f5a
ms.openlocfilehash: 26a92d5efc4bf9f0332a0e81fa2f9c8b2c2a958f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359915"
---
# <a name="preparing-a-test-machine-to-run-a-debug-executable"></a>Preparando uma máquina de teste para executar um executável de depuração

Para preparar um computador para testar a versão de depuração de um aplicativo compilado com o Visual C++, é necessário implantar versões de depuração das DLLs da biblioteca do Visual C++ das quais o aplicativo depende. Para identificar quais DLLs devem ser implantadas, siga as etapas de [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md). Normalmente, as versões de depuração das DLLs da biblioteca do Visual C++ têm nomes que terminam com "d"; por exemplo, a versão de depuração de msvcr100.dll é chamada msvcr100d.dll.

> [!NOTE]
> As versões de depuração de um aplicativo não são redistribuíveis, assim como as versões de depuração das DLLs da biblioteca do Visual C++. Você pode implantar versões de depuração de aplicativos e DLLs do Visual C++ apenas em outros computadores, para a única finalidade de depuração e teste dos aplicativos em um computador que não tenha o Visual Studio instalado. Para obter mais informações, consulte [Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md).

Há três maneiras de implantar versões de depuração de DLLs da biblioteca do Visual C++ junto com a versão de depuração de um aplicativo.

- Use a implantação central para instalar uma versão de depuração de uma DLL específica do Visual C++ no diretório %windir%\system32\ usando um projeto de Instalação que inclua módulos de mesclagem para a versão da biblioteca e a arquitetura corretas do aplicativo. Os módulos de mesclagem são encontrados no diretório Arquivos de Programas ou Arquivos de Programas (x86) em \Common Files\Merge Modules\\. A versão de depuração de um módulo de mesclagem tem Depuração no nome, por exemplo, Microsoft_VC110_DebugCRT_x86.msm. Um exemplo dessa implantação pode ser encontrado no [Passo a passo: Implantando um aplicativo do Visual C++ usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).

- Use a implantação local para instalar uma versão de depuração de um DLL Visual C++ específico no diretório de instalação do aplicativo usando arquivos \<fornecidos no diretório Arquivos\\de Programa ou Arquivos de Programa (x86) em \Microsoft Visual Studio versão>\VC\redist\Debug_NonRedist .

    > [!NOTE]
    >  Para depuração remota do seu aplicativo construído usando o Visual Studio 2005 ou o Visual Studio 2008 em outro computador, você tem que implantar versões de depuração de DLLs da biblioteca Visual C++ como conjuntos compartilhados lado a lado. Use um projeto de Instalação ou o Windows Installer para instalar os módulos de mesclagem correspondentes.

- Use a opção _**Deploy** na caixa de diálogo **Configuration Manager** do Visual Studio para copiar a saída do projeto e outros arquivos para o computador remoto.

Após a instalação das DLLs do Visual C++, execute um depurador remoto em um compartilhamento de rede. Para obter mais informações sobre a depuração remota, confira [Depuração remota](/visualstudio/debugger/remote-debugging).

## <a name="see-also"></a>Confira também

[Implantação no Visual C++](deployment-in-visual-cpp.md)<br>
[Opções de Linha de comando do Windows Installer](/windows/win32/Msi/command-line-options)<br>
[Exemplos de implantação](deployment-examples.md)<br>
[Depuração remota](/visualstudio/debugger/remote-debugging)
