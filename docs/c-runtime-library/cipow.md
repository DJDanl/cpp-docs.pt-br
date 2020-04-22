---
title: _CIpow
ms.date: 4/2/2020
api_name:
- _CIpow
- _o__CIpow
api_location:
- msvcr100.dll
- msvcr110.dll
- msvcr120.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr90.dll
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- CIpow
- _CIpow
helpviewer_keywords:
- CIpow intrinsic
- _CIpow intrinsic
ms.assetid: 477aaf0c-ac58-4252-89dd-9f3e35d47536
ms.openlocfilehash: 953f18eb9ba6978c6e97a6b3d1d8fa7a165a27d0
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745530"
---
# <a name="_cipow"></a>_CIpow

Calcula o *x* gerado para a potência de *y* com base nos valores superiores na pilha.

## <a name="syntax"></a>Sintaxe

```cpp
void __cdecl _CIpow();
```

## <a name="remarks"></a>Comentários

Esta versão da função `pow` tem uma convenção de chamada especializada que o compilador compreende. Ele acelera a execução porque ele evita que cópias sejam geradas e ajuda na alocação de registro.

O valor resultante é colocado na parte superior da pilha.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

**Plataforma:** x86

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[pow, powf, powl](../c-runtime-library/reference/pow-powf-powl.md)
