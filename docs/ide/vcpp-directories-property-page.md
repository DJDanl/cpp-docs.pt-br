---
title: "Página de propriedade de diretórios VC + + | Microsoft Docs"
ms.custom: 
ms.date: 11/28/2017
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
ms.workload: cplusplus
ms.openlocfilehash: 2c92a97ccd28a1bc7d1fae518cf499b45d339dae
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vc-directories-property-page-windows"></a>Página de propriedades VC + + diretórios (Windows)

Use esta página de propriedades para informar o Visual Studio os diretórios para usar ao criar o projeto selecionado no momento. Para definir os diretórios para vários projetos em uma solução, use uma folha de propriedades personalizadas, conforme descrito em [criar configurações de propriedade reutilizável](working-with-project-properties.md#bkmkPropertySheets).

Para a versão do Linux dessa página, consulte [diretórios VC + + (C++ Linux)](../linux/prop-pages/directories-linux.md).   

Para acessar o **diretórios VC + +** página de propriedades:

1. no menu principal, escolha **exibição | Gerenciador de soluções**
1. Clique com botão direito no nó do projeto (não a solução de nível superior) e escolha **propriedades**
1. no painel esquerdo do **páginas de propriedade** caixa de diálogo caixa, expanda **propriedades de configuração** e selecione **diretórios VC + +**.  

Propriedades de diretórios VC + + se aplicam a um projeto, não no nó da solução de nível superior:

![Selecione o nó do projeto](media/vcppdir.png "selecionar o nó do projeto para ver as propriedades de diretórios VC + +")

Se você não vir a página de propriedades, verifique se você tem o nó do projeto selecionado no **Gerenciador de soluções**. Observe que uma **diretórios VC + +** página de propriedades de projetos de plataforma cruzada parece diferente. Para projetos de não-Windows, consulte [diretórios VC + + (C++ Linux)](../linux/prop-pages/directories-linux.md) ou. 
 
Se você não estiver familiarizado com *propriedades do projeto* no Visual Studio, talvez seja útil ler primeiro [trabalhar com propriedades do projeto](working-with-project-properties.md). 
 
As configurações padrão para diretórios VC + + dependem do tipo de projeto. Para projetos de área de trabalho, eles incluem os locais de ferramentas do VC + + para um determinado conjunto de ferramentas de plataforma e o local do SDK do Windows. Você pode alterar o **conjunto de ferramentas de plataforma** e **versão do SDK do Windows** no **propriedades de configuração – geral** página. Para exibir os valores para qualquer um dos diretórios:

1. no painel à direita do **diretórios VC + +** , selecione uma linha. Por exemplo, **diretórios de biblioteca**
1. Escolha o botão de seta para baixo à direita
1. Escolha **editar**.

![Editar diretórios de biblioteca](media/vcppdir_libdir_edit.png "caixa de diálogo para editar os caminhos de biblioteca")

Agora, você verá uma caixa de diálogo como esta: 

![Mostrar diretórios de biblioteca](media/vcppdir_libdir.png "caixa de diálogo para adicionar ou remover caminhos de biblioteca")

Use esta caixa de diálogo para exibir os diretórios atuais. No entanto, se você quiser alterar ou adicionar um diretório, é melhor usar **Gerenciador de propriedades** para criar uma folha de propriedades ou modificar a folha de propriedades de usuário padrão. Para obter mais informações, consulte [criar configurações de propriedade reutilizável](working-with-project-properties.md#bkmkPropertySheets).

Como mostrado acima, muitos dos caminhos herdados são fornecidos como macros.  Para examinar o valor atual de uma macro, escolha o **Macros** botão no canto inferior direito da caixa de diálogo. Observe que muitas macros dependem do tipo de configuração. Uma macro em uma compilação de depuração pode ser avaliada como um caminho diferente de macro mesmo em uma compilação de versão. 

Você pode procurar as correspondências parciais ou completa na caixa de edição. A ilustração a seguir mostra todas as macros que contêm a cadeia de caracteres "WindowsSDK" e também mostra o caminho atual que avalia a macro:

![Consulte os valores de macro](media/vcppdir_libdir_macros.png "caixa de diálogo Editar macros")

Observação: A lista populará conforme você digita. Não pressione **Enter**.

Para obter mais informações sobre macros e por que você deve usá-los em vez de caminhos embutidos sempre que possível, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md#bkmkPropertiesVersusMacros). 

Para obter uma lista de macros usadas, consulte [comuns Macros para compilar comandos e propriedades](https://docs.microsoft.com/en-us/cpp/ide/common-macros-for-build-commands-and-properties).

Você pode definir suas próprias macros de duas maneiras:
-   Definir variáveis de ambiente em um prompt de comando do desenvolvedor. Todas as variáveis de ambiente são tratadas como propriedades do MSBuild/macros.
-   Defina macros do usuário em um arquivo de .props. Para obter mais informações, consulte [macros de página de propriedade](working-with-project-properties.md#bkmkPropertiesVersusMacros). 

Para obter mais informações, veja estas postagens do blog: [diretórios VC + +](http://blogs.msdn.com/b/vsproject/archive/2009/07/07/vc-directories.aspx), [propriedades herdadas e folhas de propriedade](http://blogs.msdn.com/b/vsproject/archive/2009/06/23/inherited-properties-and-property-sheets.aspx), e [Visual Studio 2010 C++ projeto guia de atualização](http://blogs.msdn.com/b/vcblog/archive/2010/03/02/visual-studio-2010-c-project-upgrade-guide.aspx).  
  
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

## <a name="sharing-the-settings"></a>Compartilhando as configurações

Você pode compartilhar propriedades do projeto com outros usuários ou em vários computadores. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).
