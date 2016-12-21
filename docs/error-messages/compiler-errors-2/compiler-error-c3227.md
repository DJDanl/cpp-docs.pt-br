---
title: "Erro do Compilador C3227 | Microsoft Docs"
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
  - "C3227"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3227"
ms.assetid: 7939c23a-96c8-43c2-89e9-f217d132d155
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3227
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'parâmetro' : não pode usar 'palavra\-chave' para atribuir um tipo genérico  
  
 Para criar uma instância de um tipo apropriado, um construtor é necessário.  No entanto, o compilador não pode garantir que um construtor apropriado está disponível.  
  
 Você pode usar modelos em vez de produtos genéricas para resolver este erro, ou pode usar um dos vários métodos para criar uma instância do tipo.  
  
## Exemplo  
 O exemplo a seguir produz C3227.  
  
```  
// C3227.cpp  
// compile with: /clr /c  
generic<class T> interface class ICreate {  
   static T Create();  
};  
  
generic <class T>  
where T : ICreate<T>  
ref class C {  
   void f() {  
      T t = new T;   // C3227  
  
      // OK  
      T t2 = ICreate<T>::Create();  
      T t3 = safe_cast<T>( System::Activator::CreateInstance(T::typeid) );  
   }  
};  
```