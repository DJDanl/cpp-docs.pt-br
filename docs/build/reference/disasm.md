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
ms.openlocfilehash: 89b0784ff10e7d9521351e01d8907c963c9304fd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32370365"
---
# <a name="disasm"></a>/DISASM

Imprima a desmontagem de seções de código na saída DUMPBIN.

## <a name="syntax"></a>Sintaxe

> **/DISASM**{**:**\[**BYTES**|**NOBYTES**]}  

### <a name="arguments"></a>Arguments

**BYTES**  
Inclui os bytes de instrução junto com os argumentos e interpretado opcodes na saída de desmontagem. Esta é a opção padrão.

**NOBYTES**  
Não inclui os bytes de instrução na saída de desmontagem.

## <a name="remarks"></a>Comentários

O **/DISASM** opção exibe a desmontagem de seções de código no arquivo. Ele usa os símbolos de depuração se elas estiverem presentes no arquivo.

**/DISASM** só deve ser usado em imagens não gerenciadas e nativo. A ferramenta equivalente para código gerenciado é [ILDASM](/dotnet/framework/tools/ildasm-exe-il-disassembler).

Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos pelo [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md) opção de compilador.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](../../build/reference/dumpbin-options.md)  
