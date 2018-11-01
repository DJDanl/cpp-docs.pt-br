---
title: /DISASM
ms.date: 1/17/2018
f1_keywords:
- /disasm
helpviewer_keywords:
- -DISASM dumpbin option
- DISASM dumpbin option
- /DISASM dumpbin option
ms.openlocfilehash: 77f6f05029ec4480afb2180eab0bb57838d643a6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462940"
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

Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos pelo [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](../../build/reference/dumpbin-options.md)
