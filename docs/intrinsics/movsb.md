---
title: __movsb | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __movsb
dev_langs:
- C++
helpviewer_keywords:
- movsb instruction
- rep movsb instruction
- __movsb intrinsic
ms.assetid: ba5469f6-f797-4cd2-bee8-74c7666c26d4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3488815f31f8148c21ebf2242ef85773505a316c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387673"
---
# <a name="movsb"></a>__movsb

**Seção específica da Microsoft**

Gera uma cadeia de caracteres mover (`rep movsb`) instrução.

## <a name="syntax"></a>Sintaxe

```
void __movsb( 
   unsigned char* Destination, 
   unsigned const char* Source, 
   size_t Count 
);
```

#### <a name="parameters"></a>Parâmetros

*Destino*<br/>
[out] Um ponteiro para o destino da cópia.

*Source*<br/>
[in] Um ponteiro para a origem da cópia.

*Contagem*<br/>
[in] O número de bytes a serem copiados.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__movsb`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O resultado é que a primeira `Count` bytes apontados por `Source` são copiados para o `Destination` cadeia de caracteres.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```
// movsb.cpp
// processor: x86, x64
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(__movsb)

int main()
{
    unsigned char s1[100];
    unsigned char s2[100] = "A big black dog.";
    __movsb(s1, s2, 100);

    printf_s("%s %s", s1, s2);
}
```

```Output
A big black dog. A big black dog.
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)