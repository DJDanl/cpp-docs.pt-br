---
title: propput (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.propput
helpviewer_keywords:
- propput attribute
ms.assetid: 1f84dda9-9cce-4e16-aaf0-b2c5219827f2
ms.openlocfilehash: 5e10edba60832112a9023f796be56d88afd52042
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514199"
---
# <a name="propput"></a>propput

Especifica uma função de configuração de propriedade.

## <a name="syntax"></a>Sintaxe

```cpp
[propput]
```

## <a name="remarks"></a>Comentários

O atributo **propput** C++ tem a mesma funcionalidade que o atributo MIDL [propput](/windows/win32/Midl/propput) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para obter um exemplo de uso de **propput**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|`propget`, `propputref`|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[propget](propget.md)<br/>
[propputref](propputref.md)