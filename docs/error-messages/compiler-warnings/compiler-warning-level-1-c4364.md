---
title: "Compilador aviso (nível 1) C4364 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4364
dev_langs:
- C++
helpviewer_keywords:
- C4364
ms.assetid: 1477634c-d60f-4570-ad16-1aaeae24ac7f
caps.latest.revision: 8
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
ms.openlocfilehash: 7fc63c4d11c7d309cbfdb97769f6d26e986aa971
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4364"></a>Compilador C4364 de aviso (nível 1)
\#usando para o assembly 'arquivo' visto anteriormente em location(line_number) sem as_friend atributo; as_friend não aplicado  
  
 A `#using` diretiva foi repetida para um arquivo de metadados específico, mas o `as_friend` qualificador não foi usado na primeira ocorrência; o compilador irá ignorar o segundo `as_friend`.  
  
 Para obter mais informações, consulte [Friend Assemblies (C++)](../../dotnet/friend-assemblies-cpp.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um componente.  
  
```  
// C4364.cpp  
// compile with: /clr /LD  
ref class A {};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4364.  
  
```  
// C4364_b.cpp  
// compile with: /clr /W1 /c  
#using " C4364.dll"  
#using " C4364.dll" as_friend   // C4364  
```
