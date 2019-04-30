---
title: uuid (atributos C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.uuid
helpviewer_keywords:
- uuid attribute
ms.assetid: 90562a94-5e28-451b-a4b0-cadda7f66efe
ms.openlocfilehash: 8d9d55fc2a340165480cab4036ad1e5323e6b625
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62407192"
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
Um identificador exclusivo, de 128 bits.

## <a name="remarks"></a>Comentários

Se a definição de uma interface ou classe não especifica o **uuid** atributo C++ e, em seguida, o compilador do Visual C++ fornece um. Quando você especifica um **uuid**, você deve incluir as aspas.

Se você não especificar **uuid**, em seguida, o compilador gerará o mesmo GUID para interfaces ou classes com o mesmo nome em projetos de atributo diferente em um computador.

Você pode usar Uuidgen.exe ou Guidgen.exe para gerar seus próprio IDs exclusivas. (Para executar qualquer uma dessas ferramentas, clique em **inicie** e clique em **executar** no menu. Em seguida, insira o nome da ferramenta necessária.)

Quando usado em um projeto que não usa ATL também, especificando o **uuid** atributo é o mesmo que especificar o [uuid](../../cpp/uuid-cpp.md) **declspec** modificador. Para recuperar o **uuid** de uma classe, você pode usar [uuidof](../../cpp/uuidof-operator.md)

## <a name="example"></a>Exemplo

Consulte a [associável](bindable.md) exemplo para uso do exemplo **uuid**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**class**, **struct**, **interface**, **union**, **enum**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[uuid](/windows/desktop/Midl/uuid)