---
title: __movsq
ms.date: 09/02/2019
f1_keywords:
- __movsq
helpviewer_keywords:
- __movsq intrinsic
- rep movsq instruction
- movsq instruction
ms.assetid: be116a6e-2176-4ca4-93b1-9ccf3e7e7835
ms.openlocfilehash: 66de1971c48f6697fd06579fac635cce31545e92
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217268"
---
# <a name="__movsq"></a>__movsq

**Seção específica da Microsoft**

Gera uma instrução move String (`rep movsq`) repetida.

## <a name="syntax"></a>Sintaxe

```C
void __movsq(
   unsigned char* Destination,
   unsigned char* Source,
   size_t Count
);
```

### <a name="parameters"></a>Parâmetros

*Destino*\
fora O destino da operação.

*Source*\
no A origem da operação.

*Contar*\
no O número de quadwords a serem copiados.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__movsq`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O resultado é que a primeira *contagem* quadwords apontada por *origem* é copiada para a cadeia de caracteres de *destino* .

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```cpp
// movsq.cpp
// processor: x64
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(__movsq)

int main()
{
    unsigned __int64 a1[10];
    unsigned __int64 a2[10] = {950, 850, 750, 650, 550, 450, 350, 250,
                               150, 50};
    __movsq(a1, a2, 10);

    for (int i = 0; i < 10; i++)
       printf_s("%d ", a1[i]);
    printf_s("\n");
}
```

```Output
950 850 750 650 550 450 350 250 150 50
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
