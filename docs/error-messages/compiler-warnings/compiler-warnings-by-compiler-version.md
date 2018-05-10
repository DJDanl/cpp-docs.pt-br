---
title: Avisos do compilador pela versão do compilador | Microsoft Docs
ms.custom: ''
ms.date: 01/31/2018
ms.technology:
- devlang-cpp
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- warnings, by compiler version
- cl.exe compiler, setting warning options
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 789121e3adb42cb74087339bb33bb82cb7604a10
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warnings-by-compiler-version"></a>Avisos do compilador pela versão do compilador

O compilador pode suprimir avisos introduzidos após uma versão que você especificar usando o [/Wv](../../build/reference/compiler-option-warning-level.md) opção de compilador. Isso é útil para gerenciar o processo de compilação quando você introduz uma nova versão do conjunto de ferramentas e deseja suprimir temporariamente novos avisos. Essa opção suprime as novas mensagens de erro. Não é recomendável que você Suprimir todos os avisos de novo permanentemente! É recomendável que você sempre compilar no mais alto nível de aviso regular, __/W4__e remover o __/Wv__ opção em sua compilação assim que possível. 

Essas versões do compilador introduziu novos avisos:

| Produto | Número de versão do compilador |
|-|-|
| Visual C++ 2002 | 13.00.9466 |
| Visual C++ 2003 | 13.10.3077 |
| Visual C++ 2005 | 14.00.50727.762 |
| Visual C++ 2008 | 15.00.21022.08 |
| Visual C++ 2010 | 16.00.40219.01 |
| O Visual C++ 2012 | 17.00.51106.1 |
| Visual C++ 2013 | 18.00.21005.1 |
| RTM de 2015 do Visual C++ | 19.00.23026.0 |
| Visual C++ 2015 atualização 1 | 19.00.23506.0 |
| Visual C++ 2015 atualização 2 | 19.00.23918.0 |
| Visual C++ 2015 atualização 3 | 19.00.24215.1 |
| RTM de 2017 do Visual C++ | 19.10.24903.0 |
| Visual C++ 2017 versão 15.1 | 19.10.25017.0 |
| Versão 15,3 2017 de Visual C++ | 19.11.25506.0 |
| Versão 15,5 2017 de Visual C++ | 19.12.25827.0 |

Você pode especificar somente o número principal, os números principais e secundários ou major, minor e números de compilação de __/Wv__ opção. O compilador relata todos os avisos que correspondem a versões que começam com o número especificado e suprime todos os avisos para versões maiores do que o número especificado. Por exemplo, __/Wv:17__ relata todos os avisos introduzidos em ou antes de qualquer versão do Visual Studio 2012 e suprime todos os avisos introduzidos por qualquer compilador do Visual Studio 2013 (versão de 18) ou posterior. Para suprimir avisos introduzidos no Visual Studio 2015 atualização 2 e posterior, você pode usar __/Wv:19.00.23506__. Use __/Wv:19.11__ para relatar todos os avisos introduzidos em qualquer versão do Visual Studio antes do Visual Studio 2017 versão 15,5, mas suprime avisos introduzidos no Visual Studio 2017 versão 15.5 e posteriores.

As seções a seguir listam os avisos introduzidos por cada versão do Visual C++ que você pode suprimir usando o __/Wv__ opção de compilador. O __/Wv__ opção não é possível suprimir avisos que não estão listados, qual anteriores as versões especificadas do compilador.

## <a name="warnings-introduced-in-visual-c-2017-version-155-compiler-version-1912258270"></a>Avisos introduzidos no Visual C++ 2017 versão 15,5 (versão do compilador 19.12.25827.0)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:19.11__.

|||
|-|-|
C5044|Um argumento para a opção de linha de comando *opção* aponta para um caminho '*caminho*' que não existe

## <a name="warnings-introduced-in-visual-c-2017-version-153-compiler-version-1911255060"></a>Avisos introduzidos no Visual C++ 2017 versão 15,3 (versão do compilador 19.11.25506.0)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:19.10__.

|||
|-|-|
C4843|'*type1*': um manipulador de exceção de referência para o tipo de matriz ou a função está inacessível, use '*type2*' em vez disso
C4844|' Exportar módulo *nome_de_módulo*;' agora é a sintaxe preferencial para declarar uma interface de módulo
C5039|'*função*': ponteiro ou referência para gerar potencialmente função passado para função de extern do C em - EHc. Um comportamento indefinido pode ocorrer se essa função lança uma exceção.
C5040|especificações de exceções dinâmicas são válidas somente no C++ 14 e versões anteriores; Tratando como noexcept(false)
C5041|'*definição*': definição de fora de linha para o membro de dados estáticos constexpr não é necessário e está preterida no C++ 17
C5042|'*declaração*': declarações de função no escopo de bloco não podem ser especificado 'inline' em C++ padrão, remova o especificador 'inline'
C5043|'*especificação*': especificação de exceção não corresponde à declaração anterior

## <a name="warnings-introduced-in-visual-c-2017-version-151-compiler-version-1910250170"></a>Avisos introduzidos no Visual C++ 2017 versão 15.1 (versão do compilador 19.10.25017.0)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:19.10.24903__.

|||
|-|-|
C4597|comportamento indefinido: *descrição*
C4604|'*tipo*': passar o argumento por valor através do limite nativo e gerenciado requer o construtor de cópia válida. Caso contrário, o comportamento de tempo de execução é indefinido
C4749|condicionalmente com suporte: *descrição*
C4768|atributos de declspec antes de especificação de vinculação são ignorados
C4834|Descartando o valor de retorno da função com o atributo 'nodiscard'
C4841|extensão não padrão usada: *extensão*
C4842|o resultado de 'offsetof' aplicado a um tipo usando várias heranças não é garantido para ser consistente entre as versões do compilador
C4869|'nodiscard' só pode ser aplicado a classes, enumerações e funções com tipo de retorno não void
C5033|'*classe de armazenamento*' não é uma classe de armazenamento com suporte
C5034|o uso de intrínseco '*intrínseco*' faz com que a função *função* a ser compilado como código do convidado
C5035|o uso de recurso '*recurso*' faz com que a função *função* a ser compilado como código do convidado
C5036|conversão de ponteiro de função varargs ao compilar com /hybrid:x86arm64 '*type1*'para'*type2*'
C5037|'*função de membro*': uma definição de fora de linha de um membro de um modelo de classe não pode ter argumentos padrão
C5038|membro de dados '*membro1*'serão inicializados após o membro de dados'*membro2*'

## <a name="warnings-introduced-in-visual-c-2017-rtm-compiler-version-191024903"></a>Avisos introduzidos no Visual C++ 2017 RTM (versão do compilador 19.10.24903)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:19.00__.

|||
|-|-|
C4468|'fallthrough': atributo deve ser seguido por um rótulo case ou um rótulo padrão
C4698|'*recurso*' é para fins de avaliação e está sujeita a alterações ou remoção em futuras atualizações.
C4839|uso não padrão da classe*classe*' como um argumento para uma função variadic
C4840|uso de não-portáteis de classe*classe*' como um argumento para uma função variadic

## <a name="warnings-introduced-in-visual-c-2015-update-3-compiler-version-1900242151"></a>Avisos introduzidos no Visual C++ 2015 atualização 3 (versão do compilador 19.00.24215.1)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:19.00.23918__.

|||
|-|-|
C4467|uso de atributos de ATL foi preterido
C4596|'*nome*': nome qualificado inválido na declaração de membro
C4598|' #include \< *cabeçalho*\>': o número de cabeçalho *número* no *fonte* não coincide com *fonte* em que posição
C4599|'*argumento*': *fonte* o número de argumento *número* não coincide com *fonte*

## <a name="warnings-introduced-in-visual-c-2015-update-2-compiler-version-1900239180"></a>Avisos introduzidos no Visual C++ 2015 atualização 2 (versão do compilador 19.00.23918.0)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:19.00.23506__.

|||
|-|-|
C4466|Não foi possível executar o heap de corrotina corrotina
C4595|'*classe*': operador não membro novo ou funções de exclusão não podem ser declaradas em linha
C4828|O arquivo contém um caractere que inicia no deslocamento 0 x*valor* que é ilegal no conjunto de caracteres de origem atual (página de código *número*).
C4868|compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicializadores entre chaves

## <a name="warnings-introduced-in-visual-c-2015-update-1-compiler-version-1900235060"></a>Avisos introduzidos no Visual C++ 2015 atualização 1 (versão do compilador 19.00.23506.0)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:19.00.23026__.

|||
|-|-|
C4426|os sinalizadores de otimização alterados após incluir o cabeçalho, pode ser devido a #pragma optimize()
C4654|Incluir código colocado antes de cabeçalho pré-compilado linha será ignorada. Adicione código ao cabeçalho pré-compilado.
C5031|Warning (POP) #pragma: provável incompatibilidade, estado de aviso enviado em outro arquivo mostrado
C5032|detectado Warning (push) #pragma com nenhuma Warning (POP) #pragma correspondente

## <a name="warnings-introduced-in-visual-c-2015-rtm-compiler-version-1900230260"></a>Avisos introduzidos no Visual C++ 2015 RTM (versão do compilador 19.00.23026.0)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/wv: 18__.

|||
|-|-|
C4427|'*erro*': estouro na divisão constante, comportamento indefinido
C4438|'*tipo*': não pode ser chamado com segurança /await: clrcompat modo. Se '*tipo*' chamadas o CLR, isso pode resultar em corrupção CLR
C4455|' operador *nome*': identificadores de sufixos literais que não começam com um sublinhado são reservados
C4456|declaração de '*nome*' oculta uma declaração local anterior
C4457|declaração de '*nome*' oculta um parâmetro de função
C4458|declaração de '*nome*' oculta o membro da classe
C4459|declaração de '*nome*' oculta uma declaração global
C4462|'*tipo*': não é possível determinar o GUID do tipo. O programa poderá falhar no tempo de execução.
C4463|estouro; atribuindo *valor* para o campo de bits que pode conter apenas valores de *valor* para *valor*
C4473|'*função*': não há argumentos suficientes passado para a cadeia de caracteres de formato
C4474|'*função*': muitos argumentos passados para a cadeia de caracteres de formato
C4475|'*função*': modificador de comprimento '*modificador*'não pode ser usado com o caractere de campo do tipo'*caracteres*' especificador de formato
C4476|'*função*': caractere de campo de tipo desconhecido '*caracteres*' especificador de formato
C4477|'*função*': cadeia de caracteres de formato '*cadeia de caracteres*'exige um argumento do tipo'*tipo*', mas o argumento variadic *número* tem o tipo '*tipo*'
C4478|'*função*': espaços reservados posicionais e não posicionais não podem ser misturados na mesma cadeia de caracteres de formato
C4494|'*tipo*': ignorando __declspec(allocator) porque o tipo de retorno de função não é um ponteiro ou referência
C4495|extensão não padrão super' utilizada: substitua pelo nome de classe base explícito
C4496|extensão não padrão 'for each' usada: substitua por instrução intervalo-para
C4497|extensão não padrão 'selada' usada: Substituir por 'final'
C4498|extensão não padrão usada: '*extensão*'
C4499|'*especialização*': uma especialização explícita não pode ter uma classe de armazenamento (ignorada)
C4576|um tipo entre parênteses seguido por uma lista de inicializadores é uma sintaxe de conversão de tipo explícito não padrão
C4577|'noexcept' usado com nenhum especificado; o modo de manipulação de exceção não é garantia de terminação na exceção. Especifique /EHsc
C4578|'abs': conversão de '*tipo*'para'*tipo*', possível perda de dados (você pretendia chamar '*nome*' ou #include <cmath>?)
C4582|'*tipo*': construtor não é chamado implicitamente
C4583|'*tipo*': destrutor não está chamado implicitamente
C4587|'*tipo*': alteração de comportamento: construtor é não mais implicitamente chamado
C4588|'*tipo*': alteração de comportamento: destruidor é não mais implicitamente chamado
C4589|Construtor de classe abstrata*tipo*'ignora o inicializador de classe base virtual'*tipo*'
C4591|limite de profundidade de chamada de 'constexpr' *número* excedido (/ /constexpr: Depth<NUMBER>)
C4592|'*tipo*': símbolo será dinamicamente inicializado (limitação de implementação)
C4593|'*tipo*': limite de etapa de avaliação de chamada 'constexpr' de *valor* excedido; use /constexpr: Steps<NUMBER> para aumentar o limite
C4647|alteração de comportamento: is_pod (*tipo*) tem um valor diferente em versões anteriores
C4648|o atributo padrão 'carries_dependency' é ignorado
C4649|atributos são ignorados nesse contexto
C4753|Não é possível encontrar limites para ponteiro; Função intrínseca MPX ignorada
C4771|Limites devem ser criados usando um ponteiro simple; Função intrínseca MPX ignorada
C4774|'*descrição*': formato de cadeia de caracteres esperada no argumento *número* não é uma cadeia de caracteres literal
C4775|extensão não padrão usada na cadeia de caracteres de formato '*cadeia de caracteres*'da função'*função*'
C4776|' %*caracteres*'não é permitida na cadeia de formato da função'*função*'
C4777|'*descrição*': cadeia de caracteres de formato '*cadeia de caracteres*'exige um argumento do tipo'*tipo*', mas o argumento variadic *número* tem o tipo '*tipo*'
C4778|'*descrição*': não finalizada a cadeia de caracteres de formato '*cadeia de caracteres*'
C4838|conversão de '*tipo*'para'*tipo*' requer uma conversão de restrição
C5022|'*tipo*': vários construtores de movimento especificados
C5023|'*tipo*': vários operadores de atribuição de movimento especificados
C5024|'*declaração*': construtor de movimento foi implicitamente definido como excluído
C5025|'*declaração*': mover o operador de atribuição foi implicitamente definido como excluído
C5026|'*tipo*': construtor de movimento foi implicitamente definido como excluído
C5027|'*tipo*': mover o operador de atribuição foi implicitamente definido como excluído
C5028|'*nome*': alinhamento especificado na declaração anterior (*número*) não especificado na definição
C5029|extensão não padrão usada: atributos de alinhamento no C++ se aplicam a variáveis, membros de dados e somente os tipos de marcas
C5030|atributo '*atributo*' não é reconhecido

## <a name="warnings-introduced-in-visual-c-2013-compiler-version-1800210051"></a>Avisos introduzidos no Visual C++ 2013 (versão do compilador 18.00.21005.1)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:17__.

|||
|-|-|
C4301|'*tipo*': função virtual de substituição difere somente '*declaração*' pelo qualificador const/volatile
C4316|'*tipo*': alocado no heap de objeto pode não estar alinhado *número*
C4380|'*tipo*': um construtor padrão não pode ser substituído.
C4388|'*token*': incompatibilidade assinada/não assinada
C4423|'std:: bad_alloc': será capturado pela classe ('*tipo*') na linha *número*
C4424|Catch para '*tipo*'precedido por'*tipo*' na linha *número*; imprevisível pode resultar em comportamento se 'std:: bad_alloc' for lançada
C4425|Uma anotação SAL não pode ser aplicada a '...'
C4464|caminho de inclusão relativo contém '... '
C4575|vectorcall' incompatível com o ' / clr' opção: convertendo para stdcall'
C4609|'*tipo*'deriva de interface padrão'*tipo*'no tipo'*tipo*'. Use uma interface padrão diferente para '*tipo*', ou divida a relação de base/derivada.
C4754|Regras de conversão para operações aritméticas na comparação em *descrição*(*número*) significam que uma ramificação não pode ser executada. Conversão de '*tipo*'para'*tipo*' (ou tipo similar de *número* bytes).
C4755|Regras de conversão para operações aritméticas na comparação em *descrição*(*número*) significa que uma ramificação não pode ser executada em uma função embutida. Conversão de '*tipo*'para'*tipo*' (ou tipo similar de *número* bytes).
C4767|nome da seção '*nome*' tem mais de 8 caracteres e será truncado pelo vinculador
C4770|enum parcialmente validada '*nome*' usada como índice
C4827|Um método 'ToString' público com 0 parâmetro deve ser marcado como virtual e substituir
C4882|transmissão de functors com operadores de chamada não constantes para Concurrency:: parallel_for_each foi preterida
C4973|'*tipo*': marcado como preterido
C4974|'*tipo*': marcado como preterido
C4981|Warbird: função '*declaração*' marcada como forceinline não embutida porque contém semântica de exceção
C4990|Warbird: *mensagem*
C4991|Warbird: função '*declaração*' marcada como forceinline não embutida porque o nível de proteção do item embutido é superior do pai
C4992|Warbird: função '*declaração*' marcada como forceinline não embutida porque contém assembly embutido que não pode ser protegido

## <a name="warnings-introduced-in-visual-c-2012-compiler-version-1700511061"></a>Avisos introduzidos no Visual C++ 2012 (versão do compilador 17.00.51106.1)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:16__.

|||
|-|-|
C4330|atributo '*atributo*'para a seção'*seção*' ignorado
C4415|duplicate __declspec(code_seg('*name*'))
C4416|__declspec(code_seg(...)) contém a cadeia de caracteres vazia: ignorado
C4417|uma instanciação de modelo explícita não pode ter __declspec(code_seg(...)): ignorado
C4418|__declspec(code_seg(...)) ignorada no enum
C4419|'*nome*'não tem nenhum efeito quando aplicado a classe ref privada'*tipo*'.
C4435|'*tipo*': layout de objeto em /vd2 será alterado devido à base virtual '*tipo*'
C4436|dynamic_cast da base virtual '*tipo*'para'*tipo*' no construtor ou destruidor poderia falhar com o objeto parcialmente construído
C4437|dynamic_cast da base virtual '*tipo*'para'*tipo*' pode falhar em alguns contextos
C4443|parâmetro pragma esperado como '0', '1' ou '2'
C4446|'*tipo*': não é possível mapear o membro '*nome*' para este tipo devido a conflito com o nome do tipo. O método foi renomeado para '*nome*'
C4447|assinatura 'main' encontrada sem modelo de threading. Considere o uso de ' int principal (Platform:: array\<Platform:: String ^ > ^ args)'.
C4448|'*tipo*' não tem uma interface padrão especificada nos metadados. Separação: '*tipo*', que podem falhar em tempo de execução.
C4449|'*tipo*' um tipo deve ser marcado como '[WebHostHidden]'
C4450|'*tipo*'deve ser marcado como '[WebHostHidden]' porque deriva de'*tipo*'
C4451|'*tipo*': uso de classe ref*tipo*' dentro neste contexto pode levar a empacotamento inválido do objeto entre contextos
C4452|'*tipo*': tipo público não pode estar no escopo global. Ela deve estar em um namespace que é um filho do nome do arquivo. winmd de saída.
C4453|'*tipo*': um tipo de '[WebHostHidden]' não deve ser usado na superfície publicada de um tipo público que não seja '[WebHostHidden]'
C4454|'*tipo*' sobrecarregado por mais do que o número de parâmetros de entrada sem ter [DefaultOverload] especificado. Escolhendo '*declaração*' como a sobrecarga padrão
C4471|'*nome*': declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)
C4472|'*nome*' é um enum nativo: adicionar um especificador de acesso (pública/privada) para declarar uma enum WinRT/gerenciado
C4492|'*tipo*': correspondências de método de ref class base '*tipo*', mas não está marcado como 'override'
C4493|expressão de exclusão não surte efeito porque o destruidor de '*tipo*' não tem acessibilidade 'pública'
C4585|'*tipo*': classe não lacrada WinRT uma 'classe ref pública' deve ser lacrada ou deriva de um existente
C4586|'*tipo*': um tipo público não pode ser declarado em um namespace de nível superior denominado 'Windows'
C4695|#pragma execution_character_set: '*argumento*' não é um argumento com suporte: atualmente, apenas 'UTF-8' é suportado
C4703|variável de ponteiro local potencialmente não inicializada '*nome*' usado
C4728|/ Yl-option ignorada porque a referência PCH é necessária
C4745|acesso volátil de '*nome*' não pode ser cumprido devido ao seu tamanho
C4746|acesso volátil de '*nome*' está sujeito a /volatile:\<iso\|ms > Configuração; considere o uso de funções intrínsecas iso_volatile_load/store
C4872|divisão de ponto flutuante por zero detectado ao compilar o gráfico de chamada para o Concurrency:: parallel_for_each em: '*descrição*'
C4880|conversão de '*tipo*'para'*tipo*': Rejeitando constness de um ponteiro ou referência pode resultar em comportamento indefinido em uma função de amp restringido
C4881|o construtor e/ou o destruidor não será chamado para inicializar a variável tile_static '*tipo*'
C4966|'*descrição*' tem a anotação code_seg com o nome de segmento sem suporte, anotação ignorada
C4988|'*tipo*': variável declarada fora do escopo classe/função
C4989|'*descrição*': tipo tem definições conflitantes.

## <a name="warnings-introduced-in-visual-c-2010-compiler-version-16004021901"></a>Avisos introduzidos no Visual C++ 2010 (versão do compilador 16.00.40219.01)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:15__.

|||
|-|-|
C4352|'*nome*': função intrínseca já definida
C4573|o uso de '*tipo*' requer que o compilador capture 'this' mas o modo de captura padrão atual não permite
C4574|'*nome*'está definido como ' 0': você pretendia usar ' #if *nome*'?
C4689|'*caracteres*': caractere não suportado em #pragma detect_mismatch; #pragma ignorado
C4751|/arch sinalizador AVX não se aplica a Intel (r) Extensões SIMD de Streaming que estão dentro de ASM embutido
C4752|encontrado Intel (r) Advanced Vector Extensions; Considere o uso de /arch apropriado sinalizador AVX
C4837|trigraph detectado: '? *caracteres*'substituído por'*caracteres*'
C4986|'*declaração*': especificação de exceção não corresponde à declaração anterior
C4987|extensão não padrão usada: 'throw (...)'

## <a name="warnings-introduced-in-visual-c-2008-compiler-version-15002102208"></a>Avisos introduzidos no Visual C++ 2008 (versão do compilador 15.00.21022.08)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:14__.

|||
|-|-|
C4396|'*tipo*': o especificador embutido não pode ser usado quando uma declaração friend se refere a uma especialização de um modelo de função
C4413|'*declaração*': membro de referência é inicializado para um temporário que não persiste após o construtor encerrar
C4491|'*descrição*': tem um formato inválido de versão IDL
C4603|'*nome*': macro não está definida ou definição é diferente após uso de cabeçalho pré-compilado
C4627|'*descrição*': ignorada durante a procura de uso de cabeçalho pré-compilado
C4750|'*descrição*': função com alloca () embutida dentro de um loop
C4910|'*tipo*': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita
C4985|'*declaração*': atributos não presentes em declaração anterior.

## <a name="warnings-introduced-in-visual-c-2005-compiler-version-140050727762"></a>Avisos introduzidos no Visual C++ 2005 (versão do compilador 14.00.50727.762)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:13__.

|||
|-|-|
C4000|Aviso desconhecido, escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abrir o arquivo de Ajuda do suporte técnico para obter mais informações
C4272|'*tipo*': está marcado como __declspec(dllimport); deve especificar a convenção de chamada nativa ao importar uma função.
C4333|'*expressão*': right shift por valor muito grande, perda de dados
C4334|'*expressão*': resultado de 32-bit shift convertido implicitamente para 64 bits (foi 64-bit shift era pretendido?)
C4335|Formato de arquivo Mac detectado: converta o arquivo de origem para o formato DOS ou UNIX
C4342|alteração de comportamento: '*tipo*' chamado, mas um operador membro foi chamado em versões anteriores
C4350|alteração de comportamento: '*declaração*'chamado em vez de'*declaração*'
C4357|argumento param array encontrado na lista de argumentos formais para delegate '*declaração*'ignorada ao gerar'*tipo*'
C4358|'*expressão*': tipo de retorno de delegates combinados não é 'void'; o valor retornado é indefinido
C4359|'*tipo*': especificador de alinhamento é menor que o alinhamento real (*número*) e será ignorado.
C4362|'*tipo*': alinhamento maior que 8 bytes não é suportado pelo CLR
C4364|#using para assembly '*nome*' visto anteriormente em *descrição*(*número*) sem atributo as_friend; as_friend não aplicado
C4365|'*expressão*': conversão de '*tipo*'para'*tipo*', incompatibilidade assinada/não assinada
C4366|O resultado do operador unário '*operador*' operador deve ser unaligned
C4367|Conversão de '*tipo*'para'*tipo*' pode causar a exceção de desalinhamento de tipo de dados
C4368|não é possível definir '*nome*'como membro gerenciado'*tipo*': não há suporte para tipos mistos
C4369|'*tipo*': valor do enumerador '*número*'não pode ser representado como'*tipo*', valor é'*número*'
C4374|'*declaração*': método de interface não será implementado por método não virtual '*declaração*'
C4375|método não public '*declaração*'não substitui'*declaração*'
C4376|especificador de acesso '*especificador*:' não é mais suportado: use '*especificador*:' em vez disso
C4377|tipos nativos são private por padrão. -d1PrivateNativeTypes é preterido
C4378|Deve obter ponteiros de função para executar inicializadores; Considere System::ModuleHandle::ResolveMethodHandle
C4379|Versão *versão* do common language runtime não tem suporte por este compilador. Usando esta versão pode causar resultados inesperados
C4381|'*declaração*': método de interface não será implementado por método não public '*declaração*'
C4382|Lançando '*tipo*': um tipo com clrcall destruidor ou Construtor de cópia só pode ser capturado em /clr: pure módulo
C4383|'*tipo*': o significado de desreferenciar um identificador pode mudar, quando um usuário definido '*operador*' operador existe; escreva o operador como uma função estática para ser explícito sobre o operando
C4384|#pragma '*diretiva*' deve ser usada somente no escopo global
C4393|'*tipo*': const não tem nenhum efeito *descrição* membro de dados; ignorado
C4394|'*tipo*': símbolo per-appdomain não deve ser marcado com declspec (*valor*)
C4395|'*tipo*': função membro será invocada em uma cópia do membro de dados initonly '*tipo*'
C4397|DefaultCharSetAttribute é ignorado
C4398|'*tipo*': objeto global por processo poderão não funcionar corretamente com múltiplos appdomains; considere o uso de __declspec(appdomain)
C4399|'*tipo*': símbolo per-process não deve ser marcado com declspec (*valor*) quando compilado com /clr: pure
C4400|'*tipo*': não há suporte para qualificadores const/volatile neste tipo
C4412|'*declaração*': assinatura de função contém tipo '*tipo*'; Objetos C++ são seguros para passar entre código puro e código misto ou nativo.
C4429|possíveis incompleto ou incorretamente formado-nome de caractere universal
C4430|faltando especificador de tipo - int assumido. Observação: C++ não suporta default-int
C4431|faltando especificador de tipo - int assumido. Observação: C não suporta mais default-int
C4434|um construtor estático deve ter acessibilidade private; alterando para acesso privado
C4439|'*tipo*': definição de função com um tipo gerenciado na assinatura deve ter um clrcall convenção de chamada
C4441|convenção de chamada de '*convenção*' ignorado; '*convenção*' usado em vez disso
C4445|'*declaração*': em um tipo gerenciado/WinRT um método virtual não pode ser particular
C4460|Operador CLR/WinRT '*tipo*', tem o parâmetro passado por referência. Operador CLR/WinRT '*operador*'tem semânticas diferentes do operador de C++'*operador*', você pretendia passar por valor?
C4461|'*tipo*': esta classe possui um finalizador '! *tipo*', mas nenhum destruidor ' ~*tipo*'
C4470|pragmas de controle de ponto flutuante ignorados sob /clr
C4480|extensão não padrão usada: especificação de tipo subjacente para enum '*tipo*'
C4481|extensão não padrão usada: especificador de substituição '*especificador*'
C4482|extensão não padrão usada: enum '*tipo*' usado no nome qualificado
C4483|Erro de sintaxe: esperada palavra-chave de C++
C4484|'*tipo*': correspondências de método de ref class base '*tipo*', mas não está marcado como 'virtual', 'new' ou 'override'; 'new' (e não 'virtual') é assumido
C4485|'*tipo*': correspondências de método de ref class base '*tipo*', mas não está marcado como 'new' ou 'override'; 'new' (e 'virtual') são assumidos
C4486|'*tipo*': um método private virtual de uma classe ref ou classe de valor deve ser marcado como 'sealed'
C4487|'*tipo*': correspondências herdada método não virtual '*tipo*', mas não está explicitamente marcado como 'new'
C4488|'*tipo*': requer '*palavra-chave*'palavra-chave para implementar o método de interface'*tipo*'
C4489|'*palavra-chave*': não é permitido em método de interface '*nome*'; especificadores são permitidos apenas em métodos da classe ref classe e o valor de substituição
C4490|'*palavra-chave*': uso incorreto de especificador de substituição; '*tipo*' não corresponde a um método de classe ref base
C4538|'*tipo*': não há suporte para qualificadores const/volatile neste tipo
C4559|'*tipo*': redefinição; os ganhos de função declspec (*valor*)
C4565|'*tipo*': redefinição; símbolo foi declarado anteriormente com declspec (*valor*)
C4566|caractere representado por nome de caractere universal '*caracteres*' não pode ser representado na página de código atual (*número*)
C4568|'*tipo*': nenhum membro corresponde à assinatura da substituição explícita
C4569|'*tipo*': nenhum membro corresponde à assinatura da substituição explícita
C4570|'*tipo*': não é declarado explicitamente como abstract, mas possui funções abstract
C4571|Informativo: semântica catch(...) alterada desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas
C4572|Atributo [ParamArray] é preterido sob /clr, use '...' em vez disso
C4580|[attribute] é preterido; em vez disso, especifique *especificado*atributo como uma classe base
C4581|comportamento preterido: ' "*nome*"' substituído por '*nome*' para processar atributo
C4606|Aviso #pragma: '*número*' ignorado; Avisos da análise de código não estão associados com níveis de aviso
C4631|MSXML ou XPath indisponível, documento XML de comentários não serão processados. *description*
C4632|Comentário de documento XML: *descrição* -acesso negado: *descrição*
C4633|Comentário de documento XML*descrição*: erro: *descrição*
C4634|Comentário de documento XML*descrição*: não pode ser aplicado: *descrição*
C4635|Comentário de documento XML*descrição*: incorreta de XML: *descrição*
C4636|Comentário de documento XML*descrição*: marca requer não vazio '*descrição*' atributo.
C4637|Comentário de documento XML*descrição*: <include> marca descartada. *description*
C4638|Comentário de documento XML*descrição*: referência a símbolo desconhecido '*descrição*'.
C4639|Erro MSXML, documento XML de comentários não serão processados. *description*
C4641|Comentário de documento XML tem uma referência cruzada ambígua: 
C4678|classe de base*declaração*'é menos acessível que'*nome*'
C4679|'*descrição*': não foi possível importar membro
C4687|'*tipo*': uma classe sealed abstract não pode implementar uma interface '*tipo*'
C4688|'*nome*': lista de restrições contém tipo private de assembly '*declaração*'
C4690|[ emitidl ( pop ) ]: mais ativações do que envios
C4691|'*tipo*': tipo referenciado era esperado não referenciados *módulo* '*descrição*', tipo definido na unidade de tradução atual usada
C4692|'*nome*': assinatura de membro não private contém tipo nativo private de assembly '*declaração*'
C4693|'*tipo*': uma classe sealed abstract não pode ter quaisquer membros de instância*nome*'
C4694|'*tipo*': uma classe sealed abstract não pode ter uma classe base*tipo*'
C4720|relatórios do assembler em linha: '*descrição*'
C4721|'*descrição*': não disponível como um intrínseco
C4722|'*descrição*': destruidor nunca retorna, possível perda de memória
C4726|ARM arch4/4T suporta apenas ' < cpsr_f > ou < spsr_f >' com valor imediato
C4727|PCH nomeado *nome* com mesmo carimbo de hora encontrado em *nome* e *nome*.  Usando primeiro PCH.
C4729|função muito grande para o gráfico de fluxo com base em avisos
C4730|'*descrição*': misturar m64 e expressões podem resultar em código incorreto de ponto flutuante
C4731|'*descrição*': registro de ponteiro de quadro '*registrar*' modificado por código de assembly embutido
C4732|intrínseco '*intrínseco*' não tem suporte nesta arquitetura
C4733|Asm embutido atribuindo para 'FS:0': manipulador não registrado como manipulador seguro
C4734|Mais de 64K números de linha em um COFF depurar seção de informações. interromper a emissão de números de linha de depuração COFF para módulo '*módulo*'
C4738|armazenando o resultado float de 32 bits na memória, possível perda de desempenho
C4739|referência à variável '*variável*' excede seu espaço de armazenamento
C4740|fluxo para dentro ou fora do código asm embutido suprime otimização global
C4742|'*variável*'possui alinhamento diferente '*local*'e'*local*': *número* e *número*
C4743|'*nome*'tem um tamanho diferente '*local*'e'*local*': *número* e *número* bytes
C4744|'*nome*'tem tipo diferente '*local*'e'*local*': '*tipo*'e'*tipo*'
C4747|Chamando gerenciado '*tipo*': código gerenciado não pode ser executado sob bloqueio do carregador, incluindo o ponto de entrada DLL e chamadas acessadas do ponto de entrada DLL
C4761|incompatibilidade do tamanho integral em argumento; conversão fornecida
C4764|Não é possível alinhar objetos catch maiores que 16 bytes
C4788|'*identificador*': identificador foi truncado para '*número*' caracteres
C4789|buffer '*nome*' tamanho *número* bytes serão substituídos; *número* bytes serão escritos começando no deslocamento *número*
C4801|Retorno por referência não é verificável: *descrição*
C4819|O arquivo contém um caractere que não pode ser representado na página de código atual (*número*). Salve o arquivo em formato Unicode para evitar perda de dados
C4826|Conversão de '*tipo*'para'*tipo*' possui sinal estendido. Isso pode causar comportamento inesperado em tempo de execução.
C4829|Parâmetros possivelmente incorretos para a função principal. Considere a possibilidade de ' int principal (Platform:: array\<Platform:: String ^ > ^ argv)'
C4835|'*tipo*': o inicializador para dados exportados não será executado até que o código gerenciado é executado pela primeira vez no host assembly
C4867|'*tipo*': sintaxe não padrão; use '&' para criar um ponteiro para membro
C4936|Este declspec é suportado apenas quando compilado com /clr ou /clr: pure
C4937|'*nome*'e'*nome*'são indistinguíveis como argumentos para'*opção*'
C4938|'*tipo*': variável de redução de ponto flutuante pode causar resultados inconsistentes sob /fp: strict ou #pragma fenv_access
C4939|#pragma vtordisp é preterido e será removido em uma versão futura do Visual C++
C4947|'*tipo*': marcado como obsoleto
C4949|pragmas 'managed' e 'unmanaged' são significativos apenas quando compilado com ' / clr [: opção]'
C4950|'*tipo*': marcado como obsoleto
C4955|'*descrição*': importação ignorada; já importado de '*fonte*'
C4956|'*tipo*': este tipo não é verificável
C4957|'*expressão*': conversão explícita de '*tipo*'para'*tipo*' não é verificável
C4958|'*expressão*': aritmética de ponteiro não é verificável
C4959|não é possível definir não gerenciado *classe* '*tipo*' em /CLR: safe porque o acesso aos seus membros produz código não verificável
C4960|'*descrição*' é muito grande para ser analisado
C4961|Nenhum dado de perfil foi mesclado em '*local*', otimizações guiadas por perfil desabilitadas
C4962|'*descrição*': otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente
C4963|'*descrição*': nenhum dado de perfil encontrado; opções do compilador diferentes foram usadas em compilação instrumentada
C4964|Nenhuma opção de otimização foi especificada; informações de perfil não serão coletadas
C4965|box implícito de inteiro 0; Use nullptr ou conversão explícita
C4970|construtor delegate: objeto de destino ignorado desde '*declaração*' é estático
C4971|Ordem de argumentos: \<o objeto de destino >, \<função de destino > para construtor delegate é preterida, use \<função de destino >, \<o objeto de destino >
C4972|Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável

## <a name="warnings-introduced-in-visual-c-2003-compiler-version-13103077"></a>Avisos introduzidos no Visual C++ 2003 (versão do compilador 13.10.3077)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:13.00.9466__.

|||
|-|-|
C4343|otimizar o #pragma (*descrição*, off) substitui opção /Og
C4344|alteração de comportamento: uso de resultados de argumentos de template explícitos na chamada para '*declaração*'
C4346|'*tipo*': nome dependente não é um tipo
C4348|'*declaração*': redefinição do parâmetro padrão: parâmetro *número*
C4356|'*tipo*': membro de dados estático não pode ser inicializado via classe derivada
C4408|anônimo *struct* não declarou nenhum membro de dados
C4544|'*declaração*': argumento de template ignorado nessa declaração de template padrão
C4545|expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos
C4546|faltando lista de argumentos na chamada de função antes da vírgula
C4547|'*expressão*': operador antes da vírgula não tem nenhum efeito; esperado operador com efeito colateral
C4548|expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral
C4549|'*expressão*': operador antes da vírgula não tem nenhum efeito; você pretendia usar '*expressão*'?
C4628|dígrafos não suportados com -Ze. Sequência de caracteres '*sequência*'não é interpretada como token alternativo para'*token*'
C4629|dígrafo usado, sequência de caracteres '*sequência*'interpretada como token'*token*' (Insira um espaço entre os dois caracteres se for não pretende)
C4671|'*descrição*': o construtor de cópia é inacessível
C4676|'*descrição*': o destruidor é inacessível
C4677|'*nome*': assinatura de membro não private contém tipo private de assembly '*declaração*'
C4686|'*tipo*': possível alteração em comportamento, alteração no UDT retornar a convenção de chamada
C4812|estilo de declaração obsoleta: use '*tipo*::*nome*' em vez disso
C4813|'*tipo*': uma função friend de uma classe local deve ter sido anteriormente declarada
C4821|Não é possível determinar o tipo de codificação Unicode, salve o arquivo com assinatura (BOM)
C4822|'*tipo*': função de membro de classe local não tem um corpo
C4823|'*tipo*': usa ponteiros de fixação mas desenrolar semântica não está habilitada. Considere o uso de /EHa
C4913|usuário operador binário definido pelo ',' existe mas nenhuma sobrecarga pôde converter todos os operando, operador binário interno padrão ',' usado
C4948|tipo de retorno de '*declaração*' não coincide com o último tipo de parâmetro do setter correspondente
C4951|'*descrição*' foi editado após os dados de perfil de função não usados coleta dados de perfil
C4952|'*descrição*': nenhum dado de perfil encontrado no banco de dados do programa '*descrição*'
C4953|Inline '*descrição*' foi editado após os dados de perfil não usados coleta dados de perfil
C4954|'*descrição*': não analisado (contém expressão de switch Int64)

## <a name="warnings-introduced-in-visual-c-2002-compiler-version-13009466"></a>Avisos introduzidos no Visual C++ 2002 (versão do compilador 13.00.9466)

Todos os avisos em versões posteriores e esses avisos são suprimidos usando a opção de compilador __/Wv:12__.

|||
|-|-|
C4096|'*tipo*': interface não é uma interface COM; não será emitida para IDL
C4097|esperado parâmetro de pragma como ' Restore ' ou 'off'
C4165|'HRESULT' está sendo convertido em 'bool'; Tem certeza de que é isso que você deseja?
C4183|'*nome*': faltando tipo de retorno; assumido para ser uma função membro retornando 'int'
C4199|*description*
C4255|'*nome*': nenhum protótipo de função fornecido: convertendo '()' para '(void)'
C4256|'*declaração*': construtor de classe com bases virtual possui '...'; chamadas podem não ser compatíveis com versões anteriores do Visual C++
C4258|'*nome*': definição a partir de loop é ignorado; a definição do escopo delimitador é usada
C4263|'*declaração*': função membro não substitui nenhuma função de membro virtual de classe base
C4264|'*declaração*': nenhuma substituição disponível para função membro virtual da Base de dados de '*classe*'; função é ocultada
C4265|'*tipo*': classe possui funções virtual, mas destruidor não virtual instâncias desta classe podem não ser destruídas corretamente
C4266|'*declaração*': nenhuma substituição disponível para função membro virtual da Base de dados de '*classe*'; função é ocultada
C4267|'*expressão*': conversão de 'size_t' para '*tipo*', possível perda de dados
C4274|#ident ignorado; Consulte a documentação para #pragma comment (exestr, 'string')
C4277|item importado '*tipo*::*nome*' existe como membro de dados e o membro da função; membro de dados ignorado
C4278|'*nome*': identificador em biblioteca de tipos '*descrição*' já é uma macro; use o qualificador 'rename'
C4279|'*nome*': identificador em biblioteca de tipos '*descrição*' é uma palavra-chave; use o qualificador 'rename'
C4287|'*expressão*': incompatibilidade de constante unsigned/negativa
C4288|extensão não padrão usada: '*nome*': variável de controle de loop declarada no loop for é usada fora do escopo de loop for; ela está em conflito com a declaração no escopo externo
C4289|extensão não padrão usada: '*nome*': variável de controle de loop declarada no loop for é usada fora do escopo de loop for
C4293|'*expressão*': shift Contagem negativa ou muito grande, comportamento indefinido
C4295|'*tipo*': matriz é muito pequena para incluir um caractere null de terminação
C4296|'*expressão*': expressão é sempre *valor*
C4297|'*tipo*': função não deveria para lançar uma exceção, mas não
C4298|'*nome*': identificador em biblioteca de tipos '*descrição*' já é uma macro; renomeando para ' _*nome*'
C4299|'*nome*': identificador em biblioteca de tipos '*descrição*' é uma palavra-chave; renomeando para ' _*nome*'
C4302|'*expressão*': truncamento de '*tipo*'para'*tipo*'
C4303|*conversão* de '*tipo*'para'*tipo*' é preterido, use static_cast, try_cast ou dynamic_cast
C4314|parâmetro pragma esperado como '32' ou '64'
C4315|'*tipo*': ponteiro 'this' para membro '*tipo*' pode não estar alinhado *número* conforme o esperado pelo construtor
C4318|passando constante zero como o comprimento para memset
C4319|'*expressão*': zero estendendo '*tipo*'para'*tipo*' de tamanho maior
C4321|Gerar automaticamente um IID para interface '*tipo*'
C4322|Gerar automaticamente um CLSID para classe*tipo*'
C4323|reutilizando CLSID registrado para classe*tipo*'
C4324|'*tipo*': estrutura foi preenchida devido ao especificador de alinhamento
C4325|atributos para seção padrão '*descrição*' ignorado
C4326|tipo de retorno de '*nome*'deve ser'*tipo*'em vez de'*tipo*'
C4327|'*expressão*': alinhamento de indireção de LHS (*número*) é maior do que de RHS (*número*)
C4328|'*descrição*': alinhamento de indireção de parâmetro formal *número* (*número*) é maior do que o alinhamento de argumento real (*número*)
C4329|especificador de alinhamento é ignorado em enum
C4336|Importar biblioteca de tipos com referência cruzada '*biblioteca*'antes de importar'*descrição*'
C4337|biblioteca de tipos com referência cruzada '*biblioteca*'in'*descrição*' está sendo importada automaticamente
C4338|#pragma *descrição*: seção padrão '*seção*' é usado
C4339|'*tipo*': uso de tipo indefinido detectado em metadados do CLR/WinRT - uso deste tipo pode levar a uma exceção de tempo de execução
C4353|extensão não padrão usada: constante 0 como expressão de função.  Use NOOP' função intrínseca
C4370|'*declaração*': layout da classe mudou de uma versão anterior do compilador devido a melhor empacotamento
C4371|'*declaração*': layout da classe pode ter sido alterado de uma versão anterior do compilador devido a melhor empacotamento do membro '*membro*'
C4373|'*tipo*': substituições de função virtual*declaração*', versões anteriores do compilador não substituíam quando parâmetros diferiam apenas em qualificadores const/volatile
C4387|'*descrição*': foi considerada
C4389|'*expressão*': incompatibilidade assinada/não assinada
C4391|'*declaração*': tipo de retorno incorreto para função intrínseca, esperado '*tipo*'
C4392|'*declaração*': número incorreto de argumentos para a função intrínseca, esperado '*número*' argumentos
C4407|conversão entre diferente ponteiro para representações de membro, compilador pode gerar código incorreto
C4420|'*nome*': operador não está disponível, usando '*nome*'; verificação de tempo de execução pode ser comprometida
C4440|a redefinição de convenção de chamada '*descrição*'para'*descrição*' ignorado
C4442|terminador nulo inserido em argumento de Annotation.  Valor será truncado.
C4444|'*nome*': unaligned' de nível superior não está implementado neste contexto
C4526|'*tipo*': função membro static não pode substituir função virtual '*declaração*' substituição ignorada, função virtual será ocultada
C4531|Tratamento de exceções C++ não disponível no Windows CE. Use o tratamento estruturado de exceções
C4532|'*descrição*': salto de *finalmente* bloco possui comportamento indefinido durante manipulação de encerramento
C4533|inicialização de '*declaração*' é ignorada por ' goto *declaração*'
C4534|'*declaração*' não será um construtor padrão para *classe* '*tipo*' devido ao argumento padrão
C4535|chamada _set_se_translator() requer /EHa
C4536|'*descrição*': nome de tipo excede o limite de metadados de '*número*' caracteres
C4537|'*declaração*': '.' aplicado a tipo não UDT
C4542|Ignorando a geração do arquivo de texto injetado mesclado, não é possível gravar *tipo* arquivo: '*filename*': *erro*
C4543|Injetado suprimido por atributo de texto ' nenhum\_injected_text'
C4555|expressão não tem efeito; expressão esperada com efeito colateral
C4557|'__assume' contém o efeito '*efeito*'
C4558|valor de operando '*número*'está fora do intervalo'*número* - *número*'
C4561|fastcall' incompatível com o ' / clr' opção: convertendo para stdcall'
C4562|funções totalmente prototipadas são necessárias com o ' / clr' opção: convertendo '()' para '(void)'
C4564|método '*nome*' de *classe* '*tipo*'define parâmetro padrão não suportado'*parâmetro*'
C4584|'*tipo*': classe base*declaração*'já é uma classe base de'*declaração*'
C4608|Inicializando vários membros de união: '*tipo*'e'*tipo*'
C4619|Aviso #pragma: há um número de aviso '*número*'
C4623|'*tipo*': construtor padrão foi implicitamente definido como excluído
C4624|'*tipo*': destrutor foi implicitamente definido como excluído
C4625|'*tipo*': construtor de cópia foi implicitamente definido como excluído
C4626|'*tipo*': operador de atribuição foi implicitamente definido como excluído
C4645|a função declarada com 'noreturn' tem uma instrução return
C4646|a função declarada com 'noreturn' tem o tipo de retorno não void
C4659|#pragma '*descrição*': uso de segmento reservado '*nome*' possui comportamento indefinido, use #pragma comment (linker,...)
C4667|'*declaração*': nenhum modelo de função definido que corresponda à instanciação forçada
C4668|'*nome*'não está definido como uma macro de pré-processador, substituindo por '0' para'*valor*'
C4669|'*expressão*': conversão não segura: '*tipo*' é um objeto de tipo gerenciado/WinRT
C4674|'*nome*' deve ser declarado como 'static' e ter exatamente um parâmetro
C4680|'*tipo*': coclass não especifica uma interface padrão
C4681|'*tipo*': coclass não especifica uma interface padrão que é uma origem de evento
C4682|'*tipo*': nenhum atributo de parâmetro direcional especificado, padronizando para [in]
C4683|'*declaração*': fonte de eventos possui um 'out'-parâmetro; tome cuidado ao capturar vários manipuladores de eventos
C4684|'*descrição*': aviso!! atributo pode causar a geração de código inválido: use com cuidado
C4685|esperando ' >> ' encontrado ' >> ' ao analisar parâmetros de modelo
C4700|variável local não inicializado '*nome*' usado
C4701|variável local possivelmente não inicializada '*nome*' usado
C4702|Código inacessível
C4711|função '*nome*' selecionadas para expansão inline automática
C4714|função '*declaração*' marcada como forceinline não embutida
C4715|'*função*': nem todos os caminhos de controle retornam um valor
C4716|'*função*': deve retornar um valor
C4717|'*função*': recursivo em todos os caminhos de controle, função causará estouro de pilha do tempo de execução
C4718|'*função*': chamada recursiva não tem efeitos colaterais, excluindo
C4719|Constante Double encontrada com Qfast especificado - use 'f' como um sufixo para indicar precisão simples
C4723|possível divisão por 0
C4724|possível mod por 0
C4725|instrução pode ser incorreta em alguns Pentiums
C4757|subscrito é um valor unsigned grande, você pretendia uma constante negativa?
C4772|#import referenciou um tipo de uma biblioteca de tipos faltando; '*descrição*' usado como um espaço reservado
C4792|função '*função*' declarada usando sysimport e referenciada no código nativo; biblioteca de importação requerida para vínculo
C4794|segmento de variável de armazenamento local de thread '*nome*'alterado de'*segmento*'para'*segmento*'
C4798|o código nativo gerado para a função de pseudocódigo '*nome*' com o manipulador de exceção ou semântica de liberação
C4799|função '*nome*' não possui instrução EMMS
C4803|'*declaração*': o método raise possui uma classe de armazenamento diferente do que o evento '*declaração*'
C4810|valor de pragma Pack (show) o usuário = = *número*
C4811|valor de pragma conform (forScope, show) = = *valor*
C4820|'*tipo*': '*número*' bytes de preenchimento adicionados após *tipo* '*tipo*'
C4905|literal de cadeia ampla convertido em '*tipo*'
C4906|cadeia de caracteres literal convertida em '*tipo*'
C4912|'*atributo*': atributo possui comportamento indefinido em um UDT aninhado
C4916|para ter um dispid, '*tipo*': deve ser introduzido por uma interface
C4917|'*tipo*': um GUID só pode ser associado uma classe, interface ou namespace
C4918|'*caracteres*': caractere inválido na lista de otimização de pragma
C4920|enumeração *nome* membro *nome*=*número* já visto em enum *nome* como *nome* = *número*
C4921|'*nome*': valor de atributo '*valor*' não deve ser especificado várias vezes
C4925|'*declaração*': método dispinterface não pode ser chamado do script
C4926|'*declaração*': símbolo já está definido: atributos ignorados
C4927|conversão inválida; mais de uma conversão definida pelo usuário foi aplicada implicitamente
C4928|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada
C4929|'*descrição*': biblioteca de tipos possui uma union; ignorando o qualificador 'embedded_idl'
C4930|'*declaração*': função prototipada não chamada (era uma definição de variável se destina?)
C4931|assumindo que a biblioteca de tipos foi criada para *número*-bit ponteiros
C4932|Identifier (*descrição*) e Identifier (*descrição*) são indistinguíveis
C4934|'__delegate(multicast)' é preterido, use delegate' em vez disso
C4935|especificador de acesso de assembly modificado de '*descrição*'
C4944|'*nome*': não é possível importar símbolo de '*fonte*': como*declaração*' já existe no escopo atual
C4945|'*nome*': não é possível importar símbolo de '*fonte*': como*declaração*'já foi importado de outro assembly'*fonte*'
C4946|reinterpret_cast usado entre classes relacionadas: '*declaração*'e'*declaração*'
C4995|'*nome*': nome foi marcado como #pragma preterido
C4996|'*problema*': *descrição*
C4997|'*tipo*': coclass não implementa uma interface COM ou pseudointerface
C4998|Falha na EXPECTATIVA: *descrição*(*número*)

## <a name="see-also"></a>Consulte também
[Opção de compilador /wv](../../build/reference/compiler-option-warning-level.md)
[avisos do compilador que são desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md)
[aviso](../../preprocessor/warning.md)
