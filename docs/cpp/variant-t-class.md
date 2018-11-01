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
ms.openlocfilehash: 69976cab9caed653a8278f80821569b613f690eb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50502733"
---
# <a name="variantt-class"></a>Classe _variant_t

**Seção específica da Microsoft**

Um **variant_t** objeto encapsula o `VARIANT` tipo de dados. A classe gerencia a alocação de recursos e a desalocação e faz chamadas de função `VariantInit` e `VariantClear` conforme apropriado.

### <a name="construction"></a>Construção

|||
|-|-|
|[_variant_t](../cpp/variant-t-variant-t.md)|Constrói uma **variant_t** objeto.|

### <a name="operations"></a>Operações

|||
|-|-|
|[Anexar](../cpp/variant-t-attach.md)|Anexa uma `VARIANT` do objeto para o **variant_t** objeto.|
|[Limpar](../cpp/variant-t-clear.md)|Limpa encapsulado `VARIANT` objeto.|
|[ChangeType](../cpp/variant-t-changetype.md)|Altera o tipo dos **variant_t** objeto a ser indicado `VARTYPE`.|
|[Desanexar](../cpp/variant-t-detach.md)|Desanexa encapsulado `VARIANT` objeto desta **variant_t** objeto.|
|[SetString](../cpp/variant-t-setstring.md)|Atribui uma cadeia de caracteres a este **variant_t** objeto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](../cpp/variant-t-operator-equal.md)|Atribui um novo valor a um existente **variant_t** objeto.|
|[operador = =,! =](../cpp/variant-t-relational-operators.md)|Comparar duas **variant_t** objetos para igualdade ou desigualdade.|
|[Extratores](../cpp/variant-t-extractors.md)|Extrair dados de encapsulado `VARIANT` objeto.|

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<comutil. h >

**Lib:** comsuppw. lib ou comsuppwd (consulte [/ZC: wchar_t (wchar_t Is Native Type)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Consulte também

[Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)