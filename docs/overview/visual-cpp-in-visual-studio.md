---
title: C++ no Visual Studio
description: Saiba como usar o compilador C/C++ da Microsoft, editor de código e ferramentas relacionadas no Visual Studio para desenvolver programas para Windows, Linux, Android e iOS.
ms.date: 11/05/2020
ms.technology: cpp-ide
helpviewer_keywords:
- Visual C++, home page
ms.openlocfilehash: 32d8f45c1ae0ffeabcfd7b22988f125b138c1f4d
ms.sourcegitcommit: 12eb6a824dd7187a065d44fceca4c410f58e121e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2020
ms.locfileid: "94334150"
---
# <a name="c-in-visual-studio"></a>C++ no Visual Studio

:::moniker range="msvc-160"

> [!NOTE]
> Esta documentação do desenvolvedor se aplica ao Visual Studio 2019. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.
>
> Se você estiver procurando um pacote redistribuível Microsoft Visual C++ 2019, para poder executar um programa, vá para a página de [downloads](https://visualstudio.microsoft.com/downloads/) do site Microsoft Visual Studio. Em **todos os downloads** , expanda a seção **outras ferramentas, estruturas e redistribuíveis** . Selecione sua arquitetura de destino e, em seguida, escolha o botão **baixar** .
>
> Para redistribuíveis mais antigos, abra a página de [downloads mais antiga](https://visualstudio.microsoft.com/vs/older-downloads/) . Expanda a seção **outras ferramentas, estruturas e redistribuíveis** . Localize a versão redistribuível que você deseja baixar, selecione sua arquitetura de destino e, em seguida, escolha o botão **baixar** .

:::moniker-end

:::moniker range="msvc-150"

> [!NOTE]
> Esta documentação do desenvolvedor se aplica ao Visual Studio 2017. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.
>
> Se você estiver procurando um Microsoft Visual C++ 2017 ou um pacote redistribuível mais antigo para poder executar um programa, acesse a página de [downloads mais antigos](https://visualstudio.microsoft.com/vs/older-downloads/) do site do Microsoft Visual Studio. Expanda a seção **outras ferramentas, estruturas e redistribuíveis** . Localize a versão redistribuível que você deseja baixar, selecione sua arquitetura de destino e, em seguida, escolha o botão **baixar** .

:::moniker-end

:::moniker range="msvc-140"

> [!NOTE]
> Esta documentação do desenvolvedor se aplica ao Visual Studio 2015. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.
>
> Se você estiver procurando um Microsoft Visual C++ 2015 ou um pacote redistribuível mais antigo para poder executar um programa, acesse a página de [downloads mais antigos](https://visualstudio.microsoft.com/vs/older-downloads/) do site do Microsoft Visual Studio. Expanda a seção **outras ferramentas, estruturas e redistribuíveis** . Localize a versão redistribuível que você deseja baixar, selecione sua arquitetura de destino e, em seguida, escolha o botão **baixar** .

:::moniker-end

Microsoft Visual C++ (MSVC) refere-se às ferramentas e bibliotecas de desenvolvimento de linguagem de assembly, C++ e C, disponíveis como parte do Visual Studio no Windows. Essas ferramentas e bibliotecas permitem que você crie aplicativos da UWP (Plataforma Universal do Windows), aplicativos de servidor e área de trabalho Windows nativos, bibliotecas e aplicativos multiplataforma que são executados no Windows, Linux, Android e iOS, bem como bibliotecas e aplicativos que usam o .NET Framework. Você pode usar o MSVC para escrever tudo, desde aplicativos simples de console até os aplicativos mais sofisticados e complexos para o Windows desktop, de drivers de dispositivo e componentes de sistema operacional até jogos de plataforma cruzada para dispositivos móveis e dos menores dispositivos IoT para computação de alto desempenho de vários servidores na nuvem do Azure.

O Visual Studio 2015, 2017 e 2019 podem ser instalados lado a lado. Você pode usar o Visual Studio 2019 (compilador de conjunto de ferramentas v142) ou o Visual Studio 2017 (v141) para editar e criar programas usando o conjunto de ferramentas do Visual Studio 2017 (v141) e do Visual Studio 2015 (V140).

## <a name="whats-new-and-conformance-history"></a>Histórico de novidades e de conformidade

[O que há de novo para C++ no Visual Studio](what-s-new-for-visual-cpp-in-visual-studio.md)\
Descubra as novidades do Visual Studio.

[O que há de novo para C++ no Visual Studio 2003 até 2015](../porting/visual-cpp-what-s-new-2003-through-2015.md)\
Descubra quais foram as novidades do C++ para cada versão do Visual Studio, de 2003 até 2015.

[Melhorias de conformidade do C++ no Visual Studio](cpp-conformance-improvements.md)\
Saiba mais sobre as melhorias de conformidade do C++ no Visual Studio.

[Tabela de conformidade da linguagem Microsoft C++](visual-cpp-language-conformance.md)\
Uma lista de status de conformidade por recurso no compilador C++ do MSVC.

[Histórico de alterações do Microsoft C/C++ 2003-2015](../porting/visual-cpp-change-history-2003-2015.md)\
Saiba mais sobre as alterações significativas nas versões anteriores.

## <a name="install-visual-studio-and-upgrade-from-earlier-versions"></a>Instalar o Visual Studio e atualizar de versões anteriores

[Instalar o suporte a C++ no Visual Studio](../build/vscpp-step-0-installation.md)\
Baixe o Visual Studio e instale o conjunto de ferramentas do Microsoft C/C++.

[Guia de atualização e portabilidade do Microsoft C++](../porting/visual-cpp-porting-and-upgrading-guide.md)\
Diretrizes para portabilidade de código e para atualização de projetos para o Visual Studio 2015 ou posterior para aproveitar a maior conformidade do compilador com o padrão do C++, além de tempos de compilação e recursos de segurança muito aprimorados como a mitigação do Spectre.

[Ferramentas e recursos do C++ nas edições do Visual Studio](visual-cpp-tools-and-features-in-visual-studio-editions.md)\
Descubra as diferentes edições do Visual Studio.

[Plataformas com suporte](supported-platforms-visual-cpp.md)\
Descubra em quais plataformas o compilador do Microsoft C/C++ dá suporte.

## <a name="learn-c"></a>Aprender sobre o C++

[Bem-vindo de volta ao C++](../cpp/welcome-back-to-cpp-modern-cpp.md)\
Saiba mais sobre as técnicas de programação modernas do C++ com base no C++11 e versões posteriores que permitem que você escreva código rápido e seguro e evite muitas armadilhas do estilo de programação em C.

[C++ padrão](https://isocpp.org/)\
Saiba mais sobre o C++, obtenha uma visão geral do C++ Moderno e encontre links para livros, artigos, links e eventos

[Aprenda o Visual Studio e crie seu primeiro projeto C++](../build/vscpp-step-1-create.md)\
Comece a aprender a escrever C++ no Visual Studio.

[Amostras do Visual Studio C++](visual-cpp-samples.md)\
Informações sobre os exemplos de código C++ fornecidos pela Microsoft.

## <a name="c-development-tools"></a>Ferramentas de desenvolvimento do C++

[Visão geral do desenvolvimento em C++ no Visual Studio](overview-of-cpp-development.md)\
Como usar o IDE do Visual Studio para criar projetos, editar código, vincular a bibliotecas, compilar, depurar, criar testes de unidade, fazer análise estática, implantar e muito mais.

[Projetos e sistemas de compilação](../build/projects-and-build-systems-cpp.md)\
Como criar e configurar projetos do Visual Studio C++, projetos CMake e outros tipos de projetos com as opções de compilador e vinculador do MSVC.

[Escrevendo e Refatorando o código do C++](../ide/writing-and-refactoring-code-cpp.md)\
Como usar os recursos de produtividade no editor do C++ para refatorar, navegar, entender e escrever código.

[Depuração de código nativo](/visualstudio/debugger/debugging-native-code)\
Use o depurador do Visual Studio com projetos C++.

[Visão geral da análise de código para C/C++](../code-quality/code-analysis-for-c-cpp-overview.md)\
Use anotações de SAL ou os verificadores das Diretrizes Principais do C++ para executar análise estática.

[Escrever testes de unidade para C/C++ no Visual Studio](/visualstudio/test/writing-unit-tests-for-c-cpp)\
Crie testes de unidade usando a Estrutura de Teste de Unidade da Microsoft para C++, Google Test, Boost.Test ou CTest.

## <a name="write-applications-in-c"></a>Escrever aplicativos em C++

[Aplicativos universais do Windows (C++)](../cppcx/universal-windows-apps-cpp.md)\
Encontre guias e conteúdo de referência no Centro de Desenvolvedores do Windows. Para obter informações de como desenvolver aplicativos UWP, confira [Introdução à Plataforma Universal do Windows](/windows/uwp/get-started/universal-application-platform-guide) e [Criar um app "Hello world" em C++](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp).

[Aplicativos de desktop (C++)](../windows/desktop-applications-visual-cpp.md)\
Saiba como criar aplicativos da área de trabalho tradicionais, nativos, em C++ para Windows.

[Programação .NET com C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)\
Saiba como criar DLLs que permitem a interoperabilidade entre programas nativos em C++ e no .NET escritos em linguagens como C# ou Visual Basic.

[Programação em Linux](../linux/index.yml)\
Use o Visual Studio IDE para codificar e implantar em um computador Linux remoto para compilação com GCC.

[Criar DLLs C/C++ no Visual Studio](../build/dlls-in-visual-cpp.md)\
Descubra como usar o Win32, o ATL e o MFC para criar DLLs de área de trabalho do Windows e fornece informações sobre como compilar e registrar sua DLL.

[Programação paralela](../parallel/parallel-programming-in-visual-cpp.md)\
Saiba como usar a Biblioteca de Padrões Paralelos, C++ AMP, OpenMP e outros recursos que estão relacionados ao multithreading no Windows.

[Práticas recomendadas de segurança](../security/security-best-practices-for-cpp.md)\
Saiba como proteger aplicativos contra código mal-intencionado e de uso não autorizado.

[Programação na nuvem e na Web](../cloud/cloud-and-web-programming-in-visual-cpp.md)\
No C++ há várias opções para conectar-se com a Web e com a nuvem.

[Acesso a dados](../data/data-access-in-cpp.md)\
Conecte-se a bancos de dados usando ODBC e OLE DB.

[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)\
Saiba mais sobre como trabalhar com formatos e codificações diferentes de texto e de cadeia de caracteres para desenvolvimento local e internacional.

## <a name="languages-reference"></a>Referência de linguagens

[Referência da linguagem C++](../cpp/cpp-language-reference.md)\
O guia de referência para a implementação da Microsoft da linguagem de programação C++.

[Referência de pré-processador do C/C++](../preprocessor/c-cpp-preprocessor-reference.md)\
Uma referência comum ao pré-processador de linguagem C e C++ compartilhado.

[Referência da linguagem C](../c-language/c-language-reference.md)\
O guia de referência para a implementação da linguagem de programação C da Microsoft.

[Intrínsecos do compilador e linguagem do assembly](../intrinsics/compiler-intrinsics-and-assembly-language.md)\
Guias para o compilador intrínsecos com suporte ou implementados pelos compiladores C/C++ da Microsoft em cada plataforma.

## <a name="c-libraries-in-visual-studio"></a>Bibliotecas do C++ no Visual Studio

As seções a seguir fornecem informações sobre as diferentes bibliotecas do C e C++ que estão incluídas no Visual Studio.

[Referência da biblioteca de tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)\
Inclui alternativas aprimoradas de segurança a funções que são conhecidas por impor problemas de segurança.

[Biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)\
A Biblioteca Padrão do C++.

[Active Template Library (ATL)](../atl/atl-com-desktop-components.md)\
Compatibilidade com aplicativos e componentes COM.

[Bibliotecas do Microsoft Foundation Class (MFC)](../mfc/mfc-desktop-applications.md)\
Suporte para criação de aplicativos da área de trabalho com interfaces de usuário tradicionais ou no estilo Office.

[Biblioteca de padrões paralelos (PPL)](../parallel/concrt/parallel-patterns-library-ppl.md)\
Algoritmos assíncronos e paralelos que são executados na CPU.

[C++ AMP (C++ Accelerated Massive Parallelism)](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)\
Algoritmos totalmente paralelos que são executados na GPU.

[WRL (biblioteca de modelos de Windows Runtime)](../cppcx/wrl/windows-runtime-cpp-template-library-wrl.md)\
Aplicativos UWP (Plataforma Universal do Windows) e componentes.

[Programação .NET com C++/CLI](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)\
Programação para o CLR (Common Language Runtime).

## <a name="third-party-open-source-c-libraries"></a>Bibliotecas C++ de software livre de terceiros

A ferramenta de linha de comando **vcpkg** multiplataforma simplifica bastante a descoberta e a instalação de mais de 900 bibliotecas C++ de software livre. Consulte [vcpkg: gerenciador de pacotes de C++ para Windows](../build/vcpkg.md).

## <a name="feedback-and-community"></a>Comentários e comunidade

[Microsoft Docs Q&A](/answers/topics/c%2B%2B.html)\
Microsoft Docs hospeda fóruns pesquisáveis para perguntas e respostas. Adicione uma `C++` marca à sua postagem para assistência da Comunidade sobre problemas relacionados ao C++.

[Como relatar um problema com o conjunto de ferramentas do Microsoft C/C++](how-to-report-a-problem-with-the-visual-cpp-toolset.md)\
Saiba como criar relatórios de erros efetivos no conjunto de ferramentas do Microsoft C/C++ (compilador, vinculador e outras ferramentas) e maneiras de enviar seu relatório.

[Blog da equipe](https://devblogs.microsoft.com/cppblog/) do Microsoft C++\
Saiba mais sobre os novos recursos e as informações mais recentes dos desenvolvedores das ferramentas do C++ no Visual Studio.

[Comunidade de desenvolvedores do Visual Studio C++](https://aka.ms/vsfeedback/browsecpp)\
Obtenha ajuda, arquivos de erros e faça sugestões para C++ no Visual Studio.
