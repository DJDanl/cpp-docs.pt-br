---
title: Declarações de classe aninhada
ms.date: 11/04/2016
helpviewer_keywords:
- classes [C++], declaring
- declarations, class
- nested classes [C++]
- nested classes [C++], declaring
- declaring classes [C++]
- declarations, nested classes
ms.assetid: c02e471d-b7f9-41b8-8ef6-2323f006dbd5
ms.openlocfilehash: 0ffe1077da76d7524ce99d825e97f68a031ca315
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301546"
---
# <a name="nested-class-declarations"></a>Declarações de classe aninhada

Uma classe pode ser declarada dentro do escopo de outra classe. Essa classe é chamada de “classe aninhada”. As classes aninhadas são consideradas como estando dentro do escopo da classe delimitadora e estão disponíveis para uso dentro desse escopo. Para fazer referência a uma classe aninhada a partir de um escopo diferente de seu escopo delimitador imediato, você deve usar um nome totalmente qualificado.

O exemplo a seguir mostra como declarar as classes aninhadas:

```cpp
// nested_class_declarations.cpp
class BufferedIO
{
public:
   enum IOError { None, Access, General };

   // Declare nested class BufferedInput.
   class BufferedInput
   {
   public:
      int read();
      int good()
      {
         return _inputerror == None;
      }
   private:
       IOError _inputerror;
   };

   // Declare nested class BufferedOutput.
   class BufferedOutput
   {
      // Member list
   };
};

int main()
{
}
```

`BufferedIO::BufferedInput` e `BufferedIO::BufferedOutput` são declaradas dentro `BufferedIO`. Esses nomes de classe não são visíveis fora do escopo da classe `BufferedIO`. No entanto, um objeto do tipo `BufferedIO` não contém nenhum objetos dos tipos `BufferedInput` ou `BufferedOutput`.

As classes aninhadas podem usar diretamente nomes, nomes de tipo, nomes de membros estáticos e enumeradores apenas da classe delimitadora. Para usar nomes de outros membros de classe, você deve usar ponteiros, referências ou nomes de objeto.

No exemplo de `BufferedIO` anterior, a enumeração `IOError` pode ser acessada diretamente por funções membro nas classes aninhadas, `BufferedIO::BufferedInput` ou `BufferedIO::BufferedOutput`, conforme mostrado na função `good`.

> [!NOTE]
>  As classes aninhadas declaram apenas os tipos dentro do escopo da classe. Elas não causam a criação de objetos contidos da classe aninhada. O exemplo anterior declara duas classes aninhadas, mas não declara objetos desses tipos de classe.

Uma exceção à visibilidade do escopo de uma declaração de classe aninhada é quando num nome de tipo é declarado junto com uma declaração de encaminhamento.  Nesse caso, o nome da classe declarada pela declaração de encaminhamento é visível fora da classe delimitadora, com seu escopo definido como o menor escopo delimitador que não seja da classe.  Por exemplo:

```cpp
// nested_class_declarations_2.cpp
class C
{
public:
    typedef class U u_t; // class U visible outside class C scope
    typedef class V {} v_t; // class V not visible outside class C
};

int main()
{
    // okay, forward declaration used above so file scope is used
    U* pu;

    // error, type name only exists in class C scope
    u_t* pu2; // C2065

    // error, class defined above so class C scope
    V* pv; // C2065

    // okay, fully qualified name
    C::V* pv2;
}
```

## <a name="access-privilege-in-nested-classes"></a>Privilégio de acesso em classes aninhadas

O aninhamento de uma classe dentro de outra não concede privilégios de acesso especiais às funções membro da classe aninhada. Da mesma forma, as funções membro da classe delimitadora não têm acesso especial a membros da classe aninhada.

## <a name="member-functions-in-nested-classes"></a>Funções de membro em classes aninhadas

As funções de membro declaradas em classes aninhadas podem ser definidas no escopo do arquivo. O exemplo anterior poderia ter sido escrito:

```cpp
// member_functions_in_nested_classes.cpp
class BufferedIO
{
public:
    enum IOError { None, Access, General };
    class BufferedInput
    {
    public:
        int read(); // Declare but do not define member
        int good(); //  functions read and good.
    private:
        IOError _inputerror;
    };

    class BufferedOutput
    {
        // Member list.
    };
};
// Define member functions read and good in
//  file scope.
int BufferedIO::BufferedInput::read()
{
   return(1);
}

int BufferedIO::BufferedInput::good()
{
    return _inputerror == None;
}
int main()
{
}
```

No exemplo anterior, o *nome de tipo qualificado* sintaxe é usada para declarar o nome da função. Esta declaração:

```cpp
BufferedIO::BufferedInput::read()
```

significa que “a função `read`, que é um membro da classe `BufferedInput` e que está no escopo da classe `BufferedIO`”. Como essa declaração usa o *nome de tipo qualificado* sintaxe, constructos do formulário a seguir são possíveis:

```cpp
typedef BufferedIO::BufferedInput BIO_INPUT;

int BIO_INPUT::read()
```

A declaração anterior é equivalente ao anterior, mas usa uma **typedef** nome no lugar dos nomes de classe.

## <a name="friend-functions-in-nested-classes"></a>Funções Friend em classes aninhadas

As funções friend declaradas em uma classe aninhada são consideradas como pertencentes ao escopo da classe aninhada, não à classe delimitadora. Portanto, as funções friend não ganham privilégios de acesso especiais aos membros ou às funções de membro da classe delimitadora. Se você quiser usar um nome que seja declarado em uma classe aninhada em uma função friend e essa função estiver definida no escopo do arquivo, use nomes de tipos qualificados da seguinte maneira:

```cpp
// friend_functions_and_nested_classes.cpp

#include <string.h>

enum
{
    sizeOfMessage = 255
};

char *rgszMessage[sizeOfMessage];

class BufferedIO
{
public:
    class BufferedInput
    {
    public:
        friend int GetExtendedErrorStatus();
        static char *message;
        static int  messageSize;
        int iMsgNo;
   };
};

char *BufferedIO::BufferedInput::message;
int BufferedIO::BufferedInput::messageSize;

int GetExtendedErrorStatus()
{
    int iMsgNo = 1; // assign arbitrary value as message number

    strcpy_s( BufferedIO::BufferedInput::message,
              BufferedIO::BufferedInput::messageSize,
              rgszMessage[iMsgNo] );

    return iMsgNo;
}

int main()
{
}
```

O código a seguir mostra a função `GetExtendedErrorStatus` declarada como uma função friend. Na função, que é definida no escopo do arquivo, uma mensagem é copiada de uma matriz estática para um membro da classe. Uma implementação melhor de `GetExtendedErrorStatus` é declará-lo como:

```cpp
int GetExtendedErrorStatus( char *message )
```

Com a interface anterior, várias classes podem usar os serviços dessa função transmitindo um local de memória para o qual querem que a mensagem de erro seja copiada.

## <a name="see-also"></a>Consulte também

[Classes e Structs](../cpp/classes-and-structs-cpp.md)