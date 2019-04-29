---
title: /DISASM
ms.date: 1/17/2018
f1_keywords:
- /disasm
helpviewer_keywords:
- -DISASM dumpbin option
- DISASM dumpbin option
- /DISASM dumpbin option
ms.openlocfilehash: 10e8187e896b3922438a8cf2dafa0aec4c91f904
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62272055"
---
# <a name="disasm"></a>/DISASM

Imprima a desmontagem de seções de código na saída (DUMPBIN).

## <a name="syntax"></a>Sintaxe

> **/DISASM**{**:**\[**BYTES**|**NOBYTES**]}

### <a name="arguments"></a>Arguments

**BYTES**<br/>
Inclui os bytes de instrução junto com os argumentos e interpretado opcodes na saída de desmontagem. Esta é a opção padrão.

**NOBYTES**<br/>
Não inclui os bytes de instrução na saída de desmontagem.

## <a name="remarks"></a>Comentários

O **/DISASM** opção exibe a desmontagem de seções de código no arquivo. Ele usa símbolos de depuração se eles estiverem presentes no arquivo.

**/DISASM** só deve ser usado em imagens nativas, não gerenciadas. É a ferramenta equivalente para código gerenciado [ILDASM](/dotnet/framework/tools/ildasm-exe-il-disassembler).

Somente o [/HEADERS](headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos pelo [/GL (otimização de programa inteiro)](gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
