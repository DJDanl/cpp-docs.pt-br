---
title: no_injected_text (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.no_injected_text
helpviewer_keywords:
- no_injected_text attribute
ms.assetid: 5256f808-e41e-4f4a-9ea5-e447919f5696
ms.openlocfilehash: 354643020e704a87daa2e56e923b6a0a704bf0b5
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59038363"
---
# <a name="noinjectedtext"></a>no_injected_text

Impede que o compilador injetando código como resultado do uso do atributo.

## <a name="syntax"></a>Sintaxe

```cpp
[ no_injected_text(boolean) ];
```

### <a name="parameters"></a>Parâmetros

*boolean*<br/>
(Opcional) **verdadeira** se você não quiser que nenhum código injetado, **falso** para permitir que o código injetado. **True** é o padrão.

## <a name="remarks"></a>Comentários

O uso mais comum do **no_injected_text** atributo C++ é a [/Fx](../../build/reference/fx-merge-injected-code.md) opção de compilador, que insere os **no_injected_text** atributo no arquivo. mrg.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)