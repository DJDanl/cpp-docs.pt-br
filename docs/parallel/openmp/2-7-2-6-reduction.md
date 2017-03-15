---
title: "2.7.2.6 reduction | Microsoft Docs"
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
ms.assetid: e7630a15-2978-4dbe-a29b-3a46371a0151
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.7.2.6 reduction
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa cláusula realiza uma redução nas variáveis escalares que aparecem no  *variável\-list*, com o op do operador.  A sintaxe do `reduction` cláusula é da seguinte maneira:  
  
```  
  
reduction(  
op  
:  
variable-list  
)  
  
```  
  
 Uma redução geralmente é especificada para uma declaração com uma das seguintes formas:  
  
```  
  
        x     =  x     op     expr  
x     binop=  expr  
x     =  expr     op     x            (except for subtraction)  
x++  
++x  
x--  
--x  
```  
  
 Onde:  
  
 *x*  
 Uma das variáveis de redução especificadas na `list`.  
  
 *lista de variável*  
 Uma lista separada por vírgulas de variáveis escalares de redução.  
  
 *expr*  
 Uma expressão com um tipo escalar que não faz referência a  *x*.  
  
 `op`  
 Não é um operador sobrecarregado, mas uma das \+, \*, \-, &, ^, &#124;, & &, ou &#124; &#124;.  
  
 `binop`  
 Não é um operador sobrecarregado, mas uma das \+, \*, \-, &, ^, ou &#124;.  
  
 A seguir está um exemplo da `reduction` cláusula:  
  
```  
#pragma omp parallel for reduction(+: a, y) reduction(||: am)  
for (i=0; i<n; i++) {  
   a += b[i];  
   y = sum(y, c[i]);  
   am = am || b[i] == c[i];  
}  
```  
  
 Conforme mostrado no exemplo, um operador pode estar oculto dentro de uma chamada de função.  O usuário deve ser cuidado para que o operador especificado na `reduction` cláusula coincide com a operação de redução.  
  
 Embora o operando à direita da &#124; &#124; operador não tem efeitos colaterais neste exemplo, eles são permitidos, mas devem ser usados com cuidado.  Nesse contexto, um efeito colateral que é garantido que não ocorrem durante a execução seqüencial do loop pode ocorrer durante a execução em paralelo.  Essa diferença pode ocorrer porque a ordem de execução das iterações é indeterminada.  
  
 O operador é usado para determinar o valor inicial de qualquer variável particular usados pelo compilador para a redução e determinar o operador de finalização.  Especificar o operador explicitamente permite que a instrução de redução para estar fora do rigor lexical da construção.  Qualquer número de `reduction` cláusulas podem ser especificadas na diretiva, mas uma variável pode aparecer no máximo uma `reduction` cláusula para essa diretiva.  
  
 Uma cópia particular de cada variável no  *variável\-list* é criado, um para cada thread, como se a `private` cláusula tenha sido usada.  A cópia privada é inicializada de acordo com o operador \(consulte a tabela a seguir\).  
  
 No final da região para o qual o `reduction` cláusula foi especificada, o objeto original é atualizado para refletir o resultado da combinação de seu valor original com o valor final de cada uma das cópias privadas usando o operador especificado.  Os operadores de redução são todos associativas \(exceto para subtração\) e o compilador livremente pode reassociar o cálculo do valor final.  \(Os resultados parciais de uma redução de subtração são adicionados para formar o valor final\).  
  
 O valor do objeto original torna\-se indeterminado quando o primeiro thread atinge a cláusula recipiente e permanece isso até que a computação de redução seja concluída.  Normalmente, a computação será concluída no final da construção; No entanto, se o `reduction` a cláusula é usada em uma construção ao qual `nowait` é também aplicado, o valor do objeto original permanecerá indeterminado até executar uma sincronização de barreira para garantir que todos os threads concluiu a `reduction` cláusula.  
  
 A tabela a seguir lista os operadores que são válidos e seus valores de inicialização canônico.  O valor real de inicialização seja consistente com o tipo de dados da variável de redução.  
  
|Operador|Inicialização|  
|--------------|-------------------|  
|\+|0|  
|\*|1|  
|\-|0|  
|&|~0|  
|&#124;|0|  
|^|0|  
|& &|1|  
|&#124;&#124;|0|  
  
 As restrições para o `reduction` cláusula são os seguintes:  
  
-   O tipo de variáveis na `reduction` cláusula deve ser válida para o operador de redução, exceto que os tipos de ponteiro e tipos de referência nunca são permitidos.  
  
-   Uma variável que é especificada na `reduction` cláusula não deve ser  **const**\-qualificado.  
  
-   Variáveis que são privados dentro de uma região paralela ou que aparecem na `reduction` cláusula de um  **paralela** diretiva não pode ser especificada um `reduction` cláusula em uma diretiva de compartilhamento de trabalho que vincula a construção parallel.  
  
    ```  
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