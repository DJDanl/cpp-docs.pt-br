---
title: "Erro do Compilador C3451 | Microsoft Docs"
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
  - "C3451"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3451"
ms.assetid: a4897a69-e3e7-40bb-bb1c-598644904012
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3451
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

atributo “”: não pode aplicar o atributo não gerenciado “para digitar”  
  
 O atributo c criando não pode ser aplicado a um tipo CLR.  Consulte [C\+\+ Attributes Reference](../../windows/cpp-attributes-reference.md) para maiores informações.  
  
 Para obter mais informações, consulte [User\-Defined Attributes](../../windows/user-defined-attributes-cpp-component-extensions.md).  
  
 Esse erro pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual C\+\+ 2005: o atributo de [uuid](../../windows/uuid-cpp-attributes.md) não é permitido em um atributo definido pelo usuário usando a programação de CLR.  Use <xref:System.Runtime.InteropServices.GuidAttribute> em vez disso.  
  
## Exemplo  
 O exemplo a seguir produz C3451.  
  
```  
// C3451.cpp  
// compile with: /clr /c  
using namespace System;  
[ attribute(AttributeTargets::All) ]  
public ref struct MyAttr {};  
  
[ MyAttr, helpstring("test") ]   // C3451  
// try the following line instead  
// [ MyAttr ]  
public ref struct ABC {};  
```