---
title: Classe auto_ptr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- memory/std::auto_ptr
- memory/std::auto_ptr::element_type
- memory/std::auto_ptr::get
- memory/std::auto_ptr::release
- memory/std::auto_ptr::reset
dev_langs:
- C++
helpviewer_keywords:
- std::auto_ptr [C++]
- std::auto_ptr [C++], element_type
- std::auto_ptr [C++], get
- std::auto_ptr [C++], release
- std::auto_ptr [C++], reset
ms.assetid: 7f9108b6-9eb3-4634-b615-cf7aa814f23b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 83c211617752a9c9701f513373d8fe796a26a1c6
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33850711"
---
# <a name="autoptr-class"></a>Classe auto_ptr

Encapsula um ponteiro inteligente ao redor de um recurso que garante que o recurso seja destruído automaticamente quando o controle sair de um bloco.

A classe `unique_ptr` mais capacitada substitui `auto_ptr`. Para obter mais informações, consulte [Classe unique_ptr](../standard-library/unique-ptr-class.md).

Para obter mais informações sobre `throw()` e o tratamento de exceções, consulte [Especificações de exceção (gerar)](../cpp/exception-specifications-throw-cpp.md).

## <a name="syntax"></a>Sintaxe

```cpp
class auto_ptr {
public:
    typedef Type element_type;
    explicit auto_ptr(Type* ptr = 0) throw();
    auto_ptr(auto_ptr<Type>& right) throw()
        ;
    template <class Other>
    operator auto_ptr<Other>() throw();
    template <class Other>
    auto_ptr<Type>& operator=(auto_ptr<Other>& right) throw();
    template <class Other>
    auto_ptr(auto_ptr<Other>& right);
    auto_ptr<Type>& operator=(auto_ptr<Type>& right);
    ~auto_ptr();
    Type& operator*() const throw();
    Type * operator->()const throw();
    Type *get() const throw();
    Type *release()throw();
    void reset(Type* ptr = 0);
};
```
### <a name="parameters"></a>Parâmetros

`right` O `auto_ptr` da qual obter um recurso existente.

`ptr` O ponteiro especificado para substituir o ponteiro armazenado.

## <a name="remarks"></a>Comentários

A classe de modelo descreve um ponteiro inteligente, chamado um `auto_ptr`, para um objeto alocado. O ponteiro deve ser nulo ou designar um objeto alocado pelo `new`. O `auto_ptr` transfere a propriedade se o valor armazenado for atribuído a outro objeto. (Ele substitui o valor armazenado após uma transferência com um ponteiro nulo.) O destruidor para `auto_ptr<Type>` exclui o objeto alocado. O `auto_ptr<Type>` garante que um objeto alocado seja excluído automaticamente quando o controle sai de um bloco, mesmo que seja por meio de uma exceção gerada. Você não deve criar dois objetos `auto_ptr<Type>` que detenham o mesmo objeto.

Você pode passar um objeto `auto_ptr<Type>` por valor como um argumento para uma chamada de função. Um `auto_ptr` não pode ser um elemento de nenhum contêiner de Biblioteca Padrão. Você não pode gerenciar confiavelmente uma sequência de objetos `auto_ptr<Type>` com um contêiner de Biblioteca Padrão C++.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[auto_ptr](#auto_ptr)|O construtor para objetos do tipo `auto_ptr`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[element_type](#element_type)|O tipo é um sinônimo do parâmetro de modelo `Type`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[get](#get)|A função membro retorna o ponteiro armazenado `myptr`.|
|[release](#release)|O membro substitui o ponteiro armazenado `myptr` por um ponteiro nulo e retorna o ponteiro armazenado anteriormente.|
|[reset](#reset)|A função membro avalia a expressão `delete myptr`, mas somente se o valor do ponteiro armazenado `myptr` mudar como resultado da chamada de função. Ele substitui o ponteiro armazenado por `ptr`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Um operador de atribuição que transfere a propriedade de um objeto `auto_ptr` para outro.|
|[operator*](#op_star)|O operador de desreferenciamento para objetos do tipo `auto_ptr`.|
|[operator->](#op_arrow)|O operador para permitir o acesso de membro.|
|[operator auto_ptr\<Other>](#op_auto_ptr_lt_other_gt)|Converte de um tipo de `auto_ptr` para outro tipo de `auto_ptr`.|
|[operator auto_ptr_ref\<Other>](#op_auto_ptr_ref_lt_other_gt)|Converte de um `auto_ptr` para um `auto_ptr_ref`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<memory>

**Namespace:** std

## <a name="auto_ptr"></a>  auto_ptr::auto_ptr

O construtor para objetos do tipo `auto_ptr`.

```cpp
explicit auto_ptr(Type* ptr  = 0) throw();

auto_ptr(auto_ptr<Type>& right) throw();

auto_ptr(auto _ptr_ref<Type> right) throw();

template <class Other>
auto _ptr(auto _ptr<Other>& right) throw();
```

### <a name="parameters"></a>Parâmetros

`ptr` O ponteiro para o objeto que `auto_ptr` encapsula.

`right` O `auto_ptr` objeto a ser copiada pelo construtor.

### <a name="remarks"></a>Comentários

Os primeiro construtor armazena `ptr` na **myptr**, o ponteiro armazenado para o objeto alocado. O segundo construtor transfere a propriedade do ponteiro armazenado em `right`, armazenando `right`. [release](#release) em **myptr**.

O terceiro construtor se comporta da mesma maneira que o segundo, exceto que ele armazena **right**. `ref`. **release** em **myptr**, em que `ref` é a referência armazenada em `right`.

O construtor de modelo se comporta da mesma maneira que o segundo construtor, desde que um ponteiro para **Other** possa ser convertido implicitamente em um ponteiro para **Type**.

### <a name="example"></a>Exemplo

```cpp
// auto_ptr_auto_ptr.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Int
{
public:
   Int(int i)
   {
      cout << "Constructing " << ( void* )this  << endl;
      x = i;
      bIsConstructed = true;
   };
   ~Int( )
   {
      cout << "Destructing " << ( void* )this << endl;
      bIsConstructed = false;
   };
   Int &operator++( )
   {
      x++;
      return *this;
   };
   int x;
private:
   bool bIsConstructed;
};

void function ( auto_ptr<Int> &pi )
{
   ++( *pi );
   auto_ptr<Int> pi2( pi );
   ++( *pi2 );
   pi = pi2;
}

int main( )
{
   auto_ptr<Int> pi ( new Int( 5 ) );
   cout << pi->x << endl;
   function( pi );
   cout << pi->x << endl;
}
```

```Output
Constructing 00311AF8
5
7
Destructing 00311AF8
```

## <a name="element_type"></a>  auto_ptr::element_type

O tipo é um sinônimo do parâmetro de modelo **Type**.

```cpp

typedef Type element  _type;
```

## <a name="get"></a>  auto_ptr::get

A função membro retorna o ponteiro armazenado **myptr**.

```cpp
Type *get() const throw();
```

### <a name="return-value"></a>Valor de retorno

O ponteiro armazenado **myptr**.

### <a name="example"></a>Exemplo

```cpp
// auto_ptr_get.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

class Int
{
public:
   Int(int i)
   {
      x = i;
      cout << "Constructing " << ( void* )this  << " Value: " << x << endl;
   };
   ~Int( )
   {
      cout << "Destructing " << ( void* )this << " Value: " << x << endl;
   };

   int x;

};

int main( )
{
   auto_ptr<Int> pi ( new Int( 5 ) );
   pi.reset( new Int( 6 ) );
   Int* pi2 = pi.get ( );
   Int* pi3 = pi.release ( );
   if (pi2 == pi3)
      cout << "pi2 == pi3" << endl;
   delete pi3;
}
```

```Output
Constructing 00311AF8 Value: 5
Constructing 00311B88 Value: 6
Destructing 00311AF8 Value: 5
pi2 == pi3
Destructing 00311B88 Value: 6
```

## <a name="op_eq"></a>  auto_ptr::operator=

Um operador de atribuição que transfere a propriedade de um objeto `auto_ptr` para outro.

```cpp
template <class Other>
auto_ptr<Type>& operator=(auto_ptr<Other>& right) throw();
auto_ptr<Type>& operator=(auto_ptr<Type>& right) throw();
auto_ptr<Type>& operator=(auto_ptr_ref<Type> right) throw();
```

### <a name="parameters"></a>Parâmetros

`right` Um objeto do tipo `auto_ptr`.

### <a name="return-value"></a>Valor de retorno

Uma referência a um objeto do tipo `auto_ptr`\< **Type**>.

### <a name="remarks"></a>Comentários

A atribuição avalia a expressão **delete myptr**, mas apenas se o ponteiro armazenado **myptr** mudar como resultado da atribuição. Ele então transfere a propriedade do ponteiro armazenado em _*Right* armazenando \_ *Right*. [release](#release) em **myptr**. A função retorna **\*this**.

### <a name="example"></a>Exemplo

Para obter um exemplo do uso do operador membro, consulte [auto_ptr::auto_ptr](#auto_ptr).

## <a name="op_star"></a>  auto_ptr::operator*

O operador de desreferenciamento para objetos do tipo `auto_ptr`.

```cpp
Type& operator*() const throw();
```

### <a name="return-value"></a>Valor de retorno

Uma referência a um objeto do tipo **Type** que o ponteiro detém.

### <a name="remarks"></a>Comentários

O operador de indireção retorna `*`[get](#get). Portanto, o ponteiro armazenado não deve ser nulo.

### <a name="example"></a>Exemplo

Para obter um exemplo de como usar a função membro, consulte [auto_ptr::auto_ptr](#auto_ptr).

## <a name="op_arrow"></a>  auto_ptr::operator-&gt;

O operador para permitir o acesso de membro.

```cpp
Type * operator->() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um membro do objeto que **auto_ptr** detém.

### <a name="remarks"></a>Comentários

O operador de seleção retorna [get](#get)`( )`, de modo que a expressão *ap*-> **membro** comporta-se da mesma forma que ( *ap*. **get**( ) )-> **member**, em que *ap* é um objeto da classe `auto_ptr`\< **Type**>. Portanto, o ponteiro armazenado não deve ser nulo e o **Tipo** deve ser uma classe, estrutura ou tipo de união com um membro **membro**.

### <a name="example"></a>Exemplo

Para obter um exemplo de como usar a função membro, consulte [auto_ptr::auto_ptr](#auto_ptr).

## <a name="op_auto_ptr_lt_other_gt"></a>  auto_ptr::operator auto_ptr&lt;Other&gt;

Converte de um tipo de `auto_ptr` para outro tipo de `auto_ptr`.

```cpp
template <class Other>
operator auto _ptr<Other>() throw();
```

### <a name="return-value"></a>Valor de retorno

O tipo operador de conversão retorna `auto_ptr` \< **Other**>( **\*this**).

### <a name="example"></a>Exemplo

```cpp
// auto_ptr_op_auto_ptr.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
   auto_ptr<int> pi ( new int( 5 ) );
   auto_ptr<const int> pc = ( auto_ptr<const int> )pi;
}
```

## <a name="op_auto_ptr_ref_lt_other_gt"></a>  auto_ptr::operator auto_ptr_ref&lt;Other&gt;

Conversões de um `auto_ptr` para um **auto_ptr_ref**.

```cpp
template <class Other>
operator auto _ptr  _ref<Other>() throw();
```

### <a name="return-value"></a>Valor de retorno

O tipo operador de conversão retorna **auto_ptr_ref**\< **Other**>( **\*this**).

### <a name="example"></a>Exemplo

```cpp
// auto_ptr_op_auto_ptr_ref.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class C {
public:
    C(int _i) : m_i(_i) {
    }
    ~C() {
        cout << "~C:  " << m_i << "\n";
    }
    C &operator =(const int &x) {
        m_i = x;
        return *this;
    }
    int m_i;
};
void f(auto_ptr<C> arg) {
};
int main()
{
    const auto_ptr<C> ciap(new C(1));
    auto_ptr<C> iap(new C(2));

    // Error: this implies transfer of ownership of iap's pointer
    // f(ciap);
    f(iap); // compiles, but gives up ownership of pointer

            // here, iap owns a destroyed pointer so the following is bad:
            // *iap = 5; // BOOM

    cout << "main exiting\n";
}
```

```Output
~C:  2
main exiting
~C:  1
```

## <a name="release"></a>  auto_ptr::release

O membro substitui o ponteiro armazenado **myptr** por um ponteiro nulo e retorna o ponteiro armazenado anteriormente.

```cpp
Type *release() throw();
```

### <a name="return-value"></a>Valor de retorno

O ponteiro armazenado anteriormente.

### <a name="remarks"></a>Comentários

O membro substitui o ponteiro armazenado **myptr** por um ponteiro nulo e retorna o ponteiro armazenado anteriormente.

### <a name="example"></a>Exemplo

```cpp
// auto_ptr_release.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

class Int
{
public:
    Int(int i)
    {
        x = i;
        cout << "Constructing " << (void*)this << " Value: " << x << endl;
    };
    ~Int() {
        cout << "Destructing " << (void*)this << " Value: " << x << endl;
    };

    int x;

};

int main()
{
    auto_ptr<Int> pi(new Int(5));
    pi.reset(new Int(6));
    Int* pi2 = pi.get();
    Int* pi3 = pi.release();
    if (pi2 == pi3)
        cout << "pi2 == pi3" << endl;
    delete pi3;
}
```

```Output
Constructing 00311AF8 Value: 5
Constructing 00311B88 Value: 6
Destructing 00311AF8 Value: 5
pi2 == pi3
Destructing 00311B88 Value: 6
```

## <a name="reset"></a>  auto_ptr::reset

A função de membro avalia a expressão **excluir** **myptr**, mas somente se o valor do ponteiro armazenado **myptr** alterações como resultado de uma chamada de função. Ele então substitui o ponteiro armazenado por **ptr**.

```cpp
void reset(Type* ptr = 0);
```

### <a name="parameters"></a>Parâmetros

`ptr` O ponteiro especificado para substituir o ponteiro armazenado **myptr**.

### <a name="example"></a>Exemplo

```cpp
// auto_ptr_reset.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Int
{
public:
    Int(int i)
    {
        x = i;
        cout << "Constructing " << (void*)this << " Value: " << x << endl;
    };
    ~Int()
    {
        cout << "Destructing " << (void*)this << " Value: " << x << endl;
    };

    int x;
};

int main()
{
    auto_ptr<Int> pi(new Int(5));
    pi.reset(new Int(6));
    Int* pi2 = pi.get();
    Int* pi3 = pi.release();
    if (pi2 == pi3)
        cout << "pi2 == pi3" << endl;
    delete pi3;
}
```

```Output
Constructing 00311AF8 Value: 5
Constructing 00311B88 Value: 6
Destructing 00311AF8 Value: 5
pi2 == pi3
Destructing 00311B88 Value: 6
```

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Classe unique_ptr](../standard-library/unique-ptr-class.md)<br/>
