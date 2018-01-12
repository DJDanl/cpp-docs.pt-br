---
title: Trabalhando com propriedades do projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- project properties [C++], modifying
- properties [C++]
- Visual C++ projects, properties
- projects [C++], properties
ms.assetid: 9b0d6f8b-7d4e-4e61-aa75-7d14944816cd
caps.latest.revision: "45"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: de48e03c62d924334e005ffd7f008e0083fb405f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="working-with-project-properties"></a>Trabalhando com propriedades do projeto
No IDE, todas as informações necessárias para compilar um projeto são expostas como *propriedades*. Essas informações incluem o nome do aplicativo, a extensão (como DLL, LIB, EXE), opções do compilador, opções de vinculador, as configurações do depurador, etapas de compilação personalizada e muitas outras coisas. Normalmente, você usa *páginas de propriedade* ( **projeto &#124; Propriedades**) para exibir e modificar essas propriedades. 
  
 Quando você cria um projeto, o sistema atribuirá valores para várias propriedades. Os padrões variam um pouco dependendo do tipo de projeto e as opções que você escolha no Assistente do aplicativo. Por exemplo, um projeto de ATL tem propriedades relacionadas aos arquivos MIDL, mas eles estão ausentes em um aplicativo de console básico. As propriedades padrão são mostradas no painel Geral nas páginas de propriedades:  
  
 ![Visual C# 43; &#43; Padrões de projeto](../ide/media/visual-c---project-defaults.png "padrões de projeto do Visual C++")  
  
 Algumas propriedades, como o nome do aplicativo se aplicam a todas as variações de compilação, independentemente da plataforma de destino ou se é uma compilação debug ou release. Mas a maioria das propriedades dependem da configuração. Isso ocorre porque o compilador deve saber qual plataforma específica, o programa será executado em e as opções que compilador específico a ser usado para gerar o código correto. Portanto, quando você define uma propriedade, é importante ficar atento à qual configuração e plataforma para o novo valor deve ser aplicada a. Deve aplicar apenas para compilações de depuração Win32 ou ele também deve aplicar a depurar ARM e depuração x64? Por exemplo, o **otimização** propriedade, por padrão, é definida como **maximizar velocidade (/ O2)** em uma configuração de versão, mas está desabilitado na configuração de depuração.  
  
 As páginas de propriedade são projetadas para que você sempre pode ver e, se necessário modificar, qual plataforma e configuração de um valor da propriedade deverá aplicar. A ilustração a seguir mostra as páginas de propriedades com as informações de configuração e plataforma nas caixas de listagem na parte superior. Quando o **otimização** propriedade é definida aqui, ele será aplicado apenas compilações de depuração Win32, que é a configuração ativa, conforme mostrado pelas setas vermelhas.  
  
 ![Visual C# 43; &#43; Páginas de propriedade mostrando a configuração ativa](../ide/media/visual-c---property-pages-showing-active-configuration.png "configuração ativa de mostrando páginas de propriedade do Visual C++")  
  
 A ilustração a seguir mostra a mesma página de propriedade do projeto, mas a configuração foi alterada para versão. Observe o valor diferente para a propriedade de otimização. Observe também que a configuração ativa ainda é depuração. Você pode definir propriedades para qualquer configuração aqui. ele não precisa estar ativo.  
  
 ![Visual C# 43; &#43; Configuração de liberação de páginas de propriedade mostrando](../ide/media/visual-c---property-pages-showing-release-config.png "configuração de versão mostrando páginas de propriedade do Visual C++")  
  
 O sistema do projeto é baseado no MSBuild, que define os formatos de arquivo e as regras para a criação de projetos de qualquer tipo. MSBuild gerencia muito da complexidade de construção para várias plataformas e configurações, mas você precisa entender um pouco sobre como ele funciona. Isso é especialmente importante se você quiser definir configurações personalizadas ou criar reutilizáveis conjuntos de propriedades que você pode compartilhar e importar para vários projetos.  
  
 Propriedades do projeto são armazenadas diretamente no arquivo de projeto (*. vcxproj) ou em outros arquivos. XML ou .props que a importação do arquivo de projeto e que fornecer valores padrão. Como mostrado anteriormente, a mesma propriedade para a mesma configuração pode ser atribuída um valor diferente em diferentes arquivos. Quando você cria um projeto, o mecanismo MSBuild avalia o arquivo de projeto e todos os arquivos importados em uma ordem bem definido (descritas abaixo). Como cada arquivo é avaliado, quaisquer valores de propriedade definidos no arquivo substituirá os valores existentes. Quaisquer valores que não são especificados são herdadas dos arquivos que foram avaliados anteriormente. Portanto, quando você define uma propriedade com páginas de propriedades, também é importante ficar atento à qual você definir. Se você definir uma propriedade como "X" em um arquivo de .props, mas a propriedade é definida como "Y" no arquivo de projeto, o projeto será criado com a propriedade definida como "Y". Se a mesma propriedade está definida como "Z" em um item de projeto, como um arquivo. cpp, o mecanismo MSBuild usará o valor de "Z". Para obter mais informações, consulte [herança de propriedade](#bkmkPropertyInheritance) posteriormente neste artigo.  
  
## <a name="build-configurations"></a>Configurações de compilação  
 Uma configuração é apenas um grupo arbitrário de propriedades que recebem um nome. O Visual Studio fornece configurações Debug e Release e cada uma define várias propriedades apropriadamente para uma compilação de depuração ou compilação de versão. Você pode usar o **do Configuration Manager** para definir configurações personalizadas como uma maneira conveniente de propriedades de grupo para um tipo específico de compilação. O Gerenciador de propriedade é usado para o trabalho avançado com propriedades, mas podemos conectá-lo aqui porque ele ajuda a visualizar as configurações de propriedade. Você acessá-lo do **exibição &#124;  Gerenciador de propriedades** ou **exibição &#124; Outras janelas &#124; Gerenciador de propriedades** dependendo de suas configurações. Ele tem nós para cada par de configuração/plataforma no projeto. Em cada um de nós são nós de folhas de propriedades (.props arquivos) que definir algumas propriedades específicas para essa configuração.  
  
 ![Gerenciador de propriedades](../ide/media/property-manager.png "Gerenciador de propriedades")  
  
 Se você vai para o painel Geral nas páginas de propriedades (consulte a ilustração acima) e defina a propriedade de conjunto de caracteres como "Não configurado" em vez de "Use Unicode" e clique em **Okey**, Gerenciador de propriedades mostrará nenhum **suporteaUnicode** da folha de propriedades para a configuração atual, mas ainda estarão presentes para outras configurações.  
  
 Para obter mais informações sobre o Gerenciador de propriedades e folhas de propriedades, consulte [criar configurações de propriedade reutilizável](#bkmkPropertySheets) posteriormente neste artigo.  
  
> [!TIP]
>  O arquivo. User é um recurso herdado e é recomendável que você o exclua para manter corretamente agrupadas de acordo com a plataforma/configuração de propriedades.  
  
## <a name="target-platforms"></a>Plataformas de destino  
 *Plataforma de destino* refere-se para o tipo de dispositivo e/ou sistema operacional que o executável será executado em. Você pode criar um projeto para mais de uma plataforma. As plataformas de destino disponíveis para projetos C++ dependem do tipo de projeto. Eles incluem, mas não está limitados a Win32, x64, ARM, Android e iOS.     O **x86** plataforma de destino que você pode ver em **do Configuration Manager** é idêntico ao **Win32** em projetos do C++ nativo. Win32 significa Windows de 32 bits e **x64** significa Windows de 64 bits. Para obter mais informações sobre essas duas plataformas, consulte [aplicativos em execução de 32 bits](https://msdn.microsoft.com/library/windows/desktop/aa384249\(v=vs.85\).aspx).  
  
 O **qualquer CPU** que você pode ver no valor da plataforma de destino **do Configuration Manager** não tem nenhum efeito em projetos do C++ nativo; ele é relevante para o C + + tipos de projeto de CLI e outros .NET. Para obter mais informações, consulte, [/CLRIMAGETYPE (Especificar Tipo de Imagem CLR)](../build/reference/clrimagetype-specify-type-of-clr-image.md).  
  
## <a name="property-pages"></a>Páginas de propriedade  
 Conforme mencionado anteriormente, o sistema de projeto do Visual C++ se baseia [MSBuild](/visualstudio/msbuild/msbuild-properties) e os valores são armazenados no arquivo de projeto XML, arquivos de .props e. targets padrão. Para Visual Studio 2015, esses arquivos estão localizados em **\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140**. Para o Visual Studio de 2017, esses arquivos estão localizados em  **\\arquivos de programa (x86)\\Microsoft Visual Studio\\2017\\_edição_\\Common7\\ IDE\\VC\\VCTargets**, onde _edição_ é a edição do Visual Studio instalada. Propriedades também são armazenadas em todos os arquivos .props personalizado que você pode adicionar ao seu próprio projeto. É altamente recomendável que você não editar esses arquivos manualmente e em vez disso, use as páginas de propriedades no IDE para modificar todas as propriedades, especialmente aqueles que participam de herança, a menos que você tenha uma noção do MSBuild.  
  
 A ilustração a seguir mostra as páginas de propriedades para um projeto do Visual C++. No painel esquerdo, o **diretórios VC + +***regra* estiver selecionada, e o painel direito lista as propriedades que estão associadas essa regra. O `$(...)` Infelizmente são chamados de valores *macros*. Esses são *não* macros do C/C++, mas constantes simplesmente tempo de compilação. As macros são discutidas a [macros de página de propriedade](#bkmkPropertiesVersusMacros) seção mais adiante neste artigo.)  
  
 ![Páginas de propriedades do projeto](../ide/media/project_property_pages_vc.png "Project_Property_Pages_VC")  
  
> [!WARNING]
>  O **propriedades comuns** configurações em versões anteriores do Visual Studio foram removidas. Para adicionar uma referência a um projeto, agora você usar o **adicionar referência** caixa de diálogo da mesma maneira que para linguagens gerenciadas. Consulte [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).  
  
#### <a name="to-set-a-property-for-a-project"></a>Para definir uma propriedade de um projeto  
  
1.  Na maioria dos cenários, você pode definir propriedades no nível do projeto sem criar uma folha de propriedades personalizadas. No menu principal, escolha **projeto &#124; Propriedades**, ou com o botão direito no nó do projeto no **Solution Explorer** e escolha **propriedades**.  
  
2.  Use o **configuração** e **plataforma** caixas na parte superior da caixa de diálogo para especificar quais grupos de propriedade devem aplicar as alterações. Em muitos casos **todas as plataformas** e **todas as configurações de** são a escolha certa. Para definir propriedades para apenas algumas configurações, a seleção múltipla em **Gerenciador de propriedades**e, em seguida, abra o menu de atalho e escolha **propriedades**.  
  
 O **páginas de propriedade** caixa de diálogo mostra somente as páginas de propriedades que se aplicam ao projeto atual. Por exemplo, se o projeto não tiver um arquivo .idl, a página de propriedades MIDL não será exibida.  
  
 Quando você realça uma propriedade em uma página de propriedades, você pode pressionar **F1** para ir para o tópico de referência para obter mais informações sobre a opção de compilador ou vinculador correspondente.  
  
 Você pode encontrar mais informações sobre cada página de propriedade nestes tópicos:  
  
-   [Página de propriedades gerais (projeto)](../ide/general-property-page-project.md)  
  
-   [Página de propriedades gerais (arquivo)](../ide/general-property-page-file.md)  
  
-   [Página de propriedades de linha de comando](../ide/command-line-property-pages.md)  
  
-   [Configurações do projeto para uma configuração de depuração de C++](/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration)  
  
-   [Página de propriedades de NMake](../ide/nmake-property-page.md)  
  
-   [Páginas de propriedades do vinculador](../ide/linker-property-pages.md)  
  
-   [Páginas de propriedades de recursos](../ide/resources-property-pages.md)  
  
-   [Páginas de propriedades de MIDL](../ide/midl-property-pages.md)  
  
-   [Página de propriedades de referências Web](../ide/web-references-property-page.md)  
  
-   [Página de propriedades da Ferramenta de Gerador de Dados XML](../ide/xml-data-generator-tool-property-page.md)  
  
## <a name="to-quickly-browse-and-search-all-properties"></a>Para navegar rapidamente e todas as propriedades de pesquisa  
 O **todas as opções de** página de propriedades (sob o **propriedades de configuração &#124; C/C++** nó o **páginas de propriedade** caixa de diálogo) fornece uma maneira rápida para procurar e pesquisar as propriedades que estão disponíveis no contexto atual. Tem uma caixa de pesquisa especial e uma sintaxe simples para ajudar você a filtrar resultados:  
  
 Nenhum prefixo:  
 Pesquisar nomes de propriedade somente (subcadeia de caracteres sem diferenciação de maiúsculas e minúsculas).  
  
 '/' ou '-' :  
 Pesquisar somente em opções de compilador (prefixo sem diferenciação de maiúsculas e minúsculas)  
  
 v:  
 Pesquisar somente em valores (subcadeia de caracteres sem diferenciação de maiúsculas e minúsculas).  
  
##  <a name="bkmkPropertiesVersusMacros"></a>Macros de página de propriedade  
 Um *macro* é uma constante de tempo de compilação que pode fazer referência a um valor que é definido pelo Visual Studio ou o sistema de MSBuild, ou para um valor definido pelo usuário. Ao usar macros em vez de valores embutidos, como caminhos de diretório, você pode compartilhar configurações de propriedade mais facilmente entre computadores e entre versões do Visual Studio, além de poder garantir melhor que as configurações do projeto participem corretamente da herança de propriedade. Você pode usar o Editor de propriedade para exibir os valores de todas as macros disponíveis.  
  
### <a name="predefined-macros"></a>Macros predefinidas  
 macros globais  
 Aplica-se a todos os itens em uma configuração de projeto. Tem a sintaxe `$(name)`. Um exemplo de uma macro global é `$(VCInstallDir)`, que armazena o diretório raiz da sua instalação do Visual Studio. Uma macro global corresponde a `PropertyGroup` em MSBuild.  
  
 macros de item  
 Tem a sintaxe `%(name)`. Para um arquivo, uma macro de item se aplica somente a esse arquivo — por exemplo, você pode usar `%(AdditionalIncludeDirectories)` para especificar diretórios de inclusão que se aplicam somente a um arquivo específico. Esse tipo de macro de item corresponde a um metadado `ItemGroup` no MSBuild. Quando usada no contexto de uma configuração de projeto, uma macro de item se aplica a todos os arquivos de determinado tipo. Por exemplo, C/C++ **definições de pré-processador** propriedade de configuração pode levar um `%(PreprocessorDefinitions)` macro de item que se aplica a todos os arquivos. cpp no projeto. Esse tipo de macro de item corresponde a um metadado `ItemDefinitionGroup` no MSBuild. Para obter mais informações, consulte [Definições de item](/visualstudio/msbuild/item-definitions).  
  
### <a name="user-defined-macros"></a>Macros definidas pelo usuário  
 Você pode criar *macros definidas pelo usuário* para usar como variáveis em compilações de projeto. Por exemplo, você pode criar uma macro definida pelo usuário que forneça um valor a uma etapa personalizada de compilação ou a uma ferramenta personalizada de compilação. Uma macro definida é um par de nome/valor. Em um arquivo de projeto, use o **$(***nome***)** notação para acessar o valor.  
  
 Uma macro definida pelo usuário é armazenada em uma folha de propriedades. Se o projeto já contém uma folha de propriedades, você pode criar um seguindo as etapas descritas em [criar configurações de propriedade reutilizável](#bkmkPropertySheets).  
  
##### <a name="to-create-a-user-defined-macro"></a>Para criar uma macro definida pelo usuário  
  
1.  No **Gerenciador de propriedades** janela (na barra de menus, escolha **exibição**, **Gerenciador de propriedade**), abra o menu de atalho para uma folha de propriedades (seu nome termina em. User) e, em seguida, escolha Propriedades. O **páginas de propriedade** abre a caixa de diálogo para esta folha de propriedades.  
  
2.  No painel esquerdo da caixa de diálogo, selecione **Macros do usuário**. No painel direito, escolha o **Adicionar Macro** para abrir o **Adicionar Macro do usuário** caixa de diálogo.  
  
3.  Na caixa de diálogo, especifique um nome e um valor para a macro. Opcionalmente, selecione o **Defina esta macro como uma variável de ambiente no ambiente de compilação** caixa de seleção.  
  
## <a name="property-editor"></a>Edição de Propriedades  
 Você pode usar o Editor de Propriedades para alterar certas propriedades da cadeia de caracteres e selecionar macros como valores. Para acessar o Editor de Propriedades, selecione uma propriedade em uma página de propriedades e, em seguida, selecione o botão de seta para a direita. Se a lista suspensa contém  **\<Editar >**, em seguida, você pode escolhê-lo para exibir o Editor de propriedade para a propriedade.  
  
 ![Propriedade &#95; Editor de &#95; suspenso](../ide/media/property_editor_dropdown.png "Property_Editor_Dropdown")  
  
 No Editor de propriedades, você pode escolher o **Macros** botão para exibir as macros disponíveis e seus valores atuais. A ilustração a seguir mostra o Editor de propriedade para o **diretórios de inclusão adicionais** propriedade após o **Macros** botão foi escolhido. Quando o **herdar do pai ou padrões de projeto** caixa de seleção está marcada e você adicionar um novo valor, ele é adicionado para todos os valores que estão atualmente sendo herdados. Se você desmarcar a caixa de seleção, o novo valor substituirá os valores herdados. Na maioria dos casos, deixe a caixa de seleção marcada.  
  
 ![Editor de propriedades, Visual C# 43; &#43; ] (../ide/media/propertyeditorvc.png "PropertyEditorVC")  
  
##  <a name="bkmkPropertySheets"></a>Criar configurações de propriedade reutilizável  
 Embora você possa definir propriedades “globais” por usuário e por computador, não recomendamos fazer isso. Em vez disso, recomendamos que você use **Gerenciador de propriedades** para criar um *da folha de propriedades* para armazenar as configurações para cada tipo de projeto que você deseja reutilizar ou compartilhar com outras pessoas. Folhas de propriedade também tornam menos provável que as configurações de propriedade para outros tipos de projeto sejam alteradas inadvertidamente. Folhas de propriedades são discutidas mais detalhadamente [criar configurações de propriedade reutilizável](#bkmkPropertySheets).  
  
> [!IMPORTANT]
>  **arquivos. User e porque eles são um problema**  
>   
>  Versões anteriores do Visual Studio usaram folhas de propriedade global que tinham uma extensão de nome de arquivo. User e foram localizadas no \<userprofile > \AppData\Local\Microsoft\MSBuild\v4.0\ pasta. Não recomendamos mais esses arquivos, pois definem propriedades para configurações do projeto com base no computador e no usuário. Essas configurações “globais” podem interferir com as compilações, especialmente quando você está definindo mais de uma plataforma no computador de compilação. Por exemplo, se você tiver um projeto do MFC e um projeto do Windows Phone, as propriedades .user serão inválidas para um deles. Folhas de propriedade reutilizáveis são mais flexíveis e mais robustas.  
>   
>  Embora os arquivos .user ainda sejam instalados pelo Visual Studio e participem da herança de propriedade, eles são vazios por padrão. A prática recomendada é excluir a referência a eles no **Gerenciador de propriedades** para garantir que seus projetos operam independentemente de qualquer usuário, as configurações por computador Isso é importante para garantir o comportamento correto em um SCC (código-fonte ambiente de controle).  
  
 Para exibir **Gerenciador de propriedades**, na barra de menus, escolha **exibição**, **outras janelas**, **Gerenciador de propriedades**.  
  
 Se você tiver um conjunto de propriedades que você deseja aplicar a vários projetos comuns, usado com frequência, você pode usar **Gerenciador de propriedades** para capturá-los em um reutilizável *da folha de propriedades* arquivo, que, por convenção, tem uma extensão de nome de arquivo .props. Você pode aplicar a folha (ou folhas) a novos projetos para que não precisar definir suas propriedades a partir do zero. Para acessar **Gerenciador de propriedades**, na barra de menus, escolha **exibição**, **Gerenciador de propriedades**.  
  
 ![Menu de atalho do Gerenciador de propriedades](../ide/media/sharingnew.png "SharingNew")  
  
 Em cada nó de configuração, você verá nós para cada folha de propriedades que se aplica a essa configuração. O sistema adiciona folhas de propriedades que definem valores com base em opções escolhidas no Assistente de aplicativo quando você cria o projeto. Clique em qualquer nó e escolha Propriedades para ver as propriedades que se aplicam a esse nó. Todas as folhas de propriedade são importadas automaticamente na folha de propriedade "mestre" do projeto (ms.cpp.props) e são avaliadas na ordem em que aparecem no Gerenciador de propriedades. Você pode movê-los para alterar a ordem de avaliação. Folhas de propriedades que são avaliadas posteriormente substituirão os valores em planilhas avaliada anteriormente.  
  
 Se você escolher **adicionar nova folha de propriedades de projeto** e, em seguida, selecione, por exemplo, a folha de propriedades de MyProps.props, uma caixa de diálogo de página de propriedade é exibida. Observe que isso se aplica à folha de propriedades MyProps; as alterações feitas são gravadas na folha, não no arquivo de projeto (.vcxproj).  
  
 As propriedades em uma folha de propriedades são substituídas se a mesma propriedade for definida diretamente no arquivo .vcxproj.  
  
 Você pode importar uma folha de propriedades quantas vezes for necessário. Vários projetos em uma solução podem herdar configurações da mesma folha de propriedades, e um projeto pode ter várias folhas. Uma folha de propriedades em si pode herdar configurações de outra folha de propriedades.  
  
 Você também pode criar uma folha de propriedades para várias configurações. Para fazer isso, crie uma folha de propriedades para cada configuração, abra o menu de atalho de um deles, escolha **Adicionar folha de propriedades existente**e, em seguida, adicione outras planilhas. No entanto, se você usar uma folha de propriedades comum, quando definir uma propriedade, ela será definida para todas as configurações às quais a folha se aplica. Além disso, o IDE não mostra quais projetos ou outras folhas de propriedade estão herdando de determinada folha de propriedades.  
  
 Em grandes soluções que terão vários projetos, pode ser útil criar uma folha de propriedades no nível da solução. Quando você adicionar um projeto à solução, use **Gerenciador de propriedades** para adicionar esta folha de propriedades para o projeto. Se for necessário no nível do projeto, você pode adicionar uma nova folha de propriedades para definir valores específicos do projeto.  
  
> [!IMPORTANT]
>  Um arquivo .props por padrão não participa no controle de código-fonte porque não é criado como um item de projeto. Você pode adicionar manualmente o arquivo como um item de solução se quiser incluí-lo no controle de código-fonte.  
  
#### <a name="to-create-a-property-sheet"></a>Para criar uma folha de propriedades  
  
1.  Na barra de menus, escolha **exibição**, **Gerenciador de propriedades**. O **Gerenciador de propriedades** é aberto.  
  
2.  Para definir o escopo da folha de propriedades, selecione o item ao qual se aplica. Isso pode ser uma configuração específica ou outra folha de propriedades. Abra o menu de atalho para este item e, em seguida, escolha **adicionar nova folha de propriedades de projeto**. Especifique um nome e um local.  
  
3.  Em **Gerenciador de propriedades**, abra a folha de propriedades de novo e, em seguida, defina as propriedades que você deseja incluir.  
  
##  <a name="bkmkPropertyInheritance"></a>Herança de propriedade  
 As propriedades do projeto estão em camadas. Cada camada herda os valores da camada anterior, mas um valor herdado pode ser substituído pela definição explícita da propriedade. Veja a árvore básica de herança:  
  
1.  Configurações padrão do Conjunto de Ferramentas MSBuild CPP (..\Arquivos de Programas\MSBuild\Microsoft.Cpp\v4.0\Microsoft.Cpp.Default.props, que é importado pelo arquivo .vcxproj)  
  
2.  Folhas de propriedade  
  
3.  Arquivo .vcxproj. (Pode substituir as configurações padrão e as da folha de propriedades.)  
  
4.  Metadados de itens  
  
> [!TIP]
>  Em uma página de propriedade, uma propriedade em `bold` é definido no contexto atual. Uma propriedade na fonte normal é herdada.  
  
 Um arquivo de projeto (.vcxproj) importa outras folhas de propriedade no momento da compilação. Depois que todas as folhas de propriedade são importadas, o arquivo do projeto será avaliado e a última definição de qualquer valor de propriedade será usada. Às vezes é útil ver o arquivo expandido para determinar como um valor de propriedade fornecido é herdado. Para ver a versão expandida, digite o comando a seguir em um prompt de comando do Visual Studio. (Altere os nomes dos arquivos de espaço reservado com o nome que você deseja usar.)  
  
 **MSBuild /pp:** *temp* **. txt** *myapp* **. vcxproj**  
  
 Os arquivos de projeto expandidos podem ser grandes e difíceis de entender, a menos que você esteja familiarizado com o MSBuild. Veja a estrutura básica de um arquivo de projeto:  
  
1.  Propriedades fundamentais do projeto, que não são expostas no IDE.  
  
2.  Importação de Microsoft.cpp.default.props, que define algumas propriedades básicas e independentes do conjunto de ferramentas.  
  
3.  Propriedades de configuração global (expostos como **PlatformToolset** e **projeto** propriedades padrão no **geral de configuração** página. Essas propriedades determinam quais folhas de propriedade intrínseca e conjuntos de ferramentas são importados no Microsoft.cpp.props na próxima etapa.  
  
4.  Importação de Microsoft.cpp.props, que define a maioria dos padrões do projeto.  
  
5.  Importação de todas as folhas de propriedade, incluindo arquivos .user. Essas folhas de propriedades podem substituir tudo, exceto o **PlatformToolset** e **projeto** propriedades padrão.  
  
6.  O restante das propriedades de configuração do projeto. Esses valores podem substituir o que foi definido nas folhas de propriedade.  
  
7.  Itens (arquivos) com seus metadados. Essas são sempre as últimas palavras em regras de avaliação do MSBuild, mesmo que ocorram antes de outras propriedades e importações.  
  
 Para mais informações, consulte [Propriedades do MSBuild](/visualstudio/msbuild/msbuild-properties).  
  
## <a name="adding-an-include-directory-to-the-set-of-default-directories"></a>Adicionando um diretório de inclusão ao conjunto de diretórios padrão  
 Quando você adiciona um diretório de inclusão a um projeto, é importante não substituir todos os diretórios padrão. É a maneira correta de adicionar um diretório anexar o novo caminho, por exemplo "C:\MyNewIncludeDir\"e, em seguida, para acrescentar o **$(IncludePath)** macro para o valor da propriedade.  
  
## <a name="setting-environment-variables-for-a-build"></a>Definindo variáveis de ambiente para uma compilação  
 O compilador do Visual C++ (cl.exe) reconhece determinadas variáveis de ambiente, especificamente LIB, LIBPATH, PATH e INCLUDE. Quando você cria no IDE, as propriedades que são definidas no [página de propriedade de diretórios VC + +](../ide/vcpp-directories-property-page.md) página de propriedades são usadas para definir as variáveis de ambiente. Se os valores LIB, LIBPATH e INCLUDE já tiverem sido definidos, por exemplo, por um prompt de comando do desenvolvedor, eles serão substituídos pelos valores das propriedades correspondentes do MSBuild. A compilação, em seguida, anexa o valor da propriedade de diretórios executáveis dos Diretórios VC++ como PATH. Você pode definir uma variável de ambiente definidas pelo usuário, criou uma macro definida pelo usuário e, em seguida, marcando a caixa que diz **Defina esta macro como uma variável de ambiente no ambiente de compilação**.  
  
## <a name="setting-environment-variables-for-a-debugging-session"></a>Definindo variáveis de ambiente para uma sessão de depuração  
 No painel esquerdo do projeto do **páginas de propriedade** caixa de diálogo caixa, expanda **propriedades de configuração** e, em seguida, selecione **depuração**. 
  
 No painel direito, modifique o **ambiente** ou **mesclar ambiente** configurações do projeto e, em seguida, escolha o **Okey** botão.  

## <a name="modifying-properties-and-targets-without-changing-the-project-file"></a>Modificando propriedades e os destinos sem alterar o arquivo de projeto
Você pode substituir as propriedades do projeto e destinos do prompt de comando MSBuild sem alterar o arquivo de projeto. Isso é útil quando você deseja aplicar algumas propriedades temporariamente ou ocasionalmente. Ele pressupõe um conhecimento do MSBuild. Para obter mais informações, consulte [MSBUild](https://docs.microsoft.com/en-us/visualstudio/msbuild/msbuild).

> [!IMPORTANT]
> Você pode usar o Editor de XML no Visual Studio ou qualquer editor de texto, para criar o arquivo .props ou. targets. Não use o **Gerenciador de propriedades** neste cenário porque ele adiciona as propriedades para o arquivo de projeto.

*Para substituir as propriedades de projeto:*
- Crie um arquivo de .props que especifica as propriedades que você deseja substituir. 
- No prompt de comando: definir ForceImportBeforeCppTargets="C:\sources\my_props.props"
 
*Para substituir os destinos do projeto:*
1) Criar um arquivo. targets com sua implementação ou um destino específico
2) No prompt de comando: definir ForceImportAfterCppTargets = "C:\sources\my_target.targets"
 
Você também pode definir qualquer uma das opções na linha de comando msbuild usando a opção /p::

```cmd
> msbuild myproject.sln /p:ForceImportBeforeCppTargets="C:\sources\my_props.props" 
> msbuild myproject.sln /p:ForceImportAfterCppTargets="C:\sources\my_target.targets" 
```  

Substituir as propriedades e os destinos dessa maneira é equivalente a adicionar a seguir importa todos os arquivos. vcxproj na solução:

```cmd 
<Import Project=="C:\sources\my_props.props" />
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
<Import Project==" C:\sources\my_target.targets"" />
```  

## <a name="see-also"></a>Consulte também  
 [Criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md) [estrutura do arquivo. vcxproj e .props](vcxproj-file-structure.md) [arquivos XML de página de propriedade](property-page-xml-files.md)