---
title: out (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.out
helpviewer_keywords:
- out attribute
ms.assetid: 5051b1bf-4949-4bf1-b82f-35e14f0f244b
ms.openlocfilehash: b99e520a11c2e8110d2e63fa85ddb1dd444e56e6
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837093"
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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Parâmetro de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[ValorPadrão](defaultvalue.md)<br/>
[id](id.md)
