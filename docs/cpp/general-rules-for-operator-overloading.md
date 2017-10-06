---
title: Regras gerais para sobrecarga de operador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- operator overloading [C++], rules
ms.assetid: eb2b3754-35f7-4832-b1da-c502893dc0c7
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 882c3777d2744a8a693512f564d7c3b1f1c1a46e
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="general-rules-for-operator-overloading"></a>Regras gerais para sobrecarga de operador
As seguintes regras restringem o modo como os operadores sobrecarregados são implementados. No entanto, não são aplicadas para o [novo](../cpp/new-operator-cpp.md) e [excluir](../cpp/delete-operator-cpp.md) operadores que são abordados separadamente.  
  
-   Você não pode definir novos operadores, como **.  
  
-   Você não pode redefinir o significado dos operadores quando aplicados aos tipos de dados internos.  
  
-   Os operadores sobrecarregados devem ser uma função membro da classe não estática ou uma função global. Uma função global que exige acesso a membros de classe particulares ou protegidos deve ser declarada como um amigo daquela classe. Uma função global deve ter pelo menos um argumento que é do da classe ou do tipo enumerado, ou que é uma referência a uma classe ou a um tipo enumerado. Por exemplo:  
  
    ```  
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
  
     O exemplo de código anterior declara o operador menor que como uma função membro; no entanto, os operadores de adição são declarados como funções globais que têm acesso de amigo. Observe que mais de uma implementação pode ser fornecida para um determinado operador. No caso do operador de adição acima, as duas implementações são fornecidas para facilitar a comutatividade. É tão provável que os operadores que adicionam `Point` a `Point`, `int` a `Point`, e assim por diante, possam ser implementados.  
  
-   Os operadores obedecem a precedência, agrupamento e número de operandos ditados por seu uso típico com tipos internos. Portanto, não há nenhum modo de expressar o conceito "Adicionar 2 e 3 para um objeto do tipo `Point`," esperando 2 a serem adicionadas à *x* coordenada e 3 a serem adicionadas à *y* coordenar.  
  
-   Os operadores unários declarados como funções membro não pegam argumentos; se declarados como funções globais, eles pegam um argumento.  
  
-   Os operadores binários declarados como funções membro pegam um argumento; se declarados como funções globais, eles pegam dois argumentos.  
  
-   Se um operador pode ser usado como um unário ou um operador binário (**&**, ** \* **, ** + **, e ** - **), você pode sobrecarregar cada uso separadamente.  
  
-   Os operadores sobrecarregados não podem ter argumentos padrão.  
  
-   Todos os operadores sobrecarregados, exceto a atribuição (`operator=`), são herdados por classes derivadas.  
  
-   O primeiro argumento para operadores sobrecarregados da função membro sempre é do tipo de classe do objeto para o qual o operador é invocado (a classe na qual o operador é declarado, ou uma classe derivada dessa classe.) Nenhuma conversão é fornecida para o primeiro argumento.  
  
 Observe que o significado de qualquer operador pode ser alterado completamente. Que inclui o significado do endereço de (**&**), a atribuição (**=**) e os operadores de chamada de função. Além disso, as identidades que podem ser confiáveis para os tipos internos podem ser modificadas usando a sobrecarga do operador. Por exemplo, as quatro instruções a seguir geralmente são equivalentes quando avaliada completamente:  
  
```  
var = var + 1;  
var += 1;  
var++;  
++var;  
```  
  
 Essa identidade não pode ser confiável para os tipos da classe que sobrecarregam os operadores. Além disso, alguns dos requisitos implícitos no uso desses operadores para tipos básicos são relaxados para operadores sobrecarregados. Por exemplo, o operador de adição/atribuição, `+=`, requer que o operando esquerdo seja um l-value quando aplicado aos tipos básicos; não há nenhum requisito tal quando o operador está sobrecarregado.  
  
> [!NOTE]
>  Para consistência, geralmente é melhor seguir o modelo dos tipos internos ao definir operadores sobrecarregados. Se a semântica de um operador sobrecarregado for significativamente diferentes do de seu significado em outros contextos, ela pode ser mais confusa do que útil.  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)
