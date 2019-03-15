---
title: Referência do MSBuild para projetos do C++ no Visual Studio
ms.date: 12/08/2018
helpviewer_keywords:
- MSBuild reference [C++]
ms.openlocfilehash: 854dc0554c327f191b4b4b9694548cdb9983c5f8
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824318"
---
# <a name="msbuild-reference-for-c-projects"></a>Referência do MSBuild para projetos do C++

O MSBuild é o sistema de compilação nativa para todos os projetos no Visual Studio, incluindo projetos do C++. Quando você compila um projeto no ambiente de desenvolvimento integrado (IDE) do Visual Studio, ele chama a ferramenta de msbuild.exe, que por sua vez, consome o arquivo de projeto. vcxproj e vários arquivos. targets e. Props. Em geral, é altamente recomendável usar o IDE do Visual Studio para definir as propriedades do projeto e invoque o MSBuild. Editando manualmente os arquivos de projeto pode levar a problemas graves caso não tenha feito corretamente.

Se por algum motivo, você quiser usar o MSBuild diretamente da linha de comando, consulte [usar o MSBuild na linha de comando](../msbuild-visual-cpp.md). Para obter mais informações sobre o MSBuild em geral, consulte [MSBuild](/visualstudio/msbuild/msbuild) na documentação do Visual Studio.

## <a name="in-this-section"></a>Nesta seção

[Recursos internos de MSBuild para projetos do C++](msbuild-visual-cpp-overview.md)<br/>
Informações sobre como as propriedades e destinos são armazenados e consumidos.

[Macros comuns para comandos e propriedades de build](common-macros-for-build-commands-and-properties.md)<br/>
Descreve as macros (constantes de tempo de compilação) que podem ser usadas para definir propriedades, como caminhos e versões do produto.

[Tipos de arquivo criados para projetos do C++](file-types-created-for-visual-cpp-projects.md)<br/>
Descreve os vários tipos de arquivos que o Visual Studio cria para diferentes tipos de projeto.

[Modelos de projeto do Visual Studio C++](visual-cpp-project-types.md)<br>
Descreve os tipos de projeto do MSBuild que estão disponíveis para C++.

[Novos modelos de item de C++](using-visual-cpp-add-new-item-templates.md)<br>
Descreve os arquivos de origem e outros itens que você pode adicionar a um projeto do Visual Studio.

[Arquivos de cabeçalho pré-compilado](../creating-precompiled-header-files.md) como usar arquivos de cabeçalho pré-compilado e como criar seu próprio pré-compilado código para acelerar o tempo de compilação.

[Referência de propriedade de projeto do Visual Studio](property-pages-visual-cpp.md)<br/>
Documentação de referência para as propriedades do projeto são definidas no IDE do Visual Studio.

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](c-cpp-building-reference.md)