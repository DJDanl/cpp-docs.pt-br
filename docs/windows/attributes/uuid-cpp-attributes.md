---
title: UUID (atributos C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.uuid
dev_langs:
- C++
helpviewer_keywords:
- uuid attribute
ms.assetid: 90562a94-5e28-451b-a4b0-cadda7f66efe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2bd15720c30c3a3f298e0094304205fd7fe5caeb
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790116"
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
|**Aplica-se a**|**classe**, **struct**, **interface**, **união**, **enum**|
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