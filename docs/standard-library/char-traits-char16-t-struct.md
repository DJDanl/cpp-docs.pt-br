---
title: Struct char_traits&lt;char16_t&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- char_traits<char16_t>
- iosfwd/std::char_traits<char16_t>
dev_langs:
- C++
helpviewer_keywords:
- char_traits<char16_t> class
ms.assetid: 5daf3b62-dd6e-451f-b189-0350a04ff966
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b76839dee5df211331f10f11e20ab9a45a2f4eeb
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="chartraitsltchar16tgt-struct"></a>Struct char_traits&lt;char16_t&gt;

Uma struct é uma especialização da struct de modelo **char_traits\<CharType>** para um elemento do tipo `char16_t`.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<char16_t>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos do tipo `char16_t`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<string>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<string>](../standard-library/string.md)<br/>
[Struct char_traits](../standard-library/char-traits-struct.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
