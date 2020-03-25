---
title: Threading (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.threading
helpviewer_keywords:
- threading attribute
ms.assetid: 9b558cd6-fbf0-4602-aed5-31c068550ce3
ms.openlocfilehash: b249eaf61266ed9964e44f6f0ad1c2f12a1b1067
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214494"
---
# <a name="threading-c"></a>threading (C++)

Especifica o modelo de threading para um objeto COM.

## <a name="syntax"></a>Sintaxe

```cpp
[ threading(model=enumeration) ]
```

### <a name="parameters"></a>parâmetros

*modelo*<br/>
Adicional Um dos seguintes modelos de Threading:

- `apartment` (segmentação de apartamento)

- `neutral` (.NET Framework componentes sem interface do usuário)

- `single` (Threading simples)

- `free` (Threading livre)

- `both` (segmentação de apartamento e livre)

O valor padrão é `apartment`.

## <a name="remarks"></a>Comentários

O **threading** C++ atributo threading não aparece no arquivo. idl gerado, mas será usado na implementação do seu objeto com.

Em projetos ATL, se o atributo [coclass](coclass.md) também estiver presente, o modelo de threading especificado pelo *modelo* será passado como o parâmetro de modelo para a classe [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) , inserido pelo atributo `coclass`.

O atributo **Threading** também protege o acesso a um [EVENT_SOURCE](event-source.md).

## <a name="example"></a>Exemplo

Consulte o exemplo [licenciado](licensed.md) para obter um exemplo de uso de **Threading**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de COM](com-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Suporte de multithreading para código anterior (Visual C++)](../../parallel/multithreading-support-for-older-code-visual-cpp.md)<br/>
[Apartments neutro](/windows/win32/cossdk/neutral-apartments)
