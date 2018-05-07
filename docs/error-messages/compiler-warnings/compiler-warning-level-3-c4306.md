---
title: Compilador aviso (nível 3) C4306 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4306
dev_langs:
- C++
helpviewer_keywords:
- C4306
ms.assetid: 5b2192d7-402d-4b6d-8619-08105e7dcac7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 99a490fc90ee9a977442548406ea2aec4baac3fd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4306"></a>Compilador C4306 de aviso (nível 3)
**'**   
 ***identificador* ': conversão de '**   
 ***type1* 'para'**   
 ***type2* ' de tamanho maior**  
  
 O identificador é o tipo convertido para um ponteiro maior. Os bits altos preenchidos do novo tipo serão preenchidas com zeros.  
  
 Esse aviso pode indicar uma conversão indesejada. O ponteiro resultante pode não ser válido.