---
title: Ferramentas de vinculador LNK2033 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2033
dev_langs:
- C++
helpviewer_keywords:
- LNK2033
ms.assetid: d61db467-9328-4788-bf54-e2a20537f13f
caps.latest.revision: 3
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8005ac3c75272b9aea00b98a344b5407f111b429
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2033"></a>Erro das Ferramentas de Vinculador LNK2033
token não resolvidos typeref (token) para 'type'  
  
 Um tipo não tem uma definição nos metadados MSIL.  
  
 LNK2033 pode ocorrer durante a compilação com **/CLR: safe** e onde há apenas uma declaração de encaminhamento para um tipo em um módulo MSIL, onde o tipo é referenciado no módulo MSIL.  
  
 O tipo deve ser definido em **/CLR: safe**.  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK2033.  
  
```  
// LNK2033.cpp  
// compile with: /clr:safe  
// LNK2033 expected  
ref class A;  
ref class B {};  
  
int main() {  
   A ^ aa = nullptr;  
   B ^ bb = nullptr;   // OK  
};  
```
