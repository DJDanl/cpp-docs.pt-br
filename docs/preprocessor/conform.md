---
title: Pragma conform
ms.date: 08/29/2019
f1_keywords:
- conform_CPP
- vc-pragma.conform
helpviewer_keywords:
- conform pragma
- forScope conform pragma
- pragmas, conform
ms.assetid: 71b3e174-c53c-4bfc-adf3-af39b1554191
ms.openlocfilehash: 816ff85bb19f549c6ea072073bd89fcd503545f2
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220504"
---
# <a name="conform-pragma"></a>Pragma conform

**C++Determinados**

Especifica o comportamento de tempo de execução da opção de compilador [/Zc: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) .

## <a name="syntax"></a>Sintaxe

> **#pragma conformidade (** *nome* [ **, mostrar** ] [ **,** { **on** | **off** }] [[ **,** { **Push** | **pop** }] [ **,** *Identifier* [ **,** { **on** **off}** ]  |  ] ] **)**

### <a name="parameters"></a>Parâmetros

*nomes*\
Especifica o nome da opção de compilador a ser modificada. O único *nome* válido é `forScope`.

**programa**\
Adicional Faz com que a configuração atual de *Name* (true ou false) seja exibida por meio de uma mensagem de aviso durante a compilação. Por exemplo, `#pragma conform(forScope, show)`.

**ativado**, **desativado**\
Adicional Definir o *nome* como **on** habilita a opção de compilador [/Zc: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) . O padrão é **off**.

**pressionado**\
Adicional Envia por push o valor atual do *nome* para a pilha interna do compilador. Se você especificar o *identificador*, poderá especificar o valor de **Ativar** ou **desativar** para que o *nome* seja enviado por push para a pilha. Por exemplo, `#pragma conform(forScope, push, myname, on)`.

**pop**\
Adicional Define o valor do *nome* para o valor na parte superior da pilha do compilador interno e, em seguida, exibe a pilha. Se o identificador for especificado com **pop**, a pilha será retirada até encontrar o registro com o *identificador*, que também será exibido; o valor atual do *nome* no próximo registro na pilha torna-se o novo valor para *nome*. Se você especificar **pop** com um *identificador* que não está em um registro na pilha, o **pop** será ignorado.

*ID*\
Adicional Pode ser incluído com um comando **Push** ou **pop** . Se o *identificador* for usado, um especificador **on** ou **off** também poderá ser usado.

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

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
