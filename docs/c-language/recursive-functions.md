---
title: "Fun&#231;&#245;es recursivas | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "chamadas de função, recursivo"
  - "funções [C], chamando recursivamente"
  - "funções [C], recursivo"
  - "chamadas de função recursiva"
ms.assetid: 59739040-3081-4006-abbc-9d8423992bce
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es recursivas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Qualquer função em um programa C pode ser chamada recursivamente, ou seja, pode chamar a si mesma.  O número de chamadas recursivas está limitado ao tamanho da pilha.  Consulte a opção de vinculador [\/STACK \(alocações da pilha\)](../build/reference/stack-stack-allocations.md) \(\/STACK\) para obter informações sobre as opções de vinculador que definem o tamanho da pilha.  Cada vez que a função é chamada, um novo armazenamento é alocado para os parâmetros e para as variáveis **auto** e **register** de modo que os respectivos valores em chamadas anteriores inacabadas não sejam substituídos.  Os parâmetros só são diretamente acessíveis para a instância da função na qual são criados.  Os parâmetros anteriores não são diretamente acessíveis para instâncias resultantes da função.  
  
 Observe que as variáveis declaradas com o armazenamento **static** não exigem um novo armazenamento com cada chamada recursiva.  O armazenamento existe para todo o tempo de vida do programa.  Cada referência a essa variável acessa a mesma área de armazenamento.  
  
## Exemplo  
 Este exemplo ilustra chamadas recursivas:  
  
```  
int factorial( int num );      /* Function prototype */  
  
int main()  
{  
    int result, number;  
    .  
    .  
    .  
    result = factorial( number );  
}  
  
int factorial( int num )      /* Function definition */  
{  
    .  
    .  
    .  
    if ( ( num > 0 ) || ( num <= 10 ) )  
        return( num * factorial( num - 1 ) );  
}  
  
```  
  
## Consulte também  
 [Chamadas de função](../c-language/function-calls.md)