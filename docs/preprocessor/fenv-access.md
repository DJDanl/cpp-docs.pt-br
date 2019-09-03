---
title: Pragma fenv_access
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.fenv_access
- fenv_access_CPP
helpviewer_keywords:
- pragmas, fenv_access
- fenv_access pragma
ms.assetid: 2ccea292-0ae4-42ce-9c67-cc189299857b
ms.openlocfilehash: c8e66881bde12df28bf24e18230471cb4caca792
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218599"
---
# <a name="fenv_access-pragma"></a>Pragma fenv_access

Desabilita (**ativa**) ou habilita (**desativa**) otimizações que podem alterar testes de sinalizador de ambiente de ponto flutuante e alterações de modo.

## <a name="syntax"></a>Sintaxe

> **#pragma fenv_access (** { **on** | **off** } **)**

## <a name="remarks"></a>Comentários

Por padrão, **fenv_access** é **off**. Se o compilador puder assumir que seu código não acessa ou manipula o ambiente de ponto flutuante, ele poderá executar muitas otimizações de código de ponto flutuante. Defina **fenv_access** como **on** para informar ao compilador que seu código acessa o ambiente de ponto flutuante para testar sinalizadores de status, exceções ou para definir sinalizadores de modo de controle. O compilador desabilita essas otimizações para que seu código possa acessar o ambiente de ponto flutuante de forma consistente.

Para obter mais informações sobre o comportamento de ponto flutuante, consulte [/FP (especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md).

Os tipos de otimizações que estão sujeitos a **fenv_access** são:

- Eliminação de subexpressão comum global

- Movimentação de código

- Dobra de constante

Outros pragmas de ponto flutuante incluem:

- [float_control](../preprocessor/float-control.md)

- [fp_contract](../preprocessor/fp-contract.md)

## <a name="examples"></a>Exemplos

Este exemplo define **fenv_access** como **on** para definir o registro de controle de ponto flutuante para precisão de 24 bits:

```cpp
// pragma_directive_fenv_access_x86.cpp
// compile with: /O2 /arch:IA32
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
out=9.999999776482582e-03
```

Se você comentar `#pragma fenv_access (on)` a partir do exemplo anterior, observe que a saída é diferente porque o compilador faz a avaliação de tempo de compilação, que não usa o modo de controle.

```cpp
// pragma_directive_fenv_access_2.cpp
// compile with: /O2 /arch:IA32
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
out=1.000000000000000e-02
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
