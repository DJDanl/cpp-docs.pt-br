---
title: Usar o Microsoft C++ conjunto de ferramentas da linha de comando
description: Use a cadeia de ferramentas do compilador do MSVC (Microsoft C++) na linha de comando fora do IDE do Visual Studio.
ms.custom: conceptual
ms.date: 06/06/2019
helpviewer_keywords:
- command-line builds [C++]
- compiling source code [C++], command line
- builds [C++], command-line
- command line [C++], building from
- command line [C++], compilers
ms.assetid: 7ca9daed-a003-4162-842d-908f79058365
ms.openlocfilehash: b5e9bf266d79ee86cae84535641a52c7c52be391
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821143"
---
# <a name="use-the-microsoft-c-toolset-from-the-command-line"></a>Usar o Microsoft C++ conjunto de ferramentas da linha de comando

Compile aplicativos C e C++ na linha de comando usando as ferramentas incluídas no Visual Studio. O Microsoft C++ conjunto de ferramentas do compilador (MSVC) também está disponível para download como um pacote autônomo do [downloads do Visual Studio](https://visualstudio.microsoft.com/downloads/) página. Parte do **ferramentas de Build para o Visual Studio** pacote. Você pode optar por baixar somente as ferramentas necessárias para C++ desenvolvimento.

## <a name="how-to-use-the-command-line-tools"></a>Como usar as ferramentas de linha de comando

Quando você escolhe uma das cargas de trabalho do C++ no Instalador do Visual Studio, ele instala o *Conjunto de ferramentas da plataforma* do Visual Studio. Um conjunto de ferramentas de plataforma tem todas as C e C++ ferramentas para uma versão específica do Visual Studio. As ferramentas incluem o C /C++ compiladores, vinculadores, montadores e outras ferramentas de build e bibliotecas de correspondência. Você pode usar todas essas ferramentas na linha de comando. Eles também são usados internamente pelo IDE do Visual Studio. Há separados compiladores hospedados em x86 e x64 hospedados e ferramentas para criar código para x86, x64, ARM e ARM64 destinos. Cada conjunto de ferramentas para uma arquitetura específica de build de host e destino é armazenado em seu próprio diretório.

Para que funcionem corretamente, as ferramentas exigem a definição de diversas variáveis de ambiente específicas. Essas variáveis são usadas para adicionar as ferramentas para o caminho e para definir incluem o arquivo, o arquivo de biblioteca e locais de SDK. Para facilitar a definição dessas variáveis de ambiente, o instalador cria *arquivos de comando* personalizados ou arquivos em lotes, durante a instalação. Você pode executar um desses arquivos de comando para definir um host específico e arquitetura de compilação de destino, versão do SDK do Windows e o conjunto de ferramentas da plataforma. Para sua conveniência, o instalador também cria atalhos no menu Iniciar. Os atalhos de iniciar as janelas de prompt de comando do desenvolvedor usando esses arquivos de comando para combinações específicas de host e de destino. Esses atalhos Verifique se que todas as variáveis de ambiente necessárias são definidos e prontos para uso.

As variáveis de ambiente necessárias são específicas para sua instalação e a arquitetura de compilação que você escolher. Elas também podem ser alteradas por atualizações do produto. É por isso que recomendamos que você use um arquivo de atalho ou comando instalado prompt de comando, em vez de definir as variáveis de ambiente por conta própria. Para obter mais informações, consulte [definir as caminho e variáveis de ambiente para compilações de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md).

Os conjuntos de ferramentas, arquivos de comando e atalhos instalados dependem o processador do computador e as opções selecionadas durante a instalação. As ferramentas hospedados em x86 e cruzada que compilar código x86 e x64 são sempre instalados. Se você tiver o Windows de 64 bits, as ferramentas hospedadas em x64 e cruzadas que compilar código x86 e x64 também são instalados. Se você escolher opcional C++ ferramentas da plataforma Universal do Windows e, em seguida, as ferramentas de x86 e x64 que compilar código ARM e ARM64 também instalado. Outras cargas de trabalho podem instalar ferramentas adicionais.

## <a name="developer_command_prompt_shortcuts"></a> Atalhos do Prompt de Comando do Desenvolvedor

Os atalhos do prompt de comando são instalados em uma pasta do Visual Studio específica da versão no menu Iniciar. Esta é uma lista dos atalhos do prompt de comando base e das arquiteturas de build às quais eles dão suporte:

- **Prompt de Comando do Desenvolvedor** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits.
- **Prompt de Comando de Ferramentas Nativas do x86** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits.
- **Prompt de Comando de Ferramentas Nativas do x64** – define o ambiente para uso das ferramentas nativas do x64 de 64 bits para compilar o código nativo do x64 de 64 bits.
- **Prompt de Comando de Ferramentas Cruzadas do x86_x64** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x64 de 64 bits.
- **Prompt de Comando de Ferramentas Cruzadas do x64_x86** – define o ambiente para uso das ferramentas nativas do x64 de 64 bits para compilar o código nativo do x86 de 32 bits.

::: moniker range=">= vs-2019"

Os nomes de pasta e o atalho de menu Iniciar variam dependendo da versão instalada do Visual Studio. Se você definir uma, eles também dependem da instalação **apelido**. Por exemplo, suponha que você instalou o Visual Studio de 2019, e você deu a ele um apelido de *mais recente*. O atalho de prompt de comando do desenvolvedor é denominado **Prompt de comando do desenvolvedor para VS (mais recente) de 2019**, em uma pasta chamada **2019 do Visual Studio**.

::: moniker-end
::: moniker range="= vs-2017"

Os nomes de pasta e o atalho de menu Iniciar variam dependendo da versão instalada do Visual Studio. Se você definir uma, eles também dependem da instalação **apelido**. Por exemplo, suponha que você instalou o Visual Studio 2017 e você deu a ele um apelido de *mais recente*. O atalho de prompt de comando do desenvolvedor é denominado **Prompt de comando do desenvolvedor para VS 2017 (mais recente)** , em uma pasta chamada **Visual Studio 2017**.

::: moniker-end
::: moniker range="< vs-2017"

Os nomes de pasta e o atalho de menu Iniciar variam dependendo da versão instalada do Visual Studio. Por exemplo, suponha que você instalou o Visual Studio 2015. O atalho de prompt de comando do desenvolvedor é denominado **Prompt de comando do desenvolvedor para VS 2015**.

::: moniker-end

## <a name="developer_command_prompt"></a> Para abrir uma janela do Prompt de Comando do Desenvolvedor

1. Na área de trabalho, abra o menu **Iniciar** do Windows e, em seguida, role a página para localizar e abrir a pasta da versão do Visual Studio, por exemplo, **Visual Studio 2019**.

1. Na pasta, escolha o **Prompt de Comando do Desenvolvedor** da versão do Visual Studio. Esse atalho inicia uma janela do Prompt de Comando do Desenvolvedor que usa a arquitetura de build padrão das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits. Caso prefira uma arquitetura de build não padrão, escolha um dos prompts de comando de ferramentas nativas ou cruzadas para especificar a arquitetura de host e de destino.

Para uma maneira ainda mais rápida abrir um prompt de comando do desenvolvedor, insira *prompt de comando do desenvolvedor* na caixa de pesquisa da área de trabalho. Em seguida, escolha o resultado desejado.

## <a name="developer_command_file_locations"></a> Localizações do arquivo de comando do desenvolvedor

Se você preferir configurar o ambiente de build em uma janela de prompt de comando existente, você pode usar um dos arquivos de comando criados pelo instalador. É recomendável que você defina o ambiente em uma nova janela de prompt de comando. Não recomendamos que você altere os ambientes mais adiante na mesma janela de comando.

::: moniker range=">= vs-2019"

O local do arquivo de comando depende na versão do Visual Studio que você instalou e escolhas feitas durante a instalação. Para o Visual Studio de 2019, o local de instalação típica em um sistema de 64 bits está na \\arquivos de programas (x86)\\Microsoft Visual Studio\\2019\\*edition*. *Edição* pode ser Community, Professional, Enterprise, BuildTools ou outro apelido que você forneceu.

::: moniker-end
::: moniker range="= vs-2017"

O local do arquivo de comando depende na versão do Visual Studio que você instalou e escolhas feitas durante a instalação. Para Visual Studio 2017, o local de instalação típica em um sistema de 64 bits está na \\arquivos de programas (x86)\\Microsoft Visual Studio\\2017\\*edition*. *Edição* pode ser Community, Professional, Enterprise, BuildTools ou outro apelido que você forneceu.

::: moniker-end
::: moniker range="< vs-2017"

O local do arquivo de comando depende da versão do Visual Studio e o diretório de instalação. Para Visual Studio 2015, o local de instalação típica está na \\arquivos de programas (x86)\\14.0 do Microsoft Visual Studio.

::: moniker-end

O arquivo de comando de prompt de comando do desenvolvedor principal, vsdevcmd. bat, está localizado no Common7\\subdiretório ferramentas. Quando nenhum parâmetro for especificado, ele define o ambiente para usar as ferramentas nativas de x86 para x86 de 32 bits de compilar código.

::: moniker range=">= vs-2017"

Mais arquivos de comando estão disponíveis para definir arquiteturas de compilação específica. Os arquivos de comando disponíveis dependem de cargas de trabalho do Visual Studio e as opções que você instalou. No Visual Studio 2017 e Visual Studio de 2019, você encontrará no VC\\auxiliar\\criar subdiretório.

::: moniker-end
::: moniker range="< vs-2017"

Mais arquivos de comando estão disponíveis para definir arquiteturas de compilação específica. Os arquivos de comando disponíveis dependem de cargas de trabalho do Visual Studio e as opções que você instalou. No Visual Studio 2015, eles estão localizados no VC, VC\\bin ou VC\\bin\\*arquitetura* subdiretórios, onde *arquitetura* é um dos nativo ou Opções do compilador cruzado.

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
|**vcvarsall.bat**| Use parâmetros para especificar opções de plataforma, SDK do Windows e arquiteturas de host e de destino. Para obter uma lista das opções compatíveis, faça uma chamada usando um parâmetro **/help**.|

> [!CAUTION]
> O arquivo vcvarsall.bat e outros arquivos de comando do Visual Studio podem variar conforme o computador. Não substitua um arquivo vcvarsall.bat não encontrado ou danificado usando um arquivo de outro computador. Execute novamente o Instalador do Visual Studio para substituir o arquivo ausente.
>
> O arquivo vcvarsall.bat também varia de uma versão para outra. Se a versão atual do Visual Studio estiver instalada em um computador que também tem uma versão anterior do Visual Studio, não execute vcvarsall.bat nem outro arquivo de comando do Visual Studio de versões diferentes na mesma janela do prompt de comando.

## <a name="use-the-developer-tools-in-an-existing-command-window"></a>Usar as ferramentas para desenvolvedores em uma janela Comando existente

A maneira mais simples de especificar uma arquitetura de build específica em uma janela Comando existente é usar o arquivo vcvarsall.bat. Use vcvarsall. bat para definir variáveis de ambiente para configurar a linha de comando para compilação nativa de 32 bits ou 64 bits. Argumentos permitem que você especifique a compilação cruzada para x86, x64, ARM, ARM64 processadores ou. Você pode direcionar as plataformas da Microsoft Store, a plataforma Universal do Windows ou a área de trabalho do Windows. Você pode até mesmo especificar qual SDK do Windows para usar e selecione a versão do conjunto de ferramentas de plataforma.

Quando usada sem argumentos, vcvarsall. bat configura as variáveis de ambiente para usar o compilador nativo x86 atual para destinos de área de trabalho do Windows de 32 bits. Você pode adicionar argumentos para configurar o ambiente para usar qualquer uma das nativo ou entre as ferramentas do compilador. vcvarsall. bat exibe uma mensagem de erro se você especificar uma configuração que não está instalada ou disponível no seu computador.

### <a name="vcvarsall-syntax"></a>Sintaxe de vcvarsall

> **vcvarsall.bat** [*architecture*] [*platform_type*] [*winsdk_version*] [ **-vcvars_ver=** _vcversion_]

*architecture*<br/>
Esse argumento opcional especifica a arquitetura de host e de destino a ser usada. Se *arquitetura* não for especificado, o ambiente de compilação padrão será usado. Há suporte para estes argumentos:

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

Use **-vcvars_ver=14.0 = 14.2 x .yyyyy** para especificar uma versão específica do conjunto de ferramentas de compilador do Visual Studio de 2019.

Use **-vcvars_ver=14.0 = 14.16** para especificar a versão mais recente do conjunto de ferramentas de compilador do Visual Studio 2017.

::: moniker-end
::: moniker range="= vs-2017"

Use **-vcvars_ver=14.0 = 14.16** para especificar a versão mais recente do conjunto de ferramentas de compilador do Visual Studio 2017.

Use **-vcvars_ver=14.0 = 14,1 x .yyyyy** para especificar uma versão específica do conjunto de ferramentas de compilador do Visual Studio 2017.

::: moniker-end

Use **-vcvars_ver=14.0 = 14.0** para especificar o conjunto de ferramentas de compilador do Visual Studio 2015.

<a name="vcvarsall"></a>
#### <a name="to-set-up-the-build-environment-in-an-existing-command-prompt-window"></a>Para configurar o ambiente de build em uma janela do prompt de comando existente

1. No prompt de comando, use o comando CD para alterar para o diretório de instalação do Visual Studio. Em seguida, use CD novamente para alterar para a subpasta que contém os arquivos de comando específicos da configuração. Para 2019 do Visual Studio e Visual Studio 2017, use o *VC\\auxiliar\\Build* subdiretório. Para o Visual Studio 2015, use o *VC* subdiretório.

1. Insira o comando de seu ambiente de desenvolvedor preferido. Por exemplo, para compilar o código ARM para UWP em uma plataforma de 64 bits, usando o mais recente do SDK do Windows e o Visual Studio compilador conjunto de ferramentas, use esta linha de comando:

   `vcvarsall.bat amd64_arm uwp`

## <a name="create-your-own-command-prompt-shortcut"></a>Criar seu próprio atalho do prompt de comando

::: moniker range=">= vs-2019"

Abra a caixa de diálogo de propriedades para um atalho de prompt de comando do desenvolvedor ver o destino do comando usado. Por exemplo, o destino do atalho do **Prompt de Comando de Ferramentas Nativas do x64 para VS 2019** é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"`

::: moniker-end
::: moniker range="= vs-2017"

Abra a caixa de diálogo de propriedades para um atalho de prompt de comando do desenvolvedor ver o destino do comando usado. Por exemplo, o destino para o **x64 Prompt de comando de ferramentas nativa para VS 2017** atalho é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"`

::: moniker-end
::: moniker range="< vs-2017"

Abra a caixa de diálogo de propriedades para um atalho de prompt de comando do desenvolvedor ver o destino do comando usado. Por exemplo, o destino para o **VS2015 x64 Prompt de comando de ferramentas nativas** atalho é algo semelhante a:

`%comspec% /k ""C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"" amd64`

::: moniker-end

Os arquivos em lotes específicos da arquitetura definem o parâmetro *architecture* e chamam vcvarsall.bat. Você pode passar as mesmas opções para esses arquivos em lotes, conforme você passaria para vcvarsall. bat, ou você pode simplesmente chamar vcvarsall. bat diretamente. Para especificar parâmetros para seu próprio atalho de comando, adicione-os ao final do comando entre aspas duplas. Por exemplo, aqui está um atalho para compilar o código ARM para UWP em uma plataforma de 64 bits, usando o SDK mais recente do Windows. Para usar um conjunto de ferramentas anterior do compilador, especifique o número de versão. Use algo como este destino de comando no atalho:

::: moniker range=">= vs-2019"

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat amd64_arm uwp -vcvars_ver=14.16"`

::: moniker-end
::: moniker range="= vs-2017"

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat amd64_arm uwp -vcvars_ver=14.0"`

::: moniker-end
::: moniker range="< vs-2017"

`%comspec% /k ""C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"" amd64 -vcvars_ver=12.0`

::: moniker-end

Ajuste o caminho para refletir seu diretório de instalação do Visual Studio. O arquivo vcvarsall.bat traz mais informações sobre os números de versão específicos.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

Para criar a C /C++ projeto em um prompt de comando, o Visual Studio fornece essas ferramentas de linha de comando:

[CL](reference/compiling-a-c-cpp-program.md)<br/>
Use o compilador (cl.exe) para compilar e vincular arquivos de código-fonte a aplicativos, bibliotecas e DLLs.

[Link](reference/linking.md)<br/>
Use o vinculador (link.exe) para vincular arquivos de objetos compilados e bibliotecas a aplicativos e DLLs.

[MSBuild](msbuild-visual-cpp.md)<br/>
Use o MSBuild (msbuild.exe) e um arquivo de projeto (.vcxproj) para configurar um build e invocar o conjunto de ferramentas indiretamente. É equivalente a executar o **construir** projeto ou **compilar solução** no IDE do Visual Studio. Executando o MSBuild na linha de comando é um cenário avançado e geralmente não é recomendado.

[DEVENV](/visualstudio/ide/reference/devenv-command-line-switches)<br/>
Combine DEVENV (devenv.exe) combinado com uma opção de linha de comando como **/Build** ou **/Clean** para executar determinados comandos de compilação sem exibir o IDE do Visual Studio. Em geral, DEVENV é preferível usar o MSBuild diretamente, porque você pode permitir que o Visual Studio manipule as complexidades do MSBuild.

[NMAKE](reference/nmake-reference.md)<br/>
Use o NMAKE (nmake.exe) no Windows para compilar projetos C++ baseados em um makefile tradicional.

Quando você compila na linha de comando, o comando F1 não está disponível para obter ajuda instantânea. Em vez disso, use um mecanismo de pesquisa para obter informações sobre avisos, erros e mensagens ou use os arquivos da Ajuda offline. Para usar a pesquisa no [docs.microsoft.com](https://docs.microsoft.com/cpp/), use a caixa de pesquisa na parte superior da página.

## <a name="in-this-section"></a>Nesta seção

Esses artigos mostram como compilar aplicativos na linha de comando e descrevem como personalizar o ambiente de compilação de linha de comando. Alguns mostram como usar conjuntos de ferramentas de 64 bits e direcionar x86, x64, ARM, ARM64 plataformas e. Eles também descrevem o uso das ferramentas de compilação de linha de comando MSBuild e NMAKE.

[Passo a passo: Compilando um programa do C++ nativo na linha de comando](walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)<br/>
Fornece um exemplo que mostra como criar e compilar um C++ programa na linha de comando.

[Passo a passo: Compilar um programa em C na linha de comando](walkthrough-compile-a-c-program-on-the-command-line.md)<br/>
Descreve como compilar um programa gravado na linguagem de programação C.

[Passo a passo: Compilando um programa do C++/CLI na linha de comando](walkthrough-compiling-a-cpp-cli-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CLI que usa o .NET Framework.

[Passo a passo: Compilando um programa do C++/CX na linha de comando](walkthrough-compiling-a-cpp-cx-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CX que usa o Tempo de Execução do Windows.

[Definir o caminho e variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md)<br/>
Como definir variáveis de ambiente para usar um conjunto de ferramentas de 32 bits ou 64 bits para o destino x86, x64, ARM, ARM64 plataformas e.

[Referência a NMAKE](reference/nmake-reference.md)<br/>
Fornece links a artigos que descrevem o Microsoft Program Maintenance Utility (NMAKE.EXE).

[MSBuild na linha de comando – C++](msbuild-visual-cpp.md)<br/>
Fornece links para artigos que explicam como usar o msbuild.exe na linha de comando.

## <a name="related-sections"></a>Seções relacionadas

[/MD, /MT, /LD (usar biblioteca de tempo de execução)](reference/md-mt-ld-use-run-time-library.md)<br/>
Descreve como usar essas opções do compilador para usar uma biblioteca de tempo de execução de depuração ou versão.

[Opções do compilador do C/C++](reference/compiler-options.md)<br/>
Fornece links a artigos que falam sobre as opções de compilador da linguagem C e C++ e sobre o CL.exe.

[Opções de vinculador MSVC](reference/linker-options.md)<br/>
Fornece links a artigos que falam sobre as opções do vinculador e sobre o LINK.exe.

[Ferramentas de build adicionais do MSVC](reference/c-cpp-build-tools.md)<br/>
Fornece links para as ferramentas de build do C/C++ incluídas no Visual Studio.

## <a name="see-also"></a>Consulte também

[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)
