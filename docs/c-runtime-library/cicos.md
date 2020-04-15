---
title: _CIcos
ms.date: 4/2/2020
api_name:
- _CIcos
- _o__CIcos
api_location:
- msvcr90.dll
- msvcrt.dll
- msvcr120.dll
- msvcr100.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- CIcos
- _CIcos
helpviewer_keywords:
- _CIcos intrinsic
- CIcos intrinsic
ms.assetid: 6fc203fb-66f3-4ead-9784-f85833c26f1b
ms.openlocfilehash: e7009272dbbd2b406c6355977514feaaf13ba746
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81334376"
---
# <a name="_cicos"></a>_CIcos

Calcula o cosseno do valor superior na pilha de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
void __cdecl _CIcos();
```

## <a name="remarks"></a>Comentários

Esta versão da função [cos](../c-runtime-library/reference/cos-cosf-cosl.md) tem uma convenção de chamada especializada que o compilador compreende. Ele acelera a execução porque ele evita que cópias sejam geradas e ajuda na alocação de registro.

O valor resultante é colocado na parte superior da pilha de ponto flutuante.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

**Plataforma:** x86

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[cos, cosf, cosl](../c-runtime-library/reference/cos-cosf-cosl.md)<br/>
