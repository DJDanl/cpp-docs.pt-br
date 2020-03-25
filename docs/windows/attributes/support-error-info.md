---
title: support_error_info (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.support_error_info
helpviewer_keywords:
- support_error_info attribute
ms.assetid: 20a2b55c-4738-4b35-a71d-e5e9c3a7e3bc
ms.openlocfilehash: e61ef2efbdc4039f496d7ffbcccc37cc8d111935
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166140"
---
# <a name="support_error_info"></a>support_error_info

Implementa o suporte para retornar erros detalhados.

## <a name="syntax"></a>Sintaxe

```cpp
[ support_error_info(error_interface=uuid) ]
```

### <a name="parameters"></a>parâmetros

*error_interface*<br/>
O identificador da interface que implementa `IErrorInfo`.

## <a name="remarks"></a>Comentários

O atributo **support_error_info** C++ implementa o suporte para retornar erros contextuais detalhados encontrados pelo objeto de destino para o cliente. Para que o objeto dê suporte a erros, os métodos da interface `IErrorInfo` devem ser implementados pelo objeto. Para obter mais informações, consulte [dando suporte a IDispatch e IErrorInfo](../../atl/supporting-idispatch-and-ierrorinfo.md).

Esse atributo adiciona a classe [ISupportErrorInfoImpl](../../atl/reference/isupporterrorinfoimpl-class.md) como uma classe base ao objeto de destino. Isso resulta em uma implementação padrão de `ISupportErrorInfo` e pode ser usado quando uma única interface gera erros em um objeto.

## <a name="example"></a>Exemplo

O código a seguir adiciona suporte padrão para a interface de `ISupportErrorInfo` para o objeto `CMyClass`.

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
|**Aplica-se a**|**class**|
|**Repetível**|Sim|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
