---
title: Aviso LNK4224 das ferramentas de vinculador | Documentos do Microsoft
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
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bad6fb1eeac1454fac0904b15944e3bbb7893114
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4224"></a>Aviso LNK4224 (Ferramentas de Vinculador)
Não há suporte para a opção; ignorado  
  
 Uma opção de vinculador obsoleto, inválido foi especificada e ignorada.  
  
 Por exemplo, LNK4224 pode ocorrer se uma diretiva /comment aparece no. obj. A diretiva /comment seria foram adicionada por meio de [comentário (C/C++)](../../preprocessor/comment-c-cpp.md) pragma, usando a opção exestr preterido. Usar dumpbin [/ALL](../../build/reference/all.md) para exibir as diretivas de vinculador em um arquivo. obj.  
  
 Se possível, modifique a fonte para o. obj e remova o pragma. Se você ignorar este aviso, é possível que um .executable compilado com **/clr: puro** não será executado conforme o esperado.  
  
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
