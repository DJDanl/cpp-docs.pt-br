---
title: "C3381 de erro do compilador | Microsoft Docs"
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
  - "C3381"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3381"
ms.assetid: d276c89f-8377-4cb6-a8d4-7770885f06c4
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3381 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

assembly: os especificadores de acesso do assembly só estão disponíveis no código compilado com uma opção \/clr  
  
 Os tipos nativos podem ser visíveis fora do assembly, mas você só pode especificar o assembly que o acesso para nativo em uma compilação de **\/clr** .  
  
 Para obter mais informações, consulte [Visibilidade do tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir produz C3381.  
  
```  
// C3381.cpp  
// compile with: /c  
public class A {};   // C3381  
```