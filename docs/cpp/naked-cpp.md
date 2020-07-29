---
title: naked (C++)
ms.date: 11/04/2016
f1_keywords:
- naked_cpp
helpviewer_keywords:
- __declspec keyword [C++], naked
- naked __declspec keyword
ms.assetid: 69723241-05e1-439b-868e-20a83a16ab6d
ms.openlocfilehash: cff2455608966886e9c5b07039dff439538caefe
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227329"
---
# <a name="naked-c"></a>naked (C++)

**Específico da Microsoft**

Para funções declaradas com o **`naked`** atributo, o compilador gera código sem prólogo e código epílogo. Você pode usar esse recurso para escrever suas próprias sequências de código de prólogo/epílogo usando o código de assembler embutido. As funções naked são particularmente úteis para escrever drivers para dispositivo virtuais.  Observe que o **`naked`** atributo só é válido no x86 e no ARM e não está disponível em x64.

## <a name="syntax"></a>Sintaxe

```
__declspec(naked) declarator
```

## <a name="remarks"></a>Comentários

Como o **`naked`** atributo só é relevante para a definição de uma função e não é um modificador de tipo, as funções Naked devem usar a sintaxe de atributo estendido e a palavra-chave [__declspec](../cpp/declspec.md) .

O compilador não pode gerar uma função embutida para uma função marcada com o atributo Naked, mesmo que a função também seja marcada com a palavra-chave [__forceinline](inline-functions-cpp.md) .

O compilador emitirá um erro se o **`naked`** atributo for aplicado a qualquer coisa que não seja a definição de um método que não seja membro.

## <a name="examples"></a>Exemplos

Esse código define uma função com o **`naked`** atributo:

```
__declspec( naked ) int func( formal_parameters ) {}
```

Ou, alternativamente:

```
#define Naked __declspec( naked )
Naked int func( formal_parameters ) {}
```

O **`naked`** atributo afeta apenas a natureza da geração de código do compilador para as sequências de prólogo e epílogo da função. Não afeta o código que é gerado pela chamada dessas funções. Portanto, o **`naked`** atributo não é considerado parte do tipo da função e os ponteiros de função não podem ter o **`naked`** atributo. Além disso, o **`naked`** atributo não pode ser aplicado a uma definição de dados. Por exemplo, esta amostra de código gera um erro:

```
__declspec( naked ) int i;
// Error--naked attribute not permitted on data declarations.
```

O **`naked`** atributo é relevante apenas para a definição da função e não pode ser especificado no protótipo da função. Por exemplo, esta declaração gera um erro de compilador:

```
__declspec( naked ) int func();  // Error--naked attribute not permitted on function declarations
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Chamadas de função Naked](../cpp/naked-function-calls.md)
