---
title: INVOKE
ms.date: 11/05/2019
f1_keywords:
- Invoke
helpviewer_keywords:
- INVOKE directive
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
ms.openlocfilehash: ba1377359ba9bc960e5d7d2a55df15adfe0d5d33
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076215"
---
# <a name="invoke"></a>INVOKE

(somente MASM de 32 bits.) Chama o procedimento no endereço fornecido pela *expressão*, passando os argumentos na pilha ou em registros de acordo com as convenções de chamada padrão do tipo de idioma.

## <a name="syntax"></a>Sintaxe

> **Invocar** *expressão* ⟦ __,__ *argumento* ... ⟧

## <a name="remarks"></a>Comentários

Cada argumento passado para o procedimento pode ser uma expressão, um par de registro ou uma expressão de endereço (uma expressão precedida por **addr**).

## <a name="see-also"></a>Confira também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
