---
title: local (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.local
helpviewer_keywords:
- local attribute
ms.assetid: 35cdd668-bd8e-492a-b7b8-263e7b662437
ms.openlocfilehash: d3710eee748a43a1daa5c07d8b3feb6beb8f64fa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214741"
---
# <a name="local-c"></a>local (C++)

Quando usado no cabeçalho da interface, permite que você use o compilador MIDL como um gerador de cabeçalho. Quando usado em uma função individual, o designa um procedimento local para o qual nenhum stub é gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[local]
```

## <a name="remarks"></a>Comentários

O atributo **local** C++ tem a mesma funcionalidade que o atributo MIDL [local](/windows/win32/Midl/local) .

## <a name="example"></a>Exemplo

Consulte [call_as](call-as.md) para obter um exemplo de como usar o **local**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**, método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|`dispinterface`|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[call_as](call-as.md)
