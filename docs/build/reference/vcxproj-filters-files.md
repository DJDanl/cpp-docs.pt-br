---
title: Vcxproj.filtros arquivos
ms.date: 09/25/2019
description: Use arquivos de filtros em projetos Do Visual Studio C++ para definir pastas lógicas personalizadas para arquivos no Solution Explorer
helpviewer_keywords:
- vcxproj.filters
- filters file [C++]
ms.openlocfilehash: 57735246b543680243994b99b8c05c9ad1211f38
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335940"
---
# <a name="vcxprojfilters-files"></a>vcxproj.filtros arquivos

O arquivo de\* *filtros* (.vcxproj.filters) é um arquivo XML no formato MSBuild que está localizado na pasta de projeto raiz. Ele especifica quais tipos de arquivo entram em qual pasta lógica no **Solution Explorer**. Na ilustração a seguir, os arquivos *.cpp* estão sob o nó **Arquivo de** origem. os arquivos *.h* estão sob o nó **'Arquivos de cabeçalho'** e *arquivos .ico* e *.rc* estão em **Arquivos de recursos**. Esta colocação é controlada pelo arquivo de filtros.

![Pastas lógicas no Solution Explorer](media/solution-explorer-filters.png)

## <a name="creating-a-custom-filters-file"></a>Criando um arquivo de filtros personalizado

O Visual Studio cria esse arquivo automaticamente. Para aplicativos de desktop, as pastas lógicas predefinidas (filtros) são: **Arquivos de origem,** **arquivos de cabeçalho** e **arquivos de recursos**. Outros tipos de projeto, como o UWP, podem ter um conjunto diferente de pastas padrão. O Visual Studio atribui automaticamente tipos de arquivos conhecidos a cada pasta. Se você quiser criar um filtro com um nome personalizado ou um filtro que possua tipos de arquivo personalizados, você pode criar seu próprio arquivo de filtros na pasta raiz do projeto, ou sob um filtro existente. (**Referências** e **Dependências Externas** são pastas especiais que não participam da filtragem.)

## <a name="example"></a>Exemplo

O exemplo a seguir mostra o arquivo filtros para o exemplo mostrar anteriormente. Tem uma hierarquia plana; em outras palavras, não há pastas lógicas aninhadas. O nó `UniqueIdentifier` é opcional. Ele permite que as interfaces de automação do Visual Studio encontrem o filtro. `Extensions`também é opcional. Quando um novo arquivo é adicionado a um projeto, ele é adicionado ao filtro mais superior com uma extensão de arquivo correspondente. Para adicionar um arquivo a um filtro específico, clique com o botão direito do mouse no filtro e escolha **Adicionar novo item**.

O `ItemGroup` que `ClInclude` contém os nós é criado quando o projeto é lançado pela primeira vez. Se você estiver gerando seus próprios arquivos vcxproj, certifique-se de que todos os itens do projeto também tenham uma entrada no arquivo de filtros. Os valores em um `ClInclude` nó anulam a filtragem padrão com base em extensões de arquivo. Quando você usa o Visual Studio para adicionar um novo item ao projeto, o IDE adicionará uma entrada de arquivo individual no arquivo de filtros. O filtro não é reatribuído automaticamente se você alterar a extensão do arquivo.

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

Para criar pastas lógicas aninhadas, `ItemGroup` declare todos os nós em filtros como mostrado abaixo. Cada nó de criança deve declarar o caminho lógico completo para o pai mais alto. No exemplo a seguir, um vazio `ParentFilter` deve ser declarado porque é referenciado em nós posteriores.

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
