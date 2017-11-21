---
title: "Compilador aviso (nível 3) C4306 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4306
dev_langs: C++
helpviewer_keywords: C4306
ms.assetid: 5b2192d7-402d-4b6d-8619-08105e7dcac7
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2545a039244d90d3f32a82e2beb950dcddb5185c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-3-c4306"></a>Compilador C4306 de aviso (nível 3)
**'**   
 ***identificador* ': conversão de '**   
 ***type1* 'para'**   
 ***type2* ' de tamanho maior**  
  
 O identificador é o tipo convertido para um ponteiro maior. Os bits altos preenchidos do novo tipo serão preenchidas com zeros.  
  
 Esse aviso pode indicar uma conversão indesejada. O ponteiro resultante pode não ser válido.