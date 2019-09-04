---
title: __stosq
ms.date: 09/02/2019
f1_keywords:
- __stosq
helpviewer_keywords:
- rep stosq instruction
- stosq instruction
- __stosq intrinsic
ms.assetid: 3ea28297-4369-4c2d-bf0c-91fa539ce209
ms.openlocfilehash: 8b347d595da4cdbf1fefb6244940e262981671e9
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219956"
---
# <a name="__stosq"></a>__stosq

**Seção específica da Microsoft**

Gera uma instrução de cadeia de`rep stosq`caracteres de repositório ().

## <a name="syntax"></a>Sintaxe

```C
void __stosb(
   unsigned __int64* Destination,
   unsigned __int64 Data,
   size_t Count
);
```

### <a name="parameters"></a>Parâmetros

*Destino*\
fora O destino da operação.

*Dado*\
no Os dados a serem armazenados.

*Contar*\
no O comprimento do bloco de quadwords a ser gravado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__stosq`|AMD64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O resultado é que os *dados* de quadword são gravados em um bloco de *contagem* quadwords na cadeia de caracteres de *destino* .

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```C
// stosq.c
// processor: x64
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(__stosq)

int main()
{
   unsigned __int64 val = 0xFFFFFFFFFFFFI64;
   unsigned __int64 a[10];
   memset(a, 0, sizeof(a));
   __stosq(a+1, val, 2);
   printf("%I64x %I64x %I64x %I64x", a[0], a[1], a[2], a[3]);
}
```

```Output
0 ffffffffffff ffffffffffff 0
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
