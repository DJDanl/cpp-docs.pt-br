---
title: Resolução de sobrecarga de chamadas de função de modelo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- function templates overload resolution
ms.assetid: a2918748-2cbb-4fc6-a176-e256f120bee4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 62041f78af18d6ac2f521fea763a11bb2859fbf5
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39401919"
---
# <a name="overload-resolution-of-function-template-calls"></a>Resolução de sobrecarga das chamadas de modelo de função
Um modelo de função pode sobrecarregar funções de fora do modelo com o mesmo nome. Nesse cenário, as chamadas de função são resolvidas primeiro com o uso de dedução de argumentos do modelo para criar uma instância do modelo de função com uma especialização exclusiva. Se a dedução de argumentos do modelo falhar, as outras sobrecargas de função são consideradas resolver a chamada. Essas outras sobrecargas, também conhecidas como conjunto de candidatas, incluem funções fora do modelo e outros modelos de função com instâncias. Se a dedução de argumentos do modelo for bem sucedida, a função gerada será comparada com as outras funções para determinar a melhor correspondência, de acordo com as regras de resolução de sobrecarga. Para obter mais informações, consulte [sobrecarregamento de função](function-overloading.md).  
  
## <a name="example"></a>Exemplo

 Se uma função fora do modelo for uma correspondência igualmente boa a uma função do modelo, a função fora do modelo será escolhida (a menos que os argumentos do modelo sejam especificados explicitamente), como na chamada `f(1, 1)` no exemplo a seguir.  
  
```cpp
// template_name_resolution9.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
void f(int, int) { cout << "f(int, int)" << endl; }  
void f(char, char) { cout << "f(char, char)" << endl; }  
  
template <class T1, class T2>  
void f(T1, T2)  
{  
   cout << "void f(T1, T2)" << endl;  
};  
  
int main()  
{  
   f(1, 1);   // Equally good match; choose the nontemplate function.  
   f('a', 1); // Chooses the template function.  
   f<int, int>(2, 2);  // Template arguments explicitly specified.  
}  
```  
  
```Output  
f(int, int)  
void f(T1, T2)  
void f(T1, T2)  
```  
  
## <a name="example"></a>Exemplo

 O exemplo a seguir mostra que a função de modelo com correspondência exata é preferida se a função fora do modelo requeira uma conversão.  
  
```cpp
// template_name_resolution10.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
void f(int, int) { cout << "f(int, int)" << endl; }  
  
template <class T1, class T2>  
void f(T1, T2)  
{  
   cout << "void f(T1, T2)" << endl;  
};  
  
int main()  
{  
   long l = 0;  
   int i = 0;  
   // Call the template function f(long, int) because f(int, int)  
   // would require a conversion from long to int.  
   f(l, i);  
}  
```  
  
```Output  
void f(T1, T2)  
```  
  
## <a name="see-also"></a>Consulte também
 [Resolução de nome](../cpp/templates-and-name-resolution.md)   
 [typename](../cpp/typename.md)   