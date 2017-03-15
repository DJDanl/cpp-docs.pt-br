---
title: C2872 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2872
dev_langs:
- C++
helpviewer_keywords:
- C2872
ms.assetid: c619ef97-6e0e-41d7-867c-f8d28a07d553
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 65e7a7bd56096fbeec61b651ab494d82edef9c90
ms.openlocfilehash: d53dbd9429ba3c1a525b85a3ef9f2e70152ddfa2
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2872"></a>C2872 de erro do compilador
'symbol': símbolo ambíguo  
  
O compilador não pode determinar o símbolo que você está se referindo.  
  
C2872 pode ocorrer se um arquivo de cabeçalho inclui um [usando a diretiva](../../cpp/namespaces-cpp.md#using_directives)e um arquivo de cabeçalho subsequentes está incluído e contém um tipo que esteja também no namespace especificado na `using` diretiva. Especifique um `using` diretiva somente depois de todos os arquivos de cabeçalho são especificados com `#include`.  
  
 Para obter mais informações sobre C2872, consulte os artigos da Base de Conhecimento [PRB: compilador erros quando você usar #import com XML no Visual C++ .NET](http://support.microsoft.com/kb/316317) e ["Erro C2872: 'Plataforma': símbolo ambíguo" mensagem de erro quando você usa o namespace Windows::Foundation::Metadata no Visual Studio 2013](https://support.microsoft.com/kb/2890859).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2872:  
  
```cpp  
// C2872.cpp  
namespace A {  
   int i;  
}  
  
using namespace A;  
int i;  
int main() {  
   ::i++;   // ok  
   A::i++;   // ok  
   i++;   // C2872 ::i or A::i?  
}  
```
