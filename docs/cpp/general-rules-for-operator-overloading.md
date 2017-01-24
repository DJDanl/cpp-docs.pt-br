---
title: "Regras gerais para sobrecarga de operador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "sobrecarga de operador, regras"
ms.assetid: eb2b3754-35f7-4832-b1da-c502893dc0c7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Regras gerais para sobrecarga de operador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As seguintes regras restringem o modo como os operadores sobrecarregados são implementados.  No entanto, elas não se aplicam aos operadores [new](../cpp/new-operator-cpp.md) e [delete](../cpp/delete-operator-cpp.md), que são cobertos separadamente.  
  
-   Você não pode definir novos operadores, como \*\*.  
  
-   Você não pode redefinir o significado dos operadores quando aplicados aos tipos de dados internos.  
  
-   Os operadores sobrecarregados devem ser uma função membro da classe não estática ou uma função global.  Uma função global que exige acesso a membros de classe particulares ou protegidos deve ser declarada como um amigo daquela classe.  Uma função global deve ter pelo menos um argumento que é do da classe ou do tipo enumerado, ou que é uma referência a uma classe ou a um tipo enumerado.  Por exemplo:  
  
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
  
     O exemplo de código anterior declara o operador menor que como uma função membro; no entanto, os operadores de adição são declarados como funções globais que têm acesso de amigo.  Observe que mais de uma implementação pode ser fornecida para um determinado operador.  No caso do operador de adição acima, as duas implementações são fornecidas para facilitar a comutatividade.  É tão provável que os operadores que adicionam `Point` a `Point`, `int` a `Point`, e assim por diante, possam ser implementados.  
  
-   Os operadores obedecem a precedência, agrupamento e número de operandos ditados por seu uso típico com tipos internos.  Portanto, não há maneira de expressar o conceito “adicionar 2 e 3 a um objeto de tipo `Point`”, esperando 2 ser adicionado à coordenada *x* e 3 e à coordenada *y*.  
  
-   Os operadores unários declarados como funções membro não pegam argumentos; se declarados como funções globais, eles pegam um argumento.  
  
-   Os operadores binários declarados como funções membro pegam um argumento; se declarados como funções globais, eles pegam dois argumentos.  
  
-   Se um operador puder ser usado como um unário ou binário \(**&**, **\***, **\+**, e **\-**\), você poderá sobrecarregar cada uso separadamente.  
  
-   Os operadores sobrecarregados não podem ter argumentos padrão.  
  
-   Todos os operadores sobrecarregados, exceto a atribuição \(`operator=`\), são herdados por classes derivadas.  
  
-   O primeiro argumento para operadores sobrecarregados da função membro sempre é do tipo de classe do objeto para o qual o operador é invocado \(a classe na qual o operador é declarado, ou uma classe derivada dessa classe.\)  Nenhuma conversão é fornecida para o primeiro argumento.  
  
 Observe que o significado de qualquer operador pode ser alterado completamente.  Isso inclui o significado dos operadores address\-of \(**&**\), assignment \(**\=**\) e function\-call.  Além disso, as identidades que podem ser confiáveis para os tipos internos podem ser modificadas usando a sobrecarga do operador.  Por exemplo, as quatro instruções a seguir geralmente são equivalentes quando avaliada completamente:  
  
```  
var = var + 1;  
var += 1;  
var++;  
++var;  
```  
  
 Essa identidade não pode ser confiável para os tipos da classe que sobrecarregam os operadores.  Além disso, alguns dos requisitos implícitos no uso desses operadores para tipos básicos são relaxados para operadores sobrecarregados.  Por exemplo, o operador de adição\/atribuição, `+=`, requer que o operando esquerdo seja um l\-value quando aplicado aos tipos básicos; não há nenhum requisito tal quando o operador está sobrecarregado.  
  
> [!NOTE]
>  Para consistência, geralmente é melhor seguir o modelo dos tipos internos ao definir operadores sobrecarregados.  Se a semântica de um operador sobrecarregado for significativamente diferentes do de seu significado em outros contextos, ela pode ser mais confusa do que útil.  
  
## Consulte também  
 [Sobrecarga de operador](../cpp/operator-overloading.md)