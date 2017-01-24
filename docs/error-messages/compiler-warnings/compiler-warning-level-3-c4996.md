---
title: "Compilador (n&#237;vel 3) aviso C4996 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4996"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4996"
ms.assetid: 926c7cc2-921d-43ed-ae75-634f560dd317
caps.latest.revision: 34
caps.handback.revision: 34
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador (n&#237;vel 3) aviso C4996
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O compilador encontrou uma declaração preterida.  
  
 Esse aviso ou erro tem vários significados possíveis.  
  
 `C4996` ocorre quando o compilador encontra uma função ou variável que está marcado como [preterido](../../cpp/deprecated-cpp.md). Várias funções, funções de membro, funções de modelo e variáveis globais nas bibliotecas no Visual Studio são marcados como substituídos. Essas funções podem ter um nome diferente de preferência, pode não ser segura ou tem uma variante mais segura, ou pode estar obsoleto. A mensagem de erro pode incluir uma substituição sugerida para a função preterida ou variável global. Você pode desativar esse aviso com a [Aviso](../../preprocessor/warning.md) pragma ou **\/wd4996** opção de linha de comando. Você também pode usar macros de pré\-processador para desativar determinadas classes de avisos de depreciação.  
  
 **O nome POSIX para este item foi preterido. Em vez disso, use o nome em conformidade com ISO C e C\+\+:** novo\_nome**. Consulte a Ajuda online para obter detalhes.**  
  
 Algumas funções POSIX no CRT foram renomeadas para estar de acordo com C99 e C \+ \+ 03 regras para nomes de função global definido pela implementação. Na maioria dos casos, um sublinhado à esquerda foi adicionado ao nome da função POSIX para criar um nome de conformidade padrão. O compilador emite um aviso de substituição para os nomes de função original e sugere o nome preferido. Somente os nomes originais são substituídos, não as próprias funções. Para desativar avisos de depreciação para essas funções, defina a macro do pré\-processador **\_CRT\_NONSTDC\_NO\_WARNINGS**. Você pode definir isso na linha de comando, incluindo a opção `/D_CRT_NONSTDC_NO_WARNINGS`. Para definir essa macro no Visual Studio, abra o **páginas de propriedade** caixa de diálogo para seu projeto. Expanda **Propriedades de configuração**, **C\/C\+\+**, **pré\-processador**. Em **definições de pré\-processador**, adicionar `_CRT_NONSTDC_NO_WARNINGS`. Escolha **OK** para salvar e, em seguida, recrie seu projeto. Para definir essa macro apenas nos arquivos de origem específico, adicione a linha `#define _CRT_NONSTDC_NO_WARNINGS` antes de qualquer linha que inclui um arquivo de cabeçalho.  
  
 **Essa função ou variável pode não ser seguro. Considere o uso**  safe\_version **em vez disso. Para desativar a substituição, use \_CRT\_SECURE\_NO\_WARNINGS.  Consulte a Ajuda online para obter detalhes.**  
  
 Algumas funções de CRT e a biblioteca C\+\+ padrão e globais foram preteridas e funções novas e mais seguras. O compilador emite um aviso de substituição para essas funções e sugere a função preferencial. Para desativar avisos de depreciação para essas funções no CRT, definir **\_CRT\_SECURE\_NO\_WARNINGS**. Para desativar avisos sobre variáveis globais preteridos, definir **\_CRT\_SECURE\_NO\_WARNINGS\_GLOBALS**. Para obter mais informações sobre essas funções preteridas e globais, consulte [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md) e [Bibliotecas seguras: Biblioteca Padrão C\+\+](../../standard-library/safe-libraries-cpp-standard-library.md).  
  
 **Chamada de função com parâmetros que podem ser seguros – essa chamada depende do chamador para verificar se os valores passados estão corretos. Para desativar esse aviso, use \- D\_SCL\_SECURE\_NO\_WARNINGS. Consulte a documentação sobre como usar o Visual C\+\+ 'Iteradores verificados'**  
  
 Determinadas funções de modelo da biblioteca padrão C\+\+ não verificam os parâmetros estão corretos. Esse aviso ajuda a identificar o uso dessas funções. Para desativar avisos para essas funções, definir **\_SCL\_SECURE\_NO\_WARNINGS**. Para obter mais informações, consulte [Iteradores Verificados](../../standard-library/checked-iterators.md).  
  
 **Essa função ou variável foi substituído pela funcionalidade de biblioteca ou sistema operacional mais recente. Considere o uso** new\_item **em vez disso. Consulte a Ajuda online para obter detalhes.**  
  
 Algumas funções de biblioteca e variáveis globais são preteridos como obsoleto. Essas funções e variáveis podem ser removidas em uma versão futura da biblioteca. O compilador emite um aviso de substituição para esses itens e sugere a alternativa preferida. Para desativar avisos de depreciação para esses itens, definir **\_CRT\_OBSOLETE\_NO\_WARNINGS**. Para obter mais informações, consulte a documentação para a função preterida ou variável.  
  
 **Várias mensagens no código do MFC ou ATL**  
  
 `C4996` também pode ocorrer se você usar funções MFC ou ATL preteridas por razões de segurança. Para suprimir esses avisos, consulte [\_AFX\_SECURE\_NO\_WARNINGS](../Topic/_AFX_SECURE_NO_WARNINGS.md) e [\_ATL\_SECURE\_NO\_WARNINGS](../Topic/_ATL_SECURE_NO_WARNINGS.md).  
  
 **Empacotamento de erros no código do CLR**  
  
 `C4996` também pode ocorrer quando você usar a biblioteca de marshaling. Nesse caso, C4996 é um erro, não um aviso. Este erro ocorre quando você usa [marshal\_as](../../dotnet/marshal-as.md) para converter entre dois tipos de dados que exigem um [Classe marshal\_context](../../dotnet/marshal-context-class.md). Você também receberá esse erro quando a biblioteca de marshaling não dá suporte a uma conversão. Para obter mais informações sobre a biblioteca de marshaling, consulte [Visão geral de marshaling no C\+\+](../../dotnet/overview-of-marshaling-in-cpp.md).  
  
 **Exemplos que geram C4996**  
  
 No primeiro exemplo, `C4996` é gerado para a linha em que a função é declarada e para a linha na qual a função é usada.  
  
## Exemplo  
 O exemplo a seguir gera C4996.  
  
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
   func1(1);  
}  
```  
  
## Exemplo  
 C4996 também pode ocorrer se você não usar um iterador verificado durante a compilação com `_ITERATOR_DEBUG_LEVEL` definido \(definido como 1 por padrão para compilações de modo de depuração\).  Consulte [Iteradores Verificados](../../standard-library/checked-iterators.md) para obter mais informações.  
  
 O exemplo de código STL gera C4996.  
  
```cpp  
// C4996_b.cpp  
// compile with: /EHsc /W3 /c  
#define _ITERATOR_DEBUG_LEVEL 1  
  
#include <algorithm>  
#include <iterator>  
  
using namespace std;  
using namespace stdext;  
  
int main() {  
    int a[] = { 1, 2, 3 };  
    int b[] = { 10, 11, 12 };  
    copy(a, a + 3, b + 1);   // C4996  
    // try the following line instead  
    //   copy(a, a + 3, b);  
    copy(a, a + 3, checked_array_iterator<int *>(b, 3));   // OK  
}  
  
```  
  
## Exemplo  
 O exemplo de código STL gera C4996 como um aviso. Os comentários são embutidos.  
  
```cpp  
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
    // (i.e. an overrun will trigger a debug assertion)  
    vector<int> v2(16);  
    transform(v.begin(), v.end(), v2.begin(), [](int n) { return n * 2; });  
    print("v2: ", v2);  
  
    // OK: back_insert_iterator is marked as checked in debug mode  
    // (i.e. an overrun is impossible)  
    vector<int> v3;  
    transform(v.begin(), v.end(), back_inserter(v3), [](int n) { return n * 3; });  
    print("v3: ", v3);  
  
    // OK: array::iterator is checked in debug mode  
    // (i.e. an overrun will trigger a debug assertion)  
    array<int, 16> a4;  
    transform(v.begin(), v.end(), a4.begin(), [](int n) { return n * 4; });  
    print("a4: ", a4);  
  
    // OK: Raw arrays are checked in debug mode  
    // (i.e. an overrun will trigger a debug assertion)  
    // NOTE: This applies only when raw arrays are given to STL algorithms!  
    int a5[16];  
    transform(v.begin(), v.end(), a5, [](int n) { return n * 5; });  
    print("a5: ", a5);  
  
    // WARNING C4996: Pointers cannot be checked in debug mode  
    // (i.e. an overrun will trigger undefined behavior)  
    int a6[16];  
    int * p6 = a6;  
    transform(v.begin(), v.end(), p6, [](int n) { return n * 6; });  
    print("a6: ", a6);  
  
    // OK: stdext::checked_array_iterator is checked in debug mode  
    // (i.e. an overrun will trigger a debug assertion)  
    int a7[16];  
    int * p7 = a7;  
    transform(v.begin(), v.end(), stdext::make_checked_array_iterator(p7, 16), [](int n) { return n * 7; });  
    print("a7: ", a7);  
  
    // WARNING SILENCED: stdext::unchecked_array_iterator is marked as checked in debug mode  
    // (i.e. it performs no checking, so an overrun will trigger undefined behavior)  
    int a8[16];  
    int * p8 = a8;  
    transform(v.begin(), v.end(), stdext::make_unchecked_array_iterator(p8), [](int n) { return n * 8; });  
    print("a8: ", a8);  
}  
  
```  
  
## Exemplo  
 O exemplo a seguir gera C4996 porque a biblioteca de marshaling requer um contexto para converter de um `System::String` para um `const char *`.  
  
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