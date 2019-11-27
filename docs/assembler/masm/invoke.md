---
title: INVOKE
ms.date: 11/05/2019
f1_keywords:
- Invoke
helpviewer_keywords:
- INVOKE directive
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
ms.openlocfilehash: a5175252364918ca218e81536b29f084f7fd19cc
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397307"
---
# <a name="invoke-32-bit-masm"></a>INVOKE (MASM-bit de 32 bits)

Chama o procedimento no endereço fornecido pela *expressão*, passando os argumentos na pilha ou em registros de acordo com as convenções de chamada padrão do tipo de idioma. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **Invocar** *expressão* ⟦ __,__ *argumento* ... ⟧

## <a name="remarks"></a>Comentários

Cada argumento passado para o procedimento pode ser uma expressão, um par de registro ou uma expressão de endereço (uma expressão precedida por **addr**).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
