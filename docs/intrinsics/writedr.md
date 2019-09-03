---
title: __writedr
ms.date: 09/02/2019
f1_keywords:
- __writedr
helpviewer_keywords:
- __writedr intrinsic
ms.assetid: ac55c1ee-df2f-41d4-a429-6f369d2a934d
ms.openlocfilehash: 715ef7432d506c2758c9c3da913e9c0ebb24e13f
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219228"
---
# <a name="__writedr"></a>__writedr

Grava o valor especificado para o registro de depuração especificado.

## <a name="syntax"></a>Sintaxe

```C
void __writedr(unsigned DebugRegister, unsigned DebugValue); /* x86 */
void __writedr(unsigned DebugRegister, unsigned __int64 DebugValue); /* x64 */
```

### <a name="parameters"></a>Parâmetros

*DebugRegister*\
no Um número de 0 a 7 que identifica o registro de depuração.

*Debugvalue*\
no Um valor a ser gravado no registro de depuração.

## <a name="remarks"></a>Comentários

Esses intrínsecos estão disponíveis apenas no modo kernel, e as rotinas estão disponíveis somente como intrínsecas.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__writedr`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[__readdr](../intrinsics/readdr.md)
