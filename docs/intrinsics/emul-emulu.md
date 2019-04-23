---
title: __emul, __emulu
ms.date: 11/04/2016
f1_keywords:
- __emulu_cpp
- __emul
- __emul_cpp
- __emulu
helpviewer_keywords:
- __emul intrinsic
- __emulu intrinsic
ms.assetid: 79545236-cca2-40b8-a4e1-8abce9b26311
ms.openlocfilehash: 8657c0fb034ac6bbcfbebb946e059ad08d9e7046
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59030044"
---
# <a name="emul-emulu"></a>__emul, __emulu

**Seção específica da Microsoft**

Executa multiplicações que estouram o que pode conter um inteiro de 32 bits.

## <a name="syntax"></a>Sintaxe

```
__int64 __emul(
   int a,
   int b
);
unsigned __int64 __emulu(
   unsigned int a,
   unsigned int b
);
```

#### <a name="parameters"></a>Parâmetros

*a*<br/>
[in] O primeiro operando de inteiro da multiplicação.

*b*<br/>
[in] O segundo operando de inteiro da multiplicação.

## <a name="return-value"></a>Valor de retorno

O resultado da multiplicação.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__emul`|x86, x64|
|`__emulu`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

`__emul` usa dois valores com sinal de 32 bits e retorna o resultado da multiplicação como um valor inteiro com sinal de 64 bits.

`__emulu` usa dois valores de inteiro sem sinal de 32 bits e retorna o resultado da multiplicação como um valor inteiro sem sinal de 64 bits.

## <a name="example"></a>Exemplo

```
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

```
-268435456 * 2 = -536870912
4294967295 * 251658240 = 1080863910317260800
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)