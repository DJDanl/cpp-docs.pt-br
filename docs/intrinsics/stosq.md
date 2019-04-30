---
title: __stosq
ms.date: 11/04/2016
f1_keywords:
- __stosq
helpviewer_keywords:
- rep stosq instruction
- stosq instruction
- __stosq intrinsic
ms.assetid: 3ea28297-4369-4c2d-bf0c-91fa539ce209
ms.openlocfilehash: eacb12f7c02b82607d980281f8d4a0bc1e1d7c14
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390341"
---
# <a name="stosq"></a>__stosq

**Seção específica da Microsoft**

Gera uma instrução de cadeia de caracteres de repositório (`rep stosq`).

## <a name="syntax"></a>Sintaxe

```
void __stosb(
   unsigned __int64* Dest,
   unsigned __int64 Data,
   size_t Count
);
```

#### <a name="parameters"></a>Parâmetros

*Dest*<br/>
[out] O destino da operação.

*Dados*<br/>
[in] Os dados serem armazenados.

*Contagem*<br/>
[in] O tamanho do bloco de palavras quádruplas escrever.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__stosq`|AMD64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O resultado é que o quadword `Data` é gravado em um bloco de `Count` palavras quádruplas no `Dest` cadeia de caracteres.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```
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

## <a name="output"></a>Saída

```
0 ffffffffffff ffffffffffff 0
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)