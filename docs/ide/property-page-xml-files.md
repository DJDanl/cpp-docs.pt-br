---
title: Arquivos de propriedade de regras XML Page | Microsoft Docs
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
ms.openlocfilehash: fcee2c416fba6a959785826781aefd96b0d06d75
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="property-page-xml-rule-files"></a>Arquivos de propriedade de regras Page XML
As páginas de propriedades do projeto no IDE são configuradas por arquivos XML na pasta VCTargets. O caminho exato depende de qual edition(s) do Visual Studio está instalados e o idioma do produto. Para o Visual Studio 2017 Enterprise Edition em inglês, o caminho é `%ProgramFiles%\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets\1033`. Os arquivos XML descrevem os nomes das regras, as categorias e as propriedades individuais, seu tipo de dados, valores padrão e como eles devem ser exibidos. Quando você definir uma propriedade no IDE, o novo valor é armazenado no arquivo de projeto.

Os cenários somente em que você precisa entender que o funcionamento interno desses arquivos e o IDE do Visual Studio é (a) você deseja criar uma página de propriedade personalizada, ou (b) que deseja personalizar suas propriedades de projeto de alguma maneira diferente por meio do IDE do Visual Studio. 

Primeiro, vamos abrir as páginas de propriedade para um projeto (clique com o botão direito no nó do projeto no **Solution Explorer** e escolha Propriedades):
   
![Propriedades de projeto do Visual C++](media/cpp-property-page-2017.png)

Cada nó em **propriedades de configuração** é chamado de regra. Uma regra, às vezes, representa uma única ferramenta como o compilador, mas em geral o termo se refere a algo que tem propriedades, que é executado e que pode gerar algumas saídas. Cada regra é preenchida com um arquivo xml na pasta VCTargets. Por exemplo, a regra de C/C++ que é mostrada acima é preenchida por 'cl.xml'.

Como mostrado acima, cada regra tem um conjunto de propriedades que são organizados em categorias. Cada nó sub em uma regra representa uma categoria. Por exemplo, o nó de otimização em C/C++ contém todas as propriedades relacionadas à otimização da ferramenta do compilador. As propriedades e seus próprios valores são renderizados em um formato de grade no painel direito.

Você pode abrir cl.xml no bloco de notas ou qualquer editor de XML (veja abaixo de instantâneo). Você verá um nó raiz chamado regra que tem a mesma lista de propriedades definidas sob ele, como é exibido na interface do usuário, junto com os metadados adicionais.

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

Há um arquivo XML correspondente a cada nó nas propriedades de configuração nas páginas de propriedades da interface do usuário. Você pode adicionar ou remover as regras na interface de usuário, incluindo ou removendo locais para arquivos XML correspondentes no projeto. Por exemplo, isso é como Microsoft.CppBuild.targets (um nível acima da pasta 1033) inclui cl.xml:

```xml  
<PropertyPageSchema Condition="'$(ConfigurationType)' != 'Utility'" Include="$(VCTargetsPath)$(LangID)\cl.xml"/>

``` 
Se você remover cl.xml de todos os dados, você acabará com a seguinte estrutura:
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

1. **Regra:** regra geralmente é o nó raiz no arquivo xml; ele pode ter muitos atributos:

```xml    
<Rule Name="CL" PageTemplate="tool" SwitchPrefix="/" Order="10"
          xmlns="http://schemas.microsoft.com/build/2009/properties"
          xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
          xmlns:sys="clr-namespace:System;assembly=mscorlib">
  <Rule.DisplayName>
    <sys:String>C/C++</sys:String>
  </Rule.DisplayName>
```  

   a. **Nome:** o atributo Name é uma id para a regra. Ele precisa ser exclusivo entre todos os propriedade página arquivos xml para um projeto.

   b. **PageTemplate:** o valor desse atributo é usado pela interface do usuário para escolha de uma coleção de modelos de interface do usuário. O modelo de "ferramenta" renderiza as propriedades em um formato de grade padrão. Outros valores interno para este atributo são "depurador" e "genérico". Consulte o nó de depuração e o nó geral, respectivamente, para ver o formato de interface do usuário resultante de especificar esses valores. A interface do usuário para o modelo de página "depurador" usa uma caixa de lista suspensa para alternar entre as propriedades diferentes depuradores enquanto o modelo "genérico" exibe categorias de propriedades diferentes em uma única página, em oposição a ter vários nós de subgrupos de categoria na regra nó. Esse atributo é apenas uma sugestão para a interface do usuário; o arquivo xml é projetado para ser independente de interface do usuário. Uma interface de usuário diferente pode usar esse atributo para finalidades diferentes.

  c. **SwitchPrefix:** esse é o prefixo usado na linha de comando para as opções. Um valor de "/" resultaria em opções que se parecem com /ZI, /nologo, /W3, etc.

  d. **Ordem:** isso é uma sugestão para um cliente potencial da interface do usuário o local relativo dessa regra em comparação comparada todas as outras regras do sistema.

  e. **xmlns:** é um elemento XAML padrão. Você pode ver três namespaces listados. Eles correspondem aos namespaces para a desserialização de XAML classes, de sistema e esquema do namespace XAML, respectivamente.

  f. **DisplayName:** esse é o nome que é mostrado na página de propriedades da interface do usuário para o nó de regra. Esse valor está localizado. Nós criamos DisplayName como um elemento filho de regra em vez de um atributo (como nome ou SwitchPrefix) devido à localização interno requisitos da ferramenta. Da perspectiva do XAML, ambos são equivalentes. Assim, você pode apenas ser um atributo para reduzir a desordem ou deixe-a como é.

  g. **Fonte de dados:** esta é uma propriedade muito importante que informa ao sistema de projeto, o local do qual o valor da propriedade deve ler e gravados e o agrupamento (explicado abaixo). Para cl.xml, esses valores são:

```xml  
       <DataSource Persistence="ProjectFile" ItemType="ClCompile" Label="" HasConfigurationCondition="true" />
```  
   - `Persistence="ProjectFile` informa o sistema do projeto que todas as propriedades para a regra devem ser gravadas no arquivo de projeto ou o arquivo de folha de propriedades (dependendo de qual nó foi usado para gerar as páginas de propriedade). O outro valor possível é "UserFile", que gravará o valor para o arquivo. User.

   - `ItemType="ClCompile"` diz que as propriedades serão armazenadas como metadados de ItemDefinition ou metadados de item (o último somente se as páginas de propriedade foram geradas de um nó de arquivo no Gerenciador de soluções) desse tipo de item. Se esse campo não for definido, a propriedade é gravada como uma propriedade comum em um PropertyGroup.

   - `Label=""` indica que quando as propriedades são gravadas como `ItemDefinition` metadados, o rótulo do pai ItemDefinitionGroup estará vazio (todos os elementos de MSBuild podem ter um rótulo). 2017 do Visual Studio usa grupos de rotulado para navegar o arquivo de projeto. vcxproj. Observe que os grupos que contêm a maioria das propriedades de regra tem uma cadeia de caracteres vazia como um rótulo.

   - `HasConfigurationCondition="true"` informa ao sistema de projeto para fixar uma condição de configuração para o valor para que ele entra em vigor apenas para a configuração do projeto atual (a condição pode ser afixada ao grupo pai ou o próprio valor). Por exemplo, abra as páginas de propriedade do nó do projeto e defina o valor da propriedade **tratar avisos como erros** em **propriedades de configuração > geral do C/C++** para "Sim". O seguinte valor é gravado no arquivo de projeto. Observe que a condição de configuração anexado ao ItemDefinitionGroup pai.

```xml  
     <ItemDefinitionGroup Condition="‘$(Configuration)|$(Platform)’==’Debug|Win32’">
        <ClCompile>
           <TreatWarningAsError>true</TreatWarningAsError>
        </ClCompile>
     </ItemDefinitionGroup>
 ```
   Se esse valor foi definido na página de propriedades de um arquivo específico, como stdafx.cpp, o valor da propriedade deve ser gravado sob o item stdafx.cpp no arquivo de projeto, conforme mostrado abaixo. Observe como a condição de configuração está diretamente conectada aos metadados em si.

 ```xml  
<ItemGroup>
   <ClCompile Include="stdafx.cpp">
      <TreatWarningAsError Condition="‘$(Configuration)|$(Platform)’==’Debug|Win32’">true</TreatWarningAsError>
   </ClCompile>
</ItemGroup>
 ```
   Outro atributo de **DataSource** não listadas acima é **PersistedName**. Você pode usar esse atributo para representar uma propriedade no arquivo de projeto usando um nome diferente. Por padrão, esse atributo é definido como a propriedade **nome**. 

   Uma propriedade individual pode substituir a fonte de dados da regra pai. Nesse caso, o local para o valor da propriedade será diferente de outras propriedades na regra.

   h. Há outros atributos que não são mostrados aqui de uma regra, como descrição, SupportsFileBatching, etc. O conjunto completo de atributos aplicáveis a uma regra ou em qualquer outro elemento pode ser obtido navegando a documentação para esses tipos. Como alternativa, você pode examinar as propriedades públicas nos tipos no `Microsoft.Build.Framework.XamlTypes` namespace o `Microsoft.Build.Framework .dll` assembly.

   i. **DisplayName**, **PageTemplate**, e **ordem** são propriedades relacionadas à interface do usuário que estão presentes neste caso contrário o modelo de dados independente da interface do usuário. Essas propriedades são quase certas a ser usado por qualquer interface de usuário que é usado para exibir as páginas de propriedades. **DisplayName** e **descrição** são duas propriedades que estão presentes em quase todos os elementos no arquivo xml. E estes são apenas duas propriedades que são localizadas (localização dessas cadeias de caracteres será explicada em uma postagem posterior).

2.  **Categoria:** uma regra pode ter várias categorias. A ordem na qual as categorias são listadas no arquivo xml é uma sugestão para a interface do usuário para exibir as categorias na mesma ordem. Por exemplo, a ordem das categorias de sob o nó C/C++, como mostrado na interface do usuário – geral, a otimização, pré-processador,...  – é o mesmo que cl.xml em. Uma categoria de exemplo tem esta aparência:

```xml  
 <Category Name="Optimization">
    <Category.DisplayName>
        <sys:String>Optimization</sys:String>
    </Category.DisplayName>
 </Category>
```
Mostra o trecho acima de **nome** e **DisplayName** atributos que foi descritos antes. Uma vez, há outros atributos de um **categoria** pode ter que não são usados acima. Você pode saber sobre elas ao ler a documentação ou examinando os assemblies usando ildasm.exe.

3. **Propriedades:** essa é a parte principal do arquivo xml e contém a lista de todas as propriedades nesta regra. Cada propriedade pode ser um dos cinco tipos possíveis mostrados o esqueleto do XAML acima. Naturalmente, você pode ter apenas alguns desses tipos em seu arquivo. Uma propriedade tem um número de atributos que permitem que sejam descritos sofisticada. Explicaremos apenas o **StringProperty** aqui. O restante são muito semelhantes.

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
A maioria dos atributos no trecho ter foi descrita antes. Os novos são subtipo, categoria e o comutador.

   a. **Subtipo** um atributo só está disponível para **StringProperty** e **StringListProperty**; ele fornece informações contextuais. Por exemplo, o valor de "file" indica que a propriedade representa um caminho de arquivo. Tais informações contextuais são usadas para aprimorar a experiência de edição, fornecendo o Windows Explorer como do editor a propriedade que permite ao usuário escolher o arquivo visualmente.

   b. **Categoria:** Isso declara a categoria sob a qual esta propriedade cai. Tenta encontrar essa propriedade sob o **arquivos de saída** categoria na interface de usuário.

   c. **Comutador:** quando uma regra representa uma ferramenta – como a ferramenta de compilador nesse caso, a maioria das propriedades da regra são passados como opções para a ferramenta executável durante o tempo de compilação. O valor deste atributo indica a opção literal a ser usado. A propriedade acima Especifica que o seu comutador deve ser **Fo**. Combinado com o **SwitchPrefix** atributo do pai de regra, essa propriedade é passado para o executável como **/Fo "depurar\"**  (visível na linha de comando para C/C++ na página de propriedades da interface do usuário).

   Outros atributos de propriedade incluem:

   d. **Visível:** se por algum motivo, você não deseja que sua propriedade aparecem nas páginas de propriedades (mas provavelmente ainda estará disponível durante o tempo de compilação), defina este atributo como false.

   e. **Somente leitura:** se você deseja fornecer uma exibição somente leitura do valor desta propriedade nas páginas de propriedades, defina este atributo como true.

   f. **IncludeInCommandLine:** algumas propriedades talvez não precise ser passado para uma ferramenta durante o tempo de compilação. Definir esse atributo como false impede que ele está sendo passado.


