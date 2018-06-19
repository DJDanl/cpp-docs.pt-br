---
title: Compilador (nível 4) de aviso C4057 | Microsoft Docs
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
ms.openlocfilehash: 3217ccb0a96fbe02e152ff82dedeb7e8e54b89ea
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292273"
---
# <a name="compiler-warning-level-4-c4057"></a>Compilador C4057 de aviso (nível 4)
'operator': indireção de 'identifier1' para tipos base ligeiramente diferentes de 'identifier2'  
  
 Duas expressões de ponteiro consultem diferentes tipos de base. As expressões são usadas sem conversão.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Misturar tipos assinados e não assinados.  
  
2.  Mesclando **curto** e **longo** tipos.