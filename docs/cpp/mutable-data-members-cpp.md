---
title: Membros de dados mutáveis (C++)
ms.date: 11/04/2016
f1_keywords:
- mutable_cpp
helpviewer_keywords:
- mutable keyword [C++]
ms.assetid: ebe89746-3d36-43a8-8d69-f426af23f551
ms.openlocfilehash: 9370952f503850fbc296c3df912d4a0fafe163f0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227342"
---
# <a name="mutable-data-members-c"></a>Membros de dados mutáveis (C++)

Essa palavra-chave só pode ser aplicada aos membros de dados não estáticas e não constantes de uma classe. Se um membro de dados for declarado **`mutable`** , será legal atribuir um valor a esse membro de dados de uma **`const`** função de membro.

## <a name="syntax"></a>Sintaxe

```
mutable member-variable-declaration;
```

## <a name="remarks"></a>Comentários

Por exemplo, o código a seguir será compilado sem erro porque foi `m_accessCount` declarado como sendo **`mutable`** e, portanto, pode ser modificado por `GetFlag` embora `GetFlag` seja uma função de membro const.

```cpp
// mutable.cpp
class X
{
public:
   bool GetFlag() const
   {
      m_accessCount++;
      return m_flag;
   }
private:
   bool m_flag;
   mutable int m_accessCount;
};

int main()
{
}
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
