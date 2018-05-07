---
title: Iteração pela coleção de biblioteca padrão C++ usando for each | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- DTL collections, iterating over
ms.assetid: 9358ca29-b982-4a19-bbfd-bef50fe66c9a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 963c8a4213da756f03e95924940dc179bd305f60
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="iterating-over-c-standard-library-collection-by-using-for-each"></a>Iteração pela coleção de biblioteca padrão C++ usando for each
O `for each` palavra-chave pode ser usado para iterar em uma coleção de biblioteca padrão C++.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
 **Comentários**  
  
 Uma coleção de biblioteca padrão C++ também é conhecido como um *contêiner*. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).  
  
## <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O seguinte exemplo de código usa `for each` para iterar sobre uma [ \<mapa >](../standard-library/map.md).  
  
```  
// for_each_stl.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
#include <string>  
using namespace std;  
  
int main() {  
   int retval  = 0;  
   map<string, int> months;  
  
   months["january"] = 31;  
   months["february"] = 28;  
   months["march"] = 31;  
   months["april"] = 30;  
   months["may"] = 31;  
   months["june"] = 30;  
   months["july"] = 31;  
   months["august"] = 31;  
   months["september"] = 30;  
   months["october"] = 31;  
   months["november"] = 30;  
   months["december"] = 31;  
  
   map<string, int> months_30;  
  
   for each( pair<string, int> c in months )  
      if ( c.second == 30 )  
         months_30[c.first] = c.second;  
  
   for each( pair<string, int> c in months_30 )  
      retval++;  
  
   cout << "Months with 30 days = " << retval << endl;  
}  
```  
  
 **Saída**  
  
```Output  
Months with 30 days = 4  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir usa uma referência const (`const&`) para uma variável de iteração com contêineres da biblioteca padrão C++. Você pode usar uma referência (`&`) como uma variável de iteração em qualquer coleção de um tipo que pode ser declarado como um *T*`&`.  
  
```  
// for_each_stl_2.cpp  
// compile with: /EHsc  
#include <vector>  
#include <iostream>  
using namespace std;  
  
int main() {  
   int retval = 0;  
  
   vector<int> col(3);  
   col[0] = 10;  
   col[1] = 20;  
   col[2] = 30;  
  
   for each( const int& c in col )  
      retval += c;  
  
   cout << "retval: " << retval << endl;  
}  
```  
  
 **Saída**  
  
```Output  
retval: 60  
```  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 **Comentários**  
  
 Não há nenhum comentários específicos de plataforma sobre esse recurso.  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Comentários**  
  
 Não há nenhum comentários específicos de plataforma sobre esse recurso.  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
## <a name="see-also"></a>Consulte também  
 [para cada um, no](../dotnet/for-each-in.md)   
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)