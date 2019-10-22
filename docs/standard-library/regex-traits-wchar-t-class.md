---
title: Classe regex_traits&lt;wchar_t&gt;
ms.date: 09/10/2018
f1_keywords:
- regex/std::regex_traits<wchar_t>
helpviewer_keywords:
- regex_traits<wchar_t> class
ms.assetid: 288d6fdb-fb8e-4a4d-904a-53916be7f95b
ms.openlocfilehash: 31c47e43996ee0d6d8a495c0ff294e296b4b5888
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72686655"
---
# <a name="regex_traitsltwchar_tgt-class"></a>Classe regex_traits&lt;wchar_t&gt;

Especialização de `regex_traits` para **wchar_t**.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class regex_traits<wchar_t>
```

## <a name="remarks"></a>Comentários

A classe é uma especialização explícita do modelo de classe [regex_traits](../standard-library/regex-traits-class.md) para elementos do tipo **wchar_t** (para que ele possa tirar proveito das funções de biblioteca que manipulam objetos desse tipo).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<regex>](../standard-library/regex.md)\
\ [classe regex_constants](../standard-library/regex-constants-class.md)
\ [classe regex_error](../standard-library/regex-error-class.md)
[\<regex > funções](../standard-library/regex-functions.md) \
\ [Classe regex_iterator](../standard-library/regex-iterator-class.md)
[operadores de > de \<regex](../standard-library/regex-operators.md) \
\ [classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)
\ [Classe regex_traits](../standard-library/regex-traits-class.md)
[\<Typedef regex>](../standard-library/regex-typedefs.md)
