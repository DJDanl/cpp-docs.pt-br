---
title: propput (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.propput
helpviewer_keywords:
- propput attribute
ms.assetid: 1f84dda9-9cce-4e16-aaf0-b2c5219827f2
ms.openlocfilehash: 1902ba61417be457b4c296b513e1632bfdd8cec6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50492723"
---
# <a name="propput"></a>propput

Especifica uma função de definição de propriedade.

## <a name="syntax"></a>Sintaxe

```cpp
[propput]
```

## <a name="remarks"></a>Comentários

O **propput** atributo C++ tem a mesma funcionalidade que o [propput](/windows/desktop/Midl/propput) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](bindable.md) para uso do exemplo **propput**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`propget`, `propputref`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[propget](propget.md)<br/>
[propputref](propputref.md)