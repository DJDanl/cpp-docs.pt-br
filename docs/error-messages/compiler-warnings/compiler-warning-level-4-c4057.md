---
title: Compilador aviso (nível 4) C4057
ms.date: 11/04/2016
f1_keywords:
- C4057
helpviewer_keywords:
- C4057
ms.assetid: e75d0645-84c9-4bef-a812-942ed9879aa3
ms.openlocfilehash: 234223ee7b6a031dd9e2c0fc88ccbbdba05beb3c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401430"
---
# <a name="compiler-warning-level-4-c4057"></a>Compilador aviso (nível 4) C4057

'operator': indireção de 'identifier1' para tipos base ligeiramente diferentes de 'identifier2'

Duas expressões de ponteiro se referem a diferentes tipos de base. As expressões são usadas sem conversão.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Misturar tipos assinados e não assinados.

1. Misturar **curto** e **longo** tipos.