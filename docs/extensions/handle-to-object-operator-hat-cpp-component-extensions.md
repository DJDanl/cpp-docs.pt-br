---
title: Operador Handle to Object (^) (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- ^ handle to object [C++]
ms.assetid: 70c411e6-be57-4468-a944-6ea7be89f392
ms.openlocfilehash: bdf19b6b472cd4d224d749f59c75ca77d11c34f8
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "65516691"
---
# <a name="handle-to-object-operator---ccli-and-ccx"></a>Operador Handle to Object (^) (C++/CLI e C++/CX)

O *handle declarator* (`^`, pronunciado "rét"), modifica o tipo [specifier](../cpp/overview-of-declarators.md) para significar que o objeto declarado deve ser automaticamente excluído quando o sistema determina que o objeto não está mais acessível.

## <a name="accessing-the-declared-object"></a>Acessar o objeto declarado

Uma variável que é declarada com o declarador identificador comporta-se como um ponteiro para o objeto. No entanto, a variável aponta para o objeto inteiro, não pode apontar para um membro do objeto e não é compatível com a aritmética de ponteiro. Use o operador de indireção (`*`) para acessar o objeto e o operador de acesso de membro de seta (`->`) para acessar um membro do objeto.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

O compilador usa o mecanismo *reference counting* COM para determinar se o objeto não está mais sendo usado e pode ser excluído. Isso é possível porque um objeto derivado de uma interface do Windows Runtime é, na verdade, um objeto COM. A contagem de referência é incrementada quando o objeto é criado ou copiado e reduzida quando o objeto é definido como nulo ou sai do escopo. Se a contagem de referência chegar a zero, o objeto será excluído automática e imediatamente.

A vantagem do declarador identificador é que no COM você deve gerenciar explicitamente a contagem de referência para um objeto, o que é um processo tedioso e propenso a erros. Ou seja, para incrementar e decrementar a contagem de referência, você deve chamar os métodos AddRef() e Release() do objeto. No entanto, se você declarar um objeto com o declarador identificador, o compilador gerará código que ajusta automaticamente a contagem de referência.

Saiba mais sobre como criar uma instância de um objeto em [ref new](ref-new-gcnew-cpp-component-extensions.md).

## <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

O sistema usa o mecanismo *garbage collector* do CLR para determinar se o objeto não está mais sendo usado e pode ser excluído. O Common Language Runtime mantém um heap no qual aloca objetos e usa referências gerenciadas (variáveis) em seu programa para indicar a localização de objetos no heap. Quando um objeto não é mais usado, a memória ocupada no heap é liberada. Periodicamente, o coletor de lixo compacta o heap para melhorar o uso da memória liberada. A compactação pode mover objetos no heap, o que invalida os locais referidos por referências gerenciadas. No entanto, o coletor de lixo está ciente do local de todas as referências gerenciadas e as atualiza automaticamente para indicar o local atual dos objetos no heap.

Como os ponteiros nativos de C++ (`*`) e as referências (`&`) não são referências gerenciadas, o coletor de lixo não pode atualizar automaticamente os endereços para os quais eles apontam. Para resolver esse problema, use o declarador identificador para especificar uma variável da qual o coletor de lixo esteja ciente e possa ser atualizada automaticamente.

Para obter mais informações, confira [Como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).

### <a name="examples"></a>Exemplos

Este exemplo mostra como criar uma instância de um tipo de referência no heap gerenciado.  Este exemplo também mostra que você pode iniciar um identificador com outro, resultando em duas referências ao mesmo objeto no heap gerenciado e no heap do coletor do lixo. Observe que atribuir [nullptr](nullptr-cpp-component-extensions.md) a um identificador não marca o objeto para coleta de lixo.

```cpp
// mcppv2_handle.cpp
// compile with: /clr
ref class MyClass {
public:
   MyClass() : i(){}
   int i;
   void Test() {
      i++;
      System::Console::WriteLine(i);
   }
};

int main() {
   MyClass ^ p_MyClass = gcnew MyClass;
   p_MyClass->Test();

   MyClass ^ p_MyClass2;
   p_MyClass2 = p_MyClass;

   p_MyClass = nullptr;
   p_MyClass2->Test();
}
```

```Output
1
2
```

A amostra a seguir mostra como declarar um identificador para um objeto no heap gerenciado, em que o tipo de objeto é um tipo de valor demarcado. O exemplo também mostra como obter o tipo de valor do objeto demarcado.

```cpp
// mcppv2_handle_2.cpp
// compile with: /clr
using namespace System;

void Test(Object^ o) {
   Int32^ i = dynamic_cast<Int32^>(o);

   if(i)
      Console::WriteLine(i);
   else
      Console::WriteLine("Not a boxed int");
}

int main() {
   String^ str = "test";
   Test(str);

   int n = 100;
   Test(n);
}
```

```Output
Not a boxed int
100
```

Este exemplo mostra que a linguagem comum em C++ de usar um ponteiro `void*` para apontar para um objeto arbitrário é substituída por `Object^`, que pode conter um identificador para qualquer classe de referência. Também mostra que todos os tipos, como matrizes e delegados, podem ser convertidos em um identificador de objetos.

```cpp
// mcppv2_handle_3.cpp
// compile with: /clr
using namespace System;
using namespace System::Collections;
public delegate void MyDel();
ref class MyClass {
public:
   void Test() {}
};

void Test(Object ^ x) {
   Console::WriteLine("Type is {0}", x->GetType());
}

int main() {
   // handle to Object can hold any ref type
   Object ^ h_MyClass = gcnew MyClass;

   ArrayList ^ arr = gcnew ArrayList();
   arr->Add(gcnew MyClass);

   h_MyClass = dynamic_cast<MyClass ^>(arr[0]);
   Test(arr);

   Int32 ^ bi = 1;
   Test(bi);

   MyClass ^ h_MyClass2 = gcnew MyClass;

   MyDel^ DelInst = gcnew MyDel(h_MyClass2, &MyClass::Test);
   Test(DelInst);
}
```

```Output
Type is System.Collections.ArrayList

Type is System.Int32

Type is MyDel
```

Esse exemplo mostra que a referência de um identificador pode ser removida e que um membro pode ser acessado por meio de um identificador não referenciado.

```cpp
// mcppv2_handle_4.cpp
// compile with: /clr
using namespace System;
value struct DataCollection {
private:
   int Size;
   array<String^>^ x;

public:
   DataCollection(int i) : Size(i) {
      x = gcnew array<String^>(Size);
      for (int i = 0 ; i < Size ; i++)
         x[i] = i.ToString();
   }

   void f(int Item) {
      if (Item >= Size)
      {
         System::Console::WriteLine("Cannot access array element {0}, size is {1}", Item, Size);
         return;
      }
      else
         System::Console::WriteLine("Array value: {0}", x[Item]);
   }
};

void f(DataCollection y, int Item) {
   y.f(Item);
}

int main() {
   DataCollection ^ a = gcnew DataCollection(10);
   f(*a, 7);   // dereference a handle, return handle's object
   (*a).f(11);   // access member via dereferenced handle
}
```

```Output
Array value: 7

Cannot access array element 11, size is 10
```

Este exemplo mostra que uma referência nativa (`&`) não pode ser vinculada a um membro **int** de um tipo gerenciado, pois o **int** pode ser armazenado no heap coletado do lixo e as referências nativas não rastreiam o movimento de objetos no heap gerenciado. A correção é usar uma variável local ou alterar `&` para `%`, tornando-a uma referência de rastreamento.

```cpp
// mcppv2_handle_5.cpp
// compile with: /clr
ref struct A {
   void Test(unsigned int &){}
   void Test2(unsigned int %){}
   unsigned int i;
};

int main() {
   A a;
   a.i = 9;
   a.Test(a.i);   // C2664
   a.Test2(a.i);   // OK

   unsigned int j = 0;
   a.Test(j);   // OK
}
```

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>
[Operador de Referência de Acompanhamento](tracking-reference-operator-cpp-component-extensions.md)
