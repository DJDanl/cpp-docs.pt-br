---
title: fenv_access | Microsoft Docs
ms.custom: ''
ms.date: 03/12/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.fenv_access
- fenv_access_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, fenv_access
- fenv_access pragma
ms.assetid: 2ccea292-0ae4-42ce-9c67-cc189299857b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eeb138a8b2598c209005031a3ccd3104fead48dc
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42538568"
---
# <a name="fenvaccess"></a>fenv_access
Desabilita (**na**) ou habilita (**off**) otimizações que poderiam alterar o ambiente de ponto flutuante sinalizador testes e alterações de modo.

## <a name="syntax"></a>Sintaxe

> **#pragma fenv_access (** { **nos** | **off** } **)**  

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
