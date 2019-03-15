---
title: /clr Restrições
ms.date: 11/04/2016
helpviewer_keywords:
- /clr compiler option [C++], restrictions
ms.assetid: 385f6462-2c68-46d6-810e-469553ead447
ms.openlocfilehash: e2205740aea5a2e557b8d93c3c60045435c4b71d
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816094"
---
# <a name="clr-restrictions"></a>/clr Restrições

Observe as seguintes restrições sobre o uso de **/clr**:

- Em um manipulador de exceção estruturada, há restrições sobre como usar `_alloca` ao compilar com **/clr**. Para obter mais informações, consulte [alloca](../../c-runtime-library/reference/alloca.md).

- O uso de verificações de erro em tempo de execução não é válido com **/clr**. Para obter mais informações, confira [Como: Usar verificações de tempo de execução nativas](/visualstudio/debugger/how-to-use-native-run-time-checks).

- Quando **/clr** é usado para compilar um programa que usa somente a sintaxe de C++ padrão, as diretrizes a seguir se aplicam ao uso de assembly embutido:

  - Código de assembly embutido que pressupõe conhecimento sobre o layout de pilha nativo, convenções fora da função atual, ou outras informações de baixo nível sobre o computador de chamada poderá falhar se conhecimento aplicado ao quadro da pilha para uma função gerenciada. Funções contendo o código de assembly embutido são geradas como funções não gerenciadas, como se eles eram colocados em um módulo separado que foi compilado sem **/clr**.

  - Não há suporte para o código de assembly embutido em funções que passar parâmetros de função construído por cópia.

- O [funções vprintf](../../c-runtime-library/vprintf-functions.md) não pode ser chamado a partir de um programa compilado com **/clr**.

- O [naked](../../cpp/naked-cpp.md) [declspec](../../cpp/declspec.md) modificador é ignorado em /clr.

- A função conversora definido por [set_se_translator](../../c-runtime-library/reference/set-se-translator.md) afetará somente as armadilhas no código não gerenciado. Ver [Exception Handling](../../windows/exception-handling-cpp-component-extensions.md) para obter mais informações.

- A comparação de ponteiros de função não é permitida sob **/clr**.

- O uso de funções que não são totalmente prototipadas não é permitido sob **/clr**.

- Não há suporte para as opções do compilador com **/clr**:

  - **/ /EHsc** e **/EHs** (**/clr** implica **/EHa** (consulte [/EH (modelo de tratamento de exceção)](eh-exception-handling-model.md))

  - **/FP: strict** e **/fp: except** (consulte [/fp (Especificar comportamento de ponto flutuante)](fp-specify-floating-point-behavior.md))

  - [/Zd](z7-zi-zi-debug-information-format.md)

  - [/Gm](gm-enable-minimal-rebuild.md)

  - [/MT](md-mt-ld-use-run-time-library.md)

  - [/RTC](rtc-run-time-error-checks.md)

  - [/ZI](z7-zi-zi-debug-information-format.md)

- A combinação da `_STATIC_CPPLIB` definição de pré-processador (`/D_STATIC_CPPLIB`) e o **/clr** não há suporte para a opção de compilador. Isso ocorre porque a definição faria com que seu aplicativo vincular com estática multithread biblioteca padrão C++, que não é suportado. Para obter mais informações, consulte o [/MD, /MT, /LD (usar biblioteca em tempo de execução)](md-mt-ld-use-run-time-library.md) tópico.

- Ao usar **/Zi** com **/clr**, há implicações de desempenho. Para obter mais informações, consulte [/Zi](z7-zi-zi-debug-information-format.md).

- Passando um caractere largo para um .NET Framework de rotina de saída sem especificar também [/ZC: wchar_t](zc-wchar-t-wchar-t-is-native-type.md) ou sem converter o caractere a ser `__wchar_t` fará com que a saída seja exibido como um `unsigned short int`. Por exemplo:

    ```cpp
    Console::WriteLine(L' ')              // Will output 32.
    Console::WriteLine((__wchar_t)L' ')   // Will output a space.
    ```

- [/GS](gs-buffer-security-check.md) será ignorado ao compilar com **/clr**, a menos que uma função está sob `#pragma` [não gerenciado](../../preprocessor/managed-unmanaged.md) ou se a função deve ser compilada para nativo, caso em que o compilador irá gerar Aviso C4793, que é desativada por padrão.

- Ver [/ENTRY](entry-entry-point-symbol.md) para requisitos de assinatura de função de um aplicativo gerenciado.

- Aplicativos compilados com **/openmp** e **/clr** só pode ser executado em um processo único appdomain.  Ver [/openmp (Habilitar suporte a OpenMP 2.0)](openmp-enable-openmp-2-0-support.md) para obter mais informações.

- Funções que usam um número variável de argumentos (varargs) serão geradas como funções nativas. Quaisquer tipos de dados gerenciado na posição de argumento variável serão empacotados em tipos nativos. Observe que <xref:System.String?displayProperty=fullName> tipos são, na verdade, cadeias de caracteres largos, mas eles são empacotados para cadeias de caracteres de byte único. Portanto, se um especificador de printf é %S (wchar_t *), ele realizará marshaling para uma cadeia de caracteres %s em vez disso.

- Ao usar a macro va_arg, você poderá obter resultados inesperados ao compilar com **/clr: pure**. Para obter mais informações, consulte [va_arg, va_copy, va_end, va_start](../../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md). O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017. Código que deve ser "pura" ou "segura" deve ser movido para C#.

- Você deve chamar, no código gerenciado, todas as funções que movimentar a pilha para obter informações de parâmetro (argumentos de função); a camada de P/Invoke faz com que essas informações para serem mais para baixo da pilha.  Por exemplo, não são compilados proxy/stub com **/clr**.

- Funções serão compiladas para código gerenciado sempre que possível, mas nem todas as construções de C++ podem ser traduzidas para código gerenciado.  Essa determinação é feita em uma base de função por função. Se qualquer parte de uma função não pode ser convertido em código gerenciado, a função inteira será convertida em código nativo em vez disso. Os casos a seguir impedem o compilador de geração de código gerenciado.

  - Conversões gerado pelo compilador ou funções auxiliares. Conversões nativas são geradas para qualquer chamada de função por meio de um ponteiro de função, incluindo as chamadas de função virtual.

  - Funções que chamam `setjmp` ou `longjmp`.

  - Funções que usam determinadas rotinas intrínseco para manipular diretamente os recursos de máquina. Por exemplo, o uso de `__enable` e `__disable`, `_ReturnAddress` e `_AddressOfReturnAddress`, ou de multimídia intrínsecos serão todos os resultados em código nativo.

  - Funções que seguem o `#pragma unmanaged` diretiva. (Observe que o inverso, `#pragma managed`, também tem suporte.)

  - Uma função que contém referências a alinhado tipos, ou seja, tipos declarados usando `__declspec(align(...))`.

## <a name="see-also"></a>Consulte também

- [/clr (compilação do Common Language Runtime)](clr-common-language-runtime-compilation.md)
