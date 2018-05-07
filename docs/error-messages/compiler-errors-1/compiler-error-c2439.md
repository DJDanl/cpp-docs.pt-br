---
title: C2439 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2439
dev_langs:
- C++
helpviewer_keywords:
- C2439
ms.assetid: 3c5dbe5c-b7d3-4bb0-8619-92f6e280461e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33bfe8ebf00850a54020b2a3f21159daf28b7224
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2439"></a>C2439 de erro do compilador
'Identificador': membro não pôde ser inicializado  
  
 Uma classe, estrutura ou membro de união não pode ser inicializado.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Tentativa de inicializar uma estrutura ou classe base indireta.  
  
2.  Tentativa de inicializar um membro herdado de uma classe ou estrutura. Um membro herdado deve ser inicializado pelo construtor de classe ou estrutura.