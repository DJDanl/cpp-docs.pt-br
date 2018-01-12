---
title: C2600 de erros do compilador por meio de C2699 | Microsoft Docs
ms.date: 11/17/2017
ms.technology: cpp-tools
ms.topic: error-reference
f1_keywords:
- C2604
- C2606
- C2607
- C2608
- C2609
- C2610
- C2615
- C2618
- C2620
- C2621
- C2622
- C2623
- C2625
- C2629
- C2631
- C2639
- C2641
- C2642
- C2643
- C2644
- C2684
- C2685
- C2686
- C2697
helpviewer_keywords:
- C2604
- C2606
- C2607
- C2608
- C2609
- C2610
- C2615
- C2618
- C2620
- C2621
- C2622
- C2623
- C2625
- C2629
- C2631
- C2639
- C2641
- C2642
- C2643
- C2644
- C2684
- C2685
- C2686
- C2697
dev_langs: C++
ms.assetid: 73c6319f-cbea-4a2f-913b-90dc1af61f64
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7b67597e6b841546b624d235ab017f138b969135
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-errors-c2600-through-c2699"></a>C2600 de erros do compilador por meio de C2699

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C2600](compiler-error-c2600.md)|'*função*': não é possível definir uma função de membro especial gerada pelo compilador (deve ser declarada na classe pela primeira vez)|
|[Erro do compilador C2601](compiler-error-c2601.md)|'*função*': definições de função local são inválidas|
|[Erro do compilador C2602](compiler-error-c2602.md)|'*classe*::*identificador*'não é um membro de uma classe base de'*classe*'|
|[Erro do compilador C2603](compiler-error-c2603.md)|'*função*': muitos bloco objetos static de escopo com construtores/destrutores na função|
|C2604 de erro do compilador|'*identificador*': não é possível implementar mais de um método de interface|
|[Erro do compilador C2605](compiler-error-c2605.md)|'*identificador*': este método é reservado dentro de uma classe gerenciada/WinRT|
|C2606 de erro do compilador|'*class1*': não pode reimplementar '*membro*', pois é herdado da base de tempo de execução'*class2*'|
|C2607 de erro do compilador|falhado de asserção estática|
|C2608 de erro do compilador|Obsoleto.|
|C2609 de erro do compilador|Obsoleto.|
|C2610 de erro do compilador|'*classe*::*membro*': não é uma função de membro especiais que pode ser padronizada|
|[Erro do compilador C2611](compiler-error-c2611.md)|'*token*': seguinte ilegal ' ~' (identificador esperado)|
|[Erro do compilador C2612](compiler-error-c2612.md)|à direita '*caracteres*' inválida na lista de inicializadores de base/membro|
|[Erro do compilador C2613](compiler-error-c2613.md)|à direita '*caracteres*' inválida na lista de classes base|
|[Erro do compilador C2614](compiler-error-c2614.md)|'*classe*': inicialização de membro inválida: '*identificador*' não é uma base ou membro|
|C2615 de erro do compilador|Obsoleto.|
|[Erro do compilador C2616](compiler-error-c2616.md)|'*conversão*': não é possível converter implicitamente não lvalue '*type1*' para um '*type2*' que não seja const|
|[Erro do compilador C2617](compiler-error-c2617.md)|'*função*': instrução return inconsistente|
|C2618 de erro do compilador|Obsoleto.|
|[Erro do compilador C2619](compiler-error-c2619.md)|'*identificador*': um membro de dados estático não é permitido em uma struct/união anônima|
|C2620 de erro do compilador|Obsoleto.|
|C2621 de erro do compilador|Obsoleto.|
|C2622 de erro do compilador|Obsoleto.|
|C2623 de erro do compilador|Obsoleto.|
|[Erro do compilador C2624](compiler-error-c2624.md)|'*escopo*::*tipo*': classes locais não podem ser usadas para declarar variáveis de 'extern'|
|C2625 de erro do compilador|'*identificador*': membro de união inválido; digite '*tipo*' é um tipo de referência|
|[Erro do compilador C2626](compiler-error-c2626.md)|'*identificador*': um membro de dados particulares/protegido não é permitido em uma struct/união anônima|
|[Erro do compilador C2627](compiler-error-c2627.md)|'*função*': função membro não permitida em union anônima|
|[Erro do compilador C2628](compiler-error-c2628.md)|'*type1*'seguido por'*type2*' é inválido (você esqueceu um ';'?)|
|C2629 de erro do compilador|'*identificador*': uma struct/união anônima não pode declarar um tipo aninhado|
|[Erro do compilador C2630](compiler-error-c2630.md)|'*símbolo*' encontrado no qual deve ser uma lista separada por vírgulas|
|C2631 de erro do compilador|'*identificador*': uma classe ou enum não pode ser definida em um modelo de alias|
|[Erro do compilador C2632](compiler-error-c2632.md)|'*type1*'seguido por'*type2*' é inválido|
|[Erro do compilador C2633](compiler-error-c2633.md)|'*identificador*': 'inline' é a classe de armazenamento válida somente para construtores|
|[Erro do compilador C2634](compiler-error-c2634.md)|'*classe*::*membro*': ponteiro para membro de referência é inválido|
|[Erro do compilador C2635](compiler-error-c2635.md)|não é possível converter um '*type1*\*' para um '*type2*\*'; conversão de uma classe base virtual está implícita|
|[Erro do compilador C2636](compiler-error-c2636.md)|'*identificador*': ponteiro para membro de referência é inválido|
|[Erro do compilador C2637](compiler-error-c2637.md)|'*identificador*': não é possível modificar ponteiros para membros de dados|
|[Erro do compilador C2638](compiler-error-c2638.md)|'*identificador*': based modificador inválido em ponteiro para membro|
|C2639 de erro do compilador|Obsoleto.|
|[Erro do compilador C2640](compiler-error-c2640.md)|'*identificador*': based modificador inválido em referência|
|C2641 de erro do compilador|Obsoleto.|
|C2642 de erro do compilador|Obsoleto.|
|C2643 de erro do compilador|Obsoleto.|
|C2644 de erro do compilador|Obsoleto.|
|[Erro do compilador C2645](compiler-error-c2645.md)|Nenhum nome qualificado a ponteiro para membro (encontrado ':: *')|
|[Erro do compilador C2646](compiler-error-c2646.md)|uma struct/união anônima em global ou escopo de namespace deve ser declarado estático|
|[Erro do compilador C2647](compiler-error-c2647.md)|'*operador*': não é possível desreferenciar um '*type1*' em um '*type2*'|
|[Erro do compilador C2648](compiler-error-c2648.md)|'*identificador*': uso de membro como parâmetro padrão requer membro static|
|[Erro do compilador C2649](compiler-error-c2649.md)|'*identificador*': não é uma 'classe/struct/união'|
|[Erro do compilador C2650](compiler-error-c2650.md)|'*operador*': não pode ser uma função virtual|
|[Erro do compilador C2651](compiler-error-c2651.md)|'*tipo*': esquerda de ':: ' deve ser uma classe, struct ou união|
|[Erro do compilador C2652](compiler-error-c2652.md)|'*identificador*': construtor de cópia inválido: primeiro parâmetro não deve ser um '*tipo*'|
|[Erro do compilador C2653](compiler-error-c2653.md)|'*identificador*': não é um nome de classe ou namespace|
|[Erro do compilador C2654](compiler-error-c2654.md)|'*identificador*': tentativa de acesso a membro fora de uma função de membro|
|[Erro do compilador C2655](compiler-error-c2655.md)|'*identificador*': definição ou redeclaração inválida no escopo atual|
|[Erro do compilador C2656](compiler-error-c2656.md)|'*função*': função não é permitida como um campo de bits|
|[Erro do compilador C2657](compiler-error-c2657.md)|'*classe*:: *' encontrado no início de uma instrução (você esqueceu de especificar um tipo?)|
|[Erro do compilador C2658](compiler-error-c2658.md)|'*identificador*': redefinição em struct/união anônima|
|[Erro do compilador C2659](compiler-error-c2659.md)|'*operador*': função como operando esquerdo|
|[Erro do compilador C2660](compiler-error-c2660.md)|'*função*': função não tem *número* argumentos|
|[Erro do compilador C2661](compiler-error-c2661.md)|'*função*': nenhuma função sobrecarregada recebe *número* argumentos|
|[Erro do compilador C2662](compiler-error-c2662.md)|'*função*': não é possível converter ponteiro 'this' de '*type1*'para'*type2*'|
|[Erro do compilador C2663](compiler-error-c2663.md)|'*função*': *número* sobrecargas não possuem conversão válida para ponteiro 'this'|
|[Erro do compilador C2664](compiler-error-c2664.md)|'*função*': não é possível converter o argumento *número* de '*type1*'para'*type2*'|
|[Erro do compilador C2665](compiler-error-c2665.md)|'*função*': nenhum do *número* sobrecargas podem converter todos os tipos de argumento|
|[Erro do compilador C2666](compiler-error-c2666.md)|'*função*': *número* sobrecargas possuem conversões similares|
|[Erro do compilador C2667](compiler-error-c2667.md)|'*função*': nenhuma das *número* sobrecargas possuem uma conversão melhor|
|[Erro do compilador C2668](compiler-error-c2668.md)|'*função*': chamada ambígua para função sobrecarregada|
|[Erro do compilador C2669](compiler-error-c2669.md)|função de membro não permitida em union anônima|
|[Erro do compilador C2670](compiler-error-c2670.md)|'*função*': o modelo de função não é possível converter o parâmetro *número* do tipo '*tipo*'|
|[Erro do compilador C2671](compiler-error-c2671.md)|'*função*': funções membro static não possuem ponteiros 'this'|
|[C2672 de erro do compilador](compiler-error-c2672.md)|'*função*': função sobrecarregada não correspondente encontrada|
|[Erro do compilador C2673](compiler-error-c2673.md)|'*função*': funções globais não possuem ponteiros 'this'|
|[Erro do compilador C2674](compiler-error-c2674.md)|uma declaração de generic não é permitida neste contexto|
|[Erro do compilador C2675](compiler-error-c2675.md)|unário '*operador*': '*tipo*' não define este operador ou uma conversão para um tipo aceitável ao operador pré-definido|
|[Erro do compilador C2676](compiler-error-c2676.md)|binário '*operador*': '*tipo*' não define este operador ou uma conversão para um tipo aceitável ao operador pré-definido|
|[Erro do compilador C2677](compiler-error-c2677.md)|binário '*operador*': Nenhum operador global encontrado que receba o tipo '*tipo*' (ou não há nenhuma conversão aceitável)|
|[Erro do compilador C2678](compiler-error-c2678.md)|binário '*operador*': Nenhum operador encontrado que receba um operando esquerdo do tipo '*tipo*' (ou não há nenhuma conversão aceitável)|
|[Erro do compilador C2679](compiler-error-c2679.md)|binário '*operador*': Nenhum operador encontrado que receba um operando à direita do tipo '*tipo*' (ou não há nenhuma conversão aceitável)|
|[Erro do compilador C2680](compiler-error-c2680.md)|'*tipo*': tipo de destino inválido para *conversão*|
|[Erro do compilador C2681](compiler-error-c2681.md)|'*tipo*': tipo de expressão inválido para *conversão*|
|[Erro do compilador C2682](compiler-error-c2682.md)|não é possível usar '*cast*' para converter de'*type1*'para'*type2*'|
|[Erro do compilador C2683](compiler-error-c2683.md)|'*cast*': '*tipo*' não é um tipo polimórfico|
|C2684 de erro do compilador|'*declarador*': funções excluídas e padronizadas não têm suporte nas classes do WinRT/gerenciado|
|C2685 de erro do compilador|'*declarador*': funções excluídas e padronizadas não têm suporte com especificadores de restrição explícitos|
|C2686 de erro do compilador|não é possível sobrecarregar funções membro estáticas e não-estático com os mesmos tipos de parâmetro|
|[Erro do compilador C2687](compiler-error-c2687.md)|'*tipo*': declaração de exceção não pode ser 'void' ou denotar um tipo incompleto ou um ponteiro ou uma referência a um tipo incompleto|
|[Erro do compilador C2688](compiler-error-c2688.md)|'*tipo*::*membro*': retornos covariantes com múltiplas heranças ou herança virtual não tem suportada para funções varargs|
|[Erro do compilador C2689](compiler-error-c2689.md)|'*função*': uma função friend não pode ser definida dentro de uma classe local|
|[Erro do compilador C2690](compiler-error-c2690.md)|'*operador*': não é possível realizar aritmética de ponteiro em uma matriz gerenciada/WinRT|
|[Erro do compilador C2691](compiler-error-c2691.md)|'*tipo*': uma matriz gerenciada/WinRT não pode ter esse tipo de elemento|
|[Erro do compilador C2692](compiler-error-c2692.md)|'*função*': funções totalmente prototipadas são necessárias no compilador C com o ' / clr' opção|
|[Erro do compilador C2693](compiler-error-c2693.md)|'*operador*': comparação inválida para referências a uma matriz gerenciada/WinRT|
|[Erro do compilador C2694](compiler-error-c2694.md)|'*override_function*': função virtual de substituição possui especificação de exceção menos restritiva do que a função de membro virtual da classe base '*base_function*'|
|[Erro do compilador C2695](compiler-error-c2695.md)|'*override_function*': função virtual de substituição difere de '*base_function*' apenas pela convenção de chamada|
|[Erro do compilador C2696](compiler-error-c2696.md)|Não é possível criar um objeto temporário de tipo gerenciado/WinRT '*tipo*'|
|C2697 de erro do compilador|Obsoleto.|
|[Erro do compilador C2698](compiler-error-c2698.md)|a declaração using para '*declaration1*' não pode coexistir com a declaração de using existente para'*declaration2*'|
