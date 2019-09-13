---
title: /DISASM
ms.date: 01/17/2018
f1_keywords:
- /disasm
helpviewer_keywords:
- -DISASM dumpbin option
- DISASM dumpbin option
- /DISASM dumpbin option
ms.openlocfilehash: fb394b2266470e77c50ce5398aea961c37ac34fb
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70927717"
---
# <a name="disasm"></a>/DISASM

Imprima a desmontagem de seções de código na saída DUMPBIN.

## <a name="syntax"></a>Sintaxe

> **/DISASM**{ **:** \[**BYTES**|**NOBYTES**]}

### <a name="arguments"></a>Arguments

**BYTES**<br/>
Inclui os bytes de instrução junto com os opcodes e os argumentos interpretados na saída de desmontagem. Esta é a opção padrão.

**NOBYTES**<br/>
Não inclui os bytes de instrução na saída de desmontagem.

## <a name="remarks"></a>Comentários

A opção **/DISASM** exibe a desmontagem de seções de código no arquivo. Ele usa símbolos de depuração se estiverem presentes no arquivo.

**/DISASM** só deve ser usado em imagens nativas, não gerenciadas. A ferramenta equivalente para código gerenciado é o [ILDASM](/dotnet/framework/tools/ildasm-exe-il-disassembler).

Somente a opção [/Headers](headers.md) DUMPBIN está disponível para uso em arquivos produzidos pela opção de compilador [/GL (otimização de programa completo)](gl-whole-program-optimization.md) .

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
