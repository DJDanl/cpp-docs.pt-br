---
title: Aviso do compilador (nível 3) C4996
description: Explica por que o aviso do compilador C4996 acontece e descreve o que fazer sobre ele.
ms.date: 11/25/2019
f1_keywords:
- C4996
helpviewer_keywords:
- C4996
ms.assetid: 926c7cc2-921d-43ed-ae75-634f560dd317
ms.openlocfilehash: 98662dc0b5439c1f8857e4f2ad259793a4d03e41
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865213"
---
# <a name="compiler-warning-level-3-c4996"></a>Aviso do compilador (nível 3) C4996

Seu código usa uma função, membro de classe, variável ou TypeDef marcado como *preterido*. Os símbolos são preteridos com o uso de um modificador [__declspec (preterido)](../../cpp/deprecated-cpp.md) ou do c++ 14 [\[\[preteridos\]\]](../../cpp/attributes.md) atributo. A mensagem de aviso C4996 real é especificada pelo modificador de `deprecated` ou atributo da declaração.

> [!IMPORTANT]
> Esse aviso é sempre uma mensagem deliberada do autor do arquivo de cabeçalho que declara o símbolo. Não use o símbolo preterido sem entender as consequências.

## <a name="remarks"></a>Comentários

Muitas funções, funções de membro, funções de modelo e variáveis globais em bibliotecas do Visual Studio são *preteridas*. Alguns, como o POSIX e as funções específicas da Microsoft, são preteridos porque agora têm um nome preferencial diferente. Algumas funções de biblioteca de tempo de execução C são preteridas porque não são seguras e têm uma variante mais segura. Outras foram preteridas porque estão obsoletas. As mensagens de substituição geralmente incluem uma substituição sugerida para a função preterida ou a variável global.

## <a name="turn-off-the-warning"></a>Desativar o aviso

Para corrigir um problema de C4996, geralmente recomendamos que você altere seu código. Em vez disso, use as funções sugeridas e as variáveis globais. Se você precisar usar as funções ou variáveis existentes para fins de portabilidade, você poderá desativar o aviso.

Para desativar o aviso para uma linha de código específica, use o pragma de [aviso](../../preprocessor/warning.md) , `#pragma warning(suppress : 4996)`.

Para desativar o aviso em um arquivo, use o pragma de aviso, `#pragma warning(disable : 4996)`.

Para desativar o aviso globalmente em compilações de linha de comando, use a opção de linha de comando [/wd4996](../../build/reference/compiler-option-warning-level.md) .

Para desativar o aviso para um projeto inteiro no IDE do Visual Studio:

1. Abra a caixa de diálogo **páginas de propriedades** do seu projeto. Para obter informações sobre como usar a caixa de diálogo páginas de propriedades, consulte [páginas de propriedades](../../build/reference/property-pages-visual-cpp.md).

1. Selecione a página **Propriedades de configuração** > **C/C++**  > **Advanced** .

1. Edite a propriedade **desabilitar avisos específicos** para adicionar `4996`. Escolha **OK** para aplicar suas alterações.

Você também pode usar macros de pré-processador para desativar determinadas classes específicas de avisos de substituição usados nas bibliotecas. Essas macros são descritas abaixo.

Para definir uma macro de pré-processador no Visual Studio:

1. Abra a caixa de diálogo **páginas de propriedades** do seu projeto. Para obter informações sobre como usar a caixa de diálogo páginas de propriedades, consulte [páginas de propriedades](../../build/reference/property-pages-visual-cpp.md).

1. Expanda **Propriedades de configuração >C++ o pré-processador C/>** .

1. Na propriedade **definições de pré-processador** , adicione o nome da macro. Escolha **OK** para salvar e, em seguida, recompilar o projeto.

Para definir uma macro somente em arquivos de origem específicos, adicione uma linha como `#define EXAMPLE_MACRO_NAME` antes de qualquer linha que inclua um arquivo de cabeçalho.

Aqui estão algumas das fontes comuns de erros e avisos do C4996:

## <a name="posix-function-names"></a>Nomes de função POSIX

**O nome POSIX deste item foi preterido. Em vez disso, use o ISO C++ C e o nome compatível:** *New-Name*. **Consulte a ajuda online para obter detalhes.**

A Microsoft renomeou algumas funções de biblioteca POSIX e específicas da Microsoft no CRT para estar em conformidade com as restrições C99 e C++ 03 em nomes reservados e globais definidos pela implementação. *Somente os nomes são preteridos, e não as próprias funções*. Na maioria dos casos, um sublinhado à esquerda foi adicionado ao nome da função para criar um nome de conformidade. O compilador emite um aviso de reprovação para o nome da função original e sugere o nome preferencial.

Para corrigir esse problema, geralmente recomendamos que você altere seu código para usar os nomes de função sugeridos. No entanto, os nomes atualizados são específicos da Microsoft. Se precisar usar os nomes de função existentes para motivos de portabilidade, você poderá desativar esses avisos. As funções ainda estão disponíveis na biblioteca com seus nomes originais.

Para desativar os avisos de substituição para essas funções, defina a macro de pré-processador **\_CRT\_NONSTDC\_nenhum aviso de\_** . Você pode definir essa macro na linha de comando, incluindo a opção `/D_CRT_NONSTDC_NO_WARNINGS`.

## <a name="unsafe-crt-library-functions"></a>Funções de biblioteca CRT não seguras

**Essa função ou variável pode não ser segura. Considere usar** *a versão segura* **em vez disso. Para desabilitar a reprovação, use \_CRT\_segura\_sem avisos de\_.  Consulte a ajuda online para obter detalhes.**

A Microsoft preteriu algumas C++ funções e globais de biblioteca CRT e padrão, pois há versões mais seguras disponíveis. A maioria das funções preteridas permite o acesso não verificado de leitura ou gravação aos buffers. Seu uso indevido pode levar a sérios problemas de segurança. O compilador emite um aviso de reprovação para essas funções e sugere a função preferencial.

Para corrigir esse problema, recomendamos que você use a função ou a *versão segura* de variável em vez disso. Às vezes, não é possível, para portabilidade ou motivos de compatibilidade com versões anteriores. Verifique atentamente se não é possível que uma substituição ou superleitura do buffer ocorra em seu código. Em seguida, você pode desativar o aviso.

Para desativar os avisos de substituição para essas funções no CRT, defina **\_crt\_SECURE\_sem avisos de\_** .

Para desativar os avisos sobre variáveis globais preteridas, defina **\_CRT\_SECURE\_não\_avisos\_globais**.

Para obter mais informações sobre essas funções preteridas e globais, consulte [recursos de segurança nas bibliotecas CRT](../../c-runtime-library/security-features-in-the-crt.md) e [seguras C++ : biblioteca padrão](../../standard-library/safe-libraries-cpp-standard-library.md).

## <a name="unsafe-standard-library-functions"></a>Funções de biblioteca padrão não seguras

__' std::__ *function_name* __::\_desmarcado\_iteradores::\_preterir ' Call para std::__ *function_name* **com parâmetros que podem não ser seguros – essa chamada depende do chamador para verificar se os valores passados estão corretos. Para desabilitar esse aviso, use-D\_SCL\_seguro\_não\_avisos. Consulte a documentação sobre como usar o C++ Visual ' iteradores marcados '**

Esse aviso aparece em builds de depuração C++ porque determinadas funções de modelo de biblioteca padrão não verificam os parâmetros quanto à exatidão. Geralmente, é porque não há informações suficientes disponíveis para a função para verificar os limites do contêiner. Ou, como os iteradores podem ser usados incorretamente com a função. Esse aviso ajuda a identificar essas funções, pois elas podem ser uma fonte de brechas graves de segurança em seu programa. Para obter mais informações, consulte [iteradores marcados](../../standard-library/checked-iterators.md).

Por exemplo, esse aviso aparece no modo de depuração se você passar um ponteiro de elemento para `std::copy`, em vez de uma matriz simples. Para corrigir esse problema, use uma matriz declarada apropriadamente, para que a biblioteca possa verificar as extensões de matriz e fazer a verificação de limites.

```cpp
// C4996_copyarray.cpp
// compile with: cl /c /W4 /D_DEBUG C4996_copyarray.cpp
#include <algorithm>

void example(char const * const src) {
    char dest[1234];
    char * pdest3 = dest + 3;
    std::copy(src, src + 42, pdest3); // C4996
    std::copy(src, src + 42, dest);   // OK, copy can tell that dest is 1234 elements
}
```

Vários algoritmos de biblioteca padrão foram atualizados para ter versões de "intervalo duplo" em C++ 14. Se você usar as versões de intervalo duplo, o segundo intervalo fornecerá a verificação de limites necessários:

```cpp
// C4996_containers.cpp
// compile with: cl /c /W4 /D_DEBUG C4996_containers.cpp
#include <algorithm>

bool example(
    char const * const left,
    const size_t leftSize,
    char const * const right,
    const size_t rightSize)
{
    bool result = false;
    result = std::equal(left, left + leftSize, right); // C4996
    // To fix, try this form instead:
    // result = std::equal(left, left + leftSize, right, right + rightSize); // OK
    return result;
}
```

Este exemplo demonstra várias maneiras mais usadas pela biblioteca padrão para verificar o uso do iterador e quando o uso desmarcado pode ser perigoso:

```cpp
// C4996_standard.cpp
// compile with: cl /EHsc /W4 /MDd C4996_standard.cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v(16);
    iota(v.begin(), v.end(), 0);
    print("v: ", v);

    // OK: vector::iterator is checked in debug mode
    // (i.e. an overrun triggers a debug assertion)
    vector<int> v2(16);
    transform(v.begin(), v.end(), v2.begin(), [](int n) { return n * 2; });
    print("v2: ", v2);

    // OK: back_insert_iterator is marked as checked in debug mode
    // (i.e. an overrun is impossible)
    vector<int> v3;
    transform(v.begin(), v.end(), back_inserter(v3), [](int n) { return n * 3; });
    print("v3: ", v3);

    // OK: array::iterator is checked in debug mode
    // (i.e. an overrun triggers a debug assertion)
    array<int, 16> a4;
    transform(v.begin(), v.end(), a4.begin(), [](int n) { return n * 4; });
    print("a4: ", a4);

    // OK: Raw arrays are checked in debug mode
    // (i.e. an overrun triggers a debug assertion)
    // NOTE: This applies only when raw arrays are
    // given to C++ Standard Library algorithms!
    int a5[16];
    transform(v.begin(), v.end(), a5, [](int n) { return n * 5; });
    print("a5: ", a5);

    // WARNING C4996: Pointers cannot be checked in debug mode
    // (i.e. an overrun triggers undefined behavior)
    int a6[16];
    int * p6 = a6;
    transform(v.begin(), v.end(), p6, [](int n) { return n * 6; });
    print("a6: ", a6);

    // OK: stdext::checked_array_iterator is checked in debug mode
    // (i.e. an overrun triggers a debug assertion)
    int a7[16];
    int * p7 = a7;
    transform(v.begin(), v.end(),
        stdext::make_checked_array_iterator(p7, 16),
        [](int n) { return n * 7; });
    print("a7: ", a7);

    // WARNING SILENCED: stdext::unchecked_array_iterator
    // is marked as checked in debug mode, but it performs no checking,
    // so an overrun triggers undefined behavior
    int a8[16];
    int * p8 = a8;
    transform( v.begin(), v.end(),
        stdext::make_unchecked_array_iterator(p8),
        [](int n) { return n * 8; });
    print("a8: ", a8);
}
```

Se você verificou que seu código não pode ter um erro de saturação de buffer, você pode desativar este aviso. Para desativar os avisos para essas funções, defina **\_SCL\_seguro\_não\_avisos**.

## <a name="checked-iterators-enabled"></a>Iteradores selecionados habilitados

C4996 também pode ocorrer se você não usar um iterador verificado quando `_ITERATOR_DEBUG_LEVEL` for definido como 1 ou 2. Ele é definido como 2 por padrão para compilações de modo de depuração e para 0 para compilações de varejo. Para obter mais informações, consulte [iteradores marcados](../../standard-library/checked-iterators.md).

```cpp
// C4996_checked.cpp
// compile with: /EHsc /W4 /MDd C4996_checked.cpp
#define _ITERATOR_DEBUG_LEVEL 2

#include <algorithm>
#include <iterator>

using namespace std;
using namespace stdext;

int main() {
    int a[] = { 1, 2, 3 };
    int b[] = { 10, 11, 12 };
    copy(a, a + 3, b + 1);   // C4996
    // try the following line instead:
    // copy(a, a + 3, checked_array_iterator<int *>(b, 3));   // OK
}
```

## <a name="unsafe-mfc-or-atl-code"></a>MFC ou código ATL não seguro

C4996 pode ocorrer se você usar as funções MFC ou ATL que foram preteridas por motivos de segurança.

Para corrigir esse problema, é altamente recomendável que você altere seu código para usar funções atualizadas.

Para obter informações sobre como suprimir esses avisos, consulte [_AFX_SECURE_NO_WARNINGS](../../mfc/reference/diagnostic-services.md#afx_secure_no_warnings).

## <a name="obsolete-crt-functions-and-variables"></a>Funções e variáveis CRT obsoletas

**Esta função ou variável foi substituída pela funcionalidade mais recente da biblioteca ou do sistema operacional. Considere usar** *new_item* **em vez disso. Consulte a ajuda online para obter detalhes.**

Algumas funções de biblioteca e variáveis globais são preteridas como obsoletas. Essas funções e variáveis podem ser removidas em uma versão futura da biblioteca. O compilador emite um aviso de substituição para esses itens e sugere a alternativa preferida.

Para corrigir esse problema, recomendamos que você altere seu código para usar a função ou variável sugerida.

Para desativar os avisos de substituição para esses itens, defina **\_CRT\_obsoleto\_nenhum aviso de\_** . Para obter mais informações, consulte a documentação da função ou variável preterida.

## <a name="marshaling-errors-in-clr-code"></a>Marshaling de erros no código CLR

C4996 também pode ocorrer quando você usa a biblioteca de marshaling do CLR. Nesse caso, C4996 é um erro, não um aviso. O erro ocorre quando você usa [marshal_as](../../dotnet/marshal-as.md) para converter entre dois tipos de dados que exigem uma [classe marshal_context](../../dotnet/marshal-context-class.md). Você também pode receber esse erro quando a biblioteca de marshaling não dá suporte a uma conversão. Para obter mais informações sobre a biblioteca de marshaling, consulte [visão geral do C++marshaling no ](../../dotnet/overview-of-marshaling-in-cpp.md).

Este exemplo gera C4996 porque a biblioteca de marshaling requer um contexto para converter de um `System::String` para um `const char *`.

```cpp
// C4996_Marshal.cpp
// compile with: /clr
// C4996 expected
#include <stdlib.h>
#include <string.h>
#include <msclr\marshal.h>

using namespace System;
using namespace msclr::interop;

int main() {
   String^ message = gcnew String("Test String to Marshal");
   const char* result;
   result = marshal_as<const char*>( message );
   return 0;
}
```

## <a name="example-user-defined-deprecated-function"></a>Exemplo: função preterida definida pelo usuário

Você pode usar o atributo preterido em seu próprio código para avisar os chamadores quando não for mais recomendável usar determinadas funções. Neste exemplo, C4996 é gerado em dois locais: um para a linha em que a função preterida é declarada e um para a linha em que a função é usada.

```cpp
// C4996.cpp
// compile with: /W3
// C4996 warning expected
#include <stdio.h>

// #pragma warning(disable : 4996)
void func1(void) {
   printf_s("\nIn func1");
}

[[deprecated]]
void func1(int) {
   printf_s("\nIn func2");
}

int main() {
   func1();
   func1(1);    // C4996
}
```
