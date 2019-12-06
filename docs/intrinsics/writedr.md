---
title: __writedr
ms.date: 09/02/2019
f1_keywords:
- __writedr
helpviewer_keywords:
- __writedr intrinsic
ms.assetid: ac55c1ee-df2f-41d4-a429-6f369d2a934d
ms.openlocfilehash: 473e7223e9974d0125e772c152ea85ae90b97342
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74858055"
---
# <a name="__writedr"></a>__writedr

**Seção específica da Microsoft**

Grava o valor especificado para o registro de depuração especificado.

## <a name="syntax"></a>Sintaxe

```C
void __writedr(unsigned DebugRegister, unsigned DebugValue); /* x86 */
void __writedr(unsigned DebugRegister, unsigned __int64 DebugValue); /* x64 */
```

### <a name="parameters"></a>Parâmetros

\ *DebugRegister*
no Um número de 0 a 7 que identifica o registro de depuração.

\ *debugvalue*
no Um valor a ser gravado no registro de depuração.

## <a name="remarks"></a>Comentários

Esses intrínsecos estão disponíveis apenas no modo kernel, e as rotinas estão disponíveis somente como intrínsecas.

## <a name="requirements"></a>Requisitos do

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__writedr`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

\ [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
[__readdr](../intrinsics/readdr.md)
