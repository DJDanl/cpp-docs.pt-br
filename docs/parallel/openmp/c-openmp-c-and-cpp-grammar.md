---
title: C. OpenMP C e C++ gramática
ms.date: 01/16/2019
ms.assetid: 97a878ce-1533-47f7-a134-66fcbff48524
ms.openlocfilehash: 85e18161079b49e83cc9fedb3184ee220c889e75
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62362940"
---
# <a name="c-openmp-c-and-c-grammar"></a>C. OpenMP C e C++ gramática

[C.1 Notação](#c1-notation)<br/>
[C.2 Regras](#c2-rules)

## <a name="c1-notation"></a>C.1 Notação

As regras de gramática consistem no nome de um não terminal, seguido por dois-pontos, seguido por alternativas de substituição em linhas separadas.

O termo de expressão sintática<sub>opt</sub> indica que o termo é opcional dentro da substituição.

A expressão sintática *termo*<sub>optseq</sub> é equivalente a *termo seq*<sub>aceitar</sub> com as seguintes regras adicionais:

*term-seq*:  
&nbsp;&nbsp;&nbsp;&nbsp;*term*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*term-seq* *term*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*term-seq*   `,` *term*

## <a name="c2-rules"></a>C.2 Regras

A notação é descrita na seção 6.1 do padrão C. Este apêndice gramática mostra as extensões para a gramática da linguagem de base para as diretivas OpenMP C e C++.

**/\* no C++ (ISO/IEC 14882:1998) \*/**

*statement-seq*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*openmp-directive*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement-seq statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement-seq openmp-directive*

**/\* no C90 (ISO/IEC 9899:1990) \*/**

*statement-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*openmp-directive*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de lista de instruções*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement-list openmp-directive*

**/\* em C99 (ISO/IEC 9899:1999) \*/**

*block-item*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*openmp-directive*

**/\* instruções padrão \*/**

*statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*openmp-construct*

*openmp-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parallel-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*for-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sections-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*single-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parallel-for-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parallel-sections-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*master-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*critical-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*atomic-construct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*construção ordenada*

*openmp-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*barrier-directive*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*flush-directive*

*bloco estruturado*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*

*parallel-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva paralelo*

*parallel-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp parallel` *parallel-clause*<sub>optseq</sub> *new-line*

*parallel-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unique-parallel-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*data-clause*

*unique-parallel-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `if (` *expression*   `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `num_threads (` *expression*   `)`

*for-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de iteração para diretiva*

*for-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp for` *for-clause*<sub>optseq</sub> *new-line*

*for-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unique-for-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*data-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `nowait`

*unique-for-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `ordered`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `schedule (` *schedule-kind*   `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `schedule (` *schedule-kind*   `,` *expression*   `)`

*schedule-kind*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `static`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `dynamic`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `guided`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `runtime`

*sections-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*escopo de seção de diretiva de seções*

*sections-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp sections` *sections-clause*<sub>optseq</sub> *new-line*

*sections-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*data-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `nowait`

*section-scope*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*{seção sequência}*

*section-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de seção*<sub>opt</sub> *bloco estruturado*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de seção diretiva de seção estruturado de blocos*

*section-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp section` *new-line*

*single-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva único*

*diretiva única*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp single` *single-clause*<sub>optseq</sub> *new-line*

*single-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*data-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `nowait`

*parallel-for-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de iteração em paralelo para diretiva*

*parallel-for-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp parallel for` *parallel-for-clause*<sub>optseq</sub> *new-line*

*parallel-for-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unique-parallel-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unique-for-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*data-clause*

*parallel-sections-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*escopo de seção paralelo de seções de diretiva*

*parallel-sections-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp parallel sections` *parallel-sections-clause*<sub>optseq</sub> *new-line*

*parallel-sections-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unique-parallel-clause*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*data-clause*

*master-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva Master*

*diretiva mestre*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp master` *new-line*

*critical-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva Critical*

*critical-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp critical` *region-phrase*<sub>opt</sub> *new-line*

*region-phrase*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*(identificador)*

*barrier-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp barrier` *new-line*

*atomic-construct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de expressão de diretiva Atomic*

*atomic-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp atomic` *new-line*

*flush-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp flush` *flush-vars*<sub>opt</sub> *new-line*

*flush-vars*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*(variable-list)*

*construção ordenada*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva ordenada*

*diretiva ordenada*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp ordered` *new-line*

**/\* declarações padrão \*/**

*declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*threadprivate-directive*

*threadprivate-directive*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `# pragma omp threadprivate (` *variable-list*    `)` *new-line*

*data-clause*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `private (` *variable-list*   `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `copyprivate (`  *variable-list*    `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `firstprivate (`  *variable-list*    `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `lastprivate (` *variable-list*    `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `shared (` *variable-list*   `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `default ( shared )`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `default ( none )`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `reduction (`  *reduction-operator*    `:`  *variable-list*    `)`<br/>
&nbsp;&nbsp;&nbsp;&nbsp;  `copyin (`  *variable-list*    `)`

*reduction-operator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;One of:   `+ \* - & ^ | && ||`

**/\* em C \*/**

*variable-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*variable-list*   `,` *identifier*

**/\* no C++ \*/**

*variable-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*id-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*variable-list*   `,` *id-expression*
