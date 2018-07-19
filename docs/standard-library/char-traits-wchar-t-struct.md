---
title: Struct char_traits&lt;wchar_t&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- char_traits<wchar_t>
- iosfwd/std::char_traits<wchar_t>
dev_langs:
- C++
helpviewer_keywords:
- char_traits<wchar_t> class
ms.assetid: 31f34072-04d6-4871-88fe-48e17d473484
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c7d8b87b51bfeef68ef8bfe22c8e7e201929aa3f
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38957068"
---
# <a name="chartraitsltwchartgt-struct"></a>Struct char_traits&lt;wchar_t&gt;

Uma classe que é uma especialização da struct de modelo **char_traits\<CharType >** a um elemento do tipo **wchar_t**.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<wchar_t>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos desse tipo de **wchar_t**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<string>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Struct char_traits](../standard-library/char-traits-struct.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
