---
title: está em conformidade com | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- conform_CPP
- vc-pragma.conform
dev_langs:
- C++
helpviewer_keywords:
- conform pragma
- forScope conform pragma
- pragmas, conform
ms.assetid: 71b3e174-c53c-4bfc-adf3-af39b1554191
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8c6204349731222df99683ddb20b2b2d827b3fcd
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42540734"
---
# <a name="conform"></a>conform
**Específico do C++**  
  
Especifica o comportamento de tempo de execução de [/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma conform(name [, show ] [, on | off ] [ [, push | pop ] [, identifier ] ] )  
```  
  
### <a name="parameters"></a>Parâmetros  
*name*  
Especifica o nome da opção de compilador a ser modificada. Válido somente *nome* é `forScope`.  
  
*Mostrar* (opcional)  
Faz com que a configuração atual da *nome* (true ou false) a ser exibido por meio de uma mensagem de aviso durante a compilação. Por exemplo, `#pragma conform(forScope, show)`.  
  
*ativado, desativado*(opcional)  
Definindo *nome* à *na* permite que o [/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador. O padrão é *desativar*.  
  
*envio por push* (opcional)  
Envia o valor atual da *nome* para a pilha interna do compilador. Se você especificar *identificador*, você pode especificar o *na* ou *off* valor para *nome* seja enviado por push à pilha. Por exemplo, `#pragma conform(forScope, push, myname, on)`.  
  
*pop-up* (opcional)  
Define o valor de *nome* ao valor na parte superior da pilha interna do compilador e, em seguida, a pilha de pops. Se identifier for especificado com *pop-up*, a pilha será exibida novamente até encontrar o registro com *identificador*, que também será removido; o valor atual para *nome* em o próximo registro na pilha se torna o novo valor para *nome*. Se você especificar pop com um *identificador* que não está em um registro na pilha, o *pop-up* será ignorado.  
  
*identificador*(opcional)  
Pode ser incluído em uma *push* ou *pop-up* comando. Se *identificador* for usado, então um *na* ou *off* especificador também pode ser usado.  
  
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