---
title: D. Usando a cláusula de agenda | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: bf3d8f51-ea05-4803-bf55-657c12e91efe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8987c4505adfde8534d57346cd6725231efa022f
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33694934"
---
# <a name="d-using-the-schedule-clause"></a>D. Usando a cláusula de agenda
Uma região parallel tem pelo menos uma barreira, seu final e pode ter barreiras adicionais nele. Em cada barreira, os outros membros da equipe devem aguardar o último segmento chegar. Para minimizar esse tempo de espera, o trabalho compartilhado deve ser distribuído para que todos os threads chegam a barreira em aproximadamente ao mesmo tempo. Se alguns dos que compartilhou o trabalho está contido no **para** constrói, o `schedule` cláusula pode ser usada para essa finalidade.  
  
 Quando houver repetidas referências para os mesmos objetos, a opção de agendamento para um **para** construção pode ser determinada principalmente pelo características do sistema de memória, como a presença e o tamanho de caches e se o acesso à memória os tempos estão uniforme ou. Essas considerações podem torná-lo melhor ter cada thread consulte consistentemente o mesmo conjunto de elementos de uma matriz em uma série de loops, mesmo se alguns threads atribuídos relativamente menos trabalho em alguns dos loops. Isso pode ser feito usando o **estático** agenda com os limites do mesmo para todos os circuitos. No exemplo a seguir, observe que zero é usada como o limite inferior no segundo loop, embora **k** seria mais natural se a agenda não for importante.  
  
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
  
 Os exemplos restantes, presume-se que a memória acesso não é a consideração dominante e, a menos que indicado o contrário, todos os threads recebem recursos computacionais comparáveis. Nesses casos, a opção de agendamento para um **para** construção depende de todo o trabalho compartilhado que deve ser executada entre imediatamente precedente barreira e a barreira de fechamento implícitas ou o mais próximo de barreira subsequente, se houver um `nowait` cláusula. Para cada tipo de agenda, um pequeno exemplo mostra como esse tipo de agenda é provavelmente será a melhor opção. Uma breve discussão segue cada exemplo.  
  
 O **estático** agenda também é adequada para o caso mais simples, uma região parallel contendo um único **para** construir, com cada iteração exigindo a mesma quantidade de trabalho.  
  
```  
#pragma omp parallel for schedule(static)  
for(i=0; i<n; i++) {  
  invariant_amount_of_work(i);  
}  
```  
  
 O **estático** agenda é caracterizada pelas propriedades que cada thread é aproximadamente o mesmo número de iterações que qualquer outro thread, e cada thread independentemente pode determinar as iterações atribuídas a ele. Portanto, nenhuma sincronização é necessária para distribuir o trabalho e, sob a suposição de que cada iteração requer a mesma quantidade de trabalho, todos os threads devem terminar em aproximadamente ao mesmo tempo.  
  
 Para uma equipe de `p` threads, permitem *ceiling(n/p)* ser o inteiro *p*, que satisfaz *n = p\*p - r* com *0 < = r < p* . Uma implementação de **estático** programação para este exemplo atribuiria *p* iterações para a primeira *p-1* threads, e *p-r* iterações para o último segmento.  Outra implementação aceitável atribuiria *p* iterações para a primeira *p-r* threads, e *q-1* iterações para o restante *r*threads. Isso ilustra por que um programa não deve confiar nos detalhes de uma implementação específica.  
  
 O **dinâmico** agenda é apropriada para o caso de um **para** construir com as iterações que requerem valores diferentes ou até mesmo imprevisíveis, do trabalho.  
  
```  
#pragma omp parallel for schedule(dynamic)  
  for(i=0; i<n; i++) {  
    unpredictable_amount_of_work(i);  
}  
```  
  
 O **dinâmico** agenda é caracterizada pela propriedade de que nenhum thread aguarda à barreira de leva mais tempo do que outro thread execute sua iteração final. Isso requer que iterações seja atribuído um de cada vez para threads assim que estiverem disponíveis, com a sincronização para cada atribuição. A sobrecarga de sincronização pode ser reduzida, especificando um tamanho da parte mínimo *k* maior que 1, para que os threads são atribuídos *k* cada vez até menos de *k* permanecem. Isso garante que nenhum thread aguarda à barreira mais do que o que leva a outro thread para executar seu bloco final de (no máximo) *k* iterações.  
  
 O **dinâmico** agenda pode ser útil se os segmentos de recebimento diversos recursos computacionais, que tem o mesmo efeito como diferentes quantidades de trabalho para cada iteração. Da mesma forma, o agendamento dinâmico também pode ser útil se os threads chegam a **para** construir em momentos diferentes, embora em alguns casos o **interativa** agenda pode ser preferível.  
  
 O **interativa** agenda é apropriada para o caso em que os threads podem chegar em momentos diferentes em um **para** construir com cada iteração exigindo aproximadamente a mesma quantidade de trabalho. Isso pode ocorrer se, por exemplo, o **para** construção é precedida por uma ou mais seções ou **para** constrói com `nowait` cláusulas.  
  
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
  
 Como **dinâmico**, o **interativa** agendar garante que nenhum thread aguarda a barreira mais do que o que leva a outro thread execute sua iteração final ou final *k* iterações se um tamanho de bloco de *k* for especificado. Entre esse tipo de agenda, o **interativa** agenda é caracterizada pela propriedade que ela requer as menor número sincronizações. Para o tamanho da parte *k*, atribuirá uma implementação típica *p = ceiling(n/p)* definido de iterações para o primeiro thread disponível, *n* como o maior de *n-q* e *p\*k*e repita até que todas as iterações são atribuídas.  
  
 Quando a opção da agenda ideal não é mais clara que esses exemplos, o **tempo de execução** agenda é conveniente para a experimentar com diferentes agendamentos e tamanhos de bloco sem a necessidade de modificar e recompilar o programa. Ele também pode ser útil quando a programação ideal depende (de alguma forma previsível) os dados de entrada aos quais o programa é aplicado.  
  
 Para ver um exemplo das compensações entre diferentes agendas, considere a possibilidade de compartilhamento 1000 iterações entre 8 threads. Suponha que há um valor invariável de trabalho em cada iteração e usá-lo como a unidade de tempo.  
  
 Se iniciam todos os threads ao mesmo tempo, o **estático** agenda fará com que a construção executar em unidades de 125, sem sincronização. Mas suponha que um thread é de 100 unidades no final que chegam. Os segmentos de sete restantes aguardam 100 unidades à barreira e aumenta o tempo de execução para a construção inteira para 225.  
  
 Porque tanto o **dinâmico** e **interativa** agendas Certifique-se de que nenhum thread de espera por mais de uma unidade à barreira, o thread atrasado faz com que seus tempos de execução para a construção aumentar somente a 138 unidades, possivelmente acrescidas de atrasos da sincronização. Se tais atrasos não são muito importantes, é importante que o número de sincronizações é 1000 para **dinâmico** mas 41 somente para **interativa**, supondo que o tamanho da parte de um padrão. Com um tamanho de bloco de 25, **dinâmico** e **interativa** ambos concluir em unidades de 150, além de atrasos das sincronizações necessárias, o número agora apenas 40 e 20, respectivamente.