---
title: Usar o conjunto C++ de ferramentas da Microsoft na linha de comando
description: Use a cadeia de ferramentas do compilador do MSVC (Microsoft C++) na linha de comando fora do IDE do Visual Studio.
ms.custom: conceptual
ms.date: 11/12/2019
helpviewer_keywords:
- command-line builds [C++]
- compiling source code [C++], command line
- builds [C++], command-line
- command line [C++], building from
- command line [C++], compilers
ms.assetid: 7ca9daed-a003-4162-842d-908f79058365
ms.openlocfilehash: ec30cba8e119f96efc5bca156fa565db77904520
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051489"
---
# <a name="use-the-microsoft-c-toolset-from-the-command-line"></a>Usar o conjunto C++ de ferramentas da Microsoft na linha de comando

Compile aplicativos C e C++ na linha de comando usando as ferramentas incluídas no Visual Studio. O conjunto C++ de ferramentas de compilador da Microsoft (MSVC) também é baixável como um pacote autônomo que não inclui o IDE do Visual Studio.

## <a name="download-and-install-the-tools"></a>Baixar e instalar as ferramentas

Se você tiver instalado o Visual Studio e C++ uma carga de trabalho, terá todas as ferramentas de linha de comando. Para obter informações sobre como instalar C++ o e o Visual Studio, consulte [instalar C++ o suporte no Visual Studio](vscpp-step-0-installation.md). Se você quiser apenas o conjunto de ferramentas de linha de comando, baixe as [ferramentas de Build para o Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019). Quando você executa o executável baixado, ele atualiza e executa o Instalador do Visual Studio. Para instalar apenas as ferramentas de que você C++ precisa para o desenvolvimento, selecione a carga de trabalho  **C++ ferramentas de compilação** . Você pode selecionar bibliotecas opcionais e conjuntos de ferramentas para incluir nos **detalhes da instalação**. Para compilar o código usando os conjuntos de ferramentas do Visual Studio 2015 ou 2017, selecione as ferramentas de Build MSVC v140 ou MSVC v141 opcionais. Quando estiver satisfeito com suas seleções, escolha **instalar**.

## <a name="how-to-use-the-command-line-tools"></a>Como usar as ferramentas de linha de comando

Quando você escolhe uma das cargas de trabalho do C++ no Instalador do Visual Studio, ele instala o *Conjunto de ferramentas da plataforma* do Visual Studio. Um conjunto de ferramentas de plataforma tem todas C++ as ferramentas C e para uma versão específica do Visual Studio. As ferramentas incluem C/C++ compiladores, vinculadores, montadores e outras ferramentas de compilação e bibliotecas correspondentes. Você pode usar todas essas ferramentas na linha de comando. Eles também são usados internamente pelo IDE do Visual Studio. Há compiladores separados hospedados em x86 e x64 e ferramentas para criar código para destinos x86, x64, ARM e ARM64. Cada conjunto de ferramentas para uma arquitetura específica de build de host e destino é armazenado em seu próprio diretório.

Para que funcionem corretamente, as ferramentas exigem a definição de diversas variáveis de ambiente específicas. Essas variáveis são usadas para adicionar as ferramentas ao caminho e para definir o arquivo de inclusão, o arquivo de biblioteca e os locais do SDK. Para facilitar a definição dessas variáveis de ambiente, o instalador cria *arquivos de comando* personalizados ou arquivos em lotes, durante a instalação. Você pode executar um desses arquivos de comando para definir um host específico e uma arquitetura de compilação de destino, versão SDK do Windows e conjunto de ferramentas de plataforma. Para sua conveniência, o instalador também cria atalhos no menu iniciar. Os atalhos iniciam as janelas de prompt de comando do desenvolvedor usando esses arquivos de comando para combinações específicas de host e destino. Esses atalhos garantem que todas as variáveis de ambiente necessárias estejam definidas e prontas para uso.

As variáveis de ambiente necessárias são específicas para sua instalação e para a arquitetura de compilação que você escolher. Elas também podem ser alteradas por atualizações do produto ou atualizações. É por isso que recomendamos que você use um atalho de prompt de comando instalado ou um arquivo de comando, em vez de definir as variáveis de ambiente por conta própria. Para obter mais informações, consulte [definir o caminho e as variáveis de ambiente para compilações de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md).

Os conjuntos de ferramentas, os arquivos de comando e os atalhos instalados dependem do processador do computador e das opções selecionadas durante a instalação. As ferramentas hospedadas em x86 e as ferramentas cruzadas que criam o código x86 e x64 são sempre instaladas. Se você tiver o Windows de 64 bits, as ferramentas hospedadas em x64 e as ferramentas cruzadas que criam códigos x86 e x64 também serão instaladas. Se você escolher as ferramentas C++ de plataforma universal do Windows opcionais, as ferramentas x86 e x64 que criam o código ARM e ARM64 também serão instaladas. Outras cargas de trabalho podem instalar ferramentas adicionais.

## <a name="developer_command_prompt_shortcuts"></a> Atalhos do Prompt de Comando do Desenvolvedor

Os atalhos do prompt de comando são instalados em uma pasta do Visual Studio específica da versão no menu Iniciar. Esta é uma lista dos atalhos do prompt de comando base e das arquiteturas de build às quais eles dão suporte:

- **Prompt de Comando do Desenvolvedor** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits.
- **Prompt de Comando de Ferramentas Nativas do x86** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits.
- **Prompt de Comando de Ferramentas Nativas do x64** – define o ambiente para uso das ferramentas nativas do x64 de 64 bits para compilar o código nativo do x64 de 64 bits.
- **Prompt de Comando de Ferramentas Cruzadas do x86_x64** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x64 de 64 bits.
- **Prompt de Comando de Ferramentas Cruzadas do x64_x86** – define o ambiente para uso das ferramentas nativas do x64 de 64 bits para compilar o código nativo do x86 de 32 bits.

::: moniker range=">= vs-2019"

Os nomes de atalho e de pasta do menu iniciar variam de acordo com a versão instalada do Visual Studio. Se você definir um, eles também dependem do **apelido**da instalação. Por exemplo, suponha que você instalou o Visual Studio 2019 e deu a ele um apelido do *mais recente*. O atalho do prompt de comando do desenvolvedor é denominado **prompt de comando do desenvolvedor para VS 2019 (mais recente)** , em uma pasta chamada **Visual Studio 2019**.

::: moniker-end
::: moniker range="= vs-2017"

Os nomes de atalho e de pasta do menu iniciar variam de acordo com a versão instalada do Visual Studio. Se você definir um, eles também dependem do **apelido**da instalação. Por exemplo, suponha que você instalou o Visual Studio 2017 e deu a ele um apelido do *mais recente*. O atalho do prompt de comando do desenvolvedor é denominado **prompt de comando do desenvolvedor para VS 2017 (mais recente)** , em uma pasta chamada **Visual Studio 2017**.

::: moniker-end
::: moniker range="< vs-2017"

Os nomes de atalho e de pasta do menu iniciar variam de acordo com a versão instalada do Visual Studio. Por exemplo, suponha que você instalou o Visual Studio 2015. O atalho do prompt de comando do desenvolvedor é denominado **prompt de comando do desenvolvedor para VS 2015**.

::: moniker-end

### <a name="developer_command_prompt"></a> Para abrir uma janela do Prompt de Comando do Desenvolvedor

1. Na área de trabalho, abra o menu **Iniciar** do Windows e, em seguida, role a página para localizar e abrir a pasta da versão do Visual Studio, por exemplo, **Visual Studio 2019**.

1. Na pasta, escolha o **Prompt de Comando do Desenvolvedor** da versão do Visual Studio. Esse atalho inicia uma janela do Prompt de Comando do Desenvolvedor que usa a arquitetura de build padrão das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits. Caso prefira uma arquitetura de build não padrão, escolha um dos prompts de comando de ferramentas nativas ou cruzadas para especificar a arquitetura de host e de destino.

Para uma maneira ainda mais rápida de abrir um prompt de comando do desenvolvedor, digite *prompt de comando do desenvolvedor* na caixa de pesquisa da área de trabalho. Em seguida, escolha o resultado desejado.

## <a name="developer_command_file_locations"></a> Localizações do arquivo de comando do desenvolvedor

Se preferir definir o ambiente de compilação em uma janela de prompt de comando existente, você poderá usar um dos arquivos de comando criados pelo instalador. Recomendamos que você defina o ambiente em uma nova janela de prompt de comando. Não recomendamos que você alterne posteriormente os ambientes na mesma janela de comando.

::: moniker range=">= vs-2019"

O local do arquivo de comando depende da versão do Visual Studio instalada e das escolhas feitas durante a instalação. Para o Visual Studio 2019, o local de instalação típico em um sistema de 64 bits está em \\arquivos de programas (x86)\\Microsoft Visual Studio\\2019\\*Edition*. A *edição* pode ser Community, Professional, Enterprise, BuildTools ou outro apelido que você forneceu.

::: moniker-end
::: moniker range="= vs-2017"

O local do arquivo de comando depende da versão do Visual Studio instalada e das escolhas feitas durante a instalação. Para o Visual Studio 2017, o local de instalação típico em um sistema de 64 bits está em \\arquivos de programas (x86)\\Microsoft Visual Studio\\2017\\*Edition*. A *edição* pode ser Community, Professional, Enterprise, BuildTools ou outro apelido que você forneceu.

::: moniker-end
::: moniker range="< vs-2017"

O local do arquivo de comando depende da versão do Visual Studio e do diretório de instalação. Para o Visual Studio 2015, o local de instalação típico está em \\arquivos de programas (x86)\\Microsoft Visual Studio 14,0.

::: moniker-end

O arquivo de comando do prompt de comando do desenvolvedor primário, VsDevCmd. bat, está localizado no subdiretório ferramentas de\\de Common7. Quando nenhum parâmetro é especificado, ele define o ambiente para usar as ferramentas nativas do x86 para compilar o código x86 de 32 bits.

::: moniker range=">= vs-2017"

Mais arquivos de comando estão disponíveis para configurar arquiteturas de compilação específicas. Os arquivos de comando disponíveis dependem das cargas de trabalho e das opções do Visual Studio instaladas. No Visual Studio 2017 e no Visual Studio 2019, você os encontrará no\\do VC\\auxiliar de compilação.

::: moniker-end
::: moniker range="< vs-2017"

Mais arquivos de comando estão disponíveis para configurar arquiteturas de compilação específicas. Os arquivos de comando disponíveis dependem das cargas de trabalho e das opções do Visual Studio instaladas. No Visual Studio 2015, eles estão localizados nos subdiretórios VC, VC\\bin ou VC\\\\de *arquitetura* , em que a *arquitetura* é uma das opções nativas ou de compilador cruzado.

::: moniker-end

Esses arquivos de comando definem os parâmetros padrão e chamam VsDevCmd.bat para configurar o ambiente da arquitetura de build especificada. Uma instalação típica pode incluir estes arquivos de comando:

|Arquivo de comando|Arquiteturas de host e de destino|
|---|---|
|**vcvars32.bat**| Use as ferramentas nativas do x86 de 32 bits para compilar o código do x86 de 32 bits.|
|**vcvars64.bat**| Use as ferramentas nativas do x64 de 64 bits para compilar o código do x64 de 64 bits.|
|**vcvarsx86_amd64.bat**| Use as ferramentas cruzadas nativas do x86 de 32 bits para compilar o código do x64 de 64 bits.|
|**vcvarsamd64_x86.bat**| Use as ferramentas cruzadas nativas do x64 de 64 bits para compilar o código do x86 de 32 bits.|
|**vcvarsx86_arm.bat**| Use as ferramentas cruzadas nativas do x86 de 32 bits para compilar o código do ARM.|
|**vcvarsamd64_arm.bat**| Use as ferramentas cruzadas nativas do x64 de 64 bits para compilar o código do ARM.|
|**vcvarsall.bat**| Use parâmetros para especificar as arquiteturas de host e de destino, SDK do Windows e opções de plataforma. Para obter uma lista das opções compatíveis, faça uma chamada usando um parâmetro **/help**.|

> [!CAUTION]
> O arquivo vcvarsall.bat e outros arquivos de comando do Visual Studio podem variar conforme o computador. Não substitua um arquivo vcvarsall.bat não encontrado ou danificado usando um arquivo de outro computador. Execute novamente o Instalador do Visual Studio para substituir o arquivo ausente.
>
> O arquivo vcvarsall.bat também varia de uma versão para outra. Se a versão atual do Visual Studio estiver instalada em um computador que também tem uma versão anterior do Visual Studio, não execute vcvarsall.bat nem outro arquivo de comando do Visual Studio de versões diferentes na mesma janela do prompt de comando.

## <a name="use-the-developer-tools-in-an-existing-command-window"></a>Usar as ferramentas para desenvolvedores em uma janela Comando existente

A maneira mais simples de especificar uma arquitetura de build específica em uma janela Comando existente é usar o arquivo vcvarsall.bat. Use vcvarsall. bat para definir variáveis de ambiente para configurar a linha de comando para compilação nativa de 32 bits ou 64 bits. Os argumentos permitem que você especifique os processadores de compilação cruzada para x86, x64, ARM ou ARM64. Você pode direcionar as plataformas de Microsoft Store, Plataforma Universal do Windows ou área de trabalho do Windows. Você pode até mesmo especificar qual SDK do Windows usar e selecionar a versão do conjunto de ferramentas da plataforma.

Quando usado sem argumentos, vcvarsall. bat configura as variáveis de ambiente para usar o compilador atual x86-Native para destinos de área de trabalho do Windows de 32 bits. Você pode adicionar argumentos para configurar o ambiente para usar qualquer uma das ferramentas de compilador nativas ou cruzadas. vcvarsall. bat exibirá uma mensagem de erro se você especificar uma configuração que não está instalada ou disponível no seu computador.

### <a name="vcvarsall-syntax"></a>Sintaxe de vcvarsall

> **vcvarsall.bat** [*architecture*] [*platform_type*] [*winsdk_version*] [ **-vcvars_ver=** _vcversion_]

*architecture*<br/>
Esse argumento opcional especifica a arquitetura de host e de destino a ser usada. Se a *arquitetura* não for especificada, o ambiente de compilação padrão será usado. Há suporte para estes argumentos:

|*architecture*|Compilador|Arquitetura do computador host|Arquitetura da saída do build (destino)|
|----------------------------|--------------|----------------------------------|-------------------------------|
|**x86**|Nativa de 32 bits x86|x86, x64|x86|
|**x86\_amd64** ou **x86\_x64**|Cruzada do x64 no x86|x86, x64|X64|
|**x86_arm**|ARM em x86 cruzado|x86, x64|ARM|
|**x86_arm64**|Cruzada do ARM64 no x86|x86, x64|ARM64|
|**amd64** ou **x64**|Nativa do x64 de 64 bits|X64|X64|
|**amd64\_x86** ou **x64\_x86**|Cruzada do x86 no x64|X64|x86|
|**amd64\_arm** ou **x64\_arm**|Cruzada do ARM no x64|X64|ARM|
|**amd64\_arm64** ou **x64\_arm64**|Cruzada do ARM64 no x64|X64|ARM64|

*platform_type*<br/>
Esse argumento opcional permite especificar **store** ou **uwp** como o tipo de plataforma. Por padrão, o ambiente está definido para compilar aplicativos da área de trabalho ou de console.

*winsdk_version*<br/>
Opcionalmente, especifica a versão do SDK do Windows a ser usada. Por padrão, o SDK do Windows mais recente instalado é usado. Para especificar a versão do SDK do Windows, use um número completo do SDK do Windows 10, como **10.0.10240.0** ou especifique **8.1** para usar o SDK do Windows 8.1.

*vcversion*<br/>
Opcionalmente, especifica o conjunto de ferramentas do compilador do Visual Studio a ser usado. Por padrão, o ambiente está definido para usar o conjunto de ferramentas do compilador do Visual Studio atual.

::: moniker range=">= vs-2019"

Use **-vcvars_ver = 14.2 x. yyyy** para especificar uma versão específica do conjunto de ferramentas do compilador do Visual Studio 2019.

Use **-vcvars_ver = 14.16** para especificar a versão mais recente do conjunto de ferramentas do compilador do Visual Studio 2017.

::: moniker-end
::: moniker range="= vs-2017"

Use **-vcvars_ver = 14.16** para especificar a versão mais recente do conjunto de ferramentas do compilador do Visual Studio 2017.

Use **-vcvars_ver = 14,1 x. yyyy** para especificar uma versão específica do conjunto de ferramentas do compilador do Visual Studio 2017.

::: moniker-end

Use **-vcvars_ver = 14.0** para especificar o conjunto de ferramentas do compilador do Visual Studio 2015.

#### <a name="vcvarsall"></a>Para configurar o ambiente de compilação em uma janela de prompt de comando existente

1. No prompt de comando, use o comando CD para alterar para o diretório de instalação do Visual Studio. Em seguida, use CD novamente para alterar para a subpasta que contém os arquivos de comando específicos da configuração. Para o Visual Studio 2019 e o Visual Studio 2017, use o subdiretório de *Build\\\\auxiliar do vc* . Para o Visual Studio 2015, use o subdiretório *vc* .

1. Insira o comando de seu ambiente de desenvolvedor preferido. Por exemplo, para criar código ARM para UWP em uma plataforma de 64 bits, usando o último SDK do Windows e o conjunto de ferramentas do compilador do Visual Studio, use esta linha de comando:

   `vcvarsall.bat amd64_arm uwp`

## <a name="create-your-own-command-prompt-shortcut"></a>Criar seu próprio atalho do prompt de comando

::: moniker range=">= vs-2019"

Abra a caixa de diálogo Propriedades de um atalho de prompt de comando do desenvolvedor para ver o destino de comando usado. Por exemplo, o destino do atalho do **Prompt de Comando de Ferramentas Nativas do x64 para VS 2019** é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"`

::: moniker-end
::: moniker range="= vs-2017"

Abra a caixa de diálogo Propriedades de um atalho de prompt de comando do desenvolvedor para ver o destino de comando usado. Por exemplo, o destino para o atalho do **prompt de comando de ferramentas nativas do x64 para VS 2017** é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"`

::: moniker-end
::: moniker range="< vs-2017"

Abra a caixa de diálogo Propriedades de um atalho de prompt de comando do desenvolvedor para ver o destino de comando usado. Por exemplo, o destino para o atalho de **prompt de comando de ferramentas nativas do x64 VS2015** é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64`

::: moniker-end

Os arquivos em lotes específicos da arquitetura definem o parâmetro *architecture* e chamam vcvarsall.bat. Você pode passar as mesmas opções para esses arquivos em lotes, como você passaria para vcvarsall. bat, ou pode simplesmente chamar vcvarsall. bat diretamente. Para especificar parâmetros para seu próprio atalho de comando, adicione-os ao final do comando entre aspas duplas. Por exemplo, aqui está um atalho para criar código ARM para UWP em uma plataforma de 64 bits, usando o SDK do Windows mais recente. Para usar um conjunto de ferramentas de compilador anterior, especifique o número de versão. Use algo como este destino de comando no atalho:

::: moniker range=">= vs-2019"

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64_arm uwp -vcvars_ver=14.16`

::: moniker-end
::: moniker range="= vs-2017"

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64_arm uwp -vcvars_ver=14.0`

::: moniker-end
::: moniker range="< vs-2017"

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64 -vcvars_ver=12.0`

::: moniker-end

Ajuste o caminho para refletir o diretório de instalação do Visual Studio. O arquivo vcvarsall.bat traz mais informações sobre os números de versão específicos.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

Para criar um C/C++ Project em um prompt de comando, o Visual Studio fornece essas ferramentas de linha de comando:

[CL](reference/compiling-a-c-cpp-program.md)<br/>
Use o compilador (cl.exe) para compilar e vincular arquivos de código-fonte a aplicativos, bibliotecas e DLLs.

[Link](reference/linking.md)<br/>
Use o vinculador (link.exe) para vincular arquivos de objetos compilados e bibliotecas a aplicativos e DLLs.

[MSBuild](msbuild-visual-cpp.md)<br/>
Use o MSBuild (msbuild.exe) e um arquivo de projeto (.vcxproj) para configurar um build e invocar o conjunto de ferramentas indiretamente. É equivalente a executar o comando **Compilar** projeto ou **COMPILAR solução** no IDE do Visual Studio. A execução do MSBuild na linha de comando é um cenário avançado e não é normalmente recomendado.

[DEVENV](/visualstudio/ide/reference/devenv-command-line-switches)<br/>
Use DEVENV (devenv. exe) combinado com uma opção de linha de comando, como **/Build** ou **/Clean** , para executar determinados comandos de compilação sem exibir o IDE do Visual Studio. Em geral, o DEVENV é preferido usando o MSBuild diretamente, pois você pode deixar o Visual Studio lidar com as complexidades do MSBuild.

[NMAKE](reference/nmake-reference.md)<br/>
Use o NMAKE (nmake.exe) no Windows para compilar projetos C++ baseados em um makefile tradicional.

Quando você cria na linha de comando, o comando F1 não está disponível para ajuda instantânea. Em vez disso, use um mecanismo de pesquisa para obter informações sobre avisos, erros e mensagens ou use os arquivos da Ajuda offline. Para usar a pesquisa no [docs.Microsoft.com](https://docs.microsoft.com/cpp/), use a caixa de pesquisa na parte superior da página.

## <a name="in-this-section"></a>Nesta seção

Estes artigos mostram como criar aplicativos na linha de comando e descrevem como personalizar o ambiente de compilação de linha de comando. Alguns mostram como usar os conjuntos de ferramentas de 64 bits e as plataformas x86, x64, ARM e ARM64 de destino. Eles também descrevem o uso das ferramentas de Build de linha de comando MSBuild e NMAKE.

[Walkthrough: Compilando um C++ programa nativo na linha de comando](walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)<br/>
Fornece um exemplo que mostra como criar e compilar um C++ programa na linha de comando.

[Instruções passo a passo: compilar um programa em C na linha de comando](walkthrough-compile-a-c-program-on-the-command-line.md)<br/>
Descreve como compilar um programa gravado na linguagem de programação C.

[Walkthrough: Compilando C++um programa/CLI na linha de comando](walkthrough-compiling-a-cpp-cli-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CLI que usa o .NET Framework.

[Walkthrough: Compilando C++um programa/CX na linha de comando](walkthrough-compiling-a-cpp-cx-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CX que usa o Windows Runtime.

[Definir o caminho e as variáveis de ambiente para compilações de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md)<br/>
Como definir variáveis de ambiente para usar um conjunto de ferramentas de 32 bits ou 64 bits para direcionar plataformas x86, x64, ARM e ARM64.

[Referência a NMAKE](reference/nmake-reference.md)<br/>
Fornece links a artigos que descrevem o Microsoft Program Maintenance Utility (NMAKE.EXE).

[MSBuild na linha de comando – C++](msbuild-visual-cpp.md)<br/>
Fornece links para artigos que explicam como usar o msbuild.exe na linha de comando.

## <a name="related-sections"></a>Seções relacionadas

[/MD,/MT,/LD (use a biblioteca de tempo de execução)](reference/md-mt-ld-use-run-time-library.md)<br/>
Descreve como usar essas opções do compilador para usar uma biblioteca de tempo de execução de depuração ou versão.

[Opções deC++ compilador/C](reference/compiler-options.md)<br/>
Fornece links a artigos que falam sobre as opções de compilador da linguagem C e C++ e sobre o CL.exe.

[Opções do vinculador MSVC](reference/linker-options.md)<br/>
Fornece links a artigos que falam sobre as opções do vinculador e sobre o LINK.exe.

[Ferramentas de compilação adicionais MSVC](reference/c-cpp-build-tools.md)<br/>
Fornece links para as ferramentas de build do C/C++ incluídas no Visual Studio.

## <a name="see-also"></a>Consulte também

[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)
