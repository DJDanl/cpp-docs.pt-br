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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4ff0f423ec83b9951e806a2483417f3ab79f817a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2415"></a>C2415 de erro do compilador
tipo de operando inadequada  
  
 O opcode não usa operandos desse tipo.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  O código de operação não oferece suporte para o número de operandos usados. Verificar um manual de referência de linguagem de assembly para determinar o número correto de operandos.  
  
2.  Um processador mais recente der suporte à instrução com tipos adicionais. Ajustar o [/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md) opção para usar o processador posterior.