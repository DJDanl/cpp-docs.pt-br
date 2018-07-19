---
title: Regras gerais para sobrecarga de operador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- operator overloading [C++], rules
ms.assetid: eb2b3754-35f7-4832-b1da-c502893dc0c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cd7e7a64b1dfc30d1827da614f67a5b47bd42218
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942157"
---
# <a name="general-rules-for-operator-overloading"></a>Regras gerais para sobrecarga de operador
As seguintes regras restringem o modo como os operadores sobrecarregados são implementados. No entanto, eles não se aplicam para o [novos](../cpp/new-operator-cpp.md) e [excluir](../cpp/delete-operator-cpp.md) operadores, que são cobertos separadamente.  
  
-   Você não pode definir novos operadores, tais como **.**.  
  
-   Você não pode redefinir o significado dos operadores quando aplicados aos tipos de dados internos.  
  
-   Os operadores sobrecarregados devem ser uma função membro da classe não estática ou uma função global. Uma função global que exige acesso a membros de classe particulares ou protegidos deve ser declarada como um amigo daquela classe. Uma função global deve ter pelo menos um argumento que é do da classe ou do tipo enumerado, ou que é uma referência a uma classe ou a um tipo enumerado. Por exemplo:  
  
    ```cpp  
    // rules_for_operator_overloading.cpp  
    class Point  
    {  
    public:  
        Point operator<( Point & );  // Declare a member operator   
                                     //  overload.  
        // Declare addition operators.  
        friend Point operator+( Point&, int );  
        friend Point operator+( int, Point& );  
    };  
  
    int main()  
    {  
    }  
    ```  
  
     O exemplo de código anterior declara o operador menor que como uma função membro; no entanto, os operadores de adição são declarados como funções globais que têm acesso de amigo. Observe que mais de uma implementação pode ser fornecida para um determinado operador. No caso do operador de adição acima, as duas implementações são fornecidas para facilitar a comutatividade. É tão provável que os operadores que adicionam uma `Point` para um `Point`, **int** para um `Point`e assim por diante, pode ser implementado.  
  
-   Os operadores obedecem a precedência, agrupamento e número de operandos ditados por seu uso típico com tipos internos. Portanto, não há nenhuma maneira para expressar o conceito "Adicionar 2 e 3 para um objeto do tipo `Point`," esperando 2 ser adicionado ao *x* coordenadas e 3 a ser adicionado ao *y* coordenar.  
  
-   Os operadores unários declarados como funções membro não pegam argumentos; se declarados como funções globais, eles pegam um argumento.  
  
-   Os operadores binários declarados como funções membro pegam um argumento; se declarados como funções globais, eles pegam dois argumentos.  
  
-   Se um operador pode ser usado como um unário ou um operador binário (__&__, __*__, __+__, e __-__), você poderá sobrecarregar cada uso separadamente.  
  
-   Os operadores sobrecarregados não podem ter argumentos padrão.  
  
-   Todos os operadores sobrecarregados, exceto a atribuição (`operator=`), são herdados por classes derivadas.  
  
-   O primeiro argumento para operadores sobrecarregados da função membro sempre é do tipo de classe do objeto para o qual o operador é invocado (a classe na qual o operador é declarado, ou uma classe derivada dessa classe.) Nenhuma conversão é fornecida para o primeiro argumento.  
  
 Observe que o significado de qualquer operador pode ser alterado completamente. Isso inclui o significado do endereço de (**&**), atribuição (**=**) e operadores de chamada de função. Além disso, as identidades que podem ser confiáveis para os tipos internos podem ser modificadas usando a sobrecarga do operador. Por exemplo, as quatro instruções a seguir geralmente são equivalentes quando avaliada completamente:  
  
```cpp 
var = var + 1;  
var += 1;  
var++;  
++var;  
```  
  
 Essa identidade não pode ser confiável para os tipos da classe que sobrecarregam os operadores. Além disso, alguns dos requisitos implícitos no uso desses operadores para tipos básicos são relaxados para operadores sobrecarregados. Por exemplo, o operador de adição/atribuição, `+=`, requer que o operando esquerdo seja um l-value quando aplicado aos tipos básicos; não há nenhum requisito tal quando o operador está sobrecarregado.  
  
> [!NOTE]
> Para consistência, geralmente é melhor seguir o modelo dos tipos internos ao definir operadores sobrecarregados. Se a semântica de um operador sobrecarregado for significativamente diferentes do de seu significado em outros contextos, ela pode ser mais confusa do que útil.  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)