---
title: Erro do compilador C2818
ms.date: 11/04/2016
f1_keywords:
- C2818
helpviewer_keywords:
- C2818
ms.assetid: 715fc7c9-0c6d-452b-b7f5-1682cea5e907
ms.openlocfilehash: f6e33d0e0ee139138df7d8e11357100b3ec3a1a9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50593434"
---
# <a name="compiler-error-c2818"></a>Erro do compilador C2818

'aplicativo de operador ->' sobrecarregado é recursiva através do tipo 'type'

Uma redefinição do operador de acesso de membro de classe contém uma recursiva `return` instrução. Para redefinir o `->` operador com a recursão, você deve mover a rotina recursiva para uma função distinta chamada do operador substitui a função.