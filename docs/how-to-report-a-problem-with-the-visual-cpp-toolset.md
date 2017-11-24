---
title: Como relatar um problema com o conjunto de ferramentas do Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: ec24a49c-411d-47ce-aa4b-8398b6d3e8f6
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4a669b2935e4c21421d0c760e6de0c5c7340bed4
ms.sourcegitcommit: 1b480aa74886930b3bd0435d71cfcc3ccda36424
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2017
---
# <a name="how-to-report-a-problem-with-the-visual-c-toolset"></a>Como relatar um problema com o Conjunto de Ferramentas do Visual C++

Se você encontrar problemas com o compilador, o vinculador ou outras ferramentas do Visual C++, queremos saber sobre eles.

A melhor maneira de nos informar sobre um problema é nos enviar um relatório que inclui uma descrição do problema encontrado, detalhes sobre como você está compilando seu programa e um pouco de código que possamos usar para reproduzir o problema em nossos computadores. Essas informações nos permitem verificar se o problema existe e não são locais para seu ambiente rapidamente, determinar se ele afeta outras versões do compilador e diagnosticar a causa.

Neste documento, você poderá ler sobre

- [Como preparar seu relatório](#prepare) e o que o torna um bom relatório.

- [Maneiras de enviar o relatório](#send) e o que as torna diferentes.

- [Como gerar uma reprodução](#generate) e diferentes tipos de reproduções.

Os relatórios são importantes para nós e para outros desenvolvedores como você. Obrigado por nos ajudar a melhorar o Visual C++!

## <a name="prepare"></a> Como preparar seu relatório

Criar um relatório de alta qualidade é importante porque é muito difícil reproduzir o problema encontrado em nossos computadores sem informações completas. Quanto melhor for seu relatório, mais efetivamente poderemos recriar e diagnosticar o problema.

No mínimo, o relatório deve conter

- As informações de versão completas do conjunto de ferramentas que você está usando.

- A linha de comando completa cl.exe usada para compilar seu código.

- Uma descrição detalhada do problema encontrado.

- Uma 'reprodução' – código-fonte que demonstra o problema.

Continue lendo para saber mais sobre as informações específicas necessárias e onde você pode encontrá-las.

### <a name="the-toolset-version"></a>A versão do conjunto de ferramentas

Precisamos de informações de versão completas do conjunto de ferramentas que você está usando para que possamos testar sua reprodução com o mesmo conjunto de ferramentas em nossos computadores. Se pudermos reproduzir o problema, essas informações também nos fornecerão um ponto de partida para investigar quais outras versões do conjunto de ferramentas exibem o mesmo problema.

#### <a name="to-report-the-full-version-of-the-compiler-youre-using"></a>Para relatar a versão completa do compilador que você está usando

1. Pressione a tecla Windows no teclado e comece a digitar `Developer Command Prompt`.

1. Escolha a versão **Prompt de Comando do Desenvolvedor** que corresponde à versão do Visual Studio que você está usando quando ela aparecer na lista de correspondências.

1. No console **Prompt de Comando do Desenvolvedor**, digite o comando `cl /Bv /CLR`.

A saída deverá ser parecida com esta:

```Output
C:\Compiler>cl /Bv /CLR
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.40209
for Microsoft (R) .NET Framework version 4.00.30319.34014
Copyright (C) Microsoft Corporation.  All rights reserved.

Compiler Passes:
 C:\WinCComp\binaries.x86chk\bin\i386\cl.exe:        Version 18.00.40209.0
 C:\WinCComp\binaries.x86chk\bin\i386\c1.dll:        Version 18.00.40209.0
 C:\WinCComp\binaries.x86chk\bin\i386\c1xx.dll:      Version 18.00.40209.0
 C:\WinCComp\binaries.x86chk\bin\i386\c2.dll:        Version 18.00.40209.0
 C:\WinCComp\binaries.x86chk\bin\i386\link.exe:      Version 12.00.40209.0
 C:\WinCComp\binaries.x86chk\bin\i386\mspdb120.dll:  Version 12.00.40209.0
 C:\WinCComp\binaries.x86chk\bin\i386\1033\clui.dll: Version 18.00.40209.0
 Common Language Runtime:                            Version  4.00.30319.34014

cl : Command line error D8003 : missing source filename
```

Copie e cole toda a saída em seu relatório.

### <a name="the-command-line"></a>A linha de comando

Precisamos da linha de comando completa (cl.exe e seus argumentos) usada para compilar o código para que possamos compilá-lo exatamente da mesma forma que nossos computadores. Isso é importante porque o problema que você encontrou pode existir apenas ao compilar com um determinado argumento ou combinação de argumentos.

O melhor lugar para localizar essas informações é o log de build imediatamente após o problema. Isso garante que a linha de comando contenha exatamente os mesmos argumentos que podem estar contribuindo para o problema.

#### <a name="to-report-the-contents-of-the-command-line"></a>Para relatar o conteúdo da linha de comando

1. Localize o arquivo **CL.command.1.tlog** e abra-o. Por padrão, esse arquivo está localizado em \\...\Visual Studio Version\Projects\SolutionName\ProjectName\Config\ProjectName.tlog\CL.command.1.tlog.

   Dentro desse arquivo, você encontrará os nomes dos arquivos de código-fonte seguidos pelos argumentos de linha de comando usados para compilá-los, cada um em linhas separadas.

1. Localize a linha que contém o nome do arquivo de código-fonte em que o problema ocorre. A linha abaixo dela contém o comando cl.exe correspondente e seus argumentos.

Copie e cole toda a linha de comando em seu relatório.

### <a name="a-description-of-the-problem"></a>Uma descrição do problema

Precisamos de uma descrição detalhada do problema que você encontrou para que possamos verificar se vemos o mesmo efeito em nossos computadores. Isso algumas vezes também é útil para sabermos o que você estava tentando realizar e o que esperava que aconteceria.

Forneça as mensagens de erro precisas fornecidas pelo conjunto de ferramentas, uma breve descrição do que você estava tentando realizar para nos ajudar a compreender o código de reprodução e quaisquer outros detalhes que possam nos ajudar a diagnosticar o problema encontrado, como quaisquer soluções alternativas que você possa ter encontrado. Evite repetir informações encontradas em outro lugar no relatório.

### <a name="the-repro"></a>A reprodução

Precisamos de uma *reprodução*, um exemplo de código-fonte autocontido que demonstra o problema encontrado, para que possamos reproduzir o erro em nossos computadores. O tipo de problema encontrado determinará o tipo de reprodução que você deverá incluir em seu relatório. Sem uma reprodução apropriada, não temos nada para investigar.

Reproduções curtas e independentes podem ser incluídas no texto do relatório diretamente, mas reproduções de código-fonte maiores devem ser anexadas ao relatório. As reproduções que não podem ser reduzidas a um único arquivo de código-fonte devem ser empacotadas compactando um diretório que contém todos os arquivos em um arquivo .zip ou semelhante e anexadas ao relatório. Todos os detalhes adicionais específicos do cenário sempre devem ser incluídos no texto do relatório, nunca no código-fonte.

O melhor tipo de reprodução que você pode nos fornecer é uma *reprodução mínima*. Este é um arquivo de código-fonte única e independente (sem referências aos cabeçalhos de usuário) que contém apenas código suficiente para demonstrar o problema. Se você puder fornecer uma reprodução nesse formato, basta anexar o arquivo de código-fonte ao relatório, isso é tudo o que precisamos.

Se não puder condensar o problema em uma reprodução mínima sem dependências, consulte as seções a seguir para determinar o tipo de reprodução que você deve incluir no relatório.

#### <a name="frontend-parser-crash"></a>Falha de front-end (analisador)

As falhas de front-end ocorrem durante a fase de análise do compilador. Normalmente, o compilador emitirá o [Erro Fatal C1001](error-messages/compiler-errors-1/fatal-error-c1001.md) e referenciará o arquivo de código-fonte e número de linha em que o erro ocorreu, geralmente ele mencionará um arquivo msc1.cpp, mas você pode ignorar esse detalhe.

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

#### <a name="backend_crash"></a> Falha de back-end (geração de código)

As falhas de back-end ocorrem durante a fase de geração do código do compilador. Normalmente, o compilador emitirá o [Erro Fatal C1001](error-messages/compiler-errors-1/fatal-error-c1001.md) e poderá não referenciar o arquivo de código-fonte e número de linha associados ao problema, geralmente ele mencionará um arquivo compiler\utc\src\p2\main.c, mas você pode ignorar esse detalhe.

Para esse tipo de falha, forneça uma [Reprodução de vinculação](#link-repros) se você estiver usando a LTCG (Geração de Código Durante o Tempo de Vinculação) ou uma [Reprodução pré-processada](#preprocessed-repros) se não estiver. A LTGC é habilitada pelo argumento de linha de comando `/GL` para cl.exe.

Aqui está a saída do compilador de exemplo para esse tipo de falha em que a LTCG **não** é usada. Se a saída do compilador tiver esta aparência, você deverá fornecer uma [Reprodução pré-processada](#preprocessed-repros).

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

Se a linha que começa com **INTERNAL COMPILER ERROR** menciona link.exe, em vez de cl.exe, a LTCG estava habilitada e você deverá fornecer uma [Reprodução de vinculação](#link-repros). Se não estiver claro se a LTCG estava habilitada da mensagem de erro do compilador, talvez seja necessário examinar os argumentos da linha de comando copiada do log de build em uma etapa anterior para o argumento de linha de comando `/GL`.

#### <a name="linker-crash"></a>Falha de vinculador

As falhas de vinculador ocorrerem durante a fase de vinculação, depois que o compilador foi executado. Normalmente, o vinculador emitirá o [Erro das Ferramentas de Vinculador LNK1000](error-messages/tool-errors/linker-tools-error-lnk1000.md).

> [!NOTE]
> Se a saída menciona C1001 ou envolve a Geração de Código Durante o Tempo de Vinculação, consulte [Falha de back-end (geração de código)](#backend_crash) em vez disso para obter mais informações.

Para esse tipo de falha, forneça uma [Reprodução de vinculação](#link-repros).

Aqui está a saída do compilador de exemplo par esse tipo de falha.

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

Se a vinculação incremental estiver habilitada e a falha tiver ocorrido apenas após a vinculação inicial, isto é, apenas após a primeira vinculação completa na qual a vinculação incremental subsequente se baseia, forneça também uma cópia dos arquivos de objeto (.obj) e de biblioteca (.lib) que correspondem aos arquivos de origem que foram modificados após a vinculação inicial ter sido concluída.

#### <a name="bad-code-generation"></a>Geração de código incorreto

A geração de código incorreto é rara, mas ocorre quando o compilador erroneamente gera um código incorreto que fará com que o aplicativo falhe em tempo de execução em vez de detectar esse problema no tempo de compilação. Se você acreditar que o problema que está enfrentando resulta na geração de código incorreto, trate o relatório da mesma forma que uma [Falha de back-end (geração de código)](#backend_crash).

Para esse tipo de falha, forneça uma [Reprodução de vinculação](#link-repros) se você estiver usando a LTCG (Geração de Código Durante o Tempo de Vinculação) ou uma [Reprodução pré-processada](#preprocessed-repros) se não estiver. A LTGC é habilitada pelo argumento de linha de comando `/GL` para cl.exe.

## <a name="send"></a> Maneiras de enviar o relatório

Há várias maneiras de enviar seu relatório para nós. Você pode usar a [Ferramenta Reportar um Problema](/visualstudio/ide/how-to-report-a-problem-with-visual-studio-2017) interna do Visual Studio ou enviar um email para nós. A melhor opção para seu relatório depende do tipo de problema que você encontrou, como você deseja interagir com os engenheiros que investigarão o relatório e se você deseja acompanhar o progresso ou compartilhar seu relatório com a comunidade.

> [!NOTE]
> Independentemente de como você enviar seu relatório, a Microsoft respeita sua privacidade. Para obter informações sobre como tratamos os dados que você nos envia, consulte a [Política de privacidade da família de produtos do Microsoft Visual Studio](https://www.visualstudio.com/dn948229).

### <a name="send-an-email"></a>Enviar um email

O email é outra maneira de enviar o relatório diretamente para a equipe do Visual C++. Você pode entrar em contato conosco em [compilercrash@microsoft.com](mailto:compilercrash@microsoft.com).

Se optar por enviar o relatório por email, você poderá usar o modelo a seguir como o corpo da mensagem de email. Não se esqueça de anexar o código-fonte ou outros arquivos se você não estiver incluindo essas informações no corpo do email.

```Example
To: compilercrash@microsoft.com
Subject: Visual C++ Error Report
-----

Compiler version:

CL.EXE command line:

Problem description:

Source code and repro steps:

```

### <a name="use-the-report-a-problem-tool"></a>Usar a ferramenta Relatar um Problema

A ferramenta Relatar um Problema no Visual Studio é uma maneira de os usuários do Visual Studio relatarem uma variedade de problemas com apenas alguns cliques. Ele fornece um formulário simples que você pode usar para especificar informações detalhadas sobre o problema encontrado e, em seguida, enviar o relatório sem precisar sair do IDE.

Relatar o problema por meio da ferramenta Relatar um Problema é incomum para os tipos de problemas de conjunto de ferramentas discutidos nesse documento, no entanto, é uma opção que você pode escolher se atender às suas preferências.

> [!TIP]
> Para outros tipos de problemas que podem ocorrer no Visual Studio que não estão relacionados ao conjunto de ferramentas (por exemplo, problemas da interface do usuário, funcionalidade do IDE interrompida ou falhas gerais), a ferramenta Relatar um Problema pode ser uma opção especialmente boa devido aos seus recursos de captura de tela e sua capacidade de registrar ações da interface do usuário que levam ao problema encontrado. Você jamais deve informar esses outros tipos de erros enviando um email para compilercrash@microsoft.com.

## <a name="generate"></a> Gerar uma reprodução

Uma reprodução é um exemplo de código completo e independente, que demonstra o problema que você está relatando. Uma reprodução **não** é um trecho de código — ela deve ser um exemplo completo que é compilado e executado (ou que deveria, exceto pelos erros gerados pelo problema que você está relatando). Ele deve conter todas as diretivas #include, mesmo para os cabeçalhos padrão.

Além disso, é uma boa reprodução é

- **Mínima.** As reproduções devem ser o menor possível enquanto ainda demonstram exatamente o problema encontrado. As reproduções não precisam ser complexas ou realistas — reproduções simples e diretas são melhores. Eles não precisam incluir contraexemplos de código que funciona, mas podem incluir se for ilustrativo, apenas o código de exemplo que causa o problema é necessário.

- **Independente.** As reproduções devem evitar dependências desnecessárias. Se você puder reproduzir o problema sem bibliotecas de terceiros, faça isso. Se você puder reproduzir o problema sem nenhum código de biblioteca (`std::out` e `printf()` são ok), faça isso. Reduzir a quantidade de código que precisamos considerar como um possível colaborador para o problema é extremamente útil para nós.

- **Com a versão mais recente do compilador.** As reproduções devem usar a versão mais recente do conjunto de ferramentas sempre que possível. Os problemas que ainda podem ocorrer em versões mais antigas do conjunto de ferramentas muito frequentemente foram corrigidos em versões mais recentes.

- **Comparado a outros compiladores**, se for relevante. As reproduções que envolvem código C++ portátil devem verificar o comportamento em relação a outros compiladores se possível.

   Essa etapa ajuda a determinar se seu código está correto, como quando o MSVC não concorda com Clang e GCC ou incorreto, como quando MSVC, Clang e GCC concordam que seu código produz o erro.

A seguir estão as instruções para gerar os vários tipos de reproduções que você usará para relatar diferentes tipos de problemas.

### <a name="preprocessed-repros"></a>Reproduções pré-processadas

Uma reprodução pré-processada é um único arquivo de origem que demonstra um problema e foi gerado da saída do pré-processador C processando o arquivo de origem original. As linhas internas de processo incluíam cabeçalhos para remover dependências de origem adicionais e arquivos de cabeçalho e também resolvem as macros, #ifdefs e outros comandos de pré-processador que poderiam dependem do seu ambiente local.

> [!NOTE]
> Observe que reproduções pré-processadas são menos convenientes para problemas que podem ser o resultado de bugs em nossa implementação de biblioteca padrão porque geralmente queremos substituir nossa implementação mais recente, em andamento para ver se já corrigimos o problema. Nesse caso, não pré-processe a reprodução e se você não puder reduzir o problema para um único arquivo de origem, compacte seu código em um arquivo .zip ou semelhante ou considere usar uma reprodução de projeto do IDE (consulte [Outras reproduções](#other-repros) abaixo).

#### <a name="to-preprocess-a-source-code-file"></a>Para pré-processar um arquivo de código-fonte

1. Pressione a tecla Windows no teclado e comece a digitar `Developer Command Prompt`.

1. Escolha a versão **Prompt de Comando do Desenvolvedor** que corresponde à versão do Visual Studio que você está usando quando ela aparecer na lista de correspondências.

1. Na janela do console **Prompt de Comando do Desenvolvedor**, insira o comando `cl /P argumentsfilename.cpp`.

Depois de ter o arquivo pré-processado (agora filename.i), é recomendável se certificar de que o problema ainda é reproduzido usando o arquivo pré-processado. Você pode usar o argumento de linha de comando `/TP` para dizer ao cl.exe para ignorar a etapa do pré-processador e tentar compilar como de costume.

#### <a name="to-confirm-that-the-error-still-repros-with-the-preprocessed-file"></a>Para confirmar que o erro ainda é reproduzido com o arquivo pré-processado

1. Pressione a tecla Windows no teclado e comece a digitar `Developer Command Prompt`.

1. Escolha a versão **Prompt de Comando do Desenvolvedor** que corresponde à versão do Visual Studio que você está usando quando ela aparecer na lista de correspondências.

1. Na janela do console **Prompt de Comando do Desenvolvedor**, insira o comando `cl arguments /TP filename.i`.

1. Confirme que o problema é reproduzido.

Por fim, anexe essa reprodução ao seu relatório.

### <a name="link-repros"></a>Reproduções de vinculação

Uma reprodução de vinculação é um único diretório que contém artefatos de build que coletivamente demonstram um problema que ocorre no tempo de vinculação, como falha do back-end envolvendo a LTCG (Geração de Código Durante o Tempo de Vinculação) ou uma falha do vinculador, os artefatos de build incluídos são os necessários como entrada do vinculador para que o problema possa ser reproduzido. As reproduções de vinculação podem ser facilmente criadas usando os recursos fornecidos pelo vinculador.

#### <a name="to-generate-a-link-repro"></a>Para gerar uma reprodução de vinculação

1. Abra um prompt de comando e digite o comando `mkdir directory` para criar um diretório para a reprodução de vinculação.

1. Defina a variável de ambiente link_repro para o diretório que você acabou de criar. Digite o comando `set link_repro=directory`.

1. Se você quiser executar o build de dentro do Visual Studio, inicie-o do prompt de comando inserindo o comando `devenv`. Isso garante que o valor da variável de ambiente link_repro esteja visível para o Visual Studio.

1. Compile seu aplicativo e confirme se o problema esperado ocorreu.

1. Feche o Visual Studio agora se você o iniciou na etapa 3.

1. Limpe a variável de ambiente link_repro. Digite o comando `set link_repro=`

Por fim, compacte a reprodução compactando todo o diretório em um arquivo .zip ou semelhante e anexe-o ao seu relatório.

### <a name="other-repros"></a>Outras reproduções

Se você não puder reduzir o problema para um único arquivo de origem ou reprodução pré-processada e o problema não exigir uma reprodução de vinculação, poderemos investigar e o projeto do IDE. O código dentro do projeto ainda deverá ser mínimo e todas as diretrizes deste documento ainda se aplicam.

Crie sua reprodução como um projeto do IDE mínimo e empacote-o compactando toda a estrutura do diretório em um arquivo .zip ou semelhante e anexe-o ao relatório.