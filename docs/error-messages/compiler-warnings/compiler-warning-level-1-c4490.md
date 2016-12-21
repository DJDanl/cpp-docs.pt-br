---
title: "Aviso do compilador (n&#237;vel 1) C4490 | Microsoft Docs"
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
  - "C4490"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4490"
ms.assetid: f9b03ecf-41a1-4f4d-a74c-2c1e88234ccc
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4490
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“substituição”: uso incorreto do especificador de substituição; a função “” não corresponde a um método da classe de referência de base  
  
 Um especificador de substituição foi usado incorretamente.  Por exemplo, você não substitui a função da interface, você implementá\-la.  
  
 Para obter mais informações, consulte [Especificadores de Substituição](../../windows/override-specifiers-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir produz C4490.  
  
```  
// C4490.cpp  
// compile with: /clr /c /W1  
  
interface struct IFace {  
   void Test();  
};  
  
ref struct Class1 : public IFace {  
   virtual void Test() override {}   // C4490  
   // try the following line instead  
   // virtual void Test() {}  
};  
```