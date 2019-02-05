---
title: _CItan
ms.date: 04/11/2018
apiname:
- _CItan
apilocation:
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr80.dll
- msvcrt.dll
- msvcr110.dll
- msvcr90.dll
- msvcr120.dll
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _CItan
- CItan
helpviewer_keywords:
- CItan intrinsic
- _CItan intrinsic
ms.assetid: d1ea3113-50a2-45a6-b6bc-680fcdcc0928
ms.openlocfilehash: d64ce3e187a055185a82868988825c418b3f54bd
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702863"
---
# <a name="citan"></a>_CItan

Calcula a tangente do valor superior na pilha de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
void __cdecl _CItan();
```

## <a name="remarks"></a>Comentários

Esta versão da função [tan](../c-runtime-library/reference/tan-tanf-tanl.md) tem uma convenção de chamada especializada que o compilador compreende. A função acelera a execução porque evita a geração de cópias e ajuda na alocação de registro.

O valor resultante é colocado na parte superior da pilha de ponto flutuante.

## <a name="requirements"></a>Requisitos

**Plataforma:** x86

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)<br/>
[tan, tanf, tanl](../c-runtime-library/reference/tan-tanf-tanl.md)<br/>
