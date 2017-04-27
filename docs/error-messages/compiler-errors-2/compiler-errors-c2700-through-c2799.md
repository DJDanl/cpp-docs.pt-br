---
title: C2700 de erros do compilador por meio de C2799 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2716
- C2717
- C2727
- C2729
- C2737
- C2740
- C2741
- C2742
- C2744
- C2746
- C2747
- C2759
- C2763
- C2769
- C2772
- C2789
- C2796
- C2799
helpviewer_keywords:
- C2716
- C2717
- C2727
- C2729
- C2737
- C2740
- C2741
- C2742
- C2744
- C2746
- C2747
- C2759
- C2763
- C2769
- C2772
- C2789
- C2796
- C2799
dev_langs:
- C++
ms.assetid: 6ee257bb-94bc-42b9-af2c-3c73926afba4
caps.latest.revision: 13
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 4bac7b2942f9d72674b8092dc7bf64174dd3c349
ms.openlocfilehash: 02bfc54853aea219b4ff0a08231e73fb53550a37
ms.lasthandoff: 04/24/2017

---
# <a name="compiler-errors-c2700-through-c2799"></a>C2700 de erros do compilador por meio de C2799
Os artigos nesta parte da documentação contêm informações sobre uma subseção de erros do compilador do Visual C++. Você pode acessar as informações aqui ou no **saída** janela no Visual Studio, você pode selecionar um número de erro e, em seguida, escolha a tecla F1.  
  
> [!NOTE]
>  Nem todo [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] erro está documentado no MSDN. Em muitos casos, a mensagem de diagnóstica fornece todas as informações que estão disponíveis. Se você achar que precisa de uma mensagem de erro explicação adicional, você poderá nos informar. Use o formulário de comentários nesta página, ou vá para a barra de menus do Visual Studio e escolha **ajuda**, **relatar um erro**, ou você pode enviar um relatório de sugestão ou um bug em [Microsoft Connect](http://connect.microsoft.com/VisualStudio).  
  
 Você pode obter assistência adicional para erros e avisos nos fóruns públicos do MSDN. O [linguagem Visual C++](http://go.microsoft.com/fwlink/?LinkId=158195) fórum é para perguntas e discussões sobre o [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] sintaxe de linguagem e compilador. O [geral do Visual C++](http://go.microsoft.com/fwlink/?LinkId=158194) fórum é para perguntas sobre [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] que não são abordados em outros fóruns. Você também pode encontrar ajuda sobre erros e avisos sobre [estouro de pilha](http://stackoverflow.com/).  
  
|Erro|Mensagem|  
|-----------|-------------|  
|[Erro do compilador C2700](compiler-error-c2700.md)|'*tipo*': não pode ser lançado (use /W4 para obter mais informações)|  
|[Erro do compilador C2701](compiler-error-c2701.md)|'*função*': um modelo de função/genérico não pode ser um friend de uma classe local|  
|[Erro do compilador C2702](compiler-error-c2702.md)| __except não deve aparecer em bloco de terminação|  
|[Erro do compilador C2703](compiler-error-c2703.md)|instrução __leave inválida|  
|[Erro do compilador C2704](compiler-error-c2704.md)|'*função*': intrínseco va_start permitido apenas em varargs|  
|[Erro do compilador C2705](compiler-error-c2705.md)|'*rótulo*': salto ilegal em '*exception_block*' escopo|  
|[Erro do compilador C2706](compiler-error-c2706.md)|__except inválido sem __try correspondente (faltando '}' no bloco __try?)|  
|[Erro do compilador C2707](compiler-error-c2707.md)|'*identificador*': contexto incorreto para função intrínseca|  
|[Erro do compilador C2708](compiler-error-c2708.md)|'*identificador*': comprimento em bytes de parâmetros reais difere da chamada anterior ou referência|  
|[Erro do compilador C2709](compiler-error-c2709.md)|'*identificador*': comprimento em bytes de parâmetros formais difere da declaração anterior|  
|[Erro do compilador C2710](compiler-error-c2710.md)|'*identificador*': ' declspec (*modificador*)' só pode ser aplicado a uma função que retorne um ponteiro|  
|[Erro do compilador C2711](compiler-error-c2711.md)|'*função*': esta função não pode ser compilado como gerenciado, considere usar #pragma não gerenciado|  
|[Erro do compilador C2712](compiler-error-c2712.md)|Não é possível usar __try em funções que requerem liberação de objeto|  
|[Erro do compilador C2713](compiler-error-c2713.md)|Apenas uma forma de manipulação de exceção permitida por função|  
|[Erro do compilador C2714](compiler-error-c2714.md)|alignof(void) não permitido|  
|[Erro do compilador C2715](compiler-error-c2715.md)|'*tipo*': não é possível usar throw ou catch com este tipo|  
|C2716 de erro do compilador|Obsoleto.|  
|C2717 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2718](compiler-error-c2718.md)|'*tipo*': parâmetro real com o alinhamento de *número* não será alinhado|  
|[Erro do compilador C2719](compiler-error-c2719.md)|'*parâmetro*': parâmetro formal com o alinhamento de *número* não será alinhado|  
|[Erro do compilador C2720](compiler-error-c2720.md)|'*identificador*': '*especificador*' inválido em membros de especificador de classe de armazenamento|  
|[Erro do compilador C2721](compiler-error-c2721.md)|'*especificador*': especificador de classe de armazenamento inválido entre palavra-chave operator e tipo|  
|[Erro do compilador C2722](compiler-error-c2722.md)|'::*operador*': inválido após comando operator; use ' operador *operador*'|  
|[Erro do compilador C2723](compiler-error-c2723.md)|'*função*': '*especificador*' especificador inválido na definição de função|  
|[Erro do compilador C2724](compiler-error-c2724.md)|'*função*': 'static' não deve ser usado em funções membro definidas no escopo de arquivo|  
|[Erro do compilador C2725](compiler-error-c2725.md)|'*tipo*': não é possível lançar ou capturar um objeto gerenciado/WinRT por valor ou referência|  
|[Erro do compilador C2726](compiler-error-c2726.md)|'gcnew' só pode ser usado para criar um objeto com tipo gerenciado/WinRT|  
|C2727 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2728](compiler-error-c2728.md)|'*tipo*': uma matriz nativa não pode conter este tipo|  
|C2729 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2730](compiler-error-c2730.md)|'*classe*': não pode ser uma classe base de si mesma|  
|[Erro do compilador C2731](compiler-error-c2731.md)|'*função*': função não pode ser sobrecarregada|  
|[Erro do compilador C2732](compiler-error-c2732.md)|especificação de vínculo contradiz especificação anterior para '*função*'|  
|[Erro do compilador C2733](compiler-error-c2733.md)|'*função*': segundo vínculo a C de função sobrecarregada não permitido|  
|[Erro do compilador C2734](compiler-error-c2734.md)|'*identificador*': o objeto 'const' deve ser inicializado quando não é 'extern'|  
|[Erro do compilador C2735](compiler-error-c2735.md)|'*palavra-chave*' palavra-chave não é permitida em especificador de tipo de parâmetro formal|  
|[Erro do compilador C2736](compiler-error-c2736.md)|'*palavra-chave*' palavra-chave não é permitida em conversão|  
|C2737 de erro do compilador|'*identificador*': o objeto 'constexpr' deve ser inicializado|  
|[Erro do compilador C2738](compiler-error-c2738.md)|' operador *tipo*': é ambíguo ou não é um membro de '*classe*'|  
|[Erro do compilador C2739](compiler-error-c2739.md)|'*número*': as dimensões de matriz de gerenciados/WinRT explícita devem estar entre 1 e 32|  
|C2740 de erro do compilador|valor de operando '*número*'está fora do intervalo'*lower_bound* - *upper_bound*'|  
|C2741 de erro do compilador|tamanho de quadro muito grande|  
|C2742 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2743](compiler-error-c2743.md)|'*tipo*': não é possível capturar um tipo nativo com clrcall destruidor ou Construtor de cópia|  
|C2744 de erro do compilador|'*operador*' não é um operador CLR/WinRT válido|  
|[Erro do compilador C2745](compiler-error-c2745.md)|'*token*': este token não pode ser convertido em um identificador|  
|C2746 de erro do compilador|Obsoleto.|  
|C2747 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2748](compiler-error-c2748.md)|criação de matriz gerenciados/WinRT deve ter tamanho de matriz ou inicializador de matriz|  
|[Erro do compilador C2749](compiler-error-c2749.md)|'*tipo*': somente pode usar throw ou catch com identificador em uma classe gerenciada com /CLR: safe|  
|[Erro do compilador C2750](compiler-error-c2750.md)|'*tipo*': não é possível usar 'new' na referência de tipo; use 'gcnew' em vez disso|  
|[Erro do compilador C2751](compiler-error-c2751.md)|'*parâmetro*': o nome de um parâmetro de função não pode ser qualificado|  
|[Erro do compilador C2752](compiler-error-c2752.md)|'*modelo*': mais de uma especialização parcial corresponde à lista de argumento de modelo|  
|[Erro do compilador C2753](compiler-error-c2753.md)|'*modelo*': especialização parcial não pode coincidir com a lista de argumentos para template primário|  
|[Erro do compilador C2754](compiler-error-c2754.md)|'*modelo*': uma especialização parcial não pode ter um parâmetro de modelo de tipo não dependentes|  
|[Erro do compilador C2755](compiler-error-c2755.md)|'*parâmetro*': parâmetro de tipo não de uma especialização parcial deve ser um identificador simples|  
|[Erro do compilador C2756](compiler-error-c2756.md)|'*modelo*': não é permitidos em uma especialização parcial de argumentos de template padrão|  
|[Erro do compilador C2757](compiler-error-c2757.md)|'*identificador*': um símbolo com este nome já existe e, portanto, esse nome não pode ser usado como um nome de namespace|  
|[Erro do compilador C2758](compiler-error-c2758.md)|'*membro*': um membro de tipo de referência deve ser inicializado|  
|C2759 de erro do compilador|relatórios do assembler embutido: *error_message*|  
|[Erro do compilador C2760](compiler-error-c2760.md)|Erro de sintaxe: esperado '*token1*'not'*token2*'|  
|[Erro do compilador C2761](compiler-error-c2761.md)|'*função*': redeclaração de função de membro não permitida|  
|[Erro do compilador C2762](compiler-error-c2762.md)|'*modelo*': expressão inválida como um argumento de template para '*parâmetro*'|  
|C2763 de erro do compilador|'*modelo*': uso inválido de uma cadeia de caracteres literal como um argumento de template para '*parâmetro*'|  
|[Erro do compilador C2764](compiler-error-c2764.md)|'*parâmetro*': parâmetro de modelo não usado ou dedutível em especialização parcial '*especialização*'|  
|[Erro do compilador C2765](compiler-error-c2765.md)|'*função*': uma especialização explícita de um modelo de função não pode ter argumentos padrão|  
|[Erro do compilador C2766](compiler-error-c2766.md)|especialização explícita; '*especialização*' já foi definido|  
|[Erro do compilador C2767](compiler-error-c2767.md)|incompatibilidade de dimensões da matriz gerenciados/WinRT: esperado *número* argumentos - *número* fornecido|  
|[Erro do compilador C2768](compiler-error-c2768.md)|'*função*': uso inválido de argumentos de template explícitos|  
|C2769 de erro do compilador|Você não é possível chave inicializar uma matriz gerenciada/WinRT em uma lista de inicializadores de base/membro|  
|[Erro do compilador C2770](compiler-error-c2770.md)|argumentos de modelo/generic explícita inválida para '*modelo*'|  
|[Erro do compilador C2771](compiler-error-c2771.md)|#importação permitido somente em global ou escopo de namespace|  
|C2772 de erro do compilador|Obsoleto.|  
|[Erro do compilador C2773](compiler-error-c2773.md)|#Importar e #using disponíveis apenas em compilador C++|  
|[Erro do compilador C2774](compiler-error-c2774.md)|'*identificador*': nenhum método 'put' está associado esta propriedade|  
|[Erro do compilador C2775](compiler-error-c2775.md)|'*identificador*': nenhum método 'get' está associado esta propriedade|  
|[Erro do compilador C2776](compiler-error-c2776.md)|apenas um método 'get' pode ser especificado por propriedade|  
|[Erro do compilador C2777](compiler-error-c2777.md)|apenas um método 'put' pode ser especificado por propriedade|  
|[Erro do compilador C2778](compiler-error-c2778.md)|GUID formado de modo inadequado em __declspec(uuid())|  
|[Erro do compilador C2779](compiler-error-c2779.md)|'*declaração*': métodos de propriedade só podem ser associados a membros de dados não estático|  
|[Erro do compilador C2780](compiler-error-c2780.md)|'*declaração*': espera *número* argumentos - *número* fornecido|  
|[Erro do compilador C2781](compiler-error-c2781.md)|'*declaração*': espera pelo menos *número* argumento - *número* fornecido|  
|[Erro do compilador C2782](compiler-error-c2782.md)|'*declaração*': parâmetro de modelo/generic '*parâmetro*' é ambíguo|  
|[Erro do compilador C2783](compiler-error-c2783.md)|'*declaração*': não foi possível deduzir argumento de modelo/generic para '*identificador*'|  
|[Erro do compilador C2784](compiler-error-c2784.md)|'*declaração*': não foi possível deduzir argumento de modelo/generic para '*type1*'from'*type2*'|  
|[Erro do compilador C2785](compiler-error-c2785.md)|'*declaration1*'e'*declaration2*' têm tipos diferentes de retorno|  
|[Erro do compilador C2786](compiler-error-c2786.md)|'*tipo*': operando inválido para uuidof|  
|[Erro do compilador C2787](compiler-error-c2787.md)|'*identificador*': nenhum GUID foi associado este objeto|  
|[Erro do compilador C2788](compiler-error-c2788.md)|'*identificador*': mais de um GUID associado a este objeto|  
|C2789 de erro do compilador|'*identificador*': um objeto do tipo qualificado como const deve ser inicializado|  
|[Erro do compilador C2790](compiler-error-c2790.md)|'super': esta palavra-chave só pode ser usada dentro do corpo de função membro de classe|  
|[Erro do compilador C2791](compiler-error-c2791.md)|Uso inválido de 'super': '*classe*' não tem nenhuma classe base|  
|[Erro do compilador C2792](compiler-error-c2792.md)|'super': esta palavra-chave deve ser seguida por '::'|  
|[Erro do compilador C2793](compiler-error-c2793.md)|'*token*': token inesperado após ':: ', identificador ou palavra-chave 'operator' esperados|  
|[Erro do compilador C2794](compiler-error-c2794.md)|'*identificador*': não é um membro de qualquer classe base direta ou indireta de '*classe*'|  
|[Erro do compilador C2795](compiler-error-c2795.md)|' super::*identificador*' não é uma função de membro|  
|C2796 de erro do compilador|'ref new' só pode ser usado para criar uma instância de um tipo de WinRT|  
|[Erro do compilador C2797](compiler-error-c2797.md)|(Obsoleto) '*identificador*': lista de inicializações dentro da lista de inicializador de membro ou inicializador de membro de dados não estático não está implementada.|  
|[Erro do compilador C2798](compiler-error-c2798.md)|' super::*identificador*' é ambíguo|  
|C2799 de erro do compilador|'*identificador*': um objeto do tipo de classe qualificado como const sem um construtor padrão fornecido pelo usuário deve ser inicializado|  

