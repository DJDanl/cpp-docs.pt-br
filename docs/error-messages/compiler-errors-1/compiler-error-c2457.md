---
title: C2457 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2457
dev_langs: C++
helpviewer_keywords: C2457
ms.assetid: 347e169d-23ad-434f-8836-5b09b53980ff
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 915baebbcc2b9b18b277d78f32868374c194d6ef
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="compiler-error-c2457"></a>C2457 de erro do compilador

> '*macro*': macro predefinida não pode aparecer fora de um corpo de função

Você tentou usar uma macro predefinida, como [&#95; &#95; FUNÇÃO &#95; &#95; ](../../preprocessor/predefined-macros.md), em um espaço global.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2457 e também mostra o uso correto:

```cpp
// C2457.cpp
#include <stdio.h>

__FUNCTION__;   // C2457, cannot be global

int main()
{
    printf_s("\n%s", __FUNCTION__);   // OK
}
```