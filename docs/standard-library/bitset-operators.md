---
title: Operadores &lt;bitset&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 84fe6a13-6f6e-4cdc-bf8f-6f65ab1134d4
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 2a1f1c21cdcd42e7e8d33eb6405297fc88635d87
ms.lasthandoff: 02/25/2017

---
# <a name="ltbitsetgt-operators"></a>Operadores &lt;bitset&gt;
||||  
|-|-|-|  
|[operator&amp;](#operator_amp_)|[operator&gt;&gt;](#operator_gt__gt_)|[operator&lt;&lt;](#operator_lt__lt_)|  
|[operator_xor](#operator_xor)|[operator_or](#operator_or)|  
  
##  <a name="a-nameoperatorampa--operatoramp"></a><a name="operator_amp_"></a>  operator&amp;  
 Executa um `AND` bit a bit entre dois bitsets.  
  
```  
template <size_t size>  
bitset<size>  
operator&(
    const bitset<size>& left,  
    const bitset<size>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 O primeiro dos dois bitsets cujos respectivos elementos devem ser combinados com o `AND` bit a bit.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos devem ser combinados com o `AND` bit a bit.  
  
### <a name="return-value"></a>Valor retornado  
 Um bitset cujos elementos são o resultado da execução da operação `AND` nos elementos correspondentes de ` left` e ` right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// bitset_and.cpp  
// compile with: /EHsc  
#include <bitset>  
#include <iostream>  
#include <string>  
  
using namespace std;  
  
int main()  
{  
   bitset<4> b1 ( string("0101") );  
   bitset<4> b2 ( string("0011") );  
   bitset<4> b3 = b1 & b2;  
   cout << "bitset 1: " << b1 << endl;  
   cout << "bitset 2: " << b2 << endl;  
   cout << "bitset 3: " << b3 << endl;  
}  
```  
  
```Output  
bitset 1: 0101  
bitset 2: 0011  
bitset 3: 0001  
```  
  
##  <a name="a-nameoperatorltlta--operatorltlt"></a><a name="operator_lt__lt_"></a>  operator&lt;&lt;  
 Insere uma representação de texto da sequência de bits no fluxo de saída.  
  
```  
 
template <class CharType, class Traits, size_t N>  
basic_ostream<CharType, Traits>& operator<<(
    basic_ostream<CharType, Traits>& ostr,  
    const bitset<N>& 
    right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Um objeto do tipo **bitset\<N>** que deve ser inserido no fluxo de saída como uma cadeia de caracteres.  
  
### <a name="return-value"></a>Valor retornado  
 Uma representação de texto da sequência de bits em **ostr**.  
  
### <a name="remarks"></a>Comentários  
 As função de modelo sobrecarrega **operator<<**, permitindo que um bitset seja gravado primeiro ser convertido em uma cadeia de caracteres. A função de modelo é executada efetivamente:  
  
 **ostr** << _ *Right*. [to_string](https://msdn.microsoft.com/library/2f93c55z.aspx) < **CharType**, **Traits**, **allocator**\< **CharType**> > ( )  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// bitset_op_insert.cpp  
// compile with: /EHsc  
#include <bitset>  
#include <iostream>  
#include <string>  
  
int main( )  
{  
   using namespace std;  
  
   bitset<5> b1 ( 9 );  
  
   // bitset inserted into output stream directly  
   cout << "The ordered set of bits in the bitset<5> b1(9)"  
        << "\n can be output with the overloaded << as: ( "  
        << b1 << " )" << endl;  
  
   // Compare converting bitset to a string before  
   // inserting it into the output steam  
   string s1;  
   s1 =  b1.template to_string<char,   
      char_traits<char>, allocator<char> >( );  
   cout << "The string returned from the bitset b1"  
        << "\n by the member function to_string( ) is: "  
        << s1 << "." << endl;  
}  
```  
  
##  <a name="a-nameoperatorgtgta--operatorgtgt"></a><a name="operator_gt__gt_"></a>  operator&gt;&gt;  
 Lê uma cadeia de caracteres de bit em um bitset.  
  
```  
 
template <class CharType, class Traits, size_t Bits>  
basic_istream<CharType, Traits>& operator>> (
    basic_istream<CharType, Traits>& 
_Istr,  
    bitset<N>& 
    right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Istr`  
 A cadeia de caracteres que é inserida no fluxo de entrada a ser inserido no bitset.  
  
 ` right`  
 O bitset que está recebendo os bits do fluxo de entrada.  
  
### <a name="return-value"></a>Valor retornado  
 A função de modelo retorna a cadeia de caracteres `_Istr`.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo sobrecarrega **operator>>** para armazenar no bitset_ *Right* o valor bitset( `str`), em que `str` é um objeto do tipo [basic_string](https://msdn.microsoft.com/library/syxtdd4f.aspx) < **CharType**, **Traits**, **allocator** \< **CharType**> > **& ** extraídos de `_Istr`.  
  
 A função de modelo extrai elementos de `_Istr` e insere-os em um bitset até:  
  
-   Todos os elementos do bit terem sido extraídos do fluxo de entrada e armazenados no bitset.  
  
-   O bitset ser preenchido com bits do fluxo de entrada.  
  
-   Ser localizado um elemento de entrada que não seja 0 nem 1.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
#include <bitset>  
#include <iostream>  
#include <string>  
  
using namespace std;  
int main()  
{  
  
   bitset<5> b1;  
   cout << "Enter string of (0 or 1) bits for input into bitset<5>.\n"  
        << "Try bit string of length less than or equal to 5,\n"  
        << " (for example: 10110): ";  
   cin >>  b1;  
  
   cout << "The ordered set of bits entered from the "  
        << "keyboard\n has been input into bitset<5> b1 as: ( "  
        << b1 << " )" << endl;  
  
   // Truncation due to longer string of bits than length of bitset  
   bitset<2> b3;  
   cout << "Enter string of bits (0 or 1) for input into bitset<2>.\n"  
        << " Try bit string of length greater than 2,\n"  
        << " (for example: 1011): ";  
   cin >>  b3;  
  
   cout << "The ordered set of bits entered from the "  
        << "keyboard\n has been input into bitset<2> b3 as: ( "  
        << b3 << " )" << endl;  
  
   // Flushing the input stream  
   char buf[100];  
   cin.getline(&buf[0], 99);  
  
   // Truncation with non-bit value  
   bitset<5> b2;  
   cout << "Enter a string for input into  bitset<5>.\n"  
        << " that contains a character than is NOT a 0 or a 1,\n "  
        << " (for example: 10k01): ";  
   cin >>  b2;  
  
   cout << "The string entered from the keyboard\n"  
        << " has been input into bitset<5> b2 as: ( "  
        << b2 << " )" << endl;  
}  
```  
  
##  <a name="a-nameoperatorxora--operatorxor"></a><a name="operator_xor"></a>  operator_xor  
 Executa um `EXCLUSIVE-OR` bit a bit entre dois bitsets.  
  
```  
template <size_t size>  
bitset<size>  
operator^(
    const bitset<size>& left,  
    const bitset<size>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 O primeiro dos dois bitsets cujos respectivos elementos devem ser combinados com o `EXCLUSIVE-OR` bit a bit.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos devem ser combinados com o `EXCLUSIVE-OR` bit a bit.  
  
### <a name="return-value"></a>Valor retornado  
 Um bitset cujos elementos são o resultado da execução da operação `EXCLUSIVE-OR` nos elementos correspondentes de ` left` e ` right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// bitset_xor.cpp  
// compile with: /EHsc  
#include <bitset>  
#include <iostream>  
#include <string>  
  
using namespace std;  
  
int main()  
{  
   bitset<4> b1 ( string("0101") );  
   bitset<4> b2 ( string("0011") );  
   bitset<4> b3 = b1 ^ b2;  
   cout << "bitset 1: " << b1 << endl;  
   cout << "bitset 2: " << b2 << endl;  
   cout << "bitset 3: " << b3 << endl;  
}  
```  
  
```Output  
bitset 1: 0101  
bitset 2: 0011  
bitset 3: 0110  
```  
  
##  <a name="a-nameoperatorora--operatoror"></a><a name="operator_or"></a>  operator_or  
 Executa um `OR` bit a bit entre dois bitsets.  
  
```  
template <size_t size>  
bitset<size>  
operator|(
    const bitset<size>& left,  
    const bitset<size>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 O primeiro dos dois bitsets cujos respectivos elementos devem ser combinados com o `OR` bit a bit.  
  
 ` right`  
 A segunda das duas valarrays cujos respectivos elementos devem ser combinados com o `OR` bit a bit.  
  
### <a name="return-value"></a>Valor retornado  
 Um bitset cujos elementos são o resultado da execução da operação `OR` nos elementos correspondentes de ` left` e ` right`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// bitset_or.cpp  
// compile with: /EHsc  
#include <bitset>  
#include <iostream>  
#include <string>  
  
using namespace std;  
  
int main()  
{  
   bitset<4> b1 ( string("0101") );  
   bitset<4> b2 ( string("0011") );  
   bitset<4> b3 = b1 | b2;  
   cout << "bitset 1: " << b1 << endl;  
   cout << "bitset 2: " << b2 << endl;  
   cout << "bitset 3: " << b3 << endl;  
}  
```  
  
```Output  
bitset 1: 0101  
bitset 2: 0011  
bitset 3: 0111  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<bitset>](../standard-library/bitset.md)


