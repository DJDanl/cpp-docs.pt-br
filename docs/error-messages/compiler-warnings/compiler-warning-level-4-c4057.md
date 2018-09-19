---
title: Compilador aviso (nível 4) C4057 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4057
dev_langs:
- C++
helpviewer_keywords:
- C4057
ms.assetid: e75d0645-84c9-4bef-a812-942ed9879aa3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b10ce6b67fd24b4b8db01177af0225deab9dba4b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088001"
---
# <a name="compiler-warning-level-4-c4057"></a>Compilador aviso (nível 4) C4057

'operator': indireção de 'identifier1' para tipos base ligeiramente diferentes de 'identifier2'

Duas expressões de ponteiro se referem a diferentes tipos de base. As expressões são usadas sem conversão.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Misturar tipos assinados e não assinados.

1. Misturar **curto** e **longo** tipos.