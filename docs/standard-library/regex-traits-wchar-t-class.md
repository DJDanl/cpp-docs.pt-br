---
title: Classe regex_traits&lt;wchar_t&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- regex/std::regex_traits<wchar_t>
dev_langs:
- C++
helpviewer_keywords:
- regex_traits<wchar_t> class
ms.assetid: 288d6fdb-fb8e-4a4d-904a-53916be7f95b
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 19403ce75bd453754617167b2d6a26cc0a8deec8
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="regextraitsltwchartgt-class"></a>Classe regex_traits&lt;wchar_t&gt;

Especialização de regex_traits para wchar_t.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class regex_traits<wchar_t>
```

## <a name="remarks"></a>Comentários

A classe é uma especialização explícita da classe de modelo [regex_traits](../standard-library/regex-traits-class.md) para elementos do tipo `wchar_t` (de forma que possa aproveitar as funções da biblioteca que manipulam objetos desse tipo).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<regex>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<regex>](../standard-library/regex.md)<br/>
[Classe regex_constants](../standard-library/regex-constants-class.md)<br/>
[Classe regex_error](../standard-library/regex-error-class.md)<br/>
[\<Funções regex>](../standard-library/regex-functions.md)<br/>
[Classe regex_iterator](../standard-library/regex-iterator-class.md)<br/>
[\<Operadores regex>](../standard-library/regex-operators.md)<br/>
[Classe regex_token_iterator](../standard-library/regex-token-iterator-class.md)<br/>
[Classe regex_traits](../standard-library/regex-traits-class.md)<br/>
[\<Typedef regex>](../standard-library/regex-typedefs.md)<br/>
