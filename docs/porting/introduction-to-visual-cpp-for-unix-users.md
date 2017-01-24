---
title: "Introdu&#231;&#227;o ao Visual C++ para usu&#225;rios do UNIX | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "UNIX [C++]"
ms.assetid: 36108b31-e7fa-49a8-a1f7-7077fcbec873
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Introdu&#231;&#227;o ao Visual C++ para usu&#225;rios do UNIX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico fornece informações para usuários do UNIX novatos no [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] e deseja se tornar produtivo com [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  
  
## Guia de Introdução na linha de comando  
 Você pode usar [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] da linha de comando de forma semelhante ao que você usaria um ambiente de linha de comando do UNIX.  Compilar no prompt de comando com o compilador de linha de comando do C e C\+\+ \(CL. EXE\) e ferramentas, inclusive NMAKE. EXE, a versão Microsoft do UNIX tornar utilitário.  
  
 UNIX, comandos são instalados em uma pasta comum, como \/usr\/bin.  Em [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], as ferramentas de linha de comando são instaladas no diretório de instalação em VC\\bin \(em uma instalação típica em Program Files\\Microsoft Visual Studio 8\\VC\\bin\).  Para usar as ferramentas de linha de comando, execute vsvars32. bat, que está localizado no diretório de instalação em Common7\\Tools.  Isso adiciona seu diretório bin em seu caminho e define outros caminhos que são necessários para compilar programas do Visual C\+\+ na linha de comando.  
  
> [!NOTE]
>  Se você abrir um prompt de comando com o **Prompt de linha de comando do Visual Studio** do **Iniciar** menu, em seguida, vsvars32. bat for executado para você.  
  
 Para tirar proveito dos recursos mais poderosos, como o depurador, conclusão de instrução e assim por diante, você precisa usar o ambiente de desenvolvimento.  Para obter mais informações, consulte [Compilando na linha de comando](../Topic/Building%20on%20the%20Command%20Line.md) e [Instruções passo a passo: compilando um programa do C\+\+ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md).  
  
## Depurar seu código  
 Se você usar a linha de comando e executar seus aplicativos em sua estação de trabalho de desenvolvimento, você verá que uma caixa de diálogo para executar o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] depurador é exibido quando seu código encontra uma violação de acesso de memória, a exceção sem tratamento ou outros erros irrecuperáveis.  Se você clicar em **OK**, em seguida, o ambiente de desenvolvimento do Visual Studio é iniciado e o depurador abrirá o ponto de falha.  É possível depurar seus aplicativos dessa maneira e, nesse caso, o código\-fonte só estaria disponível se você compilou com o [\/Z7, \/Zi, \/ZI \(depurar formato de informações\)](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) alternar.  Para obter mais informações, consulte [Depurando código nativo](../Topic/Debugging%20Native%20Code.md) e [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
## Usando o ambiente de desenvolvimento  
 É mais fácil usar o ambiente de desenvolvimento para editar e compilar seu código\-fonte um *projeto*.  Um projeto é uma coleção de fonte e arquivos relacionados que serão compilados em uma única unidade, como uma biblioteca ou executável.  Um projeto também contém informações sobre como os arquivos devem ser criados.  Informações sobre os projetos são armazenadas em um arquivo de projeto com o. prj extensão.  
  
 Um aplicativo que consiste em várias bibliotecas e executáveis, cada potencialmente criados com um conjunto diferente de opções do compilador ou até mesmo em um idioma diferente, são armazenados em vários projetos que fazem parte de um único *solução*.  Uma solução é uma abstração para um contêiner agrupar vários projetos.  Informações sobre as soluções são armazenadas em um arquivo de solução com o. sln extensão.  Para obter mais informações, consulte [PAVE: Managing Solutions and Projects](http://msdn.microsoft.com/pt-br/7a50db22-d3cc-46f3-b648-ab7e0528e260) e [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
## Importando seu código existente  
 Você pode usar [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] para usar o código existente que está configurado para compilar com ou sem um makefile e colocá\-lo em um [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] projeto.  Para obter mais informações, consulte o **Criar projeto de Existing Code Files Wizard**.  Para obter mais informações, consulte [Como criar um projeto do C\+\+ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md).  
  
## Criar um novo projeto  
 Você pode criar novos projetos no ambiente de desenvolvimento.  [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] fornece vários modelos que fornecem código padrão para vários projetos comuns.  Você pode usar assistentes de aplicativo para gerar projetos com estruturas de código para vários tipos de aplicativos.  
  
 Você pode começar com um projeto vazio usando o **Assistente de aplicativo de Console \(Win32\)**.  Selecione o **projeto vazio** caixa de seleção.  Em seguida, você pode adicionar arquivos novos e existentes ao projeto mais tarde.  
  
 Quando você cria um projeto, você deve nomear o projeto.  Por padrão, o nome do projeto é igual ao nome da biblioteca de vínculo dinâmico \(DLL\) ou executável que a compilação do projeto.  Para obter mais informações, consulte [Criando soluções e projetos](../Topic/Creating%20Solutions%20and%20Projects.md).  
  
## Modificadores específicos da Microsoft  
 Visual C\+\+ contém várias extensões de linguagem de programação C\+\+ padrão.  Essas extensões são usadas para especificar atributos de classe de armazenamento, convenções de chamada de função e com base em endereçamento, entre outras coisas.  Para obter uma lista completa de todas as extensões do Visual C\+\+, consulte [Modificadores específicos da Microsoft](../Topic/Microsoft-Specific%20Modifiers.md).  
  
 Você pode desabilitar todas as extensões específicas da Microsoft ao C\+\+ usando o **\/Za** opção de compilador.  Essa opção é recomendada se você quiser escrever código para ser executado em várias plataformas.  Para obter mais informações sobre o **\/Za** opção de compilador, consulte [\/Za, \/Ze \(desabilitar extensões de linguagem\)](../build/reference/za-ze-disable-language-extensions.md).  Para obter mais informações sobre compatibilidade do Visual C\+\+, consulte [Problemas de compatibilidade e conformidade no Visual C\+\+](../misc/compatibility-and-compliance-issues-in-visual-cpp.md).  
  
## Cabeçalhos Pré\-compilados  
 Os compiladores do Microsoft C e C\+\+ fornecem opções para pré\-compilar qualquer código C ou C\+\+, incluindo código embutido.  Usando esse recurso de desempenho, você pode compilar um corpo estável do código, armazenar o estado do código compilado em um arquivo e, durante as compilações subseqüentes, combinar o código pré\-compilado com código que ainda está em desenvolvimento.  Cada compilação subseqüente é mais rápida porque o código estável não precisa ser recompilado.  
  
 Por padrão, todo o código pré\-compilado é especificado nos arquivos **stdafx.h** e **stdafx.cpp**.  O **novo projeto** assistente criará automaticamente esses arquivos para você, a menos que você desmarque a **cabeçalho pré\-compilado** opção.  Para obter mais informações sobre cabeçalhos pré\-compilados, consulte [Criando arquivos de cabeçalho pré\-compilados](../build/reference/creating-precompiled-header-files.md).  
  
## Seções relacionadas  
 Para obter mais informações, consulte [Portando de UNIX para Win32](../porting/porting-from-unix-to-win32.md).  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)