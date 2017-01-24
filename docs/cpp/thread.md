---
title: "thread | Microsoft Docs"
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
  - "thread"
  - "thread_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], thread"
  - "palavra-chave thread __declspec"
  - "armazenamento local de threads (TLS)"
  - "TLS (armazenamento local de threads), implementação de compilador"
ms.assetid: 667f2a77-6d1f-4b41-bee8-05e67324fab8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# thread
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 O modificador de classe de armazenamento estendido **thread** é usado para declarar uma variável local de thread.  Para portáteis equivalente no C\+\+ 11, use o [thread\_local](../cpp/storage-classes-cpp.md#thread_local) especificador de classe de armazenamento.  
  
## Sintaxe  
  
```  
  
__declspec( thread ) declarator  
```  
  
## Comentários  
 O TLS \(armazenamento local de threads\) é o mecanismo pelo qual cada thread em um processo multithread aloca armazenamento para dados específicos ao thread.  Em programas multithread padrão, os dados são compartilhados entre todos os threads de um processo específico, enquanto o armazenamento local de threads é o mecanismo para alocar dados por thread.  Para ver uma discussão completa, consulte o tópico sobre [multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).  
  
 As declarações de variáveis locais de thread devem usar a [sintaxe de atributo estendido](../cpp/declspec.md) e a palavra\-chave `__declspec` com a palavra\-chave **thread**.  Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:  
  
```  
__declspec( thread ) int tls_i = 1;  
```  
  
 Você deve observar estas diretrizes ao declarar objetos e variáveis locais de thread:  
  
-   Você pode aplicar o **segmento** atributo apenas a classe e declarações de dados e as definições. **segmento** não pode ser usado em declarações de função ou definições.  
  
-   O uso do atributo **thread** pode interferir no [carregamento com atraso](../build/reference/linker-support-for-delay-loaded-dlls.md) de importações de DLL**.**  
  
-   Em sistemas XP, `thread` podem não funcionar corretamente se uma DLL usa dados \_\_declspec\(thread\) e ele é carregado dinamicamente por LoadLibrary.  
  
-   Você só pode especificar o atributo **thread** em itens de dados com duração de armazenamento estática.  Isso inclui objetos de dados globais \(**static** e `extern`\), objetos estáticos locais e membros de dados estáticos de classes.  Você não pode declarar objetos de dados automáticos com o atributo **thread**.  
  
-   Você deve usar o atributo **thread** para a declaração e a definição de um objeto local de thread, quer a declaração e a definição ocorram no mesmo arquivo ou em arquivos separados.  
  
-   Você não pode usar o atributo **thread** como um modificador de tipo.  
  
-   Como a declaração de objetos que usam o atributo **thread** é permitida, estes dois exemplos são semanticamente equivalentes:  
  
    ```  
    // declspec_thread_2.cpp  
    // compile with: /LD  
    __declspec( thread ) class B {  
    public:  
       int data;  
    } BObject;   // BObject declared thread local.  
  
    class B2 {  
    public:  
       int data;  
    };  
    __declspec( thread ) B2 BObject2;   // BObject2 declared thread local.  
    ```  
  
-   O C padrão permite a inicialização de um objeto ou uma variável com uma expressão que envolva uma referência a si mesma, mas apenas para objetos de extensão não estática.  Embora normalmente o C\+\+ permita essa inicialização dinâmica de um objeto com uma expressão que envolva uma referência a si mesma, esse tipo de inicialização não é permitido com objetos locais de thread.  Por exemplo:  
  
    ```  
    // declspec_thread_3.cpp  
    // compile with: /LD  
    #define Thread __declspec( thread )  
    int j = j;   // Okay in C++; C error  
    Thread int tls_i = sizeof( tls_i );   // Okay in C and C++  
    ```  
  
     Observe que uma expressão `sizeof` que inclua o objeto que está sendo inicializado não constitui uma referência a si mesma e é permitida no C e no C\+\+.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Armazenamento local de thread \(TLS\)](../parallel/thread-local-storage-tls.md)