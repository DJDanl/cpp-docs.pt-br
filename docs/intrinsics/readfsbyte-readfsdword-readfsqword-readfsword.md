---
title: __readfsbyte, __readfsdword, __readfsqword, __readfsword
ms.date: 09/02/2019
f1_keywords:
- __readfsword
- __readfsdword
- __readfsbyte
- __readfsqword
helpviewer_keywords:
- __readfsword intrinsic
- readfsword intrinsic
- __readfsdword intrinsic
- readfsbyte intrinsic
- __readfsbyte intrinsic
- readfsdword intrinsic
- readfsqword intrinsic
- __readfsqword intrinsic
ms.assetid: f6ee7203-4179-402c-a464-0746c84ce6ac
ms.openlocfilehash: 30040b33fe8c686bc0cda585c525ae2926cdf314
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222370"
---
# <a name="__readfsbyte-__readfsdword-__readfsqword-__readfsword"></a>__readfsbyte, __readfsdword, __readfsqword, __readfsword

**Seção específica da Microsoft**

Ler memória de um local especificado por um deslocamento relativo ao início do segmento FS.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __readfsbyte(
   unsigned long Offset
);
unsigned short __readfsword(
   unsigned long Offset
);
unsigned long __readfsdword(
   unsigned long Offset
);
unsigned __int64 __readfsqword(
   unsigned long Offset
);
```

### <a name="parameters"></a>Parâmetros

*Desvio*\
no O deslocamento do início de `FS` onde deve ser lido.

## <a name="return-value"></a>Valor retornado

O conteúdo de memória do byte, Word, doubleword ou quadword (conforme indicado pelo nome da função chamada) no local `FS:[Offset]`.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readfsbyte`|x86|
|`__readfsdword`|x86|
|`__readfsqword`|x86|
|`__readfsword`|x86|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essas rotinas estão disponíveis somente como intrínsecas.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__writefsbyte, \__writefsdword, \__writefsqword, \__writefsword](../intrinsics/writefsbyte-writefsdword-writefsqword-writefsword.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
