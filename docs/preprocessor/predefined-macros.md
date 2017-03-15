---
title: "Macros predefinidas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_ATL_VER"
  - "__ATOM__"
  - "__AVX__"
  - "__AVX2__"
  - "_CHAR_UNSIGNED"
  - "__CLR_VER"
  - "_CONTROL_FLOW_GUARD"
  - "__COUNTER__"
  - "__cplusplus"
  - "__cplusplus_cli"
  - "__cplusplus_winrt"
  - "_CPPRTTI"
  - "_CPPUNWIND"
  - "__DATE__"
  - "_DEBUG"
  - "_DLL"
  - "__FILE__"
  - "__FUNCDNAME__"
  - "__FUNCSIG__"
  - "__FUNCTION__"
  - "_INTEGRAL_MAX_BITS"
  - "_ISO_VOLATILE"
  - "_KERNEL_MODE"
  - "__LINE__"
  - "_M_AMD64"
  - "_M_ARM"
  - "_M_ARM_ARMV7VE"
  - "_M_ARM_FP"
  - "_M_ARM64"
  - "_M_CEE"
  - "_M_CEE_PURE"
  - "_M_CEE_SAFE"
  - "_M_FP_EXCEPT"
  - "_M_FP_FAST"
  - "_M_FP_PRECISE"
  - "_M_FP_STRICT"
  - "_M_IX86"
  - "_M_IX86_FP"
  - "_M_X64"
  - "_MANAGED"
  - "_MFC_VER"
  - "_MSC_BUILD"
  - "_MSC_EXTENSIONS"
  - "_MSC_FULL_VER"
  - "_MSC_VER"
  - "_MSVC_LANG"
  - "__MSVC_RUNTIME_CHECKS"
  - "_MT"
  - "_NATIVE_WCHAR_T_DEFINED"
  - "_NO_SIZED_DEALLOCATION"
  - "_OPENMP"
  - "_PREFAST_"
  - "_RESUMABLE_FUNCTIONS_SUPPORTED"
  - "_RTC_CONVERSION_CHECKS_ENABLED"
  - "__STDC__"
  - "__STDC_HOSTED__"
  - "__STDCPP_THREADS__"
  - "__TIME__"
  - "__TIMESTAMP__"
  - "__VA_ARGS__"
  - "_VC_NODEFAULTLIB"
  - "_WCHAR_T_DEFINED"
  - "_WIN32"
  - "_WIN64"
  - "_WINRT_DLL"
  - "__func__"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "carimbos de hora, macro de pré-processador"
  - "compilador cl.exe, número de versão"
  - "números de versão, o compilador C/C++ (cl.exe)"
  - "macros, C++ predefinido"
  - "macros de pré-processador,"
  - "macros predefinidas"
  - "Macro _ATL_VER"
  - "Macro __ATOM__"
  - "__AVX__ macro"
  - "__AVX2__ macro"
  - "Macro _CHAR_UNSIGNED"
  - "Macro __CLR_VER"
  - "Macro _CONTROL_FLOW_GUARD"
  - "Macro __COUNTER__"
  - "Macro __cplusplus"
  - "__cplusplus_cli macro"
  - "__cplusplus_winrt macro"
  - "Macro _CPPRTTI"
  - "Macro _CPPUNWIND"
  - "Macro __DATE__"
  - "Macro _DEBUG"
  - "Macro _DLL"
  - "Macro __FILE__"
  - "Macro __FUNCDNAME__"
  - "Macro __FUNCSIG__"
  - "Macro __FUNCTION__"
  - "Macro _INTEGRAL_MAX_BITS"
  - "Macro _ISO_VOLATILE"
  - "Macro _KERNEL_MODE"
  - "Macro __LINE__"
  - "_M_AMD64 macro"
  - "_M_ARM macro"
  - "Macro _M_ARM_ARMV7VE"
  - "_M_ARM_FP macro"
  - "Macro _M_ARM64"
  - "Macro _M_CEE"
  - "Macro _M_CEE_PURE"
  - "Macro _M_CEE_SAFE"
  - "Macro _M_FP_EXCEPT"
  - "Macro _M_FP_FAST"
  - "Macro _M_FP_PRECISE"
  - "Macro _M_FP_STRICT"
  - "Macro _M_IX86"
  - "Macro _M_IX86_FP"
  - "Macro _M_X64"
  - "Macro _MANAGED"
  - "Macro _MFC_VER"
  - "Macro _MSC_BUILD"
  - "Macro _MSC_EXTENSIONS"
  - "macro _MSC_FULL_VER"
  - "Macro _MSC_VER"
  - "Macro _MSVC_LANG"
  - "Macro __MSVC_RUNTIME_CHECKS"
  - "Macro _MT"
  - "Macro _NATIVE_WCHAR_T_DEFINED"
  - "Macro _NO_SIZED_DEALLOCATION"
  - "Macro _OPENMP"
  - "Macro _PREFAST_"
  - "Macro _RESUMABLE_FUNCTIONS_SUPPORTED"
  - "Macro _RTC_CONVERSION_CHECKS_ENABLED"
  - "Macro __STDC__"
  - "Macro __STDC_HOSTED__"
  - "Macro __STDCPP_THREADS__"
  - "Macro __TIME__"
  - "Macro __TIMESTAMP__"
  - "Macro __VA_ARGS__"
  - "Macro _VC_NODEFAULTLIB"
  - "Macro _WCHAR_T_DEFINED"
  - "Macro _WIN32"
  - "Macro _WIN64"
  - "Macro _WINRT_DLL"
  - "Identificador de __func__"
ms.assetid: 1cc5f70a-a225-469c-aed0-fe766238e23f
caps.latest.revision: 75
caps.handback.revision: 75
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macros predefinidas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O compilador do Visual C++ predefine determinadas macros de pré-processador, dependendo da linguagem (C ou C++), o destino de compilação e as opções do compilador escolhido.  
  
 Visual C++ oferece suporte as macros de pré-processador predefinidas necessário especificadas pelo padrão ANSI/ISO C99 e ISO C++ 14 padrão. A implementação também oferece suporte a várias macros de pré-processador específico da Microsoft mais. Algumas macros são definidas somente para ambientes de compilação específica ou opções do compilador. A menos que observado, as macros são definidas em uma unidade de conversão, como se eles foram especificados como **/D** argumentos de opção de compilador. Quando definido, as macros são expandidas com os valores especificados pelo pré-processador antes da compilação. Macros predefinidas não usam argumentos e não podem ser redefinidas.  
  
## <a name="standard-predefined-identifier"></a>Padrão de identificador predefinido  
 O compilador dá suporte a esse identificador predefinido especificado pela ISO C++ 11 e ISO C99.  
  
-   **__func\_\_** o nome qualificado e não adornado da função como uma função local `static``const` matriz de `char`.  
  
    ```cpp  
    void example(){  
        printf("%s\n", __func__);  
    } // prints "example"  
    ```  
  
## <a name="standard-predefined-macros"></a>Macros predefinidas padrão  
 O compilador suporta essas macros predefinidas especificadas pela ISO C99 padrões e ISO C + + 14.  
  
-   **cplusplus** definido como um valor literal inteiro quando a unidade de tradução é compilada como C++. Caso contrário, indefinido.  
  
-   **__DATE\_\_** a data de compilação do arquivo de origem atual. A data é uma cadeia de caracteres constante literal do formulário *Mmm dd aaaa*. O nome do mês *Mmm* é o mesmo que o nome do mês abreviado em datas geradas pela biblioteca de tempo de execução do C [asctime](../c-runtime-library/reference/asctime-wasctime.md) função. O primeiro caractere da data *dd* é um espaço se o valor for menor que 10. Essa macro é sempre definida.  
  
-   **__FILE\_\_** o nome do arquivo de origem atual. **__FILE\_\_** se expande para uma cadeia de caracteres literal. Para garantir que o caminho completo para o arquivo é exibido, use [/FC (completo caminho do arquivo de código fonte no diagnóstico)](../Topic/-FC%20\(Full%20Path%20of%20Source%20Code%20File%20in%20Diagnostics\).md). Essa macro é sempre definida.  
  
-   **__LINE\_\_** definido como o número da linha inteiro no arquivo de origem atual. O valor de **__LINE\_\_** macro pode ser alterada usando um `#line` diretiva. Essa macro é sempre definida.  
  
-   **__STDC\_\_** definido como 1 somente quando compilado como C e se o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador é especificada. Caso contrário, indefinido.  
  
-   **__STDC_HOSTED\_\_** definido como 1 se a implementação é um *hospedado implementação*, que oferece suporte a biblioteca inteira de padrão necessário. Caso contrário, definida como 0.  
  
-   **__STDCPP_THREADS\_\_** definido como 1 se e somente se um programa pode ter mais de um thread de execução e compilados como C++. Caso contrário, indefinido.  
  
-   **__TIME\_\_** o tempo de tradução de unidade de tradução pré-processado. O tempo é uma cadeia de caracteres literal do formulário *hh*, o mesmo que o tempo retornado pela biblioteca de tempo de execução do C [asctime](../c-runtime-library/reference/asctime-wasctime.md) função. Essa macro é sempre definida.  
  
## <a name="microsoft-specific-predefined-macros"></a>Macros predefinidas específicas da Microsoft  
 Microsoft Visual C++ oferece suporte a essas macros predefinidas adicionais.  
  
-   **__ATOM\_\_** definido como 1 quando o [/favor:ATOM](../build/reference/favor-optimize-for-architecture-specifics.md) é definir a opção de compilador e o destino do compilador é x86 ou x64. Caso contrário, indefinido.  
  
-   **__AVX\_\_** definido como 1 quando o [avx](../build/reference/arch-x86.md) ou [avx2](../build/reference/arch-x86.md) Opções do compilador são definidas e o destino do compilador é x86 ou x64. Caso contrário, indefinido.  
  
-   **__AVX2\_\_** definido como 1 quando o [avx2](../build/reference/arch-x86.md) é definir a opção de compilador e o destino do compilador é x86 ou x64. Caso contrário, indefinido.  
  
-   **Char_unsigned** definido como 1 se o padrão `char` tipo é assinado. Isso é definido quando o [/J (char padrão não é do tipo assinado)](../build/reference/j-default-char-type-is-unsigned.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **Clr_ver** definido como um literal de inteiro que representa a versão do common language runtime usado quando o aplicativo foi compilado. O valor é codificado no formato `Mmmbbbbb`, onde `M` é a versão principal do tempo de execução, `mm` é a versão secundária do tempo de execução, e `bbbbb` é o número de compilação. **Clr_ver** é definida se o [/clr](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
    ```cpp  
    // clr_ver.cpp  
    // compile with: /clr  
    using namespace System;  
    int main() {  
       Console::WriteLine(__CLR_VER);  
    }  
    ```  
  
-   **_CONTROL_FLOW_GUARD** definido como 1 quando o [/guard:cf (habilitar o controle de fluxo de proteção)](../build/reference/guard-enable-control-flow-guard.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **__COUNTER\_\_** Expands para um literal inteiro que começa em 0 e é incrementado em 1 sempre que ele é usado em um arquivo de origem ou cabeçalhos do arquivo de origem incluídos. **__COUNTER\_\_** lembra seu estado quando você usa cabeçalhos pré-compilados. Essa macro é sempre definida.  
  
     Este exemplo usa `__COUNTER__` para atribuir identificadores exclusivos para três objetos diferentes do mesmo tipo. O `exampleClass` construtor aceita um inteiro como um parâmetro. Em `main`, o aplicativo declara três objetos do tipo `exampleClass`, usando `__COUNTER__` como o parâmetro identificador exclusivo:  
  
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
  
-   **cplusplus_cli** definido como o valor de literal de inteiro 200406 quando compilado c++ e o [/clr](../build/reference/clr-common-language-runtime-compilation.md), [/clr: puro](../build/reference/clr-common-language-runtime-compilation.md), ou [/CLR: safe](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido. Quando definido, **cplusplus_cli** é aplicado em toda a unidade de conversão.  
  
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
  
-   **cplusplus_winrt** definido como o valor de literal de inteiro 201009 quando compilado c++ e o [/ZW (compilação de tempo de execução do Windows)](../build/reference/zw-windows-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **Cpprtti** definido como 1 se o [/GR (Habilitar informações de tipo em tempo de execução)](../Topic/-GR%20\(Enable%20Run-Time%20Type%20Information\).md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **Cppunwind** definido como 1 se um ou mais o [/GX (habilitar tratamento de exceções)](../Topic/-GX%20\(Enable%20Exception%20Handling\).md), [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md), ou [/EH (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md) Opções do compilador são definidas. Caso contrário, indefinido.  
  
-   **Debug** definido como 1 quando o [/LDd](../build/reference/md-mt-ld-use-run-time-library.md), [/MDd](../build/reference/md-mt-ld-use-run-time-library.md), ou [/MTd](../build/reference/md-mt-ld-use-run-time-library.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **Dll** definido como 1 quando o [/MD](../build/reference/md-mt-ld-use-run-time-library.md) ou [/MDd](../build/reference/md-mt-ld-use-run-time-library.md) opção de compilador (Multithreaded DLL) está definida. Caso contrário, indefinido.  
  
-   **__FUNCDNAME\_\_** definido como uma cadeia de caracteres literal que contém o [nome decorado](../Topic/Decorated%20Names.md) da função. A macro é definida apenas dentro de uma função. O **__FUNCDNAME\_\_** macro não é expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) opção de compilador.  
  
     Este exemplo usa o `__FUNCDNAME__`, `__FUNCSIG__`, e `__FUNCTION__` macros para exibir informações de função.  
  
     [!code-cpp[NVC_Predefined_Macros_Examples#1](../preprocessor/codesnippet/CPP/predefined-macros_1.cpp)]  
  
-   **__FUNCSIG\_\_** definido como uma cadeia de caracteres literal que contém a assinatura da função. A macro é definida apenas dentro de uma função. O **__FUNCSIG\_\_** macro não é expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) opção de compilador. Quando compilado para um destino de 64 bits, a convenção de chamada é `__cdecl` por padrão. Para obter um exemplo de uso, consulte o `__FUNCDNAME__` macro.  
  
-   **__FUNCTION\_\_** definido como uma cadeia de caracteres literal que contém o nome não decorado da função. A macro é definida apenas dentro de uma função. O **__FUNCTION\_\_** macro não é expandida se você usar o [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) ou [/p](../build/reference/p-preprocess-to-a-file.md) opção de compilador. Para obter um exemplo de uso, consulte o `__FUNCDNAME__` macro.  
  
-   **Integral_max_bits** definido como o valor de literal de inteiro 64, o tamanho máximo (em bits) para um tipo de vetor não integral. Essa macro é sempre definida.  
  
    ```cpp  
    // integral_max_bits.cpp  
    #include <stdio.h>  
    int main() {  
       printf("%d\n", _INTEGRAL_MAX_BITS);  
    }  
    ```  
  
-   **__INTELLISENSE\_\_** definido como 1 durante um compilador IntelliSense passar no IDE do Visual Studio. Caso contrário, indefinido. Você pode usar essa macro para proteger o código que o compilador IntelliSense não compreender ou usá-lo para alternar entre a compilação e o compilador do IntelliSense. Para obter mais informações, consulte [dicas de solução de problemas de lentidão do IntelliSense](https://blogs.msdn.microsoft.com/vcblog/2011/03/29/troubleshooting-tips-for-intellisense-slowness/).  
  
-   **_ISO_VOLATILE** definido como 1 se o [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **_KERNEL_MODE** definido como 1 se o [/kernel (criar binário do modo Kernel)](../build/reference/kernel-create-kernel-mode-binary.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **_M_AMD64** definido como 100 para compilações de valor do literal de inteiro que processadores x64. Caso contrário, indefinido.  
  
-   **_M_ARM** definido como o valor literal de inteiro 7 de compilações que processadores ARM de destino. Caso contrário, indefinido.  
  
-   **_M_ARM_ARMV7VE** definido como 1 quando o [armv7ve](../build/reference/arch-arm.md) opção de compilador é definida para compilações voltados para processadores ARM. Caso contrário, indefinido.  
  
-   **_M_ARM_FP** definido como um valor literal de inteiro que indica quais [/arch](../build/reference/arch-arm.md) opção de compilador foi definida, se o destino de compilação é um processador ARM. Caso contrário, indefinido.  
  
    -   No intervalo 30-39 Se nenhum **/arch** ARM opção foi especificada, indicando que a arquitetura padrão do ARM foi definido (`VFPv3`).  
  
    -   No intervalo 40-49, se **vfpv4** foi definido.  
  
    -   Consulte [/arch (ARM)](../build/reference/arch-arm.md) para obter mais informações.  
  
-   **_M_ARM64** definido como 1 para compilações voltados para processadores ARM de 64 bits. Caso contrário, indefinido.  
  
-   **M_cee** definido como 001 se qualquer [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **M_cee_pure** definido como 001 se a [/clr: puro](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **M_cee_safe** definido como 001 se a [/CLR: safe](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **_M_FP_EXCEPT** definido como 1 se o [/fp: exceto](../build/reference/fp-specify-floating-point-behavior.md) ou [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **_M_FP_FAST** definido como 1 se o [/fp:fast](../build/reference/fp-specify-floating-point-behavior.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **_M_FP_PRECISE** definido como 1 se o [/fp: preciso](../build/reference/fp-specify-floating-point-behavior.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **_M_FP_STRICT** definido como 1 se o [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **M_ix86** definido como o literal de inteiro valor de 600 para compilações que processadores x86. Essa macro não está definida para x64 ou destinos de compilação do ARM.  
  
-   **_M_IX86_FP** definido como um valor literal de inteiro que indica o [/arch](../build/reference/arch-arm.md) opção de compilador que tiver sido definido, o padrão. Essa macro sempre é definida quando o destino de compilação é um x86 processador. Caso contrário, indefinido. Quando definido, o valor é:  
  
    -   0 se o **/arch:IA32** opção de compilador foi definida.  
  
    -   1 se o **/arch:SSE** opção de compilador foi definida.  
  
    -   2 se o **/arch:SSE2**, **avx** ou **avx2** opção de compilador foi definida. Esse valor é o padrão se um **/arch** opção de compilador não foi especificada. Quando **avx** for especificado, a macro **__AVX\_\_** também é definida. Quando **avx2** for especificado, ambos **__AVX\_\_** e **__AVX2\_\_** também são definidos.  
  
    -   Consulte [/arch (x86)](../build/reference/arch-x86.md) para obter mais informações.  
  
-   **M_x64** definido como 100 para compilações de valor do literal de inteiro que processadores x64. Caso contrário, indefinido.  
  
-   **Managed** definido como 1 quando o [/clr](../build/reference/clr-common-language-runtime-compilation.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **Msc_build** definido como um literal de inteiro que contém o elemento de número de revisão do número de versão do compilador. O número de revisão é o quarto elemento do número de versão delimitado por período. Por exemplo, se o número da versão do compilador do Visual C++ for 15.00.20706.01, o **msc_build** macro é avaliado como 1. Essa macro é sempre definida.  
  
-   **Msc_extensions** definido como 1 se o [/Ze (habilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) opção de compilador estiver definida, o que é o padrão. Caso contrário, indefinido.  
  
-   **Msc_full_ver** definido como um literal de inteiro que codifica o principal, secundária e criar elementos de número do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitados, o número secundário é o segundo elemento e o número de compilação é o terceiro elemento. Por exemplo, se o número da versão do compilador do Visual C++ for 15.00.20706.01, o **msc_full_ver** macro será avaliada em 150020706. Digite **cl /?** na linha de comando para exibir o número da versão do compilador. Essa macro é sempre definida.  
  
-   **Msc_ver** definido como um literal de inteiro que codifica os elementos de número principais e secundários do número de versão do compilador. O número principal é o primeiro elemento do número de versão delimitada por ponto e o número secundário é o segundo elemento. Por exemplo, se o número da versão do compilador do Visual C++ for 17.00.51106.1, o **msc_ver** macro será avaliada em 1700. Digite **cl /?** na linha de comando para exibir o número da versão do compilador. Essa macro é sempre definida.  
  
-   **_MSVC_LANG** definido como um literal de inteiro que especifica o padrão de linguagem C++ direcionado pelo compilador. Quando compilado c++, a macro é o valor de literal de inteiro 201402 se o [/std:c + + 14](../Topic/-std%20\(Specify%20Language%20Standard%20Version\).md) opção de compilador está definido, ou por padrão e é definida como um superior, não for especificado quando o [/std:c + + mais recente](../Topic/-std%20\(Specify%20Language%20Standard%20Version\).md) é definir a opção de compilador. Caso contrário, a macro será indefinida. O **_MSVC_LANG** macro e [/std (especificar versão padrão do idioma)](../Topic/-std%20\(Specify%20Language%20Standard%20Version\).md) Opções do compilador estão disponíveis a partir do Visual Studio 2015 atualização 3.  
  
-   **Msvc_runtime_checks** definido como 1 quando uma do [/RTC](../build/reference/rtc-run-time-error-checks.md) Opções do compilador está definido. Caso contrário, indefinido.  
  
-   **MT** definido como 1 quando [/MD ou /MDd](../build/reference/md-mt-ld-use-run-time-library.md) (Multithreaded DLL) ou [/MT ou /MTd](../build/reference/md-mt-ld-use-run-time-library.md) (Multithreaded) for especificado. Caso contrário, indefinido.  
  
-   **Native_wchar_t_defined** definido como 1 quando o [/ZC:](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **OpenMP** definida como inteiro literal 200203, que representa a data da especificação de OpenMP implementada pelo Visual C++, se o [/openmp (Habilitar suporte a OpenMP 2.0)](../build/reference/openmp-enable-openmp-2-0-support.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
    ```cpp  
    // _OPENMP_dir.cpp  
    // compile with: /openmp   
    #include <stdio.h>   
    int main() {  
       printf("%d\n", _OPENMP);  
    }  
    ```  
  
-   **_PREFAST\_** definido como 1 quando o [/Analyze](../build/reference/analyze-code-analysis.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **__TIMESTAMP\_\_** definido como uma cadeia de caracteres literal que contém a data e hora da última modificação do arquivo de origem atual, na forma abreviada, constante, comprimento retornado pela biblioteca de tempo de execução do C [asctime](../c-runtime-library/reference/asctime-wasctime.md) funcionar, por exemplo, `Fri 19 Aug 13:32:58 2016`. Essa macro é sempre definida.  
  
-   **Vc_nodefaultlib** definido como 1 quando o [/Zl (omitir a nome de biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) é definir a opção de compilador. Caso contrário, indefinido.  
  
-   **Wchar_t_defined** definido como 1 quando o padrão [/ZC:](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) é definir a opção de compilador. O **wchar_t_defined** macro é definida, mas não tem nenhum valor se o **/Zc:wchar_t-** é definir a opção de compilador, e `wchar_t` é definido em um arquivo de cabeçalho do sistema incluído em seu projeto. Caso contrário, indefinido.  
  
-   **Win32** definidos como 1 quando o destino de compilação é ARM 32 bits, 64 bits ARM, x86, ou x64. Caso contrário, indefinido.  
  
-   **Win64** definida como 1 quando o destino de compilação é ARM de 64 bits ou x64. Caso contrário, indefinido.  
  
-   **_WINRT_DLL** definido como 1 quando compilado como C++ e ambos [/ZW (compilação de tempo de execução do Windows)](../build/reference/zw-windows-runtime-compilation.md) e [/LD ou /LDd](../build/reference/md-mt-ld-use-run-time-library.md) Opções do compilador são definidas. Caso contrário, indefinido.  
  
 Macros de pré-processador usadas para determinar a versão da biblioteca MFC ou ATL não são predefinidas pelo compilador. Essas macros são definidas nos cabeçalhos da biblioteca, para que eles não estão definidos em diretivas de pré-processador antes do cabeçalho necessário está incluído.  
  
-   **Atl_ver** definidas em \< atldef.h > como um literal de inteiro que codifica o número da versão ATL.  
  
-   **Mfc_ver** definidas em \< afxver_.h > como um literal de inteiro que codifica o número de versão do MFC.  
  
## <a name="see-also"></a>Consulte também  
 [Macros (C/C++)](../Topic/Macros%20\(C-C++\).md)   
 [Operadores de pré-processador](../preprocessor/preprocessor-operators.md)   
 [Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)