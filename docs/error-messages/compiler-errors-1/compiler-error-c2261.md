---
title: Compilador erro C2261 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2261
dev_langs:
- C++
helpviewer_keywords:
- C2261
ms.assetid: 60969482-9e83-49b5-9631-a04bc844da12
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 45050daf3149cd813fb23b5814be5fe49c375f03
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2261"></a>C2261 de erro do compilador
'string': referência de assembly é inválida e não pode ser resolvida  
  
 Um valor não era válido.  
  
 <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> é usado para especificar um assembly friend. Por exemplo, se quiser. dll especificar o b. dll como um assembly autorizado, você especificaria (em. dll): InternalsVisibleTo("b"). O tempo de execução, em seguida, permite que o b. dll acessar todo o conteúdo do. dll (exceto tipos privados).  
  
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