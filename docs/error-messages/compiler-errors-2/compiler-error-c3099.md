---
title: "Compiler Error C3099 | Microsoft Docs"
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
  - "C3099"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3099"
ms.assetid: b3dded0f-76c9-42c1-991b-532eb8619661
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compiler Error C3099
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'palavra\-chave': use \[System::AttributeUsageAttribute\] para atributos gerenciados; Use \[Windows::Foundation::Metadata::AttributeUsageAttribute\] para atributos do WinRT  
  
 Use <xref:System.AttributeUsageAttribute> para declarar **\/clr** atributos.  Use `Windows::Foundation::Metadata::AttributeUsageAttribute` para declarar atributos de tempo de execução do Windows.  
  
 Para obter mais informações sobre atributos \/CLR, consulte [User\-Defined Attributes](../../windows/user-defined-attributes-cpp-component-extensions.md).  Para atributos com suporte em tempo de execução do Windows, consulte [Windows.Foundation.Metadata namespace](http://msdn.microsoft.com/library/windows/apps/windows.foundation.metadata.aspx)  
  
## Exemplo  
 O exemplo a seguir gera C3099 e mostra como corrigi\-lo.  
  
```  
// C3099.cpp  
// compile with: /clr /c  
using namespace System;  
[usage(10)]   // C3099  
// try the following line instead  
// [AttributeUsageAttribute(AttributeTargets::All)]  
ref class A : Attribute {};  
```