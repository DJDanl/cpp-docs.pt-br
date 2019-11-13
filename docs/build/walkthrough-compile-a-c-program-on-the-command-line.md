---
title: 'Walkthrough: compilar um programa C na linha de comando'
ms.custom: conceptual
ms.date: 04/25/2019
helpviewer_keywords:
- command-line applications [C++], C programs
- Visual C, compiling
- compiling programs [C++]
- C program compiling [C++]
ms.assetid: 7e74cc2d-54b1-49de-b7ad-d3ae6b39ab8d
ms.openlocfilehash: d91ee36d26e307577aa56560eb95bef5ed03305b
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051528"
---
# <a name="walkthrough-compile-a-c-program-on-the-command-line"></a>Walkthrough: compilar um programa C na linha de comando

O C++ Visual inclui um compilador C que você pode usar para criar tudo, desde programas de console básicos até aplicativos completos de área de trabalho do Windows, aplicativos móveis e muito mais.

Este tutorial mostra como criar um programa C de estilo "Olá, mundo" e básico usando um editor de texto e, em seguida, compilá-lo na linha de comando. Se você preferir trabalhar C++ na linha de comando, confira [explicação: Compilando um programa C++ nativo na linha de comando](walkthrough-compiling-a-native-cpp-program-on-the-command-line.md). Se você quiser experimentar o IDE do Visual Studio em vez de usar a linha de comando, consulte [passo a passos: trabalhando com projetosC++e soluções ()](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) ou [usando o IDE C++ do Visual Studio para desenvolvimento de área de trabalho](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

## <a name="prerequisites"></a>Prerequisites

Para concluir este passo a passos, você deve ter instalado o Visual Studio e os C++ componentes visuais opcionais ou as ferramentas de compilação para o Visual Studio.

O Visual Studio é um poderoso ambiente de desenvolvimento integrado que dá suporte a um editor completo, gerenciadores de recursos, depuradores e compiladores para muitas linguagens e plataformas. Para obter informações sobre esses recursos e como baixar e instalar o Visual Studio, incluindo o Visual Studio Community Edition gratuito, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

As ferramentas de Build para a versão do Visual Studio do Visual Studio instalam apenas o conjunto de ferramentas de linha de comando, os compiladores, as ferramentas e C++ as bibliotecas necessárias para criar C e programas. É perfeito para os laboratórios de compilação ou exercícios de sala de aula e é instalado de forma relativamente rápida. Para instalar apenas o conjunto de ferramentas de linha de comando, baixe ferramentas de compilação para Visual Studio na página de [downloads do Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019) e execute o instalador. No instalador do Visual Studio, selecione a carga de trabalho  **C++ ferramentas de compilação** e escolha **instalar**.

Antes de criar um C ou C++ programa na linha de comando, você deve verificar se as ferramentas estão instaladas e se pode acessá-las na linha de comando. O C++ Visual tem requisitos complexos para o ambiente de linha de comando para localizar as ferramentas, os cabeçalhos e as bibliotecas que ele usa. **Você não pode usar C++ o Visual em uma janela de prompt de comando simples** sem alguma preparação. Você precisa de uma janela de *prompt de comando do desenvolvedor* , que é uma janela de prompt de comando regular que tem todas as variáveis de ambiente necessárias definidas. Felizmente, o C++ Visual instala atalhos para que você inicie prompts de comando do desenvolvedor que têm o ambiente configurado para compilações de linha de comando. Infelizmente, os nomes dos atalhos de prompt de comando do desenvolvedor e onde eles estão localizados são diferentes em quase todas as C++ versões do Visual e em versões diferentes do Windows. Sua primeira tarefa de explicação é encontrar o atalho correto a ser usado.

> [!NOTE]
> Um atalho do prompt de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e as ferramentas e para quaisquer cabeçalhos e bibliotecas necessários. Alguns desses valores são diferentes para cada configuração de compilação. Você deve definir esses valores de ambiente por conta própria se não usar um dos atalhos. Para obter mais informações, confira [Definir o caminho e as variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md). Como o ambiente de compilação é complexo, é altamente recomendável usar um atalho de prompt de comando do desenvolvedor em vez de criar o seu próprio.

Essas instruções variam de acordo com a versão do Visual Studio que você está usando. Antes de continuar, verifique se o seletor de versão no canto superior esquerdo desta página está definido corretamente.

::: moniker range="vs-2019"

## <a name="open-a-developer-command-prompt-in-visual-studio-2019"></a>Abrir um prompt de comando do desenvolvedor no Visual Studio 2019

Se você instalou o Visual Studio 2019 no Windows 10, abra o menu iniciar e, em seguida, role para baixo e abra a pasta **visual studio 2019** (não o aplicativo visual Studio 2019). Escolha **prompt de comando do desenvolvedor para VS 2019** para abrir a janela de prompt de comando.

Se você estiver usando uma versão diferente do Windows, examine o menu iniciar ou a página inicial de uma pasta de ferramentas do Visual Studio que contenha um atalho de prompt de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar "prompt de comando do desenvolvedor" e escolher um que corresponda à versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.

::: moniker-end

::: moniker range="vs-2017"

## <a name="open-a-developer-command-prompt-in-visual-studio-2017"></a>Abrir um prompt de comando do desenvolvedor no Visual Studio 2017

Se você instalou o Visual Studio 2017 no Windows 10, abra o menu iniciar e, em seguida, role para baixo e abra a pasta **visual studio 2017** (não o aplicativo visual Studio 2017). Escolha **prompt de comando do desenvolvedor para VS 2017** para abrir a janela de prompt de comando.

Se você estiver executando uma versão diferente do Windows, examine o menu iniciar ou a página inicial de uma pasta de ferramentas do Visual Studio que contenha um atalho de prompt de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar "prompt de comando do desenvolvedor" e escolher um que corresponda à versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.

::: moniker-end

::: moniker range="vs-2015"

## <a name="open-a-developer-command-prompt-in-visual-studio-2015"></a>Abrir um prompt de comando do desenvolvedor no Visual Studio 2015

Se você instalou as ferramentas de C++ compilação do Microsoft Visual 2015 no Windows 10, abra o menu **Iniciar** e, em seguida, role para baixo e abra a pasta **ferramentas de Build Visual C++**  . Escolha **Visual C++ 2015 prompt de comando de ferramentas nativas do x86** para abrir a janela de prompt de comando.

Se você estiver executando uma versão diferente do Windows, examine o menu iniciar ou a página inicial de uma pasta de ferramentas do Visual Studio que contenha um atalho de prompt de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar "prompt de comando do desenvolvedor" e escolher um que corresponda à versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.
   
::: moniker-end


Em seguida, verifique se o C++ prompt de comando do Visual Developer está configurado corretamente. Na janela do prompt de comando, digite `cl` e verifique se a saída é semelhante a esta:

```Output
C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>cl
Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

Pode haver diferenças no diretório atual ou nos números de versão, dependendo da versão do Visual C++ e das atualizações instaladas. Se a saída acima for semelhante ao que você vê, você estará pronto para criar C ou C++ programas na linha de comando.

> [!NOTE]
> Se você receber um erro como "' CL ' não é reconhecido como um comando interno ou externo, um programa ou arquivo de lote operável," erro C1034 ou erro LNK1104 ao executar o comando **CL** , você não está usando um prompt de comando do desenvolvedor ou algo está errado com a instalação do Visual C++. Você deve corrigir esse problema antes de continuar.

Se você não encontrar o atalho do prompt de comando do desenvolvedor ou se receber uma mensagem de erro ao inserir `cl`, a instalação C++ do Visual poderá ter um problema. Se você estiver usando o Visual Studio 2017 ou posterior, Tente reinstalar o **desenvolvimento de desktop C++ com** a carga de trabalho no instalador do Visual Studio. Para obter detalhes, [consulte C++ instalar o suporte no Visual Studio](vscpp-step-0-installation.md). Ou então, reinstale as ferramentas de Build da página de [downloads do Visual Studio](https://visualstudio.microsoft.com/downloads/) . Não vá para a próxima seção até que isso funcione. Para obter mais informações sobre como instalar e solucionar problemas do Visual Studio, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

> [!NOTE]
> Dependendo da versão do Windows no computador e da configuração de segurança do sistema, talvez seja necessário clicar com o botão direito do mouse para abrir o menu de atalho para o atalho do prompt de comando do desenvolvedor e escolher **Executar como administrador** para compilar e executar com êxito o programa que você criar, seguindo este passo a passos.

## <a name="create-a-c-source-file-and-compile-it-on-the-command-line"></a>Criar um arquivo de origem C e compilá-lo na linha de comando

1. Na janela do prompt de comando do desenvolvedor, digite `cd c:\` para alterar o diretório de trabalho atual para a raiz da unidade C:. Em seguida, insira `md c:\simple` para criar um diretório e, em seguida, insira `cd c:\simple` para alterar para esse diretório. Esse diretório manterá o arquivo de origem e o programa compilado.

1. Insira `notepad simple.c` no prompt de comando do desenvolvedor. Na caixa de diálogo de alerta do bloco de notas que aparece, escolha **Sim** para criar um novo arquivo. c simples em seu diretório de trabalho.

1. No bloco de notas, insira as seguintes linhas de código:

    ```C
    #include <stdio.h>

    int main()
    {
        printf("Hello, World! This is a native C program compiled on the command line.\n");
        return 0;
    }
    ```

1. Na barra de menus do bloco de notas, escolha **arquivo** > **salvar** para salvar o Simple. c em seu diretório de trabalho.

1. Volte para a janela do prompt de comando do desenvolvedor. Insira `dir` no prompt de comando para listar o conteúdo do diretório c:\simple. Você deve ver o arquivo de origem Simple. c na listagem de diretório, que se parece com:

    ```Output
    C:\simple>dir
     Volume in drive C has no label.
     Volume Serial Number is CC62-6545

     Directory of C:\simple

    10/02/2017  03:46 PM    <DIR>          .
    10/02/2017  03:46 PM    <DIR>          ..
    10/02/2017  03:36 PM               143 simple.c
                   1 File(s)            143 bytes
                   2 Dir(s)  514,900,566,016 bytes free

    ```

   As datas e outros detalhes serão diferentes no seu computador. Se você não vir o arquivo de código-fonte, Simple. c, certifique-se de ter alterado para o diretório c:\simple que você criou e, no bloco de notas, certifique-se de que você salvou o arquivo de origem nesse diretório. Além disso, certifique-se de que você salvou o código-fonte com uma extensão de nome de arquivo. c, não uma extensão. txt.

1. Para compilar seu programa, insira `cl simple.c` no prompt de comando do desenvolvedor.

   Você pode ver o nome do programa executável, Simple. exe, nas linhas de informações de saída que o compilador exibe:

    ```Output
    c:\simple>cl simple.c
    Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
    Copyright (C) Microsoft Corporation.  All rights reserved.

    simple.c
    Microsoft (R) Incremental Linker Version 14.10.25017.0
    Copyright (C) Microsoft Corporation.  All rights reserved.

    /out:simple.exe
    simple.obj
    ```

   > [!NOTE]
   > Se você receber um erro como "' CL ' não é reconhecido como um comando interno ou externo, um programa ou arquivo de lote operável," Error C1034 ou Error LNK1104, o prompt de comando do desenvolvedor não está configurado corretamente. Para obter informações sobre como corrigir esse problema, volte para a seção **abrir um prompt de comando do desenvolvedor** .

   > [!NOTE]
   > Se você obtiver um erro ou aviso do vinculador ou de um compilador diferente, examine o código-fonte para corrigir os erros, salve-o e execute o compilador novamente. Para obter informações sobre erros específicos, use a caixa de pesquisa na parte superior desta página para procurar o número do erro.

1. Para executar o programa, digite `simple` no prompt de comando.

   O programa exibe este texto e fecha na sequência:

    ```Output
    Hello, World! This is a native C program compiled on the command line.
    ```

   Parabéns, você compilou e executou um programa C usando a linha de comando.

## <a name="next-steps"></a>Próximas etapas

Esse exemplo de "Olá, mundo" é tão simples quanto um programa C pode ser obtido. Os programas do mundo real têm arquivos de cabeçalho e mais arquivos de origem, link em bibliotecas e trabalho útil.

Você pode usar as etapas neste passo a passos para criar seu próprio código C em vez de digitar o código de exemplo mostrado. Você também pode criar muitos programas de exemplo de código C que você encontrar em outro lugar. Para compilar um programa que tenha arquivos de código-fonte adicionais, insira todos eles na linha de comando, como:

`cl file1.c file2.c file3.c`

O compilador gera um programa chamado arquivo1. exe. Para alterar o nome para Program1. exe, adicione uma opção de vinculador [/out](reference/out-output-file-name.md) :

`cl file1.c file2.c file3.c /link /out:program1.exe`

E para detectar mais erros de programação automaticamente, recomendamos que você compile usando a opção de nível de aviso [/w3](reference/compiler-option-warning-level.md) ou [/W4](reference/compiler-option-warning-level.md) :

`cl /W4 file1.c file2.c file3.c /link /out:program1.exe`

O compilador, CL. exe, tem muitas outras opções que você pode aplicar para compilar, otimizar, depurar e analisar seu código. Para obter uma lista rápida, digite `cl /?` no prompt de comando do desenvolvedor. Você também pode compilar e vincular separadamente e aplicar opções de vinculador em cenários de compilação mais complexos. Para obter mais informações sobre as opções e o uso do compilador e do vinculador, consulte [C/C++ Build Reference](reference/c-cpp-building-reference.md).

Você pode usar NMAKE e makefiles, ou arquivos MSBuild e Project para configurar e compilar projetos mais complexos na linha de comando. Para obter mais informações sobre como usar essas ferramentas, consulte [referência do NMAKE](reference/nmake-reference.md) e [MSBuild](msbuild-visual-cpp.md).

As linguagens C++ C e são semelhantes, mas não as mesmas. O Microsoft C/C++ Compiler (MSVC) usa uma regra simples para determinar qual idioma usar ao compilar seu código. Por padrão, o compilador MSVC trata todos os arquivos que terminam em. c como código-fonte C e todos os arquivos que terminam C++ em. cpp como código-fonte. Para forçar o compilador a tratar todos os arquivos como C não dependente da extensão de nome de arquivo, use a opção de compilador [/TC](reference/tc-tp-tc-tp-specify-source-file-type.md) .

O MSVC é compatível com o padrão ISO C99, mas não é estritamente compatível. Na maioria dos casos, o código C portátil será compilado e executado conforme o esperado. O C++ Visual não dá suporte à maioria das alterações no C11 ISO. Certas funções de biblioteca e nomes de função POSIX são preteridos pelo MSVC. As funções têm suporte, mas os nomes preferenciais foram alterados. Para obter mais informações, consulte [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md) e [aviso do compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).

## <a name="see-also"></a>Consulte também

[Passo a passo: criando um programa C++ padrão (C++)](../windows/walkthrough-creating-a-standard-cpp-program-cpp.md)<br/>
[Referência da linguagem C](../c-language/c-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br/>
[Compatibilidade](../c-runtime-library/compatibility.md)
