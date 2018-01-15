---
title: Predefinidos Macros | Microsoft Docs
ms.custom: 
ms.date: 11/16/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _ATL_VER
- __ATOM__
- __AVX__
- __AVX2__
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
dev_langs: C++
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
caps.latest.revision: "75"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 86905a879abe9b81302a8f196e200c1d0c227bb7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="predefined-macros"></a>Macros predefinidas

O compilador do Visual C++ predefine determinadas macros de pré-processador, dependendo da linguagem (C ou C++), o destino de compilação e as opções de compilador escolhido.

Visual C++ oferece suporte as macros de pré-processador predefinidas necessárias especificadas pelo padrão ANSI/ISO C99 e o C++ 14 padrão ISO. A implementação também oferece suporte a várias mais macros de pré-processador específicas da Microsoft. Algumas macros são definidas apenas para ambientes de desenvolvimento específico ou opções do compilador. A menos que indicado, as macros são definidas em uma unidade de conversão como se eles foram especificados como **/D** argumentos de opção de compilador. Quando definido, as macros são expandidas para os valores especificados no pré-processador antes da compilação. As macros predefinidas não usam argumentos e não podem ser redefinidas.

## <a name="standard-predefined-identifier"></a>Padrão de identificador predefinida

O compilador dá suporte a esse identificador predefinido especificado pelo C99 ISO e ISO C++ 11.

- **&#95; &#95; func #95; &#95;**  o nome não qualificado e acrescido da função delimitador como um local de função `static const` matriz de `char`.

    ```cpp
    void example(){
        printf("%s\n", __func__);
    } // prints "example"
    ```

## <a name="standard-predefined-macros"></a>Macros predefinidas padrão

O compilador dá suporte a essas macros predefinidas especificadas por C99 o ISO e ISO C++ 17 padrões.

- **&#95; &#95; cplusplus** definido como um valor de literal de inteiro quando a unidade de tradução é compilada como C++. Caso contrário, indefinido.

- **&#95; &#95; Data &#95; &#95;**  a data de compilação do arquivo de origem atual. A data é uma cadeia de caracteres constante literal do formulário *Mmm dd aaaa*. O nome do mês *Mmm* é o mesmo que o nome do mês abreviado no datas geradas pela biblioteca de tempo de execução C [asctime](../c-runtime-library/reference/asctime-wasctime.md) função. O primeiro caractere da data *dd* é um espaço, se o valor for menor que 10. Essa macro é sempre definida.

- **&#95; &#95; ARQUIVO &#95; &#95;**  o nome do arquivo de origem atual. **&#95; &#95; ARQUIVO &#95; &#95;**  se expande para uma cadeia de caracteres literal. Para garantir que o caminho completo para o arquivo é exibido, use [/FC (completo caminho do arquivo de código fonte no diagnóstico)](../build/reference/fc-full-path-of-source-code-file-in-diagnostics.md). Essa macro é sempre definida.

- **&#95; &#95; LINHA &#95; &#95;**  Definido como o número de linha de número inteiro no arquivo de origem atual. O valor da **&#95; &#95; LINHA &#95; &#95;**  macro pode ser alterada usando um `#line` diretiva. Essa macro é sempre definida.

- **&#95; &#95; STDC #95; &#95;**  Definido como 1, apenas quando compilado como C e se o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador é especificada. Caso contrário, indefinido.

- **&#95; &#95; STDC &#95; HOSPEDADO &#95; &#95;**  Definido como 1 se a implementação é um *hospedado implementação*, que oferece suporte a biblioteca inteira de padrão necessária. Caso contrário, é definido como 0.

- **&#95; &#95; STDCPP &#95; THREADS #95; &#95;**  Definido como 1 se e somente se um programa pode ter mais de um thread de execução e compilado como C++. Caso contrário, indefinido.

- **&#95; &#95; TEMPO &#95; &#95;**  a hora da conversão da unidade de tradução pré-processados. O tempo é uma cadeia de caracteres literal do formulário *hh*, o mesmo que o tempo retornado pela biblioteca de tempo de execução do C [asctime](../c-runtime-library/reference/asctime-wasctime.md) função. Essa macro é sempre definida.

## <a name="microsoft-specific-predefined-macros"></a>Macros predefinidas específicas da Microsoft

Microsoft Visual C++ dá suporte a essas macros predefinidas adicionais.

- **&#95; &#95; ATOM &#95; &#95;**  Definido como 1 quando o [/favor:ATOM](../build/reference/favor-optimize-for-architecture-specifics.md) é definir a opção de compilador e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95; &#95; AVX #95; &#95;**  Definido como 1 quando o [/arch: avx](../build/reference/arch-x86.md) ou [/arch: avx2](../build/reference/arch-x86.md) opções do compilador são definidas e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95; &#95; AVX&#2;95; &#95;**  Definido como 1 quando o [/arch: avx2](../build/reference/arch-x86.md) é definir a opção de compilador e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95; CHAR &#95; Sem sinal** definido como 1 se o padrão `char` tipo não está assinado. Isso é definido quando o [/J (char padrão é de tipo não assinado)](../build/reference/j-default-char-type-is-unsigned.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; &#95; CLR &#95; VER** definido como um literal de inteiro que representa a versão do common language runtime usado quando o aplicativo foi compilado. O valor é codificado no formato `Mmmbbbbb`, onde `M` é a versão principal do tempo de execução, `mm` é a versão secundária do tempo de execução, e `bbbbb` é o número de compilação. **&#95; &#95; CLR &#95; VER** é definido se o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido.

    ```cpp
    // clr_ver.cpp
    // compile with: /clr
    using namespace System;
    int main() {
       Console::WriteLine(__CLR_VER);
    }
    ```

- **&#95; CONTROLE &#95; FLUXO &#95; PROTEGER** definido como 1 quando o [/Guard: CF (habilitar o controle de fluxo de proteção)](../build/reference/guard-enable-control-flow-guard.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; &#95; CONTADOR #95; &#95;**  Expande para um literal de inteiro que começa em 0 e é incrementada em 1 toda vez que ele é usado em um arquivo de origem ou incluídos cabeçalhos do arquivo de origem. **&#95; &#95; CONTADOR #95; &#95;**  lembra seu estado quando você usar cabeçalhos pré-compilados. Essa macro é sempre definida.

  Este exemplo usa `__COUNTER__` atribuir identificadores exclusivos para três objetos diferentes do mesmo tipo. O `exampleClass` construtor aceita um inteiro como um parâmetro. Em `main`, o aplicativo declara três objetos do tipo `exampleClass`usando `__COUNTER__` como o parâmetro do identificador exclusivo:

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

- **&#95; &#95; cplusplus &#95; cli** definido como o valor de literal de inteiro 200406 quando compilado como C++ e um [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido. Quando definido, **&#95; &#95; cplusplus &#95; cli** está em vigor em toda a unidade de tradução.

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

- **&#95; &#95; cplusplus &#95; winrt** definido como o valor de literal de inteiro 201009 quando compilado como C++ e o [/ZW (compilação de tempo de execução do Windows)](../build/reference/zw-windows-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; CPPRTTI** definido como 1 se o [/GR (Habilitar informações de tipo em tempo de execução)](../build/reference/gr-enable-run-time-type-information.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; CPPUNWIND** definido como 1 se um ou mais o [/GX (habilitar tratamento de exceção)](../build/reference/gx-enable-exception-handling.md), [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md), ou [/EH (modelo de tratamento de exceção) ](../build/reference/eh-exception-handling-model.md) opções do compilador são definidas. Caso contrário, indefinido.

- **&#95; depuração** definido como 1 quando o [/LDd](../build/reference/md-mt-ld-use-run-time-library.md), [/MDd](../build/reference/md-mt-ld-use-run-time-library.md), ou [/MTd](../build/reference/md-mt-ld-use-run-time-library.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; DLL** definido como 1 quando o [/MD](../build/reference/md-mt-ld-use-run-time-library.md) ou [/MDd](../build/reference/md-mt-ld-use-run-time-library.md) opção de compilador (DLL multithread) está definida. Caso contrário, indefinido.

- **&#95; &#95; FUNCDNAME #95; &#95;**  Definido como uma cadeia de caracteres literal que contém o [decorado nome](../build/reference/decorated-names.md) da função de delimitador. A macro é definida apenas dentro de uma função. O **&#95; &#95; FUNCDNAME #95; &#95;**  macro não será expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) opção de compilador.

   Este exemplo usa o `__FUNCDNAME__`, `__FUNCSIG__`, e `__FUNCTION__` macros para exibir informações de função.

   [!code-cpp[NVC_Predefined_Macros_Examples#1](../preprocessor/codesnippet/CPP/predefined-macros_1.cpp)]

- **&#95; &#95; FUNCSIG #95; &#95;**  Definido como uma cadeia de caracteres literal que contém a assinatura da função de delimitador. A macro é definida apenas dentro de uma função. O **&#95; &#95; FUNCSIG #95; &#95;**  macro não será expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) opção de compilador. Quando compilado para um destino de 64 bits, a convenção de chamada é `__cdecl` por padrão. Para obter um exemplo de uso, consulte o `__FUNCDNAME__` macro.

- **&#95; &#95; FUNÇÃO &#95; &#95;**  Definido como uma cadeia de caracteres literal que contém o nome não decorado da função de delimitador. A macro é definida apenas dentro de uma função. O **&#95; &#95; FUNÇÃO &#95; &#95;**  macro não será expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) opção de compilador. Para obter um exemplo de uso, consulte o `__FUNCDNAME__` macro.

- **&#95; INTEGRAL &#95; MÁX &#95; BITS** definido como o valor de literal de inteiro 64, o tamanho máximo (em bits) para um tipo de vetor não integral. Essa macro é sempre definida.

   ```cpp
   // integral_max_bits.cpp
   #include <stdio.h>
   int main() {
      printf("%d\n", _INTEGRAL_MAX_BITS);
   }
   ```

- **&#95; &#95; INTELLISENSE &#95; &#95;**  Definido como passar 1 durante um compilador IntelliSense no Visual Studio IDE. Caso contrário, indefinido. Você pode usar essa macro para proteger o código, o compilador do IntelliSense não entender ou usá-lo para alternar entre a compilação e compilador do IntelliSense. Para obter mais informações, consulte [dicas de solução de problemas de lentidão IntelliSense](https://blogs.msdn.microsoft.com/vcblog/2011/03/29/troubleshooting-tips-for-intellisense-slowness/).

- **&#95; ISO &#95; VOLÁTIL** definido como 1 se o [/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; KERNEL &#95; MODO** definido como 1 se o [/kernel (criar binário do modo Kernel)](../build/reference/kernel-create-kernel-mode-binary.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; M &#95; AMD64** definido como 100 para compilações do valor o literal de inteiro que processadores x64 de destino. Caso contrário, indefinido.

- **&#95; M &#95; ARM** definido como o valor de literal de inteiro 7 para compilações que processadores ARM de destino. Caso contrário, indefinido.

- **&#95; M &#95; ARM &#95; ARMV7VE** definido como 1 quando o [/arch:ARMv7VE](../build/reference/arch-arm.md) opção de compilador está definida para compilações que processadores ARM de destino. Caso contrário, indefinido.

- **&#95; M &#95; ARM &#95; FP** definido como um valor de literal de inteiro que indica qual [/arch](../build/reference/arch-arm.md) opção de compilador foi definida, se o destino de compilação é um processador ARM. Caso contrário, indefinido.

  - No intervalo 30 a 39 Se nenhum **/arch** ARM opção foi especificada, indicando que a arquitetura de padrão para ARM foi definido (`VFPv3`).

  - No intervalo de 40 49 se **/arch:VFPv4** foi definido.

  - Consulte [/arch (ARM)](../build/reference/arch-arm.md) para obter mais informações.

- **&#95; M &#95; ARM64** definido como 1 para compilações que processadores ARM de 64 bits de destino. Caso contrário, indefinido.

- **&#95; M &#95; CEE** definido como 001 se qualquer [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; M &#95; CEE &#95; PURO** preteridos a partir do Visual Studio 2015. Definido como 001 se o [/clr: pure](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; M &#95; CEE &#95; SEGURANÇA** preteridos a partir do Visual Studio 2015. Definido como 001 se o [/CLR: safe](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; M &#95; FP &#95; EXCETO** definido como 1 se o [/fp: exceto](../build/reference/fp-specify-floating-point-behavior.md) ou [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; M &#95; FP &#95; RÁPIDO** definido como 1 se o [Fast](../build/reference/fp-specify-floating-point-behavior.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; M &#95; FP &#95; PRECISO** definido como 1 se o [/fp: preciso](../build/reference/fp-specify-floating-point-behavior.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; M &#95; FP &#95; ESTRITO** definido como 1 se o [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; M &#95; IX86** definido como o literal de inteiro valor 600 para compilações que processadores x86 de destino. Esta macro não está definida para x64 ou destinos de compilação do ARM.

- **&#95; M &#95; IX86 &#95; FP** definido como um valor de literal de inteiro que indica o [/arch](../build/reference/arch-arm.md) opção de compilador conjunto ou o padrão. Esta macro sempre é definida quando o destino de compilação é uma arquitetura x86 processador. Caso contrário, indefinido. Quando definido, o valor é:

  - 0 se o **/arch:IA32** opção de compilador foi definida.

  - 1 se o **/arch:SSE** opção de compilador foi definida.

  - 2 se o **/arch: SSE2**, **/arch: avx** ou **/arch: avx2** opção de compilador foi definida. Esse valor é o padrão se um **/arch** opção de compilador não foi especificada. Quando **/arch: avx** for especificado, a macro **&#95; &#95; AVX #95; &#95;**  também está definido. Quando **/arch: avx2** for especificado, ambos **&#95; &#95; AVX #95; &#95;**  e **&#95; &#95; AVX&#2;95; &#95;**  também são definidas.

  - Consulte [/arch (x86)](../build/reference/arch-x86.md) para obter mais informações.

- **&#95; M &#95; X64** definido como 100 para compilações do valor o literal de inteiro que processadores x64 de destino. Caso contrário, indefinido.

- **&#95; GERENCIADO** definido como 1 quando o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; MSC &#95; CRIAR** definido como um literal de inteiro que contém o elemento de número de revisão do número de versão do compilador. O número de revisão é o quarto elemento do número de versão delimitados. Por exemplo, se o número de versão do compilador Visual C++ é 15.00.20706.01, o **&#95; MSC &#95; CRIAR** macro é avaliado como 1. Essa macro é sempre definida.

- **&#95; MSC &#95; EXTENSÕES** definido como 1 se o [/Ze (habilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) opção de compilador for definida, que é o padrão. Caso contrário, indefinido.

- **&#95; MSC &#95; COMPLETO &#95; VER** definido como um literal de inteiro que codifica as principais, secundária e criar elementos de número do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitados, o número secundário é o segundo elemento e o número de compilação é o terceiro elemento. Por exemplo, se o número de versão do compilador Visual C++ é 15.00.20706.01, o **&#95; MSC &#95; COMPLETO &#95; VER** macro é avaliada como 150020706. Insira **cl /?** na linha de comando para exibir o número da versão do compilador. Essa macro é sempre definida.

- **&#95; MSC &#95; VER** definido como um literal de inteiro que codifica os elementos principais e secundários número do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitada por ponto e o número secundário é o segundo elemento. Por exemplo, se o número de versão do compilador Visual C++ é 17.00.51106.1, o **&#95; MSC &#95; VER** macro é avaliada como 1700. Insira **cl /?** na linha de comando para exibir o número da versão do compilador. Essa macro é sempre definida.

- **&#95; MSVC &#95; LANG** definido como um literal de inteiro que especifica o padrão de linguagem C++ direcionado pelo compilador. Quando compilado c++, a macro é o valor de literal de inteiro 201402 se o [/std:c + + 14](../build/reference/std-specify-language-standard-version.md) é definir a opção de compilador, ou por padrão; é definido para 201703 se o [/std:c + + 17](../build/reference/std-specify-language-standard-version.md) é definir a opção de compilador; e ele é definido como um não especificado, maior valor quando o [/std:c + + mais recente](../build/reference/std-specify-language-standard-version.md). Caso contrário, a macro será indefinida. O **&#95; MSVC &#95; LANG** macro e [/std (especificar versão padrão do idioma)](../build/reference/std-specify-language-standard-version.md) opções do compilador são disponível a partir do Visual Studio 2015 atualização 3.

- **&#95; &#95; MSVC &#95; Tempo de execução &#95; VERIFICA** definido como 1 quando uma da [/RTC](../build/reference/rtc-run-time-error-checks.md) opções do compilador é definido. Caso contrário, indefinido.

- **&#95; MT** definido como 1 quando [/MD ou /MDd](../build/reference/md-mt-ld-use-run-time-library.md) (DLL multithread) ou [/MT ou /MTd](../build/reference/md-mt-ld-use-run-time-library.md) (Multithreaded) for especificado. Caso contrário, indefinido.

- **&#95; NATIVO &#95; WCHAR &#95; T &#95; definido pelo** definido como 1 quando o [/ZC:](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; OPENMP** definido como um inteiro literal 200203, que representa a data da especificação OpenMP implementada pelo Visual C++, se o [/openmp (Habilitar suporte a OpenMP 2.0)](../build/reference/openmp-enable-openmp-2-0-support.md) é definir a opção de compilador. Caso contrário, indefinido.

   ```cpp
   // _OPENMP_dir.cpp
   // compile with: /openmp
   #include <stdio.h>
   int main() {
      printf("%d\n", _OPENMP);
   }
   ```

- **&#95; PREFAST &#95;**  Definido como 1 quando o [/ANALYZE](../build/reference/analyze-code-analysis.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95; &#95; Carimbo de hora #95; &#95;**  Definido como uma cadeia de caracteres literal que contém a data e hora da última modificação do arquivo de origem atual, na forma abreviada, constante comprimento retornado pela biblioteca de tempo de execução do C [asctime](../c-runtime-library/reference/asctime-wasctime.md) funcionar, por exemplo, `Fri 19 Aug 13:32:58 2016`. Essa macro é sempre definida.

- **&#95; VC &#95; /NODEFAULTLIB** definido como 1 quando o [/Zl (omitir a nome de biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95; WCHAR &#95; T &#95; definido pelo** definido como 1 quando o padrão [/ZC:](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção de compilador está definida. O **&#95; WCHAR &#95; T &#95; definido pelo** macro é definida, mas não tem nenhum valor se o **/Zc:wchar_t-** é definir a opção de compilador, e `wchar_t` é definido em um arquivo de cabeçalho do sistema incluídos em seu projeto. Caso contrário, indefinido.

- **&#95; Win32** definidos como 1 quando o destino de compilação é ARM de 32 bits, 64 bits ARM, x86, ou x64. Caso contrário, indefinido.

- **&#95; Win64** definido como 1 quando o destino de compilação é ARM de 64 bits ou x64. Caso contrário, indefinido.

- **&#95; WINRT &#95; DLL** definido como 1 quando compilado como C++ e ambos [/ZW (compilação de tempo de execução do Windows)](../build/reference/zw-windows-runtime-compilation.md) e [/LD ou /LDd](../build/reference/md-mt-ld-use-run-time-library.md) opções do compilador são definidas. Caso contrário, indefinido.

 Macros de pré-processador usadas para determinar a versão da biblioteca ATL ou do MFC não são predefinidas pelo compilador. Essas macros são definidas nos cabeçalhos da biblioteca, para que eles não estão definidos em diretivas de pré-processador antes do cabeçalho necessário está incluído.

- **&#95; ATL &#95; VER** definido em \<atldef.h > como um literal de inteiro que codifica o número de versão do ATL.

- **&#95; MFC &#95; VER** definido em \<afxver_.h > como um literal de inteiro que codifica o número de versão do MFC.

## <a name="see-also"></a>Consulte também

[Macros (C/C++)](../preprocessor/macros-c-cpp.md)   
[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)   
[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)
