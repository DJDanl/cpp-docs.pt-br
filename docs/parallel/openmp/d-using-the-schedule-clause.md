---
title: D. Usando cláusula schedule
ms.date: 11/04/2016
ms.assetid: bf3d8f51-ea05-4803-bf55-657c12e91efe
ms.openlocfilehash: 85386c913a6e447ba9e71231be8b951eef504fea
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50627520"
---
# <a name="d-using-the-schedule-clause"></a>D. Usando cláusula schedule

Uma região parallel tem pelo menos uma barreira, no final e pode ter barreiras adicionais dentro dele. Em cada barreira, os outros membros da equipe devem aguardar o último thread chegar. Para minimizar esse tempo de espera, o trabalho compartilhadas deve ser distribuído para que todos os threads chegarem a barreira em aproximadamente ao mesmo tempo. Se algum dos que compartilhou o trabalho está contido em **para** constructos, o `schedule` cláusula pode ser usada para essa finalidade.

Quando há referências repetidas aos mesmos objetos, a opção de agendamento para um **para** construção pode ser determinada principalmente pelo características do sistema de memória, como a presença e o tamanho de caches e se o acesso à memória tempos são uniforme ou não uniforme. Essas considerações podem tornar preferível para fazer com que cada thread consistentemente se referem ao mesmo conjunto de elementos de uma matriz em uma série de loops, mesmo se alguns threads recebem relativamente menos trabalho em alguns dos loops. Isso pode ser feito usando o **estático** agenda com limites iguais para todos os circuitos. No exemplo a seguir, observe que zero é usado como o limite inferior no segundo loop, embora **k** seria mais natural se o agendamento não foram importante.

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

Os exemplos restantes, presume-se que a memória acesso não é a consideração dominante e, salvo indicação contrária, que todos os threads recebem recursos computacionais comparáveis. Nesses casos, a opção de agendamento para um **para** constructo depende de todo o trabalho compartilhado deve ser executada entre precedente mais próximo barreira e a barreira de fechamento implícitas ou o mais próximo da barreira subsequente, se houver um `nowait` cláusula. Para cada tipo de agenda, um pequeno exemplo mostra como esse tipo de agenda é provavelmente a melhor opção. Uma breve discussão segue cada exemplo.

O **estáticos** agendamento também é adequado para o caso mais simples, uma região paralela que contém uma única **para** construir, com cada iteração exigindo a mesma quantidade de trabalho.

```
#pragma omp parallel for schedule(static)
for(i=0; i<n; i++) {
  invariant_amount_of_work(i);
}
```

O **estático** agenda é caracterizada pelas propriedades que cada thread obtém aproximadamente o mesmo número de iterações que qualquer outro thread, e cada thread de forma independente pode determinar as iterações atribuídas a ele. Portanto, nenhuma sincronização é necessária para distribuir o trabalho e, sob a suposição de que cada iteração requer a mesma quantidade de trabalho, todos os threads devem ser concluído em aproximadamente ao mesmo tempo.

Para uma equipe de `p` threads, deixe *ceiling(n/p)* ser o inteiro *q*, que satisfaz *n = p\*p - r* com *0 < = r < p* . Uma implementação do **estáticos** agendar para este exemplo atribuiria *q* iterações para o primeiro *p-1* threads, e *p e r* iterações para o último thread.  Outra implementação aceitável atribuiria *q* iterações para a primeira *p-r* threads, e *q-1* iterações para o restante *r*segmentos. Isso ilustra por que um programa não deve confiar nos detalhes de uma implementação específica.

O **dinâmica** agenda é apropriada para o caso de uma **para** construir com as iterações que exigem variadas, ou até mesmo imprevisíveis, quantidades de trabalho.

```
#pragma omp parallel for schedule(dynamic)
  for(i=0; i<n; i++) {
    unpredictable_amount_of_work(i);
}
```

O **dinâmico** agenda é caracterizada pela propriedade que nenhum thread aguarda a barreira de leva mais tempo do que outro thread para executar sua iteração final. Isso requer que as iterações sejam atribuídas uma de cada vez para threads assim que estiverem disponíveis, com a sincronização para cada atribuição. A sobrecarga de sincronização pode ser reduzida, especificando um tamanho de parte mínimo *k* maior que 1, para que os threads são atribuídos *k* cada vez até menos de *k* permanecem. Isso garante que nenhum thread aguarda em mais do que o que leva a outro thread para executar sua parte final do (no máximo) barreira *k* iterações.

O **dinâmico** agenda pode ser útil se os threads recebem variados recursos computacionais, que tem o mesmo efeito como diferentes quantidades de trabalho para cada iteração. Da mesma forma, o agendamento dinâmico também pode ser útil se os threads de chegarem a **para** construir em momentos diferentes, embora em alguns casos o **guiado** agenda pode ser preferível.

O **guiado** agenda é apropriada para o caso em que os threads podem chegar em horários diferentes em um **para** construir com cada iteração exigindo aproximadamente a mesma quantidade de trabalho. Isso pode ocorrer se, por exemplo, o **para** constructo é precedido por uma ou mais seções ou **para** constrói com `nowait` cláusulas.

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

Como o **dinâmica**, o **interativa** agendar garante que nenhum thread aguarda na barreira mais do que o que leva a outro thread para executar sua iteração final ou final *k* iterações se um tamanho de bloco de *k* for especificado. Entre esse tipo de agenda, o **guiado** agenda é caracterizada pela propriedade que ele requer que as sincronizações menor. Para o tamanho da parte *k*, atribuirá uma implementação típica *q = ceiling(n/p)* iterações para o primeiro thread disponível, defina *n* como o maior de *n-p* e *p\*k*e repita até que todas as iterações são atribuídas.

Quando a opção da programação ideal não é tão óbvia assim como para esses exemplos, o **tempo de execução** agenda é conveniente para experimentar com diferentes agendamentos e tamanhos de partes sem a necessidade de modificar e recompilar o programa. Ele também pode ser útil quando a programação ideal depende (de alguma forma previsível) os dados de entrada aos quais o programa for aplicado.

Para ver um exemplo de como as vantagens e desvantagens entre diferentes agendas, considere a 1000 iterações entre os 8 threads de compartilhamento. Suponha que exista uma invariável quantidade de trabalho em cada iteração e usá-lo como a unidade de tempo.

Se todos os threads começam ao mesmo tempo, o **estático** agenda fará com que a construção executar em unidades de 125, sem sincronização. Mas suponha que um thread seja 100 unidades no final que chegam. Em seguida, os threads restantes de sete aguardam para 100 unidades na barreira e o tempo de execução para a construção inteira aumenta para 225.

Porque tanto o **dinâmica** e **guiado** agendas Certifique-se de que nenhum thread aguarda mais de uma unidade em que a barreira, o thread atrasado faz com que seus tempos de execução para a construção aumentar somente para 138 unidades, possivelmente aumentadas em atrasos de sincronização. Se esses atrasos não são muito importantes, é importante que o número de sincronizações de é 1000 para o **dinâmica** mas 41 somente para **guiado**, supondo que o tamanho da parte de um padrão. Com um tamanho de bloco de 25, **dinâmica** e **guiado** ambos concluir 150 unidades, além de quaisquer atrasos das sincronizações necessárias, o qual número agora apenas 40 e 20, respectivamente.