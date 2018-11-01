---
title: naked (C++)
ms.date: 11/04/2016
f1_keywords:
- naked_cpp
helpviewer_keywords:
- __declspec keyword [C++], naked
- naked __declspec keyword
ms.assetid: 69723241-05e1-439b-868e-20a83a16ab6d
ms.openlocfilehash: 951760d7f9566c084bbe3d5a574d006020576c61
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478371"
---
# <a name="naked-c"></a>naked (C++)

**Seção específica da Microsoft**

Para funções declaradas com o **naked** atributo, o compilador gera um código sem código de prólogo e epílogo. Você pode usar esse recurso para escrever suas próprias sequências de código de prólogo/epílogo usando o código de assembler embutido. As funções naked são particularmente úteis para escrever drivers para dispositivo virtuais.  Observe que o **naked** atributo só é válido em x86 e ARM e não está disponível em x64.

## <a name="syntax"></a>Sintaxe

```
__declspec(naked) declarator
```

## <a name="remarks"></a>Comentários

Porque o **naked** atributo só é relevante para a definição de uma função e não é um modificador de tipo, funções naked devem usar a sintaxe de atributo estendido e a [declspec](../cpp/declspec.md) palavra-chave.

O compilador não gere uma função embutida para uma função marcada com o atributo naked, mesmo se a função também é marcada com o [forceinline](inline-functions-cpp.md) palavra-chave.

O compilador emitirá um erro se o **naked** atributo é aplicado a qualquer coisa que não seja a definição de um método de não-membro.

## <a name="examples"></a>Exemplos

Esse código define uma função com o **naked** atributo:

```
__declspec( naked ) int func( formal_parameters ) {}
```

Ou, alternativamente:

```
#define Naked __declspec( naked )
Naked int func( formal_parameters ) {}
```

O **naked** atributo afeta somente a natureza de geração de código do compilador para sequências de prólogo e epílogo da função. Não afeta o código que é gerado pela chamada dessas funções. Portanto, o **naked** atributo não é considerado parte do tipo da função e ponteiros de função não podem ter o **naked** atributo. Além disso, o **naked** atributo não pode ser aplicado a uma definição de dados. Por exemplo, esta amostra de código gera um erro:

```
__declspec( naked ) int i;
// Error--naked attribute not permitted on data declarations.
```

O **naked** atributo só é relevante para a definição da função e não pode ser especificado no protótipo da função. Por exemplo, esta declaração gera um erro de compilador:

```
__declspec( naked ) int func();  // Error--naked attribute not permitted on function declarations
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Chamadas de função naked](../cpp/naked-function-calls.md)