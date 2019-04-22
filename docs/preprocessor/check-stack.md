---
title: check_stack
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.check_stack
- check_stack_CPP
helpviewer_keywords:
- check_stack pragma
- pragmas, check_stack
- pragmas, check_stack usage table
ms.assetid: f18e20cc-9abb-48b7-ad62-8d384875b996
ms.openlocfilehash: 49477a3b39db17047f349e341bd05c04954c964c
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59023367"
---
# <a name="checkstack"></a>check_stack
Instrui o compilador a desativar investigações da pilha, se `off` (ou `-`) for especificado, ou para ativar investigações da pilha se `on` (ou `+`) for especificado.

## <a name="syntax"></a>Sintaxe

```
#pragma check_stack([ {on | off}] )
#pragma check_stack{+ | -}
```

## <a name="remarks"></a>Comentários

Se nenhum argumento for fornecido, as investigações da pilha serão tratadas de acordo com o padrão. Esse pragma entra em vigor na primeira função definida, após a consideração do pragma. As investigações da pilha não são parte de macros ou funções que forem geradas embutidas.

Se você não fornecer um argumento para o **check_stack** pragma, verificação da pilha volta para o comportamento especificado na linha de comando. Para obter mais informações, consulte [referência de compilador](../build/reference/compiler-options.md). A interação entre o `#pragma check_stack` e o [/Gs](../build/reference/gs-control-stack-checking-calls.md) opção é resumida na tabela a seguir.

### <a name="using-the-checkstack-pragma"></a>Usando o pragma check_stack

|Sintaxe|Compilado com<br /><br /> Opção /Gs?|Ação|
|------------|------------------------------------|------------|
|`#pragma check_stack( )` ou<br /><br /> `#pragma check_stack`|Sim|Desativa a verificação da pilha quanto às funções seguintes|
|`#pragma check_stack( )` ou<br /><br /> `#pragma check_stack`|Não|Ativa a verificação da pilha quanto às funções seguintes|
|`#pragma check_stack(on)`<br /><br /> Ou `#pragma check_stack +`|Sim ou não|Ativa a verificação da pilha quanto às funções seguintes|
|`#pragma check_stack(off)`<br /><br /> Ou `#pragma check_stack -`|Sim ou não|Desativa a verificação da pilha quanto às funções seguintes|

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)