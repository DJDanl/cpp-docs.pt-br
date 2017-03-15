---
title: "2.4.1 for Construct | Microsoft Docs"
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
ms.assetid: 27d2cbce-786b-4819-91d3-d55b2cc57a5e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.4.1 for Construct
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **para** diretiva identifica uma construção de compartilhamento de trabalho iterativa que especifica que as iterações do loop associado serão executadas em paralelo.  As iterações da  **para** loop são distribuídos entre os segmentos que já existem na equipe de executar a construção paralela à qual ele se vincula.  A sintaxe do  **para** construção é da seguinte maneira:  
  
```  
#pragma omp for [clause[[,] clause] ... ] new-line  
   for-loop  
```  
  
 A cláusula é um destes procedimentos:  
  
 **particular \(** *variável\-list* **\)**  
  
 **firstprivate \(** *variável\-list* **\)**  
  
 **lastprivate \(** *variável\-list* **\)**  
  
 **reduction\(** *operator* **:** *variable\-list***\)**  
  
 **ordenado**  
  
 **schedule\(** *kind*, *chunk\_size***\)**  
  
 **nowait**  
  
 O  **para** diretiva impõe restrições na estrutura do correspondente  **para** loop.  Especificamente, o correspondente  **para** loop deve ter a forma canônica:  
  
 **for \(** *init\-expr* **;** *b do var lógico\-op*;   *incr\-expr***\)**  
  
 *Init\-expr*  
 Um dos seguintes:  
  
 *var* \= *lb*  
  
 *tipo de inteiro var* \=  *lb*  
  
 *expr de incrementais*  
 Um dos seguintes:  
  
 \+\+*var*  
  
 *var* \+\+  
  
 \-\- *var*  
  
 *var* \-\-  
  
 *var* \+\= *incr*  
  
 *var* \-\= *incr*  
  
 *var* \= *var* \+ *incr*  
  
 *var* \= *incr* \+ *var*  
  
 *var* \= *var* \- *Aumentar medida*  
  
 *var*  
 Uma variável de inteiro assinado.  Se essa variável caso contrário, seria compartilhada, ele é implicitamente feito privada durante o  **para**.  Essa variável não deve ser modificada dentro do corpo da  **para** instrução.  A menos que a variável é especificada  **lastprivate**, seu valor após o loop é indeterminado.  
  
 *lógico\-op.*  
 Um dos seguintes:  
  
 \<  
  
 \< \=  
  
 \>  
  
 \> \=  
  
 *lb*, *b*, and *incr*  
 Loop expressões invariável inteiro.  Há uma sincronização durante a avaliação dessas expressões.  Assim, efeitos colaterais avaliados produzem resultados indeterminados.  
  
 Observe que a forma canônica permite o número de iterações do loop ser computados na entrada para o loop.  Esse cálculo é executado com valores no tipo de  *var*, depois de promoções integrais.  Em particular, se o valor de  *b* \- *lb* \+  *incr* não pode ser representada nesse tipo, o resultado é indeterminado.  Se ainda mais,  *lógico\-op* é \< ou \< \=, em seguida,  *\- incr expr* devem causar  *var* para aumentar em cada iteração do loop.  Se  *lógico\-op* é \> ou \> \=, em seguida,  *\- incr expr* deve causar  *var* para diminuir em cada iteração do loop.  
  
 O  **agenda** cláusula Especifica como iterações da  **para** loop são divididos entre os threads da equipe.  A correção de um programa não deve depender de qual thread executa uma iteração específica.  O valor de  *chunk\_size*, se especificado, deve ser uma expressão de inteiro invariável de loop com um valor positivo.  Há uma sincronização durante a avaliação dessa expressão.  Assim, efeitos colaterais avaliados produzem resultados indeterminados.  O agendamento de  *tipo* pode ser uma das seguintes opções:  
  
 Tabela 2\-1  **agenda** cláusula  *tipo* valores  
  
|||  
|-|-|  
|estático|Quando  **agenda \(estática,** *chunk\_size***\)** for especificado, iterações são divididas em fragmentos de um tamanho especificado por  *chunk\_size*.  Os blocos são atribuídos estaticamente aos threads na equipe em um estilo round\-robin na ordem do número de segmento.  Quando não há  *chunk\_size* for especificado, o espaço de iteração será dividido em partes que são aproximadamente iguais em tamanho, com um bloco atribuído a cada segmento.|  
|dinâmico|Quando  **agenda \(dinâmico,** *chunk\_size***\)** for especificado, as iterações são divididas em uma série de blocos, cada um contendo  *chunk\_size* iterações.  Cada bloco é atribuído a um segmento que está aguardando uma atribuição.  O segmento executa o fragmento de iterações e aguarda sua próxima atribuição, até que não há partes permaneçam a ser atribuído.  Observe que a última parte a ser atribuído pode ter um número menor de iterações.  Quando não há  *chunk\_size* for especificado, o padrão é 1.|  
|interativa|Quando  **agenda \(guiada,** *chunk\_size***\)** for especificado, as iterações são atribuídas aos threads em blocos com tamanhos de decrescentes.  Quando um thread termina seu fragmento atribuído de iterações, ela será atribuída dinamicamente outro bloco, até que nenhum permaneçam.  Para um  *chunk\_size* de 1, o tamanho de cada bloco é aproximadamente igual ao número de iterações não atribuídos, dividido pelo número de segmentos.  Esses tamanhos aproximadamente diminuem exponencialmente para 1.  Para um  *chunk\_size* com o valor  *k* maior que 1, os tamanhos de aproximadamente diminuir exponencialmente para  *k*, exceto que a última parte pode ter menos de  *k* iterações.  Quando não há  *chunk\_size* for especificado, o padrão é 1.|  
|tempo de execução|Quando  **schedule\(runtime\)** for especificado, a decisão sobre agendamento é adiada até que o tempo de execução.  O agendamento de  *tipo*  e o tamanho dos blocos pode ser escolhido em tempo de execução, definindo a variável de ambiente  **OMP\_SCHEDULE**.  Se esta variável de ambiente não estiver definido, a agenda resultante é definidos na implementação.  Quando  **schedule\(runtime\)** for especificado,  *chunk\_size* não deve ser especificado.|  
  
 Na ausência de explicitamente definidas  **agenda** cláusula, o padrão  **agenda** é definido para implementação.  
  
 Um programa compatível com OpenMP não deve confiar em uma programação específica para a execução correta.  Um programa não deve depender de uma agenda  *tipo* conformes com precisão à descrição acima, porque é possível ter variações das implementações do mesmo agendamento no  *tipo* entre compiladores diferentes.  As descrições podem ser usadas para selecionar o agendamento que é apropriado para uma determinada situação.  
  
 O  **ordenados** cláusula deve estar presente quando  **ordenados** diretivas ligar para o  **para** construir.  
  
 Há uma barreira implícita no final de uma  **para** construir a menos que uma  **nowait** cláusula for especificada.  
  
 Restrições para o  **para** diretiva são os seguintes:  
  
-   O  **para** loop deve ser um bloco estruturado e, além disso, sua execução não deve ser terminada por um  **quebra** instrução.  
  
-   Os valores do loop controle expressões da  **para** loop associado com um  **para** diretiva deve ser o mesmo para todos os segmentos na equipe.  
  
-   O  **para** variável de iteração de loop deve ter um tipo de inteiro assinado.  
  
-   Um único  **agenda** cláusula pode aparecer em um  **para** diretiva.  
  
-   Um único  **ordenada** cláusula pode aparecer em um  **para** diretiva.  
  
-   Um único  **nowait** cláusula pode aparecer em um  **para** diretiva.  
  
-   Se não especificado ou a freqüência na qual os efeitos de qualquer lado dentro é o  *chunk\_size*,  *lb*,  *b*, ou  *incrementais* expressões ocorrerem.  
  
-   O valor da  *chunk\_size* a expressão deve ser o mesmo para todos os segmentos na equipe.  
  
## Entre as referências:  
  
-   **Private**,  **firstprivate**,  **lastprivate**, e  **redução** cláusulas, consulte  [seção 2.7.2](../Topic/2.7.2%20Data-Sharing%20Attribute%20Clauses.md) na página 25.  
  
-   **OMP\_SCHEDULE** consulte variável, do ambiente  [seção 4.1](../../parallel/openmp/4-1-omp-schedule.md) na página 48.  
  
-   **ordenada** construir, consulte  [seção 2.6.6](../../parallel/openmp/2-6-6-ordered-construct.md) na página 22.  
  
-   [Apêndice d](../../parallel/openmp/d-using-the-schedule-clause.md), página 93, fornece mais informações sobre como usar a cláusula de agenda.