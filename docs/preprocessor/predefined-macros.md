---
title: Macros predefinidas
description: Lista e descreve as macros de pré-processador predefinidas do compilador do Microsoft C++.
ms.custom: update_every_version
ms.date: 09/11/2020
f1_keywords:
- _ATL_VER
- __ATOM__
- __AVX__
- __AVX2__
- __AVX512BW__
- __AVX512CD__
- __AVX512DQ__
- __AVX512F__
- __AVX512VL__
- _CHAR_UNSIGNED
- __CLR_VER
- _CONTROL_FLOW_GUARD
- __COUNTER__
- __cplusplus
- __cplusplus_cli
- __cplusplus_winrt
- _CPPRTTI
- _CPPUNWIND
- __DATE__
- _DEBUG
- _DLL
- __FILE__
- __FUNCDNAME__
- __FUNCSIG__
- __FUNCTION__
- _INTEGRAL_MAX_BITS
- _ISO_VOLATILE
- _KERNEL_MODE
- __LINE__
- _M_AMD64
- _M_ARM
- _M_ARM_ARMV7VE
- _M_ARM_FP
- _M_ARM64
- _M_CEE
- _M_CEE_PURE
- _M_CEE_SAFE
- _M_FP_EXCEPT
- _M_FP_FAST
- _M_FP_PRECISE
- _M_FP_STRICT
- _M_IX86
- _M_IX86_FP
- _M_X64
- _MANAGED
- _MFC_VER
- _MSC_BUILD
- _MSC_EXTENSIONS
- _MSC_FULL_VER
- _MSC_VER
- _MSVC_LANG
- __MSVC_RUNTIME_CHECKS
- _MT
- _NATIVE_WCHAR_T_DEFINED
- _NO_SIZED_DEALLOCATION
- _OPENMP
- _PREFAST_
- _RESUMABLE_FUNCTIONS_SUPPORTED
- _RTC_CONVERSION_CHECKS_ENABLED
- __STDC__
- __STDC_HOSTED__
- __STDC_NO_ATOMICS__
- __STDC_NO_COMPLEX__
- __STDC_NO_THREADS__
- __STDC_NO_VLA__
- __STDC_VERSION__
- __STDCPP_THREADS__
- __TIME__
- __TIMESTAMP__
- __VA_ARGS__
- _VC_NODEFAULTLIB
- _WCHAR_T_DEFINED
- _WIN32
- _WIN64
- _WINRT_DLL
helpviewer_keywords:
- timestamps, preprocessor macro
- cl.exe compiler, version number
- version numbers, C/C++ compiler (cl.exe)
- macros, predefined C++
- preprocessor, macros
- predefined macros
- _ATL_VER macro
- __ATOM__ macro
- __AVX__ macro
- __AVX2__ macro
- __AVX512BW__ macro
- __AVX512CD__ macro
- __AVX512DQ__ macro
- __AVX512F__ macro
- __AVX512VL__ macro
- _CHAR_UNSIGNED macro
- __CLR_VER macro
- _CONTROL_FLOW_GUARD macro
- __COUNTER__ macro
- __cplusplus macro
- __cplusplus_cli macro
- __cplusplus_winrt macro
- _CPPRTTI macro
- _CPPUNWIND macro
- __DATE__ macro
- _DEBUG macro
- _DLL macro
- __FILE__ macro
- __FUNCDNAME__ macro
- __FUNCSIG__ macro
- __FUNCTION__ macro
- _INTEGRAL_MAX_BITS macro
- _ISO_VOLATILE macro
- _KERNEL_MODE macro
- __LINE__ macro
- _M_AMD64 macro
- _M_ARM macro
- _M_ARM_ARMV7VE macro
- _M_ARM_FP macro
- _M_ARM64 macro
- _M_CEE macro
- _M_CEE_PURE macro
- _M_CEE_SAFE macro
- _M_FP_EXCEPT macro
- _M_FP_FAST macro
- _M_FP_PRECISE macro
- _M_FP_STRICT macro
- _M_IX86 macro
- _M_IX86_FP macro
- _M_X64 macro
- _MANAGED macro
- _MFC_VER macro
- _MSC_BUILD macro
- _MSC_EXTENSIONS macro
- _MSC_FULL_VER macro
- _MSC_VER macro
- _MSVC_LANG macro
- __MSVC_RUNTIME_CHECKS macro
- _MT macro
- _NATIVE_WCHAR_T_DEFINED macro
- _NO_SIZED_DEALLOCATION macro
- _OPENMP macro
- _PREFAST_ macro
- _RESUMABLE_FUNCTIONS_SUPPORTED macro
- _RTC_CONVERSION_CHECKS_ENABLED macro
- __STDC__ macro
- __STDC_HOSTED__ macro
- __STDC_NO_ATOMICS__ macro
- __STDC_NO_COMPLEX__ macro
- __STDC_NO_THREADS__ macro
- __STDC_NO_VLA__ macro
- __STDC_VERSION__ macro
- __STDCPP_THREADS__ macro
- __TIME__ macro
- __TIMESTAMP__ macro
- __VA_ARGS__ macro
- _VC_NODEFAULTLIB macro
- _WCHAR_T_DEFINED macro
- _WIN32 macro
- _WIN64 macro
- _WINRT_DLL macro
- __func__ identifier
ms.assetid: 1cc5f70a-a225-469c-aed0-fe766238e23f
no-loc:
- _ATL_VER
- __ATOM__
- __AVX__
- __AVX2__
- __AVX512BW__
- __AVX512CD__
- __AVX512DQ__
- __AVX512F__
- __AVX512VL__
- _CHAR_UNSIGNED
- __CLR_VER
- _CONTROL_FLOW_GUARD
- __COUNTER__
- __cplusplus
- __cplusplus_cli
- __cplusplus_winrt
- _CPPRTTI
- _CPPUNWIND
- __DATE__
- _DEBUG
- _DLL
- __FILE__
- __FUNCDNAME__
- __FUNCSIG__
- __FUNCTION__
- _INTEGRAL_MAX_BITS
- _ISO_VOLATILE
- _KERNEL_MODE
- __LINE__
- _M_AMD64
- _M_ARM
- _M_ARM_ARMV7VE
- _M_ARM_FP
- _M_ARM64
- _M_CEE
- _M_CEE_PURE
- _M_CEE_SAFE
- _M_FP_EXCEPT
- _M_FP_FAST
- _M_FP_PRECISE
- _M_FP_STRICT
- _M_IX86
- _M_IX86_FP
- _M_X64
- _MANAGED
- _MFC_VER
- _MSC_BUILD
- _MSC_EXTENSIONS
- _MSC_FULL_VER
- _MSC_VER
- _MSVC_LANG
- __MSVC_RUNTIME_CHECKS
- _MT
- _NATIVE_WCHAR_T_DEFINED
- _NO_SIZED_DEALLOCATION
- _OPENMP
- _PREFAST_
- _RESUMABLE_FUNCTIONS_SUPPORTED
- _RTC_CONVERSION_CHECKS_ENABLED
- __STDC__
- __STDC_HOSTED__
- __STDC_NO_ATOMICS__
- __STDC_NO_COMPLEX__
- __STDC_NO_THREADS__
- __STDC_NO_VLA__
- __STDC_VERSION__
- __STDCPP_THREADS__
- __TIME__
- __TIMESTAMP__
- __VA_ARGS__
- _VC_NODEFAULTLIB
- _WCHAR_T_DEFINED
- _WIN32
- _WIN64
- _WINRT_DLL
- __func__
ms.openlocfilehash: b5e2b34357456c4937d8ed17dee5661d36b7b0c0
ms.sourcegitcommit: 25f6d52eb9e5d84bd0218c46372db85572af81da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2020
ms.locfileid: "94448456"
---
# <a name="predefined-macros"></a>Macros predefinidas

O compilador do Microsoft C/C++ (MSVC) predefine determinadas macros de pré-processador, dependendo do idioma (C ou C++), do destino de compilação e das opções de compilador escolhidas.

O MSVC dá suporte às macros predefinidas de pré-processador exigidas pelos padrões ANSI/ISO C99, C11 e C17 e os padrões ISO C++ 14 e C++ 17. A implementação também dá suporte a várias macros de pré-processador específicas da Microsoft. Algumas macros são definidas somente para ambientes de compilação específicos ou opções de compilador. Exceto quando indicado, as macros são definidas em uma unidade de tradução como se fossem especificadas como **`/D`** argumentos de opção do compilador. Quando definido, as macros são expandidas para os valores especificados pelo pré-processador antes da compilação. As macros predefinidas não usam argumentos e não podem ser redefinidas.

## <a name="standard-predefined-identifier"></a>Identificador padrão predefinido

O compilador oferece suporte a esse identificador predefinido especificado por ISO C99 e ISO C++ 11.

- `__func__` O nome não qualificado e não adornado da função de circunscrição como uma matriz **const estática** local de função de **`char`** .

    ```cpp
    void example(){
        printf("%s\n", __func__);
    } // prints "example"
    ```

## <a name="standard-predefined-macros"></a>Macros padrão predefinidas

O compilador oferece suporte a essas macros predefinidas especificadas pelos padrões ISO C99, C11, C17 e ISO C++ 17.

- `__cplusplus` Definido como um valor literal inteiro quando a unidade de tradução é compilada como C++. Caso contrário, indefinido.

- `__DATE__` A data de compilação do arquivo de origem atual. A data é um literal de cadeia de caracteres de tamanho constante da forma *Mmm dd aaaa*. O nome do mês *Mmm* é o mesmo que o nome do mês abreviado gerado pela função [asctime](../c-runtime-library/reference/asctime-wasctime.md) da biblioteca de tempo de execução do C (CRT). O primeiro caractere de data *DD* será um espaço se o valor for menor que 10. Essa macro sempre é definida.

- `__FILE__` O nome do arquivo de origem atual. `__FILE__` expande para um literal de cadeia de caracteres. Para garantir que o caminho completo para o arquivo seja exibido, use [ **`/FC`** (caminho completo do arquivo de código-fonte no diagnóstico)](../build/reference/fc-full-path-of-source-code-file-in-diagnostics.md). Essa macro sempre é definida.

- `__LINE__` Definido como o número de linha inteiro no arquivo de origem atual. O valor da `__LINE__` macro pode ser alterado usando uma `#line` diretiva. Essa macro sempre é definida.

- `__STDC__` Definido como 1 somente quando compilado como C e se a [`/Za`](../build/reference/za-ze-disable-language-extensions.md) opção do compilador for especificada. Caso contrário, indefinido.

- `__STDC_HOSTED__` Definido como 1 se a implementação for uma *implementação hospedada* , uma que dá suporte a toda a biblioteca padrão necessária. Caso contrário, definido como 0.

- `__STDC_NO_ATOMICS__` Definido como 1 se a implementação não dá suporte a Atomics padrão opcionais. A implementação MSVC define como 1 Quando compilada como C e uma das [`/std`](../build/reference/std-specify-language-standard-version.md) Opções C11 ou C17 é especificada.

- `__STDC_NO_COMPLEX__` Definido como 1 se a implementação não dá suporte a números complexos padrão opcionais. A implementação MSVC define como 1 Quando compilada como C e uma das [`/std`](../build/reference/std-specify-language-standard-version.md) Opções C11 ou C17 é especificada.

- `__STDC_NO_THREADS__` Definido como 1 se a implementação não dá suporte a threads padrão opcionais. A implementação MSVC define como 1 Quando compilada como C e uma das [`/std`](../build/reference/std-specify-language-standard-version.md) Opções C11 ou C17 é especificada.

- `__STDC_NO_VLA__` Definido como 1 se a implementação não oferece suporte a matrizes de comprimento variável padrão. A implementação MSVC define como 1 Quando compilada como C e uma das [`/std`](../build/reference/std-specify-language-standard-version.md) Opções C11 ou C17 é especificada.

- `__STDC_VERSION__` Definido quando compilado como C e uma das **`/std`** Opções C11 ou C17 é especificado. Ele se expande para `201112L` para [`/std:c11`](../build/reference/std-specify-language-standard-version.md) e `201710L` para o [`/std:c17`](../build/reference/std-specify-language-standard-version.md) .

- `__STDCPP_THREADS__` Definido como 1 se e somente se um programa puder ter mais de um thread de execução e compilado como C++. Caso contrário, indefinido.

- `__TIME__` A hora da tradução da unidade de tradução pré-processado. O tempo é um literal de cadeia de caracteres no formato *hh: mm: SS* , o mesmo que o tempo retornado pela função [asctime](../c-runtime-library/reference/asctime-wasctime.md) do CRT. Essa macro sempre é definida.

## <a name="microsoft-specific-predefined-macros"></a>Macros predefinidas específicas da Microsoft

O MSVC dá suporte a essas macros predefinidas adicionais.

- `__ATOM__` Definido como 1 quando a [`/favor:ATOM`](../build/reference/favor-optimize-for-architecture-specifics.md) opção do compilador é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `__AVX__` Definido como 1 quando as [`/arch:AVX`](../build/reference/arch-x86.md) [`/arch:AVX2`](../build/reference/arch-x86.md) Opções,, ou [`/arch:AVX512`](../build/reference/arch-x86.md) do compilador são definidas e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `__AVX2__` Definido como 1 quando a [`/arch:AVX2`](../build/reference/arch-x86.md) opção ou do [`/arch:AVX512`](../build/reference/arch-x86.md) compilador é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `__AVX512BW__` Definido como 1 quando a [`/arch:AVX512`](../build/reference/arch-x86.md) opção do compilador é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `__AVX512CD__` Definido como 1 quando a [`/arch:AVX512`](../build/reference/arch-x86.md) opção do compilador é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `__AVX512DQ__` Definido como 1 quando a [`/arch:AVX512`](../build/reference/arch-x86.md) opção do compilador é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `__AVX512F__` Definido como 1 quando a [`/arch:AVX512`](../build/reference/arch-x86.md) opção do compilador é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `__AVX512VL__` Definido como 1 quando a [`/arch:AVX512`](../build/reference/arch-x86.md) opção do compilador é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- `_CHAR_UNSIGNED` Definido como 1 se o **`char`** tipo padrão não for assinado. Esse valor é definido quando a opção de compilador [ **`/J`** (tipo de caractere padrão não assinado)](../build/reference/j-default-char-type-is-unsigned.md) é definida. Caso contrário, indefinido.

- `__CLR_VER` Definido como um literal inteiro que representa a versão do CLR (Common Language Runtime) usado para compilar o aplicativo. O valor é codificado no formulário `Mmmbbbbb` , em que `M` é a versão principal do tempo de execução, `mm` é a versão secundária do tempo de execução e `bbbbb` é o número da compilação. `__CLR_VER` será definido se a [`/clr`](../build/reference/clr-common-language-runtime-compilation.md) opção do compilador estiver definida. Caso contrário, indefinido.

    ```cpp
    // clr_ver.cpp
    // compile with: /clr
    using namespace System;
    int main() {
       Console::WriteLine(__CLR_VER);
    }
    ```

- `_CONTROL_FLOW_GUARD`Definido como 1 quando a opção de compilador [ **`/guard:cf`** (habilitar a proteção de fluxo de controle)](../build/reference/guard-enable-control-flow-guard.md) está definida. Caso contrário, indefinido.

- `__COUNTER__` Expande para um literal inteiro que começa em 0. O valor é incrementado em 1 cada vez que é usado em um arquivo de origem ou em cabeçalhos incluídos do arquivo de origem. `__COUNTER__` lembra seu estado quando você usa cabeçalhos pré-compilados. Essa macro sempre é definida.

  Este exemplo usa `__COUNTER__` para atribuir identificadores exclusivos a três objetos diferentes do mesmo tipo. O `exampleClass` construtor usa um inteiro como um parâmetro. No `main` , o aplicativo declara três objetos do tipo `exampleClass` , usando `__COUNTER__` como o parâmetro de identificador exclusivo:

    ```cpp
    // macro__COUNTER__.cpp
    // Demonstration of __COUNTER__, assigns unique identifiers to
    // different objects of the same type.
    // Compile by using: cl /EHsc /W4 macro__COUNTER__.cpp
    #include <stdio.h>

    class exampleClass {
        int m_nID;
    public:
        // initialize object with a read-only unique ID
        exampleClass(int nID) : m_nID(nID) {}
        int GetID(void) { return m_nID; }
    };

    int main()
    {
        // __COUNTER__ is initially defined as 0
        exampleClass e1(__COUNTER__);

        // On the second reference, __COUNTER__ is now defined as 1
        exampleClass e2(__COUNTER__);

        // __COUNTER__ is now defined as 2
        exampleClass e3(__COUNTER__);

        printf("e1 ID: %i\n", e1.GetID());
        printf("e2 ID: %i\n", e2.GetID());
        printf("e3 ID: %i\n", e3.GetID());

        // Output
        // ------------------------------
        // e1 ID: 0
        // e2 ID: 1
        // e3 ID: 2

        return 0;
    }
    ```

- `__cplusplus_cli` Definido como o valor inteiro literal 200406 quando compilado como C++ e uma [`/clr`](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador é definida. Caso contrário, indefinido. Quando definido, `__cplusplus_cli` está em vigor em toda a unidade de tradução.

    ```cpp
    // cplusplus_cli.cpp
    // compile by using /clr
    #include "stdio.h"
    int main() {
       #ifdef __cplusplus_cli
          printf("%d\n", __cplusplus_cli);
       #else
          printf("not defined\n");
       #endif
    }
    ```

- `__cplusplus_winrt`Definido como o valor inteiro literal 201009 quando compilado como C++ e a opção de compilador [ **`/ZW`** (compilação de Windows Runtime)](../build/reference/zw-windows-runtime-compilation.md) é definida. Caso contrário, indefinido.

- `_CPPRTTI`Definido como 1 se a opção de compilador [ **`/GR`** (habilitar informações de tipo de Run-Time)](../build/reference/gr-enable-run-time-type-information.md) estiver definida. Caso contrário, indefinido.

- `_CPPUNWIND`Definido como 1 se uma ou mais das opções de compilador [ **`/GX`** (habilitar manipulação de exceção)](../build/reference/gx-enable-exception-handling.md), [ **`/clr`** (compilação em tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md)ou [ **`/EH`** (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md) estão definidas. Caso contrário, indefinido.

- `_DEBUG` Definido como 1 quando a [`/LDd`](../build/reference/md-mt-ld-use-run-time-library.md) [`/MDd`](../build/reference/md-mt-ld-use-run-time-library.md) opção do compilador, ou [`/MTd`](../build/reference/md-mt-ld-use-run-time-library.md) é definida. Caso contrário, indefinido.

- `_DLL` Definido como 1 quando a [`/MD`](../build/reference/md-mt-ld-use-run-time-library.md) [`/MDd`](../build/reference/md-mt-ld-use-run-time-library.md) opção de compilador ou (DLL de vários threads) está definida. Caso contrário, indefinido.

- `__FUNCDNAME__` Definido como um literal de cadeia de caracteres que contém o [nome decorado](../build/reference/decorated-names.md) da função de circunscrição. A macro é definida somente dentro de uma função. A `__FUNCDNAME__` macro não será expandida se você usar a [`/EP`](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) [`/P`](../build/reference/p-preprocess-to-a-file.md) opção de compilador ou.

   Este exemplo usa as `__FUNCDNAME__` `__FUNCSIG__` `__FUNCTION__` macros, e para exibir informações de função.

   [!code-cpp[NVC_Predefined_Macros_Examples#1](../preprocessor/codesnippet/CPP/predefined-macros_1.cpp)]

- `__FUNCSIG__` Definido como um literal de cadeia de caracteres que contém a assinatura da função de circunscrição. A macro é definida somente dentro de uma função. A `__FUNCSIG__` macro não será expandida se você usar a [`/EP`](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) [`/P`](../build/reference/p-preprocess-to-a-file.md) opção de compilador ou. Quando compilado para um destino de 64 bits, a Convenção de chamada é **`__cdecl`** por padrão. Para obter um exemplo de uso, consulte a `__FUNCDNAME__` macro.

- `__FUNCTION__` Definido como um literal de cadeia de caracteres que contém o nome não decorado da função de circunscrição. A macro é definida somente dentro de uma função. A `__FUNCTION__` macro não será expandida se você usar a [`/EP`](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) [`/P`](../build/reference/p-preprocess-to-a-file.md) opção de compilador ou. Para obter um exemplo de uso, consulte a `__FUNCDNAME__` macro.

- `_INTEGRAL_MAX_BITS` Definido como o valor inteiro literal 64, o tamanho máximo (em bits) para um tipo não vetorial integral. Essa macro sempre é definida.

   ```cpp
   // integral_max_bits.cpp
   #include <stdio.h>
   int main() {
      printf("%d\n", _INTEGRAL_MAX_BITS);
   }
   ```

- `__INTELLISENSE__` Definido como 1 durante uma passagem do compilador do IntelliSense no IDE do Visual Studio. Caso contrário, indefinido. Você pode usar essa macro para proteger o código que o compilador do IntelliSense não entende ou usá-lo para alternar entre o compilador Build e o IntelliSense. Para obter mais informações, consulte [dicas de solução de problemas para o IntelliSense lentidão](https://devblogs.microsoft.com/cppblog/troubleshooting-tips-for-intellisense-slowness/).

- `_ISO_VOLATILE` Definido como 1 se a [`/volatile:iso`](../build/reference/volatile-volatile-keyword-interpretation.md) opção do compilador estiver definida. Caso contrário, indefinido.

- `_KERNEL_MODE`Definido como 1 se a opção de compilador [ **`/kernel`** (criar binário do modo kernel)](../build/reference/kernel-create-kernel-mode-binary.md) estiver definida. Caso contrário, indefinido.

- `_M_AMD64` Definido como o valor inteiro literal 100 para compilações que visam processadores x64. Caso contrário, indefinido.

- `_M_ARM` Definido como o valor literal inteiro 7 para compilações direcionadas a processadores ARM. Caso contrário, indefinido.

- `_M_ARM_ARMV7VE` Definido como 1 quando a [`/arch:ARMv7VE`](../build/reference/arch-arm.md) opção do compilador é definida para compilações direcionadas a processadores ARM. Caso contrário, indefinido.

- `_M_ARM_FP` Definido como um valor literal inteiro que indica qual [`/arch`](../build/reference/arch-arm.md) opção de compilador foi definida para destinos do processador ARM. Caso contrário, indefinido.

  - Um valor no intervalo de 30-39 se nenhuma **`/arch`** opção de ARM tiver sido especificada, indicando que a arquitetura padrão para ARM foi definida ( `VFPv3` ).

  - Um valor no intervalo de 40-49 se **`/arch:VFPv4`** foi definido.

  - Para obter mais informações, consulte [ **`/arch`** (ARM)](../build/reference/arch-arm.md).

- `_M_ARM64` Definido como 1 para compilações que visam processadores ARM de 64 bits. Caso contrário, indefinido.

- `_M_CEE`Definido como 001 se qualquer opção [ **`/clr`** de compilador (compilação de Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md) estiver definida. Caso contrário, indefinido.

- `_M_CEE_PURE` Preterido a partir do Visual Studio 2015. Definido como 001 se a [`/clr:pure`](../build/reference/clr-common-language-runtime-compilation.md) opção do compilador estiver definida. Caso contrário, indefinido.

- `_M_CEE_SAFE` Preterido a partir do Visual Studio 2015. Definido como 001 se a [`/clr:safe`](../build/reference/clr-common-language-runtime-compilation.md) opção do compilador estiver definida. Caso contrário, indefinido.

- `_M_FP_EXCEPT` Definido como 1 se a [`/fp:except`](../build/reference/fp-specify-floating-point-behavior.md) [`/fp:strict`](../build/reference/fp-specify-floating-point-behavior.md) opção de compilador ou está definida. Caso contrário, indefinido.

- `_M_FP_FAST` Definido como 1 se a [`/fp:fast`](../build/reference/fp-specify-floating-point-behavior.md) opção do compilador estiver definida. Caso contrário, indefinido.

- `_M_FP_PRECISE` Definido como 1 se a [`/fp:precise`](../build/reference/fp-specify-floating-point-behavior.md) opção do compilador estiver definida. Caso contrário, indefinido.

- `_M_FP_STRICT` Definido como 1 se a [`/fp:strict`](../build/reference/fp-specify-floating-point-behavior.md) opção do compilador estiver definida. Caso contrário, indefinido.

- `_M_IX86` Definido como o valor inteiro literal 600 para compilações que visam processadores x86. Essa macro não está definida para destinos de compilação x64 ou ARM.

- `_M_IX86_FP` Definido como um valor literal inteiro que indica a [`/arch`](../build/reference/arch-arm.md) opção de compilador que foi definida ou o padrão. Essa macro é sempre definida quando o destino da compilação é um processador x86. Caso contrário, indefinido. Quando definido, o valor é:

  - 0 se a `/arch:IA32` opção do compilador foi definida.

  - 1 se a `/arch:SSE` opção do compilador foi definida.

  - 2 se a `/arch:SSE2` `/arch:AVX` opção do compilador,, `/arch:AVX2` ou `/arch:AVX512` foi definida. Esse valor será o padrão se uma `/arch` opção de compilador não tiver sido especificada. Quando `/arch:AVX` é especificado, a macro `__AVX__` também é definida. Quando `/arch:AVX2` é especificado, `__AVX__` e `__AVX2__` também são definidos. Quando `/arch:AVX512` é especificado,,,,,, `__AVX__` `__AVX2__` `__AVX512BW__` `__AVX512CD__` `__AVX512DQ__` `__AVX512F__` e `__AVX512VL__` também são definidos.

  - Para obter mais informações, consulte [ **`/arch`** (x86)](../build/reference/arch-x86.md).

- `_M_X64` Definido como o valor inteiro literal 100 para compilações que visam processadores x64. Caso contrário, indefinido.

- `_MANAGED` Definido como 1 quando a [`/clr`](../build/reference/clr-common-language-runtime-compilation.md) opção do compilador é definida. Caso contrário, indefinido.

- `_MSC_BUILD` Definido como um literal inteiro que contém o elemento número de revisão do número de versão do compilador. O número de revisão é o quarto elemento do número de versão delimitado por período. Por exemplo, se o número de versão do compilador C/C++ da Microsoft for 15.00.20706.01, a `_MSC_BUILD` macro será avaliada como 1. Essa macro sempre é definida.

- `_MSC_EXTENSIONS`Definido como 1 se a opção de compilador ativado por padrão [ **`/Ze`** (habilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) estiver definida. Caso contrário, indefinido.

- `_MSC_FULL_VER` Definido como um literal inteiro que codifica os elementos de número principal, secundário e de compilação do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitado por período, o número secundário é o segundo elemento e o número de Build é o terceiro elemento. Por exemplo, se o número de versão do compilador C/C++ da Microsoft for 15.00.20706.01, a `_MSC_FULL_VER` macro será avaliada como 150020706. Insira `cl /?` na linha de comando para exibir o número de versão do compilador. Essa macro sempre é definida.

- `_MSC_VER` Definido como um literal inteiro que codifica os elementos de número principal e secundário do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitado por período e o número secundário é o segundo elemento. Por exemplo, se o número de versão do compilador C/C++ da Microsoft for 17.00.51106.1, a `_MSC_VER` macro será avaliada como 1700. Insira `cl /?` na linha de comando para exibir o número de versão do compilador. Essa macro sempre é definida.

   | Versão do Visual Studio | `_MSC_VER` |
   |--|--|
   | Visual Studio 6.0 | 1200 |
   | Visual Studio .NET 2002 (7,0) | 1300 |
   | Visual Studio .NET 2003 (7,1) | 1310 |
   | Visual Studio 2005 (8,0) | 1.400 |
   | Visual Studio 2008 (9,0) | 1500 |
   | Visual Studio 2010 (10,0) | 1600 |
   | Visual Studio 2012 (11,0) | 1.700 |
   | Visual Studio 2013 (12,0) | 1800 |
   | Visual Studio 2015 (14,0) | 1900 |
   | Visual Studio 2017 RTW (15,0) | 1910 |
   | Visual Studio 2017 versão 15.3 | 1911 |
   | Visual Studio 2017 versão 15.5 | 1912 |
   | Visual Studio 2017 versão 15.6 | 1913 |
   | Visual Studio 2017 versão 15.7 | 1914 |
   | Visual Studio 2017 versão 15.8 | 1915 |
   | Visual Studio 2017 versão 15,9 | 1916 |
   | Visual Studio 2019 RTW (16,0) | 1920 |
   | Visual Studio 2019 versão 16.1 | 1921 |
   | Visual Studio 2019 versão 16.2 | 1922 |
   | Visual Studio 2019 versão 16,3 | 1923 |
   |  Visual Studio 2019 versão 16.4 | 1924 |
   | Visual Studio 2019 versão 16,5 | 1925 |
   | Visual Studio 2019 versão 16,6 | 1926 |
   | Visual Studio 2019 versão 16,7 | 1927 |
   | Visual Studio 2019 versão 16,8 | 1928 |

   Para testar as versões do compilador ou as atualizações em uma determinada versão do Visual Studio ou posterior, use o `>=` operador. Você pode usá-lo em uma diretiva condicional para comparar `_MSC_VER` com essa versão conhecida. Se você tiver várias versões mutuamente exclusivas para comparar, ordene suas comparações em ordem decrescente de número de versão. Por exemplo, esse código verifica se há compiladores lançados no Visual Studio 2017 e posterior. Em seguida, ele verifica os compiladores lançados no ou após o Visual Studio 2015. Em seguida, ele verifica todos os compiladores lançados antes do Visual Studio 2015:

   ```cpp
   #if _MSC_VER >= 1910
   // . . .
   #elif _MSC_VER >= 1900
   // . . .
   #else
   // . . .
   #endif
   ```

   Para obter mais informações, consulte [Visual C++ versão do compilador](https://devblogs.microsoft.com/cppblog/visual-c-compiler-version/) no blog da equipe do Microsoft C++.

- `_MSVC_LANG` Definido como um literal inteiro que especifica o padrão de linguagem C++ direcionado pelo compilador. Ele é definido somente no código compilado como C++. A macro é o valor literal inteiro 201402L por padrão ou quando a [`/std:c++14`](../build/reference/std-specify-language-standard-version.md) opção do compilador é especificada. A macro será definida como 201703L se a [`/std:c++17`](../build/reference/std-specify-language-standard-version.md) opção do compilador for especificada. Ele é definido como um valor mais alto e não especificado quando a [`/std:c++latest`](../build/reference/std-specify-language-standard-version.md) opção é especificada. Caso contrário, a macro será indefinida. As `_MSVC_LANG` Opções de compilador macro e [ **`/std`** (especificar versão padrão da linguagem)](../build/reference/std-specify-language-standard-version.md) estão disponíveis a partir do Visual Studio 2015 atualização 3.

- `__MSVC_RUNTIME_CHECKS` Definido como 1 quando uma das [`/RTC`](../build/reference/rtc-run-time-error-checks.md) Opções do compilador é definida. Caso contrário, indefinido.

- `_MSVC_TRADITIONAL` Definido como 0 quando a opção de compilador do modo de conformidade do pré-processador [`/experimental:preprocessor`](../build/reference/experimental-preprocessor.md) estiver definida. Definido como 1 por padrão, ou quando a [`/experimental:preprocessor-`](../build/reference/experimental-preprocessor.md) opção do compilador é definida, para indicar que o pré-processador tradicional está em uso. A `_MSVC_TRADITIONAL` opção de compilador macro e [ **`/experimental:preprocessor`** (habilitar modo de conformidade do pré-processador)](../build/reference/experimental-preprocessor.md) está disponível a partir do Visual Studio 2017 versão 15,8.

   ```cpp
   #if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
   // Logic using the traditional preprocessor
   #else
   // Logic using cross-platform compatible preprocessor
   #endif
   ```

- `_MT`Definido como 1 quando [ **`/MD`** ou **`/MDd`** (DLL de vários threads)](../build/reference/md-mt-ld-use-run-time-library.md) ou [ **`/MT`** ou **`/MTd`** (multithreaded)](../build/reference/md-mt-ld-use-run-time-library.md) é especificado. Caso contrário, indefinido.

- `_NATIVE_WCHAR_T_DEFINED` Definido como 1 quando a [`/Zc:wchar_t`](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção do compilador é definida. Caso contrário, indefinido.

- `_OPENMP`Definido como inteiro literal 200203, se a opção de compilador [ **`/openmp`** (habilitar suporte de OpenMP 2,0)](../build/reference/openmp-enable-openmp-2-0-support.md) estiver definida. Esse valor representa a data da especificação de OpenMP implementada por MSVC. Caso contrário, indefinido.

   ```cpp
   // _OPENMP_dir.cpp
   // compile with: /openmp
   #include <stdio.h>
   int main() {
      printf("%d\n", _OPENMP);
   }
   ```

- `_PREFAST_` Definido como 1 quando a [`/analyze`](../build/reference/analyze-code-analysis.md) opção do compilador é definida. Caso contrário, indefinido.

- `__TIMESTAMP__` Definido como um literal de cadeia de caracteres que contém a data e a hora da última modificação do arquivo de origem atual, no formato de tamanho constante abreviado, retornado pela [`asctime`](../c-runtime-library/reference/asctime-wasctime.md) função CRT, por exemplo, `Fri 19 Aug 13:32:58 2016` . Essa macro sempre é definida.

- `_VC_NODEFAULTLIB`Definido como 1 quando a opção de compilador [ **`/Zl`** (omitir nome de biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) está definida. Caso contrário, indefinido.

- `_WCHAR_T_DEFINED` Definido como 1 quando a [`/Zc:wchar_t`](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção de compilador padrão é definida. A `_WCHAR_T_DEFINED` macro é definida, mas não tem valor se a **`/Zc:wchar_t-`** opção do compilador estiver definida e **`wchar_t`** estiver definida em um arquivo de cabeçalho do sistema incluído no seu projeto. Caso contrário, indefinido.

- `_WIN32` Definido como 1 quando o destino da compilação é ARM de 32 bits, ARM de 64 bits, x86 ou x64. Caso contrário, indefinido.

- `_WIN64` Definido como 1 quando o destino da compilação for 64-bit ARM ou x64. Caso contrário, indefinido.

- `_WINRT_DLL`Definido como 1 quando compilado como C++ e ambos [ **`/ZW`** (Windows Runtime compilação)](../build/reference/zw-windows-runtime-compilation.md) [ **`/LD`** **`/LDd`** e opções de compilador são](../build/reference/md-mt-ld-use-run-time-library.md) definidas. Caso contrário, indefinido.

Nenhuma macro de pré-processador que identifique a versão da Biblioteca ATL ou MFC é predefinida pelo compilador. Os cabeçalhos de Biblioteca ATL e MFC definem essas macros de versão internamente. Eles são indefinidos em diretivas de pré-processador feitas antes que o cabeçalho necessário seja incluído.

- `_ATL_VER` Definido \<atldef.h> como um literal inteiro que codifica o número de versão da ATL.

- `_MFC_VER` Definido \<afxver_.h> como um literal inteiro que codifica o número de versão do MFC.

## <a name="see-also"></a>Confira também

[Macros (C/C++)](../preprocessor/macros-c-cpp.md)<br/>
[Operadores do pré-processador](../preprocessor/preprocessor-operators.md)<br/>
[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)
