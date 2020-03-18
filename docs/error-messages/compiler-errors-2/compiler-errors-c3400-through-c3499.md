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
ms.openlocfilehash: f4aff80178033d34cf051a14d89736b2b8347dd0
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446841"
---
# <a name="compiler-errors-c3400-through-c3499"></a>Erros do compilador C3400 a C3499

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de erro geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="error-messages"></a>Mensagens de erro

|Error|Mensagem|
|-----------|-------------|
|[Erro do compilador C3400](compiler-error-c3400.md)|dependência de restrição circular envolvendo '*constraint1*' e '*constraint2*'|
|Erro do compilador C3401|'*especificador*': especificador de acesso de assembly inválido-somente ' Private ' é permitido em modelos de classe|
|Erro do compilador C3402|'*Function*': não é possível resolver sobrecarga exceto no escopo atual|
|Erro do compilador C3403|thread_local não pode ser usado com/CLR: pure ou/CLR: safe|
|Erro do compilador C3404|'*Construct*': erro de sintaxe inesperado|
|Erro do compilador C3405|'*Function*': não é possível resolver sobrecarga sem descritor completo|
|Erro do compilador C3406|'*keyword*': não pode ser usado em um especificador de tipo elaborado|
|Erro do compilador C3407|'*Type*' não pode ser usado neste contexto|
|[Erro do compilador C3408](compiler-error-c3408.md)|'*Attribute*': atributo não é permitido em definições de modelo|
|[Erro do compilador C3409](compiler-error-c3409.md)|bloco de atributos vazio não é permitido|
|Erro do compilador C3410|'*Identifier*': o tipo de instanciação explícita '*Type*' não corresponde ao tipo do modelo de variável '*Type*'|
|Erro do compilador C3411|'*Type*' não é válido como o tamanho de uma matriz, pois não é um tipo inteiro|
|[Erro do compilador C3412](compiler-error-c3412.md)|'*especialização*': não é possível especializar o modelo no escopo atual|
|[Erro do compilador C3413](compiler-error-c3413.md)|'*Template*': instanciação explícita inválida|
|[Erro do compilador C3414](compiler-error-c3414.md)|'*Function*': a função de membro importada não pode ser definida|
|[Erro do compilador C3415](compiler-error-c3415.md)|várias seções de '*seção*' encontradas com atributos diferentes (' 0x*Value*')|
|Erro do compilador C3416|Obsoleto.|
|[Erro do compilador C3417](compiler-error-c3417.md)|'*Declarador*': tipos de valor não podem conter funções de membro especiais definidas pelo usuário|
|[Erro do compilador C3418](compiler-error-c3418.md)|Não há suporte para o especificador de acesso '*especificador*'|
|Erro do compilador C3419|Obsoleto.|
|[Erro do compilador C3420](compiler-error-c3420.md)|'*Function*': um finalizador não pode ser virtual|
|[Erro do compilador C3421](compiler-error-c3421.md)|'*Function*': não é possível chamar o finalizador para esta classe porque ele está inacessível ou não existe|
|Erro do compilador C3422|'*declaração*': tipos incompatíveis '*Type*' e '*Type*'|
|Erro do compilador C3423|Obsoleto.|
|Erro do compilador C3424|'*Type*': uma conversão function-Style para um tipo de matriz não é permitida|
|Erro do compilador C3425|Não é possível lançar o ponteiro para o objeto do tipo incompleto '*Type*'|
|Erro do compilador C3426|Não é possível lançar o objeto do tipo incompleto '*Type*'|
|Erro do compilador C3427|'*Context*': '*palavra-chave*' não pode ser usada com layout_version (*número*)|
|Erro do compilador C3428|'*Context*': '*palavra-chave*' só pode ser aplicada a declarações de classe ou definições|
|Erro do compilador C3429|"*Context*": "*keyword*" não pode ser aplicado a uma Union|
|Erro do compilador C3430|uma enumeração com escopo deve ter um nome|
|Erro do compilador C3431|'*Identifier*': *type1* não pode ser declarado novamente como *type2*|
|Erro do compilador C3432|'*Identifier*': uma declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente|
|Erro do compilador C3433|'*Identifier*': todas as declarações de uma enumeração devem ter o mesmo tipo subjacente, era '*type1*' agora '*type2*'|
|Erro do compilador C3434|'*Context*': o valor do enumerador '*Number*' não pode ser representado como '*Type*', o valor é '*Number*'|
|Erro do compilador C3435|Não há suporte para o conjunto de caracteres '*Name*'|
|Erro do compilador C3436|Não há suporte para #pragma setlocaling quando/source-charset,/Execution-charset ou/UTF-8 foi especificado|
|Erro do compilador C3437|Não há suporte para #pragma execution_character_set quando/source-charset,/Execution-charset ou/UTF-8 foi especificado|
|Erro do compilador C3438|"*Context*": "*Value*" não pode ser aplicado a uma classe Managed/WinRT|
|Erro do compilador C3439|layout_version (*número*): número de versão inválido|
|Erro do compilador C3440|'*declaração*': layout_version (*número*) incompatível com uma declaração anterior|
|Erro do compilador C3441|'*declaração*': '*palavra-chave*' não pode ser aplicada depois que a classe tiver sido definida|
|Erro do compilador C3442|Inicializando vários membros de Union: '*member1*' e '*membro2*'|
|Erro do compilador C3443|O inicializador de membro padrão para '*Class*' é recursivo|
|Erro do compilador C3444|A classe de agregação vazia '*Class*' deve ser inicializada com '{}'|
|[Erro do compilador C3445](compiler-error-c3445.md)|a inicialização da lista de cópia de '*Type*' não pode usar um construtor explícito|
|[Erro do compilador C3446](compiler-error-c3446.md)|'*Class*': um inicializador de membro padrão não é permitido para um membro de uma classe Value|
|Erro do compilador C3447|Obsoleto.|
|Erro do compilador C3448|Obsoleto.|
|Erro do compilador C3449|Obsoleto.|
|[Erro do compilador C3450](compiler-error-c3450.md)|'*Type*': não é um atributo; Não é possível especificar [System:: AttributeUsageAttribute]/[Windows:: Foundation:: Metadata:: AttributeUsageAttribute]|
|[Erro do compilador C3451](compiler-error-c3451.md)|'*Attribute*': não é possível aplicar atributo não gerenciado a '*Type*'|
|[Erro do compilador C3452](compiler-error-c3452.md)|membro de argumento de lista não constante|
|[Erro do compilador C3453](compiler-error-c3453.md)|'*Attribute*': atributo não aplicado porque o qualificador '*Qualifier*' não correspondeu|
|[Erro do compilador C3454](compiler-error-c3454.md)|[attribute] não permitido em declaração de classe|
|[Erro do compilador C3455](compiler-error-c3455.md)|'*Attribute*': nenhum dos construtores de atributo correspondeu aos argumentos|
|[Erro do compilador C3456](compiler-error-c3456.md)|[Source\_annotation_attribute] não permitido em declaração de classe gerenciada/WinRT|
|[Erro do compilador C3457](compiler-error-c3457.md)|'*Attribute*': atributo não dá suporte a argumentos sem nome|
|[Erro do compilador C3458](compiler-error-c3458.md)|' [*Attribute*] ': atributo ' [*Attribute*] ' já especificado para '*Identifier*'|
|[Erro do compilador C3459](compiler-error-c3459.md)|' [*Attribute*] ': atributo permitido somente em indexador de classe (Propriedade Default indexada)|
|[Erro do compilador C3460](compiler-error-c3460.md)|'*Type*': somente um tipo definido pelo usuário pode ser encaminhado|
|[Erro do compilador C3461](compiler-error-c3461.md)|'*Type*': somente um tipo Managed/WinRT pode ser encaminhado|
|[Erro do compilador C3462](compiler-error-c3462.md)|'*Type*': somente um tipo importado pode ser encaminhado|
|[Erro do compilador C3463](compiler-error-c3463.md)|'*Type*': tipo não permitido no atributo ' Implements '|
|[Erro do compilador C3464](compiler-error-c3464.md)|'*Type*' um tipo aninhado não pode ser encaminhado|
|[Erro do compilador C3465](compiler-error-c3465.md)|para usar o tipo '*Type*', você deve referenciar o assembly '*assembly*'|
|[Erro do compilador C3466](compiler-error-c3466.md)|'*Type*': uma especialização de uma classe de Generic não pode ser encaminhada|
|[Erro do compilador C3467](compiler-error-c3467.md)|'*Type*': este tipo já foi encaminhado|
|[Erro do compilador C3468](compiler-error-c3468.md)|'*Type*': você só pode encaminhar um tipo para um assembly: '*Identifier*' não é um assembly|
|[Erro do compilador C3469](compiler-error-c3469.md)|'*Type*': uma classe de Generic não pode ser encaminhada|
|[Erro do compilador C3470](compiler-error-c3470.md)|'*Class*': uma classe não pode ter um indexador (Propriedade Default indexada) e um operator []|
|Erro do compilador C3471|o *nome* do novo módulo Name (definido na linha de comando) está em conflito com o *nome* do nome anterior|
|Erro do compilador C3472|novo nome do arquivo *de saída (definido* na linha de comando) está em conflito com *o nome de arquivo anterior*|
|Erro do compilador C3473|nenhum nome de caminho de saída ou de módulo especificado.|
|Erro do compilador C3474|Não foi possível abrir o arquivo de saída '*filename*'|
|Erro do compilador C3475|erro de sintaxe no arquivo de entrada '*filename*'|
|Erro do compilador C3476|Não foi possível abrir o arquivo '*filename*' para entrada|
|Erro do compilador C3477|um lambda não pode aparecer em um contexto não avaliado|
|Erro do compilador C3478|'*Identifier*': uma matriz não pode ser capturada por cópia|
|Erro do compilador C3479|Não há suporte para anotações de SAL em lambdas|
|[Erro do compilador C3480](compiler-error-c3480.md)|'*Variable*': uma variável de captura de lambda deve ser de um escopo de função delimitadora|
|[Erro do compilador C3481](compiler-error-c3481.md)|'*Identifier*': variável de captura de lambda não encontrada|
|[Erro do compilador C3482](compiler-error-c3482.md)|' this ' só pode ser usado como uma captura de lambda dentro de uma função membro não estática|
|[Erro do compilador C3483](compiler-error-c3483.md)|'*Identifier*' já faz parte da lista de captura de lambda|
|[Erro do compilador C3484](compiler-error-c3484.md)|erro de sintaxe: '-> ' esperado antes do tipo de retorno|
|[Erro do compilador C3485](compiler-error-c3485.md)|uma definição de lambda não pode ter nenhum qualificador CV|
|Erro do compilador C3486|Obsoleto.|
|[Erro do compilador C3487](compiler-error-c3487.md)|'*Type*': todas as expressões de retorno devem ser deduzidas para o mesmo tipo: anteriormente, era '*Type*'|
|[Erro do compilador C3488](compiler-error-c3488.md)|' &*Identifier*' não é permitido quando o modo de captura padrão é por referência|
|[Erro do compilador C3489](compiler-error-c3489.md)|o '*identificador*de & ' é necessário quando o modo de captura padrão é por cópia|
|[Erro do compilador C3490](compiler-error-c3490.md)|'*Identifier*' não pode ser modificado porque está sendo acessado por meio de um objeto const|
|[Erro do compilador C3491](compiler-error-c3491.md)|'*Identifier*': uma captura por cópia não pode ser modificada em um lambda não mutável|
|[Erro do compilador C3492](compiler-error-c3492.md)|'*Identifier*': não é possível capturar um membro de uma União anônima|
|[Erro do compilador C3493](compiler-error-c3493.md)|'*Identifier*' não pode ser capturado implicitamente porque nenhum modo de captura padrão foi especificado|
|Erro do compilador C3494|' this ' não pode ser capturado explicitamente porque um modo de captura delimitador não permite|
|[Erro do compilador C3495](compiler-error-c3495.md)|'*Identifier*': o identificador na captura deve ser uma variável com duração de armazenamento automático declarada no escopo de alcance do lambda|
|[Erro do compilador C3496](compiler-error-c3496.md)|' this ' é sempre capturado pelo valor: ' & ' ignorado|
|Erro do compilador C3497|Não é possível construir uma instância de um lambda|
|[Erro do compilador C3498](compiler-error-c3498.md)|'*Identifier*': não é possível capturar uma variável que tenha um tipo gerenciado/WinRT|
|[Erro do compilador C3499](compiler-error-c3499.md)|um lambda que foi especificado para ter um tipo de retorno void não pode retornar um valor|

## <a name="see-also"></a>Consulte também

[Erros eC++ avisos do C/compilador e ferramentas de compilação](../compiler-errors-1/c-cpp-build-errors.md) \
[Erros do compilador C2000-C3999](../compiler-errors-1/compiler-errors-c2000-c3999.md)
