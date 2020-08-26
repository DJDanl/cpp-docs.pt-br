---
title: retval (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.retval
helpviewer_keywords:
- retval attribute
ms.assetid: bfa16f08-157d-4eea-afde-1232c54b8501
ms.openlocfilehash: f90893390bc67cb495e646f61e3d61a994e42e50
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845985"
---
# <a name="retval"></a>retval

Designa o parâmetro que recebe o valor de retorno do membro.

## <a name="syntax"></a>Sintaxe

```cpp
[retval]
```

## <a name="remarks"></a>Comentários

O atributo **retval** C++ tem a mesma funcionalidade que o atributo MIDL do [retval](/windows/win32/Midl/retval) .

**retval** deve aparecer no último argumento na declaração de uma função.

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para um exemplo de uso de **retval**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|**fora**|
|**Atributos inválidos**|**Em**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos do método](method-attributes.md)
