---
title: C4600 de avisos do compilador por meio de C4799 | Microsoft Docs
ms.date: 11/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4602
- C4603
- C4609
- C4612
- C4613
- C4620
- C4622
- C4629
- C4631
- C4634
- C4635
- C4636
- C4637
- C4638
- C4645
- C4646
- C4655
- C4657
- C4658
- C4662
- C4670
- C4671
- C4672
- C4674
- C4676
- C4678
- C4681
- C4682
- C4685
- C4688
- C4689
- C4690
- C4693
- C4694
- C4695
- C4696
- C4718
- C4719
- C4720
- C4721
- C4722
- C4724
- C4725
- C4728
- C4729
- C4732
- C4739
- C4750
- C4751
- C4752
- C4754
- C4755
- C4757
- C4764
- C4767
- C4770
- C4792
- C4794
dev_langs:
- C++
ms.assetid: 22bd4392-f3be-445c-9f23-6126aebac901
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5ad29989e89bfe60f2180ee48c411ebd4d3098ce
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warnings-c4600-through-c4799"></a>C4600 de avisos do compilador por meio de C4799

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de aviso são geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="warning-messages"></a>Mensagens de aviso

|Aviso|Mensagem|
|-------------|-------------|
|[Aviso do compilador (nível 1) C4600](../../error-messages/compiler-warnings/compiler-warning-level-1-c4600.md)|#pragma 'nome de macro': espera-se uma cadeia de caracteres não vazia válida|
|Aviso do compilador (nível 1) C4602|#pragma pop_macro: 'nome de macro' Nenhum push_macro #pragma anterior para este identificador|
|Aviso do compilador (nível 1) C4603|'*identificador*': macro não está definida ou definição é diferente após uso de cabeçalho pré-compilado|
|Aviso do compilador (nível 1) C4604|'*tipo*': passar o argumento por valor através do limite nativo e gerenciado requer o construtor de cópia válida. Caso contrário, o comportamento de tempo de execução é indefinido|
|Aviso do compilador (nível 1) C4605|' /D*macro*' especificado na linha de comando atual, mas não foi especificado quando o cabeçalho pré-compilado foi criado|
|[Aviso do compilador (nível 1) C4606](../../error-messages/compiler-warnings/compiler-warning-level-1-c4606.md)|Aviso #pragma: 'número de aviso' ignorado; Avisos da análise de código não estão associados com níveis de aviso|
|[Aviso do compilador (nível 3) C4608](../../error-messages/compiler-warnings/compiler-warning-level-3-c4608.md)|'union_member' já foi inicializada por outro membro de união na lista de inicializador, 'union_member'|
|Aviso do compilador (nível 3, erro) C4609|'*type1*'deriva de interface padrão'*interface*'no tipo'*type2*'. Use uma interface padrão diferente para '*type1*', ou divida a relação de base/derivada.|
|[Aviso do compilador (nível 4) C4610](../../error-messages/compiler-warnings/compiler-warning-level-4-c4610.md)|o objeto 'class' nunca pode ser instanciado - construtor necessário definido pelo usuário|
|[Aviso do compilador (nível 4) C4611](../../error-messages/compiler-warnings/compiler-warning-level-4-c4611.md)|interação entre 'function' e destruição de objeto C++ é não portátil|
|Aviso do compilador (nível 1) C4612|Erro ao incluir o nome de arquivo|
|Aviso do compilador (nível 1) C4613|'*símbolo*': classe de segmento não pode ser alterado.|
|[Aviso do compilador (nível 1) C4615](../../error-messages/compiler-warnings/compiler-warning-level-1-c4615.md)|Aviso #pragma: tipo de aviso de usuário desconhecido|
|[Aviso do compilador (nível 1) C4616](../../error-messages/compiler-warnings/compiler-warning-level-1-c4616.md)|Aviso #pragma: número de aviso 'número' não é um aviso de compilador válido|
|[Aviso do compilador (nível 1) C4618](../../error-messages/compiler-warnings/compiler-warning-level-1-c4618.md)|parâmetros de pragma incluíram uma cadeia de caracteres vazia; pragma ignorado|
|[Aviso do compilador (nível 3) C4619](../../error-messages/compiler-warnings/compiler-warning-level-3-c4619.md)|aviso #pragma: não há número de aviso 'number'|
|Aviso do compilador (nível 1) C4620|nenhuma forma de pós-fixo de ' operador + + ' encontrado para o tipo 'type', usando forma de prefixo|
|[Aviso do compilador (nível 1) C4621](../../error-messages/compiler-warnings/compiler-warning-level-1-c4621.md)|nenhuma forma de pós-fixo de 'operator--' encontrado para o tipo 'type', usando forma de prefixo|
|Aviso do compilador (nível 3) C4622|substituindo informação de depuração formada durante a criação do cabeçalho pré-compilado no arquivo de objeto: 'file'|
|[Aviso do compilador (nível 4) C4623](../../error-messages/compiler-warnings/compiler-warning-level-4-c4623.md)|'classe derivada': construtor padrão foi implicitamente definido como excluído porque um construtor padrão da classe base é inacessível ou excluídos|
|[Aviso do compilador (nível 1) C4624](../../error-messages/compiler-warnings/compiler-warning-level-1-c4624.md)|'classe derivada': destrutor foi implicitamente definido como excluído porque um destruidor de classe base é inacessível ou excluídos|
|[Aviso do compilador (nível 4) C4625](../../error-messages/compiler-warnings/compiler-warning-level-4-c4625.md)|'classe derivada': construtor de cópia foi implicitamente definido como excluído, pois um construtor de cópia da classe base é inacessível ou excluídos|
|[Aviso do compilador (nível 4) C4626](../../error-messages/compiler-warnings/compiler-warning-level-4-c4626.md)|'classe derivada': operador de atribuição foi implicitamente definido como excluído, pois um operador de atribuição de classe base é inacessível ou excluídos|
|[Aviso do compilador (nível 1) C4627](../../error-messages/compiler-warnings/compiler-warning-level-1-c4627.md)|'\<identificador >': ignorada durante a procura de uso de cabeçalho pré-compilado|
|[Aviso do compilador (nível 1) C4628](../../error-messages/compiler-warnings/compiler-warning-level-1-c4628.md)|dígrafos não suportados com -Ze. Sequência de caracteres 'dígrafo' não é interpretada como token alternativo para '%s'|
|Aviso do compilador (nível 4) C4629|dígrafo usado, a sequência de caracteres 'dígrafo' interpretada como token 'char' (Insira um espaço entre os dois caracteres se for não pretende)|
|[Aviso do compilador (nível 1) C4630](../../error-messages/compiler-warnings/compiler-warning-level-1-c4630.md)|'symbol': especificador de classe de armazenamento 'extern' inválido em definição de membro|
|Aviso do compilador (nível 2) C4631|MSXML ou XPath indisponível, documento XML de comentários não serão processados. Motivo|
|[Aviso do compilador (nível 1) C4632](../../error-messages/compiler-warnings/compiler-warning-level-1-c4632.md)|Comentário de documento XML: arquivo - acesso negado: motivo|
|[Aviso do compilador (nível 3) C4633](../../error-messages/compiler-warnings/compiler-warning-level-3-c4633.md)|Destino de comentário de documento XML: erro: motivo|
|Aviso do compilador (nível 4) C4634|Destino de comentário de documento XML: não pode ser aplicado: motivo|
|Aviso do compilador (nível 3) C4635|Destino de comentário de documento XML: incorreta de XML: motivo|
|Aviso do compilador (nível 3) C4636|Comentário de documento XML aplicado para construir: marca requer atributo 'atributo' não vazio.|
|Aviso do compilador (nível 3 e nível 4) C4637|Destino de comentário de documento XML: \<incluem > marca descartada. Motivo|
|Aviso do compilador (nível 3) C4638|Destino de comentário de documento XML: referência a símbolo desconhecido 'symbol'.|
|[Aviso do compilador (nível 4) C4639](../../error-messages/compiler-warnings/compiler-warning-level-4-c4639.md)|Erro MSXML, documento XML de comentários não serão processados. Motivo|
|[Aviso do compilador (nível 3) C4640](../../error-messages/compiler-warnings/compiler-warning-level-3-c4640.md)|'instance': construção de objeto estático local não é thread-safe|
|[Aviso do compilador (nível 3) C4641](../../error-messages/compiler-warnings/compiler-warning-level-3-c4641.md)|Comentário de documento XML tem uma referência cruzada ambígua:|
|Aviso do compilador (nível 3) C4645|função declarada com __declspec(noreturn) tem uma instrução return|
|Aviso do compilador (nível 3) C4646|função declarada com __declspec(noreturn) tem o tipo de retorno não void|
|Aviso do compilador (nível 3) C4647|alteração de comportamento: is_pod (*tipo*) tem um valor diferente em versões anteriores|
|Aviso do compilador (nível 3) C4648|o atributo padrão 'carries_dependency' é ignorado|
|Aviso do compilador (nível 3) C4649|atributos são ignorados nesse contexto|
|[Aviso do compilador (nível 1) C4650](../../error-messages/compiler-warnings/compiler-warning-level-1-c4650.md)|informações de depuração não está no cabeçalho pré-compilado; apenas símbolos globais do cabeçalho estarão disponíveis|
|[Aviso do compilador (nível 1) C4651](../../error-messages/compiler-warnings/compiler-warning-level-1-c4651.md)|'definição' especificada para cabeçalho pré-compilado, mas não para compilação atual|
|[Aviso do compilador (nível 1) C4652](../../error-messages/compiler-warnings/compiler-warning-level-1-c4652.md)|opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual substituirá a definida no cabeçalho pré-compilado|
|[Aviso do compilador (nível 2) C4653](../../error-messages/compiler-warnings/compiler-warning-level-2-c4653.md)|opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual ignorada|
|Aviso do compilador (nível 4) C4654|Incluir código colocado antes de cabeçalho pré-compilado linha será ignorada. Adicione código ao cabeçalho pré-compilado.|
|Aviso do compilador (nível 1) C4655|'symbol': tipo de variável é novo desde a última compilação, ou é definido de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4656](../../error-messages/compiler-warnings/compiler-warning-level-1-c4656.md)|'symbol': tipo de dados é novo ou foi alterada desde a última compilação ou é definido de forma diferente em outro lugar|
|Aviso do compilador (nível 1) C4657|expressão envolve um tipo de dados é novo desde a última compilação|
|Aviso do compilador (nível 1) C4658|'function': protótipo de função é novo desde a última compilação, ou é declarado de forma diferente em outro lugar|
|[Aviso do compilador (nível 1) C4659](../../error-messages/compiler-warnings/compiler-warning-level-1-c4659.md)|#pragma 'pragma': uso de segmento reservado 'segmento' possui comportamento indefinido, use #pragma comment (linker,...)|
|[Aviso do compilador (nível 1) C4661](../../error-messages/compiler-warnings/compiler-warning-level-1-c4661.md)|'Identificador': nenhuma definição compatível fornecida para solicitação de instanciação de template explícitos|
|Aviso do compilador (nível 1) C4662|instanciação explícita; classe de template 'identifier1' não possui nenhuma definição de qual especializar 'identifier2'|
|[Aviso do compilador (nível 1) C4667](../../error-messages/compiler-warnings/compiler-warning-level-1-c4667.md)|'function': nenhum modelo de função definido que corresponda à instanciação forçada|
|[Aviso do compilador (nível 4) C4668](../../error-messages/compiler-warnings/compiler-warning-level-4-c4668.md)|'symbol' não está definido como uma macro de pré-processador, substituindo por '0' para 'diretiva'|
|[Aviso do compilador (nível 1) C4669](../../error-messages/compiler-warnings/compiler-warning-level-1-c4669.md)|'cast': conversão não segura: 'class' é um objeto de tipo gerenciado|
|Aviso do compilador (nível 4) C4670|'Identificador': esta classe base é inacessível|
|Aviso do compilador (nível 4) C4671|'Identificador': o construtor de cópia é inacessível|
|Aviso do compilador (nível 4) C4672|'identifier1': ambíguo. Visto primeiro como 'identifier2'|
|[Aviso do compilador (nível 4) C4673](../../error-messages/compiler-warnings/compiler-warning-level-4-c4673.md)|lançar 'Identificador' os seguintes tipos não será considerado no local de catch|
|Aviso do compilador (nível 1) C4674|'method' deve ser declarado como 'static' e ter exatamente um parâmetro|
|Aviso do compilador (nível 4) C4676|'%s'': o destruidor é inacessível|
|[Aviso do compilador (nível 1) C4677](../../error-messages/compiler-warnings/compiler-warning-level-1-c4677.md)|'function': assinatura de membro não private contém tipo private de assembly 'private_type'|
|Aviso do compilador (nível 1) C4678|classe base 'base_type' é menos acessível que 'derived_type'|
|[Aviso do compilador (nível 1) C4679](../../error-messages/compiler-warnings/compiler-warning-level-1-c4679.md)|'member': não foi possível importar membro|
|[Aviso do compilador (nível 4) C4680](../../error-messages/compiler-warnings/compiler-warning-level-4-c4680.md)|'class': coclass não especifica uma interface padrão|
|Aviso do compilador (nível 4) C4681|'class': coclass não especifica uma interface padrão que é uma origem de evento|
|Aviso do compilador (nível 4) C4682|'parameter': nenhum atributo de parâmetro direcional especificado, padronizando para [in]|
|[Aviso do compilador (nível 1) C4683](../../error-messages/compiler-warnings/compiler-warning-level-1-c4683.md)|'function': fonte de eventos possui um 'out'-parâmetro; Tome cuidado ao capturar vários manipuladores de eventos|
|[Aviso do compilador (nível 1) C4684](../../error-messages/compiler-warnings/compiler-warning-level-1-c4684.md)|'attribute': aviso!! atributo pode causar a geração de código inválido: use com cuidado|
|Aviso do compilador (nível 1) C4685|esperando ' >> ' encontrado ' >> ' ao analisar parâmetros de modelo|
|[Aviso do compilador (nível 3) C4686](../../error-messages/compiler-warnings/compiler-warning-level-3-c4686.md)|'user-defined type': possível alteração no comportamento, alteração na convenção de chamada de retorno UDT|
|[Compilador C4687 de aviso (erro)](../../error-messages/compiler-warnings/compiler-warning-c4687.md)|'class': uma classe sealed abstract não pode implementar uma interface 'interface'|
|Aviso do compilador (nível 1) C4688|'restrição de ': lista de restrições contém tipo private de assembly 'type'|
|Aviso do compilador (nível 1) C4689|'%c'': caractere em #pragma detect_mismatch; sem suporte #pragma ignorado|
|Aviso do compilador (nível 4) C4690|[ emitidl ( pop ) ]: mais ativações do que envios|
|[Aviso do compilador (nível 1) C4691](../../error-messages/compiler-warnings/compiler-warning-level-1-c4691.md)|'type': tipo referenciado era esperado no assembly não referenciado 'file', tipo definido na unidade de tradução atual usada|
|[Aviso do compilador (nível 1) C4692](../../error-messages/compiler-warnings/compiler-warning-level-1-c4692.md)|'function': assinatura de membro não privado contém tipo nativo privado de assembly 'native_type'|
|[Aviso do compilador (nível 1, erro) C4693](../../error-messages/compiler-warnings/compiler-warning-c4693.md)|'class': uma classe sealed abstract não pode ter qualquer instância membros 'membro de instância'|
|[Aviso do compilador (nível 1, erro) C4694](../../error-messages/compiler-warnings/compiler-warning-c4694.md)|'class': uma classe sealed abstract não pode ter uma classe base 'base_class'|
|Aviso do compilador (nível 1) C4695|#pragma execution_character_set: conjunto de caracteres não é um argumento com suporte: atualmente, apenas 'UTF-8' é suportado|
|Aviso do compilador (nível 1) C4696|/ Opção ZBvalue1 fora do intervalo; Supondo que 'value2'|
|[Aviso do compilador (níveis 1 e 4) C4700](../../error-messages/compiler-warnings/compiler-warning-level-1-and-level-4-c4700.md)|variável local não inicializado 'name' usado|
|[Aviso do compilador (nível 4) C4701](../../error-messages/compiler-warnings/compiler-warning-level-4-c4701.md)|variável local possivelmente não inicializada 'name' usado|
|[Aviso do compilador (nível 4) C4702](../../error-messages/compiler-warnings/compiler-warning-level-4-c4702.md)|Código inacessível|
|[Aviso do compilador (nível 4) C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)|variável de ponteiro local potencialmente não inicializada '%[NULL] s'usada|
|[Aviso do compilador (nível 4) C4706](../../error-messages/compiler-warnings/compiler-warning-level-4-c4706.md)|atribuição em expressão condicional|
|[Aviso do compilador (nível 4) C4709](../../error-messages/compiler-warnings/compiler-warning-level-4-c4709.md)|operador vírgula dentro de expressão de índice de matriz|
|[Aviso do compilador (nível 4) C4710](../../error-messages/compiler-warnings/compiler-warning-level-4-c4710.md)|'function': função não embutida|
|[Aviso do compilador (nível 1) C4711](../../error-messages/compiler-warnings/compiler-warning-level-1-c4711.md)|função 'function' selecionada para expansão inline automática|
|[Aviso do compilador (nível 4) C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md)|função 'function' marcada como forceinline não embutida|
|[Aviso do compilador (nível 1) C4715](../../error-messages/compiler-warnings/compiler-warning-level-1-c4715.md)|'function': nem todos os caminhos de controle retornam um valor|
|[Compilador C4716 de aviso (nível 1, erro)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4716.md)|'function': deve retornar um valor|
|[Aviso do compilador (nível 1) C4717](../../error-messages/compiler-warnings/compiler-warning-level-1-c4717.md)|'function': recursivo em todos os caminhos de controle, função causará estouro de pilha do tempo de execução|
|Aviso do compilador (nível 4) C4718|chamada de função: chamada recursiva não tem efeitos colaterais, excluindo|
|Aviso do compilador (nível 1) C4719|Constante Double encontrada com Qfast especificado - use 'f' como um sufixo para indicar precisão simples|
|Aviso do compilador (nível 2) C4720|relatórios do assembler em linha: 'message'|
|Aviso do compilador (nível 1) C4721|'function': não disponível como um intrínseco|
|Aviso do compilador (nível 1) C4722|'function': destruidor nunca retorna, possível perda de memória|
|[Aviso do compilador (nível 3) C4723](../../error-messages/compiler-warnings/compiler-warning-level-3-c4723.md)|possível divisão por 0|
|Aviso do compilador (nível 3) C4724|possível mod por 0|
|Aviso do compilador (nível 3) C4725|instrução pode ser incorreta em alguns Pentiums|
|[Aviso do compilador (nível 1) C4727](../../error-messages/compiler-warnings/compiler-warning-level-1-c4727.md)|PCH nomeado pch_file com mesmo carimbo de hora encontrado em obj_file_1 e obj_file_2.  Usando primeiro PCH.|
|Aviso do compilador (nível 1) C4728|/ Yl-option ignorada porque a referência PCH é necessária|
|Aviso do compilador (nível 4) C4729|função muito grande para o gráfico de fluxo com base em avisos|
|[Compilador (nível 1) de aviso C4730](../../error-messages/compiler-warnings/compiler-warning-level-1-c4730.md)aviso do compilador (nível 1) C4730|'main': misturar m64 e expressões podem resultar em código incorreto de ponto flutuante|
|[Aviso do compilador (nível 1) C4731](../../error-messages/compiler-warnings/compiler-warning-level-1-c4731.md)|'ponteiro': 'Registrar' modificado por código de assembly embutido de registro de ponteiro de quadro|
|Aviso do compilador (nível 1) C4732|intrínseco '%s'' não tem suporte nesta arquitetura|
|[Aviso do compilador (nível 1) C4733](../../error-messages/compiler-warnings/compiler-warning-level-1-c4733.md)|Asm embutido atribuindo para 'FS:0': manipulador não registrado como manipulador seguro|
|[Aviso do compilador (nível 3) C4738](../../error-messages/compiler-warnings/compiler-warning-level-3-c4738.md)|armazenando o resultado float de 32 bits na memória, possível perda de desempenho|
|Aviso do compilador (nível 1) C4739|referência à variável 'var' excede seu espaço de armazenamento|
|[Aviso do compilador (nível 4) C4740](../../error-messages/compiler-warnings/compiler-warning-level-4-c4740.md)|fluxo para dentro ou fora do código asm embutido suprime otimização global|
|[Aviso do compilador (nível 1) C4742](../../error-messages/compiler-warnings/compiler-warning-level-1-c4742.md)|'var' possui alinhamento diferente em 'file1' e 'file2': número e o número|
|[Aviso do compilador (nível 1) C4743](../../error-messages/compiler-warnings/compiler-warning-level-1-c4743.md)|'type' possui tamanho diferente em 'file1' e 'file2': número e o número de bytes|
|[Aviso do compilador (nível 1) C4744](../../error-messages/compiler-warnings/compiler-warning-level-1-c4744.md)|'var' possui tipo diferente em 'file1' e 'file2': 'type1' e 'type2'|
|[Aviso do compilador C4746](../../error-messages/compiler-warnings/compiler-warning-c4746.md)|acesso volátil de '*expressão*' está sujeito a /volatile:\<iso&#124;ms > Configuração; considere o uso de funções intrínsecas iso_volatile_load/store|
|[Aviso do compilador (nível 1) C4747](../../error-messages/compiler-warnings/compiler-warning-level-1-c4747.md)|Chamar 'entrypoint' gerenciado: código gerenciado não pode ser executado sob bloqueio do carregador, incluindo o ponto de entrada DLL e chamadas acessadas do ponto de entrada DLL|
|Aviso do compilador (nível 4) C4749|condicionalmente com suporte: offsetof aplicado a tipo de layout não standard '*tipo*'|
|Aviso do compilador (nível 1) C4750|'Identificador': função com alloca () embutida dentro de um loop|
|Aviso do compilador (nível 4) C4751|/arch: avx não se aplica a Intel (r) Extensões SIMD de Streaming que estão dentro de ASM embutido|
|Aviso do compilador (nível 4) C4752|encontrado Intel (r) Advanced Vector Extensions; Considere o uso de /arch: avx|
|Aviso do compilador (nível 4) C4754|Regras de conversão para operações aritméticas na comparação em significam que uma ramificação não pode ser executada. Converta '%s'' em '%s'' (ou tipo similar de %d bytes).|
|C4755 de aviso do compilador|Regras de conversão para operações aritméticas na comparação em significam que uma ramificação não pode ser executada em uma função embutida. Converta '%s'' em '%s'' (ou tipo similar de %d bytes).|
|[Aviso do compilador (nível 2) C4756](../../error-messages/compiler-warnings/compiler-warning-level-2-c4756.md)|Estouro em aritmética de constante|
|Aviso do compilador (nível 4) C4757|subscrito é um valor unsigned grande, você pretendia uma constante negativa?|
|Aviso do compilador (nível 4) C4764|Não é possível alinhar objetos catch maiores que 16 bytes|
|Aviso do compilador (nível 4) C4767|nome de seção '%s' tem mais de 8 caracteres e será truncado pelo vinculador|
|Aviso do compilador (nível 3) C4768|atributos de declspec antes de especificação de vinculação são ignorados|
|C4770 de aviso do compilador|enum parcialmente validada '*nome*' usada como índice|
|C4771 de aviso do compilador|Limites devem ser criados usando um ponteiro simple; Função intrínseca MPX ignorada|
|[Compilador C4772 de aviso (nível 1, erro)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4772.md)|#import referenciou um tipo de uma biblioteca de tipos faltando; 'missing_type' usado como um espaço reservado|
|Aviso do compilador (nível 4) C4774|'*cadeia de caracteres*': formato de cadeia de caracteres esperada no argumento *número* não é uma cadeia de caracteres literal|
|Aviso do compilador (nível 3) C4775|extensão não padrão usada na cadeia de caracteres de formato '*cadeia de caracteres*'da função'*função*'|
|Aviso do compilador (nível 1) C4776|' %*caracteres*'não é permitida na cadeia de formato da função'*função*'|
|Aviso do compilador (nível 4) C4777|'*função*': cadeia de caracteres de formato '*cadeia de caracteres*'exige um argumento do tipo'*type1*', mas o argumento variadic *número* tem o tipo '*type2*'|
|Aviso do compilador (nível 3) C4778|'*função*': não finalizada a cadeia de caracteres de formato '*cadeia de caracteres*'|
|[Aviso do compilador (nível 1) C4788](../../error-messages/compiler-warnings/compiler-warning-level-1-c4788.md)|'Identificador': identificador foi truncado para 'número' caracteres|
|[Aviso do compilador (nível 1) C4789](../../error-messages/compiler-warnings/compiler-warning-level-1-c4789.md)|Identificador de N bytes de tamanho do buffer será substituído; M bytes serão escritos começando no deslocamento L|
|Aviso do compilador (nível 2) C4792|função '%s' declarada usando sysimport e referenciada em código nativo; biblioteca de importação requerida para vínculo|
|[Aviso do compilador (níveis 1 e 3) C4793](../../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md)|'function': função compilada como nativa: \n\t'reason'|
|Aviso do compilador (nível 1) C4794|segmento de armazenamento local de thread variável '%[NULL] s'alterado de '%s' para '%s'|
|[Aviso do compilador (nível 1) C4799](../../error-messages/compiler-warnings/compiler-warning-level-1-c4799.md)|função 'function' não possui instrução EMMS|