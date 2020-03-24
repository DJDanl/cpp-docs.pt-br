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
ms.openlocfilehash: e11d31904fd8e54049f69ee4f6530d511c8c7f4e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187746"
---
# <a name="_variant_t-class"></a>Classe _variant_t

**Seção específica da Microsoft**

Um objeto **_variant_t** encapsula o tipo de dados `VARIANT`. A classe gerencia a alocação de recursos e a desalocação e faz chamadas de função para `VariantInit` e `VariantClear` conforme apropriado.

### <a name="construction"></a>Construção

|||
|-|-|
|[_variant_t](../cpp/variant-t-variant-t.md)|Constrói um objeto **_variant_t** .|

### <a name="operations"></a>Operações

|||
|-|-|
|[Anexar](../cpp/variant-t-attach.md)|Anexa um objeto `VARIANT` ao objeto **_variant_t** .|
|[Limpar](../cpp/variant-t-clear.md)|Limpa o objeto de `VARIANT` encapsulado.|
|[ChangeType](../cpp/variant-t-changetype.md)|Altera o tipo do objeto **_variant_t** para o `VARTYPE`indicado.|
|[Desanexar](../cpp/variant-t-detach.md)|Desanexa o objeto de `VARIANT` encapsulado deste objeto **_variant_t** .|
|[SetString](../cpp/variant-t-setstring.md)|Atribui uma cadeia de caracteres a este **_variant_t** objeto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[Operador =](../cpp/variant-t-operator-equal.md)|Atribui um novo valor a um objeto de **_variant_t** existente.|
|[operador = =,! =](../cpp/variant-t-relational-operators.md)|Compare dois objetos **_variant_t** para igualdade ou desigualdade.|
|[Extratores](../cpp/variant-t-extractors.md)|Extrair dados do objeto de `VARIANT` encapsulado.|

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<fileutil. h >

**Lib:** comsuppw. lib ou comsuppwd. lib (consulte [/Zc: Wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)
