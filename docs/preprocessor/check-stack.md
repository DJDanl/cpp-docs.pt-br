---
title: Pragma check_stack
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.check_stack
- check_stack_CPP
helpviewer_keywords:
- check_stack pragma
- pragmas, check_stack
- pragmas, check_stack usage table
ms.assetid: f18e20cc-9abb-48b7-ad62-8d384875b996
ms.openlocfilehash: 4c976692ec36cedcb73825ee0cc7093736a3a3dc
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216133"
---
# <a name="check_stack-pragma"></a>Pragma check_stack

Instrui o compilador a desativar as investigações de pilha se **off** (ou **-** ) for especificado ou ativar as investigações de pilha se **on** (ou **+** ) for especificado.

## <a name="syntax"></a>Sintaxe

> **#pragma check_stack (** [ **on** | **off** }] **)** \
> **#pragma check_stack** { **+**  |  **-** }

## <a name="remarks"></a>Comentários

Esse pragma entra em vigor na primeira função definida, após a consideração do pragma. As investigações da pilha não são parte de macros ou funções que forem geradas embutidas.

Se você não fornecer um argumento para o pragma **check_stack** , a verificação de pilha reverterá para o comportamento especificado na linha de comando. Para obter mais informações, confira [Opções do compilador](../build/reference/compiler-options.md). A interação do `#pragma check_stack` e a opção [/GS](../build/reference/gs-control-stack-checking-calls.md) são resumidas na tabela a seguir.

### <a name="using-the-check_stack-pragma"></a>Usando o pragma check_stack

|Sintaxe|Compilado com<br /><br /> Opção /Gs?|Ação|
|------------|------------------------------------|------------|
|`#pragma check_stack( )` ou<br /><br /> `#pragma check_stack`|Sim|Desativa a verificação da pilha quanto às funções seguintes|
|`#pragma check_stack( )` ou<br /><br /> `#pragma check_stack`|Não|Ativa a verificação da pilha quanto às funções seguintes|
|`#pragma check_stack(on)`<br /><br /> or`#pragma check_stack +`|Sim ou não|Ativa a verificação da pilha quanto às funções seguintes|
|`#pragma check_stack(off)`<br /><br /> or`#pragma check_stack -`|Sim ou não|Desativa a verificação da pilha quanto às funções seguintes|

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
