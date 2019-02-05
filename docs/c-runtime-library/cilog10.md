---
title: _CIlog10
ms.date: 11/04/2016
apiname:
- _CIlog10
apilocation:
- msvcr100.dll
- msvcr120.dll
- msvcr80.dll
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr110.dll
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- CIlog10
- _CIlog10
helpviewer_keywords:
- _CIlog10 intrinsic
- CIlog10 intrinsic
ms.assetid: 05d7fcaa-3cff-4cc5-8d44-015e7cacba24
ms.openlocfilehash: 0814043f56122e5e5363940ead338f8617279b09
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702941"
---
# <a name="cilog10"></a>_CIlog10

Executa uma operação `log10` no valor superior na pilha.

## <a name="syntax"></a>Sintaxe

```
void __cdecl _CIlog10();
```

## <a name="remarks"></a>Comentários

Esta versão da função `log10` tem uma convenção de chamada especializada que o compilador compreende. A função acelera a execução porque evita a geração de cópias e ajuda na alocação de registro.

O valor resultante é colocado na parte superior da pilha.

## <a name="requirements"></a>Requisitos

**Plataforma:** x86

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[log, logf, log10, log10f](../c-runtime-library/reference/log-logf-log10-log10f.md)