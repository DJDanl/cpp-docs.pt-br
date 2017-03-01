---
title: Erro do compilador c2261 () | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2261
dev_langs:
- C++
helpviewer_keywords:
- C2261
ms.assetid: 60969482-9e83-49b5-9631-a04bc844da12
caps.latest.revision: 9
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
ms.openlocfilehash: 6e3f6dc3ae3c603a090e37451f0bb09f6eece6fd
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2261"></a>Erro do compilador c2261)
'string': referência de assembly é inválida e não pode ser resolvida  
  
 Um valor não era válido.  
  
 <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute>é usado para especificar um assembly autorizado.</xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> Por exemplo, se quiser. dll especificar a DLL como um assembly autorizado, você deve especificar (em dll): InternalsVisibleTo("b"). O tempo de execução, em seguida, permite que a DLL acessar todo o conteúdo do. dll (exceto tipos privados).  
  
 Para obter mais informações sobre a sintaxe correta ao especificar assemblies amigáveis, consulte [Friend Assemblies (C++)](../../dotnet/friend-assemblies-cpp.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera c2261 ().  
  
```  
// C2261.cpp  
// compile with: /clr /c  
using namespace System::Runtime::CompilerServices;  
[assembly: InternalsVisibleTo("a,a,a")];   // C2261  
[assembly: InternalsVisibleTo("a.a")];   // OK  
[assembly: InternalsVisibleTo("a")];   // OK  
```
