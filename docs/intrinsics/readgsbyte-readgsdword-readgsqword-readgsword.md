---
title: __readgsbyte, __readgsdword, __readgsqword, __readgsword
ms.date: 09/02/2019
f1_keywords:
- __readgsbyte
- __readgsdword
- __readgsqword
- __readgsword
helpviewer_keywords:
- __readgsword intrinsic
- __readgsdword intrinsic
- __readgsqword intrinsic
- __readgsbyte intrinsic
ms.assetid: f822632d-854c-4558-a71b-cdfc3eea2236
ms.openlocfilehash: 278f1de33a7e01c5893217ddd8aaa22e68cf0c94
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222353"
---
# <a name="__readgsbyte-__readgsdword-__readgsqword-__readgsword"></a>__readgsbyte, __readgsdword, __readgsqword, __readgsword

**Seção específica da Microsoft**

Ler memória de um local especificado por um deslocamento relativo ao início do segmento GS.

## <a name="syntax"></a>Sintaxe

```C
unsigned char __readgsbyte(
   unsigned long Offset
);
unsigned short __readgsword(
   unsigned long Offset
);
unsigned long __readgsdword(
   unsigned long Offset
);
unsigned __int64 __readgsqword(
   unsigned long Offset
);
```

### <a name="parameters"></a>Parâmetros

*Desvio*\
no O deslocamento do início de `GS` onde deve ser lido.

## <a name="return-value"></a>Valor retornado

O conteúdo da memória do byte, Word, Double Word ou quadword (conforme indicado pelo nome da função chamada) no local `GS:[Offset]`.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__readgsbyte`|X64|
|`__readgsdword`|X64|
|`__readgsqword`|X64|
|`__readgsword`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essas rotinas só estão disponíveis como intrínsecas.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__writegsbyte, \__writegsdword, \__writegsqword, \__writegsword](../intrinsics/writegsbyte-writegsdword-writegsqword-writegsword.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
