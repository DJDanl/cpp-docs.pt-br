---
title: __readdr
ms.date: 09/02/2019
f1_keywords:
- __readdr
helpviewer_keywords:
- __readdr intrinsic
ms.assetid: 061b05da-c85e-4052-b392-106f14bb84f1
ms.openlocfilehash: fbaf9e761f9f1450ccd12dc378ab6e498aa0df08
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857873"
---
# <a name="__readdr"></a>__readdr

**Seção específica da Microsoft**

Lê o valor do registro de depuração especificado.

## <a name="syntax"></a>Sintaxe

```C
unsigned         __readdr(unsigned int DebugRegister); /* x86 */
unsigned __int64 __readdr(unsigned int DebugRegister); /* x64 */
```

### <a name="parameters"></a>Parâmetros

\ *DebugRegister*
no Uma constante de 0 a 7 que identifica o registro de depuração.

## <a name="return-value"></a>Valor retornado

O valor do registro de depuração especificado.

## <a name="remarks"></a>Comentários

Esses intrínsecos estão disponíveis apenas no modo kernel, e as rotinas estão disponíveis somente como intrínsecas.

## <a name="requirements"></a>Requisitos do

|Intrinsic|Arquitetura|
|---------------|------------------|
|`__readdr`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

\ [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
[__readeflags](../intrinsics/readeflags.md)
