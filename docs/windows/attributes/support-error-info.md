---
title: support_error_info (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.support_error_info
helpviewer_keywords:
- support_error_info attribute
ms.assetid: 20a2b55c-4738-4b35-a71d-e5e9c3a7e3bc
ms.openlocfilehash: f23241cf5478fa52d9d649acfb4c836b8b9d8f13
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211951"
---
# <a name="support_error_info"></a>support_error_info

Implementa o suporte para retornar erros detalhados.

## <a name="syntax"></a>Sintaxe

```cpp
[ support_error_info(error_interface=uuid) ]
```

### <a name="parameters"></a>parâmetros

*error_interface*<br/>
O identificador da interface que implementa `IErrorInfo` .

## <a name="remarks"></a>Comentários

O atributo **support_error_info** C++ implementa o suporte para retornar erros contextuais detalhados encontrados pelo objeto de destino para o cliente. Para que o objeto dê suporte a erros, os métodos da `IErrorInfo` interface devem ser implementados pelo objeto. Para obter mais informações, consulte [dando suporte a IDispatch e IErrorInfo](../../atl/supporting-idispatch-and-ierrorinfo.md).

Esse atributo adiciona a classe [ISupportErrorInfoImpl](../../atl/reference/isupporterrorinfoimpl-class.md) como uma classe base ao objeto de destino. Isso resulta em uma implementação padrão de `ISupportErrorInfo` e pode ser usado quando uma única interface gera erros em um objeto.

## <a name="example"></a>Exemplo

O código a seguir adiciona suporte padrão `ISupportErrorInfo` à interface para o `CMyClass` objeto.

```cpp
// cpp_attr_ref_support_error_info.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

[module (name="mymod")];
[object, uuid("f0b17d66-dc6e-4662-baaf-76758e09c878")]
__interface IMyErrors
{
};

[ coclass, support_error_info("IMyErrors"),
  uuid("854dd392-bdc7-4781-8667-8757936f2a4f") ]
class CMyClass
{
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`class`**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
