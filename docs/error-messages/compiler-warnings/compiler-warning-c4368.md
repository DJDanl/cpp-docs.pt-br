---
title: C4368 de aviso do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4368
dev_langs:
- C++
helpviewer_keywords:
- C4368
ms.assetid: cb85bcee-fd3d-4aa5-b626-2324f07a4f1b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a3a7e53c979a3b13bde205a4546c486061a17110
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33270490"
---
# <a name="compiler-warning-c4368"></a>C4368 de aviso do compilador
não é possível definir 'member' como um membro de gerenciado 'type': não há suporte para tipos mistos  
  
 Não é possível inserir um membro de dados nativo em um tipo CLR.  
  
 No entanto, você pode declarar um ponteiro para um tipo nativo e controlar seu tempo de vida no construtor e destruidor e o finalizador da sua classe gerenciada. Para obter mais informações, consulte [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).  
  
 Esse aviso é emitido sempre como um erro. Use o [aviso](../../preprocessor/warning.md) pragma desabilitar C4368.  
  
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