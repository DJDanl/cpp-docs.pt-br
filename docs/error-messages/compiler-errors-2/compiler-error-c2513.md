---
title: "Erro do Compilador C2513 | Microsoft Docs"
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
  - "C2513"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2513"
ms.assetid: ab5b21d3-61e2-4df7-8eea-6f14d6ba8620
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2513
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: nenhuma variável declarada antes “\=”  
  
 O especificador do tipo aparece na declaração sem o identificador da variável.  
  
 O seguinte exemplo gera C2513:  
  
```  
// C2513.cpp  
int main() {  
   int = 9;   // C2513  
   int i = 9;   // OK  
}  
```  
  
 Esse erro também pode ser gerado no resultado de um trabalho de conformidade do compilador feito para Visual Studio .NET 2003:. inicialização de um typedef não permitido.  A inicialização de um typedef não é permitida por padrão e não gerencia agora um erro de compilador.  
  
```  
// C2513b.cpp  
// compile with: /c  
typedef struct S {  
   int m_i;  
} S = { 1 };   // C2513  
// try the following line instead  
// } S;  
```  
  
 Uma alternativa seria excluir `typedef` para definir uma variável com lista agregada de inicializador, mas isso não é recomendado porque criará uma variável com o mesmo nome do tipo e ocultará o nome do tipo.