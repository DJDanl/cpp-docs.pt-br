---
title: 'Instruções passo a passo: compilando um programa do C++ nativo na linha de comando'
description: Use o compilador do Microsoft C++ em um prompt de comando.
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

O Visual Studio inclui um compilador C e C++ de linha de comando. Você pode usá-lo para criar tudo, desde aplicativos de console básicos até Plataforma Universal do Windows aplicativos, aplicativos de área de trabalho, drivers de dispositivo e componentes .NET.

Neste tutorial, você cria um programa básico de "Olá, mundo" do estilo C++ usando um editor de texto e, em seguida, o compila na linha de comando. Se você quiser experimentar o IDE do Visual Studio em vez de usar a linha de comando, consulte [passo a passos: trabalhando com projetos e soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) ou [usando o IDE do Visual Studio para desenvolvimento de desktops C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

Neste tutorial, você pode usar seu próprio programa C++ em vez de digitar aquele que é mostrado. Ou, você pode usar um exemplo de código C++ de outro artigo da ajuda.

## <a name="prerequisites"></a>Pré-requisitos

Para concluir este passo a passos, você deve ter instalado o Visual Studio e o **desenvolvimento de área de trabalho opcional com** a carga de trabalho do C++ ou as ferramentas de Build de linha de comando para o Visual Studio.

O Visual Studio é um *ambiente de desenvolvimento integrado* (IDE). Ele dá suporte a um editor completo, gerenciadores de recursos, depuradores e compiladores para muitas linguagens e plataformas. As versões disponíveis incluem o Visual Studio Community Edition gratuito, e todas podem dar suporte ao desenvolvimento em C e C++. Para obter informações sobre como baixar e instalar o Visual Studio, consulte [instalar o suporte a C++ no Visual Studio](vscpp-step-0-installation.md).

As ferramentas de compilação para o Visual Studio instalam apenas os compiladores, as ferramentas e as bibliotecas de linha de comando necessários para criar programas em C e C++. É perfeito para os laboratórios de compilação ou exercícios de sala de aula e é instalado de forma relativamente rápida. Para instalar apenas as ferramentas de linha de comando, procure ferramentas de compilação para Visual Studio na página de [downloads do Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019) .

Antes de criar um programa C ou C++ na linha de comando, verifique se as ferramentas estão instaladas e você pode acessá-las na linha de comando. Visual C++ tem requisitos complexos para o ambiente de linha de comando para localizar as ferramentas, os cabeçalhos e as bibliotecas que ele usa. **Você não pode usar Visual C++ em uma janela de prompt de comando simples** sem fazer alguma preparação. Felizmente, Visual C++ instala atalhos para que você inicie um prompt de comando do desenvolvedor que tenha o ambiente configurado para compilações de linha de comando. Infelizmente, os nomes dos atalhos de prompt de comando do desenvolvedor e onde eles estão localizados são diferentes em quase todas as versões do Visual C++ e em versões diferentes do Windows. Sua primeira tarefa de explicação explicativa está encontrando a certa para usar.

> [!NOTE]
> Um atalho do prompt de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e as ferramentas e para quaisquer cabeçalhos e bibliotecas necessários. Você mesmo deve definir esses valores de ambiente se usar uma janela de **prompt de comando** normal. Para obter mais informações, confira [Definir o caminho e as variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md). Recomendamos que você use um atalho de prompt de comando do desenvolvedor em vez de criar o seu próprio.

### <a name="open-a-developer-command-prompt"></a>Abrir um prompt de comando do desenvolvedor

1. Se você tiver instalado o Visual Studio 2017 ou posterior no Windows 10, abra o menu iniciar e escolha **todos os aplicativos**. Role para baixo e abra a pasta do **Visual Studio** (não o aplicativo do Visual Studio). Escolha **prompt de comando do desenvolvedor para o vs** abrir a janela de prompt de comando.

   Se você tiver instalado Microsoft Visual C++ ferramentas de Build 2015 no Windows 10, abra o menu **Iniciar** e escolha **todos os aplicativos**. Role para baixo e abra a pasta **ferramentas de Build de Visual C++** . Escolha **Visual C++ 2015 prompt de comando de ferramentas nativas do x86** para abrir a janela de prompt de comando.

   Você também pode usar a função de pesquisa do Windows para procurar "prompt de comando do desenvolvedor" e escolher um que corresponda à versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.

1. Em seguida, verifique se o prompt de comando do Visual C++ Developer está configurado corretamente. Na janela do prompt de comando, `cl` Insira e verifique se a saída é semelhante a esta:

   ```Output
   C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>cl
   Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
   Copyright (C) Microsoft Corporation.  All rights reserved.

   usage: cl [ option... ] filename... [ /link linkoption... ]
   ```

   Pode haver diferenças no diretório atual ou nos números de versão. Esses valores dependem da versão do Visual C++ e de todas as atualizações instaladas. Se a saída acima for semelhante ao que você vê, você estará pronto para criar programas C ou C++ na linha de comando.

   > [!NOTE]
   > Se você receber um erro como "o CL" não é reconhecido como um comando interno ou externo, um programa ou arquivo de lote operável, "erro C1034 ou erro LNK1104 ao executar o **`cl`** comando, você não está usando um prompt de comando do desenvolvedor ou algo está errado com a instalação do Visual C++. Você deve corrigir esse problema antes de continuar.

   Se você não encontrar o atalho do prompt de comando do desenvolvedor ou se receber uma mensagem de erro quando `cl`inserir, a instalação do Visual C++ poderá ter um problema. Tente reinstalar o componente de Visual C++ no Visual Studio ou reinstale as ferramentas de Build de Microsoft Visual C++. Não vá para a próxima seção até que o **`cl`** comando funcione. Para obter mais informações sobre como instalar e solucionar problemas Visual C++, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

   > [!NOTE]
   > Dependendo da versão do Windows no computador e da configuração de segurança do sistema, talvez seja necessário clicar com o botão direito do mouse para abrir o menu de atalho para o atalho do prompt de comando do desenvolvedor e escolher **Executar como administrador** para compilar e executar com êxito o programa que você criar, seguindo este passo a passos.

### <a name="create-a-visual-c-source-file-and-compile-it-on-the-command-line"></a>Criar um arquivo de origem Visual C++ e compilá-lo na linha de comando

1. Na janela do prompt de comando do desenvolvedor `md c:\hello` , digite para criar um diretório e, `cd c:\hello` em seguida, digite para alterar para esse diretório. Esse diretório é onde o arquivo de origem e o programa compilado são criados no.

1. Insira `notepad hello.cpp` na janela do prompt de comando.

   Escolha **Sim** quando o bloco de notas solicitar que você crie um arquivo. Esta etapa abre uma janela em branco do bloco de notas, pronto para que você insira seu código em um arquivo chamado Hello. cpp.

1. No bloco de notas, insira as seguintes linhas de código:

   ```cpp
   #include <iostream>
   using namespace std;
   int main()
   {
       cout << "Hello, world, from Visual C++!" << endl;
   }
   ```

   Esse código é um programa simples que gravará uma linha de texto na tela e, em seguida, sairá. Para minimizar erros, copie esse código e cole-o no bloco de notas.

1. Salve seu trabalho! No bloco de notas, no menu **arquivo** , escolha **salvar**.

   Parabéns, você criou um arquivo de origem C++, Olá. cpp, que está pronto para compilar.

1. Volte para a janela do prompt de comando do desenvolvedor. Digite `dir` no prompt de comando para listar o conteúdo do diretório c:\hello. Você deve ver o arquivo de origem Hello. cpp na listagem de diretório, que se parece com:

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

   As datas e outros detalhes serão diferentes no seu computador. Se você não vir seu arquivo de código-fonte, *Olá. cpp*, verifique se você alterou para o diretório *\\c: Olá* que você criou. No bloco de notas, certifique-se de que você salvou o arquivo de origem nesse diretório. Além disso, certifique-se de que você salvou o *`.cpp`* código-fonte com uma extensão *`.txt`* de nome de arquivo, não uma extensão.

1. No prompt de comando do desenvolvedor, `cl /EHsc hello.cpp` digite para compilar seu programa.

   O compilador CL. exe gera um arquivo. obj que contém o código compilado e, em seguida, executa o vinculador para criar um programa executável chamado Hello. exe. Esse nome aparece nas linhas de informações de saída que o compilador exibe. A saída do compilador deve ser semelhante a:

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
   > Se você receber um erro como "' CL ' não é reconhecido como um comando interno ou externo, um programa ou arquivo de lote operável," Error C1034 ou Error LNK1104, o prompt de comando do desenvolvedor não está configurado corretamente. Para obter informações sobre como corrigir esse problema, volte para a seção **abrir um prompt de comando do desenvolvedor** .

   > [!NOTE]
   > Se você obtiver um erro ou aviso do vinculador ou de um compilador diferente, examine o código-fonte para corrigir os erros, salve-o e execute o compilador novamente. Para obter informações sobre erros específicos, use a caixa de pesquisa nesta página do MSDN para procurar o número do erro.

1. Para executar o programa Hello. exe, no prompt de comando, digite `hello`.

   O programa exibe este texto e é fechado:

   ```Output
   Hello, world, from Visual C++!
   ```

   Parabéns, você compilou e executou um programa em C++ usando as ferramentas de linha de comando.

## <a name="next-steps"></a>Próximas etapas

Esse exemplo de "Olá, mundo" é tão simples quanto um programa em C++ pode ser obtido. Os programas do mundo real geralmente têm arquivos de cabeçalho, mais arquivos de origem e vinculam-se a bibliotecas.

Você pode usar as etapas neste passo a passos para criar seu próprio código C++ em vez de digitar o código de exemplo mostrado. Essas etapas também permitem que você crie muitos programas de exemplo de código C++ que você encontrar em outro lugar. Você pode colocar seu código-fonte e criar seus aplicativos em qualquer diretório gravável. Por padrão, o IDE do Visual Studio cria projetos em sua pasta de usuário, em uma subpasta *repositórios de origem\\* . As versões mais antigas podem colocar projetos em uma pasta *documentos\\do Visual \<Studio versão>\\ *projetos *.

Para compilar um programa que tenha arquivos de código-fonte adicionais, insira todos eles na linha de comando, como:

`cl /EHsc file1.cpp file2.cpp file3.cpp`

A `/EHsc` opção de linha de comando instrui o compilador a habilitar o comportamento padrão de manipulação de exceções do C++. Sem ele, as exceções geradas podem resultar em vazamentos de recursos e objetos não destruídos. Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](reference/eh-exception-handling-model.md).

Quando você fornece arquivos de origem adicionais, o compilador usa o primeiro arquivo de entrada para criar o nome do programa. Nesse caso, ele gera um programa chamado arquivo1. exe. Para alterar o nome para Program1. exe, adicione uma opção de vinculador [/out](reference/out-output-file-name.md) :

`cl /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe`

E para detectar mais erros de programação automaticamente, recomendamos que você compile usando a opção de nível de aviso [/w3](reference/compiler-option-warning-level.md) ou [/W4](reference/compiler-option-warning-level.md) :

`cl /W4 /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe`

O compilador, CL. exe, tem muito mais opções. Você pode aplicá-los para compilar, otimizar, depurar e analisar seu código. Para obter uma lista rápida, `cl /?` digite no prompt de comando do desenvolvedor. Você também pode compilar e vincular separadamente e aplicar opções de vinculador em cenários de compilação mais complexos. Para obter mais informações sobre as opções e o uso do compilador e do vinculador, consulte [referência de compilação do C/C++](reference/c-cpp-building-reference.md).

Você pode usar NMAKE e makefiles, arquivos MSBuild e Project, ou CMake, para configurar e compilar projetos mais complexos na linha de comando. Para obter mais informações sobre como usar essas ferramentas, consulte [NMAKE Reference](reference/nmake-reference.md), [MSBuild](msbuild-visual-cpp.md)e [CMake Projects in Visual Studio](cmake-projects-in-visual-studio.md).

As linguagens C e C++ são semelhantes, mas não as mesmas. O compilador MSVC usa uma regra simples para determinar qual idioma usar ao compilar seu código. Por padrão, o compilador MSVC trata os arquivos que terminam em *`.c`* como código-fonte C e os arquivos *`.cpp`* que terminam como código-fonte C++. Para forçar o compilador a tratar todos os arquivos como C++ independentemente da extensão de nome de arquivo, use a opção de compilador [/TP](reference/tc-tp-tc-tp-specify-source-file-type.md) .

O compilador MSVC inclui uma biblioteca de tempo de execução C (CRT) que está de acordo com o padrão ISO C99, com exceções secundárias. O código portátil geralmente é compilado e executado conforme o esperado. Determinadas funções de biblioteca obsoletas e vários nomes de funções POSIX são preteridas pelo compilador MSVC. As funções têm suporte, mas os nomes preferenciais foram alterados. Para obter mais informações, consulte [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md) e [aviso do compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).

## <a name="see-also"></a>Confira também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
