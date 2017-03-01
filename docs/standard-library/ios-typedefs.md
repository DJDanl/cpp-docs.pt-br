---
title: Typedefs &lt;ios&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 0b962632-3439-44de-bf26-20c67a7f0ff3
caps.latest.revision: 13
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d9f9dd5f13f0f4559455ff8d8cf09bab5350b1f0
ms.lasthandoff: 02/25/2017

---
# <a name="ltiosgt-typedefs"></a>Typedefs &lt;ios&gt;
||||  
|-|-|-|  
|[ios](#ios)|[streamoff](#streamoff)|[streampos](#streampos)|  
|[streamsize](#streamsize)|[wios](#wios)|[wstreampos](#wstreampos)|  
  
##  <a name="a-nameiosa--ios"></a><a name="ios"></a>  ios  
 Dá suporte à classe ios da biblioteca iostream antiga.  
  
```  
typedef basic_ios<char, char_traits<char>> ios;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_ios](../standard-library/basic-ios-class.md), especializado para elementos do tipo `char` com características de caractere padrão.  
  
##  <a name="a-namestreamoffa--streamoff"></a><a name="streamoff"></a>  streamoff  
 Dá suporte a operações internas.  
  
```  
#ifdef _WIN64  
    typedef __int64 streamoff;  
#else  
    typedef long streamoff;  
#endif  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um inteiro com sinal que descreve um objeto que pode armazenar um deslocamento de byte envolvido em várias operações de posicionamento de fluxo. Sua representação tem pelo menos 32 bits de valor. Ela não é necessariamente grande o suficiente para representar uma posição de byte arbitrária dentro de um fluxo. O valor **streamoff(-1)** normalmente indica um deslocamento incorreto.  
  
##  <a name="a-namestreamposa--streampos"></a><a name="streampos"></a>  streampos  
 Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.  
  
```  
typedef fpos<mbstate_t> streampos;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de [fpos](../standard-library/fpos-class.md)< `mbstate_t`>.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_streampos.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )   
{  
   using namespace std;  
  
   ofstream x( "iostream.txt" );  
   x << "testing";  
   streampos y = x.tellp( );  
   cout << y << endl;  
}  
```  
  
```Output  
7  
```  
  
##  <a name="a-namestreamsizea--streamsize"></a><a name="streamsize"></a>  streamsize  
 Indica o tamanho do fluxo.  
  
```  
#ifdef _WIN64  
    typedef __int64 streamsize;  
#else  
    typedef int streamsize;  
#endif  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um inteiro com sinal que descreve um objeto que pode armazenar uma contagem do número de elementos envolvidos em várias operações de fluxo. Sua representação tem pelo menos 16 bits. Ela não é necessariamente grande o suficiente para representar uma posição de byte arbitrária dentro de um fluxo.  
  
### <a name="example"></a>Exemplo  
  Após compilar e executar o programa a seguir, examine o arquivo test.txt para ver o efeito da configuração `streamsize`.  
  
```  
// ios_streamsize.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )   
{  
   using namespace std;  
   char a[16] = "any such text";  
   ofstream x( "test.txt" );  
   streamsize y = 6;  
   x.write( a, y );  
}  
```  
  
##  <a name="a-namewiosa--wios"></a><a name="wios"></a>  wios  
 Dá suporte à classe wios da biblioteca iostream antiga.  
  
```  
typedef basic_ios<wchar_t, char_traits<wchar_t>> wios;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo da classe de modelo [basic_ios](../standard-library/basic-ios-class.md), especializado para elementos do tipo `wchar_t` com características de caractere padrão.  
  
##  <a name="a-namewstreamposa--wstreampos"></a><a name="wstreampos"></a>  wstreampos  
 Contém a posição atual do ponteiro de buffer ou do ponteiro de arquivo.  
  
```  
typedef fpos<mbstate_t> wstreampos;  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de [fpos](../standard-library/fpos-class.md)< `mbstate_t`>.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_wstreampos.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main( )   
{  
   using namespace std;  
   wofstream xw( "wiostream.txt" );  
   xw << L"testing";  
   wstreampos y = xw.tellp( );  
   cout << y << endl;  
}  
```  
  
```Output  
7  
```  
  
## <a name="see-also"></a>Consulte também  
 [\<ios>](../standard-library/ios.md)


