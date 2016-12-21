---
title: "Erro do Compilador C3657 | Microsoft Docs"
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
  - "C3657"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3657"
ms.assetid: 89a28a18-4c17-43a1-bda6-deb52c32d203
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3657
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

os destruidores não podem substituir explicitamente ou explicitamente ser substituídos  
  
 Os destruidores ou os finalizers não podem ser substituídos.  Para obter mais informações, consulte [Substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C3657.  
  
```  
// C3657.cpp  
// compile with: /clr  
public ref struct I {  
   virtual ~I() { }  
   virtual void a();  
};  
  
public ref struct D : I {  
   virtual ~D() = I::~I {}   // C3657  
   virtual void a() = I::a {}   // OK  
};  
```