---
title: Redistribuindo arquivos do Visual C++
description: O Visual Studio inclui bibliotecas e componentes redistribuíveis que você pode implantar com seu aplicativo.
ms.date: 07/16/2020
helpviewer_keywords:
- application deployment [C++], file redistributing
- redistributing applications [C++]
- deploying applications [C++], file redistributing
- file redistribution [C++]
- redistributing applications [C++], about redistributing applications
ms.assetid: d201b2ce-36f1-44e5-a96c-0db81a1ba652
ms.openlocfilehash: 7a639f7ad7deb76cade47b0162012dcb70cb0d69
ms.sourcegitcommit: e15b46ea7888dbdd7e0bb47da76aeed680c3c1f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/17/2020
ms.locfileid: "86446747"
---
# <a name="redistributing-visual-c-files"></a>Redistribuindo arquivos do Visual C++

> [!NOTE]
> Você está aqui porque está procurando um download de um dos arquivos de tempo de execução Visual C++? Acesse o [site da Microsoft](https://www.microsoft.com/) e insira **Visual C++ redistribuível** na caixa de pesquisa. Baixe e instale o pacote redistribuível para a arquitetura de seu computador (por exemplo, x64 se estiver executando o Windows de 64 bits) e a versão do Visual C++ (por exemplo, 2015) necessária.

## <a name="redistributable-files-and-licensing"></a>Arquivos redistribuíveis e licenciamento

Ao implantar um aplicativo, você também deve implantar os arquivos que são necessários para o suporte. Se qualquer um desses arquivos for fornecido pela Microsoft, verifique se você tem permissão para redistribuí-los. Você encontrará um link para os termos de licença do Visual Studio no IDE. Use o link termos de licença na caixa de diálogo sobre o Microsoft Visual Studio. Ou então, baixe os EULAs e as licenças relevantes do [diretório de licenças](https://visualstudio.microsoft.com/license-terms/)do Visual Studio.

::: moniker range="vs-2019"

Para exibir a "lista redist" mencionada na seção "código distribuível" dos termos de licença para software Microsoft do Visual Studio 2019, consulte [arquivos de código distribuível para Microsoft Visual Studio 2019](/visualstudio/releases/2019/redistribution#-distributable-code-files-for-visual-studio-2019)

::: moniker-end

::: moniker range="vs-2017"

Para exibir a "lista redist" mencionada na seção "código distribuível" dos termos de licença para software Microsoft do Visual Studio 2017, consulte [arquivos de código distribuível para Microsoft Visual Studio 2017](/visualstudio/productinfo/2017-redistribution-vs#-distributable-code-files-for-visual-studio-2017).

::: moniker-end

::: moniker range="vs-2015"

Para exibir a "lista redist" mencionada na seção "código distribuível" dos termos de licença para software Microsoft do Visual Studio 2015, consulte [arquivos de código distribuível para Microsoft Visual Studio 2015](/visualstudio/productinfo/2015-redistribution-vs#-distributable-code-files-for-visual-studio-2015).

::: moniker-end

Para obter mais informações sobre arquivos redistribuíveis, consulte [determinando quais DLLs redistribuir](determining-which-dlls-to-redistribute.md) e [exemplos de implantação](deployment-examples.md).

## <a name="locate-the-redistributable-files"></a>Localize os arquivos redistribuíveis

Para implantar arquivos redistribuíveis, você pode usar os pacotes redistribuíveis instalados pelo Visual Studio. Em versões do Visual Studio desde 2017, esses arquivos são nomeados *`vc_redist.arm64.exe`* , *`vc_redist.x64.exe`* e *`vc_redist.x86.exe`* . No Visual Studio 2015, no Visual Studio 2017 e no Visual Studio 2019, eles também estão disponíveis com os nomes *`vcredist_x86.exe`* , *`vcredist_x64.exe`* e *`vcredist_arm.exe`* (somente 2015).

A maneira mais fácil de localizar os arquivos redistribuíveis é usando variáveis de ambiente definidas em um prompt de comando do desenvolvedor. Na versão mais recente do Visual Studio 2019, você encontrará os arquivos redistribuíveis na *`%VCINSTALLDIR%Redist\MSVC\v142`* pasta. No Visual Studio 2017 e no Visual Studio 2019, eles também são encontrados no *`%VCToolsRedistDir%`* . No Visual Studio 2015, esses arquivos podem ser encontrados em *`%VCINSTALLDIR%redist\<locale>`* , onde *`<locale>`* é a localidade dos pacotes redistribuíveis.

Outra opção de implantação é usar os módulos de mesclagem redistribuível ( *`.msm`* arquivos). No Visual Studio 2019, esses arquivos fazem parte de um componente instalável opcional chamado **C++ 2019 redistribuível MSMs** no instalador do Visual Studio. Os módulos de mesclagem são instalados por padrão como parte de uma instalação do C++ no Visual Studio 2017 e no Visual Studio 2015. Quando instalado na versão mais recente do Visual Studio 2019, você encontrará os módulos de mesclagem redistribuíveis no *`%VCINSTALLDIR%Redist\MSVC\v142\MergeModules`* . No Visual Studio 2019 e no Visual Studio 2017, eles também são encontrados no *`%VCToolsRedistDir%MergeModules`* . No Visual Studio 2015, eles são encontrados em *`Program Files [(x86)]\Common Files\Merge Modules`* .

## <a name="install-the-redistributable-packages"></a>Instalar os pacotes redistribuíveis

Os pacotes redistribuíveis do Visual C++ instalam e registram todas as bibliotecas do Visual C++. Se você usar um, execute-o como um pré-requisito no sistema de destino antes de instalar seu aplicativo. Recomendamos que você use esses pacotes para suas implantações, pois permitem a atualização automática das bibliotecas do Visual C++. Para obter um exemplo de como usar esses pacotes, confira [Passo a passo: Implantando um aplicativo do Visual C++ usando o Pacote Redistribuível do Visual C++](deploying-visual-cpp-application-by-using-the-vcpp-redistributable-package.md).

Cada Pacote Redistribuível do Visual C++ verifica a existência de uma versão mais recente no computador. Se uma versão mais recente for encontrada, o pacote não será instalado. Do Visual Studio 2015 em diante, os pacotes redistribuíveis exibem uma mensagem de erro informando que a instalação falhou. Se um pacote for executado usando o **`/quiet`** sinalizador, nenhuma mensagem de erro será exibida. Em ambos os casos, um erro é registrado em log pelo Microsoft Installer e um resultado do erro é retornado ao chamador. Começando pelos pacotes do Visual Studio 2015, você pode evitar esse erro verificando o Registro para descobrir se há uma versão mais recente instalada. O número de versão instalado atualmente é armazenado na `HKEY_LOCAL_MACHINE\SOFTWARE[\Wow6432Node]\Microsoft\VisualStudio\14.0\VC\Runtimes\{x86|x64|ARM}` chave. O número de versão é 14,0 para o Visual Studio 2015, o Visual Studio 2017 e o Visual Studio 2019 porque os redistribuíveis mais recentes são binários compatíveis com a versão 2015. A chave é `ARM` , `x86` ou `x64` dependendo das versões do VCRedist instaladas para a plataforma. (Você só precisará verificar a `Wow6432Node` subchave se estiver usando o regedit para exibir a versão do pacote x86 instalado em uma plataforma x64.) O número de versão é armazenado no valor da cadeia de caracteres REG_SZ **`Version`** e também no conjunto de **`Major`** **`Minor`** valores,, e **`Bld`** **`Rbld`** `REG_DWORD` . Para evitar um erro no momento da instalação, ignore a instalação do pacote redistribuível se a versão atualmente instalada for mais recente.

## <a name="install-the-redistributable-merge-modules"></a>Instalar os módulos de mesclagem redistribuível

Os módulos de mesclagem redistribuíveis devem ser incluídos no pacote de Windows Installer (ou em um pacote de instalação semelhante) que você usa para implantar seu aplicativo. Para obter mais informações, confira [Redistribuindo componentes usando módulos de mesclagem](redistributing-components-by-using-merge-modules.md). Para obter um exemplo [, consulte Passo a passos: Implantando um aplicativo Visual C++ usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).

## <a name="install-individual-redistributable-files"></a>Instalar arquivos redistribuíveis individuais

Também é possível instalar diretamente as DLLs redistribuíveis na *pasta local do aplicativo*. Essa é a pasta que contém o arquivo de aplicativo executável. Por motivos de manutenção, não recomendamos que você use esse local de instalação.

## <a name="potential-run-time-errors"></a>Possíveis erros de tempo de execução

Se o Windows não conseguir encontrar uma das DLLs de biblioteca redistribuível exigidas pelo seu aplicativo, ele poderá exibir uma mensagem semelhante a: "este aplicativo falhou ao iniciar porque a *biblioteca*. dll não foi encontrada. A reinstalação do aplicativo pode corrigir esse problema. "

Para resolver esse tipo de erro, verifique se o instalador do aplicativo foi criado corretamente. Verifique se as bibliotecas redistribuíveis são implantadas corretamente no sistema de destino. Para obter mais informações, confira [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md).

## <a name="related-articles"></a>Artigos relacionados

[Redistribuindo usando módulos de mesclagem](redistributing-components-by-using-merge-modules.md)\
Descreve como usar Visual C++ módulos de mesclagem redistribuíveis para instalar as bibliotecas de Visual C++ em tempo de execução como DLLs compartilhadas na *`%windir%\system32\`* pasta.

[Redistribuindo Visual C++ controles ActiveX](redistributing-visual-cpp-activex-controls.md)\
Descreve como redistribuir um aplicativo que usa controles do ActiveX.

[Redistribuindo a biblioteca do MFC](redistributing-the-mfc-library.md)\
Descreve como redistribuir um aplicativo que usa MFC.

[Redistribuindo um aplicativo ATL](redistributing-an-atl-application.md)\
Descreve como redistribuir um aplicativo que usa a ATL. Do Visual Studio 2012 em diante, nenhuma biblioteca redistribuível para ATL é necessária.

[Exemplos de implantação](deployment-examples.md)\
Links para exemplos que demonstram como implantar aplicativos do Visual C++.

[Implantando aplicativos de área de trabalho](deploying-native-desktop-applications-visual-cpp.md)\
Apresenta conceitos e tecnologias de implantação do Visual C++.
