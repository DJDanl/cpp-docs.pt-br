---
title: "Selando uma fun&#231;&#227;o virtual | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave sealed [C++]"
  - "classes derivadas, funções virtuais"
  - "funções virtuais, fechamento"
  - "Palavra-chave __sealed"
ms.assetid: 0e9fae03-6425-4512-9a24-8ccb6dc8a0d4
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Selando uma fun&#231;&#227;o virtual
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sintaxe para lacrar uma função virtual foi alterado de extensões gerenciadas para C\+\+ para [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 O `__sealed` palavra\-chave é usada nas extensões gerenciadas para modificar qualquer um tipo de referência, proibindo derivação subsequente dele \(consulte [Declaração de um tipo de classe gerenciado](../dotnet/declaration-of-a-managed-class-type.md)\), ou para modificar uma função virtual, a desabilitação de substituição subsequentes do método em uma classe derivada. Por exemplo:  
  
```  
__gc class base { public: virtual void f(); };  
__gc class derived : public base {  
public:  
   __sealed void f();  
};  
```  
  
 Neste exemplo, `derived::f()` substitui o `base::f()` instância com base na correspondência exata do protótipo da função. O `__sealed` palavra\-chave indica que uma classe subsequente herdada da classe derivada não pode fornecer uma substituição de `derived::f()`.  
  
 Na nova sintaxe, `sealed` é posicionada após a assinatura em vez de terem permissão para aparecer antes do protótipo de função real, que anteriormente era permitido. Além disso, o uso de `sealed` requer um uso explícito do `virtual` palavra\-chave também. Ou seja, a tradução correta de `derived`, acima, é o seguinte:  
  
```  
ref class derived: public base {  
public:  
   virtual void f() override sealed;  
};  
```  
  
 A ausência do `virtual` palavra\-chave nesta instância resulta em um erro. Na nova sintaxe, a palavra\-chave contextual `abstract` pode ser usado em vez do `=0` para indicar uma função virtual pura. Isso não era suportado dentro das extensões gerenciadas. Por exemplo:  
  
```  
__gc class base { public: virtual void f()=0; };  
```  
  
 pode ser reescrito como  
  
```  
ref class base { public: virtual void f() abstract; };  
```  
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [sealed](../windows/sealed-cpp-component-extensions.md)