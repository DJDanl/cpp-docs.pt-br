---
title: C.2 regras | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 4d52fef7-3eb7-4480-a335-8ed48681092b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1c5845a9125bb32254fc0c03b03e9b6076a086d1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404768"
---
# <a name="c2-rules"></a>C.2 Regras

A notação é descrita na seção 6.1 do padrão C. Este apêndice gramática mostra as extensões para a gramática da linguagem de base para as diretivas OpenMP C e C++.

**/\* no C++ (ISO/IEC 14882:1998) \*/**

*instrução seq*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de OpenMP*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de declaração seq*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de openmp seq de instrução*

**/\* no C90 (ISO/IEC 9899:1990) \*/**

*statement-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de OpenMP*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de lista de instruções*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de openmp da lista de instruções*

**/\* em C99 (ISO/IEC 9899:1999) \*/**

*Bloquear item*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de OpenMP*

**/\* instruções padrão \*/**

*statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*construção de OpenMP*

*construção de OpenMP*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*construção paralela*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*para construção*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*construção de seções*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*construção de único*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*paralelo para construção*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*paralelo de seções de construção*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*constructo Master*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*construto crítico*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*constructo Atomic*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*construção ordenada*

*diretiva de OpenMP*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de barreira*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de liberação*

*bloco estruturado*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement*

*constructo paralelo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva paralelo*

*diretiva paralelo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp parallel** *cláusula paralelo*<sub>optseq</sub> *nova linha*

*cláusula paralelo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula exclusivo paralelo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula de dados*

*cláusula exclusivo paralelo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Se (** *expressão* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**num_threads (** *expressão* **)**

*para construção*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de iteração para diretiva*

*para diretiva*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp para** *para cláusula*<sub>optseq</sub> *nova linha*

*cláusula for*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*exclusivo para cláusula*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula de dados*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**nowait**

*exclusivo para cláusula*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Ordenado**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**agenda (** *tipo de agenda* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**agenda (** *tipo de agenda* **,** *expressão* **)**

*tipo de agenda*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**static**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dinâmico**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**interativa**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**tempo de execução**

*construção de seções*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*escopo de seção de diretiva de seções*

*diretiva de seções*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**seções do # pragma omp** *cláusula seções*<sub>optseq</sub> *nova linha*

*cláusula seções*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula de dados*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**nowait**

*escopo de seção*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*{seção sequência}*

*sequência de seção*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva de seção*<sub>opt</sub> *bloco estruturado*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sequência de seção diretiva de seção estruturado de blocos*

*diretiva de seção*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**seção do # pragma omp** *nova linha*

*construção de único*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva único*

*diretiva única*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp única** *única cláusula*<sub>optseq</sub> *nova linha*

*única cláusula*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula de dados*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**nowait**

*paralelo para construção*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de iteração em paralelo para diretiva*

*paralelo para diretiva*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp parallel para** *paralelo para cláusula*<sub>optseq</sub> *nova linha*

*cláusula for paralelo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula exclusivo paralelo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*exclusivo para cláusula*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula de dados*

*construção de seções de paralelo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*escopo de seção paralelo de seções de diretiva*

*diretiva de seções de paralelo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**seções paralela do # pragma omp** *paralelo de seções de cláusula*<sub>optseq</sub> *nova linha*

*paralelo de seções de cláusula*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula exclusivo paralelo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cláusula de dados*

*construção de mestre*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva Master*

*diretiva mestre*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**mestre do # pragma omp** *nova linha*

*construto Critical*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva Critical*

*diretiva Critical*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp crítico** *região frase*<sub>aceitar</sub> *nova linha*

*frase de região*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*(identificador)*

*diretiva de barreira*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**barreira do # pragma omp** *nova linha*

*constructo Atomic*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de expressão de diretiva Atomic*

*diretiva Atomic*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp atomic** *nova linha*

*diretiva Flush*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp liberação** *flush vars*<sub>aceitar</sub> *nova linha*

*liberação vars*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*(lista de variável)*

*construção ordenada*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*bloco estruturado de diretiva ordenada*

*diretiva ordenada*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp ordenados** *nova linha*

**/\* declarações padrão \*/**

*declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva threadprivate*

*diretiva threadprivate*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**# pragma omp threadprivate (** *variável-list***)** *nova linha* 

*cláusula data*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**privado (** *variável-list* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**copyprivate (***variável-list***)** <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**firstprivate (***variável-list***)** <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**lastprivate (** *variável-list***)** <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**compartilhado (** *variável-list* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**padrão (compartilhado)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**padrão (nenhum)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**redução de (***operador de reduction***:***lista variável***)** <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**copyin (***variável-list***)** 

*operador de Reduction*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Um dos:  **+  \* -& ^ &#124; & &&#124;&#124;**

**/\* em C \*/**

*lista de variável*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de variável* **,** *identificador*

**/\* no C++ \*/**

*lista de variável*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de variável* **,** *id-expression*