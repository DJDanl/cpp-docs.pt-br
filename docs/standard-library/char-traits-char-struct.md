---
title: char_traits&lt;char&gt; Struct | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- iosfwd/std::char_traits<char>
- char_traits<char >
dev_langs:
- C++
helpviewer_keywords:
- char_traits<char> class
ms.assetid: abd9373a-77db-4031-bf4b-f8ac15087581
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5c74e00d9a1f8678539c4f722d48c409d1505b39
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="chartraitsltchargt-struct"></a>char_traits&lt;char&gt; Struct

Uma struct é uma especialização da struct de modelo **char_traits\<CharType>** para um elemento do tipo `char`.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<char>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos desse tipo `char`.

## <a name="example"></a>Exemplo

Consulte as funções de typedefs e membro da classe modelo [char_traits Class](../standard-library/char-traits-struct.md)
