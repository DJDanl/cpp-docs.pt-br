---
title: __stosb | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __stosb
dev_langs:
- C++
helpviewer_keywords:
- rep stosb instruction
- __stosb intrinsic
- stosb instruction
ms.assetid: 634589ed-2da3-439b-a381-a214d89bf10c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 61050f8fc1924f6d2a143893af5bd1918df94394
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43895182"
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

[out] `Dest`  
O destino da operação.

[in] `Data`  
Os dados a serem armazenados.

[in] `Count`  
O tamanho do bloco de bytes a serem gravados.

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