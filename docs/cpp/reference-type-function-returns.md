---
title: "Retornos da fun&#231;&#227;o de tipo de refer&#234;ncia | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de dados [C++], tipos de retorno de função"
  - "tipos de retorno de função, tipo de referência"
  - "funções [C++], tipos de retorno"
ms.assetid: 5b73be1d-2dc7-41df-ab0a-adcba36f2ad1
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Retornos da fun&#231;&#227;o de tipo de refer&#234;ncia
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções podem ser declaradas para retornar um tipo de referência.  Há duas razões para fazer tal declaração:  
  
-   As informações retornadas são um objeto tão grande que retornar uma referência é mais eficiente do que retornar uma cópia.  
  
-   O tipo da função deve ser um l\-value.  
  
-   O objeto mencionado não sairá do escopo quando a função retorna.  
  
 Assim como pode ser mais eficiente passar objetos grandes *para as* funções por referência, também pode ser mais eficiente retornar objetos grandes *das* funções por referência.  O protocolo de retorno de referência elimina a necessidade de copiar o objeto em um local temporário antes de retornar.  
  
 Os tipos de retorno de referência também podem ser úteis quando a função deve ser avaliada como um l\-value.  A maioria dos operadores sobrecarregados entra nessa categoria, particularmente o operador de atribuição.  Os operadores sobrecarregados são abordados em [Operadores sobrecarregados](../cpp/operator-overloading.md).  
  
## Exemplo  
 Considere o exemplo de `Point`:  
  
```  
// refType_function_returns.cpp  
// compile with: /EHsc  
  
#include <iostream>  
using namespace std;  
  
class Point  
{  
public:  
// Define "accessor" functions as  
//  reference types.  
unsigned& x();  
unsigned& y();  
private:  
// Note that these are declared at class scope:  
unsigned obj_x;   
unsigned obj_y;   
};  
  
unsigned& Point :: x()  
{  
return obj_x;  
}  
unsigned& Point :: y()  
{  
return obj_y;  
}  
  
int main()  
{  
Point ThePoint;  
// Use x() and y() as l-values.  
ThePoint.x() = 7;  
ThePoint.y() = 9;  
  
// Use x() and y() as r-values.  
cout << "x = " << ThePoint.x() << "\n"  
<< "y = " << ThePoint.y() << "\n";  
}  
```  
  
## Saída  
  
```  
x = 7  
y = 9  
```  
  
 Observe que as funções `x` e `y` são declaradas como tipos de referência de retorno.  Essas funções podem ser usadas em ambos os lados de uma instrução de atribuição.  
  
 Observe também que no main, ThePoint objeto permanece no escopo e, portanto, seus membros de referência ainda existem e podem ser acessados com segurança.  
  
 As declarações de tipos de referência devem conter inicializadores, exceto nos seguintes casos:  
  
-   Declaração `extern` explícita  
  
-   Declaração de um membro de classe  
  
-   Declaração em uma classe  
  
-   Declaração de um argumento para uma função ou o tipo de retorno para uma função  
  
## Cuidado, retornando o endereço do local  
 Se você declarar um objeto no escopo local, esse objeto será destruído quando a função retorna.  Se a função retorna uma referência a esse objeto, essa referência provavelmente causará uma violação de acesso em tempo de execução se o chamador tenta usar a referência nula.  
  
```  
// C4172 means Don’t do this!!!  
Foo& GetFoo()  
{  
    Foo f;  
    ...  
    return f;  
} // f is destroyed here  
```  
  
 O compilador emite um aviso neste caso: `C4172 de aviso: retornando o endereço da variável local ou temporário`.  Em programas simples é possível que, ocasionalmente, nenhuma violação de acesso ocorrerá se a referência for acessada pelo chamador antes que o local da memória será substituído.  Isso ocorre devido a enorme sorte.  Prestar atenção o aviso.  
  
## Consulte também  
 [Referências](../cpp/references-cpp.md)