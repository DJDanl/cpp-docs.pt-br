---
title: Pragma float_control
description: Descreve o uso e os efeitos da diretiva pragma float_control. A diretiva float_control controla o estado da semântica precisa de ponto flutuante e semântica de exceção em tempo de execução.
ms.date: 11/18/2019
f1_keywords:
- vc-pragma.float_control
- float_control_CPP
helpviewer_keywords:
- float_control pragma
- pragmas, float_control
ms.assetid: 4f4ba5cf-3707-413e-927d-5ecdbc0a9a43
ms.openlocfilehash: 0c9caea5ba35a55a53f7b9340cf9bfd2cce80561
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74305500"
---
# <a name="float_control-pragma"></a>Pragma float_control

Especifica o comportamento de ponto flutuante para uma função.

## <a name="syntax"></a>Sintaxe

> **#pragma float_control**\
> **#pragma float_control (preciso,** { **on** | **off** } [ **, push** ] **)** \
> **#pragma float_control (exceto,** { **on** | **off** } [ **, push** ] **)** \
> **float_control de #pragma (** { **Push** | **pop** } **)**

## <a name="options"></a>Opções

**preciso**, **em** | **desligado**, **envie**\
Especifica se deve habilitar (**ativado**) ou desabilitar (**desativado**) a semântica de ponto flutuante preciso. Para obter informações sobre como essa opção difere da opção de compilador **/fp: preciso** de forma semelhante, consulte a seção comentários. O token **Push** opcional informa o compilador para enviar por push a configuração atual para **float_control** na pilha interna do compilador.

**exceto** |  **desativado**, **envie**\
Especifica se a semântica deexceção de ponto flutuante deve ser habilitada ou desabilitada (**desativada**). Para obter informações sobre como essa opção difere da opção nomeada **/fp: except** do compilador da mesma forma, consulte a seção comentários. O token **Push** opcional informa o compilador para enviar por push a configuração atual para **float_control** na pilha interna do compilador.

**Except** só pode ser definido como **on** quando **preciso** também for definido como **on**.

**push**\
Envia por push a configuração de **float_control** atual para a pilha interna do compilador.

\ **pop**
Remove a configuração de **float_control** da parte superior da pilha interna do compilador e faz com que a nova configuração de **float_control** .

## <a name="remarks"></a>Comentários

As opções **Exact e** **Except** não têm exatamente o mesmo comportamento que as opções do compilador [/FP](../build/reference/fp-specify-floating-point-behavior.md) dos mesmos nomes. O **float_control** pragma controla apenas parte do comportamento de ponto flutuante. Ele deve ser combinado com [fp_contract](../preprocessor/fp-contract.md) e [fenv_access](../preprocessor/fenv-access.md) pragmas para recriar as opções do compilador **/FP** . A tabela a seguir mostra as configurações de pragma equivalentes para cada opção de compilador:

| | float_control (preciso, \*) | float_control (exceto \*) | fp_contract (\*) | fenv_access (\*) |
|-|-|-|-|-|
| /fp:strict             | em  | em  | desconto | em  |
| /fp:strict /fp:except- | em  | desconto | desconto | em  |
| /fp:precise            | em  | desconto | em  | desconto |
| /fp:/FP preciso: except | em  | em  | em  | desconto |
| /fp:fast               | desconto | desconto | em  | desconto |

Em outras palavras, você deve usar vários pragmas em combinação para emular as opções de linha de comando **/fp: Fast**, **/fp: preciso**, **/fp: strict**e **/fp: except** .

Há restrições sobre as maneiras pelas quais você pode usar a **float_control** e **fenv_access** pragmas de ponto flutuante em combinação:

- Você só pode usar **float_control** para definir **, exceto** como **on** , se a semântica precisa estiver habilitada. A semântica precisa pode ser habilitada pelo **float_control** pragma ou usando as opções de compilador **/fp: preciso** ou **/fp: strict** .

- Você não pode usar **float_control** para desativar a **precisão** quando a semântica de exceção está habilitada, seja por um **float_control** pragma ou uma opção de compilador **/fp: except** .

- Você não pode habilitar **fenv_access** , a menos que a semântica exata esteja habilitada, seja por um **float_control** pragma ou uma opção de compilador.

- Não é possível usar **float_control** para desativar a **precisão** quando **fenv_access** está habilitado.

Essas restrições significam que a ordem de alguns pragmas de ponto flutuante é significativa. Para ir de um modelo rápido para um modelo estrito usando o **float_control** e os pragmas relacionados, use o seguinte código:

```cpp
#pragma float_control(precise, on)  // enable precise semantics
#pragma fenv_access(on)             // enable environment sensitivity
#pragma float_control(except, on)   // enable exception semantics
#pragma fp_contract(off)            // disable contractions
```

Para ir de um modelo estrito para um modelo rápido usando o **float_control** pragma, use o seguinte código:

```cpp
#pragma float_control(except, off)  // disable exception semantics
#pragma fenv_access(off)            // disable environment sensitivity
#pragma float_control(precise, off) // disable precise semantics
#pragma fp_contract(on)             // ensable contractions
```

Se nenhuma opção for especificada, **float_control** não terá nenhum efeito.

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

[As diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
[fenv_access](../preprocessor/fenv-access.md)\
[fp_contract](../preprocessor/fp-contract.md)
