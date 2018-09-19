---
title: palavra-chave auto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 744a41c0-2510-4140-a1be-96257e722908
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 10952e6360fc8170c59e9a67fe3027622cbea4bc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46055515"
---
# <a name="auto-keyword"></a>Palavra-chave auto

O **automática** palavra-chave é um especificador de declaração. Porém, o padrão do C++ define um significado original e um significado revisado para essa palavra-chave. Antes do Visual C++ 2010, o **automática** palavra-chave declara uma variável na *automático* classe de armazenamento, ou seja, uma variável que tem um tempo de vida local. Começando com o Visual C++ 2010, o **automática** palavra-chave declara uma variável cujo tipo é deduzido da expressão de inicialização na sua declaração. O [/ZC: auto&#91;-&#93; ](../build/reference/zc-auto-deduce-variable-type.md) opção de compilador controla o significado dos **automático** palavra-chave.

## <a name="syntax"></a>Sintaxe

```cpp
auto declarator ;
auto declarator initializer;
```

## <a name="remarks"></a>Comentários

A definição do **automática** alterações de palavra-chave na linguagem de programação C++, mas não na linguagem de programação C.

Os tópicos a seguir descrevem os **automática** palavra-chave e a opção de compilador correspondente:

- [auto](../cpp/auto-cpp.md) descreve a nova definição do **automática** palavra-chave.

- [/ZC: auto (deduzir tipo variável)](../build/reference/zc-auto-deduce-variable-type.md) descreve a opção de compilador que informa ao compilador qual definição dos **automática** palavra-chave a ser usado.

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)