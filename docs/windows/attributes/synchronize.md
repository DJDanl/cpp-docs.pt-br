---
title: sincronizar (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.synchronize
dev_langs:
- C++
helpviewer_keywords:
- synchronize attribute
ms.assetid: 15fc8544-955d-4765-b3d5-0f619c8b3f40
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 740d99bfbc0da4c290a09a95f5d4f8f227a11fc8
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790127"
---
# <a name="synchronize"></a>synchronize

Sincroniza o acesso ao método de destino.

## <a name="syntax"></a>Sintaxe

```cpp
[synchronize]
```

## <a name="remarks"></a>Comentários

O **sincronizar** atributo C++ implementa o suporte para o método de destino de um objeto de sincronização. Sincronização permite que vários objetos usar um recurso comum (por exemplo, um método de uma classe), controlando o acesso do método de destino.

O código inserido por este atributo chama as devidas `Lock` método (determinado pelo modelo de threading) no início do método de destino. Quando o método é finalizado, `Unlock` é chamado automaticamente. Para obter mais informações sobre essas funções, consulte [CComAutoThreadModule::Lock](../../atl/reference/ccomautothreadmodule-class.md#lock)

Este atributo exige que o [coclass](coclass.md), [progid](progid.md), ou [vi_progid](vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicadas ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se `progid` for aplicada, `vi_progid` e `coclass` também são aplicadas.

## <a name="example"></a>Exemplo

O código a seguir fornece sincronização para o `UpdateBalance` método da `CMyClass` objeto.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método de classe, método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Um ou mais das seguintes opções: `coclass`, `progid`, ou `vi_progid`.|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de COM](com-attributes.md)  