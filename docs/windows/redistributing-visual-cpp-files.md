---
title: Redistribuindo arquivos do Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- application deployment [C++], file redistributing
- redistributing applications [C++]
- deploying applications [C++], file redistributing
- file redistribution [C++]
- redistributing applications [C++], about redistributing applications
ms.assetid: d201b2ce-36f1-44e5-a96c-0db81a1ba652
ms.openlocfilehash: 2bf4297a6c61d16c68d6a9cb893aed78b9d7609d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62388157"
---
# <a name="redistributing-visual-c-files"></a>Redistribuindo arquivos do Visual C++

> [!NOTE]
> Você está aqui porque procura um download de um dos arquivos do Tempo de Execução do Visual C++? Vá para o [site da Microsoft](http://www.microsoft.com/) e insira **Visual C++ redistribuível** na caixa de pesquisa. Baixe e instale o pacote redistribuível para a arquitetura de seu computador (por exemplo, x64 se estiver executando o Windows de 64 bits) e a versão do Visual C++ (por exemplo, 2015) necessária.

Ao implantar um aplicativo, você também deve implantar os arquivos que são necessários para o suporte. Se qualquer um desses arquivos for fornecido pela Microsoft, verifique se você tem permissão para redistribuí-lo. Para examinar os termos de licença do Visual Studio, confira o link dos Termos de licença na caixa de diálogo Sobre o Microsoft Visual Studio no IDE ou baixe o arquivo [Termos de Licença para Software Microsoft](https://visualstudio.microsoft.com/license-terms/mlt687465/). Para exibir a "lista REDIST" referenciada na seção "Código distribuível" dos Termos de Licença para Software Microsoft para algumas edições do Visual Studio, confira [Código distribuível para o Microsoft Visual Studio 2017 e o SDK do Microsoft Visual Studio 2017 (inclui utilitários e arquivos do BuildServer)](/visualstudio/productinfo/2017-redistribution-vs), ou, para o Visual Studio 2015, confira [Código distribuível para o Microsoft Visual Studio 2015 e o SDK do Microsoft Visual Studio 2015](/visualstudio/productinfo/2015-redistribution-vs). Para obter mais informações sobre arquivos redistribuíveis, confira [Determinando quais DLLs devem ser redistribuídas](determining-which-dlls-to-redistribute.md) e [Exemplos de implantação](deployment-examples.md).

Para implantar arquivos redistribuíveis do Visual C++, use os Pacotes Redistribuíveis do Visual C++ (VCRedist\_x86.exe, VCRedist\_x64.exe ou VCRedist\_arm.exe) incluídos no Visual Studio. No Visual Studio 2017, esses arquivos podem ser encontrados na pasta Arquivos de Programas [(x86)]\\Microsoft Visual Studio\\2017\\_edition_\\VC\\Redist\\MSVC\\_lib-version_, em que _edition_ é a edição instalada do Visual Studio e _lib-version_ é a versão das bibliotecas a serem redistribuídas. No Visual Studio 2015, esses arquivos podem ser encontrados no diretório de instalação do Visual Studio em Arquivos de Programas [(x86)]\Microsoft Visual Studio *versão*\VC\redist\\*locale*\\. Outra opção é usar módulos de mesclagem redistribuíveis (arquivos .msm), que, no Visual Studio 2017, podem ser encontrados na pasta Arquivos de Programas [(x86)] \\Microsoft Visual Studio\\2017\\_edition_\\VC\\Redist\\MSVC\\_lib-version_\\MergeModules\\. No Visual Studio 2015, eles podem ser encontrados em Arquivos de Programas [(x86)] \Common Files\Merge Modules\\. Também é possível instalar as DLLs redistribuíveis do Visual C++ diretamente na *pasta local do aplicativo*, que é a pasta que contém o arquivo de aplicativo executável. Por motivos de manutenção, não recomendamos o uso desse local de instalação.

Os pacotes redistribuíveis do Visual C++ instalam e registram todas as bibliotecas do Visual C++. Se você usar uma, deverá defini-la para ser executada no sistema de destino como pré-requisito para a instalação de seu aplicativo. Recomendamos que você use esses pacotes para suas implantações, pois permitem a atualização automática das bibliotecas do Visual C++. Para obter um exemplo sobre como usar esses pacotes, consulte [passo a passo: Implantação de um aplicativo em Visual C++ usando o Pacote Redistribuível do Visual C++](deploying-visual-cpp-application-by-using-the-vcpp-redistributable-package.md).

Cada Pacote Redistribuível do Visual C++ verifica a existência de uma versão mais recente no computador. Se uma versão mais recente é encontrada, o pacote não é instalado. Do Visual Studio 2015 em diante, os pacotes redistribuíveis exibem uma mensagem de erro informando que a instalação falhou. Se um pacote é executado usando o sinalizador **/quiet**, nenhuma mensagem de erro é exibida. Em ambos os casos, um erro é registrado em log pelo Microsoft Installer e um resultado do erro é retornado ao chamador. Começando pelos pacotes do Visual Studio 2015, você pode evitar esse erro verificando o Registro para descobrir se há uma versão mais recente instalada. A versão atualmente instalada é armazenada na chave HKEY_LOCAL_MACHINE\SOFTWARE[\Wow6432Node]\Microsoft\VisualStudio\\_vs-version_\VC\Runtimes\\{x86|x64|ARM}, em que _vs-version_ é o número de versão do Visual Studio (14.0 para o Visual Studio 2015 e o Visual Studio 2017, porque o pacote redistribuível atualizado da versão 2017 é um binário compatível com a versão 2015) e em que a chave é ARM, x86 ou x64, dependendo das versões de vcredist instaladas para a plataforma. (Você não precisa verificar a subchave Wow6432Node, a menos que esteja usando o RegEdit para exibir a versão do pacote x86 instalado em uma plataforma x64.) O número de versão é armazenado no valor de cadeia de caracteres **Version** de REG_SZ e também no conjunto de valores **Major**, **Minor**, **Bld** e **Rbld** de REG_DWORD. Para evitar um erro no momento da instalação, ignore a instalação do pacote redistribuível se a versão atualmente instalada for mais recente.

Se você usar um módulo de mesclagem que contém uma DLL do Visual C++, inclua-o no pacote do Windows Installer (ou em um pacote de instalação semelhante) que você está usando para implantar o aplicativo. Para obter mais informações, confira [Redistribuindo componentes usando módulos de mesclagem](redistributing-components-by-using-merge-modules.md). Para obter um exemplo, confira [Passo a passo: Implantar um Visual C++ aplicativo pelo usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md), que também mostra como usar o InstallShield Limited Edition para criar um pacote de instalação.

## <a name="potential-run-time-errors"></a>Prováveis erros no tempo de execução

Se o Windows não conseguir localizar uma biblioteca do redistribuível DLLs necessárias para seu aplicativo, pode ser exibida uma mensagem semelhante a esta: "Este aplicativo falhou ao iniciar porque *biblioteca*. dll não foi encontrado. A reinstalação do aplicativo pode corrigir este problema."

Para resolver esse tipo de erro, verifique se o instalador do aplicativo é compilado corretamente e se as bibliotecas redistribuíveis são implantadas corretamente no sistema de destino. Para obter mais informações, confira [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md).

## <a name="related-topics"></a>Tópicos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Redistribuindo componentes usando módulos de mesclagem](redistributing-components-by-using-merge-modules.md)|Descreve como usar os módulos de mesclagem redistribuíveis do Visual C++ para instalar as bibliotecas de tempo de execução do Visual C++ como DLLs compartilhadas na pasta %windir%\system32\.|
|[Redistribuindo controles ActiveX do Visual C++](redistributing-visual-cpp-activex-controls.md)|Descreve como redistribuir um aplicativo que usa controles do ActiveX.|
|[Redistribuindo a biblioteca do MFC](redistributing-the-mfc-library.md)|Descreve como redistribuir um aplicativo que usa MFC.|
|[Redistribuindo um aplicativo ATL](redistributing-an-atl-application.md)|Descreve como redistribuir um aplicativo que usa a ATL. Do Visual Studio 2012 em diante, nenhuma biblioteca redistribuível para ATL é necessária.|
|[Exemplos de implantação](deployment-examples.md)|Links para exemplos que demonstram como implantar aplicativos do Visual C++.|
|[Implantando aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md)|Apresenta conceitos e tecnologias de implantação do Visual C++.|