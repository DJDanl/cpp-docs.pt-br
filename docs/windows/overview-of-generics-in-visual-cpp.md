---
title: Visão geral de genéricos no C + + c++ CLI | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9e6240fd5e33f44c42d8a0d33302b9ef4cf9f8bb
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49327850"
---
# <a name="overview-of-generics-in-ccli"></a>Visão geral de genéricos no C + + / CLI

Genéricos são tipos parametrizados com suporte pelo common language runtime. Um tipo parametrizado é um tipo que é definido com um parâmetro de tipo desconhecido que é especificado quando a classe genérica é usada.

## <a name="why-generics"></a>Por que os genéricos?

C++ oferece suporte a ambos os modelos e modelos e tipos parametrizados para criar classes de coleção com suporte a genéricos. No entanto, os modelos fornecem a parametrização de tempo de compilação. Você não pode referenciar um assembly que contém uma definição de modelo e criar novos especializações do modelo. Uma vez que compilado, um modelo especializado se parece com qualquer outra classe ou método. Em contraste, os genéricos são emitidos em MSIL como um tipo parametrizado conhecido no tempo de execução para ser um tipo parametrizado; código-fonte que faz referência a um assembly que contém um tipo genérico pode criar especializações de tipo genérico. Para obter mais informações sobre a comparação dos modelos padrão do C++ e genéricos, consulte [genéricos e modelos (C + + / CLI)](../windows/generics-and-templates-visual-cpp.md).

## <a name="generic-functions-and-types"></a>Tipos e funções genéricas

Tipos de classe, desde que eles são tipos gerenciados, podem ser genéricos. Um exemplo disso pode ser um `List` classe. O tipo de um objeto na lista seria o parâmetro de tipo. Se você precisasse de um `List` classe para muitos tipos diferentes de objetos, antes de genéricos, você pode ter usado um `List` que usa `System::Object` como o tipo de item. Mas isso permitiria que qualquer objeto (incluindo objetos do tipo errado) a ser usado na lista. Essa lista deve ser chamada de uma classe de coleção não tipado. Na melhor das hipóteses, você pode verificar o tipo em tempo de execução e gera uma exceção. Ou, você pode ter usado um modelo, o que perderia sua qualidade genérica, uma vez que é compilada em um assembly. Os consumidores do seu assembly não foi possível criar suas próprias especializações do modelo. Os genéricos permitem que você crie classes de coleção com, digamos `List<int>` (Leia como "Lista de int") e `List<double>` ("lista de duplo") que produziria um erro de tempo de compilação se você tentou colocar um tipo que foi a coleção não foi projetado para aceitar em com tipo coleção. Além disso, esses tipos permanecem genéricos depois que são compilados.

Uma descrição da sintaxe das classes genéricas pode ser encontrada em [Classes genéricas (C + + / CLI)](../windows/generic-classes-cpp-cli.md). Um novo namespace, <xref:System.Collections.Generic>, apresenta um conjunto de tipos de coleção com parâmetros incluindo <xref:System.Collections.Generic.Dictionary%602>, <xref:System.Collections.Generic.List%601> e <xref:System.Collections.Generic.LinkedList%601>.

Instância e funções de membro de classe estática, delegados e funções globais também podem ser genéricas. Funções genéricas podem ser necessárias se os parâmetros da função de um tipo desconhecido ou se a função em si deve trabalhar com tipos genéricos. Em muitos casos onde `System::Object` pode ter sido usado no passado como um parâmetro para um tipo de objeto desconhecido, um parâmetro de tipo genérico pode ser usado em vez disso, permitindo mais código fortemente tipado. Qualquer tentativa de passar em um tipo que a função não foi projetada para será sinalizada como um erro em tempo de compilação. Usando `System::Object` como um parâmetro de função, a passagem acidental de um objeto que a função não foi destinada para lidar com não seriam detectada, e você precisará converter o tipo de objeto desconhecido para um tipo específico no corpo da função e a conta para o possibilidade de uma InvalidCastException. Com um genérico, o código tentar passar um objeto para a função poderia causar um conflito de tipo para o corpo da função é garantido para ter o tipo correto.

Os mesmos benefícios se aplicam às classes de coleção criadas sobre os genéricos. Classes de coleção no passado usaria `System::Object` para armazenar os elementos em uma coleção. Inserção de objetos de um tipo que a coleção não foi projetada para não foi sinalizada em tempo de compilação e geralmente nem mesmo quando os objetos foram inseridos. Normalmente, um objeto seria ser convertido em algum outro tipo quando ele foi acessado na coleção. Somente quando a conversão falha seria do tipo inesperado detectado. Genéricos resolvem esse problema no tempo de compilação através da detecção de qualquer código que insere um tipo que não correspondem (ou se convertem implicitamente) o parâmetro de tipo de coleção genérica.

Para obter uma descrição da sintaxe, consulte [funções genéricas (C + + / CLI)](../windows/generic-functions-cpp-cli.md).

## <a name="terminology-used-with-generics"></a>Terminologia usada com genéricos

### <a name="type-parameters"></a>Parâmetros de tipo

Uma declaração genérica contém um ou mais tipos desconhecidos, conhecidos como *parâmetros de tipo*. Parâmetros de tipo recebem um nome que representa o tipo dentro do corpo da declaração genérica. O parâmetro de tipo é usado como um tipo de dentro do corpo da declaração genérica. A declaração genérica para `List<T>` contém o parâmetro de tipo T.

### <a name="type-arguments"></a>Argumentos de tipo

O *argumento de tipo* é o tipo real usado no lugar do parâmetro de tipo quando genérica é especializada para um tipo específico ou tipos. Por exemplo, **int** é o argumento de tipo na `List<int>`. Tipos de valor e tipos de identificador são os únicos tipos permitidos no como um argumento de tipo genérico.

### <a name="constructed-type"></a>Tipo construído

Um tipo construído de um tipo genérico é conhecido como um *tipo construído*. Um tipo não totalmente especificado, tais como `List<T>` é um *abrir tipo construído*; um tipo totalmente especificada, tais como `List<double>,` é um *fechado tipo construído* ou *especializadas de tipo* . Tipos construídos abertos podem ser usados na definição de outros tipos ou métodos genéricos e não podem ser totalmente especificados até que o fechamento genérico é especificado. Por exemplo, este é um uso de um tipo construído aberto como uma classe base para um genérico:

```cpp
// generics_overview.cpp
// compile with: /clr /c
generic <typename T>

ref class List {};

generic <typename T>

ref class Queue : public List<T> {};
```

### <a name="constraint"></a>Restrição

Uma restrição é uma restrição sobre os tipos que podem ser usados como um parâmetro de tipo. Por exemplo, uma determinada classe genérica pode aceitar somente as classes que herdam de uma classe especificada ou implementar uma interface especificada. Para obter mais informações, consulte [restrições em parâmetros de tipo genéricos (C + + / CLI)](../windows/constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="reference-types-and-value-types"></a>Tipos de referência e tipos de valor

Tipos de identificadores e tipos de valor podem ser usados como argumentos de tipo. Na definição de genéricos, na qual qualquer tipo pode ser usado, a sintaxe é que um dos tipos de referência. Por exemplo, o `->` operador é usado para acessar membros do tipo do parâmetro de tipo, se o tipo usado eventualmente é um tipo de referência ou um tipo de valor ou não. Quando um tipo de valor é usado como o argumento de tipo, o tempo de execução gera o código que usa os tipos de valor diretamente, sem conversão boxing de tipos de valor.

Ao usar um tipo de referência como um argumento de tipo genérico, use a sintaxe de identificador. Ao usar um tipo de valor como um argumento de tipo genérico, use o nome do tipo diretamente.

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

Parâmetros de tipo em uma classe genérica são tratados como outros identificadores. No entanto, como o tipo não é conhecido, há restrições em seu uso. Por exemplo, você não pode usar os membros e os métodos da classe de parâmetro de tipo, a menos que o parâmetro de tipo é conhecido para dar suporte a esses membros. Ou seja, para acessar um membro por meio do parâmetro de tipo, você deve adicionar o tipo que contém o membro à lista de restrição de parâmetro do tipo.

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

Essas restrições se aplicam aos operadores também. Um parâmetro de tipo genérico sem restrição não pode usar o `==` e `!=` operadores para comparar duas instâncias do parâmetro de tipo, caso o tipo não oferece suporte a esses operadores. Essas verificações são necessárias para genéricos, mas não para os modelos, porque os genéricos podem ser especializados em tempo de execução com qualquer classe que satisfaz as restrições, quando é tarde demais para verificar o uso de membros inválidos.

Uma instância padrão do parâmetro de tipo pode ser criada usando o `()` operador. Por exemplo:

`T t = T();`

onde `T` é um parâmetro de tipo em uma definição de classe ou método genérico, inicializa a variável para o valor padrão. Se `T` é uma classe ref é um ponteiro nulo; se `T` é uma classe de valor, o objeto é inicializado como zero. Isso é chamado de um *padrão inicializador*.

## <a name="see-also"></a>Consulte também

[Genéricos](../windows/generics-cpp-component-extensions.md)