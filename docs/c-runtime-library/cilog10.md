---
title: _CIlog10
ms.date: 4/2/2020
api_name:
- _CIlog10
- _o__CIlog10
api_location:
- msvcr100.dll
- msvcr120.dll
- msvcr80.dll
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr110.dll
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- CIlog10
- _CIlog10
helpviewer_keywords:
- _CIlog10 intrinsic
- CIlog10 intrinsic
ms.assetid: 05d7fcaa-3cff-4cc5-8d44-015e7cacba24
ms.openlocfilehash: ba5868892a352f071774a817e375c1f43505ed02
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82918018"
---
# <a name="_cilog10"></a>_CIlog10

Executa uma operação `log10` no valor superior na pilha.

## <a name="syntax"></a>Sintaxe

```cpp
void __cdecl _CIlog10();
```

## <a name="remarks"></a>Comentários

Esta versão da função `log10` tem uma convenção de chamada especializada que o compilador compreende. A função acelera a execução porque evita a geração de cópias e ajuda na alocação de registro.

O valor resultante é colocado na parte superior da pilha.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

**Plataforma:** x86

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[log, logf, log10, log10f](../c-runtime-library/reference/log-logf-log10-log10f.md)
