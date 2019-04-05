---
title: loop
ms.date: 10/18/2018
f1_keywords:
- loop_CPP
- vc-pragma.loop
ms.assetid: 6d5bb428-cead-47e7-941d-7513bbb162c7
ms.openlocfilehash: a1640881d98073381a941478f4b78177a95698d7
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59023160"
---
# <a name="loop"></a>loop

Controla como o código de loop deverá ser considerado pelo paralelizador automático, e/ou exclui um loop de ser considerado pelo vetorizador automático.

## <a name="syntax"></a>Sintaxe

```
#pragma loop( hint_parallel(n) )
#pragma loop( no_vector )
#pragma loop( ivdep )
```

### <a name="parameters"></a>Parâmetros

*hint_parallel(n)*<br/>
Indica que o compilador que esse loop deverá ser paralelizado por *n* threads, onde *n* é um literal de inteiro positivo ou zero. Se *n* for zero, o número máximo de threads é usado em tempo de execução. Esta é uma dica para o compilador, não um comando, e não há nenhuma garantia de que o loop será paralelizado. Se o loop tiver dependências de dados ou problemas estruturais - por exemplo, se o loop for armazenado em um escalar usado além do corpo do loop -, o loop não será paralelizado.

O compilador ignora essa opção, a menos que o [/Qpar](../build/reference/qpar-auto-parallelizer.md) comutador de compilador é especificado.

*no_vector*<br/>
Por padrão, o vetorizador automático está ativo e tentará vetorizar todos os loops que, em sua avaliação, beneficiam-se disso. Especifique este pragma para desabilitar o vetorizador automático para o loop que se segue a ele.

*ivdep*<br/>
Indica que o compilador deverá ignorar as dependências de vetor para esse loop. Use em conjunto com *hint_parallel*.

## <a name="remarks"></a>Comentários

Para usar o **loop** pragma, coloque-o imediatamente antes — não em — uma definição de loop. O pragma entra em vigor para o escopo do loop que se segue a ele. Você pode aplicar vários pragmas a um loop, em qualquer ordem, mas deve declarar cada um em uma instrução pragma separada.

## <a name="see-also"></a>Consulte também

[Paralelização automática e vetorização automática](../parallel/auto-parallelization-and-auto-vectorization.md)<br/>
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)