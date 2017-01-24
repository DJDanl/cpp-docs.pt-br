---
title: "Iterando na cole&#231;&#227;o STL usando for each | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Coleções de DTL, iterando sobre"
ms.assetid: 9358ca29-b982-4a19-bbfd-bef50fe66c9a
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Iterando na cole&#231;&#227;o STL usando for each
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave de `for each` pode ser usado para iterar sobre uma coleção de biblioteca padrão do C\+\+ \(STL\).  
  
## Todas as Plataformas  
 **Comentários**  
  
 Uma coleção STL também é conhecida como *um contêiner*.  Para obter mais informações, consulte [Contêineres da STL](../standard-library/stl-containers.md).  
  
## Exemplos  
 **Exemplo**  
  
 O exemplo de código usa `for each` para iterar sobre [\<map\>](../Topic/%3Cmap%3E.md).  
  
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
  
  **Meses com 30 dias \= 4** **Exemplo**  
  
 O exemplo de código usa uma referência de const \(`const&`\) para uma variável de iteração com contêineres STL.  Você pode usar uma referência \(`&`\) como uma variável de iteração em qualquer coleção de um tipo que pode ser declarado como *T*`&`.  
  
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
  
  **retval: 60**   
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Comentários**  
  
 Não há nenhum comentário de plataforma específica sobre esse recurso.  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
 Não há nenhum comentário de plataforma específica sobre esse recurso.  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
## Consulte também  
 [for each, in](../dotnet/for-each-in.md)   
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)