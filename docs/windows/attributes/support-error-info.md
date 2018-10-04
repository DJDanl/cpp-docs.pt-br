---
title: support_error_info (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.support_error_info
dev_langs:
- C++
helpviewer_keywords:
- support_error_info attribute
ms.assetid: 20a2b55c-4738-4b35-a71d-e5e9c3a7e3bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0c6bb07071efa162b5b33ae5f1dfe72ac7ea02e8
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790104"
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