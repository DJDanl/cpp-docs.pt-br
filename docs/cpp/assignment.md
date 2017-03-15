---
title: "Atribui&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "operadores de atribuição, sobrecarregado"
  - "operadores [C++], atribuição"
ms.assetid: d87e4f89-f8f5-42c1-9d3c-184bca9d0e15
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atribui&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador de atribuição \(**\=**\) é, estritamente falando, um operador binário.  Sua declaração é idêntica a qualquer outro operador binário, com as seguintes exceções:  
  
-   Ele deve ser uma função de membro não estático.  Nenhum `operator=` pode ser declarado como uma função diferente de membro.  
  
-   Ele não é herdado por classes derivadas.  
  
-   Uma função padrão `operator=` pode ser gerada pelo compilador para tipos de classe, se nenhum existir. \(Para obter mais informações sobre as funções padrão `operator=`, consulte [Atribuição e inicialização relacionadas a membros](http://msdn.microsoft.com/pt-br/94048213-8b49-4416-8069-b1b7a6f271f9).\)  
  
 O exemplo a seguir ilustra como declarar um operador de atribuição:  
  
```  
// assignment.cpp  
class Point  
{  
public:  
   Point &operator=( Point & );  // Right side is the argument.  
   int _x, _y;  
};  
  
// Define assignment operator.  
Point &Point::operator=( Point &ptRHS )  
{  
   _x = ptRHS._x;  
   _y = ptRHS._y;  
  
   return *this;  // Assignment operator returns left side.  
}  
  
int main()  
{  
}  
```  
  
 Observe que o argumento fornecido é o lado direito da expressão.  O operador retorna o objeto para preservar o comportamento do operador de atribuição, que retorna o valor do lado esquerdo após a conclusão da atribuição.  Isso permite a gravação de instruções como:  
  
```  
pt1 = pt2 = pt3;  
```  
  
## Consulte também  
 [Sobrecarga de operador](../cpp/operator-overloading.md)