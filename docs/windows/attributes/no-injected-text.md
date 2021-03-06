---
title: no_injected_text (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.no_injected_text
helpviewer_keywords:
- no_injected_text attribute
ms.assetid: 5256f808-e41e-4f4a-9ea5-e447919f5696
ms.openlocfilehash: ab718376d5da7214813d5ab2e0caaa7bbccd077b
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88844074"
---
# <a name="no_injected_text"></a>no_injected_text

Impede que o compilador insira código como resultado do uso do atributo.

## <a name="syntax"></a>Sintaxe

```cpp
[ no_injected_text(boolean) ];
```

### <a name="parameters"></a>parâmetros

*booleano*<br/>
(Opcional) **`true`** Se você quiser que nenhum código seja injetado, **`false`** para permitir que o código seja injetado. **`true`** é o padrão.

## <a name="remarks"></a>Comentários

O uso mais comum do atributo **no_injected_text** C++ é pela opção de compilador [/FX](../../build/reference/fx-merge-injected-code.md) , que insere o atributo **no_injected_text** no arquivo. mrg.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)
