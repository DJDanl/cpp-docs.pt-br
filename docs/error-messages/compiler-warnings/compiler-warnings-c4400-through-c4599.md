---
title: Avisos do compilador C4400 a C4599
ms.date: 04/21/2019
f1_keywords:
- C4413
- C4415
- C4416
- C4417
- C4418
- C4419
- C4421
- C4423
- C4424
- C4425
- C4426
- C4427
- C4438
- C4442
- C4443
- C4444
- C4446
- C4447
- C4448
- C4449
- C4450
- C4452
- C4453
- C4454
- C4455
- C4472
- C4474
- C4475
- C4476
- C4478
- C4480
- C4482
- C4483
- C4491
- C4492
- C4493
- C4494
- C4495
- C4496
- C4497
- C4498
- C4499
- C4509
- C4519
- C4531
- C4542
- C4562
- C4568
- C4569
- C4573
- C4574
- C4575
- C4582
- C4583
- C4585
- C4586
- C4587
- C4588
- C4591
- C4592
- C4593
- C4594
- C4595
helpviewer_keywords:
- C4413
- C4415
- C4416
- C4417
- C4418
- C4419
- C4421
- C4423
- C4424
- C4425
- C4426
- C4427
- C4438
- C4442
- C4443
- C4444
- C4446
- C4447
- C4448
- C4449
- C4450
- C4451
- C4452
- C4453
- C4454
- C4455
- C4456
- C4457
- C4459
- C4472
- C4474
- C4475
- C4476
- C4478
- C4480
- C4482
- C4483
- C4491
- C4492
- C4493
- C4494
- C4495
- C4496
- C4497
- C4498
- C4499
- C4509
- C4519
- C4531
- C4542
- C4562
- C4568
- C4569
- C4573
- C4574
- C4575
- C4582
- C4583
- C4585
- C4586
- C4587
- C4588
- C4591
- C4592
- C4593
- C4594
- C4595
ms.assetid: b07850a5-ae89-48ea-bf9a-f0e30939f9b9
ms.openlocfilehash: 9f7886a88ebd98d5d7ab1848ea7a788967362ad7
ms.sourcegitcommit: d3829ae0c3db909f96057755a80665f5ea4896ea
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2019
ms.locfileid: "69550446"
---
# <a name="compiler-warnings-c4400-through-c4599"></a>Avisos do compilador C4400 a C4599

Os artigos nesta seção da documentação explicam um subconjunto das mensagens de aviso que são geradas pelo compilador.

[!INCLUDE[error-boilerplate](../../error-messages/includes/error-boilerplate.md)]

## <a name="warning-messages"></a>Mensagens de aviso

|Aviso|Mensagem|
|-------------|-------------|
|[Aviso do compilador (nível 1) C4600](compiler-warning-level-1-c4600.md)|#pragma '*nome da macro*': esperada uma cadeia de caracteres não vazia válida|
|[Aviso do compilador (nível 4) C4400](../../error-messages/compiler-warnings/compiler-warning-level-4-c4400.md)|'*Type*': não há suporte para qualificadores const/volatile neste tipo|
|[Aviso do compilador (nível 1) C4401](../../error-messages/compiler-warnings/compiler-warning-level-1-c4401.md)|'área de bits ': membro é campo de bit|
|[Aviso do compilador (nível 1) C4402](../../error-messages/compiler-warnings/compiler-warning-level-1-c4402.md)|deve usar o operador PTR|
|[Aviso do compilador (nível 1) C4403](../../error-messages/compiler-warnings/compiler-warning-level-1-c4403.md)|operador PTR inválido|
|[Aviso do compilador (nível 3) C4404](../../error-messages/compiler-warnings/compiler-warning-level-3-c4404.md)|período na diretiva ignorado|
|[Aviso do compilador (nível 1) C4405](../../error-messages/compiler-warnings/compiler-warning-level-1-c4405.md)|'*Identifier*': o identificador é uma palavra reservada|
|[Aviso do compilador (nível 1) C4406](../../error-messages/compiler-warnings/compiler-warning-level-1-c4406.md)|operando na diretiva ignorado|
|[Aviso do compilador (nível 1) C4407](../../error-messages/compiler-warnings/compiler-warning-level-1-c4407.md)|conversão entre um ponteiro diferente para representações de membro, o compilador pode gerar código incorreto|
|[Aviso do compilador (nível 4) C4408](../../error-messages/compiler-warnings/compiler-warning-level-4-c4408.md)|' struct&#124;Union ' anônima não declarou nenhum membro de dados|
|[Aviso do compilador (nível 1) C4409](../../error-messages/compiler-warnings/compiler-warning-level-1-c4409.md)|tamanho de instrução inválido|
|[Aviso do compilador (nível 1) C4410](../../error-messages/compiler-warnings/compiler-warning-level-1-c4410.md)|tamanho ilegal para operando|
|[Aviso do compilador (nível 1) C4411](../../error-messages/compiler-warnings/compiler-warning-level-1-c4411.md)|'*Identifier*': símbolo resolve para registro de deslocamento|
|[Aviso do compilador (nível 2) C4412](../../error-messages/compiler-warnings/compiler-warning-level-2-c4412.md)|'*Function*': assinatura de função contém tipo '*Type*'; C++ os objetos não são seguros para passar entre o código puro e o misto ou nativo.|
|Aviso do compilador C4413|' ClassName:: member ': membro de referência é inicializado para um temporário que não persiste após o Construtor sair|
|[Aviso do compilador (nível 3) C4414](../../error-messages/compiler-warnings/compiler-warning-level-3-c4414.md)|'*Function*': salto curto para função convertido para Near|
|Aviso do compilador (nível 1) C4415|duplicate __declspec(code_seg('*name*'))|
|Aviso do compilador (nível 1) C4416|_ _ declspec (code_seg (...)) contém cadeia de caracteres vazia: ignorado|
|Aviso do compilador (nível 1) C4417|uma instanciação de modelo explícita não pode ter _ declspec (code_seg (...)): ignorado|
|Aviso do compilador (nível 1) C4418|_ _ declspec (code_seg (...)) ignorada em uma enumeração|
|Aviso do compilador (nível 3) C4419|'*Symbol*' não tem nenhum efeito quando aplicado à classe ref privada '*Class*'.|
|[Aviso do compilador (nível 1) C4420](../../error-messages/compiler-warnings/compiler-warning-level-1-c4420.md)|'*checked_operator*': operador não disponível, usando '*Operator*' em vez disso; a verificação de tempo de execução pode ser comprometida|
|Aviso do compilador (nível 3) C4421|'*Parameter*': um parâmetro de referência em uma função retomável é potencialmente inseguro|
|Aviso do compilador (nível 3) C4423|' std:: bad_alloc ': será capturado pela classe ('*Type*') no *número* de linha|
|Aviso do compilador (nível 3) C4424|Catch para '*type1*' precedido por '*type2*' no *número*de linha; um comportamento imprevisível pode ocorrer se ' std:: bad_alloc ' for gerado|
|Aviso do compilador (nível 1) C4425|Uma anotação SAL não pode ser aplicada a '... '|
|Aviso do compilador (nível 1) C4426|sinalizadores de otimização foram alterados após incluir o cabeçalho, pode ser devido a #pragma Optimize ()|
|Aviso do compilador (nível 1) C4427|'*Operator*': estouro na divisão constante, comportamento indefinido|
|[Aviso do compilador (nível 4) C4429](../../error-messages/compiler-warnings/compiler-warning-level-4-c4429.md)|nome de caractere universal formado incompleto ou incorretamente|
|[Aviso do compilador (erro) C4430](../../error-messages/compiler-warnings/compiler-warning-c4430.md)|faltando especificador de tipo - int assumido. Observação: C++Não dá suporte a default-int|
|[Aviso do compilador (nível 4) C4431](../../error-messages/compiler-warnings/compiler-warning-level-4-c4431.md)|faltando especificador de tipo - int assumido. Observação: C não dá mais suporte a default-int|
|[Aviso do compilador (nível 4) C4434](../../error-messages/compiler-warnings/compiler-warning-level-4-c4434.md)|um construtor estático deve ter acessibilidade privada; alterando para acesso privado|
|[Aviso do compilador (nível 4) C4435](../../error-messages/compiler-warnings/compiler-warning-level-4-c4435.md)|'*derived_class*': O layout do objeto em/vd2 será alterado devido à base virtual '*BASE_CLASS*'|
|[Aviso do compilador (nível 1) C4436](../../error-messages/compiler-warnings/compiler-warning-level-1-c4436.md)|a\_conversão dinâmica da base virtual '*BASE_CLASS*' para '*derived_class*' no construtor ou no destruidor pode falhar com o objeto parcialmente construído|
|[Aviso do compilador (nível 4) C4437](../../error-messages/compiler-warnings/compiler-warning-level-4-c4437.md)|a\_conversão dinâmica da base virtual '*BASE_CLASS*' para '*derived_class*' poderia falhar em alguns contextos|
|Aviso do compilador C4438|'*Function*': não pode ser chamado com segurança em/Await: modo clrcompat. Se as chamadas '*Function*' para o CLR, isso poderá resultar na corrupção da cabeça do CLR|
|[Aviso do compilador (erro) C4439](../../error-messages/compiler-warnings/compiler-warning-c4439.md)|'*Function*': a definição de função com um tipo gerenciado na assinatura deve ter uma Convenção de chamada ir_ clrcall|
|[Aviso do compilador (nível 1) C4440](../../error-messages/compiler-warnings/compiler-warning-level-1-c4440.md)|redefinição de Convenção de chamada de '*calling_convention1*' para '*calling_convenction2*' ignorada|
|[Aviso do compilador (nível 1) C4441](../../error-messages/compiler-warnings/compiler-warning-level-1-c4441.md)|Convenção de chamada de '*calling_convention1*' ignorada; '*calling_convention2*' usado em vez disso|
|Aviso do compilador (nível 1) C4442|terminador nulo inserido no argumento __annotation.  O valor será truncado.|
|Aviso do compilador (nível 1) C4443|esperado parâmetro de pragma como ' 0 ', ' 1 ' ou ' 2 '|
|Aviso do compilador (nível 3) C4444|'*Identifier*': o nível superior ' __unaligned ' não está implementado neste contexto|
|[Aviso do compilador (nível 1) C4445](../../error-messages/compiler-warnings/compiler-warning-level-1-c4445.md)|'*Function*': em um tipo '&#124;gerenciado por WinRT ', um método virtual não pode ser privado|
|Aviso do compilador (nível 1) C4446|'*Type*': não é possível mapear o membro '*Nome1*' para esse tipo, devido a conflito com o nome do tipo. O método foi renomeado para '*nome2*'|
|Aviso do compilador (nível 1) C4447|assinatura ' Main ' encontrada sem modelo de Threading. Considere o uso de ' int main (plataforma:\<: plataforma de matriz:: cadeia de caracteres ^ > ^ args) '.|
|Aviso do compilador C4448|'*Type*1 ' não tem uma interface padrão especificada nos metadados. Separação: '*type2*', que pode falhar em tempo de execução.|
|Aviso do compilador C4449|'*Type*' um tipo não lacrado deve ser marcado como ' [WebHostHidden] '|
|Aviso do compilador C4450|'*type1*' deve ser marcado como ' [WebHostHidden] ' porque deriva de '*type2*'|
|Aviso do compilador (nível 4) C4451|' classname1:: member ': O uso da classe ref ' classname2:: member ' dentro desse contexto pode levar a um marshaling inválido do objeto entre contextos|
|Aviso do compilador (nível 1) C4452|'*Identifier*': o tipo público não pode estar no escopo global. Ele deve estar em um namespace que seja um filho do nome do arquivo. winmd de saída.|
|Aviso do compilador (nível 1) C4453|'*Type*': Um tipo ' [WebHostHidden] ' não deve ser usado na superfície publicada de um tipo público que não seja ' [WebHostHidden] '|
|Aviso do compilador (nível 1) C4454|'*Function*' está sobrecarregado por mais do que o número de parâmetros de entrada sem ter [defaultoverload] especificado. Selecionando '*declaração*' como a sobrecarga padrão|
|Aviso do compilador (nível 1) C4455|' operator *Operator*': identificadores de sufixo literais que não começam com um sublinhado são reservados|
|[Aviso do compilador (nível 4) C4456](compiler-warning-level-4-c4456.md)|a declaração de '*Identifier*' oculta a declaração local anterior|
|[Aviso do compilador (nível 4) C4457](compiler-warning-level-4-c4457.md)|a declaração de '*Identifier*' oculta o parâmetro de função|
|[Aviso do compilador (nível 4) C4458](compiler-warning-level-4-c4458.md)|a declaração de '*Identifier*' oculta o membro da classe|
|[Aviso do compilador (nível 4) C4459](compiler-warning-level-4-c4459.md)|a declaração de '*Identifier*' oculta a declaração global|
|[Aviso do compilador (nível 4) C4460](../../error-messages/compiler-warnings/compiler-warning-level-4-c4460.md)|' Operator&#124;' gerenciado do WinRT', tem parâmetro passado por referência. O operador&#124;' gerenciado WinRT ' '*Operator*' tem semânticas diferentes C++ do operador '*cpp_operator*', você pretendia passar por valor?|
|[Aviso do compilador (nível 1) C4461](../../error-messages/compiler-warnings/compiler-warning-level-1-c4461.md)|'*ClassName*': esta classe tem um finalizador '! *finalizador*' mas nenhum destruidor ' ~*dtor*'|
|[Aviso do compilador (nível 1, erro) C4462](../../error-messages/compiler-warnings/compiler-warning-level-1-c4462.md)|'*Type*': não é possível determinar o GUID do tipo. O programa poderá falhar no tempo de execução.|
|[Aviso do compilador (nível 4) C4463](compiler-warning-level-4-c4463.md)|contra atribuindo '*Value*' ao campo de bits que só pode conter valores de '*MIN_VALUE*' para '*MAX_VALUE*'|
|[Aviso do compilador (nível 4) C4464](../../error-messages/compiler-warnings/c4464.md)|o caminho de inclusão relativo contém '.. '|
|[Aviso do compilador (nível 1) C4470](../../error-messages/compiler-warnings/compiler-warning-level-1-c4470.md)|pragmas de controle de ponto flutuante ignorados sob/CLR|
|[Aviso do compilador (nível 4) C4471](compiler-warning-level-4-c4471.md)|'*Enumeration*': uma declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)|
|Aviso do compilador (nível 1) C4472|'*Identifier*' é uma enumeração nativa: adicionar um especificador de acesso (privado/público) para declarar uma&#124;enumeração ' gerenciado do WinRT '|
|[Aviso do compilador (nível 1) C4473](c4473.md)|'*Function*': não foram passados argumentos suficientes para a cadeia de caracteres de formato|
|Aviso do compilador (nível 3) C4474|'*Function*': muitos argumentos passados para cadeia de caracteres de formato|
|Aviso do compilador (nível 3) C4475|'*Function*': o modificador de comprimento '*Modifier*' não pode ser usado com o caractere de campo de tipo '*Character*' no especificador de formato|
|Aviso do compilador (nível 3) C4476|'*Function*': tipo desconhecido de caractere de campo '*Character*' no especificador de formato|
|[Aviso do compilador (nível 1) C4477](c4477.md)|'*Function*': a cadeia de caracteres de formato '*String*' requer um argumento do tipo '*Type*', mas o *número* do argumento Variadic tem o tipo '*Type*'|
|Aviso do compilador (nível 1) C4478|'*Function*': espaços reservados posicionais e não posicionais não podem ser misturados na mesma cadeia de caracteres de formato|
|Aviso do compilador (erro) C4480|extensão não padrão usada: especificando o tipo subjacente para enumeração '*Enumeration*'|
|[Aviso do compilador (nível 4) C4481](../../error-messages/compiler-warnings/compiler-warning-level-4-c4481.md)|extensão não padrão usada: especificador de substituição '*palavra-chave*'|
|Aviso do compilador C4482|extensão não padrão usada: enumeração '*Enumeration*' usada em nome qualificado|
|Aviso do compilador (nível 1, erro) C4483|erro de sintaxe: C++ palavra-chave esperada|
|[Aviso do compilador (erro) C4484](../../error-messages/compiler-warnings/compiler-warning-c4484.md)|'*override_function*': corresponde ao método de classe ref base '*base_class_function*', mas não está marcado como ' virtual ', ' New ' ou ' override '; ' New ' (e not ' virtual ') é assumido|
|[Aviso do compilador (erro) C4485](../../error-messages/compiler-warnings/compiler-warning-c4485.md)|'*override_function*': corresponde ao método de classe ref base '*base_class_function*', mas não está marcado como ' New ' ou ' override '; ' New ' (e ' virtual ') é assumido|
|[Aviso do compilador (nível 1) C4486](../../error-messages/compiler-warnings/compiler-warning-level-1-c4486.md)|'*Function*': um método virtual privado de uma classe ref ou de uma classe value deve ser marcado como ' sealed '|
|[Aviso do compilador (nível 4) C4487](../../error-messages/compiler-warnings/compiler-warning-level-4-c4487.md)|'*derived_class_function*': corresponde ao método não virtual herdado '*base_class_function*', mas não está marcado explicitamente como ' New '|
|[Aviso do compilador (nível 1) C4488](../../error-messages/compiler-warnings/compiler-warning-level-1-c4488.md)|'*Function*': requer palavra-chave '*keyword*' para implementar o método de interface '*interface_method*'|
|[Aviso do compilador (nível 1) C4489](../../error-messages/compiler-warnings/compiler-warning-level-1-c4489.md)|'*especificador*': não permitido no método de interface '*Method*'; os especificadores de substituição só são permitidos em métodos de classe ref e de valor|
|[Aviso do compilador (nível 1) C4490](../../error-messages/compiler-warnings/compiler-warning-level-1-c4490.md)|' override ': uso incorreto de especificador de substituição; '*Function*' não corresponde a um método base ref class|
|Aviso do compilador (nível 1) C4491|'*Name*': tem um formato de versão IDL inválido|
|Aviso do compilador (nível 1, erro) C4492|'*function1*': corresponde ao método de classe ref base '*function2*', mas não está marcado como ' override '|
|Aviso do compilador (nível 3, erro) C4493|a expressão Delete não tem nenhum efeito, pois o destruidor de '*Type*' não tem acessibilidade ' pública '|
|Aviso do compilador (nível 1) C4494|'*função*': Ignorando _ declspec (alocador) porque o tipo de retorno da função não é um ponteiro ou uma referência|
|Aviso do compilador C4495|extensão não padrão ' __super ' usada: substituir pelo nome da classe base explícita|
|Aviso do compilador C4496|extensão não padrão ' para cada ' usada: substituir pela instrução Ranged-for|
|Aviso do compilador C4497|extensão não padrão ' sealed ' usada: substituir por ' final '|
|Aviso do compilador C4498|extensão não padrão usada: '*extensão*'|
|Aviso do compilador (nível 4) C4499|'*Function*': uma especialização explícita não pode ter uma classe de armazenamento (ignorada) "|
|[Aviso do compilador (nível 1) C4502](../../error-messages/compiler-warnings/compiler-warning-level-1-c4502.md)|'*especificação de vínculo*' requer o uso da palavra-chave ' extern ' e deve preceder todos os outros especificadores|
|[Aviso do compilador (nível 1) C4503](../../error-messages/compiler-warnings/compiler-warning-level-1-c4503.md)|'*Identifier*': tamanho de nome decorado excedido, o nome foi truncado|
|[Aviso do compilador (nível 4) C4505](../../error-messages/compiler-warnings/compiler-warning-level-4-c4505.md)|'*Function*': função local não referenciada foi removida|
|[Aviso do compilador (nível 1) C4506](../../error-messages/compiler-warnings/compiler-warning-level-1-c4506.md)|nenhuma definição para função embutida '*Function*'|
|[Aviso do compilador (nível 1) C4508](../../error-messages/compiler-warnings/compiler-warning-level-1-c4508.md)|'*Function*': a função deve retornar um valor; tipo de retorno ' void ' assumido|
|Aviso do compilador C4509|extensão não padrão usada: '*Function*' usa Seh e '*Object*' tem destruidor|
|[Aviso do compilador (nível 4) C4510](../../error-messages/compiler-warnings/compiler-warning-level-4-c4510.md)|'*Class*': o construtor padrão foi implicitamente definido como excluído|
|[Aviso do compilador (nível 3) C4511](../../error-messages/compiler-warnings/compiler-warning-level-3-c4511.md)|'*Class*': o construtor de cópia foi implicitamente definido como excluído|
|[Aviso do compilador (nível 4) C4512](../../error-messages/compiler-warnings/compiler-warning-level-4-c4512.md)|'*Class*': o operador de atribuição foi implicitamente definido como excluído|
|[Aviso do compilador (nível 4) C4513](../../error-messages/compiler-warnings/compiler-warning-level-4-c4513.md)|'*Class*': o destruidor foi implicitamente definido como excluído|
|[Aviso do compilador (nível 4) C4514](../../error-messages/compiler-warnings/compiler-warning-level-4-c4514.md)|'*Function*': função embutida não referenciada foi removida|
|[Aviso do compilador (nível 4) C4515](../../error-messages/compiler-warnings/compiler-warning-level-4-c4515.md)|'*namespace*': o namespace usa a si mesmo|
|[Aviso do compilador (nível 4) C4516](../../error-messages/compiler-warnings/compiler-warning-level-4-c4516.md)|' class:: Symbol ': declarações de acesso são preteridas; declarações using de membro fornecem uma alternativa melhor|
|[Aviso do compilador (nível 4) C4517](../../error-messages/compiler-warnings/compiler-warning-level-4-c4517.md)|declarações de acesso são preteridas; declarações using de membro fornecem uma alternativa melhor|
|[Aviso do compilador (nível 1) C4518](../../error-messages/compiler-warnings/compiler-warning-level-1-c4518.md)|'*especificador*': Storage-Class ou especificadores de tipo inesperados aqui; aceita|
|Aviso do compilador (erro) C4519|argumentos de modelo padrão são permitidos somente em um modelo de classe|
|[Aviso do compilador (nível 3) C4521](../../error-messages/compiler-warnings/compiler-warning-level-3-c4521.md)|'*Class*': vários construtores de cópia especificados|
|[Aviso do compilador (nível 3) C4522](../../error-messages/compiler-warnings/compiler-warning-level-3-c4522.md)|'*Class*': vários operadores de atribuição especificados|
|[Aviso do compilador (nível 3) C4523](../../error-messages/compiler-warnings/compiler-warning-level-3-c4523.md)|'*Class*': vários destruidores especificados|
|[Aviso do compilador (nível 1) C4526](../../error-messages/compiler-warnings/compiler-warning-level-1-c4526.md)|'*Function*': a função de membro static não pode substituir a função virtual '*função virtual*' override ignorada, a função virtual será ocultada|
|[Aviso do compilador (nível 1) C4530](../../error-messages/compiler-warnings/compiler-warning-level-1-c4530.md)|C++manipulador de exceção usado, mas semântica de liberação não está habilitada. Especificar/EHsc|
|Aviso do compilador (nível 1) C4531|C++manipulação de exceção não disponível em Windows CE. Usar manipulação de exceção estruturada|
|[Aviso do compilador (nível 1) C4532](../../error-messages/compiler-warnings/compiler-warning-level-1-c4532.md)|' continue ': salto para fora do bloco ' __finally/Finally ' tem comportamento indefinido durante tratamento de encerramento|
|[Aviso do compilador (nível 1) C4533](../../error-messages/compiler-warnings/compiler-warning-level-1-c4533.md)|a inicialização de '*Variable*' é ignorada por '*goto Label*'|
|[Aviso do compilador (nível 3) C4534](../../error-messages/compiler-warnings/compiler-warning-level-3-c4534.md)|'*constructor*' não será um construtor padrão para o*identificador*' Class/struct ' ' devido ao argumento padrão|
|[Aviso do compilador (nível 3) C4535](../../error-messages/compiler-warnings/compiler-warning-level-3-c4535.md)|chamar _set_se_translator () requer/EHa|
|[Aviso do compilador (nível 4) C4536](../../error-messages/compiler-warnings/compiler-warning-level-4-c4536.md)|'*TypeName*': o nome de tipo excede o limite de metadados de '*character_limit*' caracteres|
|[Aviso do compilador (nível 1) C4537](../../error-messages/compiler-warnings/compiler-warning-level-1-c4537.md)|'*Object*': '. ' aplicado a tipo não UDT|
|[Aviso do compilador (nível 3) C4538](../../error-messages/compiler-warnings/compiler-warning-level-3-c4538.md)|'*Type*': não há suporte para qualificadores const/volatile neste tipo|
|[Aviso do compilador (nível 1) C4540](../../error-messages/compiler-warnings/compiler-warning-level-1-c4540.md)|dynamic_cast usado para converter em base inacessível ou ambígua; o teste de tempo de execução falhará ('*type1*' para '*type2*')|
|[Aviso do compilador (nível 1) C4541](../../error-messages/compiler-warnings/compiler-warning-level-1-c4541.md)|'*Identifier*' usado no tipo polimórfico '*Type*' com/gr-; pode ocorrer um comportamento imprevisível|
|Aviso do compilador (nível 1) C4542|Ignorando a geração de arquivo de texto injetado mesclado, não é possível gravar o arquivo *filetype* : '*Issue*': *mensagem*|
|[Aviso do compilador (nível 3) C4543](../../error-messages/compiler-warnings/compiler-warning-level-3-c4543.md)|Texto injetado suprimido pelo atributo ' no\_injected_text '|
|[Aviso do compilador (nível 1) C4544](../../error-messages/compiler-warnings/compiler-warning-level-1-c4544.md)|'*declaração*': argumento de modelo padrão ignorado nesta declaração de modelo|
|[Aviso do compilador (nível 1) C4545](../../error-messages/compiler-warnings/compiler-warning-level-1-c4545.md)|expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos|
|[Aviso do compilador (nível 1) C4546](../../error-messages/compiler-warnings/compiler-warning-level-1-c4546.md)|faltando lista de argumentos na chamada de função antes da vírgula|
|[Aviso do compilador (nível 1) C4547](../../error-messages/compiler-warnings/compiler-warning-level-1-c4547.md)|'*Operator*': o operador antes da vírgula não tem efeito; operador esperado com efeito colateral|
|[Aviso do compilador (nível 1) C4548](../../error-messages/compiler-warnings/compiler-warning-level-1-c4548.md)|expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral|
|[Aviso do compilador (nível 1) C4549](../../error-messages/compiler-warnings/compiler-warning-level-1-c4549.md)|'*Operator*': o operador antes da vírgula não tem efeito; Você pretendia '*Operator*'?|
|[Aviso do compilador (nível 1) C4550](../../error-messages/compiler-warnings/compiler-warning-level-1-c4550.md)|a expressão é avaliada como uma função que não tem uma lista de argumentos|
|[Aviso do compilador (nível 1) C4551](../../error-messages/compiler-warnings/compiler-warning-level-1-c4551.md)|lista de argumentos ausente na chamada de função|
|[Aviso do compilador (nível 1) C4552](../../error-messages/compiler-warnings/compiler-warning-level-1-c4552.md)|'*Operator*': operador não tem efeito; operador esperado com efeito colateral|
|[Aviso do compilador (nível 1) C4553](../../error-messages/compiler-warnings/compiler-warning-level-1-c4553.md)|'*Operator*': operador não tem efeito; Você pretendia ' operator?|
|[Aviso do compilador (nível 3) C4554](../../error-messages/compiler-warnings/compiler-warning-level-3-c4554.md) C4554|'*Operator*': verificar a precedência de operador para possível erro; Use parênteses para esclarecer a precedência|
|[Aviso do compilador (nível 1) C4555](../../error-messages/compiler-warnings/compiler-warning-level-1-c4555.md)|expressão não tem efeito; expressão esperada com efeito colateral|
|[Aviso do compilador (nível 1) C4556](../../error-messages/compiler-warnings/compiler-warning-level-1-c4556.md)|o valor do argumento imediato intrínseco '*Value*' está fora do intervalo '*lower_bound* - *upper_bound*'|
|[Aviso do compilador (nível 3) C4557](../../error-messages/compiler-warnings/compiler-warning-level-3-c4557.md)|' __assume ' contém efeito '*Effect*'|
|[Aviso do compilador (nível 1) C4558](../../error-messages/compiler-warnings/compiler-warning-level-1-c4558.md)|o valor do operando '*Value*' está fora do intervalo '*lower_bound* - *upper_bound*'|
|[Aviso do compilador (nível 4) C4559](../../error-messages/compiler-warnings/compiler-warning-level-4-c4559.md)|'*função*': redefinição; a função obtém _ declspec (modificador)|
|[Aviso do compilador (nível 1) C4561](../../error-messages/compiler-warnings/compiler-warning-level-1-c4561.md)|' __fastcall ' incompatível com a opção '/CLR ': convertendo para ' __stdcall '|
|Aviso do compilador (nível 4) C4562|funções com protótipo total são necessárias com a opção '/CLR ': convertendo ' () ' para ' (void) '|
|[Aviso do compilador (nível 4) C4564](../../error-messages/compiler-warnings/compiler-warning-level-4-c4564.md)|o método '*Method*' de ' class ' '*ClassName*' define um parâmetro padrão sem suporte '*Parameter*'|
|[Aviso do compilador (nível 4) C4565](../../error-messages/compiler-warnings/compiler-warning-level-4-c4565.md)|'*função*': redefinição; o símbolo foi declarado anteriormente com _ declspec (modificador)|
|[Aviso do compilador (nível 1) C4566](../../error-messages/compiler-warnings/compiler-warning-level-1-c4566.md)|o caractere representado pelo nome de caractere universal '*Char*' não pode ser representado na página de código atual (*número*)|
|Aviso do compilador (nível 1) C4568|'*Function*': nenhum membro corresponde à assinatura da substituição explícita|
|Aviso do compilador (nível 3) C4569|'*Function*': nenhum membro corresponde à assinatura da substituição explícita|
|[Aviso do compilador (nível 3) C4570](../../error-messages/compiler-warnings/compiler-warning-level-3-c4570.md)|'*Type*': não é declarado explicitamente como abstract, mas tem funções abstract|
|[Aviso do compilador (nível 4) C4571](../../error-messages/compiler-warnings/compiler-warning-level-4-c4571.md)|Informação: a semântica catch (...) foi alterada desde o C++ Visual 7,1; as exceções estruturadas (SEH) não são mais detectadas|
|[Aviso do compilador (nível 1) C4572](../../error-messages/compiler-warnings/compiler-warning-level-1-c4572.md)|O atributo [ParamArray] está preterido em/CLR, use '... ' Stead|
|Aviso do compilador (nível 1) C4573|o uso de "*função lambda*" requer que o compilador Capture "This", mas o modo de captura padrão atual não permite|
|Aviso do compilador (nível 4) C4574|'*Identifier*' está definido como ' 0 ': você quis dizer usar ' #if identifier '?|
|Aviso do compilador (nível 1) C4575|' __vectorcall ' incompatível com a opção '/CLR ': convertendo para ' __stdcall '|
|Aviso do compilador (nível 1, erro) C4576|um tipo entre parênteses seguido por uma lista de inicializadores é uma sintaxe de conversão de tipo explícito não padrão|
|Aviso do compilador (nível 1, desativado) C4577|' noexcept ' usado sem modo de tratamento de exceção especificado; a rescisão na exceção não é garantida. Especificar/EHsc|
|Aviso do compilador (nível 1, erro) C4578|' ABS ': conversão de '*type1*' para '*type2*', possível perda de dados (você pretendia chamar '*Function*' ou para #include \<cmath >?)|
|[Aviso do compilador (nível 3) C4580](../../error-messages/compiler-warnings/compiler-warning-level-3-c4580.md)|[attribute] é preterido; em vez disso, especifique System:: Attribute ou Platform:: Metadata como uma classe base|
|[Aviso do compilador (nível 1) C4581](../../error-messages/compiler-warnings/compiler-warning-level-1-c4581.md)|comportamento preterido: ' "*String*" ' substituído por '*String*' para processar o atributo|
|Aviso do compilador (nível 4) C4582|'*Type*': o construtor não é chamado implicitamente|
|Aviso do compilador (nível 4) C4583|'*Type*': o destruidor não é chamado implicitamente|
|[Aviso do compilador (nível 1) C4584](../../error-messages/compiler-warnings/compiler-warning-level-1-c4584.md)|'*Class1*': classe base '*class2*' já é uma classe base de '*class3*'|
|Aviso do compilador (nível 1, erro) C4585|'*Class*': Uma ' classe ref pública ' do WinRT deve ser sealed ou derive de uma classe sem lacre existente|
|Aviso do compilador (nível 1, erro) C4586|'*Type*': Um tipo público não pode ser declarado em um namespace de nível superior chamado ' Windows '|
|Aviso do compilador (nível 1) C4587|'*anonymous_structure*': alteração de comportamento: o construtor não é mais implicitamente chamado|
|Aviso do compilador (nível 1) C4588|'*anonymous_structure*': alteração de comportamento: o destruidor não é mais implicitamente chamado|
|Aviso do compilador (nível 1) C4591|o limite de profundidade de chamada ' constexpr ' do *número* foi excedido (\</constexpr: número de profundidade >)|
|Aviso do compilador (nível 3) C4592|'*Function*': falha na avaliação da chamada ' constexpr '; a função será chamada em tempo de execução|
|Aviso do compilador (nível 1) C4593|'*função*': o limite de '*limite*' da etapa de avaliação da chamada ' constexpr ' foi excedido; Use/constexpr: número\<de etapas > para aumentar o limite|
|Aviso do compilador (nível 3) C4594|'*Type*': o destruidor não será chamado implicitamente se uma exceção for lançada|
|Aviso do compilador (nível 1) C4595|'*Type*': alteração de comportamento: o destruidor não será mais chamado implicitamente se uma exceção for gerada|
|[Aviso do compilador (nível 4) C4596](../../error-messages/compiler-warnings/c4596.md)|'*Identifier*': nome qualificado inválido em declaração de membro|
|Aviso do compilador (erro) C4597|comportamento indefinido: offsetof aplicado a um membro de uma base virtual|
|Aviso do compilador (nível 1 e nível 3) C4598|*cabeçalho*' #include "" ': o *número* de número de cabeçalho no cabeçalho pré-compilado não corresponde à compilação atual nessa posição|
|Aviso do compilador (nível 3) C4599|'*Flag* *Path*': o *número* de número do argumento de linha de comando não corresponde ao cabeçalho pré-compilado|

## <a name="see-also"></a>Consulte também

[Erros eC++ avisos do C/compilador e ferramentas de compilação](../compiler-errors-1/c-cpp-build-errors.md) \
[Avisos do compilador C4000-C5999](compiler-warnings-c4000-c5999.md)
