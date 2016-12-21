---
title: "Erro do Compilador C2261 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2261"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2261"
ms.assetid: 60969482-9e83-49b5-9631-a04bc844da12
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2261
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“cadeia de caracteres”: a referência de assembly não é válida e não pode ser resolvida  
  
 Um valor inválido.  
  
 <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> é usado para especificar um assembly de amigo.  Por exemplo, se a.dll deseja especificar b.dll como um assembly de amigo, você deve especificar \(na.dll\): B InternalsVisibleTo \(“”\).  O tempo de execução então permite que b.dll acessa tudo na.dll \(exceto os tipos particulares\).  
  
 Para obter mais informações sobre a sintaxe correta para especificar os assemblies de amigo, consulte [Assemblies amigáveis \(C\+\+\)](../../dotnet/friend-assemblies-cpp.md).  
  
## Exemplo  
 O exemplo a seguir produz C2261.  
  
```  
// C2261.cpp  
// compile with: /clr /c  
using namespace System::Runtime::CompilerServices;  
[assembly: InternalsVisibleTo("a,a,a")];   // C2261  
[assembly: InternalsVisibleTo("a.a")];   // OK  
[assembly: InternalsVisibleTo("a")];   // OK  
```