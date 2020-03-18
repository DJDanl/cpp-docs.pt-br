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
- C4728
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
- C4728
- C4732
- C4751
- C4752
- C4755
- C4757
- C4767
- C4770
ms.assetid: 22bd4392-f3be-445c-9f23-6126aebac901
ms.openlocfilehash: 638af32b27f8d66086f3a39b74ecd46fdbb4649d
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438173"
---
# <a name="compiler-warnings-c4600-through-c4799"></a>Avisos do compilador C4600 a C4799

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de aviso que são geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="warning-messages"></a>Mensagens de aviso

|Aviso|Mensagem|
|-------------|-------------|
|[Aviso do compilador (nível 1) C4600](../../error-messages/compiler-warnings/compiler-warning-level-1-c4600.md)|#pragma ' nome da macro ': esperada uma cadeia de caracteres não vazia válida|
|[Aviso do compilador (nível 1) C4602](compiler-warning-level-1-c4602.md)|#pragma pop_macro: ' nome da macro ' não push_macro #pragma anterior para este identificador|
|[Aviso do compilador (nível 1) C4603](compiler-warning-level-1-c4603.md)|'*Identifier*': a macro não está definida ou a definição é diferente após o uso de cabeçalho pré-compilado|
|Aviso do compilador (nível 1) C4604|'*Type*': passagem de argumento por valor entre limites nativos e gerenciados requer um construtor de cópia válido. Caso contrário, o comportamento de tempo de execução será indefinido|
|Aviso do compilador (nível 1) C4605|'/D*macro*' especificada na linha de comando atual, mas não foi especificada quando o cabeçalho pré-compilado foi criado|
|[Aviso do compilador (nível 1) C4606](../../error-messages/compiler-warnings/compiler-warning-level-1-c4606.md)|aviso de #pragma: ' número de aviso ' ignorado; Os avisos de análise de código não estão associados aos níveis de aviso|
|[Aviso do compilador (nível 3) C4608](../../error-messages/compiler-warnings/compiler-warning-level-3-c4608.md)|' union_member ' já foi inicializado por outro membro de União na lista de inicializadores, ' union_member '|
|Aviso do compilador (nível 3, erro) C4609|'*type1*' deriva da interface padrão '*interface*' no tipo '*type2*'. Use uma interface padrão diferente para '*type1*' ou quebre a relação base/derivada.|
|[Aviso do compilador (nível 4) C4610](../../error-messages/compiler-warnings/compiler-warning-level-4-c4610.md)|o objeto ' class ' nunca pode ser instanciado-Construtor definido pelo usuário necessário|
|[Aviso do compilador (nível 4) C4611](../../error-messages/compiler-warnings/compiler-warning-level-4-c4611.md)|a interação entre a ' função C++ ' e a destruição de objeto não é portátil|
|[Aviso do compilador (nível 1) C4612](compiler-warning-level-1-c4612.md)|erro no nome de arquivo de inclusão|
|[Aviso do compilador (nível 1) C4613](compiler-warning-level-1-c4613.md)|'*Symbol*': classe de segmento não pode ser alterada|
|[Aviso do compilador (nível 1) C4615](../../error-messages/compiler-warnings/compiler-warning-level-1-c4615.md)|aviso de #pragma: tipo de aviso de usuário desconhecido|
|[Aviso do compilador (nível 1) C4616](../../error-messages/compiler-warnings/compiler-warning-level-1-c4616.md)|aviso de #pragma: número de aviso ' número ' não é um aviso de compilador válido|
|[Aviso do compilador (nível 1) C4618](../../error-messages/compiler-warnings/compiler-warning-level-1-c4618.md)|parâmetros de pragma incluíam uma cadeia de caracteres vazia; pragma ignorado|
|[Aviso do compilador (nível 3) C4619](../../error-messages/compiler-warnings/compiler-warning-level-3-c4619.md)|aviso #pragma: não há número de aviso 'number'|
|[Aviso do compilador (nível 1) C4620](compiler-warning-level-1-c4620.md)|nenhuma forma de sufixo de ' operator + + ' encontrada para o tipo ' type ', usando o formato de prefixo|
|[Aviso do compilador (nível 1) C4621](../../error-messages/compiler-warnings/compiler-warning-level-1-c4621.md)|nenhuma forma de sufixo de ' operator--' encontrada para o tipo ' type ', usando o formato de prefixo|
|[Aviso do compilador (nível 3) C4622](compiler-warning-level-3-c4622.md)|substituindo informações de depuração formadas durante a criação do cabeçalho pré-compilado no arquivo de objeto: ' file '|
|[Aviso do compilador (nível 4) C4623](../../error-messages/compiler-warnings/compiler-warning-level-4-c4623.md)|' classe derivada ': o construtor padrão foi implicitamente definido como excluído porque um construtor padrão de classe base é inacessível ou excluído|
|[Aviso do compilador (nível 1) C4624](../../error-messages/compiler-warnings/compiler-warning-level-1-c4624.md)|' classe derivada ': o destruidor foi implicitamente definido como excluído porque um destruidor de classe base é inacessível ou excluído|
|[Aviso do compilador (nível 4) C4625](../../error-messages/compiler-warnings/compiler-warning-level-4-c4625.md)|' classe derivada ': o construtor de cópia foi implicitamente definido como excluído porque um construtor de cópia de classe base é inacessível ou excluído|
|[Aviso do compilador (nível 4) C4626](../../error-messages/compiler-warnings/compiler-warning-level-4-c4626.md)|' classe derivada ': o operador de atribuição foi implicitamente definido como excluído porque um operador de atribuição de classe base é inacessível ou excluído|
|[Aviso do compilador (nível 1) C4627](../../error-messages/compiler-warnings/compiler-warning-level-1-c4627.md)|'\<identificador > ': ignorado ao procurar por uso de cabeçalho pré-compilado|
|[Aviso do compilador (nível 1) C4628](../../error-messages/compiler-warnings/compiler-warning-level-1-c4628.md)|dígrafos não suportados com -Ze. Sequência de caracteres ' dígrafo ' não interpretada como token alternativo para '% s'|
|[Aviso do compilador (nível 4) C4629](compiler-warning-level-4-c4629.md)|dígrafo usado, sequência de caracteres ' dígrafo ' interpretada como token ' char ' (Insira um espaço entre os dois caracteres se isso não for o que você pretendia)|
|[Aviso do compilador (nível 1) C4630](../../error-messages/compiler-warnings/compiler-warning-level-1-c4630.md)|' Symbol ': especificador de classe de armazenamento ' extern ' inválido na definição de membro|
|Aviso do compilador (nível 2) C4631|MSXML ou XPath indisponível, comentários de documento XML não serão processados. reason|
|[Aviso do compilador (nível 1) C4632](../../error-messages/compiler-warnings/compiler-warning-level-1-c4632.md)|Comentário do documento XML: acesso ao arquivo negado: motivo|
|[Aviso do compilador (nível 3) C4633](../../error-messages/compiler-warnings/compiler-warning-level-3-c4633.md)|Destino do comentário do documento XML: erro: motivo|
|[Aviso do compilador (nível 4) C4634](compiler-warning-level-4-c4634.md)|Destino de comentário de documento XML: não pode ser aplicado: motivo|
|[Aviso do compilador (nível 3) C4635](compiler-warning-level-3-c4635.md)|Destino de comentário de documento XML: XML com formato incorreto: motivo|
|[Aviso do compilador (nível 3) C4636](compiler-warning-level-3-c4636.md)|Comentário de documento XML aplicado a Construct: marca requer atributo ' attribute ' não vazio.|
|[Aviso do compilador (nível 3 e nível 4) C4637](compiler-warning-level-3-c4637.md)|Destino de comentário de documento XML: \<incluir > marca descartada. Reason|
|[Aviso do compilador (nível 3) C4638](compiler-warning-level-3-c4638.md)|Destino de comentário de documento XML: referência a símbolo desconhecido ' Symbol '.|
|[Aviso do compilador (nível 4) C4639](../../error-messages/compiler-warnings/compiler-warning-level-4-c4639.md)|Erro de MSXML, comentários de documento XML não serão processados. Reason|
|[Aviso do compilador (nível 3) C4640](../../error-messages/compiler-warnings/compiler-warning-level-3-c4640.md)|'instance': construção de objeto estático local não é thread-safe|
|[Aviso do compilador (nível 3) C4641](../../error-messages/compiler-warnings/compiler-warning-level-3-c4641.md)|O comentário do documento XML tem uma referência cruzada ambígua:|
|[Aviso do compilador (nível 3) C4645](compiler-warning-level-3-c4645.md)|função declarada com __declspec (noreturn) tem uma instrução return|
|[Aviso do compilador (nível 3) C4646](compiler-warning-level-3-c4646.md)|função declarada com __declspec (noreturn) tem tipo de retorno não void|
|Aviso do compilador (nível 3) C4647|alteração de comportamento: __is_pod (*tipo*) tem um valor diferente em versões anteriores|
|Aviso do compilador (nível 3) C4648|o atributo padrão ' carries_dependency ' é ignorado|
|Aviso do compilador (nível 3) C4649|os atributos são ignorados neste contexto|
|[Aviso do compilador (nível 1) C4650](../../error-messages/compiler-warnings/compiler-warning-level-1-c4650.md)|informações de depuração não estão no cabeçalho pré-compilado; somente os símbolos globais do cabeçalho estarão disponíveis|
|[Aviso do compilador (nível 1) C4651](../../error-messages/compiler-warnings/compiler-warning-level-1-c4651.md)|' Definition ' especificado para cabeçalho pré-compilado, mas não para compilação atual|
|[Aviso do compilador (nível 1) C4652](../../error-messages/compiler-warnings/compiler-warning-level-1-c4652.md)|opção de compilador ' Option ' inconsistente com cabeçalho pré-compilado; a opção de linha de comando atual substituirá aquela definida no cabeçalho pré-compilado|
|[Aviso do compilador (nível 2) C4653](../../error-messages/compiler-warnings/compiler-warning-level-2-c4653.md)|opção de compilador ' Option ' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual ignorada|
|Aviso do compilador (nível 4) C4654|O código colocado antes da inclusão da linha de cabeçalho pré-compilado será ignorado. Adicione código ao cabeçalho pré-compilado.|
|[Aviso do compilador (nível 1) C4655](compiler-warning-level-1-c4655.md)|' Symbol ': o tipo de variável é novo desde a última compilação ou é definido de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4656](../../error-messages/compiler-warnings/compiler-warning-level-1-c4656.md)|' Symbol ': o tipo de dados é novo ou foi alterado desde a última compilação, ou é definido de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4657](compiler-warning-level-1-c4657.md)|a expressão envolve um tipo de dados que é novo desde a última compilação|
|Aviso do compilador (nível 1) C4658|' function ': o protótipo de função é novo desde a última compilação, ou é declarado de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4659](../../error-messages/compiler-warnings/compiler-warning-level-1-c4659.md)|#pragma ' pragma ': o uso do segmento reservado ' Segment ' tem comportamento indefinido; use #pragma Comment (linker,...)|
|[Aviso do compilador (nível 1) C4661](../../error-messages/compiler-warnings/compiler-warning-level-1-c4661.md)|' identifier ': nenhuma definição adequada fornecida para solicitação explícita de instanciação de modelo|
|[Aviso do compilador (nível 1) C4662](compiler-warning-level-1-c4662.md)|instanciação explícita; a classe de modelo ' identifier1 ' não tem definição da qual especializar ' identifier2 '|
|[Aviso do compilador (nível 1) C4667](../../error-messages/compiler-warnings/compiler-warning-level-1-c4667.md)|' function ': nenhum modelo de função definido que corresponda à instanciação forçada|
|[Aviso do compilador (nível 4) C4668](../../error-messages/compiler-warnings/compiler-warning-level-4-c4668.md)|' Symbol ' não está definido como uma macro de pré-processador, substituindo por ' 0 ' para ' diretiva '|
|[Aviso do compilador (nível 1) C4669](../../error-messages/compiler-warnings/compiler-warning-level-1-c4669.md)|' cast ': conversão não segura: ' class ' é um objeto de tipo gerenciado|
|[Aviso do compilador (nível 4) C4670](compiler-warning-level-4-c4670.md)|' identifier ': esta classe base é inacessível|
|Aviso do compilador (nível 4) C4671|' identifier ': o construtor de cópia é inacessível|
|[Aviso do compilador (nível 4) C4672](compiler-warning-level-4-c4672.md)|' identifier1 ': ambíguo. Visto pela primeira vez como ' identifier2 '|
|[Aviso do compilador (nível 4) C4673](../../error-messages/compiler-warnings/compiler-warning-level-4-c4673.md)|gerando ' identificador ' os seguintes tipos não serão considerados no local de captura|
|[Aviso do compilador (nível 1) C4674](compiler-warning-level-1-c4674.md)|' method ' deve ser declarado como ' static ' e ter exatamente um parâmetro|
|Aviso do compilador (nível 4) C4676|'% s': o destruidor é inacessível|
|[Aviso do compilador (nível 1) C4677](../../error-messages/compiler-warnings/compiler-warning-level-1-c4677.md)|' function ': assinatura de membro não privado contém tipo privado de assembly ' private_type '|
|[Aviso do compilador (nível 1) C4678](compiler-warning-level-1-c4678.md)|a classe base ' base_type ' é menos acessível que ' derived_type '|
|[Aviso do compilador (nível 1) C4679](../../error-messages/compiler-warnings/compiler-warning-level-1-c4679.md)|' member ': não foi possível importar o membro|
|[Aviso do compilador (nível 4) C4680](../../error-messages/compiler-warnings/compiler-warning-level-4-c4680.md)|"Class": coclass não especifica uma interface padrão|
|[Aviso do compilador (nível 4) C4681](compiler-warning-level-4-c4681.md)|"Class": coclass não especifica uma interface padrão que seja uma origem de evento|
|[Aviso do compilador (nível 4) C4682](compiler-warning-level-4-c4682.md)|' Parameter ': nenhum atributo de parâmetro direcional especificado, padronizando para [in]|
|[Aviso do compilador (nível 1) C4683](../../error-messages/compiler-warnings/compiler-warning-level-1-c4683.md)|' function ': a origem do evento tem um parâmetro ' parâmetro '; tenha cuidado ao conectar vários manipuladores de eventos|
|[Aviso do compilador (nível 1) C4684](../../error-messages/compiler-warnings/compiler-warning-level-1-c4684.md)|' attribute ': aviso!! o atributo pode causar geração de código inválida: Use com cuidado|
|[Aviso do compilador (nível 1) C4685](compiler-warning-level-1-c4685.md)|esperando ' > > ' encontrado ' > > ' ao analisar parâmetros de modelo|
|[Aviso do compilador (nível 3) C4686](../../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md)|'user-defined type': possível alteração no comportamento, alteração na convenção de chamada de retorno UDT|
|[Aviso do compilador (erro) C4687](../../error-messages/compiler-warnings/compiler-warning-c4687.md)|' class ': uma classe sealed abstract não pode implementar uma interface ' interface '|
|[Aviso do compilador (nível 1) C4688](../../error-messages/compiler-warnings/compiler-warning-level-1-c4688.md)|' constraint ': lista de restrições contém tipo privado de assembly ' type '|
|Aviso do compilador (nível 1) C4689|'%c': unsupported character in #pragma detect_mismatch; #pragma ignored|
|[Aviso do compilador (nível 4) C4690](../../error-messages/compiler-warnings/compiler-warning-level-4-c4690.md)|\[ emitidl (pop)]: mais Pops do que envios|
|[Aviso do compilador (nível 1) C4691](../../error-messages/compiler-warnings/compiler-warning-level-1-c4691.md)|' type ': tipo referenciado era esperado em ' file ' de assembly não referenciado, tipo definido na unidade de tradução atual usado em vez disso|
|[Aviso do compilador (nível 1) C4692](../../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md)|'function': assinatura de membro não privado contém tipo nativo privado de assembly 'native_type'|
|[Aviso do compilador (nível 1, erro) C4693](../../error-messages/compiler-warnings/compiler-warning-c4693.md)|' class ': uma classe sealed abstract não pode possuir nenhum membro de instância de membros de instância '|
|[Aviso do compilador (nível 1, erro) C4694](../../error-messages/compiler-warnings/compiler-warning-c4694.md)|' class ': uma classe sealed abstract não pode ter uma classe base ' base_class '|
|Aviso do compilador (nível 1) C4695|#pragma execution_character_set: ' conjunto de caracteres ' não é um argumento com suporte: atualmente, há suporte apenas para ' UTF-8 '|
|Aviso do compilador (nível 1) C4696|Opção/ZBvalue1 fora do intervalo; Supondo que ' value2 '|
|[Aviso do compilador (nível 1 e nível 4) C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md)|variável local não inicializada ' name ' usada|
|[Aviso do compilador (nível 4) C4701](../../error-messages/compiler-warnings/compiler-warning-level-4-c4701.md)|variável local potencialmente não inicializada ' name ' usada|
|[Aviso do compilador (nível 4) C4702](../../error-messages/compiler-warnings/compiler-warning-level-4-c4702.md)|código inacessível|
|[Aviso do compilador (nível 4) C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)|variável de ponteiro local potencialmente não inicializada '% s' usada|
|[Aviso do compilador (nível 4) C4706](../../error-messages/compiler-warnings/compiler-warning-level-4-c4706.md)|atribuição dentro de expressão condicional|
|[Aviso do compilador (nível 4) C4709](../../error-messages/compiler-warnings/compiler-warning-level-4-c4709.md)|operador de vírgula dentro da expressão de índice de matriz|
|[Aviso do compilador (nível 4) C4710](../../error-messages/compiler-warnings/compiler-warning-level-4-c4710.md)|'function': função não embutida|
|[Aviso do compilador (nível 1) C4711](../../error-messages/compiler-warnings/compiler-warning-level-1-c4711.md)|função ' function ' selecionada para expansão embutida automática|
|[Aviso do compilador (nível 4) C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md)|função ' function ' marcada como __forceinline não embutida|
|[Aviso do compilador (nível 1) C4715](../../error-messages/compiler-warnings/compiler-warning-level-1-c4715.md)|' function ': nem todos os caminhos de controle retornam um valor|
|[Aviso do compilador (nível 1, erro) C4716](../../error-messages/compiler-warnings/compiler-warning-level-1-c4716.md)|' function ': deve retornar um valor|
|[Aviso do compilador (nível 1) C4717](../../error-messages/compiler-warnings/compiler-warning-level-1-c4717.md)|"function": recursivo em todos os caminhos de controle, função causará estouro de pilha de tempo de execução|
|[Aviso do compilador (nível 4) C4718](compiler-warning-level-4-c4718.md)|' chamada de função ': chamada recursiva não tem efeitos colaterais, excluindo|
|Aviso do compilador (nível 1) C4719|Constante Double encontrada quando Qfast especificado – use ' f ' como um sufixo para indicar uma precisão única|
|Aviso do compilador (nível 2) C4720|relatórios de Assembler embutidos: ' message '|
|Aviso do compilador (nível 1) C4721|' function ': não disponível como um intrínseco|
|[Aviso do compilador (nível 1) C4722](compiler-warning-level-1-c4722.md)|' function ': o destruidor nunca retorna, possível perda de memória|
|[Aviso do compilador (nível 3) C4723](../../error-messages/compiler-warnings/compiler-warning-level-3-c4723.md)|possível divisão por 0|
|[Aviso do compilador (nível 3) C4724](compiler-warning-level-3-c4724.md)|possível Mod por 0|
|Aviso do compilador (nível 3) C4725|a instrução pode ser imprecisa em alguns Pentiums|
|[Aviso do compilador (nível 1) C4727](../../error-messages/compiler-warnings/compiler-warning-level-1-c4727.md)|PCH nomeado pch_file com o mesmo carimbo de data/hora encontrado em obj_file_1 e obj_file_2.  Usando o primeiro PCH.|
|Aviso do compilador (nível 1) C4728|Opção/YL-ignorada porque a referência PCH é necessária|
|Aviso do compilador (nível 4) C4729|função muito grande para avisos baseados em grafo de fluxo|
|[Aviso do compilador (nível 1) C4730](../../error-messages/compiler-warnings/compiler-warning-level-1-c4730.md) Aviso do compilador (nível 1) C4730|' Main ': misturar _m64 e expressões de ponto flutuante podem resultar em código incorreto|
|[Aviso do compilador (nível 1) C4731](../../error-messages/compiler-warnings/compiler-warning-level-1-c4731.md)|' pointer ': ponteiro de quadro registra ' Register ' modificado por código de assembly embutido|
|Aviso do compilador (nível 1) C4732|intrínseco '% s' não é suportado nesta arquitetura|
|[Aviso do compilador (nível 1) C4733](../../error-messages/compiler-warnings/compiler-warning-level-1-c4733.md)|Asm embutido atribuindo a ' FS: 0 ': manipulador não registrado como manipulador seguro|
|[Aviso do compilador (nível 3) C4738](../../error-messages/compiler-warnings/compiler-warning-level-3-c4738.md)|armazenando o resultado float de 32 bits na memória, possível perda de desempenho|
|[Aviso do compilador (nível 1) C4739](compiler-warning-level-1-c4739.md)|referência à variável ' var ' excede seu espaço de armazenamento|
|[Aviso do compilador (nível 4) C4740](../../error-messages/compiler-warnings/compiler-warning-level-4-c4740.md)|o fluxo para dentro ou para fora do código asm embutido suprime a otimização global|
|[Aviso do compilador (nível 1) C4742](../../error-messages/compiler-warnings/compiler-warning-level-1-c4742.md)|' var ' tem alinhamento diferente em ' arquivo1 ' e ' arquivo2 ': número e número|
|[Aviso do compilador (nível 1) C4743](../../error-messages/compiler-warnings/compiler-warning-level-1-c4743.md)|' type ' tem um tamanho diferente em ' arquivo1 ' e ' arquivo2 ': número e bytes de número|
|[Aviso do compilador (nível 1) C4744](../../error-messages/compiler-warnings/compiler-warning-level-1-c4744.md)|' var ' tem um tipo diferente em ' arquivo1 ' e ' arquivo2 ': ' type1 ' e ' type2 '|
|[Aviso do compilador C4746](../../error-messages/compiler-warnings/compiler-warning-c4746.md)|o acesso volátil de '*expression*' está sujeito a/volatile:\<&#124;ISO MS > Setting; Considere usar __iso_volatile_load funções intrínsecas/Store|
|[Aviso do compilador (nível 1) C4747](../../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md)|Chamando ' entrypoint ' gerenciado: o código gerenciado não pode ser executado sob o bloqueio do carregador, incluindo o ponto de entrada da DLL e chamadas atingidas do ponto de entrada da DLL|
|Aviso do compilador (nível 4) C4749|com suporte condicional: offsetof aplicado ao tipo de layout não padrão '*Type*'|
|[Aviso do compilador (nível 1) C4750](compiler-warning-level-1-c4750.md)|' identifier ': função com _alloca () embutida em um loop|
|Aviso do compilador (nível 4) C4751|/Arch: AVX não se aplica às extensões SIMD de streaming Intel (R) que estão dentro do ASM embutido|
|Aviso do compilador (nível 4) C4752|foram encontradas extensões de vetor avançadas Intel (R); Considere o uso de/Arch: AVX|
|[Aviso do compilador (nível 4) C4754](compiler-warning-level-4-c4754.md)|As regras de conversão para operações aritméticas na comparação em% s (% d) significam que uma ramificação não pode ser executada. Conversão de '% s' para '% s' (ou tipo semelhante de% d bytes).|
|Aviso do compilador C4755|As regras de conversão para operações aritméticas na comparação em% s (% d) significam que uma ramificação não pode ser executada em uma função embutida. Conversão de '% s' para '% s' (ou tipo semelhante de% d bytes).|
|[Aviso do compilador (nível 2) C4756](../../error-messages/compiler-warnings/compiler-warning-level-2-c4756.md)|estouro na aritmética de constante|
|Aviso do compilador (nível 4) C4757|o subscrito é um valor não assinado grande, você pretendia uma constante negativa?|
|[Aviso do compilador (nível 4) C4764](compiler-warning-level-4-c4764.md)|Não é possível alinhar objetos catch com mais de 16 bytes|
|Aviso do compilador (nível 4) C4767|o nome da seção '% s' tem mais de 8 caracteres e será truncado pelo vinculador|
|Aviso do compilador (nível 3) C4768|atributos de __declspec antes da especificação de vinculação serem ignorados|
|Aviso do compilador C4770|Enumeração parcialmente validada '*Name*' usado como índice|
|Aviso do compilador C4771|Os limites devem ser criados usando um ponteiro simples; Função intrínseca MPX ignorada|
|[Aviso do compilador (nível 1, erro) C4772](../../error-messages/compiler-warnings/compiler-warning-level-1-c4772.md)|#import referenciou um tipo de uma biblioteca de tipos ausente; ' missing_type ' usado como um espaço reservado|
|Aviso do compilador (nível 4) C4774|'*String*': cadeia de caracteres de formato esperada no *número* de argumento não é um literal de cadeia de caracteres|
|Aviso do compilador (nível 3) C4775|extensão não padrão usada na cadeia de caracteres de formato '*String*' da função '*Function*'|
|Aviso do compilador (nível 1) C4776|'%*Character*' não é permitido na cadeia de caracteres de formato da função '*Function*'|
|Aviso do compilador (nível 4) C4777|'*Function*': a cadeia de caracteres de formato '*String*' requer um argumento do tipo '*type1*', mas o *número* do argumento Variadic tem o tipo '*type2*'|
|Aviso do compilador (nível 3) C4778|'*Function*': cadeia de caracteres de formato não finalizada '*String*'|
|[Aviso do compilador (nível 1) C4788](../../error-messages/compiler-warnings/compiler-warning-level-1-c4788.md)|' identifier ': identificador foi truncado para ' Number ' caracteres|
|[Aviso do compilador (nível 1) C4789](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md)|o buffer ' identifier ' do tamanho de N bytes será saturado; M bytes serão gravados começando no deslocamento L|
|Aviso do compilador (nível 2) C4792|função '% s' declarada usando sysimport e referenciada de código nativo; biblioteca de importação necessária para vincular|
|[Aviso do compilador (nível 1 e 3) C4793](../../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md)|' function ': função compilada como nativa: \ n\t ' Reason '|
|[Aviso do compilador (nível 1) C4794](compiler-warning-level-1-c4794.md)|o segmento da variável de armazenamento local do thread '% s' mudou de '% s' para '% s'|
|[Aviso do compilador (nível 1) C4799](../../error-messages/compiler-warnings/compiler-warning-level-1-c4799.md)|a função ' function ' não tem instrução EMMS|

## <a name="see-also"></a>Consulte também

[Erros eC++ avisos do C/compilador e ferramentas de compilação](../compiler-errors-1/c-cpp-build-errors.md) \
[Avisos do compilador C4000-C5999](compiler-warnings-c4000-c5999.md)
