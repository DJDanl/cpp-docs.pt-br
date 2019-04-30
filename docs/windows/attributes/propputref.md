---
title: propputref (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.propputref
helpviewer_keywords:
- propputref attribute
ms.assetid: 9b0aed74-fdc7-4e59-9117-949bea4f86dd
ms.openlocfilehash: e471e467c55e0b8a17be96fd1bcb3cd24cfafe06
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62407465"
---
# <a name="propputref"></a>propputref

Especifica uma função de definição de propriedade que usa uma referência em vez de um valor.

## <a name="syntax"></a>Sintaxe

```cpp
[propputref]
```

## <a name="remarks"></a>Comentários

O **propputref** atributo C++ tem a mesma funcionalidade que o [propputref](/windows/desktop/Midl/propputref) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [associável](bindable.md) para uso do exemplo **propputref**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`propget`, `propput`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[propget](propget.md)<br/>
[propput](propput.md)