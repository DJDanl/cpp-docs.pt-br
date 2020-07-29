---
title: Threading (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.threading
helpviewer_keywords:
- threading attribute
ms.assetid: 9b558cd6-fbf0-4602-aed5-31c068550ce3
ms.openlocfilehash: e08d25df07ad881c8843953d01d9074c815ddb85
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87193062"
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

- `apartment`(segmentação de apartamento)

- `neutral`(Componentes do .NET Framework sem interface do usuário)

- `single`(Threading simples)

- `free`(Threading livre)

- `both`(segmentação de apartamento e gratuita)

O valor padrão é `apartment`.

## <a name="remarks"></a>Comentários

O atributo **Threading** do C++ não aparece no arquivo. idl gerado, mas será usado na implementação do seu objeto com.

Em projetos ATL, se o atributo [coclass](coclass.md) também estiver presente, o modelo de threading especificado pelo *modelo* será passado como o parâmetro de modelo para a classe [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) , inserido pelo `coclass` atributo.

O atributo **Threading** também protege o acesso a um [EVENT_SOURCE](event-source.md).

## <a name="example"></a>Exemplo

Consulte o exemplo [licenciado](licensed.md) para obter um exemplo de uso de **Threading**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|**coclass**|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Suporte multithread para código anterior (Visual C++)](../../parallel/multithreading-support-for-older-code-visual-cpp.md)<br/>
[Apartments neutro](/windows/win32/cossdk/neutral-apartments)
