---
title: Noções básicas sobre geração de manifesto para programas do C/C++
ms.date: 11/04/2016
helpviewer_keywords:
- manifests [C++]
ms.assetid: a1f24221-5b09-4824-be48-92eae5644b53
ms.openlocfilehash: 16d5efc5c5f7ce81b4b60269b0c666fd5d24266e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492520"
---
# <a name="understanding-manifest-generation-for-cc-programs"></a>Noções básicas sobre geração de manifesto para programas do C/C++

Um [manifesto](/windows/win32/sbscs/manifests) é um documento XML que pode ser um arquivo XML externo ou um recurso inserido dentro de um aplicativo ou um assembly. O manifesto de um [aplicativo isolado](/windows/win32/SbsCs/isolated-applications) é usado para gerenciar os nomes e as versões de assemblies compartilhados lado a lado para os quais o aplicativo deve ser associado em tempo de execução. O manifesto de um assembly lado a lado especifica suas dependências em nomes, versões, recursos e outros assemblies.

Há duas maneiras de criar um manifesto para um aplicativo isolado ou um assembly lado a lado. Primeiro, o autor do assembly pode criar manualmente um arquivo de manifesto seguindo as regras e os requisitos de nomenclatura. Como alternativa, se um programa depende apenas de assemblies C++ visuais como, por exemplo, CRT, MFC, ATL ou outros, um manifesto pode ser gerado automaticamente pelo vinculador.

Os cabeçalhos de bibliotecas C++ visuais contêm informações de assembly e, quando as bibliotecas são incluídas no código do aplicativo, essas informações de assembly são usadas pelo vinculador para formar um manifesto para o binário final. O vinculador não incorpora o arquivo de manifesto dentro do binário e só pode gerar o manifesto como um arquivo externo. Ter um manifesto como um arquivo externo pode não funcionar para todos os cenários. Por exemplo, é recomendável que os assemblies privados tenham manifestos incorporados. Em compilações de linha de comando, como aquelas que usam NMAKE para criar código, um manifesto pode ser inserido usando a ferramenta de manifesto; para obter mais informações [, consulte geração de manifesto na linha de comando](manifest-generation-at-the-command-line.md). Ao criar no Visual Studio, um manifesto pode ser incorporado definindo uma propriedade para a ferramenta de manifesto na caixa de diálogo **Propriedades do projeto** ; consulte [geração de manifesto no Visual Studio](manifest-generation-in-visual-studio.md).

## <a name="see-also"></a>Consulte também

[Conceitos de aplicativos isolados e assemblies lado a lado](concepts-of-isolated-applications-and-side-by-side-assemblies.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)
