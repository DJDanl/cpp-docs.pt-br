---
title: Compilador aviso (nível 3) C4306 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: error-reference
f1_keywords:
- C4306
dev_langs:
- C++
helpviewer_keywords:
- C4306
ms.assetid: 5b2192d7-402d-4b6d-8619-08105e7dcac7
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c341f968e8484228431c9ca870b7cdc5ae5bb6e0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4306"></a>Compilador C4306 de aviso (nível 3)
**'**   
 ***identificador* ': conversão de '**   
 ***type1* 'para'**   
 ***type2* ' de tamanho maior**  
  
 O identificador é o tipo convertido para um ponteiro maior. Os bits altos preenchidos do novo tipo serão preenchidas com zeros.  
  
 Esse aviso pode indicar uma conversão indesejada. O ponteiro resultante pode não ser válido.