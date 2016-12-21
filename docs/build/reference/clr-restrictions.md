---
title: "/clr Restri&#231;&#245;es | Microsoft Docs"
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
  - "Opção de compilador /clr [C++], restrições"
ms.assetid: 385f6462-2c68-46d6-810e-469553ead447
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /clr Restri&#231;&#245;es
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Observe as seguintes limitações no uso de **\/clr**:  
  
-   Em um manipulador estruturado de exceção, há limitações no uso `_alloca` durante a criação com **\/clr**.  Para obter mais informações, consulte [\_alloca](../../c-runtime-library/reference/alloca.md).  
  
-   O uso de verificações de erro em tempo de execução não é válido com **\/clr**.  Para obter mais informações, consulte [Verificações de erro em tempo de execução](../Topic/How%20to:%20Use%20Native%20Run-Time%20Checks.md).  
  
-   Quando **\/clr** é usado para criar um programa que usa somente a sintaxe padrão do C\+\+, as diretrizes a seguir se aplicam ao uso do assembly embutida:  
  
    -   O código em linha do assembly que assume o conhecimento de layout nativo da pilha, chamando convenções da função atual, ou outras informações de baixo nível sobre o computador pode falhar se esse conhecimento é aplicado ao quadro de pilhas para uma função gerenciada.  As funções que contêm código embutida do assembly são geradas como funções não gerenciado, como se foram colocadas em um módulo separado que é compilado sem **\/clr**.  
  
    -   Embutido código do assembly em funções que os parâmetros cópia de passagem da função não têm suporte.  
  
-   [funções de vprintf](../../c-runtime-library/vprintf-functions.md) não pode ser chamado de um programa compilado com **\/clr**.  
  
-   O modificador de [despido](../Topic/naked%20\(C++\).md)[\_\_declspec](../../cpp/declspec.md) é ignorado em \/clr.  
  
-   O conjunto da função de tradutor por [\_set\_se\_translator](../../c-runtime-library/reference/set-se-translator.md) afetará apenas captura em código não gerenciado.  Consulte [Exception Handling](../../windows/exception-handling-cpp-component-extensions.md) para maiores informações.  
  
-   A comparação de ponteiros da função não é permitida em **\/clr**.  
  
-   O uso de funções que não são completamente protótipos não é permitido em **\/clr**.  
  
-   As seguintes opções do compilador não têm suporte em **\/clr**:  
  
    -   **\/EHsc** e **\/EHs** \(**\/clr** implica **\/EHa** \(consulte [\/EH \(modelo de tratamento de exceções\)](../../build/reference/eh-exception-handling-model.md)\)  
  
    -   **\/fp:strict** e **\/fp:except** \(consulte [\/fp \(especificar comportamento de ponto flutuante\)](../../build/reference/fp-specify-floating-point-behavior.md)\)  
  
    -   [\/Zd](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)  
  
    -   [\/Gm](../../build/reference/gm-enable-minimal-rebuild.md)  
  
    -   [\/MT](../../build/reference/md-mt-ld-use-run-time-library.md)  
  
    -   [\/RTC](../../build/reference/rtc-run-time-error-checks.md)  
  
    -   **\/ZI**  
  
-   A combinação da definição de pré\-processador de `_STATIC_CPPLIB` \(`/D_STATIC_CPPLIB`\) e a opção do compilador de **\/clr** ou de **\/clr:pure** não tem suporte.  Isso é bem como a definição faz com que o aplicativo vincular com a biblioteca multi\-threaded estático padrão do C\+\+, que não tem suporte.  Para obter mais informações, consulte o tópico [\/MD, \/MT, \/LD \(usar biblioteca em tempo de execução\)](../../build/reference/md-mt-ld-use-run-time-library.md).  
  
-   [\/J](../../build/reference/j-default-char-type-is-unsigned.md) não tem suporte com **\/clr:safe** ou **\/clr:pure**.  
  
-   As bibliotecas de ATL e de MFC não são suportadas pela compilação pura de modo**\/clr:pure**\(\).  Você pode usar **\/clr:pure** com a biblioteca padrão do C\+\+ e o CRT se você também cria com **\/MD** ou **\/MDd**.  
  
-   Ao usar **\/Zi** com **\/clr**, as implicações de desempenho.  Para obter mais informações, consulte [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md).  
  
-   Passe um caractere largo para uma rotina de saída do .NET Framework sem especificação [\/Zc: wchar\_t](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) ou sem converter a cadeia de caracteres a `__wchar_t` fará com que a saída aparecem como `unsigned short int`.  Por exemplo:  
  
    ```  
    Console::WriteLine(L' ')              // Will output 32.  
    Console::WriteLine((__wchar_t)L' ')   // Will output a space.  
    ```  
  
-   [\/GS](../Topic/-GS%20\(Buffer%20Security%20Check\).md) será ignorado durante a criação com **\/clr**, a menos que uma função está em `#pragma` [não gerenciado](../../preprocessor/managed-unmanaged.md) ou se a função deverá ser criada ao nativo, caso o compilador gerará C4793 de aviso, que é desativada por padrão.  
  
-   Consulte para [\/ENTRY](../../build/reference/entry-entry-point-symbol.md) requisitos de assinatura da função de um aplicativo gerenciado.  
  
-   Os aplicativos criados com **\/openmp** e **\/clr** só podem ser executados em um único processo de appdomain.  Consulte [\/openmp \(habilitar suporte a OpenMP 2.0\)](../../build/reference/openmp-enable-openmp-2-0-support.md) para maiores informações.  
  
-   As funções que usam um número variável de argumentos \(varargs\) serão geradas como funções nativos.  Todos os dados gerenciados na posição variável de marshaling argumento para tipos nativos.  Observe que os tipos de <xref:System.String?displayProperty=fullName> são realmente cadeias de caracteres de ampla marshaling de caracteres, mas em cadeias de caracteres de um byte.  Isso se um especificador de printf é wchar\_t\* \(%S\), marshaling para uma cadeia de caracteres de %s em vez disso.  
  
-   Ao usar a macro de va\_arg, você pode obter resultados inesperados ao criar com **\/clr:pure**.  Para obter mais informações, consulte [va\_arg, va\_copy, va\_end, va\_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md).  
  
-   Se seu aplicativo passa um argumento de tipo [va\_list](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) a uma função declarada para fazer [número variável de argumentos](../Topic/Variable%20Argument%20Lists.md), e seu aplicativo for compilado com **\/clr:pure**CLR, gerencie <xref:System.NotSupportedException>.  Se **\/clr**  é usado por outro lado, as funções afetadas são criadas em código nativo e sejam executadas corretamente.  Se **\/clr:safe** for usado, o diagnóstico de erro é emitido.  
  
-   Você não deve chamar, o código gerenciado, qualquer função que mostram a pilha para obter informações de parâmetro \(argumentos de função\); as causas da camada de P\/Invoke essas informações ser listados mais adicional a pilha.  Por exemplo, não crie o proxy\/stub com **\/clr**.  
  
-   As funções serão criadas ao código gerenciado construções sempre que possível, mas não todas as C\+\+ podem ser traduzidas para código gerenciado.  A determinação é feita em uma base de função\-por\- função.  Se qualquer parte de uma função não pode ser convertida no código gerenciado, a função inteira será convertida em código nativo em vez disso.  Os seguintes casos impedir que o compilador gerencia o código gerenciado.  
  
    -   Thunks completo gerados ou funções auxiliares.  Os thunks nativos são gerados para qualquer chamada de função por meio de um ponteiro de função, incluindo chamadas de função virtuais.  
  
    -   Funções que chamam `setjmp` ou `longjmp`.  
  
    -   Funções que usam determinadas rotinas intrínsecas para manipular diretamente recursos do computador.  Por exemplo, o uso de `__enable` e `__disable`, `_ReturnAddress` e `_AddressOfReturnAddress`, ou intrinsics de multimédios qualquer resultado em código nativo.  
  
    -   Funções que seguem a política de `#pragma unmanaged` . \(Observe que o inverso, `#pragma managed`, também há suporte.\)  
  
    -   Uma função que contém referências aos tipos alinhados, ou seja, digite declarado usando `__declspec(align(...))`.  
  
-   Você não pode usar as classes de [Suporte COM do compilador](../Topic/Compiler%20COM%20Support.md) com **\/clr:pure** ou **\/clr:safe**.  
  
## Consulte também  
 [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md)