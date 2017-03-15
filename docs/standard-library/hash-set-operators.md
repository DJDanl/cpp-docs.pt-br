---
title: Operadores &lt;hash_set&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 403d8e4e-0b3f-43fb-bc5a-8100c4f331c5
caps.latest.revision: 13
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 031904042e81f5ec9c8b54bbc3e2bfa9e9a365cf
ms.lasthandoff: 02/25/2017

---
# <a name="lthashsetgt-operators"></a>Operadores &lt;hash_set&gt;
||||  
|-|-|-|  
|[operator!=](#operator_neq)|[operator!= (hash_multiset)](#operator_neq__hash_multiset_)|[operator==](#operator_eq_eq)|  
|[operator== (hash_multiset)](#operator_eq_eq__hash_multiset_)|  
  
##  <a name="a-nameoperatorneqa--operator"></a><a name="operator_neq"></a>  operator!=  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Testa se o objeto hash_set no lado esquerdo do operador não é igual ao objeto hash_set no lado direito.  
  
```  
bool operator!=(const hash_set <Key, Traits, Allocator>& left, const hash_set <Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `hash_set`.  
  
 ` right`  
 Um objeto do tipo `hash_set`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os hash_sets não forem iguais; **false** se os hash_sets forem iguais.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos hash_set é baseada em uma comparação de paridade de seus elementos. Dois hash_sets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_op_ne.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> hs1, hs2, hs3;  
   int i;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      hs1.insert ( i );  
      hs2.insert ( i * i );  
      hs3.insert ( i );  
   }  
  
   if ( hs1 != hs2 )  
      cout << "The hash_sets hs1 and hs2 are not equal." << endl;  
   else  
      cout << "The hash_sets hs1 and hs2 are equal." << endl;  
  
   if ( hs1 != hs3 )  
      cout << "The hash_sets hs1 and hs3 are not equal." << endl;  
   else  
      cout << "The hash_sets hs1 and hs3 are equal." << endl;  
}  
```  
  
```Output  
The hash_sets hs1 and hs2 are not equal.  
The hash_sets hs1 and hs3 are equal.  
```  
  
##  <a name="a-nameoperatoreqeqa--operator"></a><a name="operator_eq_eq"></a>  operator==  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Testa se o objeto hash_set no lado esquerdo do operador é igual ao objeto hash_set no lado direito.  
  
```  
bool operator!==(const hash_set <Key, Traits, Allocator>& left, const hash_set <Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `hash_set`.  
  
 ` right`  
 Um objeto do tipo `hash_set`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o hash_set no lado esquerdo do operador for igual ao hash_set no lado direito do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre objetos hash_set é baseada em uma comparação de paridade de seus elementos. Dois hash_sets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_set_op_eq.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_set <int> s1, s2, s3;  
   int i;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      s1.insert ( i );  
      s2.insert ( i * i );  
      s3.insert ( i );  
   }  
  
   if ( s1 == s2 )  
      cout << "The hash_sets s1 and s2 are equal." << endl;  
   else  
      cout << "The hash_sets s1 and s2 are not equal." << endl;  
  
   if ( s1 == s3 )  
      cout << "The hash_sets s1 and s3 are equal." << endl;  
   else  
      cout << "The hash_sets s1 and s3 are not equal." << endl;  
}  
```  
  
```Output  
The hash_sets s1 and s2 are not equal.  
The hash_sets s1 and s3 are equal.  
```  
  
##  <a name="a-nameoperatorneqhashmultiseta--operator-hashmultiset"></a><a name="operator_neq__hash_multiset_"></a>  operator!= (hash_multiset)  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Testa se o objeto hash_multiset no lado esquerdo do operador não é igual ao objeto hash_multiset no lado direito.  
  
```  
bool operator!=(const hash_multiset <Key, Traits, Allocator>& left, const hash_multiset <Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `hash_multiset`.  
  
 ` right`  
 Um objeto do tipo `hash_multiset`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se os hash_multisets não forem iguais; **false** se os hash_multisets forem iguais.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos hash_multiset é baseada em uma comparação de paridade de seus elementos. Dois hash_multisets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hashset_op_ne.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   using namespace stdext;  
   hash_multiset <int> hs1, hs2, hs3;  
   int i;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      hs1.insert ( i );  
      hs2.insert ( i * i );  
      hs3.insert ( i );  
   }  
  
   if ( hs1 != hs2 )  
      cout << "The hash_multisets hs1 and hs2 are not equal." << endl;  
   else  
      cout << "The hash_multisets hs1 and hs2 are equal." << endl;  
  
   if ( hs1 != hs3 )  
      cout << "The hash_multisets hs1 and hs3 are not equal." << endl;  
   else  
      cout << "The hash_multisets hs1 and hs3 are equal." << endl;  
}  
```  
  
```Output  
The hash_multisets hs1 and hs2 are not equal.  
The hash_multisets hs1 and hs3 are equal.  
```  
  
##  <a name="a-nameoperatoreqeqhashmultiseta--operator-hashmultiset"></a><a name="operator_eq_eq__hash_multiset_"></a>  operator== (hash_multiset)  
  
> [!NOTE]
>  Esta API está obsoleta. A alternativa é a [Classe unordered_set](../standard-library/unordered-set-class.md).  
  
 Testa se o objeto hash_multiset no lado esquerdo do operador é igual ao objeto hash_multiset no lado direito.  
  
```  
bool operator!==(const hash_multiset <Key, Traits, Allocator>& left, const hash_multiset <Key, Traits, Allocator>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` left`  
 Um objeto do tipo `hash_multiset`.  
  
 ` right`  
 Um objeto do tipo `hash_multiset`.  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o hash_multiset no lado esquerdo do operador for igual ao hash_multiset no lado direito do operador; caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 A comparação entre os objetos hash_multiset é baseada em uma comparação de paridade de seus elementos. Dois hash_multisets serão iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.  
  
 No Visual C++ .NET 2003, membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não estão mais no namespace std e foram movidos para o namespace stdext. Consulte [Namespace stdext](../standard-library/stdext-namespace.md) para obter mais informações.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// hash_multiset_op_eq.cpp  
// compile with: /EHsc  
#include <hash_set>  
#include <iostream>  
  
int main( )  
{  
   using namespace std;  
   using namespace stdext;  
   hash_multiset <int> s1, s2, s3;  
   int i;  
  
   for ( i = 0 ; i < 3 ; i++ )  
   {  
      s1.insert ( i );  
      s2.insert ( i * i );  
      s3.insert ( i );  
   }  
  
   if ( s1 == s2 )  
      cout << "The hash_multisets s1 and s2 are equal." << endl;  
   else  
      cout << "The hash_multisets s1 and s2 are not equal." << endl;  
  
   if ( s1 == s3 )  
      cout << "The hash_multisets s1 and s2 are equal." << endl;  
   else  
      cout << "The hash_multisets s1 and s2 are not equal." << endl;  
}  
```  
  
```Output  
The hash_multisets s1 and s2 are not equal.  
The hash_multisets s1 and s2 are equal.  
```  
  
## <a name="see-also"></a>Consulte também  
 [<hash_set>](../standard-library/hash-set.md)


