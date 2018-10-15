---
title: Restrições em genérica de parâmetros de tipo (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- where
dev_langs:
- C++
helpviewer_keywords:
- where keyword [C++]
- constraints, C++
ms.assetid: eb828cc9-684f-48a3-a898-b327700c0a63
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c9e3a7f5dc68f9f6726d591f051a6c04a0d48485
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49328552"
---
# <a name="constraints-on-generic-type-parameters-ccli"></a>Restrições em parâmetros de tipo genérico (C++/CLI)

Em declarações de método ou tipo genérico, você pode qualificar um parâmetro de tipo com restrições. Uma restrição é um requisito que tipos usados como argumentos de tipo devem satisfazer. Por exemplo, uma restrição pode ser que o argumento de tipo deve implementar uma interface de determinados ou herdar de uma classe específica.

Restrições são opcionais. não especificar uma restrição em um parâmetro é equivalente a esse parâmetro para a restrição <xref:System.Object>.

## <a name="syntax"></a>Sintaxe

```cpp
where type-parameter: constraint list
```

### <a name="parameters"></a>Parâmetros

*parâmetro de tipo*<br/>
Um dos parâmetros de tipo, a ser restringido.

*lista de restrições*<br/>
*lista de restrições* é uma lista separada por vírgulas das especificações de restrição. A lista pode incluir as interfaces a serem implementadas pelo parâmetro de tipo.

A lista também pode incluir uma classe. Para o argumento de tipo satisfazer uma restrição de classe base, ele deve ser da mesma classe que a restrição ou derivar de restrição.

Você também pode especificar **gcnew()** para indicar o argumento de tipo deve ter um construtor público sem parâmetros; ou **classe ref** para indicar o argumento de tipo deve ser um tipo de referência, incluindo qualquer classe, interface, delegado ou tipo de matriz; ou **classe de valor** para indicar o tipo de argumento deve ser um tipo de valor. Qualquer valor de tipo, exceto permite valor nulo\<T > pode ser especificado.

Você também pode especificar um parâmetro genérico como uma restrição. O argumento de tipo fornecido para o tipo que são a restrição deve ser ou derivar do tipo de restrição. Isso é chamado uma restrição de tipo naked.

## <a name="remarks"></a>Comentários

A cláusula de restrição consiste **onde** seguido de um parâmetro de tipo, dois-pontos (**:**) e a restrição, que especifica a natureza da restrição no parâmetro de tipo. **em que** é uma palavra-chave contextual, consulte [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md) para obter mais informações. Separe vários **onde** cláusulas com um espaço.

Restrições são aplicadas aos parâmetros para colocar as limitações nos tipos que podem ser usados como argumentos para um tipo genérico ou método de tipo.

Restrições de classe e interface especificam que os tipos de argumento devem ser ou herdar de uma classe especificada ou implementar uma interface especificada.

A aplicação de restrições para um tipo genérico ou método permite que o código em que tipo ou método para tirar proveito dos recursos conhecidos dos tipos de restritos. Por exemplo, você pode declarar uma classe genérica, de modo que o parâmetro de tipo implementa o `IComparable<T>` interface:

```cpp
// generics_constraints_1.cpp
// compile with: /c /clr
using namespace System;
generic <typename T>
where T : IComparable<T>
ref class List {};
```

Essa restrição requer que um argumento de tipo usado para `T` implementa `IComparable<T>` em tempo de compilação. Ele também permite que os métodos de interface, tais como `CompareTo`, para ser chamado. Nenhuma conversão é necessária em uma instância do parâmetro de tipo para chamar métodos de interface.

Métodos estáticos na classe do argumento de tipo não podem ser chamados por meio do parâmetro de tipo; eles podem ser chamados somente por meio do tipo nomeado real.

Uma restrição não pode ser um tipo de valor, incluindo tipos internos, como **int** ou **duplo**. Uma vez que os tipos de valor não podem ter as classes derivadas, apenas uma classe nunca seria capaz de satisfazer a restrição. Nesse caso, o genérico pode ser reescrito com o parâmetro de tipo substituído pelo tipo de valor específico.

Restrições são necessárias em alguns casos, pois o compilador não permitirá o uso de métodos ou outros recursos de um tipo desconhecido, a menos que as restrições implicam que o tipo desconhecido oferece suporte a métodos ou interfaces.

Várias restrições para o mesmo parâmetro de tipo podem ser especificadas em uma lista separada por vírgulas

```cpp
// generics_constraints_2.cpp
// compile with: /c /clr
using namespace System;
using namespace System::Collections::Generic;
generic <typename T>
where T : List<T>, IComparable<T>
ref class List {};
```

Com vários parâmetros de tipo, use um **onde** cláusula para cada parâmetro de tipo. Por exemplo:

```cpp
// generics_constraints_3.cpp
// compile with: /c /clr
using namespace System;
using namespace System::Collections::Generic;

generic <typename K, typename V>
   where K: IComparable<K>
   where V: IComparable<K>
ref class Dictionary {};
```

Para resumir, use restrições em seu código de acordo com as regras a seguir:

- Se várias restrições estão listadas, as restrições podem estar listadas em qualquer ordem.

- Restrições também podem ser tipos de classe, como classes base abstratas. No entanto, as restrições não podem ser tipos de valor ou classes sealed.

- As restrições não podem ser parâmetros de tipo, mas eles podem envolver os parâmetros de tipo em um tipo construído aberto. Por exemplo:

    ```cpp
    // generics_constraints_4.cpp
    // compile with: /c /clr
    generic <typename T>
    ref class G1 {};

    generic <typename Type1, typename Type2>
    where Type1 : G1<Type2>   // OK, G1 takes one type parameter
    ref class G2{};
    ```

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar restrições para chamar métodos de instância em parâmetros de tipo.

```cpp
// generics_constraints_5.cpp
// compile with: /clr
using namespace System;

interface class IAge {
   int Age();
};

ref class MyClass {
public:
   generic <class ItemType> where ItemType : IAge
   bool isSenior(ItemType item) {
      // Because of the constraint,
      // the Age method can be called on ItemType.
      if (item->Age() >= 65)  
         return true;
      else
         return false;
   }
};

ref class Senior : IAge {
public:
   virtual int Age() {
      return 70;
   }
};

ref class Adult: IAge {
public:
   virtual int Age() {
      return 30;
   }
};

int main() {
   MyClass^ ageGuess = gcnew MyClass();
   Adult^ parent = gcnew Adult();
   Senior^ grandfather = gcnew Senior();

   if (ageGuess->isSenior<Adult^>(parent))  
      Console::WriteLine("\"parent\" is a senior");
   else
      Console::WriteLine("\"parent\" is not a senior");

   if (ageGuess->isSenior<Senior^>(grandfather))  
      Console::WriteLine("\"grandfather\" is a senior");
   else
      Console::WriteLine("\"grandfather\" is not a senior");
}
```

```Output
"parent" is not a senior
"grandfather" is a senior
```

## <a name="example"></a>Exemplo

Quando um parâmetro de tipo genérico é usado como uma restrição, ele é chamado uma restrição de tipo naked. Restrições de tipo naked são úteis quando uma função de membro com seu próprio parâmetro de tipo precisa restringir esse parâmetro para o parâmetro de tipo do tipo recipiente.

No exemplo a seguir `T` é uma restrição de tipo naked no contexto do `Add` método.

Restrições de tipo naked também podem ser usadas em definições de classe genérica. A utilidade das restrições de tipo naked com as classes genéricas é limitada, pois o compilador pode presumir nada sobre uma restrição de tipo naked, exceto que ele deriva <xref:System.Object>. Use restrições de tipo naked em classes genéricas em cenários em que você deseja impor uma relação de herança entre dois parâmetros de tipo.

```cpp
// generics_constraints_6.cpp
// compile with: /clr /c
generic <class T>
ref struct List {
   generic <class U>
   where U : T
   void Add(List<U> items)  {}
};

generic <class A, class B, class C>
where A : C
ref struct SampleClass {};
```

## <a name="see-also"></a>Consulte também

[Genéricos](../windows/generics-cpp-component-extensions.md)