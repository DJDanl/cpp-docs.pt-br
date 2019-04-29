---
title: Erros do compilador C3400 a C3499
ms.date: 04/21/2019
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
ms.assetid: a5651dfb-c402-4e01-b3ae-28f371e51d6a
ms.openlocfilehash: 587b28cedb0ab8b11c244be4278c7dc17d1f4247
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62281381"
---
# <a name="compiler-errors-c3400-through-c3499"></a>Erros do compilador C3400 a C3499

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro que são gerados pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Erro|Mensagem|
|-----------|-------------|
|[Erro do compilador C3400](compiler-error-c3400.md)|dependência de restrição circular envolvendo '*constraint1*'e'*restrição2*'|
|Erro do compilador C3401|'*especificador*': especificador de acesso de assembly inválido - somente 'private' é permitido em modelos de classe|
|Erro do compilador C3402|'*função*': não é possível resolver sobrecarga exceto no escopo atual|
|Erro do compilador C3403|thread_local não pode ser usado com /clr: pure ou /CLR: safe|
|Erro do compilador C3404|'*construir*': erro de sintaxe inesperado|
|Erro do compilador C3405|'*função*': não é possível resolver sobrecarga sem descritor completo|
|Erro do compilador C3406|'*palavra-chave*': não pode ser usado em um especificador de tipo elaborado|
|Erro do compilador C3407|'*tipo*' não pode ser usado neste contexto|
|[Erro do compilador C3408](compiler-error-c3408.md)|'*atributo*': atributo não é permitido em definições de modelo|
|[Erro do compilador C3409](compiler-error-c3409.md)|bloco de atributos vazio não é permitido|
|Erro do compilador C3410|'*identificador*': o tipo de instanciação explícito '*tipo*'não coincide com o tipo de modelo de variável'*tipo*'|
|Erro do compilador C3411|'*tipo*' não é válido como o tamanho de uma matriz como não é um tipo de inteiro|
|[Erro do compilador C3412](compiler-error-c3412.md)|'*especialização*': não é possível especializar template no escopo atual|
|[Erro do compilador C3413](compiler-error-c3413.md)|'*modelo*': instanciação explícita inválida|
|[Erro do compilador C3414](compiler-error-c3414.md)|'*função*': função membro importada não pode ser definida.|
|[Erro do compilador C3415](compiler-error-c3415.md)|vários '*seção*' seções encontradas com atributos diferentes ('0 x*valor*')|
|Erro do compilador C3416|Obsoleto.|
|[Erro do compilador C3417](compiler-error-c3417.md)|'*declarador*': tipos de valor não podem conter funções de membro especiais definidas pelo usuário|
|[Erro do compilador C3418](compiler-error-c3418.md)|especificador de acesso '*especificador*' não tem suporte|
|Erro do compilador C3419|Obsoleto.|
|[Erro do compilador C3420](compiler-error-c3420.md)|'*função*': um finalizador não pode ser virtual|
|[Erro do compilador C3421](compiler-error-c3421.md)|'*função*': não é possível chamar o finalizador para esta classe porque ele é inacessível ou não existe|
|Erro do compilador C3422|'*declaração*': tipos incompatíveis*tipo*'e'*tipo*'|
|Erro do compilador C3423|Obsoleto.|
|Erro do compilador C3424|'*tipo*': não é permitido um estilo de função convertido para um tipo de matriz|
|Erro do compilador C3425|não é possível lançar um ponteiro para objeto do tipo incompleto '*tipo*'|
|Erro do compilador C3426|não é possível lançar um objeto do tipo incompleto '*tipo*'|
|Erro do compilador C3427|'*contexto*': '*palavra-chave*' não pode ser usado com layout_version (*número*)|
|Erro do compilador C3428|'*contexto*': '*palavra-chave*' só pode ser aplicado a declarações de classe ou definições|
|Erro do compilador C3429|'*contexto*': '*palavra-chave*' não pode ser aplicado a uma união|
|Erro do compilador C3430|uma enumeração com escopo deve ter um nome|
|Erro do compilador C3431|'*identificador*': *type1* não pode ser declarado novamente como *type2*|
|Erro do compilador C3432|'*identificador*': declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente|
|Erro do compilador C3433|'*identificador*': todas as declarações de uma enumeração devem ter o mesmo tipo subjacente, era '*type1*'agora'*type2*'|
|Erro do compilador C3434|'*contexto*': valor do enumerador '*número*'não pode ser representado como'*tipo*', valor é'*número*'|
|Erro do compilador C3435|conjunto de caracteres '*nome*' não tem suporte|
|Erro do compilador C3436|#pragma setlocale não tem suporte quando /source-charset, /execution-charset ou /utf-8 tiver sido especificado|
|Erro do compilador C3437|#pragma execution_character_set não tem suporte quando /source-charset, /execution-charset ou /utf-8 tiver sido especificado|
|Erro do compilador C3438|'*contexto*': '*valor*' não pode ser aplicado a uma classe gerenciada/WinRT|
|Erro do compilador C3439|layout_version (*número*): número de versão inválido|
|Erro do compilador C3440|'*declaração*': layout_version (*número*) incompatível com uma declaração anterior|
|Erro do compilador C3441|'*declaração*': '*palavra-chave*' não pode ser aplicado após a definição de classe|
|Erro do compilador C3442|Inicializando vários membros de união: '*member1*'e'*membro2*'|
|Erro do compilador C3443|O inicializador de membro padrão para '*classe*' é recursivo|
|Erro do compilador C3444|Esvazie a classe de agregação*classe*'deve ser inicializado com'{}'|
|[Erro do compilador C3445](compiler-error-c3445.md)|Copy-list-initialization de '*tipo*' não é possível usar um construtor explícito|
|[Erro do compilador C3446](compiler-error-c3446.md)|'*classe*': um inicializador de membro padrão não é permitido para um membro de uma classe de valor|
|Erro do compilador C3447|Obsoleto.|
|Erro do compilador C3448|Obsoleto.|
|Erro do compilador C3449|Obsoleto.|
|[Erro do compilador C3450](compiler-error-c3450.md)|'*tipo*': não é um atributo; não é possível especificar [System::AttributeUsageAttribute] / [Windows::Foundation::Metadata::AttributeUsageAttribute]|
|[Erro do compilador C3451](compiler-error-c3451.md)|'*atributo*': não é possível aplicar o atributo não gerenciado para '*tipo*'|
|[Erro do compilador C3452](compiler-error-c3452.md)|membro de argumento da lista não constante|
|[Erro do compilador C3453](compiler-error-c3453.md)|'*atributo*': atributo não aplicado porque qualificador '*qualificador*' não correspondeu|
|[Erro do compilador C3454](compiler-error-c3454.md)|[attribute] não permitido em declaração de classe|
|[Erro do compilador C3455](compiler-error-c3455.md)|'*atributo*': nenhum dos construtores de atributo corresponderam aos argumentos|
|[Erro do compilador C3456](compiler-error-c3456.md)|[origem\_annotation_attribute] não permitido em declaração de classe WinRT/gerenciado|
|[Erro do compilador C3457](compiler-error-c3457.md)|'*atributo*': atributo não suporta argumentos sem nome|
|[Erro do compilador C3458](compiler-error-c3458.md)|' [*atributo*]': atributo ' [*atributo*]' já especificado para '*identificador*'|
|[Erro do compilador C3459](compiler-error-c3459.md)|' [*atributo*]': atributo permitido apenas em indexador de classe (propriedade default indexada)|
|[Erro do compilador C3460](compiler-error-c3460.md)|'*tipo*': apenas um tipo definido pelo usuário pode ser encaminhado.|
|[Erro do compilador C3461](compiler-error-c3461.md)|'*tipo*': apenas um tipo gerenciado/WinRT pode ser encaminhado.|
|[Erro do compilador C3462](compiler-error-c3462.md)|'*tipo*': apenas tipos importados podem ser encaminhados.|
|[Erro do compilador C3463](compiler-error-c3463.md)|'*tipo*': tipo não permitido em atributo 'implements'|
|[Erro do compilador C3464](compiler-error-c3464.md)|'*tipo*' não pode ser encaminhado a um tipo aninhado|
|[Erro do compilador C3465](compiler-error-c3465.md)|Para usar o tipo '*tipo*'deve referenciar o assembly'*assembly*'|
|[Erro do compilador C3466](compiler-error-c3466.md)|'*tipo*': uma especialização de uma classe genérica não pode ser encaminhada.|
|[Erro do compilador C3467](compiler-error-c3467.md)|'*tipo*': este tipo já foi enviado|
|[Erro do compilador C3468](compiler-error-c3468.md)|'*tipo*': só é possível enviar um tipo a um assembly: '*identificador*' não é um assembly|
|[Erro do compilador C3469](compiler-error-c3469.md)|'*tipo*': uma classe genérica não pode ser encaminhada.|
|[Erro do compilador C3470](compiler-error-c3470.md)|'*classe*': uma classe não pode possuir um indexador (propriedade default indexada) e um operator]|
|Erro do compilador C3471|novo nome do módulo *nome* (definido na linha de comando) está em conflito com o nome anterior *nome*|
|Erro do compilador C3472|novo nome de arquivo de saída *filename* (definido na linha de comando) está em conflito com o nome de arquivo anterior *filename*|
|Erro do compilador C3473|Nenhum nome de módulo ou nome de caminho de saída especificado.|
|Erro do compilador C3474|não foi possível abrir o arquivo de saída '*filename*'|
|Erro do compilador C3475|Erro de sintaxe no arquivo de entrada '*filename*'|
|Erro do compilador C3476|não foi possível abrir o arquivo '*filename*' para a entrada|
|Erro do compilador C3477|um lambda não pode aparecer em um contexto não avaliado|
|Erro do compilador C3478|'*identificador*': uma matriz não pode ser capturada por cópia|
|Erro do compilador C3479|Não há suporte para anotações SAL em lambdas|
|[Erro do compilador C3480](compiler-error-c3480.md)|'*variável*': uma variável de captura de lambda deve ser de um escopo delimitador de função|
|[Erro do compilador C3481](compiler-error-c3481.md)|'*identificador*': variável de captura de lambda não encontrado|
|[Erro do compilador C3482](compiler-error-c3482.md)|'this' só pode ser usado como uma captura de lambda dentro de uma função de membro não estático|
|[Erro do compilador C3483](compiler-error-c3483.md)|'*identificador*' já é parte da lista de captura de lambda|
|[Erro do compilador C3484](compiler-error-c3484.md)|Erro de sintaxe: esperado '->' antes do tipo de retorno|
|[Erro do compilador C3485](compiler-error-c3485.md)|uma definição de lambda não pode ter cv-qualifiers|
|Erro do compilador C3486|Obsoleto.|
|[Erro do compilador C3487](compiler-error-c3487.md)|'*tipo*': todos retornam expressões devem ser deduzidas para o mesmo tipo: anteriormente era '*tipo*'|
|[Erro do compilador C3488](compiler-error-c3488.md)|' &*identificador*' não é permitida quando o modo de captura padrão é por referência|
|[Erro do compilador C3489](compiler-error-c3489.md)|' &*identificador*' é necessária quando o modo de captura padrão é por cópia|
|[Erro do compilador C3490](compiler-error-c3490.md)|'*identificador*' não pode ser modificado porque ele está sendo acessado por meio de um objeto const|
|[Erro do compilador C3491](compiler-error-c3491.md)|'*identificador*': uma captura por cópia não pode ser modificada em um lambda não mutável|
|[Erro do compilador C3492](compiler-error-c3492.md)|'*identificador*': não é possível capturar um membro de uma união anônima|
|[Erro do compilador C3493](compiler-error-c3493.md)|'*identificador*' não pode ser capturado implicitamente porque nenhum modo de captura padrão foi especificado|
|Erro do compilador C3494|'this' não pode ser capturado explicitamente porque um modo de captura delimitador não permite|
|[Erro do compilador C3495](compiler-error-c3495.md)|'*identificador*': identificador na captura deve ser uma variável com duração de armazenamento automático declarada no escopo de alcance do lambda|
|[Erro do compilador C3496](compiler-error-c3496.md)|'this' sempre é capturado por valor: '&' ignorado|
|Erro do compilador C3497|não é possível construir uma instância de uma lambda|
|[Erro do compilador C3498](compiler-error-c3498.md)|'*identificador*': não é possível capturar uma variável que tem um tipo gerenciado/WinRT|
|[Erro do compilador C3499](compiler-error-c3499.md)|um lambda que foi especificado para ter um tipo de retorno void não pode retornar um valor|

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000 - C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)
