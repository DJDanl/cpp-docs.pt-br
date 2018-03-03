---
title: "Compilador (nível 1) de aviso C4711 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4711
dev_langs:
- C++
helpviewer_keywords:
- C4711
ms.assetid: 270506ab-fead-4328-b714-2978113be238
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d9be609e0900ad5aea5011fbd880b7952e3e71cb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4711"></a>Compilador C4711 de aviso (nível 1)
função selecionada para expansão inline ' function'  
  
 O compilador executada inlining em determinada função, embora ele não foi marcado para inlining.  
  
 C4711 estará habilitada se [/Ob2](../../build/reference/ob-inline-function-expansion.md) for especificado.  
  
 Inlining é executada a critério do compilador. Esse aviso é informativo.  
  
 Esse aviso é desativada por padrão. Para habilitar um aviso, use [#pragma aviso](../../preprocessor/warning.md). Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.