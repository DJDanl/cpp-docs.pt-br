---
title: INVOKE
ms.date: 08/30/2018
f1_keywords:
- Invoke
helpviewer_keywords:
- INVOKE directive
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
ms.openlocfilehash: efa8f710701e15845c3a6a22ba024c9cf1882457
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62202610"
---
# <a name="invoke"></a>INVOKE

Chama o procedimento no endereço fornecido pelo *expressão*, passando os argumentos na pilha ou em registros de acordo com as convenções de chamada padrão do tipo de linguagem.

## <a name="syntax"></a>Sintaxe

> INVOKE *expression* [[, *arguments*]]

## <a name="remarks"></a>Comentários

Cada argumento passado para o procedimento pode ser uma expressão, um par de registro ou uma expressão de endereço (uma expressão precedida por `ADDR`).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>