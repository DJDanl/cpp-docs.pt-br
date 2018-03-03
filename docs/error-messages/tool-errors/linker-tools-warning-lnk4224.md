---
title: Aviso LNK4224 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4224
dev_langs:
- C++
helpviewer_keywords:
- LNK4224
ms.assetid: 8624b70e-0b93-43cf-b457-834d38632d0b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 96399e0c66eb3cb719073b2318513cd680723d97
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4224"></a>Aviso LNK4224 (Ferramentas de Vinculador)
Não há suporte para a opção; ignorado  
  
 Uma opção de vinculador obsoleto, inválido foi especificada e ignorada.  
  
 Por exemplo, LNK4224 pode ocorrer se uma diretiva /comment aparece em. obj. A diretiva /comment foram adicionada por meio de [comentário (C/C++)](../../preprocessor/comment-c-cpp.md) pragma, usando a opção exestr preterido. Use dumpbin [/All](../../build/reference/all.md) para exibir as diretivas de vinculador em um arquivo. obj.  
  
 Se possível, modifique a fonte para o. obj e remova o pragma. Se você ignorar este aviso, é possível que um .executable compilado com **/clr: pure** não funcionará como esperado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK4224.  
  
```  
// LNK4224.cpp  
// compile with: /c /Zi  
// post-build command: link LNK4224.obj /debug /debugtype:map  
int main () {  
   return 0;  
}  
```