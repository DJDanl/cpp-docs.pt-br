---
title: Erro do compilador C2818
ms.date: 11/04/2016
f1_keywords:
- C2818
helpviewer_keywords:
- C2818
ms.assetid: 715fc7c9-0c6d-452b-b7f5-1682cea5e907
ms.openlocfilehash: 00952e55f1b732bd9af3733f5c0ec575a39116fe
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202090"
---
# <a name="compiler-error-c2818"></a>Erro do compilador C2818

o aplicativo de ' operator-> ' sobrecarregado é recursivo por meio do tipo ' type '

Uma redefinição do operador de acesso de membro de classe contém uma instrução de `return` recursiva. Para redefinir o operador de `->` com recursão, você deve mover a rotina recursiva para uma função separada chamada da função de substituição de operador.
