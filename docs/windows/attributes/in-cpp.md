---
title: in (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.in
helpviewer_keywords:
- in attribute
ms.assetid: 7b450cc4-4d2e-4910-a195-7487c6b7c373
ms.openlocfilehash: 2838a00ffe365f42fb7778b654306eb0c73b5996
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842228"
---
# <a name="in-c"></a>in (C++)

Indica que um parâmetro deve ser passado do procedimento de chamada para o procedimento chamado.

## <a name="syntax"></a>Sintaxe

```cpp
[in]
```

## <a name="remarks"></a>Comentários

O atributo **in** C++ tem a mesma funcionalidade que o [no](/windows/win32/Midl/in) atributo MIDL.

## <a name="example"></a>Exemplo

Consulte [ligável](bindable.md) para obter um exemplo de como usar o **no**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|**retval**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[ValorPadrão](defaultvalue.md)<br/>
[id](id.md)<br/>
[fora](out-cpp.md)
