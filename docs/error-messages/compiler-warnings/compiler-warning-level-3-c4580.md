---
title: "Aviso do compilador (n&#237;vel 3) C4580 | Microsoft Docs"
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
  - "C4580"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4580"
ms.assetid: fef6e8e0-0d6a-44fa-b22a-2fe7ba2ef379
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4580
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\[atributo\] é substituído; em vez disso, especifique System::Attribute ou Platform:: Metadata como uma classe base  
  
 [attribute](../../windows/attribute.md) não é mais a sintaxe preferencial para criar atributos definidos pelo usuário.  Para obter mais informações, consulte [User\-Defined Attributes](../../windows/user-defined-attributes-cpp-component-extensions.md).  Para o código CLR, derivar atributos de [System::Attribute](assetId:///System::Attribute?qualifyHint=False&autoUpgrade=True).  Para o código de tempo de execução do Windows, obter atributos de `Platform::Metadata`.  
  
## Exemplo  
 O exemplo a seguir gera C3454 e mostra como corrigi\-lo.  
  
```  
// C4580.cpp  
// compile with: /W3 /c /clr  
[attribute]   // C4580  
public ref class Attr {  
public:  
   int m_t;  
};  
  
public ref class Attr2 : System::Attribute {  
public:  
   int m_t;  
};  
```