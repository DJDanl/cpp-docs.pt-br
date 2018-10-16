---
title: Delegar (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- delegate_cpp
- delegate
dev_langs:
- C++
helpviewer_keywords:
- delegate keyword [C++]
ms.assetid: 03caf23d-7873-4a23-9b34-becf42aaf429
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2281dfb6648f9c4756800a0693f184ccaa7435d7
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49327954"
---
# <a name="delegate--ccli-and-ccx"></a>Delegar (C + + c++ /CLI e c++ /CLI CX)

Declara um tipo que representa um ponteiro de função.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

O tempo de execução do Windows e o common language runtime dão suporte a delegados.

### <a name="remarks"></a>Comentários

**Delegar** é uma palavra-chave contextual. Para obter mais informações, consulte [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).

Para detectar no tempo de compilação se um tipo é um delegado, use o `__is_delegate()` característica de tipo. Para obter mais informações, consulte [suporte do compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

C + + c++ /CX oferece suporte a delegados com a sintaxe a seguir.

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
(opcional) A acessibilidade do delegado, que pode ser **pública** (o padrão) ou **privada**. O protótipo de função também pode ser qualificado com o **const** ou **volátil** palavras-chave.

*tipo de retorno*<br/>
O tipo de retorno do protótipo da função.

*Identificador de tipo de delegado*<br/>
O nome do tipo de delegado declarado.

*Parâmetros*<br/>
(Opcional) Os tipos e identificadores de protótipo da função.

### <a name="remarks"></a>Comentários

Use o *identificador de tipo de delegado* para declarar um evento com o mesmo protótipo como o delegado. Para obter mais informações, consulte [delegados (C + + c++ /CX)](../cppcx/delegates-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

O common language runtime dá suporte a delegados com a sintaxe a seguir.

### <a name="syntax"></a>Sintaxe

```cpp
access
delegate
function_declaration
```

### <a name="parameters"></a>Parâmetros

*access*<br/>
(opcional) A acessibilidade do delegado fora do assembly pode ser público ou privado.  O padrão é particular.  Dentro de uma classe, um delegado pode ter qualquer acessibilidade.

*function_declaration*<br/>
A assinatura da função que pode ser associada ao delegado. O tipo de retorno de um delegado pode ser qualquer tipo gerenciado. Por motivos de interoperabilidade, é recomendável que o tipo de retorno de um delegado ser um tipo com CLS.

Para definir um delegate não associado, o primeiro parâmetro na *function_declaration* deve ser o tipo dos **isso** ponteiro para o objeto.

### <a name="remarks"></a>Comentários

Os representantes são multicast: o "ponteiro de função" pode ser associado a um ou mais métodos dentro de uma classe gerenciada. O **delegar** palavra-chave define um tipo de delegado multicast com uma assinatura de método específico.

Um delegado também pode ser associado a um método de uma classe de valor, como um método estático.

Um delegado tem as seguintes características:

- Herda de `System::MulticastDelegate`.

- Ele tem um construtor que aceita dois argumentos: um ponteiro para uma classe gerenciada ou NULL (no caso de associação a um método estático) e um método totalmente qualificado do tipo especificado.

- Tem um método chamado `Invoke`, cuja assinatura corresponde à assinatura declarada do delegado.

Quando um delegado é invocado, suas funções são chamados na ordem em que eles foram anexados.

O valor de retorno de um delegado é o valor retornado de sua função de membro anexada a última.

Delegados não podem ser sobrecarregados.

Delegados podem ser associados ou não associados.

Ao instanciar um delegado associado, o primeiro argumento deve ser uma referência de objeto. O segundo argumento de uma instanciação de delegado, qualquer um deverá ser o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor. O segundo argumento de uma instanciação de delegado deve nomear o método com a sintaxe de escopo de classe completo e aplicar o operador address-of.

Quando você instancia um delegate não associado, o primeiro argumento deve ser o endereço de um método de um objeto de classe gerenciada ou um ponteiro para um método de um tipo de valor. O argumento deve nomear o método com a sintaxe de escopo de classe completo e aplicar o operador address-of.

Ao criar um delegado para uma função global ou estática, apenas um parâmetro é necessário: a função (e, opcionalmente, o endereço da função).

Para obter mais informações sobre delegados, consulte

- [Como definir e usar delegados (C++/CLI)](../dotnet/how-to-define-and-use-delegates-cpp-cli.md)

- [Delegados genéricos (C + + / CLI)](../windows/generic-delegates-visual-cpp.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra como declarar, inicializar e invocar representantes.

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

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)