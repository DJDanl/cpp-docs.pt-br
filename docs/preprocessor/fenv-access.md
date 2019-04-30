---
title: fenv_access
ms.date: 03/12/2018
f1_keywords:
- vc-pragma.fenv_access
- fenv_access_CPP
helpviewer_keywords:
- pragmas, fenv_access
- fenv_access pragma
ms.assetid: 2ccea292-0ae4-42ce-9c67-cc189299857b
ms.openlocfilehash: 507e78dd9f9571cc9ce44d7fd91e78b1c955ba73
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389249"
---
# <a name="fenvaccess"></a>fenv_access
Desabilita (**na**) ou habilita (**off**) otimizações que poderiam alterar o ambiente de ponto flutuante sinalizador testes e alterações de modo.

## <a name="syntax"></a>Sintaxe

> **#pragma fenv_access (** { **on** | **off** } **)**

## <a name="remarks"></a>Comentários

Por padrão, **fenv_access** é **off**. Se o compilador não pode presumir que seu código não acessar ou manipular o ambiente de ponto flutuante, em seguida, ele pode executar muitas otimizações de código de ponto flutuante. Definir **fenv_access** à **em** para informar ao compilador que seu código acessa o ambiente de ponto flutuante para testar sinalizadores de status, exceções, ou para definir sinalizadores de modo de controle. O compilador desabilita essas otimizações para que seu código possa acessar o ambiente de ponto flutuante consistentemente.

Para obter mais informações sobre o comportamento de ponto flutuante, consulte [/fp (Especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md).

Os tipos de otimizações que estão sujeitos aos **fenv_access** são:

- Eliminação de subexpressão comum global

- Movimentação de código

- Dobra de constante

Outros pragmas de ponto flutuante incluem:

- [float_control](../preprocessor/float-control.md)

- [fp_contract](../preprocessor/fp-contract.md)

## <a name="examples"></a>Exemplos

Este exemplo define **fenv_access** à **em** para definir o registro de controle de ponto flutuante de precisão de 24 bits:

```cpp
// pragma_directive_fenv_access_x86.cpp
// compile with: /O2
// processor: x86
#include <stdio.h>
#include <float.h>
#include <errno.h>
#pragma fenv_access (on)

int main() {
   double z, b = 0.1, t = 0.1;
   unsigned int currentControl;
   errno_t err;

   err = _controlfp_s(&currentControl, _PC_24, _MCW_PC);
   if (err != 0) {
      printf_s("The function _controlfp_s failed!\n");
      return -1;
   }
   z = b * t;
   printf_s ("out=%.15e\n",z);
}
```

```Output
out=9.999999776482582e-003
```

Se você comentar `#pragma fenv_access (on)` do exemplo anterior, observe que a saída é diferente porque o compilador faz a avaliação do tempo de compilação, que não usa o modo de controle.

```cpp
// pragma_directive_fenv_access_2.cpp
// compile with: /O2
#include <stdio.h>
#include <float.h>

int main() {
   double z, b = 0.1, t = 0.1;
   unsigned int currentControl;
   errno_t err;

   err = _controlfp_s(&currentControl, _PC_24, _MCW_PC);
   if (err != 0) {
      printf_s("The function _controlfp_s failed!\n");
      return -1;
   }
   z = b * t;
   printf_s ("out=%.15e\n",z);
}
```

```Output
out=1.000000000000000e-002
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
