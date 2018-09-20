---
title: __stosd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __stosd
dev_langs:
- C++
helpviewer_keywords:
- stosd instruction
- rep stosd instruction
- __stosd intrinsic
ms.assetid: 03104247-1cea-49f6-b6f8-287917bf5680
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8bb0d75cc4af033bf1bc942a918beecf2aedf911
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396136"
---
# <a name="stosd"></a>__stosd

**Seção específica da Microsoft**

Gera uma instrução de cadeia de caracteres de repositório (`rep stosd`).

## <a name="syntax"></a>Sintaxe

```
void __stosd( 
   unsigned long* Dest, 
   unsigned long Data, 
   size_t Count 
);
```

#### <a name="parameters"></a>Parâmetros

*dest*<br/>
[out] O destino da operação.

*Dados*<br/>
[in] Os dados serem armazenados.

*Contagem*<br/>
[in] O tamanho do bloco de palavras duplas para gravar.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__stosd`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O resultado é que as palavras duplas `Data` é gravado em um bloco de `Count` palavras duplas no local da memória apontada por `Dest`.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```
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