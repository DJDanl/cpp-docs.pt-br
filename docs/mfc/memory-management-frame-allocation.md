---
title: "Gerenciamento de mem&#243;ria: aloca&#231;&#227;o do quadro | Microsoft Docs"
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
  - "detectando perdas de memória"
  - "alocação de quadro"
  - "variáveis de quadro"
  - "variáveis de quadro, exclusão automática de"
  - "alocação de heap, vs. alocação de quadro"
  - "alocação de memória, quadros"
  - "perdas de memória, alocando objetos no quadro"
  - "perdas de memória, detectando"
  - "perdas de memória, alocação de quadro"
  - "memória, detectando perdas"
  - "memória, recuperando"
  - "memória, liberando"
  - "escopo, variáveis de quadro"
  - "registros de ativação"
  - "variáveis, variáveis de quadro"
ms.assetid: 945a211a-6f4f-4679-bb6a-b0f2a0d4a6c1
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciamento de mem&#243;ria: aloca&#231;&#227;o do quadro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A alocação do quadro deixa seu nome “quadro de pilha” que é configurado sempre que uma função é chamada.  O quadro de pilhas é uma área de memória que armazena temporariamente os argumentos à função assim como alguns variáveis que são locais à função definido.  As variáveis do quadro são chamados frequentemente variáveis “automático” porque o compilador atribui automaticamente espaço para eles.  
  
 Há duas chaves características de alocações do quadro.  Primeiro, quando você define uma variável local, bastante espaço é alocado no quadro de pilhas para manter a variável inteiro, mesmo se for uma matriz ou estrutura de dados.  Segundo, variáveis do quadro são excluídos automaticamente quando sair do escopo:  
  
 [!code-cpp[NVC_MFC_Utilities#10](../mfc/codesnippet/CPP/memory-management-frame-allocation_1.cpp)]  
  
 Para variáveis da função local, essa transição de escopo acontece quando a função é encerrado, mas o escopo de uma variável do quadro pode ser menor do que uma função se as chaves aninhadas são usadas.  Essa exclusão automática de variáveis do quadro é muito importante.  No caso de tipos primitivos simples \(como `int` ou **byte**\), matrizes, ou as estruturas de dados, a exclusão automática recuperam apenas a memória usada pela variável.  Desde que a variável à esquerda do escopo, não pode ser acessado de qualquer forma.  No caso de objetos C\+\+, porém, o processo de exclusão automática é um pouco mais complicado.  
  
 Quando um objeto é definido como uma variável do quadro, o construtor é invocado automaticamente no ponto onde a definição for encontrada.  Quando o objeto sair do escopo, o destruidor é invocado automaticamente antes que a memória para o objeto foi recuperada.  Essas construção e destruição automática podem ser muito úteis, mas você deve estar ciente das chamadas automático, especialmente ao destruidor.  
  
 A vantagem importante de atribuir objetos no quadro é que são excluídos automaticamente.  Quando você atribui os objetos no quadro, você não precisa se preocupar sobre objetos esquecidos causando vazamentos de memória. \(Para obter detalhes sobre possíveis vazamentos de memória, consulte o artigo [Detectando vazamentos de memória em MFC](http://msdn.microsoft.com/pt-br/29ee8909-96e9-4246-9332-d3a8aa8d4658).\) Uma desvantagem da alocação do quadro é que as variáveis do quadro não podem ser usados fora do escopo.  Outro fator que influencia escolha a alocação do quadro na alocação de heap é o mesmo para estruturas e objetos grandes, frequentemente é melhor usar o heap em vez da pilha para o armazenamento desde que o espaço de pilha geralmente é limitado.  
  
## Consulte também  
 [Gerenciamento de memória](../mfc/memory-management.md)