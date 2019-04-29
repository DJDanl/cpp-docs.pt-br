---
title: Palavra-chave auto
ms.date: 11/04/2016
ms.assetid: 744a41c0-2510-4140-a1be-96257e722908
ms.openlocfilehash: 3477bd5033fac5b69733db5d6095c1317aac42ee
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62284716"
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