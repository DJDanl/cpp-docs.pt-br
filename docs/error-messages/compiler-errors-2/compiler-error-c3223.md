---
title: Erro do compilador C3223
ms.date: 11/04/2016
f1_keywords:
- C3223
helpviewer_keywords:
- C3223
ms.assetid: 1f4380b4-0413-40db-a868-62f97babaf78
ms.openlocfilehash: 5771de24cd07978903a3e598f1ff5658cb61eafa
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59778540"
---
# <a name="compiler-error-c3223"></a>Erro do compilador C3223

'property': não é possível aplicar 'typeid' a uma propriedade

Não é possível aplicar [typeid](../../extensions/typeid-cpp-component-extensions.md) a uma propriedade.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3223.

```
// C3223.cpp
// compile with: /clr
ref class R {
public:
   property int myprop;
};

int main() {
   System::Type^ type2 = R::myprop::typeid;   // C3223
}
```