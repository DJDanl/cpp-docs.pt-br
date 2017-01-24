---
title: "2.3 parallel Construct | Microsoft Docs"
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
ms.assetid: 190eacdf-2c16-4c06-8cb7-ac60eb211425
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.3 parallel Construct
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A diretiva a seguir define uma região paralela, o que é uma região do programa que está a ser executada por vários threads em paralelo.  Esta é a construção fundamental que inicia a execução em paralelo.  
  
```  
#pragma omp parallel [clause[ [, ]clause] ...] new-line  
   structured-block  
```  
  
 O  *cláusula*  é um dos seguintes:  
  
 **Se \(** *scalar\-expressão* **\)**  
  
 **particular \(** *variável\-list* **\)**  
  
 **firstprivate \(** *variável\-list* **\)**  
  
 **Default\(Shared &#124; none\)**  
  
 **compartilhado \(** *variável\-list* **\)**  
  
 **copyin \(** *variável\-list* **\)**  
  
 **reduction\(** *operator* **:**  *variable\-list* **\)**  
  
 **num\_threads \(** *expressão de inteiro* **\)**  
  
 Quando um thread encontra uma construção em paralela, uma equipe de threads é criada, se uma das seguintes situações for verdadeira:  
  
-   Não  **Se** cláusula está presente.  
  
-   O  **Se** expressão for avaliada como um valor diferente de zero.  
  
 Este segmento se torna o segmento principal da equipe, com um número de segmento de 0, e todos os segmentos da equipe, incluindo o segmento mestre, executar a região em paralelo.  Se o valor da  **Se** expressão é zero, a região é serializada.  
  
 Para determinar o número de segmentos que são solicitados, serão consideradas as regras a seguir na ordem.  A primeira regra cuja condição for atendida será aplicada:  
  
1.  Se a  **num\_threads** cláusula está presente, em seguida, o valor da expressão inteiro é o número de segmentos solicitada.  
  
2.  Se a  **omp\_set\_num\_threads** a função de biblioteca foi chamada, em seguida, o valor do argumento na chamada executada mais recentemente é o número de segmentos solicitada.  
  
3.  Se a variável de ambiente  **OMP\_NUM\_THREADS** for definido, o valor dessa variável de ambiente é o número de segmentos solicitada.  
  
4.  Se nenhum dos métodos acima fosse usado, o número de segmentos solicitada é definidos na implementação.  
  
 Se a  **num\_threads** cláusula está presente, em seguida, ele substitui o número de segmentos solicitada pelo  **omp\_set\_num\_threads** função de biblioteca ou o  **OMP\_NUM\_THREADS** a variável de ambiente somente para a região paralela, ela é aplicada a.  Regiões paralelas subseqüentes não são afetados por ele.  
  
 O número de segmentos que executam a região paralela depende ou não o ajuste dinâmico do número de threads está habilitado.  Se o ajuste dinâmico estiver desativado, o número solicitado de threads executará a região paralela.  Se o ajuste dinâmico estiver ativado o número solicitado de threads é o número máximo de threads que podem executar a região paralela.  
  
 Se uma região paralela é encontrada durante o ajuste dinâmico do número de segmentos estiver desativada e o número de segmentos solicitada para a região paralela excede o número que o sistema de tempo de execução pode fornecer, o comportamento do programa é definidos na implementação.  Uma implementação por exemplo, talvez, interromper a execução do programa, ou ele pode serializar a região paralela.  
  
 O  **omp\_set\_dynamic** a função de biblioteca e o  **OMP\_DYNAMIC** a variável de ambiente pode ser usada para ativar e desativar o ajuste dinâmico do número de threads.  
  
 O número de processadores físicos, na verdade, que hospeda os threads em um determinado momento é definidos na implementação.  Uma vez criado, o número de threads na equipe permanece constante durante o período da região paralela.  Ele pode ser alterado explicitamente pelo usuário ou automaticamente pelo sistema de tempo de execução de uma região paralela para outro.  
  
 As instruções contidas na extensão dinâmica da região paralela são executadas por cada segmento e cada thread possa executar um caminho de instruções que é diferente de outros threads.  As diretivas encontradas fora a extensão lexical de uma região paralela são chamadas de diretivas órfãos.  
  
 Há uma barreira implícita no final de uma região paralela.  Apenas o segmento principal da equipe continua a execução no final de uma região paralela.  
  
 Se um thread em uma equipe na execução de uma região paralela encontrar outro construtor paralelo, ele cria uma nova equipe e torna\-se o mestre da nova equipe.  Regiões paralelas aninhados são serializados por padrão.  Como resultado, por padrão, uma região paralela aninhada é executada por uma equipe composta de um thread.  O comportamento padrão pode ser alterado usando a função de biblioteca de tempo de execução  **omp\_set\_nested** ou a variável de ambiente  **OMP\_NESTED**.  No entanto, o número de segmentos em uma equipe que executar uma região paralela aninhada é definidos na implementação.  
  
 Restrições para o  **paralela** diretiva são os seguintes:  
  
-   No máximo um  **Se** cláusula pode aparecer na diretiva.  
  
-   Ele não é especificado se qualquer lado efeitos dentro a se expressão ou  **num\_threads** ocorrer de expressão.  
  
-   A  **lança** executado dentro de uma região paralela deve causar a execução de retomar dentro da extensão dinâmica do mesmo bloco estruturado, e ele deve ser detectado pelo mesmo thread que gerou a exceção.  
  
-   Um único  **num\_threads** cláusula pode aparecer na diretiva.  O  **num\_threads** expressão é avaliada fora do contexto da região paralela e deve ser avaliada como um valor inteiro positivo.  
  
-   A ordem de avaliação da  **Se**  e  **num\_threads** cláusulas não for especificado.  
  
## Entre as referências:  
  
-   **Private**,  **firstprivate**,  **padrão**,  **compartilhado**,  **copyin**, e  **redução**  cláusulas, consulte  [seção 2.7.2](../Topic/2.7.2%20Data-Sharing%20Attribute%20Clauses.md) na página 25.  
  
-   **OMP\_NUM\_THREADS** variável de ambiente,  [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48.  
  
-   **omp\_set\_dynamic** a função de biblioteca, consulte  [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.  
  
-   **OMP\_DYNAMIC** consulte variável, do ambiente  [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.  
  
-   **omp\_set\_nested** funcionam, consulte  [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40.  
  
-   **OMP\_NESTED** consulte variável, do ambiente  [seção 4.4](../Topic/4.4%20OMP_NESTED.md) na página 49.  
  
-   **omp\_set\_num\_threads** a função de biblioteca, consulte  [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36.