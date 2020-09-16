---
title: Restrições em parâmetros de tipo genérico (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- where
helpviewer_keywords:
- where keyword [C++]
- constraints, C++
ms.assetid: eb828cc9-684f-48a3-a898-b327700c0a63
ms.openlocfilehash: 829f11c9f0c3935f9a415cae381cfc12d88df18a
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686750"
---
# <a name="constraints-on-generic-type-parameters-ccli"></a>Restrições em parâmetros de tipo genérico (C++/CLI)

Em declarações de tipo genérico ou de método, você pode qualificar um parâmetro de tipo com restrições. Uma restrição é um requisito que os tipos usados como argumentos de tipo devem atender. Um exemplo de restrição seria a necessidade do argumento de tipo de implementar uma certa interface ou herdar de uma classe específica.

Restrições são opcionais; não especificar uma restrição em um parâmetro é o mesmo que restringir esse parâmetro a <xref:System.Object>.

## <a name="syntax"></a>Sintaxe

```cpp
where type-parameter: constraint list
```

### <a name="parameters"></a>Parâmetros

*parâmetro de tipo*<br/>
Um dos parâmetros de tipo a ser restringido.

*lista de restrições*<br/>
A *lista de restrições* é uma lista separada por vírgulas das especificações de restrição. A lista pode incluir as interfaces a serem implementadas pelo parâmetro de tipo.

Ela também pode incluir uma classe. Para o argumento de tipo atender a uma restrição de classe base, ele deve ser da mesma classe que a restrição ou derivar da restrição.

Você também pode especificar **gcnew()** para indicar que o argumento de tipo deve ter um construtor público sem parâmetros; ou **classe ref** para indicar que o argumento de tipo deve ser um tipo de referência, incluindo qualquer classe, interface, delegado ou tipo de matriz; ou **classe de valor** para indicar que o tipo de argumento deve ser um tipo de valor. Qualquer tipo de valor, exceto Nullable, \<T> pode ser especificado.

Você também pode especificar um parâmetro genérico como restrição. O argumento de tipo fornecido para o tipo que você está restringindo deve ser ou derivar do tipo de restrição. Isso é chamado de restrição de tipo naked.

## <a name="remarks"></a>Comentários

A cláusula da restrição é composta por **where** seguido por um parâmetro de tipo, dois-pontos (**:**) e a restrição, que especifica a natureza da restrição no parâmetro de tipo. **where** é uma palavra-chave contextual; veja mais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md). Separe várias cláusulas **where** com um espaço.

As restrições são aplicadas aos parâmetros de tipo para colocar limitações sobre os tipos que podem ser usados como argumentos para um tipo ou método genérico.

As restrições de classe e de interface especificam que os tipos de argumento devem ser ou herdar de uma classe especificada ou implementar uma interface especificada.

A aplicação de restrições a um tipo ou método genérico permite que o código nesse tipo ou método tire proveito dos recursos conhecidos dos tipos restritos. Por exemplo, você pode declarar uma classe genérica de modo que o parâmetro de tipo implemente a interface `IComparable<T>`:

```cpp
// generics_constraints_1.cpp
// compile with: /c /clr
using namespace System;
generic <typename T>
where T : IComparable<T>
ref class List {};
```

Essa restrição exige que um argumento de tipo usado para `T` implemente `IComparable<T>` em tempo de compilação. Também permite que os métodos de interface, tais como `CompareTo`, sejam chamados. Nenhuma conversão é necessária em uma instância do parâmetro de tipo para chamar métodos de interface.

Os métodos estáticos na classe do argumento de tipo não podem ser chamados por meio do parâmetro de tipo; eles só podem ser chamados por meio do tipo nomeado real.

Uma restrição não pode ser um tipo de valor, incluindo tipos internos, como **`int`** ou **`double`** . Como os tipos de valor não podem ter classes derivadas, apenas uma classe seria capaz de atender à restrição. Nesse caso, o genérico pode ser reescrito com o parâmetro de tipo substituído pelo tipo de valor específico.

As restrições são necessárias em alguns casos, pois o compilador não permitirá o uso de métodos ou de outros recursos de um tipo desconhecido, a menos que as restrições indiquem que o tipo desconhecido é compatível com métodos ou interfaces.

É possível especificar várias restrições para o mesmo parâmetro de tipo em uma lista separada por vírgulas

```cpp
// generics_constraints_2.cpp
// compile with: /c /clr
using namespace System;
using namespace System::Collections::Generic;
generic <typename T>
where T : List<T>, IComparable<T>
ref class List {};
```

Com vários parâmetros de tipo, use uma cláusula **where** para cada parâmetro de tipo. Por exemplo:

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

- Se houver várias restrições listadas, as restrições poderão estar listadas em qualquer ordem.

- As restrições também podem ser tipos de classe, como classes base abstratas. No entanto, as restrições não podem ser tipos de valor ou classes seladas.

- As restrições não podem ser parâmetros de tipo, mas podem envolver os parâmetros de tipo em um tipo construído aberto. Por exemplo:

    ```cpp
    // generics_constraints_4.cpp
    // compile with: /c /clr
    generic <typename T>
    ref class G1 {};

    generic <typename Type1, typename Type2>
    where Type1 : G1<Type2>   // OK, G1 takes one type parameter
    ref class G2{};
    ```

## <a name="examples"></a>Exemplos

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

Quando um parâmetro de tipo genérico for usado como restrição, será chamado de restrição de tipo naked. As restrições de tipo naked são úteis quando uma função membro com parâmetro de tipo próprio tiver que restringir esse parâmetro ao parâmetro de tipo do tipo recipiente.

No exemplo a seguir, `T` é uma restrição de tipo naked no contexto do método `Add`.

Também é possível usar restrições de tipo naked em definições de classe genérica. A utilidade das restrições de tipo naked classes genéricas é limitada, pois o compilador não pode presumir nada sobre a restrição de tipo naked, exceto que deriva de <xref:System.Object>. Use as restrições de tipo naked em classes genéricas em cenários nos quais você deseja impor uma relação de herança entre dois parâmetros de tipo.

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

## <a name="see-also"></a>Confira também

[Genéricos](generics-cpp-component-extensions.md)
