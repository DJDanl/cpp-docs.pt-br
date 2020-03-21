---
title: Arquivos vcxproj. Filters
ms.date: 09/25/2019
description: Usar arquivos de filtros em projetos C++ do Visual Studio para definir pastas lógicas personalizadas para arquivos no Gerenciador de soluções
helpviewer_keywords:
- vcxproj.filters
- filters file [C++]
ms.openlocfilehash: bdf40708a70d841cb3d3144fa8fa73a71e9e9ef2
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078275"
---
# <a name="vcxprojfilters-files"></a>Arquivos vcxproj. Filters

O arquivo de *filtros* (\*. vcxproj. Filters) é um arquivo XML no formato MSBuild localizado na pasta raiz do projeto. Especifica quais tipos de arquivo são inseridos em qual pasta lógica em **Gerenciador de soluções**. Na ilustração a seguir, os arquivos *. cpp* estão no nó **arquivos de origem** . os arquivos *. h* estão no nó **arquivos de cabeçalho** e os arquivos *. ico* e *. rc* estão em **arquivos de recurso**. Esse posicionamento é controlado pelo arquivo de filtros.

![Pastas lógicas no Gerenciador de Soluções](media/solution-explorer-filters.png)

## <a name="creating-a-custom-filters-file"></a>Criando um arquivo de filtros personalizados

O Visual Studio cria esse arquivo automaticamente. Para aplicativos de área de trabalho, as pastas lógicas predefinidas (filtros) são: **arquivos de origem**, **arquivos de cabeçalho** e arquivos de **recurso**. Outros tipos de projeto, como UWP, podem ter um conjunto diferente de pastas padrão. O Visual Studio atribui automaticamente tipos de arquivo conhecidos a cada pasta. Se você quiser criar um filtro com um nome personalizado ou um filtro que contém tipos de arquivo personalizados, poderá criar seu próprio arquivo de filtros na pasta raiz do projeto ou em um filtro existente. (**Referências** e **dependências externas** são pastas especiais que não participam da filtragem.)

## <a name="example"></a>Exemplo

O exemplo a seguir mostra o arquivo de filtros para o exemplo mostrado anteriormente. Ele tem uma hierarquia simples; em outras palavras, não há pastas lógicas aninhadas. O nó `UniqueIdentifier` é opcional. Ele permite que as interfaces de automação do Visual Studio encontrem o filtro. `Extensions` também é opcional. Quando um novo arquivo é adicionado a um projeto, ele é adicionado ao filtro de nível superior com uma extensão de arquivo correspondente. Para adicionar um arquivo a um filtro específico, clique com o botão direito do mouse no filtro e escolha **Adicionar novo item**.

O `ItemGroup` que contém os nós `ClInclude` é criado quando o projeto é iniciado pela primeira vez. Se você estiver gerando seus próprios arquivos vcxproj, certifique-se de que todos os itens de projeto também tenham uma entrada no arquivo de filtros. Os valores em um nó de `ClInclude` substituem a filtragem padrão com base em extensões de arquivo. Quando você usar o Visual Studio para adicionar um novo item ao projeto, o IDE adicionará uma entrada de arquivo individual no arquivo de filtros. O filtro não será reatribuído automaticamente se você alterar a extensão do arquivo.

```xml
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <Filter Include="Source Files">
      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>
      <Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions>
    </Filter>
    <Filter Include="Header Files">
      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>
      <Extensions>h;hh;hpp;hxx;hm;inl;inc;ipp;xsd</Extensions>
    </Filter>
    <Filter Include="Resource Files">
      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>
      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="MFCApplication1.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="MFCApplication1Dlg.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="stdafx.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="targetver.h">
      <Filter>Header Files</Filter>
    </ClInclude>
    <ClInclude Include="Resource.h">
      <Filter>Header Files</Filter>
    </ClInclude>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="MFCApplication1.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="MFCApplication1Dlg.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
    <ClCompile Include="stdafx.cpp">
      <Filter>Source Files</Filter>
    </ClCompile>
  </ItemGroup>
  <ItemGroup>
    <ResourceCompile Include="MFCApplication1.rc">
      <Filter>Resource Files</Filter>
    </ResourceCompile>
  </ItemGroup>
  <ItemGroup>
    <None Include="res\MFCApplication1.rc2">
      <Filter>Resource Files</Filter>
    </None>
  </ItemGroup>
  <ItemGroup>
    <Image Include="res\MFCApplication1.ico">
      <Filter>Resource Files</Filter>
    </Image>
  </ItemGroup>
</Project>
```

Para criar pastas lógicas aninhadas, declare todos os nós em filtros `ItemGroup` conforme mostrado abaixo. Cada nó filho deve declarar o caminho lógico completo para o pai superior. No exemplo a seguir, uma `ParentFilter` vazia deve ser declarada porque é referenciada em nós posteriores.

```xml
  <ItemGroup>
    <Filter Include="ParentFilter">
    </Filter>
    <Filter Include="ParentFilter\Source Files"> <!-- Full path to topmost parent.-->  
      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier> <!--  Optional-->
      <Extensions>cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx</Extensions> <!-- Optional -->
    </Filter>
    <Filter Include="Header Files">
      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>
      <Extensions>h;hh;hpp;hxx;hm;inl;inc;ipp;xsd</Extensions>
    </Filter>
  </ItemGroup>
```
