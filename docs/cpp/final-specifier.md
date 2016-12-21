---
title: "especificador final | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "final"
  - "final_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Identificador final"
ms.assetid: 649866d0-79d4-449f-ab74-f84b911b79a3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# especificador final
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar a palavra\-chave `final` para designar funções virtuais que não podem ser substituídas em uma classe derivada.  Também é possível usá\-la para designar classes que não podem ser herdadas.  
  
## Sintaxe  
  
```  
  
function-declaration final;  
```  
  
```  
  
class class-name final base-classes  
```  
  
## Comentários  
 `final` é contextual e tem um significado especial somente quando é usada após uma declaração de função ou um nome de classe; caso contrário, não é uma palavra\-chave reservada.  
  
 Quando `final` é usada em declarações de classe, `base-classes` é uma parte opcional da declaração.  
  
## Exemplo  
 O exemplo a seguir usa a palavra\-chave `final` para especificar que uma função virtual não pode ser substituída.  
  
```cpp  
class BaseClass  
{  
    virtual void func() final;  
};  
  
class DerivedClass: public BaseClass  
{  
    virtual void func(); // compiler error: attempting to   
                         // override a final function  
};  
```  
  
 Para obter informações sobre como especificar que as funções de membro podem ser substituídas, consulte [substituir especificador](../cpp/override-specifier.md).  
  
 O exemplo a seguir usa a palavra\-chave `final` para especificar que uma classe não pode ser herdada.  
  
```cpp  
class BaseClass final   
{  
};  
  
class DerivedClass: public BaseClass // compiler error: BaseClass is   
                                     // marked as non-inheritable  
{  
};  
```  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [\(NOTINBUILD\) C\+\+ Type Names](http://msdn.microsoft.com/pt-br/b53ba470-e583-4e5c-b634-6018f6110674)   
 [substituir especificador](../cpp/override-specifier.md)