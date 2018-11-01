---
title: Erros do compilador C2900 a C2999
ms.date: 11/17/2017
f1_keywords:
- C2900
- C2901
- C2905
- C2907
- C2915
- C2916
- C2922
- C2924
- C2925
- C2926
- C2938
- C2949
- C2950
- C2954
- C2956
- C2960
- C2961
- C2963
- C2964
- C2965
- C2966
- C2967
- C2968
- C2972
- C2980
- C2981
- C2982
- C2983
- C2984
- C2985
- C2986
- C2987
- C2997
- C2999
helpviewer_keywords:
- C2900
- C2901
- C2905
- C2907
- C2915
- C2916
- C2922
- C2924
- C2925
- C2926
- C2938
- C2949
- C2950
- C2954
- C2956
- C2960
- C2961
- C2963
- C2964
- C2965
- C2966
- C2967
- C2968
- C2972
- C2980
- C2981
- C2982
- C2983
- C2984
- C2985
- C2986
- C2987
- C2997
- C2999
ms.assetid: e3440738-e11b-4878-9ae3-6bc6c53ba461
ms.openlocfilehash: 4d430d1d446147c662f7f6405185aee75d95bc0b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50466882"
---
# <a name="compiler-errors-c2900-through-c2999"></a>Erros do compilador C2900 a C2999

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|Erro do compilador C2900|'*declarador*': modelos de função de membro em classes do WinRT devem ser 'private', 'interna' ou 'protected private'|
|C2901 de erro do compilador|'*identificador*': uma interface genérica ou representante não pode ser público|
|[Erro do compilador C2902](compiler-error-c2902.md)|'*token*': inesperado token seguinte 'modelo/genérico', identificador esperado|
|[Erro do compilador C2903](compiler-error-c2903.md)|'*identificador*': símbolo não é um modelo de classe/genérico nem um modelo de função/genérico|
|[Erro do compilador C2904](compiler-error-c2904.md)|'*identificador*': nome já usado para um modelo no escopo atual|
|C2905 de erro do compilador|Obsoleto.|
|[Erro do compilador C2906](compiler-error-c2906.md)|'*modelo*': especialização explícita requer 'modelo <>'|
|C2907 de erro do compilador|Registre-se o argumento '*número*' não especifica o número de registro válido|
|[Erro do compilador C2908](compiler-error-c2908.md)|especialização explícita; '*modelo*' já foi instanciado|
|[Erro do compilador C2909](compiler-error-c2909.md)|'*identificador*': instanciação explícita de modelo de função requer tipo de retorno|
|[Erro do compilador C2910](compiler-error-c2910.md)|'*função*': não pode ser explicitamente especializado|
|[Erro do compilador C2911](compiler-error-c2911.md)|'*membro*': não pode ser declarada ou definida no escopo atual|
|[Erro do compilador C2912](compiler-error-c2912.md)|especialização explícita '*declaração*' não é uma especialização de um modelo de função|
|[Erro do compilador C2913](compiler-error-c2913.md)|especialização explícita; '*declaração*' não é uma especialização de um modelo de classe|
|[Erro do compilador C2914](compiler-error-c2914.md)|'*identificador*': não é possível deduzir argumento de modelo/genérico como argumento da função é ambíguo|
|C2915 de erro do compilador|'*identificador*': '*tipo*' não pode ser usado diretamente na superfície publicada de um tipo WinRT. Use ' Platform:: Object ^' em vez disso, para passar esse tipo|
|C2916 de erro do compilador|'*identificador*': [FlagsAttribute] (somente) deve ser especificado em uma enumeração pública com um 'unsigned int' tipo subjacente|
|[Erro do compilador C2917](compiler-error-c2917.md)|'*identificador*': parâmetro de modelo inválido|
|[Erro do compilador C2918](compiler-error-c2918.md)|'*identificador*': propriedades indexadas não podem ser usadas na superfície publicada de um tipo WinRT|
|[Erro do compilador C2919](compiler-error-c2919.md)|'*tipo*': operadores não podem ser usados na superfície publicada de um tipo WinRT|
|[Erro do compilador C2920](compiler-error-c2920.md)|redefinição: '*tipo*': classe de modelo/genérico já foi declarado como*declaração*'|
|[Erro do compilador C2921](compiler-error-c2921.md)|redefinição: '*tipo*': classe de modelo/genérico está sendo declarada novamente como*declaração*'|
|C2922 de erro do compilador|'*interface*': WinRT uma interface não pode conter membros estáticos|
|[Erro do compilador C2923](compiler-error-c2923.md)|'*tipo*': '*identificador*'não é um argumento de tipo de modelo/genérico válido para o parâmetro'*parâmetro*'|
|C2924 de erro do compilador|argumento de rotina Interrupt não no R2|
|C2925 de erro do compilador|rotina Interrupt não é possível usar ponto flutuante|
|C2926 de erro do compilador|'*identificador*': um inicializador de membro padrão não é permitido para um membro de um struct anônimo dentro de uma união|
|[Erro do compilador C2927](compiler-error-c2927.md)|'*identificador*': um modelo de função deve ser chamado com pelo menos um argumento|
|[Erro do compilador C2928](compiler-error-c2928.md)|instanciação explícita; '*identificador*'não é uma função ou um membro de dados estáticos da classe de modelo'*classe*'|
|[Erro do compilador C2929](compiler-error-c2929.md)|'*declarador*': instanciação explícita; explicitamente não pode forçar e suprimir instanciação de membro de classe de modelo|
|[Erro do compilador C2930](compiler-error-c2930.md)|'*classe*': template-id/id genérica é redefinido como um enumerador de ' enum *identificador*'|
|[Erro do compilador C2931](compiler-error-c2931.md)|'*class1*': template-id/id genérica é redefinida como uma função de membro de '*class2*'|
|[Erro do compilador C2932](compiler-error-c2932.md)|'*tipo*': template-id/id genérica é redefinido como um membro de dados de '*identificador*'|
|[Erro do compilador C2933](compiler-error-c2933.md)|'*tipo*': template-id/id genérica é redefinido como um membro typedef da '*identificador*'|
|[Erro do compilador C2934](compiler-error-c2934.md)|'*tipo*': template-id/id genérico redefinidos como aninhado '*item*'de'*identificador*'|
|[Erro do compilador C2935](compiler-error-c2935.md)|'*tipo*': template-id/id genérica é redefinida como uma função global|
|[Erro do compilador C2936](compiler-error-c2936.md)|'*tipo*': template-id/id genérica é redefinida como uma variável de dados globais|
|[Erro do compilador C2937](compiler-error-c2937.md)|'*tipo*': template-id/id genérica é redefinido como um typedef global|
|C2938 de erro do compilador|'*identificador*': Falha ao especializar o modelo de alias|
|[Erro do compilador C2939](compiler-error-c2939.md)|'*tipo*': template-id/id genérica é redefinida como uma variável de dados local|
|[Erro do compilador C2940](compiler-error-c2940.md)|'*tipo*': template-id/id genérica é redefinido como um typedef de local|
|[Erro do compilador C2941](compiler-error-c2941.md)|'*tipo*': template-id/id genérica é redefinido como um local '*item*'|
|[Erro do compilador C2942](compiler-error-c2942.md)|'*tipo*': template-id/id genérico redefinidos como um argumento formal de uma função|
|[Erro do compilador C2943](compiler-error-c2943.md)|'*tipo*': template-id/id genérico redefinidos como um argumento de tipo de um modelo|
|[Erro do compilador C2944](compiler-error-c2944.md)|'*tipo*': template-id/id genérico redefinidos como um argumento de valor de um modelo|
|[Erro do compilador C2945](compiler-error-c2945.md)|instanciação explícita não faz referência a uma especialização de classe de modelo|
|[Erro do compilador C2946](compiler-error-c2946.md)|instanciação explícita; '*tipo*' não é uma especialização de classe de modelo|
|[Erro do compilador C2947](compiler-error-c2947.md)|esperando ' >' para encerrar os argumentos de modelo, encontrado '*token*'|
|[Erro do compilador C2948](compiler-error-c2948.md)|instanciação explícita; especificador de classe de armazenamento '*especificador*' não permitido em especialização|
|C2949 de erro do compilador|thread_local não é suportado com /kernel|
|C2950 de erro do compilador|Obsoleto.|
|[Erro do compilador C2951](compiler-error-c2951.md)|declarações de modelo/genérico só são permitidas no namespace global, ou escopo de classe|
|[Erro do compilador C2952](compiler-error-c2952.md)|'*declaração*': declaração de modelo/genérico faltando lista de parâmetros de modelo/genérico|
|[Erro do compilador C2953](compiler-error-c2953.md)|'*tipo*': template de classe já foi definido|
|C2954 de erro do compilador|argumento de palavra de instrução fora do intervalo|
|[Erro do compilador C2955](compiler-error-c2955.md)|'*tipo*': lista de argumentos de modelo/genérico requer o uso do modelo de classe/genérico|
|C2956 de erro do compilador|desalocação dimensionada função 'operator delete (void *, size_t)' deve ser escolhida como a função de desalocação de posicionamento.|
|[Erro do compilador C2957](compiler-error-c2957.md)|'*token*': delimitador esquerdo inválido: esperado ' <'|
|[Erro do compilador C2958](compiler-error-c2958.md)|à esquerda *delimitador* encontrado em '*arquivo*(*line_number*)' não foi correspondido corretamente|
|[Erro do compilador C2959](compiler-error-c2959.md)|uma classe genérica ou uma função não pode ser um membro de um modelo|
|C2960 de erro do compilador|Obsoleto.|
|C2961 de erro do compilador|'*função*': instanciações explícitas inconsistentes, uma instanciação explícita anterior não especificou '*argumento*'|
|[Erro do compilador C2962](compiler-error-c2962.md)|Erro de sintaxe: '*token*': esperado da definição de função de membro de classe de modelo para terminar com '}'|
|C2963 de erro do compilador|Obsoleto.|
|C2964 de erro do compilador|Obsoleto.|
|C2965 de erro do compilador|declspec (*especificador*) não é suportado com /kernel|
|C2966 de erro do compilador|'*identifier1*': deve ter o mesmo __declspec(code_seg(...)) como sua classe base*identifier2*'|
|C2967 de erro do compilador|'*identificador*': uma função virtual de substituição deve ter o mesmo __declspec(code_seg(...)) como uma função virtual substituída|
|C2968 de erro do compilador|'*identificador*': declaração de alias recursiva|
|[Erro do compilador C2969](compiler-error-c2969.md)|Erro de sintaxe: '*token*': esperado da definição de função de membro para terminar com '}'|
|[Erro do compilador C2970](compiler-error-c2970.md)|'*tipo*': parâmetro de modelo '*parâmetro*': '*argumento*': uma expressão envolvendo objetos com vinculação interna não pode ser usada como um argumento sem tipo|
|[Erro do compilador C2971](compiler-error-c2971.md)|'*tipo*': parâmetro de modelo '*parâmetro*': '*argumento*': uma variável com duração de armazenamento não estática não pode ser usada como um argumento sem tipo|
|C2972 de erro do compilador|'*tipo*': parâmetro de modelo '*parâmetro*': o tipo de argumento sem tipo é inválido|
|[Erro do compilador C2973](compiler-error-c2973.md)|'*modelo*': argumento de template inválido '*número*'|
|[Erro do compilador C2974](compiler-error-c2974.md)|'*tipo*': argumento de modelo/genérico inválido para '*parâmetro*', tipo esperado|
|[Erro do compilador C2975](compiler-error-c2975.md)|'*tipo*': argumento de template inválido para '*parâmetro*', esperada expressão constante de tempo de compilação|
|[Erro do compilador C2976](compiler-error-c2976.md)|'*tipo*': poucos argumentos de modelo/genérico|
|[Erro do compilador C2977](compiler-error-c2977.md)|'*tipo*': muitos argumentos de modelo/genérico|
|[Erro do compilador C2978](compiler-error-c2978.md)|Erro de sintaxe: esperado '*palavrachave1*'ou'*palavrachave2*'; tipo encontrado'*tipo*'; tipo de não parâmetros não são suportados em genéricos|
|[Erro do compilador C2979](compiler-error-c2979.md)|especializações explícitas não têm suporte em genéricos|
|C2980 de erro do compilador|Tratamento de exceções C++ não é suportado com /kernel|
|C2981 de erro do compilador|o formulário dinâmico de '*palavra-chave*' não é suportado com /kernel|
|C2982 de erro do compilador|'*declaração*': __declspec(code_seg(...)) diferentes usados: era '*identifier1*'agora'*identifier2*'|
|C2983 de erro do compilador|'*declaração*': todas as declarações devem ter um __declspec(code_seg(...)) idênticos|
|C2984 de erro do compilador|Obsoleto.|
|C2985 de erro do compilador|'*argumento*': o argumento __declspec(code_seg(...)) deve ser uma seção de texto|
|C2986 de erro do compilador|'*identificador*': __declspec(code_seg(...)) só pode ser aplicado a uma classe ou uma função|
|C2987 de erro do compilador|uma declaração não pode ter declspec (code_seg ('*identificador*')) e declspec (code_seg ('*valor*'))|
|[Erro do compilador C2988](compiler-error-c2988.md)|declaração/definição de template irreconhecível|
|[Erro do compilador C2989](compiler-error-c2989.md)|'*classe*': classe de modelo/genérico já foi declarado como um modelo de não classe/genérico|
|[Erro do compilador C2990](compiler-error-c2990.md)|'*classe*': não classe modelo/genérico já foi declarado como um modelo de classe/genérico|
|[Erro do compilador C2991](compiler-error-c2991.md)|redefinição do parâmetro de modelo/genérico '*parâmetro*'|
|[Erro do compilador C2992](compiler-error-c2992.md)|'*classe*': lista de parâmetros de modelo/genérico inválido ou ausente|
|[Erro do compilador C2993](compiler-error-c2993.md)|'*tipo*': tipo inválido para parâmetro de modelo sem tipo '*identificador*'|
|[Erro do compilador C2994](compiler-error-c2994.md)|classe sem nome na lista de parâmetros de modelo|
|[Erro do compilador C2995](compiler-error-c2995.md)|'*declaração*': template de função já foi definido|
|[Erro do compilador C2996](compiler-error-c2996.md)|'*função*': definição de modelo de função recursiva|
|C2997 de erro do compilador|'*função*': limite de matriz não pode ser deduzida de um inicializador de membro padrão|
|[Erro do compilador C2998](compiler-error-c2998.md)|'*declarador*': não pode ser uma definição de modelo|
|C2999 de erro do compilador|Erro desconhecido, escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abra o arquivo de Ajuda do suporte técnico para obter mais informações|
