---
title: delegate (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- delegate_cpp
- delegate
helpviewer_keywords:
- delegate keyword [C++]
ms.assetid: 03caf23d-7873-4a23-9b34-becf42aaf429
ms.openlocfilehash: 29bf305ed5e4845437b90ed672d1ab0c0de9ced6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516481"
---
# <a name="delegate--ccli-and-ccx"></a>delegate (C++/CLI e C++/CX)

Declara um tipo que representa um ponteiro de função.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

O Windows Runtime e o common language runtime dão suporte a delegados.

### <a name="remarks"></a>Comentários

**delegate** é uma palavra-chave contextual. Saiba mais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md).

Para detectar em tempo de compilação se um tipo é um delegado, use o traço de tipo `__is_delegate()`. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

O C++/CX é compatível com delegados com a sintaxe a seguir.

### <a name="syntax"></a>Sintaxe

```cpp
access
delegate
return-type
delegate-type-identifier
(
[ parameters ]
)
```

### <a name="parameters"></a>Parâmetros

*access*<br/>
(opcional) A acessibilidade do delegado, que pode ser **public** (padrão) ou **private**. O protótipo de função também pode ser qualificado com as palavras-chaves **const** ou **volatile**.

*return-type*<br/>
O tipo de retorno do protótipo da função.

*delegate-type-identifier*<br/>
O nome do tipo de delegado declarado.

*parameters*<br/>
(Opcional) Os tipos e identificadores do protótipo da função.

### <a name="remarks"></a>Comentários

Use o *delegate-type-identifier* para declarar um evento com o mesmo protótipo que o delegado. Saiba mais em [Delegates (C++/CX)](../cppcx/delegates-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

O common language runtime é compatível com delegates com a sintaxe a seguir.

### <a name="syntax"></a>Sintaxe

```cpp
access
delegate
function_declaration
```

### <a name="parameters"></a>Parâmetros

*access*<br/>
(opcional) A acessibilidade de delegate fora do assembly pode ser public ou private.  O padrão é private.  Dentro de uma classe, um delegado pode ter qualquer acessibilidade.

*function_declaration*<br/>
A assinatura da função que pode ser associada ao delegado. O tipo de retorno de um delegado pode ser qualquer tipo gerenciado. Por motivos de interoperabilidade, recomendamos que o tipo de retorno de um delegado seja do tipo CLS.

Para definir um delegado não associado, o primeiro parâmetro em *function_declaration* deve ser o tipo do ponteiro **this** do objeto.

### <a name="remarks"></a>Comentários

Os delegados são multicast: o "ponteiro da função" pode ser associado a um ou mais métodos dentro de uma classe gerenciada. A palavra-chave **delegate** define um tipo de delegado multicast com uma assinatura de método específica.

Um delegado também pode ser associado a um método de uma classe de valor, como um método estático.

Um delegado tem as seguintes características:

- Herda de `System::MulticastDelegate`.

- Tem um construtor que utiliza dois argumentos: um ponteiro para uma classe gerenciada ou NULL (no caso de associação a um método estático) e um método totalmente qualificado do tipo especificado.

- Tem um método chamado `Invoke`, cuja assinatura corresponde à assinatura declarada do delegado.

Quando um delegado é invocado, suas funções são chamadas na ordem em que foram anexados.

O valor de retorno de um delegado é o valor de retorno de sua última função de membro anexada.

Não é possível sobrecarregar delegados.

É possível associar ou desassociar.

Ao instanciar um delegado associado, o primeiro argumento deve ser uma referência ao objeto. O segundo argumento de uma instanciação de delegado deve ser o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor. O segundo argumento de uma instanciação de delegado deve nomear o método com a sintaxe de escopo de classe completa e aplicar o operador address-of.

Ao instanciar um delegado não associado, o primeiro argumento deve ser o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor. O argumento deve nomear o método com a sintaxe de escopo de classe completa e aplicar o operador address-of.

Ao criar um delegado para uma função global ou estática, apenas um parâmetro é necessário: a função (e, opcionalmente, o endereço da função).

Saiba mais sobre delegados em

- [Como: definir e usar delegados (C++/CLI)](../dotnet/how-to-define-and-use-delegates-cpp-cli.md)

- [Delegados genéricos (C++/CLI)](generic-delegates-visual-cpp.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra como declarar, inicializar e invocar delegados.

```cpp
// mcppv2_delegate.cpp
// compile with: /clr
using namespace System;

// declare a delegate
public delegate void MyDel(int i);

ref class A {
public:
   void func1(int i) {
      Console::WriteLine("in func1 {0}", i);
   }

   void func2(int i) {
      Console::WriteLine("in func2 {0}", i);
   }

   static void func3(int i) {
      Console::WriteLine("in static func3 {0}", i);
   }
};

int main () {
   A ^ a = gcnew A;

   // declare a delegate instance
   MyDel^ DelInst;

   // test if delegate is initialized
   if (DelInst)
      DelInst(7);

   // assigning to delegate
   DelInst = gcnew MyDel(a, &A::func1);

   // invoke delegate
   if (DelInst)
      DelInst(8);

   // add a function
   DelInst += gcnew MyDel(a, &A::func2);

   DelInst(9);

   // remove a function
   DelInst -= gcnew MyDel(a, &A::func1);

   // invoke delegate with Invoke
   DelInst->Invoke(10);

   // make delegate to static function
   MyDel ^ StaticDelInst = gcnew MyDel(&A::func3);
   StaticDelInst(11);
}
```

```Output
in func1 8

in func1 9

in func2 9

in func2 10

in static func3 11
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)