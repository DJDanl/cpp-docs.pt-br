---
title: Aviso LNK4286 (Ferramentas de Vinculador)
ms.date: 04/15/2019
f1_keywords:
- LNK4286
helpviewer_keywords:
- LNK4286
ms.openlocfilehash: 43ed18808ba5ce632dd7dc7095f7bc30e4497ec9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62352431"
---
# <a name="linker-tools-warning-lnk4286"></a>Aviso LNK4286 (Ferramentas de Vinculador)

> símbolo de '*símbolo*'definido em'*filename_1.obj*'é importado por'*filename_2.obj*'

[__declspec(DllImport)](../../cpp/dllexport-dllimport.md) foi especificado para *símbolo* mesmo que o símbolo é definido no arquivo de objeto *filename_1.obj* na mesma imagem. Remover o `__declspec(dllimport)` modificador para resolver este aviso.

## <a name="remarks"></a>Comentários

Aviso LNK4286 é uma versão mais geral do [LNK4217 de aviso de ferramentas de vinculador](linker-tools-warning-lnk4217.md). O vinculador gera o aviso LNK4286 quando ele pode informar qual arquivo de objeto referenciada o símbolo, mas não qual função.

Para resolver LNK4286, remova os `__declspec(dllimport)` modificador de declaração da declaração de encaminhamento *símbolo* referenciado na *filename_2.obj*.

Embora o código gerado final se comporta corretamente, o código gerado para chamar uma função importada é menos eficiente do que chamar a função diretamente. Esse aviso não aparece quando você compila usando o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção.

Para obter mais informações sobre importar e exportar dados de declarações, consulte [dllexport, dllimport](../../cpp/dllexport-dllimport.md).

## <a name="see-also"></a>Consulte também

[Aviso LNK4049 ferramentas de vinculador](linker-tools-warning-lnk4049.md) \
[Aviso LNK4217 ferramentas de vinculador](linker-tools-warning-lnk4217.md) \
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)