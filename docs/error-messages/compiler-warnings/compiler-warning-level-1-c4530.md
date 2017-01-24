---
title: "Aviso do compilador (n&#237;vel 1) C4530 | Microsoft Docs"
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
  - "C4530"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4530"
ms.assetid: a04dcdb2-84db-459d-9e5e-4e743887465f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4530
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O manipulador de exceção C\+\+ usado, mas desenrola a semântica não está habilitado.Especifique \/EHsc  
  
 A manipulação de exceção C\+\+ foi usada [\/EHsc](../../build/reference/eh-exception-handling-model.md) mas não foi selecionado.  
  
 Quando a opção \/EHsc não foi habilitada, um objeto com armazenamento automática no quadro, entre a função que fazem o lançamento e a função que captura o lançamento, não será destruído.  No entanto, um objeto com o armazenamento automático criado em um bloco de **try** ou de **catch** será destruído.  
  
 O seguinte exemplo gera C4530:  
  
```  
// C4530.cpp  
// compile with: /W1  
int main() {  
   try{} catch(int*) {}   // C4530  
}  
```  
  
 Crie o exemplo com \/EHsc para resolver o aviso.