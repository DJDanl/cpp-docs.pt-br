---
title: "Visão geral de genéricos no Visual C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
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
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5082f603c64e796ef369044e3586ae5bfe85605a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overview-of-generics-in-visual-c"></a>Visão geral de genéricos no Visual C++
Genéricos são parametrizados tipos com suporte pelo common language runtime. Um tipo parametrizado é um tipo que é definido com um parâmetro de tipo desconhecido que é especificado quando a classe genérica é usada.  
  
## <a name="why-generics"></a>Por que genéricos?  
 C++ dá suporte a modelos e ambos os modelos e tipos parametrizados para criar classes de coleção com suporte a genéricos. No entanto, os modelos oferecem parametrização de tempo de compilação. Você não pode fazer referência a um assembly que contém uma definição de modelo e criar novos especializações do modelo. Depois de compilado, um modelo especializado parece com qualquer outra classe ou método. Por outro lado, genéricos são emitidos em MSIL como um tipo parametrizado conhecido pelo tempo de execução para um tipo com parâmetros; código-fonte que faz referência a um assembly que contém um tipo genérico pode criar especializações do tipo genérico. Para obter mais informações sobre a comparação de modelos do Visual C++ e genéricos, consulte [genéricos e modelos (Visual C++)](../windows/generics-and-templates-visual-cpp.md).  
  
## <a name="generic-functions-and-types"></a>Tipos e funções genéricas  
 Tipos de classe, desde que eles sejam tipos gerenciados, podem ser genéricos. Um exemplo disso pode ser um `List` classe. O tipo de um objeto da lista seria o parâmetro de tipo. Se for necessário um `List` classe para muitos tipos diferentes de objetos, antes de genéricos, talvez você tenha usado um `List` que usa **System::Object** como o tipo de item. Mas isso permitiria que qualquer objeto (incluindo objetos do tipo errado) a ser usado na lista. Essa lista deve ser chamada uma classe de coleção não tipado. Na melhor das hipóteses, você poderá verificar o tipo em tempo de execução e gera uma exceção. Ou, talvez você tenha usado um modelo, que poderá perder sua qualidade genérica, uma vez compilada em um assembly. Os consumidores de seu assembly não foi possível criar suas próprias especializações do modelo. Genéricos permitem que você crie classes de coleção tipada, digamos que `List<int>` (leitura como "Lista de int") e `List<double>` ("lista de duplo") não que geraria um erro de tempo de compilação se você tentar colocar um tipo que a coleção foi projetado para aceitar em com tipo coleção. Além disso, esses tipos de permanecem genéricos depois que são compilados.  
  
 Uma descrição da sintaxe de classes genéricas que pode ser encontrada no [Classes genéricas (C + + CLI)](../windows/generic-classes-cpp-cli.md) `.` um novo namespace, <xref:System.Collections.Generic>, apresenta um conjunto de tipos de coleção com parâmetros incluindo <xref:System.Collections.Generic.Dictionary%602>, <xref:System.Collections.Generic.List%601>e <xref:System.Collections.Generic.LinkedList%601>.  
  
 Instância e funções de membro de classe estática, representantes e funções globais também podem ser genéricas. Funções genéricas podem ser necessárias se os parâmetros da função de um tipo desconhecido ou se a função em si deve trabalhar com tipos genéricos. Em muitos casos onde **System::Object** pode ter sido usado no passado como um parâmetro para um tipo de objeto desconhecido, um parâmetro de tipo genérico pode ser usado em vez disso, permitindo mais código fortemente tipado. Qualquer tentativa de passar de um tipo que a função não foi projetada para seria sinalizada como um erro em tempo de compilação. Usando **System::Object** como um parâmetro de função, a transmissão acidental de um objeto que não era deve lidar com a função não seriam detectada e você precisa converter o tipo de objeto desconhecido para um tipo específico do corpo da função e a conta para a possibilidade de uma InvalidCastException. Com um genérico, o código tentar passar um objeto para a função causará um conflito de tipo para que o corpo da função é garantido que têm o tipo correto.  
  
 Os mesmos benefícios se aplica a classes de coleção criados em genéricos. Classes de coleção no passado usaria **System::Object** para armazenar elementos em uma coleção. Inserção de objetos de um tipo que a coleção não foi projetada para não foi sinalizada durante a compilação e geralmente nem mesmo quando os objetos foram inseridos. Normalmente, um objeto deve ser convertido para outro tipo quando ele foi acessado na coleção. Somente quando a conversão falha seria o tipo inesperado detectado. Genéricos resolve esse problema em tempo de compilação, detectar qualquer código que insere um tipo que não correspondem (ou se convertem implicitamente) o parâmetro de tipo de coleção genérica.  
  
 Para obter uma descrição da sintaxe, consulte [funções genéricas (C + + CLI)](../windows/generic-functions-cpp-cli.md).  
  
## <a name="terminology-used-with-generics"></a>Terminologia usada com genéricos  
  
##### <a name="type-parameters"></a>Parâmetros de tipo  
 Uma declaração de generic contém um ou mais tipos desconhecidos, conhecidos como *parâmetros de tipo*. Parâmetros de tipo recebem um nome que representa o tipo de dentro do corpo da declaração genérico. O parâmetro de tipo é usado como um tipo dentro do corpo da declaração genérico. A declaração de generic para lista < T\> contém o parâmetro de tipo T.  
  
##### <a name="type-arguments"></a>Argumentos de tipo  
 O *argumento de tipo* é o tipo real usado no lugar do parâmetro de tipo quando genérica é especializada para um tipo específico ou tipos. Por exemplo, `int` é o argumento de tipo em `List<int>`. Tipos de valor e tipos de identificador são os únicos tipos permitidos em como um argumento de tipo genérico.  
  
##### <a name="constructed-type"></a>Tipo construído  
 Um tipo construído de um tipo genérico é conhecido como um *tipo construído*. Um tipo não totalmente especificado, tais como `List<T>` é um *abrir tipo construído*; um tipo totalmente especificada, tais como `List<double>,` é um *fechado tipo construído* ou *especializadas de tipo* . Tipos construídos abertos podem ser usados na definição de outros tipos ou métodos genéricos e não podem ser totalmente especificados até que o delimitador genérico é especificado. Por exemplo, este é um uso de um tipo construído aberto como uma classe base para um genérico:  
  
 `// generics_overview.cpp`  
  
 `// compile with: /clr /c`  
  
 `generic <typename T>`  
  
 `ref class List {};`  
  
 `generic <typename T>`  
  
 `ref class Queue : public List<T> {};`  
  
##### <a name="constraint"></a>Restrição  
 Uma restrição é uma restrição sobre os tipos que podem ser usados como um parâmetro de tipo. Por exemplo, uma determinada classe genérica pode aceitar somente as classes que herdam de uma classe especificada ou implementar uma interface especificada. Para obter mais informações, consulte [restrições em parâmetros de tipo genérico (C + + CLI)](../windows/constraints-on-generic-type-parameters-cpp-cli.md).  
  
## <a name="reference-types-and-value-types"></a>Tipos de referência e tipos de valor  
 Tipos de identificadores e tipos de valor podem ser usados como argumentos de tipo. Na definição genérica, no qual tipo pode ser usado, a sintaxe é a que tipos de referência. Por exemplo, o  **->**  operador é usado para acessar membros de tipo do parâmetro de tipo, se o tipo usado eventualmente é um tipo de referência ou um tipo de valor ou não. Quando um tipo de valor é usado como o argumento de tipo, o tempo de execução gera o código que usa os tipos de valor diretamente sem conversão boxing de tipos de valor.  
  
 Ao usar um tipo de referência como um argumento de tipo genérico, use a sintaxe de identificador. Ao usar um tipo de valor como um argumento de tipo genérico, use o nome do tipo diretamente.  
  
 `// generics_overview_2.cpp`  
  
 `// compile with: /clr`  
  
 `generic <typename T>`  
  
 `ref class GenericType {};`  
  
 `ref class ReferenceType {};`  
  
 `value struct ValueType {};`  
  
 `int main() {`  
  
 `GenericType<ReferenceType^> x;`  
  
 `GenericType<ValueType> y;`  
  
 `}`  
  
## <a name="type-parameters"></a>Parâmetros de tipo  
 Parâmetros de tipo em uma classe genérica são tratados como outros identificadores. No entanto, porque o tipo não é conhecido, há restrições sobre seu uso. Por exemplo, você não pode usar os membros e os métodos da classe de parâmetro de tipo, a menos que o parâmetro de tipo é conhecido para dar suporte a esses membros. Ou seja, para acessar um membro por meio do parâmetro de tipo, você deve adicionar o tipo que contém o membro à lista de restrição do parâmetro de tipo.  
  
 `// generics_overview_3.cpp`  
  
 `// compile with: /clr`  
  
```  
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
  
 Essas restrições se aplicam aos operadores também. Um parâmetro de tipo genérico irrestrita não pode usar o `==` e `!=` operadores para comparar duas instâncias do parâmetro de tipo, caso o tipo não oferece suporte a esses operadores. Essas verificações são necessárias para genéricos, mas não para os modelos, pois podem ser especializados genéricos em tempo de execução com qualquer classe que satisfaça as restrições, quando é tarde demais para verificar o uso de membros inválidos.  
  
 Uma instância padrão do parâmetro de tipo pode ser criada usando o `()` operador. Por exemplo:  
  
 `T t = T();`  
  
 onde `T` é um parâmetro de tipo em uma definição de classe ou método genérico, inicializa a variável para o valor padrão. Se `T` é uma classe de referência é um ponteiro nulo; se `T` é uma classe de valor, o objeto é inicializado a zero. Isso é chamado de um *padrão inicializador*.  
  
## <a name="see-also"></a>Consulte também  
 [Genéricos](../windows/generics-cpp-component-extensions.md)