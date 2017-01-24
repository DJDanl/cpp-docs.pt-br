---
title: "volatile (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "volatile_cpp"
  - "volatile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interromper manipuladores e palavra-chave volatile"
  - "objetos [C++], volatile"
  - "palavra-chave volatile [C++]"
  - "objetos voláteis"
ms.assetid: 81db4a85-ed5a-4a2c-9a53-5d07a771d2de
caps.latest.revision: 43
caps.handback.revision: 43
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# volatile (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um qualificador de tipo que você pode usar para declarar que um objeto pode ser modificado no programa pelo hardware.  
  
## Sintaxe  
  
```  
  
volatile declarator ;  
```  
  
## Comentários  
 Você pode usar o switch do compilador [\/volatile](../build/reference/volatile-volatile-keyword-interpretation.md) para modificar como o compilador interpreta essa palavra\-chave.  
  
 O Visual Studio interpreta a palavra\-chave `volatile` de modo diferente de acordo com a arquitetura de destino.  Para ARM, se nenhuma opção de compilador **\/volatile** for especificada, o compilador será executado como se **\/volatile:iso** tivesse sido especificado.  Para arquiteturas que não sejam ARM, se nenhuma opção de compilador **\/volatile** for especificada, o compilador será executado como se **\/volatile:ms** tivesse sido especificado. Portanto, para arquiteturas que não sejam ARM, é altamente recomendável especificar **\/volatile:iso** e usar primitivos de sincronização explícitos e intrínsecos do compilador ao gerenciar memória compartilhada entre threads.  
  
 Você pode usar o qualificador `volatile` para fornecer acesso aos locais de memória usados por processos assíncronos, como manipuladores de interrupção.  
  
 Quando `volatile` é usado em uma variável que também tem a palavra\-chave [\_\_restrict](../cpp/extension-restrict.md), `volatile` tem precedência.  
  
 Se um membro `struct` é marcado como `volatile`, `volatile` é propagado para a estrutura inteira.  Se uma estrutura não tem um tamanho que pode ser copiado na arquitetura atual usando uma instrução, `volatile` pode ser completamente perdido nessa estrutura.  
  
 A palavra\-chave `volatile` pode não ter nenhum efeito sobre um campo se uma das seguintes condições for verdadeira:  
  
-   O tamanho do campo volátil excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.  
  
-   O tamanho do contentor `struct` mais externo \(ou se for um membro de uma `struct` possivelmente aninhada\) excede o tamanho máximo que pode ser copiado para a arquitetura atual usando uma instrução.  
  
 Embora o processador não reorganize acessos de memória sem cache, as variáveis sem cache devem ser marcadas como `volatile` para garantir que o compilador não reorganize os acessos de memória.  
  
 Objetos que são declarados como `volatile` não são usados em determinadas otimizações porque seus valores podem ser alterados a qualquer momento.  O sistema sempre lê o valor atual de um objeto volátil quando solicitado, mesmo que uma instrução anterior tenha solicitado um valor do mesmo objeto.  Além disso, o valor do objeto é gravado imediatamente na atribuição.  
  
## Compatível com ISO  
 Se você estiver familiarizado com a palavra\-chave [C\# volatile](../Topic/volatile%20\(C%23%20Reference\).md) ou com o comportamento de `volatile` em versões anteriores do Visual C\+\+, lembre\-se de que a palavra\-chave `volatile` do C\+\+11 ISO padrão é diferente e tem suporte no Visual Studio quando a opção de compilador [\/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) é especificada. \(Para ARM, ela é especificada por padrão\).  A palavra\-chave `volatile` no código C\+\+11 ISO padrão deve ser usada somente para acesso de hardware. Não a use para comunicação entre threads.  Para comunicação entre threads, use mecanismos como [std::atomic\<T\>](../standard-library/atomic.md) da [Biblioteca de modelos C\+\+ padrão](../standard-library/cpp-standard-library-reference.md).  
  
## Fim de compatível com ISO  
  
## Específico da Microsoft  
 Quando a opção de compilador **\/volatile:ms** é usada \(por padrão quando as arquiteturas que não sejam ARM são segmentadas\), o compilador gera códigos adicionais para manter a ordem entre referências a objetos voláteis, além de manter a ordem para referências a outros objetos globais.  Em particular:  
  
-   Uma gravação em um objeto volátil \(também conhecida como gravação volátil\) tem semântica de versão; ou seja, uma referência a um objeto global ou estático que ocorre antes de uma gravação em um objeto volátil na sequência da instrução ocorrerá antes dessa gravação volátil no binário compilado.  
  
-   Uma leitura de um objeto volátil \(também conhecida como leitura volátil\) tem semântica de aquisição; ou seja, uma referência a um objeto global ou estático que ocorre depois de uma leitura de memória volátil na sequência da instrução ocorrerá depois dessa leitura volátil no binário compilado.  
  
 Isso permite que os objetos voláteis sejam usados para versões e bloqueios de memória em aplicativos multithread.  
  
> [!NOTE]
>  Quando depende da garantia aprimorada que é fornecida quando a opção de compilador **\/volatile:ms** é usada, o código é não portátil.  
  
## Fim de Específico da Microsoft  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [const](../cpp/const-cpp.md)   
 [Ponteiros const e voláteis](../Topic/const%20and%20volatile%20Pointers.md)