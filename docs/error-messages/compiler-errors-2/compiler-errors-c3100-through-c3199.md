---
title: Erros do compilador C3100 a C3199
ms.date: 04/21/2019
f1_keywords:
- C3102
- C3105
- C3107
- C3108
- C3109
- C3111
- C3112
- C3119
- C3122
- C3123
- C3124
- C3125
- C3127
- C3128
- C3129
- C3143
- C3144
- C3146
- C3147
- C3148
- C3151
- C3158
- C3164
- C3165
- C3169
- C3177
- C3178
- C3184
- C3188
- C3191
- C3193
helpviewer_keywords:
- C3102
- C3105
- C3107
- C3108
- C3109
- C3111
- C3112
- C3119
- C3122
- C3123
- C3124
- C3125
- C3127
- C3128
- C3129
- C3143
- C3144
- C3146
- C3147
- C3148
- C3151
- C3158
- C3164
- C3165
- C3169
- C3177
- C3178
- C3184
- C3188
- C3191
- C3193
ms.assetid: 7bc40c2f-6a8d-488a-b665-f39375afee77
ms.openlocfilehash: efa3207a9fdfb81a52bf319a1cbc2da84084b6cd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62281645"
---
# <a name="compiler-errors-c3100-through-c3199"></a>Erros do compilador C3100 a C3199

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C3100](compiler-error-c3100.md)|'*identificador*': qualificador de atributo desconhecido|
|[Erro do compilador C3101](compiler-error-c3101.md)|expressão inválida para argumento de atributo nomeado '*identificador*'|
|Erro do compilador C3102|Obsoleto.|
|[Erro do compilador C3103](compiler-error-c3103.md)|'*identificador*': argumento nomeado repetido|
|[Erro do compilador C3104](compiler-error-c3104.md)|argumento de atributo inválido|
|Erro do compilador C3105|'*símbolo*': não pode ser usado como um atributo|
|[Erro do compilador C3106](compiler-error-c3106.md)|'*atributo*': argumentos sem nome devem preceder argumentos nomeados|
|Erro do compilador C3107|'*atributo*': funções de membro de atributos nativos não podem ser definidas.|
|Erro do compilador C3108|não é possível deduzir um tipo como uma lista de inicializadores não é uma expressão|
|Erro do compilador C3109|'*identificador*': métodos de interface devem usar a stdcall' ou cdecl' convenção de chamada|
|[Erro do compilador C3110](compiler-error-c3110.md)|'*função*': não é possível sobrecarregar um método de interface COM|
|Erro do compilador C3111|Uma lista de inicializadores não pode ser usada como o argumento padrão para um parâmetro de modelo|
|Erro do compilador C3112|'*interface*': uma interface só pode ser declarada no global ou escopo de namespace|
|[Erro do compilador C3113](compiler-error-c3113.md)|um 'interface/enum' não pode ser um modelo/genérico|
|[Erro do compilador C3114](compiler-error-c3114.md)|'*identificador*': argumento de atributo nomeado não válido|
|[Erro do compilador C3115](compiler-error-c3115.md)|'*atributo*': esse atributo não é permitido em '*construir*'|
|[Erro do compilador C3116](compiler-error-c3116.md)|'*especificador*': classe de armazenamento inválido para o método de interface|
|[Erro do compilador C3117](compiler-error-c3117.md)|'*interface*': uma interface só pode ter uma classe base|
|[Erro do compilador C3118](compiler-error-c3118.md)|'*interface*': interfaces não suportam herança virtual|
|Erro do compilador C3119|alignas (void) não é permitido|
|[Erro do compilador C3120](compiler-error-c3120.md)|'*identificador*': métodos de interface não podem conter uma lista de argumentos variáveis|
|[Erro do compilador C3121](compiler-error-c3121.md)|não é possível alterar o GUID para classe*classe*'|
|Erro do compilador C3122|'*interface*': uma interface genérica do WinRT não pode ter um GUID|
|Erro do compilador C3123|Interface genérica do WinRT não pode ter restrições|
|Erro do compilador C3124|'signed char' não é um tipo de dados válido do WinRT. Em vez disso, use 'unsigned char', 'wchar_t' ou 'signed short'.|
|Erro do compilador C3125|'*tipo*': tipo não pode derivar direta ou indiretamente de 'Platform:: Exception'|
|[Erro do compilador C3126](compiler-error-c3126.md)|não é possível definir uma union '*união*'dentro de ' tipo/WinRT gerenciados*tipo*'|
|Erro do compilador C3127|'*tipo*': '*característica*' característica só pode ser usada em uma classe de ref WinRT|
|Erro do compilador C3128|'*tipo*'não tem uma vtable introduzida por'*tipo*'|
|Erro do compilador C3129|'*tipo*': default_vptr_for_base só pode ser usado em bases e tipos polimórficos definidos localmente|
|[Erro do compilador C3130](compiler-error-c3130.md)|Erro do compilador interno: Falha ao gravar bloco de código injetado em PDB|
|[Erro do compilador C3131](compiler-error-c3131.md)|projeto deve ter um atributo 'module' com uma propriedade 'name'|
|[Erro do compilador C3132](compiler-error-c3132.md)|'*parâmetro*': matrizes de parâmetro só podem ser aplicados a um argumento formal do tipo 'matriz unidimensional de WinRT gerenciados /'|
|[Erro do compilador C3133](compiler-error-c3133.md)|Atributos não podem ser aplicados a C++ varargs|
|[Erro do compilador C3134](compiler-error-c3134.md)|'*valor*': o valor do argumento do atributo '*argumento*'possui um tipo válido'*tipo*'|
|[Erro do compilador C3135](compiler-error-c3135.md)|'*identificador*': uma propriedade não pode ter 'const' ou 'volatile' de tipo|
|[Erro do compilador C3136](compiler-error-c3136.md)|'*interface*': uma interface COM só pode herdar de outra interface COM, '*interface*' não é uma interface COM|
|[Erro do compilador C3137](compiler-error-c3137.md)|'*identificador*': uma propriedade não pode ser inicializada|
|[Erro do compilador C3138](compiler-error-c3138.md)|'*identificador*': um '*atributo*' interface deve herdar de IDispatch, ou de uma interface que herde de IDispatch|
|[Erro do compilador C3139](compiler-error-c3139.md)|'*tipo*': não é possível exportar um UDT sem membros|
|[Erro do compilador C3140](compiler-error-c3140.md)|não é possível ter vários atributos 'module' na mesma unidade de compilação|
|[Erro do compilador C3141](compiler-error-c3141.md)|'*interface*': interfaces suportam apenas herança public|
|[Erro do compilador C3142](compiler-error-c3142.md)|'*propriedade*': é possível tomar o endereço de uma propriedade|
|Erro do compilador C3143|'*argumento*': argumento de atributo não pode ter vários valores|
|Erro do compilador C3144|'*atributo*': atributo requer argumentos explícitos, '*argumento*' está sem nome|
|[Erro do compilador C3145](compiler-error-c3145.md)|'*identificador*': variável global ou estática não pode ter tipo gerenciado/WinRT '*tipo*'|
|Erro do compilador C3146|Obsoleto.|
|Erro do compilador C3147|Obsoleto.|
|Erro do compilador C3148|Obsoleto.|
|[Erro do compilador C3149](compiler-error-c3149.md)|'*tipo*': não é possível usar este tipo aqui sem um nível superior '*token*'|
|[Erro do compilador C3150](compiler-error-c3150.md)|'*construir*': '*atributo*' só pode ser aplicada a uma classe, struct, interface, array ou ponteiro|
|Erro do compilador C3151|Obsoleto.|
|[Erro do compilador C3152](compiler-error-c3152.md)|'*função*': '*palavra-chave*' só pode ser aplicada a uma classe, struct ou função membro virtual|
|[Erro do compilador C3153](compiler-error-c3153.md)|'*interface*': você não pode criar uma instância de uma interface|
|[Erro do compilador C3154](compiler-error-c3154.md)|Esperado ',' antes de reticências. Vírgula não separadas não tem suportada em funções de matriz de parâmetro de reticências.|
|[Erro do compilador C3155](compiler-error-c3155.md)|atributos não são permitidos em um indexador de propriedades|
|[Erro do compilador C3156](compiler-error-c3156.md)|'*classe*': você não pode ter uma definição de local de um tipo gerenciado/WinRT|
|[Erro do compilador C3157](compiler-error-c3157.md)|Atributo ParamArray só pode ser aplicado ao último parâmetro|
|Erro do compilador C3158|'*função*': '*palavra-chave*' só pode ser aplicado a uma função membro virtual|
|[Erro do compilador C3159](compiler-error-c3159.md)|'*identificador*': matriz de ponteiros para tipo de valor não pode ser declarado|
|[Erro do compilador C3160](compiler-error-c3160.md)|'*tipo*': um membro de dados de uma classe gerenciada/WinRT não pode ter esse tipo|
|[Erro do compilador C3161](compiler-error-c3161.md)|'*interface*': aninhar class, struct ou interface em uma interface é inválido; aninhar interface em uma classe ou struct é ilegal|
|[Erro do compilador C3162](compiler-error-c3162.md)|'*tipo*': um tipo de referência que possui um destruidor não pode ser usado como o tipo de membro de dados estáticos '*membro*'|
|[Erro do compilador C3163](compiler-error-c3163.md)|'*classe*': atributos inconsistentes com declaração anterior|
|Erro do compilador C3164|Obsoleto.|
|Erro do compilador C3165|'*valor*': não é possível converter um valor de ponto flutuante ou integral|
|[Erro do compilador C3166](compiler-error-c3166.md)|Obsoleto. '*tipo*': um membro de dados de uma classe gerenciada/WinRT não pode possuir tipo '*pointer_type* ao interior *managed_pointer_type*'|
|[Erro do compilador C3167](compiler-error-c3167.md)|Não foi possível inicializar o .NET Framework: Verifique se ele está instalado|
|[Erro do compilador C3168](compiler-error-c3168.md)|'*tipo*': tipo subjacente inválido para enumeração|
|Erro do compilador C3169|'*tipo*': não é possível deduzir o tipo para 'auto' de '*tipo*'|
|[Erro do compilador C3170](compiler-error-c3170.md)|não é possível ter identificadores de módulo diferentes em um projeto|
|[Erro do compilador C3171](compiler-error-c3171.md)|'*módulo*': não é possível especificar atributos de módulo diferentes em um projeto|
|[Erro do compilador C3172](compiler-error-c3172.md)|'*identificador*': não é possível especificar atributos de idl_module diferentes em um projeto|
|[Erro do compilador C3173](compiler-error-c3173.md)|incompatibilidade de versão em mesclagem de idl|
|[Erro do compilador C3174](compiler-error-c3174.md)|atributo de módulo não foi especificado|
|[Erro do compilador C3175](compiler-error-c3175.md)|'*função*': não é possível chamar um método de um tipo gerenciado de função não gerenciada '*função*'|
|[Erro do compilador C3176](compiler-error-c3176.md)|'*tipo*': não é possível declarar tipo value local|
|Erro do compilador C3177|Você não pode ter uma função de conversão para um tipo que contém '*tipo*'|
|Erro do compilador C3178|'*tipo*': não é possível usar ParamArray em uma função com argumentos padrão|
|[Erro do compilador C3179](compiler-error-c3179.md)|um tipo gerenciado/WinRT sem nome não é permitido|
|[Erro do compilador C3180](compiler-error-c3180.md)|'*tipo*': nome excede o limite de metadados de '*número*' caracteres|
|[Erro do compilador C3181](compiler-error-c3181.md)|'*tipo*': operando inválido para *operador*|
|[Erro do compilador C3182](compiler-error-c3182.md)|'*tipo*': uma declaração de acesso ou declaração de using membro é ilegal dentro de um tipo gerenciado/WinRT|
|[Erro do compilador C3183](compiler-error-c3183.md)|não é possível definir sem nome de classe, struct ou união dentro do tipo gerenciado/WinRT '*classe*'|
|Erro do compilador C3184|Obsoleto.|
|[Erro do compilador C3185](compiler-error-c3185.md)|'typeid': usado em um tipo gerenciado/WinRT '*tipo*', use '*operador*' em vez disso|
|Erro do compilador C3186|Obsoleto.|
|[Erro do compilador C3187](compiler-error-c3187.md)|'*identificador*': só está disponível dentro do corpo de uma função|
|Erro do compilador C3188|Obsoleto.|
|[Erro do compilador C3189](compiler-error-c3189.md)|' typeid <*declarador*>': esta sintaxe não é mais suportado, use::typeid em vez disso|
|[Erro do compilador C3190](compiler-error-c3190.md)|'*declarador*'com os argumentos de modelo fornecido não é a instanciação explícita de nenhuma função de membro de'*tipo*'|
|Erro do compilador C3191|Obsoleto.|
|[Erro do compilador C3192](compiler-error-c3192.md)|Erro de sintaxe: ' ^' não é um operador de prefixo (Você quis dizer ' *'?)|
|Erro do compilador C3193|'*construir*': requer ' / clr' ou ' / ZW' opção de linha de comando|
|[Erro do compilador C3194](compiler-error-c3194.md)|'*tipo*': um tipo de valor não pode ter um operador de atribuição|
|[Erro do compilador C3195](compiler-error-c3195.md)|'*palavra-chave*': é reservado e não pode ser usado como um membro de um tipo de valor ou classe ref. Operadores CLR/WinRT devem ser definidos usando a palavra-chave 'operator'|
|[Erro do compilador C3196](compiler-error-c3196.md)|'*identificador*': usado mais de uma vez|
|[Erro do compilador C3197](compiler-error-c3197.md)|'*palavra-chave*': só pode ser usado em definições|
|[Erro do compilador C3198](compiler-error-c3198.md)|Uso inválido de pragmas de ponto flutuante: pragma fenv_access opera apenas em modo preciso|
|[Erro do compilador C3199](compiler-error-c3199.md)|Uso inválido de pragmas de ponto flutuante: exceções não têm suporte no modo não preciso|

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000 - C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)
