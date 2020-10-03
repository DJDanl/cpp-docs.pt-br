---
title: arquivos. vcxproj e curingas
description: Como os arquivos System. vcxproj de projeto do MSBuild nativo do C++ manipulam curingas.
ms.date: 09/30/2020
helpviewer_keywords:
- .vcxproj file structure
ms.assetid: 14d0c552-29db-480e-80c1-7ea89d6d8e9c
ms.openlocfilehash: 23d36a63f328e14cca59d1d57838173b4dcb0954
ms.sourcegitcommit: f7fbdc39d73e1fb3793c396fccf7a1602af7248b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2020
ms.locfileid: "91662875"
---
# <a name="vcxproj-files-and-wildcards"></a>`.vcxproj` arquivos e curingas

O IDE do Visual Studio não dá suporte a determinadas construções em itens de projeto em *`.vcxproj`* arquivos. Essas construções sem suporte incluem curingas, listas delimitadas por ponto e vírgula ou macros do MSBuild que expandem para vários arquivos. O `.vcxproj` sistema de projeto para compilações do C++ é mais restritivo do que o MSBuild. Cada item de projeto é necessário para ter seu próprio item do MSBuild. Para obter mais informações sobre o `.vcxproj` formato de arquivo, consulte [ `.vcxproj` e `.props` estrutura de arquivos](vcxproj-file-structure.md).

Esses exemplos de construção não são suportados pelo IDE:

```xml
<ItemGroup>
  <None Include="*.txt">
  <ClCompile Include="a.cpp;b.cpp"/>
  <ClCompile Include="@(SomeItems)" />
</ItemGroup>
```

Se um `.vcxproj` arquivo de projeto que inclui essas construções for carregado no IDE, o projeto pode parecer funcionar a princípio. No entanto, os problemas são prováveis assim que o projeto é modificado pelo Visual Studio e, em seguida, salvo em disco. Você pode experimentar falhas aleatórias e um comportamento indefinido.

No Visual Studio 2019 versão 16,7, quando o Visual Studio carrega um `.vcxproj` arquivo de projeto, ele detecta automaticamente entradas sem suporte em itens de projeto. Você verá avisos na janela de saída durante o carregamento da solução.

O Visual Studio 2019 versão 16,7 também adiciona suporte de projeto somente leitura. O suporte somente leitura permite que o IDE Use projetos criados manualmente que não têm limitações adicionais de projetos editáveis por IDE.

Se você tiver um `.vcxproj` arquivo que usa uma ou mais das construções sem suporte, poderá fazer com que ele seja carregado com avisos no IDE usando uma destas opções:

- Listar todos os itens explicitamente
- Marcar seu projeto como somente leitura
- Mover itens curinga para um corpo de destino

## <a name="list-all-items-explicitly"></a>Listar todos os itens explicitamente

Atualmente, não há como tornar itens de expansão curinga visíveis na janela de Gerenciador de Soluções em um projeto não somente leitura. Gerenciador de Soluções espera que os projetos listem todos os itens explicitamente.

Para fazer com que os `.vcxproj` projetos expandam automaticamente os curingas no Visual Studio 2019 versão 16,7 ou posterior, defina a `ReplaceWildcardsInProjectItems` propriedade como `true` . Recomendamos que você crie um *`Directory.Build.props`* arquivo em um diretório raiz e use este conteúdo:

```xml
<Project>
  <PropertyGroup>
    <ReplaceWildcardsInProjectItems>true</ReplaceWildcardsInProjectItems>
  </PropertyGroup>
</Project>
```

## <a name="mark-your-project-as-read-only"></a>Marcar seu projeto como somente leitura

No Visual Studio 2019 versão 16,7 e posterior, você pode marcar projetos como *somente leitura*. Para marcar o projeto como somente leitura, adicione a seguinte propriedade ao *`.vcxproj`* arquivo ou a qualquer um dos arquivos que ele importa:

```xml
<PropertyGroup>
    <ReadOnlyProject>true</ReadOnlyProject>
</PropertyGroup>
```

A `<ReadOnlyProject>` configuração impede que o Visual Studio edite e salve o projeto, para que você possa usar quaisquer construções do MSBuild nele, incluindo curingas.

É importante saber que o cache do projeto não estará disponível se o Visual Studio detectar curingas em itens de projeto no *`.vcxproj`* arquivo ou em qualquer uma de suas importações. Os tempos de carregamento da solução no IDE são muito mais longos se você tiver muitos projetos que usam Curingas.

## <a name="move-wildcard-items-to-a-target-body"></a>Mover itens curinga para um corpo de destino

Talvez você queira usar curingas para coletar recursos, adicionar fontes geradas e assim por diante. Se você não precisar que eles sejam listados na janela de Gerenciador de Soluções, você poderá usar este procedimento:

1. Altere o nome do grupo de itens para adicionar curingas. Por exemplo, em vez de:

   ```xml
   <Image Include="*.bmp" />
   <ClCompile Include="*.cpp" />
   ```

   Altere-o para:

   ```xml
   <_WildCardImage Include="*.bmp" />
   <_WildCardClCompile Include="*.cpp" />
   ```

1. Adicione este conteúdo ao seu  *`.vcxproj`* arquivo.Ou adicione-o a um *`Directory.Build.targets`* arquivo em um diretório raiz para afetar todos os projetos sob essa raiz:

   ```xml
   <Target Name="AddWildCardItems"
       AfterTargets="BuildGenerateSources">
     <ItemGroup>
       <Image Include="@(_WildCardImage)" />
       <ClCompile Include="@(_WildCardClCompile)" />
     </ItemGroup>
   </Target>
   ```

   Essa alteração faz com que a compilação Veja os itens conforme eles são definidos no  *`.vcxproj`* arquivo. No entanto, agora eles não são visíveis na janela de Gerenciador de Soluções e não causarão problemas no IDE.

1. Para mostrar o IntelliSense correto para  `_WildCardClCompile`   itens ao abrir esses arquivos no editor, adicione o seguinte conteúdo:

   ```xml
   <PropertyGroup>
     <ComputeCompileInputsTargets>
       AddWildCardItems
       $(ComputeCompileInputsTargets)
     </ComputeCompileInputsTargets>
   </PropertyGroup>
   ```

Efetivamente, você pode usar curingas para todos os itens dentro de um corpo de destino. Você também pode usar caracteres curinga em um  `ItemGroup`   que não esteja definido como um item de projeto por um [`ProjectSchemaDefinition`](https://devblogs.microsoft.com/cppblog/vc-MSBuild-extensibility-example/) .

> [!NOTE]
> Se você mover o curinga inclui de um *`.vcxproj`* arquivo para um arquivo importado, eles não estarão visíveis na janela de Gerenciador de soluções. Essa alteração também permite que seu projeto seja carregado no IDE sem modificação. No entanto, não recomendamos essa abordagem, pois ela desabilita o cache do projeto.

## <a name="see-also"></a>Consulte também

[Definição das propriedades de compilação do C++ no Visual Studio](../working-with-project-properties.md)<br/>
[Arquivos XML de página de propriedades](property-page-xml-files.md)
