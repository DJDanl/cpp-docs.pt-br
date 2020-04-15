---
title: 'Instruções passo a passo: compilar um programa em C na linha de comando'
ms.custom: conceptual
ms.date: 04/25/2019
helpviewer_keywords:
- command-line applications [C++], C programs
- Visual C, compiling
- compiling programs [C++]
- C program compiling [C++]
ms.assetid: 7e74cc2d-54b1-49de-b7ad-d3ae6b39ab8d
ms.openlocfilehash: d807fa75b32b515c2222fec9ea9d070266303e33
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335256"
---
# <a name="walkthrough-compile-a-c-program-on-the-command-line"></a>Instruções passo a passo: compilar um programa em C na linha de comando

O Visual C++ inclui um compilador C que você pode usar para criar tudo, desde programas básicos de console até aplicativos completos do Windows Desktop, aplicativos móveis e muito mais.

Este passo a passo mostra como criar um programa C básico, estilo "Hello, World", usando um editor de texto e, em seguida, compilá-lo na linha de comando. Se preferir trabalhar em C++ na linha de comando, consulte [Passo a Passo: Compilando um Programa C++ nativo na linha de comando](walkthrough-compiling-a-native-cpp-program-on-the-command-line.md). Se você quiser experimentar o Visual Studio IDE em vez de usar a linha de comando, consulte [Passo a Passo: Trabalhando com Projetos e Soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) ou [Usando o Visual Studio IDE para Desenvolvimento de Desktop C++.](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md)

## <a name="prerequisites"></a>Pré-requisitos

Para completar este passo a passo, você deve ter instalado o Visual Studio e os componentes opcionais Do Visual C++, ou o Build Tools for Visual Studio.

O Visual Studio é um poderoso ambiente de desenvolvimento integrado que suporta um editor completo, gerentes de recursos, depuradores e compiladores para muitos idiomas e plataformas. Para obter informações sobre esses recursos e como baixar e instalar o Visual Studio, incluindo a edição gratuita do Visual Studio Community, consulte [Install Visual Studio](/visualstudio/install/install-visual-studio).

A versão Build Tools for Visual Studio do Visual Studio instala apenas o conjunto de ferramentas de linha de comando, os compiladores, ferramentas e bibliotecas que você precisa para construir programas C e C++. É perfeito para construir laboratórios ou exercícios em sala de aula e instala-se relativamente rapidamente. Para instalar apenas o conjunto de ferramentas de linha de comando, baixe Build Tools for Visual Studio na página [de downloads](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019) do Visual Studio e execute o instalador. No instalador do Visual Studio, selecione a carga de trabalho das **ferramentas de compilação C++** e escolha **Instalar**.

Antes de construir um programa C ou C++ na linha de comando, você deve verificar se as ferramentas estão instaladas e que você pode acessá-las a partir da linha de comando. O Visual C++ tem requisitos complexos para que o ambiente de linha de comando encontre as ferramentas, cabeçalhos e bibliotecas que usa. **Você não pode usar o Visual C++ em uma janela de prompt de comando simples** sem alguma preparação. Você precisa de uma janela *de prompt de comando do desenvolvedor,* que é uma janela de prompt de comando regular que tem todas as variáveis de ambiente necessárias definidas. Felizmente, o Visual C++ instala atalhos para você lançar solicitações de comando de desenvolvedor que têm o ambiente configurado para compilações de linhas de comando. Infelizmente, os nomes dos atalhos de prompt de comando do desenvolvedor e onde eles estão localizados são diferentes em quase todas as versões do Visual C++ e em diferentes versões do Windows. Sua primeira tarefa passo a passo é encontrar o atalho certo para usar.

> [!NOTE]
> Um atalho de solicitação de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e as ferramentas e para quaisquer cabeçalhos e bibliotecas necessários. Alguns desses valores são diferentes para cada configuração de compilação. Você deve definir esses valores de ambiente se você não usar um dos atalhos. Para obter mais informações, confira [Definir o caminho e as variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md). Como o ambiente de construção é complexo, recomendamos fortemente que você use um atalho de solicitação de comando do desenvolvedor em vez de construir o seu próprio.

Essas instruções variam dependendo da versão do Visual Studio que você está usando. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

## <a name="open-a-developer-command-prompt-in-visual-studio-2019"></a>Abra um prompt de comando de desenvolvedor no Visual Studio 2019

Se você instalou o Visual Studio 2019 no Windows 10, abra o menu Iniciar e, em seguida, role para baixo e abra a pasta **Visual Studio 2019** (não o aplicativo Visual Studio 2019). Escolha **o Prompt de comando do desenvolvedor para VS 2019** para abrir a janela de solicitação de comando.

Se você estiver usando uma versão diferente do Windows, procure no menu Iniciar ou na página Iniciar uma pasta de ferramentas do Visual Studio que contém um atalho de solicitação de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar por "prompt de comando de desenvolvedor" e escolher um que corresponda à sua versão instalada do Visual Studio. Use o atalho para abrir a janela de solicitação de comando.

::: moniker-end

::: moniker range="vs-2017"

## <a name="open-a-developer-command-prompt-in-visual-studio-2017"></a>Abra um prompt de comando de desenvolvedor no Visual Studio 2017

Se você instalou o Visual Studio 2017 no Windows 10, abra o menu Iniciar e, em seguida, role para baixo e abra a pasta **Visual Studio 2017** (não o aplicativo Visual Studio 2017). Escolha **o Prompt de comando do desenvolvedor para VS 2017** para abrir a janela de solicitação de comando.

Se você estiver executando uma versão diferente do Windows, procure no menu Iniciar ou na página Iniciar uma pasta de ferramentas do Visual Studio que contém um atalho de solicitação de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar por "prompt de comando de desenvolvedor" e escolher um que corresponda à sua versão instalada do Visual Studio. Use o atalho para abrir a janela de solicitação de comando.

::: moniker-end

::: moniker range="vs-2015"

## <a name="open-a-developer-command-prompt-in-visual-studio-2015"></a>Abra um prompt de comando de desenvolvedor no Visual Studio 2015

Se você instalou o Microsoft Visual C++ Build Tools 2015 no Windows 10, abra o menu **Iniciar** e, em seguida, role para baixo e abra a pasta **Ferramentas de Construção Visual C++.** Escolha **o Comando de Ferramentas Nativas Visual C++ 2015 x86 prompt** para abrir a janela de prompt de comando.

Se você estiver executando uma versão diferente do Windows, procure no menu Iniciar ou na página Iniciar uma pasta de ferramentas do Visual Studio que contém um atalho de solicitação de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar por "prompt de comando de desenvolvedor" e escolher um que corresponda à sua versão instalada do Visual Studio. Use o atalho para abrir a janela de solicitação de comando.

::: moniker-end

Em seguida, verifique se o prompt de comando do desenvolvedor Visual C++ está configurado corretamente. Na janela de solicitação `cl` de comando, digite e verifique se a saída se parece com algo assim:

```Output
C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>cl
Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

Pode haver diferenças no diretório atual ou números de versão, dependendo da versão do Visual C++ e quaisquer atualizações instaladas. Se a saída acima for semelhante à que você vê, então você está pronto para construir programas C ou C++ na linha de comando.

> [!NOTE]
> Se você tiver um erro como "'cl' não for reconhecido como um comando interno ou externo, programa operável ou arquivo em lote", erro C1034 ou erro LNK1104 quando você executar o comando **cl,** então você não está usando um prompt de comando do desenvolvedor, ou algo está errado com a instalação do Visual C++. Você deve corrigir este problema antes de continuar.

Se você não conseguir encontrar o atalho de solicitação de comando `cl`do desenvolvedor ou se receber uma mensagem de erro ao entrar, então sua instalação visual C++ pode ter um problema. Se você estiver usando o Visual Studio 2017 ou posterior, tente reinstalar o desenvolvimento do Desktop com carga de trabalho **C++** no instalador do Visual Studio. Para obter detalhes, consulte [o suporte instalar C++ no Visual Studio](vscpp-step-0-installation.md). Ou, reinstale as Ferramentas de Compilação a partir da página de downloads do [Visual Studio.](https://visualstudio.microsoft.com/downloads/) Não vá para a próxima seção até que isso funcione. Para obter mais informações sobre como instalar e solucionar problemas do Visual Studio, consulte [Install Visual Studio](/visualstudio/install/install-visual-studio).

> [!NOTE]
> Dependendo da versão do Windows no computador e da configuração de segurança do sistema, você pode ter que clicar com o botão direito do mouse para abrir o menu de atalho para o atalho de solicitação de comando do desenvolvedor e, em seguida, escolher **Executar como administrador** para construir e executar com sucesso o programa que você cria seguindo este passo a passo.

## <a name="create-a-c-source-file-and-compile-it-on-the-command-line"></a>Crie um arquivo de origem C e compile-o na linha de comando

1. Na janela de solicitação `cd c:\` de comando do desenvolvedor, digite para alterar o diretório de trabalho atual para a raiz da unidade C: .. Em seguida, digite `md c:\simple` para criar `cd c:\simple` um diretório e, em seguida, digite para alterar para esse diretório. Este diretório manterá seu arquivo de origem e o programa compilado.

1. Digite `notepad simple.c` no prompt de comando do desenvolvedor. Na caixa de diálogo alerta do bloco de notas que aparece, escolha **Sim** para criar um novo arquivo simple.c em seu diretório de trabalho.

1. No Bloco de Notas, digite as seguintes linhas de código:

    ```C
    #include <stdio.h>

    int main()
    {
        printf("Hello, World! This is a native C program compiled on the command line.\n");
        return 0;
    }
    ```

1. Na barra de menu do bloco de notas, escolha **'Salvar** **arquivos'** > para salvar simple.c em seu diretório de trabalho.

1. Volte para a janela de solicitação de comando do desenvolvedor. Digite `dir` no prompt de comando para listar o conteúdo do diretório c:\simples. Você deve ver o arquivo de origem simple.c na listagem do diretório, que se parece com:

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

   As datas e outros detalhes diferem no seu computador. Se você não ver seu arquivo de código fonte, simple.c, certifique-se de que você mudou para o diretório c:\simples que você criou e no Bloco de Notas, certifique-se de que você salvou seu arquivo de origem neste diretório. Certifique-se também de que você salvou o código-fonte com uma extensão de nome de arquivo .c, não uma extensão .txt.

1. Para compilar seu `cl simple.c` programa, digite no prompt de comando do desenvolvedor.

   Você pode ver o nome do programa executável, simple.exe, nas linhas de informações de saída que o compilador exibe:

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
   > Se você tiver um erro como "'cl' não for reconhecido como um comando interno ou externo, programa operável ou arquivo em lote", erro C1034 ou erro LNK1104, o prompt de comando do desenvolvedor não será configurado corretamente. Para obter informações sobre como corrigir esse problema, volte para a seção Abrir uma seção **de solicitação de comando do desenvolvedor.**

   > [!NOTE]
   > Se você tiver um erro ou aviso de compilador ou linker diferente, revise seu código-fonte para corrigir quaisquer erros, então salve-o e execute o compilador novamente. Para obter informações sobre erros específicos, use a caixa de pesquisa na parte superior desta página para procurar o número de erro.

1. Para executar seu `simple` programa, digite no prompt de comando.

   O programa exibe este texto e fecha na sequência:

    ```Output
    Hello, World! This is a native C program compiled on the command line.
    ```

   Parabéns, você compilou e executou um programa C usando a linha de comando.

## <a name="next-steps"></a>Próximas etapas

Este exemplo de "Olá, Mundo" é tão simples quanto um programa C pode ficar. Programas do mundo real têm arquivos de cabeçalho e mais arquivos de origem, link em bibliotecas e fazem trabalho útil.

Você pode usar as etapas neste passo a passo para construir seu próprio código C em vez de digitar o código de amostra mostrado. Você também pode construir muitos programas de amostra de código C que você encontra em outro lugar. Para compilar um programa que tenha arquivos de código-fonte adicionais, digite todos eles na linha de comando, como:

`cl file1.c file2.c file3.c`

O compilador produz um programa chamado file1.exe. Para alterar o nome para program1.exe, adicione uma opção [de linker /out:](reference/out-output-file-name.md)

`cl file1.c file2.c file3.c /link /out:program1.exe`

E para capturar mais erros de programação automaticamente, recomendamos que você compile usando a opção de nível de aviso [/W3](reference/compiler-option-warning-level.md) ou [/W4:](reference/compiler-option-warning-level.md)

`cl /W4 file1.c file2.c file3.c /link /out:program1.exe`

O compilador, cl.exe, tem muito mais opções que você pode aplicar para construir, otimizar, depurar e analisar seu código. Para uma lista `cl /?` rápida, digite no prompt de comando do desenvolvedor. Você também pode compilar e vincular separadamente e aplicar opções de linker em cenários de compilação mais complexos. Para obter mais informações sobre opções e uso de compiladores e linker, consulte [C/C++ Building Reference](reference/c-cpp-building-reference.md).

Você pode usar NMAKE e makefiles, ou MSBuild e arquivos de projeto para configurar e construir projetos mais complexos na linha de comando. Para obter mais informações sobre o uso dessas ferramentas, consulte [NMAKE Reference](reference/nmake-reference.md) e [MSBuild](msbuild-visual-cpp.md).

As línguas C e C++ são semelhantes, mas não as mesmas. O compilador Microsoft C/C++ (MSVC) usa uma regra simples para determinar qual idioma usar quando compila seu código. Por padrão, o compilador MSVC trata todos os arquivos que terminam em .c como código fonte C, e todos os arquivos que terminam em .cpp como código fonte C++. Para forçar o compilador a tratar todos os arquivos como C não dependentes da extensão do nome do arquivo, use a opção [compilador /Tc.](reference/tc-tp-tc-tp-specify-source-file-type.md)

O MSVC é compatível com o padrão ISO C99, mas não está estritamente em conformidade. Na maioria dos casos, o código C portátil irá compilar e executar como esperado. Visual C++ não suporta a maioria das alterações no ISO C11. Certas funções de biblioteca e nomes de funções POSIX são preteridas pelo MSVC. As funções são suportadas, mas os nomes preferidos mudaram. Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md) e no Aviso do [Compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).

## <a name="see-also"></a>Confira também

[Passo a passo: criando um programa C++ padrão (C++)](../windows/walkthrough-creating-a-standard-cpp-program-cpp.md)<br/>
[Referência em Linguagem C](../c-language/c-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br/>
[Compatibilidade](../c-runtime-library/compatibility.md)
