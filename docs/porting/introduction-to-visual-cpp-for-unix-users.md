---
title: Introdução à Microsoft C++ para usuários do UNIX
ms.date: 10/23/2019
helpviewer_keywords:
- UNIX [C++]
ms.assetid: 36108b31-e7fa-49a8-a1f7-7077fcbec873
ms.openlocfilehash: 791c513553acbd300204746ae1e1dddf7a3ae5c4
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626996"
---
# <a name="introduction-to-microsoft-c-for-unix-users"></a>Introdução à Microsoft C++ para usuários do UNIX

Este tópico fornece informações para os usuários de todos os tipos de UNIX que são novos no Visual Studio e que desejam se tornar produtivos C++ a partir da linha de comando ou usando o Visual Studio. Você pode usar o Visual Studio com o C++ compilador da Microsoft para o Windows de destino. Você também pode usar o IDE do Visual Studio com GCC ou clang em ambientes UNIX, como computadores Linux remotos, MinGW-w64 e subsistema do Windows para Linux. Para usar C++ o no Visual Studio, o **desenvolvimento de C++ desktop com** carga de trabalho deve ser instalado. Abra o Instalador do Visual Studio para instalar a carga de trabalho ou adicionar ou remover componentes opcionais. Instale também o **desenvolvimento do Linux C++ com** carga de trabalho se você for direcionar a um computador Linux remoto. Para o desenvolvimento do Android ou do IOS, instale o **desenvolvimento móvel com C++**  carga de trabalho.

## <a name="getting-started-on-the-command-line"></a>Introdução à linha de comando

Você pode usar o compilador C++ da Microsoft na linha de comando de uma maneira semelhante à de usar um ambiente de linha de comando Unix. A compilação ocorre no prompt de comando usando o compilador C e C++ da linha de comando (CL.EXE), o vinculador (LINK.EXE) e outras ferramentas, incluindo o NMAKE.EXE, a versão da Microsoft do utilitário da marca UNIX.

No UNIX, os comandos são instalados em uma pasta comum, como /usr/bin. No Visual Studio, as ferramentas de linha de comando são instaladas no seu diretório de instalação do Visual Studio no subdiretório VC\bin e seus subdiretórios. Ao contrário do UNIX, essas ferramentas não estão disponíveis em uma janela do prompt de comando simples. Para usar as ferramentas de linha de comando, você deve usar um prompt de comando de desenvolvedor especial que configura o caminho e outras variáveis de ambiente que são C++ necessárias para compilar programas. Para obter mais informações, consulte [Compilar código C/C++ na linha de comando](../build/building-on-the-command-line.md) e [Instruções passo a passo: compilando um programa C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md).

## <a name="debugging-your-code"></a>Depurando seu código

Você pode usar o depurador do Visual Studio para C++ projetos da Microsoft na linha de comando ou de dentro do IDE. Compile com a opção [/Z7,/Zi,/Zi (formato de informações de depuração)](../build/reference/z7-zi-zi-debug-information-format.md) para habilitar a passagem por meio de fontes. Para obter mais informações, consulte [Depurando código nativo](/visualstudio/debugger/debugging-native-code) e [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

Para programas compilados com GCC ou Clang, o Visual Studio invoca o GDB, o LLDB ou qualquer depurador personalizado que você especificar.

## <a name="visual-studio-project-system"></a>Sistema de projeto do Visual Studio

O sistema de projeto do Visual Studio é chamado de MSBuild. Ele usa arquivos de projeto em formato XML; C++ arquivos de projeto têm a extensão. vcxproj. Um aplicativo composto por várias bibliotecas e executáveis, cada um deles criado eventualmente com um conjunto diferente de opções do compilador ou até mesmo em uma linguagem diferente, é armazenado em vários projetos que fazem parte de uma única *solução*. Uma solução é uma abstração para um contêiner agrupar vários projetos. As informações sobre soluções são armazenadas em um arquivo de solução com a extensão .sln. Para obter mais informações, consulte [Soluções e projetos no Visual Studio](/visualstudio/ide/solutions-and-projects-in-visual-studio) e [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md). No menu principal, escolha **arquivo** > **novo** **projeto** de > para ver os modelos de projeto disponíveis do Visual Studio.

A partir do Visual Studio 2017, o suporte para projetos CMake é adicionado, bem como opções para usar o C++ compilador da Microsoft com qualquer sistema de compilação arbitrário ou com uma pasta flexível de arquivos de origem e nenhum arquivo de projeto. Para obter mais informações, consulte [projetos do cmake no Visual Studio](../build/cmake-projects-in-visual-studio.md) e [abrir projetos de pasta no Visual Studio](../build/open-folder-projects-cpp.md).

## <a name="microsoft-specific-modifiers"></a>Modificadores específicos da Microsoft

O compilador do Microsoft C++ implementa várias extensões da linguagem de programação C++ padrão para dar suporte à programação para sistemas operacionais Windows. Essas extensões são usadas para especificar atributos de classe de armazenamento, convenções de chamada de função e endereçamento baseado, entre outros. Para obter uma lista completa de todas as extensões do C++ compatíveis, consulte [Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).

Você pode desabilitar todas as extensões específicas da Microsoft para C++ usando a opção do compilador `/Za`. Essa opção é recomendada se você desejar escrever um código para ser executado em várias plataformas. Para obter mais informações sobre a opção do compilador `/Za`, confira [/Za, /Ze (desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md). Para obter mais informações C++ sobre a conformidade do compilador, consulte [tabela de conformidade de idioma da C++ Microsoft](../overview/visual-cpp-language-conformance.md) e comportamento não [padrão](../cpp/nonstandard-behavior.md).

## <a name="precompiled-headers"></a>Cabeçalhos pré-compilados

Os compiladores C e C++ da Microsoft fornecem opções para pré-compilar qualquer código C ou C++, incluindo código embutido. Usando esse recurso de desempenho, é possível compilar um corpo de código estável, armazenar o estado compilado do código em um arquivo e, durante as compilações subsequentes, combinar o código pré-compilado com código que ainda está em desenvolvimento. Cada compilação subsequente é mais rápida, porque o código estável não precisa ser recompilado.

Por padrão, todo código pré-compilado é especificado nos arquivos *pch.h* e *pch.cpp* (*stdafx.h* e *stdafx.cpp* no Visual Studio 2017 e versões anteriores). Para obter mais informações sobre cabeçalhos pré-compilados, consulte [Criando arquivos de cabeçalho pré-compilados](../build/creating-precompiled-header-files.md).

## <a name="related-sections"></a>Seções relacionadas

Para obter mais informações, consulte [executando programas do Linux no Windows](../porting/porting-from-unix-to-win32.md).

## <a name="see-also"></a>Consulte também

[Sistemas de Compilação e Projetos](../build/projects-and-build-systems-cpp.md)
