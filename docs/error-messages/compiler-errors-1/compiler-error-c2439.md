---
title: C2439 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2439
dev_langs:
- C++
helpviewer_keywords:
- C2439
ms.assetid: 3c5dbe5c-b7d3-4bb0-8619-92f6e280461e
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6aa5c0dcfd12be6979b0872f001bf0bf26a6e6e7
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2439"></a>C2439 de erro do compilador
'Identificador': membro não pôde ser inicializado  
  
 Uma classe, estrutura ou membro de união não pode ser inicializado.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Tentativa de inicializar uma estrutura ou classe base indireta.  
  
2.  Tentativa de inicializar um membro herdado de uma classe ou estrutura. Um membro herdado deve ser inicializado pelo construtor de classe ou estrutura.
