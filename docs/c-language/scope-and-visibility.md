---
title: "Escopo e visibilidade | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "escopo de arquivo [C++]"
  - "escopo, níveis"
  - "visibilidade"
ms.assetid: a019eb7c-66ed-46a7-bc9f-89a963930a56
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Escopo e visibilidade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A "visibilidade" de um identificador determina as partes do programa nas quais pode ser feita uma referência a ele — seu "escopo”. Um identificador é visível \(ou seja, pode ser usado\) somente nas partes de um programa abrangidas por seu “escopo”, que pode ser limitado \(em ordem crescente de restrição\) ao arquivo, função, bloco ou protótipo de função em que aparece.  O escopo de um identificador é a parte do programa na qual o nome pode ser usado.  Isso é às vezes chamado de “escopo léxico”. Há quatro tipos de escopo: de função, de arquivo, de bloco e de protótipo de função.  
  
 Todos os identificadores, exceto os rótulos, têm seu escopo determinado pelo nível em que a declaração ocorre.  As seguintes regras para cada tipo de escopo controlam a visibilidade dos identificadores em um programa:  
  
 Escopo de arquivo  
 O declarador ou especificador de tipo de um identificador com escopo de arquivo aparece fora de qualquer bloco ou lista de parâmetros e está acessível de qualquer local da unidade de tradução após sua declaração.  Os nomes de identificadores com escopo de arquivo são frequentemente denominados “globais” ou “externos”. O escopo de um identificador global inicia no ponto da sua definição ou declaração e termina no final da unidade de tradução.  
  
 Escopo de função  
 Um rótulo é o único tipo de identificador que tem escopo de função.  Um rótulo é declarado implicitamente por seu uso em uma instrução.  Os nomes de rótulos devem ser exclusivos dentro de uma função. \(Para obter mais informações sobre rótulos e nomes de rótulo, consulte [Instruções goto e identificadas](../c-language/goto-and-labeled-statements-c.md).\)  
  
 Escopo de bloco  
 O declarador ou especificador de tipo de um identificador de escopo de bloco ocorre dentro de um bloco ou uma lista de declarações de parâmetros formais em uma definição de função.  Só é visível do ponto de sua declaração ou definição até o final do bloco que contém sua declaração ou definição.  O escopo é limitado a esse bloco e a todos os blocos aninhados naquele bloco e termina na chave que fecha o bloco associado.  Esses identificadores às vezes são chamados de “variáveis locais”.  
  
 Escopo de protótipo de função  
 O declarador ou especificador de tipo de um identificador com escopo de protótipo de função ocorre na lista de declarações de parâmetro em um protótipo de função \(que não parte da declaração da função\).  O escopo termina no final do declarador da função.  
  
 As declarações apropriada para tornar as variáveis visíveis em outros arquivos de origem são descritas em [Classes de armazenamento](../c-language/c-storage-classes.md).  No entanto, as variáveis e as funções declaradas no nível externo com o especificador de classe de armazenamento **static** são visíveis apenas no arquivo de origem nas quais são definidas.  Todas as funções restantes são visíveis globalmente.  
  
## Consulte também  
 [Tempo de vida, escopo, visibilidade e ligação](../Topic/Lifetime,%20Scope,%20Visibility,%20and%20Linkage.md)