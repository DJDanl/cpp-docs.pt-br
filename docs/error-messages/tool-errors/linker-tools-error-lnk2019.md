---
title: Erro das Ferramentas de Vinculador LNK2019
ms.date: 12/15/2017
f1_keywords:
- LNK2019
helpviewer_keywords:
- nochkclr.obj
- LNK2019
- _check_commonlanguageruntime_version
ms.openlocfilehash: 3c4e5578c7b0f496feb4d40933af624f462a31d2
ms.sourcegitcommit: 680a155cc44a38f88bb2b1c5a1ef6dcb7141c011
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/10/2019
ms.locfileid: "72252631"
---
# <a name="linker-tools-error-lnk2019"></a>Erro das Ferramentas de Vinculador LNK2019

símbolo externo '*Symbol*' não resolvido referenciado na função '*Function*'

O código compilado para a *função* faz uma referência ou uma chamada para *símbolo*, mas esse símbolo não é definido em nenhuma das bibliotecas ou arquivos de objeto especificados para o vinculador.

Essa mensagem de erro é seguida pelo erro fatal [LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md). Você deve corrigir todos os erros LNK2001 e LNK2019 para corrigir o erro LNK1120.

## <a name="possible-causes"></a>Possíveis causas

Há várias maneiras de obter esse erro, mas todos eles envolvem uma referência a uma função ou variável que o vinculador não pode *resolver*, ou encontrar uma definição para. O compilador pode identificar quando um símbolo não é *declarado*, mas não quando ele não está *definido*, pois a definição pode estar em um arquivo ou biblioteca de origem diferente. Se um símbolo for referenciado, mas nunca definido, o vinculador gerará um erro de símbolo externo não resolvido.

Aqui estão alguns problemas comuns que causam LNK2019:

### <a name="the-object-file-or-library-that-contains-the-definition-of-the-symbol-is-not-linked"></a>O arquivo de objeto ou a biblioteca que contém a definição do símbolo não está vinculada

No Visual Studio, verifique se o arquivo de origem que contém a definição foi criado e vinculado como parte do seu projeto. Na linha de comando, verifique se o arquivo de origem que contém a definição foi compilado e se o arquivo de objeto resultante está incluído na lista de arquivos a serem vinculados.

### <a name="the-declaration-of-the-symbol-is-not-spelled-the-same-as-the-definition-of-the-symbol"></a>A declaração do símbolo não é escrita da mesma forma que a definição do símbolo

Verifique se a grafia correta e a capitalização são usadas na declaração e na definição, e onde quer que o símbolo seja usado ou chamado.

### <a name="a-function-is-used-but-the-type-or-number-of-the-parameters-do-not-match-the-function-definition"></a>Uma função é usada, mas o tipo ou o número de parâmetros não coincide com a definição da função

A declaração da função deve corresponder à definição. Verifique se a chamada de função corresponde à declaração e se a declaração corresponde à definição. O código que invoca as funções de modelo também deve ter declarações de função de modelo correspondentes que incluam os mesmos parâmetros de modelo que a definição. Para obter um exemplo de uma incompatibilidade de declaração de modelo, consulte Sample LNK2019e. cpp na seção de exemplos.

### <a name="a-function-or-variable-is-declared-but-not-defined"></a>Uma função ou variável é declarada mas não definida

Isso geralmente significa que existe uma declaração em um arquivo de cabeçalho, mas nenhuma definição correspondente é implementada. Para funções membro ou membros de dados estáticos, a implementação deve incluir o seletor de escopo de classe. Para obter um exemplo, consulte [faltando o corpo da função ou a variável](../../error-messages/tool-errors/missing-function-body-or-variable.md).

### <a name="the-calling-convention-is-different-between-the-function-declaration-and-the-function-definition"></a>A Convenção de chamada é diferente entre a declaração da função e a definição da função

As convenções de chamada ([__cdecl](../../cpp/cdecl.md), [__stdcall](../../cpp/stdcall.md), [__fastcall](../../cpp/fastcall.md)ou [__vectorcall](../../cpp/vectorcall.md)) são codificadas como parte do nome decorado. Verifique se a Convenção de chamada é a mesma.

### <a name="a-symbol-is-defined-in-a-c-file-but-declared-without-using-extern-c-in-a-c-file"></a>Um símbolo é definido em um arquivo C, mas declarado sem usar "C" externo em um C++ arquivo

Os símbolos definidos em um arquivo compilado como C têm nomes decorados diferentes dos símbolos declarados em C++ um arquivo, a menos que você use um modificador ["C" externo](../../cpp/using-extern-to-specify-linkage.md) . Verifique se a declaração corresponde ao vínculo de compilação para cada símbolo. Da mesma forma, se você definir um símbolo C++ em um arquivo que será usado por um programa C, use `extern "C"` na definição.

### <a name="a-symbol-is-defined-as-static-and-then-later-referenced-outside-the-file"></a>Um símbolo é definido como estático e, posteriormente, referenciado fora do arquivo

No C++, ao contrário de C, as [constantes globais](../../error-messages/tool-errors/global-constants-in-cpp.md) têm vínculo `static`. Para contornar essa limitação, você pode incluir as inicializações `const` em um arquivo de cabeçalho e incluir esse cabeçalho em seus arquivos. cpp ou pode tornar a variável não constante e usar uma referência constante para acessá-la.

### <a name="a-static-member-of-a-class-is-not-defined"></a>Um membro estático de uma classe não está definido

Um membro de classe estática deve ter uma definição exclusiva ou violará a regra de uma definição. Um membro de classe estática que não pode ser definido em linha deve ser definido em um arquivo de origem usando seu nome totalmente qualificado. Se não estiver definido, o vinculador gerará LNK2019.

### <a name="a-build-dependency-is-only-defined-as-a-project-dependency-in-the-solution"></a>Uma dependência de compilação só é definida como uma dependência de projeto na solução

Em versões anteriores do Visual Studio, esse nível de dependência era suficiente. No entanto, a partir do Visual Studio 2010, o Visual Studio requer uma [referência projeto-para-projeto](/visualstudio/ide/managing-references-in-a-project). Se o seu projeto não tiver uma referência de projeto para projeto, você poderá receber esse erro de vinculador. Adicione uma referência projeto-para-projeto para corrigi-lo.

### <a name="an-entry-point-is-not-defined"></a>Um ponto de entrada não está definido

O código do aplicativo deve definir um ponto de entrada apropriado: `main` ou `wmain` para aplicativos de console, `WinMain` ou `wWinMain` para aplicativos do Windows. Para obter mais informações, consulte [main: Inicialização do programa @ no__t-0 ou [função WinMain](/windows/win32/api/winbase/nf-winbase-winmain). Para usar um ponto de entrada personalizado, especifique a opção de vinculador [/Entry (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md) . 

### <a name="you-build-a-console-application-by-using-settings-for-a-windows-application"></a>Você cria um aplicativo de console usando as configurações para um aplicativo do Windows

Se a mensagem de erro for semelhante a um **símbolo externo não resolvido WinMain referenciado na função** *function_name*, VINCULE usando **/SUBSYSTEM: console** em vez de **/SUBSYSTEM: Windows**. Para obter mais informações sobre essa configuração e obter instruções sobre como definir essa propriedade no Visual Studio, consulte [/Subsystem (especificar subsistema)](../../build/reference/subsystem-specify-subsystem.md).

### <a name="you-attempt-to-link-64-bit-libraries-to-32-bit-code-or-32-bit-libraries-to-64-bit-code"></a>Você tenta vincular bibliotecas de 64 bits a código de 32 bits ou bibliotecas de 32 bits ao código de 64 bits

Bibliotecas e arquivos de objeto vinculados ao seu código devem ser compilados para a mesma arquitetura que seu código. Verifique se as bibliotecas às quais suas referências de projeto são compiladas para a mesma arquitetura que o seu projeto. Verifique se a opção de caminho de **diretórios de biblioteca** [/LIBPATH](../../build/reference/libpath-additional-libpath.md) ou adicional usada pelo vinculador aponta para bibliotecas criadas para a arquitetura correta.

### <a name="you-use-different-compiler-options-for-function-inlining-in-different-source-files"></a>Você usa opções de compilador diferentes para o inlinear funções em diferentes arquivos de origem

O uso de funções embutidas definidas em arquivos. cpp e na combinação de opções do compilador de entrada de função em arquivos de origem diferentes pode causar LNK2019. Para obter mais informações, consulte [problemas de inalinhamento de função](../../error-messages/tool-errors/function-inlining-problems.md).

### <a name="you-use-automatic-variables-outside-their-scope"></a>Você usa variáveis automáticas fora de seu escopo

Variáveis automáticas (escopo de função) só podem ser usadas no escopo dessa função. Essas variáveis não podem ser declaradas `extern` e usadas em outros arquivos de origem. Para obter um exemplo, consulte [variáveis automáticas (escopo de função)](../../error-messages/tool-errors/automatic-function-scope-variables.md).

### <a name="you-call-instrinsic-functions-or-pass-argument-types-to-intrinsic-functions-that-are-not-supported-on-your-target-architecture"></a>Você chama funções instrinsic ou passa tipos de argumentos para funções intrínsecas que não têm suporte na sua arquitetura de destino

Por exemplo, se você usar um intrínseco AVX2, mas não especificar a opção de compilador [/Arch: AVX2](../../build/reference/arch-x86.md) , o compilador assumirá que o intrínseco é uma função externa. Em vez de gerar uma instrução embutida, o compilador gera uma chamada para um símbolo externo com o mesmo nome que o intrínseco. Quando o vinculador tenta localizar a definição dessa função ausente, ele gera LNK2019. Verifique se você só usa intrínsecos e tipos com suporte na sua arquitetura de destino.

### <a name="you-mix-code-that-uses-native-wchar_t-with-code-that-doesnt"></a>Você mistura o código que usa WCHAR @ no__t-0T nativo com código que não

C++o trabalho de conformidade de idioma que foi feito no Visual Studio 2005 fez `wchar_t` um tipo nativo por padrão. Você deve usar a opção [/Zc: wchar_t-](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) Compiler para gerar código compatível com biblioteca e arquivos de objeto compilados usando versões anteriores do Visual Studio. Se nem todos os arquivos tiverem sido compilados usando as mesmas configurações **/Zc: WCHAR @ no__t-1T** , as referências de tipo não poderão ser resolvidas para tipos compatíveis. Verifique se os tipos `wchar_t` em todos os arquivos de biblioteca e de objeto são compatíveis, seja atualizando os tipos usados ou usando/Zc consistentes: configurações de **wchar_t** quando você compila.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e Vcpkg

Se você vir esse erro ao tentar configurar uma biblioteca de terceiros como parte de sua compilação, considere usar o [Vcpkg](../../vcpkg.md), o Gerenciador de pacotes do C++ Visual, para instalar e compilar a biblioteca. O Vcpkg dá suporte a uma lista grande e crescente [de bibliotecas de](https://github.com/Microsoft/vcpkg/tree/master/ports)terceiros e define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto. Para obter mais informações, consulte a postagem do blog relacionado do [Visual C++ ](https://blogs.msdn.microsoft.com/vcblog/2016/09/19/vcpkg-a-tool-to-acquire-and-build-c-open-source-libraries-on-windows/) .

## <a name="diagnosis-tools"></a>Ferramentas de diagnóstico

Pode ser difícil dizer por que o vinculador não consegue encontrar uma definição de símbolo específica. Geralmente, o problema é que você não incluiu o código que contém a definição em sua compilação, ou as opções de compilação criaram nomes decorados diferentes para símbolos externos. Há várias ferramentas e opções que podem ajudá-lo a diagnosticar um erro LNK2019.

- A opção de vinculador [/Verbose](../../build/reference/verbose-print-progress-messages.md) pode ajudá-lo a determinar quais arquivos são referenciados pelo vinculador. Isso pode ajudá-lo a verificar se o arquivo que contém a definição do símbolo está incluído em seu Build.

- As opções [/Exports](../../build/reference/dash-exports.md) e [/Symbols](../../build/reference/symbols.md) do utilitário **DUMPBIN** podem ajudá-lo a descobrir quais símbolos são definidos nos arquivos. dll e de objeto ou biblioteca. Verifique se os nomes decorados exportados correspondem aos nomes decorados que o vinculador pesquisa.

- O utilitário **UNDNAME** pode mostrar o símbolo externo não decorado equivalente para um nome decorado.

## <a name="examples"></a>Exemplos

Aqui estão vários exemplos de código que causa um erro de LNK2019, junto com informações sobre como corrigir o erro.

### <a name="a-symbol-is-declared-but-not-defined"></a>Um símbolo é declarado mas não definido

Neste exemplo, uma variável externa é declarada, mas não definida:

```cpp
// LNK2019.cpp
// Compile by using: cl /EHsc /W4 LNK2019.cpp
// LNK2019 expected
extern char B[100];   // B is not available to the linker
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

### <a name="a-static-data-member-is-declared-but-not-defined"></a>Um membro de dados estático é declarado mas não definido

LNK2019 também pode ocorrer quando um membro de dados estáticos é declarado, mas não definido. O exemplo a seguir gera LNK2019 e mostra como corrigi-lo.

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

### <a name="declaration-parameters-do-not-match-definition"></a>Os parâmetros de declaração não correspondem à definição

O código que invoca funções de modelo deve ter declarações de função de modelo correspondentes. As declarações devem incluir os mesmos parâmetros de modelo que a definição. O exemplo a seguir gera LNK2019 em um operador definido pelo usuário e mostra como corrigi-lo.

```cpp
// LNK2019e.cpp
// compile by using: cl /EHsc LNK2019e.cpp
// LNK2019 expected
#include <iostream>
using namespace std;

template<class T> class
Test {
   // The operator<< declaration does not match the definition below:
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

### <a name="inconsistent-wchar_t-type-definitions"></a>Definições de tipo de wchar_t inconsistentes

Este exemplo cria uma DLL que tem uma exportação que usa `WCHAR`, que é resolvido para `wchar_t`.

```cpp
// LNK2019g.cpp
// compile with: cl /EHsc /LD LNK2019g.cpp
#include "windows.h"
// WCHAR resolves to wchar_t
__declspec(dllexport) void func(WCHAR*) {}
```

O exemplo a seguir usa a DLL no exemplo anterior e gera LNK2019 porque os tipos sem sinal curto * e WCHAR @ no__t-0 não são iguais.

```cpp
// LNK2019h.cpp
// compile by using: cl /EHsc LNK2019h LNK2019g.lib
// LNK2019 expected
__declspec(dllimport) void func(unsigned short*);

int main() {
   func(0);
}
```

Para corrigir esse erro, altere `unsigned short` para `wchar_t` ou `WCHAR` ou compile LNK2019g. cpp usando **/Zc: wchar_t-** .

## <a name="additional-resources"></a>Recursos adicionais

Para obter mais informações sobre possíveis causas e soluções para LNK2001, consulte a Stack Overflow pergunta [o que é um erro de símbolo externo de referência indefinido/não resolvido e como corrigi-lo?](https://stackoverflow.com/q/12573816/2002113).

