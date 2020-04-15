---
title: Classes de armazenamento (C++)
description: Em C++, as palavras-chave estática, extern e thread_local especificam a localização de vida, vinculação e memória de uma variável ou função.
ms.date: 12/11/2019
f1_keywords:
- thread_local_cpp
- static_cpp
- register_cpp
helpviewer_keywords:
- storage classes [C++], basic concepts
ms.assetid: f10e1c56-6249-4eb6-b08f-09ab1eef1992
ms.openlocfilehash: 75ccb11689b4863d2d0df5edd6d066be6bd3858c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365353"
---
# <a name="storage-classes"></a>Classes de armazenamento

Uma classe de *armazenamento* no contexto das declarações variáveis C++ é um especificador de tipo que rege a vida útil, a vinculação e a localização da memória dos objetos. Um determinado objeto pode ter apenas uma classe de armazenamento. As variáveis definidas dentro de um bloco têm armazenamento automático, a menos que especificado de outra forma usando os especificadores **extern,** **estático**ou **thread_local.** Objetos e variáveis automáticas não têm vinculação; eles não são visíveis para codificar fora do bloco. A memória é alocada para eles automaticamente quando a execução entra no bloco e desaloca da forma quando o bloco é eliminado.

**Observações**

1. A palavra-chave [mutável](../cpp/mutable-data-members-cpp.md) pode ser considerada um especificador de classe de armazenamento. No entanto, ela só está disponível na lista de membros de uma definição de classe.

1. **Visual Studio 2010 e posteriores:** A **palavra-chave automática** não é mais um especificador de classe de armazenamento C++ e a palavra-chave de **registro** é depreciada. **Visual Studio 2017 versão 15.7 e posterior:** (disponível com [/std:c++17](../build/reference/std-specify-language-standard-version.md)): A palavra-chave de **registro** é removida do idioma C++.

```cpp
   register int val; // warning C5033: 'register' is no longer a supported storage class
```

## <a name="static"></a><a name="static"></a>Estático

A palavra-chave **estática** pode ser usada para declarar variáveis e funções no escopo global, escopo de namespace e escopo de classe. Variáveis estáticas também podem ser declaradas no âmbito local.

Duração estática significa que o objeto ou a variável são alocados quando o programa inicia e desalocados quando o programa termina. Vinculação externa significa que o nome da variável é visível fora do arquivo em que a variável é declarada. Por outro lado, a vinculação externa significa que o nome não é visível fora do arquivo em que a variável é declarada. Por padrão, um objeto ou variável definido no namespace global tem duração estática e vinculação externa. A palavra-chave **estática** pode ser usada nas seguintes situações.

1. Quando você declara uma variável ou função no escopo do arquivo (escopo global e/ou namespace), a **palavra-chave estática** especifica que a variável ou função tem ligação interna. Ao declarar uma variável, a variável tem duração estática, e o compilador a inicializa com o valor 0 a menos que você especifique outro valor.

1. Quando você declara uma variável em uma função, a palavra-chave **estática** especifica que a variável retém seu estado entre chamadas para essa função.

1. Quando você declara um membro de dados em uma declaração de classe, a palavra-chave **estática** especifica que uma cópia do membro é compartilhada por todas as instâncias da classe. Um membro de dados static deve ser definido no escopo do arquivo. Um membro de dados integral que você declara como **estático const** pode ter um inicializador.

1. Quando você declara uma função de membro em uma declaração de classe, a palavra-chave **estática** especifica que a função é compartilhada por todas as instâncias da classe. Uma função de membro estático não pode acessar um membro de instância porque a função não tem um ponteiro **implícito.** Para acessar um membro de instância, declare a função com um parâmetro que seja um ponteiro ou uma referência de instância.

1. Não é possível declarar os membros de uma união como estáticos. No entanto, uma união anônima declarada globalmente deve ser explicitamente declarada **estática.**

Este exemplo mostra como uma variável declarada **estática** em uma função retém seu estado entre chamadas para essa função.

```cpp
// static1.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
void showstat( int curr ) {
   static int nStatic;    // Value of nStatic is retained
                          // between each function call
   nStatic += curr;
   cout << "nStatic is " << nStatic << endl;
}

int main() {
   for ( int i = 0; i < 5; i++ )
      showstat( i );
}
```

```Output
nStatic is 0
nStatic is 1
nStatic is 3
nStatic is 6
nStatic is 10
```

Este exemplo mostra o uso de **estática** em uma classe.

```cpp
// static2.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class CMyClass {
public:
   static int m_i;
};

int CMyClass::m_i = 0;
CMyClass myObject1;
CMyClass myObject2;

int main() {
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;

   myObject1.m_i = 1;
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;

   myObject2.m_i = 2;
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;

   CMyClass::m_i = 3;
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;
}
```

```Output
0
0
1
1
2
2
3
3
```

Este exemplo mostra uma variável local declarada **estática** em uma função de membro. A variável estática está disponível para o programa inteiro; todas as instâncias do tipo compartilham a mesma cópia da variável estática.

```cpp
// static3.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
struct C {
   void Test(int value) {
      static int var = 0;
      if (var == value)
         cout << "var == value" << endl;
      else
         cout << "var != value" << endl;

      var = value;
   }
};

int main() {
   C c1;
   C c2;
   c1.Test(100);
   c2.Test(100);
}
```

```Output
var != value
var == value
```

A partir de C++11, uma inicialização de variável local estática é garantida como segura de rosca. Esse recurso às vezes é chamado *de estática mágica.* No entanto, em um aplicativo multithreaded todas as atribuições subseqüentes devem ser sincronizadas. O recurso de inicialização estática seguro por rosca pode ser desativado usando o sinalizador [/Zc:threadSafeInit para](../build/reference/zc-threadsafeinit-thread-safe-local-static-initialization.md) evitar uma dependência do CRT.

## <a name="extern"></a><a name="extern"></a>Extern

Objetos e variáveis declarados como **extern** declaram um objeto definido em outra unidade de tradução ou em um escopo de fechamento como tendo linkagem externa. Para obter mais informações, consulte [unidades extern](extern-cpp.md) e [de tradução e vinculação](program-and-linkage-cpp.md).

## <a name="thread_local-c11"></a><a name="thread_local"></a>thread_local (C++11)

Uma variável declarada com o **thread_local** especificador é acessível apenas no segmento em que é criado. A variável é criada quando o segmento é criado e destruído quando o segmento é destruído. Cada segmento tem sua própria cópia da variável. No Windows, **thread_local** é funcionalmente equivalente ao atributo [__declspec específico da](../cpp/thread.md) Microsoft.

```cpp
thread_local float f = 42.0; // Global namespace. Not implicitly static.

struct S // cannot be applied to type definition
{
    thread_local int i; // Illegal. The member must be static.
    thread_local static char buf[10]; // OK
};

void DoSomething()
{
    // Apply thread_local to a local variable.
    // Implicitly "thread_local static S my_struct".
    thread_local S my_struct;
}
```

Coisas a notar sobre **o** thread_local especificador:

- Variáveis locais de thread inicializadas dinamicamente em DLLs podem não ser corretamente inicializadas em todos os segmentos de chamada. Para obter mais informações, veja [thread](thread.md).

- O **thread_local** especificador pode ser combinado com **estática** ou **extern**.

- Você pode aplicar **thread_local** apenas a declarações e definições de dados; **thread_local** não podem ser usados em declarações ou definições de funções.

- Você pode especificar **thread_local** somente em itens de dados com duração de armazenamento estático. Isso inclui objetos de dados globais **(estática séptico sépticos** e **extern),** objetos estáticos locais e membros de dados estáticos de classes. Qualquer variável local declarada **thread_local** é implicitamente estática se nenhuma outra classe de armazenamento for fornecida; em outras palavras, no escopo `thread_local static`de bloco **thread_local** equivale a .

- Você deve especificar **thread_local** tanto para a declaração quanto para a definição de um objeto local de segmento, se a declaração e a definição ocorrem no mesmo arquivo ou arquivos separados.

No Windows, **thread_local** é funcionalmente equivalente a [__declspec(thread)](../cpp/thread.md) exceto que **__declspec(thread)** pode ser aplicada a uma definição de tipo e é válida em código C. Sempre que possível, use **thread_local** porque faz parte do padrão C++ e, portanto, é mais portátil.

## <a name="register"></a><a name="register"></a>Registrar

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std:c++17](../build/reference/std-specify-language-standard-version.md)): A palavra-chave **de registro** não é mais uma classe de armazenamento suportada. A palavra-chave ainda está reservada no padrão para uso futuro.

```cpp
   register int val; // warning C5033: 'register' is no longer a supported storage class
```

## <a name="example-automatic-vs-static-initialization"></a>Exemplo: inicialização automática vs. estática

Um objeto ou uma variável local automática são inicializados cada vez que o fluxo de controle alcança sua definição. Um objeto ou uma variável local estática são inicializados na primeira vez que o fluxo de controle alcança sua definição.

Considere o exemplo a seguir, que define uma classe que registra a inicialização e a destruição de objetos e depois define três objetos, `I1`, `I2` e `I3`:

```cpp
// initialization_of_objects.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>
using namespace std;

// Define a class that logs initializations and destructions.
class InitDemo {
public:
    InitDemo( const char *szWhat );
    ~InitDemo();

private:
    char *szObjName;
    size_t sizeofObjName;
};

// Constructor for class InitDemo
InitDemo::InitDemo( const char *szWhat ) :
    szObjName(NULL), sizeofObjName(0) {
    if ( szWhat != 0 && strlen( szWhat ) > 0 ) {
        // Allocate storage for szObjName, then copy
        // initializer szWhat into szObjName, using
        // secured CRT functions.
        sizeofObjName = strlen( szWhat ) + 1;

        szObjName = new char[ sizeofObjName ];
        strcpy_s( szObjName, sizeofObjName, szWhat );

        cout << "Initializing: " << szObjName << "\n";
    }
    else {
        szObjName = 0;
    }
}

// Destructor for InitDemo
InitDemo::~InitDemo() {
    if( szObjName != 0 ) {
        cout << "Destroying: " << szObjName << "\n";
        delete szObjName;
    }
}

// Enter main function
int main() {
    InitDemo I1( "Auto I1" ); {
        cout << "In block.\n";
        InitDemo I2( "Auto I2" );
        static InitDemo I3( "Static I3" );
    }
    cout << "Exited block.\n";
}
```

```Output
Initializing: Auto I1
In block.
Initializing: Auto I2
Initializing: Static I3
Destroying: Auto I2
Exited block.
Destroying: Auto I1
Destroying: Static I3
```

Este exemplo demonstra como `I1`e `I2`quando `I3` os objetos , e são inicializados e quando são destruídos.

Há vários pontos a serem observados sobre o programa:

- Primeiro, `I1` e `I2` são destruídos automaticamente quando o fluxo de controle sai do bloco em que estão definidos.

- Depois, em C++, não é necessário declarar objetos ou variáveis no início de um bloco. Além disso, esses objetos são inicializados somente quando o fluxo de controle atinge suas definições. (`I2` `I3` e são exemplos de tais definições.) A saída mostra exatamente quando são inicializadas.

- Por fim, as variáveis locais estáticas, como `I3`, retêm seus valores enquanto o programa dura, mas são destruídas quando o programa é encerrado.

## <a name="see-also"></a>Confira também

[Declarações e definições](../cpp/declarations-and-definitions-cpp.md)
