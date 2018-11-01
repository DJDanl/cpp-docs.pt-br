---
title: __writedr
ms.date: 11/04/2016
f1_keywords:
- __writedr
helpviewer_keywords:
- __writedr intrinsic
ms.assetid: ac55c1ee-df2f-41d4-a429-6f369d2a934d
ms.openlocfilehash: f8049485d40185d83ed01c91ad336e83f3e79834
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50651809"
---
# <a name="writedr"></a>__writedr

Grava o valor especificado para o registro de depuração especificado.

## <a name="syntax"></a>Sintaxe

```
void __writedr(unsigned DebugRegister, unsigned DebugValue);
void __writedr(unsigned DebugRegister, unsigned __int64 DebugValue);
```

#### <a name="parameters"></a>Parâmetros

*DebugRegister*<br/>
[in] Registre-se um número de 0 a 7 que identifica a depuração.

*DebugValue*<br/>
[in] Registre-se um valor a ser gravado para a depuração.

## <a name="remarks"></a>Comentários

Esses intrínsecos estão disponíveis somente no modo kernel e as rotinas estão disponíveis apenas como intrínsecos.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writedr`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__readdr](../intrinsics/readdr.md)