---
title: Erro das Ferramentas de Vinculador LNK2027
ms.date: 11/04/2016
f1_keywords:
- LNK2027
helpviewer_keywords:
- LNK2027
ms.assetid: e2f857a8-8e8a-4697-bbff-12ccb84a35c1
ms.openlocfilehash: 0c531f70f98a017e8b75cceddc684f99d33bc554
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194584"
---
# <a name="linker-tools-error-lnk2027"></a>Erro das Ferramentas de Vinculador LNK2027

' módulo ' de referência de módulo não resolvido

Um arquivo passado para o vinculador tem uma dependência em um módulo que não foi especificado com **/ASSEMBLYMODULE** nem passado diretamente para o vinculador.

Para resolver o LNK2027, siga um destes procedimentos:

- Não passe para o vinculador o arquivo que tem a dependência de módulo.

- Especifique o módulo com **/ASSEMBLYMODULE**.

- Se o módulo for um. netmodule seguro, passe o módulo diretamente para o vinculador.

Para obter mais informações, consulte [/ASSEMBLYMODULE (adicionar um módulo MSIL ao assembly)](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md) e [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).
