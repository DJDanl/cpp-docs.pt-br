---
title: 'Operador cast: () | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- cast operators [C++]
- () cast operator
ms.assetid: 4c99eb92-1b19-4a5d-9840-5d8c29b8453e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 96428c5a18c7b345f323ab377c24fe5f008bc025
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cast-operator-"></a>Operador cast: ()
Uma conversão de tipo fornece um método para conversão explícita do tipo de um objeto em uma situação específica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      unary-expression  
( type-name ) cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 Qualquer expressão unária é considerada uma expressão de conversão.  
  
 O compilador trata *cast-expression* como tipo *type-name* depois que uma conversão de tipo é feita. As conversões podem ser usadas para converter objetos de qualquer tipo escalar em ou de qualquer outro tipo escalar. As conversões de tipo explícito são restringidas pelas mesmas regras que determinam os efeitos de conversões implícitas. As restrições adicionais de conversões podem resultar de tamanhos reais ou de representação de tipos específicos.  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_CastOperator.cpp  
// compile with: /EHsc  
// Demonstrate cast operator  
#include <iostream>  
  
using namespace std;  
  
int main()  
{  
    double x = 3.1;  
    int i;  
    cout << "x = " << x << endl;  
    i = (int)x;   // assign i the integer part of x  
    cout << "i = " << i << endl;  
}  
```  
  
## <a name="example"></a>Exemplo  
  
```  
// expre_CastOperator2.cpp  
// The following sample shows how to define and use a cast operator.   
#include <string.h>  
#include <stdio.h>  
  
class CountedAnsiString  
{  
public:  
    // Assume source is not null terminated  
    CountedAnsiString(const char *pStr, size_t nSize) :  
                      m_nSize(nSize)  
    {  
        m_pStr = new char[sizeOfBuffer];  
  
        strncpy_s(m_pStr, sizeOfBuffer, pStr, m_nSize);  
        memset(&m_pStr[m_nSize], '!', 9); // for demonstration purposes.  
    }  
  
    // Various string-like methods...  
  
    const char *GetRawBytes() const  
    {  
        return(m_pStr);  
    }  
  
    //   
    // operator to cast to a const char *  
    //   
    operator const char *()  
    {  
        m_pStr[m_nSize] = '\0';  
        return(m_pStr);  
    }  
  
    enum  
    {  
        sizeOfBuffer = 20  
    } size;  
  
private:  
    char *m_pStr;  
    const size_t m_nSize;  
};  
  
int main()  
{  
    const char *kStr = "Excitinggg";  
    CountedAnsiString myStr(kStr, 8);  
  
    const char *pRaw = myStr.GetRawBytes();  
    printf_s("RawBytes truncated to 10 chars:   %.10s\n", pRaw);  
  
    const char *pCast = myStr; // or (const char *)myStr;  
    printf_s("Casted Bytes:   %s\n", pCast);  
  
    puts("Note that the cast changed the raw internal string");  
    printf_s("Raw Bytes after cast:   %s\n", pRaw);  
}  
```  
  
```Output  
RawBytes truncated to 10 chars:   Exciting!!  
Casted Bytes:   Exciting  
Note that the cast changed the raw internal string  
Raw Bytes after cast:   Exciting  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operador de conversão de tipo explícito:)](../cpp/explicit-type-conversion-operator-parens.md)   
 [Operadores de conversão](../cpp/casting-operators.md)   
 [Operadores cast](../c-language/cast-operators.md)