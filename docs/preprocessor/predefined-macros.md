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
ms.openlocfilehash: 15b70b0292f671d99b320c8d23598e68b47adb0d
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70273815"
---
# <a name="predefined-macros"></a>Macros predefinidas

O compilador C/C++ Microsoft (MSVC) predefine determinadas macros de pré-processador, dependendo da linguagem (C ou C++), do destino de compilação e das opções de compilador escolhidas.

O MSVC dá suporte às macros de pré-processador predefinidas exigidas pelo padrão ANSI/ISO C99 e pelos padrões ISO C++ 14 e C++ 17. A implementação também dá suporte a várias macros de pré-processador específicas da Microsoft. Algumas macros são definidas somente para ambientes de compilação específicos ou opções de compilador. Exceto quando indicado, as macros são definidas em uma unidade de tradução como se fossem especificadas como argumentos de opção de compilador **/d** . Quando definido, as macros são expandidas para os valores especificados pelo pré-processador antes da compilação. As macros predefinidas não usam argumentos e não podem ser redefinidas.

## <a name="standard-predefined-identifier"></a>Identificador padrão predefinido

O compilador oferece suporte a esse identificador predefinido especificado por ISO C99 e ISO C++ 11.

- **&#95; Func &#95; &#95;** O nome não qualificado e não adornado da função de circunscrição como uma matriz **const estática** de função local de **Char**.

    ```cpp
    void example(){
        printf("%s\n", __func__);
    } // prints "example"
    ```

## <a name="standard-predefined-macros"></a>Macros padrão predefinidas

O compilador oferece suporte a essas macros predefinidas especificadas pelos padrões ISO C99 e ISO C++ 17.

- **&#95;CPlusPlus &#95;** Definido como um valor literal inteiro quando a unidade de tradução é compilada como C++. Caso contrário, indefinido.

- **Data de&#95; início &#95; &#95;** A data de compilação do arquivo de origem atual. A data é um literal de cadeia de caracteres de tamanho constante da forma *Mmm dd aaaa*. O nome do mês *Mmm* é o mesmo que o nome do mês abreviado gerado pela função [asctime](../c-runtime-library/reference/asctime-wasctime.md) da biblioteca de tempo de execução do C (CRT). O primeiro caractere de data *DD* será um espaço se o valor for menor que 10. Essa macro sempre é definida.

- **&#95;&#95; Do &#95;arquivo** O nome do arquivo de origem atual. O arquivo expande para um literal de cadeia de caracteres. **&#95; &#95;&#95;** Para garantir que o caminho completo para o arquivo seja exibido, use [/FC (caminho completo do arquivo de código-fonte no diagnóstico)](../build/reference/fc-full-path-of-source-code-file-in-diagnostics.md). Essa macro sempre é definida.

- **&#95; Linha &#95; &#95;** Definido como o número de linha inteiro no arquivo de origem atual. O valor da  **&#95; &#95;macro de&#95; linha** pode ser alterado usando uma `#line` diretiva. Essa macro sempre é definida.

- **&#95; Stdc &#95; &#95;** Definido como 1 somente quando compilado como C e se a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) for especificada. Caso contrário, indefinido.

- **&#95;&#95;STDC&#95;hospedado&#95;**  definido como 1 se a implementação for uma *implementação hospedada*, uma que dá suporte a toda a biblioteca padrão necessária. Caso contrário, definido como 0.

- **&#95;&#95;STDCPP&#95;&#95; threads** definidos como 1 se e somente se um programa puder ter mais de um thread de execução e compilado como C++. Caso contrário, indefinido.

- **&#95; Tempo &#95; &#95;** A hora da tradução da unidade de tradução pré-processado. O tempo é um literal de cadeia de caracteres no formato *hh: mm: SS*, o mesmo que o tempo retornado pela função [asctime](../c-runtime-library/reference/asctime-wasctime.md) do CRT. Essa macro sempre é definida.

## <a name="microsoft-specific-predefined-macros"></a>Macros predefinidas específicas da Microsoft

O MSVC dá suporte a essas macros predefinidas adicionais.

- **&#95; Atom &#95; &#95;** Definido como 1 quando a opção de compilador [/favor: Atom](../build/reference/favor-optimize-for-architecture-specifics.md) é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95; AVX &#95; &#95;** Definido como 1 quando as opções de compilador [/Arch: AVX](../build/reference/arch-x86.md) ou [/Arch: AVX2](../build/reference/arch-x86.md) são definidas e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95; AVX2 &#95; &#95;** Definido como 1 quando a opção de compilador [/Arch: AVX2](../build/reference/arch-x86.md) é definida e o destino do compilador é x86 ou x64. Caso contrário, indefinido.

- **&#95;CHAR&#95;não assinado** definido como 1 se o tipo de **caractere** padrão não estiver assinado. Esse valor é definido quando a opção de compilador [/j (tipo de caractere padrão não assinado)](../build/reference/j-default-char-type-is-unsigned.md) está definida. Caso contrário, indefinido.

- **&#95;CLR ver &#95;&#95;** Definido como um literal inteiro que representa a versão do CLR (Common Language Runtime) usado para compilar o aplicativo. O valor `Mmmbbbbb`é codificado no formulário, em que `M` é a versão principal do tempo de execução, `mm` é a versão secundária do tempo de execução `bbbbb` e é o número da compilação. **&#95;&#95;CLR&#95;ver** será definido se a opção de compilador [/CLR](../build/reference/clr-common-language-runtime-compilation.md) estiver definida. Caso contrário, indefinido.

    ```cpp
    // clr_ver.cpp
    // compile with: /clr
    using namespace System;
    int main() {
       Console::WriteLine(__CLR_VER);
    }
    ```

- **&#95;O&#95;protetor&#95;de fluxo de controle** definido como 1 quando a opção de compilador [/Guard: CF (habilitar proteção de fluxo de controle)](../build/reference/guard-enable-control-flow-guard.md) está definida. Caso contrário, indefinido.

- **&#95;Contador de &#95;&#95;** Expande para um literal inteiro que começa em 0. O valor é incrementado em 1 cada vez que é usado em um arquivo de origem ou em cabeçalhos incluídos do arquivo de origem. O contador lembra seu estado quando você usa cabeçalhos pré-compilados. **&#95; &#95;&#95;** Essa macro sempre é definida.

  Este exemplo usa `__COUNTER__` para atribuir identificadores exclusivos a três objetos diferentes do mesmo tipo. O `exampleClass` construtor usa um inteiro como um parâmetro. No `main`, o aplicativo declara três objetos do tipo `exampleClass`, usando `__COUNTER__` como o parâmetro de identificador exclusivo:

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

- **&#95;&#95;CPlusPlus&#95;CLI** definida como o valor literal de inteiro 200406 quando compilado C++ como e uma opção de compilador [/CLR](../build/reference/clr-common-language-runtime-compilation.md) é definida. Caso contrário, indefinido. Quando definido,  **&#95; &#95;a&#95;CLI do CPlusPlus** está em vigor em toda a unidade de tradução.

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

- **&#95;&#95;CPlusPlus&#95;winrt** definido como o valor de literal inteiro 201009 quando compilado C++ como e a opção de compilador [/zw (compilação de Windows Runtime)](../build/reference/zw-windows-runtime-compilation.md) é definida. Caso contrário, indefinido.

- **&#95;CPPRTTI** Definido como 1 se a opção de compilador [/gr (habilitar informações de tipo de tempo de execução)](../build/reference/gr-enable-run-time-type-information.md) está definida. Caso contrário, indefinido.

- **&#95;CPPUNWIND** Definido como 1 se uma ou mais das opções de compilador [/GX (habilitar manipulação de exceção)](../build/reference/gx-enable-exception-handling.md), [/CLR (Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md)ou [/eh (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md) estão definidas. Caso contrário, indefinido.

- **&#95;Depurar** Definido como 1 quando a opção de compilador [/ldd](../build/reference/md-mt-ld-use-run-time-library.md), [/MDD](../build/reference/md-mt-ld-use-run-time-library.md)ou [/MTD](../build/reference/md-mt-ld-use-run-time-library.md) é definida. Caso contrário, indefinido.

- DLL definido como 1 quando a opção de compilador [/MD](../build/reference/md-mt-ld-use-run-time-library.md) ou [/MDD](../build/reference/md-mt-ld-use-run-time-library.md) (DLL de vários threads) está definida.  **&#95;** Caso contrário, indefinido.

- **&#95; FUNCDNAME &#95; &#95;** Definido como um literal de cadeia de caracteres que contém o [nome decorado](../build/reference/decorated-names.md) da função de circunscrição. A macro é definida somente dentro de uma função. **&#95;A &#95;macro&#95; FUNCDNAME** não será expandida se você usar a opção de compilador [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) .

   Este exemplo usa as `__FUNCDNAME__`macros, `__FUNCTION__` `__FUNCSIG__`e para exibir informações de função.

   [!code-cpp[NVC_Predefined_Macros_Examples#1](../preprocessor/codesnippet/CPP/predefined-macros_1.cpp)]

- **&#95; FUNCSIG &#95; &#95;** Definido como um literal de cadeia de caracteres que contém a assinatura da função de circunscrição. A macro é definida somente dentro de uma função. **&#95;A &#95;macro&#95; FUNCSIG** não será expandida se você usar a opção de compilador [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) . Quando compilado para um destino de 64 bits, a Convenção de chamada `__cdecl` é por padrão. Para obter um exemplo de uso, consulte `__FUNCDNAME__` a macro.

- **&#95; Função &#95; &#95;** Definido como um literal de cadeia de caracteres que contém o nome não decorado da função de circunscrição. A macro é definida somente dentro de uma função. A macro da  **&#95; &#95;&#95; função** não será expandida se você usar a opção de compilador [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) . Para obter um exemplo de uso, consulte `__FUNCDNAME__` a macro.

- **máximo de bits integral&#95;&#95; &#95;** Definido como o valor inteiro literal 64, o tamanho máximo (em bits) para um tipo não vetorial integral. Essa macro sempre é definida.

   ```cpp
   // integral_max_bits.cpp
   #include <stdio.h>
   int main() {
      printf("%d\n", _INTEGRAL_MAX_BITS);
   }
   ```

- **&#95; INTELLISENSE &#95; &#95;** Definido como 1 durante uma passagem do compilador do IntelliSense no IDE do Visual Studio. Caso contrário, indefinido. Você pode usar essa macro para proteger o código que o compilador do IntelliSense não entende ou usá-lo para alternar entre o compilador Build e o IntelliSense. Para obter mais informações, consulte [dicas de solução de problemas para o IntelliSense lentidão](https://devblogs.microsoft.com/cppblog/troubleshooting-tips-for-intellisense-slowness/).

- **&#95;ISO&#95;volatile** definido como 1 se a opção de compilador [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) estiver definida. Caso contrário, indefinido.

- **&#95;Modo&#95;kernel** definido como 1 se a opção de compilador [/kernel (criar binário do modo kernel)](../build/reference/kernel-create-kernel-mode-binary.md) está definida. Caso contrário, indefinido.

- **&#95;M&#95;AMD64** Definido como o valor inteiro literal 100 para compilações que visam processadores x64. Caso contrário, indefinido.

- **&#95;braço&#95;M** Definido como o valor literal inteiro 7 para compilações direcionadas a processadores ARM. Caso contrário, indefinido.

- **&#95;M&#95;ARM&#95;ARMV7VE** definido como 1 quando a opção de compilador [/Arch: ARMV7VE](../build/reference/arch-arm.md) é definida para compilações direcionadas a processadores ARM. Caso contrário, indefinido.

- **&#95;O&#95;FP&#95;de ARM de M** definido como um valor literal inteiro que indica qual opção de compilador [/Arch](../build/reference/arch-arm.md) foi definida para destinos de processador ARM. Caso contrário, indefinido.

  - Um valor no intervalo de 30-39 se nenhuma `/arch` opção de ARM tiver sido especificada, indicando que a arquitetura padrão para ARM`VFPv3`foi definida ().

  - Um valor no intervalo de 40-49 se `/arch:VFPv4` foi definido.

  - Para obter mais informações, consulte [/Arch (ARM)](../build/reference/arch-arm.md).

- **&#95;ARM64&#95;M** Definido como 1 para compilações que visam processadores ARM de 64 bits. Caso contrário, indefinido.

- **&#95;M&#95;CEE** definido como 001 se qualquer opção [de compilador/CLR (Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md) estiver definida. Caso contrário, indefinido.

- **M&#95;CEE&#95;puro &#95;** Preterido a partir do Visual Studio 2015. Definido como 001 se a opção de compilador [/CLR: Pure](../build/reference/clr-common-language-runtime-compilation.md) estiver definida. Caso contrário, indefinido.

- **CEE segurança de M&#95;&#95; &#95;** Preterido a partir do Visual Studio 2015. Definido como 001 se a opção de compilador [/CLR: safe](../build/reference/clr-common-language-runtime-compilation.md) estiver definida. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;, exceto** definido como 1 se a opção de compilador [/fp: except](../build/reference/fp-specify-floating-point-behavior.md) ou [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) estiver definida. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;rápido** definido como 1 se a opção de compilador [/fp: Fast](../build/reference/fp-specify-floating-point-behavior.md) for definida. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;preciso** definido como 1 se a opção de compilador [/fp: preciso](../build/reference/fp-specify-floating-point-behavior.md) estiver definida. Caso contrário, indefinido.

- **&#95;M&#95;FP&#95;estrito** definido como 1 se a opção de compilador [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) estiver definida. Caso contrário, indefinido.

- **&#95;IX86&#95;M** Definido como o valor inteiro literal 600 para compilações que visam processadores x86. Essa macro não está definida para destinos de compilação x64 ou ARM.

- **&#95;M&#95;IX86&#95;FP** definido como um valor literal inteiro que indica a opção de compilador [/Arch](../build/reference/arch-arm.md) que foi definida ou o padrão. Essa macro é sempre definida quando o destino da compilação é um processador x86. Caso contrário, indefinido. Quando definido, o valor é:

  - 0 se a `/arch:IA32` opção do compilador foi definida.

  - 1 se a `/arch:SSE` opção do compilador foi definida.

  - 2 se a `/arch:SSE2`opção `/arch:AVX`do compilador `/arch:AVX2` , ou foi definida. Esse valor será o padrão se uma `/arch` opção de compilador não tiver sido especificada. Quando `/arch:AVX` é especificado, a macro **&#95; &#95;AVX&#95;** também é definida. Quando `/arch:AVX2` é especificado, **&#95; &#95;AVX&#95;** e **&#95; AVX2 também são definidos. &#95; &#95;**

  - Para obter mais informações, consulte [/arch (x86)](../build/reference/arch-x86.md).

- **&#95;M&#95;x64** Definido como o valor inteiro literal 100 para compilações que visam processadores x64. Caso contrário, indefinido.

- **&#95;Gerenciado** Definido como 1 quando a opção de compilador [/CLR](../build/reference/clr-common-language-runtime-compilation.md) está definida. Caso contrário, indefinido.

- **&#95;Build&#95;MSC** Definido como um literal inteiro que contém o elemento número de revisão do número de versão do compilador. O número de revisão é o quarto elemento do número de versão delimitado por período. Por exemplo, se o número de versão do compilador C/C++ Microsoft for 15.00.20706.01, a macro de  **&#95;Build MSC&#95;** será avaliada como 1. Essa macro sempre é definida.

- **&#95;Extensões&#95;MSC** definidas como 1 se a opção de compilador [/Ze (habilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) padrão está definida. Caso contrário, indefinido.

- **MSC&#95;completo&#95;da &#95;versão** Definido como um literal inteiro que codifica os elementos de número principal, secundário e de compilação do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitado por período, o número secundário é o segundo elemento e o número de Build é o terceiro elemento. Por exemplo, se o número de versão do compilador C/C++ Microsoft for 15.00.20706.01, a  **&#95;macro&#95;MSC&#95;Full ver** será avaliada como 150020706. Insira `cl /?` na linha de comando para exibir o número de versão do compilador. Essa macro sempre é definida.

- **&#95;MSC&#95;ver** Definido como um literal inteiro que codifica os elementos de número principal e secundário do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitado por período e o número secundário é o segundo elemento. Por exemplo, se o número de versão do Microsoft C/C++ compilador for 17.00.51106.1, a  **&#95;macro&#95;MSC ver** será avaliada como 1700. Insira `cl /?` na linha de comando para exibir o número de versão do compilador. Essa macro sempre é definida.

   |Versão do Visual Studio|**&#95;MSC&#95;VER**|
   |-|-|
   |Visual Studio 6.0|1200|
   |Visual Studio .NET 2002 (7,0)|1300|
   |Visual Studio .NET 2003 (7,1)|1310|
   |Visual Studio 2005 (8,0)|1400|
   |Visual Studio 2008 (9,0)|1500|
   |Visual Studio 2010 (10,0)|1600|
   |Visual Studio 2012 (11,0)|1700|
   |Visual Studio 2013 (12,0)|1800|
   |Visual Studio 2015 (14,0)|1900|
   |Visual Studio 2017 RTW (15,0)|1910|
   |Visual Studio 2017 versão 15.3|1911|
   |Visual Studio 2017 versão 15.5|1912|
   |Visual Studio 2017 versão 15.6|1913|
   |Visual Studio 2017 versão 15.7|1914|
   |Visual Studio 2017 versão 15.8|1915|
   |Visual Studio 2017 versão 15,9|1916|
   |Visual Studio 2019 RTW (16,0)|1920|
   |Visual Studio 2019 versão 16.1|1921|
   |Visual Studio 2019 versão 16.2|1922|
   |Visual Studio 2019 versão 16,3|1923|

   Para testar as versões do compilador ou as atualizações em uma determinada versão do Visual Studio ou posterior, **>=** use o operador. Você pode usá-lo em uma diretiva condicional para  **&#95;comparar&#95;MSC ver** com essa versão conhecida. Se você tiver várias versões mutuamente exclusivas para comparar, ordene suas comparações em ordem decrescente de número de versão. Por exemplo, esse código verifica se há compiladores lançados no Visual Studio 2017 e posterior. Em seguida, ele verifica os compiladores lançados no ou após o Visual Studio 2015. Em seguida, ele verifica todos os compiladores lançados antes do Visual Studio 2015:

   ```cpp
   #if _MSC_VER >= 1910
   // . . .
   #elif _MSC_VER >= 1900
   // . . .
   #else
   // . . .
   #endif
   ```

   Para obter mais informações, [consulte C++ versão do compilador Visual](https://devblogs.microsoft.com/cppblog/visual-c-compiler-version/) no C++ blog da equipe da Microsoft.

- **&#95;MSVC&#95;Lang** definido como um literal inteiro que especifica o C++ padrão de idioma direcionado pelo compilador. Ele é definido somente no código compilado como C++. A macro é o valor literal inteiro 201402L por padrão ou quando a opção de compilador [/std: c++ 14](../build/reference/std-specify-language-standard-version.md) é especificada. A macro será definida como 201703L se a opção de compilador [/std: c++ 17](../build/reference/std-specify-language-standard-version.md) for especificada. Ele é definido como um valor superior, não especificado quando a opção [/std: c + + mais recente](../build/reference/std-specify-language-standard-version.md) é especificada. Caso contrário, a macro será indefinida. As opções de  **&#95;compilador MSVC&#95;Lang** macro e [/STD (especificar versão padrão da linguagem)](../build/reference/std-specify-language-standard-version.md) estão disponíveis a partir do Visual Studio 2015 atualização 3.

- **&#95;&#95;As&#95;verificações&#95;de tempo de execução MSVC** são definidas como 1 quando uma das opções do compilador [/RTC](../build/reference/rtc-run-time-error-checks.md) é definida. Caso contrário, indefinido.

- **&#95;MSVC&#95;tradicional** definido como 0 quando o modo de conformidade do pré-processador [/experimental:](../build/reference/rtc-run-time-error-checks.md) opção de compilador de pré-processador está definida. Definido como 1 por padrão, ou quando a opção [/experimental: pré-processador-](../build/reference/rtc-run-time-error-checks.md) Compiler é definida, para indicar que o pré-processador tradicional está em uso. A  **&#95;opção&#95;** de compilador MSVC macro tradicional e [/experimental: pré-processador (habilitar modo de conformidade do pré-processador)](../build/reference/experimental-preprocessor.md) está disponível a partir do Visual Studio 2017 versão 15,8.

   ```cpp
   #if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
   // Logic using the traditional preprocessor
   #else
   // Logic using cross-platform compatible preprocessor
   #endif
   ```

- **&#95;MT** Definido como 1 quando [/MD ou/MDD](../build/reference/md-mt-ld-use-run-time-library.md) (DLL multi-threaded) ou [/MT ou/MTD](../build/reference/md-mt-ld-use-run-time-library.md) (multi-threaded) é especificado. Caso contrário, indefinido.

- **&#95;NATIVO&#95;WCHAR&#95;T&#95;definido** definido como 1 quando a opção de compilador [/Zc: wchar_t](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) está definida. Caso contrário, indefinido.

- **&#95;OpenMP** Definido como inteiro literal 200203, se a opção de compilador [/OpenMP (habilitar suporte de openmp 2,0)](../build/reference/openmp-enable-openmp-2-0-support.md) estiver definida. Esse valor representa a data da especificação de OpenMP implementada por MSVC. Caso contrário, indefinido.

   ```cpp
   // _OPENMP_dir.cpp
   // compile with: /openmp
   #include <stdio.h>
   int main() {
      printf("%d\n", _OPENMP);
   }
   ```

- **&#95;PREfast&#95;** Definido como 1 quando a opção de compilador [/Analyze](../build/reference/analyze-code-analysis.md) é definida. Caso contrário, indefinido.

- **&#95; Timestamp &#95; &#95;** Definido como um literal de cadeia de caracteres que contém a data e a hora da última modificação do arquivo de origem atual, na forma abreviada, de tamanho constante, retornada pela função [asctime](../c-runtime-library/reference/asctime-wasctime.md) do CRT `Fri 19 Aug 13:32:58 2016`, por exemplo,. Essa macro sempre é definida.

- **&#95;VC&#95;NODEFAULTLIB** definido como 1 quando a opção de compilador [/zl (omitir nome da biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) está definida. Caso contrário, indefinido.

- **&#95;WCHAR&#95;T&#95;definido** definido como 1 quando a opção de compilador [/Zc: wchar_t](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) padrão está definida. A  **&#95;&#95;macro&#95;definida em WCHAR** não é definida, mas não tem valor `/Zc:wchar_t-` se a opção do compilador estiver definida e **wchar_t** estiver definido em um arquivo de cabeçalho do sistema incluído no seu projeto. Caso contrário, indefinido.

- **&#95;Win32** Definido como 1 quando o destino da compilação é ARM de 32 bits, ARM de 64 bits, x86 ou x64. Caso contrário, indefinido.

- **&#95;Win64** Definido como 1 quando o destino da compilação for 64-bit ARM ou x64. Caso contrário, indefinido.

- **&#95;A&#95;dll do WINRT** definida como 1 quando C++ compiladas como e as opções de compilador [/zw (Windows Runtime compilação)](../build/reference/zw-windows-runtime-compilation.md) e [/LD ou/ldd](../build/reference/md-mt-ld-use-run-time-library.md) estão definidas. Caso contrário, indefinido.

Nenhuma macro de pré-processador que identifique a versão da Biblioteca ATL ou MFC é predefinida pelo compilador. Os cabeçalhos de Biblioteca ATL e MFC definem essas macros de versão internamente. Eles são indefinidos em diretivas de pré-processador feitas antes que o cabeçalho necessário seja incluído.

- **&#95;A&#95;ATL ver** definida \<em atldef. h > como um literal inteiro que codifica o número de versão da ATL.

- **&#95;O&#95;MFC ver** definido \<em afxver_. h > como um literal inteiro que codifica o número de versão do MFC.

## <a name="see-also"></a>Consulte também

[Macros (C/C++)](../preprocessor/macros-c-cpp.md)<br/>
[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)<br/>
[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)