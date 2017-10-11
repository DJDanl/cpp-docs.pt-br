---
title: C2415 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2415
dev_langs:
- C++
helpviewer_keywords:
- C2415
ms.assetid: f225c913-2bea-46b1-b096-3d358ac94a15
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 68666ba203897b43fb1658525e1f342bcb923c09
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2415"></a>C2415 de erro do compilador
tipo de operando inadequada  
  
 O opcode não usa operandos desse tipo.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O código de operação não oferece suporte para o número de operandos usados. Verificar um manual de referência de linguagem de assembly para determinar o número correto de operandos.  
  
2.  Um processador mais recente der suporte à instrução com tipos adicionais. Ajustar o [/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md) opção para usar o processador posterior.
