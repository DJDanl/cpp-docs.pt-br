---
title: 'Instruções passo a passo: compilando um programa do C++ nativo na linha de comando'
description: Use o compilador C++ da Microsoft em um prompt de comando.
ms.custom: conceptual
ms.date: 04/23/2019
helpviewer_keywords:
- native code [C++]
- Visual C++, native code
- compiling programs [C++]
- command-line applications [C++], native
ms.assetid: b200cfd1-0440-498f-90ee-7ecf92492dc0
ms.openlocfilehash: daab00768f8140869a8db39c73f4fec3ab6304c7
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051519"
---
# <a name="walkthrough-compiling-a-native-c-program-on-the-command-line"></a>Instruções passo a passo: compilando um programa do C++ nativo na linha de comando

O Visual Studio inclui um compilador de C++ linha de comando que você pode usar para criar tudo, desde aplicativos de console básicos até plataforma universal do Windows aplicativos, aplicativos de área de trabalho, drivers de dispositivo e componentes .net.

Neste tutorial, você cria um C++ programa básico, "Olá, mundo", usando um editor de texto e, em seguida, o compila na linha de comando. Se você quiser experimentar o IDE do Visual Studio em vez de usar a linha de comando, consulte [passo a passos: trabalhando com projetosC++e soluções ()](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) ou [usando o IDE C++ do Visual Studio para desenvolvimento de área de trabalho](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

Neste passo a passo, é possível usar o próprio programa do Visual C++ em vez de digitar o programa mostrado, ou usar uma amostra de código do Visual C++ de outro artigo de ajuda.

## <a name="prerequisites"></a>Prerequisites

Para concluir este passo a passos, você deve ter instalado o Visual Studio e o **desenvolvimento de C++ área de trabalho opcional com** a Workload ou as ferramentas de Build de linha de comando para o Visual Studio.

O Visual Studio é um poderoso ambiente de desenvolvimento integrado (IDE) que dá suporte a um editor completo, gerenciadores de recursos, depuradores e compiladores para muitas linguagens e plataformas. Para obter informações sobre como baixar e instalar o Visual Studio, incluindo o Visual Studio Community Edition gratuito e para incluir suporte para C/C++ Development, consulte [instalar C++ o suporte no Visual Studio](vscpp-step-0-installation.md).

As ferramentas de compilação para o Visual Studio instalam apenas os compiladores, as ferramentas e as bibliotecas de linha de comando necessários C++ para criar C e programas. É perfeito para os laboratórios de compilação ou exercícios de sala de aula e é instalado de forma relativamente rápida. Para instalar apenas as ferramentas de linha de comando, procure ferramentas de compilação para Visual Studio na página de [downloads do Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019) .

Antes de criar um C ou C++ programa na linha de comando, você deve verificar se as ferramentas estão instaladas e se pode acessá-las na linha de comando. O C++ Visual tem requisitos complexos para o ambiente de linha de comando para localizar as ferramentas, os cabeçalhos e as bibliotecas que ele usa. **Você não pode usar C++ o Visual em uma janela de prompt de comando simples** sem fazer alguma preparação. Felizmente, o C++ Visual instala atalhos para que você inicie um prompt de comando do desenvolvedor que tem o ambiente configurado para compilações de linha de comando. Infelizmente, os nomes dos atalhos de prompt de comando do desenvolvedor e onde eles estão localizados são diferentes em quase todas as C++ versões do Visual e em versões diferentes do Windows. Sua primeira tarefa de explicação explicativa está encontrando a certa para usar.

> [!NOTE]
> Um atalho do prompt de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e as ferramentas e para quaisquer cabeçalhos e bibliotecas necessários. Você mesmo deve definir esses valores de ambiente se usar uma janela de **prompt de comando** normal. Para obter mais informações, confira [Definir o caminho e as variáveis de ambiente para builds de linha de comando](setting-the-path-and-environment-variables-for-command-line-builds.md). Recomendamos que você use um atalho de prompt de comando do desenvolvedor em vez de criar o seu próprio.

### <a name="open-a-developer-command-prompt"></a>Abrir um prompt de comando do desenvolvedor

1. Se você tiver instalado o Visual Studio 2017 ou posterior no Windows 10, abra o menu iniciar e escolha **todos os aplicativos**. Role para baixo e abra a pasta do **Visual Studio** (não o aplicativo do Visual Studio). Escolha **prompt de comando do desenvolvedor para o vs** abrir a janela de prompt de comando.

   Se você tiver instalado as ferramentas C++ de compilação do Microsoft Visual 2015 no Windows 10, abra o menu **Iniciar** e escolha **todos os aplicativos**. Role para baixo e abra a pasta  **C++ Visual Build Tools** . Escolha **Visual C++ 2015 prompt de comando de ferramentas nativas do x86** para abrir a janela de prompt de comando.

   Você também pode usar a função de pesquisa do Windows para procurar "prompt de comando do desenvolvedor" e escolher um que corresponda à versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.

1. Em seguida, verifique se o C++ prompt de comando do Visual Developer está configurado corretamente. Na janela do prompt de comando, digite `cl` e verifique se a saída é semelhante a esta:

   ```Output
   C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>cl
   Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
   Copyright (C) Microsoft Corporation.  All rights reserved.

   usage: cl [ option... ] filename... [ /link linkoption... ]
   ```

   Pode haver diferenças no diretório atual ou nos números de versão, dependendo da versão do Visual C++ e das atualizações instaladas. Se a saída acima for semelhante ao que você vê, você estará pronto para criar C ou C++ programas na linha de comando.

   > [!NOTE]
   > Se você receber um erro como "' CL ' não é reconhecido como um comando interno ou externo, um programa ou arquivo de lote operável," erro C1034 ou erro LNK1104 ao executar o comando **CL** , você não está usando um prompt de comando do desenvolvedor ou algo está errado com a instalação do Visual C++. Você deve corrigir esse problema antes de continuar.

   Se você não encontrar o atalho do prompt de comando do desenvolvedor ou se receber uma mensagem de erro ao inserir `cl`, a instalação C++ do Visual poderá ter um problema. Tente reinstalar o componente Visual C++ no Visual Studio ou reinstale as ferramentas de Build C++ do Microsoft Visual. Não vá para a próxima seção até que isso funcione. Para obter mais informações sobre como instalar e solucionar problemas do Visual C++, consulte instalar o [Visual Studio](/visualstudio/install/install-visual-studio).

   > [!NOTE]
   > Dependendo da versão do Windows no computador e da configuração de segurança do sistema, talvez seja necessário clicar com o botão direito do mouse para abrir o menu de atalho para o atalho do prompt de comando do desenvolvedor e escolher **Executar como administrador** para compilar e executar com êxito o programa que você criar, seguindo este passo a passos.

### <a name="create-a-visual-c-source-file-and-compile-it-on-the-command-line"></a>Criar um arquivo C++ de origem Visual e compilá-lo na linha de comando

1. Na janela do prompt de comando do desenvolvedor, digite `md c:\hello` para criar um diretório e, em seguida, insira `cd c:\hello` para alterar para esse diretório. Esse diretório é onde o arquivo de origem e o programa compilado são criados no.

1. Insira `notepad hello.cpp` na janela de prompt de comando.

   Escolha **Sim** quando o bloco de notas solicitar que você crie um arquivo. Esta etapa abre uma janela em branco do bloco de notas, pronto para que você insira seu código em um arquivo chamado Hello. cpp.

1. No bloco de notas, insira as seguintes linhas de código:

   ```cpp
   #include <iostream>
   using namespace std;
   void main()
   {
       cout << "Hello, world, from Visual C++!" << endl;
   }
   ```

   Esse código é um programa simples que gravará uma linha de texto na tela e, em seguida, sairá. Para minimizar erros, copie esse código e cole-o no bloco de notas.

1. Salve seu trabalho! No bloco de notas, no menu **arquivo** , escolha **salvar**.

   Parabéns, você criou um C++ arquivo de origem Hello. cpp, que está pronto para compilar.

1. Volte para a janela do prompt de comando do desenvolvedor. Insira `dir` no prompt de comando para listar o conteúdo do diretório c:\hello. Você deve ver o arquivo de origem Hello. cpp na listagem de diretório, que se parece com:

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

   As datas e outros detalhes serão diferentes no seu computador. Se você não vir seu arquivo de código-fonte, Olá. cpp, certifique-se de ter alterado para o diretório c:\hello que você criou e, no bloco de notas, certifique-se de que você salvou o arquivo de origem nesse diretório. Além disso, certifique-se de que você salvou o código-fonte com uma extensão de nome de arquivo. cpp, não uma extensão. txt.

1. No prompt de comando do desenvolvedor, digite `cl /EHsc hello.cpp` para compilar o programa.

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

   Parabéns, você compilou e executou um C++ programa usando as ferramentas de linha de comando.

## <a name="next-steps"></a>Próximas etapas

Esse exemplo de "Olá, mundo" é tão simples quanto um C++ programa pode obter. Os programas do mundo real têm arquivos de cabeçalho e mais arquivos de origem, link em bibliotecas e trabalho útil.

Você pode usar as etapas neste passo a passos para criar seu C++ próprio código em vez de digitar o código de exemplo mostrado. Você também pode criar muitos C++ programas de exemplo de código que você encontrar em outro lugar. Você pode colocar seu código-fonte e criar seus aplicativos em qualquer diretório gravável. Por padrão, o IDE do Visual Studio cria projetos em sua pasta documentos, em uma subpasta projetos de uma pasta do Visual Studio chamada para sua versão do Visual Studio.

Para compilar um programa que tenha arquivos de código-fonte adicionais, insira todos eles na linha de comando, como:

`cl /EHsc file1.cpp file2.cpp file3.cpp`

A opção de linha de comando `/EHsc` instrui o compilador a habilitar C++ o tratamento de exceção. Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](reference/eh-exception-handling-model.md).

Quando você fornece arquivos de origem adicionais, o compilador usa o primeiro arquivo de entrada para criar o nome do programa. Nesse caso, ele gera um programa chamado arquivo1. exe. Para alterar o nome para Program1. exe, adicione uma opção de vinculador [/out](reference/out-output-file-name.md) :

`cl /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe`

E para detectar mais erros de programação automaticamente, recomendamos que você compile usando a opção de nível de aviso [/w3](reference/compiler-option-warning-level.md) ou [/W4](reference/compiler-option-warning-level.md) :

`cl /W4 /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe`

O compilador, CL. exe, tem muitas outras opções que você pode aplicar para compilar, otimizar, depurar e analisar seu código. Para obter uma lista rápida, digite `cl /?` no prompt de comando do desenvolvedor. Você também pode compilar e vincular separadamente e aplicar opções de vinculador em cenários de compilação mais complexos. Para obter mais informações sobre as opções e o uso do compilador e do vinculador, consulte [C/C++ Build Reference](reference/c-cpp-building-reference.md).

Você pode usar NMAKE e makefiles, ou arquivos MSBuild e Project para configurar e compilar projetos mais complexos na linha de comando. Para obter mais informações sobre como usar essas ferramentas, consulte [referência do NMAKE](reference/nmake-reference.md) e [MSBuild](msbuild-visual-cpp.md).

As linguagens C++ C e são semelhantes, mas não as mesmas. O compilador MSVC usa uma regra simples para determinar qual idioma usar ao compilar seu código. Por padrão, o compilador MSVC trata todos os arquivos que terminam em. c como código-fonte C e todos os arquivos que terminam C++ em. cpp como código-fonte. Para forçar o compilador a tratar todos os arquivos C++ como não dependentes da extensão de nome de arquivo, use a opção de compilador [/TP](reference/tc-tp-tc-tp-specify-source-file-type.md) .

O compilador do MSVC inclui uma biblioteca de tempo de execução C (CRT) que é compatível com o padrão ISO C99, mas não é estritamente compatível. Na maioria dos casos, o código portátil será compilado e executado conforme o esperado. O C++ Visual não dá suporte a algumas das alterações de CRT no C11 ISO. Certas funções de biblioteca e nomes de função POSIX são preteridos pelo compilador MSVC. As funções têm suporte, mas os nomes preferenciais foram alterados. Para obter mais informações, consulte [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md) e [aviso do compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).

## <a name="see-also"></a>Consulte também

[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
