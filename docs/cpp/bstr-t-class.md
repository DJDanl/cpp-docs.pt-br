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
ms.openlocfilehash: 3ef89c6f6742d528c427c49fd2a62d8820625e79
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190372"
---
# <a name="_bstr_t-class"></a>Classe _bstr_t

**Seção específica da Microsoft**

Um objeto `_bstr_t` encapsula o [tipo de dados BSTR](/previous-versions/windows/desktop/automat/bstr). A classe gerencia a alocação de recursos e a desalocação por meio de chamadas de função para `SysAllocString` e `SysFreeString` e outras APIs de `BSTR` quando apropriado. A classe **_bstr_t** usa a contagem de referência para evitar sobrecarga excessiva.

### <a name="construction"></a>Construção

|||
|-|-|
|[_bstr_t](../cpp/bstr-t-bstr-t.md)|Constrói um objeto `_bstr_t`.|

### <a name="operations"></a>Operações

|||
|-|-|
|[Assign](../cpp/bstr-t-assign.md)|Copia um `BSTR` para o `BSTR` encapsulado por um `_bstr_t`.|
|[Anexar](../cpp/bstr-t-attach.md)|Vincula um wrapper `_bstr_t` a um `BSTR`.|
|[copy](../cpp/bstr-t-copy.md)|Constrói uma cópia do `BSTR` encapsulado.|
|[Desanexar](../cpp/bstr-t-detach.md)|Retorna o `BSTR` encapsulado por um `_bstr_t` e desanexa o `BSTR` do `_bstr_t`.|
|[GetAddress](../cpp/bstr-t-getaddress.md)|Aponta para o `BSTR` encapsulado por um `_bstr_t`.|
|[Getbstr](../cpp/bstr-t-getbstr.md)|Aponta para o início do `BSTR` encapsulado por `_bstr_t`.|
|[length](../cpp/bstr-t-length.md)|Retorna o número de caracteres no `_bstr_t`.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](../cpp/bstr-t-operator-equal.md)|Atribui um novo valor a um objeto `_bstr_t` existente.|
|[operador + =](../cpp/bstr-t-operator-add-equal-plus.md)|Acrescenta caracteres ao final do objeto `_bstr_t`.|
|[operador +](../cpp/bstr-t-operator-add-equal-plus.md)|Concatena duas cadeias de caracteres.|
|[operador !](../cpp/bstr-t-operator-logical-not.md)|Verifica se o `BSTR` encapsulado é uma cadeia de caracteres nula.|
|[Operator = =,! =, \<, >, \<=, > =](../cpp/bstr-t-relational-operators.md)|Compara dois objetos `_bstr_t`.|
|[operador wchar_t * &#124; Char\*](../cpp/bstr-t-wchar-t-star-bstr-t-char-star.md)|Extrai os ponteiros para o objeto `BSTR` Unicode ou multibyte encapsulado.|

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<fileutil. h >

**Lib:** comsuppw. lib ou comsuppwd. lib (consulte [/Zc: Wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)
