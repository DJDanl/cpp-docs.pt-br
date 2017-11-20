---
title: Compilador erro C2261 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2261
dev_langs: C++
helpviewer_keywords: C2261
ms.assetid: 60969482-9e83-49b5-9631-a04bc844da12
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 8269b891ed899501625973b81c1823d4db2d56c8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2261"></a>C2261 de erro do compilador
'string': referência de assembly é inválida e não pode ser resolvida  
  
 Um valor não era válido.  
  
 <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute>é usado para especificar um assembly friend. Por exemplo, se quiser. dll especificar o b. dll como um assembly autorizado, você especificaria (em. dll): InternalsVisibleTo("b"). O tempo de execução, em seguida, permite que o b. dll acessar todo o conteúdo do. dll (exceto tipos privados).  
  
 Para obter mais informações sobre a sintaxe correta ao especificar assemblies amigáveis, consulte [Friend Assemblies (C++)](../../dotnet/friend-assemblies-cpp.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2261.  
  
```  
// C2261.cpp  
// compile with: /clr /c  
using namespace System::Runtime::CompilerServices;  
[assembly: InternalsVisibleTo("a,a,a")];   // C2261  
[assembly: InternalsVisibleTo("a.a")];   // OK  
[assembly: InternalsVisibleTo("a")];   // OK  
```