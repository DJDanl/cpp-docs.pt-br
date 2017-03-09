---
title: "Introdução ao Visual C++ para usuários do UNIX | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- UNIX [C++]
ms.assetid: 36108b31-e7fa-49a8-a1f7-7077fcbec873
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: 7c75629d56e6d8e5291b7d1f7cca9995ab9a50da
ms.openlocfilehash: d8515fc613f95ae5d6395e33b49482488bcc488d
ms.lasthandoff: 02/25/2017

---
# <a name="introduction-to-visual-c-for-unix-users"></a>Introdução ao Visual C++ para usuários do UNIX
Este tópico fornece informações para usuários do UNIX novatos no [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] e que desejam tornar-se produtivos com o [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  
  
## <a name="getting-started-on-the-command-line"></a>Introdução à linha de comando  
 É possível usar o [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] na linha de comando de forma semelhante à que você usaria um ambiente de linha de comando UNIX. Você compila no prompt de comando com as ferramentas e o compilador C e C++ da linha de comando (CL.EXE), incluindo NMAKE.EXE, a versão da Microsoft do utilitário da marca UNIX.  
  
 No UNIX, os comandos são instalados em uma pasta comum, como /usr/bin. No [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], as ferramentas de linha de comando são instaladas em seu diretório de instalação em VC\bin (em uma instalação típica em Arquivos de Programas\Microsoft Visual Studio 8\VC\bin). Para usar as ferramentas de linha de comando, execute vsvars32. bat, localizado no diretório de instalação em Common7\Tools. Isso adiciona seu diretório bin a seu caminho e configura outros caminhos necessários para compilar programas do Visual C++ na linha de comando. Para obter mais informações, consulte [Compilando na linha de comando](../build/building-on-the-command-line.md) e [Instruções passo a passo: compilando um programa do C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md).  
  
> [!NOTE]
>  Se você abrir um prompt de comando com o **Prompt de linha de comando do Visual Studio** no menu **Iniciar**, então vsvars32.bat será executado para você.  
  
 Para aproveitar os recursos mais avançados do Visual Studio, como o depurador, preenchimento de declaração e assim por diante, é necessário usar o ambiente de desenvolvimento.  
  
## <a name="debugging-your-code"></a>Depurando seu código  
 Se você usar a linha de comando e executar seus aplicativos em sua estação de trabalho de desenvolvimento, verá que uma caixa de diálogo para executar o depurador [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] será exibida quando seu código encontrar uma violação de acesso de memória, exceção sem tratamento ou outros erros irrecuperáveis. Se você clicar em **OK**, então o ambiente de desenvolvimento do Visual Studio será iniciado e o depurador será aberto no ponto de falha. É possível depurar seus aplicativos dessa maneira e, nesse caso, seu código-fonte só estaria disponível se você compilasse com a opção [/Z7, /Zi, /ZI (formato de informação de depuração)](../build/reference/z7-zi-zi-debug-information-format.md). Para obter mais informações, consulte [Depurando código nativo](/visualstudio/debugger/debugging-native-code) e [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
## <a name="using-the-development-environment"></a>Usando o ambiente de desenvolvimento  
 É mais fácil usar o ambiente de desenvolvimento para editar e compilar seu código-fonte em um *projeto*. Um projeto é uma coleção de fonte e arquivos relacionados que serão compilados em uma única unidade, como uma biblioteca ou um executável. Um projeto também contém informações sobre como os arquivos devem ser criados. As informações sobre projetos são armazenadas em um arquivo de projeto com a extensão .prj.  
  
 Um aplicativo composto por várias bibliotecas e executáveis, cada um deles criado eventualmente com um conjunto diferente de opções do compilador ou até mesmo em uma linguagem diferente, é armazenado em vários projetos que fazem parte de uma única *solução*. Uma solução é uma abstração para um contêiner agrupar vários projetos. As informações sobre soluções são armazenadas em um arquivo de solução com a extensão .sln. Para obter mais informações, consulte [Soluções e projetos no Visual Studio](/visualstudio/ide/solutions-and-projects-in-visual-studio) e [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
## <a name="importing-your-existing-code"></a>Importando seu código existente  
 É possível usar o [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] para usar o código existente configurado para compilar com ou sem um makefile e colocá-lo em um projeto [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)]. Para obter mais informações, consulte o **Create Project From Existing Code Files Wizard (Assistente de Criação de projetos com base em arquivos de código existentes)**. Para obter mais informações, consulte [Como criar um projeto do C++ com base no código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md).  
  
## <a name="creating-a-new-project"></a>Criando um novo projeto  
 É possível criar novos projetos no ambiente de desenvolvimento. O [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] oferece vários modelos que fornecem código padrão para vários projetos comuns. É possível usar assistentes de aplicativo para gerar projetos com estruturas de tópicos de código para vários tipos de aplicativo.  
  
 É possível começar com um projeto vazio usando o **Assistente de aplicativo de console (Win32)**. Marque a caixa de seleção **Projeto vazio**. Em seguida, é possível adicionar arquivos novos e existentes ao projeto mais tarde.  
  
 Quando você cria um projeto, é necessário nomeá-lo. Por padrão, o nome do projeto é igual ao nome da DLL (biblioteca de vínculo dinâmico) ou do executável compilado com base no projeto. Para obter mais informações, consulte [Criando soluções e projetos](/visualstudio/ide/creating-solutions-and-projects).  
  
## <a name="microsoft-specific-modifiers"></a>Modificadores específicos da Microsoft  
 O Visual C++ contém várias extensões da linguagem de programação C++ padrão. Essas extensões são usadas para especificar atributos de classe de armazenamento, convenções de chamada de função e endereçamento baseado, entre outros. Para obter uma lista completa de todas as extensões do Visual C++, consulte [Microsoft-Specific Modifiers (Modificadores específicos da Microsoft)](../cpp/microsoft-specific-modifiers.md).  
  
 É possível desabilitar todas as extensões específicas da Microsoft do C++ usando a opção do compilador **/Za**. Essa opção é recomendada se você desejar escrever um código para ser executado em várias plataformas. Para obter mais informações sobre a opção do compilador **/Za**, consulte [/Za, /Ze (Desabilitar Extensões de Linguagem)](../build/reference/za-ze-disable-language-extensions.md). Para obter mais informações sobre a conformidade do Visual C++, consulte [Comportamento não padrão](../cpp/nonstandard-behavior.md).  
  
## <a name="precompiled-headers"></a>Cabeçalhos Pré-compilados  
 Os compiladores C e C++ da Microsoft fornecem opções para pré-compilar qualquer código C ou C++, incluindo código embutido. Usando esse recurso de desempenho, é possível compilar um corpo de código estável, armazenar o estado compilado do código em um arquivo e, durante as compilações subsequentes, combinar o código pré-compilado com código que ainda está em desenvolvimento. Cada compilação subsequente é mais rápida, porque o código estável não precisa ser recompilado.  
  
 Por padrão, todo código pré-compilado é especificado nos arquivos **stdafx.h** e **stdafx.cpp**. O assistente **Novo projeto** criará automaticamente esses arquivos para você, a menos que você desmarque a opção **Cabeçalho pré-compilado**. Para obter mais informações sobre cabeçalhos pré-compilados, consulte [Criando arquivos de cabeçalho pré-compilados](../build/reference/creating-precompiled-header-files.md).  
  
## <a name="related-sections"></a>Seções relacionadas  
 Para obter mais informações, consulte [Porting from UNIX to Win32 (Portabilidade do UNIX para Win32)](../porting/porting-from-unix-to-win32.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tour guiado do Visual C++](http://msdn.microsoft.com/en-us/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)
