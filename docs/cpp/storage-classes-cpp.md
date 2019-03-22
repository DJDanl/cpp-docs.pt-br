---
title: Classes de armazenamento (C++)
ms.date: 11/04/2016
f1_keywords:
- thread_local_cpp
- external_cpp
- static_cpp
- register_cpp
helpviewer_keywords:
- storage classes [C++], basic concepts
ms.assetid: f10e1c56-6249-4eb6-b08f-09ab1eef1992
ms.openlocfilehash: e50e5da5ea24d59131f123bb0c772897f9a30218
ms.sourcegitcommit: c1f646c8b72f330fa8cf5ddb0f8f261ba10d16f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2019
ms.locfileid: "58329020"
---
# <a name="storage-classes-c"></a>Classes de armazenamento (C++)

Um *classe de armazenamento* no contexto do C++ declarações de variável é um especificador de tipo que rege o local de memória, vinculação e tempo de vida dos objetos. Um determinado objeto pode ter apenas uma classe de armazenamento. As variáveis definidas em um bloco têm armazenamento automático, a menos que especificado de outra forma usando o **extern**, **estático**, ou `thread_local` especificadores. Variáveis e objetos automáticos não têm nenhuma vinculação; eles não são visíveis para o código fora do bloco.

**Observações**

1. O [mutável](../cpp/mutable-data-members-cpp.md) palavra-chave pode ser considerada um especificador de classe de armazenamento. No entanto, ela só está disponível na lista de membros de uma definição de classe.

1. **Visual C++ 2010 e posterior:** O **automática** palavra-chave não é mais um especificador de classe de armazenamento do C++ e o **registrar** palavra-chave é preterida. **Visual Studio 2017 versão 15.7 e posterior:** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): O **registrar** palavra-chave é removida da linguagem C++.

```cpp
   register int val; // warning C5033: 'register' is no longer a supported storage class
```

## <a name="in-this-section"></a>Nesta seção:

- [static](#static)
- [extern](#extern)
- [thread_local](#thread_local)

## <a name="static"></a> Estático

O **estático** palavra-chave pode ser usado para declarar variáveis e funções no escopo global, o escopo de namespace e o escopo da classe. Variáveis estáticas também podem ser declaradas no escopo local.

Duração estática significa que o objeto ou a variável são alocados quando o programa inicia e desalocados quando o programa termina. Vinculação externa significa que o nome da variável é visível fora do arquivo em que a variável é declarada. Por outro lado, a vinculação externa significa que o nome não é visível fora do arquivo em que a variável é declarada. Por padrão, um objeto ou variável que é definida no namespace global tem duração estática e vinculação externa. O **estático** palavra-chave pode ser usado nas seguintes situações.

1. Quando você declara uma variável ou função no escopo do arquivo (global e/ou escopo de namespace), o **estático** palavra-chave especifica que a variável ou função tem vinculação interna. Ao declarar uma variável, a variável tem duração estática, e o compilador a inicializa com o valor 0 a menos que você especifique outro valor.

1. Quando você declara uma variável em uma função, o **estático** palavra-chave especifica que a variável manterá seu estado entre chamadas para a função.

1. Quando você declara um membro de dados em uma declaração de classe, o **estático** palavra-chave especifica que uma cópia do membro é compartilhada por todas as instâncias da classe. Um membro de dados static deve ser definido no escopo do arquivo. Um membro de dados integrais que você declara como **const estático** pode ter um inicializador.

1. Quando você declara uma função de membro em uma declaração de classe, o **estático** palavra-chave especifica que a função é compartilhada por todas as instâncias da classe. Uma função de membro estático não pode acessar um membro de instância porque a função não tem implícito **isso** ponteiro. Para acessar um membro de instância, declare a função com um parâmetro que seja um ponteiro ou uma referência de instância.

1. Não é possível declarar os membros de uma união como estáticos. No entanto, uma união anônima globalmente declarada deve ser declarada explicitamente **estático**.

Este exemplo mostra como uma variável declarada **estático** em uma função mantém o estado entre chamadas para a função.

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

Este exemplo mostra o uso de **estático** em uma classe.

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

Este exemplo mostra uma variável local declarada **estático** em uma função de membro. A variável estática está disponível para o programa inteiro; todas as instâncias do tipo compartilham a mesma cópia da variável estática.

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

A partir do c++11, uma inicialização de variável local estática é garantida para ser thread-safe. Esse recurso às vezes é chamado *mágica estática*. No entanto, em um aplicativo multithreaded todas as atribuições subsequentes devem ser sincronizadas. O recurso de inicialização estática de thread-safe pode ser desabilitado usando o [/Zc:threadSafeInit-](../build/reference/zc-threadsafeinit-thread-safe-local-static-initialization.md) sinalizador para evitar uma dependência no CRT.

## <a name="extern"></a> extern

Objetos e as variáveis declaradas como **extern** declarar um objeto que é definido em outra unidade de tradução ou em um escopo delimitador como tendo vinculação externa.

Declaração de **const** variáveis com o **extern** força a classe de armazenamento a variável para ter vinculação externa. Uma inicialização de um **extern const** variável é permitida na unidade de tradução de definição. As inicializações das unidades de tradução diferentes da unidade de tradução de definição geram resultados indefinidos. Para obter mais informações, consulte [usando extern para especificar ligação](../cpp/using-extern-to-specify-linkage.md)

O [/ZC: externconstexpr](../build/reference/zc-externconstexpr.md) opção de compilador faz o compilador aplique [vinculação externa](../c-language/external-linkage.md) para as variáveis declaradas usando `extern constexpr`. Em versões anteriores do Visual Studio e, por padrão ou se **/Zc:externConstexpr-** for especificado, vinculação interna para o Visual Studio aplicará **constexpr** mesmo variáveis a **extern** palavra-chave é usada. O **/ZC: externconstexpr** opção está disponível a partir do Visual Studio 2017 15.6 de atualização. e é desativado por padrão. O /permissive-option não habilita /ZC: externconstexpr.

O código a seguir mostra duas **extern** declarações, `DefinedElsewhere` (que se refere a um nome definido em uma unidade de tradução diferente) e `DefinedHere` (que se refere a um nome definido em um escopo delimitador):

```cpp
// external.cpp
// DefinedElsewhere is defined in another translation unit
extern int DefinedElsewhere;
int main() {
   int DefinedHere;
   {
      // refers to DefinedHere in the enclosing scope
      extern int DefinedHere;
   }
}
```

## <a name="thread_local"></a> thread_local (c++11)

Uma variável declarada com o `thread_local` especificador é acessível somente no thread no qual ele é criado. A variável é criada quando o thread é criado e destruído quando o thread é destruído. Cada thread tem sua própria cópia da variável. No Windows, `thread_local` é funcionalmente equivalente à específicos da Microsoft [declspec (thread)](../cpp/thread.md) atributo.

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

Coisas a observar sobre o `thread_local` especificador:

- Variáveis de thread local dinamicamente inicializadas em DLLs podem não ser inicializadas corretamente em todos os threads de chamada. Para obter mais informações, veja [thread](thread.md).

- O `thread_local` especificador pode ser combinada com **estáticos** ou **extern**.

- Você pode aplicar `thread_local` somente a declarações de dados e as definições. `thread_local` não pode ser usado em definições ou declarações de função.

- Você pode especificar `thread_local` apenas em itens de dados com duração de armazenamento estático. Isso inclui objetos de dados globais (ambos **estáticos** e **extern**), objetos estáticos locais e membros de dados estáticos de classes. Qualquer variável local declarada `thread_local` é implicitamente estático se nenhuma outra classe de armazenamento é fornecida; em outras palavras, no escopo de bloco `thread_local` é equivalente a `thread_local static`.

- Você deve especificar `thread_local` para a declaração e a definição de um objeto de thread local, se a declaração e a definição ocorrem no mesmo arquivo ou em arquivos separados.

No Windows, `thread_local` é funcionalmente equivalente à [__declspec(thread)](../cpp/thread.md) exceto que **__declspec(thread)** pode ser aplicado a uma definição de tipo e é válido no código C. Sempre que possível, use `thread_local` porque ele faz parte do C++ padrão e, portanto, é mais portátil.

##  <a name="register"></a>  register

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): O **registrar** palavra-chave não é uma classe de armazenamento com suporte. A palavra-chave é preservada no padrão para uso futuro.

```cpp
   register int val; // warning C5033: 'register' is no longer a supported storage class
```

## <a name="example-automatic-vs-static-initialization"></a>Exemplo: automático versus inicialização estática

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

Este exemplo demonstra como e quando os objetos `I1`, `I2`, e `I3` são inicializados e quando eles são destruídos.

Há vários pontos a observar sobre o programa:

- Primeiro, `I1` e `I2` são destruídos automaticamente quando o fluxo de controle sai do bloco em que estão definidos.

- Depois, em C++, não é necessário declarar objetos ou variáveis no início de um bloco. Além disso, esses objetos são inicializados somente quando o fluxo de controle atinge suas definições. (`I2` e `I3` são exemplos de tais definições.) A saída mostra exatamente quando eles são inicializados.

- Por fim, as variáveis locais estáticas, como `I3`, retêm seus valores enquanto o programa dura, mas são destruídas quando o programa é encerrado.

## <a name="see-also"></a>Consulte também

[Declarações e definições](../cpp/declarations-and-definitions-cpp.md)