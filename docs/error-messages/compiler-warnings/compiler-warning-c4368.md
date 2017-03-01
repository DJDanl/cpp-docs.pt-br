---
title: C4368 de aviso do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4368
dev_langs:
- C++
helpviewer_keywords:
- C4368
ms.assetid: cb85bcee-fd3d-4aa5-b626-2324f07a4f1b
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a0c5ece0081f34c14a1e78050e612fc80d7dd658
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-c4368"></a>C4368 de aviso do compilador
não é possível definir 'member' como um membro do tipo' gerenciado': não há suporte para tipos mistos  
  
 Você não pode incorporar um membro de dados nativo em um tipo CLR.  
  
 No entanto, você pode declarar um ponteiro para um tipo nativo e controlar seu tempo de vida no construtor e destruidor e o finalizador da classe gerenciada. Para obter mais informações, consulte [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).  
  
 Esse aviso é emitido sempre que um erro. Use o [aviso](../../preprocessor/warning.md) pragma para desabilitar C4368.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4368.  
  
```  
// C4368.cpp  
// compile with: /clr /c  
struct N {};  
ref struct O {};  
ref struct R {  
    R() : m_p( new N ) {}  
    ~R() { delete m_p; }  
  
   property N prop;   // C4368  
   int i[10];   // C4368  
  
   property O ^ prop2;   // OK  
   N * m_p;   // OK  
};  
```
