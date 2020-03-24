---
title: Referência do MSBuild C++ para projetos no Visual Studio
ms.date: 12/08/2018
helpviewer_keywords:
- MSBuild reference [C++]
ms.openlocfilehash: ec1285a760d438a94863181a1b099e6db153c268
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168896"
---
# <a name="msbuild-reference-for-c-projects"></a>Referência do MSBuild para projetos C++

O MSBuild é o sistema de compilação nativo para todos os projetos no Visual C++ Studio, incluindo projetos. Quando você cria um projeto no IDE (ambiente de desenvolvimento integrado) do Visual Studio, ele invoca a ferramenta MSBuild. exe, que, por sua vez, consome o arquivo de projeto. vcxproj e vários arquivos. targets e. props. Em geral, é altamente recomendável usar o IDE do Visual Studio para definir as propriedades do projeto e invocar o MSBuild. A edição manual de arquivos de projeto pode levar a problemas sérios, se não for feito corretamente.

Se, por alguma razão, você quiser usar o MSBuild diretamente da linha de comando, consulte [usar o MSBuild na linha de comando](../msbuild-visual-cpp.md). Para obter mais informações sobre o MSBuild em geral, consulte [MSBuild](/visualstudio/msbuild/msbuild) na documentação do Visual Studio.

## <a name="in-this-section"></a>Nesta seção

[Recursos internos do MSBuild para projetos C++](msbuild-visual-cpp-overview.md)<br/>
Informações sobre como as propriedades e os destinos são armazenados e consumidos.

[Macros comuns para comandos e propriedades de build](common-macros-for-build-commands-and-properties.md)<br/>
Descreve as macros (constantes de tempo de compilação) que podem ser usadas para definir propriedades como caminhos e versões de produtos.

[Tipos de arquivo criados C++ para projetos](file-types-created-for-visual-cpp-projects.md)<br/>
Descreve os vários tipos de arquivos que o Visual Studio cria para diferentes tipos de projeto.

[Modelos de C++ projeto do Visual Studio](visual-cpp-project-types.md)<br>
Descreve os tipos de projeto baseados em MSBuild que estão disponíveis C++para o.

[Novos modelos de item do C++](using-visual-cpp-add-new-item-templates.md)<br>
Descreve os arquivos de origem e outros itens que você pode adicionar a um projeto do Visual Studio.

[Arquivos de cabeçalho pré-compilados](../creating-precompiled-header-files.md) Como usar arquivos de cabeçalho pré-compilados e como criar seu próprio código pré-compilado personalizado para acelerar os tempos de compilação.

[Referência de propriedades do projeto do Visual Studio](property-pages-visual-cpp.md)<br/>
Documentação de referência para propriedades de projeto que são definidas no IDE do Visual Studio.

## <a name="see-also"></a>Confira também

[Referência de compilação C/C++](c-cpp-building-reference.md)
