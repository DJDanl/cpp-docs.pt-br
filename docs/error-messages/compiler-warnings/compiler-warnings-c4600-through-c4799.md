---
title: Avisos do compilador C4600 a C4799
ms.date: 04/21/2019
f1_keywords:
- C4609
- C4658
- C4671
- C4676
- C4689
- C4695
- C4696
- C4719
- C4720
- C4721
- C4728"
- C4732
- C4751
- C4752
- C4755
- C4757
- C4767
- C4770
helpviewer_keywords:
- C4609
- C4658
- C4671
- C4676
- C4689
- C4695
- C4696
- C4719
- C4720
- C4721
- C4728"
- C4732
- C4751
- C4752
- C4755
- C4757
- C4767
- C4770
ms.assetid: 22bd4392-f3be-445c-9f23-6126aebac901
ms.openlocfilehash: 3df17b115797f4d68621854d072c41aca14a0fd8
ms.sourcegitcommit: 283cb64fd7958a6b7fbf0cd8534de99ac8d408eb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2019
ms.locfileid: "64857557"
---
# <a name="compiler-warnings-c4600-through-c4799"></a>Avisos do compilador C4600 a C4799

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de aviso são geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="warning-messages"></a>Mensagens de aviso

|Aviso|Mensagem|
|-------------|-------------|
|[Aviso do compilador (nível 1) C4600](../../error-messages/compiler-warnings/compiler-warning-level-1-c4600.md)|#pragma 'nome de macro': espera-se uma cadeia de caracteres não vazia válida|
|[Aviso do compilador (nível 1) C4602](compiler-warning-level-1-c4602.md)|#pragma pop_macro: 'nome de macro' nenhuma push_macro #pragma anterior para este identificador|
|[Aviso do compilador (nível 1) C4603](compiler-warning-level-1-c4603.md)|'*identificador*': macro não está definida ou definição é diferente após uso de cabeçalho pré-compilado|
|Aviso do compilador (nível 1) C4604|'*tipo*': passar o argumento por valor entre limites nativo e gerenciado exige um construtor de cópia válido. Caso contrário, o comportamento de tempo de execução é indefinido|
|Aviso do compilador (nível 1) C4605|' /D*macro*' especificado na linha de comando atual, mas não foi especificado quando o cabeçalho pré-compilado foi criado|
|[Aviso do compilador (nível 1) C4606](../../error-messages/compiler-warnings/compiler-warning-level-1-c4606.md)|Aviso #pragma: 'número de aviso' ignorado; Avisos da análise de código não estão associados com níveis de aviso|
|[Aviso do compilador (nível 3) C4608](../../error-messages/compiler-warnings/compiler-warning-level-3-c4608.md)|'union_member' já foi inicializado por outro membro de união na lista de inicializadores, 'union_member'|
|Aviso do compilador (nível 3, erro) C4609|'*type1*deriva interface padrão*interface*'no tipo'*type2*'. Use uma interface padrão diferente para '*type1*', ou interromper a relação de base/derivada.|
|[Aviso do compilador (nível 4) C4610](../../error-messages/compiler-warnings/compiler-warning-level-4-c4610.md)|o objeto 'class' nunca pode ser instanciado - construtor necessárias definidas pelo usuário|
|[Aviso do compilador (nível 4) C4611](../../error-messages/compiler-warnings/compiler-warning-level-4-c4611.md)|interação entre 'function' e a destruição de objeto de C++ é não portátil|
|[Aviso do compilador (nível 1) C4612](compiler-warning-level-1-c4612.md)|Erro ao incluir o nome de arquivo|
|[Aviso do compilador (nível 1) C4613](compiler-warning-level-1-c4613.md)|'*símbolo*': classe de segmento não pode ser alterado.|
|[Aviso do compilador (nível 1) C4615](../../error-messages/compiler-warnings/compiler-warning-level-1-c4615.md)|Aviso #pragma: tipo de aviso de usuário desconhecido|
|[Aviso do compilador (nível 1) C4616](../../error-messages/compiler-warnings/compiler-warning-level-1-c4616.md)|Aviso #pragma: número de aviso 'number' não um aviso do compilador válido|
|[Aviso do compilador (nível 1) C4618](../../error-messages/compiler-warnings/compiler-warning-level-1-c4618.md)|parâmetros de pragma incluíram uma cadeia de caracteres vazia; pragma ignorado|
|[Aviso do compilador (nível 3) C4619](../../error-messages/compiler-warnings/compiler-warning-level-3-c4619.md)|aviso #pragma: não há número de aviso 'number'|
|[Aviso do compilador (nível 1) C4620](compiler-warning-level-1-c4620.md)|nenhuma forma de pós-fixo de ' operador + + ' encontrada para tipo 'type', usando forma de prefixo|
|[Aviso do compilador (nível 1) C4621](../../error-messages/compiler-warnings/compiler-warning-level-1-c4621.md)|nenhuma forma de pós-fixo de 'operator--' encontrada para tipo 'type', usando forma de prefixo|
|[Aviso do compilador (nível 3) C4622](compiler-warning-level-3-c4622.md)|substituindo informação de depuração formada durante a criação de cabeçalho pré-compilado no arquivo de objeto: 'file'|
|[Aviso do compilador (nível 4) C4623](../../error-messages/compiler-warnings/compiler-warning-level-4-c4623.md)|'derived class': construtor padrão foi implicitamente definido como excluído porque um construtor padrão da classe base está inacessível ou foi excluído|
|[Aviso do compilador (nível 1) C4624](../../error-messages/compiler-warnings/compiler-warning-level-1-c4624.md)|'derived class': destrutor foi implicitamente definido como excluído porque um destruidor de classe base está inacessível ou foi excluído|
|[Aviso do compilador (nível 4) C4625](../../error-messages/compiler-warnings/compiler-warning-level-4-c4625.md)|'derived class': construtor de cópia foi implicitamente definido como excluído porque um construtor de cópia de classe base está inacessível ou foi excluído|
|[Aviso do compilador (nível 4) C4626](../../error-messages/compiler-warnings/compiler-warning-level-4-c4626.md)|'derived class': operador de atribuição foi implicitamente definido como excluído como um operador de atribuição de classe base é inacessível ou foi excluído|
|[Aviso do compilador (nível 1) C4627](../../error-messages/compiler-warnings/compiler-warning-level-1-c4627.md)|'\<identificador >': ignorado ao procurar o uso de cabeçalho pré-compilado|
|[Aviso do compilador (nível 1) C4628](../../error-messages/compiler-warnings/compiler-warning-level-1-c4628.md)|dígrafos não suportados com -Ze. Sequência de caracteres 'digraph' não é interpretada como token alternativo para '%s'|
|[Aviso do compilador (nível 4) C4629](compiler-warning-level-4-c4629.md)|dígrafo usado, a sequência de caracteres 'digraph' interpretada como token 'char' (inserir um espaço entre os dois caracteres quando se trata de não o que você pretendia)|
|[Aviso do compilador (nível 1) C4630](../../error-messages/compiler-warnings/compiler-warning-level-1-c4630.md)|'symbol': especificador de classe de armazenamento 'extern' inválido em definição de membro|
|Aviso do compilador (nível 2) C4631|MSXML ou XPath indisponível, documento XML de comentários não serão processados. Motivo|
|[Aviso do compilador (nível 1) C4632](../../error-messages/compiler-warnings/compiler-warning-level-1-c4632.md)|Comentário de documento XML: arquivo - acesso negado: motivo|
|[Aviso do compilador (nível 3) C4633](../../error-messages/compiler-warnings/compiler-warning-level-3-c4633.md)|Destino de comentário de documento XML: erro: motivo|
|[Aviso do compilador (nível 4) C4634](compiler-warning-level-4-c4634.md)|Destino de comentário de documento XML: não pode ser aplicado: motivo|
|[Aviso do compilador (nível 3) C4635](compiler-warning-level-3-c4635.md)|Destino de comentário de documento XML:-XML malformado: motivo|
|[Aviso do compilador (nível 3) C4636](compiler-warning-level-3-c4636.md)|Comentário de documento XML aplicado para construir: marca requer atributo 'atributo' não vazio.|
|[Aviso do compilador (nível 3 e nível 4) C4637](compiler-warning-level-3-c4637.md)|Destino de comentário de documento XML: \<incluem > marca descartada. Motivo|
|[Aviso do compilador (nível 3) C4638](compiler-warning-level-3-c4638.md)|Destino de comentário de documento XML: referência a símbolo desconhecido 'symbol'.|
|[Aviso do compilador (nível 4) C4639](../../error-messages/compiler-warnings/compiler-warning-level-4-c4639.md)|Erro MSXML, documento XML de comentários não serão processados. Motivo|
|[Aviso do compilador (nível 3) C4640](../../error-messages/compiler-warnings/compiler-warning-level-3-c4640.md)|'instance': construção de objeto estático local não é thread-safe|
|[Aviso do compilador (nível 3) C4641](../../error-messages/compiler-warnings/compiler-warning-level-3-c4641.md)|Comentário de documento XML tem uma referência cruzada ambígua:|
|[Aviso do compilador (nível 3) C4645](compiler-warning-level-3-c4645.md)|função declarada com __declspec(noreturn) tem uma instrução return|
|[Aviso do compilador (nível 3) C4646](compiler-warning-level-3-c4646.md)|função declarada com __declspec(noreturn) tem o tipo de retorno não nulo|
|Aviso do compilador (nível 3) C4647|alteração de comportamento: is_pod (*tipo*) tem um valor diferente em versões anteriores|
|Aviso do compilador (nível 3) C4648|o atributo padrão 'carries_dependency' é ignorado|
|Aviso do compilador (nível 3) C4649|os atributos são ignorados nesse contexto|
|[Aviso do compilador (nível 1) C4650](../../error-messages/compiler-warnings/compiler-warning-level-1-c4650.md)|informações de depuração não está no cabeçalho pré-compilado; apenas símbolos globais do cabeçalho estarão disponíveis|
|[Aviso do compilador (nível 1) C4651](../../error-messages/compiler-warnings/compiler-warning-level-1-c4651.md)|'definição' especificada para cabeçalho pré-compilado, mas não para compilação atual|
|[Aviso do compilador (nível 1) C4652](../../error-messages/compiler-warnings/compiler-warning-level-1-c4652.md)|opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual substituirá a definida no cabeçalho pré-compilado|
|[Aviso do compilador (nível 2) C4653](../../error-messages/compiler-warnings/compiler-warning-level-2-c4653.md)|opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual ignorada|
|Aviso do compilador (nível 4) C4654|O código colocado antes de incluir de cabeçalho pré-compilado linha será ignorada. Adicione código ao cabeçalho pré-compilado.|
|[Aviso do compilador (nível 1) C4655](compiler-warning-level-1-c4655.md)|'symbol': tipo de variável é novo desde a última compilação, ou é definido de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4656](../../error-messages/compiler-warnings/compiler-warning-level-1-c4656.md)|'symbol': tipo de dados é novo ou foi alterado desde a última compilação ou é definido de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4657](compiler-warning-level-1-c4657.md)|expressão envolve um tipo de dados que há de novo desde a última compilação|
|Aviso do compilador (nível 1) C4658|'function': protótipo de função é novo desde a última compilação, ou é declarado de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4659](../../error-messages/compiler-warnings/compiler-warning-level-1-c4659.md)|#pragma 'pragma': use of reserved segment 'segment' has undefined behavior, use #pragma comment(linker, ...)|
|[Aviso do compilador (nível 1) C4661](../../error-messages/compiler-warnings/compiler-warning-level-1-c4661.md)|'identifier': nenhuma definição compatível fornecida para solicitação de instanciação de modelo explícitos|
|[Aviso do compilador (nível 1) C4662](compiler-warning-level-1-c4662.md)|instanciação explícita; classe de modelo 'identifier1' não possui nenhuma definição da qual especializar 'identifier2'|
|[Aviso do compilador (nível 1) C4667](../../error-messages/compiler-warnings/compiler-warning-level-1-c4667.md)|'function': nenhum template de função definido que corresponda à instanciação de forçada|
|[Aviso do compilador (nível 4) C4668](../../error-messages/compiler-warnings/compiler-warning-level-4-c4668.md)|'symbol' não está definido como uma macro de pré-processador, substituindo por '0' para 'diretiva'|
|[Aviso do compilador (nível 1) C4669](../../error-messages/compiler-warnings/compiler-warning-level-1-c4669.md)|'cast': conversão não segura: 'class' é um objeto do tipo gerenciado|
|[Aviso do compilador (nível 4) C4670](compiler-warning-level-4-c4670.md)|'identifier': esta classe base é inacessível|
|Aviso do compilador (nível 4) C4671|'identifier': o construtor de cópia é inacessível|
|[Aviso do compilador (nível 4) C4672](compiler-warning-level-4-c4672.md)|'identifier1': ambíguo. Visto primeiro como 'identifier2'|
|[Aviso do compilador (nível 4) C4673](../../error-messages/compiler-warnings/compiler-warning-level-4-c4673.md)|gerar os seguintes tipos de 'identifier' não será considerado no local de catch|
|[Aviso do compilador (nível 1) C4674](compiler-warning-level-1-c4674.md)|'method' deve ser declarado como 'static' e ter exatamente um parâmetro|
|Aviso do compilador (nível 4) C4676|'%s'': o destruidor é inacessível|
|[Aviso do compilador (nível 1) C4677](../../error-messages/compiler-warnings/compiler-warning-level-1-c4677.md)|'function': assinatura de membro não private contém tipo private de assembly 'private_type'|
|[Aviso do compilador (nível 1) C4678](compiler-warning-level-1-c4678.md)|a classe base 'base_type' é menos acessível que 'derived_type'|
|[Aviso do compilador (nível 1) C4679](../../error-messages/compiler-warnings/compiler-warning-level-1-c4679.md)|'member': não foi possível importar membro|
|[Aviso do compilador (nível 4) C4680](../../error-messages/compiler-warnings/compiler-warning-level-4-c4680.md)|'class': coclass não especifica uma interface padrão|
|[Aviso do compilador (nível 4) C4681](compiler-warning-level-4-c4681.md)|'class': coclass não especifica uma interface padrão que é uma origem do evento|
|[Aviso do compilador (nível 4) C4682](compiler-warning-level-4-c4682.md)|'parameter': nenhum atributo de parâmetro direcional especificado, padronizando para [in]|
|[Aviso do compilador (nível 1) C4683](../../error-messages/compiler-warnings/compiler-warning-level-1-c4683.md)|'function': origem do evento tem um 'out'-parâmetro; Tome cuidado ao capturar vários manipuladores de eventos|
|[Aviso do compilador (nível 1) C4684](../../error-messages/compiler-warnings/compiler-warning-level-1-c4684.md)|'attribute': AVISO!! atributo pode causar a geração de código inválido: use com cuidado|
|[Aviso do compilador (nível 1) C4685](compiler-warning-level-1-c4685.md)|esperando ' >> ' encontrado ' >> ' durante a análise de parâmetros de modelo|
|[Aviso do compilador (nível 3) C4686](../../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md)|'user-defined type': possível alteração no comportamento, alteração na convenção de chamada de retorno UDT|
|[Aviso (erro) C4687 do compilador](../../error-messages/compiler-warnings/compiler-warning-c4687.md)|'class': uma classe sealed abstract não pode implementar uma interface 'interface'|
|[Aviso do compilador (nível 1) C4688](../../error-messages/compiler-warnings/compiler-warning-level-1-c4688.md)|'restrição de ': lista de restrições contém tipo private de assembly 'type'|
|Aviso do compilador (nível 1) C4689|'%c': unsupported character in #pragma detect_mismatch; #pragma ignored|
|[Aviso do compilador (nível 4) C4690](../../error-messages/compiler-warnings/compiler-warning-level-4-c4690.md)|\[ emitidl (pop)]: mais ativações do que envios por push|
|[Aviso do compilador (nível 1) C4691](../../error-messages/compiler-warnings/compiler-warning-level-1-c4691.md)|'type': tipo referenciado era esperado no assembly não referenciado 'file', tipo definido na unidade de tradução atual usada em vez disso|
|[Aviso do compilador (nível 1) C4692](../../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md)|'function': assinatura de membro não privado contém tipo nativo privado de assembly 'native_type'|
|[Aviso do compilador (nível 1, erro) C4693](../../error-messages/compiler-warnings/compiler-warning-c4693.md)|'class': uma classe sealed abstract não pode ter qualquer instância membros 'membro de instância'|
|[Aviso do compilador (nível 1, erro) C4694](../../error-messages/compiler-warnings/compiler-warning-c4694.md)|'class': uma classe sealed abstract não pode ter uma classe base 'base_class'|
|Aviso do compilador (nível 1) C4695|#pragma execution_character_set: conjunto de caracteres não é um argumento com suporte: atualmente, apenas 'UTF-8' tem suporte|
|Aviso do compilador (nível 1) C4696|/ Opção ZBvalue1 fora do intervalo; Supondo que 'value2'|
|[Aviso do compilador (nível 1 e nível 4) C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md)|variável local não inicializado 'name' usado|
|[Aviso do compilador (nível 4) C4701](../../error-messages/compiler-warnings/compiler-warning-level-4-c4701.md)|variável local possivelmente não inicializada 'name' usado|
|[Aviso do compilador (nível 4) C4702](../../error-messages/compiler-warnings/compiler-warning-level-4-c4702.md)|Código inacessível|
|[Aviso do compilador (nível 4) C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)|variável de ponteiro local potencialmente não inicializada '%[NULL] s'usada|
|[Aviso do compilador (nível 4) C4706](../../error-messages/compiler-warnings/compiler-warning-level-4-c4706.md)|atribuição em expressão condicional|
|[Aviso do compilador (nível 4) C4709](../../error-messages/compiler-warnings/compiler-warning-level-4-c4709.md)|operador vírgula dentro de expressão de índice de matriz|
|[Aviso do compilador (nível 4) C4710](../../error-messages/compiler-warnings/compiler-warning-level-4-c4710.md)|'function': função não embutida|
|[Aviso do compilador (nível 1) C4711](../../error-messages/compiler-warnings/compiler-warning-level-1-c4711.md)|função 'function' selecionada para expansão inline automática|
|[Aviso do compilador (nível 4) C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md)|função 'function' marcada como forceinline não embutida|
|[Aviso do compilador (nível 1) C4715](../../error-messages/compiler-warnings/compiler-warning-level-1-c4715.md)|'function': nem todos os caminhos de controle retornam um valor|
|[Aviso do compilador (nível 1, erro) C4716](../../error-messages/compiler-warnings/compiler-warning-level-1-c4716.md)|'function': deve retornar um valor|
|[Aviso do compilador (nível 1) C4717](../../error-messages/compiler-warnings/compiler-warning-level-1-c4717.md)|'function': recursivo em todos os caminhos de controle, função causará estouro de pilha de tempo de execução|
|[Aviso do compilador (nível 4) C4718](compiler-warning-level-4-c4718.md)|chamada de função: chamada recursiva não tem efeitos colaterais, excluindo|
|Aviso do compilador (nível 1) C4719|Constante Double encontrada com Qfast especificado - use 'f' como um sufixo para indicar precisão simples|
|Aviso do compilador (nível 2) C4720|relatórios de assembler embutido: 'message'|
|Aviso do compilador (nível 1) C4721|'function': não disponível como um intrínseco|
|[Aviso do compilador (nível 1) C4722](compiler-warning-level-1-c4722.md)|'function': destruidor nunca retorna, potencial perda de memória|
|[Aviso do compilador (nível 3) C4723](../../error-messages/compiler-warnings/compiler-warning-level-3-c4723.md)|possível divisão por 0|
|[Aviso do compilador (nível 3) C4724](compiler-warning-level-3-c4724.md)|possível mod por 0|
|Aviso do compilador (nível 3) C4725|instrução pode ser incorreta em alguns Pentiums|
|[Aviso do compilador (nível 1) C4727](../../error-messages/compiler-warnings/compiler-warning-level-1-c4727.md)|PCH nomeado pch_file com mesmo carimbo de hora encontrado em obj_file_1 e obj_file_2.  Usando primeiro PCH.|
|Aviso do compilador (nível 1) C4728|/ Yl-option ignorada porque a referência PCH é necessária|
|Aviso do compilador (nível 4) C4729|avisos baseados em função muito grande para um gráfico de fluxo|
|[Aviso C4730 (nível 1) do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4730.md)aviso do compilador (nível 1) C4730|'principal': misturar _m64 e expressões podem resultar em um código incorreto de ponto flutuante|
|[(Nível 1) C4731 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4731.md)|'ponteiro': 'Registrar' modificado por código de assembly embutido de registro de ponteiro de quadro|
|Aviso do compilador (nível 1) C4732|intrínseco '%s'' não tem suporte nesta arquitetura|
|[(Nível 1) C4733 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4733.md)|Asm embutido atribuindo para 'FS:0': manipulador não registrado como manipulador seguro|
|[(Nível 3) C4738 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-3-c4738.md)|armazenando o resultado float de 32 bits na memória, possível perda de desempenho|
|[Aviso do compilador (nível 1) C4739](compiler-warning-level-1-c4739.md)|referência à variável 'var' excede seu espaço de armazenamento|
|[(Nível 4) C4740 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-4-c4740.md)|fluxo para dentro ou fora do código asm embutido suprime otimização global|
|[(Nível 1) C4742 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4742.md)|'var' possui alinhamento diferente em 'file1' e 'file2': número e número|
|[(Nível 1) C4743 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4743.md)|'type' possui tamanho diferente em 'file1' e 'file2': número e o número de bytes|
|[(Nível 1) C4744 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4744.md)|'var' possui tipo diferente em 'file1' e 'file2': 'type1' e 'type2'|
|[C4746 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-c4746.md)|acesso volátil de '*expressão*' está sujeito a /volatile:\<iso&#124;ms > Configuração; considere o uso de funções intrínsecas do iso_volatile_load/store|
|[Aviso do compilador (nível 1) C4747](../../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md)|Chamada gerenciada 'entrypoint': Código gerenciado não pode ser executado sob bloqueio do carregador, incluindo o ponto de entrada da DLL e chamadas acessadas do ponto de entrada DLL|
|Aviso do compilador (nível 4) C4749|tem suporte condicionalmente: offsetof aplicado ao tipo de layout não padrão '*tipo*'|
|[Aviso do compilador (nível 1) C4750](compiler-warning-level-1-c4750.md)|'identifier': função com alloca () embutida em um loop|
|Aviso do compilador (nível 4) C4751|/arch: avx não se aplica a Intel (r) Extensões SIMD de Streaming que estão dentro do ASM embutido|
|Aviso do compilador (nível 4) C4752|encontrar extensões de vetor avançadas Intel (r); Considere o uso de /arch: avx|
|[Aviso do compilador (nível 4) C4754](compiler-warning-level-4-c4754.md)|Regras de conversão para operações aritméticas na comparação em %s(%d) significam que uma ramificação não pode ser executada. Converta '%s'' para '%s'' (ou tipo similar de %d bytes).|
|C4755 de aviso do compilador|Regras de conversão para operações aritméticas na comparação em %s(%d) significam que uma ramificação não pode ser executada em uma função embutida. Converta '%s'' para '%s'' (ou tipo similar de %d bytes).|
|[Aviso do compilador (nível 2) C4756](../../error-messages/compiler-warnings/compiler-warning-level-2-c4756.md)|Estouro em aritmética de constante|
|Aviso do compilador (nível 4) C4757|subscrito é um valor unsigned grande, você pretendia uma constante negativa?|
|[Aviso do compilador (nível 4) C4764](compiler-warning-level-4-c4764.md)|Não é possível alinhar objetos catch maiores que 16 bytes|
|Aviso do compilador (nível 4) C4767|nome da seção '%s'' tem mais de 8 caracteres e será truncado pelo vinculador|
|Aviso do compilador (nível 3) C4768|atributos de declspec antes da especificação de vinculação são ignorados|
|C4770 de aviso do compilador|enumeração parcialmente validada '*nome*' usada como índice|
|C4771 de aviso do compilador|Limites devem ser criados usando um ponteiro simple; Intrínseca MPX ignorada|
|[Aviso do compilador (nível 1, erro) C4772](../../error-messages/compiler-warnings/compiler-warning-level-1-c4772.md)|#import referenciou um tipo de uma biblioteca de tipos faltando; 'missing_type' usado como um espaço reservado|
|Aviso do compilador (nível 4) C4774|'*cadeia de caracteres*': Formatar a cadeia de caracteres esperada no argumento *número* não é uma cadeia de caracteres literal|
|Aviso do compilador (nível 3) C4775|extensão não padrão usada na cadeia de caracteres de formato '*cadeia de caracteres*'da função'*função*'|
|Aviso do compilador (nível 1) C4776|' %*caractere*'não é permitida na cadeia de caracteres de formato da função'*função*'|
|Aviso do compilador (nível 4) C4777|'*função*': cadeia de caracteres de formato '*cadeia de caracteres*'requer um argumento do tipo'*type1*', mas o argumento variadic *número* tem o tipo '*type2*'|
|Aviso do compilador (nível 3) C4778|'*função*': não finalizada a cadeia de caracteres de formato '*cadeia de caracteres*'|
|[(Nível 1) C4788 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4788.md)|'identifier': identificador foi truncado para caracteres 'number'|
|[(Nível 1) C4789 de aviso do compilador](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md)|será possível saturação de buffer 'identifier' tamanho de N bytes; M bytes serão escritos começando no deslocamento L|
|Aviso do compilador (nível 2) C4792|função '%s' declarada usando sysimport e referenciada em código nativo; biblioteca de importação necessária para vincular|
|[Aviso do compilador (nível 1 e 3) C4793](../../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md)|'function': função compilada como nativa: \n\t'reason'|
|[Aviso do compilador (nível 1) C4794](compiler-warning-level-1-c4794.md)|segmento de armazenamento local de thread variável '%[NULL] s'alterado de '%s' para '%s'|
|[Aviso do compilador (nível 1) C4799](../../error-messages/compiler-warnings/compiler-warning-level-1-c4799.md)|função 'function' não possui instrução EMMS|

## <a name="see-also"></a>Consulte também

[C /C++ ferramentas de compilador e build erros e avisos](../compiler-errors-1/c-cpp-build-errors.md) \
[Avisos do compilador C4000 - C5999](compiler-warnings-c4000-c5999.md)
