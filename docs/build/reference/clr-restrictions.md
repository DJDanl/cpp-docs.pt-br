---
title: /clr Restrições
ms.date: 11/04/2016
helpviewer_keywords:
- /clr compiler option [C++], restrictions
ms.assetid: 385f6462-2c68-46d6-810e-469553ead447
ms.openlocfilehash: d0318ce2e23f92600d5a78d6472646ec91492152
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837368"
---
# <a name="clr-restrictions"></a>/clr Restrições

Observe as seguintes restrições sobre o uso de **/clr**:

- Em um manipulador de exceção estruturado, há restrições sobre o uso de `_alloca` durante a compilação com **/clr**. Para obter mais informações, confira [_alloca](../../c-runtime-library/reference/alloca.md).

- O uso de verificações de erro em tempo de execução não é válido com **/clr**. Para obter mais informações, confira [Como: Usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks).

- Quando **/clr** é usado para compilar um programa que usa apenas a sintaxe C++ padrão, as seguintes diretrizes se aplicam ao uso do assembly embutido:

  - O código de assembly embutido que pressupõe conhecimento sobre o layout empilhado nativo, as convenções de chamada fora da função atual ou outras informações de nível inferior sobre o computador poderá falhar se esse conhecimento for aplicado ao registro de ativação de uma função gerenciada. As funções que contêm o código de assembly embutido são geradas como funções não gerenciadas, como se fossem colocadas em um módulo separado compilado sem **/clr**.

  - Não há suporte para o código de assembly embutido em funções que passam parâmetros de função construídos por cópia.

- As [Funções vprintf](../../c-runtime-library/vprintf-functions.md) não podem ser chamadas em um programa compilado com **/clr**.

- O modificador [naked](../../cpp/naked-cpp.md) [__declspec](../../cpp/declspec.md) é ignorado em /clr.

- A função de conversão definida por [_set_se_translator](../../c-runtime-library/reference/set-se-translator.md) afetará somente as capturas no código não gerenciado. Confira [Tratamento de exceção](../../extensions/exception-handling-cpp-component-extensions.md) para obter mais informações.

- A comparação de ponteiros de função não é permitida em **/clr**.

- O uso de funções que não são totalmente prototipadas não é permitido em **/clr**.

- Não há suporte para as seguintes opções do compilador com **/clr**:

  - **/EHsc** e **/EHs** [**/clr** implica **/EHa** – confira [/EH (modelo de tratamento de exceção)](eh-exception-handling-model.md)]

  - **/fp:strict** e **/fp:except** [confira [/fp (especificar comportamento de ponto flutuante)](fp-specify-floating-point-behavior.md)]

  - [/Zd](z7-zi-zi-debug-information-format.md)

  - [/Gm](gm-enable-minimal-rebuild.md)

  - [/MT](md-mt-ld-use-run-time-library.md)

  - [/RTC](rtc-run-time-error-checks.md)

  - [/ZI](z7-zi-zi-debug-information-format.md)

- Não há suporte para a combinação da definição de pré-processador `_STATIC_CPPLIB` (`/D_STATIC_CPPLIB`) e a opção do compilador **/clr**. Isso ocorre porque a definição faz com que o aplicativo seja vinculado à Biblioteca Padrão C++ estática multi-threaded, para a qual não há suporte. Para obter mais informações, confira o tópico [/MD, /MT, /LD (Usar biblioteca em tempo de execução)](md-mt-ld-use-run-time-library.md).

- Ao usar **/Zi** com **/clr**, há implicações de desempenho. Para obter mais informações, confira [/Zi](z7-zi-zi-debug-information-format.md).

- Passar um caractere largo para uma rotina de saída do .NET Framework sem especificar também [/Zc:wchar_t](zc-wchar-t-wchar-t-is-native-type.md) ou sem converter o caractere em `__wchar_t` fará com que a saída seja exibida como um `unsigned short int`. Por exemplo:

    ```cpp
    Console::WriteLine(L' ')              // Will output 32.
    Console::WriteLine((__wchar_t)L' ')   // Will output a space.
    ```

- [/GS](gs-buffer-security-check.md) será ignorado na compilação com **/clr**, a menos que uma função esteja sob o `#pragma` [unmanaged](../../preprocessor/managed-unmanaged.md) ou se a função precisar ser compilada para nativa, caso em que o compilador gerará o aviso C4793, que está desativado por padrão.

- Confira [/ENTRY](entry-entry-point-symbol.md) para obter os requisitos de assinatura de função de um aplicativo gerenciado.

- Os aplicativos compilados com **/openmp** e **/clr** só podem ser executados em um único processo do AppDomain.  Confira [/openmp (Habilitar o suporte ao OpenMP 2.0)](openmp-enable-openmp-2-0-support.md) para obter mais informações.

- As funções que usam um número variável de argumentos (varargs) serão geradas como funções nativas. Será realizado o marshaling dos tipos de dados gerenciados na posição de argumento variável para tipos nativos. Observe que os tipos <xref:System.String?displayProperty=fullName> são, na verdade, cadeias de caracteres largos, mas é realizado o marshaling deles para cadeias de caracteres de byte único. Portanto, se um especificador de printf for %S (wchar_t*), ele realizará marshaling para uma cadeia de caracteres %s.

- Ao usar a macro va_arg, você poderá obter resultados inesperados na compilação com **/clr:pure**. Para obter mais informações, confira [va_arg, va_copy, va_end, va_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md). As opções do compilador **/clr:pure** e **/clr:safe** foram preteridas no Visual Studio 2015 e estão sem suporte no Visual Studio 2017 e posterior. O código que precisa ser "puro" ou "seguro" deve ser portado para o C#.

- Você não deve chamar, no código gerenciado, as funções que se movimentam na pilha para obter informações de parâmetro (argumentos de função); a camada de P/Invoke faz com que essas informações estejam mais abaixo na pilha.  Por exemplo, não compile proxy/stub com **/clr**.

- As funções serão compiladas em código gerenciado sempre que possível, mas nem todos os constructos C++ podem ser convertidos em código gerenciado.  Essa determinação é feita por função. Se qualquer parte de uma função não puder ser convertida em código gerenciado, a função inteira será convertida em código nativo. Os casos a seguir impedem o compilador de gerar um código gerenciado.

  - Conversões geradas pelo compilador ou funções auxiliares. Conversões nativas são geradas para qualquer chamada de função por meio de um ponteiro de função, incluindo chamadas de função virtual.

  - Funções que chamam `setjmp` ou `longjmp`.

  - Funções que usam algumas rotinas intrínsecas para manipular diretamente os recursos do computador. Por exemplo, o uso de `__enable` e `__disable`, `_ReturnAddress` e `_AddressOfReturnAddress` ou todos os intrínsecos de multimídia resultarão em código nativo.

  - Funções que seguem a diretiva `#pragma unmanaged`. (Observe que também há suporte para o inverso, `#pragma managed`.)

  - Uma função que contém referências a tipos alinhados, ou seja, tipos declarados usando `__declspec(align(...))`.

## <a name="see-also"></a>Consulte também

- [/clr (compilação do Common Language Runtime)](clr-common-language-runtime-compilation.md)
