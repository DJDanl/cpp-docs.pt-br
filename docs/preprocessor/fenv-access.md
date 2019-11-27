---
title: fenv_access (pragma)
description: Descreve o uso e os efeitos da diretiva pragma fenv_access. A diretiva fenv_access controla o acesso ao ambiente de ponto flutuante em tempo de execução.
ms.date: 11/19/2019
f1_keywords:
- vc-pragma.fenv_access
- fenv_access_CPP
helpviewer_keywords:
- pragmas, fenv_access
- fenv_access pragma
ms.assetid: 2ccea292-0ae4-42ce-9c67-cc189299857b
ms.openlocfilehash: e03eb404f2805a4f7c96509600c063c1b1acf629
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74305853"
---
# <a name="fenv_access-pragma"></a>fenv_access (pragma)

Desabilita (**ativa**) ou habilita (**desativa**) otimizações que podem alterar testes de sinalizador de ambiente de ponto flutuante e alterações de modo.

## <a name="syntax"></a>Sintaxe

> **fenv_access de #pragma (** { **on** | **off** } **)**

## <a name="remarks"></a>Comentários

Por padrão, **fenv_access** está **desativado**. O compilador pressupõe que seu código não acessa ou manipula o ambiente de ponto flutuante. Se o acesso ao ambiente não for necessário, o compilador poderá fazer mais para otimizar seu código de ponto flutuante.

Habilite **fenv_access** se o código testar sinalizadores de status de ponto flutuante, exceções ou definir sinalizadores de modo de controle. O compilador desabilita otimizações de ponto flutuante, para que seu código possa acessar o ambiente de ponto flutuante de forma consistente.

A opção de linha de comando [/fp: strict] habilita automaticamente **fenv_access**. Para obter mais informações sobre esse e outro comportamento de ponto flutuante, consulte [/FP (especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md).

Há restrições sobre as maneiras pelas quais você pode usar o **fenv_access** pragma em combinação com outras configurações de ponto flutuante:

- Você não pode habilitar **fenv_access** , a menos que a semântica precisa esteja habilitada. A semântica precisa pode ser habilitada pelo [float_control](float-control.md) pragma ou usando as opções de compilador [/fp: preciso](../build/reference/fp-specify-floating-point-behavior.md) ou [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) . O padrão do compilador é **/fp: preciso** se nenhuma outra opção de linha de comando de ponto flutuante for especificada.

- Você não pode usar **float_control** para desabilitar a semântica precisa quando **fenv_access (on)** é definido.

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

Se você comentar `#pragma fenv_access (on)` do exemplo anterior, a saída será diferente. É porque o compilador faz a avaliação em tempo de compilação, que não usa o modo de controle.

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
