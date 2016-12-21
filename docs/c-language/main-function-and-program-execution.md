---
title: "Fun&#231;&#227;o main e execu&#231;&#227;o do programa | Microsoft Docs"
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
  - "pontos de entrada, programa"
  - "Função main"
  - "Função main, execução de programa"
  - "inicialização de programa [C++]"
  - "programas [C++], encerrando"
  - "código de inicialização, Função main"
ms.assetid: 5984f1bd-072d-4e06-8640-122fb1454401
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o main e execu&#231;&#227;o do programa
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada programa C tem uma função principal que deve ser nomeada **main**.  Se o seu código obedece ao modelo de programação Unicode, você pode usar a versão de **main** para caracteres largos, **wmain**.  A função **main** serve como o ponto de partida para a execução do programa.  Em geral, ela controla a execução direcionando as chamadas para outras funções no programa.  Normalmente, um programa para de ser executado no final de **main**, embora possa ser terminado em outros pontos por diversos motivos.  Às vezes, talvez quando um determinado erro é detectado, pode ser conveniente forçar o término de um programa.  Para fazer isso, use a função **exit**.  Consulte a *Referência da biblioteca em tempo de execução* para obter informações sobre como usar a função [exit](../c-runtime-library/reference/exit-exit-exit.md), juntamente com um exemplo.  
  
## Sintaxe  
  
```  
main( int argc, char *argv[ ], char *envp[ ] )  
```  
  
## Comentários  
 As funções do programa de origem executam uma ou mais tarefas específicas.  A função **main** pode chamar essas funções para executar as respectivas tarefas.  Quando **main** chama outra função, passa para ela o controle da execução, de modo que a execução começa na primeira instrução da função.  Uma função devolve o controle a **main** quando uma instrução `return` é executada ou quando o término da função é atingido.  
  
 Você pode declarar qualquer função, inclusive **main**, para ter parâmetros.  O termo "parâmetro" ou "parâmetro formal" refere\-se ao identificador que recebe um valor passado para uma função.  Consulte [Parâmetros](../c-language/parameters.md) para obter informações sobre como passar argumentos para parâmetros.  Quando uma função chama outra, a função chamada recebe valores para os respectivos parâmetros da função que chamou.  Esses valores são chamados de "argumentos". Você pode declarar parâmetros formais para **main** de modo que a função possa receber argumentos da linha de comando usando este formato:  
  
 Quando você quer passar informações para a função **main**, tradicionalmente os parâmetros são nomeados `argc` e `argv`, embora o compilador de C não exija esses nomes.  Os tipos para `argc` e `argv` são definidos pela linguagem C.  Tradicionalmente, se um terceiro parâmetro é passado para **main**, esse parâmetro é nomeado `envp`.  Exemplos posteriormente nesta seção mostram como usar esses três parâmetros para acessar argumentos de linha de comando.  As seções a seguir explicam esses parâmetros.  
  
 Consulte [Usando wmain](../c-language/using-wmain.md) para obter uma descrição da versão de **main** para caracteres largos.  
  
## Consulte também  
 [main: inicialização do programa](../Topic/main:%20Program%20Startup.md)