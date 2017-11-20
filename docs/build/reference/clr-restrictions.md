---
title: "-clr restrições | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: /clr compiler option [C++], restrictions
ms.assetid: 385f6462-2c68-46d6-810e-469553ead447
caps.latest.revision: "27"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: b5113abbf63fdb7ab87363e5344806d6eb34e0dd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="clr-restrictions"></a>/clr Restrições
Observe as seguintes restrições sobre o uso de **/clr**:  
  
-   Em um manipulador de exceção estruturada, há restrições ao uso de `_alloca` ao compilar com **/clr**. Para obter mais informações, consulte [alloca](../../c-runtime-library/reference/alloca.md).  
  
-   O uso de verificações de erro de tempo de execução não é válido com **/clr**. Para saber mais, confira [Como usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks).  
  
-   Quando **/clr** é usado para compilar um programa que usa apenas a sintaxe de C++ padrão, as diretrizes a seguir se aplicam ao uso de assembly embutido:  
  
    -   Código de assembly embutido que pressupõe conhecimento do layout da pilha nativa, convenções fora da função atual, ou outras informações de baixo nível sobre o computador de chamada poderá falhar se conhecimento aplicado ao quadro de pilha para uma função gerenciada. Funções contendo o código de assembly embutido são geradas como funções não gerenciadas, como se eles foram colocados em um módulo separado que foi compilado sem **/clr**.  
  
    -   Não há suporte para o código de assembly embutido em funções que passar parâmetros de função construído por cópia.  
  
-   O [funções vprintf](../../c-runtime-library/vprintf-functions.md) não pode ser chamado a partir de um programa compilado com **/clr**.  
  
-   O [naked](../../cpp/naked-cpp.md) [declspec](../../cpp/declspec.md) modificador é ignorado em /clr.  
  
-   A função de conversor definida [set_se_translator](../../c-runtime-library/reference/set-se-translator.md) afetará apenas compromete em código não gerenciado. Consulte [tratamento de exceção](../../windows/exception-handling-cpp-component-extensions.md) para obter mais informações.  
  
-   A comparação de ponteiros de função não é permitida em **/clr**.  
  
-   O uso de funções que não são totalmente prototipada não é permitido em **/clr**.  
  
-   Não há suporte para as seguintes opções de compilador com **/clr**:  
  
    -   **/ /EHsc** e **/EHs** (**/clr** implica **/EHa** (consulte [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md))  
  
    -   **/FP: strict** e **/fp: exceto** (consulte [/fp (Especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md))  
  
    -   [/Zd](../../build/reference/z7-zi-zi-debug-information-format.md)  
  
    -   [/GM manual](../../build/reference/gm-enable-minimal-rebuild.md)  
  
    -   [/MT](../../build/reference/md-mt-ld-use-run-time-library.md)  
  
    -   [/RTC](../../build/reference/rtc-run-time-error-checks.md)  
  
    -   **/ZI**  
  
-   A combinação da `_STATIC_CPPLIB` definição de pré-processador (`/D_STATIC_CPPLIB`) e o **/clr** ou **/clr: pure** não há suporte para a opção de compilador. Isso acontece porque a definição causaria o seu aplicativo vincular com estático multithread biblioteca padrão C++, que não é suportado. Para obter mais informações, consulte o [/MD, /MT, /LD (usar biblioteca de tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md) tópico.  
  
-   [/J](../../build/reference/j-default-char-type-is-unsigned.md) não é compatível com **/CLR: safe** ou **/clr: pure**. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
-   Não há suporte para as bibliotecas ATL e MFC pela compilação de modo puro (**/clr: pure**). Você pode usar **/clr: pure** com a biblioteca padrão C++ e CRT se você compilar também com **/MD** ou **/MDd**.  
  
-   Ao usar **/Zi** com **/clr**, há implicações de desempenho. Para obter mais informações, consulte [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md).  
  
-   Passando um caractere largo para um .NET Framework rotina de saída sem especificar [/ZC:](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) ou sem conversão de caractere para `__wchar_t` fará com que a saída seja exibido como um `unsigned short int`. Por exemplo:  
  
    ```  
    Console::WriteLine(L' ')              // Will output 32.  
    Console::WriteLine((__wchar_t)L' ')   // Will output a space.  
    ```  
  
-   [/GS](../../build/reference/gs-buffer-security-check.md) é ignorada durante a compilação com **/clr**, a menos que uma função é em `#pragma` [não gerenciado](../../preprocessor/managed-unmanaged.md) ou se a função deve ser compilada para nativo, caso em que o compilador Gere aviso C4793, que é desativado por padrão.  
  
-   Consulte [/ENTRY](../../build/reference/entry-entry-point-symbol.md) para requisitos de assinatura de função de um aplicativo gerenciado.  
  
-   Os aplicativos compilados com **/openmp** e **/clr** só pode ser executado em um processo único appdomain.  Consulte [/openmp (Habilitar suporte a OpenMP 2.0)](../../build/reference/openmp-enable-openmp-2-0-support.md) para obter mais informações.  
  
-   Funções que possuem um número variável de argumentos (varargs) serão geradas como funções nativas. Quaisquer tipos de dados gerenciado na posição de argumento variável serão possível realizar marshaling em tipos nativos. Observe que <xref:System.String?displayProperty=fullName> tipos são cadeias de caracteres largos, na verdade, mas eles são empacotados em cadeias de caracteres de byte único. Então se um especificador de printf é %S (wchar_t *), ele controlará a uma cadeia de caracteres %s em vez disso.  
  
-   Ao usar a macro va_arg, você pode obter resultados inesperados ao compilar com **/clr: pure**.  Para obter mais informações, consulte [va_arg, va_copy, va_end, va_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md).  
  
-   Se seu aplicativo passar um argumento de tipo [va_list](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) para uma função declarada tenham um número variável de argumentos, e seu aplicativo é compilado com **/clr: pure**, gera o CLR <xref:System.NotSupportedException>. Se **/clr** é usado em vez disso, as funções afetadas são compiladas para código nativo e executados corretamente. Se **/CLR: safe** é usado, um erro de diagnóstico é emitido.  
  
-   Não chame, de código gerenciado, todas as funções que orientam a pilha para obter informações de parâmetro (argumentos de função); a camada de P/Invoke faz com que essas informações para serem mais para baixo na pilha.  Por exemplo, não compilar o proxy/stub com **/clr**.  
  
-   Funções serão compiladas para código gerenciado sempre que possível, mas nem todas as construções de C++ que podem ser convertidas em código gerenciado.  Isso é feito em uma base de função pela função. Se qualquer parte de uma função não pode ser convertido em código gerenciado, a função inteira será convertida em código nativo em vez disso. Os casos a seguir impedem o compilador de geração de código gerenciado.  
  
    -   Conversões gerado pelo compilador ou funções auxiliares. Conversões nativo são gerados para qualquer chamada de função através de um ponteiro de função, incluindo as chamadas de função virtual.  
  
    -   Funções que chamam `setjmp` ou `longjmp`.  
  
    -   Funções que usam determinadas rotinas intrínsecas para manipular diretamente os recursos de máquina. Por exemplo, o uso de `__enable` e `__disable`, `_ReturnAddress` e `_AddressOfReturnAddress`, ou de multimídia intrínsecos serão todos os resultados em código nativo.  
  
    -   Funções que siga a `#pragma unmanaged` diretiva. (Observe que o inverso, `#pragma managed`, também têm suporte.)  
  
    -   Uma função que contém referências a alinhado tipos, ou seja, tipos declarados usando `__declspec(align(...))`.  
  
-   Não é possível usar o [suporte COM do compilador](../../cpp/compiler-com-support.md) classes com **/clr: pure** ou **/CLR: safe**.  
  
## <a name="see-also"></a>Consulte também  
 [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)