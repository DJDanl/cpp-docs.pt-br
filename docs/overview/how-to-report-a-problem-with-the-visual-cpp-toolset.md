---
title: Como relatar um problema com o conjunto de ferramentas do Microsoft C++
description: Como criar um bom relatório de problemas e informações de repro para o conjunto de ferramentas Microsoft C++.
ms.date: 09/24/2019
ms.technology: cpp-ide
author: corob-msft
ms.author: corob
ms.openlocfilehash: 350e902501aca5cbe2b4022ec1f977719844644b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "71685696"
---
# <a name="how-to-report-a-problem-with-the-microsoft-c-toolset-or-documentation"></a>Como relatar um problema com o conjunto de ferramentas ou a documentação do Microsoft C++

Se você encontrar problemas no compilador, no vinculador ou em outras ferramentas e bibliotecas do Microsoft C++ (MSVC), vamos querer saber sobre eles. Quando o problema está em nossa documentação, queremos saber sobre isso também.

## <a name="how-to-report-a-c-toolset-issue"></a>Como relatar um problema de conjunto de ferramentas do C++

A melhor maneira de nos informar sobre um problema é enviar um relatório que inclua uma descrição do problema que você descobriu. Ele precisa ter todos os detalhes sobre como criar o seu programa. E tem que incluir uma *reprodução*, um caso de teste completo que possamos usar para reproduzir o problema em nossos computadores. Essas informações nos permitem verificar rapidamente se o problema está em seu código e não em seu ambiente local. Ele ajuda a determinar se ele afeta outras versões do compilador e diagnosticar a causa.

Nas seções a seguir, você poderá ler sobre o que faz um bom relatório. Descrevemos como gerar uma reprodução para o tipo de problema encontrado e como enviar seu relatório para a equipe de produto. Os relatórios são importantes para nós e para outros desenvolvedores como você. Obrigado por nos ajudar a melhorar o Microsoft C++!

## <a name="how-to-prepare-your-report"></a>Como preparar seu relatório

É importante criar um relatório de alta qualidade, porque é difícil para nós reproduzirmos o problema encontrado sem informações completas. Quanto melhor for seu relatório, mais efetivamente poderemos recriar e diagnosticar o problema.

No mínimo, o relatório precisa conter:

- As informações de versão completas do conjunto de ferramentas que você está usando.

- A linha de comando completa cl.exe usada para compilar seu código.

- Uma descrição detalhada do problema encontrado.

- Uma reprodução: um exemplo de código-fonte completo, simplificado e independente que demonstra o problema.

Continue lendo para saber mais sobre as informações específicas necessárias, onde você pode encontrá-las e sobre como criar uma boa reprodução.

### <a name="the-toolset-version"></a>A versão do conjunto de ferramentas

Precisamos de informações completas de versão e a arquitetura de destino do conjunto de ferramentas que causa o problema. Isso serve para que possamos testar sua reprodução com o mesmo conjunto de ferramentas em nossos computadores. Se pudermos reproduzir o problema, essas informações também nos fornecerão um ponto de partida para investigar quais outras versões do conjunto de ferramentas têm o mesmo problema.

#### <a name="to-report-the-full-version-of-your-compiler"></a>Para relatar a versão completa de seu compilador

1. Abra o **Prompt de Comando do Desenvolvedor** correspondente à arquitetura de versão e à configuração do Visual Studio usada para compilar o projeto. Por exemplo, se você compila usando o Visual Studio de 2017 em x64 para destinos x64, escolha **Prompt de Comando de Ferramentas Nativas do x64 para VS 2017**. Para obter mais informações, consulte [Atalhos de prompt de comando do desenvolvedor](../build/building-on-the-command-line.md#developer_command_prompt_shortcuts).

1. Na janela do console de prompt de comando do desenvolvedor, insira o comando **cl /Bv**.

A saída deverá ser parecida com:

```Output
C:\Users\username\Source>cl /Bv
Microsoft (R) C/C++ Optimizing Compiler Version 19.14.26428.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

Compiler Passes:
 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.14.26428\bin\HostX86\x86\cl.exe:        Version 19.14.26428.1
 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.14.26428\bin\HostX86\x86\c1.dll:        Version 19.14.26428.1
 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.14.26428\bin\HostX86\x86\c1xx.dll:      Version 19.14.26428.1
 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.14.26428\bin\HostX86\x86\c2.dll:        Version 19.14.26428.1
 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.14.26428\bin\HostX86\x86\link.exe:      Version 14.14.26428.1
 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.14.26428\bin\HostX86\x86\mspdb140.dll:  Version 14.14.26428.1
 C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.14.26428\bin\HostX86\x86\1033\clui.dll: Version 19.14.26428.1

cl : Command line error D8003 : missing source filename
```

Copie e cole toda a saída em seu relatório.

### <a name="the-command-line"></a>A linha de comando

Precisamos da linha de comando exata, cl.exe e todos os argumentos usados para compilar seu código. Isso serve para que possamos compilá-lo exatamente da mesma forma em nossos computadores. É importante porque o problema que você encontrou pode existir apenas ao compilar com um determinado argumento ou combinação de argumentos.

O melhor lugar para localizar essas informações é o log de build imediatamente após você passar pelo problema. Isso garante que a linha de comando contenha exatamente os mesmos argumentos que podem contribuir para o problema.

#### <a name="to-report-the-contents-of-the-command-line"></a>Para relatar o conteúdo da linha de comando

1. Localize o arquivo **CL.command.1.tlog** e abra-o. Por padrão, este arquivo está localizado \\na pasta\\Documentos na *versão*\\Visual Studio\\Projetos*SolutionName*\\*ProjectName*\\*Configuration*\\*ProjectName*.tlog\\CL.1.tlog, ou em sua pasta de usuário em\\\\*Configuration*\\ \\Source ReposSolutionName*SolutionName*\\*ProjectName*Configuration*ProjectName*.tlog\\CL.command.1.tlog. Ele pode estar em um local diferente se você usa outro sistema de compilação ou se alterou o local padrão para seu projeto.

   Dentro desse arquivo, você encontrará os nomes dos arquivos de seu código-fonte seguidos pelos argumentos de linha de comando usados para compilá-los, cada um em linhas separadas.

1. Localize a linha que contém o nome do arquivo de código fonte onde o problema ocorre. A linha abaixo dela contém os argumentos de comando cl.exe correspondentes.

Copie e cole toda a linha de comando em seu relatório.

### <a name="a-description-of-the-problem"></a>Uma descrição do problema

Precisamos de uma descrição detalhada do problema encontrado. Isso serve para que possamos garantir que teremos o mesmo efeito em nossos computadores. Também é útil às vezes que saibamos o que você estava tentando fazer e o que você esperava que acontecesse.

Uma boa descrição fornece as **mensagens de erro exatas** emitidas pelo conjunto de ferramentas ou o comportamento de runtime exato que você vir. Precisamos dessas informações para confirmar se reproduzimos o problema corretamente. Inclua **toda** a saída do compilador, não apenas a última mensagem de erro. Precisamos ver tudo o que levou ao problema relatado. Se você puder duplicar o problema usando o compilador de linha de comando, essa saída do compilador é o que preferimos. O IDE e outros sistemas de compilação podem filtrar as mensagens de erro que você vê ou capturar somente a primeira linha de uma mensagem de erro.

Se o problema é que o compilador aceita código inválido e não gera um diagnóstico, inclua isso em seu relatório.

Para relatar um problema de comportamento de runtime, inclua uma **cópia exata** do que o programa imprime e o que você espera ver. Idealmente, você vai inserir isso na saída da instrução em si, por exemplo, `printf("This should be 5: %d\n", actual_result);`. Se o programa falhar ou travar, mencione isso também.

Adicione outros detalhes que puderem nos ajudar a diagnosticar o problema encontrado, como soluções alternativas que você possa ter descoberto. Evite repetir informações encontradas em outro lugar no relatório.

### <a name="the-repro"></a>A reprodução

Uma *reprodução* é um exemplo de código-fonte completo e independente. Ela demonstra o problema encontrado de forma reproduzível, por isso o nome. Precisamos de uma reprodução para que possamos reproduzir o erro em nossos computadores. O código deve ser suficiente por si só para criar um executável básico que compila e executa. Ou que *compilaria e executaria* caso você não encontrasse o problema. Uma reprodução não é um snippet de código. Ela deve ter classes e funções completas e conter todas as diretivas #include necessárias, mesmo para os cabeçalhos padrão.

#### <a name="what-makes-a-good-repro"></a>O que compõe uma boa reprodução

Uma boa reprodução é:

- **Mínimo.** As reproduções devem ter o menor tamanho possível enquanto ainda demonstram exatamente o problema encontrado. As reproduções não precisam ser complexas ou realistas. Elas precisam apenas mostrar o código que está em conformidade com o padrão ou para a implementação documentada do compilador. Caso não haja um diagnóstico, sua reprodução deve mostrar o código que não é compatível. As reproduções simples e objetivas, contendo apenas o código necessário para demonstrar o problema, são as melhores. Se você puder eliminar ou simplificar o código de modo que ele permaneça compatível e deixe o problema inalterado, faça isso. Não é necessário incluir contraexemplos de códigos que funcionam.

- **Independente.** As reproduções devem evitar dependências desnecessárias. Se você puder reproduzir o problema sem bibliotecas de terceiros, faça isso. Se puder reproduzir o problema sem nenhum código de biblioteca além de instruções de saída simples (por exemplo, `puts("this shouldn't compile");`, `std::cout << value;` e `printf("%d\n", value);`), faça isso. O ideal é que o exemplo possa ser condensado em um único arquivo de código-fonte, sem referência a nenhum cabeçalho de usuário. Reduzir a quantidade de código que precisamos considerar como um possível colaborador para o problema é extremamente útil para nós.

- **Com a versão mais recente do compilador.** As reproduções devem usar a atualização mais recente da versão mais recente do conjunto de ferramentas sempre que possível. Ou use a versão mais recente de pré-lançamento da próxima atualização ou da próxima versão principal. Em versões mais recentes, os problemas que podem ocorrer nas versões mais antigas do conjunto de ferramentas frequentemente foram corrigidos. As correções são implementadas em versões mais antigas apenas em circunstâncias excepcionais.

- **Comparadas com outros compiladores**, se for relevante. As reproduções que envolvem código C++ portátil devem verificar o comportamento em relação a outros compiladores se possível. O padrão C++ acaba por determinar a correção do programa e nenhum compilador é perfeito. No entanto, quando o Clang e o GCC aceitam seu código sem um diagnóstico e o MSVC não, você provavelmente encontrou um bug em nosso compilador. (Outras possibilidades incluem diferenças no comportamento do Unix e do Windows, ou diferentes níveis de implementação de padrões C++, e assim por diante.) Quando todos os compiladores rejeitam seu código, então é provável que seu código esteja incorreto. Ver mensagens de erro diferentes pode ajudá-lo a diagnosticar o problema por conta própria.

   Você pode encontrar listas de compiladores online nos quais pode testar seu código em [Compiladores C++ Online](https://isocpp.org/blog/2013/01/online-c-compilers) no site do ISO C++ ou nesta [Lista de Compiladores C++ Online](https://arnemertz.github.io/online-compilers/) no GitHub. Alguns exemplos específicos incluem [Wandbox](https://wandbox.org/), [Compiler Explorer](https://godbolt.org/) e [Coliru](https://coliru.stacked-crooked.com/).

   > [!NOTE]
   > Os sites de compiladores online não são afiliados à Microsoft. Muitos sites de compilador online são executados como projetos pessoais. Alguns desses sites podem estar indisponíveis quando você ler isto, mas uma pesquisa deve localizar outros que você pode usar.

Problemas no compilador, no vinculador e em bibliotecas tendem a ter aspectos particulares. O tipo de problema encontrado determinará o tipo de reprodução que você deverá incluir em seu relatório. Sem uma reprodução apropriada, não temos nada para investigar. Aqui estão alguns dos tipos de problemas que você pode encontrar. Incluímos instruções sobre como gerar o tipo de reprodução que você deve usar para relatar cada tipo de problema.

#### <a name="frontend-parser-crash"></a>Falha de front-end (analisador)

As falhas de front-end ocorrem durante a fase de análise do compilador. Normalmente, o compilador emite [Erro Fatal C1001](../error-messages/compiler-errors-1/fatal-error-c1001.md) e faz referência ao arquivo de código-fonte e ao número de linha no qual o erro aconteceu. Ele frequentemente menciona um arquivo chamado msc1.cpp, mas você pode ignorar esse detalhe.

Para esse tipo de falha, forneça uma [Reprodução pré-processada](#preprocessed-repros).

Aqui está o exemplo de saída do compilador para esse tipo de falha:

```Output
SandBoxHost.cpp
d:\o\dev\search\foundation\common\tools\sandbox\managed\managed.h(929):
        fatal error C1001: An internal error has occurred in the compiler.
(compiler file 'msc1.cpp', line 1369)
To work around this problem, try simplifying or changing the program near the
        locations listed above.
Please choose the Technical Support command on the Visual C++
Help menu, or open the Technical Support help file for more information
d:\o\dev\search\foundation\common\tools\sandbox\managed\managed.h(929):
        note: This diagnostic occurred in the compiler generated function
        'void Microsoft::Ceres::Common::Tools::Sandbox::SandBoxedProcess::Dispose(bool)'
Internal Compiler Error in d:\o\dev\otools\bin\x64\cl.exe.  You will be prompted
        to send an error report to Microsoft later.
INTERNAL COMPILER ERROR in 'd:\o\dev\otools\bin\x64\cl.exe'
    Please choose the Technical Support command on the Visual C++
    Help menu, or open the Technical Support help file for more information
```

#### <a name="backend-code-generation-crash"></a>Falha de back-end (geração de código)

As falhas de back-end ocorrem durante a fase de geração do código do compilador. Normalmente, o compilador emite [Fatal Error C1001](../error-messages/compiler-errors-1/fatal-error-c1001.md) e pode não fazer referência ao arquivo de código-fonte e ao número de linha associados ao problema. Ele frequentemente menciona o compilador de arquivo\\utc\\src\\p2\\main.c, mas você pode ignorar esse detalhe.

Para esse tipo de falha, forneça uma [Reprodução de vinculação](#link-repros) se você estiver usando a LTCG (Geração de Código Durante o Tempo de Vinculação), habilitada pelo argumento de linha de comando **/GL** para cl.exe. Caso contrário, forneça uma [Reprodução pré-processada](#preprocessed-repros).

Este é um exemplo de saída do compilador para uma falha de back-end em que a LTCG não é usada. Se a saída do compilador tiver a aparência a seguir, você deverá fornecer uma [Reprodução pré-processada](#preprocessed-repros).

```Output
repro.cpp
\\officefile\public\tadg\vc14\comperror\repro.cpp(13) : fatal error C1001:
        An internal error has occurred in the compiler.
(compiler file 'f:\dd\vctools\compiler\utc\src\p2\main.c', line 230)
To work around this problem, try simplifying or changing the program near the
        locations listed above.
Please choose the Technical Support command on the Visual C++
Help menu, or open the Technical Support help file for more information
INTERNAL COMPILER ERROR in
        'C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\BIN\cl.exe'
    Please choose the Technical Support command on the Visual C++
    Help menu, or open the Technical Support help file for more information
```

Se a linha que começa com **INTERNAL COMPILER ERROR** menciona link.exe, em vez de cl.exe, a LTCG estava habilitada. Forneça uma [reprodução de vinculação](#link-repros) nesse caso. Quando não está claro na mensagem de erro se o LTCG estava habilitado, examine os argumentos da linha de comando. Você os copiou do log de build em uma etapa anterior do argumento de linha de comando **/GL**.

#### <a name="linker-crash"></a>Falha de vinculador

As falhas de vinculador ocorrerem durante a fase de vinculação, depois que o compilador foi executado. Normalmente, o vinculador emitirá o [Erro das Ferramentas de Vinculador LNK1000](../error-messages/tool-errors/linker-tools-error-lnk1000.md).

> [!NOTE]
> Se a saída menciona C1001 ou envolve a Geração de Código Durante o Tempo de Vinculação, confira [Falha de back-end (geração de código)](#backend-code-generation-crash) em vez disso.

Para esse tipo de falha, forneça uma [Reprodução de vinculação](#link-repros).

Aqui está a saída do compilador de exemplo para esse tipo de falha:

```Output
z:\foo.obj : error LNK1000: Internal error during IMAGE::Pass2

  Version 14.00.22816.0

  ExceptionCode            = C0000005
  ExceptionFlags           = 00000000
  ExceptionAddress         = 00007FF73C9ED0E6 (00007FF73C9E0000)
        "z:\tools\bin\x64\link.exe"
  NumberParameters         = 00000002
  ExceptionInformation[ 0] = 0000000000000000
  ExceptionInformation[ 1] = FFFFFFFFFFFFFFFF

CONTEXT:

  Rax    = 0000000000000400  R8     = 0000000000000000
  Rbx    = 000000655DF82580  R9     = 00007FF840D2E490
  Rcx    = 005C006B006F006F  R10    = 000000655F97E690
  Rdx    = 000000655F97E270  R11    = 0000000000000400
  Rsp    = 000000655F97E248  R12    = 0000000000000000
  Rbp    = 000000655F97EFB0  E13    = 0000000000000000
  Rsi    = 000000655DF82580  R14    = 000000655F97F390
  Rdi    = 0000000000000000  R15    = 0000000000000000
  Rip    = 00007FF73C9ED0E6  EFlags = 0000000000010206
  SegCs  = 0000000000000033  SegDs  = 000000000000002B
  SegSs  = 000000000000002B  SegEs  = 000000000000002B
  SegFs  = 0000000000000053  SegGs  = 000000000000002B
  Dr0    = 0000000000000000  Dr3    = 0000000000000000
  Dr1    = 0000000000000000  Dr6    = 0000000000000000
  Dr2    = 0000000000000000  Dr7    = 0000000000000000
```

Se a vinculação incremental está habilitada e a falha ocorreu apenas após uma vinculação inicial bem-sucedida, isto é, apenas após a primeira vinculação completa na qual a vinculação incremental posterior se baseia, forneça também uma cópia dos arquivos de objeto (.obj) e de biblioteca (.lib) que correspondem aos arquivos de origem modificados após a vinculação inicial ter sido concluída.

#### <a name="bad-code-generation"></a>Geração de código incorreto

A geração de código incorreto é rara. Isso acontece quando o compilador gera código incorreto por engano, o que faz com que o aplicativo falhe no runtime. Em vez disso, ele deve gerar código ou detectar um problema no momento da compilação. Se você acreditar que o problema encontrado resulta na geração de código incorreto, trate o relatório da mesma forma que uma [Falha de back-end (geração de código)](#backend-code-generation-crash).

Para esse tipo de falha, ofereça uma [reprodução de vinculação](#link-repros) se estiver usando o argumento de linha de comando **/GL** para cl.exe. Caso contrário, forneça uma [Reprodução pré-processada](#preprocessed-repros).

## <a name="how-to-generate-a-repro"></a>Como gerar uma reprodução

Para nos ajudar a identificar a origem do problema, é vital ter uma [boa reprodução](#what-makes-a-good-repro). Antes de executar qualquer uma das etapas descritas abaixo para tipos específicos de reproduções, tente condensar o código que demonstra o problema tanto quanto possível. Tente eliminar ou minimizar dependências, cabeçalhos necessários e bibliotecas. Limite as opções do compilador e as definições de pré-processador usadas, se possível.

A seguir estão as instruções para gerar os vários tipos de reproduções que você usará para relatar diferentes tipos de problemas.

### <a name="preprocessed-repros"></a>Reproduções pré-processadas

Uma *reprodução pré-processada* é um único arquivo de origem que demonstra um problema. Ele é gerado pela saída do pré-processador C. Para criar um, use a opção do compilador **/p** no arquivo de origem de reprodução original. Essa opção alinha os cabeçalhos incluídos para remover dependências em arquivos de origem e de cabeçalho adicionais. A opção também resolve macros, condicionais #ifdef e outros comandos de pré-processador que podem depender de seu ambiente local.

> [!NOTE]
> As reproduções pré-processadas não são tão úteis para problemas que podem ser resultantes de bugs em nossa implementação de biblioteca padrão porque geralmente queremos substituir nossa implementação mais recente, em andamento, para ver se já corrigimos o problema. Nesse caso, não pré-processe a reprodução e, se você não puder reduzir o problema para um único arquivo de origem, compacte seu código em um arquivo .zip ou semelhante ou considere usar uma reprodução de projeto do IDE. Para obter mais informações, consulte [Outras reproduções](#other-repros).

#### <a name="to-preprocess-a-source-code-file"></a>Para pré-processar um arquivo de código-fonte

1. Capture os argumentos de linha de comando usados para criar sua reprodução, conforme descrito em [Para relatar o conteúdo da linha de comando](#to-report-the-contents-of-the-command-line).

1. Abra o **Prompt de Comando do Desenvolvedor** correspondente à arquitetura de versão e à configuração do Visual Studio usada para compilar o projeto.

1. Mude para o diretório que contém seu projeto de reprodução.

1. Na janela do console de prompt de comando do desenvolvedor, insira o comando **cl /P** *arguments* *filename.cpp*. Para *argumentos*, use a lista de argumentos capturados acima. *filename.cpp* é o nome do arquivo de origem da reprodução. Esse comando replica a linha de comando usada para a reprodução, mas interrompe a compilação após a fase de pré-processamento. Ele grava o código-fonte pré-processado em *filename.i*.

Se você estiver pré-processando o arquivo de código de origem do C++/CX, ou estiver usando o recurso de módulos do C++, algumas etapas adicionais serão necessárias. Para obter mais informações, veja as seguintes abaixo.

Após ter gerado o arquivo pré-processado, é recomendável certificar-se de que o problema ainda é reproduzido quando você compila o arquivo pré-processado.

#### <a name="to-confirm-the-preprocessed-file-still-repros-the-error"></a>Para confirmar que o arquivo pré-processado ainda reproduz o erro

1. Na janela do console do prompt de comando, insira o comando **cl** *argumentos* **/TP** *nomedoarquivo.i* para dizer ao cl.exe para compilar o arquivo pré-processado como um arquivo de origem C++. Os *argumentos* são os mesmos argumentos capturados acima, mas com os argumentos **/D** e **/I** removidos. Isso ocorre porque eles já foram incluídos no arquivo pré-processado. *nomedoarquivo.i* é o nome do arquivo pré-processado.

1. Confirme que o problema é reproduzido.

Por fim, anexe a reprodução pré-processada *nomedoarquivo*.i ao seu relatório.

### <a name="preprocessed-ccx-winrtuwp-code-repros"></a>Reproduções de código do C++/CXWinRT/UWP pré-processadas

Se você estiver usando C++/CX para criar o executável, algumas etapas adicionais serão necessárias para criar e validar uma reprodução pré-processada.

#### <a name="to-preprocess-ccx-source-code"></a>Para pré-processar um código-fonte C++/CX

1. Crie um arquivo de origem pré-processado conforme descrito no arquivo [Para pré-processar um arquivo de código-fonte](#to-preprocess-a-source-code-file).

1. Pesquise o arquivo _nomedoarquivo_.i gerado para diretivas **#using**.

1. Faça uma lista de todos os arquivos referenciados. Omita todos os arquivos Windows\*.winmd, platform.winmd e mscorlib.dll.

Para se preparar para validar que o arquivo pré-processado ainda reproduz o problema,

1. Crie um diretório para o arquivo pré-processado e copie-o para o novo diretório.

1. Copie os arquivos .winmd da lista **#using** para o novo diretório.

1. Crie um arquivo vccorlib.h vazio no novo diretório.

1. Edite o arquivo pré-processado para remover todas as diretivas **#using** para mscorlib.dll.

1. Edite o arquivo pré-processado para alterar qualquer caminho absoluto para apenas os nomes de arquivo vazio para os arquivos .winmd copiados.

Confirme que o arquivo pré-processado ainda reproduz o problema, conforme acima.

### <a name="preprocessed-c-modules-repros"></a>Reproduções de módulos do C++ pré-processadas

Se você estiver usando o recurso de módulos do compilador C++, algumas etapas diferentes serão necessárias para criar e validar uma reprodução pré-processada.

#### <a name="to-preprocess-a-source-code-file-that-uses-a-module"></a>Para pré-processar um arquivo de código-fonte que usa um módulo

1. Capture os argumentos de linha de comando usados para criar sua reprodução, conforme descrito em [Para relatar o conteúdo da linha de comando](#to-report-the-contents-of-the-command-line).

1. Abra o **Prompt de Comando do Desenvolvedor** correspondente à arquitetura de versão e à configuração do Visual Studio usada para compilar o projeto.

1. Mude para o diretório que contém seu projeto de reprodução.

1. Na janela do console de prompt de comando do desenvolvedor, insira o comando **cl /P** *arguments* *filename.cpp*. Os *argumentos* são os argumentos capturados acima e *filename.cpp* é o nome do arquivo de origem que consome o módulo.

1. Altere para o diretório que contém o projeto de reprodução que criou a interface do módulo (a saída .ifc).

1. Capture os argumentos de linha de comando usados para criar sua interface de módulo.

1. Na janela do console de prompt de comando do desenvolvedor, insira o comando **cl /P** *arguments* *modulename.ixx*. Os *argumentos* são os argumentos capturados acima e *modulename.ixx* é o nome do arquivo que cria a interface de módulo.

Após ter gerado os arquivos pré-processados, é recomendável certificar-se de que o problema ainda é reproduzido usando o arquivo pré-processado.

#### <a name="to-confirm-the-preprocessed-file-still-repros-the-error"></a>Para confirmar que o arquivo pré-processado ainda reproduz o erro

1. Na janela do console de prompt de comando do desenvolvedor, volte para o diretório que contém seu projeto de reprodução.

1. Digite o comando **cl** *argumentos* **/TP** *nomedoarquivo*.i como acima, para compilar o arquivo pré-processado como se fosse um arquivo de origem do C++.

1. Confirme que o problema ainda é reproduzido pelo arquivo pré-processado.

Finalmente, anexe os arquivos de reprodução pré-processados (*nomedoarquivo*.i e *nomedomódulo*.i) junto com a saída de .ifc ao seu relatório.

### <a name="link-repros"></a>Reproduções de vinculação

Uma *repro de link* é o conteúdo gerado pelo linker de um diretório, especificado pela variável de ambiente **repro link,\_** ou como um argumento para a opção [linker /LINKREPRO.](../build/reference/linkrepro.md) Ela contém artefatos de compilação que demonstram coletivamente um problema que acontece no tempo de vinculação. Os exemplos incluem uma falha de back-end que envolve a Geração de Código Durante o Tempo de Vinculação (LTCG) ou uma falha de vinculador. Estes artefatos de construção são os necessários como entrada de linker para que o problema possa ser reproduzido. Uma repro link pode ser criada facilmente usando essa variável de ambiente. Ela habilita o recurso de geração de reprodução interno do vinculador.

#### <a name="to-generate-a-link-repro-using-the-link_repro-environment-variable"></a>Para gerar uma repro link usando a variável ambiente link_repro

1. Capture os argumentos de linha de comando usados para criar sua reprodução, conforme descrito em [Para relatar o conteúdo da linha de comando](#to-report-the-contents-of-the-command-line).

1. Abra o **Prompt de Comando do Desenvolvedor** correspondente à arquitetura de versão e à configuração do Visual Studio usada para compilar o projeto.

1. Na janela do console de prompt de comando do desenvolvedor, mude para o diretório que contém seu projeto de reprodução.

1. Digite **mkdir linkrepro** para criar um diretório chamado *linkrepro* para o link repro. Você pode usar um nome diferente para capturar outro link repro.

1. Digite o comando **set link\_repro=linkrepro** para definir a variável de ambiente **link\_repro** para o diretório que você criou. Se a sua compilação for executada a partir de um diretório diferente, como é frequentemente o caso de projetos mais complexos, então defina o **\_link repro** para o caminho completo para o seu diretório de repro link em vez disso.

1. Para compilar o projeto de reprodução no Visual Studio, na janela do console de prompt de comando do desenvolvedor, digite o comando **devenv**. Isso garante que o valor da variável de ambiente **link\_repro** esteja visível para o Visual Studio. Para compilar o projeto na linha de comando, use os argumentos de linha de comando capturados acima para duplicar a compilação de reprodução.

1. Compile seu projeto de reprodução e confirme se o problema esperado ocorreu.

1. Feche o Visual Studio se você o usou para executar a compilação.

1. Na janela do console de prompt de comando do desenvolvedor, digite o comando **set link\_repro=** para limpar a variável de ambiente **link\_repro**.

Finalmente, empacote a repro comprimindo todo o diretório linkrepro em um arquivo .zip ou similar e anexe-o ao seu relatório.

A opção **linker /LINKREPRO** tem o mesmo efeito que a variável de ambiente **link\_repro.** Você pode usar a opção [/LINKREPROTARGET](../build/reference/linkreprotarget.md) para especificar o nome a ser filtrado para a repro de link gerada. Para usar **/LINKREPROTARGET,** você também deve especificar a opção **linker /OUT.**

#### <a name="to-generate-a-link-repro-using-the-linkrepro-option"></a>Para gerar um link repro usando a opção /LINKREPRO

1. Crie um diretório para segurar o link repro. Vamos nos referir ao caminho completo do diretório que você cria como _caminho de diretório_. Use aspas duplas ao redor do caminho se ele incluir espaços.

1. Adicione o **comando /LINKREPRO:**_diretório-path_ à linha de comando linker. No Visual Studio, abra a caixa de diálogo **Páginas** de Propriedade para o seu projeto. Selecione a página de propriedade **Configuração Propriedades** > **linker's** > **command line.** Em seguida, digite a opção **/LINKREPRO:**_diretório-path_ na caixa **Opções adicionais.** Escolha **OK** para salvar suas alterações.

1. Compile seu projeto de reprodução e confirme se o problema esperado ocorreu.

Finalmente, empacote a repro comprimindo todo o _diretório-path_ link repro em um arquivo .zip ou similar e anexe-o ao seu relatório.

### <a name="other-repros"></a>Outras reproduções

Se você não pode reduzir o problema a um único arquivo de origem ou repro pré-processado, e o problema não requer uma repro link, podemos investigar um projeto IDE. Todas as orientações sobre como criar uma boa reprovação ainda se aplicam: O código deve ser mínimo e auto-contido. O problema deve ocorrer em nossas ferramentas mais recentes e, se for relevante, não deve ser visto em outros compiladores.

Crie sua reprodução como um projeto do IDE mínimo e empacote-o compactando toda a estrutura do diretório em um arquivo .zip ou semelhante e anexe-o ao relatório.

## <a name="ways-to-send-your-report"></a>Maneiras de enviar o relatório

Há várias boas maneiras de enviar seu relatório para nós. Você pode usar a ferramenta interna [Relatar um Problema](/visualstudio/ide/how-to-report-a-problem-with-visual-studio-2017) do Visual Studio ou as páginas da [Comunidade de Desenvolvedores do Visual Studio](https://developercommunity.visualstudio.com/). Também há um botão **Comentários sobre o produto** no final desta página. A escolha depende se você deseja usar as ferramentas internas no IDE para obter capturas de tela e organizar seu relatório. Caso prefira não fazê-lo, você pode usar diretamente o site da Comunidade de Desenvolvedores.

> [!NOTE]
> Independentemente de como você enviar seu relatório, a Microsoft respeita sua privacidade. A Microsoft está comprometida com a conformidade com todas as leis e regulamentos de privacidade de dados. Para obter informações sobre como tratamos os dados que você nos envia, confira a [Política de privacidade da Microsoft](https://privacy.microsoft.com/privacystatement).

### <a name="use-the-report-a-problem-tool"></a>Usar a ferramenta Relatar um Problema

A ferramenta **Relatar um Problema** no Visual Studio é uma maneira de os usuários do Visual Studio relatarem problemas com apenas alguns cliques. Ele exibe um formulário simples para enviar informações detalhadas sobre o problema encontrado. Em seguida, você pode enviar seu relatório sem precisar sair do IDE.

Relatar o problema usando a ferramenta **Relatar um Problema** no IDE é fácil e prático. Você pode acessá-la na barra de título escolhendo o ícone **Enviar Comentários** ao lado da caixa de pesquisa **Início Rápido**. Ou, você pode encontrá-lo na barra de menu em **Ajudar** > **enviar relatório de feedback** > **um problema**.

Ao escolher relatar um problema, pesquise primeiro na Comunidade de Desenvolvedores para tentar encontrar problemas semelhantes. Se o problema já tiver sido relatado anteriormente, vote a favor do relatório e adicione comentários com informações adicionais específicas. Se você não encontrar nenhum problema semelhante, escolha o botão **Relatar problema novo** na parte inferior da caixa de diálogo Comentários do Visual Studio e siga as etapas para relatar o problema.

### <a name="use-the-visual-studio-developer-community-pages"></a>Usar as páginas da Comunidade de Desenvolvedores do Visual Studio

As páginas da Comunidade de Desenvolvedores do Visual Studio são outra maneira prática para relatar problemas e encontrar soluções relacionadas ao Visual Studio e ao compilador do C++, às ferramentas e às bibliotecas. Há páginas da Comunidade de Desenvolvedores para [Visual Studio](https://developercommunity.visualstudio.com/spaces/8/index.html), [Visual Studio para Mac](https://developercommunity.visualstudio.com/spaces/41/index.html), [.NET](https://developercommunity.visualstudio.com/spaces/61/index.html), [C++](https://developercommunity.visualstudio.com/spaces/62/index.html), [Azure DevOps Services](https://developercommunity.visualstudio.com/spaces/21/index.html) e [TFS](https://developercommunity.visualstudio.com/spaces/22/index.html).

Nas guias da comunidade, próximo à parte superior de cada página, há uma caixa de pesquisa. Você pode usá-la para encontrar postagens que relatam problemas semelhantes ao seu. Você poderá encontrar uma solução ou outras informações úteis relacionadas ao seu problema já disponíveis. Se alguém já tiver relatado o mesmo problema anteriormente, vote a favor e comente nesse relatório em vez de criar um novo relatório de problema. Para comentar, votar ou relatar um problema novo, você poderá ser solicitado a entrar sua conta do Visual Studio. Na primeira vez que entrar, você terá que concordar em dar acesso ao aplicativo da Comunidade de Desenvolvedores ao seu perfil.

Para problemas relacionados ao compilador C++, ao vinculador e às outras ferramentas e bibliotecas, use a página do [C++](https://developercommunity.visualstudio.com/spaces/62/index.html). Se você pesquisar seu problema e ele não tiver sido relatado anteriormente, escolha o botão **Relatar um problema** ao lado da caixa de pesquisa. Você poderá incluir o código de reprodução e a linha de comando, capturas de tela, links para discussões relacionadas e qualquer outra informação que achar relevante e útil.

> [!TIP]
> Para ver outros tipos de problemas que possam ser encontrados no Visual Studio não relacionados ao conjunto de ferramentas do C++ (Por exemplo, problemas de interface do usuário, funcionalidade IDE corrompida ou falhas gerais), use a ferramenta **Relatar um problema** no IDE. Isso é a melhor opção, devido a suas funcionalidades de captura de tela e sua capacidade de registrar ações de interface do usuário que levam ao problema encontrado. Esses tipos de erros também podem ser pesquisados no site da [Comunidade de Desenvolvedores](https://developercommunity.visualstudio.com/). Para obter mais informações, consulte [Como relatar um problema com o Visual Studio](/visualstudio/ide/how-to-report-a-problem-with-visual-studio-2017).

### <a name="reports-and-privacy"></a>Relatórios e privacidade

**Todas as informações em relatórios e quaisquer comentários e respostas são publicamente visíveis por padrão**. Normalmente, isso é uma vantagem, pois permite que toda a comunidade veja os problemas, as soluções e alternativas encontradas por outros usuários. No entanto, se você está preocupado em tornar seus dados ou a sua identidade pública, por motivos de propriedade intelectual ou de privacidade, há opções.

Se você está preocupado com a revelação da sua identidade, [crie uma conta Microsoft](https://signup.live.com/) que não divulgue todos os detalhes sobre você. Use essa conta para criar seu relatório.

**Não coloque algo que você deseja manter particular no título ou no conteúdo do relatório inicial, que é público.** Em vez disso, diga que você enviará detalhes em particular em um comentário separado. Para ter certeza de que o relatório será direcionado às pessoas certas, inclua **cppcompiler** na lista de tópicos do seu relatório de problemas. Depois de criar o relatório de problemas, é possível especificar quem pode ver suas respostas e anexos.

#### <a name="to-create-a-problem-report-for-private-information"></a>Para criar um relatório de problemas para informações particulares

1. No relatório que você criou, escolha **Adicionar comentário** para criar sua descrição privada do problema.

1. No editor de resposta, use o controle de lista suspensa abaixo dos botões **Enviar** e **Cancelar** para especificar o público-alvo para a sua resposta. Somente as pessoas que você especificar podem ver essas respostas privadas e imagens, links ou código que você incluir. Escolha **Visível por moderadores e o cartaz original** para limitar a visibilidade aos funcionários da Microsoft e a você mesmo.

1. Adicione a descrição e quaisquer outras informações, imagens e anexos de arquivo necessários para a reprodução. Escolha o botão **Enviar** para enviar essas informações em particular.

   Há um limite de 2 GB para arquivos anexados e de no máximo 10 arquivos. Para uploads maiores, solicite uma URL de upload no seu comentário particular.

Quaisquer respostas sob esse comentário têm a mesma visibilidade restrita que você especificou. Isso é verdadeiro mesmo se o controle de lista suspensa em respostas não mostra o status de visibilidade restrito corretamente.

Para manter sua privacidade e manter suas informações confidenciais ocultas do público, seja cuidadoso. Mantenha todas as interações com a Microsoft nas respostas ao comentário restrito. Respostas a outros comentários podem gerar a divulgação acidental de informações confidenciais.

## <a name="how-to-report-a-c-documentation-issue"></a>Como relatar um problema na documentação do C++

Usamos os problemas do GitHub para acompanhar os problemas relatados em nossa documentação. Agora você pode criar problemas do GitHub diretamente de uma página de conteúdo, o que permite interagir de forma muito mais sofisticada com escritores e equipes de produto. Se você encontrar um problema com um documento, um exemplo de código inválido, uma explicação confusa, uma omissão crítica ou até mesmo um erro de digitação, fale conosco – é fácil. Role até a parte inferior da página e selecione **Entre para fornecer comentários sobre a documentação**. Você precisará criar uma conta no GitHub caso ainda não tenha uma. Quando tem uma conta do GitHub, você pode ver todos os problemas de sua documentação e o status dela. Você também recebe notificações quando as alterações são feitas no problema relatado por você. Para obter mais informações, confira [Em breve, um novo sistema de comentários em docs.microsoft.com](/teamblog/a-new-feedback-system-is-coming-to-docs).

Você pode criar um problema de documentação no GitHub quando usa o botão de comentários de documentação. O problema será automaticamente preenchido com algumas informações sobre a página na qual você criou o problema. É assim que podemos saber onde o problema está localizado, portanto, não edite essas informações. Acrescente apenas os detalhes sobre o que está incorreto e, se desejar, uma correção sugerida. [Nossos documentos C++ são de software livre](https://github.com/MicrosoftDocs/cpp-docs/) então, se quiser enviar você mesmo uma correção, é possível. Para obter mais informações sobre como você pode contribuir com nossa documentação, confira nosso [Guia de colaboração](https://github.com/MicrosoftDocs/cpp-docs/blob/master/CONTRIBUTING.md) no GitHub.
