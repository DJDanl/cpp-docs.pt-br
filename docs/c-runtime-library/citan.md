---
title: _CItan | Microsoft Docs
ms.custom: ''
ms.date: 04/11/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
apitype: DLLExport
f1_keywords:
- _CItan
- CItan
dev_langs:
- C++
helpviewer_keywords:
- CItan intrinsic
- _CItan intrinsic
ms.assetid: d1ea3113-50a2-45a6-b6bc-680fcdcc0928
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fcbd7f4258447df6f60f464b4c0a24080155fa9c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32387971"
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
