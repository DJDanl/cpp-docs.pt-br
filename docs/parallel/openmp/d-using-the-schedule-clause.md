---
title: D. A cláusula de agendamento
ms.date: 01/22/2019
ms.assetid: bf3d8f51-ea05-4803-bf55-657c12e91efe
ms.openlocfilehash: 89e011784c5cccedc4a75f38d553458ea2e5d7e0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62362875"
---
# <a name="d-the-schedule-clause"></a>D. A cláusula de agendamento

Uma região parallel tem pelo menos uma barreira, no final e pode ter barreiras adicionais dentro dele. Em cada barreira, os outros membros da equipe devem aguardar o último thread chegar. Para minimizar esse tempo de espera, o trabalho compartilhadas deve ser distribuído para que todos os threads chegarem a barreira em aproximadamente ao mesmo tempo. Se algum dos que compartilhou o trabalho está contido em `for` constructos, o `schedule` cláusula pode ser usada para essa finalidade.

Quando há referências repetidas aos mesmos objetos, a opção de agendamento para um `for` construção pode ser determinada principalmente pelo características do sistema de memória, como a presença e o tamanho de caches e se o número de acessos de memória são uniforme ou nonuniform. Essas considerações podem tornar preferível para fazer com que cada thread consistentemente se referem ao mesmo conjunto de elementos de uma matriz em uma série de loops, mesmo se alguns threads recebem relativamente menos trabalho em alguns dos loops. Essa configuração pode ser feita usando o `static` agenda com limites iguais para todos os circuitos. No exemplo a seguir, zero é usado como o limite inferior no segundo loop, embora `k` seria mais natural se o agendamento não foram importante.

```cpp
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

Nos exemplos restantes, ele supõe que a memória acesso não é a consideração dominante. Salvo indicação contrária, que todos os threads recebem recursos computacionais comparáveis. Nesses casos, a opção de agendamento para um `for` constructo depende de todo o trabalho compartilhado deve ser executada entre precedente mais próximo barreira e a barreira de fechamento implícitas ou o mais próximo da barreira futura, se houver um `nowait` cláusula. Para cada tipo de agenda, um pequeno exemplo mostra como esse tipo de agenda é provavelmente a melhor opção. Uma breve discussão segue cada exemplo.

O `static` agendamento também é adequado para o caso mais simples, uma região paralela que contém um único `for` construir, com cada iteração exigindo a mesma quantidade de trabalho.

```cpp
#pragma omp parallel for schedule(static)
for(i=0; i<n; i++) {
  invariant_amount_of_work(i);
}
```

O `static` agenda é caracterizada pelas propriedades que cada thread obtém aproximadamente o mesmo número de iterações que qualquer outro thread, e cada thread de forma independente pode determinar as iterações atribuídas a ele. Portanto, nenhuma sincronização é necessária para distribuir o trabalho e, sob a suposição de que cada iteração requer a mesma quantidade de trabalho, todos os threads devem ser concluído em aproximadamente ao mesmo tempo.

Para uma equipe de *p* threads, deixe *ceiling(n/p)* ser o número inteiro *q*, que satisfaz *n = p\*p - r* com *0 < = r < p*. Uma implementação do `static` agendar para este exemplo atribuiria *q* iterações para a primeira *p-1* threads, e *p e r* iterações para o último thread.  Outra implementação aceitável atribuiria *q* iterações para a primeira *p-r* threads, e *q-1* iterações para o restante *r*segmentos. Este exemplo ilustra por que um programa não deve confiar nos detalhes de uma implementação específica.

O `dynamic` agendamento é apropriado para o caso de um `for` construir com as iterações que exigem variadas, ou até mesmo imprevisíveis, quantidades de trabalho.

```cpp
#pragma omp parallel for schedule(dynamic)
  for(i=0; i<n; i++) {
    unpredictable_amount_of_work(i);
}
```

O `dynamic` agenda é caracterizada pela propriedade que nenhum thread aguarda a barreira de leva mais tempo do que outro thread para executar sua iteração final. Esse requisito significa iterações devem ser atribuídas um de cada vez para threads conforme eles se tornam disponíveis, com a sincronização para cada atribuição. A sobrecarga de sincronização pode ser reduzida, especificando um tamanho de parte mínimo *k* maior que 1, para que os threads são atribuídos *k* cada vez até menos de *k* permanecem. Isso garante que nenhum thread aguarda em mais do que o que leva a outro thread para executar sua parte final do (no máximo) barreira *k* iterações.

O `dynamic` agenda pode ser útil se os threads recebem variados recursos computacionais, que tem o mesmo efeito como diferentes quantidades de trabalho para cada iteração. Da mesma forma, o agendamento dinâmico também pode ser útil se os threads de chegarem a `for` construir em momentos diferentes, embora em alguns casos o `guided` agenda pode ser preferível.

O `guided` agendamento é apropriado para o caso em que os threads podem chegar em horários diferentes em um `for` construir com cada iteração exigindo aproximadamente a mesma quantidade de trabalho. Essa situação pode ocorrer se, por exemplo, o `for` constructo é precedido por uma ou mais seções ou `for` constrói com `nowait` cláusulas.

```cpp
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

Como o `dynamic`, o `guided` garante que nenhum thread aguarda na barreira mais do que o que leva a outro thread para executar sua iteração final ou final de agendar *k* iterações se um tamanho de bloco de *k* for especificado. Entre esse tipo de agenda, o `guided` agenda é caracterizada pela propriedade que ele requer que as sincronizações menor. Para o tamanho da parte *k*, atribuirá uma implementação típica *q = ceiling(n/p)* iterações para o primeiro thread disponível, defina *n* como o maior de *n-p* e *p\*k*e repita até que todas as iterações são atribuídas.

Quando a opção da agenda ideal não é tão clara como ele é para esses exemplos, o `runtime` agenda é conveniente para experimentar com diferentes agendamentos e tamanhos de partes sem a necessidade de modificar e recompilar o programa. Ele também pode ser útil quando a programação ideal depende (de alguma forma previsível) os dados de entrada aos quais o programa for aplicado.

Para ver um exemplo de como as vantagens e desvantagens entre diferentes agendas, considere a 1000 iterações entre oito threads de compartilhamento. Suponha que exista uma invariável quantidade de trabalho em cada iteração e usá-lo como a unidade de tempo.

Se todos os threads começam ao mesmo tempo, o `static` agenda fará com que a construção executar em unidades de 125, sem sincronização. Mas suponha que um thread seja 100 unidades no final que chegam. Em seguida, os threads restantes de sete aguardam para 100 unidades na barreira e o tempo de execução para a construção inteira aumenta para 225.

Como tanto o `dynamic` e `guided` agendas Certifique-se de que nenhum thread aguarda mais de uma unidade em que a barreira, o thread atrasado faz com que seus tempos de execução para a construção aumentar somente para as unidades de 138, possivelmente aumentadas em atrasos de sincronização. Se esses atrasos não são muito importantes, é importante que o número de sincronizações de é 1000 para `dynamic` mas 41 somente para `guided`, supondo que o tamanho da parte de um padrão. Com um tamanho de bloco de 25 `dynamic` e `guided` ambos concluir 150 unidades, além de quaisquer atrasos das sincronizações necessárias, o qual número agora apenas 40 e 20, respectivamente.
