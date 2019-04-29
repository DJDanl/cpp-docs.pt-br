---
title: conform
ms.date: 11/04/2016
f1_keywords:
- conform_CPP
- vc-pragma.conform
helpviewer_keywords:
- conform pragma
- forScope conform pragma
- pragmas, conform
ms.assetid: 71b3e174-c53c-4bfc-adf3-af39b1554191
ms.openlocfilehash: 35c3b06106779a9056f682ff76c6ed4b4ab1ab41
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366753"
---
# <a name="conform"></a>conform
**Específico do C++**

Especifica o comportamento de tempo de execução de [/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador.

## <a name="syntax"></a>Sintaxe

> **está em conformidade com #pragma (** *nome* [**, mostrar** ] [**,** { **em** | **off** }] [[**,** { **push** | **pop-up** }] [**,** *identificador* ]] **)**

### <a name="parameters"></a>Parâmetros

*name*<br/>
Especifica o nome da opção de compilador a ser modificada. Válido somente *nome* é `forScope`.

**show**<br/>
(Opcional) Faz com que a configuração atual da *nome* (true ou false) a ser exibido por meio de uma mensagem de aviso durante a compilação. Por exemplo, `#pragma conform(forScope, show)`.

**on**, **off**<br/>
(Opcional) Definindo *nome* à **na** permite que o [/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador. O padrão é **desativar**.

**push**<br/>
(Opcional) Envia o valor atual da *nome* para a pilha interna do compilador. Se você especificar *identificador*, você pode especificar o **na** ou **off** valor para *nome* seja enviado por push à pilha. Por exemplo, `#pragma conform(forScope, push, myname, on)`.

**pop**<br/>
(Opcional) Define o valor de *nome* ao valor na parte superior da pilha interna do compilador e, em seguida, a pilha de pops. Se identifier for especificado com **pop-up**, a pilha será exibida novamente até encontrar o registro com *identificador*, que também será removido; o valor atual para *nome* em o próximo registro na pilha se torna o novo valor para *nome*. Se você especificar **pop-up** com um *identificador* que não está em um registro na pilha, o **pop-up** será ignorado.

*identifier*<br/>
(Opcional) Pode ser incluído em uma **push** ou **pop-up** comando. Se *identificador* for usado, então um **na** ou **off** especificador também pode ser usado.

## <a name="example"></a>Exemplo

```cpp
// pragma_directive_conform.cpp
// compile with: /W1
// C4811 expected
#pragma conform(forScope, show)
#pragma conform(forScope, push, x, on)
#pragma conform(forScope, push, x1, off)
#pragma conform(forScope, push, x2, off)
#pragma conform(forScope, push, x3, off)
#pragma conform(forScope, show)
#pragma conform(forScope, pop, x1)
#pragma conform(forScope, show)

int main() {}
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)