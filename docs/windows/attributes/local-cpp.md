---
title: local (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.local
helpviewer_keywords:
- local attribute
ms.assetid: 35cdd668-bd8e-492a-b7b8-263e7b662437
ms.openlocfilehash: dea62653478e451af00fa47b72984f3b580aadc0
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834083"
---
# <a name="local-c"></a>local (C++)

Quando usado no cabeçalho da interface, permite que você use o compilador MIDL como um gerador de cabeçalho. Quando usado em uma função individual, o designa um procedimento local para o qual nenhum stub é gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[local]
```

## <a name="remarks"></a>Comentários

O atributo C++ **local** tem a mesma funcionalidade que o atributo MIDL [local](/windows/win32/Midl/local) .

## <a name="example"></a>Exemplo

Consulte [call_as](call-as.md) para obter um exemplo de como usar o **local**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**interface**, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`dispinterface`|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[call_as](call-as.md)
