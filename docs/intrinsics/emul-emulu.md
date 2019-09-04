---
title: __emul, __emulu
ms.date: 09/02/2019
f1_keywords:
- __emulu_cpp
- __emul
- __emul_cpp
- __emulu
helpviewer_keywords:
- __emul intrinsic
- __emulu intrinsic
ms.assetid: 79545236-cca2-40b8-a4e1-8abce9b26311
ms.openlocfilehash: 16b2b38f6f44b99c9f5b9370ba586342a860684e
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216747"
---
# <a name="__emul-__emulu"></a>__emul, __emulu

**Seção específica da Microsoft**

Executa multiplicações que estouram o que um inteiro de 32 bits pode conter.

## <a name="syntax"></a>Sintaxe

```C
__int64 __emul(
   int a,
   int b
);
unsigned __int64 __emulu(
   unsigned int a,
   unsigned int b
);
```

### <a name="parameters"></a>Parâmetros

*um*\
no O primeiro operando inteiro da multiplicação.

*b*\
no O segundo operando de inteiro da multiplicação.

## <a name="return-value"></a>Valor retornado

O resultado da multiplicação.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__emul`|x86, x64|
|`__emulu`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

`__emul`usa valores assinados de 2 32 bits e retorna o resultado da multiplicação como um valor inteiro com sinal de 64 bits.

`__emulu`usa valores inteiros sem sinal de 2 32 bits e retorna o resultado da multiplicação como um valor inteiro sem sinal de 64 bits.

## <a name="example"></a>Exemplo

```cpp
// emul.cpp
// compile with: /EHsc
// processor: x86, x64
#include <iostream>
#include <intrin.h>
using namespace std;

#pragma intrinsic(__emul)
#pragma intrinsic(__emulu)

int main()
{
   int a = -268435456;
   int b = 2;

   __int64 result = __emul(a, b);

   cout << a << " * " << b << " = " << result << endl;

   unsigned int ua = 0xFFFFFFFF; // Dec value: 4294967295
   unsigned int ub = 0xF000000;  // Dec value: 251658240

   unsigned __int64 uresult = __emulu(ua, ub);

   cout << ua << " * " << ub << " = " << uresult << endl;

}
```

## <a name="output"></a>Saída

```Output
-268435456 * 2 = -536870912
4294967295 * 251658240 = 1080863910317260800
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
