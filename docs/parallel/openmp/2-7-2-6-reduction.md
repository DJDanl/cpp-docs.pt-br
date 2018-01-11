---
title: "2.7.2.6 redução de | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: e7630a15-2978-4dbe-a29b-3a46371a0151
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 684067eae668398e71ca4ace0cc136e3210e0dbf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="2726-reduction"></a>2.7.2.6 reduction

Essa cláusula executa uma redução nas variáveis escalares que aparecem em *lista variável*, com o operador *op*. A sintaxe de `reduction` cláusula é o seguinte:

> redução (*op*: *lista variável*)

Uma redução geralmente é especificada para uma instrução com uma das seguintes formas:

> *x* = *x* *op* *expr*  
> *x* *binop* = *expr*  
> *x* = *expr* *op* *x* (com exceção de subtração)  
> *x*++  
> ++*x*  
> *x*--  
> --*x*  

em que:

*x*  
Uma das variáveis de redução especificadas no `list`.

*lista de variável*  
Uma lista separada por vírgulas de variáveis de redução de escalar.

*expr*  
Uma expressão com um tipo escalar que não faz referência a *x*.

*operações*  
Não é um operador sobrecarregado, mas um dos +, &#42; -, &amp;, ^, &#124; &amp; &amp;, ou &#124; &#124;.

*binop*  
Não é um operador sobrecarregado, mas um dos +, &#42; -, &amp;, ^, ou &#124;.

A seguir está um exemplo de como o `reduction` cláusula:  
  
```cpp  
#pragma omp parallel for reduction(+: a, y) reduction(||: am)  
for (i=0; i<n; i++) {  
   a += b[i];  
   y = sum(y, c[i]);  
   am = am || b[i] == c[i];  
}  
```  
  
Conforme mostrado no exemplo, um operador pode estar oculto dentro de uma chamada de função. O usuário deve ter cuidado que o operador especificado no `reduction` cláusula corresponde a operação de redução.

Embora o operando direito do &#124; &#124; operador não tem efeitos colaterais neste exemplo, são permitidos, mas deve ser usadas com cuidado. Nesse contexto, um efeito colateral que é garantido que não ocorrem durante a execução do loop sequencial pode ocorrer durante a execução paralela. Essa diferença pode ocorrer porque a ordem de execução das iterações é indeterminada.

O operador é usado para determinar o valor inicial de todas as variáveis privadas usado pelo compilador para a redução e determinar o operador de finalização. Especificar explicitamente o operador permite que a instrução de redução fora a extensão de léxica da construção. Qualquer número de `reduction` cláusulas podem ser especificadas na diretiva, mas uma variável pode aparecer no máximo uma `reduction` cláusula para essa diretiva.

Uma cópia privada de cada variável *lista variável* é criado, uma para cada thread, como se o `private` cláusula tivesse sido usada. A cópia particular é inicializada de acordo com o operador (consulte a tabela a seguir).

No final da região para a qual o `reduction` cláusula foi especificada, o objeto original é atualizado para refletir o resultado da combinação de seu valor original com o valor final de cada uma das cópias privadas usando o operador especificado. Os operadores de redução são todos associativos (exceto subtração) e o compilador pode livremente reassociar o cálculo do valor final. (Os resultados parciais de uma redução de subtração são adicionados para formar o valor final).

O valor do objeto original se torna indeterminado quando o primeiro thread atinge a cláusula recipiente e permanece isso até que a computação de redução for concluída.  Normalmente, o cálculo será concluído ao final da construção; No entanto, se o `reduction` cláusula é usada em uma construção que `nowait` é também aplicada, o valor do objeto original permanece indeterminado até que uma sincronização de barreira foi executada para garantir que todos os threads concluiu a `reduction`cláusula.

A tabela a seguir lista os operadores que são válidos e seus valores de inicialização canônico. O valor real de inicialização seja consistente com o tipo de dados da variável de redução.

|Operador|Inicialização|
|--------------|--------------------|
|+|0|
|&#42;|1|
|-|0|
|&amp;|~0|
|&#124;|0|
|^|0|
|&amp;&amp;|1|
|&#124;&#124;|0|

As restrições para o `reduction` cláusula são da seguinte maneira:

- O tipo das variáveis no `reduction` cláusula deve ser válida para o operador de redução, exceto que os tipos de referência e tipos de ponteiro nunca são permitidos.

- Uma variável que é especificada no `reduction` cláusula não deve ser **const**-qualificado.

- Variáveis que são particulares dentro de uma região parallel ou que aparecem no `reduction` cláusula de um **paralela** diretiva não pode ser especificada um `reduction` cláusula em uma diretiva de compartilhamento de trabalho que vincula-se para a construção paralela.

   ```cpp
   #pragma omp parallel private(y)
   { /* ERROR - private variable y cannot be specified
                in a reduction clause */
      #pragma omp for reduction(+: y)
      for (i=0; i<n; i++)
         y += b[i];
   }
   
   /* ERROR - variable x cannot be specified in both
              a shared and a reduction clause */
   #pragma omp parallel for shared(x) reduction(+: x)
   ```
