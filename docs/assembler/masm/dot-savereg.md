---
title: .SAVEREG
ms.date: 12/16/2019
f1_keywords:
- .SAVEREG
helpviewer_keywords:
- .SAVEREG directive
ms.assetid: 1dbc2ef6-a197-40e7-9e55-fddcae8cef29
ms.openlocfilehash: 18cb6e563084e8c5357bec2a8052a2b38fcdffee
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317546"
---
# <a name="savereg"></a>.SAVEREG

Gera um `UWOP_SAVE_NONVOL` ou uma `UWOP_SAVE_NONVOL_FAR` entrada de código de desenrolamento para o registro especificado (*reg*) e o deslocamento (*deslocamento*) usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.

## <a name="syntax"></a>Sintaxe

> **. SAVEREG** *reg* __,__ *offset*

## <a name="remarks"></a>Comentários

**. SAVEREG** permite que os usuários de ml64. exe especifiquem como uma função de quadro desenrola e só é permitida dentro do prólogo, que se estende da declaração de quadro [proc](proc.md) para o [. Diretiva endprólogo](dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. **. SAVEREG** deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](masm-for-x64-ml64-exe.md).

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
