---
title: Classe auto_gcroot
ms.date: 01/16/2019
ms.topic: reference
f1_keywords:
- msclr::auto_gcroot::auto_gcroot
- msclr::auto_gcroot::attach
- msclr::auto_gcroot::get
- msclr::auto_gcroot::release
- msclr::auto_gcroot::reset
- msclr::auto_gcroot::swap
- msclr::auto_gcroot::operator=
- msclr::auto_gcroot::operator->
- msclr::auto_gcroot::operator!
- msclr::auto_gcroot::operator auto_gcroot
helpviewer_keywords:
- msclr::auto_gcroot
ms.assetid: b5790912-265d-463e-a486-47302e91042a
ms.openlocfilehash: 87e6703f759888b36ed89daed10df937701c6dbd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372547"
---
# <a name="auto_gcroot-class"></a>Classe auto_gcroot

O gerenciamento automático de recursos (como [auto_ptr Class)](../standard-library/auto-ptr-class.md)que pode ser usado para incorporar uma alça virtual em um tipo nativo.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename _element_type>
class auto_gcroot;
```

### <a name="parameters"></a>Parâmetros

*_element_type*<br/>
O tipo gerenciado a ser incorporado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|---------|-----------|
|[auto_gcroot:auto_gcroot](#auto-gcroot)|O `auto_gcroot` construtor.|
|[auto_gcroot::~auto_gcroot](#tilde-auto-gcroot)|O `auto_gcroot` destruidor.
|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|---------|-----------|
|[auto_gcroot::attach](#attach)|Anexar `auto_gcroot` a um objeto.|
|[auto_gcroot::get](#get)|Pega o objeto contido.|
|[auto_gcroot::release](#release)|Libera o objeto `auto_gcroot` da gestão.|
|[auto_gcroot::reset](#reset)|Destrua o objeto de propriedade atual e, opcionalmente, tome posse de um novo objeto.|
|[auto_gcroot::swap](#swap)|Troca objetos `auto_gcroot`por outro .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|---------|-----------|
|[auto_gcroot::operador-&gt;](#operator-arrow)|O operador de acesso de membros.|  
|[auto_gcroot::operator=](#operator-assign)|Operador de atribuição.|
|[auto_gcroot:auto_gcroot&nbsp;do operador](#operator-auto-gcroot)|Operador de molde `auto_gcroot` de tipo entre e tipos compatíveis.|
|[auto_gcroot::bool operador&nbsp;](#operator-bool)|Operador para `auto_gcroot` uso em uma expressão condicional.|  
|[auto_gcroot:operador!](#operator-logical-not)|Operador para `auto_gcroot` uso em uma expressão condicional.|

## <a name="requirements"></a>Requisitos

Arquivo \< **de cabeçalho** msclr\auto_gcroot.h>

**Namespace** msclr

## <a name="auto_gcrootauto_gcroot"></a><a name="auto-gcroot"></a>auto_gcroot:auto_gcroot

O `auto_gcroot` construtor.

```cpp
auto_gcroot(
   _element_type _ptr = nullptr
);
auto_gcroot(
   auto_gcroot<_element_type> & _right
);
template<typename _other_type>
auto_gcroot(
   auto_gcroot<_other_type> & _right
);
```

### <a name="parameters"></a>Parâmetros

*_ptr*<br/>
O objeto a possuir.

*_right*<br/>
Um `auto_gcroot` existente.

### <a name="remarks"></a>Comentários

Ao construir `auto_gcroot` um a `auto_gcroot`partir de `auto_gcroot` um existente, o existente libera seu `auto_gcroot`objeto antes de transferir a propriedade do objeto para o novo .

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_auto_gcroot.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class RefClassA {
protected:
   String^ m_s;
public:
   RefClassA(String^ s) : m_s(s) {
      Console::WriteLine( "in RefClassA constructor: " + m_s );
   }
   ~RefClassA() {
      Console::WriteLine( "in RefClassA destructor: " + m_s );
   }

   virtual void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }
};

ref class RefClassB : RefClassA {
public:
   RefClassB( String^ s ) : RefClassA( s ) {}
   virtual void PrintHello() new {
      Console::WriteLine( "Hello from {0} B!", m_s );
   }
};

class ClassA { //unmanaged class
private:
   auto_gcroot<RefClassA^> m_a;

public:
   ClassA() : m_a( gcnew RefClassA( "unmanaged" ) ) {}
   ~ClassA() {} //no need to delete m_a

   void DoSomething() {
      m_a->PrintHello();
   }
};

int main()
{
   {
      ClassA a;
      a.DoSomething();
   } // a.m_a is automatically destroyed as a goes out of scope

   {
      auto_gcroot<RefClassA^> a(gcnew RefClassA( "first" ) );
      a->PrintHello();
   }

   {
      auto_gcroot<RefClassB^> b(gcnew RefClassB( "second" ) );
      b->PrintHello();
      auto_gcroot<RefClassA^> a(b); //construct from derived type
      a->PrintHello();
      auto_gcroot<RefClassA^> a2(a); //construct from same type
      a2->PrintHello();
   }

   Console::WriteLine("done");
}
```

```Output
in RefClassA constructor: unmanaged
Hello from unmanaged A!
in RefClassA destructor: unmanaged
in RefClassA constructor: first
Hello from first A!
in RefClassA destructor: first
in RefClassA constructor: second
Hello from second B!
Hello from second A!
Hello from second A!
in RefClassA destructor: second
done
```

## <a name="auto_gcrootauto_gcroot"></a><a name="tilde-auto-gcroot"></a>auto_gcroot::~auto_gcroot

O `auto_gcroot` destruidor.

```cpp
~auto_gcroot();
```

### <a name="remarks"></a>Comentários

O destruidor também destrói o objeto.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_dtor.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
public:
   ClassA() { Console::WriteLine( "ClassA constructor" ); }
   ~ClassA() { Console::WriteLine( "ClassA destructor" ); }
};

int main()
{
   // create a new scope for a:
   {
      auto_gcroot<ClassA^> a = gcnew ClassA;
   }
   // a goes out of scope here, invoking its destructor
   // which in turns destructs the ClassA object.

   Console::WriteLine( "done" );
}
```

```Output
ClassA constructor
ClassA destructor
done
```

## <a name="auto_gcrootattach"></a><a name="attach"></a>auto_gcroot::anexar

Anexar `auto_gcroot` a um objeto.

```cpp
auto_gcroot<_element_type> & attach(
   _element_type _right
);
auto_gcroot<_element_type> & attach(
   auto_gcroot<_element_type> & _right
);
template<typename _other_type>
auto_gcroot<_element_type> & attach(
   auto_gcroot<_other_type> & _right
);
```

### <a name="parameters"></a>Parâmetros

*_right*<br/>
O objeto a ser `auto_gcroot` anexado, ou um que contenha o objeto a ser anexado.

### <a name="return-value"></a>Valor retornado

O `auto_gcroot` atual.

### <a name="remarks"></a>Comentários

Se `_right` for `auto_gcroot`um , ele libera a propriedade de seu `auto_gcroot`objeto antes que o objeto seja anexado à corrente .

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_attach.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
protected:
   String^ m_s;
public:
   ClassA( String^ s ) : m_s( s ) {
      Console::WriteLine( "in ClassA constructor:" + m_s );
   }
   ~ClassA() {
      Console::WriteLine( "in ClassA destructor:" + m_s );
   }

   virtual void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }
};

ref class ClassB : ClassA {
public:
   ClassB( String ^ s) : ClassA( s ) {}
   virtual void PrintHello() new {
      Console::WriteLine( "Hello from {0} B!", m_s );
   }
};

int main() {
   auto_gcroot<ClassA^> a( gcnew ClassA( "first" ) );
   a->PrintHello();
   a.attach( gcnew ClassA( "second" ) ); // attach same type
   a->PrintHello();
   ClassA^ ha = gcnew ClassA( "third" );
   a.attach( ha ); // attach raw handle
   a->PrintHello();
   auto_gcroot<ClassB^> b( gcnew ClassB("fourth") );
   b->PrintHello();
   a.attach( b ); // attach derived type
   a->PrintHello();
}
```

```Output
in ClassA constructor:first
Hello from first A!
in ClassA constructor:second
in ClassA destructor:first
Hello from second A!
in ClassA constructor:third
in ClassA destructor:second
Hello from third A!
in ClassA constructor:fourth
Hello from fourth B!
in ClassA destructor:third
Hello from fourth A!
in ClassA destructor:fourth
```

## <a name="auto_gcrootget"></a><a name="get"></a>auto_gcroot:get

Pega o objeto contido.

```cpp
_element_type get() const;
```

### <a name="return-value"></a>Valor retornado

O objeto contidos.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_get.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
   String^ m_s;
public:
   ClassA( String^ s ) : m_s( s ){
      Console::WriteLine( "in ClassA constructor:" + m_s );
   }
   ~ClassA() {
      Console::WriteLine( "in ClassA destructor:" + m_s );
   }

   void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }
};

void PrintA( ClassA^ a ) {
   a->PrintHello();
}

int main() {
   auto_gcroot<ClassA^> a = gcnew ClassA( "first" );
   a->PrintHello();

   ClassA^ a2 = a.get();
   a2->PrintHello();

   PrintA( a.get() );
}
```

```Output
in ClassA constructor:first
Hello from first A!
Hello from first A!
Hello from first A!
in ClassA destructor:first
```

## <a name="auto_gcrootrelease"></a><a name="release"></a>auto_gcroot::liberação

Libera o objeto `auto_gcroot` da gestão.

```cpp
_element_type release();
```

### <a name="return-value"></a>Valor retornado

O objeto solto.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_release.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
   String^ m_s;
public:
   ClassA( String^ s ) : m_s( s ) {
      Console::WriteLine( "ClassA constructor: " + m_s );
   }
   ~ClassA() {
      Console::WriteLine( "ClassA destructor: " + m_s );
   }

   void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }
};

int main()
{
   ClassA^ a;

   // create a new scope:
   {
      auto_gcroot<ClassA^> agc1 = gcnew ClassA( "first" );
      auto_gcroot<ClassA^> agc2 = gcnew ClassA( "second" );
      a = agc1.release();
   }
   // agc1 and agc2 go out of scope here

   a->PrintHello();

   Console::WriteLine( "done" );
}
```

```Output
ClassA constructor: first
ClassA constructor: second
ClassA destructor: second
Hello from first A!
done
```

## <a name="auto_gcrootreset"></a><a name="reset"></a>auto_gcroot::reset

Destrua o objeto de propriedade atual e, opcionalmente, tome posse de um novo objeto.

```cpp
void reset(
   _element_type _new_ptr = nullptr
);
```

### <a name="parameters"></a>Parâmetros

*_new_ptr*<br/>
(Opcional) O novo objeto.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_reset.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
   String^ m_s;
public:
   ClassA( String^ s ) : m_s( s ) {
      Console::WriteLine( "ClassA constructor: " + m_s );
   }
   ~ClassA() {
      Console::WriteLine( "ClassA destructor: " + m_s );
   }

   void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }
};

int main()
{
   auto_gcroot<ClassA^> agc1 = gcnew ClassA( "first" );
   agc1->PrintHello();

   ClassA^ ha = gcnew ClassA( "second" );
   agc1.reset( ha ); // release first object, reference second
   agc1->PrintHello();

   agc1.reset(); // release second object, set to nullptr

   Console::WriteLine( "done" );
}
```

```Output
ClassA constructor: first
Hello from first A!
ClassA constructor: second
ClassA destructor: first
Hello from second A!
ClassA destructor: second
done
```

## <a name="auto_gcrootswap"></a><a name="swap"></a>auto_gcroot::swap

Troca objetos `auto_gcroot`por outro .

```cpp
void swap(
   auto_gcroot<_element_type> & _right
);
```

### <a name="parameters"></a>Parâmetros

*_right*<br/>
Com `auto_gcroot` o qual trocar objetos.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_swap.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

int main() {
   auto_gcroot<String^> s1 = "string one";
   auto_gcroot<String^> s2 = "string two";

   Console::WriteLine( "s1 = '{0}', s2 = '{1}'",
      s1->ToString(), s2->ToString() );
   s1.swap( s2 );
   Console::WriteLine( "s1 = '{0}', s2 = '{1}'",
      s1->ToString(), s2->ToString() );
}
```

```Output
s1 = 'string one', s2 = 'string two'
s1 = 'string two', s2 = 'string one'
```

## <a name="auto_gcrootoperator-gt"></a><a name="operator-arrow"></a>auto_gcroot::operador-&gt;

O operador de acesso de membros.

```cpp
_element_type operator->() const;
```

### <a name="return-value"></a>Valor retornado

O objeto que está `auto_gcroot`embrulhado por.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_op_arrow.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
protected:
   String^ m_s;
public:
   ClassA( String^ s ) : m_s( s ) {}

   virtual void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }

   int m_i;
};

int main() {
   auto_gcroot<ClassA^> a( gcnew ClassA( "first" ) );
   a->PrintHello();

   a->m_i = 5;
   Console::WriteLine( "a->m_i = {0}", a->m_i );
}
```

```Output
Hello from first A!
a->m_i = 5
```

## <a name="auto_gcrootoperator"></a><a name="operator-assign"></a>auto_gcroot:operador=

Operador de atribuição.

```cpp
auto_gcroot<_element_type> & operator=(
   _element_type _right
);
auto_gcroot<_element_type> & operator=(
   auto_gcroot<_element_type> & _right
);
template<typename _other_type>
auto_gcroot<_element_type> & operator=(
   auto_gcroot<_other_type> & _right
);
```

### <a name="parameters"></a>Parâmetros

*_right*<br/>
O objeto `auto_gcroot` ou a ser `auto_gcroot`atribuído à corrente.

### <a name="return-value"></a>Valor retornado

A `auto_gcroot`corrente, agora `_right`possuindo.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_operator_equals.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
protected:
   String^ m_s;
public:
   ClassA(String^ s) : m_s(s) {
      Console::WriteLine( "in ClassA constructor: " + m_s );
   }
   ~ClassA() {
      Console::WriteLine( "in ClassA destructor: " + m_s );
   }

   virtual void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }
};

ref class ClassB : ClassA {
public:
   ClassB( String^ s ) : ClassA( s ) {}
   virtual void PrintHello() new {
      Console::WriteLine( "Hello from {0} B!", m_s );
   }
};

int main()
{
   auto_gcroot<ClassA^> a;
   auto_gcroot<ClassA^> a2(gcnew ClassA( "first" ) );
   a = a2; // assign from same type
   a->PrintHello();

   ClassA^ ha = gcnew ClassA( "second" );
   a = ha; // assign from raw handle

   auto_gcroot<ClassB^> b(gcnew ClassB( "third" ) );
   b->PrintHello();
   a = b; // assign from derived type
   a->PrintHello();

   Console::WriteLine("done");
}
```

```Output
in ClassA constructor: first
Hello from first A!
in ClassA constructor: second
in ClassA destructor: first
in ClassA constructor: third
Hello from third B!
in ClassA destructor: second
Hello from third A!
done
in ClassA destructor: third
```

## <a name="auto_gcrootoperator-auto_gcroot"></a><a name="operator-auto-gcroot"></a>auto_gcroot:auto_gcroot do operador

Operador de molde `auto_gcroot` de tipo entre e tipos compatíveis.

```cpp
template<typename _other_type>
operator auto_gcroot<_other_type>();
```

### <a name="return-value"></a>Valor retornado

O `auto_gcroot` elenco `auto_gcroot<_other_type>`atual para .

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_op_auto_gcroot.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class ClassA {
protected:
   String^ m_s;
public:
   ClassA( String^ s ) : m_s( s ) {}

   virtual void PrintHello() {
      Console::WriteLine( "Hello from {0} A!", m_s );
   }
};

ref class ClassB : ClassA {
public:
   ClassB( String ^ s) : ClassA( s ) {}
   virtual void PrintHello() new {
      Console::WriteLine( "Hello from {0} B!", m_s );
   }
};

int main() {
   auto_gcroot<ClassB^> b = gcnew ClassB("first");
   b->PrintHello();
   auto_gcroot<ClassA^> a = (auto_gcroot<ClassA^>)b;
   a->PrintHello();
}
```

```Output
Hello from first B!
Hello from first A!
```

## <a name="auto_gcrootoperator-bool"></a><a name="operator-bool"></a>auto_gcroot::bool operador

Operador para `auto_gcroot` uso em uma expressão condicional.

```cpp
operator bool() const;
```

### <a name="return-value"></a>Valor retornado

`true`se o objeto embrulhado for válido; `false` caso contrário.

### <a name="remarks"></a>Comentários

Este operador realmente `_detail_class::_safe_bool`se converte `bool` para , o que é mais seguro do que porque não pode ser convertido para um tipo integral.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_operator_bool.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

int main() {
   auto_gcroot<String^> s;
   if ( s ) Console::WriteLine( "s is valid" );
   if ( !s ) Console::WriteLine( "s is invalid" );
   s = "something";
   if ( s ) Console::WriteLine( "now s is valid" );
   if ( !s ) Console::WriteLine( "now s is invalid" );
   s.reset();
   if ( s ) Console::WriteLine( "now s is valid" );
   if ( !s ) Console::WriteLine( "now s is invalid" );
}
```

```Output
s is invalid
now s is valid
now s is invalid
```

## <a name="auto_gcrootoperator"></a><a name="operator-logical-not"></a>auto_gcroot:operador!

Operador para `auto_gcroot` uso em uma expressão condicional.

```cpp
bool operator!() const;
```

### <a name="return-value"></a>Valor retornado

`true`se o objeto embrulhado for inválido; `false` caso contrário.

### <a name="example"></a>Exemplo

```cpp
// msl_auto_gcroot_operator_not.cpp
// compile with: /clr
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace msclr;

int main() {
   auto_gcroot<String^> s;
   if ( s ) Console::WriteLine( "s is valid" );
   if ( !s ) Console::WriteLine( "s is invalid" );
   s = "something";
   if ( s ) Console::WriteLine( "now s is valid" );
   if ( !s ) Console::WriteLine( "now s is invalid" );
   s.reset();
   if ( s ) Console::WriteLine( "now s is valid" );
   if ( !s ) Console::WriteLine( "now s is invalid" );
}
```

```Output
s is invalid
now s is valid
now s is invalid
```
