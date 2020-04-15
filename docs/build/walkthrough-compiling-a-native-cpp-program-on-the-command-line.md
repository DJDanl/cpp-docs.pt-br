---
title: 'Instruções passo a passo: compilando um programa do C++ nativo na linha de comando'
description: Use o compilador Microsoft C++ a partir de um prompt de comando.
ms.custom: conceptual
ms.date: 04/02/2020
helpviewer_keywords:
- native code [C++]
- Visual C++, native code
- compiling programs [C++]
- command-line applications [C++], native
ms.assetid: b200cfd1-0440-498f-90ee-7ecf92492dc0
ms.openlocfilehash: c24fdfdaef612059d5c2fbaaa58f10d83f5fe3a8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335238"
---
# <a name="walkthrough-compiling-a-native-c-program-on-the-command-line"></a>Instruções passo a passo: compilando um programa do C++ nativo na linha de comando

O Visual Studio inclui um compilador de linha de comando C e C++. Você pode usá-lo para criar tudo, desde aplicativos básicos de console até aplicativos da Universal Windows Platform, aplicativos de desktop, drivers de dispositivos e componentes .NET.

Neste passo a passo, você cria um programa C++ básico, estilo "Hello, World", usando um editor de texto e, em seguida, compilá-lo na linha de comando. Se você quiser experimentar o Visual Studio IDE em vez de usar a linha de comando, consulte [Passo a Passo: Trabalhando com Projetos e Soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) ou [Usando o Visual Studio IDE para Desenvolvimento de Desktop C++.](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md)

Neste passo a passo, você pode usar seu próprio programa C++ em vez de digitar o que é mostrado. Ou, você pode usar uma amostra de código C++ de outro artigo de ajuda.

## <a name="prerequisites"></a>Pré-requisitos

Para completar este passo a passo, você deve ter instalado o Visual Studio e o desenvolvimento opcional de desktop com carga de trabalho **C++,** ou a linha de comando Build Tools para Visual Studio.

O Visual Studio é um *ambiente de desenvolvimento integrado* (IDE). Ele suporta um editor completo, gerentes de recursos, depuradores e compiladores para muitos idiomas e plataformas. As versões disponíveis incluem a edição gratuita do Visual Studio Community, e todas podem suportar o desenvolvimento C e C++. Para obter informações sobre como baixar e instalar o Visual Studio, consulte [O suporte ao Install C++ no Visual Studio](vscpp-step-0-installation.md).

O Build Tools for Visual Studio instala apenas os compiladores, ferramentas e bibliotecas de linha de comando que você precisa para construir programas C e C++. É perfeito para construir laboratórios ou exercícios em sala de aula e instala-se relativamente rapidamente. Para instalar apenas as ferramentas de linha de comando, procure o Build Tools for Visual Studio na página [Desportos](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019) do Visual Studio.

Antes de construir um programa C ou C++ na linha de comando, verifique se as ferramentas estão instaladas e você pode acessá-las a partir da linha de comando. O Visual C++ tem requisitos complexos para que o ambiente de linha de comando encontre as ferramentas, cabeçalhos e bibliotecas que usa. **Você não pode usar o Visual C++ em uma janela de prompt de comando simples** sem fazer alguma preparação. Felizmente, o Visual C++ instala atalhos para você lançar um prompt de comando do desenvolvedor que tem o ambiente configurado para compilações de linhas de comando. Infelizmente, os nomes dos atalhos de prompt de comando do desenvolvedor e onde eles estão localizados são diferentes em quase todas as versões do Visual C++ e em diferentes versões do Windows. Sua primeira tarefa passo a passo é encontrar a certa para usar.

> [!NOTE]
> Um atalho de solicitação de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e as ferramentas e para quaisquer cabeçalhos e bibliotecas necessários. Você deve definir esses valores de ambiente se você usar uma janela **de solicitação de comando** regular. Para obter mais informações, confira [Definir o caminho e as variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md). Recomendamos que você use um atalho de solicitação de comando do desenvolvedor em vez de construir o seu próprio.

### <a name="open-a-developer-command-prompt"></a>Abra um prompt de comando de desenvolvedor

1. Se você instalou o Visual Studio 2017 ou posteriormente no Windows 10, abra o menu Iniciar e escolha **Todos os aplicativos**. Role para baixo e abra a pasta **Visual Studio** (não o aplicativo Visual Studio). Escolha **o Prompt de comando do desenvolvedor para VS** para abrir a janela de solicitação de comando.

   Se você instalou o Microsoft Visual C++ Build Tools 2015 no Windows 10, abra o menu **Iniciar** e escolha **Todos os aplicativos**. Role para baixo e abra a pasta **Ferramentas de Compilação Visual C++.** Escolha **o Comando de Ferramentas Nativas Visual C++ 2015 x86 prompt** para abrir a janela de prompt de comando.

   Você também pode usar a função de pesquisa do Windows para procurar por "prompt de comando de desenvolvedor" e escolher um que corresponda à sua versão instalada do Visual Studio. Use o atalho para abrir a janela de solicitação de comando.

1. Em seguida, verifique se o prompt de comando do desenvolvedor Visual C++ está configurado corretamente. Na janela de solicitação `cl` de comando, digite e verifique se a saída se parece com algo assim:

   ```Output
   C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>cl
   Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
   Copyright (C) Microsoft Corporation.  All rights reserved.

   usage: cl [ option... ] filename... [ /link linkoption... ]
   ```

   Pode haver diferenças no diretório atual ou números de versão. Esses valores dependem da versão do Visual C++ e de quaisquer atualizações instaladas. Se a saída acima for semelhante à que você vê, então você está pronto para construir programas C ou C++ na linha de comando.

   > [!NOTE]
   > Se você tiver um erro como "'cl' não for reconhecido como um comando interno ou externo, programa operável ou arquivo em **`cl`** lote", erro C1034 ou erro LNK1104 quando você executar o comando, então você não está usando um prompt de comando do desenvolvedor, ou algo está errado com a instalação do Visual C++. Você deve corrigir este problema antes de continuar.

   Se você não conseguir encontrar o atalho de solicitação de comando `cl`do desenvolvedor ou se receber uma mensagem de erro ao entrar, então sua instalação visual C++ pode ter um problema. Tente reinstalar o componente Visual C++ no Visual Studio ou reinstale as Ferramentas de Compilação Microsoft Visual C++. Não vá para a próxima seção até que o **`cl`** comando funcione. Para obter mais informações sobre como instalar e solucionar problemas visual C++, consulte [Install Visual Studio](/visualstudio/install/install-visual-studio).

   > [!NOTE]
   > Dependendo da versão do Windows no computador e da configuração de segurança do sistema, você pode ter que clicar com o botão direito do mouse para abrir o menu de atalho para o atalho de solicitação de comando do desenvolvedor e, em seguida, escolher **Executar como administrador** para construir e executar com sucesso o programa que você cria seguindo este passo a passo.

### <a name="create-a-visual-c-source-file-and-compile-it-on-the-command-line"></a>Crie um arquivo de origem Visual C++ e compile-o na linha de comando

1. Na janela prompt de `md c:\hello` comando do desenvolvedor, entre `cd c:\hello` para criar um diretório e, em seguida, digite para alterar para esse diretório. Este diretório é onde seu arquivo de origem e o programa compilado são criados.

1. Digite `notepad hello.cpp` na janela de solicitação de comando.

   Escolha **Sim** quando o bloco de notas solicitar que você crie um arquivo. Esta etapa abre uma janela de bloco de notas em branco, pronta para você inserir seu código em um arquivo chamado hello.cpp.

1. No Bloco de Notas, digite as seguintes linhas de código:

   ```cpp
   #include <iostream>
   using namespace std;
   int main()
   {
       cout << "Hello, world, from Visual C++!" << endl;
   }
   ```

   Este código é um programa simples que escreverá uma linha de texto na tela e, em seguida, sairá. Para minimizar erros, copie este código e cole-o no Bloco de Notas.

1. Salve seu trabalho! No Bloco de Notas, no menu **Arquivo,** escolha **Salvar**.

   Parabéns, você criou um arquivo de fonte C++, hello.cpp, que está pronto para compilar.

1. Volte para a janela de solicitação de comando do desenvolvedor. Digite `dir` no prompt de comando para listar o conteúdo do diretório c:\hello. Você deve ver o arquivo de origem hello.cpp na listagem do diretório, que se parece com:

   ```Output
   c:\hello>dir
    Volume in drive C has no label.
    Volume Serial Number is CC62-6545

    Directory of c:\hello

   05/24/2016  05:36 PM    <DIR>          .
   05/24/2016  05:36 PM    <DIR>          ..
   05/24/2016  05:37 PM               115 hello.cpp
                  1 File(s)            115 bytes
                  2 Dir(s)  571,343,446,016 bytes free

   ```

   As datas e outros detalhes diferem no seu computador. Se você não ver o seu arquivo de código fonte, *hello.cpp*, certifique-se de que você mudou para o *diretório\\c: olá* que você criou. No Bloco de Notas, certifique-se de que você salvou seu arquivo de origem neste diretório. Certifique-se também de que você *`.cpp`* salvou o código-fonte com uma extensão de nome de arquivo, não uma *`.txt`* extensão.

1. No prompt de comando `cl /EHsc hello.cpp` do desenvolvedor, digite para compilar seu programa.

   O compilador cl.exe gera um arquivo .obj que contém o código compilado e, em seguida, executa o linker para criar um programa executável chamado hello.exe. Este nome aparece nas linhas de informações de saída que o compilador exibe. A saída do compilador deve parecer algo como:

   ```Output
   c:\hello>cl /EHsc hello.cpp
   Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
   Copyright (C) Microsoft Corporation.  All rights reserved.

   hello.cpp
   Microsoft (R) Incremental Linker Version 14.10.25017.0
   Copyright (C) Microsoft Corporation.  All rights reserved.

   /out:hello.exe
   hello.obj
   ```

   > [!NOTE]
   > Se você tiver um erro como "'cl' não for reconhecido como um comando interno ou externo, programa operável ou arquivo em lote", erro C1034 ou erro LNK1104, o prompt de comando do desenvolvedor não será configurado corretamente. Para obter informações sobre como corrigir esse problema, volte para a seção Abrir uma seção **de solicitação de comando do desenvolvedor.**

   > [!NOTE]
   > Se você tiver um erro ou aviso de compilador ou linker diferente, revise seu código-fonte para corrigir quaisquer erros, então salve-o e execute o compilador novamente. Para obter informações sobre erros específicos, use a caixa de pesquisa nesta página do MSDN para procurar o número de erro.

1. Para executar o programa hello.exe, no `hello`prompt de comando, digite .

   O programa exibe este texto e é fechado:

   ```Output
   Hello, world, from Visual C++!
   ```

   Parabéns, você compilou e executou um programa C++ usando as ferramentas de linha de comando.

## <a name="next-steps"></a>Próximas etapas

Este exemplo de "Olá, Mundo" é tão simples quanto um programa C++ pode ficar. Programas do mundo real geralmente têm arquivos de cabeçalho, mais arquivos de origem e link para bibliotecas.

Você pode usar as etapas neste passo a passo para construir seu próprio código C++ em vez de digitar o código de amostra mostrado. Essas etapas também permitem que você crie muitos programas de exemplo de código C++ que você encontra em outros lugares. Você pode colocar seu código fonte e construir seus aplicativos em qualquer diretório gravável. Por padrão, o Visual Studio IDE cria projetos em sua pasta de usuário, em uma subpasta *de repositórios\\de* origem. Versões mais antigas podem colocar projetos em uma *versão do Visual\\Studio \<documentos>\\ *projects*.

Para compilar um programa que tenha arquivos de código-fonte adicionais, digite todos eles na linha de comando, como:

`cl /EHsc file1.cpp file2.cpp file3.cpp`

A `/EHsc` opção de linha de comando instrui o compilador a habilitar o comportamento padrão de manipulação de exceções C++. Sem ele, exceções lançadas podem resultar em objetos não destruídos e vazamentos de recursos. Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](reference/eh-exception-handling-model.md).

Quando você fornece arquivos de origem adicionais, o compilador usa o primeiro arquivo de entrada para criar o nome do programa. Neste caso, ele produz um programa chamado file1.exe. Para alterar o nome para program1.exe, adicione uma opção [de linker /out:](reference/out-output-file-name.md)

`cl /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe`

E para capturar mais erros de programação automaticamente, recomendamos que você compile usando a opção de nível de aviso [/W3](reference/compiler-option-warning-level.md) ou [/W4:](reference/compiler-option-warning-level.md)

`cl /W4 /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe`

O compilador, cl.exe, tem muito mais opções. Você pode aplicá-los para construir, otimizar, depurar e analisar seu código. Para uma lista `cl /?` rápida, digite no prompt de comando do desenvolvedor. Você também pode compilar e vincular separadamente e aplicar opções de linker em cenários de compilação mais complexos. Para obter mais informações sobre opções e uso de compiladores e linker, consulte [C/C++ Building Reference](reference/c-cpp-building-reference.md).

Você pode usar NMAKE e makefiles, MSBuild e arquivos de projeto, ou CMake, para configurar e construir projetos mais complexos na linha de comando. Para obter mais informações sobre o uso dessas ferramentas, consulte os projetos [NMAKE Reference,](reference/nmake-reference.md) [MSBuild](msbuild-visual-cpp.md)e [CMake no Visual Studio](cmake-projects-in-visual-studio.md).

As línguas C e C++ são semelhantes, mas não as mesmas. O compilador MSVC usa uma regra simples para determinar qual idioma usar quando compila seu código. Por padrão, o compilador MSVC trata *`.c`* arquivos que terminam como código *`.cpp`* fonte C, e arquivos que terminam como código fonte C++. Para forçar o compilador a tratar todos os arquivos como C++ independente da extensão do nome do arquivo, use a opção [compilador /TP.](reference/tc-tp-tc-tp-specify-source-file-type.md)

O compilador MSVC inclui uma Biblioteca de Tempo de Execução C (CRT) que está em conformidade com o padrão ISO C99, com pequenas exceções. O código portátil geralmente compila e executa como esperado. Certas funções obsoletas de biblioteca, e vários nomes de funções POSIX, são preteridas pelo compilador MSVC. As funções são suportadas, mas os nomes preferidos mudaram. Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md) e no Aviso do [Compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).

## <a name="see-also"></a>Confira também

[Referência de linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
