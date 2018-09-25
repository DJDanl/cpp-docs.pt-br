---
title: Arquivos de regras XML da página de propriedades | Microsoft Docs
ms.custom: ''
ms.date: 04/27/2017
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- property page XML files
ms.assetid: dd9d9734-4387-4098-8ba6-85b93507731d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 28751a1e672c7b5dfcefe5f24a9248c9ded5ad82
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46383670"
---
# <a name="property-page-xml-rule-files"></a>Arquivos de regra XML da Página de Propriedades

As páginas de propriedades do projeto no IDE são configuradas por arquivos XML na pasta VCTargets. O caminho exato depende de quais edições do Visual Studio estão instaladas e do idioma do produto. Para o Visual Studio 2017 Enterprise Edition em inglês, o caminho é `%ProgramFiles%\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets\1033`. Os arquivos XML descrevem os nomes das regras, as categorias e as propriedades individuais, seu tipo de dados, valores padrão e como eles devem ser exibidos. Quando você define uma propriedade no IDE, o novo valor é armazenado no arquivo de projeto.

Os únicos cenários nos quais você precisa entender o funcionamento interno desses arquivos e do IDE do Visual Studio são quando (a) você deseja criar uma página de propriedades personalizada ou quando (b) você deseja personalizar as propriedades do projeto de uma maneira diferente por meio do IDE do Visual Studio.

Primeiro, vamos abrir as páginas de propriedades de um projeto (clique com o botão direito do mouse no nó do projeto no **Gerenciador de Soluções** e escolha Propriedades):

![Propriedades de projeto do Visual C++](media/cpp-property-page-2017.png)

Cada nó em **Propriedades de Configuração** é chamado de Regra. Às vezes, uma Regra representa uma única ferramenta como o compilador, mas, em geral, o termo se refere a algo que tem propriedades, que é executado e que pode produzir uma saída. Cada regra é populada com um arquivo XML na pasta VCTargets. Por exemplo, a regra do C/C++ mostrada acima é populada por 'cl.xml'.

Conforme mostrado acima, cada Regra tem um conjunto de propriedades que são organizadas em categorias. Cada subnó em uma Regra representa uma categoria. Por exemplo, o nó Otimização no C/C++ contém todas as propriedades relacionadas à otimização da ferramenta de compilador. As propriedades e seus próprios valores são renderizados em um formato de grade no painel direito.

Abra cl.xml no Bloco de notas ou em qualquer editor de XML (veja o instantâneo abaixo). Você verá um nó raiz chamado Rule que tem a mesma lista de propriedades definida nele, da mesma forma como é exibido na interface do usuário, junto com metadados adicionais.

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
...
```

Há um arquivo XML correspondente a cada nó em Propriedades de Configuração na interface do usuário das páginas de propriedades. Adicione ou remova as regras na interface do usuário, incluindo ou removendo locais para arquivos XML correspondentes no projeto. Por exemplo, é assim como Microsoft.CppBuild.targets (um nível acima da pasta 1033) inclui cl.xml:

```xml
<PropertyPageSchema Condition="'$(ConfigurationType)' != 'Utility'" Include="$(VCTargetsPath)$(LangID)\cl.xml"/>
```

Se você remover todos os dados de cl.xml, acabará com o seguinte esqueleto:

```xml
<?xml version="1.0" encoding="utf-8"?>
<Rule>
  <Rule.DataSource />
  <Rule.Categories>
    <Category />
        ...
  </Rule.Categories>
  <BoolProperty />
  <EnumProperty />
  <IntProperty />
  <StringProperty />
  <StringListProperty />
</Rule>
```

A seção a seguir descreve todos os elementos principais e alguns dos metadados que podem ser anexados a eles.

1. **Rule:** geralmente, Rule é o nó raiz no arquivo XML; pode ter muitos atributos:

    ```xml
    <Rule Name="CL" PageTemplate="tool" SwitchPrefix="/" Order="10"
              xmlns="http://schemas.microsoft.com/build/2009/properties"
              xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
              xmlns:sys="clr-namespace:System;assembly=mscorlib">
      <Rule.DisplayName>
        <sys:String>C/C++</sys:String>
      </Rule.DisplayName>
    ```

   a. **Name:** o atributo Name é uma ID para a Rule. Precisa ser exclusivo entre todos os arquivos XML da página de propriedades de um projeto.

   b. **PageTemplate:** o valor desse atributo é usado pela interface do usuário para a escolha de um item em uma coleção de modelos de interface do usuário. O modelo de "ferramenta" renderiza as propriedades em um formato de grade padrão. Outros valores internos para esse atributo são "depurador" e "genérico". Veja os nós Depuração e Geral, respectivamente, para ver o formato de interface do usuário resultante da especificação desses valores. A interface do usuário do modelo de página "depurador" usa uma caixa suspensa para alternar entre as propriedades de diferentes depuradores, enquanto o modelo "genérico" exibe categorias de diferentes propriedades em uma única página, em vez de ter vários subnós de categoria abaixo do nó Rule. Esse atributo é apenas uma sugestão para a interface do usuário; o arquivo XML foi projetado para ser independente de interface do usuário. Outra interface do usuário pode usar esse atributo para diferentes finalidades.

   c. **SwitchPrefix:** esse é o prefixo usado na linha de comando para as opções. Um valor igual a "/" resulta em opções semelhantes a /ZI, /nologo, /W3, etc.

   d. **Order:** essa é uma sugestão para um cliente potencial de interface do usuário no local relativo dessa Regra em comparação com todas as outras Regras do sistema.

   e. **xmlns:** esse é um elemento XAML padrão. É possível ver três namespaces listados. Eles correspondem aos namespaces para as classes de desserialização de XAML, o esquema XAML e o namespace do sistema, respectivamente.

   f. **DisplayName:** esse é o nome mostrado na interface do usuário da página de propriedades para o nó Rule. Esse valor está localizado. Criamos DisplayName como um elemento filho de Rule, em vez de um atributo (como Name ou SwitchPrefix) devido aos requisitos da ferramenta de localização interna. Da perspectiva do XAML, ambos são equivalentes. Portanto, basta torná-lo um atributo para reduzir a desordem ou deixá-lo como é.

   g. **DataSource:** essa é uma propriedade muito importante que informa ao sistema do projeto o local do qual o valor da propriedade deve ser lido e no qual ele deve ser gravado, bem como seu agrupamento (explicado abaixo). Para cl.xml, estes valores são:

      ```xml
      <DataSource Persistence="ProjectFile" ItemType="ClCompile" Label="" HasConfigurationCondition="true" />
      ```

   - `Persistence="ProjectFile` informa o sistema do projeto que todas as propriedades para a Rule devem ser gravadas no arquivo de projeto ou no arquivo de folha de propriedades (dependendo de qual nó foi usado para gerar as páginas de propriedades). O outro valor possível é "UserFile", que gravará o valor no arquivo .user.

   - `ItemType="ClCompile"` indica que as propriedades serão armazenadas como metadados de ItemDefinition ou metadados de item (o último somente ocorrerá se as páginas de propriedades foram geradas com base em um nó de arquivo no Gerenciador de Soluções) desse tipo de item. Se esse campo não é definido, a propriedade é gravada como uma propriedade comum em um PropertyGroup.

   - `Label=""` indica que quando as propriedades forem gravadas como metadados de `ItemDefinition`, o rótulo do ItemDefinitionGroup pai ficará vazio (cada elemento do MSBuild pode ter um Rótulo). O Visual Studio 2017 usa grupos rotulados para navegar pelo arquivo de projeto .vcxproj. Observe que os grupos que contêm a maioria das propriedades de Rule têm uma cadeia de caracteres vazia como rótulo.

   - `HasConfigurationCondition="true"` instrui o sistema do projeto a afixar uma condição de configuração ao valor, de modo que ele entre em vigor apenas na configuração do projeto atual (a condição pode ser afixada ao grupo pai ou ao próprio valor). Por exemplo, abra as páginas de propriedades do nó do projeto e defina o valor da propriedade **Tratar Avisos como Erros** em **Propriedades de Configuração > Geral do C/C++** como "Sim". O valor a seguir é gravado no arquivo de projeto. Observe a condição de configuração anexada ao ItemDefinitionGroup pai.

      ```xml
      <ItemDefinitionGroup Condition="‘$(Configuration)|$(Platform)’==’Debug|Win32’">
        <ClCompile>
          <TreatWarningAsError>true</TreatWarningAsError>
        </ClCompile>
      </ItemDefinitionGroup>
      ```

      Se esse valor for definido na página de propriedades de um arquivo específico, como stdafx.cpp, o valor da propriedade será gravado sob o item stdafx.cpp no arquivo de projeto, conforme mostrado abaixo. Observe como a condição de configuração está diretamente anexada aos próprios metadados.

      ```xml
      <ItemGroup>
        <ClCompile Include="stdafx.cpp">
          <TreatWarningAsError Condition="‘$(Configuration)|$(Platform)’==’Debug|Win32’">true</TreatWarningAsError>
        </ClCompile>
      </ItemGroup>
      ```

   Outro atributo de **DataSource** não listado acima é **PersistedName**. Use esse atributo para representar uma propriedade no arquivo de projeto usando outro nome. Por padrão, esse atributo é definido com o **Name** da propriedade.

   Uma propriedade individual pode substituir a DataSource da Regra pai. Nesse caso, o local para o valor da propriedade será diferente das outras propriedades na Rule.

   h. Há outros atributos de uma Rule, como Description, SupportsFileBatching, etc., que não são mostrados aqui. Obtenha o conjunto completo de atributos aplicáveis a uma Rule ou a qualquer outro elemento navegando pela documentação desses tipos. Como alternativa, você pode examinar as propriedades públicas nos tipos no namespace `Microsoft.Build.Framework.XamlTypes` do assembly `Microsoft.Build.Framework .dll`.

   i. **DisplayName**, **PageTemplate** e **Order** são propriedades relacionadas à interface do usuário que estão presentes nesse modelo de dados, de outro modo, independente de interface do usuário. Quase certamente, essas propriedades serão usadas por qualquer interface do usuário usada para exibir as páginas de propriedades. **DisplayName** e **Description** são duas propriedades que estão presentes em quase todos os elementos do arquivo XML. Essas são as únicas duas propriedades que são localizadas (a localização dessas cadeias de caracteres será explicada em uma postagem posterior).

1. **Category:** uma Regra pode ter várias Categorias. A ordem na qual as categorias são listadas no arquivo XML é uma sugestão para que a interface do usuário exiba as categorias na mesma ordem. Por exemplo, a ordem das categorias no nó do C/C++, conforme visto na Interface do Usuário – Geral, Otimização, Pré-processador, etc.  – é a mesma que em cl.xml. Uma categoria de exemplo tem esta aparência:

    ```xml
    <Category Name="Optimization">
      <Category.DisplayName>
        <sys:String>Optimization</sys:String>
      </Category.DisplayName>
    </Category>
    ```

   O snippet acima mostra os atributos **Name** e **DisplayName** descritos antes. Novamente, há outros atributos que uma **Categoria** pode ter que não são usados acima. Saiba mais sobre eles lendo a documentação ou examinando os assemblies usando ildasm.exe.

1. **Properties:** essa é a parte principal do arquivo XML e contém a lista de todas as propriedades nessa Rule. Cada propriedade pode ter um dos cinco tipos possíveis mostrados no esqueleto de XAML acima. Naturalmente, você pode ter apenas alguns desses tipos em seu arquivo. Uma propriedade tem diversos atributos que permitem que ela seja descrita de maneira sofisticada. Explicaremos apenas a **StringProperty** aqui. O restante é muito parecido.

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

   A maioria dos atributos no snippet foi descrita antes. Os novos são Subtype, Category e Switch.

   a. **Subtype** é um atributo disponível somente para **StringProperty** e **StringListProperty**; fornece informações contextuais. Por exemplo, o valor de "file" indica que a propriedade representa um caminho de arquivo. Essas informações contextuais são usadas para aprimorar a experiência de edição, fornecendo um Windows Explorer como o editor da propriedade que permite ao usuário escolher o arquivo visualmente.

   b. **Categoria:** Isso declara a categoria na qual essa propriedade se enquadra. Tente encontrar essa propriedade na categoria **Arquivos de Saída** na interface do usuário.

   c. **Switch:** quando uma Rule representa uma ferramenta – como a ferramenta de compilador, nesse caso – a maioria das propriedades da Rule é passada como opções para o executável da ferramenta no momento do build. O valor desse atributo indica o literal de opção a ser usado. A propriedade acima especifica que sua opção deve ser **Fo**. Combinada com o atributo **SwitchPrefix** na Rule pai, essa propriedade é passada para o executável como **/Fo"Debug\"** (visível na linha de comando para o C/C++ na interface do usuário da página de propriedades).

   Outros atributos de propriedade incluem:

   d. **Visible:** se, por algum motivo, você não deseja que a propriedade seja exibida nas páginas de propriedades (mas provavelmente ainda esteja disponível no momento do build), defina esse atributo como falso.

   e. **ReadOnly:** caso deseje fornecer uma exibição somente leitura do valor dessa propriedade nas páginas de propriedades, defina esse atributo como verdadeiro.

   f. **IncludeInCommandLine:** talvez algumas propriedades não precisem ser passadas para uma ferramenta no momento do build. A definição desse atributo como falso impedirá que ele seja passado.
