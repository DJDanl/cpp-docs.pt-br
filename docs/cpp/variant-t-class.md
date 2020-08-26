---
title: Classe _variant_t
ms.date: 11/04/2016
f1_keywords:
- _variant_t
helpviewer_keywords:
- _variant_t class [C++], operators
- _variant_t class
- _variant_t class [C++], member functions
- VARIANT object
- VARIANT object [C++], COM encapsulation
ms.assetid: 6a3cbd4e-0ae8-425e-b4cf-ca0df894c93f
ms.openlocfilehash: 3873452afca0159cba815a2cb290ebb6e62aff07
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842553"
---
# <a name="_variant_t-class"></a>Classe _variant_t

**Específico da Microsoft**

Um objeto **_variant_t** encapsula o `VARIANT` tipo de dados. A classe gerencia a alocação de recursos e a desalocação e faz chamadas de função para `VariantInit` e `VariantClear` conforme apropriado.

### <a name="construction"></a>Construção

| Nome | Descrição |
|--|--|
| [_variant_t](../cpp/variant-t-variant-t.md) | Constrói um objeto **_variant_t** . |

### <a name="operations"></a>Operations

| Nome | Descrição |
|--|--|
| [Attach](../cpp/variant-t-attach.md) | Anexa um `VARIANT` objeto ao objeto **_variant_t** . |
| [Limpar](../cpp/variant-t-clear.md) | Limpa o objeto encapsulado `VARIANT` . |
| [ChangeType](../cpp/variant-t-changetype.md) | Altera o tipo do objeto **_variant_t** para o indicado `VARTYPE` . |
| [Desanexar](../cpp/variant-t-detach.md) | Desanexa o objeto encapsulado `VARIANT` deste **_variant_t** objeto. |
| [SetString](../cpp/variant-t-setstring.md) | Atribui uma cadeia de caracteres a este **_variant_t** objeto. |

### <a name="operators"></a>Operadores

| Nome | Descrição |
|--|--|
| [Operador =](../cpp/variant-t-operator-equal.md) | Atribui um novo valor a um objeto de **_variant_t** existente. |
| [operador = =,! =](../cpp/variant-t-relational-operators.md) | Compare dois objetos **_variant_t** para igualdade ou desigualdade. |
| [Extratores](../cpp/variant-t-extractors.md) | Extrair dados do objeto encapsulado `VARIANT` . |

**FINAL específico da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<comutil.h>

**Lib:** comsuppw. lib ou comsuppwd. lib (consulte [/Zc: Wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Classes de suporte de COM do compilador](../cpp/compiler-com-support-classes.md)
