---
title: Estrutura de arquivos .vcxproj e .props
ms.date: 09/18/2018
helpviewer_keywords:
- .vcxproj file structure
ms.assetid: 14d0c552-29db-480e-80c1-7ea89d6d8e9c
ms.openlocfilehash: 3b7c7bdad8848a3755db4ea565117459c72e939b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62317114"
---
# <a name="vcxproj-and-props-file-structure"></a>Estrutura de arquivos .vcxproj e .props

O [MSBuild](../msbuild-visual-cpp.md) é o sistema de projeto padrão no Visual Studio; quando você escolhe **Arquivo** > **Novo Projeto** no Visual C++ você está criando um projeto do MSBuild cujas configurações são armazenadas em um arquivo de projeto XML que tem a extensão `.vcxproj`. O arquivo de projeto também pode importar arquivos .props e .targets nos quais as configurações podem ser armazenadas. Na maioria dos casos, você nunca precisa editar o arquivo de projeto manualmente e, na verdade, não deve editá-lo manualmente, a menos que tenha noções avançadas do MSBuild. Sempre que possível, você deve usar as páginas de propriedades do Visual Studio para modificar as configurações de projeto (consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md). No entanto, em alguns casos, talvez seja necessário modificar uma folha de propriedades ou um arquivo de projeto manualmente. Para esses cenários, este artigo contém informações básicas sobre a estrutura do arquivo.

**Importante:**

Caso você opte por editar um arquivo .vcxproj manualmente, lembre-se destes fatos:

1. A estrutura do arquivo precisa seguir um formato prescrito, que é descrito neste artigo.

1. Atualmente, o sistema de projeto do Visual C++ não dá suporte a curingas em itens de projeto. Por exemplo, não há suporte para o seguinte:

   ```xml
   <ClCompile Include="*.cpp"/>
   ```

1. Atualmente, o sistema de projeto do Visual C++ não dá suporte a macros em caminhos de itens de projeto. Por exemplo, não há suporte para o seguinte:

   ```xml
   <ClCompile Include="$(IntDir)\generated.cpp"/>
   ```

   "Sem suporte" significa que não há garantia de que as macros funcionarão em todas as operações no IDE. Macros que não alteram seu valor em configurações diferentes devem funcionar, mas talvez não sejam preservadas caso um item seja movido para um projeto ou um filtro diferente. Macros que alteram seu valor em diferentes configurações causarão problemas, porque o IDE não espera que os caminhos de item de projeto sejam diferentes para diferentes configurações de projeto.

1. Para adicionar, remover ou modificar propriedades do projeto corretamente quando elas forem editadas na caixa de diálogo **Propriedades do Projeto**, o arquivo precisa conter grupos separados para cada configuração de projeto e as condições precisam estar neste formato:

   ```xml
   Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"
   ```

1. Cada propriedade precisa ser especificada no grupo com o rótulo correto, conforme especificado no arquivo de regra de propriedade. Para obter mais informações, confira [Arquivos de regras XML da página de propriedades](property-page-xml-files.md).

## <a name="vcxproj-file-elements"></a>Elementos do arquivo .vcxproj

Inspecione o conteúdo de um arquivo .vcxproj usando qualquer editor de texto ou de XML. Exiba-o no Visual Studio clicando com o botão direito do mouse no projeto no Gerenciador de Soluções, escolhendo **Descarregar projeto** e, em seguida, **Editar Foo.vcxproj**.

A primeira coisa a ser observada é que os elementos de nível superior são exibidos em uma ordem específica. Por exemplo:

- A maioria dos grupos de propriedades e dos grupos de definição de item ocorre após a importação para Microsoft.Cpp.Default.props.

- Todos os destinos são importados no final do arquivo.

- Há vários grupos de propriedades, cada um com um rótulo exclusivo, e que ocorrem em uma ordem específica.

A ordem dos elementos no arquivo de projeto é muito importante, pois o MSBuild se baseia em um modelo de avaliação sequencial.  Se o arquivo de projeto, incluindo todos os arquivos .targets e .props importados, consiste em várias definições de uma propriedade, a última definição substitui as anteriores. No exemplo a seguir, o valor "xyz" será definido durante a compilação, porque o mecanismo MSBuild o encontra por último durante sua avaliação.

```xml
  <MyProperty>abc</MyProperty>
  <MyProperty>xyz</MyProperty>
```

O snippet a seguir mostra um arquivo .vcxproj mínimo. Qualquer arquivo .vcxproj gerado pelo Visual Studio conterá esses elementos de nível superior do MSBuild e eles serão exibidos nesta ordem (embora possam conter várias cópias de cada elemento de nível superior). Observe que os atributos `Label` são marcas arbitrárias somente usadas pelo Visual Studio como indicações para edição; eles não têm nenhuma outra função.

```xml
<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns='http://schemas.microsoft.com/developer/msbuild/2003'>
  <ItemGroup Label="ProjectConfigurations" />
  <PropertyGroup Label="Globals" />
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
  <PropertyGroup Label="Configuration" />
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ImportGroup Label="ExtensionSettings" />
  <ImportGroup Label="PropertySheets" />
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup />
  <ItemDefinitionGroup />
  <ItemGroup />
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets" />
</Project>
```

As seguintes seções descrevem a finalidade de cada um desses elementos e o motivo pelo qual eles são ordenados dessa forma:

### <a name="project-element"></a>Elemento de projeto

```xml
<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns='http://schemas.microsoft.com/developer/msbuild/2003' >
```

`Project` é o nó raiz. Especifica a versão do MSBuild a ser usada e também o destino padrão a ser executado quando esse arquivo é passado para MSBuild.exe.

### <a name="projectconfigurations-itemgroup-element"></a>Elemento ProjectConfigurations ItemGroup

```xml
<ItemGroup Label="ProjectConfigurations" />
```

`ProjectConfigurations` contém a descrição da configuração de projeto. Alguns exemplos são Debug|Win32, Release|Win32, Debug|ARM e assim por diante. Muitas configurações de projeto são específicas a determinada configuração. Por exemplo, provavelmente, você desejará definir as propriedades de otimização para um build de versão, mas não para um build de depuração.

O grupo de itens `ProjectConfigurations` não é usado no momento do build. O IDE do Visual Studio precisa dele para carregar o projeto. Esse grupo de itens pode ser movido para um arquivo .props e importado para o arquivo .vcxproj. No entanto, nesse caso, se você precisar adicionar ou remover as configurações, precisará editar o arquivo .props manualmente; não poderá usar o IDE.

### <a name="projectconfiguration-elements"></a>Elementos de ProjectConfiguration

O snippet a seguir mostra uma configuração de projeto. Neste exemplo, 'Debug|x64' é o nome da configuração. O nome da configuração de projeto precisa estar no formato $(Configuration)|$(Platform). Um nó de configuração de projeto pode ter duas propriedades: Configuração e plataforma. Essas propriedades serão definidas automaticamente com os valores especificados aqui quando a configuração estiver ativa.

```xml
<ProjectConfiguration Include="Debug|x64">
  <Configuration>Debug</Configuration>
  <Platform>x64</Platform>
</ProjectConfiguration>
```

O IDE espera encontrar uma configuração de projeto para qualquer combinação de valores de Configuração e Plataforma usados em todos os itens de ProjectConfiguration. Geralmente, isso significa que um projeto pode ter configurações de projeto sem sentido para atender a esse requisito. Por exemplo, se um projeto tiver essas configurações:

- Debug|Win32

- Retail|Win32

- Special 32-bit Optimization|Win32

ele também precisará ter essas configurações, mesmo que "Otimização Especial de 32 bits" não tenha sentido para x64:

- Debug|x64

- Retail|x64

- Special 32-bit Optimization|x64

Desabilite o build e implante comandos para qualquer configuração no **Gerenciador de Configurações da Solução**.

### <a name="globals-propertygroup-element"></a>Elemento Globals PropertyGroup

```xml
<PropertyGroup Label="Globals" />
```

`Globals` contém configurações no nível do projeto como ProjectGuid, RootNamespace e ApplicationType/ApplicationTypeRevision. As duas últimas geralmente definem o sistema operacional de destino. Um projeto só pode ser direcionado a um sistema operacional devido ao fato de que as referências e os itens de projeto não podem ter condições no momento. Normalmente, essas propriedades não são substituídas em nenhum outro lugar do arquivo de projeto. Esse grupo não é dependente de configuração e, portanto, normalmente, há apenas um grupo Globals no arquivo de projeto.

### <a name="microsoftcppdefaultprops-import-element"></a>Elemento Microsoft.Cpp.default.props Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
```

A folha de propriedades **Microsoft.Cpp.default.props** é fornecida com o Visual Studio e não pode ser modificada. Ela contém as configurações padrão para o projeto. Os padrões podem variar dependendo do ApplicationType.

### <a name="configuration-propertygroup-elements"></a>Elementos Configuration PropertyGroup

```xml
<PropertyGroup Label="Configuration" />
```

Um grupo de propriedades `Configuration` tem uma condição de configuração anexada (como `Condition=”'$(Configuration)|$(Platform)'=='Debug|Win32'”`) e é fornecido em várias cópias, uma por configuração. Esse grupo de propriedades hospeda as propriedades que são definidas para uma configuração específica. As propriedades de configuração incluem PlatformToolset e também controlam a inclusão de folhas de propriedades do sistema em **Microsoft.Cpp.props**. Por exemplo, se você definir a propriedade `<CharacterSet>Unicode</CharacterSet>`, a folha de propriedades do sistema **microsoft.Cpp.unicodesupport.Props** será incluída. Se você inspecionar **Microsoft.Cpp.props**, verá a linha `<Import Condition=”'$(CharacterSet)' == 'Unicode'”   Project=”$(VCTargetsPath)\microsoft.Cpp.unicodesupport.props”/>`.

### <a name="microsoftcppprops-import-element"></a>Elemento Microsoft.Cpp.props Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
```

A folha de propriedades **Microsoft.Cpp.props** (diretamente ou por meio de importações) define os valores padrão para muitas propriedades específicas à ferramenta, como as propriedades no Nível de Aviso e de Otimização do compilador, a propriedade TypeLibraryName da ferramenta MIDL e assim por diante. Ela também importa várias folhas de propriedades do sistema com base em quais propriedades de configuração são definidas no grupo de propriedades imediatamente acima.

### <a name="extensionsettings-importgroup-element"></a>Elemento ExtensionSettings ImportGroup

```xml
<ImportGroup Label="ExtensionSettings" />
```

O grupo `ExtensionSettings` contém importações para as folhas de propriedades que fazem parte das Personalizações de Build. Uma Personalização de Build é definida por até três arquivos: um arquivo .targets, um arquivo .props e um arquivo .xml. Esse grupo de importação contém as importações para o arquivo .props.

### <a name="propertysheets-importgroup-elements"></a>Elementos PropertySheets ImportGroup

```xml
<ImportGroup Label="PropertySheets" />
```

O grupo `PropertySheets` contém as importações para as folhas de propriedades do usuário. Essas são as folhas de propriedades que podem ser adicionadas por meio da exibição do Gerenciador de Propriedades no Visual Studio. A ordem na qual essas importações são listadas é importante e é refletida no Gerenciador de Propriedades. Normalmente, o arquivo de projeto contém várias instâncias desse tipo de grupo de importação, uma para cada configuração de projeto.

### <a name="usermacros-propertygroup-element"></a>Elemento UserMacros PropertyGroup

```xml
<PropertyGroup Label="UserMacros" />
```

`UserMacros` contém as propriedades criadas como variáveis que são usadas para personalizar o processo de build. Por exemplo, você pode definir uma macro de usuário para definir o caminho de saída personalizado como $(CustomOutputPath) e usá-lo para definir outras variáveis. Esse grupo de propriedades hospeda essas propriedades. Observe que, no Visual Studio, esse grupo não é populado no arquivo de projeto porque o Visual C++ não dá suporte a macros de usuário para configurações. Há suporte para macros de usuário em folhas de propriedades.

### <a name="per-configuration-propertygroup-elements"></a>Elementos PropertyGroup por configuração

```xml
<PropertyGroup />
```

Há várias instâncias desse grupo de propriedades, um por configuração para todas as configurações de projeto. Cada grupo de propriedades precisa ter uma condição de configuração anexada. Se as configurações estiverem ausentes, a caixa de diálogo **Propriedades do Projeto** não funcionará corretamente. Ao contrário dos grupos de propriedades acima, esse não tem um rótulo. Esse grupo contém as configurações no nível de configuração do projeto. Essas configurações se aplicam a todos os arquivos que fazem parte do grupo de itens especificado. Os metadados de definição de item de personalização de build são inicializados aqui.

Esse PropertyGroup precisa vir após `<Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />` e não deve haver nenhum outro PropertyGroup sem um Label antes dele (caso contrário, a edição de Propriedades do Projeto não funcionará corretamente).

### <a name="per-configuration-itemdefinitiongroup-elements"></a>Elementos ItemDefinitionGroup por configuração

```xml
<ItemDefinitionGroup />
```

Contém definições de item. Elas precisam seguir as mesmas regras de condições que os elementos PropertyGroup sem rótulo por configuração.

### <a name="itemgroup-elements"></a>Elementos ItemGroup

```xml
<ItemGroup />
```

Contém os itens (arquivos de origem, etc.) no projeto. Não há suporte para condições em itens de Projeto (ou seja, tipos de item que são tratados como itens de projeto pelas definições de regras).

Os metadados deverão ter condições de configuração para cada configuração, mesmo se forem os mesmos. Por exemplo:

```xml
<ItemGroup>
  <ClCompile Include="stdafx.cpp">
    <TreatWarningAsError Condition="‘$(Configuration)|$(Platform)’==’Debug|Win32’">true</TreatWarningAsError>
    <TreatWarningAsError Condition="‘$(Configuration)|$(Platform)’==’Debug|x64’">true</TreatWarningAsError>
  </ClCompile>
</ItemGroup>
```

Atualmente, o sistema de projeto do Visual C++ não dá suporte a curingas em itens de projeto.

```xml
<ItemGroup>
  <ClCompile Include="*.cpp"> <!--Error-->
</ItemGroup>
```

Atualmente, o sistema de projeto do Visual C++ não dá suporte a macros em itens de projeto.

```xml
<ItemGroup>
  <ClCompile Include="$(IntDir)\generated.cpp"> <!--not guaranteed to work in all scenarios-->
</ItemGroup>
```

As referências são especificadas em um ItemGroup e têm as seguintes limitações:

- As referências não dão suporte a condições.

- Os metadados de referências não dão suporte a condições.

### <a name="microsoftcpptargets-import-element"></a>Elemento Microsoft.Cpp.targets Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
```

Define (diretamente ou por meio de importações) os destinos do Visual C++ como build, limpeza, etc.

### <a name="extensiontargets-importgroup-element"></a>Elemento ExtensionTargets ImportGroup

```xml
<ImportGroup Label="ExtensionTargets" />
```

Esse grupo contém importações para os arquivos de destino de Personalização de Build.

## <a name="impact-of-incorrect-ordering"></a>Impacto da ordenação incorreta

O IDE do Visual Studio depende que o arquivo de projeto tenha a ordenação descrita acima. Por exemplo, quando você definir um valor de propriedade nas páginas de propriedades, geralmente, o IDE colocará a definição de propriedade no grupo de propriedades com o rótulo vazio. Isso garante que os valores padrão trazidos nas folhas de propriedades do sistema sejam substituídos por valores definidos pelo usuário. Da mesma forma, os arquivos de destino são importados no final, pois consomem as propriedades definidas acima e, geralmente, não definem as propriedades por conta própria. Da mesma forma, as folhas de propriedades do usuário são importadas após as folhas de propriedades do sistema (incluídas por meio de **Microsoft.Cpp.props**). Isso garante que o usuário possa substituir os padrões trazidos pelas folhas de propriedades do sistema.

Se um arquivo .vcxproj não segue esse layout, os resultados do build podem não ser o esperado. Por exemplo, se, por engano, você importar uma folha de propriedades do sistema após as folhas de propriedades definidas pelo usuário, as configurações do usuário serão substituídas pelas folhas de propriedades do sistema.

Até mesmo a experiência em tempo de design do IDE depende, até certo ponto, da ordenação correta dos elementos. Por exemplo, se o arquivo .vcxproj não tem o grupo de importação `PropertySheets`, o IDE pode não conseguir determinar o local em que colocar uma nova folha de propriedades criada polo usuário no **Gerenciador de Propriedades**. Isso pode resultar na substituição de uma folha do usuário por uma folha do sistema. Embora a heurística usada pelo IDE possa tolerar pequenas inconsistências no layout do arquivo .vcxproj, é altamente recomendável não se desviar da estrutura mostrada anteriormente neste artigo.

## <a name="how-the-ide-uses-element-labels"></a>Como o IDE usa os rótulos de elementos

No IDE, quando você define a propriedade **UseOfAtl** na página de propriedades geral, ela é gravada no grupo de propriedades de Configuração no arquivo de projeto, enquanto a propriedade **TargetName** na mesma página de propriedades é gravada no grupo de propriedades sem rótulo por configuração. O Visual Studio examina o arquivo XML da página de propriedades para obter as informações sobre o local em que gravar cada propriedade. Para a página de propriedades **Geral** (supondo que você tenha uma versão em inglês do Visual Studio Enterprise Edition), esse arquivo é `%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets\1033\general.xml`. O arquivo de regra XML da página de propriedades define as informações estáticas sobre uma Rule e todas as suas propriedades. Uma dessas informações é a posição preferencial de uma propriedade Rule no arquivo de destino (o arquivo no qual seu valor será gravado). A posição preferencial é especificada pelo atributo Label nos elementos do arquivo de projeto.

## <a name="property-sheet-layout"></a>Layout da folha de propriedades

O snippet XML a seguir é um layout mínimo de um arquivo de folha de propriedades (.props). Ele é semelhante a um arquivo .vcxproj e a funcionalidade dos elementos .props pode ser inferida com base na discussão anterior.

```xml
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ImportGroup Label="PropertySheets" />
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup />
  <ItemDefinitionGroup />
  <ItemGroup />
</Project>
```

Para criar sua própria folha de propriedades, copie um dos arquivos .props na pasta VCTargets e modifique-o conforme a finalidade. Para a Visual Studio 2017 Enterprise Edition, o caminho padrão de VCTargets é `%ProgramFiles%\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets`.

## <a name="see-also"></a>Consulte também

[Definição das propriedades de compilação do C++ no Visual Studio](../working-with-project-properties.md)<br/>
[Arquivos XML de página de propriedade](property-page-xml-files.md)
