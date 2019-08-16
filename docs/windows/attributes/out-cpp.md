---
title: out (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.out
helpviewer_keywords:
- out attribute
ms.assetid: 5051b1bf-4949-4bf1-b82f-35e14f0f244b
ms.openlocfilehash: 11c8e4473f0b849fab7846a825b90da3ed9f036f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514291"
---
# <a name="out-c"></a>out (C++)

Identifica os parâmetros de ponteiro que são retornados do procedimento chamado para o procedimento de chamada (do servidor para o cliente).

## <a name="syntax"></a>Sintaxe

```cpp
[out]
```

## <a name="remarks"></a>Comentários

O atributo **out** C++ tem a mesma funcionalidade que o atributo MIDL de [saída](/windows/win32/Midl/out-idl) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para um exemplo de uso de **out**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[defaultvalue](defaultvalue.md)<br/>
[id](id.md)