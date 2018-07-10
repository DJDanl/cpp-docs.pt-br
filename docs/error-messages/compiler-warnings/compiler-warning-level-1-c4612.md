---
title: Compilador (nível 1) de aviso C4612 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4612
dev_langs:
- C++
helpviewer_keywords:
- C4612
ms.assetid: 21ac02b2-51cd-4aff-9b70-d543511d5962
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0983f5d0bb89eaf1daee94468b318557bc83cd05
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33281876"
---
# <a name="compiler-warning-level-1-c4612"></a>Compilador C4612 de aviso (nível 1)
Erro ao incluir o nome de arquivo  
  
 Este aviso ocorre com **#pragma include_alias** quando um nome de arquivo está incorreta ou ausente.  
  
 Os argumentos para o **#pragma include_alias** instrução pode usar a cotação de (**"***filename***"**) ou colchete angular ( **\< ***filename***>**), mas ambos devem usar o mesmo formulário.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4612.cpp  
// compile with: /W1 /LD  
#pragma include_alias("StandardIO", <stdio.h>) // C4612  
```