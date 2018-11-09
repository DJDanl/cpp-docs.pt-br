---
title: Trabalhando com propriedades do projeto
ms.date: 08/27/2018
helpviewer_keywords:
- project properties [C++], modifying
- properties [C++]
- Visual C++ projects, properties
- projects [C++], properties
ms.assetid: 9b0d6f8b-7d4e-4e61-aa75-7d14944816cd
ms.openlocfilehash: 5edf7a9a162c0980a6d872658204bcdf66fbdb7e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516279"
---
# <a name="working-with-project-properties"></a>Trabalhando com propriedades do projeto

No IDE, todas as informações necessárias para compilar um projeto são expostas como *propriedades*. Essas informações incluem nome do aplicativo, extensão (como DLL, LIB, EXE), opções do compilador, opções do vinculador, configurações do depurador, etapas de build personalizadas e muitas outras. Normalmente, você usa as *páginas de propriedades* (**Projeto &#124; Propriedades**) para exibir e modificar essas propriedades.

Quando você cria um projeto, o sistema atribui valores para várias propriedades. Os padrões variam um pouco dependendo do tipo de projeto e das opções escolhidas no assistente de aplicativo. Por exemplo, um projeto ATL tem propriedades relacionadas a arquivos MIDL, mas eles estão ausentes em um aplicativo de console básico. As propriedades padrão são mostradas no painel Geral nas Páginas de Propriedades:

![Visual C#&#43;&#43; Padrões de Projeto](../ide/media/visual-c---project-defaults.png "Padrões de Projeto do Visual C++")

Algumas propriedades, como o nome do aplicativo, se aplicam a todas as variações de build, independentemente da plataforma de destino ou se o build é de depuração ou de versão. No entanto, a maioria das propriedades é dependente de configuração. Isso ocorre porque o compilador precisa saber em qual plataforma específica o programa será executado e as opções específicas do compilador a serem usadas para gerar o código correto. Portanto, quando você define uma propriedade, é importante ficar atento à qual configuração e plataforma o novo valor deve se aplicar. Ele deve aplicar-se apenas a builds de Depuração Win32 ou também à Depuração ARM e à Depuração x64? Por exemplo, a propriedade **Otimização**, por padrão, é definida como **Maximizar Velocidade (/O2)** em uma configuração de Versão, mas está desabilitada na configuração de Depuração.

As páginas de propriedades foram projetadas para que você sempre possa ver e, se necessário, modificar a configuração e a plataforma à qual um valor de propriedade deve se aplicar. A ilustração a seguir mostra as páginas de propriedades com as informações de configuração e de plataforma nas caixas de listagem na parte superior. Quando a propriedade **Otimização** for definida aqui, ela será aplicada apenas a builds de Depuração Win32, que é a configuração ativa, conforme mostrado pelas setas vermelhas.

![Páginas de Propriedades do Visual C#&#43;&#43; mostrando a configuração ativa](../ide/media/visual-c---property-pages-showing-active-configuration.png "Visual C++ Property Pages showing active configuration")

A ilustração a seguir mostra a mesma página de propriedades do projeto, mas a configuração foi alterada para Versão. Observe o valor diferente para a propriedade Otimização. Observe também que a configuração ativa ainda é Depuração. Defina as propriedades de qualquer configuração aqui; ela não precisa ser a configuração ativa.

![Páginas de Propriedades do Visual C#&#43;&#43; mostrando a configuração de versão](../ide/media/visual-c---property-pages-showing-release-config.png "Visual C++ Property Pages showing release config")

O próprio sistema de projeto é baseado no MSBuild, que define os formatos de arquivo e as regras para a compilação de projetos de qualquer tipo. O MSBuild gerencia grande parte da complexidade da compilação para várias configurações e plataformas, mas você precisa entender um pouco sobre como ele funciona. Isso é especialmente importante se você deseja definir configurações personalizadas ou criar conjuntos reutilizáveis de propriedades que você pode compartilhar e importar para vários projetos.

As propriedades do projeto são armazenadas diretamente no arquivo de projeto (*.vcxproj) ou em outros arquivos .xml ou .props que são importados pelo arquivo de projeto e que fornecem valores padrão. Conforme mostrado anteriormente, a mesma propriedade para a mesma configuração pode receber um valor diferente em arquivos diferentes. Quando você compila um projeto, o mecanismo MSBuild avalia o arquivo de projeto e todos os arquivos importados em uma ordem bem definida (descrita abaixo). Conforme cada arquivo for avaliado, os valores de propriedade definidos nesse arquivo substituirão os valores existentes. Os valores não especificados são herdados dos arquivos que foram avaliados anteriormente. Portanto, quando você define uma propriedade com páginas de propriedades, também é importante ficar atento ao local em que você a define. Se você definir uma propriedade como "X" em um arquivo .props, mas a propriedade for definida como "Y" no arquivo de projeto, o projeto será compilado com a propriedade definida como "Y". Se a mesma propriedade for definida como "Z" em um item de projeto, como um arquivo .cpp, o mecanismo MSBuild usará o valor "Z". Para obter mais informações, confira [Herança de propriedade](#bkmkPropertyInheritance) mais adiante neste artigo.

## <a name="build-configurations"></a>Configurações de build

Uma configuração é apenas um grupo arbitrário de propriedades que recebem um nome. O Visual Studio fornece configurações de Depuração e Versão e cada uma define várias propriedades de maneira apropriada para um build de depuração ou de versão. Use o **Configuration Manager** para definir configurações personalizadas como uma maneira conveniente de agrupar propriedades para um tipo específico de build. O Gerenciador de Propriedades é usado para o trabalho avançado com propriedades, mas nós o apresentamos aqui porque ele ajuda a visualizar as configurações de propriedade. Acesse-o em **Exibir &#124; Gerenciador de Propriedades** ou **Exibir &#124; Outras Janelas &#124; Gerenciador de Propriedades**, dependendo das configurações. Ele contém nós para cada par de configuração/plataforma no projeto. Em cada um desses nós estão os nós das folhas de propriedades (arquivos .props) que definem algumas propriedades específicas para essa configuração.

![Gerenciador de Propriedades](../ide/media/property-manager.png "Property Manager")

Se você acessar o painel Geral nas Páginas de Propriedades (veja a ilustração acima) e definir a propriedade Conjunto de Caracteres como "Não Definido", em vez de "Usar Unicode" e clicar em **OK**, o Gerenciador de Propriedades não mostrará nenhuma folha de propriedades de **Suporte a Unicode** para a configuração atual, mas ela ainda estará presente para outras configurações.

Para obter mais informações sobre o Gerenciador de Propriedades e as folhas de propriedades, confira [Criando configurações de propriedade reutilizáveis](#bkmkPropertySheets) mais adiante neste artigo.

> [!TIP]
> O arquivo .user é um recurso herdado, e recomendamos que você o exclua para manter as propriedades agrupadas corretamente de acordo com a configuração/plataforma.

## <a name="target-platforms"></a>Plataformas de destino

*Plataforma de destino* refere-se ao tipo de dispositivo e/ou sistema operacional no qual o executável será executado. Você pode compilar um projeto para mais de uma plataforma. As plataformas de destino disponíveis para projetos do C++ dependem do tipo de projeto; elas incluem, entre outros, Win32, x64, ARM, Android e iOS.     A plataforma de destino **x86** que pode ser vista no **Configuration Manager** é idêntica ao **Win32** em projetos do C++ nativo. Win32 significa Windows de 32 bits e **x64** significa Windows de 64 bits. Para obter mais informações sobre essas duas plataformas, confira [Executando aplicativos de 32 bits](/windows/desktop/WinProg64/running-32-bit-applications).

O valor de plataforma de destino **Qualquer CPU** que pode ser visto no **Configuration Manager** não tem nenhum efeito em projetos do C++ nativo; ele é relevante para o C++/CLI e outros tipos de projeto .NET. Para obter mais informações, consulte, [/CLRIMAGETYPE (Especificar Tipo de Imagem CLR)](../build/reference/clrimagetype-specify-type-of-clr-image.md).

## <a name="property-pages"></a>Páginas de propriedades

Conforme mencionado anteriormente, o sistema de projeto do Visual C++ se baseia no [MSBuild](/visualstudio/msbuild/msbuild-properties) e os valores são armazenados no arquivo de projeto XML e nos arquivos .props e .targets padrão. No Visual Studio 2015, esses arquivos estão localizados em **\Arquivos de Programas (x86)\MSBuild\Microsoft.Cpp\v4.0\V140**. No Visual Studio 2017, esses arquivos estão localizados em **\\Arquivos de Programas (x86)\\Microsoft Visual Studio\\2017\\_edition_\\Common7\\IDE\\VC\\VCTargets**, em que _edition_ é a edição instalada do Visual Studio. As propriedades também são armazenadas em arquivos .props personalizados que você pode adicionar ao seu próprio projeto. É altamente recomendável que você NÃO edite esses arquivos manualmente e, em vez disso, use as páginas de propriedades no IDE para modificar todas as propriedades, especialmente aquelas que participam da herança, a menos que você tenha noções avançadas do MSBuild.

A ilustração a seguir mostra as páginas de propriedades para um projeto do Visual C++. No painel esquerdo, a **regra** *Diretórios do VC++* está selecionada e o painel direito lista as propriedades associadas a essa regra. Infelizmente, os valores `$(...)` são chamados de *macros*. Eles *não* são macros do C/C++, mas apenas constantes em tempo de compilação. As macros são abordadas na seção [Macros da página de propriedades](#bkmkPropertiesVersusMacros) mais adiante neste artigo.

![Páginas de propriedades do projeto](../ide/media/project_property_pages_vc.png "Project_Property_Pages_VC")

> [!WARNING]
> As configurações **Propriedades Comuns** em versões anteriores do Visual Studio foram removidas. Para adicionar uma referência a um projeto, agora você usa a caixa de diálogo **Adicionar Referência** da mesma maneira usada para as linguagens gerenciadas. Confira [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).

#### <a name="to-set-a-property-for-a-project"></a>Para definir uma propriedade de um projeto

1. Na maioria dos cenários, você define as propriedades no nível do projeto sem criar uma folha de propriedades personalizada. No menu principal, escolha **Projeto &#124; Propriedades** ou clique com o botão direito do mouse no nó do projeto no **Gerenciador de Soluções** e escolha **Propriedades**.

2. Use as caixas de listagem **Configuração** e **Plataforma** na parte superior da caixa de diálogo para especificar quais grupos de propriedades devem aplicar as alterações. Em muitos casos, **Todas as Plataformas** e **Todas as Configurações** são a escolha certa. Para definir propriedades para apenas algumas configurações, faça uma seleção múltipla delas no **Gerenciador de Propriedades** e, em seguida, abra o menu de atalho e escolha **Propriedades**.

A caixa de diálogo **Páginas de Propriedades** mostra somente as páginas de propriedades que se aplicam ao projeto atual. Por exemplo, se o projeto não tiver um arquivo .idl, a página de propriedades MIDL não será exibida.

Ao realçar uma propriedade em uma Página de Propriedades, pressione **F1** para ir para o tópico de referência para obter mais informações sobre a opção do compilador ou do vinculador correspondente.

Encontre mais informações sobre cada Página de Propriedades nestes tópicos:

- [Página de propriedades gerais (projeto)](../ide/general-property-page-project.md)

- [Página de propriedades gerais (arquivo)](../ide/general-property-page-file.md)

- [Página de propriedades de linha de comando](../ide/command-line-property-pages.md)

- [Configurações do projeto para uma configuração de depuração de C++](/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration)

- [Página de propriedades de NMake](../ide/nmake-property-page.md)

- [Páginas de propriedades do vinculador](../ide/linker-property-pages.md)

- [Páginas de propriedades de recursos](../ide/resources-property-pages.md)

- [Páginas de propriedades de MIDL](../ide/midl-property-pages.md)

- [Página de propriedades de referências Web](../ide/web-references-property-page.md)

- [Página de propriedades da Ferramenta de Gerador de Dados XML](../ide/xml-data-generator-tool-property-page.md)

## <a name="to-quickly-browse-and-search-all-properties"></a>Para procurar e pesquisar rapidamente todas as propriedades

A página de propriedades **Todas as Opções** (no nó **Propriedades de Configuração &#124; C/C++** da caixa de diálogo **Páginas de Propriedades**) oferece uma maneira rápida de navegar e pesquisar as propriedades disponíveis no contexto atual. Tem uma caixa de pesquisa especial e uma sintaxe simples para ajudar você a filtrar resultados:

Nenhum prefixo:<br/>
Pesquisar nomes de propriedade somente (subcadeia de caracteres sem diferenciação de maiúsculas e minúsculas).

'/' ou '-' :<br/>
Pesquisar somente em opções de compilador (prefixo sem diferenciação de maiúsculas e minúsculas)

v:<br/>
Pesquisar somente em valores (subcadeia de caracteres sem diferenciação de maiúsculas e minúsculas).

##  <a name="bkmkPropertiesVersusMacros"></a> Macros da página de propriedades

Uma *macro* é uma constante em tempo de compilação que pode se referir a um valor definido pelo Visual Studio ou pelo sistema do MSBuild, ou a um valor definido pelo usuário. Ao usar macros em vez de valores embutidos, como caminhos de diretório, você pode compartilhar configurações de propriedade mais facilmente entre computadores e entre versões do Visual Studio, além de poder garantir melhor que as configurações do projeto participem corretamente da herança de propriedade. Use o Editor de Propriedades para exibir os valores de todas as macros disponíveis.

### <a name="predefined-macros"></a>Macros predefinidas

*macros globais*<br/>
Aplica-se a todos os itens em uma configuração de projeto. Tem a sintaxe `$(name)`. Um exemplo de uma macro global é `$(VCInstallDir)`, que armazena o diretório raiz da sua instalação do Visual Studio. Uma macro global corresponde a `PropertyGroup` em MSBuild.

*macros de item*<br/>
Tem a sintaxe `%(name)`. Para um arquivo, uma macro de item se aplica somente a esse arquivo — por exemplo, você pode usar `%(AdditionalIncludeDirectories)` para especificar diretórios de inclusão que se aplicam somente a um arquivo específico. Esse tipo de macro de item corresponde a um metadado `ItemGroup` no MSBuild. Quando usada no contexto de uma configuração de projeto, uma macro de item se aplica a todos os arquivos de determinado tipo. Por exemplo, a propriedade da configuração **Definições do Pré-processador** do C/C++ pode usar uma macro de item `%(PreprocessorDefinitions)` que se aplica a todos os arquivos .cpp do projeto. Esse tipo de macro de item corresponde a um metadado `ItemDefinitionGroup` no MSBuild. Para obter mais informações, consulte [Definições de item](/visualstudio/msbuild/item-definitions).

### <a name="user-defined-macros"></a>Macros definidas pelo usuário

Crie *macros definidas pelo usuário* para usar como variáveis em builds do projeto. Por exemplo, você pode criar uma macro definida pelo usuário que forneça um valor a uma etapa personalizada de compilação ou a uma ferramenta personalizada de compilação. Uma macro definida é um par de nome/valor. Em um arquivo de projeto, use a notação **$(**<em>name</em>**)** para acessar o valor.

Uma macro definida pelo usuário é armazenada em uma folha de propriedades. Se o projeto ainda não contém uma folha de propriedades, crie uma seguindo as etapas descritas em [Criando configurações de propriedade reutilizáveis](#bkmkPropertySheets).

##### <a name="to-create-a-user-defined-macro"></a>Para criar uma macro definida pelo usuário

1. Na janela **Gerenciador de Propriedades** (na barra de menus, escolha **Exibir**, **Gerenciador de Propriedades**), abra o menu de atalho de uma folha de propriedades (o nome termina com .user) e, em seguida, escolha Propriedades. A caixa de diálogo **Páginas de Propriedades** dessa folha de propriedades será aberta.

1. No painel esquerdo da caixa de diálogo, selecione **Macros de Usuário**. No painel direito, escolha o botão **Adicionar Macro** para abrir a caixa de diálogo **Adicionar Macro de Usuário**.

1. Na caixa de diálogo, especifique um nome e um valor para a macro. Opcionalmente, marque a caixa de seleção **Definir esta macro como uma variável de ambiente no ambiente de build**.

## <a name="property-editor"></a>Edição de Propriedades

Você pode usar o Editor de Propriedades para alterar certas propriedades da cadeia de caracteres e selecionar macros como valores. Para acessar o Editor de Propriedades, selecione uma propriedade em uma página de propriedades e, em seguida, selecione o botão de seta para a direita. Se a lista suspensa contiver **\<Editar>**, você poderá escolher essa opção para exibir o Editor de Propriedades dessa propriedade.

![Lista&#95;Suspensa&#95;do&#95;Editor&#95;de&#95;Propriedades](../ide/media/property_editor_dropdown.png "Property_Editor_Dropdown")

No Editor de Propriedades, escolha o botão **Macros** para exibir as macros disponíveis e seus valores atuais. A ilustração a seguir mostra o Editor de Propriedades da propriedade **Diretórios de Inclusão Adicionais** depois de o botão **Macros** ser escolhido. Quando a caixa de seleção **Herdar do pai ou padrões de projeto** é marcada e você adiciona um novo valor, ele é acrescentado a todos os valores atualmente herdados. Se você desmarcar a caixa de seleção, o novo valor substituirá os valores herdados. Na maioria dos casos, deixe a caixa de seleção marcada.

![Editor de propriedades, Visual C#&#43;&#43;](../ide/media/propertyeditorvc.png "PropertyEditorVC")

##  <a name="bkmkPropertySheets"></a> Criando configurações de propriedade reutilizáveis

Embora você possa definir propriedades “globais” por usuário e por computador, não recomendamos fazer isso. Em vez disso, recomendamos que você use o **Gerenciador de Propriedades** para criar uma *folha de propriedades* para armazenar configurações para cada tipo de projeto que você deseja poder reutilizar ou compartilhar com outras pessoas. Folhas de propriedade também tornam menos provável que as configurações de propriedade para outros tipos de projeto sejam alteradas inadvertidamente. As folhas de propriedades são abordadas em mais detalhes em [Criando configurações de propriedade reutilizáveis](#bkmkPropertySheets).

> [!IMPORTANT]
> **Arquivos .user e por que eles são problemáticos**
>
> As versões anteriores do Visual Studio usavam folhas de propriedades globais que tinham uma extensão de nome de arquivo .user e estavam localizadas na pasta \<perfil do usuário>\AppData\Local\Microsoft\MSBuild\v4.0\. Não recomendamos mais esses arquivos, pois definem propriedades para configurações do projeto com base no computador e no usuário. Essas configurações “globais” podem interferir com as compilações, especialmente quando você está definindo mais de uma plataforma no computador de compilação. Por exemplo, se você tiver um projeto do MFC e um projeto do Windows Phone, as propriedades .user serão inválidas para um deles. Folhas de propriedade reutilizáveis são mais flexíveis e mais robustas.
>
> Embora os arquivos .user ainda sejam instalados pelo Visual Studio e participem da herança de propriedade, eles são vazios por padrão. A melhor prática é excluir a referência a eles no **Gerenciador de Propriedades** para garantir que os projetos operem independentemente de qualquer configuração por usuário e por computador. É importante garantir o comportamento correto em um ambiente de SCC (controle do código-fonte).

Para exibir o **Gerenciador de Propriedades**, na barra de menus, escolha **Exibir**, **Outras Janelas**, **Gerenciador de Propriedades**.

Se você tiver um conjunto de propriedades comuns usadas com frequência que deseje aplicar a vários projetos, use o **Gerenciador de Propriedades** para capturá-las em um arquivo de *folha de propriedades* reutilizável que, por convenção, tem uma extensão de nome de arquivo .props. Você pode aplicar a folha (ou folhas) a novos projetos para que não precisar definir suas propriedades a partir do zero. Para acessar o **Gerenciador de Propriedades**, na barra de menus, escolha **Exibir**, **Gerenciador de Propriedades**.

![Menu de atalho do Gerenciador de Propriedades](../ide/media/sharingnew.png "SharingNew")

Em cada nó de configuração, você verá os nós de cada folha de propriedades que se aplica a essa configuração. O sistema adiciona folhas de propriedades que definem valores com base nas opções escolhidas no assistente de aplicativo no momento da criação do projeto. Clique com o botão direito do mouse em qualquer nó e escolha Propriedades para ver as propriedades que se aplicam a esse nó. Todas as folhas de propriedades são importadas automaticamente para a folha de propriedades "mestre" do projeto (ms.cpp.props) e são avaliadas na ordem em que são exibidas no Gerenciador de Propriedades. Mova-as para alterar a ordem de avaliação. As folhas de propriedades que são avaliadas posteriormente substituirão os valores nas planilhas avaliadas anteriormente.

Se você escolher **Adicionar Nova Folha de Propriedades do Projeto** e, em seguida, selecionar, por exemplo, a folha de propriedades MyProps.props, uma caixa de diálogo da página de propriedades será aberta. Observe que isso se aplica à folha de propriedades MyProps; as alterações feitas são gravadas na folha, não no arquivo de projeto (.vcxproj).

As propriedades em uma folha de propriedades são substituídas se a mesma propriedade for definida diretamente no arquivo .vcxproj.

Você pode importar uma folha de propriedades quantas vezes for necessário. Vários projetos em uma solução podem herdar configurações da mesma folha de propriedades, e um projeto pode ter várias folhas. Uma folha de propriedades em si pode herdar configurações de outra folha de propriedades.

Você também pode criar uma folha de propriedades para várias configurações. Para fazer isso, crie uma folha de propriedades para cada configuração, abra o menu de atalho de uma delas, escolha **Adicionar Folha de Propriedades Existente** e, em seguida, adicione as outras folhas. No entanto, se você usar uma folha de propriedades comum, quando definir uma propriedade, ela será definida para todas as configurações às quais a folha se aplica. Além disso, o IDE não mostra quais projetos ou outras folhas de propriedade estão herdando de determinada folha de propriedades.

Em grandes soluções que terão vários projetos, pode ser útil criar uma folha de propriedades no nível da solução. Quando você adicionar um projeto à solução, use o **Gerenciador de Propriedades** para adicionar a folha de propriedades ao projeto. Se for necessário no nível do projeto, você pode adicionar uma nova folha de propriedades para definir valores específicos do projeto.

> [!IMPORTANT]
> Um arquivo .props por padrão não participa no controle de código-fonte porque não é criado como um item de projeto. Você pode adicionar manualmente o arquivo como um item de solução se quiser incluí-lo no controle de código-fonte.

#### <a name="to-create-a-property-sheet"></a>Para criar uma folha de propriedades

1. Na barra de menus, escolha **Exibir**, **Gerenciador de Propriedades**. O **Gerenciador de Propriedades** será aberto.

2. Para definir o escopo da folha de propriedades, selecione o item ao qual se aplica. Isso pode ser uma configuração específica ou outra folha de propriedades. Abra o menu de atalho desse item e, em seguida, escolha **Adicionar Nova Folha de Propriedades do Projeto**. Especifique um nome e um local.

3. No **Gerenciador de Propriedades**, abra a nova folha de propriedades e, em seguida, defina as propriedades que deseja incluir.

##  <a name="bkmkPropertyInheritance"></a> Herança de propriedade

As propriedades do projeto estão em camadas. Cada camada herda os valores da camada anterior, mas um valor herdado pode ser substituído pela definição explícita da propriedade. Veja a árvore básica de herança:

1. Configurações padrão do Conjunto de Ferramentas MSBuild CPP (..\Arquivos de Programas\MSBuild\Microsoft.Cpp\v4.0\Microsoft.Cpp.Default.props, que é importado pelo arquivo .vcxproj)

2. Folhas de propriedade

3. Arquivo .vcxproj. (Pode substituir as configurações padrão e as da folha de propriedades.)

4. Metadados de itens

> [!TIP]
> Em uma página de propriedades, uma propriedade em `bold` é definida no contexto atual. Uma propriedade na fonte normal é herdada.

Um arquivo de projeto (.vcxproj) importa outras folhas de propriedade no momento da compilação. Depois que todas as folhas de propriedade são importadas, o arquivo do projeto será avaliado e a última definição de qualquer valor de propriedade será usada. Às vezes é útil ver o arquivo expandido para determinar como um valor de propriedade fornecido é herdado. Para ver a versão expandida, digite o comando a seguir em um prompt de comando do Visual Studio. (Altere os nomes dos arquivos de espaço reservado com o nome que você deseja usar.)

**msbuild /pp:** *temp* **.txt** *myapp* **.vcxproj**

Os arquivos de projeto expandidos podem ser grandes e difíceis de entender, a menos que você esteja familiarizado com o MSBuild. Veja a estrutura básica de um arquivo de projeto:

1. Propriedades fundamentais do projeto, que não são expostas no IDE.

2. Importação de Microsoft.cpp.default.props, que define algumas propriedades básicas e independentes do conjunto de ferramentas.

3. Propriedades de Configuração Global (expostas como propriedades padrão de **PlatformToolset** e **Project** na página **Configuração Geral**). Essas propriedades determinam quais folhas de propriedade intrínseca e conjuntos de ferramentas são importados no Microsoft.cpp.props na próxima etapa.

4. Importação de Microsoft.cpp.props, que define a maioria dos padrões do projeto.

5. Importação de todas as folhas de propriedade, incluindo arquivos .user. Essas folhas de propriedade podem substituir tudo, exceto as propriedades padrão **PlatformToolset** e **Project**.

6. O restante das propriedades de configuração do projeto. Esses valores podem substituir o que foi definido nas folhas de propriedade.

7. Itens (arquivos) com seus metadados. Essas são sempre as últimas palavras em regras de avaliação do MSBuild, mesmo que ocorram antes de outras propriedades e importações.

Para mais informações, consulte [Propriedades do MSBuild](/visualstudio/msbuild/msbuild-properties).

## <a name="adding-an-include-directory-to-the-set-of-default-directories"></a>Adicionando um diretório de inclusão ao conjunto de diretórios padrão

Quando você adiciona um diretório de inclusão a um projeto, é importante não substituir todos os diretórios padrão. A maneira correta de adicionar um diretório é acrescentar o novo caminho, por exemplo, "C:\MyNewIncludeDir\" e, em seguida, acrescentar a macro **$(IncludePath)** ao valor da propriedade.

## <a name="setting-environment-variables-for-a-build"></a>Definindo variáveis de ambiente para uma compilação

O compilador do Visual C++ (cl.exe) reconhece determinadas variáveis de ambiente, especificamente LIB, LIBPATH, PATH e INCLUDE. Quando você compila com o IDE, as propriedades definidas na página de propriedades [Página de Propriedades de Diretórios do VC++](../ide/vcpp-directories-property-page.md) são usadas para definir essas variáveis de ambiente. Se os valores LIB, LIBPATH e INCLUDE já tiverem sido definidos, por exemplo, por um prompt de comando do desenvolvedor, eles serão substituídos pelos valores das propriedades correspondentes do MSBuild. A compilação, em seguida, anexa o valor da propriedade de diretórios executáveis dos Diretórios VC++ como PATH. Defina uma variável de ambiente definida pelo usuário criando uma macro definida pelo usuário e, em seguida, marcando a caixa que indica **Definir esta macro como uma variável de ambiente no ambiente de build**.

## <a name="setting-environment-variables-for-a-debugging-session"></a>Definindo variáveis de ambiente para uma sessão de depuração

No painel esquerdo da caixa de diálogo **Páginas de Propriedades** do projeto, expanda **Propriedades de Configuração** e, em seguida, selecione **Depuração**.

No painel direito, modifique as configurações do projeto **Ambiente** ou **Ambiente de Mesclagem** e, em seguida, escolha o botão **OK**.

## <a name="modifying-properties-and-targets-without-changing-the-project-file"></a>Modificando propriedades e destinos sem alterar o arquivo de projeto

Substitua as propriedades e os destinos do projeto no prompt de comando do MSBuild sem alterar o arquivo de projeto. Isso é útil quando você deseja aplicar algumas propriedades temporária ou ocasionalmente. Isso pressupõe noções básicas do MSBuild. Para obter mais informações, confira [MSBUild](https://docs.microsoft.com/visualstudio/msbuild/msbuild).

> [!IMPORTANT]
> Use o Editor de XML no Visual Studio ou qualquer editor de texto para criar o arquivo .props ou .targets. Não use o **Gerenciador de Propriedades** neste cenário porque ele adiciona as propriedades ao arquivo de projeto.

*Para substituir as propriedades do projeto:*

1. Crie um arquivo .props que especifica as propriedades que você deseja substituir.

1. No prompt de comando: defina ForceImportBeforeCppTargets="C:\sources\my_props.props"

*Para substituir os destinos do projeto:*

1. Criar um arquivo .targets com sua implementação ou um destino específico

2. No prompt de comando: defina ForceImportAfterCppTargets ="C:\sources\my_target.targets"

Defina também qualquer uma das opções na linha de comando do MSBuild usando a opção /p:

```cmd
> msbuild myproject.sln /p:ForceImportBeforeCppTargets="C:\sources\my_props.props"
> msbuild myproject.sln /p:ForceImportAfterCppTargets="C:\sources\my_target.targets"
```

A substituição de propriedades e destinos dessa maneira é equivalente à adição das seguintes importações a todos os arquivos .vcxproj da solução:

```cmd
<Import Project=="C:\sources\my_props.props" />
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
<Import Project==" C:\sources\my_target.targets"" />
```

## <a name="see-also"></a>Consulte também

[Criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md)<br/>
[Estrutura de arquivos .vcxproj e .props](vcxproj-file-structure.md)<br/>
[Arquivos XML de página de propriedades](property-page-xml-files.md)<br/>
