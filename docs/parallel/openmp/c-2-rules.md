---
title: C. 2 regras | Microsoft Docs
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
ms.openlocfilehash: a3bdf26435fdfeea2196b9ef281d656805f51bf2
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="c2-rules"></a>C.2 Regras
A notação é descrita na seção 6.1 C padrão. Este apêndice gramática mostra as extensões a gramática da linguagem de base para as diretivas OpenMP C e C++.  
  
 **/\* em C++ (ISO/IEC 14882:1998) \*/**  
  
 *instrução seq*:  
  
 *statement*  
  
 *diretiva de OpenMP*  
  
 *instrução de declaração seq*  
  
 *diretiva de openmp seq de instrução*  
  
 **/\* no C90 (ISO/IEC 9899:1990) \*/**  
  
 *statement-list*:  
  
 *statement*  
  
 *diretiva de OpenMP*  
  
 *statement-list statement*  
  
 *diretiva de openmp lista de instruções*  
  
 **/\* no C99 (ISO/IEC 9899:1999) \*/**  
  
 *Bloquear item*:  
  
 *declaration*  
  
 *statement*  
  
 *diretiva de OpenMP*  
  
 *statement*:  
  
 **/\* instruções padrão \*/**  
  
 *construção de OpenMP*  
  
 *construção OpenMP*:  
  
 *construção paralela*  
  
 *para criar*  
  
 *construção de seções*  
  
 *construção de único*  
  
 *paralelo para construção*  
  
 *construção de seções de paralelo*  
  
 *construc mestre*  
  
 *construto Critical*  
  
 *constructo Atomic*  
  
 *construção ordenada*  
  
 *diretiva de OpenMP*:  
  
 *diretiva de barreira*  
  
 *diretiva de liberação*  
  
 *bloco estruturado*:  
  
 *statement*  
  
 *construção paralela*:  
  
 *bloco estruturado paralela diretiva*  
  
 *diretiva paralelo*:  
  
 **# pragma omp parallel***paralelo cláusula*optseq *nova linha*   
  
 *cláusula paralelo*:  
  
 *cláusula exclusivo paralelo*  
  
 *cláusula de dados*  
  
 *cláusula exclusivo paralelo*:  
  
 **Se (** *expressão* **)**  
  
 **num_threads (** *expressão* **)**  
  
 *para construir*:  
  
 *instrução de iteração para diretiva*  
  
 *para diretiva*:  
  
 **# pragma omp para** *para cláusula*optseq *nova linha*  
  
 *cláusula for*:  
  
 *exclusivo para cláusula*  
  
 *cláusula de dados*  
  
 **nowait**  
  
 *exclusivo para cláusula*:  
  
 **ordenados**  
  
 **agenda (** *tipo de agenda* **)**  
  
 **agenda (** *tipo de agenda* **,** *expressão* **)**  
  
 *tipo de agenda*:  
  
 **static**  
  
 **dynamic**  
  
 **interativa**  
  
 **Tempo de execução**  
  
 *construção de seções*:  
  
 *escopo de seção de diretiva de seções*  
  
 *diretiva de seções*:  
  
 **seções do # pragma omp** *seções cláusula*optseq *nova linha*  
  
 *cláusula seções*:  
  
 *cláusula de dados*  
  
 **nowait**  
  
 *escopo de seção*:  
  
 *{seção sequência}*  
  
 *sequência de seção*:  
  
 *diretiva de seção*aceitação *bloco estruturado*  
  
 *sequência de seção diretiva de seção estruturado de bloco*  
  
 *diretiva de seção*:  
  
 **seção do # pragma omp** *nova linha*  
  
 *construção de único*:  
  
 *diretiva único bloco estruturado*  
  
 *diretiva única*:  
  
 **# pragma omp único** *única cláusula*optseq *nova linha*  
  
 *cláusula única*:  
  
 *cláusula de dados*  
  
 **nowait**  
  
 *paralelo para construção*:  
  
 *instrução de iteração em paralelo para diretiva*  
  
 *paralelo para diretiva*:  
  
 **# pragma omp parallel para** *paralelo para cláusula*optseq *nova linha*  
  
 *paralelo para cláusula*:  
  
 *cláusula exclusivo paralelo*  
  
 *exclusivo para cláusula*  
  
 *cláusula de dados*  
  
 *construção de seções paralelo*:  
  
 *escopo de seção paralelo de seções de diretiva*  
  
 *diretiva de seções paralelo*:  
  
 **seções de paralelo # pragma omp** *paralelo de seções de cláusula*optseq *nova linha*  
  
 *cláusula de seções paralelo*:  
  
 *cláusula exclusivo paralelo*  
  
 *cláusula de dados*  
  
 *construção mestre*:  
  
 *bloco estruturado de diretiva mestre*  
  
 *diretiva mestre*:  
  
 **mestre do # pragma omp** *nova linha*  
  
 *construto Critical*:  
  
 *bloco estruturado de diretiva crítica*  
  
 *diretiva crítica*:  
  
 **# pragma omp crítico** *região frase*aceitação *nova linha*  
  
 *frase de região*:  
  
 *(identificador)*  
  
 *diretiva de barreira*:  
  
 **barreira do # pragma omp** *nova linha*  
  
 *constructo Atomic*:  
  
 *instrução de expressão de diretiva atômica*  
  
 *diretiva atômica*:  
  
 **# pragma omp atomic** *nova linha*  
  
 *diretiva de liberação*:  
  
 **# pragma omp liberação** *vars de liberação*aceitação *nova linha*  
  
 *liberação vars*:  
  
 *(lista de variável)*  
  
 *construção ordenada*:  
  
 *diretiva ordenada bloco estruturado*  
  
 *diretiva ordenada*:  
  
 **# pragma omp ordenados** *nova linha*  
  
 *declaração*:  
  
 **/\* declarações padrão \*/**  
  
 *diretiva threadprivate*  
  
 *diretiva threadprivate*:  
  
 **# pragma omp threadprivate (** *lista variável***)** *nova linha*   
  
 *cláusula dados*:  
  
 **privada (** *lista variável* **)**  
  
 **copyprivate (***lista variável***)**   
  
 **firstprivate (***lista variável***)**   
  
 **lastprivate (** *lista variável***)**   
  
 **compartilhado (** *lista variável* **)**  
  
 **padrão (compartilhado)**  
  
 **padrão (nenhum)**  
  
 **redução (***operador de reduction***:***lista variável***)**   
  
 **copyin (***lista variável***)**   
  
 *operador de Reduction*:  
  
 *Um dos*:  **+  \* -& ^ &#124; & &&#124;&#124;**  
  
 **/\* em C \*/**  
  
 *lista de variável*:  
  
 *identifier*  
  
 *lista de variável* **,** *identificador*  
  
 **/\* em C++ \*/**  
  
 *lista de variável*:  
  
 *ID de expressão*  
  
 *lista de variável* **,** *id de expressão*