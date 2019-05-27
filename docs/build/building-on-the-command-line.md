---
title: Usar o Conjunto de ferramentas do MSVC na linha de comando – Visual Studio
description: Use a cadeia de ferramentas do compilador do MSVC (Microsoft C++) na linha de comando fora do IDE do Visual Studio.
ms.custom: conceptual
ms.date: 05/16/2019
helpviewer_keywords:
- command-line builds [C++]
- compiling source code [C++], command line
- builds [C++], command-line
- command line [C++], building from
- command line [C++], compilers
ms.assetid: 7ca9daed-a003-4162-842d-908f79058365
ms.openlocfilehash: 97626455ace0d3ad47b9011594e82c144d7ea27d
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837123"
---
# <a name="use-the-msvc-toolset-from-the-command-line"></a>Usar o Conjunto de ferramentas do MSVC na linha de comando

Compile aplicativos C e C++ na linha de comando usando as ferramentas incluídas no Visual Studio. Baixe também o conjunto de ferramentas do compilador como um pacote autônomo na página [Downloads do Visual Studio](https://visualstudio.microsoft.com/downloads/). Ele faz parte do pacote **Ferramentas de Build do Visual Studio**; você pode optar por baixar somente as ferramentas necessárias para o desenvolvimento em C++.

## <a name="how-to-use-the-command-line-tools"></a>Como usar as ferramentas de linha de comando

Quando você escolhe uma das cargas de trabalho do C++ no Instalador do Visual Studio, ele instala o *Conjunto de ferramentas da plataforma* do Visual Studio. Um Conjunto de ferramentas da plataforma tem todas as ferramentas do C e C++ para uma versão específica do Visual Studio, incluindo compiladores, vinculadores, assemblers do C/C++ e outras ferramentas de build, bem como as bibliotecas correspondentes. Você pode usar todas essas ferramentas na linha de comando e elas também são usadas internamente pelo IDE do Visual Studio. Há ferramentas e compiladores hospedados no x86 e no x64 separados para compilar o código para os destinos x86, x64, ARM e ARM64. Cada conjunto de ferramentas para uma arquitetura específica de build de host e destino é armazenado em seu próprio diretório.

Os conjuntos de ferramentas do compilador instalados dependem do processador do computador e das opções selecionadas durante a instalação. No mínimo, são instaladas as ferramentas hospedadas no x86 de 32 bits que compilam o código nativo do x86 de 32 bits e ferramentas cruzadas que compilam o código nativo do x64 de 64 bits. Se você tem o Windows de 64 bits, também são instaladas as ferramentas hospedadas no x64 de 64 bits que compilam o código nativo de 64 bits e ferramentas cruzadas que compilam o código nativo de 32 bits. Caso você opte por instalar as ferramentas opcionais da Plataforma Universal do Windows para C++, as ferramentas nativas de 32 e 64 bits que compilam o código do ARM também são instaladas. Outras cargas de trabalho podem instalar ferramentas adicionais.

## <a name="environment-variables-and-developer-command-prompts"></a>Variáveis de ambiente e Prompts de Comando do Desenvolvedor

Para que funcionem corretamente, as ferramentas exigem a definição de diversas variáveis de ambiente específicas. Elas são usadas para adicioná-las ao caminho e para definir as localizações do arquivo de inclusão, do arquivo de biblioteca e do SDK. Para facilitar a definição dessas variáveis de ambiente, o instalador cria *arquivos de comando* personalizados ou arquivos em lotes, durante a instalação. Execute um desses arquivos de comando em uma janela do prompt de comando para definir uma arquitetura de build de host e destino, uma versão do SDK do Windows, uma plataforma de destino e o Conjunto de ferramentas da plataforma específicos. Para sua conveniência, o instalador também cria atalhos no menu Iniciar que iniciam janelas do Prompt de Comando do Desenvolvedor usando esses arquivos de comando, de modo que todas as variáveis de ambiente necessárias estejam definidas e prontas para uso.

As variáveis de ambiente necessárias são específicas à instalação e à arquitetura de build escolhida e podem ser alteradas por atualizações do produto. Portanto, recomendamos expressamente que você use um dos arquivos de comando ou um dos atalhos do prompt de comando instalado em vez de definir as variáveis de ambiente no Windows por conta própria. Para obter mais informações, confira [Definir o caminho e as variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md).

## <a name="developer_command_prompt_shortcuts"></a> Atalhos do Prompt de Comando do Desenvolvedor

Os atalhos do prompt de comando são instalados em uma pasta do Visual Studio específica da versão no menu Iniciar. Esta é uma lista dos atalhos do prompt de comando base e das arquiteturas de build às quais eles dão suporte:

- **Prompt de Comando do Desenvolvedor** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits.
- **Prompt de Comando de Ferramentas Nativas do x86** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits.
- **Prompt de Comando de Ferramentas Nativas do x64** – define o ambiente para uso das ferramentas nativas do x64 de 64 bits para compilar o código nativo do x64 de 64 bits.
- **Prompt de Comando de Ferramentas Cruzadas do x86_x64** – define o ambiente para uso das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x64 de 64 bits.
- **Prompt de Comando de Ferramentas Cruzadas do x64_x86** – define o ambiente para uso das ferramentas nativas do x64 de 64 bits para compilar o código nativo do x86 de 32 bits.

Os nomes reais da pasta e do atalho do menu Iniciar variam conforme a versão do Visual Studio instalada e o apelido da instalação, caso você tenha definido um. Por exemplo, se você tiver o Visual Studio 2019 instalado e der a ele o apelido de instalação *Versão Prévia*, o atalho do Prompt de Comando do Desenvolvedor será chamado **Prompt de Comando do Desenvolvedor para VS 2019** em uma pasta chamada **Visual Studio 2019**.

## <a name="developer_command_prompt"></a> Para abrir uma janela do Prompt de Comando do Desenvolvedor

1. Na área de trabalho, abra o menu **Iniciar** do Windows e, em seguida, role a página para localizar e abrir a pasta da versão do Visual Studio, por exemplo, **Visual Studio 2019**. Em algumas versões mais antigas do Visual Studio, os atalhos estão em uma subpasta chamada **Ferramentas do Visual Studio**.

1. Na pasta, escolha o **Prompt de Comando do Desenvolvedor** da versão do Visual Studio. Esse atalho inicia uma janela do Prompt de Comando do Desenvolvedor que usa a arquitetura de build padrão das ferramentas nativas do x86 de 32 bits para compilar o código nativo do x86 de 32 bits. Caso prefira uma arquitetura de build não padrão, escolha um dos prompts de comando de ferramentas nativas ou cruzadas para especificar a arquitetura de host e de destino.

Uma maneira ainda mais rápida de abrir uma janela do Prompt de Comando do Desenvolvedor é inserir *Prompt de Comando do Desenvolvedor* na caixa de pesquisa da área de trabalho e, em seguida, escolher o resultado desejado.

## <a name="developer_command_file_locations"></a> Localizações do arquivo de comando do desenvolvedor

Caso prefira definir o ambiente de arquitetura de build em uma janela do prompt de comando existente, use um dos arquivos de comando (arquivos em lotes) criados pelo instalador para definir o ambiente necessário. Só recomendamos que você faça isso em uma nova janela do prompt de comando e não recomendamos que você alterne os ambientes posteriormente na mesma janela Comando. A localização desses arquivos depende da versão instalada do Visual Studio e das escolhas de localização e nomenclatura feitas durante a instalação. Para o Visual Studio 2019, a localização de instalação típica em um computador de 64 bits é \Arquivos de Programas (x86)\Microsoft Visual Studio\2019\*edição*, em que *edição* pode ser Community, Professional, Enterprise, BuildTools ou outro nome fornecido. A localização do Visual Studio 2017 é semelhante. Para o Visual Studio 2015, a localização de instalação típica é \Arquivos de Programas (x86)\Microsoft Visual Studio 14.0.

O arquivo de comando principal do Prompt de Comando do Desenvolvedor, VsDevCmd.bat, está localizado no subdiretório Common7\Tools do diretório de instalação. Quando nenhum parâmetro é especificado, isso define o ambiente e a arquitetura de build de host e destino para uso das ferramentas nativas do x86 de 32 bits para compilar o código do x86 de 32 bits.

Arquivos de comando adicionais estão disponíveis para configurar arquiteturas de build específicas, dependendo da arquitetura do processador e das opções de cargas de trabalho do Visual Studio instaladas. No Visual Studio 2017 e no Visual Studio 2019, eles estão localizados no subdiretório VC\Auxiliary\Build do diretório de instalação do Visual Studio. No Visual Studio 2015, eles estão localizados nos subdiretórios VC, VC\bin ou VC\bin\\*arquiteturas* do diretório de instalação, em que *arquiteturas* é uma das opções do compilador nativo ou cruzado. Esses arquivos de comando definem os parâmetros padrão e chamam VsDevCmd.bat para configurar o ambiente da arquitetura de build especificada. Uma instalação típica pode incluir estes arquivos de comando:

|Arquivo de comando|Arquiteturas de host e de destino|
|---|---|
|**vcvars32.bat**| Use as ferramentas nativas do x86 de 32 bits para compilar o código do x86 de 32 bits.|
|**vcvars64.bat**| Use as ferramentas nativas do x64 de 64 bits para compilar o código do x64 de 64 bits.|
|**vcvarsx86_amd64.bat**| Use as ferramentas cruzadas nativas do x86 de 32 bits para compilar o código do x64 de 64 bits.|
|**vcvarsamd64_x86.bat**| Use as ferramentas cruzadas nativas do x64 de 64 bits para compilar o código do x86 de 32 bits.|
|**vcvarsx86_arm.bat**| Use as ferramentas cruzadas nativas do x86 de 32 bits para compilar o código do ARM.|
|**vcvarsamd64_arm.bat**| Use as ferramentas cruzadas nativas do x64 de 64 bits para compilar o código do ARM.|
|**vcvarsall.bat**| Use parâmetros para especificar as arquiteturas de host e de destino, bem como as opções de SDK e plataforma. Para obter uma lista das opções compatíveis, faça uma chamada usando um parâmetro **/help**.|

> [!CAUTION]
> O arquivo vcvarsall.bat e outros arquivos de comando do Visual Studio podem variar conforme o computador. Não substitua um arquivo vcvarsall.bat não encontrado ou danificado usando um arquivo de outro computador. Execute novamente o Instalador do Visual Studio para substituir o arquivo ausente.
>
> O arquivo vcvarsall.bat também varia de uma versão para outra. Se a versão atual do Visual Studio estiver instalada em um computador que também tem uma versão anterior do Visual Studio, não execute vcvarsall.bat nem outro arquivo de comando do Visual Studio de versões diferentes na mesma janela do prompt de comando.

## <a name="use-the-developer-tools-in-an-existing-command-window"></a>Usar as ferramentas para desenvolvedores em uma janela Comando existente

A maneira mais simples de especificar uma arquitetura de build específica em uma janela Comando existente é usar o arquivo vcvarsall.bat. Use vcvarsall.bat para definir variáveis de ambiente a fim de configurar a linha de comando para a compilação nativa de 32 ou 64 bits ou para a compilação cruzada em processadores x86, x64 ou ARM; para definir como destino as plataformas Microsoft Store, Plataforma Universal do Windows ou Área de Trabalho do Windows; para especificar qual SDK do Windows será usado; e para especificar a versão do Conjunto de ferramentas da plataforma. Se nenhum argumento for fornecido, vcvarsall.bat configurará as variáveis de ambiente para usar o compilador nativo atual de 32 bits para os destinos x86 da Área de Trabalho do Windows. No entanto, você pode usá-lo para configurar uma das ferramentas do compilador nativo ou cruzado. Se você especificar uma configuração do compilador não instalada ou não disponível na arquitetura do computador de build, uma mensagem de erro será exibida.

### <a name="vcvarsall-syntax"></a>Sintaxe de vcvarsall

> **vcvarsall.bat** [*architecture*] [*platform_type*] [*winsdk_version*] [**-vcvars_ver=**_vcversion_]

*architecture*<br/>
Esse argumento opcional especifica a arquitetura de host e de destino a ser usada. Se *architecture* não for especificado, o ambiente de build padrão será usado. Há suporte para estes argumentos:

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
Opcionalmente, especifica o conjunto de ferramentas do compilador do Visual Studio a ser usado. Por padrão, o ambiente está definido para usar o conjunto de ferramentas do compilador do Visual Studio atual. Use **-vcvars_ver=14.0** para especificar o conjunto de ferramentas do compilador do Visual Studio 2015 ou **-vcvars_ver=15.0** para especificar o conjunto de ferramentas do compilador do Visual Studio 2017.

<a name="vcvarsall"></a>
#### <a name="to-set-up-the-build-environment-in-an-existing-command-prompt-window"></a>Para configurar o ambiente de build em uma janela do prompt de comando existente

1. No prompt de comando, use o comando CD para alterar para o diretório de instalação do Visual Studio. Em seguida, use CD novamente para alterar para a subpasta que contém os arquivos de comando específicos da configuração. Para o Visual Studio 2017 e o Visual Studio 2019, esse é o subdiretório VC\Auxiliary\Build. Para o Visual Studio 2015, use o subdiretório VC.

1. Insira o comando de seu ambiente de desenvolvedor preferido. Por exemplo, para compilar o código do ARM para o UWP em uma plataforma de 64 bits usando o SDK do Windows mais recente e o conjunto de ferramentas do compilador do Visual Studio 2019, use esta linha de comando:

   `vcvarsall.bat amd64_arm uwp`

## <a name="create-your-own-command-prompt-shortcut"></a>Criar seu próprio atalho do prompt de comando

Se você abrir a caixa de diálogo Propriedades de um dos atalhos existentes do Prompt de Comando do Desenvolvedor, poderá ver o destino de comando usado. Por exemplo, o destino do atalho do **Prompt de Comando de Ferramentas Nativas do x64 para VS 2019** é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"`

Os arquivos em lotes específicos da arquitetura definem o parâmetro *architecture* e chamam vcvarsall.bat. Passe as mesmas opções adicionais para esses arquivos em lotes que você passaria para vcvarsall.bat ou apenas chame vcvarsall.bat diretamente. Para especificar parâmetros para seu próprio atalho de comando, adicione-os ao final do comando entre aspas duplas. Por exemplo, para configurar um atalho para compilar o código do ARM para o UWP em uma plataforma de 64 bits usando o SDK do Windows mais recente e um conjunto de ferramentas do compilador anterior à versão atual, você precisará especificar o número de versão. Use algo como este destino de comando no atalho:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat amd64_arm uwp -vcvars_ver=15.0"`

É necessário ajustar o caminho para que ele reflita o diretório de instalação do Visual Studio. O arquivo vcvarsall.bat traz mais informações sobre os números de versão específicos.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

Para compilar um projeto C/C++ na linha de comando, o Visual Studio fornece estas ferramentas de linha de comando:

[CL](reference/compiling-a-c-cpp-program.md)<br/>
Use o compilador (cl.exe) para compilar e vincular arquivos de código-fonte a aplicativos, bibliotecas e DLLs.

[Link](reference/linking.md)<br/>
Use o vinculador (link.exe) para vincular arquivos de objetos compilados e bibliotecas a aplicativos e DLLs.

[MSBuild](msbuild-visual-cpp.md)<br/>
Use o MSBuild (msbuild.exe) e um arquivo de projeto (.vcxproj) para configurar um build e invocar o conjunto de ferramentas indiretamente. Isso equivale a executar o projeto **Build** ou o comando **Compilar Solução** no IDE do Visual Studio. A execução do MSBuild na linha de comando é um cenário avançado e geralmente não é recomendado.

[DEVENV](/visualstudio/ide/reference/devenv-command-line-switches)<br/>
Use o DEVENV (devenv.exe) combinado com uma opção de linha de comando – por exemplo, **/Build** ou **/Clean** – para executar determinados comandos de build sem exibir o IDE do Visual Studio. Em geral, isso é preferível a usar o MSBuild diretamente, porque você pode permitir que o Visual Studio cuide das complexidades do MSBuild.

[NMAKE](reference/nmake-reference.md)<br/>
Use o NMAKE (nmake.exe) no Windows para compilar projetos C++ baseados em um makefile tradicional.

Durante o build na linha de comando, o comando F1 não fica disponível para ajuda instantânea. Em vez disso, use um mecanismo de pesquisa para obter informações sobre avisos, erros e mensagens ou use os arquivos da Ajuda offline. Para usar a pesquisa em [docs.microsoft.com](https://docs.microsoft.com/cpp/), insira a cadeia de pesquisa na caixa de pesquisa na parte superior da página.

## <a name="in-this-section"></a>Nesta seção

Os artigos desta seção da documentação mostram como compilar aplicativos na linha de comando, descrevem como personalizar o ambiente de compilação da linha de comando para usar conjuntos de ferramentas de 64 bits, segmentar plataformas x86, x64 e ARM e demonstrar como usar as ferramentas de compilação de linha de comando MSBuild e NMAKE.

[Passo a passo: Compilando um programa do C++ nativo na linha de comando](walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)<br/>
Apresenta um exemplo que mostra como criar e compilar um programa C++ simples na linha de comando.

[Passo a passo: Compilar um programa em C na linha de comando](walkthrough-compile-a-c-program-on-the-command-line.md)<br/>
Descreve como compilar um programa gravado na linguagem de programação C.

[Passo a passo: Compilando um programa do C++/CLI na linha de comando](walkthrough-compiling-a-cpp-cli-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CLI que usa o .NET Framework.

[Passo a passo: Compilando um programa do C++/CX na linha de comando](walkthrough-compiling-a-cpp-cx-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CX que usa o Tempo de Execução do Windows.

[Definir o caminho e variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md)<br/>
Descreve como iniciar uma janela do prompt de comando que tem as variáveis de ambiente necessárias definidas para os builds de linha de comando direcionados às plataformas x86, x64 e ARM usando um conjunto de ferramentas de 32 ou 64 bits.

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