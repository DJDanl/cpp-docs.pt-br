---
title: Arquivos e programas de origem | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- files [C++], source
- programs [C++], source
- source files, specifying in compiler
- source programs
ms.assetid: 18bb2826-17da-48e5-92a2-10e649f1bc9f
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: b1e663fc53dd1fe0964523b90dfe010a0188e597
ms.lasthandoff: 02/25/2017

---
# <a name="source-files-and-source-programs"></a>Arquivos e programas de origem
Um programa de origem pode ser dividido em um ou mais "arquivos de origem “ ou “unidades de conversão”. A entrada no compilador é chamada de "unidade de conversão".  
  
## <a name="syntax"></a>Sintaxe  
 *translation-unit*:  
 *external-declaration*  
  
 *translation-unit external-declaration*  
  
 *external-declaration*:  
 *function-definition*  
  
 *declaration*  
  
 [Visão geral das declarações](../c-language/overview-of-declarations.md) fornece a sintaxe da `declaration` não terminal e *Referência do pré-processador* explica como a [unidade de translação](../preprocessor/phases-of-translation.md) é processada.  
  
> [!NOTE]
>  Consulte a introdução do [Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md) para obter uma explicação das convenções de sintaxe ANSI.  
  
 Os componentes de uma unidade de conversão são declarações externas que incluem definições de função e declarações de identificador. Essas declarações e definições podem estar nos arquivos de origem, arquivos de cabeçalho, bibliotecas e outros arquivos de que o programa precisa. Você deve compilar cada unidade de conversão e vincular os arquivos de objeto resultantes para criar um programa.  
  
 Um “programa de origem” C é uma coleção de políticas, pragmas, declarações, definições, blocos de instruções e funções. Para que sejam componentes válidos de um programa do Microsoft C, cada um deve ter a sintaxe descrita neste manual, embora possam aparecer em qualquer ordem no programa (sujeito às regras definidas ao longo deste manual). No entanto, o local desses componentes em um programa afeta como variáveis e funções podem ser usadas em um programa. (Consulte [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md) para obter mais informações.)  
  
 Os arquivos de origem não precisam conter instruções executáveis. Por exemplo, você pode considerar útil colocar definições de variáveis em um arquivo de origem e depois declarar referências a essas variáveis em outros arquivos de origem que as usam. Essa técnica torna as definições fáceis de localizar e atualizar quando necessário. Pela mesma razão, constantes e macros são geralmente organizadas em arquivos separados chamados “arquivos de inclusão” ou “arquivos de cabeçalho” que podem ser referenciados nos arquivos de origem conforme necessário. Consulte a *Referência do pré-processador* para obter informações sobre [macros](../preprocessor/macros-c-cpp.md) e [arquivos de inclusão](../preprocessor/hash-include-directive-c-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura do Programa](../c-language/program-structure.md)
