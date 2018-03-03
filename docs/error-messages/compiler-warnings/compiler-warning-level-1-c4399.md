---
title: "Compilador (nível 1) de aviso C4399 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4399
dev_langs:
- C++
helpviewer_keywords:
- C4399
ms.assetid: f58d9ba7-71a0-4c3b-b26f-f946dda8af30
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eff01c29d423b0823b41bf63702cf42ee839a523
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4399"></a>Compilador C4399 de aviso (nível 1)
'symbol': símbolo per-process não deve ser marcado com __declspec(dllimport) quando compilado com /clr: pure  
  
 O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015.  
  
 Dados de uma imagem nativa ou uma imagem com nativo e construções CLR não podem ser importados em uma imagem pura. Para resolver este aviso, compile com **/clr** (não **/clr: pure**) ou excluir `__declspec(dllimport)`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4399.  
  
```  
// C4399.cpp  
// compile with: /clr:pure /doc /W1 /c  
__declspec(dllimport) __declspec(process) extern const int i;   // C4399  
```