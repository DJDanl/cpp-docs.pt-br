---
title: no_injected_text (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.no_injected_text
helpviewer_keywords:
- no_injected_text attribute
ms.assetid: 5256f808-e41e-4f4a-9ea5-e447919f5696
ms.openlocfilehash: 5f98be3478b2e1eeb4b464f1784f3f4ece22d8a4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166608"
---
# <a name="no_injected_text"></a>no_injected_text

Impede que o compilador insira código como resultado do uso do atributo.

## <a name="syntax"></a>Sintaxe

```cpp
[ no_injected_text(boolean) ];
```

### <a name="parameters"></a>parâmetros

*booleano*<br/>
Adicional **true** se você quiser que nenhum código seja injetado, **false** para permitir que o código seja injetado. **true** é o padrão.

## <a name="remarks"></a>Comentários

O uso mais comum do atributo **no_injected_text** C++ é pela opção de compilador [/FX](../../build/reference/fx-merge-injected-code.md) , que insere o atributo **no_injected_text** no arquivo. mrg.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de compilador](compiler-attributes.md)
