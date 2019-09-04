---
title: fp_contract pragma
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.fp_contract
- fp_contract_CPP
helpviewer_keywords:
- pragmas, fp_contract
- fp_contract pragma
ms.assetid: 15b97338-6680-4287-ba2a-2dccc5b2ccf5
ms.openlocfilehash: 833d8e7f4b8c9da18901610e52afed619468c5c3
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218569"
---
# <a name="fp_contract-pragma"></a>fp_contract pragma

Determina se ocorre a contratação de ponto flutuante. Uma contratação de ponto flutuante é uma instrução como o FMA (com fusível de multiplicação de adição) que combina duas operações de ponto flutuante separadas em uma única instrução. O uso dessas instruções pode afetar a precisão do ponto flutuante, porque, em vez de arredondar após cada operação, o processador pode ser arredondado apenas uma vez após ambas as operações.

## <a name="syntax"></a>Sintaxe

> **#pragma fp_contract (** { **on** | **off** } **)**

## <a name="remarks"></a>Comentários

Por padrão, **fp_contract** está **on**. Isso informa o compilador para usar instruções de contratação de ponto flutuante sempre que possível. Defina **fp_contract** como **off** para preservar instruções de ponto flutuante individuais.

Para obter mais informações sobre o comportamento de ponto flutuante, consulte [/FP (especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md).

Outros pragmas de ponto flutuante incluem:

- [fenv_access](../preprocessor/fenv-access.md)

- [float_control](../preprocessor/float-control.md)

## <a name="example"></a>Exemplo

O código gerado neste exemplo não usa uma instrução com fusível de multiplicação, mesmo quando está disponível no processador de destino. Se você comentar `#pragma fp_contract (off)`, o código gerado poderá usar uma instrução com fusível de multiplicação, se estiver disponível.

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

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
