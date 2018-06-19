---
title: Compilador (nível 3) do aviso C4996 | Microsoft Docs
ms.custom: ''
ms.date: 11/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4996
dev_langs:
- C++
helpviewer_keywords:
- C4996
ms.assetid: 926c7cc2-921d-43ed-ae75-634f560dd317
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a6af8a8ff3cde50ea8b196e7f293874998547ec0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33315393"
---
# <a name="compiler-warning-level-3-c4996"></a>Compilador C4996 de aviso (nível 3)

O compilador encontrou uma declaração preterida. **Esse aviso é sempre uma mensagem deliberada do autor da biblioteca ou do arquivo de cabeçalho incluído que você não deve usar o símbolo substituído sem entender as consequências.** A mensagem de aviso real é especificada pelo atributo no site da declaração ou o modificador de substituição. 

Essas são algumas mensagens C4996 comuns geradas pela biblioteca de tempo de execução do C e a biblioteca padrão, mas não uma lista completa. Siga os links ou continue lendo para formas de corrigir o problema ou para desativar o aviso. 

- [O nome POSIX para este item está obsoleto. Em vez disso, use o nome em conformidade com ISO C e C++: *novo_nome*. Consulte a ajuda online para obter detalhes.](#posix-function-names)

- [Esta função ou variável pode não ser seguro. Considere o uso de *safe_version* em vez disso. Para desabilitar a substituição, use \_CRT\_seguro\_não\_avisos.  Consulte a ajuda online para obter detalhes.](#unsafe-crt-library-functions)

- [' std::*function_name*::\_desmarcado\_iteradores::\_Deprecate' chamada para std::*function_name*com parâmetros que podem não ser seguros - esta chamada depende o chamador para verificar se os valores passados estão corretos. Para desabilitar esse aviso, use -D_SCL_SECURE_NO_WARNINGS. Consulte a documentação sobre como usar o Visual C++ 'Iteradores verificados'](#unsafe-standard-library-functions)

- [Esta função ou variável foi substituído por funcionalidade de biblioteca ou o sistema operacional mais recente. Considere o uso de *new_item* em vez disso. Consulte a ajuda online para obter detalhes.](#obsolete-crt-functions-and-variables)

## <a name="cause"></a>Causa

C4996 ocorre quando o compilador encontra uma função ou variável que está marcado como [preterido](../../cpp/deprecated-cpp.md) usando um `__declspec(deprecated)` modificador, ou quando você tenta acessar uma função, membro de classe ou um typedef com C++ 14 [ \[ \[preterido\] \] ](../../cpp/attributes.md) atributo. Você pode usar o `__declspec(deprecated)` modificador ou `[[deprecated]]` atributo por conta própria em suas bibliotecas ou arquivos de cabeçalho para avisar os clientes sobre preteridas funções, variáveis, membros ou definições de tipo.

## <a name="remarks"></a>Comentários

Muitas funções, funções de membro, funções de modelo e variáveis globais nas bibliotecas no Visual Studio são marcadas como *preterido*. Essas funções são preteridas porque eles podem ter um nome diferente de preferência, pode ser inseguro ou ter uma variação mais segura, ou pode estar obsoleto. Muitas mensagens de substituição incluem uma substituição sugerida para a função preterida ou a variável global.

Para corrigir esse problema, geralmente recomendamos que alterar seu código para usar as funções sugeridas de mais seguras ou atualizadas e variáveis globais, em vez disso. Se você precisar usar as funções existentes ou variáveis por motivos de portabilidade, o aviso pode ser desativado.

### <a name="to-turn-the-warning-off-without-fixing-the-issue"></a>Para desativar o aviso sem corrigir o problema

Você pode desativar o aviso de uma linha de código específica usando o [aviso](../../preprocessor/warning.md) pragma, `#pragma warning(suppress : 4996)`. Você também pode desativar o aviso dentro de um arquivo usando o pragma de aviso, `#pragma warning(disable : 4996)`.

Você pode desativar o aviso globalmente em compilações de linha de comando usando o **/wd4996** opção de linha de comando.

Para desativar o aviso para um projeto inteiro no IDE do Visual Studio:

- Abra o **páginas de propriedade** caixa de diálogo para seu projeto. Para obter informações sobre como usar a caixa de diálogo páginas de propriedades, consulte [páginas de propriedade](../../ide/property-pages-visual-cpp.md).
- Selecione o **propriedades de configuração**, **C/C++**, **avançado** página.
- Editar o **desativar avisos específicos** propriedade a adicionar `4996`. Escolha **Okey** para aplicar as alterações.

Você também pode usar macros de pré-processador desativar determinadas classes específicas de avisos de depreciação usados nas bibliotecas. Essas macros são descritas abaixo.

Para definir uma macro de pré-processador no Visual Studio:

- Abra o **páginas de propriedade** caixa de diálogo para seu projeto. Para obter informações sobre como usar a caixa de diálogo páginas de propriedades, consulte [páginas de propriedade](../../ide/property-pages-visual-cpp.md).
- Expanda **propriedades de configuração > C/C++ > pré-processador**.
- No **definições de pré-processador** propriedade, adicione o nome da macro. Escolha **Okey** para salvar e, em seguida, recrie seu projeto.

Para definir uma macro somente nos arquivos de origem específico, adicione uma linha como `#define EXAMPLE_MACRO_NAME` antes de qualquer linha que inclui um arquivo de cabeçalho.

## <a name="specific-c4996-messages"></a>Mensagens C4996 específicas

Aqui estão algumas das fontes comuns de erros e avisos C4996.

### <a name="posix-function-names"></a>Nomes de função POSIX

**O nome POSIX para este item está obsoleto. Em vez disso, use o nome em conformidade com ISO C e C++:** *novo_nome*. **Consulte a Ajuda online para obter detalhes.**

Microsoft renomeou algumas funções POSIX no CRT para manter a conformidade com C99 e C + + 03 as regras para nomes de função global definido pela implementação. Somente os nomes POSIX originais são preteridos, não as próprias funções. Na maioria dos casos, um sublinhado à esquerda foi adicionado ao nome da função POSIX para criar um nome de conformidade padrão. O compilador emite um aviso de substituição para o nome de função original e sugere o nome preferido.

Para corrigir esse problema, geralmente recomendamos que alterar seu código para usar os nomes de função sugerido em vez disso. No entanto, os nomes atualizados são específicas da Microsoft. Se você precisar usar os nomes de função existente por motivos de portabilidade, você pode desativar esses avisos. As funções POSIX ainda estão disponíveis na biblioteca em seus nomes originais.

Para desativar os avisos de depreciação para essas funções, defina a macro de pré-processador  **\_CRT\_NONSTDC\_não\_avisos**. Você pode definir esta macro na linha de comando, incluindo a opção `/D_CRT_NONSTDC_NO_WARNINGS`.


### <a name="unsafe-crt-library-functions"></a>Funções de biblioteca CRT inseguras

 **Esta função ou variável pode não ser seguro. Considere o uso de** *safe_version* **em vez disso. Para desabilitar a substituição, use \_CRT\_seguro\_não\_avisos.  Consulte a ajuda online para obter detalhes.**

 Microsoft foi preterido algumas funções de CRT e biblioteca padrão C++ e globais em favor de versões mais seguras. Na maioria dos casos, as funções preteridas permitem desmarcada acesso de leitura ou gravação para buffers, que pode levar a problemas graves de segurança. O compilador emite um aviso de substituição para essas funções e sugere a função preferencial.

 Para corrigir esse problema, recomendamos que você use a função ou variável *safe_version* em vez disso. Se você tiver verificado que não é possível substituir um buffer ou overread ocorra em seu código e você não pode alterar o código por motivos de portabilidade, você pode desativar o aviso.
 
 Para desativar os avisos de depreciação para essas funções no CRT, definir  **\_CRT\_seguro\_não\_avisos**. Para desativar avisos sobre preteridos variáveis globais, definir  **\_CRT\_seguro\_não\_avisos\_globais**. Para obter mais informações sobre essas funções preteridas e globais, consulte [recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md) e [bibliotecas seguras: biblioteca padrão C++](../../standard-library/safe-libraries-cpp-standard-library.md).

### <a name="unsafe-standard-library-functions"></a>Funções de biblioteca padrão não seguras

__' std::__*function_name*__::\_desmarcado\_iteradores::\_Deprecate' chamar std::__*function_name* **com parâmetros que podem não ser seguros - esta chamada depende do chamador para verificar se os valores passados estão corretos. Para desabilitar esse aviso, use -D\_SCL\_seguro\_não\_avisos. Consulte a documentação sobre como usar o Visual C++ 'Iteradores verificados'**

Esse aviso é exibido em compilações de depuração porque determinadas funções de modelo de biblioteca padrão C++ não verificam se os parâmetros estão corretos. Na maioria dos casos, isso é porque não há informações suficientes disponíveis para a função de verificação de limites de contêiner ou iteradores podem ser usados incorretamente, com a função. Esse aviso ajuda a identificar esses usos de função, porque eles podem ser uma fonte de vulnerabilidades de segurança grave em seu programa. Para obter mais informações, consulte [Iteradores verificados](../../standard-library/checked-iterators.md).

Por exemplo, esse aviso é exibido no modo de depuração se você passar um ponteiro de elemento para `std::copy` em vez de uma matriz simples. Para corrigir esse problema, use uma matriz declarada adequadamente, para a biblioteca pode verificar as extensões de matriz e fazer uma verificação de limites.

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

Vários algoritmos de biblioteca padrão foram atualizados para versões de "intervalo duplo" em C++ 14. Se você usar as versões de intervalo duplo, o segundo intervalo fornece a verificação de limites necessários:

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

Este exemplo demonstra várias maneiras mais a biblioteca padrão pode ser usada para verificar o uso de iterador, e ao uso desmarcado pode ser perigoso:

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

Se você verificou que o seu código não pode ter um buffer de saturação de erro nas funções de biblioteca padrão que disparam esse aviso, convém desativar esse aviso. Para desativar os avisos para essas funções, definir  **\_SCL\_seguro\_não\_avisos**.

### <a name="checked-iterators-enabled"></a>Iteradores verificados habilitados

C4996 também poderá ocorrer se você não usar um iterador verificado durante a compilação com `_ITERATOR_DEBUG_LEVEL` definido como 1 ou 2. Ele é definido para 2 por padrão para compilações de modo de depuração e 0 para compilações para venda. Consulte [Iteradores Verificados](../../standard-library/checked-iterators.md) para obter mais informações.

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

### <a name="unsafe-mfc-or-atl-code"></a>Código não seguro MFC ou do ATL

C4996 também poderá ocorrer se você usar funções MFC ou do ATL que foram substituídas por motivos de segurança.

Para corrigir esse problema, recomendamos que você altere seu código para usar funções atualizadas em vez disso.

Para obter informações sobre como suprimir esses avisos, consulte [_AFX_SECURE_NO_WARNINGS](../../mfc/reference/diagnostic-services.md#afx_secure_no_warnings).

### <a name="obsolete-crt-functions-and-variables"></a>Variáveis e funções de CRT obsoletas

**Esta função ou variável foi substituído por funcionalidade de biblioteca ou o sistema operacional mais recente. Considere o uso de** *new_item* **em vez disso. Consulte a ajuda online para obter detalhes.**

Algumas funções de biblioteca e as variáveis globais são preteridas como obsoleto. Essas funções e variáveis podem ser removidos em uma versão futura da biblioteca. O compilador emite um aviso de substituição para esses itens e sugere a opção preferencial.

Para corrigir esse problema, recomendamos que você altere seu código para usar a função sugerida ou variável.

Para desativar os avisos de depreciação para esses itens, definir  **\_CRT\_obsoleto\_não\_avisos**. Para obter mais informações, consulte a documentação para a função preterida ou variável.

### <a name="marshalling-errors-in-clr-code"></a>O empacotamento de erros no código do CLR

C4996 também pode ocorrer quando você usar a biblioteca de marshaling de CLR. Nesse caso, C4996 é um erro, não um aviso. Esse erro ocorre quando você usar [marshal_as](../../dotnet/marshal-as.md) para converter entre os dois tipos de dados que exigem um [classe marshal_context](../../dotnet/marshal-context-class.md). Você também pode receber esse erro quando a biblioteca de marshaling não dá suporte a uma conversão. Para obter mais informações sobre a biblioteca de marshaling, consulte [visão geral de Marshaling no C++](../../dotnet/overview-of-marshaling-in-cpp.md).

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

## <a name="example-user-defined-deprecated-function"></a>Exemplo: Função preterida definido pelo usuário

Você pode usar o atributo substituído em seu próprio código para avisar os chamadores quando você não recomenda o uso de determinadas funções. Neste exemplo, C4996 é gerado para a linha em que a função preterida é declarada e para a linha na qual a função é usada.

```cpp
// C4996.cpp
// compile with: /W3
// C4996 warning expected
#include <stdio.h>

// #pragma warning(disable : 4996)
void func1(void) {
   printf_s("\nIn func1");
}

__declspec(deprecated) void func1(int) {
   printf_s("\nIn func2");
}

int main() {
   func1();
   func1(1);    // C4996
}
```
