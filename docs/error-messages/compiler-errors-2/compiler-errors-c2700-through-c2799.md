---
title: Erros do compilador C2700 a C2799
ms.date: 04/21/2019
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
ms.assetid: 6ee257bb-94bc-42b9-af2c-3c73926afba4
ms.openlocfilehash: 174f6a9c8ec9e44deadfca090ba492cb32d53e9f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87197508"
---
# <a name="compiler-errors-c2700-through-c2799"></a>Erros do compilador C2700 a C2799

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C2700](compiler-error-c2700.md)|'*Type*': não pode ser lançado (use/W4 para obter mais informações)|
|[Erro do compilador C2701](compiler-error-c2701.md)|'*Function*': um template de função/genérico não pode ser um Friend de uma classe local|
|[Erro do compilador C2702](compiler-error-c2702.md)| __except pode não aparecer no bloco de terminação|
|[Erro do compilador C2703](compiler-error-c2703.md)|instrução de __leave ilegal|
|[Erro do compilador C2704](compiler-error-c2704.md)|'*Function*': __va_start intrínseco permitido somente em VarArgs|
|[Erro do compilador C2705](compiler-error-c2705.md)|'*Label*': salto inválido para o escopo '*exception_block*'|
|[Erro do compilador C2706](compiler-error-c2706.md)|__except ilegal sem __try correspondente (faltando '} ' no bloco de __try?)|
|[Erro do compilador C2707](compiler-error-c2707.md)|'*Identifier*': contexto inadequado para função intrínseca|
|[Erro do compilador C2708](compiler-error-c2708.md)|'*Identifier*': o comprimento dos parâmetros reais em bytes difere da chamada ou da referência anterior|
|[Erro do compilador C2709](compiler-error-c2709.md)|'*Identifier*': comprimento de parâmetros formais em bytes difere da declaração anterior|
|[Erro do compilador C2710](compiler-error-c2710.md)|'*Identifier*': ' __declspec (*modificador*) ' só pode ser aplicado a uma função que retorna um ponteiro|
|[Erro do compilador C2711](compiler-error-c2711.md)|'*Function*': esta função não pode ser compilada como gerenciada, considere usar #pragma não gerenciado|
|[Erro do compilador C2712](compiler-error-c2712.md)|Não é possível usar __try em funções que exigem o desenrolamento de objeto|
|[Erro do compilador C2713](compiler-error-c2713.md)|Apenas uma forma de manipulação de exceção permitida por função|
|[Erro do compilador C2714](compiler-error-c2714.md)| `alignof(void)`Não é permitido|
|[Erro do compilador C2715](compiler-error-c2715.md)|'*Type*': não é possível lançar ou capturar este tipo|
|Erro do compilador C2716|Obsoleto.|
|Erro do compilador C2717|Obsoleto.|
|[Erro do compilador C2718](compiler-error-c2718.md)|'*Type*': o parâmetro real com o alinhamento solicitado do *número* não será alinhado|
|[Erro do compilador C2719](compiler-error-c2719.md)|'*Parameter*': o parâmetro formal com o alinhamento solicitado do *número* não será alinhado|
|[Erro do compilador C2720](compiler-error-c2720.md)|'*Identifier*': especificador de classe de armazenamento '*especificador*' inválido em membros|
|[Erro do compilador C2721](compiler-error-c2721.md)|'*especificador*': especificador de classe de armazenamento inválido entre palavra-chave do operador e tipo|
|[Erro do compilador C2722](compiler-error-c2722.md)|'::*Operator*': inválido após comando de operador; Use ' operator *Operator*'|
|[Erro do compilador C2723](compiler-error-c2723.md)|especificador '*Function*': '*especificador*' inválido na definição de função|
|[Erro do compilador C2724](compiler-error-c2724.md)|"*Function*": "Static" não deve ser usado em funções membro definidas no escopo do arquivo|
|[Erro do compilador C2725](compiler-error-c2725.md)|'*Type*': não é possível lançar ou capturar um objeto gerenciado/WinRT por valor ou referência|
|[Erro do compilador C2726](compiler-error-c2726.md)|' gcnew ' só pode ser usado para criar um objeto com tipo gerenciado/WinRT|
|Erro do compilador C2727|Obsoleto.|
|[Erro do compilador C2728](compiler-error-c2728.md)|'*Type*': uma matriz nativa não pode conter este tipo|
|Erro do compilador C2729|Obsoleto.|
|[Erro do compilador C2730](compiler-error-c2730.md)|'*Class*': não pode ser uma classe base de si mesma|
|[Erro do compilador C2731](compiler-error-c2731.md)|'*Function*': a função não pode ser sobrecarregada|
|[Erro do compilador C2732](compiler-error-c2732.md)|a especificação de vinculação contradiz a especificação anterior para '*Function*'|
|[Erro do compilador C2733](compiler-error-c2733.md)|'*Function*': segundo vínculo de C de função sobrecarregada não permitido|
|[Erro do compilador C2734](compiler-error-c2734.md)|'*Identifier*': o objeto ' const ' deve ser inicializado se não for ' extern '|
|[Erro do compilador C2735](compiler-error-c2735.md)|palavra-chave '*keyword*' não é permitida em especificador de tipo de parâmetro formal|
|[Erro do compilador C2736](compiler-error-c2736.md)|palavra-chave '*keyword*' não é permitida em conversão|
|Erro do compilador C2737|'*Identifier*': o objeto ' constexpr ' deve ser inicializado|
|[Erro do compilador C2738](compiler-error-c2738.md)|' operator *Type*': é ambíguo ou não é um membro de '*Class*'|
|[Erro do compilador C2739](compiler-error-c2739.md)|'*Number*': dimensões explícitas de matriz gerenciadas/WinRT devem estar entre 1 e 32|
|Erro do compilador C2740|o valor do operando '*Number*' está fora do intervalo '*lower_bound*  -  *upper_bound*'|
|Erro do compilador C2741|tamanho do quadro muito grande|
|Erro do compilador C2742|Obsoleto.|
|[Erro do compilador C2743](compiler-error-c2743.md)|'*Type*': não é possível capturar um tipo nativo com destruidor __clrcall ou construtor de cópia|
|Erro do compilador C2744|'*Operator*' não é um operador CLR/WinRT válido|
|[Erro do compilador C2745](compiler-error-c2745.md)|'*token*': este token não pode ser convertido em um identificador|
|Erro do compilador C2746|Obsoleto.|
|Erro do compilador C2747|Obsoleto.|
|[Erro do compilador C2748](compiler-error-c2748.md)|a criação da matriz gerenciada/WinRT deve ter o tamanho da matriz ou inicializador de matriz|
|[Erro do compilador C2749](compiler-error-c2749.md)|'*Type*': só é possível lançar ou detectar identificadores em uma classe gerenciada com/CLR: safe|
|[Erro do compilador C2750](compiler-error-c2750.md)|'*Type*': não é possível usar ' New ' no tipo de referência; em vez disso, use ' gcnew '|
|[Erro do compilador C2751](compiler-error-c2751.md)|'*Parameter*': o nome de um parâmetro de função não pode ser qualificado|
|[Erro do compilador C2752](compiler-error-c2752.md)|'*Template*': mais de uma especialização parcial corresponde à lista de argumentos de template|
|[Erro do compilador C2753](compiler-error-c2753.md)|'*Template*': a especialização parcial não pode corresponder à lista de argumentos para o modelo primário|
|[Erro do compilador C2754](compiler-error-c2754.md)|'*Template*': uma especialização parcial não pode ter um parâmetro de template dependente que não seja de tipo|
|[Erro do compilador C2755](compiler-error-c2755.md)|'*Parameter*': parâmetro sem tipo de uma especialização parcial deve ser um identificador simples|
|[Erro do compilador C2756](compiler-error-c2756.md)|'*Template*': argumentos de modelo padrão não permitidos em uma especialização parcial|
|[Erro do compilador C2757](compiler-error-c2757.md)|'*Identifier*': já existe um símbolo com este nome e, portanto, esse nome não pode ser usado como um nome de namespace|
|[Erro do compilador C2758](compiler-error-c2758.md)|'*Member*': um membro de tipo de referência deve ser inicializado|
|Erro do compilador C2759|relatórios de Assembler embutidos: *ERROR_MESSAGE*|
|[Erro do compilador C2760](compiler-error-c2760.md)|erro de sintaxe: '*token1*' esperado não '*token2*'|
|[Erro do compilador C2761](compiler-error-c2761.md)|"*Function*": redeclaração de função membro não permitida|
|[Erro do compilador C2762](compiler-error-c2762.md)|'*Template*': expressão inválida como um argumento de modelo para '*Parameter*'|
|Erro do compilador C2763|'*Template*': uso inválido de um literal de cadeia de caracteres como um argumento de modelo para '*Parameter*'|
|[Erro do compilador C2764](compiler-error-c2764.md)|'*Parameter*': parâmetro de template não usado ou dedutível em '*especialization*' de especialização parcial|
|[Erro do compilador C2765](compiler-error-c2765.md)|'*Function*': uma especialização explícita de um modelo de função não pode ter nenhum argumento padrão|
|[Erro do compilador C2766](compiler-error-c2766.md)|especialização explícita; '*especialização*' já foi definido|
|[Erro do compilador C2767](compiler-error-c2767.md)|incompatibilidade de dimensão de matriz gerenciada/WinRT: argumento (s) de *número* esperado – *número* fornecido|
|[Erro do compilador C2768](compiler-error-c2768.md)|'*Function*': uso ilegal de argumentos de template explícitos|
|Erro do compilador C2769|Não é possível inicializar a chave de uma matriz gerenciada/WinRT em uma lista de inicializadores de base/membro|
|[Erro do compilador C2770](compiler-error-c2770.md)|modelo explícito/argumento genérico inválido (s) para '*Template*'|
|[Erro do compilador C2771](compiler-error-c2771.md)|#import permitido somente em escopo global ou de namespace|
|Erro do compilador C2772|Obsoleto.|
|[Erro do compilador C2773](compiler-error-c2773.md)|#import e #using disponíveis somente no compilador C++|
|[Erro do compilador C2774](compiler-error-c2774.md)|'*Identifier*': nenhum método ' put ' está associado a esta propriedade|
|[Erro do compilador C2775](compiler-error-c2775.md)|'*Identifier*': nenhum método ' Get ' está associado a esta propriedade|
|[Erro do compilador C2776](compiler-error-c2776.md)|somente um método ' Get ' pode ser especificado por Propriedade|
|[Erro do compilador C2777](compiler-error-c2777.md)|somente um método ' put ' pode ser especificado por Propriedade|
|[Erro do compilador C2778](compiler-error-c2778.md)|GUID formado de forma inadequada no __declspec (UUID ())|
|[Erro do compilador C2779](compiler-error-c2779.md)|'*declaração*': métodos de propriedade só podem ser associados a membros de dados não estáticos|
|[Erro do compilador C2780](compiler-error-c2780.md)|'*declaração*': espera argumentos de *número* - *número* fornecido|
|[Erro do compilador C2781](compiler-error-c2781.md)|'*declaração*': espera pelo menos *o número de* argumento de *número* fornecido|
|[Erro do compilador C2782](compiler-error-c2782.md)|'*declaração*': template/parâmetro genérico '*Parameter*' é ambíguo|
|[Erro do compilador C2783](compiler-error-c2783.md)|'*declaração*': não foi possível deduzir o modelo/argumento genérico para '*Identifier*'|
|[Erro do compilador C2784](compiler-error-c2784.md)|'*declaração*': não foi possível deduzir o modelo/argumento genérico para '*type1*' de '*type2*'|
|[Erro do compilador C2785](compiler-error-c2785.md)|'*declaration1*' e '*declaration2*' têm tipos de retorno diferentes|
|[Erro do compilador C2786](compiler-error-c2786.md)|'*Type*': operando inválido para __uuidof|
|[Erro do compilador C2787](compiler-error-c2787.md)|'*Identifier*': nenhum GUID foi associado a este objeto|
|[Erro do compilador C2788](compiler-error-c2788.md)|'*Identifier*': mais de um GUID associado a este objeto|
|Erro do compilador C2789|'*Identifier*': um objeto do tipo qualificado como const deve ser inicializado|
|[Erro do compilador C2790](compiler-error-c2790.md)|' super ': esta palavra-chave só pode ser usada dentro do corpo da função membro da classe|
|[Erro do compilador C2791](compiler-error-c2791.md)|uso ilegal de ' super ': '*Class*' não tem nenhuma classe base|
|[Erro do compilador C2792](compiler-error-c2792.md)|' super ': esta palavra-chave deve ser seguida por ':: '|
|[Erro do compilador C2793](compiler-error-c2793.md)|'*token*': token inesperado após ':: ', identificador ou palavra-chave ' operator ' esperado|
|[Erro do compilador C2794](compiler-error-c2794.md)|'*Identifier*': não é um membro de nenhuma classe base direta ou indireta de '*Class*'|
|[Erro do compilador C2795](compiler-error-c2795.md)|' super::*Identifier*' não é uma função membro|
|Erro do compilador C2796|' ref New ' só pode ser usado para criar uma instância de um tipo de WinRT|
|[Erro do Compilador C2797](compiler-error-c2797.md)|Substituí '*Identifier*': a inicialização de lista dentro da lista de inicializadores de membros ou inicializador de membro de dados não estático não está implementada|
|[Erro do compilador C2798](compiler-error-c2798.md)|' super::*Identifier*' é ambíguo|
|Erro do compilador C2799|'*Identifier*': um objeto do tipo de classe qualificado como const sem um construtor padrão fornecido pelo usuário deve ser inicializado|

## <a name="see-also"></a>Confira também

[Erros e avisos das ferramentas de compilação e do compilador C/C++](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000 a C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)
