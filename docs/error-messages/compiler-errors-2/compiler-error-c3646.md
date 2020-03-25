---
title: Erro do compilador C3646
ms.date: 06/14/2018
f1_keywords:
- C3646
helpviewer_keywords:
- C3646
ms.assetid: 4391ead2-9637-4ca3-aeda-5a991b18d66d
ms.openlocfilehash: 13a3ebeb6e7783687abc73cd0dcc018abe827809
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200467"
---
# <a name="compiler-error-c3646"></a>Erro do compilador C3646

> ' especificador ': especificador de substituição desconhecido

## <a name="remarks"></a>Comentários

O compilador encontrou um token na posição em que esperava encontrar um especificador de substituição, mas o token não foi reconhecido pelo compilador.

Por exemplo, se o *especificador* não reconhecido for **_NOEXCEPT**, substitua-o pela palavra-chave **noexcept**.

Para obter mais informações, consulte [especificadores de substituição](../../extensions/override-specifiers-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3646 e mostra uma maneira de corrigi-lo:

```cpp
// C3646.cpp
// compile with: /clr /c
ref class C {
   void f() unknown;   // C3646
   // try the following line instead
   // virtual void f() abstract;
};
```
