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
ms.openlocfilehash: 12cead3a142c69da56390ca6f5bf32cecc3b0075
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="declaration-of-a-clr-reference-class-object"></a>Declaração de um objeto de classe de referência CLR
A sintaxe para declarar e criar um objeto do tipo de classe de referência foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 No Managed Extensions, um objeto de tipo de classe de referência é declarado usando a sintaxe de ponteiro ISO C++, com um uso opcional do `__gc` palavra-chave à esquerda da estrela (`*`). Por exemplo, aqui está uma variedade de referência de declarações de objeto de tipo de classe em que a sintaxe das extensões gerenciadas:  
  
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
  
 Sob a nova sintaxe, você deve declarar um objeto de tipo de classe de referência usando um novo token declarativo (`^`) conhecido anteriormente como um *identificador de rastreamento* e mais informalmente como um *hat*. (O controle adjetivo significa que um tipo de referência fica no heap de CLR e, portanto, pode mover transparentemente locais durante a compactação de heap de coleta de lixo. Um identificador de controle de forma transparente é atualizado durante a execução. São dois conceitos semelhantes de *a referência de rastreamento* (`%`) e o *ponteiro interior* (`interior_ptr<>`), discutido na [semântica do tipo de valor](../dotnet/value-type-semantics.md).  
  
 As principais razões para mover a sintaxe declarativa longe uma reutilização da sintaxe do ponteiro C++ ISO são da seguinte maneira:  
  
-   O uso da sintaxe de ponteiro não permitiu que operadores sobrecarregados ser aplicado diretamente a um objeto de referência. Em vez disso, era preciso chamar o operador, usando seu nome interno, como `rV1->op_Addition(rV2)` em vez de mais intuitiva `rV1+rV2`.  
  
-   Um número de operações de ponteiro, como a conversão e a aritmética de ponteiro não permitido para objetos armazenados em um lixo coletado heap. A noção de um identificador de rastreamento melhor captura a natureza de um tipo de referência do CLR.  
  
 O `__gc` modificador em um identificador de rastreamento não é necessário e não é suportado. O uso do objeto em si não é alterado; ele ainda acessa membros por meio do operador de seleção de membro de ponteiro (`->`). Por exemplo, aqui está o exemplo de código anterior das extensões gerenciadas traduzido para a nova sintaxe:  
  
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
  
## <a name="dynamic-allocation-of-an-object-on-the-clr-heap"></a>Alocação dinâmica de um objeto do heap de CLR  
 No Managed Extensions, a existência de dois `new` expressões para alocar entre o heap gerenciado e nativo foi amplamente transparente. Em quase todos os casos, o compilador é capaz de usar o contexto para determinar se deve alocar memória do heap gerenciado ou nativo. Por exemplo,  
  
```  
Button *button1 = new Button; // OK: managed heap  
int *pi1 = new int;           // OK: native heap  
Int32 *pi2 = new Int32;       // OK: managed heap  
```  
  
 Quando você não quiser que a alocação de heap contextuais, você pode direcionar o compilador com o o `__gc` ou `__nogc` palavra-chave. A nova sintaxe, a natureza separada das duas expressões novo é feita explícita com a introdução do `gcnew` palavra-chave. Por exemplo, três declarações anteriores é semelhante ao seguinte na nova sintaxe:  
  
```  
Button^ button1 = gcnew Button;        // OK: managed heap  
int * pi1 = new int;                   // OK: native heap  
Int32^ pi2 = gcnew Int32; // OK: managed heap  
```  
  
 Aqui está a inicialização das extensões gerenciadas do `Form1` membros declarados na seção anterior:  
  
```  
void InitializeComponent() {  
   components = new System::ComponentModel::Container();  
   button1 = new System::Windows::Forms::Button();  
   myDataGrid = new DataGrid();  
  
   button1->Click +=   
      new System::EventHandler(this, &Form1::button1_Click);  
}  
```  
  
 Aqui está a mesma inicialização reconvertida a nova sintaxe. Observe que o hat não é necessário para o tipo de referência quando ele é o destino de um `gcnew` expressão.  
  
```  
void InitializeComponent() {  
   components = gcnew System::ComponentModel::Container;  
   button1 = gcnew System::Windows::Forms::Button;  
   myDataGrid = gcnew DataGrid;  
  
   button1->Click +=   
      gcnew System::EventHandler( this, &Form1::button1_Click );  
}  
```  
  
## <a name="a-tracking-reference-to-no-object"></a>Uma referência de rastreamento para nenhum objeto  
 Na sintaxe de novo, `0` não representa um endereço nulo, mas é tratado como um inteiro, mesmo que `1`, `10`, ou `100`. Um novo token especial representa um valor nulo para uma referência de rastreamento. Por exemplo, nas extensões gerenciadas, podemos inicializar um tipo de referência para não atender a nenhum objeto da seguinte maneira:  
  
```  
// OK: we set obj to refer to no object  
Object * obj = 0;  
  
// Error: no implicit boxing  
Object * obj2 = 1;  
```  
  
 Na sintaxe de novo, qualquer inicialização ou atribuição de um valor de tipo para um `Object` faz com que uma conversão boxing implícita desse tipo de valor. Na nova sintaxe, ambos `obj` e `obj2` são inicializadas endereçados demarcados objetos Int32 mantendo os valores 0 e 1, respectivamente. Por exemplo:  
  
```  
// causes the implicit boxing of both 0 and 1  
Object ^ obj = 0;  
Object ^ obj2 = 1;  
```  
  
 Portanto, para executar a inicialização explícita, a atribuição e a comparação de um identificador de rastreamento como null, use uma nova palavra-chave, `nullptr`.  A revisão correta do exemplo original tem a seguinte aparência:  
  
```  
// OK: we set obj to refer to no object  
Object ^ obj = nullptr;  
  
// OK: we initialize obj2 to a Int32^  
Object ^ obj2 = 1;  
```  
  
 Isso complica um pouco a portabilidade de código existente para a nova sintaxe. Por exemplo, considere a seguinte declaração de classe de valor:  
  
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
  
 Da mesma forma, testes em relação a esses membros compará-los para `0` também deve ser alterada para comparar os membros a serem `nullptr`. Aqui está a sintaxe das extensões gerenciadas:  
  
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
  
 Aqui está a revisão, substituindo cada `0` instância com um `nullptr`. A ferramenta de conversão ajuda a essa transformação automatizando muitos se não usam todas as ocorrências, incluindo o `NULL` macro.  
  
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
  
 O `nullptr` é convertido em qualquer tipo de identificador de ponteiro ou controle, mas não é promovido para um tipo integral. Por exemplo, no seguinte conjunto de inicializações, o `nullptr` é válida somente como um valor inicial para as duas primeiras.  
  
```  
// OK: we set obj and pstr to refer to no object  
Object^ obj = nullptr;  
char*   pstr = nullptr; // 0 would also work here  
  
// Error: no conversion of nullptr to 0  
int ival = nullptr;  
```  
  
 Da mesma forma, dado um sobrecarregados conjunto de métodos, como o seguinte:  
  
```  
void f( Object^ ); // (1)  
void f( char* );   // (2)  
void f( int );     // (3)  
```  
  
 Uma chamada com `nullptr` literal, como o seguinte  
  
```  
// Error: ambiguous: matches (1) and (2)  
f(  nullptr );  
```  
  
 é ambíguo porque o `nullptr` corresponde a um identificador de rastreamento e um ponteiro e não há nenhuma preferência para um tipo a outro. (Essa situação requer uma conversão explícita para desfazer a ambiguidade.)  
  
 Uma chamada com `0` exatamente a instância de correspondências (3):  
  
```  
// OK: matches (3)  
f( 0 );  
```  
  
 porque `0` é do tipo inteiro. Foram `f(int)` não está presente, a chamada de maneira não ambígua corresponderia `f(char*)` por meio de uma conversão padrão. As regras de correspondência dar prioridade de uma correspondência exata em lugar de uma conversão padrão. Na ausência de uma correspondência exata, uma conversão padrão tem precedência sobre uma conversão boxing implícita de um tipo de valor. É por isso que não há nenhuma ambiguidade.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C + + CL)](../dotnet/managed-types-cpp-cl.md)   
 [Classes e structs](../windows/classes-and-structs-cpp-component-extensions.md)   
 [Operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)   
 [nullptr](../windows/nullptr-cpp-component-extensions.md)