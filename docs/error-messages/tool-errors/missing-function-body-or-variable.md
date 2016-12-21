---
title: "Corpo de fun&#231;&#227;o ou vari&#225;vel ausente | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "corpo de função"
  - "variáveis, ausente"
ms.assetid: 1a88d809-b14f-46a4-97c4-3e48beb418f2
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Corpo de fun&#231;&#227;o ou vari&#225;vel ausente
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Apenas com um protótipo de função, o compilador pode continuar sem erro, mas o vinculador não pode resolver uma chamada para um endereço porque não há nenhum código de função ou variável espaço reservado.  Você não verá esse erro até que você crie uma chamada à função que o vinculador deve resolver.  
  
## Exemplo  
 A chamada de função no main causará LNK2019 porque o protótipo permite que o compilador pense a função existir.  Encontra do vinculador que não.  
  
```  
// LNK2019_MFBV.cpp  
// LNK2019 expected  
void DoSomething(void);  
int main() {  
   DoSomething();  
}  
```  
  
## Exemplo  
 Em C\+\+, certifique\-se de que você inclui a implementação de uma função específica de uma classe e não apenas um protótipo na definição da classe.  Se você estiver definindo a classe fora do arquivo de cabeçalho, inclua o nome da classe antes da função \(`Classname``::``memberfunction`\).  
  
```  
// LNK2019_MFBV_2.cpp  
// LNK2019 expected  
struct A {  
   static void Test();  
};  
  
// Should be void A::Test() {}  
void Test() {}  
  
int main() {  
   A AObject;  
   AObject.Test();  
}  
```  
  
## Consulte também  
 [Erro das Ferramentas de Vinculador LNK2019](../Topic/Linker%20Tools%20Error%20LNK2019.md)