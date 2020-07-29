---
title: Erro do compilador C2818
ms.date: 11/04/2016
f1_keywords:
- C2818
helpviewer_keywords:
- C2818
ms.assetid: 715fc7c9-0c6d-452b-b7f5-1682cea5e907
ms.openlocfilehash: 786a38aca2c3b9674969018d9e5766eed29c358c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212664"
---
# <a name="compiler-error-c2818"></a>Erro do compilador C2818

o aplicativo de ' operator-> ' sobrecarregado é recursivo por meio do tipo ' type '

Uma redefinição do operador de acesso de membro de classe contém uma **`return`** instrução recursiva. Para redefinir o `->` operador com recursão, você deve mover a rotina recursiva para uma função separada chamada da função de substituição de operador.
