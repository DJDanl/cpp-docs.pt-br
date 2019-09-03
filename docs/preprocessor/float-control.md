---
title: Pragma float_control
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.float_control
- float_control_CPP
helpviewer_keywords:
- float_control pragma
- pragmas, float_control
ms.assetid: 4f4ba5cf-3707-413e-927d-5ecdbc0a9a43
ms.openlocfilehash: aa8cdc07953405175c1753791ab53214d73ba516
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218571"
---
# <a name="float_control-pragma"></a>Pragma float_control

Especifica o comportamento de ponto flutuante para uma função.

## <a name="syntax"></a>Sintaxe

> **#pragma float_control**\
> **#pragma float_control (** { **exato** | **estrito** |  **,** **exceto** }, { **on** | **off** } [ **, push** ] **)** \
> **#pragma float_control (** { **Push** | **pop** } **)**

## <a name="options"></a>Opções

**exato** estrito, exceto, ativado,enviarporpush |  |  | \
Especifica o comportamento de ponto flutuante, que pode ser **preciso**, **estrito**ou **Except**. Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md). A configuração pode ser **ativada** ou desativada.

Quando **estrito**, as configurações de **Strict** e **Except** são especificadas pela configuração **on** ou **off** . **Except** só pode ser definido como **on** quando **preciso** ou **Strict** também é definido como **on**.

Se o token **Push** opcional for adicionado, a configuração atual para **float_control** será enviada para a pilha do compilador interno.

**pressionado**\
Enviar por push a configuração atual de **float_control** para a pilha interna do compilador

**pop**\
Remove a configuração **float_control** da parte superior da pilha interna do compilador e faz com que a nova configuração **float_control** .

## <a name="remarks"></a>Comentários

Não é possível usar **float_control** para desativar a **precisão** quando **Except** for on. Da mesma forma, a **precisão** não pode ser desativada quando [fenv_access](../preprocessor/fenv-access.md) está ativada. Para ir de um modelo estrito para um modelo rápido usando o pragma **float_control** , use o seguinte código:

```cpp
#pragma float_control(except, off)
#pragma fenv_access(off)
#pragma float_control(precise, off)
```

Para ir de um modelo rápido para um modelo estrito com o pragma **float_control** , use o seguinte código:

```cpp
#pragma float_control(precise, on)
#pragma fenv_access(on)
#pragma float_control(except, on)
```

Se nenhuma opção for especificada, **float_control** não terá nenhum efeito.

Outros pragmas de ponto flutuante incluem:

- [fenv_access](../preprocessor/fenv-access.md)

- [fp_contract](../preprocessor/fp-contract.md)

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como capturar uma exceção de ponto flutuante de estouro usando pragma **float_control**.

```cpp
// pragma_directive_float_control.cpp
// compile with: /EHa
#include <stdio.h>
#include <float.h>

double func( ) {
   return 1.1e75;
}

#pragma float_control (except, on)

int main( ) {
   float u[1];
   unsigned int currentControl;
   errno_t err;

   err = _controlfp_s(&currentControl, ~_EM_OVERFLOW, _MCW_EM);
   if (err != 0)
      printf_s("_controlfp_s failed!\n");

   try  {
      u[0] = func();
      printf_s ("Fail");
      return(1);
   }

   catch (...)  {
      printf_s ("Pass");
      return(0);
   }
}
```

```Output
Pass
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
