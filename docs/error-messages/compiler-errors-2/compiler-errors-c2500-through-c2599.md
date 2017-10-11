---
title: C2500 de erros do compilador por meio de C2599 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2501
- C2508
- C2515
- C2519
- C2520
- C2522
- C2525
- C2527
- C2536
- C2538
- C2539
- C2546
- C2547
- C2559
- C2560
- C2564
- C2565
- C2576
- C2578
- C2580
- C2590
- C2591
- C2595
- C2596
helpviewer_keywords:
- C2501
- C2508
- C2515
- C2519
- C2520
- C2522
- C2525
- C2527
- C2536
- C2538
- C2539
- C2546
- C2547
- C2559
- C2560
- C2564
- C2565
- C2576
- C2578
- C2580
- C2590
- C2591
- C2595
- C2596
dev_langs:
- C++
ms.assetid: a869aaed-e9f6-49e3-b273-00ea7f45bed7
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 31df41ea122c762428e153fe406efba1175c64f2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-errors-c2500-through-c2599"></a>C2500 de erros do compilador por meio de C2599
Os artigos nesta parte da documentação contêm informações sobre uma subseção de erros do compilador do Visual C++. Você pode acessar as informações aqui ou no **saída** janela no Visual Studio, você pode selecionar um número de erro e, em seguida, escolha a tecla F1.  
  
> [!NOTE]
>  Nem todo [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] erro está documentado no MSDN. Em muitos casos, a mensagem de diagnóstica fornece todas as informações que estão disponíveis. Se você achar que precisa de uma mensagem de erro explicação adicional, você poderá nos informar. Use o formulário de comentários nesta página, ou vá para a barra de menus do Visual Studio e escolha **ajuda**, **relatar um erro**, ou você pode enviar um relatório de sugestão ou um bug no [Microsoft Connect](http://connect.microsoft.com/VisualStudio).  
  
 Você pode obter assistência adicional para erros e avisos nos fóruns públicos do MSDN. O [linguagem Visual C++](http://go.microsoft.com/fwlink/?LinkId=158195) fórum é para perguntas e discussões sobre o [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] sintaxe de linguagem e compilador. O [geral do Visual C++](http://go.microsoft.com/fwlink/?LinkId=158194) fórum é para perguntas sobre [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] que não são abordados em outros fóruns. Você também pode encontrar ajuda sobre erros e avisos sobre [estouro de pilha](http://stackoverflow.com/).  
  
|Erro|Mensagem|  
|-----------|-------------|  
|[Erro do compilador C2500](compiler-error-C2500.md)|'*identifier1*': '*identifier2*' já é uma classe base direta|  
|C2501 de erro do compilador|'*identificador*': ' declspec (*especificador*)' só pode ser aplicada a estruturas, uniões, classes ou membros de campo de bits sem sinal|  
|[Erro do compilador C2502](compiler-error-C2502.md)|'*identificador*': muitos modificadores de acesso na classe base|  
|[Erro do compilador C2503](compiler-error-C2503.md)|'*classe*': classes de base não podem conter matrizes de tamanho zero|  
|[Erro do compilador C2504](compiler-error-C2504.md)|'*classe*': classe base indefinida|  
|[Erro do compilador C2505](compiler-error-C2505.md)|'*símbolo*': ' declspec (*especificador*)' só pode ser aplicado a declarações ou definições de objetos globais ou membros de dados estáticos|  
|[Erro do compilador C2506](compiler-error-C2506.md)|'*membro*': ' declspec (*especificador*)' não pode ser aplicado a este símbolo|  
|[Erro do compilador C2507](compiler-error-C2507.md)|'*identificador*': muitos modificadores virtual na classe base|  
|C2508 de erro do compilador|'*identificador*': '\_\_declspec (*specifier1*)' não pode ser combinado com '\_\_declspec (*specifier2*)'|  
|[Erro do compilador C2509](compiler-error-C2509.md)|'*identificador*': função membro não declarada em '*classe*'|  
|[Erro do compilador C2510](compiler-error-C2510.md)|'*identificador*': esquerda de ':: ' deve ser uma classe/struct/união|  
|[Erro do compilador C2511](compiler-error-C2511.md)|'*identificador*': membro função sobrecarregada não encontrada em '*classe*'|  
|[Erro do compilador C2512](compiler-error-C2512.md)|'*identificador*': nenhum construtor padrão apropriado disponível|  
|[Erro do compilador C2513](compiler-error-C2513.md)|' * tipo ': nenhuma variável declarada antes de '='|  
|[Erro do compilador C2514](compiler-error-C2514.md)|'*classe*': classe não possui construtores|  
|C2515 de erro do compilador|'*identificador*': 'vtguard' só pode ser aplicado a declarações de classe ou definições|  
|[Erro do compilador C2516](compiler-error-C2516.md)|'*classe*': não é uma classe base válida|  
|[Erro do compilador C2517](compiler-error-C2517.md)|'*identificador*': direita de ':: ' é indefinido|  
|[Erro do compilador C2518](compiler-error-C2518.md)|palavra-chave '*palavra-chave*' inválida na lista de classes base; ignorada|  
|C2519 de erro do compilador|'*identificador*': atributos WinRT só podem conter campos públicos|  
|C2520 de erro do compilador|'*classe*': nenhum construtor não explícito disponível para conversão implícita|  
|[Erro do compilador C2521](compiler-error-C2521.md)|um destruidor/finalizador não tem nenhum argumento|  
|C2522 de erro do compilador|'*identificador*': identificador de sobrecarga não pode ser usado em '*identifier1*'pois ele já foi especificado em'*identifier2*'|  
|[Erro do compilador C2523](compiler-error-C2523.md)|'*classe*:: ~*identificador*': incompatibilidade de marca de destruidor/finalizador|  
|[Erro do compilador C2524](compiler-error-C2524.md)|'*identificador*': um destruidor/finalizador deve ter uma lista de parâmetros 'void'|  
|C2525 de erro do compilador|'*identificador*': O parâmetro '*identifier1*'chamado'*identifier2*' na base de função e devem ser iguais em uma implementação pública|  
|[Erro do compilador C2526](compiler-error-C2526.md)|'*identifier1*': função de vínculo a C não pode retornar classe de C++*identifier2*'|  
|C2527 de erro do compilador|'*identificador*': DefaultOverload não pode ser especificado no '*function1*'e'*function2*'. Remova uma especificação ou renomeie a função durante a implementação|  
|[Erro do compilador C2528](compiler-error-C2528.md)|'*identificador*': ponteiro para referência é inválido|  
|[Erro do compilador C2529](compiler-error-C2529.md)|'*identificador*': a referência é inválida|  
|[Erro do compilador C2530](compiler-error-C2530.md)|'*identificador*': referências devem ser inicializadas|  
|[Erro do compilador C2531](compiler-error-C2531.md)|'*identificador*': referência a um bit ilegal de campo|  
|[Erro do compilador C2532](compiler-error-C2532.md)|'*identificador*': modificador inválido para referência|  
|[Erro do compilador C2533](compiler-error-C2533.md)|'*identificador*': construtores não permitidas um tipo de retorno|  
|[Erro do compilador C2534](compiler-error-C2534.md)|'*identificador*': construtor não pode retornar um valor|  
|[Erro do compilador C2535](compiler-error-C2535.md)|'*identificador*': função de membro já definida ou declarada|  
|C2536 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2537](compiler-error-C2537.md)|'*especificador*': especificação de vínculo inválida|  
|C2538 de erro do compilador|Obsoleto.|  
|C2539 de erro do compilador|Obsoleto.|
|[Erro do compilador C2540](compiler-error-C2540.md)|expressão não constante como limite de matriz|  
|[Erro do compilador C2541](compiler-error-C2541.md)|'*identificador*': não é possível excluir objetos que não são ponteiros|  
|[Erro do compilador C2542](compiler-error-C2542.md)|'*identificador*': o objeto de classe não possui construtor para inicialização|  
|[Erro do compilador C2543](compiler-error-C2543.md)|esperado ']' para o operador '[]'|  
|[Erro do compilador C2544](compiler-error-C2544.md)|esperado ')' para o operador '()'|  
|[Erro do compilador C2545](compiler-error-C2545.md)|'*operador*': não é possível encontrar operador sobrecarregado|  
|C2546 de erro do compilador|'*identificador*': quando um tipo é definido em um PIA e um não PIA, o PIA deve ser referenciado primeiro|  
|C2547 de erro do compilador|'*identificador*': todos os parâmetros de um método público devem ser nomeados explicitamente na declaração|  
|[Erro do compilador C2548](compiler-error-C2548.md)|'*função*': faltando parâmetro padrão para o parâmetro *parâmetro*|  
|[Erro do compilador C2549](compiler-error-C2549.md)|conversão definida pelo usuário não é possível especificar um tipo de retorno|  
|[Erro do compilador C2550](compiler-error-C2550.md)|'*identificador*': listas de inicializadores de construtor só são permitidas em definições de construtor|  
|[Erro do compilador C2551](compiler-error-C2551.md)|' void *' precisa de conversão explícita do tipo|  
|[Erro do compilador C2552](compiler-error-C2552.md)|'*identificador*': não não possível inicializar não agregações com uma lista de inicializadores|  
|[Erro do compilador C2553](compiler-error-C2553.md)|'*tipo* *derived_class*::*função*': tipo de retorno de função virtual de substituição difere de '*tipo* *base_ classe*::*função*'|  
|[Erro do compilador C2555](compiler-error-C2555.md)|'*derived_class*::*função*': função virtual de substituição retornar tipo difere e não é covariante com '*base_class*::*função*'|  
|[Erro do compilador C2556](compiler-error-C2556.md)|'*type1* *classe*::*função*': função sobrecarregada difere apenas pelo tipo de retorno de '*type2* *declasse*::*função*'|  
|[Erro do compilador C2557](compiler-error-C2557.md)|'*identificador*': membros private e protected não podem ser inicializados sem um construtor|  
|[Erro do compilador C2558](compiler-error-C2558.md)|classe*classe*': nenhum construtor de cópia disponível ou Construtor de cópia está declarado como 'explicit'|  
|C2559 de erro do compilador|'*identificador*': não é possível sobrecarregar uma função de membro sem o qualificador de referência com uma função de membro com o qualificador de referência|  
|C2560 de erro do compilador|'*identificador*': não é possível sobrecarregar uma função de membro com o qualificador de referência com uma função de membro sem o qualificador de referência|  
|[Erro do compilador C2561](compiler-error-C2561.md)|'*função*': função deve retornar um valor|  
|[Erro do compilador C2562](compiler-error-C2562.md)|'*função*': retornando um valor de função 'void'|  
|[Erro do compilador C2563](compiler-error-C2563.md)|incompatibilidade na lista de parâmetros formais|  
|C2564 de erro do compilador|Obsoleto.|  
|C2565 de erro do compilador|'*identificador*': qualificador de referência é inválido para construtores/destrutores|  
|[Erro do compilador C2566](compiler-error-C2566.md)|função sobrecarregada em expressão condicional|  
|[Erro do compilador C2567](compiler-error-C2567.md)|não é possível abrir metadados '*filename*', *possible_reason*|  
|[Erro do compilador C2568](compiler-error-C2568.md)|'*identificador*': não é possível resolver sobrecarga de função|  
|[Erro do compilador C2569](compiler-error-C2569.md)|'*identificador*': enum/union não pode ser usado como uma classe base|  
|[Erro do compilador C2570](compiler-error-C2570.md)|'*identificador*': union não pode possuir classes base|  
|[Erro do compilador C2571](compiler-error-C2571.md)|'*identificador*': função virtual não pode estar em union '*união*'|  
|[Erro do compilador C2572](compiler-error-C2572.md)|'*função*': redefinição do argumento padrão: parâmetro *número*|  
|[Erro do compilador C2573](compiler-error-C2573.md)|'*classe*': não é possível excluir ponteiros para objetos desse tipo, a classe não tem nenhuma sobrecarga de não posicionamento para 'operator delete'. Uso:: excluir ou adicionar 'operador delete(void*)' para a classe|  
|[Erro do compilador C2574](compiler-error-C2574.md)|'*destruidor*': não pode ser declarado como static|  
|[Erro do compilador C2575](compiler-error-C2575.md)|'*identificador*': apenas funções de membro e bases de dados podem ser virtuais|  
|C2576 de erro do compilador|'*identificador*': não é possível introduzir um novo método virtual como 'public'. Considere tornar o método não virtual ou altere a acessibilidade para 'interna' ou 'protected private'|  
|[Erro do compilador C2577](compiler-error-C2577.md)|'*identificador*': um destruidor/finalizador não pode ter um tipo de retorno|  
|C2578 de erro do compilador|'*classe*': tipo não pode ter um 'protected' ou 'público protegido' construtor|  
|[Erro do compilador C2579](compiler-error-C2579.md)|não é possível resolver tipo *tipo* (*deslocamento*). É esperado no *filename*|  
|C2580 de erro do compilador|'*identificador*': não são permitidas várias versões de um padrão especial de funções de membro|  
|[Erro do compilador C2581](compiler-error-C2581.md)|'*tipo*': estático ' operador =' função é inválida|  
|[Erro do compilador C2582](compiler-error-C2582.md)|' operador *operador*'função não está disponível em'*tipo*'|  
|[Erro do compilador C2583](compiler-error-C2583.md)|'*identificador*': ' const/volatile' ponteiro 'this' é inválido para construtores/destrutores|  
|[Erro do compilador C2584](compiler-error-C2584.md)|'*classe*': base direta '*base_class2*' é inacessível; já é uma base de '*base_class1*'|  
|[Erro do compilador C2585](compiler-error-C2585.md)|conversão explícita para '*tipo*' é ambíguo|  
|[Erro do compilador C2586](compiler-error-C2586.md)|sintaxe incorreta de conversão definida pelo usuário: vias indiretas inválidas|  
|[Erro do compilador C2587](compiler-error-C2587.md)|'*identificador*': uso inválido de variável local como parâmetro padrão|  
|[Erro do compilador C2588](compiler-error-C2588.md)|':: ~*identificador*': destruidor/finalizador global inválido|  
|[Erro do compilador C2589](compiler-error-C2589.md)|'*identificador*': token inválido no lado direito de ':: '|  
|C2590 de erro do compilador|'*identificador*': apenas um construtor pode ter uma lista de inicializadores de base/membro|  
|C2591 de erro do compilador|ExclusiveTo não é possível usar '*tipo*' como um argumento. Somente uma 'classe ref' é um argumento válido|  
|[Erro do compilador C2592](compiler-error-C2592.md)|'*classe*': '*base_class2*'é herdado de'*base_class1*' e não pode ser especificado novamente|  
|[Erro do compilador C2593](compiler-error-C2593.md)|' operador *identificador*' é ambíguo|  
|[Erro do compilador C2594](compiler-error-C2594.md)|'*operador*': conversões ambíguas de '*type1*'para'*type2*'|  
|C2595 de erro do compilador|'*identificador*' WinRT de um tipo de atributo deve ser fechado.|  
|C2596 de erro do compilador|'*identificador*' WinRT de um campo de atributo só pode ser um 'public enum class', 'int', 'unsigned int', 'bool', 'Platform:: Type', 'Platform:: String' ou 'Windows:: Foundation:: HResult'|  
|[Erro do compilador C2597](compiler-error-C2597.md)|referência inválida para membro não estático '*identificador*'|  
|[Erro do compilador C2598](compiler-error-C2598.md)|especificação de vinculação deve estar no escopo global|  
|[Erro do compilador C2599](compiler-error-C2599.md)|'*identificador*': a declaração de encaminhamento de uma enum WinRT gerenciado/não é permitida|  
