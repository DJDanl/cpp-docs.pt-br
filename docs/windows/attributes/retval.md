---
title: retval (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.retval
helpviewer_keywords:
- retval attribute
ms.assetid: bfa16f08-157d-4eea-afde-1232c54b8501
ms.openlocfilehash: 2a2865c1eda229f1a2fcd457c22119b2908c1caa
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514051"
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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos necessários**|**out**|
|**Atributos inválidos**|**in**|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de método](method-attributes.md)