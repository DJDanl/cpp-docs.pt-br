---
title: Classe _bstr_t
ms.date: 11/04/2016
f1_keywords:
- _bstr_t
helpviewer_keywords:
- BSTR object
- _bstr_t class
- BSTR object [C++], COM encapsulation
ms.assetid: 58841fef-fe21-4a84-aab9-780262b5201f
ms.openlocfilehash: f521681da10eeda3b8024b0865d5164021296353
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838705"
---
# <a name="_bstr_t-class"></a>Classe _bstr_t

**Específico da Microsoft**

Um `_bstr_t` objeto encapsula o [tipo de dados BSTR](/previous-versions/windows/desktop/automat/bstr). A classe gerencia a alocação de recursos e a desalocação por meio de chamadas de função para `SysAllocString` e `SysFreeString` e outras `BSTR` APIs quando apropriado. A classe **_bstr_t** usa a contagem de referência para evitar sobrecarga excessiva.

### <a name="construction"></a>Construção

| Construtor | Descrição |
|--|--|
| [_bstr_t](../cpp/bstr-t-bstr-t.md) | Constrói um objeto `_bstr_t`. |

### <a name="operations"></a>Operations

| Função | Descrição |
|--|--|
| [Assign](../cpp/bstr-t-assign.md) | Copia um `BSTR` para o `BSTR` encapsulado por um `_bstr_t`. |
| [Attach](../cpp/bstr-t-attach.md) | Vincula um wrapper `_bstr_t` a um `BSTR`. |
| [copy](../cpp/bstr-t-copy.md) | Constrói uma cópia do `BSTR` encapsulado. |
| [Desanexar](../cpp/bstr-t-detach.md) | Retorna o `BSTR` encapsulado por um `_bstr_t` e desanexa o `BSTR` do `_bstr_t`. |
| [GetAddress](../cpp/bstr-t-getaddress.md) | Aponta para o `BSTR` encapsulado por um `_bstr_t`. |
| [GetBSTR](../cpp/bstr-t-getbstr.md) | Aponta para o início do `BSTR` encapsulado por `_bstr_t`. |
| [length](../cpp/bstr-t-length.md) | Retorna o número de caracteres no `_bstr_t`. |

### <a name="operators"></a>Operadores

| Operador | Descrição |
|--|--|
| [operador =](../cpp/bstr-t-operator-equal.md) | Atribui um novo valor a um objeto `_bstr_t` existente. |
| [operador + =](../cpp/bstr-t-operator-add-equal-plus.md) | Acrescenta caracteres ao final do objeto `_bstr_t`. |
| [operador +](../cpp/bstr-t-operator-add-equal-plus.md) | Concatena duas cadeias de caracteres. |
| [operador!](../cpp/bstr-t-operator-logical-not.md) | Verifica se o encapsulado `BSTR` é uma cadeia de caracteres nula. |
| [operador = =,! =, \<, > , \<=, >=](../cpp/bstr-t-relational-operators.md) | Compara dois objetos `_bstr_t`. |
| [wchar_t do operador * &#124; Char\*](../cpp/bstr-t-wchar-t-star-bstr-t-char-star.md) | Extrai os ponteiros para o objeto `BSTR` Unicode ou multibyte encapsulado. |

**FINAL específico da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<comutil.h>

**Lib:** comsuppw. lib ou comsuppwd. lib (consulte [/Zc: Wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Classes de suporte de COM do compilador](../cpp/compiler-com-support-classes.md)
