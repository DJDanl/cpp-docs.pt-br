---
title: "Overview of Generics in Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "generics [C++], about generics"
  - "default initializers [C++]"
  - "type parameters [C++]"
  - "constructed types"
  - "type arguments [C++]"
  - "constructed types, open [C++]"
  - "open constructed types [C++]"
  - "constructed types, closed [C++]"
ms.assetid: 21f10637-0fce-4916-b925-6c86a126d3aa
caps.latest.revision: 21
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Overview of Generics in Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os produtos genéricas tipos são parametrizadas com suporte do Common Language Runtime.  Um tipo com parâmetros é um tipo que é definido com um parâmetro de tipo desconhecido que é especificado quando o genérico é usado.  
  
## Por que produtos genéricas?  
 Os modelos da suporte C\+\+ e modelos e produtos genéricas suporte a tipos com parâmetros para criar classes da coleção.  No entanto, os modelos oferecem a parametrização de tempo de compilação.  Você não pode fazer referência a um assembly que contém uma definição de modelo e criar novas especializações do modelo.  Depois de criado, um modelo especializado aparência classe ou qualquer outro método.  Ao contrário, os produtos genéricas serão emitidos em MSIL como um tipo com parâmetros conhecido em tempo de execução para ser um tipo com parâmetros; o código\-fonte que faz referência a um assembly que contém um tipo genérico pode criar especializações de tipo genérico.  Para obter mais informações sobre a comparação de modelos de produtos e genéricas do Visual C\+\+, consulte [Generics and Templates \(Visual C\+\+\)](../windows/generics-and-templates-visual-cpp.md).  
  
## Funções e tipos genéricos  
 Os tipos da classe, à medida que são tipos gerenciados, podem ser genéricas.  Um exemplo desse pode ser uma classe de `List` .  O tipo de um objeto da lista será o parâmetro de tipo.  Se você for uma classe de `List` para muitos tipos diferentes de objetos, antes dos produtos genéricas você pode usar `List` que usa **System::Object** como o tipo de item.  Mas isso permitiria que qualquer objeto \(que inclui objetos do tipo errado\) é usado na lista.  Essa lista será chamada sem\-tipo uma classe de coleção.  O melhor forma, você pode verificar o tipo em tempo de execução e gerar uma exceção.  Ou, você pode usar um modelo, que perdesse a qualidade genérico criada uma vez em um assembly.  Os consumidores do assembly não podem criar suas próprias especializações do modelo.  Os produtos genéricas permitem que você crie classes da coleção, indicam `List<int>` \(leitura como “lista de int”\) e `List<double>` lista de double \(“”\) que gerencia um erro de tempo de compilação se você tentar colocar um tipo que a coleção não tenha sido criada para aceitar digitada na coleção.  Além disso, esses tipos genéricos permanecem depois que são criados.  
  
 Uma descrição da sintaxe de classes genéricas podem ser encontradas na nova namespace de [Generic Classes \(C\+\+\/CLI\)](../Topic/Generic%20Classes%20\(C++-CLI\).md)`.` A, <xref:System.Collections.Generic>, apresenta um conjunto de tipos com parâmetros da coleção que incluem <xref:System.Collections.Generic.Dictionary%602>, <xref:System.Collections.Generic.List%601> e <xref:System.Collections.Generic.LinkedList%601>.  Consulte [Genéricos na biblioteca de classes .NET Framework](../Topic/Generics%20in%20the%20.NET%20Framework%20Class%20Library%20\(C%23%20Programming%20Guide\).md) para maiores informações.  
  
 As funções de membro da classe de instância e estáticos, os representantes, e as funções globais também podem ser genéricas.  As funções genéricas podem ser necessárias se os parâmetros de função são de um tipo desconhecido, ou se a própria função deve trabalhar com tipos genéricos.  Em muitos casos em que **System::Object** pode ter sido usado no passado como um parâmetro para um tipo de objeto desconhecido, um parâmetro de tipo genérico pode ser usado, permitindo para um código fortemente tipado mais segura.  Qualquer tentativa para passar um tipo que a função não foi criada para será sinalizada como um erro em tempo de compilação.  Usando **System::Object** como um parâmetro de função, transmita inadvertido de um objeto que a função não foi planejada tratar não será detectado, e precisará converter o tipo de objeto desconhecido em um tipo específico no corpo da função, e esclarece a possibilidade de um InvalidCastException.  Com um genérico, o código que tenta transmitir um objeto à função provocará um conflito de tipo para que o corpo da função é garantido para ter o tipo correto.  
  
 Os mesmos benefícios aplicam à coleção as classes criadas em produtos genéricas.  As classes da coleção no passado **System::Object** usariam para armazenar os elementos em uma coleção.  A inserção dos objetos de um tipo que a coleção não esteve criada para não foi sinalizada em tempo de compilação, e geralmente nem mesmo quando os objetos forem inseridos.  Geralmente, um objeto será convertido em outro tipo quando foi acessado na coleção.  Somente quando a conversão falha no tipo inesperado será detectado.  Os produtos genéricas resolver esse problema em tempo de compilação detectando qualquer código que inserir um tipo que não corresponde a \(ou para converter implicitamente\) o parâmetro de tipo de coleção genérica.  
  
 Para obter uma descrição da sintaxe, consulte [Generic Functions \(C\+\+\/CLI\)](../windows/generic-functions-cpp-cli.md).  
  
## Terminologia usada com produtos genéricas  
  
##### Parâmetros de tipo  
 Uma declaração genérico contém um ou mais tipos desconhecidos conhecidos como *parâmetros de tipo*.  Os parâmetros de tipo dados são um nome que representa o tipo dentro do corpo da instrução genérico.  O parâmetro de tipo for usado como um tipo dentro do corpo da instrução genérico.  A declaração genérico para ListT\<\> contém o parâmetro de tipo T.  
  
##### Argumentos do tipo  
 *O argumento de tipo* é o tipo real usado no lugar do parâmetro de tipo genérico quando o é especializado para um tipo específico ou digite.  Por exemplo, `int` é o argumento do tipo em `List<int>`.  Os tipos de valor e os tipos de identificador são os únicos tipos permitidos em como um argumento de tipo genérico.  
  
##### Tipo construído  
 Um tipo construído de um tipo genérico é referido como *um tipo construído*.  Um tipo especificado não total, como `List<T>` é *um tipo construído aberto*; um tipo especificado total, como `List<double>,` é *um tipo construído fechado* ou *tipo especializado*.  Abrir construído tipos pode ser usado na definição de outros tipos ou métodos genéricos e não pode ser completamente especificado até que incluir genérico próprios seja especificado.  Por exemplo, o seguinte é um uso de um tipo construído aberto como uma classe base de um genérico:  
  
 `// generics_overview.cpp`  
  
 `// compile with: /clr /c`  
  
 `generic <typename T>`  
  
 `ref class List {};`  
  
 `generic <typename T>`  
  
 `ref class Queue : public List<T> {};`  
  
##### Restrição  
 Uma restrição é uma limitação em tipos que podem ser usados como um parâmetro de tipo.  Por exemplo, uma classe genérico determinada pode aceitar apenas as classes que herdam de uma classe especificada, ou implementa uma interface especificada.  Para obter mais informações, consulte [Constraints on Generic Type Parameters \(C\+\+\/CLI\)](../Topic/Constraints%20on%20Generic%20Type%20Parameters%20\(C++-CLI\).md).  
  
## Tipos e tipos de valor de referência  
 Os identificadores tipos e os tipos de valores podem ser usados como argumentos do tipo.  Na definição genérico, em que cada tipo pode ser usado, a sintaxe é a de tipos de referência.  Por exemplo, o operador de **\-\>** é usado para acessar membros de tipo de parâmetro de tipo mesmo que o tipo usado se houver é um tipo de referência ou um tipo de valor.  Quando um tipo de valor é usado como o argumento do tipo, o tempo de execução gerencia o código que usa os tipos de valores diretamente sem o caso dos tipos de valor.  
  
 Ao usar um tipo de referência como um argumento de tipo genérico, use a sintaxe do identificador.  Ao usar um tipo de valor como um argumento genérico do tipo, use o nome do tipo diretamente.  
  
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
  
## Parâmetros de tipo  
 Os parâmetros de tipo em uma classe genérico são tratados como outros identificadores.  Porém, como o tipo não for conhecido, há limitações no uso.  Por exemplo, você não pode usar os membros e os métodos de parâmetro de tipo classificação a menos que o parâmetro de tipo é conhecido para oferecer suporte a esses membros.  Ou seja, para acessar um membro com o parâmetro de tipo, você deve adicionar o tipo que contém o membro à lista de restrição de parâmetro de tipo.  
  
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
  
 Essas restrições se aplicam aos operadores também.  Um parâmetro de tipo genérico irrestritas não pode usar os operadores de `==` e de `!=` para comparar duas instâncias do parâmetro de tipo, caso o tipo não oferece suporte a estes operadores.  Essas verificações são necessárias para produtos genéricos, mas não para modelos, como os produtos genéricas podem ser habilidosos em tempo de execução com qualquer classe que satisfaz as restrições, quando é muito tarde para verificar o uso de membros inválidos.  
  
 Uma instância padrão do parâmetro de tipo pode ser criada usando o operador de `()` .  Por exemplo:  
  
 `T t = T();`  
  
 onde `T` é um parâmetro de tipo em uma definição genérico da classe ou do método, inicializa a variável com seu valor padrão.  Se `T` é uma classe de referência será um ponteiro nulo; se `T` é uma classe de valor, o objeto é inicializado como zero.  Isso é chamado *de inicializador padrão*.  
  
## Consulte também  
 [Generics](../windows/generics-cpp-component-extensions.md)