---
title: __incgsbyte, __incgsword, __incgsdword, __incgsqword
ms.date: 09/02/2019
f1_keywords:
- __incgsdword
- __incgsqword_cpp
- __incgsword_cpp
- __incgsword
- __incgsbyte
- __incgsbyte_cpp
- __incgsqword
- __incgsdword_cpp
helpviewer_keywords:
- __incgsbyte intrinsic
- __incgsword intrinsic
- __incgsqword intrinsic
- __incgsdword intrinsic
ms.assetid: 06bfdf4f-7643-4fe0-8455-60ce3068073e
ms.openlocfilehash: 8b4e88b4ccd2cf1d2a3130e3a535de1c9a434320
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217799"
---
# <a name="__incgsbyte-__incgsword-__incgsdword-__incgsqword"></a>__incgsbyte, __incgsword, __incgsdword, __incgsqword

**Seção específica da Microsoft**

Adicione um ao valor em um local de memória especificado por um deslocamento relativo ao início do `GS` segmento.

## <a name="syntax"></a>Sintaxe

```C
void __incgsbyte(
   unsigned long Offset
);
void __incgsword(
   unsigned long Offset
);
void __incgsdword(
   unsigned long Offset
);
void __incgsqword(
   unsigned long Offset
);
```

### <a name="parameters"></a>Parâmetros

*Desvio*\
no O deslocamento do início de `GS`.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__incgsbyte`|X64|
|`__incgsword`|X64|
|`__incgsdword`|X64|
|`__incgsqword`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Essas rotinas só estão disponíveis como intrínsecas.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[\__addgsbyte, \__addgsword, \__addgsdword, \__addgsqword](../intrinsics/addgsbyte-addgsword-addgsdword-addgsqword.md)\
[\__readgsbyte, \__readgsdword, \__readgsqword, \__readgsword](../intrinsics/readgsbyte-readgsdword-readgsqword-readgsword.md)\
[\__writegsbyte, \__writegsdword, \__writegsqword, \__writegsword](../intrinsics/writegsbyte-writegsdword-writegsqword-writegsword.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
