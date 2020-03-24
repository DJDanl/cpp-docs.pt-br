---
title: Aviso do compilador (nível 4) C4057
ms.date: 11/04/2016
f1_keywords:
- C4057
helpviewer_keywords:
- C4057
ms.assetid: e75d0645-84c9-4bef-a812-942ed9879aa3
ms.openlocfilehash: 45d2db56a7b0fc871de60743954012faf0f5c366
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185380"
---
# <a name="compiler-warning-level-4-c4057"></a>Aviso do compilador (nível 4) C4057

' operator ': indireção ' identifier1 ' para tipos base ligeiramente diferentes de ' identifier2 '

Duas expressões de ponteiro se referem a tipos de base diferentes. As expressões são usadas sem conversão.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Combinação de tipos assinados e não assinados.

1. Combinação de tipos **curtos** e **longos** .
