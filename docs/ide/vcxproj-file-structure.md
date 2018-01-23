---
title: estrutura do arquivo. vcxproj e .props | Microsoft Docs
ms.custom: 
ms.date: 04/27/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: .vcxproj file structure
ms.assetid: 14d0c552-29db-480e-80c1-7ea89d6d8e9c
caps.latest.revision: "1"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d48b16d9a4250de8c8c3dfef62fdcfb5c1434960
ms.sourcegitcommit: 6f40bba1772a09ff0e3843d5f70b553e1a15ab50
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2018
---
# <a name="vcxproj-and-props-file-structure"></a>estrutura do arquivo. vcxproj e .props

MSBuild é o sistema de projeto padrão no Visual Studio; Quando você escolhe **arquivo | Novo projeto** no Visual C++, você está criando um projeto do MSBuild cujas configurações são armazenadas em um arquivo de projeto XML que tem a extensão `.vcxproj`. O arquivo de projeto também pode importar arquivos de .props e arquivos. targets onde as configurações podem ser armazenadas. Na maioria dos casos, você nunca precisa editar manualmente o arquivo de projeto e, na verdade não edite-lo manualmente, a menos que você tem uma boa compreensão do MSBuild. Sempre que possível você deve usar as páginas de propriedades do Visual Studio para modificar as configurações de projeto (consulte [trabalhar com propriedades do projeto](working-with-project-properties.md). No entanto, em alguns casos pode ser necessário modificar uma folha de propriedade ou o arquivo de projeto manualmente. Para esses cenários, este artigo contém informações básicas sobre a estrutura do arquivo.

**Importante:**

Se você optar por editar manualmente um arquivo. vcxproj, lembre-se desses fatos:

1. A estrutura do arquivo deve seguir um formulário prescrito, que é descrito neste artigo.

1. O sistema de projeto do Visual C++ atualmente não suporta curingas em itens de projeto. Por exemplo, isso não é suportado:

   ```xml
   <ClCompile Include="*.cpp"/>
   ```

1. O sistema de projeto do Visual C++ no momento não oferece suporte as macros em caminhos de item de projeto. Por exemplo, isso não é suportado:

   ```xml
   <ClCompile Include="$(IntDir)\generated.cpp"/>
   ```

1. Para propriedades do projeto adicionado, removido ou modificado quando editada no corretamente o **propriedades do projeto** caixa de diálogo, o arquivo deve conter grupos separados para cada configuração de projeto e as condições devem ser neste formulário:

   ```xml
   Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"
   ```

1. Cada propriedade deve ser especificada no grupo com o rótulo correto, conforme especificado no arquivo de regra de propriedade. Para obter mais informações, consulte [arquivos de regras do xml de página de propriedade](property-page-xml-files.md).

## <a name="vcxproj-file-elements"></a>elementos do arquivo. vcxproj

Você pode inspecionar o conteúdo de um arquivo. vcxproj usando qualquer editor de texto ou XML. Você pode exibi-lo no Visual Studio clicando no projeto no Gerenciador de soluções, escolha **descarregar projeto** e, em seguida, escolhendo **Foo.vcxproj editar**.

A primeira coisa a observar é que os elementos de nível superior aparecem em uma ordem específica. Por exemplo:

- a maioria dos grupos de propriedades e grupos de definição de item ocorrem após a importação para Microsoft.Cpp.Default.props.
- todos os destinos são importados no final do arquivo.
- Há vários grupos de propriedade, cada um com um rótulo exclusivo, e que ocorrem em uma ordem específica.

A ordem dos elementos no arquivo de projeto é muito importante, pois o MSBuild é baseado em um modelo de avaliação sequencial.  Se o arquivo de projeto, incluindo todos os arquivos. targets e importados .props consiste em várias definições de uma propriedade, a última definição substitui os anteriores. No exemplo a seguir, o valor "xyz" será definido durante a compilação porque o MSBUild mecanismo encontra-última durante sua avaliação.

```xml
  <MyProperty>abc</MyProperty>
  <MyProperty>xyz</MyProperty>
```

O trecho a seguir mostra um arquivo. vcxproj mínimo. Qualquer arquivo. vcxproj gerado pelo Visual Studio irá conter esses elementos de nível superior de MSBuild e eles serão exibidos nesta ordem (embora podem conter várias cópias de cada esse elemento de nível superior). Observe que `Label` atributos são marcas arbitrárias que são usadas somente pelo Visual Studio como signposts para edição; eles têm nenhuma outra função.

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

As seções a seguir descrevem a finalidade de cada um desses elementos e por que eles são ordenados desta forma:

### <a name="project-element"></a>Elemento de projeto

```xml
<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns='http://schemas.microsoft.com/developer/msbuild/2003' >
```

`Project`é o nó raiz. Especifica a versão de MSBuild para usar e também o destino padrão a ser executado quando esse arquivo é passado para MSBuild.exe.

### <a name="projectconfigurations-itemgroup-element"></a>Elemento ProjectConfigurations ItemGroup

```xml
<ItemGroup Label="ProjectConfigurations" />
```

`ProjectConfigurations`contém a descrição da configuração de projeto. Os exemplos são Debug | Win32, versão | Win32, Debug | ARM e assim por diante. Muitas configurações de projeto são específicas para uma determinada configuração. Por exemplo, você provavelmente desejará definir propriedades de otimização para um build de versão, mas não uma compilação de depuração.

O `ProjectConfigurations` grupo de item não é usado no momento da compilação. IDE do Visual Studio requer a fim de carregar o projeto. Este grupo de itens pode ser movido para um arquivo .props e importado para o arquivo. vcxproj. No entanto, nesse caso, se você precisar adicionar ou remover as configurações, você deve editar manualmente o arquivo .props; Você não pode usar o IDE.

### <a name="projectconfiguration-elements"></a>Elementos de ProjectConfiguration

O trecho a seguir mostra uma configuração de projeto. Neste exemplo ' Depurar | x 64' é o nome da configuração. O nome da configuração de projeto deve estar no $(Configuration)|$(Platform). formato Um nó de configuração de projeto pode ter duas propriedades: configuração e plataforma. Essas propriedades serão definidas automaticamente com os valores especificados aqui quando a configuração está ativa.

   ```xml
   <ProjectConfiguration Include="Debug|x64">
     <Configuration>Debug</Configuration>
     <Platform>x64</Platform>
   </ProjectConfiguration>
   ```

O IDE espera encontrar uma configuração de projeto para qualquer combinação de valores de configuração e plataforma usada em todos os itens de ProjectConfiguration. Geralmente, isso significa que um projeto pode ter configurações de projeto sem sentido para atender a esse requisito. Por exemplo, se um projeto tem essas configurações:

- Debug|Win32
- Retail|Win32
- Otimização de 32 bits especial | Win32

em seguida, ela também deve ter essas configurações, mesmo que "Otimização especial de 32 bits" não tem sentida para x64:

- Debug|x64
- Retail|x64
- Otimização de 32 bits especial | x64

Você pode desabilitar a compilação e implantar comandos para qualquer configuração no **Gerenciador de configuração**.

### <a name="globals-propertygroup-element"></a>Elemento Globals PropertyGroup

```xml
 <PropertyGroup Label="Globals" />
```

`Globals`contém configurações de nível de projeto como ProjectGuid, RootNamespace e ApplicationType / ApplicationTypeRevision. Os dois últimos geralmente definem o sistema operacional de destino. Um projeto só pode direcionar um sistema operacional devido ao fato de que as referências e itens de projeto não podem ter condições no momento. Essas propriedades são geralmente não substituídas em outro lugar no arquivo de projeto. Esse grupo não é dependente de configuração e, portanto, normalmente apenas um grupo de Globals existe no arquivo de projeto.

### <a name="microsoftcppdefaultprops-import-element"></a>Elemento Microsoft.Cpp.default.props Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.default.props" />
```

O **Microsoft.Cpp.default.props** folha de propriedades é fornecido com o Visual Studio e não pode ser modificada. Ele contém as configurações padrão para o projeto. Os padrões podem variar dependendo do ApplicationType.

### <a name="configuration-propertygroup-elements"></a>Elementos PropertyGroup de configuração

```xml
<PropertyGroup Label="Configuration" />
```

Um `Configuration` grupo de propriedade tem uma condição de configuração anexado (como `Condition=”'$(Configuration)|$(Platform)'=='Debug|Win32'”`) e é fornecido em várias cópias, um por configuração. Esse grupo de propriedade hospeda as propriedades que são definidas para uma configuração específica. Propriedades de configuração incluem PlatformToolset e também controlar a inclusão de folhas de propriedades do sistema em **Microsoft.Cpp.props**. Por exemplo, se você definir a propriedade `<CharacterSet>Unicode</CharacterSet>`, em seguida, a folha de propriedades do sistema **microsoft. Cpp.unicodesupport.Props** serão incluídos. Se você inspecionar **Microsoft.Cpp.props**, você verá a linha: `<Import Condition=”'$(CharacterSet)' == 'Unicode'”   Project=”$(VCTargetsPath)\microsoft.Cpp.unicodesupport.props”/>`.

### <a name="microsoftcppprops-import-element"></a>Elemento Microsoft.Cpp.props Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
```

O **Microsoft.Cpp.props** da folha de propriedades (diretamente ou por meio de importações) define os valores padrão para várias propriedades específicas da ferramenta, como propriedades de nível de aviso e de otimização do compilador, TypeLibraryName da ferramenta MIDL propriedade e assim por diante. Ele também importa várias folhas de propriedade de sistema com base em quais propriedades de configuração são definidas no grupo de propriedades imediatamente acima.

### <a name="extensionsettings-importgroup-element"></a>Elemento ExtensionSettings ImportGroup

```xml
<ImportGroup Label="ExtensionSettings" />
```

O `ExtensionSettings` grupo contém importações para as folhas de propriedades que fazem parte das personalizações de compilação. Uma personalização de compilação é definida por até três arquivos: um arquivo. targets, um arquivo .props e um arquivo. XML. Esse grupo de importação contém o importa para o arquivo .props.

### <a name="propertysheets-importgroup-elements"></a>Elementos de PropertySheets ImportGroup

```xml
<ImportGroup Label="PropertySheets" />
```

O `PropertySheets` grupo contém as importações de folhas de propriedade do usuário. Essas são as folhas de propriedades que podem ser adicionados por meio da exibição do Gerenciador de propriedades no Visual Studio. A ordem na qual essas importações são listadas é importante e é refletida no Gerenciador de propriedade. Normalmente, o arquivo de projeto contém várias instâncias desse tipo de grupo de importação, uma para cada configuração de projeto.

### <a name="usermacros-propertygroup-element"></a>Elemento UserMacros PropertyGroup

```xml
<PropertyGroup Label="UserMacros" />
```

`UserMacros`contém propriedades criar variáveis que são usadas para personalizar o processo de compilação. Por exemplo, você pode definir uma macro de usuário para definir o caminho de saída personalizado como $(CustomOutputPath) e usá-lo para definir outras variáveis. Este grupo de propriedades armazena essas propriedades. Observe que no Visual Studio, esse grupo não é populado no arquivo de projeto porque o Visual C++ não dá suporte para macros do usuário para configurações. Macros do usuário têm suporte em folhas de propriedades.

### <a name="per-configuration-propertygroup-elements"></a>Elementos de PropertyGroup por configuração

```xml
<PropertyGroup />
```

Há várias instâncias deste grupo de propriedade, um por configuração para todas as configurações de projeto. Cada grupo de propriedade deve ter uma condição de configuração anexada. Se as configurações estiverem ausentes, o **propriedades do projeto** caixa de diálogo não funcionará corretamente. Ao contrário dos grupos de propriedade acima, este não tem um rótulo. Esse grupo contém as configurações de nível de configuração do projeto. Essas configurações se aplicam a todos os arquivos que fazem parte do grupo de itens especificado. Definição de item de personalização de compilação metadados é inicializado aqui.

Este PropertyGroup deve vir após `<Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />` e não deve haver nenhuma outra PropertyGroup sem um rótulo antes dele (caso contrário, a edição de propriedades do projeto não funcionará corretamente).

### <a name="per-configuration-itemdefinitiongroup-elements"></a>Elementos de ItemDefinitionGroup por configuração

```xml
 <ItemDefinitionGroup />
```

Contém definições de item. Estas deve seguir as mesmas regras de condições que os elementos PropertyGroup de rótulo sem por configuração.

### <a name="itemgroup-elements"></a>Elementos ItemGroup

```xml
<ItemGroup />
```

Contém os itens (arquivos de origem, etc.) no projeto. Não há suporte para condições para itens de projeto (ou seja, tipos de item que são tratados como itens de projeto pelas definições de regras).

Os metadados devem ter condições de configuração para cada configuração, mesmo se eles são os mesmos. Por exemplo:

   ```xml
   <ItemGroup>
     <ClCompile Include="stdafx.cpp">
       <TreatWarningAsError Condition="‘$(Configuration)|$(Platform)’==’Debug|Win32’">true</TreatWarningAsError>
       <TreatWarningAsError Condition="‘$(Configuration)|$(Platform)’==’Debug|x64’">true</TreatWarningAsError>
     </ClCompile>
   </ItemGroup>
   ```

O sistema de projeto do Visual C++ atualmente não suporta curingas em itens de projeto.

   ```xml
   <ItemGroup>
     <ClCompile Include="*.cpp"> <!--Error-->
   </ItemGroup>
   ```

O sistema de projeto do Visual C++ no momento não oferece suporte as macros em itens de projeto.

   ```xml
   <ItemGroup>
     <ClCompile Include="$(IntDir)\generated.cpp"> <!--not guaranteed to work in all scenarios-->
   </ItemGroup>
   ```

Referências são especificadas em um ItemGroup e têm as seguintes limitações:

- As referências não dão suporte a condições.
- Metadados de referências não dão suporte a condições.

### <a name="microsoftcpptargets-import-element"></a>Elemento Microsoft.Cpp.targets Import

```xml
<Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
```

Define (diretamente ou por meio de importações) destinos de Visual C++ como criar, limpeza, etc.

### <a name="extensiontargets-importgroup-element"></a>Elemento ExtensionTargets ImportGroup

```xml
<ImportGroup Label="ExtensionTargets" />
```

Esse grupo contém importações para os arquivos de destino de personalização de compilação.

## <a name="impact-of-incorrect-ordering"></a>Impacto de ordenação incorreta

O Visual Studio IDE depende do arquivo de projeto com que a ordenação descrita acima. Por exemplo, quando você define um valor de propriedade nas páginas de propriedades, o IDE geralmente colocará a definição da propriedade no grupo de propriedades com o rótulo vazio. Isso garante que os valores padrão colocados nas folhas de propriedade de sistema são substituídos por valores definidos pelo usuário. Da mesma forma, os arquivos de destino são importados no final, desde que eles consomem as propriedades definidas acima e como eles geralmente não definem propriedades próprias. Da mesma forma, folhas de propriedade do usuário são importadas após as folhas de propriedades do sistema (incluído por meio de **Microsoft.Cpp.props**). Isso garante que o usuário pode substituir os padrões obtidos pelas folhas de propriedades do sistema.

Se um arquivo. vcxproj não segue este layout, os resultados de compilação não podem ser o esperado. Por exemplo, se você por engano importar uma folha de propriedades do sistema após as folhas de propriedades definidas pelo usuário, as configurações do usuário serão substituídas pelas folhas de propriedades do sistema.

Até mesmo a experiência de tempo de design IDE depende até certo ponto correto a ordenação dos elementos. Por exemplo, se o arquivo. vcxproj não tem o `PropertySheets` grupo de importação, o IDE não consiga determinar onde colocar uma folha de propriedades que o usuário foi criado no **Gerenciador de propriedades**. Isso pode resultar em uma tabela de usuário que está sendo substituída por uma folha de sistema. Embora a heurística usada pelo IDE pode tolerar pequenas inconsistências no layout do arquivo. vcxproj, ele é altamente recomendável não desviar da estrutura de mostrado anteriormente neste artigo.

## <a name="how-the-ide-uses-element-labels"></a>Como o IDE usa rótulos de elemento

No IDE, quando você define o **UseOfAtl** propriedade na página de propriedades geral, escrito para o grupo de propriedades de configuração no arquivo de projeto, enquanto o **TargetName** propriedade na mesma página de propriedade é gravado para o grupo de propriedade sem nome por configuração. O Visual Studio examina o arquivo de xml da página de propriedade para obter as informações sobre onde cada propriedade de gravação. Para o **geral** página de propriedades (supondo que você tem uma versão em inglês do Visual Studio Enterprise Edition), esse arquivo é `%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets\1033\general.xml`. O arquivo de regra XML de página de propriedade define as informações estáticas sobre uma regra e todas as suas propriedades. Uma essa informação é a posição preferencial de uma propriedade de regra no arquivo de destino (o arquivo em que seu valor será gravado). A posição preferencial é especificada pelo atributo rótulo dos elementos de arquivo de projeto.

## <a name="property-sheet-layout"></a>Layout da folha de propriedade

O trecho XML a seguir é um layout mínimo de um arquivo de folha (.props) de propriedade. Ele é semelhante a um arquivo. vcxproj e a funcionalidade dos elementos .props pode ser inferida a partir da discussão anterior.

```xml
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ImportGroup Label="PropertySheets" />
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup />
  <ItemDefinitionGroup />
  <ItemGroup />
</Project>
```

Para tornar sua própria folha de propriedades, copie um dos arquivos .props na pasta VCTargets e modificá-lo para suas finalidades. Para a edição do Visual Studio Enterprise de 2017, o caminho padrão do VCTargets é `%ProgramFiles%\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets`.

## <a name="see-also"></a>Consulte também

[Trabalhando com Propriedades do Projeto](working-with-project-properties.md)  
[Arquivos XML de página de propriedade](property-page-xml-files.md)  
