---
title: .SAVEREG
ms.date: 08/30/2018
f1_keywords:
- .SAVEREG
helpviewer_keywords:
- .SAVEREG directive
ms.assetid: 1dbc2ef6-a197-40e7-9e55-fddcae8cef29
ms.openlocfilehash: 324cf0e70a7ad619e5741c9acc18c24a72f54d13
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397966"
---
# <a name="savereg"></a>.SAVEREG

Gera um `UWOP_SAVE_NONVOL` ou uma `UWOP_SAVE_NONVOL_FAR` entrada de código de desenrolamento para o registro especificado (*reg*) e o deslocamento (*deslocamento*) usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.

## <a name="syntax"></a>Sintaxe

> **. SAVEREG** *reg* __,__ *offset*

## <a name="remarks"></a>Comentários

**. SAVEREG**permite que os usuários de ml64. exe especifiquem como uma função de quadro desenrola e só é permitida dentro do prólogo, que se estende da declaração de quadro [proc](../../assembler/masm/proc.md) para o [. Diretiva endprólogo](../../assembler/masm/dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. **. SAVEREG** deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
