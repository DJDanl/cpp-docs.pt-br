---
title: "Objetos tempor&#225;rios | Microsoft Docs"
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
  - "objetos [C++], temporário"
  - "objetos temporários"
ms.assetid: 4c8cec02-391e-4225-9bc6-06d150201412
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Objetos tempor&#225;rios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em alguns casos, é necessário que o compilador crie objetos temporários.  Esses objetos temporários podem ser criados pelos seguintes motivos:  
  
-   Para inicializar uma referência `const` com um inicializador de um tipo diferente do tipo subjacente da referência que está sendo inicializada.  
  
-   Para armazenar o valor de retorno de uma função que retorna um tipo definido pelo usuário.  Esses temporários só serão criados quando o programa não copia o valor de retorno para um objeto.  Por exemplo:  
  
    ```  
    UDT Func1();    //  Declare a function that returns a user-defined  
                    //   type.  
  
    ...  
  
    Func1();        //  Call Func1, but discard return value.  
                    //  A temporary object is created to store the return  
                    //   value.  
    ```  
  
     Como o valor de retorno não é copiado a outro objeto, um objeto temporário será criado.  Um caso comum mais comum onde os temporários são criados é durante a avaliação de uma expressão onde as funções sobrecarregadas do operador devem ser chamadas.  Essas funções sobrecarregadas do operador retornam um tipo definido pelo usuário que geralmente não é copiado a outro objeto.  
  
     Considere a expressão `ComplexResult = Complex1 + Complex2 + Complex3`.  A expressão `Complex1 + Complex2` é avaliada, e o resultado é armazenado em um objeto temporário.  Em seguida, a expressão *temporary* `+ Complex3` é avaliada, e o resultado é copiado para `ComplexResult` \(presumindo que o operador de atribuição não seja sobrecarregado\).  
  
-   Para armazenar o resultado de uma conversão em um tipo definido pelo usuário.  Quando um objeto de um determinado tipo é convertido explicitamente em um tipo definido pelo usuário, o novo objeto é criado como um objeto temporário.  
  
 Os objetos temporários têm um tempo de vida definido pelo ponto de criação e pelo ponto em que são destruídos.  Qualquer expressão que cria mais de um objeto temporário acaba destruindo\-os na ordem inversa da qual foram criados.  Os pontos em que a destruição ocorre são mostrados na tabela a seguir.  
  
### Pontos de destruição para objetos temporários  
  
|Motivo temporário criado|Ponto de destruição|  
|------------------------------|-------------------------|  
|Resultado da avaliação de expressão|Todos os temporaries criados como resultado da avaliação da expressão são destruídos o final da instrução de expressão \(ou seja, no ponto\-e\-vírgula\), ou no final das expressões de controle para instruções `for`, `if`, `while`, `do` e `switch`.|  
|Inicializando referências `const`|Se um inicializador não for um valor l do mesmo tipo da referência que está sendo inicializada, um temporário do tipo de objeto subjacente será criada e inicializada com a expressão de inicialização.  Esse objeto temporário será destruído imediatamente depois que o objeto de referência ao qual está associado é destruído.|  
  
## Consulte também  
 [Funções de membro especiais](../misc/special-member-functions-cpp.md)