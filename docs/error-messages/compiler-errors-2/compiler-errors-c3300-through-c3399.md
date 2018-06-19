---
title: C3300 de erros do compilador por meio de C3399 | Microsoft Docs
ms.custom: ''
ms.date: 11/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
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
dev_langs:
- C++
ms.assetid: 190b7d29-ffe6-4261-921d-140da1935d00
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c5976e57e0a3b7f51c9df3fbdf3ebebb08dd1b4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33284112"
---
# <a name="compiler-errors-c3300-through-c3399"></a>C3300 de erros do compilador por meio de C3399

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|C3300 de erro do compilador|'*símbolo*': formato inadequado para IDL '*valor*'|
|C3301 de erro do compilador|'*coclass*': coclass não pode ser um '*símbolo*' interface|
|C3302 de erro do compilador|'*identificador*': identificador possui mais de *número* caracteres|
|[Erro do compilador C3303](compiler-error-c3303.md)|'*atributo*': atributo só pode ser usado em '*tipo*'|
|C3304 de erro do compilador|Obsoleto.|
|C3305 de erro do compilador|Obsoleto.|
|C3306 de erro do compilador|'*modelo*': classe sem nome modelo/generic não é permitido|
|C3307 de erro do compilador|'*módulo*': não é possível criar o módulo IDL|
|C3308 de erro do compilador|' *função*': direta não há suporte para a chamada por meio de classe importada|
|[Erro do compilador C3309](compiler-error-c3309.md)|'*macro*/*palavra-chave*': nome do módulo não pode ser uma macro ou uma palavra-chave|
|C3310 de erro do compilador|'*identificador*': conflito de nome de módulo|
|C3311 de erro do compilador|atributo de módulo deve ser definido no escopo global|
|C3312 de erro do compilador|não pode ser chamado '*identificador*'função encontrado para o tipo'*tipo*'|
|C3313 de erro do compilador|'*identificador*': variável não pode ter o tipo '*tipo*'|
|C3314 de erro do compilador|'*símbolo*': não um tipo com suporte de módulo IDL|
|C3315 de erro do compilador|' *função*': deve ser uma função de membro|
|C3316 de erro do compilador|'*tipo*': uma matriz de tamanho desconhecido não pode ser usada em um intervalo de instrução|
|C3317 de erro do compilador|'*identificador*': uma função de sobrecarga não pode ser usada como a expressão em um intervalo de instrução|
|C3318 de erro do compilador|'*tipo*': uma matriz não pode ter um tipo de elemento que contenha 'auto'|
|C3319 de erro do compilador|Obsoleto.|
|[Erro do compilador C3320](compiler-error-c3320.md)|'*tipo*': tipo não pode ter o mesmo nome que a propriedade 'name' de módulo|
|C3321 de erro do compilador|uma lista de inicializadores é inesperada neste contexto|
|[Erro do compilador C3322](compiler-error-c3322.md)|'*propriedade*': não é uma propriedade válida para o atributo '*atributo*'|
|C3323 de erro do compilador|'alinharcomo' e '__declspec(align)' não são permitidos em declarações de função|
|C3324 de erro do compilador|'*propriedade*': propriedade ocorre mais de uma vez no atributo '*atributo*'|
|C3325 de erro do compilador|'*atributo*': atributo possui muitos argumentos|
|C3326 de erro do compilador|'*valor*': não é um valor válido para a propriedade '*propriedade*'do atributo'*atributo*'|
|C3327 de erro do compilador|'*propriedade*': deve especificar o valor de propriedade do atributo '*atributo*'|
|C3328 de erro do compilador|'*atributo*': atributo não possui argumentos suficientes|
|C3329 de erro do compilador|Erro de sintaxe: esperado '*token1*'not'*token2*'|
|C3330 de erro do compilador|' *função*': uma função não pode retornar uma matriz '*tipo*'|
|C3331 de erro do compilador|'*identificador*': atributos em parâmetros são permitidos somente em interfaces e coclasses|
|C3332 de erro do compilador|'*propriedade*': propriedade inconsistente, gramática '*propriedade*' é obrigatórias e tem um padrão|
|[Erro do compilador C3333](compiler-error-c3333.md)|'*biblioteca*': não é possível #import biblioteca de tipos corrompida|
|[Erro do compilador C3334](compiler-error-c3334.md)|não é possível #import corrompido com biblioteca de tipos|
|C3335 de erro do compilador|'*identificador*': pode haver no máximo uma interface padrão para uma coclass*classe*'|
|C3336 de erro do compilador|Esta operação deve ser executada no escopo da classe|
|C3337 de erro do compilador|'*identificador*': defaultvtable deve ser uma fonte de evento para uma coclass*classe*'|
|C3338 de erro do compilador|'*identificador*': pode haver no máximo uma interface padrão que também é uma origem de evento para uma coclass*classe*'|
|C3339 de erro do compilador|parâmetro de modelo requer 'class' ou 'typename' após a lista de parâmetros|
|[Erro do compilador C3340](compiler-error-c3340.md)|'*identificador*': interface não pode ser 'restricted' e 'default' em coclass'*classe*'|
|C3341 de erro do compilador|'*interface*': uma interface defaultvtable deve ser 'dual' ou 'custom'|
|[Erro do compilador C3342](compiler-error-c3342.md)|'*identificador*': atributo ambíguo|
|C3343 de erro do compilador|'*classe*::*nome*': identificador de atributo possui muitos caracteres|
|C3344 de erro do compilador|não é possível definir uma especialização explícita nem uma especialização parcial de '*símbolo*'|
|[Erro do compilador C3345](compiler-error-c3345.md)|'*nome*': identificador inválido para o nome do módulo|
|C3346 de erro do compilador|declaração exportada no escopo sem namespace|
|[Erro do compilador C3347](compiler-error-c3347.md)|'*argumento*': necessário argumento não for especificado no atributo *asttribute*|
|C3348 de erro do compilador|modelos exportados não fazem parte dos padrões C++ atuais|
|C3349 de erro do compilador|'*classe*::*membro*': atributo multicast já foi implementado pelo provedor *provedor*|
|[Erro do compilador C3350](compiler-error-c3350.md)|' *função*': um construtor delegate espera *número* argumento (s)|
|[Erro do compilador C3351](compiler-error-c3351.md)|' *função*': se você passar uma instância de objeto nulo para um construtor delegate, você também deve transmitir o endereço de uma função de membro estático|
|[Erro do compilador C3352](compiler-error-c3352.md)|'*função*': a função especificada não corresponde ao tipo delegado '*tipo*'|
|[Erro do compilador C3353](compiler-error-c3353.md)|'*identificador*': um delegate só pode ser criado de uma função global ou uma função de membro de um tipo gerenciado/WinRT|
|[Erro do compilador C3354](compiler-error-c3354.md)|'*identificador*': a função usada para criar um delegate não pode ter tipo de retorno '*tipo*'|
|C3355 de erro do compilador|'*classe*::*membro*': atributo multicast escuta ao provedor '*provedor1*', mas é implementado pelo provedor '*provedor2*'|
|[Erro do compilador C3356](compiler-error-c3356.md)|'*identificador*': não é possível chamar um atributo multicast com um nome totalmente qualificado|
|C3357 de erro do compilador|'*atributo*': atributo é ambíguo, deve usar o nome totalmente qualificado|
|[Erro do compilador C3358](compiler-error-c3358.md)|'*símbolo*': símbolo não encontrado|
|C3359 de erro do compilador|'*especialização*': não é possível especializar template|
|[Erro do compilador C3360](compiler-error-c3360.md)|'*cadeia de caracteres*': não é possível criar *nome*|
|C3361 de erro do compilador|Não há nenhum contexto no qual *ação*|
|C3362 de erro do compilador|'*classe*::*membro*': atributo multicast não foi implementado.|
|[Erro do compilador C3363](compiler-error-c3363.md)|'*identificador*': 'typeid' só pode ser aplicado a um tipo|
|[Erro do compilador C3364](compiler-error-c3364.md)|' *função*': argumento inválido para construtor delegate; destino de delegate deve ser um ponteiro para uma função de membro|
|[Erro do compilador C3365](compiler-error-c3365.md)|operador '*operador*': operandos diferentes do tipo '*tipo*'e'*tipo*'|
|[Erro do compilador C3366](compiler-error-c3366.md)|'*membro*': membros de dados estáticos de tipos gerenciados/WinRT devem ser definidos na definição de classe|
|[Erro do compilador C3367](compiler-error-c3367.md)|' *função*': não é possível usar função static para criar um delegate não associado|
|[Erro do compilador C3368](compiler-error-c3368.md)|'*declarador*': convenção de chamada inválida para IDL|
|[Erro do compilador C3369](compiler-error-c3369.md)|'*módulo*': idl_module já definido|
|[Erro do compilador C3370](compiler-error-c3370.md)|'*módulo*': idl_module ainda não foi definido|
|[Erro do compilador C3371](compiler-error-c3371.md)|'idl_module': apenas a propriedade 'name' é permitida aqui|
|[Erro do compilador C3372](compiler-error-c3372.md)|Especifique pelo menos 1 interface para o atributo '*atributo*' em uma coclass|
|[Erro do compilador C3373](compiler-error-c3373.md)|atributo '*atributo*' não recebe argumentos exceto em uma coclass|
|[Erro do compilador C3374](compiler-error-c3374.md)|não é possível obter o endereço de ' *função*', a menos que criar instância delegate|
|[Erro do compilador C3375](compiler-error-c3375.md)|'*função*': função delegate ambígua|
|C3376 de erro do compilador|'*modelo*': somente modelos de membro de dados estáticos são permitidos|
|C3377 de erro do compilador|'decltype (Auto)' não é permitido em uma nova expressão|
|C3378 de erro do compilador|uma declaração pode ser exportada somente de uma unidade de interface de módulo|
|[Erro do compilador C3379](compiler-error-c3379.md)|'*classe*': uma classe aninhada não pode ter um especificador de acesso de assembly como parte de sua declaração|
|[Erro do compilador C3380](compiler-error-c3380.md)|'*especificador*': acesso de assembly inválido especificador - apenas 'public' ou 'private' é permitidas|
|[Erro do compilador C3381](compiler-error-c3381.md)|'*especificador*': especificadores de acesso de assembly só estão disponíveis no código compilado com uma opção /clr|
|[Erro do compilador C3382](compiler-error-c3382.md)|'sizeof' não é suportado com /CLR: safe|
|[Erro do compilador C3383](compiler-error-c3383.md)|'operator new' não é suportado com /CLR: safe|
|[Erro do compilador C3384](compiler-error-c3384.md)|'*tipo*': a restrição de valor e a restrição ref são mutuamente exclusivos|
|[Erro do compilador C3385](compiler-error-c3385.md)|' *função*': uma função que tem um atributo personalizado de DllImport não pode retornar uma instância de uma classe|
|[Erro do compilador C3386](compiler-error-c3386.md)|'*tipo*': __declspec(dllexport)/__declspec(dllimport) não pode ser aplicado a um tipo gerenciado/WinRT|
|[Erro do compilador C3387](compiler-error-c3387.md)|'*membro*': __declspec(dllexport)/__declspec(dllimport) não pode ser aplicado a um membro de um tipo gerenciado/WinRT|
|[Erro do compilador C3388](compiler-error-c3388.md)|'*token*': não é permitido como uma restrição, assumindo '*valor*' para continuar análise|
|[Erro do compilador C3389](compiler-error-c3389.md)|declspec (*especificador*) não pode ser usado com /clr: pure ou /CLR: safe|
|[Erro do compilador C3390](compiler-error-c3390.md)|'*tipo*': argumento de tipo inválido para parâmetro genérico '*parâmetro*'de generic'*generic_type*', deve ser um tipo de referência|
|[Erro do compilador C3391](compiler-error-c3391.md)|'*tipo*': argumento de tipo inválido para parâmetro genérico '*parâmetro*'de generic'*generic_type*', deve ser um tipo de valor não nulo|
|[Erro do compilador C3392](compiler-error-c3392.md)|'*tipo*': argumento de tipo inválido para parâmetro genérico '*parâmetro*'de generic'*generic_type*', deve ter um construtor público sem parâmetros|
|[Erro do compilador C3393](compiler-error-c3393.md)|Erro de sintaxe em cláusula de restrição: '*identificador*' não é um tipo|
|[Erro do compilador C3394](compiler-error-c3394.md)|Erro de sintaxe em cláusula de restrição: encontrado '*símbolo*' era esperado um tipo|
|[Erro do compilador C3395](compiler-error-c3395.md)|' *função*': dllexport não pode ser aplicado a uma função com o clrcall convenção de chamada|
|[Erro do compilador C3396](compiler-error-c3396.md)|'*classe*. *membro*': atributo personalizado não encontrado em '*namespace*'|
|[Erro do compilador C3397](compiler-error-c3397.md)|Inicialização de agregação não é permitida em argumentos padrão|
|[Erro do compilador C3398](compiler-error-c3398.md)|'*operador*': não é possível converter de '*tipo*'para'*tipo*'. Expressão fonte deve ser um símbolo de função|
|[Erro do compilador C3399](compiler-error-c3399.md)|'*tipo*': não é possível fornecer argumentos ao criar uma instância de um parâmetro genérico|
