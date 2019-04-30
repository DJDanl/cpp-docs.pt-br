---
title: Usar o conjunto de ferramentas do MSVC da linha de comando - Visual Studio
description: Use a cadeia de ferramentas de compilador Microsoft C++ (MSVC) da linha de comando fora do IDE do Visual Studio.
ms.custom: conceptual
ms.date: 12/10/2018
helpviewer_keywords:
- command-line builds [C++]
- compiling source code [C++], command line
- builds [C++], command-line
- command line [C++], building from
- command line [C++], compilers
ms.assetid: 7ca9daed-a003-4162-842d-908f79058365
ms.openlocfilehash: 21d1c9063a1d6dd154de8d2caca913ea3fd0ce37
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64342161"
---
# <a name="use-the-msvc-toolset-from-the-command-line"></a>Usar o conjunto de ferramentas do MSVC da linha de comando

Você pode criar aplicativos C e C++ na linha de comando usando as ferramentas que estão incluídas no Visual Studio. Você também pode baixar o conjunto de ferramentas do compilador como um pacote autônomo do [ferramentas de Build do Visual Studio 2017](https://go.microsoft.com/fwlink/p/?linkid=875721).

## <a name="how-to-use-the-command-line-tools"></a>Como usar as ferramentas de linha de comando

Quando você escolhe uma das cargas de trabalho do C++ no instalador do Visual Studio, ele instala o Visual Studio *conjunto de ferramentas de plataforma*. Um conjunto de ferramentas de plataforma tem ferramentas de C e C++ para uma versão específica do Visual Studio, incluindo os compiladores do C/C++, vinculadores, montadores e outras ferramentas de compilação, bem como as bibliotecas correspondentes. Você pode usar todas essas ferramentas na linha de comando, e eles também são usados internamente pelo IDE do Visual Studio. Há separados compiladores hospedados em x86 e x64 hospedados e ferramentas para compilar o código para x86, x64, ARM e ARM64 destinos. Cada conjunto de ferramentas para uma arquitetura de compilação específica do host e de destino é armazenado em seu próprio diretório.

Os conjuntos de ferramentas de compilador que são instalados dependem do processador do computador e as opções selecionadas durante a instalação. No mínimo, as ferramentas hospedados em x86 de 32 bits que compilar o código nativo x86 de 32 bits e entre as ferramentas que compilar o código nativo x64 de 64 bits são instaladas. Se você tiver o Windows de 64 bits, as ferramentas hospedadas em x64 de 64 bits que compilar o código nativo de 64 bits e ferramentas que criam o código nativo de 32 bits de cruzar também são instaladas. Se você optar por instalar as ferramentas C++ da plataforma Windows Universal opcionais, as ferramentas nativas de 32 bits e 64 bits que compilar código ARM também são instaladas. Outras cargas de trabalho podem instalar ferramentas adicionais.

## <a name="environment-variables-and-developer-command-prompts"></a>Variáveis de ambiente e prompts de comando do desenvolvedor

Para funcionar corretamente, as ferramentas requerem diversas variáveis de ambiente específico a ser definido. Eles são usados para adicioná-los para o caminho e definir incluem o arquivo, o arquivo de biblioteca e locais de SDK. Para que seja fácil definir essas variáveis de ambiente, o instalador cria personalizado *arquivos de comando*, ou um lote de arquivos, durante a instalação. Você pode executar um desses arquivos de comando em uma janela de prompt de comando para definir um host específico e arquitetura de compilação de destino, versão do SDK do Windows, plataforma de destino e o conjunto de ferramentas da plataforma. Para sua conveniência, o instalador também cria atalhos no menu Iniciar que iniciam as janelas de prompt de comando do desenvolvedor usando esses arquivos de comando, portanto, todas as variáveis de ambiente necessárias são definidos e prontos para uso.

As variáveis de ambiente necessárias são específicas para sua instalação e a arquitetura de compilação que você escolhe e pode ser alteradas pelas atualizações do produto. Portanto, é altamente recomendável que você use um dos atalhos de prompt de comando instalada ou arquivos de comando em vez de definir as variáveis de ambiente no Windows. Para obter mais informações, consulte [definir o caminho e variáveis de ambiente para Builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md).

## <a name="developer_command_prompt_shortcuts"></a> Atalhos de prompt de comando do desenvolvedor

Os atalhos de prompt de comando estão instalados em uma pasta do Visual Studio específica da versão no seu menu Iniciar. Aqui está uma lista de atalhos de prompt de comando de base e as arquiteturas de compilação que eles dão suporte a:

- **Prompt de comando do desenvolvedor** -define o ambiente para usar ferramentas nativo x86 de 32 bits para compilar o código nativo x86 de 32 bits.
- **x86 Prompt de comando de ferramentas nativas** -define o ambiente para usar ferramentas nativo x86 de 32 bits para compilar o código nativo x86 de 32 bits.
- **x64 nativo Prompt de comando de ferramentas** -define o ambiente para usar as ferramentas de 64 bits, x64 nativo para compilar o código de 64 bits, x64 nativo.
- **Prompt de comando de ferramentas de Cross x86_x64** -define o ambiente para usar ferramentas nativo x86 de 32 bits para compilar o código de 64 bits, x64 nativo.
- **Prompt de comando de ferramentas de Cross x64_x86** -define o ambiente para usar ferramentas nativo x64 de 64 bits para compilar o código nativo x86 de 32 bits.

Iniciar menu atalho e pasta nomes reais variam conforme a versão do Visual Studio que você instalou e a apelido da instalação se você definir um. Por exemplo, se você tiver o Visual Studio 2017 instalado e você tiver fornecido ele uma instalação apelido de *versão prévia*, o atalho de prompt de comando do desenvolvedor é denominado **Prompt de comando do desenvolvedor para VS 2017 (versão prévia)**, em uma pasta chamada **Visual Studio 2017**.

Se você instalou o [ferramentas de Build do Visual Studio 2017](https://go.microsoft.com/fwlink/p/?linkid=875721) (que também inclui o conjunto de ferramentas de compilador do Visual Studio 2015 atualização 3), somente as nativos específicos de arquitetura cruzada ferramentas ou prompt de comando do desenvolvedor opções estão instaladas e não gerais **Prompt de comando do desenvolvedor** atalho.

## <a name="developer_command_prompt"></a> Para abrir uma janela de prompt de comando do desenvolvedor

1. Na área de trabalho, abra o Windows **inicie** menu e, em seguida, role para localizar e abrir a pasta para a sua versão do Visual Studio, por exemplo, **Visual Studio 2017**. Em algumas versões mais antigas do Visual Studio, os atalhos estão em uma subpasta chamada **ferramentas do Visual Studio**.

1. Na pasta, escolha o **Prompt de comando do desenvolvedor** para sua versão do Visual Studio. Esse atalho inicia uma janela de prompt de comando do desenvolvedor que usa a arquitetura de compilação padrão de ferramentas nativo x86 de 32 bits para compilar o código de 32 bits, nativo x86. Se você preferir uma arquitetura de compilação não padrão, escolha uma das nativo ou prompts de comando para especificar a arquitetura de host e de destino de ferramentas cruzadas.

Uma maneira ainda mais rápida para abrir uma janela de prompt de comando do desenvolvedor é inserir *prompt de comando do desenvolvedor* na caixa de pesquisa da área de trabalho, em seguida, escolha o resultado desejado.

## <a name="developer_command_file_locations"></a> Locais de arquivo de comando do desenvolvedor

Se você preferir configurar o ambiente de arquitetura de build em uma janela de prompt de comando existente, você pode usar um dos arquivos de comando (arquivos em lotes) criado pelo instalador para definir o ambiente necessário. Só recomendamos que você faça isso em uma nova janela de prompt de comando e não recomendamos que você altere os ambientes mais adiante na mesma janela de comando. O local desses arquivos depende a versão do Visual Studio que você instalou e no local e na nomenclatura escolhas feitas durante a instalação. Para Visual Studio 2017, o local de instalação típica em um computador de 64 bits é \Program arquivos (x86) \Microsoft Visual Studio\2017\\*edition*, onde *edition* pode ser a comunidade, Professional, Enterprise, BuildTools ou outro nome que você forneceu. Para Visual Studio 2015, o local de instalação típica é \Program Files (x86) \Microsoft 14.0 do Visual Studio.

O arquivo de comandos de prompt de comando do desenvolvedor principal, vsdevcmd. bat, está localizado no subdiretório Common7\Tools do diretório de instalação. Quando nenhum parâmetro for especificado, isso define o ambiente e o host e o destino compilar arquitetura para usar as ferramentas nativo x86 de 32 bits x86 de 32 bits de compilar código.

Arquivos de comando adicionais estão disponíveis para definir arquiteturas de compilação específica, dependendo da sua arquitetura de processador e as opções que você instalou e cargas de trabalho do Visual Studio. No Visual Studio 2017, eles estão localizados no subdiretório VC\Auxiliary\Build do diretório de instalação do Visual Studio. No Visual Studio 2015, eles estão localizados no VC, VC\bin ou VC\bin\\*arquiteturas* subdiretórios do diretório de instalação, onde *arquiteturas* é um dos nativo ou Opções do compilador cruzado. Esses arquivos de comando definir parâmetros padrão e chamar o vsdevcmd. bat para configurar o ambiente de arquitetura de compilação especificada. Uma instalação típica pode incluir esses arquivos de comando:

|Arquivo de comando|Arquiteturas de host e de destino|
|---|---|
|**vcvars32.bat**| Usar as ferramentas nativo x86 de 32 bits x86 de 32 bits de compilar código.|
|**vcvars64.bat**| Use as ferramentas nativo x64 de 64 bits para compilação de 64 bits x64 código.|
|**vcvarsx86_amd64.bat**| Use as ferramentas cruzadas do nativo x86 de 32 bits para compilação de 64 bits x64 código.|
|**vcvarsamd64_x86.bat**| Use as ferramentas cruzadas do x64 nativo de 64 bits para x86 de 32 bits de compilar código.|
|**vcvarsx86_arm.bat**| Use as ferramentas cruzadas do nativo x86 de 32 bits para compilar o código ARM.|
|**vcvarsamd64_arm.bat**| Use as ferramentas cruzadas do x64 nativo de 64 bits para compilar o código ARM.|
|**vcvarsall.bat**| Use parâmetros para especificar o host e arquiteturas de destino, bem como as opções de SDK e plataforma. Para obter uma lista de opções com suporte, chamar usando um **/Help** parâmetro.|

> [!CAUTION]
> O arquivo vcvarsall. bat e outros arquivos de comando do Visual Studio podem variar de um computador para outro. Não substitua um arquivo vcvarsall.bat não encontrado ou danificado usando um arquivo de outro computador. Execute novamente o instalador do Visual Studio para substituir o arquivo não encontrado.
>
> O arquivo vcvarsall.bat também varia de uma versão para outra. Se a versão atual do Visual Studio estiver instalada em um computador que também tem uma versão anterior do Visual Studio, não execute vcvarsall. bat ou em outro arquivo de comando do Visual Studio de versões diferentes na mesma janela do prompt de comando.

## <a name="use-the-developer-tools-in-an-existing-command-window"></a>Usar as ferramentas de desenvolvedor em uma janela de comando existente

É a maneira mais simples para especificar uma arquitetura de compilação específica em uma janela de comando existente usar o arquivo vcvarsall. bat. Você pode usar vcvarsall. bat para definir variáveis de ambiente para configurar a linha de comando para compilação nativa de 32 bits ou 64 bits, ou para compilação cruzada para x86, x64 ou processadores ARM; a Microsoft Store de destino, a plataforma Universal do Windows ou plataformas de área de trabalho do Windows; para especificar qual SDK do Windows deve usar. e para especificar a versão do conjunto de ferramentas de plataforma. Se nenhum argumento for fornecido, vcvarsall. bat configura as variáveis de ambiente para usar o compilador nativo de 32 bits atual para x86 destinos de área de trabalho do Windows. No entanto, você pode usá-lo para configurar qualquer uma das nativo ou entre as ferramentas do compilador. Se você especificar uma configuração de compilador que não está instalada ou não está disponível na arquitetura do computador de compilação, uma mensagem de erro é exibida.

### <a name="vcvarsall-syntax"></a>sintaxe de vcvarsall

> **vcvarsall.bat** [*architecture*] [*platform_type*] [*winsdk_version*] [**-vcvars_ver=**_vcversion_]

*architecture*<br/>
Esse argumento opcional especifica a arquitetura de host e de destino para usar. Se *arquitetura* não for especificado, o ambiente de compilação padrão será usado. Esses argumentos têm suporte:

|*architecture*|Compilador|Arquitetura do computador host|Criar a arquitetura de saída (destino)|
|----------------------------|--------------|----------------------------------|-------------------------------|
|**x86**|Nativa de 32 bits x86|x86, x64|x86|
|**x86\_amd64** ou **x86\_x64**|x64 em x86 cruzado|x86, x64|X64|
|**x86_arm**|ARM em x86 cruzado|x86, x64|ARM|
|**x86_arm64**|ARM64 em x86 cruzado|x86, x64|ARM64|
|**AMD64** ou **x64**|x64 nativo de 64 bits|X64|X64|
|**AMD64\_x86** ou **x64\_x86**|x86 em x64 cruzado|X64|x86|
|**AMD64\_arm** ou **x64\_arm**|ARM em x64 cruzado|X64|ARM|
|**AMD64\_arm64** ou **x64\_arm64**|ARM64 em x64 cruzado|X64|ARM64|

*platform_type*<br/>
Esse argumento opcional permite que você especifique **armazenar** ou **uwp** como o tipo de plataforma. Por padrão, o ambiente está definido para criar aplicativos de área de trabalho ou console.

*winsdk_version*<br/>
Opcionalmente, especifica a versão do SDK do Windows para usar. Por padrão, o SDK do Windows mais recente instalado é usado. Para especificar a versão do SDK do Windows, você pode usar como um número total de SDK do Windows 10 **10.0.10240.0**, ou especificar **8.1** para usar o SDK do Windows 8.1.

*vcversion*<br/>
Opcionalmente, especifica o conjunto de ferramentas do compilador Visual Studio para usar. Por padrão, o ambiente está definido para usar o conjunto de ferramentas do compilador do Visual Studio 2017 atual. Use **-vcvars_ver=14.0 = 14.0** para especificar o conjunto de ferramentas de compilador do Visual Studio 2015.

<a name="vcvarsall"></a>
#### <a name="to-set-up-the-build-environment-in-an-existing-command-prompt-window"></a>Para configurar o ambiente de compilação em uma janela de prompt de comando existente

1. No prompt de comando, use o comando CD para alterar para o diretório de instalação do Visual Studio. Em seguida, use CD novamente para mudar para a subpasta que contém os arquivos de comando específicas de configuração. Para o Visual Studio 2017, esse é o subdiretório VC\Auxiliary\Build. Para o Visual Studio 2015, use o subdiretório do VC.

1. Digite o comando para o seu ambiente de desenvolvedor preferencial. Por exemplo, para compilar o código ARM para UWP em uma plataforma de 64 bits usando o SDK mais recente do Windows e o conjunto de ferramentas do compilador Visual Studio 2017 RTM, use esta linha de comando:

   `vcvarsall.bat amd64_arm uwp -vcvars_ver=14.10`

## <a name="create-your-own-command-prompt-shortcut"></a>Criar seu próprio atalho de prompt de comando

Se você abrir a caixa de diálogo de propriedades para um dos atalhos de prompt de comando do desenvolvedor existente, você pode ver o destino do comando usado. Por exemplo, o destino para o **x64 Prompt de comando de ferramentas nativa para VS 2017** atalho é algo semelhante a:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"`

Conjunto de arquivos de lote específicos de arquitetura a *arquitetura* vcvarsall. bat de parâmetro e chamada. Você pode passar as mesmas opções adicionais para esses arquivos em lote, você passaria para vcvarsall. bat, ou você pode simplesmente chamar vcvarsall. bat diretamente. Para especificar parâmetros para seu próprio atalho do comando, adicioná-los ao final do comando entre aspas duplas. Por exemplo, para configurar um atalho para compilar o código ARM para UWP em uma plataforma de 64 bits usando o SDK mais recente do Windows e o conjunto de ferramentas do compilador Visual Studio 2017 RTM, use algo como o destino do comando em seu atalho:

`%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat amd64_arm uwp -vcvars_ver=14.10"`

Você deve ajustar o caminho para refletir seu diretório de instalação do Visual Studio.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

Para criar um projeto C/C++ na linha de comando, o Visual Studio fornece essas ferramentas de linha de comando:

[CL](reference/compiling-a-c-cpp-program.md)<br/>
Use o compilador (cl.exe) para compilar e vincular arquivos de código-fonte a aplicativos, bibliotecas e DLLs.

[Link](reference/linking.md)<br/>
Use o vinculador (link.exe) para vincular arquivos de objetos compilados e bibliotecas a aplicativos e DLLs.

[MSBuild](msbuild-visual-cpp.md)<br/>
Use MSBuild (msbuild.exe) e um arquivo de projeto (. vcxproj) para configurar uma compilação e invocar o conjunto de ferramentas indiretamente. Isso é equivalente a executar o **construir** projeto ou **compilar solução** no IDE do Visual Studio. Executando o MSBuild na linha de comando é um cenário avançado e geralmente não é recomendado.

[DEVENV](/visualstudio/ide/reference/devenv-command-line-switches)<br/>
Combine DEVENV (devenv.exe) combinado com uma opção de linha de comando — por exemplo, **/Build** ou **/Clean**— para executar determinados comandos de compilação sem exibir o IDE do Visual Studio. Em geral isso é preferível usar o MSBuild diretamente, porque você pode permitir que o Visual Studio manipule as complexidades do MSBuild.

[NMAKE](reference/nmake-reference.md)<br/>
Use NMAKE (nmake.exe) no Windows para compilar projetos do C++ com base em um makefile tradicional.

Quando você compila na linha de comando, o comando F1 não está disponível para obter ajuda instantânea. Em vez disso, você pode usar um mecanismo de pesquisa para obter informações sobre avisos, erros e mensagens, ou você pode usar os arquivos de Ajuda offline. Para usar a pesquisa no [docs.microsoft.com](https://docs.microsoft.com/cpp/), insira sua cadeia de caracteres de pesquisa na caixa de pesquisa na parte superior da página.

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
Descreve como iniciar uma janela de prompt de comando que tem as variáveis de ambiente necessárias definido para compilações de linha de comando que direcionam o x86, x64 e ARM plataformas usando um conjunto de ferramentas de 32 bits ou 64 bits.

[Referência a NMAKE](reference/nmake-reference.md)<br/>
Fornece links a artigos que descrevem o Microsoft Program Maintenance Utility (NMAKE.EXE).

[MSBuild na linha de comando – C++](msbuild-visual-cpp.md)<br/>
Fornece links para artigos que discutem como usar msbuild.exe da linha de comando.

## <a name="related-sections"></a>Seções relacionadas

[/MD, /MT, /LD (usar biblioteca de tempo de execução)](reference/md-mt-ld-use-run-time-library.md)<br/>
Descreve como usar essas opções do compilador para usar uma biblioteca de tempo de execução de depuração ou versão.

[Opções do compilador do C/C++](reference/compiler-options.md)<br/>
Fornece links a artigos que falam sobre as opções de compilador da linguagem C e C++ e sobre o CL.exe.

[Opções de vinculador MSVC](reference/linker-options.md)<br/>
Fornece links a artigos que falam sobre as opções do vinculador e sobre o LINK.exe.

[Ferramentas de Build do MSVC adicionais](reference/c-cpp-build-tools.md)<br/>
Fornece links para o C/C++ criam ferramentas que estão incluídas no Visual Studio.

## <a name="see-also"></a>Consulte também

[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)