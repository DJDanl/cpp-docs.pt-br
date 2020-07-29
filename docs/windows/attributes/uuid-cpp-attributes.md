---
title: uuid (atributos C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.uuid
helpviewer_keywords:
- uuid attribute
ms.assetid: 90562a94-5e28-451b-a4b0-cadda7f66efe
ms.openlocfilehash: 72d18eb50f8d85fb10d5af3ffce08c5b74947531
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222089"
---
# <a name="uuid-c-attributes"></a>uuid (atributos C++)

Especifica a ID exclusiva para uma classe ou interface.

## <a name="syntax"></a>Sintaxe

```cpp
[ uuid( "uuid" ) ]
```

### <a name="parameters"></a>parâmetros

*uuid*<br/>
Um identificador exclusivo de 128 bits.

## <a name="remarks"></a>Comentários

Se a definição de uma interface ou classe não especificar o `uuid` atributo C++, o compilador do Microsoft C++ fornecerá um. Ao especificar um `uuid` , você deve incluir as aspas.

Se você não especificar `uuid` , o compilador irá gerar o mesmo GUID para interfaces ou classes com o mesmo nome em projetos de atributos diferentes em um computador.

Você pode usar Uuidgen.exe ou Guidgen.exe para gerar suas próprias IDs exclusivas. (Para executar uma dessas ferramentas, clique em **Iniciar** e em **executar** no menu. Em seguida, digite o nome da ferramenta necessária.)

Quando usado em um projeto que não usa ATL também, especificar o `uuid` atributo é o mesmo que especificar o [uuid](../../cpp/uuid-cpp.md) **`__declspec`** modificador UUID. Para recuperar o `uuid` de uma classe, você pode usar [__uuidof](../../cpp/uuidof-operator.md)

## <a name="example"></a>Exemplo

Consulte o exemplo [acoplável](bindable.md) para um exemplo de uso de `uuid` .

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|`class`, `struct`, `interface`, `union`, `enum`|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[uuid](/windows/win32/Midl/uuid)
