---
title: em conformidade | Microsoft Docs
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
ms.openlocfilehash: b145225cfed3131b406d15827b589aed718d16bb
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33843737"
---
# <a name="conform"></a>conform
**Específicas do C++**  
  
 Especifica o comportamento de tempo de execução de [/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma conform(name [, show ] [, on | off ] [ [, push | pop ] [, identifier ] ] )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 Especifica o nome da opção de compilador a ser modificada. Válido somente *nome* é `forScope`.  
  
 **Mostrar** (opcional)  
 Faz com que a configuração atual de *nome* (true ou false) a ser exibida por meio de uma mensagem de aviso durante a compilação. Por exemplo, `#pragma conform(forScope, show)`.  
  
 **ligar, desligar**(opcional)  
 Configuração *nome* para **na** permite que o [/ZC: forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador. O padrão é **off**.  
  
 **Enviar por push** (opcional)  
 Envia o valor atual de *nome* na pilha do compilador interno. Se você especificar *identificador*, você pode especificar o **na** ou **off** valor para *nome* a ser inserido na pilha. Por exemplo, `#pragma conform(forScope, push, myname, on)`.  
  
 **pop** (opcional)  
 Define o valor de *nome* ao valor na parte superior da pilha do compilador interno e, em seguida, pops a pilha. Se o identificador é especificado com **pop**, a pilha será ser exibida novamente até encontrar o registro com *identificador*, que também será exibido; o valor atual para *nome* em o próximo registro na pilha se torna o novo valor para *nome*. Se você especificar pop com um *identificador* que não está em um registro na pilha, o **pop** será ignorado.  
  
 *identificador*(opcional)  
 Pode ser incluído em um **push** ou **pop** comando. Se *identificador* for usado, então um **na** ou **off** especificador também pode ser usado.  
  
## <a name="example"></a>Exemplo  
  
```  
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