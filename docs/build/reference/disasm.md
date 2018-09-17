---
title: /DISASM | Microsoft Docs
ms.date: 1/17/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /disasm
dev_langs:
- C++
helpviewer_keywords:
- -DISASM dumpbin option
- DISASM dumpbin option
- /DISASM dumpbin option
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6a5a4d930c47d2a3c2808cbd0a343c5c68de4ac9
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707181"
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
