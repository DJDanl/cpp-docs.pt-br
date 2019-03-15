---
title: Defina o compilador C++ e compilar propriedades no Visual Studio
description: Use o IDE do Visual Studio para alterar as opções de compilador e vinculador C++ e outras configurações de compilação.
ms.date: 12/10/2018
helpviewer_keywords:
- project properties [C++], modifying
- properties [C++]
- Visual C++ projects, properties
- projects [C++], properties
ms.assetid: 9b0d6f8b-7d4e-4e61-aa75-7d14944816cd
ms.openlocfilehash: 55adb6dc91919bda9c2827a89e5de536667085c1
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824629"
---
# <a name="set-compiler-and-build-properties"></a>Defina o compilador e propriedades de compilação

No IDE, todas as informações necessárias para compilar um projeto são expostas como *propriedades*. Essas informações incluem nome do aplicativo, extensão (como DLL, LIB, EXE), opções do compilador, opções do vinculador, configurações do depurador, etapas de build personalizadas e muitas outras. Normalmente, você usa as *páginas de propriedades* (**Projeto &#124; Propriedades**) para exibir e modificar essas propriedades. Para acessar as páginas de propriedades, escolha **projeto > \<nome do projeto > propriedades** do menu principal, ou o botão direito do mouse no nó do projeto no **Gerenciador de soluções** e escolha **Propriedades**.

## <a name="default-properties"></a>Propriedades padrão

Quando você cria um projeto, o sistema atribui valores para várias propriedades. Os padrões variam um pouco dependendo do tipo de projeto e das opções escolhidas no assistente de aplicativo. Por exemplo, um projeto ATL tem propriedades relacionadas a arquivos MIDL, mas eles estão ausentes em um aplicativo de console básico. As propriedades padrão são mostradas no painel Geral nas Páginas de Propriedades:

![Visual C#&#43;&#43; Padrões de Projeto](media/visual-c---project-defaults.png "Padrões de Projeto do Visual C++")

## <a name="applying-properties-to-build-configurations-and-target-platforms"></a>Aplicação de propriedades para criar configurações e plataformas de destino

Algumas propriedades, como o nome do aplicativo, se aplicam a todas as variações de build, independentemente da plataforma de destino ou se o build é de depuração ou de versão. No entanto, a maioria das propriedades é dependente de configuração. Isso ocorre porque o compilador precisa saber em qual plataforma específica o programa será executado e as opções específicas do compilador a serem usadas para gerar o código correto. Portanto, quando você define uma propriedade, é importante ficar atento à qual configuração e plataforma o novo valor deve se aplicar. Ele deve aplicar-se apenas a builds de Depuração Win32 ou também à Depuração ARM e à Depuração x64? Por exemplo, a propriedade **Otimização**, por padrão, é definida como **Maximizar Velocidade (/O2)** em uma configuração de Versão, mas está desabilitada na configuração de Depuração.

As páginas de propriedades foram projetadas para que você sempre possa ver e, se necessário, modificar a configuração e a plataforma à qual um valor de propriedade deve se aplicar. A ilustração a seguir mostra as páginas de propriedades com as informações de configuração e de plataforma nas caixas de listagem na parte superior. Quando a propriedade **Otimização** for definida aqui, ela será aplicada apenas a builds de Depuração Win32, que é a configuração ativa, conforme mostrado pelas setas vermelhas.

![Páginas de Propriedades do Visual C#&#43;&#43; mostrando a configuração ativa](media/visual-c---property-pages-showing-active-configuration.png "Visual C++ Property Pages showing active configuration")

A ilustração a seguir mostra a mesma página de propriedades do projeto, mas a configuração foi alterada para Versão. Observe o valor diferente para a propriedade Otimização. Observe também que a configuração ativa ainda é Depuração. Defina as propriedades de qualquer configuração aqui; ela não precisa ser a configuração ativa.

![Páginas de Propriedades do Visual C#&#43;&#43; mostrando a configuração de versão](media/visual-c---property-pages-showing-release-config.png "Visual C++ Property Pages showing release config")

## <a name="target-platforms"></a>Plataformas de destino

*Plataforma de destino* refere-se ao tipo de dispositivo e/ou sistema operacional no qual o executável será executado. Você pode compilar um projeto para mais de uma plataforma. As plataformas de destino disponíveis para projetos do C++ dependem do tipo de projeto; elas incluem, entre outros, Win32, x64, ARM, Android e iOS.     A plataforma de destino **x86** que pode ser vista no **Configuration Manager** é idêntica ao **Win32** em projetos do C++ nativo. Win32 significa Windows de 32 bits e **x64** significa Windows de 64 bits. Para obter mais informações sobre essas duas plataformas, confira [Executando aplicativos de 32 bits](/windows/desktop/WinProg64/running-32-bit-applications).

O valor de plataforma de destino **Qualquer CPU** que pode ser visto no **Configuration Manager** não tem nenhum efeito em projetos do C++ nativo; ele é relevante para o C++/CLI e outros tipos de projeto .NET. Para obter mais informações, consulte, [/CLRIMAGETYPE (Especificar Tipo de Imagem CLR)](reference/clrimagetype-specify-type-of-clr-image.md).


Para obter mais informações sobre como definir propriedades para uma compilação de depuração, consulte:

- [Configurações do projeto para uma configuração de depuração de C++](/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration)
- [Preparação e configurações do depurador](/visualstudio/debugger/debugger-settings-and-preparation)
- [Preparação de depuração: Tipos de projeto do Visual C++](/visualstudio/debugger/debugging-preparation-visual-cpp-project-types)
- [Especificar arquivos de símbolo (.pdb) e de origem no depurador do Visual Studio](/visualstudio/debugger/specify-symbol-dot-pdb-and-source-files-in-the-visual-studio-debugger)

## <a name="c-compiler-and-linker-options"></a>Opções do compilador e vinculador C++

Opções do compilador e vinculador C++ estão localizadas sob o **C/C++** e **vinculador** nós no painel esquerdo, sob **propriedades de configuração**. Elas são convertidas diretamente às opções de linha de comando que serão passadas para o compilador. Para ler a documentação sobre uma opção específica, selecione a opção no painel central e pressione **F1**. Ou, você pode procurar a documentação para todas as opções na [opções do compilador MSVC](reference/compiler-options.md) e [opções de vinculador MSVC](reference/linker-options.md). 

O **páginas de propriedade** caixa de diálogo mostra somente as páginas de propriedades que são relevantes para o projeto atual. Por exemplo, se o projeto não tiver um arquivo .idl, a página de propriedades MIDL não será exibida. Para obter mais informações sobre a configuração em cada páginas de propriedade, consulte [páginas de propriedade (C++)](reference/property-pages-visual-cpp.md). 

## <a name="directory-and-path-values"></a>Valores de caminho e diretório

MSBuild oferece suporte ao uso de constantes de tempo de compilação chamado "macros" para determinados valores de cadeia de caracteres incluem diretórios e caminhos. Esses são expostos nas páginas de propriedade, em que você possa consultar e modificá-los usando o [Editor de propriedade](#property_editor). 

A ilustração a seguir mostra as páginas de propriedades para um projeto do Visual C++. No painel esquerdo, a **regra** *Diretórios do VC++* está selecionada e o painel direito lista as propriedades associadas a essa regra. O `$(...)` valores são chamados *macros*. Uma *macro* é uma constante em tempo de compilação que pode se referir a um valor definido pelo Visual Studio ou pelo sistema do MSBuild, ou a um valor definido pelo usuário. Usando macros em vez de valores embutidos, como caminhos de diretório, você pode compartilhar mais facilmente as configurações de propriedade entre máquinas e entre versões do Visual Studio, e você pode garantir melhor que as configurações do projeto participem corretamente no [ herança de propriedade](project-property-inheritance.md). 

![Páginas de propriedades do projeto](media/project_property_pages_vc.png "Project_Property_Pages_VC")

Use o Editor de Propriedades para exibir os valores de todas as macros disponíveis. As macros são abordadas na seção [Macros da página de propriedades](#bkmkPropertiesVersusMacros) mais adiante neste artigo.

### <a name="predefined-macros"></a>Macros predefinidas

*macros globais*<br/>
Aplica-se a todos os itens em uma configuração de projeto. Tem a sintaxe `$(name)`. Um exemplo de uma macro global é `$(VCInstallDir)`, que armazena o diretório raiz da sua instalação do Visual Studio. Uma macro global corresponde a `PropertyGroup` em MSBuild.

*macros de item*<br/>
Tem a sintaxe `%(name)`. Para um arquivo, uma macro de item se aplica somente a esse arquivo — por exemplo, você pode usar `%(AdditionalIncludeDirectories)` para especificar diretórios de inclusão que se aplicam somente a um arquivo específico. Esse tipo de macro de item corresponde a um metadado `ItemGroup` no MSBuild. Quando usada no contexto de uma configuração de projeto, uma macro de item se aplica a todos os arquivos de determinado tipo. Por exemplo, a propriedade da configuração **Definições do Pré-processador** do C/C++ pode usar uma macro de item `%(PreprocessorDefinitions)` que se aplica a todos os arquivos .cpp do projeto. Esse tipo de macro de item corresponde a um metadado `ItemDefinitionGroup` no MSBuild. Para obter mais informações, consulte [Definições de item](/visualstudio/msbuild/item-definitions).

### <a name="user-defined-macros"></a>Macros definidas pelo usuário

Crie *macros definidas pelo usuário* para usar como variáveis em builds do projeto. Por exemplo, você pode criar uma macro definida pelo usuário que forneça um valor a uma etapa personalizada de compilação ou a uma ferramenta personalizada de compilação. Uma macro definida é um par de nome/valor. Em um arquivo de projeto, use a notação **$(**<em>name</em>**)** para acessar o valor.

Uma macro definida pelo usuário é armazenada em uma folha de propriedades. Se seu projeto ainda não contiver uma folha de propriedades, você pode criar um seguindo as etapas descritas em [resuse ou compartilhamento de configurações de projeto do Visual Studio C++](#bkmkPropertySheets).

#### <a name="to-create-a-user-defined-macro"></a>Para criar uma macro definida pelo usuário

1. Na janela **Gerenciador de Propriedades** (na barra de menus, escolha **Exibir**, **Gerenciador de Propriedades**), abra o menu de atalho de uma folha de propriedades (o nome termina com .user) e, em seguida, escolha Propriedades. A caixa de diálogo **Páginas de Propriedades** dessa folha de propriedades será aberta.

1. No painel esquerdo da caixa de diálogo, selecione **Macros de Usuário**. No painel direito, escolha o botão **Adicionar Macro** para abrir a caixa de diálogo **Adicionar Macro de Usuário**.

1. Na caixa de diálogo, especifique um nome e um valor para a macro. Opcionalmente, marque a caixa de seleção **Definir esta macro como uma variável de ambiente no ambiente de build**.

## <a name="property_editor">Editor de propriedades</a>

Você pode usar o Editor de Propriedades para alterar certas propriedades da cadeia de caracteres e selecionar macros como valores. Para acessar o Editor de Propriedades, selecione uma propriedade em uma página de propriedades e, em seguida, selecione o botão de seta para a direita. Se a lista suspensa contiver **\<Editar>**, você poderá escolher essa opção para exibir o Editor de Propriedades dessa propriedade.

![Lista&#95;Suspensa&#95;do&#95;Editor&#95;de&#95;Propriedades](media/property_editor_dropdown.png "Property_Editor_Dropdown")

No Editor de Propriedades, escolha o botão **Macros** para exibir as macros disponíveis e seus valores atuais. A ilustração a seguir mostra o Editor de Propriedades da propriedade **Diretórios de Inclusão Adicionais** depois de o botão **Macros** ser escolhido. Quando a caixa de seleção **Herdar do pai ou padrões de projeto** é marcada e você adiciona um novo valor, ele é acrescentado a todos os valores atualmente herdados. Se você desmarcar a caixa de seleção, o novo valor substituirá os valores herdados. Na maioria dos casos, deixe a caixa de seleção marcada.

![Editor de propriedades, Visual C#&#43;&#43;](media/propertyeditorvc.png "PropertyEditorVC")

## <a name="add-an-include-directory-to-the-set-of-default-directories"></a>Adicionar um diretório de inclusão ao conjunto de diretórios padrão

Quando você adiciona um diretório de inclusão a um projeto, é importante não substituir todos os diretórios padrão. A maneira correta de adicionar um diretório é acrescentar o novo caminho, por exemplo, "C:\MyNewIncludeDir\" e, em seguida, acrescentar a macro **$(IncludePath)** ao valor da propriedade.

## <a name="quickly-browse-and-search-all-properties"></a>E procurar rapidamente todas as propriedades

A página de propriedades **Todas as Opções** (no nó **Propriedades de Configuração &#124; C/C++** da caixa de diálogo **Páginas de Propriedades**) oferece uma maneira rápida de navegar e pesquisar as propriedades disponíveis no contexto atual. Tem uma caixa de pesquisa especial e uma sintaxe simples para ajudar você a filtrar resultados:

Nenhum prefixo:<br/>
Pesquisar nomes de propriedade somente (subcadeia de caracteres sem diferenciação de maiúsculas e minúsculas).

'/' ou '-' :<br/>
Pesquisar somente em opções de compilador (prefixo sem diferenciação de maiúsculas e minúsculas)

v:<br/>
Pesquisar somente em valores (subcadeia de caracteres sem diferenciação de maiúsculas e minúsculas).

## <a name="set-environment-variables-for-a-build"></a>Definir variáveis de ambiente para uma compilação

O compilador MSVC (cl.exe) reconhece determinadas variáveis de ambiente, especificamente LIB, LIBPATH, PATH e INCLUDE. Quando você compila com o IDE, as propriedades definidas na página de propriedades [Página de Propriedades de Diretórios do VC++](reference/vcpp-directories-property-page.md) são usadas para definir essas variáveis de ambiente. Se os valores LIB, LIBPATH e INCLUDE já tiverem sido definidos, por exemplo, por um prompt de comando do desenvolvedor, eles serão substituídos pelos valores das propriedades correspondentes do MSBuild. A compilação, em seguida, anexa o valor da propriedade de diretórios executáveis dos Diretórios VC++ como PATH. Defina uma variável de ambiente definida pelo usuário criando uma macro definida pelo usuário e, em seguida, marcando a caixa que indica **Definir esta macro como uma variável de ambiente no ambiente de build**.

## <a name="set-environment-variables-for-a-debugging-session"></a>Definir variáveis de ambiente para uma sessão de depuração

No painel esquerdo da caixa de diálogo **Páginas de Propriedades** do projeto, expanda **Propriedades de Configuração** e, em seguida, selecione **Depuração**.

No painel direito, modifique as configurações do projeto **Ambiente** ou **Ambiente de Mesclagem** e, em seguida, escolha o botão **OK**.

## <a name="in-this-section"></a>Nesta seção

[Resuse ou compartilhamento de configurações de projeto do Visual Studio](create-reusable-property-configurations.md)<br/>
Como criar um arquivo. Props com as configurações de compilação personalizados que podem ser compartilhadas ou resused.

[Herança de propriedade do projeto](project-property-inheritance.md)<br/>
Descreve a ordem de avaliação para. Props,. targets, arquivos. vcxproj e variáveis de ambiente no processo de compilação.

[Modificar as propriedades e destinos sem alterar o arquivo de projeto](modify-project-properties-without-changing-project-file.md)<br/>
Como criar configurações de build temporários sem ter que modificar um arquivo de projeto. 

## <a name="see-also"></a>Consulte também

[Projetos do Visual Studio – C++](creating-and-managing-visual-cpp-projects.md)<br/>
[Estrutura de arquivos .vcxproj e .props](reference/vcxproj-file-structure.md)<br/>
[Arquivos XML de página de propriedades](reference/property-page-xml-files.md)<br/>
