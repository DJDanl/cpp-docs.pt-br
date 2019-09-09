---
title: uuid (atributos C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.uuid
helpviewer_keywords:
- uuid attribute
ms.assetid: 90562a94-5e28-451b-a4b0-cadda7f66efe
ms.openlocfilehash: d644f59ac92bf4e39f191c291dd4fef626411c3d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514942"
---
# <a name="uuid-c-attributes"></a>uuid (atributos C++)

Especifica a ID exclusiva para uma classe ou interface.

## <a name="syntax"></a>Sintaxe

```cpp
[ uuid(
   "uuid"
) ]
```

### <a name="parameters"></a>Parâmetros

*uuid*<br/>
Um identificador exclusivo de 128 bits.

## <a name="remarks"></a>Comentários

Se a definição de uma interface ou classe não especificar o atributo **UUID** C++ , o compilador da Microsoft C++ fornecerá um. Ao especificar um **UUID**, você deve incluir as aspas.

Se você não especificar o **UUID**, o compilador irá gerar o mesmo GUID para interfaces ou classes com o mesmo nome em projetos de atributos diferentes em um computador.

Você pode usar Uuidgen. exe ou Guidgen. exe para gerar suas próprias IDs exclusivas. (Para executar uma dessas ferramentas, clique em **Iniciar** e em **executar** no menu. Em seguida, digite o nome da ferramenta necessária.)

Quando usado em um projeto que não usa a ATL também, especificar o atributo **UUID** é o mesmo que especificar o modificador **_ overdeclspec** do [UUID](../../cpp/uuid-cpp.md) . Para recuperar o **UUID** de uma classe, você pode usar [__uuidof](../../cpp/uuidof-operator.md)

## <a name="example"></a>Exemplo

Consulte o exemplo [ligável](bindable.md) para obter um exemplo de uso de **UUID**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**Class**, **struct**, **interface**, **Union**, **enum**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[uuid](/windows/win32/Midl/uuid)