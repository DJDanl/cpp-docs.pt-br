---
title: _CIfmod
ms.date: 4/2/2020
api_name:
- _CIfmod
- _o__CIfmod
api_location:
- msvcrt.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr80.dll
- msvcr90.dll
- msvcr120.dll
- msvcr110.dll
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _CIfmod
- CIfmod
helpviewer_keywords:
- CIfmod intrinsic
- _CIfmod intrinsic
ms.assetid: 7c050653-7ec6-4810-b3a7-7a0057ea65ed
ms.openlocfilehash: 8f1a78da3ed210ef37c3295adbd5d55f0215e7ff
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81349566"
---
# <a name="_cifmod"></a>_CIfmod

Calcula o restante do ponto flutuante dos dois valores superiores na pilha.

## <a name="syntax"></a>Sintaxe

```
void __cdecl _CIfmod();
```

## <a name="remarks"></a>Comentários

Esta versão da função `fmod` tem uma convenção de chamada especializada que o compilador compreende. Ele acelera a execução porque ele evita que cópias sejam geradas e ajuda na alocação de registro.

O valor resultante é colocado na parte superior da pilha.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

**Plataforma:** x86

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[fmod, fmodf](../c-runtime-library/reference/fmod-fmodf.md)
