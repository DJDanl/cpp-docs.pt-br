---
title: Erro do compilador C3646 | Microsoft Docs
ms.custom: ''
ms.date: 06/14/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3646
dev_langs:
- C++
helpviewer_keywords:
- C3646
ms.assetid: 4391ead2-9637-4ca3-aeda-5a991b18d66d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c038520c1a35fa5264e1e98b074687efb336d028
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "35658605"
---
# <a name="compiler-error-c3646"></a>Erro do compilador C3646

> 'especificador de ': especificador de substituição desconhecido

## <a name="remarks"></a>Comentários

O compilador não encontrou um token na posição em que ele esperava-se encontrar um especificador de substituição, mas o token não foi reconhecido pelo compilador.

Por exemplo, se o não reconhecido *especificador* é **_NOEXCEPT**, substitua-o com a palavra-chave **noexcept**.

Para obter mais informações, consulte [especificadores de substituição](../../windows/override-specifiers-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3646 e mostra uma maneira de corrigir isso:

```cpp
// C3646.cpp
// compile with: /clr /c
ref class C {
   void f() unknown;   // C3646
   // try the following line instead
   // virtual void f() abstract;
};
```