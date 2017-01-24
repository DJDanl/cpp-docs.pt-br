---
title: "noreturn | Microsoft Docs"
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
  - "noreturn_cpp"
  - "noreturn"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], noreturn"
  - "palavra-chave noreturn __declspec"
ms.assetid: 9c6517e5-22d7-4051-9974-3d2200ae4d1d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# noreturn
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Esse atributo `__declspec` diz ao compilador que uma função não retorna.  Como consequência, o compilador sabe que o código seguinte a uma chamada para uma função **\_\_declspec\(noreturn\)** está inacessível.  
  
 Se o compilador encontra uma função com um caminho de controle que não retorna um valor, ele gera um aviso \(C4715\) ou uma mensagem de erro \(C2202\).  Se o caminho de controle não pode ser acessado devido a uma função que nunca retorna, você pode usar **\_\_declspec\(noreturn\)** para evitar esse aviso ou erro.  
  
> [!NOTE]
>  Adicionar **\_\_declspec\(noreturn\)** a uma função cujo retorno é esperado pode resultar em um comportamento indefinido.  
  
## Exemplo  
 No exemplo a seguir, a cláusula **else** não contém uma instrução return.  Declarar `fatal` como **\_\_declspec\(noreturn\)** impede um erro ou uma mensagem de aviso.  
  
```  
// noreturn2.cpp  
__declspec(noreturn) extern void fatal () {}  
  
int main() {  
   if(1)  
     return 1;  
   else if(0)  
     return 0;  
   else  
     fatal();  
}  
```  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)