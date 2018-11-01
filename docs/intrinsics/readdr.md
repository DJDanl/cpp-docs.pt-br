---
title: __readdr
ms.date: 11/04/2016
f1_keywords:
- __readdr
helpviewer_keywords:
- __readdr intrinsic
ms.assetid: 061b05da-c85e-4052-b392-106f14bb84f1
ms.openlocfilehash: 7e6f485eef5e3c54cb406d0c2b3abe824dbf584b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50438760"
---
# <a name="readdr"></a>__readdr

Lê o valor de registro de depuração especificado.

## <a name="syntax"></a>Sintaxe

```
unsigned         __readdr(unsigned int DebugRegister);
unsigned __int64 __readdr(unsigned int DebugRegister);
```

#### <a name="parameters"></a>Parâmetros

*DebugRegister*<br/>
[in] Registre-se de uma constante de 0 a 7 que identifica a depuração.

## <a name="return-value"></a>Valor de retorno

O valor do registro de depuração especificado.

## <a name="remarks"></a>Comentários

Esses intrínsecos estão disponíveis somente no modo kernel e as rotinas estão disponíveis apenas como intrínsecos.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readdr`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[__readeflags](../intrinsics/readeflags.md)