---
title: Compilador (nível 1) de aviso C4691 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4691
dev_langs:
- C++
helpviewer_keywords:
- C4691
ms.assetid: 722133d9-87f6-46c1-9e86-9825453d6999
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9dccce2468c83dd7d14596c1c26e19bd13ad1a70
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282591"
---
# <a name="compiler-warning-level-1-c4691"></a>Compilador C4691 de aviso (nível 1)
'type': tipo referenciado era esperado no assembly não referenciado 'file', tipo definido na unidade de tradução atual usada  
  
 O arquivo de metadados que contém a definição do tipo original não é referenciado e, em seguida, o compilador é usando uma definição de tipo local.  
  
 No caso em que você estiver recriando *arquivo*, pode ser ignorado ou desativado com pragma C4691 [aviso](../../preprocessor/warning.md).  Ou seja, se o arquivo que você está criando é o mesmo que o arquivo onde o compilador espera encontrar a definição de tipo, você pode ignorar C4691.  
  
 No entanto, pode ocorrer um comportamento inesperado se o compilador usa uma definição que não seja do mesmo assembly que é referenciado nos metadados; Tipos CLR são digitados não apenas pelo nome do tipo, mas também pelo assembly.  Ou seja, um tipo Z do assembly z.dll é diferente de um tipo Z do assembly y.dll.  
  
## <a name="example"></a>Exemplo  
 Este exemplo contém a definição do tipo original.  
  
```  
// C4691_a.cpp  
// compile with: /clr /LD /W1  
public ref class Original_Type {};  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo faz referência a C4691_a.dll e declara um campo do tipo Original_Type.  
  
```  
// C4691_b.cpp  
// compile with: /clr /LD  
#using "C4691_a.dll"  
public ref class Client {  
public:  
   Original_Type^ ot;  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4691.  Observe que esse exemplo contém uma definição para Original_Type e não faz referência a C4691a.dll.  
  
 Para resolver, fazer referência ao arquivo de metadados que contém a definição do tipo original e remova a declaração de local e a definição.  
  
```  
// C4691_c.cpp  
// compile with: /clr /LD /W1  
// C4691 expected  
  
// Uncomment the following line to resolve.  
// #using "C4691_a.dll"  
#using "C4691_b.dll"  
  
// Delete the following line to resolve.  
ref class Original_Type;  
  
public ref class MyClass : Client {};  
```