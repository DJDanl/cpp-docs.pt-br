---
title: Erro do compilador C2666
ms.date: 11/04/2016
f1_keywords:
- C2666
helpviewer_keywords:
- C2666
ms.assetid: 78364d15-c6eb-439a-9088-e04a0176692b
ms.openlocfilehash: 4a1d46f3b000b5054564b05ca2c3c94a9e7b6398
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50479269"
---
# <a name="compiler-error-c2666"></a>Erro do compilador C2666

'identifier': número sobrecargas possuem conversões similares

Uma função sobrecarregada ou o operador é ambíguo.   Listas de parâmetros formais podem ser muito semelhantes para o compilador resolver a ambiguidade.  Para resolver esse erro, converta explicitamente um ou mais dos parâmetros reais.

O exemplo a seguir gera C2666:

```
// C2666.cpp
struct complex {
   complex(double);
};

void h(int,complex);
void h(double, double);

int main() {
   h(3,4);   // C2666
}
```

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003:

- operadores binários e conversões definidas pelo usuário para tipos de ponteiro

- conversão de qualificação não é o mesmo que a conversão de identidade

Para os operadores binários \<, >, \<= e > = um passado parâmetro agora é convertido implicitamente no tipo do operando se o tipo do parâmetro define um operador de conversão definida pelo usuário a ser convertido para o tipo do operando. Agora há potencial de ambiguidade.

Para o código que é válido no Visual Studio .NET 2003 e versões do Visual Studio .NET do Visual C++, chame o operador de classe explicitamente usando a sintaxe da função.

## <a name="example"></a>Exemplo

```
// C2666b.cpp
#include <string.h>
#include <stdio.h>

struct T
{
    T( const T& copy )
    {
        m_str = copy.m_str;
    }

    T( const char* str )
    {
        int iSize = (strlen( str )+ 1);
        m_str = new char[ iSize ];
        if (m_str)
            strcpy_s( m_str, iSize, str );
    }

    bool operator<( const T& RHS )
    {
        return m_str < RHS.m_str;
    }

    operator char*() const
    {
        return m_str;
    }

    char* m_str;
};

int main()
{
    T str1( "ABCD" );
    const char* str2 = "DEFG";

    // Error - Ambiguous call to operator<()
    // Trying to convert str1 to char* and then call
    // operator<( const char*, const char* )?
    //  OR
    // trying to convert str2 to T and then call
    // T::operator<( const T& )?

    if( str1 < str2 )   // C2666

    if ( str1.operator < ( str2 ) )   // Treat str2 as type T
        printf_s("str1.operator < ( str2 )\n");

    if ( str1.operator char*() < str2 )   // Treat str1 as type char*
        printf_s("str1.operator char*() < str2\n");
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2666

```
// C2666c.cpp
// compile with: /c

enum E
{
    E_A,   E_B
};

class A
{
    int h(const E e) const {return 0; }
    int h(const int i) { return 1; }
    // Uncomment the following line to resolve.
    // int h(const E e) { return 0; }

    void Test()
    {
        h(E_A);   // C2666
        h((const int) E_A);
        h((int) E_A);
    }
};
```