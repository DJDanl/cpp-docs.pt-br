---
title: Referência mSBuild para projetos C++ no Visual Studio
ms.date: 12/08/2018
helpviewer_keywords:
- MSBuild reference [C++]
ms.openlocfilehash: 96987a252d12f718025dd55deecad5c6bac26872
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336206"
---
# <a name="msbuild-reference-for-c-projects"></a>Referência do MSBuild para projetos C++

O MSBuild é o sistema de construção nativo para todos os projetos no Visual Studio, incluindo projetos C++. Quando você constrói um projeto no ambiente de desenvolvimento integrado do Visual Studio (IDE), ele invoca a ferramenta msbuild.exe, que por sua vez consome o arquivo do projeto .vcxproj, e vários arquivos .targets e .props. Em geral, recomendamos fortemente o uso do Visual Studio IDE para definir propriedades do projeto e invocar o MSBuild. Editar manualmente arquivos de projeto pode levar a sérios problemas se não for feito corretamente.

Se, por algum motivo, desejar usar o MSBuild diretamente da linha de comando, consulte [Usar mSBuild a partir da linha de comando](../msbuild-visual-cpp.md). Para obter mais informações sobre o MSBuild em geral, consulte [o MSBuild](/visualstudio/msbuild/msbuild) na documentação do Visual Studio.

## <a name="in-this-section"></a>Nesta seção

[Recursos internos do MSBuild para projetos C++](msbuild-visual-cpp-overview.md)<br/>
Informações sobre como as propriedades e os alvos são armazenados e consumidos.

[Macros comuns para comandos e propriedades de build](common-macros-for-build-commands-and-properties.md)<br/>
Descreve macros (constantes de tempo de compilação) que podem ser usadas para definir propriedades como caminhos e versões do produto.

[Tipos de arquivos criados para projetos C++](file-types-created-for-visual-cpp-projects.md)<br/>
Descreve os vários tipos de arquivos que o Visual Studio cria para diferentes tipos de projeto.

[Modelos de projeto Visual Studio C++](visual-cpp-project-types.md)<br>
Descreve os tipos de projeto baseados no MSBuild que estão disponíveis para C++.

[Novos modelos de item do C++](using-visual-cpp-add-new-item-templates.md)<br>
Descreve arquivos de origem e outros itens que você pode adicionar a um projeto do Visual Studio.

[Arquivos de cabeçalho pré-compilados](../creating-precompiled-header-files.md) Como usar arquivos de cabeçalho pré-compilados e como criar seu próprio código pré-compilado personalizado para acelerar os tempos de compilação.

[Referência de propriedade do projeto Visual Studio](property-pages-visual-cpp.md)<br/>
Documentação de referência para propriedades do projeto que estão definidas no Visual Studio IDE.

## <a name="see-also"></a>Confira também

[Referência de build C/C++](c-cpp-building-reference.md)
