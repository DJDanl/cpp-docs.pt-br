---
title: Palavra-chave auto
ms.date: 05/07/2019
ms.assetid: 744a41c0-2510-4140-a1be-96257e722908
ms.openlocfilehash: a695c33ab55601bb8d81b00f963646f6a48f09d5
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65222254"
---
# <a name="auto-keyword"></a>Palavra-chave auto

O **automática** palavra-chave é um especificador de declaração. Porém, o padrão do C++ define um significado original e um significado revisado para essa palavra-chave. Antes do Visual Studio 2010, o **automática** palavra-chave declara uma variável na *automático* classe de armazenamento, ou seja, uma variável que tem um tempo de vida local. Começando com o Visual Studio 2010, o **automática** palavra-chave declara uma variável cujo tipo é deduzido da expressão de inicialização na sua declaração. O [/ZC: auto&#91;-&#93; ](../build/reference/zc-auto-deduce-variable-type.md) opção de compilador controla o significado dos **automático** palavra-chave.

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