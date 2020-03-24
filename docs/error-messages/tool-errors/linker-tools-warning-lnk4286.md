---
title: Aviso LNK4286 (Ferramentas de Vinculador)
ms.date: 04/15/2019
f1_keywords:
- LNK4286
helpviewer_keywords:
- LNK4286
ms.openlocfilehash: d0205ba065f6e410383c38a0f1c2eaa0da55fe93
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173862"
---
# <a name="linker-tools-warning-lnk4286"></a>Aviso LNK4286 (Ferramentas de Vinculador)

> o símbolo '*Symbol*' definido em '*filename_1. obj*' é importado por '*filename_2. obj*'

[__declspec (dllimport)](../../cpp/dllexport-dllimport.md) foi especificado para *símbolo* , embora o símbolo esteja definido no arquivo de objeto *filename_1. obj* na mesma imagem. Remova o modificador de `__declspec(dllimport)` para resolver este aviso.

## <a name="remarks"></a>Comentários

Aviso LNK4286 é uma versão mais geral do [aviso de ferramentas do vinculador LNK4217](linker-tools-warning-lnk4217.md). O vinculador gera um aviso LNK4286 quando pode informar qual arquivo de objeto referenciou o símbolo, mas não qual função.

Para resolver LNK4286, remova o modificador de declaração `__declspec(dllimport)` da declaração de encaminhamento do *símbolo* referenciado em *filename_2. obj*.

Embora o código gerado final se comporta corretamente, o código gerado para chamar uma função importada é menos eficiente do que chamar a função diretamente. Esse aviso não aparece quando você compila usando a opção [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) .

Para obter mais informações sobre como importar e exportar declarações de dados, consulte [dllexport, DllImport](../../cpp/dllexport-dllimport.md).

## <a name="see-also"></a>Confira também

[LNK4049 de aviso das ferramentas do vinculador](linker-tools-warning-lnk4049.md) \
[LNK4217 de aviso das ferramentas do vinculador](linker-tools-warning-lnk4217.md) \
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)
