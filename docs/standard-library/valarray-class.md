---
title: "Classe valarray | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "valarray"
  - "std.valarray"
  - "std::valarray"
  - "valarray/std::valarray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe valarray"
ms.assetid: 19b862f9-5d09-4003-8844-6ddd02c1a3a7
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe valarray
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que controla uma sequência de elementos do tipo **tipo** que são armazenados como uma matriz, projetado para executar operações matemáticas em alta velocidade e otimizado para desempenho computacional.  
  
## <a name="remarks"></a>Comentários  
 A classe é uma representação do conceito matemático de um conjunto ordenado de valores e os elementos são numerados em sequência de zero. A classe é descrita como um contêiner quase porque ele oferece suporte a alguns, mas não todos, os recursos de primeira classe que os contêineres de sequência, como [vetor](../standard-library/vector-class.md), suporte. Ele difere do vetor de classe de modelo de duas maneiras importantes:  
  
-   Ele define várias operações aritméticas entre elementos correspondentes das **valarray \< tipo>** objetos do mesmo tipo e comprimento, como *xarr* = cos ( *yarr*) + sin ( *zarr*).  
  
-   Ele define uma variedade de maneiras interessantes de subscrito um **valarray \< tipo>** objeto pela sobrecarga [operador &#91; &#93;](#valarray__operator_at).  
  
 Um objeto da classe **tipo**:  
  
-   Tem um construtor padrão público, destruidor, construtor de cópia e o operador de atribuição, com o comportamento convencional.  
  
-   Define os operadores aritméticos e funções matemáticas, conforme necessário, que são definidas para os tipos de ponto flutuantes, com o comportamento convencional.  
  
 Em particular, não há diferenças sutis podem existir entre a construção da cópia e de construção padrão seguido por atribuição. Nenhuma das operações em objetos da classe **tipo** pode lançar exceções.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[valarray](#valarray__valarray)|Constrói um `valarray` de um tamanho específico ou com elementos de um valor específico ou como uma cópia de outro `valarray` ou subconjunto de outro `valarray`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[value_type](#valarray__value_type)|Um tipo que representa o tipo de elemento armazenado em um `valarray`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[Aplicar](#valarray__apply)|Aplica-se a uma função específica para cada elemento de um `valarray`.|  
|[CShift](#valarray__cshift)|Cyclically desloca todos os elementos em um `valarray` por um número especificado de posições.|  
|[livre](#valarray__free)|Libera a memória usada pelo `valarray`.|  
|[Max](#valarray__max)|Localiza o elemento maior em um `valarray`.|  
|[min](#valarray__min)|Localiza o menor elemento em um `valarray`.|  
|[redimensionar](#valarray__resize)|Altera o número de elementos em um `valarray` para um número especificado, adicionando ou removendo elementos conforme necessário.|  
|[SHIFT](#valarray__shift)|Desloca todos os elementos em um `valarray` por um número especificado de posições.|  
|[tamanho](#valarray__size)|Localiza o número de elementos em um `valarray`.|  
|[soma](#valarray__sum)|Determina a soma de todos os elementos em um `valarray` de comprimento diferente de zero.|  
|[troca](#valarray__swap)||  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador!](#valarray__operator_not)|Um operador unário que obtém a lógica `NOT` valores de cada elemento em um `valarray`.|  
|[operador % =](#valarray__operator_mod_eq)|Obtém o resto da divisão dos elementos de uma matriz element-wise por um `valarray` ou por um valor do tipo de elemento.|  
|[operador & =](#valarray__operator_amp__eq)|Obtém o bit a bit `AND` de elementos em uma matriz com os elementos correspondentes no especificada `valarray` ou com um valor do tipo de elemento.|  
|[operador >> =](#valarray__operator_gt__gt__eq)|Direita-desloca os bits para cada elemento de um `valarray` um número especificado de posições ou por um valor em relação ao elemento especificado por um segundo operando `valarray`.|  
|[operador << =](#valarray__operator_lt__lt__eq)|Left-desloca os bits para cada elemento de um `valarray` um número especificado de posições ou por um valor em relação ao elemento especificado por um segundo operando `valarray`.|  
|[operador * =](#valarray__operator_star_eq)|Multiplica os elementos de um `valarray` ou um valor do tipo de elemento, em relação ao elemento, para um operando `valarray`.|  
|[operador +](#valarray__operator_add)|Um operador unário que se aplica a um sinal de mais para cada elemento em um `valarray`.|  
|[operador + =](#valarray__operator_add_eq)|Adiciona os elementos de um `valarray` ou um valor do tipo de elemento, em relação ao elemento, para um operando `valarray`.|  
|[operador-](#valarray__operator-)|Um operador unário que se aplica a um sinal de menos para cada elemento em um `valarray`.|  
|[operador =](#valarray__operator-_eq)|Subtrai os elementos de um `valarray` ou um valor do tipo de elemento, em relação ao elemento, de um operando `valarray`.|  
|[operador / =](#valarray__operator__eq)|Divide um operando `valarray` em relação ao elemento pelos elementos de um `valarray` ou um valor do tipo de elemento.|  
|[operador =](#valarray__operator_eq)|Atribui elementos para um `valarray` cujos valores são especificados diretamente ou como parte de algum outro `valarray` ou por um `slice_array`, `gslice_array`, `mask_array`, ou `indirect_array`.|  
|[operador &#91; &#93;](#valarray__operator_at)|Retorna uma referência a um elemento ou seu valor no índice especificado ou um subconjunto especificado.|  
|[operador ^ =](#valarray__operator_xor_eq)|Obtém o operador or exclusivo em relação ao elemento lógico ( `XOR`) de uma matriz com um valarray especificado ou um valor do tipo de elemento.|  
|[operador &#124; =](#valarray__operator_or_eq)|Obtém o bit a bit `OR` de elementos em uma matriz com os elementos correspondentes no especificada `valarray` ou com um valor do tipo de elemento.|  
|[operador ~](#valarray__operator_dtor)|Um operador unário que obtém o bit a bit `NOT` valores de cada elemento em um `valarray`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< valarray>  
  
 **Namespace:** std  
  
##  <a name="a-namevalarrayapplya-valarrayapply"></a><a name="valarray__apply"></a>  valarray:: Apply  
 Aplica uma função especificada a cada elemento de um valarray.  
  
```  
valarray<Type> apply(Type _Func(Type)) const;

valarray<Type> apply(Type _Func(constType&)) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 *_Func(Type)*  
 O objeto de função a ser aplicada a cada elemento da valarray operando.  
  
 *_Func(Const Type&)*  
 O objeto de função de constante a ser aplicado a cada elemento da valarray operando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos tiveram `_Func` element-wise aplicada aos elementos de valarray o operando.  
  
### <a name="remarks"></a>Comentários  
 A função de membro retorna um objeto da classe [valarray](../standard-library/valarray-class.md)**\< tipo>**, de comprimento [tamanho](#valarray__size), cada um dos cujos elementos `I` é **func**(( **\*isso**) [ `I`]).  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_apply.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
using namespace std;  
  
int __cdecl MyApplyFunc( int n )  
{  
   return n*2;  
}  
  
int main( int argc, char* argv[] )  
{  
   valarray<int> vaR(10), vaApplied(10);  
   int i;  
  
   for ( i = 0; i < 10; i += 3 )  
      vaR[i] = i;  
  
   for ( i = 1; i < 10; i += 3 )  
      vaR[i] = 0;  
  
   for ( i = 2; i < 10; i += 3 )  
      vaR[i] = -i;  
  
   cout << "The initial Right valarray is: (";  
   for   ( i=0; i < 10; ++i )  
      cout << " " << vaR[i];  
   cout << " )" << endl;  
  
   vaApplied = vaR.apply( MyApplyFunc );  
  
   cout << "The element-by-element result of "  
       << "applying MyApplyFunc to vaR is the\nvalarray: ( ";  
   for ( i = 0; i < 10; ++i )  
      cout << " " << vaApplied[i];  
   cout << " )" << endl;  
}  
\* Output:   
The initial Right valarray is: ( 0 0 -2 3 0 -5 6 0 -8 9 )  
The element-by-element result of applying MyApplyFunc to vaR is the  
valarray: (  0 0 -4 6 0 -10 12 0 -16 18 )  
*\  
```  
  
##  <a name="a-namevalarraycshifta-valarraycshift"></a><a name="valarray__cshift"></a>  valarray:: CShift  
 Cyclically desloca todos os elementos em um valarray em um número especificado de posições.  
  
```  
valarray<Type> cshift(int count) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` count`  
 O número de casas os elementos serão deslocadas para frente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um novo valarray em que todos os elementos foram movidos ` count` posições cyclically na frente do valarray, à esquerda em relação a suas posições no valarray operando.  
  
### <a name="remarks"></a>Comentários  
 Um valor positivo de ` count` desloca os elementos cyclically esquerda ` count` coloca.  
  
 Um valor negativo de ` count` desloca os elementos cyclically direito ` count` coloca.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_cshift.cpp  
// compile with: /EHsc  
  
#include <valarray>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    int i;  
  
    valarray<int> va1(10), va2(10);  
    for (i = 0; i < 10; i+=1)  
        va1[i] = i;  
    for (i = 0; i < 10; i+=1)  
        va2[i] = 10 - i;  
  
    cout << "The operand valarray va1 is: (";  
    for (i = 0; i < 10; i++)  
        cout << " " << va1[i];  
    cout << ")" << endl;  
  
    // A positive parameter shifts elements right  
    va1 = va1.cshift(4);  
    cout << "The cyclically shifted valarray va1 is:\nva1.cshift (4) = (";  
    for (i = 0; i < 10; i++)  
        cout << " " << va1[i];  
    cout << ")" << endl;  
  
    cout << "The operand valarray va2 is: (";  
    for (i = 0; i < 10; i++)  
        cout << " " << va2[i];  
    cout << ")" << endl;  
  
    // A negative parameter shifts elements left  
    va2 = va2.cshift(-4);  
    cout << "The cyclically shifted valarray va2 is:\nva2.shift (-4) = (";  
    for (i = 0; i < 10; i++)  
        cout << " " << va2[i];  
    cout << ")" << endl;  
}  
\* Output:   
The operand valarray va1 is: ( 0 1 2 3 4 5 6 7 8 9)  
The cyclically shifted valarray va1 is:  
va1.cshift (4) = ( 4 5 6 7 8 9 0 1 2 3)  
The operand valarray va2 is: ( 10 9 8 7 6 5 4 3 2 1)  
The cyclically shifted valarray va2 is:  
va2.shift (-4) = ( 4 3 2 1 10 9 8 7 6 5)  
*\  
```  
  
##  <a name="a-namevalarrayfreea-valarrayfree"></a><a name="valarray__free"></a>  valarray:: Free  
 Libera a memória usada pelo valarray.  
  
```  
void free();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função não padrão é equivalente ao atribuir um valarray vazio. Por exemplo:  
  
```  
valarray<T> v;  
v = valarray<T>();

// equivalent to v.free()  
```  
  
##  <a name="a-namevalarraymaxa-valarraymax"></a><a name="valarray__max"></a>  valarray:: max  
 Localiza o elemento maior em um valarray.  
  
```  
Type max() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor máximo dos elementos no valarray operando.  
  
### <a name="remarks"></a>Comentários  
 A função de membro compara valores aplicando **operador \<** ou **operador >** entre pares de elementos da classe **tipo**, para os operadores devem ser fornecidas para o elemento **tipo**.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_max.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i, MaxValue;  
  
   valarray<int> vaR ( 10 );  
   for ( i = 0 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 3 )  
      vaR [ i ] =  2*i - 1;  
   for ( i = 2 ; i < 10 ; i += 3 )  
      vaR [ i ] =  10 - i;  
  
   cout << "The operand valarray is: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   MaxValue = vaR.max (  );  
   cout << "The largest element in the valarray is: "  
        << MaxValue  << "." << endl;  
}  
\* Output:   
The operand valarray is: ( 0 1 8 3 7 5 6 13 2 9 ).  
The largest element in the valarray is: 13.  
*\  
```  
  
##  <a name="a-namevalarraymina-valarraymin"></a><a name="valarray__min"></a>  valarray:: min  
 Localiza o menor elemento em um valarray.  
  
```  
Type min() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor mínimo dos elementos no valarray operando.  
  
### <a name="remarks"></a>Comentários  
 A função de membro compara valores aplicando **operador \<** ou **operador >** entre pares de elementos da classe **tipo**, para os operadores devem ser fornecidas para o elemento **tipo**.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_min.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i, MinValue;  
  
   valarray<int> vaR ( 10 );  
   for ( i = 0 ; i < 10 ; i += 3 )  
      vaR [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 3 )  
      vaR [ i ] =  2*i;  
   for ( i = 2 ; i < 10 ; i += 3 )  
      vaR [ i ] =  5 - i;  
  
   cout << "The operand valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   MinValue = vaR.min ( );  
   cout << "The smallest element in the valarray is: "  
        << MinValue  << "." << endl;  
}  
\* Output:   
The operand valarray is: ( 0 2 3 -3 8 0 -6 14 -3 -9 ).  
The smallest element in the valarray is: -9.  
*\  
```  
  
##  <a name="a-namevalarrayoperatornota-valarrayoperator"></a><a name="valarray__operator_not"></a>  valarray:: Operator!  
 Um operador unário que obtém a lógica **NÃO** valores de cada elemento em um valarray.  
  
```  
valarray<bool> operator!() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Valarray de valores booleanos são a negação dos valores de elemento de valarray o operando.  
  
### <a name="remarks"></a>Comentários  
 A operação lógica **NÃO** nega os elementos porque converte todos os zeros para aqueles e considera todos os valores diferentes de zero, como aquelas e converte-os em zeros. O valarray retornado de valores booleanos tem o mesmo tamanho que o operando valarray.  
  
 Também há um bit a bit **NÃO**[valarray:: Operator ~](#valarray__operator_dtor) que nega no nível de bits individuais dentro da representação binária do `char` e `int` elementos de um valarray.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_lognot.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 );  
   valarray<bool> vaNOT ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i-1;  
  
   cout << "The initial valarray is:  ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNOT = !vaL;  
   cout << "The element-by-element result of "  
        << "the logical NOT operator! is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNOT [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is:  ( 0 0 0 2 0 4 0 6 0 8 ).  
The element-by-element result of the logical NOT operator! is the  
 valarray: ( 1 1 1 0 1 0 1 0 1 0 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatormodeqa-valarrayoperator"></a><a name="valarray__operator_mod_eq"></a>  valarray:: Operator % =  
 Obtém o resto da divisão dos elementos de uma matriz element-wise por um valarray especificado ou por um valor do tipo de elemento.  
  
```  
valarray<Type>& operator%=(const valarray<Type>& right);

valarray<Type>& operator%=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento idêntico de valarray o operando a dividir, element-wise, o operando valarray ou valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são o restante da divisão de valarray o operando em relação ao elemento por ` right.`  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_class_op_rem.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 6 ), vaR ( 6 );  
   for ( i = 0 ; i < 6 ; i += 2 )  
      vaL [ i ] =  53;  
   for ( i = 1 ; i < 6 ; i += 2 )  
      vaL [ i ] =  -67;  
   for ( i = 0 ; i < 6 ; i++ )  
      vaR [ i ] =  3*i+1;  
  
   cout << "The initial valarray is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial  right valarray is: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL %= vaR;  
   cout << "The remainders from the element-by-element "  
        << "division is the\n valarray: ( ";  
      for ( i = 0 ; i < 6 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is: ( 53 -67 53 -67 53 -67 ).  
The initial  right valarray is: ( 1 4 7 10 13 16 ).  
The remainders from the element-by-element division is the  
 valarray: ( 0 -3 4 -7 1 -3 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatorampeqa-valarrayoperatoramp"></a><a name="valarray__operator_amp__eq"></a>  valarray:: Operator&amp;=  
 Obtém o bit a bit **AND** de elementos em uma matriz com os elementos correspondentes em um valarray especificado ou com um valor do tipo de elemento.  
  
```  
valarray<Type>& operator&=(const valarray<Type>& right);

valarray<Type>& operator&=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento em relação ao elemento, por lógica, idêntico do valarray operando a ser combinado ou valarray **e** com o valarray do operando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são a em relação ao elemento lógico **e** de valarray o operando por ` right.`  
  
### <a name="remarks"></a>Comentários  
 Uma operação bit a bit só pode ser usada para manipular bits em `char` e `int` tipos de dados e variantes e não no **float**, **double**, **longdouble**, `void`, `bool`, ou outros tipos de dados mais complexos.  
  
 AND bit a bit tenha a mesma tabela de verdade que a lógica **e** mas se aplica ao tipo de dados no nível dos bits individuais. Considerando os bits *b*1 e *b*2, *b*1 **AND** *b*2 é **true** se ambos os bits forem true; **False** se pelo menos um é false.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_class_op_bitand.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i-1;  
   for ( i = 0 ; i < 10 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL &= vaR;  
   cout << "The element-by-element result of "  
        << "the logical AND operator&= is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is:  ( 0 0 0 2 0 4 0 6 0 8 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The element-by-element result of the logical AND operator&= is the  
 valarray: ( 0 0 0 2 0 4 0 6 0 8 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatorgtgteqa-valarrayoperatorgtgt"></a><a name="valarray__operator_gt__gt__eq"></a>  valarray:: Operator&gt;&gt;=  
 Os bits para cada elemento de um operando de valarray um número especificado de posições ou por um valor em relação ao elemento especificado por um segundo valarray de turnos de direito.  
  
```  
valarray<Type>& operator>>=(const valarray<Type>& right);

valarray<Type>& operator>>=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor que indica a quantidade de deslocamento para a direita ou valarray cujos elementos indicam a quantidade em relação ao elemento de deslocamento para a direita.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos foram deslocados direito a quantidade especificada em ` right`.  
  
### <a name="remarks"></a>Comentários  
 Números assinados têm seus sinais preservados.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_class_op_rs.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  64;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -64;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial operand valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The  right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL >>= vaR;  
   cout << "The element-by-element result of "  
        << "the right shift is the\n valarray: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial operand valarray is: ( 64 -64 64 -64 64 -64 64 -64 ).  
The  right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the right shift is the  
 valarray: ( 64 -32 16 -8 4 -2 1 -1 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatorltlteqa-valarrayoperatorltlt"></a><a name="valarray__operator_lt__lt__eq"></a>  valarray:: Operator&lt;&lt;=  
 Left-desloca os bits para cada elemento de um operando de valarray um número especificado de posições ou por um valor em relação ao elemento especificado por um segundo valarray.  
  
```  
valarray<Type>& operator<<=(const valarray<Type>& right);

valarray<Type>& operator<<=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor que indica a quantidade de deslocamento para a esquerda ou valarray cujos elementos indicam a quantidade em relação ao elemento de deslocamento à esquerda.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos mudaram deixado a quantidade especificada em ` right`.  
  
### <a name="remarks"></a>Comentários  
 Números assinados têm seus sinais preservados.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_class_op_ls.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  1;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -1;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial operand valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The  right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL <<= vaR;  
   cout << "The element-by-element result of "  
        << "the left shift\n on the operand array is the valarray:\n ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial operand valarray is: ( 1 -1 1 -1 1 -1 1 -1 ).  
The  right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the left shift  
 on the operand array is the valarray:  
 ( 1 -2 4 -8 16 -32 64 -128 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatorstareqa-valarrayoperator"></a><a name="valarray__operator_star_eq"></a>  valarray:: Operator * =  
 Multiplica os elementos de um valarray especificado ou um valor do tipo de elemento, element-wise, para valarray um operando.  
  
```  
valarray<Type>& operator*=(const valarray<Type>& right);

valarray<Type>& operator*=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento idêntico de valarray o operando a multiplicação, element-wise, o operando valarray ou valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são o produto em relação ao elemento de valarray o operando e ` right.`  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_emult.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  2;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -1;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL *= vaR;  
   cout << "The element-by-element result of "  
        << "the multiplication is the\n valarray: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is: ( 2 -1 2 -1 2 -1 2 -1 ).  
The initial Right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the multiplication is the  
 valarray: ( 0 -1 4 -3 8 -5 12 -7 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatoradda-valarrayoperator"></a><a name="valarray__operator_add"></a>  valarray:: Operator +  
 Um operador unário que se aplica a um sinal de mais para cada elemento em um valarray.  
  
```  
valarray<Type> operator+() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são mais os da matriz operando.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_eplus.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 );  
   valarray<int> vaPLUS ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i-1;  
  
   cout << "The initial valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   vaPLUS = +vaL;  
   cout << "The element-by-element result of "  
        << "the operator+ is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaPLUS [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is:  ( 0 0 -2 2 -4 4 -6 6 -8 8 ).  
The element-by-element result of the operator+ is the  
 valarray: ( 0 0 -2 2 -4 4 -6 6 -8 8 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatoraddeqa-valarrayoperator"></a><a name="valarray__operator_add_eq"></a>  + valarray:: Operator =  
 Adiciona os elementos de um valarray especificado ou um valor do tipo de elemento, element-wise, a valarray um operando.  
  
```  
valarray<Type>& operator+=(const valarray<Type>& right);

valarray<Type>& operator+=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento idêntico de valarray o operando a ser adicionado, element-wise, para o operando valarray ou valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são a soma em relação ao elemento de valarray o operando e ` right.`  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_eadd.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  2;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  -1;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial valarray is: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial  right valarray is: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL += vaR;  
   cout << "The element-by-element result of "  
        << "the sum is the\n valarray: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is: ( 2 -1 2 -1 2 -1 2 -1 ).  
The initial  right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the sum is the  
 valarray: ( 2 0 4 2 6 4 8 6 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperator-a-valarrayoperator-"></a><a name="valarray__operator-"></a>  valarray:: Operator-  
 Um operador unário que se aplica a um sinal de menos para cada elemento em um valarray.  
  
```  
valarray<Type> operator-() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são menos aquelas da matriz operando.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_eminus.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 );  
   valarray<int> vaMINUS ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  -i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  i-1;  
  
   cout << "The initial valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   vaMINUS = -vaL;  
   cout << "The element-by-element result of "  
        << "the operator+ is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaMINUS [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is:  ( 0 0 -2 2 -4 4 -6 6 -8 8 ).  
The element-by-element result of the operator+ is the  
 valarray: ( 0 0 2 -2 4 -4 6 -6 8 -8 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperator-eqa-valarrayoperator-"></a><a name="valarray__operator-_eq"></a>  valarray:: Operator =  
 Subtrai os elementos de um valarray especificado ou um valor do tipo de elemento, element-wise, de valarray um operando.  
  
```  
valarray<Type>& operator-=(const valarray<Type>& right);

valarray<Type>& operator-=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento idêntico de valarray o operando a ser subtraído, element-wise, o operando valarray ou valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são a diferença em relação ao elemento de valarray o operando e ` right.`  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_esub.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 8 ), vaR ( 8 );  
   for ( i = 0 ; i < 8 ; i += 2 )  
      vaL [ i ] =  10;  
   for ( i = 1 ; i < 8 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 0 ; i < 8 ; i++ )  
      vaR [ i ] =  i;  
  
   cout << "The initial valarray is: ( ";  
      for (i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial  right valarray is: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL -= vaR;  
   cout << "The element-by-element result of "  
        << "the difference is the\n valarray: ( ";  
      for ( i = 0 ; i < 8 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is: ( 10 0 10 0 10 0 10 0 ).  
The initial  right valarray is: ( 0 1 2 3 4 5 6 7 ).  
The element-by-element result of the difference is the  
 valarray: ( 10 -1 8 -3 6 -5 4 -7 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatoreqa-valarrayoperator"></a><a name="valarray__operator__eq"></a>  valarray:: Operator / =  
 Divide um operando valarray element-wise os elementos de um valarray especificado ou um valor do tipo de elemento.  
  
```  
valarray<Type>& operator/=(const valarray<Type>& right);

valarray<Type>& operator/=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento idêntico de valarray o operando a ser dividida, element-wise, o operando valarray ou valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são o quociente em relação ao elemento de valarray o operando é dividido por ` right.`  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_ediv.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<double> vaL ( 6 ), vaR ( 6 );  
   for ( i = 0 ; i < 6 ; i += 2 )  
      vaL [ i ] =  100;  
   for ( i = 1 ; i < 6 ; i += 2 )  
      vaL [ i ] =  -100;  
   for ( i = 0 ; i < 6 ; i++ )  
      vaR [ i ] =  2*i;  
  
   cout << "The initial valarray is: ( ";  
      for (i = 0 ; i < 6 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The initial Right valarray is: ( ";  
      for (i = 0 ; i < 6 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL /= vaR;  
   cout << "The element-by-element result of "  
        << "the quotient is the\n valarray: ( ";  
      for (i = 0 ; i < 6 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray is: ( 100 -100 100 -100 100 -100 ).  
The initial Right valarray is: ( 0 2 4 6 8 10 ).  
The element-by-element result of the quotient is the  
 valarray: ( 1.#INF -50 25 -16.6667 12.5 -10 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatoreqa-valarrayoperator"></a><a name="valarray__operator_eq"></a>  valarray:: Operator =  
 Atribui os elementos a uma valarray cujos valores são especificados diretamente ou como parte de alguns outro valarray ou por um slice_array, gslice_array, mask_array ou indirect_array.  
  
```  
valarray<Type>& operator=(const valarray<Type>& right);

valarray<Type>& operator=(valarray<Type>&& right);

valarray<Type>& operator=(const Type& val);

valarray<Type>& operator=(const slice_array<Type>& _Slicearray);

valarray<Type>& operator=(const gslice_array<Type>& _Gslicearray);

valarray<Type>& operator=(const mask_array<Type>& _Maskarray);

valarray<Type>& operator=(const indirect_array<Type>& _Indarray);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Valarray sejam copiados para o valarray operando.  
  
 ` val`  
 O valor a ser atribuído aos elementos de valarray o operando.  
  
 `_Slicearray`  
 Slice_array sejam copiados para o valarray operando.  
  
 `_Gslicearray`  
 Gslice_array sejam copiados para o valarray operando.  
  
 `_Maskarray`  
 Mask_array sejam copiados para o valarray operando.  
  
 `_Indarray`  
 Indirect_array sejam copiados para o valarray operando.  
  
### <a name="return-value"></a>Valor de retorno  
 Primeiro operador membro substitui a sequência controlada por uma cópia da sequência controlada por ` right`.  
  
 O segundo operador de membro é o mesmo que a primeiro, mas com um [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
 O terceiro operador de membro substitui cada elemento da sequência controlada por uma cópia de ` val`.  
  
 Operadores de membro restantes substitua os elementos da sequência controlada selecionado por seus argumentos, que são gerados somente por [operador &#91; &#93;](#valarray__operator_at).  
  
 Se o valor de um membro na sequência controlada de substituição depende de um membro na sequência controlada inicial, o resultado será indefinido.  
  
### <a name="remarks"></a>Comentários  
 Se o comprimento da sequência controlada for alterado, o resultado é geralmente indefinido. Nessa implementação, no entanto, o efeito é simplesmente invalidar qualquer ponteiros ou referências a elementos na sequência controlada.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_assign.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> va ( 10 ), vaR ( 10 );  
   for ( i = 0 ; i < 10 ; i += 1 )  
      va [ i ] = i;  
   for ( i = 0 ; i < 10 ; i+=1 )  
      vaR [ i ] = 10 -  i;  
  
   cout << "The operand valarray va is:";  
   for ( i = 0 ; i < 10 ; i++ )  
      cout << " " << va [ i ];  
   cout << endl;  
  
   cout << "The operand valarray vaR is:";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << " " << vaR [ i ];  
   cout << endl;  
  
   // Assigning vaR to va with the first member functon  
   va = vaR;  
   cout << "The reassigned valarray va is:";  
   for ( i = 0 ; i < 10 ; i++ )  
      cout << " " << va [ i ];  
   cout << endl;  
  
   // Assigning elements of value 10 to va  
   // with the second member functon  
   va = 10;  
   cout << "The reassigned valarray va is:";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << " " << va [ i ];  
   cout << endl;  
}  
\* Output:   
The operand valarray va is: 0 1 2 3 4 5 6 7 8 9  
The operand valarray vaR is: 10 9 8 7 6 5 4 3 2 1  
The reassigned valarray va is: 10 9 8 7 6 5 4 3 2 1  
The reassigned valarray va is: 10 10 10 10 10 10 10 10 10 10  
*\  
```  
  
##  <a name="a-namevalarrayoperatorata-valarrayoperator"></a><a name="valarray__operator_at"></a>  [] valarray:: Operator  
 Retorna uma referência a um elemento ou seu valor no índice especificado ou um subconjunto especificado.  
  
```  
Type& operator[](size_t _Off);

slice_array<Type> operator[](slice _Slicearray);

gslice_array<Type> operator[](const gslice& _Gslicearray);

mask_array<Type> operator[](const valarray<bool>& _Boolarray);

indirect_array<Type> operator[](const valarray<size_t>& _Indarray);

Type operator[](size_t _Off) const;

 
valarray<Type> operator[](slice _Slice) const;

 
valarray<Type> operator[](const gslice& _Gslicearray) const;

 
valarray<Type> operator[](const valarray<bool>& _Boolarray) const;

 
valarray<Type> operator[](const valarray<size_t>& _Indarray) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 O índice do elemento a ser atribuído um valor.  
  
 `_Slicearray`  
 Um slice_array de um valarray que especifica um subconjunto a ser selecionado ou retornado para um novo valarray.  
  
 `_Gslicearray`  
 Um gslice_array de um valarray que especifica um subconjunto a ser selecionado ou retornado para um novo valarray.  
  
 *_Boolarray*  
 Um bool_array de um valarray que especifica um subconjunto a ser selecionado ou retornado para um novo valarray.  
  
 `_Indarray`  
 Um indirect_array de um valarray que especifica um subconjunto a ser selecionado ou retornado para um novo valarray.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um elemento ou seu valor no índice especificado ou um subconjunto especificado.  
  
### <a name="remarks"></a>Comentários  
 O operador de membro está sobrecarregado para fornecer várias maneiras de selecionar sequências de elementos entre aquelas controlados por *\****isso**. O primeiro grupo de operadores de membro cinco funcionam em conjunto com várias sobrecargas de [operador =](#valarray__operator_eq) (e outros operadores de atribuição) para permitir a substituição seletiva (divisão) da sequência controlada. Os elementos selecionados devem existir.  
  
 Ao compilar com secure_scl 1, um erro de tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites do valarray.  Consulte [iteradores](../standard-library/checked-iterators.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  Consulte os exemplos de [Slice:: Slice](../Topic/slice%20Class.md#slice__slice) e [gslice:: gslice](../Topic/gslice%20Class.md#gslice__gslice) para obter um exemplo de como declarar e usar o operador.  
  
##  <a name="a-namevalarrayoperatorxoreqa-valarrayoperator"></a><a name="valarray__operator_xor_eq"></a>  valarray:: Operator ^ =  
 Obtém o operador or exclusivo em relação ao elemento lógico ( **XOR**) de uma matriz com um valarray especificado ou um valor do tipo de elemento.  
  
```  
valarray<Type>& operator|=(const valarray<Type>& right);

valarray<Type>& operator|=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento idêntico de valarray o operando a ser combinado, em relação ao elemento, por lógica exclusiva ou valarray **XOR** com valarray o operando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são lógica exclusiva em relação ao elemento, **XOR** de valarray o operando e ` right.`  
  
### <a name="remarks"></a>Comentários  
 O exclusivo lógico ou referido como **XOR**, tem a seguinte semântica: determinados elementos *e*1 e *e*2, *e*1 **XOR** *e*2 é **true** se exatamente um dos elementos é true; **False** se ambos os elementos são falsos ou se ambos os elementos forem verdadeiras.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_exor.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  1;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 0 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
   for ( i = 2 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
  
   cout << "The initial operand valarray is:  ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The  right valarray is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL ^= vaR;  
   cout << "The element-by-element result of "  
        << "the bitwise XOR operator^= is the\n valarray: ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial operand valarray is:  ( 1 0 1 0 1 0 1 0 1 0 ).  
The  right valarray is: ( 0 0 1 3 3 4 6 6 7 9 ).  
The element-by-element result of the bitwise XOR operator^= is the  
 valarray: ( 1 0 0 3 2 4 7 6 6 9 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatororeqa-valarrayoperator124"></a><a name="valarray__operator_or_eq"></a>  valarray:: Operator &#124; =  
 Obtém o bit a bit `OR` de elementos em uma matriz com os elementos correspondentes em um valarray especificado ou com um valor do tipo de elemento.  
  
```  
valarray<Type>& operator|=(const valarray<Type>& right);

valarray<Type>& operator|=(const Type& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 O valor de um tipo de elemento idêntico de valarray o operando a ser combinado, em relação ao elemento, por bit a bit ou valarray `OR` com valarray o operando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valarray cujos elementos são a em relação ao elemento bit a bit `OR` de valarray o operando por ` right.`  
  
### <a name="remarks"></a>Comentários  
 Uma operação bit a bit só pode ser usada para manipular bits em `char` e `int` tipos de dados e variantes e não no **float**, **double**, **longdouble**, `void`, `bool`, ou outros tipos de dados mais complexos.  
  
 Bit a bit `OR` tem a mesma tabela de verdade lógica `OR` mas se aplica ao tipo de dados no nível dos bits individuais. Considerando os bits *b*1 e *b*2, *b*1 `OR` *b*2 é **true** se pelo menos um dos bits é true; **False** se ambos os bits forem falsos.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_class_op_bitor.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> vaL ( 10 ), vaR ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL [ i ] =  1;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL [ i ] =  0;  
   for ( i = 0 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
   for ( i = 2 ; i < 10 ; i += 3 )  
      vaR [ i ] =  i-1;  
  
   cout << "The initial operand valarray is:\n ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The  right valarray is:\n ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaR [ i ] << " ";  
   cout << ")." << endl;  
  
   vaL |= vaR;  
   cout << "The element-by-element result of "  
        << "the logical OR\n operator|= is the valarray:\n ( ";  
      for (i = 0 ; i < 10 ; i++ )  
         cout << vaL [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial operand valarray is:  
 ( 1 0 1 0 1 0 1 0 1 0 ).  
The  right valarray is:  
 ( 0 0 1 3 3 4 6 6 7 9 ).  
The element-by-element result of the logical OR  
 operator|= is the valarray:  
 ( 1 0 1 3 3 4 7 6 7 9 ).  
*\  
```  
  
##  <a name="a-namevalarrayoperatordtora-valarrayoperator"></a><a name="valarray__operator_dtor"></a>  valarray:: Operator ~  
 Um operador unário que obtém o bit a bit **NÃO** valores de cada elemento em um valarray.  
  
```  
valarray<Type> operator~() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Valarray de valores booleanos são bit a bit **NÃO** dos valores de elemento de valarray o operando.  
  
### <a name="remarks"></a>Comentários  
 Uma operação bit a bit só pode ser usada para manipular bits em `char` e `int` tipos de dados e variantes e não no **float**, **double**, **longdouble**, `void`, `bool` ou outros tipos de dados mais complexos.  
  
 Bit a bit **NÃO** tem a mesma tabela de verdade lógica **NÃO** mas se aplica ao tipo de dados no nível dos bits individuais. Dado bit *b*, ~ *b* é verdadeiro se *b* é false e FALSO se *b* for true. A lógica **NÃO**[operador!](#valarray__operator_not) aplica-se em um nível de elemento, a contagem de todos os valores diferentes de zero como **true**, e o resultado é um valarray de valores booleanos. Bit a bit **NOToperator ~**, por outro lado, pode resultar em um valarray de valores diferente de 0 ou 1, dependendo do resultado da operação bit a bit.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_op_bitnot.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<unsigned short int> vaL1 ( 10 );  
   valarray<unsigned short int> vaNOT1 ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL1 [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL1 [ i ] =  5*i;  
  
   cout << "The initial valarray <unsigned short int> is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL1 [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNOT1 = ~vaL1;  
   cout << "The element-by-element result of "  
        << "the bitwise NOT operator~ is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNOT1 [ i ] << " ";  
   cout << ")." << endl << endl;  
  
   valarray<int> vaL2 ( 10 );  
   valarray<int> vaNOT2 ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      vaL2 [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      vaL2 [ i ] =  -2 * i;  
  
   cout << "The initial valarray <int> is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaL2 [ i ] << " ";  
   cout << ")." << endl;  
  
   vaNOT2 = ~vaL2;  
   cout << "The element-by-element result of "  
        << "the bitwise NOT operator~ is the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNOT2 [ i ] << " ";  
   cout << ")." << endl;  
  
   // The negative numbers are represented using  
   // the two's complement approach, so adding one  
   // to the flipped bits returns the negative elements  
   vaNOT2 = vaNOT2 + 1;  
   cout << "The element-by-element result of "  
        << "adding one\n is the negative of the "  
        << "original elements the\n valarray: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << vaNOT2 [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial valarray <unsigned short int> is:  ( 0 5 2 15 4 25 6 35 8 45 ).  
The element-by-element result of the bitwise NOT operator~ is the  
 valarray: ( 65535 65530 65533 65520 65531 65510 65529 65500 65527 65490 ).  
  
The initial valarray <int> is:  ( 0 -2 2 -6 4 -10 6 -14 8 -18 ).  
The element-by-element result of the bitwise NOT operator~ is the  
 valarray: ( -1 1 -3 5 -5 9 -7 13 -9 17 ).  
The element-by-element result of adding one  
 is the negative of the original elements the  
 valarray: ( 0 2 -2 6 -4 10 -6 14 -8 18 ).  
*\  
```  
  
##  <a name="a-namevalarrayresizea-valarrayresize"></a><a name="valarray__resize"></a>  valarray:: Resize  
 Altera o número de elementos em um valarray para um número especificado.  
  
```  
void resize(
    size_t _Newsize);

void resize(
    size_t _Newsize,   
    const Type val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Newsize`  
 O número de elementos de valarray redimensionado.  
  
 ` val`  
 O valor a ser dado aos elementos de valarray o redimensionado.  
  
### <a name="remarks"></a>Comentários  
 A primeira função de membro inicializa elementos com o construtor padrão.  
  
 Qualquer ponteiros ou referências a elementos na sequência controlada são invalidadas.  
  
### <a name="example"></a>Exemplo  
  O exemplo a seguir demonstra o uso da função de membro valarray:: Resize.  
  
```  
// valarray_resize.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    int i;  
    size_t size1, sizeNew;  
  
    valarray<int> va1(10);  
    for (i = 0; i < 10; i+=1)  
        va1[i] = i;  
  
    cout << "The valarray contains ( ";  
        for (i = 0; i < 10; i++)  
            cout << va1[i] << " ";  
    cout << ")." << endl;  
  
    size1 = va1.size();  
    cout << "The number of elements in the valarray is: "  
         << size1  << "." <<endl << endl;  
  
    va1.resize(15, 10);  
  
    cout << "The valarray contains ( ";  
        for (i = 0; i < 15; i++)  
            cout << va1[i] << " ";  
    cout << ")." << endl;  
    sizeNew = va1.size();  
    cout << "The number of elements in the resized valarray is: "  
         << sizeNew  << "." <<endl << endl;  
}  
\* Output:   
The valarray contains ( 0 1 2 3 4 5 6 7 8 9 ).  
The number of elements in the valarray is: 10.  
  
The valarray contains ( 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 ).  
The number of elements in the resized valarray is: 15.  
*\  
```  
  
##  <a name="a-namevalarrayshifta-valarrayshift"></a><a name="valarray__shift"></a>  valarray:: SHIFT  
 Desloca todos os elementos em um valarray em um número especificado de casas.  
  
```  
valarray<Type> shift(int count) const;
```  
  
### <a name="parameters"></a>Parâmetros  
 ` count`  
 O número de casas os elementos serão deslocadas para frente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um novo valarray em que todos os elementos foram movidos ` count` posições na frente do valarray, à esquerda em relação a suas posições no valarray operando.  
  
### <a name="remarks"></a>Comentários  
 Um valor positivo de ` count` desloca os elementos à esquerda ` count` coloca com preenchimento de zero.  
  
 Um valor negativo de ` count` desloca o direito de elementos ` count` coloca com preenchimento de zero.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_shift.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
  
   valarray<int> va1 ( 10 ), va2 ( 10 );  
   for ( i = 0 ; i < 10 ; i += 1 )  
      va1 [ i ] =  i;  
   for ( i = 0 ; i < 10 ; i += 1 )  
      va2 [ i ] = 10 -  i;  
  
   cout << "The operand valarray va1(10) is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va1 [ i ] << " ";  
   cout << ")." << endl;  
  
   // A positive parameter shifts elements left  
   va1 = va1.shift ( 4 );  
   cout << "The shifted valarray va1 is: va1.shift (4) = ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va1 [ i ] << " ";  
   cout << ")." << endl;  
  
   cout << "The operand valarray va2(10) is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va2 [ i ] << " ";  
   cout << ")." << endl;  
  
   // A negative parameter shifts elements right  
   va2 = va2.shift ( - 4 );  
   cout << "The shifted valarray va2 is: va2.shift (-4) = ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va2 [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The operand valarray va1(10) is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The shifted valarray va1 is: va1.shift (4) = ( 4 5 6 7 8 9 0 0 0 0 ).  
The operand valarray va2(10) is: ( 10 9 8 7 6 5 4 3 2 1 ).  
The shifted valarray va2 is: va2.shift (-4) = ( 0 0 0 0 10 9 8 7 6 5 ).  
*\  
```  
  
##  <a name="a-namevalarraysizea-valarraysize"></a><a name="valarray__size"></a>  valarray:: Size  
 Localiza o número de elementos em um valarray.  
  
```  
size_t size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos no valarray operando.  
  
### <a name="example"></a>Exemplo  
  O exemplo a seguir demonstra o uso da função de membro valarray:: Size.  
  
```  
// valarray_size.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    int i;  
    size_t size1, size2;  
  
    valarray<int> va1(10), va2(12);  
    for (i = 0; i < 10; i += 1)  
        va1[i] =  i;  
    for (i = 0; i < 10; i += 1)  
        va2[i] =  i;  
  
    cout << "The operand valarray va1(10) is: ( ";  
        for (i = 0; i < 10; i++)  
            cout << va1[i] << " ";  
    cout << ")." << endl;  
  
    size1 = va1.size();  
    cout << "The number of elements in the valarray va1 is: va1.size = "  
         << size1  << "." <<endl << endl;  
  
    cout << "The operand valarray va2(12) is: ( ";  
        for (i = 0; i < 10; i++)  
            cout << va2[i] << " ";  
    cout << ")." << endl;  
  
    size2 = va2.size();  
    cout << "The number of elements in the valarray va2 is: va2.size = "  
         << size2  << "." << endl << endl;  
  
    // Initializing two more elements to va2  
    va2[10] = 10;  
    va2[11] = 11;  
    cout << "After initializing two more elements,\n "  
         << "the operand valarray va2(12) is now: ( ";  
        for (i = 0; i < 12; i++)  
            cout << va2[i] << " ";  
    cout << ")." << endl;  
    cout << "The number of elements in the valarray va2 is still: "  
         << size2  << "." << endl;  
}  
\* Output:   
The operand valarray va1(10) is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The number of elements in the valarray va1 is: va1.size = 10.  
  
The operand valarray va2(12) is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The number of elements in the valarray va2 is: va2.size = 12.  
  
After initializing two more elements,  
 the operand valarray va2(12) is now: ( 0 1 2 3 4 5 6 7 8 9 10 11 ).  
The number of elements in the valarray va2 is still: 12.  
*\  
```  
  
##  <a name="a-namevalarraysuma-valarraysum"></a><a name="valarray__sum"></a>  valarray:: Sum  
 Determina a soma de todos os elementos em um valarray de comprimento diferente de zero.  
  
```  
Type sum() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A soma dos elementos de valarray o operando.  
  
### <a name="remarks"></a>Comentários  
 Se o comprimento for maior do que um, a função de membro adiciona valores a soma aplicando `operator+=` entre pares de elementos da classe **tipo**, consequentemente, o operador que precisa ser fornecido para elementos do tipo **tipo**.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_sum.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
   int sumva = 0;  
  
   valarray<int> va ( 10 );  
   for ( i = 0 ; i < 10 ; i+=1 )  
      va [ i ] =  i;  
  
   cout << "The operand valarray va (10) is: ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va [ i ] << " ";  
   cout << ")." << endl;  
  
   sumva = va.sum ( );  
   cout << "The sum of elements in the valarray is: "  
        << sumva  << "." <<endl;  
}  
\* Output:   
The operand valarray va (10) is: ( 0 1 2 3 4 5 6 7 8 9 ).  
The sum of elements in the valarray is: 45.  
*\  
```  
  
##  <a name="a-namevalarrayswapa-valarrayswap"></a><a name="valarray__swap"></a>  valarray:: swap  
 Troca os elementos de dois `valarray`s.  
  
```  
void swap(valarray& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|` right`|Um `valarray` fornecendo os elementos a ser trocado.|  
  
### <a name="remarks"></a>Comentários  
 A função de membro troca as sequências controladas entre `*this` e ` right`. Ele faz isso em tempo constante, ele não lança exceções e invalida sem referências, ponteiros ou iteradores que designam elementos as duas sequências controlados.  
  
##  <a name="a-namevalarrayvalarraya-valarrayvalarray"></a><a name="valarray__valarray"></a>  valarray:: valarray  
 Constrói um valarray de um tamanho específico ou com elementos de um valor específico ou como uma cópia de outro valarray ou subconjunto de outro valarray.  
  
```  
valarray();

explicit valarray(
    size_t Count);

valarray(
    const Type& Val,   
    size_t Count);

valarray(
    const Type* Ptr,   
    size_t Count);

valarray(
    const valarray<Type>& Right);

valarray(
    const slice_array<Type>& SliceArray);

valarray(
    const gslice_array<Type>& GsliceArray);

valarray(
    const mask_array<Type>& MaskArray);

valarray(
    const indirect_array<Type>& IndArray);

valarray(
    valarray<Type>&& Right);

valarray(
    initializer_list<Type> IList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Count`  
 O número de elementos no valarray.  
  
 `Val`  
 O valor a ser usado ao inicializar os elementos de valarray.  
  
 `Ptr`  
 Ponteiro para os valores a serem usados para inicializar os elementos de valarray.  
  
 `Right`  
 Um valarray existente para inicializar o novo valarray.  
  
 `SliceArray`  
 Um slice_array cujos valores de elemento devem ser usadas ao inicializar os elementos de valarray sendo construído.  
  
 `GsliceArray`  
 Um gslice_array cujos valores de elemento devem ser usadas ao inicializar os elementos de valarray sendo construído.  
  
 `MaskArray`  
 Um mask_array cujos valores de elemento devem ser usadas ao inicializar os elementos de valarray sendo construído.  
  
 `IndArray`  
 Um indirect_array cujos valores de elemento devem ser usadas ao inicializar os elementos de valarray sendo construído.  
  
 `IList`  
 O initializer_list que contém os elementos a serem copiados.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor (padrão) inicializa o objeto para uma matriz vazia. Os próximos três construtores cada inicializam o objeto para uma matriz de `Count` elementos da seguinte maneira:  
  
-   Para explícita `valarray(size_t Count)`, cada elemento é inicializado com o construtor padrão.  
  
-   Para `valarray(const Type& Val, Count)`, cada elemento é inicializado com `Val`.  
  
-   Para `valarray(const Type* Ptr, Count)`, o elemento na posição `I` é inicializada com `Ptr`[ `I`].  
  
 Cada construtor restante inicializa o objeto para um valarray \< tipo> objeto determinado pelo subconjunto especificado no argumento.  
  
 O último construtor é o mesmo que o próximo ou por último, mas com um [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_ctor.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    int i;  
  
    // The second member function  
    valarray<int> va(10);  
    for (auto i : va){  
        va[i] = 2 * (i + 1);  
    }  
  
    cout << "The operand valarray va is:\n(";  
    for (auto i : va) {  
        cout << " " << va[i];  
    }  
    cout << " )" << endl;  
  
    slice Slice(2, 4, 3);  
  
    // The fifth member function  
    valarray<int> vaSlice = va[Slice];  
  
    cout << "The new valarray initialized from the slice is vaSlice ="  
        << "\nva[slice( 2, 4, 3)] = (";  
    for (int i = 0; i < 3; i++) {  
        cout << " " << vaSlice[i];  
    }  
    cout << " )" << endl;  
  
    valarray<int> va2{{ 1, 2, 3, 4 }};  
    for (auto& v : va2){  
        cout << v << " ";  
    }  
    cout << endl;  
}  
  
```  
  
```Output  
The operand valarray va is:( 0 2 2 2 2 2 2 2 2 2 )The new valarray initialized from the slice is vaSlice =va[slice( 2, 4, 3)] = ( 0 0 0 )1 2 3 4  
```  
  
##  <a name="a-namevalarrayvaluetypea-valarrayvaluetype"></a><a name="valarray__value_type"></a>  valarray:: value_type  
 Um tipo que representa o tipo de elemento armazenado em um valarray.  
  
```  
typedef Type value_type;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para o parâmetro de modelo **tipo**.  
  
### <a name="example"></a>Exemplo  
  
```  
// valarray_value_type.cpp  
// compile with: /EHsc  
#include <valarray>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   int i;  
   valarray<int> va ( 10 );  
   for ( i = 0 ; i < 10 ; i += 2 )  
      va [ i ] =  i;  
   for ( i = 1 ; i < 10 ; i += 2 )  
      va [ i ] =  -1;  
  
   cout << "The initial operand valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va [ i ] << " ";  
   cout << ")." << endl;  
  
   // value_type declaration and initialization:  
   valarray<int>::value_type Right = 10;  
  
   cout << "The decalared value_type Right is: "   
           << Right << endl;  
   va *= Right;  
   cout << "The resulting valarray is:  ( ";  
      for ( i = 0 ; i < 10 ; i++ )  
         cout << va [ i ] << " ";  
   cout << ")." << endl;  
}  
\* Output:   
The initial operand valarray is:  ( 0 -1 2 -1 4 -1 6 -1 8 -1 ).  
The decalared value_type Right is: 10  
The resulting valarray is:  ( 0 -10 20 -10 40 -10 60 -10 80 -10 ).  
*\  
```  
  
## <a name="see-also"></a>Consulte também  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

