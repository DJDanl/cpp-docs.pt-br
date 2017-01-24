---
title: "property (C++) | Microsoft Docs"
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
  - "property_cpp"
  - "Property"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], propriedade"
  - "palavra-chave property __declspec"
ms.assetid: f3b850ba-bf48-4df7-a1d6-8259d97309ce
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# property (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Esse atributo pode ser aplicado a “membros de dados virtuais” não estáticos em uma definição de classe ou estrutura.  O compilador trata esses “membros de dados virtuais” como membros de dados alterando suas referências em chamadas de função.  
  
## Sintaxe  
  
```  
  
      __declspec( property( get=get_func_name ) ) declarator  
__declspec( property( put=put_func_name ) ) declarator  
__declspec( property( get=get_func_name, put=put_func_name ) ) declarator  
```  
  
## Comentários  
 Quando o compilador consulta um membro de dados declarado com esse atributo à direita de um operador de seleção de membro \(“**.**” ou “**\-\>**"\), a operação converte a uma função **get** ou **put**, dependendo se essa expressão for um l\-value ou r\-value.  Nos contextos mais complicados, como “`+=`”, uma regravação é executada fazendo **get** e **put**.  
  
 Esse atributo também pode ser usado na declaração de uma matriz vazia em uma definição de classe ou estrutura.  Por exemplo:  
  
```  
__declspec(property(get=GetX, put=PutX)) int x[];  
```  
  
 A instrução anterior indica que `x[]` pode ser usado com um ou mais índices da matriz.  Nesse caso, `i=p->x[a][b]` será transformado em `i=p->GetX(a, b)`, e `p->x[a][b] = i` será transformado em `p->PutX(a, b, i);`  
  
 **FIM de Específico da Microsoft**  
  
## Exemplo  
  
```  
// declspec_property.cpp  
struct S {  
   int i;  
   void putprop(int j) {   
      i = j;  
   }  
  
   int getprop() {  
      return i;  
   }  
  
   __declspec(property(get = getprop, put = putprop)) int the_prop;  
};  
  
int main() {  
   S s;  
   s.the_prop = 5;  
   return s.the_prop;  
}  
```  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)