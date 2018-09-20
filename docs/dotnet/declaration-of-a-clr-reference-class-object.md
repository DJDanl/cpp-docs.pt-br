---
title: Declaração de um objeto de classe de referência CLR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- types [C++], reference types
- reference types, CLR
ms.assetid: 6d64f746-3715-4948-ada3-88859f4150e4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f3e8ec6407e12d0c26331d45dc1659277feed016
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444574"
---
# <a name="declaration-of-a-clr-reference-class-object"></a>Declaração de um objeto de classe de referência CLR

A sintaxe para declarar e instanciar um objeto do tipo de classe de referência foi alterado de extensões gerenciadas para C++ no Visual C++.

Nas extensões gerenciadas, um objeto de tipo de classe de referência é declarado usando a sintaxe de ponteiro de ISO-c, com um uso opcional do `__gc` palavra-chave à esquerda da estrela (`*`). Por exemplo, eis uma variedade de referência de declarações de objeto de tipo de classe em que a sintaxe de Managed Extensions:

```
public __gc class Form1 : public System::Windows::Forms::Form {
private:
   System::ComponentModel::Container __gc *components;
   Button __gc *button1;
   DataGrid __gc *myDataGrid;
   DataSet __gc *myDataSet;

   void PrintValues( Array* myArr ) {
      System::Collections::IEnumerator* myEnumerator =
         myArr->GetEnumerator();

      Array *localArray;
      myArr->Copy(myArr, localArray, myArr->Length);
   }
};
```

Sob a nova sintaxe, você deve declarar um objeto de tipo de classe de referência por meio de um novo token declarativo (`^`) conhecido anteriormente como um *alça de controle* e, de modo mais informal, como um *hat*. (O controle adjetivo significa que um tipo de referência se encontra no heap de CLR e, portanto, pode mover transparentemente locais durante a compactação de heap de coleta de lixo. Um identificador de acompanhamento de forma transparente é atualizado durante o tempo de execução. Dois conceitos semelhantes são as *referência de rastreamento* (`%`) e o *ponteiro interior* (`interior_ptr<>`), discutido [semântica de tipo de valor](../dotnet/value-type-semantics.md).

Os principais motivos para mover a sintaxe declarativa para fora de uma reutilização da sintaxe de ponteiro de ISO-c serão o seguinte:

- O uso da sintaxe de ponteiro não permitiu que os operadores sobrecarregados a ser aplicado diretamente a um objeto de referência. Em vez disso, era preciso chamar o operador, usando seu nome interno, como `rV1->op_Addition(rV2)` em vez de mais intuitiva `rV1+rV2`.

- Um número de operações de ponteiro, como a projeção e aritmética, de ponteiro não permitido para objetos armazenados em um lixo coletado heap. A noção de um identificador de acompanhamento melhor captura a natureza de um tipo de referência do CLR.

O `__gc` modificador em um identificador de acompanhamento é desnecessário e não tem suporte. O uso do objeto em si não é alterado; ainda acessa os membros por meio do operador de seleção de membro do ponteiro (`->`). Por exemplo, aqui está o exemplo de código anterior extensões gerenciadas traduzido para a nova sintaxe:

```
public ref class Form1: public System::Windows::Forms::Form {
private:
   System::ComponentModel::Container^ components;
   Button^ button1;
   DataGrid^ myDataGrid;
   DataSet^ myDataSet;

   void PrintValues( Array^ myArr ) {
      System::Collections::IEnumerator^ myEnumerator =
         myArr->GetEnumerator();

      Array ^localArray;
      myArr->Copy(myArr, localArray, myArr->Length);   }
};
```

## <a name="dynamic-allocation-of-an-object-on-the-clr-heap"></a>Alocação dinâmica de um objeto no Heap CLR

Nas extensões gerenciadas, a existência de dois `new` expressões para alocar entre o heap gerenciado e nativo foi totalmente transparente. Em quase todos os casos, o compilador é capaz de usar o contexto para determinar se deve alocar memória do heap nativo ou gerenciado. Por exemplo,

```
Button *button1 = new Button; // OK: managed heap
int *pi1 = new int;           // OK: native heap
Int32 *pi2 = new Int32;       // OK: managed heap
```

Quando você não quiser que a alocação de heap contextuais, você pode direcionar o compilador com qualquer um de `__gc` ou `__nogc` palavra-chave. Na nova sintaxe, a natureza separada das duas expressões novo é explicita com a introdução do `gcnew` palavra-chave. Por exemplo, três declarações anteriores é semelhante ao seguinte na nova sintaxe:

```
Button^ button1 = gcnew Button;        // OK: managed heap
int * pi1 = new int;                   // OK: native heap
Int32^ pi2 = gcnew Int32; // OK: managed heap
```

Aqui está a inicialização de Managed Extensions do `Form1` membros declarados na seção anterior:

```
void InitializeComponent() {
   components = new System::ComponentModel::Container();
   button1 = new System::Windows::Forms::Button();
   myDataGrid = new DataGrid();

   button1->Click +=
      new System::EventHandler(this, &Form1::button1_Click);
}
```

Aqui está a inicialização mesma reconvertida a nova sintaxe. Observe que o chapéu não é necessário para o tipo de referência quando ele é o destino de um `gcnew` expressão.

```
void InitializeComponent() {
   components = gcnew System::ComponentModel::Container;
   button1 = gcnew System::Windows::Forms::Button;
   myDataGrid = gcnew DataGrid;

   button1->Click +=
      gcnew System::EventHandler( this, &Form1::button1_Click );
}
```

## <a name="a-tracking-reference-to-no-object"></a>Uma referência a nenhum objeto de rastreamento

Na nova sintaxe `0` não representa um endereço nulo, mas é tratado como um inteiro, o mesmo que `1`, `10`, ou `100`. Um novo token especial representa um valor nulo para uma referência de rastreamento. Por exemplo, nas extensões gerenciadas, vamos inicializar um tipo de referência para não atender a nenhum objeto da seguinte maneira:

```
// OK: we set obj to refer to no object
Object * obj = 0;

// Error: no implicit boxing
Object * obj2 = 1;
```

Na nova sintaxe, qualquer inicialização ou atribuição de um valor de tipo para um `Object` faz com que uma conversão boxing implícita de que tipo de valor. Na nova sintaxe, ambos `obj` e `obj2` são inicializadas endereçados objetos convertidos de Int32, mantendo os valores 0 e 1, respectivamente. Por exemplo:

```
// causes the implicit boxing of both 0 and 1
Object ^ obj = 0;
Object ^ obj2 = 1;
```

Portanto, para executar a inicialização explícita, atribuição e comparação de um identificador de acompanhamento para nulo, use uma nova palavra-chave, `nullptr`.  A revisão correta do exemplo original tem a seguinte aparência:

```
// OK: we set obj to refer to no object
Object ^ obj = nullptr;

// OK: we initialize obj2 to a Int32^
Object ^ obj2 = 1;
```

Isso complica um pouco a portabilidade do código existente para a nova sintaxe. Por exemplo, considere a seguinte declaração de classe de valor:

```
__value struct Holder {
   Holder( Continuation* c, Sexpr* v ) {
      cont = c;
      value = v;
      args = 0;
      env = 0;
   }

private:
   Continuation* cont;
   Sexpr * value;
   Environment* env;
   Sexpr * args __gc [];
};
```

Aqui, ambas `args` e `env` são tipos de referência do CLR. A inicialização desses dois membros para `0` no construtor não é possível permanecem inalterados na transição para a nova sintaxe. Em vez disso, eles devem ser alterados para `nullptr`:

```
value struct Holder {
   Holder( Continuation^ c, Sexpr^ v )
   {
      cont = c;
      value = v;
      args = nullptr;
      env = nullptr;
   }

private:
   Continuation^ cont;
   Sexpr^ value;
   Environment^ env;
   array<Sexpr^>^ args;
};
```

Da mesma forma, testes em relação a esses membros compará-los para `0` também deve ser alterado para comparar os membros a serem `nullptr`. Aqui está a sintaxe de Managed Extensions:

```
Sexpr * Loop (Sexpr* input) {
   value = 0;
   Holder holder = Interpret(this, input, env);

   while (holder.cont != 0) {
      if (holder.env != 0) {
         holder=Interpret(holder.cont,holder.value,holder.env);
      }
      else if (holder.args != 0) {
         holder =
         holder.value->closure()->
         apply(holder.cont,holder.args);
      }
   }

   return value;
}
```

Aqui está a revisão, substituindo cada `0` da instância com um `nullptr`. A ferramenta de tradução ajuda a essa transformação automatiza muitas se não usam todas as ocorrências, incluindo o `NULL` macro.

```
Sexpr ^ Loop (Sexpr^ input) {
   value = nullptr;
   Holder holder = Interpret(this, input, env);

   while ( holder.cont != nullptr ) {
      if ( holder.env != nullptr ) {
         holder=Interpret(holder.cont,holder.value,holder.env);
      }
      else if (holder.args != nullptr ) {
         holder =
         holder.value->closure()->
         apply(holder.cont,holder.args);
      }
   }

   return value;
}
```

O `nullptr` é convertida em qualquer tipo de identificador de rastreamento ou de ponteiro, mas não será promovido para um tipo integral. Por exemplo, no seguinte conjunto de inicializações, o `nullptr` é válida somente como um valor inicial para as duas primeiras.

```
// OK: we set obj and pstr to refer to no object
Object^ obj = nullptr;
char*   pstr = nullptr; // 0 would also work here

// Error: no conversion of nullptr to 0
int ival = nullptr;
```

Da mesma forma, dado um conjunto sobrecarregado dos métodos como o seguinte:

```
void f( Object^ ); // (1)
void f( char* );   // (2)
void f( int );     // (3)
```

Uma invocação com `nullptr` literal, como a seguir,

```
// Error: ambiguous: matches (1) and (2)
f(  nullptr );
```

é ambíguo porque o `nullptr` corresponde a um identificador de acompanhamento e um ponteiro e não há nenhuma preferência para um tipo em detrimento do outro. (Essa situação requer uma conversão explícita para resolver a ambiguidade.)

Uma invocação com `0` exatamente a instância de correspondências (3):

```
// OK: matches (3)
f( 0 );
```

porque `0` é do tipo inteiro. Foram `f(int)` não estiver presente, a chamada de maneira não ambígua corresponderia `f(char*)` por meio de uma conversão padrão. As regras de correspondência dar prioridade de uma correspondência exata ao longo de uma conversão padrão. Na ausência de uma correspondência exata, uma conversão padrão tem precedência sobre uma conversão boxing implícita de um tipo de valor. É por isso que não há nenhuma ambiguidade.

## <a name="see-also"></a>Consulte também

[Tipos gerenciados (C++ /CLI CL)](../dotnet/managed-types-cpp-cl.md)<br/>
[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)<br/>
[Operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)<br/>
[nullptr](../windows/nullptr-cpp-component-extensions.md)