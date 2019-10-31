---
title: Visão geral de genéricos em C++/CLI
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- generics [C++], about generics
- default initializers [C++]
- type parameters [C++]
- constructed types
- type arguments [C++]
- constructed types, open [C++]
- open constructed types [C++]
- constructed types, closed [C++]
ms.assetid: 21f10637-0fce-4916-b925-6c86a126d3aa
ms.openlocfilehash: 38d33faec3610495e8cc5e97db2e81bd74be8b8b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515661"
---
# <a name="overview-of-generics-in-ccli"></a>Visão geral de genéricos em C++/CLI

Genéricos são tipos parametrizados compatíveis com o Common Language Runtime. Um tipo parametrizado é um tipo definido com um parâmetro de tipo desconhecido especificado quando o genérico é usado.

## <a name="why-generics"></a>Por que genéricos?

O C++ é compatível com modelos, e tanto modelos quanto genéricos são compatíveis com tipos parametrizados para criar classes de coleção com tipos definidos. No entanto, modelos fornecem parametrização em tempo de compilação. Não é possível fazer referência a uma montagem que contenha uma definição de modelo e criar novas especializações do modelo. Uma vez compilado, um modelo especializado se parece com qualquer outra classe ou método. Em contraste, os genéricos são emitidos no MSIL como um tipo parametrizado conhecido pelo tempo de execução por ser um tipo parametrizado. Um código-fonte que faz referência a um assembly contendo um tipo genérico pode criar especializações do tipo genérico. Confira mais informações sobre a comparação de genéricos e modelos C++ padrão em [Genéricos e modelos (C++/CLI)](generics-and-templates-visual-cpp.md).

## <a name="generic-functions-and-types"></a>Funções e tipos genéricos

Tipos de classe, desde que sejam tipos gerenciados, podem ser genéricos. Um exemplo disso pode ser uma classe `List`. O tipo de um objeto na lista seria o parâmetro de tipo. Se você precisasse de uma classe `List` para vários tipos diferentes de objetos, antes dos genéricos, seria possível usar uma `List` que usa `System::Object` como o tipo de item. Porém, isso permitiria que qualquer objeto (incluindo objetos do tipo errado) fosse usado na lista. Essa lista seria chamada de uma classe de coleção sem tipo definido. Na melhor das hipóteses, você poderia verificar o tipo em tempo de execução e lançar uma exceção. Ou, poderia ter usado um modelo, que perderia sua qualidade genérica depois de compilado em um assembly. Os consumidores do seu assembly não poderiam criar suas próprias especializações do modelo. Genéricos permitem criar classes de coleção com tipos definidos, digamos `List<int>` (lidas como "Lista de int") e `List<double>` ("Lista de duplos"), o que geraria um erro em tempo de compilação se você tentasse inserir um tipo que a coleção não foi projetada para aceitar na coleção com tipo definido. Além disso, esses tipos permanecem genéricos depois de serem compilados.

Uma descrição da sintaxe de classes genéricas pode ser encontrada em [Classes genéricas (C++/CLI)](generic-classes-cpp-cli.md). Um novo namespace, <xref:System.Collections.Generic>, introduz um conjunto de tipos de coleção parametrizados, incluindo <xref:System.Collections.Generic.Dictionary%602>, <xref:System.Collections.Generic.List%601> e <xref:System.Collections.Generic.LinkedList%601>.

Funções de membros de classes estáticas e de instâncias, delegados e funções globais também podem ser genéricos. Funções genéricas podem ser necessárias se os parâmetros da função são de um tipo desconhecido ou se a própria função precisa trabalhar com tipos genéricos. Em muitos casos em que `System::Object` pode ter sido usado no passado como um parâmetro para um tipo de objeto desconhecido, um parâmetro de tipo genérico pode ser usado no lugar, permitindo um código mais seguro fortemente tipado. Qualquer tentativa de transmitir um tipo para o qual a função não foi projetada seria sinalizada como um erro em tempo de compilação. Usando `System::Object` como parâmetro de função, a transmissão inadvertida de um objeto com o qual a função não estivesse destinada a lidar não seria detectada, e você precisaria converter o tipo de objeto desconhecido em um tipo específico no corpo da função, além de considerar a chance de receber uma exceção do tipo InvalidCastException. Com um genérico, um código que tentasse transmitir um objeto à função causaria um conflito de tipos e, portanto, o corpo da função tem a garantia de incluir o tipo correto.

Os mesmos benefícios se aplicam a classes de coleções criadas em genéricos. No passado, classes de coleções usavam `System::Object` para armazenar elementos em uma coleção. A inserção de objetos de um tipo ao qual a coleção não foi projetada não era sinalizada em tempo de compilação e muitas vezes nem mesmo quando os objetos eram inseridos. Em geral, um objeto era convertido em algum outro tipo quando acessado na coleção. O tipo inesperado apenas era detectado quando a conversão falhava. Os genéricos resolvem esse problema em tempo de compilação, detectando qualquer código que insira um tipo que não corresponda ao parâmetro de tipo da coleção genérica (ou faça uma conversão implícita para esse tipo).

Confira uma descrição da sintaxe em [Funções genéricas (C++/CLI)](generic-functions-cpp-cli.md).

## <a name="terminology-used-with-generics"></a>Terminologia usada com genéricos

### <a name="type-parameters"></a>Parâmetros de tipo

Uma declaração genérica contém um ou mais tipos desconhecidos, chamados de *parâmetros de tipo*. Parâmetros de tipo recebem um nome que indica o tipo dentro do corpo da declaração genérica. O parâmetro de tipo é usado como um tipo dentro do corpo da declaração genérica. A declaração genérica para `List<T>` contém o parâmetro de tipo T.

### <a name="type-arguments"></a>Argumentos de tipo

O *argumento de tipo* é o tipo real usado no lugar do parâmetro de tipo quando o genérico é especializado para um ou mais tipos específicos. Por exemplo, **int** é o argumento de tipo em `List<int>`. Tipos de valores e tipos de identificadores são os únicos tipos permitidos em um argumento de tipo genérico.

### <a name="constructed-type"></a>Tipo construído

Um tipo construído de um tipo genérico é chamado de um *tipo construído*. Um tipo não totalmente especificado, como `List<T>`, é um *tipo construído aberto*. Um tipo totalmente especificado, como `List<double>,`, é um *tipo construído fechado* ou *tipo especializado*. Tipos construídos abertos podem ser usados na definição de outros tipos ou métodos genéricos e podem não ser totalmente especificados até que o próprio genérico delimitante seja especificado. Por exemplo, o seguinte é um uso de um tipo construído aberto como uma classe base para um genérico:

```cpp
// generics_overview.cpp
// compile with: /clr /c
generic <typename T>

ref class List {};

generic <typename T>

ref class Queue : public List<T> {};
```

### <a name="constraint"></a>Restrição

Uma restrição é aplicada aos tipos que podem ser usados como um parâmetro de tipo. Por exemplo, uma determinada classe genérica pode aceitar apenas classes que herdam de uma classe especificada ou que implementam uma interface especificada. Confira mais informações em [Restrições em parâmetros de tipo genérico (C++/CLI)](constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="reference-types-and-value-types"></a>Tipos de referência e tipos de valor

Tipos de identificador de tipos de valor podem ser usados como argumentos de tipo. Na definição genérica, em que qualquer um desses tipos pode ser usado, a sintaxe é a dos tipos de referência. Por exemplo, o operador `->` é usado para acessar membros do tipo do parâmetro de tipo, independentemente de o tipo de referência usado no final ser um tipo de referência ou um tipo de valor. Quando um tipo de valor é usado como argumento de tipo, o tempo de execução gera um código que usa os tipos de valor diretamente sem fazer a conversão boxing dos tipos de valor.

Ao usar um tipo de referência como um argumento de tipo genérico, use a sintaxe do identificador. Ao usar um tipo de valor como um argumento de tipo genérico, use o nome do tipo diretamente.

```cpp
// generics_overview_2.cpp
// compile with: /clr
generic <typename T>

ref class GenericType {};
ref class ReferenceType {};

value struct ValueType {};

int main() {
    GenericType<ReferenceType^> x;
    GenericType<ValueType> y;
}
```

## <a name="type-parameters"></a>Parâmetros de tipo

Os parâmetros de tipo em uma classe genérica são tratados como outros identificadores. No entanto, como o tipo não é conhecido, existem restrições sobre o seu uso. Por exemplo, você não pode usar membros e métodos da classe do parâmetro de tipo, a menos que esse parâmetro seja conhecido por ser compatível com esses membros. Ou seja, para acessar um membro por meio do parâmetro de tipo, você deve incluir o tipo que contém esse membro na lista de restrições do parâmetro de tipo.

```cpp
// generics_overview_3.cpp
// compile with: /clr
interface class I {
   void f1();
   void f2();
};

ref struct R : public I {
   virtual void f1() {}
   virtual void f2() {}
   virtual void f3() {}
};

generic <typename T>
where T : I
void f(T t) {
   t->f1();
   t->f2();
   safe_cast<R^>(t)->f3();
}

int main() {
   f(gcnew R());
}
```

Essas restrições também se aplicam a operadores. Um parâmetro de tipo genérico irrestrito não pode usar os operadores `==` e `!=` para comparar duas instâncias do parâmetro de tipo, no caso de o tipo não ser compatível com esses operadores. Essas verificações são necessárias para genéricos, mas não para modelos porque os genéricos podem ser especializados em tempo de execução com qualquer classe que atenda às restrições, quando for tarde demais para verificar o uso de membros inválidos.

Uma instância padrão do parâmetro de tipo pode ser criada usando o operador `()`. Por exemplo:

`T t = T();`

em que `T` é um parâmetro de tipo em uma classe genérica ou definição de método, inicializa a variável com seu valor padrão. Se `T` for uma classe ref, ele será um ponteiro nulo. Se `T` for uma classe de valor, o objeto será inicializado como zero. Isso é chamado de *inicializador padrão*.

## <a name="see-also"></a>Consulte também

[Genéricos](generics-cpp-component-extensions.md)