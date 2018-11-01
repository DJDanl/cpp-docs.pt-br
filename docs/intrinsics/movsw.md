---
title: __movsw
ms.date: 11/04/2016
f1_keywords:
- __movsw
helpviewer_keywords:
- movsw instruction
- rep movsw instruction
- __movsw intrinsic
ms.assetid: db402ad5-7f0e-449a-b0b0-eea9928d6435
ms.openlocfilehash: 4bb8a6411c3700b3338fb7d5bc76884f84bb2413
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50453606"
---
# <a name="movsw"></a>__movsw

**Seção específica da Microsoft**

Gera uma cadeia de caracteres mover (`rep movsw`) instrução.

## <a name="syntax"></a>Sintaxe

```
void __movsw( 
   unsigned short* Dest, 
   unsigned short* Source, 
   size_t Count 
);
```

#### <a name="parameters"></a>Parâmetros

*dest*<br/>
[out] O destino da operação.

*Source*<br/>
[in] A origem da operação.

*Contagem*<br/>
[in] O número de palavras para copiar.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__movsw`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O resultado é que a primeira `Count` palavras apontado por `Source` são copiados para o `Dest` cadeia de caracteres.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```
// movsw.cpp
// processor: x86, x64
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(__movsw)

int main()
{
    unsigned short s1[10];
    unsigned short s2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    __movsw(s1, s2, 10);

    for (int i = 0; i < 10; i++)
        printf_s("%d ", s1[i]);
    printf_s("\n");
}
```

```Output
0 1 2 3 4 5 6 7 8 9
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)