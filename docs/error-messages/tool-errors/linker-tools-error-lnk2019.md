---
title: Erro das Ferramentas de Vinculador LNK2019
description: Tudo sobre a Microsoft Visual Studio erro do vinculador LNK2019 e como diagnosticar e corrigi-lo em C++ C e código.
ms.date: 01/15/2020
f1_keywords:
- LNK2019
helpviewer_keywords:
- nochkclr.obj
- LNK2019
- _check_commonlanguageruntime_version
no-loc:
- main
- WinMain
- wmain
- wWinMain
- __cdecl
- __stdcall
- __fastcall
- __vectorcall
- extern
- static
- const
- ARCH
- AVX2
- wchar_t
- VERBOSE
- EXPORTS
- SYMBOLS
- DUMPBIN
- UNDNAME
ms.openlocfilehash: 0e741c1442f9762c4cf5f9b891c4cd7c38103dfe
ms.sourcegitcommit: e93f3e6a110fe38bc642055bdf4785e620d4220f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2020
ms.locfileid: "76123910"
---
# <a name="linker-tools-error-lnk2019"></a>Erro das Ferramentas de Vinculador LNK2019

> símbolo externo '*Symbol*' não resolvido referenciado na função '*Function*'

O código compilado para a *função* faz uma referência ou uma chamada para *símbolo*, mas o vinculador não consegue localizar a definição de símbolo em nenhuma das bibliotecas ou arquivos de objeto a serem vinculados.

Essa mensagem de erro é seguida pelo erro fatal [LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md). Para corrigir o erro LNK1120, você deve corrigir todos os erros de LNK2001 e LNK2019 primeiro.

## <a name="possible-causes"></a>Causas possíveis

Há várias maneiras de obter esse erro. Todos eles envolvem uma referência a uma função ou variável que o vinculador não pôde *resolver*, ou encontrar uma definição para. O compilador pode identificar quando um símbolo não é *declarado*, mas não pode dizer quando o símbolo não está *definido*. Isso ocorre porque a definição pode estar em um arquivo ou biblioteca de origem diferente. Se um símbolo for referenciado, mas nunca definido, o vinculador gerará um erro de símbolo externo não resolvido.

Aqui estão alguns problemas comuns que causam LNK2019:

### <a name="the-source-file-that-contains-the-definition-of-the-symbol-isnt-compiled"></a>O arquivo de origem que contém a definição do símbolo não é compilado

No Visual Studio, verifique se o arquivo de origem que define o símbolo é compilado como parte do seu projeto. Verifique o diretório de saída do Build intermediário para obter um arquivo. obj correspondente. Se o arquivo de origem não for compilado, clique com o botão direito do mouse no arquivo em Gerenciador de Soluções e escolha **Propriedades** para verificar as propriedades do arquivo. As **Propriedades de configuração** > página **geral** devem mostrar um **tipo de item** de **C/C++ compilador**. Na linha de comando, verifique se o arquivo de origem que contém a definição foi compilado.

### <a name="the-object-file-or-library-that-contains-the-definition-of-the-symbol-isnt-linked"></a>O arquivo de objeto ou a biblioteca que contém a definição do símbolo não está vinculado

No Visual Studio, verifique se o arquivo de objeto ou a biblioteca que contém a definição de símbolo está vinculada como parte do seu projeto. Na linha de comando, verifique se a lista de arquivos a serem vinculados inclui o arquivo de objeto ou a biblioteca.

### <a name="the-declaration-of-the-symbol-isnt-spelled-the-same-as-the-definition-of-the-symbol"></a>A declaração do símbolo não é escrita da mesma forma que a definição do símbolo

Verifique se você usa a grafia correta e a capitalização na declaração e na definição, e onde quer que o símbolo seja usado ou chamado.

### <a name="a-function-is-used-but-the-type-or-number-of-the-parameters-dont-match-the-function-definition"></a>Uma função é usada, mas o tipo ou o número dos parâmetros não correspondem à definição da função

A declaração da função deve corresponder à definição. Verifique se a chamada de função corresponde à declaração e se a declaração corresponde à definição. O código que invoca as funções de modelo também deve ter declarações de função de modelo correspondentes que incluam os mesmos parâmetros de modelo que a definição. Para obter um exemplo de uma incompatibilidade de declaração de modelo, consulte Sample LNK2019e. cpp na seção de exemplos.

### <a name="a-function-or-variable-is-declared-but-not-defined"></a>Uma função ou variável é declarada mas não definida

LNK2019 pode ocorrer quando uma declaração existe em um arquivo de cabeçalho, mas nenhuma definição correspondente é implementada. Para funções de membro ou membros de dados de static, a implementação deve incluir o seletor de escopo de classe. Para obter um exemplo, consulte [faltando o corpo da função ou a variável](../../error-messages/tool-errors/missing-function-body-or-variable.md).

### <a name="the-calling-convention-is-different-between-the-function-declaration-and-the-function-definition"></a>A Convenção de chamada é diferente entre a declaração da função e a definição da função

As convenções de chamada ([__cdecl](../../cpp/cdecl.md), [__stdcall](../../cpp/stdcall.md), [__fastcall](../../cpp/fastcall.md)ou [__vectorcall](../../cpp/vectorcall.md)) são codificadas como parte do nome decorado. Verifique se a Convenção de chamada é a mesma.

### <a name="a-symbol-is-defined-in-a-c-file-but-declared-without-using-opno-locextern-c-in-a-c-file"></a>Um símbolo é definido em um arquivo C, mas declarado sem usar extern "C" em um C++ arquivo

Os símbolos definidos em um arquivo compilado como C têm nomes decorados diferentes dos símbolos declarados em C++ um arquivo, a menos que você use um modificador ["C"extern](../../cpp/using-extern-to-specify-linkage.md) . Verifique se a declaração corresponde ao vínculo de compilação para cada símbolo. Da mesma forma, se você definir um símbolo C++ em um arquivo que será usado por um programa C, use `extern "C"` na definição.

### <a name="a-symbol-is-defined-as-opno-locstatic-and-then-later-referenced-outside-the-file"></a>Um símbolo é definido como static e, posteriormente, referenciado fora do arquivo

No C++, ao contrário de C, as [constantes globais](../../error-messages/tool-errors/global-constants-in-cpp.md) têm `static` vinculação. Para contornar essa limitação, você pode incluir as inicializações de `const` em um arquivo de cabeçalho e incluir esse cabeçalho em seus arquivos. cpp ou pode tornar a variável não constante e usar uma referência constante para acessá-la.

### <a name="a-opno-locstatic-member-of-a-class-isnt-defined"></a>Um membro static de uma classe não está definido

Um membro da classe static deve ter uma definição exclusiva ou violará a regra de uma definição. Um membro da classe static que não pode ser definido em linha deve ser definido em um arquivo de origem usando seu nome totalmente qualificado. Se não estiver definido, o vinculador gerará LNK2019.

### <a name="a-build-dependency-is-only-defined-as-a-project-dependency-in-the-solution"></a>Uma dependência de compilação só é definida como uma dependência de projeto na solução

Em versões anteriores do Visual Studio, esse nível de dependência era suficiente. No entanto, a partir do Visual Studio 2010, o Visual Studio requer uma [referência projeto-para-projeto](/visualstudio/ide/managing-references-in-a-project). Se o seu projeto não tiver uma referência de projeto para projeto, você poderá receber esse erro de vinculador. Adicione uma referência projeto-para-projeto para corrigi-lo.

### <a name="an-entry-point-isnt-defined"></a>Um ponto de entrada não está definido

O código do aplicativo deve definir um ponto de entrada apropriado: `main` ou `wmain` para aplicativos de console e `WinMain` ou `wWinMain` para aplicativos do Windows. Para obter mais informações, consulte [main função e argumentos de linha de comando](../../cpp/main-function-command-line-args.md) ou [WinMain função](/windows/win32/api/winbase/nf-winbase-winmain). Para usar um ponto de entrada personalizado, especifique a opção de vinculador [/Entry (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) .

### <a name="you-build-a-console-application-by-using-settings-for-a-windows-application"></a>Você cria um aplicativo de console usando as configurações para um aplicativo do Windows

Se a mensagem de erro for semelhante a um **símbolo externo não resolvido WinMain referenciado na função** *function_name*, VINCULE usando **/SUBSYSTEM: console** em vez de **/SUBSYSTEM: Windows**. Para obter mais informações sobre essa configuração e obter instruções sobre como definir essa propriedade no Visual Studio, consulte [/Subsystem (especificar subsistema)](../../build/reference/subsystem-specify-subsystem.md).

### <a name="you-attempt-to-link-64-bit-libraries-to-32-bit-code-or-32-bit-libraries-to-64-bit-code"></a>Você tenta vincular bibliotecas de 64 bits a código de 32 bits ou bibliotecas de 32 bits ao código de 64 bits

Bibliotecas e arquivos de objeto vinculados ao seu código devem ser compilados para a mesma arquitetura que seu código. Verifique se as bibliotecas às quais suas referências de projeto são compiladas para a mesma arquitetura que o seu projeto. Verifique se a propriedade de **diretórios de biblioteca** [/LIBPATH](../../build/reference/libpath-additional-libpath.md) ou adicional aponta para bibliotecas criadas para a arquitetura correta.

### <a name="you-use-different-compiler-options-for-function-inlining-in-different-source-files"></a>Você usa opções de compilador diferentes para o inlinear funções em diferentes arquivos de origem

O uso de funções embutidas definidas em arquivos. cpp e na combinação de opções do compilador de entrada de função em arquivos de origem diferentes pode causar LNK2019. Para obter mais informações, consulte [problemas de inalinhamento de função](../../error-messages/tool-errors/function-inlining-problems.md).

### <a name="you-use-automatic-variables-outside-their-scope"></a>Você usa variáveis automáticas fora de seu escopo

Variáveis automáticas (escopo de função) só podem ser usadas no escopo dessa função. Essas variáveis não podem ser declaradas `extern` e usadas em outros arquivos de origem. Para obter um exemplo, consulte [variáveis automáticas (escopo de função)](../../error-messages/tool-errors/automatic-function-scope-variables.md).

### <a name="you-call-intrinsic-functions-or-pass-argument-types-to-intrinsic-functions-that-arent-supported-on-your-target-architecture"></a>Você chama funções intrínsecas ou passa tipos de argumentos para funções intrínsecas que não têm suporte na sua arquitetura de destino

Por exemplo, se você usar um AVX2 intrínseco, mas não especificar a opção de compilador [/ARCH:AVX2](../../build/reference/arch-x86.md) , o compilador pressupõe que o intrínseco é uma função externa. Em vez de gerar uma instrução embutida, o compilador gera uma chamada para um símbolo externo com o mesmo nome que o intrínseco. Quando o vinculador tenta localizar a definição dessa função ausente, ele gera LNK2019. Certifique-se de usar somente intrínsecos e tipos com suporte na sua arquitetura de destino.

### <a name="you-mix-code-that-uses-native-opno-locwchar_t-with-code-that-doesnt"></a>Você mistura código que usa wchar_t nativos com código que não

C++o trabalho de conformidade de idioma que foi feito no Visual Studio 2005 fez **wchar_t** um tipo nativo por padrão. Se nem todos os arquivos tiverem sido compilados usando as mesmas configurações de **/Zc:wchar_t** , referências de tipo podem não ser resolvidas para tipos compatíveis. Verifique se os tipos de **wchar_t** em todos os arquivos de biblioteca e de objeto são compatíveis. Atualize de um **wchar_t** typedef ou use as configurações consistentes de **/Zc:wchar_t** ao compilar.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e Vcpkg

Se você vir esse erro ao tentar configurar uma biblioteca de terceiros como parte de sua compilação, considere usar o [Vcpkg](../../vcpkg.md), o Gerenciador de pacotes do C++ Visual, para instalar e compilar a biblioteca. O Vcpkg dá suporte a uma lista grande e crescente [de bibliotecas de](https://github.com/Microsoft/vcpkg/tree/master/ports)terceiros. Ele define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto. Para obter mais informações, consulte a postagem do blog relacionado do [Visual C++ ](https://blogs.msdn.microsoft.com/vcblog/2016/09/19/vcpkg-a-tool-to-acquire-and-build-c-open-source-libraries-on-windows/) .

## <a name="diagnosis-tools"></a>Ferramentas de diagnóstico

Às vezes, é difícil dizer por que o vinculador não consegue encontrar uma definição de símbolo específica. Geralmente, o problema é que você não incluiu o código que contém a definição em sua compilação. Ou, as opções de compilação criaram nomes decorados diferentes para símbolos externos. Há várias ferramentas e opções que podem ajudá-lo a diagnosticar erros LNK2019.

- A opção [/VERBOSE](../../build/reference/verbose-print-progress-messages.md) vinculador pode ajudá-lo a determinar quais arquivos são referenciados pelo vinculador. Essa opção pode ajudá-lo a verificar se o arquivo que contém a definição do símbolo está incluído em seu Build.

- As opções [/EXPORTS](../../build/reference/dash-exports.md) e [/SYMBOLS](../../build/reference/symbols.md) do utilitário **DUMPBIN** podem ajudá-lo a descobrir quais símbolos são definidos em seus arquivos. dll e de objeto ou biblioteca. Verifique se os nomes decorados exportados correspondem aos nomes decorados que o vinculador pesquisa.

- O utilitário **UNDNAME** pode mostrar o símbolo externo não decorado equivalente para um nome decorado.

## <a name="examples"></a>Exemplos

Aqui estão vários exemplos de código que causa um erro de LNK2019, junto com informações sobre como corrigir o erro.

### <a name="a-symbol-is-declared-but-not-defined"></a>Um símbolo é declarado mas não definido

Neste exemplo, uma variável externa é declarada, mas não definida:

```cpp
// LNK2019.cpp
// Compile by using: cl /EHsc /W4 LNK2019.cpp
// LNK2019 expected
extern char B[100];   // B isn't available to the linker
int main() {
   B[0] = ' ';   // LNK2019
}
```

Aqui está outro exemplo em que uma variável e uma função são declaradas como `extern`, mas nenhuma definição é fornecida:

```cpp
// LNK2019c.cpp
// Compile by using: cl /EHsc LNK2019c.cpp
// LNK2019 expected
extern int i;
extern void g();
void f() {
   i++;
   g();
}
int main() {}
```

A menos que `i` e `g` sejam definidos em um dos arquivos incluídos na compilação, o vinculador gera LNK2019. Você pode corrigir os erros incluindo o arquivo de código-fonte que contém as definições como parte da compilação. Como alternativa, você pode passar arquivos. obj ou arquivos. lib que contêm as definições para o vinculador.

### <a name="a-opno-locstatic-data-member-is-declared-but-not-defined"></a>Um membro de dados static é declarado mas não definido

LNK2019 também pode ocorrer quando um membro de dados static é declarado, mas não definido. O exemplo a seguir gera LNK2019 e mostra como corrigi-lo.

```cpp
// LNK2019b.cpp
// Compile by using: cl /EHsc LNK2019b.cpp
// LNK2019 expected
struct C {
   static int s;
};

// Uncomment the following line to fix the error.
// int C::s;

int main() {
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

int main() {
   Test<int> t;
   cout << "Test: " << t << endl;   // LNK2019 unresolved external
}
```

### <a name="inconsistent-opno-locwchar_t-type-definitions"></a>Definições de tipo de wchar_t inconsistentes

Este exemplo cria uma DLL que tem uma exportação que usa `WCHAR`, que é resolvida para `wchar_t`.

```cpp
// LNK2019g.cpp
// compile with: cl /EHsc /LD LNK2019g.cpp
#include "windows.h"
// WCHAR resolves to wchar_t
__declspec(dllexport) void func(WCHAR*) {}
```

O exemplo a seguir usa a DLL no exemplo anterior e gera LNK2019 porque os tipos `unsigned short*` e `WCHAR*` não são iguais.

```cpp
// LNK2019h.cpp
// compile by using: cl /EHsc LNK2019h LNK2019g.lib
// LNK2019 expected
__declspec(dllimport) void func(unsigned short*);

int main() {
   func(0);
}
```

Para corrigir esse erro, altere `unsigned short` para `wchar_t` ou `WCHAR`ou compile LNK2019g. cpp usando **/Zc:wchar_t-** .

## <a name="additional-resources"></a>Recursos adicionais

Para obter mais informações sobre possíveis causas e soluções para LNK2001, consulte a Stack Overflow pergunta [o que é um erro de símbolo externo de referência indefinido/não resolvido e como corrigi-lo?](https://stackoverflow.com/q/12573816/2002113).
