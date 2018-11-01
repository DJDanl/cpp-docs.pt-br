---
title: fp_contract
ms.date: 03/12/2018
f1_keywords:
- vc-pragma.fp_contract
- fp_contract_CPP
helpviewer_keywords:
- pragmas, fp_contract
- fp_contract pragma
ms.assetid: 15b97338-6680-4287-ba2a-2dccc5b2ccf5
ms.openlocfilehash: 14c3ac60d4fc0f45fcf0ece6c3f73153e5de4271
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50476499"
---
# <a name="fpcontract"></a>fp_contract

Determina se contração do ponto flutuante ocorre. Uma contração de ponto flutuante é uma instrução como FMA (Fused-Multiply-Add) que combina dois separado operações de ponto flutuante em uma única instrução. O uso dessas instruções pode afetar a precisão de ponto flutuante, porque, em vez de arredondamento após cada operação, o processador pode arredondar apenas uma vez após as duas operações.

## <a name="syntax"></a>Sintaxe

> **#pragma fp_contract (** { **nos** | **off** } **)**

## <a name="remarks"></a>Comentários

Por padrão, **fp_contract** é **em**. Isso informa ao compilador para usar as instruções de ponto flutuante contração sempre que possível. Definir **fp_contract** à **off** para preservar as instruções de ponto flutuantes individuais.

Para obter mais informações sobre o comportamento de ponto flutuante, consulte [/fp (Especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md).

Outros pragmas de ponto flutuante incluem:

- [fenv_access](../preprocessor/fenv-access.md)

- [float_control](../preprocessor/float-control.md)

## <a name="example"></a>Exemplo

O código gerado deste exemplo não usa uma instrução fused-multiply-add, mesmo quando ele está disponível no processador de destino. Se você comentar `#pragma fp_contract (off)`, o código gerado pode usar uma instrução fused-multiply-add, se ele estiver disponível.

```cpp
// pragma_directive_fp_contract.cpp
// on x86 and x64 compile with: /O2 /fp:fast /arch:AVX2
// other platforms compile with: /O2

#include <stdio.h>

// remove the following line to enable FP contractions
#pragma fp_contract (off)

int main() {
   double z, b, t;

   for (int i = 0; i < 10; i++) {
      b = i * 5.5;
      t = i * 56.025;

      z = t * i + b;
      printf("out = %.15e\n", z);
   }
}
```

```Output
out = 0.000000000000000e+00
out = 6.152500000000000e+01
out = 2.351000000000000e+02
out = 5.207249999999999e+02
out = 9.184000000000000e+02
out = 1.428125000000000e+03
out = 2.049900000000000e+03
out = 2.783725000000000e+03
out = 3.629600000000000e+03
out = 4.587525000000000e+03
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
