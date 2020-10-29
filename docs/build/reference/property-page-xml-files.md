---
title: Arquivos de regra XML da Página de Propriedades
description: Descrição do conteúdo e arquivos de regra XML da página de propriedades do IDE do Visual Studio C++.
ms.date: 10/14/2020
helpviewer_keywords:
- property page XML files
ms.openlocfilehash: f8aa893fa2b062da2f1d0784e5a9b1a6f2b30c95
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921393"
---
# <a name="property-page-xml-rule-files"></a>Arquivos de regra XML da Página de Propriedades

As páginas de propriedades do projeto no IDE são configuradas por arquivos XML na pasta regras padrão. Os arquivos XML descrevem os nomes das regras, das categorias e das propriedades individuais, seus tipos de dados, valores padrão e como exibi-los. Quando você define uma propriedade no IDE, o novo valor é armazenado no arquivo de projeto.

::: moniker range="msvc-140"

O caminho para a pasta regras padrão depende da localidade e da versão do Visual Studio em uso. Em um prompt de comando do desenvolvedor do Visual Studio 2015 ou anterior, a pasta regras é *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\<locale>`* . O `<version>` valor está *`v140`* no Visual Studio 2015. O `<locale>` é um LCID, por exemplo, `1033` para inglês. Você usará um caminho diferente para cada edição do Visual Studio que está instalado e para cada idioma. Por exemplo, o caminho da pasta regras padrão para o Visual Studio 2015 Community Edition em inglês pode ser *`C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\v140\1033\`* .

::: moniker-end

::: moniker range="msvc-150"

O caminho para a pasta regras padrão depende da localidade e da versão do Visual Studio em uso. Em um prompt de comando do desenvolvedor do Visual Studio 2017, a pasta regras é *`%VSINSTALLDIR%Common7\IDE\VC\VCTargets\<locale>\`* . O `<locale>` é um LCID, por exemplo, `1033` para inglês. Em um prompt de comando do desenvolvedor do Visual Studio 2015 ou anterior, a pasta regras é *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\<locale>\`* , em que o `<version>` valor está *`v140`* no Visual Studio 2015. Você usará um caminho diferente para cada edição do Visual Studio que está instalado e para cada idioma. Por exemplo, o caminho da pasta regras padrão para o Visual Studio 2017 Community Edition em inglês pode ser *`C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets\1033\`* .

::: moniker-end

::: moniker range=">=msvc-160"

O caminho para a pasta regras padrão depende da localidade e da versão do Visual Studio em uso. Em um prompt de comando do desenvolvedor do Visual Studio 2019 ou posterior, a pasta regras é *`%VSINSTALLDIR%MSBuild\Microsoft\VC\<version>\<locale>\`* , em que o `<version>` valor está *`v160`* no Visual Studio 2019. O `<locale>` é um LCID, por exemplo, `1033` para inglês. No Visual Studio 2017, a pasta regras é *`%VSINSTALLDIR%Common7\IDE\VC\VCTargets\<locale>\`* . Em um prompt de comando do desenvolvedor do Visual Studio 2015 ou anterior, a pasta regras é *`%ProgramFiles(x86)%\MSBuild\Microsoft.Cpp\v4.0\<version>\<locale>\`* . Você usará um caminho diferente para cada edição do Visual Studio que está instalado e para cada idioma. Por exemplo, o caminho da pasta regras padrão para o Visual Studio 2019 Community Edition em inglês pode ser *`C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Microsoft\VC\v160\1033\`* .

::: moniker-end

Você só precisa compreender o funcionamento interno desses arquivos e o IDE do Visual Studio em alguns cenários:

- Você deseja criar uma página de propriedades Personalizada ou
- Você deseja personalizar as propriedades do projeto sem usar o IDE do Visual Studio.

## <a name="contents-of-rule-files"></a>Conteúdo dos arquivos de regra

Primeiro, vamos abrir as páginas de propriedades de um projeto. Clique com o botão direito do mouse no nó do projeto em **Gerenciador de soluções** e escolha **Propriedades** :

![Mostra a caixa de diálogo Propriedades do projeto C++ do Visual Studio](../media/cpp-property-page-2017.png)

Cada nó em **Propriedades de configuração** é chamado de *regra* . Algumas vezes, uma regra representa uma única ferramenta como o compilador. Em geral, o termo refere-se a algo que tem propriedades, que é executada e que pode produzir alguma saída. Cada regra é populada a partir de um arquivo XML na pasta regras padrão. Por exemplo, a regra C/C++ mostrada aqui é preenchida por *'cl.xml '* .

Cada regra tem um conjunto de propriedades, que são organizadas em *categorias* . Cada subnó em uma regra representa uma categoria. Por exemplo, o nó **otimização** em **C/C++** contém todas as propriedades relacionadas à otimização da ferramenta do compilador. As propriedades e seus valores são renderizados em um formato de grade no painel direito.

Você pode abrir *`cl.xml`* no bloco de notas ou em qualquer editor de XML. Você verá um nó raiz chamado `Rule` . Ele define a mesma lista de propriedades que são exibidas na interface do usuário, juntamente com metadados adicionais.

```xml
<?xml version="1.0" encoding="utf-8"?>
<!--Copyright, Microsoft Corporation, All rights reserved.-->
<Rule Name="CL" PageTemplate="tool" DisplayName="C/C++" SwitchPrefix="/" Order="10" xmlns="http://schemas.microsoft.com/build/2009/properties" xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" xmlns:sys="clr-namespace:System;assembly=mscorlib">
  <Rule.Categories>
    <Category Name="General" DisplayName="General" />
    <Category Name="Optimization" DisplayName="Optimization" />
    <Category Name="Preprocessor" DisplayName="Preprocessor" />
    <Category Name="Code Generation" DisplayName="Code Generation" />
    <Category Name="Language" DisplayName="Language" />
    <Category Name="Precompiled Headers" DisplayName="Precompiled Headers" />
    <Category Name="Output Files" DisplayName="Output Files" />
    <Category Name="Browse Information" DisplayName="Browse Information" />
    <Category Name="Advanced" DisplayName="Advanced" />
    <Category Name="All Options" DisplayName="All Options" Subtype="Search" />
    <Category Name="Command Line" DisplayName="Command Line" Subtype="CommandLine" />
  </Rule.Categories>
  <!-- . . . -->
</Rule>
```

Há um arquivo XML para cada nó em **Propriedades de configuração** na interface do usuário de páginas de propriedades. Você pode adicionar ou remover regras na interface do usuário: isso é feito incluindo ou removendo locais para arquivos XML correspondentes no projeto. Por exemplo, é como *`Microsoft.CppBuild.targets`* (encontrado um nível acima da pasta 1033) inclui *`cl.xml`* :

```xml
<PropertyPageSchema Condition="'$(ConfigurationType)' != 'Utility'" Include="$(VCTargetsPath)$(LangID)\cl.xml"/>
```

Se você remover *`cl.xml`* todos os dados, terá essa estrutura básica:

```xml
<?xml version="1.0" encoding="utf-8"?>
<Rule>
  <Rule.DataSource />
  <Rule.Categories>
    <Category />
    <!-- . . . -->
  </Rule.Categories>
  <BoolProperty />
  <EnumProperty />
  <IntProperty />
  <StringProperty />
  <StringListProperty />
</Rule>
```

A próxima seção descreve cada elemento principal e alguns dos metadados que você pode anexar.

### <a name="rule-attributes"></a>Atributos da regra

Um **`<Rule>`** elemento é o nó raiz no arquivo XML. Ele pode ter muitos atributos:

```xml
<Rule Name="CL" PageTemplate="tool" SwitchPrefix="/" Order="10"
          xmlns="http://schemas.microsoft.com/build/2009/properties"
          xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
          xmlns:sys="clr-namespace:System;assembly=mscorlib">
  <Rule.DisplayName>
    <sys:String>C/C++</sys:String>
  </Rule.DisplayName>
```

- **`Name`** : O atributo Name é uma ID para o `Rule` . Ele precisa ser exclusivo entre todos os arquivos XML da página de propriedades de um projeto.

- **`PageTemplate`** : O valor desse atributo é usado pela interface do usuário para escolher um conjunto de modelos de interface do usuário. O modelo de "ferramenta" renderiza as propriedades em um formato de grade padrão. Outros valores internos para esse atributo são "depurador" e "genérico". Veja os nós Depuração e Geral, respectivamente, para ver o formato de interface do usuário resultante da especificação desses valores. A interface do usuário do modelo de página "depurador" usa uma caixa suspensa para alternar entre as propriedades de diferentes depuradores. O modelo "genérico" exibe categorias de propriedade diferentes em uma página, em vez de ter vários subnós de categoria sob o `Rule` nó. Esse atributo é apenas uma sugestão para a interface do usuário. O arquivo XML é projetado para ser independente da interface do usuário. Outra interface do usuário pode usar esse atributo para diferentes finalidades.

- **`SwitchPrefix`** : O prefixo usado na linha de comando para as opções. Um valor `"/"` pode resultar em opções que se parecem com **`/ZI`** , **`/nologo`** , **`/W3`** e assim por diante.

- **`Order`** : Uma sugestão a um cliente de interface do usuário potencial no local relativo, em `Rule` comparação com todas as outras regras no sistema.

- **`xmlns`** : Um elemento XML padrão. É possível ver três namespaces listados. Esses atributos correspondem aos namespaces para as classes de desserialização XML, o esquema XML e o namespace System, respectivamente.

- **`DisplayName`** : O nome mostrado na interface do usuário da página de propriedades para o `Rule` nó. Esse valor está localizado. Criamos `DisplayName` como um elemento filho de `Rule` , em vez de como um atributo (como `Name` ou `SwitchPrefix` ) devido aos requisitos da ferramenta de localização interna. De uma perspectiva XML, ambas são equivalentes. Portanto, basta torná-lo um atributo para reduzir a desordem ou deixá-lo como é.

- **`DataSource`** : Essa propriedade importante informa ao sistema do projeto o local para ler e gravar o valor da propriedade e seu agrupamento (explicado posteriormente). Para o *`cl.xml`* , esses valores são:

    ```xml
    <DataSource Persistence="ProjectFile" ItemType="ClCompile" Label="" HasConfigurationCondition="true" />
    ```

  - `Persistence="ProjectFile"` informa ao sistema do projeto que todas as propriedades do `Rule` devem ser gravadas no arquivo de projeto ou no arquivo de folha de Propriedades (dependendo de qual nó foi usado para gerar as páginas de propriedades). O outro valor possível é `"UserFile"` , que gravará o valor no *`.user`* arquivo.

  - `ItemType="ClCompile"` indica que as propriedades serão armazenadas como metadados de ItemDefinition ou metadados de item (o último somente ocorrerá se as páginas de propriedades foram geradas com base em um nó de arquivo no Gerenciador de Soluções) desse tipo de item. Se esse campo não estiver definido, a propriedade será gravada como uma propriedade comum em um PropertyGroup.

  - `Label=""` indica que quando as propriedades forem gravadas como metadados de `ItemDefinition`, o rótulo do ItemDefinitionGroup pai ficará vazio (cada elemento do MSBuild pode ter um Rótulo). O Visual Studio 2017 e posterior usa grupos rotulados para navegar pelo arquivo de projeto .vcxproj. Os grupos que contêm a maioria das `Rule` Propriedades têm uma cadeia de caracteres vazia como um rótulo.

  - `HasConfigurationCondition="true"` instrui o sistema do projeto a afixar uma condição de configuração ao valor, de modo que ele entre em vigor apenas na configuração do projeto atual (a condição pode ser afixada ao grupo pai ou ao próprio valor). Por exemplo, abra as páginas de propriedades do nó do projeto e defina o valor da propriedade **Tratar Avisos como Erros** em **Propriedades de Configuração > Geral do C/C++** como "Sim". O valor a seguir é gravado no arquivo de projeto. Observe a condição de configuração anexada ao ItemDefinitionGroup pai.

    ```xml
    <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
      <ClCompile>
        <TreatWarningAsError>true</TreatWarningAsError>
      </ClCompile>
    </ItemDefinitionGroup>
    ```

     Se esse valor for definido na página de propriedades de um arquivo específico, como *`stdafx.cpp`* , o valor da propriedade deverá ser gravado sob o `stdafx.cpp` item no arquivo do projeto, conforme mostrado aqui. Observe como a condição de configuração é anexada diretamente aos próprios metadados:

    ```xml
    <ItemGroup>
      <ClCompile Include="stdafx.cpp">
        <TreatWarningAsError Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">true</TreatWarningAsError>
      </ClCompile>
    </ItemGroup>
    ```

  Outro atributo de `DataSource` não listado aqui é `PersistedName` . Use esse atributo para representar uma propriedade no arquivo de projeto usando outro nome. Por padrão, esse atributo é definido como a propriedade `Name` .

  Uma propriedade individual pode substituir o `DataSource` de seu pai `Rule` . Nesse caso, o local para o valor dessa propriedade será diferente de outras propriedades no `Rule` .

- Há outros atributos de a `Rule` , incluindo `Description` e `SupportsFileBatching` , que não são mostrados aqui. O conjunto completo de atributos aplicáveis a um `Rule` ou em qualquer outro elemento pode ser obtido navegando na documentação para esses tipos. Como alternativa, você pode examinar as propriedades públicas nos tipos no namespace `Microsoft.Build.Framework.XamlTypes` do assembly `Microsoft.Build.Framework.dll`.

- **`DisplayName`** , **`PageTemplate`** e **`Order`** são propriedades relacionadas à interface do usuário que estão presentes neste modelo de dados independente de IU. Quase certamente, essas propriedades serão usadas por qualquer interface do usuário usada para exibir as páginas de propriedades. `DisplayName` e `Description` são duas propriedades que estão presentes em quase todos os elementos no arquivo XML. E essas duas propriedades são as únicas que estão localizadas.

### <a name="category-elements"></a>Elementos de categoria

Um `Rule` pode ter vários `Category` elementos. A ordem na qual as categorias são listadas no arquivo XML é uma sugestão para a interface do usuário exibir as categorias na mesma ordem. Por exemplo, a ordem das categorias no nó **C/C++** que você vê na interface do usuário é igual à ordem em *`cl.xml`* . Uma categoria de exemplo tem esta aparência:

```xml
<Category Name="Optimization">
  <Category.DisplayName>
    <sys:String>Optimization</sys:String>
  </Category.DisplayName>
</Category>
```

Este trecho de código mostra os `Name` `DisplayName` atributos e que foram descritos anteriormente. Mais uma vez, há outros atributos `Category` que um pode ter e que não são mostrados no exemplo. Você pode aprender sobre eles lendo a documentação ou examinando os assemblies usando o *`ildasm.exe`* .

### <a name="property-elements"></a>Elementos de propriedade

A maior parte do arquivo de regras consiste em `Property` elementos. Eles contêm a lista de todas as propriedades em um `Rule` . Cada propriedade pode ser um dos cinco tipos possíveis mostrados na estrutura básica:,,, `BoolProperty` `EnumProperty` `IntProperty` `StringProperty` e `StringListProperty` . Você pode ter apenas alguns desses tipos em seu arquivo. Uma propriedade tem um número de atributos que permitem que ele seja descrito em detalhes. O `StringProperty` é descrito aqui. O restante é semelhante.

```xml
<StringProperty Subtype="file" Name="ObjectFileName" Category="Output Files" Switch="Fo">
  <StringProperty.DisplayName>
    <sys:String>Object File Name</sys:String>
  </StringProperty.DisplayName>
  <StringProperty.Description>
    <sys:String>Specifies a name to override the default object file name; can be file or directory name.(/Fo[name])</sys:String>
  </StringProperty.Description>
</StringProperty>
```

A maioria dos atributos no snippet foi descrita antes. Os novos são `Subtype` , `Category` e `Switch` .

- **`Subtype`** é um atributo disponível somente para `StringProperty` `StringListProperty` elementos e. Ele fornece informações contextuais. Por exemplo, o valor `file` indica que a propriedade representa um caminho de arquivo. O Visual Studio usa essas informações contextuais para aprimorar a experiência de edição. Por exemplo, ele pode fornecer uma janela do Windows Explorer que permite ao usuário escolher o arquivo visualmente como o editor da propriedade.

- **`Category`** : A categoria sob a qual essa propriedade cai. Tente encontrar essa propriedade na categoria **Arquivos de Saída** na interface do usuário.

- **`Switch`** : Quando uma regra representa uma ferramenta como a ferramenta do compilador, a maioria das `Rule` Propriedades é passada como comutadores para o executável da ferramenta no momento da compilação. O valor desse atributo indica qual comutador literal usar. O `<StringProperty>` exemplo especifica que sua opção deve ser **`Fo`** . Combinado com o `SwitchPrefix` atributo no pai `Rule` , essa propriedade é passada para o executável como  **`/Fo"Debug\"`** . Ele é visível na linha de comando para C/C++ na interface do usuário da página de propriedades.

   Outros atributos de propriedade incluem:

- **`Visible`** : Se você não quiser que sua propriedade apareça nas páginas de propriedades, mas deseja disponibilizá-la no momento da compilação, defina esse atributo como `false` .

- **`ReadOnly`** : Se você quiser fornecer uma exibição somente leitura do valor dessa propriedade nas páginas de propriedades, defina esse atributo como `true` .

- **`IncludeInCommandLine`** : No momento da compilação, uma ferramenta pode não precisar de algumas de suas propriedades. Defina este atributo como `false` para impedir que uma determinada propriedade seja passada.
