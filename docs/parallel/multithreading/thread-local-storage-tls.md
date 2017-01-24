---
title: "Armazenamento local de thread (TLS) | Microsoft Docs"
ms.custom: ""
ms.date: "12/09/2016"
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
  - "multithreading [C++], Armazenamento local de thread"
  - "armazenando dados específicos de thread"
  - "atributo de thread"
  - "Armazenamento Local de Thread [C++]"
  - "threading [C++], Armazenamento local de thread"
  - "TLS [C++]"
ms.assetid: 80801907-d792-45ca-b776-df0cf2e9f197
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Armazenamento local de thread (TLS)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Armazenamento Local da thread \(TLS\) é o método pelo qual cada thread em um determinado processo multithread pode alocar locais para armazenar dados específicos de segmento.  Dinamicamente os dados específicos de segmento de limite \(tempo de execução\) são suportados por meio da API de TLS \([TlsAlloc](assetId:///TlsAlloc?qualifyHint=False&autoUpgrade=True),  [TlsGetValue](assetId:///TlsGetValue?qualifyHint=False&autoUpgrade=True),  [TlsSetValue](assetId:///TlsSetValue?qualifyHint=False&autoUpgrade=True), e [TlsFree](assetId:///TlsFree?qualifyHint=False&autoUpgrade=True)\).  Para obter mais informações sobre como o armazenamento local de thread é implementado no Windows, consulte [armazenamento de Thread Local \(Windows\)](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686749\(v=vs.85\).aspx).  Win32 e o compilador do Visual C\+\+ agora oferecem suporte a dados associados estaticamente \(tempo de carregamento\) por thread além de implementação da API existente.  
  
##  <a name="_core_compiler_implementation_for_tls"></a> Implementação do compilador para TLS  
 **C \+ \+ 11:**  o `thread_local` especificador de classe de armazenamento é a maneira recomendada para especificar o armazenamento local de thread para objetos e membros de classe.  Para obter mais informações, consulte [classes de armazenamento \(C\+\+\)](../../cpp/storage-classes-cpp.md#thread_local).  
  
 O Visual C\+\+ também fornece um atributo específico da Microsoft,  [thread](../../cpp/thread.md), como modificador de classe de armazenamento estendido.  Use o `__declspec` palavra\-chave para declarar um **segmento** variável.  Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:  
  
```  
__declspec( thread ) int tls_i = 1;  
```  
  
## Regras e limitações  
 As diretrizes a seguir devem ser observadas quando declarar estaticamente vinculado variáveis e objetos locais de thread.  Essas diretrizes se aplicam tanto ao [thread](../../cpp/thread.md)e a maior parte também [thread\_local](../../cpp/storage-classes-cpp.md#thread_local):  
  
-   O `thread` atributo pode ser aplicado somente a definições e declarações de classe e de dados.  Ele não pode ser usado em declarações ou definições de função.  Por exemplo, o código a seguir gera um erro de compilador:  
  
    ```  
  
    __declspec( thread )void func();     // This will generate an error.  
    ```  
  
-   O `thread` modificador pode ser especificada somente em itens de dados com `static` extensão.  Isso inclui objetos de dados globais \(ambos `static` e `extern`\), objetos estáticos locais e membros de dados estáticos de classes C\+\+.  Objetos de dados automática não podem ser declarados com o `thread` atributo.  O código a seguir gera erros de compilador:  
  
    ```  
  
    void func1()  
    {  
        __declspec( thread )int tls_i;            // This will generate an error.  
    }  
  
    int func2(__declspec( thread )int tls_i )    // This will generate an error.  
    {  
        return tls_i;  
    }  
    ```  
  
-   As declarações e a definição de um thread de objeto local deve especificar o `thread` atributo.  Por exemplo, o código a seguir gera um erro:  
  
    ```  
    #define Thread  __declspec( thread )  
    extern int tls_i;        // This will generate an error, since the  
    int __declspec( thread )tls_i;        // declaration and definition differ.  
    ```  
  
-   O `thread` atributo não pode ser usado como um modificador de tipo.  Por exemplo, o código a seguir gera um erro de compilador:  
  
    ```  
    char __declspec( thread ) *ch;        // Error  
    ```  
  
-   Porque a declaração do C\+\+ objetos que usam o `thread` atributo é permitido, os dois exemplos a seguintes são semanticamente equivalentes:  
  
    ```  
  
    __declspec( thread ) class B  
    {  
    // Code  
    } BObject;  // OK--BObject is declared thread local.  
  
    class B  
    {  
    // Code  
    };  
    __declspec( thread ) B BObject;  // OK--BObject is declared thread local.  
    ```  
  
-   O endereço de um objeto de local de thread não é considerado constante, e qualquer expressão que envolva um endereço não é considerada uma expressão constante.  Em C padrão, o efeito disso é proibir o uso do endereço de uma variável local de thread como um inicializador de um objeto ou ponteiro.  Por exemplo, o código a seguir é sinalizado como um erro pelo compilador C:  
  
    ```  
  
    __declspec( thread )int tls_i;  
    int *p = &tls_i;       //This will generate an error in C.  
    ```  
  
     Essa restrição não se aplica em C\+\+.  Como C\+\+ permite para inicialização dinâmica de todos os objetos, você pode inicializar um objeto usando uma expressão que usa o endereço de uma variável local de thread.  Isso é feito como a construção de objetos locais de thread.  Por exemplo, o código mostrado anteriormente não gera um erro quando ele é compilado como um arquivo de origem C\+\+.  Observe que o endereço de uma variável local de thread é válido somente enquanto o thread no qual o endereço foi obtido ainda existe.  
  
-   C padrão permite a inicialização de um objeto ou variável com uma expressão que envolva uma referência a mesma, mas apenas para objetos de extensão não estática.  Embora o C\+\+ geralmente permita essa inicialização dinâmica de objetos com uma expressão que envolva uma referência a mesma, esse tipo de inicialização não é permitido com objetos locais de thread.  Por exemplo:  
  
    ```  
    __declspec( thread )int tls_i = tls_i;                // Error in C and C++   
    int j = j;                               // OK in C++, error in C  
    __declspec( thread )int tls_i = sizeof( tls_i )       // Legal in C and C++  
    ```  
  
     Observe que um `sizeof` expressão que inclua o objeto sendo inicializado não representa uma referência a mesma e é habilitado em C e C\+\+.  
  
     C\+\+ não permite essa inicialização dinâmica de dados de thread devido a possíveis aprimoramentos futuros para o recurso de armazenamento local de thread.  
  
-   Em sistemas operacionais do Windows antes de [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)], `__declspec`\(thread\) tem algumas limitações.  Se uma DLL declarar qualquer dado ou objeto como `__declspec`\(thread\), ele pode causar uma falha de proteção se carregado dinamicamente.  Depois que a DLL é carregada com [LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175), causar falha no sistema sempre que o código faz referência a `__declspec`dados \(thread\).  Como o espaço de variável global para um thread é alocado em tempo de execução, o tamanho desse espaço baseia\-se em um cálculo de requisitos do aplicativo mais os requisitos de todas as DLLs vinculadas estaticamente.  Quando você usa `LoadLibrary`, você não pode estender esse espaço para permitir que as variáveis locais de thread declaradas com `__declspec`\(thread\).  Use as APIs de TLS, como [TlsAlloc](http://msdn.microsoft.com/library/windows/desktop/ms686801), na DLL para alocar TLS se a DLL pode ser carregada com `LoadLibrary`.  
  
## Consulte também  
 [Multithread com C e Win32](../../parallel/multithreading-with-c-and-win32.md)   
 [Regras e limitações para TLS](../../misc/rules-and-limitations-for-tls.md)