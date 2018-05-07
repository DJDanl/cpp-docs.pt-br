---
title: Página de propriedade de diretórios VC + + | Microsoft Docs
ms.custom: ''
ms.date: 04/26/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCDirectories.IncludePath
- VC.Project.VCDirectories.ReferencePath
- VC.Project.VCDirectories.SourcePath
- VC.Project.VCDirectories.LibraryWPath
- VC.Project.VCDirectories.ExecutablePath
- VC.Project.VCDirectories.LibraryPath
- VS.ToolsOptionsPages.Projects.VCDirectories
- VC.Project.VCDirectories.ExcludePath
dev_langs:
- C++
helpviewer_keywords:
- VC++ Directories Property Page
ms.assetid: 428eeef6-f127-4271-b3ea-0ae6f2c3d624
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3acaccff2e2764f4fd7f6f4815f5721f0ba845a3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="vc-directories-property-page-windows"></a>Página de propriedades VC + + diretórios (Windows)

Use esta página de propriedades para informar o Visual Studio os diretórios para usar ao criar o projeto selecionado no momento. Para definir os diretórios para vários projetos em uma solução, use uma folha de propriedades personalizadas, conforme descrito em [criar configurações de propriedade reutilizável](working-with-project-properties.md#bkmkPropertySheets).

Para a versão do Linux dessa página, consulte [diretórios VC + + (C++ Linux)](../linux/prop-pages/directories-linux.md).   

Para acessar o **diretórios VC + +** página de propriedades:

1. Se o **Solution Explorer** janela não estiver visível, em seguida, no menu principal, escolha **exibição** > **Gerenciador de soluções**.
1. Clique com botão direito em um nó de projeto (não a solução de nível superior) e escolha **propriedades**.
1. No painel esquerdo do **páginas de propriedade** caixa de diálogo, selecione **propriedades de configuração** > **diretórios VC + +**.  

Propriedades de diretórios VC + + se aplicam a um projeto, não no nó da solução de nível superior. Se você não vir **diretórios VC + +** em **propriedades de configuração**, selecione um nó de projeto de C++ no **Solution Explorer** janela: 

![Selecione o nó do projeto](media/vcppdir.png "selecionar o nó do projeto para ver as propriedades de diretórios VC + +")

Observe que o **diretórios VC + +** página de propriedades de projetos de plataforma cruzada parece diferente. Para obter informações específicas para projetos C++ do Linux, consulte [diretórios VC + + (C++ Linux)](../linux/prop-pages/directories-linux.md). 
 
Se você não estiver familiarizado com *propriedades do projeto* no Visual Studio, talvez seja útil ler primeiro [trabalhar com propriedades do projeto](working-with-project-properties.md). 
 
As configurações padrão para **diretórios VC + +** propriedades dependem do tipo de projeto. Para projetos de área de trabalho, eles incluem os locais de ferramentas do C++ para um determinado conjunto de ferramentas de plataforma e o local do SDK do Windows. Você pode alterar o **conjunto de ferramentas de plataforma** e **versão do SDK do Windows** no **propriedades de configuração** > **geral** página. 

Para exibir os valores para qualquer um dos diretórios:

1. Selecione uma das propriedades de **diretórios VC + +** página. Por exemplo, escolha **diretórios de biblioteca**.
1. Escolha o botão de seta para baixo no final do campo de valor de propriedade.
1. No menu suspenso, selecione **editar**.

![Editar diretórios de biblioteca](media/vcppdir_libdir_edit.png "caixa de diálogo para editar os caminhos de biblioteca")

Agora, você verá uma caixa de diálogo como esta: 

![Mostrar diretórios de biblioteca](media/vcppdir_libdir.png "caixa de diálogo para adicionar ou remover caminhos de biblioteca")

Use esta caixa de diálogo para exibir os diretórios atuais. No entanto, se você quiser alterar ou adicionar um diretório, é melhor usar **Gerenciador de propriedades** para criar uma folha de propriedades ou modificar a folha de propriedades de usuário padrão. Para obter mais informações, consulte [criar configurações de propriedade reutilizável](working-with-project-properties.md#bkmkPropertySheets).

Como mostrado acima, muitos dos caminhos herdados são fornecidos como macros.  Para examinar o valor atual de uma macro, escolha o **Macros** botão no canto inferior direito da caixa de diálogo. Observe que muitas macros dependem do tipo de configuração. Uma macro em uma compilação de depuração pode ser avaliada como um caminho diferente de macro mesmo em uma compilação de versão. 

Você pode procurar as correspondências parciais ou completa na caixa de edição. A ilustração a seguir mostra todas as macros que contêm a cadeia de caracteres "WindowsSDK" e também mostra o caminho atual que avalia a macro:

![Consulte os valores de macro](media/vcppdir_libdir_macros.png "caixa de diálogo Editar macros")

Observação: A lista é preenchida conforme você digita. Não pressione **Enter**.

Para obter mais informações sobre macros e por que você deve usá-los em vez de caminhos embutidos sempre que possível, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md#bkmkPropertiesVersusMacros). 

Para obter uma lista de macros usadas, consulte [comuns Macros para compilar comandos e propriedades](https://docs.microsoft.com/en-us/cpp/ide/common-macros-for-build-commands-and-properties).

Você pode definir suas próprias macros de duas maneiras:
-   Definir variáveis de ambiente em um prompt de comando do desenvolvedor. Todas as variáveis de ambiente são tratadas como propriedades do MSBuild/macros.
-   Defina macros do usuário em um arquivo de .props. Para obter mais informações, consulte [macros de página de propriedade](working-with-project-properties.md#bkmkPropertiesVersusMacros). 

Para obter mais informações, veja estas postagens do blog: [diretórios VC + +](http://blogs.msdn.com/b/vsproject/archive/2009/07/07/vc-directories.aspx), [propriedades herdadas e folhas de propriedade](http://blogs.msdn.com/b/vsproject/archive/2009/06/23/inherited-properties-and-property-sheets.aspx), e [Visual Studio 2010 C++ projeto guia de atualização](http://blogs.msdn.com/b/vcblog/archive/2010/03/02/visual-studio-2010-c-project-upgrade-guide.aspx).  
  
## <a name="directory-types"></a>Tipos de diretório

Você também pode especificar outros diretórios, como a seguir.  
  
**Diretórios executáveis**<br/>
Diretórios onde procurar por arquivos executáveis. Corresponde do **caminho** variável de ambiente.

**Incluir Diretórios**<br/>
Diretórios nos quais procurar por arquivos de inclusão que são referenciados no código-fonte. Corresponde do **incluir** variável de ambiente.

**Diretórios de referência**<br/>
 Diretórios para a pesquisa de assembly e arquivos de módulo (metadados) que são referenciados no código-fonte, o [#using](../preprocessor/hash-using-directive-cpp.md) diretiva. Corresponde do **LIBPATH** variável de ambiente.

**Diretórios de Biblioteca**<br/>
Diretórios onde procurar por arquivos de bibliotecas (.lib); isso inclui as bibliotecas em tempo de execução. Corresponde do **LIB** variável de ambiente. Essa configuração não se aplica a arquivos. obj; Para vincular a um arquivo. obj, do **propriedades de configuração** > **vinculador** > **geral** página de propriedades, selecione  **Dependências de biblioteca adicionais** e, em seguida, especifique o caminho relativo do arquivo. Para obter mais informações, consulte [páginas de propriedade do vinculador](../ide/linker-property-pages.md).

**Biblioteca WinRT diretórios**<br/>
Diretórios para procurar por arquivos de biblioteca do WinRT para usam em aplicativos do Windows UWP (plataforma Universal). 

**Diretórios de origem**<br/>
Diretórios onde procurar por arquivos de origem para uso para o IntelliSense.

**Excluir diretórios**<br/>
Antes de cada compilação, o Visual Studio consulta o carimbo de hora em todos os arquivos para determinar se qualquer tiver sido modificado desde a compilação anterior. Se o projeto tiver grandes bibliotecas estáveis, você pode potencialmente acelerar a tempos de compilação excluindo esses diretórios desde a verificação de carimbo de hora.

## <a name="sharing-the-settings"></a>Compartilhando as configurações

Você pode compartilhar propriedades do projeto com outros usuários ou em vários computadores. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).
