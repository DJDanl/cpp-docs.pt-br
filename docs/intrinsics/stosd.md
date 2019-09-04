---
title: __stosd
ms.date: 09/02/2019
f1_keywords:
- __stosd
helpviewer_keywords:
- stosd instruction
- rep stosd instruction
- __stosd intrinsic
ms.assetid: 03104247-1cea-49f6-b6f8-287917bf5680
ms.openlocfilehash: c46bb124390ff23d79361c66530493c48faf3f0a
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219984"
---
# <a name="__stosd"></a>__stosd

**Seção específica da Microsoft**

Gera uma instrução de cadeia de`rep stosd`caracteres de repositório ().

## <a name="syntax"></a>Sintaxe

```C
void __stosd(
   unsigned long* Destination,
   unsigned long Data,
   size_t Count
);
```

### <a name="parameters"></a>Parâmetros

*Destino*\
fora O destino da operação.

*Dado*\
no Os dados a serem armazenados.

*Contar*\
no O comprimento do bloco de doublewords a ser gravado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__stosd`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O resultado é que os *dados* de doubleword são gravados em um bloco de *contagem* doublewords no local da memória apontado por *destino*.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```C
// stosd.c
// processor: x86, x64

#include <stdio.h>
#include <memory.h>
#include <intrin.h>

#pragma intrinsic(__stosd)

int main()
{
    unsigned long val = 99999;
    unsigned long a[10];

    memset(a, 0, sizeof(a));
    __stosd(a+1, val, 2);

printf_s( "%u %u %u %u",
              a[0], a[1], a[2], a[3]);
}
```

```Output
0 99999 99999 0
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
