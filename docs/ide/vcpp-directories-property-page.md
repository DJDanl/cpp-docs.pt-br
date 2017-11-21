---
title: "Página de propriedade de diretórios VC + + | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCDirectories.IncludePath
- VC.Project.VCDirectories.ReferencePath
- VC.Project.VCDirectories.SourcePath
- VC.Project.VCDirectories.LibraryWPath
- VC.Project.VCDirectories.ExecutablePath
- VC.Project.VCDirectories.LibraryPath
- VS.ToolsOptionsPages.Projects.VCDirectories
- VC.Project.VCDirectories.ExcludePath
dev_langs: C++
helpviewer_keywords: VC++ Directories Property Page
ms.assetid: 428eeef6-f127-4271-b3ea-0ae6f2c3d624
caps.latest.revision: "25"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 30a54b1d90585e6433f059acf30991ca53948d60
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="vc-directories-property-page"></a>Página de propriedade dos diretórios do VC++
Especifica os diretórios que você deseja que o Visual Studio use para compilar um projeto. Para acessar esta página de propriedades, na **Solution Explorer**, abra o menu de atalho para o projeto e escolha **propriedades**e, em seguida, no painel esquerdo do **páginas de propriedade** caixa de diálogo caixa, expanda **propriedades de configuração** e selecione **diretórios VC + +**.  
  
 Quando você usa o Visual Studio para criar um projeto, ele herda determinados diretórios. Vários deles são fornecidos como macros. Para examinar o valor atual de uma macro, no painel à direita do **diretórios VC + +** , selecione uma linha — por exemplo, **diretórios de inclusão**— escolha o botão de seta para baixo à direita, escolha  **Editar**e, em seguida, na caixa de diálogo que aparece, escolha o **Macros** botão. Para obter mais informações, veja estas postagens do blog: [diretórios VC + +](http://blogs.msdn.com/b/vsproject/archive/2009/07/07/vc-directories.aspx), [propriedades herdadas e folhas de propriedade](http://blogs.msdn.com/b/vsproject/archive/2009/06/23/inherited-properties-and-property-sheets.aspx), e [Visual Studio 2010 C++ projeto guia de atualização](http://blogs.msdn.com/b/vcblog/archive/2010/03/02/visual-studio-2010-c-project-upgrade-guide.aspx).  
  
## <a name="directory-types"></a>Tipos de diretório  
 Você também pode especificar outros diretórios, como a seguir.  
  
 **Diretórios executáveis**  
 Diretórios onde procurar por arquivos executáveis. Corresponde do **caminho** variável de ambiente.  
  
 **Incluir Diretórios**  
 Diretórios nos quais procurar por arquivos de inclusão que são referenciados no código-fonte. Corresponde do **incluir** variável de ambiente.  
  
 **Diretórios de referência**  
 Diretórios para a pesquisa de assembly e arquivos de módulo (metadados) que são referenciados no código-fonte, o [#using](../preprocessor/hash-using-directive-cpp.md) diretiva. Corresponde do **LIBPATH** variável de ambiente.  
  
 **Diretórios de Biblioteca**  
 Diretórios onde procurar por arquivos de bibliotecas (.lib); isso inclui as bibliotecas em tempo de execução. Corresponde do **LIB** variável de ambiente. Essa configuração não se aplica a arquivos. obj; Para vincular a um arquivo. obj, do [vinculador](../ide/linker-property-pages.md)**geral** página de propriedades, selecione **dependências de biblioteca adicionais** e, em seguida, especifique o caminho relativo do arquivo.  
  
 **Diretórios de origem**  
 Diretórios onde procurar por arquivos de origem para uso para o IntelliSense.  
  
 **Excluir diretórios**  
 Diretórios onde não procurar ao verificar dependências de compilação.  
  
#### <a name="to-specify-or-modify-directory-settings"></a>Para especificar ou modificar as configurações de diretório  
  
1.  Em **Solution Explorer**, abra o menu de atalho para o projeto que você deseja alterar e, em seguida, escolha **propriedades**.  
  
2.  No painel esquerdo do **páginas de propriedade** caixa de diálogo caixa, expanda **propriedades de configuração** e, em seguida, selecione **diretórios VC + +**.  
  
3.  Para modificar uma das listas de diretório, selecione-o, escolha o botão de seta para baixo à direita e, em seguida, escolha **editar**.  
  
     Na caixa de diálogo que aparece, você pode adicionar ou remover valores, e pode reorganizar a ordem em que os valores são exibidos. Você também pode alterar se o projeto herda as configurações selecionando ou desmarcando **herdar do pai ou padrões de projeto**.  
  
## <a name="sharing-the-settings"></a>Compartilhando as configurações  
 Você pode compartilhar propriedades do projeto com outros usuários ou em vários computadores. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
