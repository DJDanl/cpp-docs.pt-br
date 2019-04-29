---
title: Membros de dados mutáveis (C++)
ms.date: 11/04/2016
f1_keywords:
- mutable_cpp
helpviewer_keywords:
- mutable keyword [C++]
ms.assetid: ebe89746-3d36-43a8-8d69-f426af23f551
ms.openlocfilehash: 8d592eb97f70bfc26c075317c57ec4d5c78e3956
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301585"
---
# <a name="mutable-data-members-c"></a>Membros de dados mutáveis (C++)

Essa palavra-chave só pode ser aplicada aos membros de dados não estáticas e não constantes de uma classe. Se um membro de dados for declarado **mutável**, então é válido para atribuir um valor para este membro de dados de uma **const** função de membro.

## <a name="syntax"></a>Sintaxe

```
mutable member-variable-declaration;
```

## <a name="remarks"></a>Comentários

Por exemplo, o código a seguir será compilado sem erros porque `m_accessCount` tenha sido declarado **mutável**e, portanto, pode ser modificado por `GetFlag` Embora `GetFlag` é uma função de membro const.

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

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)