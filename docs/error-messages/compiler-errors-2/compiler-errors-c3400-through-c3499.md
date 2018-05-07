---
title: C3400 de erros do compilador por meio de C3499 | Microsoft Docs
ms.custom: ''
ms.date: 11/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3401
- C3402
- C3403
- C3404
- C3405
- C3406
- C3407
- C3410
- C3411
- C3416
- C3419
- C3422
- C3424
- C3425
- C3426
- C3427
- C3428
- C3429
- C3430
- C3431
- C3432
- C3433
- C3434
- C3435
- C3436
- C3437
- C3438
- C3439
- C3440
- C3441
- C3442
- C3443
- C3444
- C3445
- C3446
- C3471
- C3472
- C3473
- C3474
- C3475
- C3476
- C3477
- C3478
- C3479
- C3486
- C3494
- C3497
helpviewer_keywords:
- C3401
- C3402
- C3403
- C3404
- C3405
- C3406
- C3407
- C3410
- C3411
- C3416
- C3419
- C3422
- C3424
- C3425
- C3426
- C3427
- C3428
- C3429
- C3430
- C3431
- C3432
- C3433
- C3434
- C3435
- C3436
- C3437
- C3438
- C3439
- C3440
- C3441
- C3442
- C3443
- C3444
- C3445
- C3446
- C3471
- C3472
- C3473
- C3474
- C3475
- C3476
- C3477
- C3478
- C3479
- C3486
- C3494
- C3497
dev_langs:
- C++
ms.assetid: a5651dfb-c402-4e01-b3ae-28f371e51d6a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bcc3a06a5c39aff2fea0850879a8d95f757e1b66
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-errors-c3400-through-c3499"></a>C3400 de erros do compilador por meio de C3499

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C3400](compiler-error-c3400.md)|dependência de restrição circular envolvendo '*constraint1*'e'*restrição2*'|
|C3401 de erro do compilador|'*especificador*': especificador de acesso de assembly inválido - somente 'private' é permitido em modelos de classe|
|C3402 de erro do compilador|'*função*': não é possível resolver sobrecarga exceto no escopo atual|
|C3403 de erro do compilador|thread_local não pode ser usado com /clr: pure ou /CLR: safe|
|C3404 de erro do compilador|'*construir*': erro de sintaxe inesperado|
|C3405 de erro do compilador|'*função*': não é possível resolver sobrecarga sem descritor completo|
|C3406 de erro do compilador|'*palavra-chave*': não pode ser usado em um especificador de tipo elaborado|
|C3407 de erro do compilador|'*tipo*' não pode ser usado neste contexto|
|[Erro do compilador C3408](compiler-error-c3408.md)|'*atributo*': atributo não é permitido em definições de modelo|
|[Erro do compilador C3409](compiler-error-c3409.md)|bloco de atributos vazio não é permitido|
|C3410 de erro do compilador|'*identificador*': o tipo de instanciação explícito '*tipo*'não coincide com o tipo do modelo de variável'*tipo*'|
|C3411 de erro do compilador|'*tipo*' não é válido como o tamanho de uma matriz que não seja um tipo inteiro|
|[Erro do compilador C3412](compiler-error-c3412.md)|'*especialização*': não é possível especializar template no escopo atual|
|[Erro do compilador C3413](compiler-error-c3413.md)|'*modelo*': instanciação explícita inválida|
|[Erro do compilador C3414](compiler-error-c3414.md)|'*função*': função membro importada não pode ser definida|
|[Erro do compilador C3415](compiler-error-c3415.md)|vários '*seção*' seções encontradas com atributos diferentes ('0 x*valor*')|
|C3416 de erro do compilador|Obsoleto.|
|[Erro do compilador C3417](compiler-error-c3417.md)|'*declarador*': tipos de valor não podem conter funções de membro especiais definidas pelo usuário|
|[Erro do compilador C3418](compiler-error-c3418.md)|especificador de acesso '*especificador*' não tem suporte|
|C3419 de erro do compilador|Obsoleto.|
|[Erro do compilador C3420](compiler-error-c3420.md)|'*função*': um finalizador não pode ser virtual|
|[Erro do compilador C3421](compiler-error-c3421.md)|'*função*': não é possível chamar o finalizador para esta classe porque ele é inacessível ou não existe|
|C3422 de erro do compilador|'*declaração*': tipos incompatíveis*tipo*'e'*tipo*'|
|C3423 de erro do compilador|Obsoleto.|
|C3424 de erro do compilador|'*tipo*': não é permitida uma conversão para um tipo de matriz function-style|
|C3425 de erro do compilador|não é possível lançar um ponteiro para objeto do tipo incompleto '*tipo*'|
|C3426 de erro do compilador|não é possível lançar um objeto do tipo incompleto '*tipo*'|
|C3427 de erro do compilador|'*contexto*': '*palavra-chave*' não pode ser usado com layout_version (*número*)|
|C3428 de erro do compilador|'*contexto*': '*palavra-chave*' só pode ser aplicado a declarações de classe ou definições|
|C3429 de erro do compilador|'*contexto*': '*palavra-chave*' não pode ser aplicado a uma união|
|C3430 de erro do compilador|uma enumeração com escopo deve ter um nome|
|C3431 de erro do compilador|'*identificador*': *type1* não pode ser declarado novamente como *type2*|
|C3432 de erro do compilador|'*identificador*': declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente|
|C3433 de erro do compilador|'*identificador*': todas as declarações de uma enumeração devem ter o mesmo tipo subjacente, era '*type1*'agora'*type2*'|
|C3434 de erro do compilador|'*contexto*': valor do enumerador '*número*'não pode ser representado como'*tipo*', valor é'*número*'|
|C3435 de erro do compilador|conjunto de caracteres '*nome*' não tem suporte|
|C3436 de erro do compilador|#pragma setlocale não tem suporte quando /source-charset, /execution-charset ou /utf-8 tiver sido especificado|
|C3437 de erro do compilador|#pragma execution_character_set não tem suporte quando /source-charset, /execution-charset ou /utf-8 tiver sido especificado|
|C3438 de erro do compilador|'*contexto*': '*valor*' não pode ser aplicado a uma classe gerenciada/WinRT|
|C3439 de erro do compilador|layout_version (*número*): número de versão inválido|
|C3440 de erro do compilador|'*declaração*': layout_version (*número*) incompatível com uma declaração anterior|
|C3441 de erro do compilador|'*declaração*': '*palavra-chave*' não pode ser aplicado após a definição de classe|
|C3442 de erro do compilador|Inicializando vários membros de união: '*membro1*'e'*membro2*'|
|C3443 de erro do compilador|O inicializador de membro padrão de '*classe*' é recursivo|
|C3444 de erro do compilador|Esvazie a classe de agregação*classe*'deve ser inicializado com'{}'|
|[C3445 de erro do compilador](compiler-error-c3445.md)|Copy-list-initialization de '*tipo*' não é possível usar um construtor explícito|
|[Erro do compilador C3446](compiler-error-c3446.md)|'*classe*': um inicializador de membro padrão não é permitido para um membro de uma classe de valor|
|C3447 de erro do compilador|Obsoleto.|
|C3448 de erro do compilador|Obsoleto.|
|C3449 de erro do compilador|Obsoleto.|
|[Erro do compilador C3450](compiler-error-c3450.md)|'*tipo*': não é um atributo; não é possível especificar [System::AttributeUsageAttribute] / [Windows::Foundation::Metadata::AttributeUsageAttribute]|
|[Erro do compilador C3451](compiler-error-c3451.md)|'*atributo*': não é possível aplicar o atributo não gerenciado para '*tipo*'|
|[Erro do compilador C3452](compiler-error-c3452.md)|membro de argumento de lista não constante|
|[Erro do compilador C3453](compiler-error-c3453.md)|'*atributo*': atributo não aplicado porque qualificador '*qualificador*' não corresponde|
|[Erro do compilador C3454](compiler-error-c3454.md)|[attribute] não é permitido em declaração de classe|
|[Erro do compilador C3455](compiler-error-c3455.md)|'*atributo*': nenhum dos construtores de atributo corresponde aos argumentos|
|[Erro do compilador C3456](compiler-error-c3456.md)|[fonte\_annotation_attribute] não é permitido em declaração de classe gerenciada/WinRT|
|[Erro do compilador C3457](compiler-error-c3457.md)|'*atributo*': atributo não suporta argumentos sem nome|
|[Erro do compilador C3458](compiler-error-c3458.md)|' [*atributo*]': atributo ' [*atributo*]' já especificado para '*identificador*'|
|[Erro do compilador C3459](compiler-error-c3459.md)|' [*atributo*]': atributo permitido apenas em indexador de classe (propriedade default indexada)|
|[Erro do compilador C3460](compiler-error-c3460.md)|'*tipo*': somente um tipo definido pelo usuário pode ser encaminhado|
|[Erro do compilador C3461](compiler-error-c3461.md)|'*tipo*': apenas um tipo gerenciado/WinRT possa ser encaminhado.|
|[Erro do compilador C3462](compiler-error-c3462.md)|'*tipo*': apenas tipos importados podem ser encaminhados|
|[Erro do compilador C3463](compiler-error-c3463.md)|'*tipo*': tipo não permitido em atributo 'implements'|
|[Erro do compilador C3464](compiler-error-c3464.md)|'*tipo*' não pode ser enviado a um tipo aninhado|
|[Erro do compilador C3465](compiler-error-c3465.md)|Para usar o tipo '*tipo*'deve referenciar o assembly'*assembly*'|
|[Erro do compilador C3466](compiler-error-c3466.md)|'*tipo*': uma especialização de uma classe genérica não pode ser encaminhada|
|[Erro do compilador C3467](compiler-error-c3467.md)|'*tipo*': este tipo já foi enviado|
|[Erro do compilador C3468](compiler-error-c3468.md)|'*tipo*': só é possível enviar um tipo para um assembly: '*identificador*' não é um assembly|
|[Erro do compilador C3469](compiler-error-c3469.md)|'*tipo*': uma classe genérica não pode ser encaminhada|
|[Erro do compilador C3470](compiler-error-c3470.md)|'*classe*': uma classe não pode ter um indexador (propriedade default indexada) e um operador]|
|C3471 de erro do compilador|novo nome de módulo *nome* (definido na linha de comando) está em conflito com o nome anterior *nome*|
|C3472 de erro do compilador|novo nome de arquivo de saída *filename* (definido na linha de comando) está em conflito com o nome de arquivo anterior *filename*|
|C3473 de erro do compilador|Nenhum nome de caminho ou o módulo de saída especificado.|
|C3474 de erro do compilador|não foi possível abrir o arquivo de saída '*filename*'|
|C3475 de erro do compilador|Erro de sintaxe no arquivo de entrada '*filename*'|
|C3476 de erro do compilador|não foi possível abrir o arquivo '*filename*' para entrada|
|C3477 de erro do compilador|uma expressão lambda não pode aparecer em um contexto não avaliado|
|C3478 de erro do compilador|'*identificador*': uma matriz não pode ser capturada por cópia|
|C3479 de erro do compilador|Não há suporte para anotações SAL em lambdas|
|[Erro do compilador C3480](compiler-error-c3480.md)|'*variável*': uma variável de captura de lambda deve ser de um escopo de função delimitadora|
|[Erro do compilador C3481](compiler-error-c3481.md)|'*identificador*': variável de captura de lambda não encontrada|
|[Erro do compilador C3482](compiler-error-c3482.md)|'this' só pode ser usado como uma captura de lambda dentro de uma função de membro não estático|
|[Erro do compilador C3483](compiler-error-c3483.md)|'*identificador*' já é parte da lista de captura de lambda|
|[Erro do compilador C3484](compiler-error-c3484.md)|Erro de sintaxe: esperado '->' antes do tipo de retorno|
|[Erro do compilador C3485](compiler-error-c3485.md)|uma definição de lambda não pode ter cv-qualifiers|
|C3486 de erro do compilador|Obsoleto.|
|[Erro do compilador C3487](compiler-error-c3487.md)|'*tipo*': todos retornam expressões devem ser deduzidas para o mesmo tipo: anteriormente era '*tipo*'|
|[Erro do compilador C3488](compiler-error-c3488.md)|' &*identificador*' não é permitida quando o modo de captura padrão é por referência|
|[Erro do compilador C3489](compiler-error-c3489.md)|' &*identificador*' é necessária quando o modo de captura padrão é por cópia|
|[Erro do compilador C3490](compiler-error-c3490.md)|'*identificador*' não pode ser modificado porque está sendo acessado por meio de um objeto const|
|[Erro do compilador C3491](compiler-error-c3491.md)|'*identificador*': uma captura por cópia não pode ser modificada em um lambda não mutável|
|[Erro do compilador C3492](compiler-error-c3492.md)|'*identificador*': não é possível capturar um membro de uma união anônima|
|[Erro do compilador C3493](compiler-error-c3493.md)|'*identificador*' não pode ser capturado implicitamente porque nenhum modo de captura padrão foi especificado|
|C3494 de erro do compilador|'this' não pode ser capturado explicitamente porque um modo de captura delimitador não permite|
|[Erro do compilador C3495](compiler-error-c3495.md)|'*identificador*': identificador de captura deve ser uma variável com duração de armazenamento automático declarada no escopo de alcance do lambda|
|[Erro do compilador C3496](compiler-error-c3496.md)|'this' sempre é capturado por valor: '&' ignorado|
|C3497 de erro do compilador|não é possível construir uma instância de uma expressão lambda|
|[Erro do compilador C3498](compiler-error-c3498.md)|'*identificador*': não é possível capturar uma variável que possui um tipo gerenciado/WinRT|
|[Erro do compilador C3499](compiler-error-c3499.md)|uma expressão lambda que foi especificada para ter um tipo de retorno void não pode retornar um valor|

