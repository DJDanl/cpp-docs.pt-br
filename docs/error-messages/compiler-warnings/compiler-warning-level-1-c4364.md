---
title: Compilador (nível 1) de aviso C4364 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4364
dev_langs:
- C++
helpviewer_keywords:
- C4364
ms.assetid: 1477634c-d60f-4570-ad16-1aaeae24ac7f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fb3bfb8075d618a6d2ea9b733b01d8b456fdc0e7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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