---
title: Página de propriedade dos diretórios do VC++
ms.date: 07/17/2019
f1_keywords:
- VC.Project.VCDirectories.IncludePath
- VC.Project.VCDirectories.ReferencePath
- VC.Project.VCDirectories.SourcePath
- VC.Project.VCDirectories.LibraryWPath
- VC.Project.VCDirectories.ExecutablePath
- VC.Project.VCDirectories.LibraryPath
- VS.ToolsOptionsPages.Projects.VCDirectories
- VC.Project.VCDirectories.ExcludePath
helpviewer_keywords:
- VC++ Directories Property Page
ms.assetid: 428eeef6-f127-4271-b3ea-0ae6f2c3d624
ms.openlocfilehash: 39362deaa770b39eea964f1e4e58186dd5923b7f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846024"
---
# <a name="vc-directories-property-page-windows"></a>Página de propriedades de Diretórios do VC++ (Windows)

Use esta página de propriedades para informar o Visual Studio de quais diretórios devem ser usados ao compilar o projeto atualmente selecionado. Para definir diretórios para vários projetos em uma solução, use uma folha de propriedades Personalizada, conforme descrito em [compartilhar ou reutilizar configurações de projeto do Visual Studio C++](../create-reusable-property-configurations.md).

Para obter a versão do Linux desta página, confira [Diretórios do VC++ (Linux C++)](../../linux/prop-pages/directories-linux.md).

Para acessar a página de propriedades de **Diretórios do VC++**:

1. Se a janela do **Gerenciador de Soluções** não estiver visível, no menu principal, escolha **Exibir** > **Gerenciador de Soluções**.
1. Clique com o botão direito do mouse em um nó do projeto (não na solução de nível superior) e escolha **Propriedades**.
1. No painel esquerdo da caixa de diálogo **Páginas de Propriedades**, selecione **Propriedades de Configuração** > **Diretórios do VC++**.

As propriedades de Diretórios do VC++ se aplicam a um projeto, não ao nó da solução de nível superior. Se as propriedades de **Diretórios do VC++** não forem exibidas em **Propriedades de Configuração**, selecione um nó do projeto do C++ na janela do **Gerenciador de Soluções**:

![Selecionar o nó do projeto](../media/vcppdir.png "Selecione o nó do projeto para ver as propriedades dos diretórios do VC + +")

Observe que a página de propriedades de **Diretórios do VC++** para projetos multiplataforma tem outra aparência. Para obter informações específicas a projetos do Linux C++, confira [Diretórios do VC++ (Linux C++)](../../linux/prop-pages/directories-linux.md).

Se você não estiver familiarizado com *as propriedades do projeto* no Visual Studio, talvez seja útil primeiro ler o [compilador do C++ e as propriedades de compilação no Visual Studio](../working-with-project-properties.md).

As configurações padrão para as propriedades de **Diretórios do VC++** dependem do tipo de projeto. Para projetos da área de trabalho, elas incluem os locais das ferramentas do C++ de determinado Conjunto de Ferramentas da Plataforma e o local do SDK do Windows. Altere o **Conjunto de Ferramentas da Plataforma** e a **versão do SDK do Windows** na página **Propriedades de Configuração** > **Geral**.

Para exibir os valores para um dos diretórios:

1. Selecione uma das propriedades na página **Diretórios do VC++**. Por exemplo, escolha **Diretórios de Biblioteca**.
1. Escolha o botão de seta para baixo ao final do campo de valor da propriedade.
1. No menu suspenso, escolha **Editar**.

![Editar diretórios de biblioteca](../media/vcppdir_libdir_edit.png "Caixa de diálogo para editar caminhos de biblioteca")

Agora você verá uma caixa de diálogo como esta:

![Mostrar diretórios de biblioteca](../media/vcppdir_libdir.png "Caixa de diálogo para adicionar ou remover caminhos de biblioteca")

Use essa caixa de diálogo para exibir os diretórios atuais. No entanto, caso deseje alterar ou adicionar um diretório, será melhor usar o **Gerenciador de Propriedades** para criar uma folha de propriedades ou modificar a folha de propriedades do usuário padrão. Para obter mais informações, consulte [compartilhar ou reutilizar configurações de projeto do Visual Studio C++](../create-reusable-property-configurations.md).

Conforme mostrado acima, muitos dos caminhos herdados são fornecidos como macros.  Para examinar o valor atual de uma macro, escolha o botão **Macros** no canto inferior direito da caixa de diálogo. Observe que muitas macros dependem do tipo de configuração. Uma macro em um build de depuração pode ser avaliada como um caminho diferente comparado à mesma macro em um build de versão.

Pesquise correspondências parciais ou completas na caixa de edição. A ilustração a seguir mostra todas as macros que contêm a cadeia de caracteres "WindowsSDK" e também mostra o caminho atual para o qual a macro é avaliada:

![Ver valores de macro](../media/vcppdir_libdir_macros.png "Caixa de diálogo para editar macros")

Observação: a lista é populada conforme você digita. Não pressione **Enter**.

Para obter mais informações sobre macros e por que você deve usá-las em vez de caminhos embutidos em código sempre que possível, consulte [definir compilador C++ e propriedades de compilação no Visual Studio](../working-with-project-properties.md).

Para obter uma lista de macros usadas com frequência, consulte [macros comuns para comandos e propriedades de compilação](common-macros-for-build-commands-and-properties.md).

Defina suas próprias macros de duas maneiras:

- Defina variáveis de ambiente em um Prompt de Comando do Desenvolvedor. Todas as variáveis de ambiente são tratadas como propriedades/macros do MSBuild.

- Defina macros do usuário em um arquivo .props. Para obter mais informações, confira [Macros da página de propriedades](../working-with-project-properties.md).

Para obter mais informações, consulte [herança de propriedade em projetos do Visual Studio](../project-property-inheritance.md)e estas Postagens de blog: [diretórios do vc + +](/archive/blogs/vsproject/vc-directories), [Guia de atualização de projetos do Visual Studio 2010 C++](https://devblogs.microsoft.com/cppblog/visual-studio-2010-c-project-upgrade-guide/).

## <a name="directory-types"></a>Tipos de diretório

Você também pode especificar outros diretórios, como a seguir.

**Diretórios Executáveis**<br/>
Diretórios onde procurar por arquivos executáveis. Corresponde à variável de ambiente **PATH**.

**Diretórios de inclusão**<br/>
Diretórios nos quais procurar por arquivos de inclusão que são referenciados no código-fonte. Corresponde à variável de ambiente **INCLUDE**.

**Diretórios de Referência**<br/>
Diretórios nos quais pesquisar arquivos de assembly e de módulo (metadados) referenciados no código-fonte pela diretiva [#using](../../preprocessor/hash-using-directive-cpp.md). Corresponde à variável de ambiente **LIBPATH**.

**Diretórios de Biblioteca**<br/>
Diretórios onde procurar por arquivos de bibliotecas (.lib); isso inclui as bibliotecas em tempo de execução. Corresponde à variável de ambiente **LIB**. Essa configuração não se aplica a arquivos. obj; para vincular a um arquivo. obj, na página de propriedade geral do vinculador Propriedades de **configuração**  >  **Linker**  >  **General** , selecione **dependências de biblioteca adicionais** e, em seguida, especifique o caminho relativo do arquivo. Para obter mais informações, confira [Páginas de propriedades do Vinculador](linker-property-pages.md).

**Diretórios de Biblioteca WinRT**<br/>
Diretórios nos quais pesquisar arquivos de biblioteca WinRT para uso em aplicativos UWP (Plataforma Universal do Windows).

**Diretórios de origem**<br/>
Diretórios onde procurar por arquivos de origem para uso para o IntelliSense.

**Excluir Diretórios**<br/>
Antes de cada compilação, o Visual Studio consulta o carimbo de data/hora em todos os arquivos para determinar se um deles foi modificado desde a compilação anterior. Se o projeto tem bibliotecas grandes estáveis, potencialmente, você pode acelerar os tempos de build excluindo esses diretórios da verificação de carimbo de data/hora.

## <a name="sharing-the-settings"></a>Compartilhando as configurações

Você pode compartilhar propriedades do projeto com outros usuários ou em vários computadores. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).
