---
title: propputref (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.propputref
helpviewer_keywords:
- propputref attribute
ms.assetid: 9b0aed74-fdc7-4e59-9117-949bea4f86dd
ms.openlocfilehash: a9c4413e9bb8c7faa332bb842700dfcf84d6666a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166426"
---
# <a name="propputref"></a>propputref

Especifica uma função de configuração de propriedade que usa uma referência em vez de um valor.

## <a name="syntax"></a>Sintaxe

```cpp
[propputref]
```

## <a name="remarks"></a>Comentários

O atributo **propputref** C++ tem a mesma funcionalidade que o atributo MIDL [propputref](/windows/win32/Midl/propputref) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para obter um exemplo de uso de **propputref**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|`propget`, `propput`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[propget](propget.md)<br/>
[propput](propput.md)
