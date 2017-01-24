---
title: "Declara&#231;&#227;o de um objeto de classe de refer&#234;ncia CLR | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de referência, CLR"
  - "tipos [C++], tipos de referência"
ms.assetid: 6d64f746-3715-4948-ada3-88859f4150e4
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#227;o de um objeto de classe de refer&#234;ncia CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sintaxe para declarar e criar uma instância de um objeto de um tipo de classe de referência foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Em extensões gerenciadas, objeto de tipo de classe de referência é declarado usando a sintaxe do ponteiro de ISO\-C\+\+, com um uso opcional da palavra\-chave de `__gc` à esquerda em estrela \(`*`\).  Por exemplo, aqui estão uma variedade de instruções do objeto de tipo de classe de referência na sintaxe gerenciado de extensões:  
  
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
  
 Na nova sintaxe, você declara um objeto de tipo de classe de referência usando um novo token declarativo \(\)`^`mencionado como formalmente como *um identificador de rastreamento* e mais o como *um chapéu*. \(O adjetivo de rastreamento significa que um tipo de referência se encontra no heap de CLR, e se transparente em virtude disso pode mover locais durante a consolidação de heap de coleta de lixo.  Um identificador de rastreamento é atualizada transparente durante o tempo de execução.  Dois conceitos são semelhantes *a referência de rastreamento* \(`%`\), e *o ponteiro dentro*`interior_ptr<>`\(\), discutido em [Semântica do tipo de valor](../Topic/Value%20Type%20Semantics.md).  
  
 As razões principais mover a sintaxe declarativa longe a reutilização da sintaxe do ponteiro de ISO\-C\+\+ são os seguintes:  
  
-   O uso da sintaxe do ponteiro não permitidos operadores sobrecarregados ser aplicado diretamente a um objeto de referência.  Em vez disso, se tivesse que chamar o operador usando seu nome interna, como `rV1->op_Addition(rV2)` em vez de `rV1+rV2`mais intuitivo.  
  
-   Um número de operações do ponteiro, como a conversão e aritmética do ponteiro, não permitidas para os objetos armazenados em um heap coletado lixo.  A noção de melhores captura de um identificador de rastreamento a natureza de um tipo de referência de CLR.  
  
 O modificador de `__gc` em um identificador de rastreamento é desnecessário e não tem suporte.  O uso do próprio objeto não é alterado; ainda acessará membros por meio do operador de seleção do membro do ponteiro`->`\(\).  Por exemplo, aqui está o exemplo de código gerenciado anterior das extensões convertida na nova sintaxe:  
  
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
  
## Alocação dinâmica de um objeto no heap de CLR  
 Em extensões gerenciadas, a existência de duas expressões de `new` a atribuir entre o modo nativo e o heap não gerenciada em grande parte transparente.  Em praticamente todas as instâncias, o compilador pode usar o contexto para determinar se alocar memória nativo ou heap gerenciado.  Por exemplo,  
  
```  
Button *button1 = new Button; // OK: managed heap  
int *pi1 = new int;           // OK: native heap  
Int32 *pi2 = new Int32;       // OK: managed heap  
```  
  
 Quando você não quiser que a alocação contextuais de heap, você pode direcionar o compilador com `__gc` ou palavras\-chave de `__nogc` .  Na nova sintaxe, a natureza separado das duas novas expressões são explicitadas com a introdução da palavra\-chave de `gcnew` .  Por exemplo, as três instruções anteriores são semelhantes a seguir na nova sintaxe:  
  
```  
Button^ button1 = gcnew Button;        // OK: managed heap  
int * pi1 = new int;                   // OK: native heap  
Int32^ pi2 = gcnew Int32; // OK: managed heap  
```  
  
 Aqui está a inicialização gerenciado das extensões dos membros de `Form1` declarados na seção anterior:  
  
```  
void InitializeComponent() {  
   components = new System::ComponentModel::Container();  
   button1 = new System::Windows::Forms::Button();  
   myDataGrid = new DataGrid();  
  
   button1->Click +=   
      new System::EventHandler(this, &Form1::button1_Click);  
}  
```  
  
 Aqui está a mesma inicialização foi reconvertida a nova sintaxe.  Observe que o chapéu não é necessário para o tipo de referência quando é o destino de uma expressão de `gcnew` .  
  
```  
void InitializeComponent() {  
   components = gcnew System::ComponentModel::Container;  
   button1 = gcnew System::Windows::Forms::Button;  
   myDataGrid = gcnew DataGrid;  
  
   button1->Click +=   
      gcnew System::EventHandler( this, &Form1::button1_Click );  
}  
```  
  
## Uma referência a um objeto de controle  
 Na nova sintaxe, `0` não representa um endereço mas nulo é tratado como um inteiro, o mesmo que `1`, `10`, ou `100`.  Um novo token especial representa um valor nulo para uma referência de rastreamento.  Por exemplo, em extensões gerenciadas, é inicializamos um tipo de referência para não ter nenhum objeto da seguinte maneira:  
  
```  
// OK: we set obj to refer to no object  
Object * obj = 0;  
  
// Error: no implicit boxing  
Object * obj2 = 1;  
```  
  
 Na nova sintaxe, qualquer inicialização ou atribuição de um tipo de valor a `Object` causam um com implícita desse tipo de valor.  Na nova sintaxe, `obj` e `obj2` são inicializados para objetos boxed Int32 os endereçados que mantêm os valores 0 e 1, respectivamente.  Por exemplo:  
  
```  
// causes the implicit boxing of both 0 and 1  
Object ^ obj = 0;  
Object ^ obj2 = 1;  
```  
  
 Consequentemente, a fim de executar a inicialização explícita, a atribuição, e a comparação de um identificador de rastreamento como nulo, usam uma nova palavra\-chave, `nullptr`.  A análise correta de exemplo original é semelhante a seguinte maneira:  
  
```  
// OK: we set obj to refer to no object  
Object ^ obj = nullptr;  
  
// OK: we initialize obj2 to a Int32^  
Object ^ obj2 = 1;  
```  
  
 Isso complica um pouco mover de código existente na nova sintaxe.  Por exemplo, considere a seguinte declaração de classe do valor:  
  
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
  
 Aqui, `args` e `env` são tipos de referência de CLR.  A inicialização desses dois membros a `0` no construtor não pode permanecer inalterado na transição para a nova sintaxe.  Em vez disso, devem ser alterados para `nullptr`:  
  
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
  
 Da mesma forma, o teste nos membros que comparam a `0` também devem ser alterados para comparar os membros a `nullptr`.  Aqui está a sintaxe gerenciado de extensões:  
  
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
  
 Aqui está a análise, substituindo cada instância de `0` com `nullptr`.  A ferramenta de conversão ajuda nessa transformação para automatizar muitos se nem todas as ocorrências, inclusive o uso de macro de `NULL` .  
  
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
  
 `nullptr` é convertido em qualquer tipo de ponteiro ou do identificador de rastreamento mas não promovido a um tipo integral.  Por exemplo, o seguinte conjunto de `nullptr` inicializações, é válido apenas como um valor inicial para os primeiros dois.  
  
```  
// OK: we set obj and pstr to refer to no object  
Object^ obj = nullptr;  
char*   pstr = nullptr; // 0 would also work here  
  
// Error: no conversion of nullptr to 0 …  
int ival = nullptr;  
```  
  
 De maneira semelhante, dado um conjunto de métodos sobrecarregados como o seguinte:  
  
```  
void f( Object^ ); // (1)  
void f( char* );   // (2)  
void f( int );     // (3)  
```  
  
 Uma invocação com literal de `nullptr` , como a seguinte,  
  
```  
// Error: ambiguous: matches (1) and (2)  
f(  nullptr );  
```  
  
 é ambíguo porque `nullptr` corresponde a um identificador de rastreamento e um ponteiro, e não há nenhuma preferência determinada em um tipo em outro. \(Essa situação exija uma conversão explícita para resolver a ambiguidade.\)  
  
 Uma invocação de `0` com correspondem exatamente instâncias \(3\):  
  
```  
// OK: matches (3)  
f( 0 );  
```  
  
 como `0` é do tipo inteiro.  Não foi `f(int)` atual, a chamada corresponderia maneira `f(char*)` com uma conversão padrão.  As regras de correspondência permitem a precedência de uma correspondência exata em uma conversão padrão.  Na ausência de uma correspondência exata, uma conversão padrão terá precedência sobre um com implícita de um tipo de valor.  É por isso não há nenhuma ambiguidade.  
  
## Consulte também  
 [Tipos gerenciados \(C\+\+\/CL\)](../dotnet/managed-types-cpp-cl.md)   
 [Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)   
 [Operador Handle to Object \(^\)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)   
 [nullptr](../windows/nullptr-cpp-component-extensions.md)