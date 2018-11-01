---
title: support_error_info (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.support_error_info
helpviewer_keywords:
- support_error_info attribute
ms.assetid: 20a2b55c-4738-4b35-a71d-e5e9c3a7e3bc
ms.openlocfilehash: 8aed647677b8c8d26fdca522c10ec9ecee9f87c9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50625986"
---
# <a name="supporterrorinfo"></a>support_error_info

Implementa o suporte para retornar erros detalhados.

## <a name="syntax"></a>Sintaxe

```cpp
[ support_error_info(error_interface=uuid) ]
```

### <a name="parameters"></a>Parâmetros

*error_interface*<br/>
O identificador da implementação de interface `IErrorInfo`.

## <a name="remarks"></a>Comentários

O **support_error_info** atributo C++ implementa o suporte para retorno de erros detalhados, contextuais encontrados pelo objeto de destino para o cliente. Para o objeto dar suporte a erros, os métodos do `IErrorInfo` interface deve ser implementada pelo objeto. Para obter mais informações, consulte [que dão suporte a IDispatch e IErrorInfo](../../atl/supporting-idispatch-and-ierrorinfo.md).

Esse atributo adiciona o [ISupportErrorInfoImpl](../../atl/reference/isupporterrorinfoimpl-class.md) classe como uma classe base para o objeto de destino. Isso resulta em uma implementação padrão de `ISupportErrorInfo` e pode ser usado quando uma única interface gera erros em um objeto.

## <a name="example"></a>Exemplo

O código a seguir adiciona o suporte padrão para o `ISupportErrorInfo` da interface para o `CMyClass` objeto.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**class**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)