---
title: "2.7.1 threadprivate Directive | Microsoft Docs"
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
ms.assetid: 08e0b70f-5359-4607-b0ca-38c2d570d7b3
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.7.1 threadprivate Directive
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `threadprivate` diretiva faz com que o escopo do arquivo nomeado, escopo do espaço para nome ou variáveis de escopo de bloco estática especificadas na  *variável\-list* particular para um segmento.  *variável\-list* é uma lista separada por vírgulas de variáveis que não têm um tipo incompleto.  A sintaxe do `threadprivate` diretiva é o seguinte:  
  
```  
#pragma omp threadprivate(variable-list) new-line  
```  
  
 Cada cópia de um `threadprivate` variável é inicializada de uma vez, em um ponto especificado no programa antes da primeira referência a essa cópia e da maneira normal \(ou seja, como a cópia mestra deve ser inicializada em uma execução serial do programa\).  Observe que, se um objeto é referenciado no inicializador explícito de um `threadprivate` e o valor do objeto é modificado antes para a primeira referência a uma cópia da variável, em seguida, o comportamento não for especificado.  
  
 Como com qualquer variável particular, um thread não deve fazer referência a cópia do segmento de um `threadprivate` objeto.  Durante a regiões seriais e regiões mestres do programa, referências será a cópia mestre do segmento do objeto.  
  
 Após a primeira região paralela ser executada, os dados do `threadprivate` objetos é garantido para persistir somente se o mecanismo de threads a dinâmica foi desativado e se o número de segmentos permanece inalterado para todas as regiões paralelas.  
  
 As restrições para o `threadprivate` diretiva são os seguintes:  
  
-   A `threadprivate` diretiva para variáveis de escopo do arquivo ou o escopo do espaço para nome deve aparecer fora de qualquer declaração ou definição e lexicalmente deve preceder todas as referências a qualquer uma das variáveis em sua lista.  
  
-   Cada variável no  *variável\-list* de um `threadprivate` diretiva no escopo do arquivo ou namespace deve se referir a uma declaração de variável no escopo do arquivo ou namespace que lexicalmente precede a diretiva.  
  
-   A `threadprivate` a diretiva para variáveis estáticas de escopo de bloco deve aparecer no escopo da variável e não em um escopo aninhado.  A diretiva lexicalmente deve preceder todas as referências a qualquer uma das variáveis em sua lista.  
  
-   Cada variável no  *variável\-list* de um `threadprivate` diretiva no escopo de bloco deve se referir a uma declaração de variável no mesmo escopo que lexicalmente precede a diretiva.  A declaração de variável deve usar o especificador de classe estática de armazenamento.  
  
-   Se uma variável é especificada em um `threadprivate` diretiva na unidade de uma tradução, ele deve ser especificado em um `threadprivate` diretiva em cada unidade de conversão na qual é declarada.  
  
-   A `threadprivate` variável não pode aparecer em qualquer cláusula, exceto o `copyin`, `copyprivate`, `schedule`, `num_threads`, ou o  **se** cláusula.  
  
-   O endereço de um `threadprivate` variável não é uma constante de endereço.  
  
-   A `threadprivate` variável não deve ter um tipo incompleto ou um tipo de referência.  
  
-   A `threadprivate` variável com tipo de classe não\-POD deve ter um construtor de cópia acessíveis, inequívoca se ela for declarada com um inicializador explícito.  
  
 O exemplo a seguir ilustra como a modificação de uma variável que aparece em um inicializador pode causar comportamento não especificado e também como evitar esse problema usando um objeto auxiliar e um construtor de cópia.  
  
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
  
## Entre as referências:  
  
-   Segmentos dinâmicos, consulte  [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.  
  
-   `OMP_DYNAMIC`Consulte variável, do ambiente  [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.