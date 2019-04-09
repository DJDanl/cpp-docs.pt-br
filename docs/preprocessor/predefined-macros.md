---
title: Macros predefinidas
ms.custom: update_every_version
ms.date: 04/05/2019
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
ms.openlocfilehash: dedcab9b0addd3696749b50fef92b70081981c03
ms.sourcegitcommit: 35c4b3478f8cc310ebbd932a18963ad8ab846ed9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/08/2019
ms.locfileid: "59237205"
---
# <a name="predefined-macros"></a>Macros predefinidas

O compilador Microsoft C/C++ (MSVC) predefine determinadas macros de pré-processador, dependendo do idioma (C ou C++), o destino de compilação e as opções do compilador escolhida.

MSVC dá suporte as macros de pré-processador predefinidas exigidas pelo padrão ANSI/ISO C99 e ISO C + + 14 e padrões do c++17. A implementação também dá suporte a várias macros de pré-processador de específico da Microsoft mais. Algumas macros são definidas apenas para ambientes de compilação específica ou opções do compilador. Exceto onde observado, as macros são definidas em toda uma unidade de conversão, como se eles foram especificados como **/D** argumentos de opção de compilador. Quando definido, as macros são expandidas para os valores especificados pelo pré-processador antes da compilação. Macros predefinidas não usam argumentos e não podem ser redefinidas.

## <a name="standard-predefined-identifier"></a>Padrão de identificador predefinido

O compilador dá suporte a esse identificador predefinido, especificado pelo ISO C99 e ISO c++11.

- **&#95;&#95;Func&#95; &#95;**  o nome qualificado e não adornado da função como um local de função **const estático** matriz de **char**.

    ```cpp
    void example(){
        printf("%s\n", __func__);
    } // prints "example"
    ```

## <a name="standard-predefined-macros"></a>Padrão de macros predefinidas

O compilador dá suporte a essas macros predefinidas especificadas pelo ISO C99 e ISO padrões do c++17.

- **&#95;&#95;cplusplus** definido como um valor de literal de inteiro quando a unidade de tradução é compilada como C++. Caso contrário, indefinido.

- **&#95;&#95;DATA&#95; &#95;**  a data de compilação do arquivo de origem atual. A data é uma cadeia de caracteres de tamanho constante literal do formulário *Mmm dd aaaa*. O nome do mês *Mmm* é o mesmo que o nome do mês abreviado gerado pela biblioteca de tempo de execução C (CRT) [asctime](../c-runtime-library/reference/asctime-wasctime.md) função. O primeiro caractere da data *dd* é um espaço, se o valor for menor que 10. Essa macro é sempre definida.

- **&#95;&#95;ARQUIVO&#95; &#95;**  o nome do arquivo de origem atual. **&#95;&#95;ARQUIVO&#95; &#95;**  expande para uma cadeia de caracteres literal. Para garantir que o caminho completo para o arquivo é exibido, use [/FC (caminho completo da fonte de código de arquivo no diagnóstico)](../build/reference/fc-full-path-of-source-code-file-in-diagnostics.md). Essa macro é sempre definida.

- **&#95;&#95;LINHA&#95; &#95;**  definido como o número de linha de número inteiro no arquivo de origem atual. O valor da **&#95; &#95;linha&#95; &#95;** macro pode ser alterada usando uma `#line` diretiva. Essa macro é sempre definida.

- **&#95;&#95;STDC&#95; &#95;**  definido como 1, apenas quando compilado como C e, se o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador é especificada. Caso contrário, indefinido.

- **&#95;&#95;STDC&#95;HOSTED&#95; &#95;**  definido como 1 se a implementação é um *hospedado implementação*, um que ofereça suporte a biblioteca inteira de padrão necessária. Caso contrário, é definido como 0.

- **&#95;&#95;STDCPP&#95;THREADS&#95; &#95;**  definido como 1 se e somente se um programa pode ter mais de um thread de execução e compilada como C++. Caso contrário, indefinido.

- **&#95;&#95;TEMPO de&#95; &#95;**  o tempo de tradução de unidade de tradução pré-processado. O tempo é uma cadeia de caracteres literal do formulário *hh*, o mesmo que a hora retornada pelo CRT [asctime](../c-runtime-library/reference/asctime-wasctime.md) função. Essa macro é sempre definida.

## <a name="microsoft-specific-predefined-macros"></a>Macros predefinidas de específico da Microsoft

MSVC dá suporte a essas macros predefinidas adicionais.

- **&#95;&#95;ATOM&#95; &#95;**  definido como 1 quando o [/favor:ATOM](../build/reference/favor-optimize-for-architecture-specifics.md) opção de compilador é definida e o alvo do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95;&#95;AVX&#95; &#95;**  definido como 1 quando o [/arch: avx](../build/reference/arch-x86.md) ou [/arch:avx2](../build/reference/arch-x86.md) opções do compilador são definidas e o alvo do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95;&#95;AVX2&#95; &#95;**  definido como 1 quando o [/arch:avx2](../build/reference/arch-x86.md) opção de compilador é definida e o alvo do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95;CHAR&#95;não assinado** definido como 1 se o padrão **char** tipo é não assinado. Esse valor é definido quando o [/J (char padrão não é do tipo assinado)](../build/reference/j-default-char-type-is-unsigned.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95;&#95;CLR&#95;VIDOR** definido como um literal de inteiro que representa a versão do tempo de execução do CLR (Common Language) usados para compilar o aplicativo. O valor é codificado no formulário `Mmmbbbbb`, onde `M` é a versão principal do tempo de execução `mm` é a versão secundária do tempo de execução, e `bbbbb` é o número de compilação. **&#95;&#95;CLR&#95;VIDOR** está definido se o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido.

    ```cpp
    // clr_ver.cpp
    // compile with: /clr
    using namespace System;
    int main() {
       Console::WriteLine(__CLR_VER);
    }
    ```

- **&#95;CONTROLE de&#95;fluxo&#95;proteger** definido como 1 quando o [/Guard: CF (Habilitar controle de fluxo de proteção)](../build/reference/guard-enable-control-flow-guard.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95;&#95;CONTADOR de&#95; &#95;**  expande para um literal de inteiro que começa em 0. O valor é incrementado em 1 toda vez que foi usado em um arquivo de origem ou em incluíam cabeçalhos do arquivo de origem. **&#95;&#95;CONTADOR de&#95; &#95;**  lembra seu estado quando você usar cabeçalhos pré-compilados. Essa macro é sempre definida.

  Este exemplo usa `__COUNTER__` para atribuir identificadores exclusivos para três objetos diferentes do mesmo tipo. O `exampleClass` construtor aceita um inteiro como um parâmetro. Na `main`, o aplicativo declara três objetos do tipo `exampleClass`, usando `__COUNTER__` como o parâmetro identificador exclusivo:

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

- **&#95;&#95;cplusplus&#95;cli** definido como o valor de literal de inteiro 200406 quando compilada como C++ e um [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido. Quando definido,  **&#95; &#95;cplusplus&#95;cli** está em vigor em toda a unidade de tradução.

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

- **&#95;&#95;cplusplus&#95;winrt** definido como o valor de literal de inteiro 201009 quando compilada como C++ e o [/ZW (compilação de tempo de execução do Windows)](../build/reference/zw-windows-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95;CPPRTTI** definido como 1 se o [/GR (Habilitar informações de tipo em tempo de execução)](../build/reference/gr-enable-run-time-type-information.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95;CPPUNWIND** definido como 1 se uma ou mais da [/GX (habilitar tratamento de exceções)](../build/reference/gx-enable-exception-handling.md), [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md), ou [/EH (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md) opções do compilador são definidas. Caso contrário, indefinido.

- **&#95;Depurar** definido como 1 quando o [/LDd](../build/reference/md-mt-ld-use-run-time-library.md), [/MDd](../build/reference/md-mt-ld-use-run-time-library.md), ou [/MTd](../build/reference/md-mt-ld-use-run-time-library.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95;DLL** definido como 1 quando o [/MD](../build/reference/md-mt-ld-use-run-time-library.md) ou [/MDd](../build/reference/md-mt-ld-use-run-time-library.md) opção do compilador (Multithreaded DLL) está definida. Caso contrário, indefinido.

- **&#95;&#95;FUNCDNAME&#95; &#95;**  definido como uma cadeia de caracteres literal que contém o [nome decorado](../build/reference/decorated-names.md) da função. A macro é definida apenas dentro de uma função. O **&#95; &#95;FUNCDNAME&#95; &#95;** macro não é expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [p](../build/reference/p-preprocess-to-a-file.md) opção de compilador.

   Este exemplo usa o `__FUNCDNAME__`, `__FUNCSIG__`, e `__FUNCTION__` macros para exibir informações de função.

   [!code-cpp[NVC_Predefined_Macros_Examples#1](../preprocessor/codesnippet/CPP/predefined-macros_1.cpp)]

- **&#95;&#95;FUNCSIG&#95; &#95;**  definido como uma cadeia de caracteres literal que contém a assinatura da função. A macro é definida apenas dentro de uma função. O **&#95; &#95;FUNCSIG&#95; &#95;** macro não é expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [p](../build/reference/p-preprocess-to-a-file.md) opção de compilador. Quando compilada para um destino de 64 bits, a convenção de chamada é `__cdecl` por padrão. Para obter um exemplo de uso, consulte o `__FUNCDNAME__` macro.

- **&#95;&#95;FUNÇÃO&#95; &#95;**  definido como uma cadeia de caracteres literal que contém o nome não decorado da função. A macro é definida apenas dentro de uma função. O **&#95; &#95;função&#95; &#95;** macro não é expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [p](../build/reference/p-preprocess-to-a-file.md) opção de compilador. Para obter um exemplo de uso, consulte o `__FUNCDNAME__` macro.

- **&#95;INTEGRAL&#95;MAX&#95;BITS** definidos como o valor de literal de inteiro 64, o tamanho máximo (em bits) para um tipo de integral não vetor. Essa macro é sempre definida.

   ```cpp
   // integral_max_bits.cpp
   #include <stdio.h>
   int main() {
      printf("%d\n", _INTEGRAL_MAX_BITS);
   }
   ```

- **&#95;&#95;INTELLISENSE&#95; &#95;**  definido como 1 durante um compilador IntelliSense passe no IDE do Visual Studio. Caso contrário, indefinido. Você pode usar essa macro para proteger o código, o compilador do IntelliSense não compreender ou usá-lo para alternar entre a compilação e o compilador do IntelliSense. Para obter mais informações, consulte [dicas de solução de problemas de lentidão de IntelliSense](https://devblogs.microsoft.com/cppblog/troubleshooting-tips-for-intellisense-slowness/).

- **&#95;ISO&#95;volátil** definido como 1 se o [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95;KERNEL&#95;modo** definido como 1 se o [/kernel (criar binário do modo Kernel)](../build/reference/kernel-create-kernel-mode-binary.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95;M&#95;AMD64** definido como o literal inteiro valor 100 para compilações que processadores x64. Caso contrário, indefinido.

- **&#95;M&#95;ARM** definido como o valor de literal de inteiro 7 para compilações destinados a processadores ARM. Caso contrário, indefinido.

- **&#95;M&#95;ARM&#95;ARMV7VE** definido como 1 quando o [arch:armv7ve](../build/reference/arch-arm.md) opção de compilador é definida para compilações destinados a processadores ARM. Caso contrário, indefinido.

- **&#95;M&#95;ARM&#95;FP** definido como um valor de literal de inteiro que indica qual [/arch](../build/reference/arch-arm.md) opção do compilador foi definida para destinos de processador ARM. Caso contrário, indefinido.

  - Um valor no intervalo 30-39, se nenhum `/arch` ARM opção foi especificada, indicando a arquitetura padrão para ARM foi definido (`VFPv3`).

  - Um valor no intervalo 40-49, se `/arch:VFPv4` foi definido.

  - Para obter mais informações, consulte [/arch (ARM)](../build/reference/arch-arm.md).

- **&#95;M&#95;ARM64** definido como 1 para compilações destinados a processadores ARM de 64 bits. Caso contrário, indefinido.

- **&#95;M&#95;CEE** definido como 001 se qualquer [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95;M&#95;CEE&#95;PURE** preterido a partir do Visual Studio 2015. Definido como 001 se o [/clr: pure](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95;M&#95;CEE&#95;seguro** preterido a partir do Visual Studio 2015. Definido como 001 se o [/CLR: safe](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;EXCEPT** definido como 1 se o [/fp: exceto](../build/reference/fp-specify-floating-point-behavior.md) ou [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) opção do compilador está definida. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;rápido** definido como 1 se o [Fast](../build/reference/fp-specify-floating-point-behavior.md) opção do compilador está definida. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;PRECISE** definido como 1 se o [/fp: preciso](../build/reference/fp-specify-floating-point-behavior.md) opção do compilador está definida. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;STRICT** definido como 1 se o [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) opção do compilador está definida. Caso contrário, indefinido.

- **&#95;M&#95;IX86** definido como o literal inteiro valor 600 para compilações que processadores x86. Essa macro não está definida para x64 ou destinos de compilação do ARM.

- **&#95;M&#95;IX86&#95;FP** definido como um valor de literal de inteiro que indica a [/arch](../build/reference/arch-arm.md) opção de compilador que era conjunto ou padrão. Essa macro é sempre definida quando o destino de compilação é x86 processador. Caso contrário, indefinido. Quando definido, o valor é:

  - 0 se o `/arch:IA32` opção do compilador foi definida.

  - 1 se o `/arch:SSE` opção do compilador foi definida.

  - 2 se a `/arch:SSE2`, `/arch:AVX`, ou `/arch:AVX2` opção do compilador foi definida. Esse valor é o padrão se um `/arch` opção de compilador não foi especificada. Quando `/arch:AVX` for especificado, a macro **&#95; &#95;AVX&#95; &#95;** também é definida. Quando `/arch:AVX2` for especificado, ambos **&#95; &#95;AVX&#95; &#95;** e **&#95; &#95;AVX2&#95; &#95;** também estão definidos.

  - Para obter mais informações, consulte [/arch (x86)](../build/reference/arch-x86.md).

- **&#95;M&#95;X64** definido como o literal inteiro valor 100 para compilações que processadores x64. Caso contrário, indefinido.

- **&#95;MANAGED** definido como 1 quando o [/clr](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.

- **&#95;MSC&#95;COMPILAR** definido como um literal de inteiro que contém o elemento de número de revisão do número de versão do compilador. O número de revisão é o quarto elemento do número de versão delimitado por período. Por exemplo, se o número de versão do compilador Microsoft C/C++ for 15.00.20706.01, a  **&#95;MSC&#95;COMPILAR** macro é avaliada como 1. Essa macro é sempre definida.

- **&#95;MSC&#95;extensões** definido como 1 se o ativado por padrão [/Ze (habilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95;MSC&#95;completo&#95;VIDOR** definido como um literal de inteiro que codifica as principais, secundária e criar o número de elementos do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitado por ponto, o número secundário é o segundo elemento e o número de compilação é o terceiro elemento. Por exemplo, se o número de versão do compilador Microsoft C/C++ for 15.00.20706.01, a  **&#95;MSC&#95;completo&#95;VIDOR** macro será avaliada em 150020706. Insira `cl /?` na linha de comando para exibir o número de versão do compilador. Essa macro é sempre definida.

- **&#95;MSC&#95;VIDOR** definido como um literal de inteiro que codifica os elementos de número principais e secundárias do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitado por ponto e o número secundário é o segundo elemento. Por exemplo, se o número de versão do compilador Microsoft C/C++ for 17.00.51106.1, a  **&#95;MSC&#95;VIDOR** macro será avaliada em 1700. Insira `cl /?` na linha de comando para exibir o número de versão do compilador. Essa macro é sempre definida.

   |Versão do Visual Studio|**&#95;MSC&#95;VER**|
   |-|-|
   |Visual Studio 6.0|1200|
   |Visual Studio .NET 2002 (7.0)|1300|
   |Visual Studio .NET 2003 (7.1)|1310|
   |Visual Studio 2005 (8.0)|1400|
   |O Visual Studio 2008 (9.0)|1500|
   |Visual Studio 2010 (10.0)|1600|
   |Visual Studio 2012 (11.0)|1700|
   |Visual Studio 2013 (12.0)|1800|
   |Visual Studio 2015 (14.0)|1900|
   |Visual Studio 2017 RTW (15.0)|1910|
   |Visual Studio 2017 versão 15.3|1911|
   |Visual Studio 2017 versão 15.5|1912|
   |Visual Studio 2017 versão 15.6|1913|
   |Visual Studio 2017 versão 15.7|1914|
   |Visual Studio 2017 versão 15.8|1915|
   |Visual Studio 2017 versão 15,9|1916|
   |Visual Studio 2019 RTW (16.0)|1920|

   Para testar versões do compilador ou atualizações em uma determinada versão do Visual Studio ou depois, use o **>=** operador. Você pode usá-lo em uma diretiva condicional a ser comparado  **&#95;MSC&#95;VIDOR** em relação a essa versão conhecida. Se você tiver várias versões mutuamente exclusivas para comparar, ordene nas comparações em ordem decrescente de número de versão. Por exemplo, esse código verifica para compiladores lançados no Visual Studio 2017 e versões posteriores. Em seguida, ele verifica os compiladores lançados em ou após o Visual Studio 2015. Em seguida, ele verifica todos os compiladores lançados antes do Visual Studio 2015:

   ```cpp
   #if _MSC_VER >= 1910
   // . . .
   #elif _MSC_VER >= 1900
   // . . .
   #else
   // . . .
   #endif
   ```

   Para obter mais informações, consulte [versão do compilador Visual C++](https://devblogs.microsoft.com/cppblog/visual-c-compiler-version/) no Blog da equipe do Microsoft C++.

- **&#95;MSVC&#95;LANG** definido como um literal de inteiro que especifica o padrão de linguagem C++ direcionado pelo compilador. Ele é definido apenas em código compilado como C++. A macro é o literal inteiro valor L 201402 por padrão, ou quando o [/std:c++17 + + 14](../build/reference/std-specify-language-standard-version.md) for especificada a opção de compilador. A macro é definida como 201703L se o [/std:c++17 + + 17](../build/reference/std-specify-language-standard-version.md) for especificada a opção de compilador. Ele é definido como um valor superior, não especificado quando o [/std:c++17 + + mais recente](../build/reference/std-specify-language-standard-version.md) opção for especificada. Caso contrário, a macro será indefinida. O  **&#95;MSVC&#95;LANG** macro e [/std (especificar versão de idioma padrão)](../build/reference/std-specify-language-standard-version.md) opções do compilador estão disponíveis no Visual Studio 2015 atualização 3.

- **&#95;&#95;MSVC&#95;tempo de execução&#95;VERIFICA** definida como 1 quando um do [/RTC](../build/reference/rtc-run-time-error-checks.md) opções do compilador está definido. Caso contrário, indefinido.

- **&#95;MT** definido como 1 quando [/MD ou /MDd](../build/reference/md-mt-ld-use-run-time-library.md) (Multithreaded DLL) ou [/MT ou /MTd](../build/reference/md-mt-ld-use-run-time-library.md) (Multithreaded) são especificados. Caso contrário, indefinido.

- **&#95;NATIVO&#95;WCHAR&#95;T&#95;definido pelo** definido como 1 quando o [/ZC: wchar_t](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção do compilador está definida. Caso contrário, indefinido.

- **&#95;OPENMP** definido como inteiro literal 200203, se o [/openmp (Habilitar suporte a OpenMP 2.0)](../build/reference/openmp-enable-openmp-2-0-support.md) é definir a opção de compilador. Esse valor representa a data da especificação de OpenMP implementada pelo MSVC. Caso contrário, indefinido.

   ```cpp
   // _OPENMP_dir.cpp
   // compile with: /openmp
   #include <stdio.h>
   int main() {
      printf("%d\n", _OPENMP);
   }
   ```

- **&#95;PREFAST&#95;**  definido como 1 quando o [/ANALYZE](../build/reference/analyze-code-analysis.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95;&#95;TIMESTAMP&#95; &#95;**  definido como uma cadeia de caracteres literal que contém a data e hora da última modificação do arquivo de origem atual, na forma abreviada, constante comprimento retornado pelo CRT [asctime](../c-runtime-library/reference/asctime-wasctime.md) função, por exemplo, `Fri 19 Aug 13:32:58 2016`. Essa macro é sempre definida.

- **&#95;VC&#95;/NODEFAULTLIB** definido como 1 quando o [/Zl (omitir nome da biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) opção de compilador está definida. Caso contrário, indefinido.

- **&#95;WCHAR&#95;T&#95;definidos** definido como 1 quando o padrão [/ZC: wchar_t](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção do compilador está definida. O  **&#95;WCHAR&#95;T&#95;definidas** macro é definida, mas não tem nenhum valor se a `/Zc:wchar_t-` é definir a opção de compilador, e **wchar_t** é definido em um arquivo de cabeçalho do sistema incluído no seu projeto. Caso contrário, indefinido.

- **&#95;Win32** definidos como 1 quando o destino de compilação é ARM de 32 bits, 64-bit ARM, x86, ou x64. Caso contrário, indefinido.

- **&#95;Win64** definida como 1 quando o destino de compilação é ARM de 64 bits ou x64. Caso contrário, indefinido.

- **&#95;WINRT&#95;DLL** definido como 1 quando compilada como C++ e ambos [/ZW (compilação de tempo de execução do Windows)](../build/reference/zw-windows-runtime-compilation.md) e [/LD ou /LDd](../build/reference/md-mt-ld-use-run-time-library.md) opções do compilador são definidas. Caso contrário, indefinido.

Sem macros de pré-processador que identificam a versão da biblioteca MFC ou ATL são predefinidas pelo compilador. Cabeçalhos de biblioteca do MFC e ATL definem essas macros versão internamente. Eles estiverem indefinidos em diretivas de pré-processador feitas antes que o cabeçalho necessário está incluído.

- **&#95;ATL&#95;VIDOR** definidos no \<atldef.h > como um literal de inteiro que codifica o número de versão do ATL.

- **&#95;MFC&#95;VIDOR** definidos no \<afxver_.h > como um literal de inteiro que codifica o número de versão do MFC.

## <a name="see-also"></a>Consulte também

[Macros (C/C++)](../preprocessor/macros-c-cpp.md)<br/>
[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)<br/>
[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)