---
title: Criando e gerenciando projetos do Visual C++
ms.date: 11/04/2016
f1_keywords:
- vcprojects
- creatingmanagingVC
helpviewer_keywords:
- ATL projects, creating
- Visual C++ projects, creating
- projects [C++], creating
- Visual C++ projects
- ATL projects
ms.assetid: 11003cd8-9046-4630-a189-a32bf3b88047
ms.openlocfilehash: e511ef597e64a3782ce7a3ce650db065e9299cdd
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57744331"
---
# <a name="creating-and-managing-msbuild-based-visual-c-projects"></a>Criando e gerenciando projetos do Visual C++ baseados no MSBuild

O MSBuild é o sistema de build nativo para o Visual C++ e, geralmente, é o melhor sistema de build a ser usado para aplicativos UWP, bem como para aplicativos da Área de Trabalho que usam bibliotecas MFC ou ATL. O MSBuild está totalmente integrado com o IDE e o sistema de projeto do Visual Studio, mas você também pode usá-lo na linha de comando. Começando pelo Visual Studio 2017, o Visual C++ dá suporte ao [CMake e a outros sistemas que não são MSBuild, por meio do recurso Abrir Pasta](non-msbuild-projects.md).

Um projeto baseado no MSBuild tem um arquivo de projeto em formato XML (.vcxproj) que especifica todos os arquivos e recursos necessários para compilar o programa, bem como outras definições de configuração, por exemplo, a plataforma de destino (x86, x64 ou ARM) e indica se você está compilando uma versão de lançamento ou de depuração do programa. Um projeto (ou muitos projetos) estão contidos em uma *Solução*; por exemplo, uma solução pode conter vários projetos de DLL do Win32 e um único aplicativo de console Win32 que usa essas DLLs. Quando você compila o projeto, o mecanismo MSBuild consome o arquivo de projeto e produz o arquivo executável e/ou outra saída personalizada especificada.

Crie projetos do Visual C++ escolhendo **Arquivo &#124; Novo &#124; Projeto**, garantindo que o Visual C++ esteja selecionado no painel esquerdo e, em seguida, escolhendo uma opção na lista de modelos de projeto no painel central. Quando você clicar em um modelo, em muitos casos, será exibido um assistente, que permite definir várias propriedades do projeto antes de sua criação. Exiba e modifique essas propriedades posteriormente usando as páginas de propriedades do projeto (**Projeto &#124; Propriedades**).

Crie também novos projetos das seguintes maneiras:

- escolhendo **Arquivo &#124; Novo &#124; Projeto com base em um Código Existente** e seguindo os prompts para adicionar arquivos de código-fonte existentes. Essa opção funciona melhor para projetos relativamente pequenos e simples, talvez com 25 arquivos de código-fonte ou menos, com poucas ou nenhuma dependência complexa.

- começando com um makefile e escolhendo o modelo de Projeto Makefile na guia Geral.

- criando um projeto vazio (na guia **Geral**) e adicionando os arquivos de código-fonte manualmente clicando com o botão direito do mouse no nó do projeto no Gerenciador de Soluções e escolhendo **Adicionar &#124; Item Existente**.

- usando o [Assistente de Aplicativo Win32](../windows/win32-application-wizard.md).

## <a name="in-this-section"></a>Nesta seção

[Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)<br>
Descreve os tipos de projeto baseados no MSBuild disponíveis no Visual C++.

[Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)<br>
Descreve os tipos de arquivos usados ​com vários tipos de projeto do MSBuild.

[Criando projetos para área de trabalho com Assistentes de Aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)<br>
Como usar os assistentes para criar projetos com o Visual C++.

[Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)<br>
Descreve como usar as Páginas de Propriedades e as Folhas de Propriedades para especificar as configurações do projeto.

[Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)<br>
Descreve como adicionar classes, métodos, variáveis e outros elementos ao seu projeto para adicionar funcionalidade.

[Como: Organizar arquivos de saída do projeto para compilações](../ide/how-to-organize-project-output-files-for-builds.md)<br>
Descreve como organizar arquivos de saída do projeto.

## <a name="related-sections"></a>Seções relacionadas

[Compilando programas do C/C++](../build/building-c-cpp-programs.md)<br>
Fornece links para tópicos que descrevem como compilar seu programa pela linha de comando ou pelo ambiente de desenvolvimento integrado do Visual Studio.

## <a name="see-also"></a>Consulte também

[SDK do Visual Studio](https://msdn.microsoft.com/vstudio/extend)
