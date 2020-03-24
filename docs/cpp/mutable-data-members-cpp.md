---
title: Membros de dados mutáveis (C++)
ms.date: 11/04/2016
f1_keywords:
- mutable_cpp
helpviewer_keywords:
- mutable keyword [C++]
ms.assetid: ebe89746-3d36-43a8-8d69-f426af23f551
ms.openlocfilehash: db3a9594a77a9ada971213eaea74a9842bd96a54
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179335"
---
# <a name="mutable-data-members-c"></a>Membros de dados mutáveis (C++)

Essa palavra-chave só pode ser aplicada aos membros de dados não estáticas e não constantes de uma classe. Se um membro de dados for declarado como **mutável**, será legal atribuir um valor a esse membro de dados de uma função de membro **const** .

## <a name="syntax"></a>Sintaxe

```
mutable member-variable-declaration;
```

## <a name="remarks"></a>Comentários

Por exemplo, o código a seguir será compilado sem erro porque `m_accessCount` foi declarado como **mutável**e, portanto, pode ser modificado por `GetFlag` mesmo que `GetFlag` seja uma função de membro const.

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
