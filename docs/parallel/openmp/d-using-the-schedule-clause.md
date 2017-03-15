---
title: "D. Using the schedule Clause | Microsoft Docs"
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
ms.assetid: bf3d8f51-ea05-4803-bf55-657c12e91efe
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# D. Using the schedule Clause
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma região paralela tem pelo menos uma barreira, em sua extremidade e pode ter barreiras adicionais dentro dele.  Em cada barreira, os outros membros da equipe devem esperar até o último segmento chegar.  Para minimizar esse tempo de espera, o trabalho compartilhado deve ser distribuído para que todos os threads chegam a barreira em aproximadamente ao mesmo tempo.  Se alguns dos que compartilhado trabalho está contido no  **para** constrói, a `schedule` cláusula pode ser usada para essa finalidade.  
  
 Quando houver referências repetidas para os mesmos objetos, a opção de agendamento para uma  **para** construção pode ser determinada principalmente por características do sistema de memória, como, por exemplo, a presença e o tamanho de caches e se os tempos de acesso de memória são uniforme ou.  Tais considerações podem tornar melhor ter cada thread consulte consistentemente o mesmo conjunto de elementos de uma matriz em uma série de loops, mesmo que alguns segmentos são atribuídos relativamente menos trabalho em alguns dos loops.  Isso pode ser feito usando o  **estático** agenda com os mesmos limites para todos os circuitos.  No exemplo a seguir, observe que zero é usado como o limite inferior no segundo loop, mesmo que  **k** seria mais natural se o agendamento não eram importante.  
  
```  
#pragma omp parallel  
{  
#pragma omp for schedule(static)  
  for(i=0; i<n; i++)  
    a[i] = work1(i);  
#pragma omp for schedule(static)  
  for(i=0; i<n; i++)  
    if(i>=k) a[i] += work2(i);  
}  
```  
  
 Nos exemplos restantes, presume que a memória o acesso não é a consideração dominante e, salvo indicação em contrário, que todos os threads recebam recursos computacionais comparáveis.  Nesses casos, a opção de agendamento para uma  **para** construção depende de todo o trabalho compartilhado deve ser executada entre antecedente mais próxima barreira e a barreira de fechamento implícita ou o mais próximo de barreira subseqüente, se houver um `nowait` cláusula.  Para cada tipo de agenda, um pequeno exemplo mostra como esse tipo de agendamento é provavelmente a melhor opção.  Uma breve discussão sobre segue cada exemplo.  
  
 O  **estático** agenda também é apropriada para o caso mais simples, uma região paralela, que contém um único  **para** construir, com cada iteração que exigem a mesma quantidade de trabalho.  
  
```  
#pragma omp parallel for schedule(static)  
for(i=0; i<n; i++) {  
  invariant_amount_of_work(i);  
}  
```  
  
 O  **estático** agenda é caracterizada por propriedades que cada thread obtém aproximadamente o mesmo número de iterações que qualquer outro segmento, e cada thread independentemente pode determinar as iterações atribuídas a ele.  Assim, nenhuma sincronização é necessária para distribuir o trabalho e, sob a suposição de que cada iteração requer a mesma quantidade de trabalho, todos os threads devem terminar ao praticamente ao mesmo tempo.  
  
 Para uma equipe de `p` deixe de threads,  *ceiling\(n\/p\)* ser o inteiro  *q*, que satisfaz  *n \= p \* q \- r* com  *0 \< \= r \< p*.  Uma implementação da  **estático** programar para este exemplo atribuiria  *q* iterações para o primeiro  *p – 1* segmentos, e  *p\-r* iterações para o último segmento.  Outra implementação aceitável atribuiria  *q* iterações para o primeiro  *p\-r* segmentos, e  *p\-1* iterações para o restante  *r* segmentos.  Isso ilustra o motivo pelo qual um programa não deve confiar nos detalhes de uma implementação específica.  
  
 O  **dinâmico** agenda é apropriada para o caso de um  **para** construir com as iterações que exigem variadas, ou até mesmo imprevisíveis, quantidades de trabalho.  
  
```  
#pragma omp parallel for schedule(dynamic)  
  for(i=0; i<n; i++) {  
    unpredictable_amount_of_work(i);  
}  
```  
  
 O  **dinâmico** agenda é caracterizada pela propriedade que nenhum thread aguarda na barreira para mais do que ele leva a outro segmento para executar sua iteração final.  Isso requer que iterações seja atribuída uma de cada vez para threads assim que estiverem disponíveis, com a sincronização de cada atribuição.  A sobrecarga de sincronização pode ser reduzida, especificando um tamanho mínimo do bloco  *k* maior que 1, para que os threads são atribuídos  *k* cada vez até menos de  *k* permanecem.  Isso garante que nenhum thread aguarda na barreira mais demorado outro thread para executar sua parte final do \(no máximo\)  *k* iterações.  
  
 O  **dinâmico** agenda pode ser útil se os threads recebem variados recursos computacionais, que tem o mesmo efeito como quantidades variáveis de trabalho para cada iteração.  Da mesma forma, a programação dinâmica também pode ser útil se os threads chegam a  **para** construir em momentos diferentes, embora em alguns casos o  **interativa** agenda pode ser preferível.  
  
 O  **interativa** agenda é apropriada para o caso em que os threads podem chegar em momentos diferentes em um  **para** construir com cada iteração que requerem aproximadamente a mesma quantidade de trabalho.  Isso pode acontecer se, por exemplo, o  **para** construção é precedida por uma ou mais seções ou  **para** constrói com `nowait` cláusulas.  
  
```  
#pragma omp parallel  
{  
  #pragma omp sections nowait  
  {  
    // ...  
  }  
  #pragma omp for schedule(guided)  
  for(i=0; i<n; i++) {  
    invariant_amount_of_work(i);  
  }  
}  
```  
  
 Como  **dinâmico**, o  **interativa** agendar garante que nenhum segmento espera pela barreira mais demorado outro thread para executar sua iteração final ou final  *k* iterações se um tamanho de bloco de  *k* é especificado.  Entre essas agendas, o  **interativa** agenda é caracterizada pela propriedade que ele requer que as sincronizações mais baixas.  Para tamanho do bloco  *k*, uma implementação típica atribuirá  *q \= ceiling\(n\/p\)* iterações para o primeiro thread disponível, defina  *n* para o maior de  *n\-q* e  *p \* k*e repita até que todas as iterações são atribuídas.  
  
 Quando a opção da agenda ideal não é tão óbvia, assim como para esses exemplos, o  **tempo de execução** agenda é conveniente para experiências com tamanhos de bloco e agendamentos diferentes sem ter que modificar e recompilar o programa.  Ele também pode ser útil quando a agenda ideal depende \(em alguma forma previsível\) os dados de entrada à qual o programa é aplicado.  
  
 Para ver um exemplo de trade\-offs entre agendas diferentes, considere compartilhamento 1000 iterações entre 8 threads.  Suponha que haja uma quantidade invariável de trabalho em cada iteração e utilize\-o como a unidade de tempo.  
  
 Se todos os threads iniciar ao mesmo tempo, o  **estático** agenda fará com que a construção a ser executado em unidades de 125, sem sincronização.  Mas suponha que um segmento é de 100 unidades no final que chegam.  Em seguida, os segmentos de sete restantes Aguarde para 100 unidades em que a barreira e aumenta o tempo de execução para a construção inteira 225.  
  
 Porque tanto o  **dinâmico** e  **interativa** agendas Certifique\-se de que nenhum segmento espera por mais de uma unidade em que a barreira, o thread atrasado faz com que o tempo de execução para a construção com um aumento apenas 138 unidades, possivelmente aumentadas devido aos atrasos da sincronização.  Se tais atrasos não insignificantes, ele se torna importante que o número de sincronizações de 1000 para  **dinâmico** , mas apenas 41 para  **interativa**, supondo que o tamanho da parte de um padrão.  Com um tamanho de bloco de 25,  **dinâmico** e  **interativa** ambos concluir em 150 unidades, além de eventuais atrasos das sincronizações necessárias, qual número agora somente 40 e 20, respectivamente.