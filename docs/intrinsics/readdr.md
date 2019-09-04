---
title: __readdr
ms.date: 09/02/2019
f1_keywords:
- __readdr
helpviewer_keywords:
- __readdr intrinsic
ms.assetid: 061b05da-c85e-4052-b392-106f14bb84f1
ms.openlocfilehash: 646330ca92af08903485fd4583eb2c217fe3e023
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216679"
---
# <a name="__readdr"></a>__readdr

Lê o valor do registro de depuração especificado.

## <a name="syntax"></a>Sintaxe

```C
unsigned         __readdr(unsigned int DebugRegister); /* x86 */
unsigned __int64 __readdr(unsigned int DebugRegister); /* x64 */
```

### <a name="parameters"></a>Parâmetros

*DebugRegister*\
no Uma constante de 0 a 7 que identifica o registro de depuração.

## <a name="return-value"></a>Valor retornado

O valor do registro de depuração especificado.

## <a name="remarks"></a>Comentários

Esses intrínsecos estão disponíveis apenas no modo kernel, e as rotinas estão disponíveis somente como intrínsecas.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readdr`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__readeflags](../intrinsics/readeflags.md)
