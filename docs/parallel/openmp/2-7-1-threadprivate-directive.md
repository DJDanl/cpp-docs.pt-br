---
title: 2.7.1 Diretiva threadprivate
ms.date: 11/04/2016
ms.assetid: 08e0b70f-5359-4607-b0ca-38c2d570d7b3
ms.openlocfilehash: 0ba5ea4892d70458f0f63bcb5b92968b36235273
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646999"
---
# <a name="271-threadprivate-directive"></a>2.7.1 Diretiva threadprivate

O `threadprivate` diretiva torna o escopo de arquivo nomeado, escopo de namespace ou variáveis estáticas de escopo de bloco especificadas na *lista variável* privada para um thread. *lista de variável* é uma lista separada por vírgulas de variáveis que não têm um tipo incompleto. A sintaxe do `threadprivate` diretiva é da seguinte maneira:

```
#pragma omp threadprivate(variable-list) new-line
```

Cada cópia de um `threadprivate` variável é inicializada uma vez, em um ponto especificado no programa antes da primeira referência para a cópia e da maneira usual (ou seja, como a cópia mestra deve ser inicializada em uma execução serial do programa). Observe que, se um objeto é referenciado no inicializador explícito de um `threadprivate` variável e o valor do objeto é modificado antes da primeira referência a uma cópia da variável e, em seguida, o comportamento é especificado.

Como com qualquer variável particular, um thread não deve fazer referência a cópia do outro thread de um `threadprivate` objeto. Durante a regiões seriais e mestre do programa, referências será a cópia mestre do segmento do objeto.

Depois que a primeira região paralela é executada, os dados no `threadprivate` objetos é garantido para manter somente se o mecanismo de threads de dinâmica foi desabilitada e, se o número de threads permanece inalterado para todas as regiões em paralelo.

As restrições para o `threadprivate` diretiva são da seguinte maneira:

- Um `threadprivate` diretiva para variáveis de escopo de arquivo ou o escopo de namespace deve aparecer fora de qualquer definição ou declaração e deve preceder lexicalmente todas as referências a qualquer uma das variáveis em sua lista.

- Cada variável na *variável-list* de um `threadprivate` diretiva no escopo de namespace ou arquivo deve se referir a uma declaração de variável no escopo de namespace ou arquivo que precede lexicalmente a diretiva.

- Um `threadprivate` diretiva para variáveis estáticas de escopo de bloco deve aparecer no escopo da variável e não em um escopo aninhado. A diretiva deve preceder lexicalmente todas as referências a qualquer uma das variáveis em sua lista.

- Cada variável na *variável-list* de um `threadprivate` diretiva no escopo de bloco deve se referir a uma declaração de variável no mesmo escopo que precede lexicalmente a diretiva. A declaração de variável deve usar o especificador de classe de armazenamento estático.

- Se uma variável for especificada em uma `threadprivate` diretiva em uma unidade de conversão, ele deve ser especificado em um `threadprivate` diretiva em cada unidade de tradução na qual ela é declarada.

- Um `threadprivate` variável não deve aparecer em qualquer cláusula, exceto o `copyin`, `copyprivate`, `schedule`, `num_threads`, ou o **se** cláusula.

- O endereço de um `threadprivate` variável não é uma constante de endereço.

- Um `threadprivate` variável não deve ter um tipo incompleto ou um tipo de referência.

- Um `threadprivate` variável com tipo de classe não POD deve ter um construtor de cópia acessível e não ambígua, se ela for declarada com um inicializador explícito.

O exemplo a seguir ilustra como modificar uma variável que é exibido em um inicializador que pode causar um comportamento não especificado e também como evitar esse problema usando um objeto auxiliar e um construtor de cópia.

```
int x = 1;
T a(x);
const T b_aux(x); /* Capture value of x = 1 */
T b(b_aux);
#pragma omp threadprivate(a, b)

void f(int n) {
   x++;
   #pragma omp parallel for
   /* In each thread:
   * Object a is constructed from x (with value 1 or 2?)
   * Object b is copy-constructed from b_aux
   */
   for (int i=0; i<n; i++) {
      g(a, b); /* Value of a is unspecified. */
   }
}
```

## <a name="cross-references"></a>Entre as referências:

- Threads dinâmicos, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.

- `OMP_DYNAMIC` Consulte de variável de ambiente [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.