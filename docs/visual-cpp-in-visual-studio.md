---
title: Visual C++ no Visual Studio | Microsoft Docs
ms.custom: 
ms.date: 1/02/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- unmanaged code, C++
- development environment, Visual C++
- unmanaged code
- Visual C++
- Visual C++, reference
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a4eccca9e7afd26684d5845d853b4be98001cf58
ms.sourcegitcommit: a5d8f5b92cb5e984d5d6c9d67fe8a1241f3fe184
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/05/2018
---
# <a name="visual-c-in-visual-studio"></a>Visual C++ no Visual Studio

As ferramentas de desenvolvimento e a linguagem de programação do Visual Studio 2017 ajudam a desenvolver aplicativos nativos universais do Windows, aplicativos nativos de área de trabalho e servidor, bibliotecas de plataforma cruzada que são executadas no Android e no iOS, bem como no Windows e aplicativos gerenciados que são executados no .NET Framework.

**Para quem é esta documentação?**

Este conteúdo é para desenvolvedores de C++ que estão escrevendo programas.

- Se você estiver procurando por um pacote redistribuível e componentes de tempo de execução do C++ para executar um programa, vá até o [Centro de Download da Microsoft](http://www.microsoft.com/en-us/download/) e digite **Visual C++** na caixa de pesquisa.

- Se você estiver procurando por uma introdução aos conceitos de programação do C++, vá até um dos diversos sites que oferece esse conteúdo ou obtenha uma cópia do [Programação – princípios e práticas usando o C++ (Segunda edição)](http://stroustrup.com/Programming/) do inventor do C++, Bjarne Stroustrup. O conteúdo do Visual C++ pressupõe que você já tem uma familiaridade básica com o C++.

- Se você estiver procurando o compilador do Visual C++, será necessário baixar uma edição gratuita ou paga do Visual Studio de [https://www.visualstudio.com/](https://www.visualstudio.com/).

## <a name="general-information-about-visual-c"></a>Informações gerais sobre o Visual C++

[Novidades do Visual C++](what-s-new-for-visual-cpp-in-visual-studio.md)  
Descubra as novidades do Visual C++.

[Aprimoramentos de conformidade do C++ no Visual Studio 2017](cpp-conformance-improvements-2017.md)  
Saiba mais sobre as melhorias de conformidade do C++ no Visual Studio 2017.

[Conformidade com a linguagem Visual C++](visual-cpp-language-conformance.md)  
Uma lista de status de conformidade por recurso no Visual C++.

[Histórico de alterações de 2003 a 2015 do Visual C++](porting/visual-cpp-change-history-2003-2015.md)  
Saiba mais sobre as alterações significativas nas versões anteriores.

[Bem-vindo outra vez ao C++](cpp/welcome-back-to-cpp-modern-cpp.md)  
Saiba mais sobre as técnicas de programação modernas do C++ com base em C++11 e C++14 que permitem que você escreva código rápido e seguro e evite muitas das armadilhas do estilo de programação em C.

[Como relatar um problema com o Conjunto de Ferramentas do Visual C++](how-to-report-a-problem-with-the-visual-cpp-toolset.md)  
 Aprenda a criar relatórios de erro eficazes sobre o conjunto de ferramentas do Visual C++ (compilador, vinculador e outras ferramentas) e as maneiras de enviar o relatório.

[Guia de atualização e portabilidade do Visual C++](porting/visual-cpp-porting-and-upgrading-guide.md)  
Diretrizes para portabilidade de código e atualização de projetos para o Visual C++ no Visual Studio 2017, incluindo a portabilidade de código C++ para o Windows 10 e a Plataforma Universal do Windows.

[Blog da Equipe do Visual C++](http://blogs.msdn.com/b/vcblog/)  
 Saiba mais sobre os novos recursos e as informações mais recentes dos desenvolvedores do [!INCLUDE[vcprvc](build/includes/vcprvc_md.md)].

[Downloads do Visual Studio](http://go.microsoft.com/fwlink/p/?linkid=235233)  
Baixe o Visual C++.

[Ferramentas e recursos do Visual C++ em edições do Visual Studio](ide/visual-cpp-tools-and-features-in-visual-studio-editions.md)  
Descubra as diferentes edições do Visual Studio.

[Plataformas com suporte](supported-platforms-visual-cpp.md)  
Descubra quais plataformas têm suporte.

[Exemplos do Visual C++](visual-cpp-samples.md)  
Informações sobre exemplos.

[Comunidade de Desenvolvedores do Visual Studio](https://developercommunity.visualstudio.com/)  
Saiba como obter ajuda, arquivar bugs e fazer sugestões para o Visual Studio.

## <a name="writing-applications-in-c"></a>Gravando aplicativos no C++

[Aplicativos universais do Windows](windows/universal-windows-apps-cpp.md)  
Encontre guias e conteúdo de referência no Centro de Desenvolvedores do Windows. Para obter informações sobre como desenvolver aplicativos da Windows Store, consulte [Desenvolver aplicativos da Windows Store usando o Visual Studio](http://go.microsoft.com/fwlink/p/?LinkId=248364) e [Roteiro para aplicativos da Windows Store usando o C++](http://go.microsoft.com/fwlink/p/?LinkId=244654).

[Aplicativos de área de trabalho (Visual C++)](windows/desktop-applications-visual-cpp.md)  
Saiba como criar aplicativos de área de trabalho que tenham um loop de mensagens e retornos de chamada.

[DLLs no Visual C++](build/dlls-in-visual-cpp.md)  
Descubra como usar o Win32, o ATL e o MFC para criar DLLs de área de trabalho do Windows e fornece informações sobre como compilar e registrar sua DLL.

[Programação paralela](parallel/parallel-programming-in-visual-cpp.md)  
Saiba como usar a Biblioteca de Padrões Paralelos, C++ AMP, OpenMP e outros recursos que estão relacionados ao multithreading no Windows.

[Práticas Recomendadas de segurança](security/security-best-practices-for-cpp.md)  
Saiba como proteger aplicativos contra código mal-intencionado e de uso não autorizado.

[Programação de Nuvem e da Web](cloud/cloud-and-web-programming-in-visual-cpp.md)  
No C++ há várias opções para conectar-se com a Web e com a nuvem.

[Acesso a dados](http://msdn.microsoft.com/Library/a9455752-39c4-4457-b14e-197772d3df0b)  
Conecte-se a bancos de dados usando ODBC e outras tecnologias de acesso de banco de dados.

[Texto e cadeias de caracteres](text/text-and-strings-in-visual-cpp.md)  
Saiba mais sobre como trabalhar com formatos e codificações diferentes de texto e de cadeia de caracteres para desenvolvimento local e internacional.

## <a name="c-development-tools"></a>Ferramentas de desenvolvimento do C++

Para saber sobre como criar projetos, trabalhar com arquivos de código-fonte, vincular-se a bibliotecas, compilar, depurar, analisar, implantar e muito mais, consulte [IDE e Ferramentas de desenvolvimento](ide/ide-and-tools-for-visual-cpp-development.md).

## <a name="c-language-reference"></a>Referência da linguagem C++

Para obter mais informações sobre a linguagem C++, consulte [Referência da linguagem C++](cpp/cpp-language-reference.md).

Para obter informações sobre o pré-processador C++, consulte [Referência de pré-processador C/C++](preprocessor/c-cpp-preprocessor-reference.md).

## <a name="c-libraries-in-visual-studio"></a>Bibliotecas do C++ no Visual Studio

As seções a seguir fornecem informações sobre as diferentes bibliotecas do C++ que estão incluídas no Visual C++.

[Referência da biblioteca em tempo de execução do C](c-runtime-library/c-run-time-library-reference.md)  
Inclui alternativas aprimoradas de segurança a funções que são conhecidas por impor problemas de segurança.

[Biblioteca Padrão do C++](standard-library/cpp-standard-library-reference.md)  
A Biblioteca Padrão do C++.

[ATL (Active Template Library)](atl/atl-com-desktop-components.md)  
Suporte para aplicativos e componentes COM.

[Bibliotecas MFC (Microsoft Foundation Class)](mfc/mfc-desktop-applications.md)  
Suporte para criação de aplicativos da área de trabalho com interfaces de usuário tradicionais ou no estilo Office.

[PPL (Biblioteca de Padrões Paralelos)](parallel/concrt/parallel-patterns-library-ppl.md)  
Algoritmos assíncronos e paralelos que são executados na CPU.

[C++ AMP (C++ Accelerated Massive Parallelism)](parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)  
Algoritmos totalmente paralelos que são executados na GPU.

[WRL (Biblioteca de Modelos do Windows Runtime)](http://msdn.microsoft.com/library/windows/apps/hh438466.aspx)  
Aplicativos e componentes da [!INCLUDE[win8_appname_long](build/includes/win8_appname_long_md.md)].

[Programação do .NET com C++/CLI (Visual C++)](dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)  
Programação para o CLR (Common Language Runtime).

Consulte também a documentação de [STL/CLR](dotnet/stl-clr-library-reference.md) e da [Biblioteca de suporte do C++](dotnet/cpp-support-library.md).

## <a name="other-c-libraries"></a>Outras bibliotecas do C++

Esta seção contém links para bibliotecas que não estão incluídas no Visual Studio, mas podem ser baixadas e usadas com o Visual C++.

[Boost](http://www.boost.org/)  
Uma biblioteca popular e amplamente usada.

[SDK do C++ REST](http://casablanca.codeplex.com).  
Uma biblioteca da Microsoft para comunicar-se com serviços Web via HTTP.

## <a name="more-resources"></a>Mais recursos

[Recursos do Visual C++](http://msdn.microsoft.com/vstudio/hh386302.aspx)  
Mais recursos do Visual C++.

[C++ Padrão](http://isocpp.org/)  
Saiba mais sobre o C++, obtenha uma visão geral do C++ Moderno e encontre links para livros, artigos, links e eventos

[Aprender sobre o Visual C++](http://msdn.microsoft.com/vstudio/hh386302.aspx)  
Comece a conhecer o C++.

## <a name="see-also"></a>Consulte também

[Referência da linguagem C](c-language/c-language-reference.md)   
[Referência da biblioteca em tempo de execução do C](c-runtime-library/c-run-time-library-reference.md)   
[Intrínsecos do compilador e linguagem assembly](intrinsics/compiler-intrinsics-and-assembly-language.md)
