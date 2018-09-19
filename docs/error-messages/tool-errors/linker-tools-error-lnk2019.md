---
title: Ferramentas de vinculador LNK2019 erro | Microsoft Docs
ms.custom: ''
ms.date: 12/15/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2019
dev_langs:
- C++
helpviewer_keywords:
- nochkclr.obj
- LNK2019
- _check_commonlanguageruntime_version
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 679d322f6d5ebcf8e56d1691d18e634bb34a2bb2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46067539"
---
# <a name="linker-tools-error-lnk2019"></a>Erro das Ferramentas de Vinculador LNK2019

símbolo externo não resolvido '*símbolo*'referenciado na função'*função*'

O código compilado para *função* faz uma referência ou uma chamada para *símbolo*, mas esse símbolo não está definido em qualquer uma das bibliotecas ou arquivos de objeto especificados para o vinculador.

Essa mensagem de erro é seguida por um erro fatal [das LNK1120](../../error-messages/tool-errors/linker-tools-error-lnk1120.md). Você deve corrigir os erros de todos os LNK2001 e LNK2019 para corrigir o erro das LNK1120.

## <a name="possible-causes"></a>Possíveis causas

Há várias maneiras de obter esse erro, mas todos eles envolvem uma referência a uma função ou variável que o vinculador não pode *resolver*, ou encontrar uma definição. O compilador pode identificar quando um símbolo não é *declarado*, mas não quando ele não está *definidos*, porque a definição pode estar em um arquivo de origem diferente ou uma biblioteca. Se um símbolo é referenciado, mas nunca definido, o vinculador gera um erro de símbolo externo não resolvido.

Aqui estão alguns problemas comuns que causam LNK2019:

### <a name="the-object-file-or-library-that-contains-the-definition-of-the-symbol-is-not-linked"></a>O arquivo de objeto ou a biblioteca que contém a definição do símbolo não está vinculada

No Visual Studio, verifique se o arquivo de origem que contém a definição é criado e vinculado como parte do seu projeto. Na linha de comando, verifique se que o arquivo de origem que contém a definição é compilado, e se o arquivo-objeto resultante está incluído na lista de arquivos para vincular.

### <a name="the-declaration-of-the-symbol-is-not-spelled-the-same-as-the-definition-of-the-symbol"></a>A declaração do símbolo não foi digitada para o mesmo que a definição do símbolo

Verifique se a grafia correta e capitalização é usado na declaração e a definição e onde quer que o símbolo é usado ou chamado.

### <a name="a-function-is-used-but-the-type-or-number-of-the-parameters-do-not-match-the-function-definition"></a>Uma função é usada, mas o tipo ou o número de parâmetros não correspondem a definição de função

A declaração da função deve corresponder à definição. Verifique se que a chamada de função corresponde a declaração, e se a declaração corresponde a definição. Código que invoca as funções de modelo também deve ter as declarações de função de modelo que incluem os mesmos parâmetros de modelo que a definição de correspondência. Para obter um exemplo de uma incompatibilidade de declaração de modelo, consulte o exemplo LNK2019e.cpp na seção exemplos.

### <a name="a-function-or-variable-is-declared-but-not-defined"></a>Uma função ou variável é declarada mas não definido

Isso geralmente significa uma declaração existe em um arquivo de cabeçalho, mas nenhuma definição correspondente é implementada. Para funções de membro ou membros de dados estáticos, a implementação deve incluir o seletor de escopo de classe. Por exemplo, consulte [faltando o corpo da função ou variável](../../error-messages/tool-errors/missing-function-body-or-variable.md).

### <a name="the-calling-convention-is-different-between-the-function-declaration-and-the-function-definition"></a>A convenção de chamada é diferente entre a declaração da função e a definição de função

Convenções de chamada ([cdecl](../../cpp/cdecl.md), [stdcall](../../cpp/stdcall.md), [fastcall](../../cpp/fastcall.md), ou [vectorcall](../../cpp/vectorcall.md)) são codificados como parte do nome decorado. Verifique se que a convenção de chamada é o mesmo.

### <a name="a-symbol-is-defined-in-a-c-file-but-declared-without-using-extern-c-in-a-c-file"></a>Um símbolo é definido em um arquivo de C, mas declarado sem usar extern "C" em um arquivo do C++

Símbolos definidos em um arquivo que é compilado como C têm diferentes nomes decorados símbolos declarados em um arquivo C++, a menos que você use uma [extern "C"](../../cpp/using-extern-to-specify-linkage.md) modificador. Verifique se a declaração corresponde a ligação de compilação para cada símbolo. Da mesma forma, se você definir um símbolo em um arquivo do C++ que será usado por um programa C, use `extern "C"` na definição.

### <a name="a-symbol-is-defined-as-static-and-then-later-referenced-outside-the-file"></a>Um símbolo é definido como estático e, em seguida, posteriormente referenciado fora do arquivo

No C++, ao contrário do C, [constantes globais](../../error-messages/tool-errors/global-constants-in-cpp.md) ter `static` vinculação. Para contornar essa limitação, você pode incluir o `const` inicializações em um cabeçalho de arquivo e incluem esse cabeçalho em seus arquivos. cpp, ou você pode tornar a variável não constante e usar uma referência constante para acessá-lo.

### <a name="a-static-member-of-a-class-is-not-defined"></a>Um membro estático de uma classe não está definido.

Um membro de classe estática deve ter uma definição de exclusiva ou violar a regra de definição. Um membro de classe estática que não pode ser definidas em linha deve ser definido em um arquivo de origem usando seu nome totalmente qualificado. Se ele não está definido em todos os, o vinculador gera LNK2019.

### <a name="a-build-dependency-is-only-defined-as-a-project-dependency-in-the-solution"></a>Uma dependência de compilação é definida somente como uma dependência de projeto na solução

Em versões anteriores do Visual Studio, esse nível de dependência foi suficiente. No entanto, começando com o Visual Studio 2010, o Visual Studio requer um [referência projeto a projeto](/visualstudio/ide/managing-references-in-a-project). Se seu projeto não tem uma referência projeto a projeto, você poderá receber esse erro de vinculador. Adicione uma referência projeto a projeto para corrigi-lo.

### <a name="you-build-a-console-application-by-using-settings-for-a-windows-application"></a>Criar um aplicativo de console usando as configurações para um aplicativo do Windows

Se a mensagem de erro é semelhante ao **símbolo externo não resolvido WinMain referenciado na função** *function_name*, link, usando **/Subsystem: console** em vez de **/Subsystem: Windows**. Para obter mais informações sobre essa configuração e para obter instruções sobre como definir essa propriedade no Visual Studio, consulte [/SUBSYSTEM (especificar subsistema)](../../build/reference/subsystem-specify-subsystem.md).

### <a name="you-attempt-to-link-64-bit-libraries-to-32-bit-code-or-32-bit-libraries-to-64-bit-code"></a>Você tentar vincular a bibliotecas de 64 bits para código de 32 bits ou bibliotecas de 32 bits para código de 64 bits

Bibliotecas e arquivos de objeto vinculados ao seu código devem ser compilados para a mesma arquitetura de seu código. Verificar se as bibliotecas de suas referências do projeto são compiladas para a mesma arquitetura de seu projeto. Verifique se o [/LIBPATH](../../build/reference/libpath-additional-libpath.md) ou **diretórios de biblioteca adicionais** opção path usada pelos pontos de vinculador para bibliotecas criadas para a arquitetura correta.

### <a name="you-use-different-compiler-options-for-function-inlining-in-different-source-files"></a>Usar opções do compilador diferentes para a função inlining nos arquivos de origem diferentes

Usando funções embutidas definidas nos arquivos. cpp e combinação de opções do compilador inlining função nos arquivos de origem diferentes pode causar LNK2019. Para obter mais informações, consulte [problemas de Inlining de função](../../error-messages/tool-errors/function-inlining-problems.md).

### <a name="you-use-automatic-variables-outside-their-scope"></a>Use as variáveis automáticas fora do escopo de suas

Variáveis automáticas (escopo da função) podem ser usadas somente no escopo dessa função. Essas variáveis não podem ser declaradas `extern` e usado em outros arquivos de origem. Por exemplo, consulte [as variáveis automáticas (escopo da função)](../../error-messages/tool-errors/automatic-function-scope-variables.md).

### <a name="you-call-instrinsic-functions-or-pass-argument-types-to-intrinsic-functions-that-are-not-supported-on-your-target-architecture"></a>Chamar funções instrinsic ou passar tipos de argumentos para funções intrínsecas que não têm suporte em sua arquitetura de destino

Por exemplo, se você usar um AVX2 intrínseco, mas não especificar o [/arch:avx2](../../build/reference/arch-x86.md) opção de compilador, o compilador pressupõe que o intrínseco é uma função externa. Em vez de gerar uma instrução embutido, o compilador gera uma chamada para um símbolo externo com o mesmo nome que o intrínseco. Quando o vinculador tenta encontrar a definição dessa função ausente, ele gera LNK2019. Verifique se que você use somente tipos compatíveis com sua arquitetura de destino e intrínsecos.

### <a name="you-mix-code-that-uses-native-wchart-with-code-that-doesnt"></a>Você mistura o código que usa native wchar\_t com código não

Trabalho de conformidade de linguagem C++ que foi feito no Visual C++ 2005 feitas `wchar_t` um tipo nativo por padrão. Você deve usar o [/Zc:wchar_t-](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção de compilador para gerar código compatível com arquivos de biblioteca e objeto compilados usando versões anteriores do Visual C++. Se nem todos os arquivos foram compilados usando o mesmo **/Zc:wchar\_t** configurações, o tipo de referências não podem ser resolvidos em tipos compatíveis. Verifique `wchar_t` tipos em todos os arquivos de biblioteca e objeto são compatíveis, atualizando os tipos que são usados ou com o uso consistente **/ZC: wchar_t** configurações quando você compila.

## <a name="third-party-library-issues-and-vcpkg"></a>Problemas de biblioteca de terceiros e Vcpkg

Se você vir esse erro quando você está tentando configurar uma biblioteca de terceiros como parte da compilação, considere o uso [Vcpkg](../../vcpkg.md), o Visual C++ Gerenciador de pacotes para instalar e criar a biblioteca. Vcpkg dá suporte a um grande e crescente [lista de bibliotecas de terceiros](https://github.com/Microsoft/vcpkg/tree/master/ports)e define todas as propriedades de configuração e dependências necessárias para compilações bem-sucedidas como parte do seu projeto. Para obter mais informações, consulte relacionado [Blog do Visual C++](https://blogs.msdn.microsoft.com/vcblog/2016/09/19/vcpkg-a-tool-to-acquire-and-build-c-open-source-libraries-on-windows/) lançar.

## <a name="diagnosis-tools"></a>Ferramentas de diagnóstico

Pode ser difícil saber por que o vinculador não é possível encontrar uma definição de símbolo específico. Geralmente, o problema é que você não incluiu o código que contém a definição em seu build ou build opções criou diferentes decoradas nomes para símbolos externos. Há várias ferramentas e opções que podem ajudar você a diagnosticarem um erro de LNK2019.

- O [/verbose](../../build/reference/verbose-print-progress-messages.md) a opção de vinculador pode ajudá-lo a determinar quais arquivos as vinculador de referências. Isso pode ajudá-lo a verificar se o arquivo que contém a definição do símbolo está incluído em sua compilação.

- O [/EXPORTA](../../build/reference/dash-exports.md) e [/símbolos](../../build/reference/symbols.md) opções dos **DUMPBIN** utilitário pode ajudá-lo a descobrir quais símbolos são definidos em seus arquivos. dll e biblioteca ou objeto. Verifique se que o exportado decorado o decorado nomeia o vinculador procura de correspondência de nomes.

- O **UNDNAME** utilitário pode mostrar o símbolo externo não decorado equivalente para um nome decorado.

## <a name="examples"></a>Exemplos

Aqui estão vários exemplos de código que causa um erro de LNK2019, junto com informações sobre como corrigir o erro.

### <a name="a-symbol-is-declared-but-not-defined"></a>Um símbolo é declarado mas não definido

Neste exemplo, uma variável externa é declarada mas não definida:

```cpp
// LNK2019.cpp
// Compile by using: cl /EHsc /W4 LNK2019.cpp
// LNK2019 expected
extern char B[100];   // B is not available to the linker
int main() {
   B[0] = ' ';   // LNK2019
}
```

Aqui está outro exemplo onde uma variável e função são declarados como `extern` , mas é fornecida nenhuma definição:

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

A menos que `i` e `g` são definidos em um dos arquivos incluídos na compilação, o vinculador gera LNK2019. Você pode corrigir os erros, incluindo o arquivo de código fonte que contém as definições como parte da compilação. Como alternativa, você pode passar a arquivos. obj ou arquivos. lib que contêm as definições para o vinculador.

### <a name="a-static-data-member-is-declared-but-not-defined"></a>Um membro de dados estático é declarado, mas não definido

LNK2019 também pode ocorrer quando um membro de dados estático é declarado, mas não definido. O exemplo a seguir gera LNK2019 e mostra como corrigi-lo.

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

### <a name="declaration-parameters-do-not-match-definition"></a>Parâmetros de declaração não coincidem definição

Código que invoca as funções de modelo deve ter correspondência de declarações de função de modelo. As declarações devem incluir os mesmos parâmetros de modelo que a definição. O exemplo a seguir gera LNK2019 em um operador definido pelo usuário e mostra como corrigi-lo.

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

### <a name="inconsistent-wchart-type-definitions"></a>Definições de tipo wchar_t inconsistente

Este exemplo cria uma DLL que tem uma exportação que usa `WCHAR`, que resolve para `wchar_t`.

```cpp
// LNK2019g.cpp
// compile with: cl /EHsc /LD LNK2019g.cpp
#include "windows.h"
// WCHAR resolves to wchar_t
__declspec(dllexport) void func(WCHAR*) {}
```

O próximo exemplo usa a DLL no exemplo anterior e gera LNK2019, porque os tipos unsigned short * e WCHAR\* não são iguais.

```cpp
// LNK2019h.cpp
// compile by using: cl /EHsc LNK2019h LNK2019g.lib
// LNK2019 expected
__declspec(dllimport) void func(unsigned short*);

int main() {
   func(0);
}
```

Para corrigir esse erro, altere `unsigned short` à `wchar_t` ou `WCHAR`, ou compile LNK2019g.cpp usando **/Zc:wchar_t-**.

## <a name="additional-resources"></a>Recursos adicionais

Para obter mais informações sobre possíveis causas e soluções para LNK2001, consulte a pergunta do Stack Overflow [o que é um erro de símbolo externo indefinido referência/não resolvido e como corrigi-lo?](http://stackoverflow.com/q/12573816/2002113).

