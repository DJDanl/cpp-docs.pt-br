---
title: INVOKE
ms.date: 11/05/2019
f1_keywords:
- Invoke
helpviewer_keywords:
- INVOKE directive
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
ms.openlocfilehash: 7a005e5e70a2696ca89fb0ad1a3ff02aab8ffe5a
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317182"
---
# <a name="invoke"></a>INVOKE

(somente MASM de 32 bits.) Chama o procedimento no endereço fornecido pela *expressão*, passando os argumentos na pilha ou em registros de acordo com as convenções de chamada padrão do tipo de idioma.     

## <a name="syntax"></a>Sintaxe

> **Invocar** *expressão* ⟦ __,__ *argumento* ... ⟧

## <a name="remarks"></a>Comentários

Cada argumento passado para o procedimento pode ser uma expressão, um par de registro ou uma expressão de endereço (uma expressão precedida por **addr**).

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
