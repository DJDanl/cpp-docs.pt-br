---
title: especificador final
ms.date: 11/04/2016
f1_keywords:
- final_CPP
helpviewer_keywords:
- final Identifier
ms.assetid: 649866d0-79d4-449f-ab74-f84b911b79a3
ms.openlocfilehash: 93e8d9b0b445d1120ec15911eb763ae1d7d2d359
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188645"
---
# <a name="final-specifier"></a>especificador final

Você pode usar a palavra-chave **final** para designar funções virtuais que não podem ser substituídas em uma classe derivada. Também é possível usá-la para designar classes que não podem ser herdadas.

## <a name="syntax"></a>Sintaxe

```
function-declaration final;
class class-name final base-classes
```

## <a name="remarks"></a>Comentários

**final** é contextual e tem um significado especial apenas quando é usado após uma declaração de função ou nome de classe; caso contrário, não é uma palavra-chave reservada.

Quando **final** é usado em declarações de classe, `base-classes` é uma parte opcional da declaração.

## <a name="example"></a>Exemplo

O exemplo a seguir usa a palavra-chave **final** para especificar que uma função virtual não pode ser substituída.

```cpp
class BaseClass
{
    virtual void func() final;
};

class DerivedClass: public BaseClass
{
    virtual void func(); // compiler error: attempting to
                         // override a final function
};
```

Para obter informações sobre como especificar que as funções de membro podem ser substituídas, consulte [especificador de substituição](../cpp/override-specifier.md).

O exemplo a seguir usa a palavra-chave **final** para especificar que uma classe não pode ser herdada.

```cpp
class BaseClass final
{
};

class DerivedClass: public BaseClass // compiler error: BaseClass is
                                     // marked as non-inheritable
{
};
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Especificador override](../cpp/override-specifier.md)
