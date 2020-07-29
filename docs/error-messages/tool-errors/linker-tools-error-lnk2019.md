---
title: Erro das Ferramentas de Vinculador LNK2019
description: Tudo sobre a Microsoft Visual Studio erro do vinculador LNK2019 e como diagnosticar e corrigi-lo em código C e C++.
ms.date: 01/15/2020
f1_keywords:
- LNK2019
helpviewer_keywords:
- nochkclr.obj
- LNK2019
- _check_commonlanguageruntime_version
no-loc:
- ':::no-loc(main):::'
- ':::no-loc(WinMain):::'
- ':::no-loc(wmain):::'
- ':::no-loc(wWinMain):::'
- ':::no-loc(__cdecl):::'
- ':::no-loc(__stdcall):::'
- ':::no-loc(__fastcall):::'
- ':::no-loc(__vectorcall):::'
- ':::no-loc(extern):::'
- ':::no-loc(static):::'
- ':::no-loc(const):::'
- ':::no-loc(ARCH):::'
- ':::no-loc(AVX2):::'
- ':::no-loc(wchar_t):::'
- ':::no-loc(VERBOSE):::'
- ':::no-loc(EXPORTS):::'
- ':::no-loc(SYMBOLS):::'
- ':::no-loc(DUMPBIN):::'
- ':::no-loc(UNDNAME):::'
ms.openlocfilehash: b83ed3663e6b199e0f3384f6d30cb1c87c0e52c4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219801"
---
# <a name="linker-tools-error-lnk2019"></a>Erro das Ferramentas de Vinculador LNK2019

> :::no-loc(extern):::símbolo Al '*Symbol*' não resolvido referenciado na função '*Function*'

O código compilado para a *função* faz uma referência ou uma chamada para *símbolo*, mas o vinculador não consegue localizar a definição de símbolo em nenhuma das bibliotecas ou arquivos de objeto a serem vinculados.

Essa mensagem de erro é seguida pelo erro fatal [LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md). Para corrigir o erro LNK1120, você deve corrigir todos os erros de LNK2001 e LNK2019 primeiro.

## <a name="possible-causes"></a>Possíveis causas

Há várias maneiras de obter esse erro. Todos eles envolvem uma referência a uma função ou variável que o vinculador não pôde *resolver*, ou encontrar uma definição para. O compilador pode identificar quando um símbolo não é *declarado*, mas não pode dizer quando o símbolo não está *definido*. Isso ocorre porque a definição pode estar em um arquivo ou biblioteca de origem diferente. Se um símbolo for chamado, mas nunca definido, o vinculador gerará um erro de :::no-loc(extern)::: símbolo Al não resolvido.

Aqui estão alguns problemas comuns que causam LNK2019:

### <a name="the-source-file-that-contains-the-definition-of-the-symbol-isnt-compiled"></a>O arquivo de origem que contém a definição do símbolo não é compilado

No Visual Studio, verifique se o arquivo de origem que define o símbolo é compilado como parte do seu projeto. Verifique o diretório de saída do Build intermediário para obter um arquivo. obj correspondente. Se o arquivo de origem não for compilado, clique com o botão direito do mouse no arquivo em Gerenciador de Soluções e escolha **Propriedades** para verificar as propriedades do arquivo. A página geral de **Propriedades de configuração**  >  **General** deve mostrar um **tipo de item** do **compilador C/C++**. Na linha de comando, verifique se o arquivo de origem que contém a definição foi compilado.

### <a name="the-object-file-or-library-that-contains-the-definition-of-the-symbol-isnt-linked"></a>O arquivo de objeto ou a biblioteca que contém a definição do símbolo não está vinculado

No Visual Studio, verifique se o arquivo de objeto ou a biblioteca que contém a definição de símbolo está vinculada como parte do seu projeto. Na linha de comando, verifique se a lista de arquivos a serem vinculados inclui o arquivo de objeto ou a biblioteca.

### <a name="the-declaration-of-the-symbol-isnt-spelled-the-same-as-the-definition-of-the-symbol"></a>A declaração do símbolo não é escrita da mesma forma que a definição do símbolo

Verifique se você usa a grafia correta e a capitalização na declaração e na definição, e onde quer que o símbolo seja usado ou chamado.

### <a name="a-function-is-used-but-the-type-or-number-of-the-parameters-dont-match-the-function-definition"></a>Uma função é usada, mas o tipo ou o número dos parâmetros não correspondem à definição da função

A declaração da função deve corresponder à definição. Verifique se a chamada de função corresponde à declaração e se a declaração corresponde à definição. O código que invoca as funções de modelo também deve ter declarações de função de modelo correspondentes que incluam os mesmos parâmetros de modelo que a definição. Para obter um exemplo de uma incompatibilidade de declaração de modelo, consulte Sample LNK2019e. cpp na seção de exemplos.

### <a name="a-function-or-variable-is-declared-but-not-defined"></a>Uma função ou variável é declarada mas não definida

LNK2019 pode ocorrer quando uma declaração existe em um arquivo de cabeçalho, mas nenhuma definição correspondente é implementada. Para funções de membro ou :::no-loc(static)::: membros de dados, a implementação deve incluir o seletor de escopo de classe. Para obter um exemplo, consulte [faltando o corpo da função ou a variável](../../error-messages/tool-errors/missing-function-body-or-variable.md).

### <a name="the-calling-convention-is-different-between-the-function-declaration-and-the-function-definition"></a>A Convenção de chamada é diferente entre a declaração da função e a definição da função

As convenções de chamada ( [:::no-loc(__cdecl):::](../../cpp/cdecl.md) , [:::no-loc(__stdcall):::](../../cpp/stdcall.md) , [:::no-loc(__fastcall):::](../../cpp/fastcall.md) ou [:::no-loc(__vectorcall):::](../../cpp/vectorcall.md) ) são codificadas como parte do nome decorado. Verifique se a Convenção de chamada é a mesma.

### <a name="a-symbol-is-defined-in-a-c-file-but-declared-without-using-no-locextern-c-in-a-c-file"></a>Um símbolo é definido em um arquivo C, mas declarado sem usar :::no-loc(extern)::: "C" em um arquivo C++

Os símbolos definidos em um arquivo compilado como C têm nomes decorados diferentes dos símbolos declarados em um arquivo C++, a menos que você use um modificador [ :::no-loc(extern)::: "C"](../../cpp/using-:::no-loc(extern):::-to-specify-linkage.md) . Verifique se a declaração corresponde ao vínculo de compilação para cada símbolo. Da mesma forma, se você definir um símbolo em um arquivo C++ que será usado por um programa C, use `:::no-loc(extern)::: "C"` na definição.

### <a name="a-symbol-is-defined-as-no-locstatic-and-then-later-referenced-outside-the-file"></a>Um símbolo é definido como :::no-loc(static)::: e depois referenciado fora do arquivo

Em C++, ao contrário de C, os [ :::no-loc(const)::: Ants globais](../../error-messages/tool-errors/global-:::no-loc(const):::ants-in-cpp.md) têm o **`:::no-loc(static):::`** vínculo. Para contornar essa limitação, você pode incluir as **`:::no-loc(const):::`** inicializações em um arquivo de cabeçalho e incluir esse cabeçalho em seus arquivos. cpp ou pode tornar a variável não :::no-loc(const)::: Ant e usar uma :::no-loc(const)::: referência Ant para acessá-la.

### <a name="a-no-locstatic-member-of-a-class-isnt-defined"></a>Um :::no-loc(static)::: membro de uma classe não está definido

Um :::no-loc(static)::: membro de classe deve ter uma definição exclusiva ou violará a regra de uma definição. Um :::no-loc(static)::: membro de classe que não pode ser definido em linha deve ser definido em um arquivo de origem usando seu nome totalmente qualificado. Se não estiver definido, o vinculador gerará LNK2019.

### <a name="a-build-dependency-is-only-defined-as-a-project-dependency-in-the-solution"></a>Uma dependência de compilação só é definida como uma dependência de projeto na solução

Em versões anteriores do Visual Studio, esse nível de dependência era suficiente. No entanto, a partir do Visual Studio 2010, o Visual Studio requer uma [referência projeto-para-projeto](/visualstudio/ide/managing-references-in-a-project). Se o seu projeto não tiver uma referência de projeto para projeto, você poderá receber esse erro de vinculador. Adicione uma referência projeto-para-projeto para corrigi-lo.

### <a name="an-entry-point-isnt-defined"></a>Um ponto de entrada não está definido

O código do aplicativo deve definir um ponto de entrada apropriado: `:::no-loc(main):::` ou para aplicativos de `:::no-loc(wmain):::` console e `:::no-loc(WinMain):::` ou `:::no-loc(wWinMain):::` para aplicativos do Windows. Para obter mais informações, consulte [ :::no-loc(main)::: função e argumentos de linha de comando](../../cpp/:::no-loc(main):::-function-command-line-args.md) ou [ :::no-loc(WinMain)::: função](/windows/win32/api/winbase/nf-winbase-win:::no-loc(main):::). Para usar um ponto de entrada personalizado, especifique a opção de vinculador [/Entry (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) .

### <a name="you-build-a-console-application-by-using-settings-for-a-windows-application"></a>Você cria um aplicativo de console usando as configurações para um aplicativo do Windows

Se a mensagem de erro for semelhante ao ** :::no-loc(extern)::: símbolo Al não resolvido :::no-loc(WinMain)::: referenciado na função** *function_name*, vincule usando **/SUBSYSTEM: console** em vez de **/SUBSYSTEM: Windows**. Para obter mais informações sobre essa configuração e obter instruções sobre como definir essa propriedade no Visual Studio, consulte [/Subsystem (especificar subsistema)](../../build/reference/subsystem-specify-subsystem.md).

### <a name="you-attempt-to-link-64-bit-libraries-to-32-bit-code-or-32-bit-libraries-to-64-bit-code"></a>Você tenta vincular bibliotecas de 64 bits a código de 32 bits ou bibliotecas de 32 bits ao código de 64 bits

Bibliotecas e arquivos de objeto vinculados ao seu código devem ser compilados para a mesma arquitetura que seu código. Verifique se as bibliotecas às quais suas referências de projeto são compiladas para a mesma arquitetura que o seu projeto. Verifique se a propriedade de **diretórios de biblioteca** [/LIBPATH](../../build/reference/libpath-additional-libpath.md) ou adicional aponta para bibliotecas criadas para a arquitetura correta.

### <a name="you-use-different-compiler-options-for-function-inlining-in-different-source-files"></a>Você usa opções de compilador diferentes para o inlinear funções em diferentes arquivos de origem

O uso de funções embutidas definidas em arquivos. cpp e na combinação de opções do compilador de entrada de função em arquivos de origem diferentes pode causar LNK2019. Para obter mais informações, consulte [problemas de inalinhamento de função](../../error-messages/tool-errors/function-inlining-problems.md).

### <a name="you-use-automatic-variables-outside-their-scope"></a>Você usa variáveis automáticas fora de seu escopo

Variáveis automáticas (escopo de função) só podem ser usadas no escopo dessa função. Essas variáveis não podem ser declaradas **`:::no-loc(extern):::`** e usadas em outros arquivos de origem. Para obter um exemplo, consulte [variáveis automáticas (escopo de função)](../../error-messages/tool-errors/automatic-function-scope-variables.md).

### <a name="you-call-intrinsic-functions-or-pass-argument-types-to-intrinsic-functions-that-arent-supported-on-your-target-architecture"></a>Você chama funções intrínsecas ou passa tipos de argumentos para funções intrínsecas que não têm suporte na sua arquitetura de destino

Por exemplo, se você usar um :::no-loc(AVX2)::: intrínseco, mas não especificar a opção [ / :::no-loc(ARCH)::: :::no-loc(AVX2)::: :](../../build/reference/arch-x86.md) compilador, o compilador pressupõe que o intrínseco é uma :::no-loc(extern)::: função al. Em vez de gerar uma instrução embutida, o compilador gera uma chamada para um :::no-loc(extern)::: símbolo Al com o mesmo nome que o intrínseco. Quando o vinculador tenta localizar a definição dessa função ausente, ele gera LNK2019. Certifique-se de usar somente intrínsecos e tipos com suporte na sua arquitetura de destino.

### <a name="you-mix-code-that-uses-native-no-locwchar_t-with-code-that-doesnt"></a>Você mistura código que usa nativo :::no-loc(wchar_t)::: com código que não

O trabalho de conformidade da linguagem C++ que foi feito no Visual Studio 2005 tornou **`:::no-loc(wchar_t):::`** um tipo nativo por padrão. Se nem todos os arquivos tiverem sido compilados usando o mesmo **/Zc :::no-loc(wchar_t)::: :** configurações, referências de tipo podem não ser resolvidas para tipos compatíveis. Verifique se **`:::no-loc(wchar_t):::`** os tipos em todos os arquivos de biblioteca e de objeto são compatíveis. Atualize de um **`:::no-loc(wchar_t):::`** typedef ou use as configurações consistentes de **/Zc: :::no-loc(wchar_t)::: ** ao compilar.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e vcpkg

Se você vir esse erro ao tentar configurar uma biblioteca de terceiros como parte de sua compilação, considere usar o [vcpkg](../../vcpkg.md), um Gerenciador de pacotes do C++, para instalar e criar a biblioteca. o vcpkg dá suporte a uma lista grande e crescente [de bibliotecas de](https://github.com/Microsoft/vcpkg/tree/master/ports)terceiros. Ele define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto.

## <a name="diagnosis-tools"></a>Ferramentas de diagnóstico

Às vezes, é difícil dizer por que o vinculador não consegue encontrar uma definição de símbolo específica. Geralmente, o problema é que você não incluiu o código que contém a definição em sua compilação. Ou, as opções de compilação criaram nomes decorados diferentes para os :::no-loc(extern)::: símbolos al. Há várias ferramentas e opções que podem ajudá-lo a diagnosticar erros LNK2019.

- A [/:::no-loc(VERBOSE):::](../../build/reference/verbose-print-progress-messages.md) opção de vinculador pode ajudá-lo a determinar quais arquivos são referenciados pelo vinculador. Essa opção pode ajudá-lo a verificar se o arquivo que contém a definição do símbolo está incluído em seu Build.

- As [/:::no-loc(EXPORTS):::](../../build/reference/dash-exports.md) [/:::no-loc(SYMBOLS):::](../../build/reference/symbols.md) Opções e do **:::no-loc(DUMPBIN):::** utilitário podem ajudá-lo a descobrir quais símbolos são definidos nos arquivos. dll e de objeto ou biblioteca. Verifique se os nomes decorados exportados correspondem aos nomes decorados que o vinculador pesquisa.

- O **:::no-loc(UNDNAME):::** utilitário pode mostrar o símbolo Al não decorado equivalente :::no-loc(extern)::: para um nome decorado.

## <a name="examples"></a>Exemplos

Aqui estão vários exemplos de código que causa um erro de LNK2019, junto com informações sobre como corrigir o erro.

### <a name="a-symbol-is-declared-but-not-defined"></a>Um símbolo é declarado mas não definido

Neste exemplo, uma :::no-loc(extern)::: variável Al é declarada, mas não definida:

```cpp
// LNK2019.cpp
// Compile by using: cl /EHsc /W4 LNK2019.cpp
// LNK2019 expected
:::no-loc(extern)::: char B[100];   // B isn't available to the linker
int :::no-loc(main):::() {
   B[0] = ' ';   // LNK2019
}
```

Aqui está outro exemplo em que uma variável e uma função são declaradas **`:::no-loc(extern):::`** , mas nenhuma definição é fornecida:

```cpp
// LNK2019c.cpp
// Compile by using: cl /EHsc LNK2019c.cpp
// LNK2019 expected
:::no-loc(extern)::: int i;
:::no-loc(extern)::: void g();
void f() {
   i++;
   g();
}
int :::no-loc(main):::() {}
```

A menos que `i` e `g` sejam definidos em um dos arquivos incluídos na compilação, o vinculador gera LNK2019. Você pode corrigir os erros incluindo o arquivo de código-fonte que contém as definições como parte da compilação. Como alternativa, você pode passar arquivos. obj ou arquivos. lib que contêm as definições para o vinculador.

### <a name="a-no-locstatic-data-member-is-declared-but-not-defined"></a>Um :::no-loc(static)::: membro de dados é declarado mas não definido

LNK2019 também pode ocorrer quando um :::no-loc(static)::: membro de dados é declarado, mas não definido. O exemplo a seguir gera LNK2019 e mostra como corrigi-lo.

```cpp
// LNK2019b.cpp
// Compile by using: cl /EHsc LNK2019b.cpp
// LNK2019 expected
struct C {
   :::no-loc(static)::: int s;
};

// Uncomment the following line to fix the error.
// int C::s;

int :::no-loc(main):::() {
   C c;
   C::s = 1;
}
```

### <a name="declaration-parameters-dont-match-the-definition"></a>Os parâmetros de declaração não correspondem à definição

O código que invoca funções de modelo deve ter declarações de função de modelo correspondentes. As declarações devem incluir os mesmos parâmetros de modelo que a definição. O exemplo a seguir gera LNK2019 em um operador definido pelo usuário e mostra como corrigi-lo.

```cpp
// LNK2019e.cpp
// compile by using: cl /EHsc LNK2019e.cpp
// LNK2019 expected
#include <iostream>
using namespace std;

template<class T> class
Test {
   // The operator<< declaration doesn't match the definition below:
   friend ostream& operator<<(ostream&, Test&);
   // To fix, replace the line above with the following:
   // template<typename T> friend ostream& operator<<(ostream&, Test<T>&);
};

template<typename T>
ostream& operator<<(ostream& os, Test<T>& tt) {
   return os;
}

int :::no-loc(main):::() {
   Test<int> t;
   cout << "Test: " << t << endl;   // LNK2019 unresolved :::no-loc(extern):::al
}
```

### <a name="inconsistent-no-locwchar_t-type-definitions"></a>Definições de tipo inconsistentes :::no-loc(wchar_t):::

Este exemplo cria uma DLL que tem uma exportação que usa `WCHAR` , que é resolvida para **`:::no-loc(wchar_t):::`** .

```cpp
// LNK2019g.cpp
// compile with: cl /EHsc /LD LNK2019g.cpp
#include "windows.h"
// WCHAR resolves to :::no-loc(wchar_t):::
__declspec(dllexport) void func(WCHAR*) {}
```

O exemplo a seguir usa a DLL no exemplo anterior e gera LNK2019 porque os tipos `unsigned short*` e `WCHAR*` não são os mesmos.

```cpp
// LNK2019h.cpp
// compile by using: cl /EHsc LNK2019h LNK2019g.lib
// LNK2019 expected
__declspec(dllimport) void func(unsigned short*);

int :::no-loc(main):::() {
   func(0);
}
```

Para corrigir esse erro, altere **`unsigned short`** para **`:::no-loc(wchar_t):::`** ou ou `WCHAR` compile LNK2019g. cpp usando **/Zc: :::no-loc(wchar_t)::: - **.

## <a name="additional-resources"></a>Recursos adicionais

Para obter mais informações sobre possíveis causas e soluções para LNK2001, consulte a Stack Overflow pergunta [o que é um erro de símbolo de referência indefinido/não resolvido :::no-loc(extern)::: e como corrigi-lo?](https://stackoverflow.com/q/12573816/2002113).
