---
title: Aviso do compilador (nível 4) C4057
ms.date: 11/04/2016
f1_keywords:
- C4057
helpviewer_keywords:
- C4057
ms.assetid: e75d0645-84c9-4bef-a812-942ed9879aa3
ms.openlocfilehash: d0bae91af3c2bfed97e252a74232e2a1bd778347
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225287"
---
# <a name="compiler-warning-level-4-c4057"></a>Aviso do compilador (nível 4) C4057

' operator ': indireção ' identifier1 ' para tipos base ligeiramente diferentes de ' identifier2 '

Duas expressões de ponteiro se referem a tipos de base diferentes. As expressões são usadas sem conversão.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Combinação de tipos assinados e não assinados.

1. Combinação **`short`** e **`long`** tipos.
