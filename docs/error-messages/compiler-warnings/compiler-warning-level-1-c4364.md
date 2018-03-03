---
title: "Compilador (nível 1) de aviso C4364 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4364
dev_langs:
- C++
helpviewer_keywords:
- C4364
ms.assetid: 1477634c-d60f-4570-ad16-1aaeae24ac7f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9d532ff9cc030c92543bec898f34daf3559531f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4364"></a>Compilador C4364 de aviso (nível 1)
\#usando para o assembly 'file' visto anteriormente em location(line_number) sem atributo as_friend; as_friend não aplicado  
  
 Um `#using` diretiva foi repetida para um arquivo de metadados fornecidos, mas o `as_friend` qualificador não foi usado na primeira ocorrência; o compilador irá ignorar o segundo `as_friend`.  
  
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