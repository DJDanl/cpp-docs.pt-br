---
title: Synchronize (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.synchronize
helpviewer_keywords:
- synchronize attribute
ms.assetid: 15fc8544-955d-4765-b3d5-0f619c8b3f40
ms.openlocfilehash: a7edbaa4e572af18bec9b3b6bef54594d6511390
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831665"
---
# <a name="synchronize"></a>synchronize

Sincroniza o acesso ao método de destino.

## <a name="syntax"></a>Sintaxe

```cpp
[synchronize]
```

## <a name="remarks"></a>Comentários

O atributo **Synchronize** C++ implementa o suporte para sincronizar o método de destino de um objeto. A sincronização permite que vários objetos usem um recurso comum (como um método de uma classe) controlando o acesso do método de destino.

O código inserido por esse atributo chama o `Lock` método apropriado (determinado pelo modelo de Threading) no início do método de destino. Quando o método é encerrado, `Unlock` é chamado automaticamente. Para obter mais informações sobre essas funções, consulte [CComAutoThreadModule:: Lock](../../atl/reference/ccomautothreadmodule-class.md#lock)

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento. Se qualquer atributo único for usado, os outros dois serão aplicados automaticamente. Por exemplo, se `progid` é aplicado `vi_progid` e `coclass` também é aplicado.

## <a name="example"></a>Exemplo

O código a seguir fornece a sincronização para o `UpdateBalance` método do `CMyClass` objeto.

```cpp
// cpp_attr_ref_synchronize.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

[module(name="SYNC")];

[coclass,
threading(both),
vi_progid("MyProject.MyClass"),
progid("MyProject.MyClass.1"),
uuid("7a7baa0d-59b8-4576-b754-79d07e1d1cc3")
]
class CMyClass {
   float m_nBalance;

   [synchronize]
   void UpdateBalance(float nAdjust) {
      m_nBalance += nAdjust;
   }
};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Método de classe, método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Um ou mais dos seguintes: `coclass` , `progid` ou `vi_progid` .|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)
