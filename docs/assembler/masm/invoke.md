---
title: INVOKE
ms.date: 11/05/2019
f1_keywords:
- Invoke
helpviewer_keywords:
- INVOKE directive
ms.assetid: 12d9bb40-33b9-411e-b801-45a1d675967e
ms.openlocfilehash: 853bc9cd22d866357a4cd2d695beccc3efc20acf
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73703961"
---
# <a name="invoke-32-bit-masm"></a>INVOKE (MASM-bit de 32 bits)

Chama o procedimento no endereço fornecido pela *expressão*, passando os argumentos na pilha ou em registros de acordo com as convenções de chamada padrão do tipo de idioma. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> CHAMAR *expressão* [[, *arguments*]]

## <a name="remarks"></a>Comentários

Cada argumento passado para o procedimento pode ser uma expressão, um par de registro ou uma expressão de endereço (uma expressão precedida por `ADDR`).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>