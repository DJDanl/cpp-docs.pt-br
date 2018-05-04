---
title: Compilar o código C/C++ na linha de comando | Microsoft Docs
ms.custom: conceptual
ms.date: 03/29/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- command-line builds [C++]
- compiling source code [C++], command line
- builds [C++], command-line
- command line [C++], building from
- command line [C++], compilers
ms.assetid: 7ca9daed-a003-4162-842d-908f79058365
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d1e02ea59ffc5a4ece71d2790b2ebb6a953ed682
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="build-cc-code-on-the-command-line"></a>Compilar o código C/C++ na linha de comando

Você pode criar aplicativos C e C++ na linha de comando, usando ferramentas que estão incluídas no Visual Studio.

## <a name="how-to-get-the-command-line-tools"></a>Como obter as ferramentas de linha de comando

Quando você escolhe uma das cargas de trabalho C++ no Visual Studio Installer, ele instala o Visual Studio *conjunto de ferramentas de plataforma*. Um conjunto de ferramentas da plataforma tem as ferramentas de todos os C e C++ para uma versão específica do Visual Studio, incluindo os compiladores do C/C++, vinculadores, montadores e outras ferramentas de compilação, bem como as bibliotecas de correspondência. Você pode usar todas essas ferramentas na linha de comando, e também são usados internamente pelo Visual Studio IDE. Há compiladores hospedado x86 e x64 hospedado separados e ferramentas para compilar o código para x86, x64, ARM e ARM64 destinos. Cada conjunto de ferramentas para uma arquitetura de compilação do host e de destino específica é armazenado em seu próprio diretório.

Para funcionar corretamente, as ferramentas requerem diversas variáveis de ambiente específico a ser definido. Eles são usados para adicioná-los para o caminho e definir incluem arquivos, o arquivo de biblioteca e locais do SDK. Para facilitar a definir essas variáveis de ambiente, o instalador cria personalizado *arquivos de comando*, ou lotes de arquivos, durante a instalação. Você pode executar um desses arquivos de comando em uma janela de prompt de comando para definir um host específico e arquitetura de compilação de destino, versão do SDK do Windows, a plataforma de destino e o conjunto de ferramentas da plataforma. Para sua conveniência, o instalador também cria atalhos no menu Iniciar (ou a página inicial no Windows 8. x) que iniciar janelas de prompt de comando do desenvolvedor, usando esses arquivos de comando, para todas as variáveis de ambiente necessárias são definido e pronta para uso.

As variáveis de ambiente necessárias são específicas para sua instalação e a arquitetura de compilação escolha e pode ser alterado por atualizações de produto. Portanto, é altamente recomendável que você use uma do prompt de comando instalada atalhos ou arquivos de comando em vez de configurar as variáveis de ambiente no Windows. Para obter mais informações, consulte [definir o caminho e as variáveis de ambiente para compilações de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md).

Os conjuntos de ferramentas de linha de comando, arquivos de comando e atalhos do prompt de comando que são instalados dependem o processador do computador e as opções selecionadas durante a instalação. No mínimo, as ferramentas hospedado x86 de 32 bits que compilar o código nativo x86 de 32 bits e cross ferramentas de compilação do código x64 nativo de 64 bits são instaladas. Se você tiver o Windows de 64 bits, as ferramentas de 64 bits x64 hospedado que compilar o código nativo de 64 bits e cross ferramentas de compilação de código nativo de 32 bits são instaladas também. Se você optar por instalar as ferramentas de plataforma Universal do Windows C++ opcionais, as ferramentas nativas de 32 bits e 64 bits que compilar código ARM também são instaladas. Outras cargas de trabalho podem instalar ferramentas adicionais.

## <a name="developer-command-prompt-shortcuts"></a>Atalhos de prompt de comando do desenvolvedor

Os atalhos de prompt de comando estão instalados em uma pasta do Visual Studio versão específica no menu Iniciar. Aqui está uma lista de atalhos do prompt de comando base e as arquiteturas de compilação que eles oferecem suporte a:

- **Prompt de comando do desenvolvedor** -define o ambiente para usar as ferramentas de 32 bits x86 nativo para compilar o código nativo x86 de 32 bits.
- **x86 Prompt de comando de ferramentas nativas** -define o ambiente para usar as ferramentas de 32 bits x86 nativo para compilar o código nativo x86 de 32 bits.
- **x64 nativo Prompt de comando de ferramentas** -define o ambiente para usar as ferramentas de 64 bits, x64 nativo para compilar o código de 64 bits, x64 nativo.
- **Prompt de comando de ferramentas cruzadas x86_x64** -define o ambiente para usar as ferramentas de 32 bits x86 nativo para compilar o código de 64 bits, x64 nativo.
- **Prompt de comando de ferramentas cruzadas x64_x86** -define o ambiente para usar as ferramentas de 64 bits, x64 nativo para compilar o código nativo x86 de 32 bits.

Início menu pasta e o atalho nomes reais variam de acordo com a versão do Visual Studio que você instalou e a instalação apelido se você definir um. Por exemplo, se você tiver o Visual Studio de 2017 instalado e você tiver fornecido ele uma instalação apelido de *visualização*, chamado de atalho do prompt de comando do desenvolvedor **Prompt de comando do desenvolvedor para VS 2017 (visualização)**, em uma pasta chamada **2017 do Visual Studio**.

Se você tiver instalado o [Build Tools para Visual Studio de 2017](https://go.microsoft.com/fwlink/p/?linkid=840931) (que também inclui o conjunto de ferramentas de compilador do Visual Studio 2015 atualização 3), somente o nativo de arquitetura específicas ou cruzada das ferramentas de prompt de comando do desenvolvedor opções estão instaladas e não o geral **Prompt de comando do desenvolvedor** atalho.

<a name="developer_command_prompt"></a>
### <a name="to-open-a-developer-command-prompt-window"></a>Para abrir uma janela de prompt de comando do desenvolvedor

1. Na área de trabalho, abra o Windows **iniciar** menu e, em seguida, role para localizar e abrir a pasta para a sua versão do Visual Studio, por exemplo, **2017 do Visual Studio**. Em algumas versões mais antigas do Visual Studio, os atalhos estão em uma subpasta chamada **ferramentas do Visual Studio**.

1. Na pasta, escolha o **Prompt de comando do desenvolvedor** para sua versão do Visual Studio. Esse atalho inicia uma janela de prompt de comando do desenvolvedor que usa a arquitetura de compilação padrão das ferramentas de 32 bits x86 nativo para compilar o código nativo x86 de 32 bits. Se você preferir uma arquitetura de compilação não padrão, escolha uma das nativo ou prompts de comando para especificar a arquitetura de host e de destino de ferramentas cruzadas.

Uma maneira ainda mais rápida para abrir uma janela de prompt de comando do desenvolvedor é inserir *prompt de comando do desenvolvedor* na caixa de pesquisa de área de trabalho, escolha o resultado desejado.

## <a name="developer-command-files-and-locations"></a>Locais e arquivos de comando do desenvolvedor

Se você preferir definir o ambiente de arquitetura de compilação em uma janela de prompt de comando existente, você pode usar um dos arquivos de comando (arquivos em lotes) criado pelo instalador para definir o ambiente necessário. Você só é recomendável fazer isso em uma nova janela de prompt de comando, e não recomendamos que você posteriores ambientes na mesma janela de comando. O local desses arquivos depende a versão do Visual Studio que você instalou e no local e nomenclatura escolhas feitas durante a instalação. Para o Visual Studio de 2017, o local de instalação típica em um computador de 64 bits é \Program arquivos (x86) \Microsoft Visual Studio\2017\\*edição*, onde *edição* comunidade, é possível Professional, Enterprise, BuildTools ou outro nome que você forneceu. Para Visual Studio 2015, o local de instalação típica é \Program Files (x86) \Microsoft 14.0 do Visual Studio.

O arquivo de comandos de prompt de comando do desenvolvedor principal, VsDevCmd.bat, está localizado no subdiretório Common7\Tools do diretório de instalação. Quando nenhum parâmetro for especificado, define o ambiente e o host e o destino de compilação arquitetura para usar as ferramentas de nativo x86 de 32 bits para x86 de 32 bits de criar código.

Arquivos de comando adicionais estão disponíveis para configurar a arquiteturas de compilação específico, dependendo de sua arquitetura de processador e as opções que você instalou e cargas de trabalho do Visual Studio. No Visual Studio de 2017, eles estão localizados no subdiretório VC\Auxiliary\Build do diretório de instalação do Visual Studio. No Visual Studio 2015, eles estão localizados no VC, VC\bin ou VC\bin\\*arquiteturas* subdiretórios do diretório de instalação, onde *arquiteturas* é um nativo ou Opções de compilador cruzado. Esses arquivos de comando definir parâmetros e chame VsDevCmd.bat para configurar o ambiente de arquitetura de compilação especificada. Uma instalação típica pode incluir esses arquivos de comando:

|Arquivo de comando|Arquiteturas de host e de destino|
|---|---|
|**vcvars32.bat**| Use as ferramentas de nativo x86 de 32 bits para compilar x86 de 32 bits código.|
|**vcvars64.bat**| Usar as ferramentas de x64 nativo de 64 bits para compilação de 64 bits x64 código.|
|**vcvarsx86_amd64.bat**| Use as ferramentas cruzadas do nativo x86 de 32 bits para 64 bits x64 de compilação código.|
|**vcvarsamd64_x86.bat**| Use as ferramentas cruzadas do x64 nativo de 64 bits para x86 de 32 bits de compilação código.|
|**vcvarsx86_arm.bat**| Use as ferramentas cruzadas do nativo x86 de 32 bits para compilar código ARM.|
|**vcvarsamd64_arm.bat**| Use as ferramentas cruzadas do x64 nativo de 64 bits para compilar código ARM.|
|**vcvarsall.bat**| Use parâmetros para especificar o host e arquiteturas de destino, bem como as opções de SDK e plataforma. Para obter uma lista de opções com suporte, chame usando um **/Help** parâmetro.|

> [!CAUTION]
> O arquivo vcvarsall.bat e outros arquivos de comando do Visual Studio podem variar de um computador para outro. Não substitua um arquivo vcvarsall.bat não encontrado ou danificado usando um arquivo de outro computador. Execute novamente o instalador do Visual Studio para substituir o arquivo ausente.
>
> O arquivo vcvarsall.bat também varia de uma versão para outra. Se a versão atual do Visual Studio está instalada em um computador que também tem uma versão anterior do Visual Studio, não execute vcvarsall.bat ou em outro arquivo de comando do Visual Studio de versões diferentes na mesma janela do prompt de comando.

## <a name="use-the-developer-tools-in-an-existing-command-window"></a>Use as ferramentas de desenvolvedor em uma janela de comando existente

É a maneira mais simples para especificar uma arquitetura de compilação específica em uma janela de comando existente usar o arquivo vcvarsall.bat. Você pode usar vcvarsall.bat para definir variáveis de ambiente para configurar a linha de comando de compilação nativa de 32 bits ou 64 bits ou de compilação cruzada para x86, x64 ou ARM processadores; destino Microsoft Store, plataforma Universal do Windows ou plataformas de área de trabalho do Windows; para especificar quais SDK do Windows será usado; e para especificar a versão do conjunto de ferramentas de plataforma. Se nenhum argumento for fornecido, vcvarsall.bat configura as variáveis de ambiente para usar o compilador nativo de 32 bits atual para x86 de destinos de área de trabalho do Windows. No entanto, você pode usá-lo para configurar qualquer uma das nativo ou entre as ferramentas de compilador. Se você especificar uma configuração de compilador que não está instalada ou não está disponível em sua arquitetura de computador de compilação, uma mensagem de erro será exibida.

### <a name="vcvarsall-syntax"></a>sintaxe de vcvarsall

> **vcvarsall.bat** [*arquitetura*] [*platform_type*] [*winsdk_version*] [**-vcvars_ver =** _vcversion_]

*Arquitetura*<br/>
Esse argumento opcional especifica a arquitetura de host e de destino a ser usado. Se *arquitetura* não for especificado, o ambiente de compilação padrão será usado. Há suporte para estes argumentos:

|*Arquitetura*|Compilador|Arquitetura do computador host|Criar a arquitetura de saída (destino)|
|----------------------------|--------------|----------------------------------|-------------------------------|
|**x86**|Nativa de 32 bits x86|x86, x64|x86|
|**x86\_amd64** ou **x86\_x64**|cross x64 x86|x86, x64|X64|
|**x86_arm**|ARM em x86 cruzado|x86, x64|ARM|
|**x86_arm64**|ARM64 em x86 cruzada|x86, x64|ARM64|
|**AMD64** ou **x64**|x64 nativo de 64 bits|X64|X64|
|**AMD64\_x86** ou **x64\_x86**|cross x86 em x64|X64|x86|
|**AMD64\_arm** ou **x64\_arm**|Prepare-se em x64 cruzada|X64|ARM|
|**AMD64\_arm64** ou **x64\_arm64**|ARM64 em x64 cruzada|X64|ARM64|

*platform_type*<br/>
Esse argumento opcional permite que você especifique **armazenar** ou **uwp** como o tipo de plataforma. Por padrão, o ambiente é configurado para compilar aplicativos de área de trabalho ou console.

*winsdk_version*<br/>
Opcionalmente, especifica a versão do SDK do Windows para usar. Por padrão, é usado o SDK do Windows mais recente instalado. Para especificar a versão do SDK do Windows, você pode usar um número total de SDK do Windows 10 como **10.0.10240.0**, ou especifique **8.1** para usar o SDK do Windows 8.1.

*vcversion*<br/>
Especifica opcionalmente o conjunto de ferramentas de compilador Visual Studio para usar. Por padrão, o ambiente está definido para usar o conjunto de ferramentas de compilador 2017 do Visual Studio atual. Use **-vcvars_ver = 14.0** para especificar o conjunto de ferramentas de compilador do Visual Studio 2015.

<a name="vcvarsall"></a>
#### <a name="to-set-up-the-build-environment-in-an-existing-command-prompt-window"></a>Para configurar o ambiente de compilação em uma janela de prompt de comando existente

1. No prompt de comando, use o comando CD para alterar para o diretório de instalação do Visual Studio. Em seguida, use novamente para mudar para a subpasta que contém os arquivos de comando específicas de configuração. Para Visual Studio de 2017, esse é o subdiretório VC\Auxiliary\Build. Para Visual Studio 2015, use o subdiretório do VC.

1. Digite o comando para o seu ambiente de desenvolvedor preferencial. Por exemplo, para compilar código ARM para UWP em uma plataforma de 64 bits usando o SDK do Windows e o conjunto de ferramentas do compilador Visual Studio 2017 RTM, use a linha de comando:

   `vcvarsall.bat amd64_arm uwp -vcvars_ver=14.10`

## <a name="create-your-own-command-prompt-shortcut"></a>Criar seu próprio atalho do prompt de comando

Se você abrir a caixa de diálogo de propriedades para um dos atalhos de prompt de comando do desenvolvedor existente, você pode ver o destino do comando usado. Por exemplo, o destino para o **x64 Prompt de comando de ferramentas nativas para VS 2017** atalho é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"`

Conjunto de arquivos de lote específicos de arquitetura de *arquitetura* vcvarsall.bat parâmetro e chamada. Você pode passar as mesmas opções adicionais para esses arquivos em lote, você passaria para vcvarsall.bat ou você pode simplesmente chamar vcvarsall.bat diretamente. Para especificar parâmetros para o seu próprio atalho do comando, adicioná-los ao final do comando entre aspas duplas. Por exemplo, para configurar um atalho para compilar código ARM de UWP em uma plataforma de 64 bits usando o SDK do Windows e o conjunto de ferramentas do compilador Visual Studio 2017 RTM, use algo parecido com este comando de destino em seu atalho:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat amd64_arm uwp -vcvars_ver=14.10"`

Você deve ajustar o caminho para refletir seu diretório de instalação do Visual Studio.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

Para criar um projeto de C/C++ na linha de comando, o Visual Studio fornece essas ferramentas de linha de comando:

[CL](../build/reference/compiling-a-c-cpp-program.md)<br/>
Use o compilador (cl.exe) para compilar e vincular arquivos de código-fonte a aplicativos, bibliotecas e DLLs.

[Link](../build/reference/linking.md)<br/>
Use o vinculador (link.exe) para vincular arquivos de objetos compilados e bibliotecas a aplicativos e DLLs.

[MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)<br/>
Use o MSBuild (msbuild.exe) para criar projetos do Visual C++ e soluções do Visual Studio. Isso é equivalente a executar o **criar** projeto ou **compilar solução** comando no IDE do Visual Studio.

[DEVENV](/visualstudio/ide/reference/devenv-command-line-switches)<br/>
Use DEVENV (devenv.exe) combinada com uma opção de linha de comando — por exemplo, **compilação** ou **/limpar**— para executar certos comandos de construção sem exibir o Visual Studio IDE.

[NMAKE](../build/nmake-reference.md)<br/>
Use NMAKE (nmake.exe) para automatizar tarefas que compila projetos do Visual C++ usando um makefile tradicional.

Quando você compila na linha de comando, o comando F1 não está disponível para obter ajuda instantânea. Em vez disso, você pode usar um mecanismo de pesquisa para obter informações sobre os avisos, erros e mensagens, ou você pode usar os arquivos de Ajuda offline. Para usar a pesquisa no [docs.microsoft.com](https://docs.microsoft.com/cpp/), insira a cadeia de caracteres de pesquisa na caixa de pesquisa na parte superior da página.

## <a name="in-this-section"></a>Nesta seção

Os artigos desta seção da documentação mostram como compilar aplicativos na linha de comando, descrevem como personalizar o ambiente de compilação da linha de comando para usar conjuntos de ferramentas de 64 bits, segmentar plataformas x86, x64 e ARM e demonstrar como usar as ferramentas de compilação de linha de comando MSBuild e NMAKE.

[Instruções passo a passo: compilando um programa do C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)<br/>
Apresenta um exemplo que mostra como criar e compilar um programa C++ simples na linha de comando.

[Passo a passo: Compilar um programa em C na linha de comando](../build/walkthrough-compile-a-c-program-on-the-command-line.md)<br/>
Descreve como compilar um programa gravado na linguagem de programação C.

[Instruções passo a passo: compilando um programa C++/CLI na linha de comando](../build/walkthrough-compiling-a-cpp-cli-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CLI que usa o .NET Framework.

[Instruções passo a passo: compilando um programa C++/CX na linha de comando](../build/walkthrough-compiling-a-cpp-cx-program-on-the-command-line.md)<br/>
Descreve como criar e compilar um programa C++/CX que usa o Tempo de Execução do Windows.

[Definir o caminho e variáveis de ambiente para builds de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md)<br/>
Descreve como iniciar uma janela de prompt de comando com as variáveis de ambiente necessário definido para compilações de linha de comando que visam x86, x64 e ARM plataformas usando um conjunto de ferramentas de 32 bits ou 64 bits.

[Referência a NMAKE](../build/nmake-reference.md)<br/>
Fornece links a artigos que descrevem o Microsoft Program Maintenance Utility (NMAKE.EXE).

[MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)<br/>
Fornece links a artigos que explicam como usar o MSBuild.EXE.

## <a name="related-sections"></a>Seções relacionadas

[/MD, /MT, /LD (usar biblioteca de tempo de execução)](../build/reference/md-mt-ld-use-run-time-library.md)<br/>
Descreve como usar essas opções do compilador para usar uma biblioteca de tempo de execução de depuração ou versão.

[Opções do compilador C/C++](../build/reference/compiler-options.md)<br/>
Fornece links a artigos que falam sobre as opções de compilador da linguagem C e C++ e sobre o CL.exe.

[Opções do vinculador](../build/reference/linker-options.md)<br/>
Fornece links a artigos que falam sobre as opções do vinculador e sobre o LINK.exe.

[Ferramentas de build de C/C++](../build/reference/c-cpp-build-tools.md)<br/>
Fornece links para C/C++ criam ferramentas que estão incluídas no Visual Studio.

## <a name="see-also"></a>Consulte também

[Compilando programas do C/C++](../build/building-c-cpp-programs.md)