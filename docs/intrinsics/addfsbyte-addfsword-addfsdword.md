---
title: __addfsbyte, __addfsword, __addfsdword
ms.date: 09/02/2019
f1_keywords:
- __addfsbyte_cpp
- __addfsdword
- __addfsword_cpp
- __addfsbyte
- __addfsword
- __addfsdword_cpp
helpviewer_keywords:
- __addfsdword intrinsic
- __addfsword intrinsic
- __addfsbyte intrinsic
ms.assetid: 706c70df-6b52-4401-9268-2977ed8ad715
ms.openlocfilehash: 302e58ed13c144913e7806a0a8b7adc202a67ef6
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218528"
---
# <a name="__addfsbyte-__addfsword-__addfsdword"></a>__addfsbyte, __addfsword, __addfsdword

**Seção específica da Microsoft**

Adicione um valor a um local de memória especificado por um deslocamento relativo ao início do `FS` segmento.

## <a name="syntax"></a>Sintaxe

```C
void __addfsbyte(
   unsigned long Offset,
   unsigned char Data
);
void __addfsword(
   unsigned long Offset,
   unsigned short Data
);
void __addfsdword(
   unsigned long Offset,
   unsigned long Data
);
```

### <a name="parameters"></a>Parâmetros

*Desvio*\
no O deslocamento do início de `FS`.

*Dado*\
no O valor a ser adicionado ao local da memória.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__addfsbyte`|x86|
|`__addfsword`|x86|
|`__addfsdword`|x86|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essas rotinas estão disponíveis somente como intrínsecas.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__incfsbyte, \__incfsword, \__incfsdword](../intrinsics/incfsbyte-incfsword-incfsdword.md)\
[__readfsbyte, \__readfsdword, \__readfsqword, \__readfsword](../intrinsics/readfsbyte-readfsdword-readfsqword-readfsword.md)\
[__writefsbyte, \__writefsdword, \__writefsqword, \__writefsword](../intrinsics/writefsbyte-writefsdword-writefsqword-writefsword.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
