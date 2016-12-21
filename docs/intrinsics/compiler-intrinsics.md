---
title: "Intr&#237;nsecos do compilador | Microsoft Docs"
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
helpviewer_keywords: 
  - "Compilador cl.exe, intrínsecos"
  - "Compilador cl.exe, desempenho"
  - "intrínsecos do compilador"
  - "intrínsecos, Compilador "
ms.assetid: 48bb9929-7d78-4fd8-a092-ae3c9f971858
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Intr&#237;nsecos do compilador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria das funções está contidas em bibliotecas, mas algumas funções são internas \(ou seja, intrínsecas\) para o compilador.  Elas são chamadas de funções intrínsecas ou intrínsecos.  
  
## Comentários  
 Se uma função for um intrínseco, o código para essa função será inserido geralmente embutido, evitando a sobrecarga de uma chamada de função e permitindo que instruções de máquina altamente eficientes sejam emitidas para a função.  Um intrínseco geralmente é mais rápido do que o assembly embutido equivalente, porque o otimizador tem conhecimento interno de quantos intrínsecos se comportam, algumas otimizações que podem estar disponíveis não estarão disponíveis quando o assembly embutido for usado.  Além disso, o otimizador pode expandir o intrínseco diferentemente, alinhar buffers de forma diferente ou fazer outros ajustes dependendo do contexto e dos argumentos da chamada.  
  
 O uso de intrínsecos afeta a portabilidade do código, pois os intrínsecos que estão disponíveis no Visual C\+\+ podem não estar disponíveis se o código for compilado com outros compiladores, e alguns intrínsecos que podem estar disponíveis para algumas arquiteturas de destino não estarão disponíveis para todas as arquiteturas.  No entanto, intrínsecos são geralmente mais portáteis do que o assembly embutido.  Os intrínsecos são necessários em arquiteturas de 64 bits em que não há suporte para assembly embutido.  
  
 Alguns intrínsecos como `__assume` e `__ReadWriteBarrier`, fornecem informações ao compilador, o que afeta o comportamento do otimizador.  
  
 Alguns intrínsecos estão disponíveis apenas como intrínsecos e outros estão disponíveis nas implementações de intrínsecos e função.  Você pode instruir o compilador para usar a implementação intrínseca em uma das duas maneiras, dependendo se quer habilitar apenas as funções específicas ou todos os intrínsecos.  A primeira maneira é usar `#pragma intrinsic(``intrinsic-function-name-list``)`.  O pragma pode ser usado para especificar um único intrínseco ou vários intrínsecos separados por vírgulas.  A segunda é usar a opção [\/Oi \(Gerar funções intrínsecas\)](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md) de compilador, que disponibiliza todos os intrínsecos em uma plataforma disponível.  Em **\/Oi**, use `#pragma function(``intrinsic-function-name-list``)` para forçar uma chamada de função a ser usada em vez de um intrínseco.  Se a documentação para determinado intrínseco nota que a rotina só está disponível como um intrínseco, a implementação intrínseca é usada independentemente da especificação do **\/Oi** ou `#pragma intrinsic` .  Em todos os casos, **\/Oi** or `#pragma intrinsic` permite, mas não força o otimizador usar o intrínseco.  O otimizador ainda pode chamar a função.  
  
 Algumas funções de biblioteca de C\/C\+\+ padrão estão disponíveis em implementações intrínsecas em algumas arquiteturas.  Ao chamar uma função CRT, a implementação intrínseca será usada se **\/Oi** for especificado na linha de comando.  
  
 Um arquivo de cabeçalho, \<intrin.h\> está disponível e declara protótipos para funções intrínsecas comuns.  Intrínsecos específicos de fabricante estão disponíveis nos arquivos de cabeçalho \<immintrin.h\> e \<ammintrin.h\>.  Além disso, determinados cabeçalhos Windows declaram funções que mapeiam para um compilador intrínseco.  
  
 As seções a seguir listam todos os intrínsecos que estão disponíveis em várias arquiteturas.  Para obter mais informações sobre como os intrínsecos funcionam no seu processador de destino específico, consulte a documentação de referência do fabricante.  
  
-   [Intrínsecos ARM](../intrinsics/arm-intrinsics.md)  
  
-   [Lista de intrínsecos x86](../Topic/x86%20Intrinsics%20List.md)  
  
-   [Lista de intrínsecos x64 \(amd64\)](../Topic/x64%20\(amd64\)%20Intrinsics%20List.md)  
  
-   [Intrínsecos disponíveis em todas as arquiteturas](../intrinsics/intrinsics-available-on-all-architectures.md)  
  
-   [Listagem alfabética de funções intrínsecas](../intrinsics/alphabetical-listing-of-intrinsic-functions.md)  
  
## Consulte também  
 [ARM Assembler Reference](../Topic/ARM%20Assembler%20Reference.md)   
 [Microsoft Macro Assembler Reference](../assembler/masm/microsoft-macro-assembler-reference.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md)