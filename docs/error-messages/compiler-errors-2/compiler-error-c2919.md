---
title: Erro do compilador C2919
ms.date: 11/04/2016
f1_keywords:
- C2919
helpviewer_keywords:
- C2919
ms.assetid: 140a6db9-eb48-4c5e-84a7-a09d2653605b
ms.openlocfilehash: 624b3ab47ccb1c934b612ec8648b5eee0d233690
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176969"
---
# <a name="compiler-error-c2919"></a>Erro do compilador C2919

' type ': os operadores não podem ser usados na superfície publicada de um tipo WinRT

O sistema do tipo Windows Runtime não oferece suporte a funções de membro de operador na superfície publicada de um tipo. Isso ocorre porque nem todas as linguagens podem consumir funções de membro do operador. Você pode criar funções de membro de operador privado ou interno que podem ser C++ chamadas a partir do código na mesma classe ou unidade de compilação.

Para corrigir esse problema, remova a função de membro de operador da interface pública ou altere-a para uma função de membro nomeada. Por exemplo, em vez de `operator==`, nomeie a função de membro `Equals`.
