---
title: "Compilar o código C/C++ na linha de comando | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs:
- C++
helpviewer_keywords:
- command-line builds [C++]
- compiling source code [C++], command line
- builds [C++], command-line
- command line [C++], building from
- command line [C++], compilers
ms.assetid: 7ca9daed-a003-4162-842d-908f79058365
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9f613c20e0cab45a8eaa802c4c7ba0c6ac391357
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="build-cc-code-on-the-command-line"></a>Compilar o código C/C++ na linha de comando

Você pode compilar aplicativos C e C++ na linha de comando usando as ferramentas presentes no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].

Quando você escolhe uma das cargas de trabalho C++ no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] instalador, ele instala um conjunto de ferramentas que inclui os compiladores do C/C++, vinculadores, e outras ferramentas de compilação. Essas ferramentas são usadas pelo [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] IDE e eles também podem ser usados na linha de comando. Há compiladores hospedado x86 e x64 hospedado separados e ferramentas para compilar o código para x86, x64 e ARM destinos. Cada conjunto de ferramentas para uma arquitetura de compilação do host e de destino específica é armazenado em seu próprio diretório. Para funcionar corretamente, essas ferramentas exigem várias variáveis de ambiente específico para adicioná-los para o caminho e definir incluem arquivos, o arquivo de biblioteca e locais de SDK. Para facilitar a definir essas variáveis de ambiente, o instalador cria arquivos de comando personalizado, também conhecidos como arquivos em lotes, durante a instalação. Você pode executar um desses arquivos de comando em uma janela de prompt de comando para definir uma arquitetura de compilação específica. Para sua conveniência, o instalador também cria atalhos no menu Iniciar (ou a página inicial no Windows 8. x) que iniciar janelas de prompt de comando do desenvolvedor, usando esses arquivos de comando, para todas as variáveis de ambiente necessárias são definido e pronta para uso. 

As variáveis de ambiente necessárias são específicas para sua instalação e a arquitetura de compilação escolha e pode ser alterado por atualizações de produto. Portanto, é altamente recomendável que você use uma do prompt de comando instalada atalhos ou arquivos de comando em vez de configurar as variáveis de ambiente no Windows. Para obter mais informações, consulte [definir o caminho e as variáveis de ambiente para compilações de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md).  

Os conjuntos de ferramentas de linha de comando, arquivos de comando e atalhos do prompt de comando que são instalados dependem o processador do computador e as opções selecionadas durante a instalação. No mínimo, as ferramentas hospedado x86 de 32 bits que compilar o código nativo x86 de 32 bits e cross ferramentas de compilação do código x64 nativo de 64 bits são instaladas. Se você tiver o Windows de 64 bits, as ferramentas de 64 bits x64 hospedado que compilar o código nativo de 64 bits e cross ferramentas de compilação de código nativo de 32 bits são instaladas também. Se você optar por instalar as ferramentas de plataforma Universal do Windows C++ opcionais, as ferramentas nativas de 32 bits e 64 bits que compilar código ARM também são instaladas. Outras cargas de trabalho podem instalar ferramentas adicionais.

<a name="developer_command_prompt_shortcuts"></a>
## <a name="developer-command-prompt-shortcuts"></a>Atalhos de prompt de comando do desenvolvedor

Os atalhos de prompt de comando estão instalados em uma determinada versão [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] pasta no menu Iniciar. Aqui está uma lista de atalhos do prompt de comando base e as arquiteturas de compilação que eles oferecem suporte a:

- **Prompt de comando do desenvolvedor** define o ambiente para usar as ferramentas de 32 bits x86 nativo para compilar o código nativo x86 de 32 bits.  
- **x86 Prompt de comando de ferramentas nativas** define o ambiente para usar as ferramentas de 32 bits x86 nativo para compilar o código nativo x86 de 32 bits.  
- **x64 nativo Prompt de comando de ferramentas** define o ambiente para usar as ferramentas de 64 bits, x64 nativo para compilar o código de 64 bits, x64 nativo.  
- **Prompt de comando de ferramentas cruzadas x86_x64** define o ambiente para usar as ferramentas de 32 bits x86 nativo para compilar o código de 64 bits, x64 nativo.  
- **Prompt de comando de ferramentas cruzadas x64_x86** define o ambiente para usar as ferramentas de 64 bits, x64 nativo para compilar o código nativo x86 de 32 bits.  

Iniciar menu pasta e o atalho nomes reais variam dependendo da versão do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] você instalou e a instalação apelido se você definir um. Por exemplo, se você tiver o Visual Studio de 2017 instalado e você deu a ele uma instalação apelido do 15,3, atalho do prompt de comando do desenvolvedor é denominado **Prompt de comando do desenvolvedor para VS 2017 (15,3)**, em uma pasta chamada  **Visual Studio de 2017**. 

Se você tiver instalado o [Build Tools para Visual Studio de 2017](https://go.microsoft.com/fwlink/p/?linkid=840931) ou [criar ferramentas do Visual C++ 2015](http://landinghub.visualstudio.com/visual-cpp-build-tools) edition, só pode ser nativo específico ou opções de prompt de comando do desenvolvedor de ferramentas cruzadas. 

<a name="developer_command_prompt"></a>
## <a name="to-open-a-developer-command-prompt-window"></a>Para abrir uma janela de prompt de comando do desenvolvedor  
  
1.  Na área de trabalho, abra o Windows **iniciar** menu e, em seguida, role para localizar e abrir a pasta para a sua versão do Visual Studio, por exemplo, **2017 do Visual Studio**. Em algumas versões mais antigas do Visual Studio, os atalhos estão em uma subpasta chamada **ferramentas do Visual Studio**.  
  
2.  Na pasta, escolha o **Prompt de comando do desenvolvedor** para sua versão do Visual Studio. Esse atalho inicia uma janela de prompt de comando do desenvolvedor que usa a arquitetura de compilação padrão das ferramentas de 32 bits x86 nativo para compilar o código nativo x86 de 32 bits. Se você preferir uma arquitetura de compilação não padrão, escolha uma das nativo ou prompts de comando para especificar a arquitetura de host e de destino de ferramentas cruzadas. 

Uma maneira ainda mais rápida para abrir uma janela de prompt de comando do desenvolvedor é inserir *prompt de comando do desenvolvedor* na caixa de pesquisa de área de trabalho, escolha o resultado desejado.

<a name="developer_command_files"></a>
## <a name="developer-command-files-and-locations"></a>Locais e arquivos de comando do desenvolvedor

Se você preferir definir o ambiente de arquitetura de compilação em uma janela de prompt de comando existente, você pode usar um dos arquivos de comando criados pelo instalador. O local desses arquivos depende da versão de [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] você instalou e no local e a nomeação de escolhas feitas durante a instalação. Para o Visual Studio de 2017, o local de instalação típica em um computador de 64 bits é \Program arquivos (x86) \Microsoft Visual Studio\2017\\*edição*, onde *edição* comunidade, é possível Professional, Enterprise, BuildTools ou outro nome que você forneceu. Para Visual Studio 2015, o local de instalação típica é \Program Files (x86) \Microsoft 14.0 do Visual Studio. 

O arquivo de comandos de prompt de comando do desenvolvedor principal, VsDevCmd.bat, está localizado no subdiretório Common7\Tools do diretório de instalação. Quando nenhum parâmetro for especificado, define a arquitetura de compilação e de ambiente para usar as ferramentas de nativo x86 de 32 bits para x86 de 32 bits de compilação código.

Arquivos de comando adicionais estão disponíveis para configurar as arquiteturas de compilação específica, dependendo da sua arquitetura de processador e a [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] cargas de trabalho e opções que você instalou. No Visual Studio de 2017, eles estão localizados no subdiretório VC\Auxiliary\Build do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] diretório de instalação. No Visual Studio 2015, eles estão localizados no VC, VC\bin ou VC\bin\\*arquiteturas* subdiretórios do diretório de instalação, onde *arquiteturas* é uma das nativo ou cruzada Opções do compilador. Esses arquivos de comando definir parâmetros e chame VsDevCmd.bat para configurar o ambiente de arquitetura de compilação especificada. Uma instalação típica pode incluir esses arquivos de comando:

- **vcvars32.bat** usar as ferramentas de nativo x86 de 32 bits para x86 de 32 bits de compilação código.  
- **vcvars64.bat** usar as ferramentas de x64 nativo de 64 bits para compilação de 64 bits x64 código.  
- **vcvarsx86_amd64.bat** usar as ferramentas cruzadas do nativo x86 de 32 bits para 64 bits x64 de compilação código.  
- **vcvarsamd64_x86.bat** usar as ferramentas cruzadas do x64 nativo de 64 bits para x86 de 32 bits de compilar código.  
- **vcvarsx86_arm.bat** usar as ferramentas cruzadas do nativo x86 de 32 bits para compilar código ARM.  
- **vcvarsamd64_arm.bat** usar as ferramentas cruzadas do x64 nativo de 64 bits para compilar código ARM.  
- **vcvarsall.bat** usa parâmetros para especificar o host e arquiteturas de destino, bem como as opções de SDK e plataforma. Chamar usando um `/help` parâmetro para uma lista de opções.  

> [!CAUTION]
>  O arquivo vcvarsall.bat e outros arquivos de comando podem variar de um computador para outro. Não substitua um arquivo vcvarsall.bat não encontrado ou danificado usando um arquivo de outro computador. Execute novamente o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] instalador para substituir o arquivo ausente.  
>   
> O arquivo vcvarsall.bat também varia de uma versão para outra. Se a versão atual do Visual C++ está instalada em um computador que também tem uma versão anterior do Visual C++, não execute vcvarsall.bat ou em outro arquivo de comando de versões diferentes na mesma janela do prompt de comando.  
 
É a maneira mais simples para especificar uma arquitetura de compilação específica em uma janela de comando existente usar o arquivo vcvarsall.bat. Você pode usar vcvarsall.bat para definir variáveis de ambiente para configurar a linha de comando de compilação nativa de 32 bits ou 64 bits ou de compilação cruzada para x86, x64 ou ARM processadores; destino Microsoft Store, plataforma Universal do Windows ou plataformas de área de trabalho do Windows; para especificar quais SDK do Windows será usado; e para especificar a versão do conjunto de ferramentas de plataforma. Se nenhum argumento for fornecido, vcvarsall.bat configura as variáveis de ambiente para usar o compilador nativo de 32 bits atual para x86 de destinos de área de trabalho do Windows. No entanto, você pode usá-lo para configurar qualquer uma das nativo ou entre as ferramentas de compilador. Se você especificar uma configuração de compilador que não está instalada ou não está disponível em sua arquitetura de computador de compilação, uma mensagem de erro será exibida. Esta tabela mostra os argumentos de arquitetura com suporte:  
  
|Argumento de arquitetura de Vcvarsall.bat|Compilador|Arquitetura do computador host|Arquitetura de saída de compilação|  
|----------------------------|--------------|----------------------------------|-------------------------------|  
|x86|Nativa de 32 bits x86|x86, x64|x86|  
|x86\_amd64 ou x86\_x64|cross x64 x86|x86, x64|X64|  
|x86_arm|ARM em x86 cruzado|x86, x64|ARM|  
|AMD64 ou x64|x64 nativo de 64 bits|X64|X64|  
|AMD64\_x86 ou x64\_x86|cross x86 em x64|X64|x86|  
|AMD64\_arm ou x64\_arm|Prepare-se em x64 cruzada|X64|ARM|  
  
Você pode usar o **armazenar** ou **uwp** opções para especificar o tipo de plataforma ou nenhum para especificar um aplicativo de área de trabalho. Para especificar a versão do SDK do Windows, você pode usar um número total de SDK do Windows 10 como 10.0.10240.0 ou especifique 8.1 para usar o SDK do Windows 8.1. Use 14.0 para especificar o conjunto de ferramentas de compilador do Visual Studio 2015; Por padrão, o ambiente está configurado para usar o conjunto de ferramentas de compilador do Visual Studio de 2017.

<a name="vcvarsall"></a>
## <a name="to-set-up-the-build-environment-in-an-existing-command-prompt-window"></a>Para configurar o ambiente de compilação em uma janela de prompt de comando existente  
  
1.  No prompt de comando, use o comando CD para alterar para o diretório de instalação do Visual Studio. Em seguida, use novamente para mudar para a subpasta que contém os arquivos de comando específicas de configuração. Para Visual Studio de 2017, esse é o subdiretório VC\Auxiliary\Build. Para Visual Studio 2015, use o subdiretório do VC.  
  
1.  Para configurar esta janela de prompt de comando para usar ferramentas de 32 bits para compilar o código para x86 de plataformas, no prompt de comando, digite:  
  
     `vcvarsall`  

1.  Para configurar esta janela de prompt de comando para usar ferramentas de 32 bits para compilar o código para x64 plataformas, no prompt de comando, digite:  
  
     `vcvarsall x86_amd64`  
  
1.  Para configurar esta janela de prompt de comando para usar ferramentas de 32 bits para compilar o código para plataformas ARM, no prompt de comando, digite:  
  
     `vcvarsall x86_arm`  
  
1.  Para configurar esta janela de prompt de comando para usar ferramentas de 64 bits para compilar o código para x64 plataformas, no prompt de comando, digite:  
  
     `vcvarsall amd64`  
  
1.  Para configurar esta janela de prompt de comando para usar ferramentas de 64 bits para compilar o código para x86 de plataformas, no prompt de comando, digite:  
  
     `vcvarsall amd64_x86`  
  
1.  Para configurar esta janela de prompt de comando para usar ferramentas de 64 bits para compilar o código para plataformas ARM, no prompt de comando, digite:  
  
     `vcvarsall amd64_arm`  

O arquivo de comando define as variáveis de ambiente necessário para os caminhos para as ferramentas de compilação, bibliotecas e cabeçalhos. Agora você pode usar essa janela de prompt de comando para executar as ferramentas e o compilador de linha de comando.  
  
Se você estiver usando [DEVENV](/visualstudio/ide/reference/devenv-command-line-switches) para compilações de linha de comando, o ambiente definido por vcvarsall.bat ou outros arquivos de comando não afeta suas compilações, a menos que você também especificar o **/useenv** opção.  

## <a name="command-line-tools"></a>Ferramentas de linha de comando
  
Para criar um projeto de C/C++ na linha de comando, você pode usar essas ferramentas de linha de comando do Visual C++:  
  
[CL](../build/reference/compiling-a-c-cpp-program.md)  
Use o compilador (cl.exe) para compilar e vincular arquivos de código-fonte a aplicativos, bibliotecas e DLLs.  
  
[Link](../build/reference/linking.md)  
Use o vinculador (link.exe) para vincular arquivos de objetos compilados e bibliotecas a aplicativos e DLLs.  
  
[MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)  
Usar o MSBuild (msbuild.exe) para criar projetos do Visual C++ e [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] soluções. Isso é equivalente a executar o **criar** projeto ou **compilar solução** do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] IDE.  
  
[DEVENV](/visualstudio/ide/reference/devenv-command-line-switches)  
Use DEVENV (devenv.exe) combinada com uma opção de linha de comando — por exemplo, **compilação** ou **/limpar**— para executar certos comandos de construção sem exibir o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] IDE.  
  
[NMAKE](../build/nmake-reference.md)  
Use NMAKE (nmake.exe) para automatizar tarefas que compila projetos do Visual C++ usando um makefile tradicional.  
  
Quando você compila na linha de comando, você pode obter informações sobre os avisos, erros e mensagens. Iniciar [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] e, em seguida, na barra de menus, escolha **ajuda**, **pesquisa**.  
  
## <a name="in-this-section"></a>Nesta seção  

Os artigos desta seção da documentação mostram como compilar aplicativos na linha de comando, descrevem como personalizar o ambiente de compilação da linha de comando para usar conjuntos de ferramentas de 64 bits, segmentar plataformas x86, x64 e ARM e demonstrar como usar as ferramentas de compilação de linha de comando MSBuild e NMAKE.  
  
[Instruções passo a passo: compilando um programa do C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md)  
Apresenta um exemplo que mostra como criar e compilar um programa C++ simples na linha de comando.  
  
[Passo a passo: Compilar um programa em C na linha de comando](../build/walkthrough-compile-a-c-program-on-the-command-line.md)  
Descreve como compilar um programa gravado na linguagem de programação C.  
  
[Instruções passo a passo: compilando um programa C++/CLI na linha de comando](../build/walkthrough-compiling-a-cpp-cli-program-on-the-command-line.md)  
Descreve como criar e compilar um programa C++/CLI que usa o .NET Framework.  
  
[Instruções passo a passo: compilando um programa C++/CX na linha de comando](../build/walkthrough-compiling-a-cpp-cx-program-on-the-command-line.md)  
Descreve como criar e compilar um programa C++/CX que usa o Tempo de Execução do Windows.  
  
[Definir o caminho e variáveis de ambiente para builds de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md)  
Descreve como iniciar uma janela de prompt de comando com as variáveis de ambiente necessário definido para compilações de linha de comando que visam x86, x64 e ARM plataformas usando um conjunto de ferramentas de 32 bits ou 64 bits.  
  
[Referência a NMAKE](../build/nmake-reference.md)  
Fornece links a artigos que descrevem o Microsoft Program Maintenance Utility (NMAKE.EXE).  
  
[MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)  
Fornece links a artigos que explicam como usar o MSBuild.EXE.  
  
## <a name="related-sections"></a>Seções relacionadas  

[/MD, /MT, /LD (usar biblioteca de tempo de execução)](../build/reference/md-mt-ld-use-run-time-library.md)  
Descreve como usar essas opções do compilador para usar uma biblioteca de tempo de execução de depuração ou versão.  
  
[Opções do compilador C/C++](../build/reference/compiler-options.md)  
Fornece links a artigos que falam sobre as opções de compilador da linguagem C e C++ e sobre o CL.exe.  
  
[Opções do vinculador](../build/reference/linker-options.md)  
Fornece links a artigos que falam sobre as opções do vinculador e sobre o LINK.exe.  
  
[Ferramentas de build de C/C++](../build/reference/c-cpp-build-tools.md)  
Fornece links às ferramentas de compilação da linguagem C/C++ incluídas no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
## <a name="see-also"></a>Consulte também  

[Compilando programas do C/C++](../build/building-c-cpp-programs.md)