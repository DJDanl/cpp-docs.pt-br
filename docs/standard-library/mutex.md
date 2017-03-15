---
title: "&lt;mutex&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<mutex>"
dev_langs: 
  - "C++"
ms.assetid: efb60c89-687a-4e38-8fe4-694e11c4e8a3
caps.latest.revision: 17
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;mutex&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Incluir o cabeçalho \< mutex \> padrão para definir as classes`mutex``recursive_mutex``timed_mutex`e`recursive_timed_mutex`; os modelos`lock_guard`e`unique_lock`; e dar suporte a tipos e funções que definem as regiões de código de exclusão mútua.  
  
> [!WARNING]
>  Os tipos de sincronização STL no Visual Studio de 2015 se baseiam em primitivos de sincronização do Windows e não usam mais ConcRT \(exceto quando a plataforma de destino for o Windows XP\).  Os tipos definidos em \< mutex \> não devem ser usados com qualquer tipo de ConcRT ou funções.  
  
## Sintaxe  
  
```cpp  
#include <mutex>  
```  
  
## Comentários  
  
> [!NOTE]
>  No código que é compilado usando**\/clr**ou**\/clr:pure**esse cabeçalho é bloqueado.  
  
 As classes`mutex`e`recursive_mutex`são*tipos de mutex*.  Um tipo de mutex tem um construtor padrão e um destruidor que não lançam exceções.  Esses objetos possuem métodos que propiciam exclusão mútua quando vários threads tentam bloquear o mesmo objeto.  Especificamente, um tipo de mutex contém os métodos`lock``try_lock`e`unlock`:  
  
-   O`lock`método bloqueia o thread de chamada até que o thread obtém a propriedade do mutex.  O valor de retorno será ignorado.  
  
-   O`try_lock`método tenta obter a propriedade do mutex sem bloqueio.  Seu tipo de retorno é convertido em`bool`e`true`se o método obtém propriedade, mas não`false`.  
  
-   O`unlock`método libera a propriedade do mutex do thread de chamada.  
  
 Você pode usar tipos de mutex como argumentos de tipo para instanciar os modelos`lock_guard`e`unique_lock`.  Você pode usar objetos desses tipos, como o`Lock`argumento para as funções de membro de espera no modelo[condition\_variable\_any](../standard-library/condition-variable-any-class.md).  
  
 Um*atingiu o tempo de mutex tipo*atende aos requisitos de um tipo de mutex.  Além disso, ele tem o`try_lock_for`e`try_lock_until`métodos que devem ser chamado usando um argumento e devem retornar um tipo que pode ser convertido em`bool`.  Um tipo de mutex regulares pode definir essas funções usando argumentos adicionais, desde que esses argumentos adicionais todos têm valores padrão.  
  
-   O`try_lock_for`método deve ser chamado usando um argumento,`Rel_time`cujo tipo é uma instanciação de[chrono::duration](../standard-library/duration-class.md).  O método tenta obter a propriedade do mutex, mas retorna no tempo designado pelo`Rel_time`independentemente do êxito.  Converte o valor de retorno para`true`se o método obtém a propriedade; caso contrário, o valor de retorno converte para`false`.  
  
-   O`try_lock_until`método deve ser chamado usando um argumento,`Abs_time`cujo tipo é uma instanciação de[chrono::time\_point](../standard-library/time-point-class.md).  O método tenta obter a propriedade do mutex, mas retorna até a hora em que é designada por`Abs_time`independentemente do êxito.  Converte o valor de retorno para`true`se o método obtém a propriedade; caso contrário, o valor de retorno converte para`false`.  
  
 Um tipo de mutex também é conhecido como um*bloqueável tipo*.  Se não fornecer a função de membro`try_lock`é um*tipo bloqueável básico*.  Um tipo de mutex cronometrada também é conhecido como um*atingiu o tempo de tipo bloqueável*.  
  
### Classes  
  
|Nome|Descrição|  
|----------|---------------|  
|[Classe lock\_guard](../standard-library/lock-guard-class.md)|Representa um modelo que pode ser instanciado para criar um objeto cujo destruidor desbloqueia um`mutex`.|  
|[Classe mutex \(STL\)](../standard-library/mutex-class-stl.md)|Representa um tipo de mutex.  Usar objetos desse tipo reforçam a exclusão mútua dentro de um programa.|  
|[Classe recursive\_mutex](../standard-library/recursive-mutex-class.md)|Representa um tipo de mutex.  Em constrast para o`mutex`classe, o comportamento de chamar métodos de bloqueio para objetos que já estão bloqueados é bem definido.|  
|[Classe recursive\_timed\_mutex](../standard-library/recursive-timed-mutex-class.md)|Representa um tipo de mutex programado.  Usar objetos desse tipo reforçam a exclusão mútua cujo tempo limite de bloqueio dentro de um programa.  Ao contrário de objetos do tipo`timed_mutex`o efeito de chamar métodos de bloqueio para`recursive_timed_mutex`objects é bem definido.|  
|[Classe timed\_mutex](../standard-library/timed-mutex-class.md)|Representa um tipo de mutex programado.  Usar objetos desse tipo reforçam a exclusão mútua cujo tempo limite de bloqueio dentro de um programa.|  
|[Classe unique\_lock](../standard-library/unique-lock-class.md)|Representa um modelo que pode ser instanciado para criar objetos que gerenciam o bloqueio e desbloqueio de um`mutex`.|  
  
### Funções  
  
|Nome|Descrição|  
|----------|---------------|  
|[Função call\_once](../Topic/call_once%20Function.md)|Fornece um mecanismo para chamar um objeto especificado que pode ser chamado apenas uma vez durante a execução.|  
|[Função lock](../Topic/lock%20Function.md)|Tenta bloquear todos os argumentos sem bloqueio.|  
  
### Structs  
  
|Nome|Descrição|  
|----------|---------------|  
|[Estrutura adopt\_lock\_t](../standard-library/adopt-lock-t-structure.md)|Representa um tipo que é usado para definir um`adopt_lock`.|  
|[Estrutura defer\_lock\_t](../standard-library/defer-lock-t-structure.md)|Representa um tipo que define uma`defer_lock`objeto que é usado para selecionar um dos construtores sobrecarregados de`unique_lock`.|  
|[Estrutura once\_flag](../standard-library/once-flag-structure.md)|Representa um`struct`que é usada com a função de modelo`call_once`para garantir que a inicialização código é chamado apenas uma vez, até mesmo na presença de vários threads de execução.|  
|[Estrutura try\_to\_lock\_t](../Topic/try_to_lock_t%20Structure.md)|Representa um`struct`que define um`try_to_lock`do objeto e é usado para selecionar um dos construtores sobrecarregados de`unique_lock`.|  
  
### Variáveis  
  
|Nome|Descrição|  
|----------|---------------|  
|[Variável adopt\_lock](../Topic/adopt_lock%20Variable.md)|Representa um objeto que pode ser passado para construtores para`lock_guard`e`unique_lock`para indicar que o objeto de mutex também está sendo passado para o construtor é bloqueado.|  
|[Variável defer\_lock](../Topic/defer_lock%20Variable.md)|Representa um objeto que pode ser passado para o construtor para`unique_lock`para indicar que o construtor não deve bloquear o objeto de mutex também está sendo passado para ele.|  
|[Variável try\_to\_lock](../Topic/try_to_lock%20Variable.md)|Representa um objeto que pode ser passado para o construtor`unique_lock`para indicar que o construtor deve tentar desbloquear o`mutex`que também está sendo passado a ele sem bloqueio.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)