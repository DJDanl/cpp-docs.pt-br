---
title: (C++ COM atributo nonextensible)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.nonextensible
helpviewer_keywords:
- nonextensible attribute
ms.assetid: c7ef1554-809f-4ea0-a7cd-dc7786d40c3e
ms.openlocfilehash: ed396b3d55e16cf195949c713ab574812b796a1a
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59032070"
---
# <a name="nonextensible"></a>nonextensible

Especifica que o `IDispatch` implementação inclui apenas as propriedades e os métodos listados na descrição da interface e não podem ser estendidos com membros adicionais em tempo de execução.

## <a name="syntax"></a>Sintaxe

```cpp
[nonextensible]
```

## <a name="remarks"></a>Comentários

O **nonextensible** atributo C++ tem a mesma funcionalidade que o [nonextensible](/windows/desktop/Midl/nonextensible) atributo MIDL.

Uso de **nonextensible** também requer o [oleautomation](oleautomation.md) atributo.

## <a name="example"></a>Exemplo

O código a seguir mostra um uso de **nonextensible** atributo:

```cpp
// cpp_attr_ref_nonextensible.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="ATLFIRELib")];
[export] typedef long HRESULT;

[dual, nonextensible, ms_union, oleautomation,
uuid("00000000-0000-0000-0000-000000000001")]
__interface IFireTabCtrl
{
   HRESULT procedure (int i);
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos obrigatórios**|`dual` e `oleautomation`, ou `dispinterface`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)