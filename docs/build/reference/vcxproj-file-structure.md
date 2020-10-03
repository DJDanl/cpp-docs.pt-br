---
title: Estrutura de arquivos .vcxproj e .props
description: Como os arquivos System. vcxproj e. props do C++ Native MSBuild armazenam informações do projeto.
ms.date: 09/30/2020
helpviewer_keywords:
- .vcxproj file structure
ms.assetid: 14d0c552-29db-480e-80c1-7ea89d6d8e9c
ms.openlocfilehash: 562ef0c1b371d7212f31da1917d19c012e4cbb24
ms.sourcegitcommit: f7fbdc39d73e1fb3793c396fccf7a1602af7248b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2020
ms.locfileid: "91662276"
---
# <a name="vcxproj-and-props-file-structure"></a>`.vcxproj` e `.props` estrutura de arquivos

O [MSBuild](../msbuild-visual-cpp.md) é o sistema de projeto padrão no Visual Studio; Quando você escolhe **arquivo**  >  **novo projeto** no Visual C++ você está criando um projeto do MSBuild cujas configurações são armazenadas em um arquivo de projeto XML que tem a extensão *`.vcxproj`* . O arquivo de projeto também pode importar *`.props`* arquivos e *`.targets`* arquivos onde as configurações podem ser armazenadas.

Recomendamos que você crie e modifique apenas *`.vcxproj`* projetos no IDE e evite a edição manual tanto quanto possível. Na maioria dos casos, você nunca precisa editar manualmente o arquivo de projeto. Sempre que possível, você deve usar as páginas de propriedades do Visual Studio para modificar as configurações do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

Se você precisar de personalizações que não são possíveis no IDE, recomendamos que você adicione props personalizados ou destinos. Os locais práticos para inserir personalizações são os *`Directory.Build.props`* *`Directory.Build.targets`* arquivos e, que são importados automaticamente em todos os projetos baseados em MSBuild.

Em alguns casos, talvez você ainda precise modificar um *`.vcxproj`* arquivo de projeto ou folha de propriedades manualmente. Não recomendamos que você o edite manualmente, a menos que você tenha uma boa compreensão do MSBuild e siga as diretrizes neste artigo. Para que o IDE carregue e atualize *`.vcxproj`* arquivos automaticamente, esses arquivos têm várias restrições que não se aplicam a outros arquivos de projeto do MSBuild. Elas não foram projetadas para edição manual. Erros podem fazer com que o IDE falhe ou se comporte de maneiras inesperadas.

Para cenários de edição manual, este artigo contém informações básicas sobre a estrutura *`.vcxproj`* e os arquivos relacionados.

**Importante:**

Se você optar por editar um arquivo manualmente, lembre-se desses *`.vcxproj`* fatos:

- A estrutura do arquivo precisa seguir um formato prescrito, que é descrito neste artigo.

- Atualmente, o sistema de projeto C++ do Visual Studio não dá suporte a curingas ou listas diretamente em itens de projeto. Por exemplo, esses formulários não têm suporte:

   ```xml
   <ItemGroup>
     <None Include="*.txt"/>
     <ClCompile Include="a.cpp;b.cpp"/>
   </ItemGroup>
   ```

   Para obter mais informações sobre o suporte a caracteres curinga em projetos e possíveis soluções alternativas, consulte [ `.vcxproj` arquivos e curingas](vcxproj-files-and-wildcards.md).

- Atualmente, o sistema de projeto C++ do Visual Studio não dá suporte a macros em caminhos de item de projeto. Por exemplo, não há suporte para esse formulário:

   ```xml
   <ItemGroup>
     <ClCompile Include="$(IntDir)\generated.cpp"/>
   </ItemGroup>
   ```

   "Sem suporte" significa que não há garantia de que as macros funcionem para todas as operações no IDE. As macros que não alteram seu valor em configurações diferentes devem funcionar, mas podem não ser preservadas se um item for movido para um filtro ou projeto diferente. As macros que alteram seu valor para configurações diferentes causarão problemas. Isso ocorre porque o IDE não espera que os caminhos de item do projeto sejam diferentes para diferentes configurações de projeto.

- Para adicionar, remover ou modificar as propriedades do projeto corretamente ao editá-las na caixa de diálogo **Propriedades do projeto** , o arquivo deve conter grupos separados para cada configuração de projeto. As condições devem estar neste formato:

   ```xml
   Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"
   ```

- Cada propriedade deve ser especificada no grupo com seu rótulo correto, conforme especificado no arquivo de regra de propriedade. Para obter mais informações, confira [Arquivos de regras XML da página de propriedades](property-page-xml-files.md).

## <a name="vcxproj-file-elements"></a>`.vcxproj` elementos de arquivo

Você pode inspecionar o conteúdo de um *`.vcxproj`* arquivo usando qualquer editor de texto ou XML. Exiba-o no Visual Studio clicando com o botão direito do mouse no projeto no Gerenciador de Soluções, escolhendo **Descarregar projeto** e, em seguida, **Editar Foo.vcxproj**.

A primeira coisa a ser observada é que os elementos de nível superior são exibidos em uma ordem específica. Por exemplo:

- A maioria dos grupos de propriedades e dos grupos de definição de item ocorre após a importação para Microsoft.Cpp.Default.props.

- Todos os destinos são importados no final do arquivo.

- Há vários grupos de propriedades, cada um com um rótulo exclusivo, e que ocorrem em uma ordem específica.

A ordem dos elementos no arquivo de projeto é vitalmente importante, pois o MSBuild é baseado em um modelo de avaliação sequencial.  Se o arquivo de projeto, incluindo todos os *`.props`* arquivos e importados *`.targets`* , consistir em várias definições de uma propriedade, a última definição substituirá os anteriores. No exemplo a seguir, o valor "XYZ" será definido durante a compilação porque o mecanismo MSBUild o encontrará por último durante sua avaliação.

```xml
  <MyProperty>abc</MyProperty>
  <MyProperty>xyz</MyProperty>
```

O trecho a seguir mostra um *`.vcxproj`* arquivo mínimo. Qualquer *`.vcxproj`* arquivo gerado pelo Visual Studio conterá esses elementos do MSBuild de nível superior. E eles aparecerão nesta ordem, embora possam conter várias cópias de cada elemento de nível superior. Todos os `Label` atributos são marcas arbitrárias que são usadas apenas pelo Visual Studio como signposts para edição; elas não têm nenhuma outra função.

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

As seções a seguir descrevem a finalidade de cada um desses elementos e por que eles são ordenados dessa maneira:

### <a name="project-element"></a>Elemento de projeto

```xml
<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns='http://schemas.microsoft.com/developer/msbuild/2003' >
```

`Project` é o nó raiz. Ele especifica a versão do MSBuild a ser usada e também o destino padrão a ser executado quando esse arquivo é passado para MSBuild.exe.

### <a name="projectconfigurations-itemgroup-element"></a>Elemento ProjectConfigurations ItemGroup

```xml
<ItemGroup Label="ProjectConfigurations" />
```

`ProjectConfigurations` contém a descrição da configuração de projeto. Alguns exemplos são Debug|Win32, Release|Win32, Debug|ARM e assim por diante. Muitas configurações de projeto são específicas a determinada configuração. Por exemplo, você provavelmente desejará definir propriedades de otimização para uma compilação de versão, mas não para uma compilação de depuração.

O `ProjectConfigurations` grupo de itens não é usado no momento da compilação. O IDE do Visual Studio exige que ele carregue o projeto. Este grupo de itens pode ser movido para um *`.props`* arquivo e importado para o *`.vcxproj`* arquivo. No entanto, nesse caso, se você precisar adicionar ou remover configurações, será necessário editar manualmente o *`.props`* arquivo; não é possível usar o IDE.

### <a name="projectconfiguration-elements"></a>Elementos de ProjectConfiguration

O snippet a seguir mostra uma configuração de projeto. Neste exemplo, ' Debug | x64 ' é o nome da configuração. O nome de configuração do projeto deve estar no formato `$(Configuration)|$(Platform)` . Um `ProjectConfiguration` nó pode ter duas propriedades: `Configuration` e `Platform` . Essas propriedades são definidas automaticamente com os valores especificados aqui quando a configuração está ativa.

```xml
<ProjectConfiguration Include="Debug|x64">
  <Configuration>Debug</Configuration>
  <Platform>x64</Platform>
</ProjectConfiguration>
```

O IDE espera encontrar uma configuração de projeto para qualquer combinação de `Configuration` `Platform` valores e usados em todos os `ProjectConfiguration` itens. Geralmente, isso significa que um projeto pode ter configurações de projeto sem sentido para atender a esse requisito. Por exemplo, se um projeto tiver essas configurações:

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

`Globals` contém configurações de nível de projeto, como `ProjectGuid` , `RootNamespace` e `ApplicationType` ou `ApplicationTypeRevision` . As duas últimas geralmente definem o sistema operacional de destino. Um projeto só pode ter como destino um único sistema operacional porque atualmente, as referências e os itens de projeto não podem ter condições. Normalmente, essas propriedades não são substituídas em nenhum outro lugar do arquivo de projeto. Esse grupo não é dependente de configuração e normalmente existe apenas um `Globals` grupo no arquivo de projeto.

### <a name="microsoftcppdefaultprops-import-element"></a>Elemento Microsoft.Cpp.default.props Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
```

A folha de propriedades **Microsoft. cpp. default. props** vem com o Visual Studio e não pode ser modificada. Ela contém as configurações padrão para o projeto. Os padrões podem variar dependendo do ApplicationType.

### <a name="configuration-propertygroup-elements"></a>Elementos Configuration PropertyGroup

```xml
<PropertyGroup Label="Configuration" />
```

Um grupo de propriedades `Configuration` tem uma condição de configuração anexada (como `Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"`) e é fornecido em várias cópias, uma por configuração. Esse grupo de propriedades hospeda as propriedades que são definidas para uma configuração específica. As propriedades de configuração incluem PlatformToolset e também controlam a inclusão de folhas de propriedades do sistema em **Microsoft.Cpp.props**. Por exemplo, se você definir a propriedade `<CharacterSet>Unicode</CharacterSet>`, a folha de propriedades do sistema **microsoft.Cpp.unicodesupport.Props** será incluída. Se você inspecionar **Microsoft. cpp. props**, verá a linha: `<Import Condition="'$(CharacterSet)' == 'Unicode'" Project="$(VCTargetsPath)\microsoft.Cpp.unicodesupport.props" />` .

### <a name="microsoftcppprops-import-element"></a>Elemento Microsoft.Cpp.props Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
```

A folha de propriedades **Microsoft. cpp. props** (direta ou por meio de importações) define os valores padrão para muitas propriedades específicas da ferramenta. Os exemplos incluem a otimização do compilador e as propriedades do nível de aviso, a propriedade TypeLibraryName da ferramenta MIDL e assim por diante. Ele também importa várias folhas de propriedades do sistema com base nas propriedades de configuração definidas no grupo de propriedades imediatamente antes dela.

### <a name="extensionsettings-importgroup-element"></a>Elemento ExtensionSettings ImportGroup

```xml
<ImportGroup Label="ExtensionSettings" />
```

O grupo `ExtensionSettings` contém importações para as folhas de propriedades que fazem parte das Personalizações de Build. Uma personalização de compilação é definida por até três arquivos: um *`.targets`* arquivo, um *`.props`* arquivo e um *`.xml`* arquivo. Esse grupo de importação contém as importações para o *`.props`* arquivo.

### <a name="propertysheets-importgroup-elements"></a>Elementos PropertySheets ImportGroup

```xml
<ImportGroup Label="PropertySheets" />
```

O grupo `PropertySheets` contém as importações para as folhas de propriedades do usuário. Essas importações são as folhas de propriedades que você adiciona por meio da exibição Gerenciador de Propriedades no Visual Studio. A ordem na qual essas importações são listadas é importante e é refletida no Gerenciador de Propriedades. Normalmente, o arquivo de projeto contém várias instâncias desse tipo de grupo de importação, uma para cada configuração de projeto.

### <a name="usermacros-propertygroup-element"></a>Elemento UserMacros PropertyGroup

```xml
<PropertyGroup Label="UserMacros" />
```

`UserMacros` contém as propriedades criadas como variáveis que são usadas para personalizar o processo de build. Por exemplo, você pode definir uma macro de usuário para definir o caminho de saída personalizado como $(CustomOutputPath) e usá-lo para definir outras variáveis. Esse grupo de propriedades hospeda essas propriedades. No Visual Studio, esse grupo não é preenchido no arquivo de projeto porque Visual C++ não dá suporte a macros de usuário para configurações. Há suporte para macros de usuário em folhas de propriedades.

### <a name="per-configuration-propertygroup-elements"></a>Elementos PropertyGroup por configuração

```xml
<PropertyGroup />
```

Há várias instâncias desse grupo de propriedades, um por configuração para todas as configurações de projeto. Cada grupo de propriedades precisa ter uma condição de configuração anexada. Se as configurações estiverem ausentes, a caixa de diálogo **Propriedades do Projeto** não funcionará corretamente. Ao contrário dos grupos de propriedades listados anteriormente, este não tem um rótulo. Esse grupo contém as configurações no nível de configuração do projeto. Essas configurações se aplicam a todos os arquivos que fazem parte do grupo de itens especificado. Os metadados de definição de item de personalização de build são inicializados aqui.

Este PropertyGroup deve vir após `<Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />` e não deve haver outro PropertyGroup sem um rótulo antes dele (caso contrário, a edição das propriedades do projeto não funcionará corretamente).

### <a name="per-configuration-itemdefinitiongroup-elements"></a>Elementos ItemDefinitionGroup por configuração

```xml
<ItemDefinitionGroup />
```

Contém definições de item. Essas definições devem seguir as mesmas regras de condições que os elementos por configuração sem rótulo `PropertyGroup` .

### <a name="itemgroup-elements"></a>Elementos ItemGroup

```xml
<ItemGroup />
```

`ItemGroup` os elementos contêm os itens (arquivos de origem e assim por diante) no projeto. Não há suporte para condições para itens de projeto (ou seja, tipos de item que são tratados como itens de projeto por definições de regras).

Os metadados devem ter condições de configuração para cada configuração, mesmo que sejam todos iguais. Por exemplo:

```xml
<ItemGroup>
  <ClCompile Include="stdafx.cpp">
    <TreatWarningAsError Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</TreatWarningAsError>
    <TreatWarningAsError Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">true</TreatWarningAsError>
  </ClCompile>
</ItemGroup>
```

Atualmente, o sistema de projeto C++ do Visual Studio não dá suporte a curingas em itens de projeto.

```xml
<ItemGroup>
  <ClCompile Include="*.cpp"> <!--Error-->
</ItemGroup>
```

Atualmente, o sistema de projeto C++ do Visual Studio não oferece suporte a macros em itens de projeto.

```xml
<ItemGroup>
  <ClCompile Include="$(IntDir)\generated.cpp"> <!--not guaranteed to work in all scenarios-->
</ItemGroup>
```

As referências são especificadas em um ItemGroup e têm as seguintes limitações:

- Referências não dão suporte a condições.

- Os metadados de referência não dão suporte a condições.

### <a name="microsoftcpptargets-import-element"></a>Elemento Microsoft.Cpp.targets Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
```

Define (diretamente ou por meio de importações) destinos do C++ como compilar, limpar e assim por diante.

### <a name="extensiontargets-importgroup-element"></a>Elemento ExtensionTargets ImportGroup

```xml
<ImportGroup Label="ExtensionTargets" />
```

Esse grupo contém importações para os arquivos de destino de Personalização de Build.

## <a name="impact-of-incorrect-ordering"></a>Impacto da ordenação incorreta

O IDE do Visual Studio depende do arquivo de projeto que tem a ordem descrita anteriormente. Por exemplo, quando você definir um valor de propriedade nas páginas de propriedades, geralmente, o IDE colocará a definição de propriedade no grupo de propriedades com o rótulo vazio. Essa ordenação garante que os valores padrão trazidos nas folhas de propriedades do sistema sejam substituídos por valores definidos pelo usuário. Da mesma forma, os arquivos de destino são importados no final, pois eles consomem as propriedades definidas antes e, como geralmente não definem as próprias propriedades. Da mesma forma, as folhas de propriedades do usuário são importadas após as folhas de propriedades do sistema (incluídas pelo *`Microsoft.Cpp.props`* ). Essa ordem garante que o usuário possa substituir os padrões trazidos pelas folhas de propriedades do sistema.

Se um *`.vcxproj`* arquivo não seguir esse layout, os resultados da compilação talvez não sejam os esperados. Por exemplo, se você importou por engano uma folha de propriedades do sistema após as folhas de propriedades definidas pelo usuário, as configurações do usuário são substituídas pelas folhas de propriedades do sistema.

Até mesmo a experiência de tempo de design do IDE depende de alguma medida na ordenação correta dos elementos. Por exemplo, se o *`.vcxproj`* arquivo não tiver o `PropertySheets` grupo de importação, o IDE poderá não conseguir determinar onde posicionar uma nova folha de propriedades que o usuário criou no **Gerenciador de propriedades**. Isso pode fazer com que uma planilha de usuário seja substituída por uma planilha do sistema. Embora a heurística usada pelo IDE possa tolerar inconsistências secundárias no *`.vcxproj`* layout do arquivo, é altamente recomendável que você não desvie da estrutura mostrada anteriormente neste artigo.

## <a name="how-the-ide-uses-element-labels"></a>Como o IDE usa os rótulos de elementos

No IDE, quando você define a propriedade **UseOfAtl** na página de propriedades geral, ela é gravada no grupo de propriedades de configuração no arquivo de projeto. A propriedade **TargetName** na mesma página de propriedades é gravada no grupo de propriedades sem rótulo por configuração. O Visual Studio examina o arquivo XML da página de propriedades para obter as informações sobre o local em que gravar cada propriedade. Para a página de propriedades **geral** , supondo que você tenha uma versão em inglês do Visual Studio 2019 Enterprise Edition, esse arquivo é `%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\VC\VCTargets\1033\general.xml` . O arquivo de regra XML da página de propriedades define as informações estáticas sobre uma Rule e todas as suas propriedades. Uma dessas informações é a posição preferencial de uma propriedade Rule no arquivo de destino (o arquivo no qual seu valor será gravado). A posição preferencial é especificada pelo atributo Label nos elementos do arquivo de projeto.

## <a name="property-sheet-layout"></a>Layout da folha de propriedades

O snippet XML a seguir é um layout mínimo de um arquivo de folha de propriedades (.props). Ele é semelhante a um *`.vcxproj`* arquivo, e a funcionalidade dos *`.props`* elementos pode ser inferida da discussão anterior.

```xml
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ImportGroup Label="PropertySheets" />
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup />
  <ItemDefinitionGroup />
  <ItemGroup />
</Project>
```

Para criar sua própria folha de propriedades, copie um dos *`.props`* arquivos na *`VCTargets`* pasta e modifique-o para suas finalidades. Para o Visual Studio 2019 Enterprise Edition, o *`VCTargets`* caminho padrão é `%ProgramFiles%\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\VC\VCTargets` .

## <a name="see-also"></a>Consulte também

[Definir o compilador C++ e as propriedades de compilação no Visual Studio](../working-with-project-properties.md)\
[Arquivos XML de página de propriedades](property-page-xml-files.md)\
[`.vcxproj` arquivos e curingas](vcxproj-files-and-wildcards.md)
