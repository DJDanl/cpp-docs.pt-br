---
title: Não extensívelC++ (atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.nonextensible
helpviewer_keywords:
- nonextensible attribute
ms.assetid: c7ef1554-809f-4ea0-a7cd-dc7786d40c3e
ms.openlocfilehash: 2a1cd4d685e2fd141c6e11feaea488f44a884c80
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214638"
---
# <a name="nonextensible"></a>nonextensible

Especifica que a implementação de `IDispatch` inclui apenas as propriedades e os métodos listados na descrição da interface e não pode ser estendido com membros adicionais em tempo de execução.

## <a name="syntax"></a>Sintaxe

```cpp
[nonextensible]
```

## <a name="remarks"></a>Comentários

O atributo **extensível** C++ tem a mesma funcionalidade que o atributo MIDL não [extensível](/windows/win32/Midl/nonextensible) .

O uso de **extensível** também requer o atributo [oleautomation](oleautomation.md) .

## <a name="example"></a>Exemplo

O código a seguir mostra um uso do atributo não **extensível** :

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**|
|**Repetível**|Não|
|**Atributos necessários**|`dual` e `oleautomation`ou `dispinterface`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)
