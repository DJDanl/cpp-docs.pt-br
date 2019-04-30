---
title: __stosb
ms.date: 11/04/2016
f1_keywords:
- __stosb
helpviewer_keywords:
- rep stosb instruction
- __stosb intrinsic
- stosb instruction
ms.assetid: 634589ed-2da3-439b-a381-a214d89bf10c
ms.openlocfilehash: 679f1a892a6ee5b458a05d1577ecf766bed385dd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390276"
---
# <a name="stosb"></a>__stosb

**Seção específica da Microsoft**

Gera uma instrução de cadeia de caracteres de repositório (`rep stosb`).

## <a name="syntax"></a>Sintaxe

```
void __stosb(
   unsigned char* Dest,
   unsigned char Data,
   size_t Count
);
```

#### <a name="parameters"></a>Parâmetros

*Dest*<br/>
[out] O destino da operação.

*Dados*<br/>
[in] Os dados serem armazenados.

*Contagem*<br/>
[in] O tamanho do bloco de bytes a serem gravados.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__stosb`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O resultado é que o caractere `Data` é gravado em um bloco de `Count` bytes no `Dest` cadeia de caracteres.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```C
// stosb.c
// processor: x86, x64
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(__stosb)

int main()
{
    unsigned char c = 0x40; /* '@' character */
    unsigned char s[] = "*********************************";

    printf_s("%s\n", s);
    __stosb((unsigned char*)s+1, c, 6);
    printf_s("%s\n", s);

}
```

```Output
*********************************
*@@@@@@**************************
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)