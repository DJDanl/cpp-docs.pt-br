---
title: Erros do compilador C3300 a C3399
ms.date: 04/21/2019
f1_keywords:
- C3300
- C3301
- C3302
- C3304
- C3305
- C3306
- C3307
- C3308
- C3310
- C3311
- C3312
- C3313
- C3314
- C3315
- C3316
- C3317
- C3318
- C3319
- C3321
- C3323
- C3324
- C3325
- C3326
- C3327
- C3328
- C3329
- C3330
- C3331
- C3332
- C3335
- C3336
- C3337
- C3338
- C3339
- C3341
- C3343
- C3344
- C3346
- C3348
- C3349
- C3355
- C3357
- C3359
- C3361
- C3362
- C3376
- C3377
- C3378
helpviewer_keywords:
- C3300
- C3301
- C3302
- C3304
- C3305
- C3306
- C3307
- C3308
- C3310
- C3311
- C3312
- C3313
- C3314
- C3315
- C3316
- C3317
- C3318
- C3319
- C3321
- C3323
- C3324
- C3325
- C3326
- C3327
- C3328
- C3329
- C3330
- C3331
- C3332
- C3335
- C3336
- C3337
- C3338
- C3339
- C3341
- C3343
- C3344
- C3346
- C3348
- C3349
- C3355
- C3357
- C3359
- C3361
- C3362
- C3376
- C3377
- C3378
ms.assetid: 190b7d29-ffe6-4261-921d-140da1935d00
ms.openlocfilehash: ca55e19534f722a7231a1d30c63e2dbb77d25ec7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62281450"
---
# <a name="compiler-errors-c3300-through-c3399"></a>Erros do compilador C3300 a C3399

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|Erro do compilador C3300|'*símbolo*': formato inadequado para IDL '*valor*'|
|Erro do compilador C3301|'*coclass*': coclass não pode ser um '*símbolo*' interface|
|Erro do compilador C3302|'*identificador*': identificador possui mais de *número* caracteres|
|[Erro do compilador C3303](compiler-error-c3303.md)|'*atributo*': atributo só pode ser usado em '*tipo*'|
|Erro do compilador C3304|Obsoleto.|
|Erro do compilador C3305|Obsoleto.|
|Erro do compilador C3306|'*modelo*': não é permitido sem nome de classe de modelo/genérico|
|Erro do compilador C3307|'*módulo*': não é possível criar o módulo IDL|
|Erro do compilador C3308|' *função*': direcionar não há suporte para a chamada por meio da classe importada|
|[Erro do compilador C3309](compiler-error-c3309.md)|'*macro*/*palavra-chave*': nome do módulo não pode ser uma macro ou uma palavra-chave|
|Erro do compilador C3310|'*identificador*': conflito de nome de módulo|
|Erro do compilador C3311|atributo de módulo deve ser definido no escopo global|
|Erro do compilador C3312|não pode ser chamado '*identificador*'função encontrado para o tipo'*tipo*'|
|Erro do compilador C3313|'*identificador*': variável não pode ter o tipo '*tipo*'|
|Erro do compilador C3314|'*símbolo*': não um tipo com suporte de módulo IDL|
|Erro do compilador C3315|' *função*': deve ser uma função de membro|
|Erro do compilador C3316|'*tipo*': uma matriz de tamanho desconhecido não pode ser usada em um baseado em intervalo para a instrução|
|Erro do compilador C3317|'*identificador*': uma função de sobrecarga não pode ser usada como a expressão em um intervalo com base em instrução|
|Erro do compilador C3318|'*tipo*': uma matriz não pode ter um tipo de elemento que contenha 'auto'|
|Erro do compilador C3319|Obsoleto.|
|[Erro do compilador C3320](compiler-error-c3320.md)|'*tipo*': tipo não pode ter o mesmo nome que a propriedade de 'name' do módulo|
|Erro do compilador C3321|uma lista de inicializadores é inesperada neste contexto|
|[Erro do compilador C3322](compiler-error-c3322.md)|'*propriedade*': não é uma propriedade válida para atributo '*atributo*'|
|Erro do compilador C3323|'alinharcomo' e '__declspec(align)' não são permitidos em declarações de função|
|Erro do compilador C3324|'*propriedade*': propriedade ocorre mais de uma vez no atributo '*atributo*'|
|Erro do compilador C3325|'*atributo*': atributo possui muitos argumentos|
|Erro do compilador C3326|'*valor*': não é um valor válido para a propriedade '*propriedade*'do atributo'*atributo*'|
|Erro do compilador C3327|'*propriedade*': deve especificar o valor da propriedade do atributo '*atributo*'|
|Erro do compilador C3328|'*atributo*': atributo não possui argumentos suficientes|
|Erro do compilador C3329|Erro de sintaxe: esperado '*token1*'not'*token2*'|
|Erro do compilador C3330|' *função*': uma função não pode retornar uma matriz '*tipo*'|
|Erro do compilador C3331|'*identificador*': atributos em parâmetros são permitidos apenas em interfaces e coclasses|
|Erro do compilador C3332|'*propriedade*': propriedade de gramática inconsistente, '*propriedade*' é obrigatórias e tem um padrão|
|[Erro do compilador C3333](compiler-error-c3333.md)|'*biblioteca*': não é possível #import biblioteca de tipos corrompida|
|[Erro do compilador C3334](compiler-error-c3334.md)|não é possível #import corrompido biblioteca de tipos|
|Erro do compilador C3335|'*identifier*': Pode haver no máximo uma interface padrão para de uma coclass*classe*'|
|Erro do compilador C3336|Esta operação deve ser executada no escopo da classe|
|Erro do compilador C3337|'*identificador*': defaultvtable deve ser uma fonte de evento para de uma coclass*classe*'|
|Erro do compilador C3338|'*identifier*': Pode haver no máximo uma interface padrão que também é uma origem de evento para de uma coclass*classe*'|
|Erro do compilador C3339|parâmetro de modelo requer 'class' ou 'typename' após a lista de parâmetros|
|[Erro do compilador C3340](compiler-error-c3340.md)|'*identificador*': interface não pode ser 'restricted' e 'default' em coclass'*classe*'|
|Erro do compilador C3341|'*interface*': uma interface defaultvtable deve ser 'dual' ou 'custom'|
|[Erro do compilador C3342](compiler-error-c3342.md)|'*identificador*': atributo ambíguo|
|Erro do compilador C3343|'*classe*::*nome*': identificador de atributo possui muitos caracteres|
|Erro do compilador C3344|não é possível definir uma especialização explícita nem uma especialização parcial de '*símbolo*'|
|[Erro do compilador C3345](compiler-error-c3345.md)|'*nome*': identificador inválido para o nome do módulo|
|Erro do compilador C3346|declaração exportada no escopo sem namespace|
|[Erro do compilador C3347](compiler-error-c3347.md)|'*argumento*': necessárias de argumento não for especificado no atributo *asttribute*|
|Erro do compilador C3348|modelos exportados não são parte dos padrões C++ atuais|
|Erro do compilador C3349|'*classe*::*membro*': atributo multicast já foi implementado pelo provedor *provedor*|
|[Erro do compilador C3350](compiler-error-c3350.md)|' *função*': um construtor delegate espera *número* argumento (s)|
|[Erro do compilador C3351](compiler-error-c3351.md)|' *função*': se você passar uma instância de objeto NULL para um construtor delegate, você também deve transmitir o endereço de uma função de membro estático|
|[Erro do compilador C3352](compiler-error-c3352.md)|'*função*': a função especificada não corresponde ao tipo delegado '*tipo*'|
|[Erro do compilador C3353](compiler-error-c3353.md)|'*identificador*': um delegado só pode ser criado de uma função global ou uma função de membro de um tipo gerenciado/WinRT|
|[Erro do compilador C3354](compiler-error-c3354.md)|'*identificador*': a função usada para criar um delegado não pode ter tipo de retorno '*tipo*'|
|Erro do compilador C3355|'*classe*::*membro*': atributo multicast escuta ao provedor '*provider1*', mas é implementado pelo provedor '*® Security2*'|
|[Erro do compilador C3356](compiler-error-c3356.md)|'*identificador*': não é possível chamar um atributo multicast com um nome totalmente qualificado|
|Erro do compilador C3357|'*atributo*': atributo é ambíguo, deve usar o nome totalmente qualificado|
|[Erro do compilador C3358](compiler-error-c3358.md)|'*símbolo*': símbolo não encontrado|
|Erro do compilador C3359|'*especialização*': não é possível especializar template|
|[Erro do compilador C3360](compiler-error-c3360.md)|'*cadeia de caracteres*': não é possível criar *nome*|
|Erro do compilador C3361|Não há nenhum contexto no qual *ação*|
|Erro do compilador C3362|'*classe*::*membro*': atributo multicast não foi implementado.|
|[Erro do compilador C3363](compiler-error-c3363.md)|'*identificador*': 'typeid' só pode ser aplicada a um tipo|
|[Erro do compilador C3364](compiler-error-c3364.md)|' *função*': argumento inválido para o construtor delegate; precisa ser um ponteiro para uma função de membro de destino de delegado|
|[Erro do compilador C3365](compiler-error-c3365.md)|operador '*operador*': operandos diferentes do tipo '*tipo*'e'*tipo*'|
|[Erro do compilador C3366](compiler-error-c3366.md)|'*membro*': membros de dados estáticos de tipos gerenciados/WinRT devem ser definidos dentro da definição de classe|
|[Erro do compilador C3367](compiler-error-c3367.md)|' *função*': não é possível usar função static para criar um delegate não associado|
|[Erro do compilador C3368](compiler-error-c3368.md)|'*declarador*': convenção de chamada inválida para IDL|
|[Erro do compilador C3369](compiler-error-c3369.md)|'*módulo*': idl_module já definido|
|[Erro do compilador C3370](compiler-error-c3370.md)|'*módulo*': idl_module ainda não foi definido|
|[Erro do compilador C3371](compiler-error-c3371.md)|'idl_module': apenas a propriedade 'name' é permitida aqui|
|[Erro do compilador C3372](compiler-error-c3372.md)|deve especificar pelo menos 1 interface para atributo '*atributo*' em uma coclass|
|[Erro do compilador C3373](compiler-error-c3373.md)|atributo '*atributo*' não recebe argumentos exceto em uma coclass|
|[Erro do compilador C3374](compiler-error-c3374.md)|não é possível obter o endereço de ' *função*', a menos que a criação de instância de delegado|
|[Erro do compilador C3375](compiler-error-c3375.md)|'*função*': função delegate ambígua|
|Erro do compilador C3376|'*modelo*': somente modelos de membro de dados estáticos são permitidos|
|Erro do compilador C3377|'decltype (Auto)' não é permitido em uma expressão new|
|Erro do compilador C3378|uma declaração pode ser exportada somente de uma unidade de interface do módulo|
|[Erro do compilador C3379](compiler-error-c3379.md)|'*classe*': uma classe aninhada não pode ter um especificador de acesso de assembly como parte de sua declaração|
|[Erro do compilador C3380](compiler-error-c3380.md)|'*especificador*': especificador - de acesso de assembly inválido apenas 'public' ou 'private' é permitidos|
|[Erro do compilador C3381](compiler-error-c3381.md)|'*especificador*': especificadores de acesso de assembly só estão disponíveis no código compilado com uma opção /clr|
|[Erro do compilador C3382](compiler-error-c3382.md)|'sizeof' não é suportado com /CLR: safe|
|[Erro do compilador C3383](compiler-error-c3383.md)|'operator new' não é suportado com /CLR: safe|
|[Erro do compilador C3384](compiler-error-c3384.md)|'*tipo*': a restrição de valor e a restrição ref são mutuamente exclusivas|
|[Erro do compilador C3385](compiler-error-c3385.md)|' *função*': uma função que tem um atributo personalizado de DllImport não pode retornar uma instância de uma classe|
|[Erro do compilador C3386](compiler-error-c3386.md)|'*tipo*': __declspec(dllexport)/__declspec(dllimport) não pode ser aplicado a um tipo gerenciado/WinRT|
|[Erro do compilador C3387](compiler-error-c3387.md)|'*membro*': __declspec(dllexport)/__declspec(dllimport) não pode ser aplicado a um membro de um tipo gerenciado/WinRT|
|[Erro do compilador C3388](compiler-error-c3388.md)|'*token*': não é permitido como uma restrição, supondo que '*valor*' para continuar análise|
|[Erro do compilador C3389](compiler-error-c3389.md)|__declspec(*specifier*) cannot be used with /clr:pure or /clr:safe|
|[Erro do compilador C3390](compiler-error-c3390.md)|'*tipo*': argumento de tipo inválido para parâmetro de generic '*parâmetro*'de genérico'*generic_type*', deve ser um tipo de referência|
|[Erro do compilador C3391](compiler-error-c3391.md)|'*tipo*': argumento de tipo inválido para parâmetro de generic '*parâmetro*'de genérico'*generic_type*', deve ser um tipo de valor não anulável|
|[Erro do compilador C3392](compiler-error-c3392.md)|'*tipo*': argumento de tipo inválido para parâmetro de generic '*parâmetro*'de genérico'*generic_type*', deve ter um construtor público sem parâmetros|
|[Erro do compilador C3393](compiler-error-c3393.md)|Erro de sintaxe em cláusula de restrição: '*identificador*' não é um tipo|
|[Erro do compilador C3394](compiler-error-c3394.md)|Erro de sintaxe em cláusula de restrição: encontrado '*símbolo*' tipo esperado|
|[Erro do compilador C3395](compiler-error-c3395.md)|' *função*': dllexport não pode ser aplicado a uma função com a convenção de chamada clrcall|
|[Erro do compilador C3396](compiler-error-c3396.md)|'*classe*. *membro*': atributo personalizado não encontrado em '*namespace*'|
|[Erro do compilador C3397](compiler-error-c3397.md)|Inicialização de agregação não é permitida em argumentos padrão|
|[Erro do compilador C3398](compiler-error-c3398.md)|'*operador*': não é possível converter de '*tipo*'para'*tipo*'. Expressão fonte deve ser um símbolo de função|
|[Erro do compilador C3399](compiler-error-c3399.md)|'*tipo*': não é possível fornecer argumentos ao criar uma instância de um parâmetro genérico|

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000 - C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)
