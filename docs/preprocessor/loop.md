---
title: Pragma loop
ms.date: 08/29/2019
f1_keywords:
- loop_CPP
- vc-pragma.loop
ms.assetid: 6d5bb428-cead-47e7-941d-7513bbb162c7
ms.openlocfilehash: 83dc8753392f9177f810746fce641437ed0ffec8
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520623"
---
# <a name="loop-pragma"></a>Pragma loop

Controla como o código de loop deve ser considerado pelo paralelizador automático automático ou exclui um loop da consideração pelo vetorizador automático automático.

## <a name="syntax"></a>Sintaxe

> **loop de #pragma (hint_parallel (** *n* **))**\
> **loop de #pragma (no_vector)**\
> **loop de #pragma (ivdep)**

### <a name="parameters"></a>Parâmetros

**hint_parallel (** *n* **)**\
Uma dica ao compilador que esse loop deve ser paralelizado entre *n* threads, em que *n* é um literal inteiro positivo ou zero. Se *n* for zero, o número máximo de threads será usado em tempo de execução. É uma dica para o compilador, não um comando. Não há garantia de que o loop será paralelizado. Se o loop tiver dependências de dados ou problemas estruturais, ele não será paralelizado. Por exemplo, ele não será paralelizado se for armazenado em um escalar que é usado além do corpo do loop.

O compilador ignora essa opção, a menos que a opção de compilador [/Qpar](../build/reference/qpar-auto-parallelizer.md) seja especificada.

**no_vector**\
Por padrão, o vetorizador automático automático tenta fazer o vetor de todos os loops que ele avalia pode se beneficiar dele. Especifique esse pragma para desabilitar o vetorizador automático automático para o loop a seguir.

**ivdep**\
Uma dica ao compilador para ignorar dependências de vetor para esse loop.

## <a name="remarks"></a>Comentários

Para usar o **loop** pragma, coloque-o imediatamente antes, não em uma definição de loop. O pragma entra em vigor para o escopo do loop que se segue a ele. Você pode aplicar vários pragmas a um loop, em qualquer ordem, mas deve declarar cada um em uma instrução pragma separada.

## <a name="see-also"></a>Consulte também

[Auto-paralelização e vetorização automática](../parallel/auto-parallelization-and-auto-vectorization.md)\
[Diretivas Pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
