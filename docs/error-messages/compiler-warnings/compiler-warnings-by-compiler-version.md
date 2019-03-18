---
title: Avisos do compilador pela versão do compilador
ms.date: 10/24/2018
helpviewer_keywords:
- warnings, by compiler version
- cl.exe compiler, setting warning options
ms.openlocfilehash: 79cf78de865f480530df89c778e9fe432b0bbf33
ms.sourcegitcommit: a901c4acbfc80ca10663d37c09921f04c5b6dd17
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/18/2019
ms.locfileid: "58142533"
---
# <a name="compiler-warnings-by-compiler-version"></a>Avisos do compilador pela versão do compilador

O compilador pode suprimir avisos introduzidos após uma versão que você especificar usando o [/Wv](../../build/reference/compiler-option-warning-level.md) opção de compilador. Essa opção é útil para gerenciar o processo de compilação quando você introduz uma nova versão do conjunto de ferramentas e deseja suprimir temporariamente novos avisos. Essa opção não suprime novas mensagens de erro. Não é recomendável você Suprimir todos os avisos novos permanentemente! É recomendável que você sempre compilar no mais alto nível de aviso regular, __/W4__e remova os __/Wv__ opção em sua compilação assim que possível.

Essas versões do compilador introduziram novos avisos:

| Produto | Número de versão do compilador |
|-|-|
| Visual C++ 2002 | 13.00.9466 |
| Visual C++ 2003 | 13.10.3077 |
| Visual C++ 2005 | 14.00.50727.762 |
| Visual C++ 2008 | 15.00.21022.08 |
| Visual C++ 2010 | 16.00.40219.01 |
| Visual C++ 2012 | 17.00.51106.1 |
| Visual C++ 2013 | 18.00.21005.1 |
| Visual C++ 2015 RTM | 19.00.23026.0 |
| Visual C++ 2015 atualização 1 | 19.00.23506.0 |
| Visual C++ 2015 atualização 2 | 19.00.23918.0 |
| Visual C++ 2015 atualização 3 | 19.00.24215.1 |
| Visual C++ 2017 RTM | 19.10.25017.0 |
| Visual C++ 2017 versão 15.3 | 19.11.25506.0 |
| Visual C++ 2017 versão 15.5 | 19.12.25830.0 |
| Visual C++ 2017 versão 15.6 | 19.13.26128.0 |
| Visual C++ 2017 versão 15.7 | 19.14.26428.0 |
| Visual C++ 2017 versão 15,8 | 19.15.26726.0 |
| Visual C++ 2017 versão 15,9 | 19.16.26926.0 |
| Visual C++ 2019 RTM | 19.20.27004.0 |

Você pode especificar apenas o número principal, os números principais e secundárias ou major, minor e compilar os números para o __/Wv__ opção. O compilador relata todos os avisos que correspondem a versões que começam com o número especificado e suprime todos os avisos para as versões superiores do número especificado. Por exemplo, __/Wv:17__ relata todos os avisos introduzidos em ou antes de qualquer versão do Visual Studio 2012 e suprime todos os avisos introduzidos por qualquer compilador do Visual Studio 2013 (versão de 18) ou posterior. Para suprimir avisos introduzidos no Visual Studio 2015 atualização 2 e posterior, você pode usar __/Wv:19.00.23506__. Use __/Wv:19.11__ para relatar todos os avisos introduzidos em qualquer versão do Visual Studio anteriores ao Visual Studio 2017 versão 15.5, mas suprime avisos introduzidos no Visual Studio 2017 versão 15.5 e posteriores.

As seções a seguir listam os avisos introduzidos por cada versão do Visual C++ que você pode suprimir usando o __/Wv__ opção de compilador. O __/Wv__ opção não é possível suprimir avisos que não estão listados, que são anteriores às versões especificadas do compilador.

::: moniker range=">= vs-2019"

## <a name="warnings-introduced-in-visual-c-2019-rc-compiler-version-1920270040"></a>Avisos introduzidos no Visual C++ de 2019 RC (versão do compilador 19.20.27004.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.15__.

|||
|-|-|
C4848 | suporte para o atributo padrão ' nenhuma\_exclusivo\_seu endereço de C + + 17 e versões anteriores é uma extensão de fornecedor

::: moniker-end
::: moniker range=">= vs-2017"


## <a name="warnings-introduced-in-visual-c-2017-version-158-compiler-version-1915267260"></a>Avisos introduzidos no Visual C++ 2017 versão 15,8 (versão do compilador 19.15.26726.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.14__.

|||
|-|-|
C4643 | Encaminhar declarando '*identificador*' no namespace std não é permitido pelo padrão C++.
C4644 | uso do padrão com base em macro offsetof em expressões de constante é diferente do padrão; usar offsetof definida na biblioteca padrão C++ em vez disso
C4845 | \_\_declspec (nenhum\_init\_all)' será ignorado se ' / d1initall\[0\|1\|2\|3]' não foi especificado na linha de comando
C4846 | '*valor*' não é um argumento válido para ' / d1initall': sinalizador de linha de comando ignorado
C4847 | '\_\_declspec (nenhum\_init\_all)' só pode ser aplicada a uma função, um tipo de classe ou uma variável local: ignorado
C4866 | compilador não pode impor a ordem de avaliação da esquerda para a direita para a chamada para '*função*'
C5046 | '*função*': Símbolo que envolvem o tipo com vinculação interna não definida
C5047 | uso de não-padrão \_ \_se\_existe com módulos não tem suporte
C5048 | Uso da macro '*macroname*' pode resultar em saída não determinística.
C5049 | '*string*': Inserir um caminho completo pode resultar em saída dependente da máquina
C5050 | Possíveis ambiente incompatível durante a importação de módulo '*module_name*': *problema*
C5100 | \_\_VA\_ARGS\_ \_ é reservado para uso em macros variadic
C5101 | uso da diretiva de pré-processador na lista de argumentos de macro do tipo função é um comportamento indefinido
C5102 | Ignorando a definição de macro de linha de comando inválida '*valor*'
C5103 | colando '*token1*'e'*token2*' não resulta em um token válido de pré-processamento
C5104 | encontrado '*string1*#*string2*'na lista de substituição de macro, você quis dizer'*string1*"" #*string2*'?
C5105 | expansão de macro produzindo 'defined' possui comportamento indefinido
C5106 | macro redefinido com nomes de parâmetro diferentes
C5107 | faltando encerrando '*char*' caractere

## <a name="warnings-introduced-in-visual-c-2017-version-157-compiler-version-1914264280"></a>Avisos introduzidos no Visual C++ 2017 versão 15.7 (versão do compilador 19.14.26428.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.13__.

|||
|-|-|
C4642|'*problema*': não foi possível importar as restrições de parâmetro genérico '*parâmetro*'
C5045|Compilador inserirá a mitigação de espectro para carga de memória se a opção /Qspectre especificado

## <a name="warnings-introduced-in-visual-c-2017-version-156-compiler-version-1913261280"></a>Avisos introduzidos no Visual C++ 2017 versão 15.6 (versão do compilador 19.13.26128.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.12__.

|||
|-|-|
C5044|Um argumento para a opção de linha de comando *opção* aponta para um caminho '*caminho*' que não existe

## <a name="warnings-introduced-in-visual-c-2017-version-155-compiler-version-1912258300"></a>Avisos introduzidos no Visual C++ 2017 versão 15.5 (versão do compilador 19.12.25830.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.11__.

|||
|-|-|
C4843|'*type1*': Um manipulador de exceção de referência ao tipo de matriz ou função está inacessível, use '*type2*' em vez disso
C4844|' Exportar módulo *module_name*;' agora é a sintaxe preferencial para declarar uma interface de módulo
C5039|'*função*': ponteiro ou referência a função potencialmente lançada passada para a função C externa em - EHc. Um comportamento indefinido pode ocorrer se essa função gera uma exceção.
C5040|especificações de exceção dinâmica são válidas somente no c++14 e versões anteriores; tratar como noexcept (False)
C5041|'*definição*': definição fora de linha para o membro de dados estáticos constexpr não é necessária e foi preterida no c++17
C5042|'*declaração*': declarações de função no escopo de bloco não podem ser especificado 'inline' em C++ padrão; remova o especificador "embutido"
C5043|'*especificação*': especificação de exceção não corresponde à declaração anterior

## <a name="warnings-introduced-in-visual-c-2017-version-153-compiler-version-1911255060"></a>Avisos introduzidos no Visual C++ 2017 versão 15.3 (versão do compilador 19.11.25506.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.10__.

|||
|-|-|
C4597|um comportamento indefinido: *descrição*
C4604|'*tipo*': passar o argumento por valor entre limites nativo e gerenciado exige um construtor de cópia válido. Caso contrário, o comportamento de tempo de execução é indefinido
C4749|tem suporte condicionalmente: *descrição*
C4768|atributos de declspec antes da especificação de vinculação são ignorados
C4834|Descartando o valor retornado da função com o atributo 'nodiscard'
C4841|extensão não padrão usada: *extensão*
C4842|o resultado de 'offsetof' aplicado a um tipo usando a herança múltipla não é garantido para ser consistente entre versões do compilador
C4869|'nodiscard' só pode ser aplicado a classes, enumerações e funções com o tipo de retorno não nulo
C5033|'*classe de armazenamento*' não é uma classe de armazenamento com suporte
C5034|Use intrínseco '*intrínseco*' faz com que a função *função* seja compilada como código de convidado
C5035|usar o recurso '*recurso*' faz com que a função *função* seja compilada como código de convidado
C5036|conversão de ponteiro de função varargs ao compilar com/Hybrid:x86arm64 '*type1*'para'*type2*'
C5037|'*função de membro*': uma definição fora de linha de um membro de um modelo de classe não pode ter argumentos padrão
C5038|membro de dados '*member1*'será inicializados após o membro de dados'*membro2*'

## <a name="warnings-introduced-in-visual-c-2017-rtm-compiler-version-1910250170"></a>Avisos introduzidos no Visual C++ 2017 RTM (versão do compilador 19.10.25017.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.00__.

|||
|-|-|
C4468|'fallthrough': atributo deve ser seguido por um rótulo case ou um rótulo padrão
C4698|'*recurso*' é para fins de avaliação e está sujeita a alterações ou remoções em atualizações futuras.
C4839|uso não padrão da classe*classe*' como um argumento para uma função variadic
C4840|o uso não portátil da classe*classe*' como um argumento para uma função variadic

::: moniker-end

## <a name="warnings-introduced-in-visual-c-2015-update-3-compiler-version-1900242151"></a>Avisos introduzidos no Visual C++ 2015 atualização 3 (versão do compilador 19.00.24215.1)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.00.23918__.

|||
|-|-|
C4467|uso de atributos de ATL foi preterido
C4596|'*nome*': nome qualificado inválido na declaração de membro
C4598|' #include \< *cabeçalho*\>': o número de cabeçalho *número* no *origem* não corresponde ao *fonte* em que posição
C4599|'*argumento*': *fonte* número de argumento *número* não corresponde ao *fonte*

## <a name="warnings-introduced-in-visual-c-2015-update-2-compiler-version-1900239180"></a>Avisos introduzidos no Visual C++ 2015 atualização 2 (versão do compilador 19.00.23918.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.00.23506__.

|||
|-|-|
C4466|Não foi possível executar omissão do heap de corrotina
C4595|'*classe*': operador não membro novo ou excluir funções não podem ser declaradas embutidos
C4828|O arquivo contém um caractere começando com offset 0 x*valor* que é ilegal no conjunto de caracteres de origem atual (página de código *número*).
C4868|compilador não pode impor a ordem de avaliação da esquerda para a direita na lista de inicializadores entre chaves

## <a name="warnings-introduced-in-visual-c-2015-update-1-compiler-version-1900235060"></a>Avisos introduzidos no Visual C++ 2015 atualização 1 (versão do compilador 19.00.23506.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:19.00.23026__.

|||
|-|-|
C4426|os sinalizadores de otimização foram alterados após incluir o cabeçalho, pode ser devido a #pragma optimize)
C4654|O código colocado antes de incluir de cabeçalho pré-compilado linha será ignorada. Adicione código ao cabeçalho pré-compilado.
C5031|Warning (POP) #pragma: provável incompatibilidade, estado de aviso enviado por push em outro arquivo mostrado
C5032|detectado Warning (push) #pragma com nenhum Warning (POP) #pragma correspondente

## <a name="warnings-introduced-in-visual-c-2015-rtm-compiler-version-1900230260"></a>Avisos introduzidos no Visual C++ 2015 RTM (versão do compilador 19.00.23026.0)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/wv:18__.

|||
|-|-|
C4427|'*erro*': estouro na divisão constante, comportamento indefinido
C4438|'*tipo*': não pode ser chamado com segurança /await: clrcompat modo. Se '*tipo*' chamadas para o CLR-lo pode resultar em corrupção de cabeçalhos CLR
C4455|' operador *nome*': identificadores de sufixos literais que não começam com um sublinhado são reservados
C4456|declaração de '*nome*' oculta uma declaração local anterior
C4457|declaração de '*nome*' oculta o parâmetro de função
C4458|declaração de '*nome*' oculta o membro da classe
C4459|declaração de '*nome*' oculta uma declaração global
C4462|'*tipo*': não é possível determinar o GUID do tipo. O programa poderá falhar no tempo de execução.
C4463|estouro; atribuindo *valor* ao campo de bits que pode conter apenas valores de *valor* para *valor*
C4473|'*função*': não há argumentos suficientes passado para a cadeia de caracteres de formato
C4474|'*função*': muitos argumentos passados para a cadeia de caracteres de formato
C4475|'*função*': modificador de comprimento '*modificador*'não pode ser usado com o caractere de campo do tipo'*caractere*' no especificador de formato
C4476|'*função*': caractere de campo de tipo desconhecido '*caractere*' no especificador de formato
C4477|'*função*': cadeia de caracteres de formato '*cadeia de caracteres*'requer um argumento do tipo'*tipo*', mas o argumento variadic *número* tem o tipo '*tipo*'
C4478|'*função*': os espaços reservados posicionais e não posicionais não podem ser misturados na mesma cadeia de caracteres de formato
C4494|'*tipo*': Ignorando __declspec(allocator) porque o tipo de retorno de função não é um ponteiro ou referência
C4495|extensão não padrão super' utilizada: substitua pelo nome de classe base explícito
C4496|extensão não padrão 'for each' usada: Substituir por instrução intervalo-para
C4497|extensão não padrão 'selada' usada: Substituir por 'final'
C4498|extensão não padrão usada: '*extensão*'
C4499|'*especialização*': uma especialização explícita não pode ter uma classe de armazenamento (ignorada)
C4576|um tipo de entre parênteses seguido por uma lista de inicializadores é uma sintaxe de conversão de tipo explícito não padrão
C4577|'noexcept' usado com nenhum modo especificado; de manipulação de exceção Não há garantia a terminação na exceção. Especifique /EHsc
C4578|'abs': conversão de '*tipo*'para'*tipo*', possível perda de dados (você pretendia chamar '*nome*' ou #include \<cmath >?)
C4582|'*tipo*': construtor não está chamado implicitamente
C4583|'*tipo*': destruidor não é chamado implicitamente
C4587|'*tipo*': alteração de comportamento: construtor é não é mais implicitamente chamado
C4588|'*tipo*': alteração de comportamento: destruidor é não é mais implicitamente chamado
C4589|Construtor da classe abstrata*tipo*'ignora o inicializador para a classe base virtual'*tipo*'
C4591|limite de profundidade da chamada de 'constexpr' *número* excedido (/ /constexpr: Depth\<número >)
C4592|'*tipo*': símbolo será dinamicamente inicializados (limitação de implementação)
C4593|'*tipo*': limite de etapa de avaliação de chamadas de 'constexpr' de *valor* excedido; use /constexpr: Steps\<número > para aumentar o limite
C4647|alteração de comportamento: is_pod (*tipo*) tem um valor diferente em versões anteriores
C4648|o atributo padrão 'carries_dependency' é ignorado
C4649|os atributos são ignorados nesse contexto
C4753|Não é possível encontrar limites para ponteiro; Intrínseca MPX ignorada
C4771|Limites devem ser criados usando um ponteiro simple; Intrínseca MPX ignorada
C4774|'*descrição*': Formatar a cadeia de caracteres esperada no argumento *número* não é uma cadeia de caracteres literal
C4775|extensão não padrão usada na cadeia de caracteres de formato '*cadeia de caracteres*'da função'*função*'
C4776|' %*caractere*'não é permitida na cadeia de caracteres de formato da função'*função*'
C4777|'*descrição*': cadeia de caracteres de formato '*cadeia de caracteres*'requer um argumento do tipo'*tipo*', mas o argumento variadic *número* tem o tipo '*tipo*'
C4778|'*descrição*': não finalizada a cadeia de caracteres de formato '*cadeia de caracteres*'
C4838|conversão de '*tipo*'para'*tipo*' requer uma conversão redutora
C5022|'*tipo*': vários construtores de movimento especificados
C5023|'*tipo*': vários operadores de atribuição de movimento especificados
C5024|'*declaração*': construtor de movimento foi implicitamente definido como excluído
C5025|'*declaração*': mover operador de atribuição foi implicitamente definido como excluído
C5026|'*tipo*': construtor de movimento foi implicitamente definido como excluído
C5027|'*tipo*': mover operador de atribuição foi implicitamente definido como excluído
C5028|'*name*': Alinhamento especificado na declaração anterior (*número*) não especificado na definição
C5029|extensão não padrão usada: atributos de alinhamento no C++ se aplicam a variáveis, membros de dados e somente os tipos de marcas
C5030|atributo '*atributo*' não é reconhecido

## <a name="warnings-introduced-in-visual-c-2013-compiler-version-1800210051"></a>Avisos introduzidos no Visual C++ 2013 (versão do compilador 18.00.21005.1)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:17__.

|||
|-|-|
C4301|'*tipo*': função virtual de substituição difere apenas '*declaração*' pelo qualificador const/volatile
C4316|'*tipo*': objeto alocado no heap pode não estar alinhado *número*
C4380|'*type*': Não é possível preterir um construtor padrão
C4388|'*token*': incompatibilidade de signed/unsigned
C4423|'std:: bad_alloc': será capturado por classe ('*tipo*') na linha *número*
C4424|Catch para '*tipo*'precedido por'*tipo*' na linha *número*; imprevisível poderá ocorrer um comportamento se 'std:: bad_alloc' for lançada
C4425|Uma anotação SAL não pode ser aplicada a '...'
C4464|caminho de inclusão relativo contém '.. '
C4575|vectorcall' incompatível com o ' / clr' opção: convertendo para stdcall'
C4609|'*tipo*deriva interface padrão*tipo*'no tipo'*tipo*'. Use uma interface padrão diferente para '*tipo*', ou interromper a relação de base/derivada.
C4754|Regras de conversão para operações aritméticas na comparação em *descrição*(*número*) significam que uma ramificação não pode ser executada. Conversão de '*tipo*'para'*tipo*' (ou tipo similar de *número* bytes).
C4755|Regras de conversão para operações aritméticas na comparação em *descrição*(*número*) significam que uma ramificação não pode ser executada em uma função embutida. Conversão de '*tipo*'para'*tipo*' (ou tipo similar de *número* bytes).
C4767|nome da seção '*nome*' tem mais de 8 caracteres e será truncado pelo vinculador
C4770|enumeração parcialmente validada '*nome*' usada como índice
C4827|Um método 'ToString' público com 0 parâmetro deve ser marcado como virtual e substituir
C4882|a transmissão de functors com operadores de chamada não constantes para Concurrency:: parallel_for_each foi preterida
C4973|'*tipo*': marcados como preteridos
C4974|'*tipo*': marcados como preteridos
C4981|Warbird: função '*declaração*' marcada como forceinline não embutida porque contém semântica de exceção
C4990|Warbird: *mensagem*
C4991|Warbird: função '*declaração*' marcada como forceinline não embutida porque o nível de proteção do item embutido é maior que o pai
C4992|Warbird: função '*declaração*' marcada como forceinline não embutida porque contém assembly embutido que não pode ser protegido

## <a name="warnings-introduced-in-visual-c-2012-compiler-version-1700511061"></a>Avisos introduzidos no Visual C++ 2012 (versão do compilador 17.00.51106.1)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:16__.

|||
|-|-|
C4330|atributo '*atributo*'para a seção'*seção*' ignorado
C4415|duplicate __declspec(code_seg('*name*'))
C4416|__declspec(code_seg(...)) contém a cadeia de caracteres vazia: ignorado
C4417|uma instanciação de modelo explícitos não pode ter __declspec(code_seg(...)): ignorado
C4418|__declspec(code_seg(...)) ignorada na enumeração
C4419|'*nome*'não tem nenhum efeito quando aplicado à ref class privada'*tipo*'.
C4435|'*type*': Layout do objeto em/vd2 será alterado devido à base virtual '*tipo*'
C4436|dynamic_cast da base virtual '*tipo*'para'*tipo*' no construtor ou destruidor poderia falhar com o objeto parcialmente construído
C4437|dynamic_cast da base virtual '*tipo*'para'*tipo*' poderia falhar em alguns contextos
C4443|parâmetro pragma esperado como ser '0', '1' ou '2'
C4446|'*tipo*': não é possível mapear o membro '*nome*' para este tipo devido a conflito com o nome do tipo. O método foi renomeado para '*nome*'
C4447|assinatura 'main' encontrada sem modelo de threading. Considere o uso de ' int principal (Platform:: array\<Platform:: String ^ > ^ args)'.
C4448|'*tipo*' não tem uma interface padrão especificada nos metadados. Separação: '*tipo*', que pode falhar em tempo de execução.
C4449|'*tipo*' um tipo não selado deve ser marcado como '[WebHostHidden]'
C4450|'*tipo*'deve ser marcado como '[WebHostHidden]' porque deriva de'*tipo*'
C4451|'*type*': Uso de classe ref*tipo*' inside neste contexto pode levar a empacotamento inválido do objeto entre contextos
C4452|'*tipo*': tipo público não pode estar em escopo global. Ele deve ser em um namespace que é um filho do nome do arquivo de saída. winmd.
C4453|'*type*': Um tipo de '[WebHostHidden]' não deve ser usado na superfície publicada de um tipo público que não seja '[WebHostHidden]'
C4454|'*tipo*' está sobrecarregado por mais do que o número de parâmetros de entrada sem ter [DefaultOverload] especificado. Separação '*declaração*' como a sobrecarga padrão
C4471|'*nome*': declaração de encaminhamento de uma enumeração sem escopo deve ter um tipo subjacente (int assumido)
C4472|'*nome*' é uma enumeração nativa: adicionar um especificador de acesso (pública/privada) para declarar um enum gerenciado/WinRT
C4492|'*tipo*': correspondências de método ref class base '*tipo*', mas não está marcado como 'override'
C4493|expressão de exclusão não surte efeito porque o destruidor de '*tipo*' não tem acessibilidade 'pública'
C4585|'*type*': Uma WinRT '' classe ref pública deve ser selada ou deriva de uma classe não lacrada existente
C4586|'*type*': Um tipo público não pode ser declarado em um namespace de nível superior chamado 'Windows'
C4695|#pragma execution_character_set: '*argumento*' não é um argumento com suporte: atualmente, apenas 'UTF-8' tem suporte
C4703|variável de ponteiro local potencialmente não inicializada '*nome*' usado
C4728|/ Yl-option ignorada porque a referência PCH é necessária
C4745|acesso volátil de '*nome*' não pode ser cumprido devido ao seu tamanho
C4746|acesso volátil de '*nome*' está sujeito a /volatile:\<iso\|ms > Configuração; considere o uso de funções intrínsecas do iso_volatile_load/store
C4872|divisão de ponto flutuante por zero detectado ao compilar o grafo de chamada para o Concurrency:: parallel_for_each em: '*descrição*'
C4880|conversão de '*tipo*'para'*tipo*': constness de um ponteiro ou referência podem resultar em comportamento indefinido em uma função de amp restringido
C4881|o construtor e/ou o destruidor não será invocado para inicializar a variável tile_static '*tipo*'
C4966|'*descrição*' tem a anotação code_seg com o nome de segmento sem suporte, anotação ignorada
C4988|'*tipo*': variável declarada fora do escopo de classe/função
C4989|'*descrição*': tipo tem definições conflitantes.

## <a name="warnings-introduced-in-visual-c-2010-compiler-version-16004021901"></a>Avisos introduzidos no Visual C++ 2010 (versão do compilador 16.00.40219.01)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:15__.

|||
|-|-|
C4352|'*nome*': função intrínseca já definida
C4573|o uso de '*tipo*' requer que o compilador capture 'this' mas o modo de captura padrão atual não permite
C4574|'*nome*'é definido como ' 0': você pretendia usar ' #if *nome*'?
C4689|'*caractere*': caractere não suportado em #pragma detect_mismatch; #pragma ignorado
C4751|sinalizador /arch AVX não se aplica a Intel (r) Extensões SIMD de Streaming que estão dentro do ASM embutido
C4752|encontrar extensões de vetor avançadas Intel (r); Considere usar o sinalizador /arch AVX apropriado
C4837|trígrafo detectado: '?? *caractere*'substituído por'*caractere*'
C4986|'*declaração*': especificação de exceção não corresponde à declaração anterior
C4987|extensão não padrão usada: 'throw (...)'

## <a name="warnings-introduced-in-visual-c-2008-compiler-version-15002102208"></a>Avisos introduzidos no Visual C++ 2008 (versão do compilador 15.00.21022.08)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:14__.

|||
|-|-|
C4396|'*tipo*': o especificador embutido não pode ser usado quando uma declaração friend se refere a uma especialização de um modelo de função
C4413|'*declaração*': membro de referência é inicializado para um temporário que não persiste após o construtor encerrar
C4491|'*descrição*': tem um formato de versão IDL inválido
C4603|'*nome*': macro não está definida ou definição é diferente após uso de cabeçalho pré-compilado
C4627|'*descrição*': ignorado ao procurar o uso de cabeçalho pré-compilado
C4750|'*descrição*': função com alloca () embutida em um loop
C4910|'*tipo*': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita
C4985|'*declaração*': atributos não presentes em declaração anterior.

## <a name="warnings-introduced-in-visual-c-2005-compiler-version-140050727762"></a>Avisos introduzidos no Visual C++ 2005 (versão do compilador 14.00.50727.762)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:13__.

|||
|-|-|
C4000|Aviso desconhecido, escolha o comando de suporte técnico no menu Ajuda do Visual C++, ou abra o arquivo de Ajuda do suporte técnico para obter mais informações
C4272|'*tipo*': está marcado como __declspec(dllimport); deve especificar a convenção de chamada nativa ao importar uma função.
C4333|'*expressão*': right shift por valor muito grande, perda de dados
C4334|'*expressão*': o resultado de 32-bit shift convertido implicitamente para 64 bits (foi a mudança de 64 bits se destina?)
C4335|Formato de arquivo Mac detectado: converta o arquivo de origem para o formato DOS ou UNIX
C4342|alteração de comportamento: '*tipo*' chamado, mas um operador de membro foi chamado em versões anteriores
C4350|alteração de comportamento: '*declaração*'chamado em vez de'*declaração*'
C4357|argumento param array encontrado na lista de argumentos formais para delegate '*declaração*'ignorada ao gerar'*tipo*'
C4358|'*expressão*': tipo de retorno de delegates combinados não é 'void'; o valor retornado será indefinido
C4359|'*type*': Especificador de alinhamento é menor que o alinhamento real (*número*) e será ignorado.
C4362|'*tipo*': alinhamento maior que 8 bytes não é compatível com CLR
C4364|#using para assembly '*nome*' visto anteriormente em *descrição*(*número*) sem atributo as_friend; as_friend não aplicado
C4365|'*expressão*': conversão de '*tipo*'para'*tipo*', incompatibilidade de signed/unsigned
C4366|O resultado do operador unário '*operador*' operador deve ser unaligned
C4367|Conversão de '*tipo*'para'*tipo*' pode causar exceção de desalinhamento de tipo de dados
C4368|não é possível definir '*nome*'como um membro do gerenciado'*tipo*': não há suporte para tipos mistos
C4369|'*tipo*': valor do enumerador '*número*'não pode ser representado como'*tipo*', valor é'*número*'
C4374|'*declaração*': método de interface não será implementado por método não virtual '*declaração*'
C4375|método não public '*declaração*'não substitui'*declaração*'
C4376|especificador de acesso '*especificador*:' não é mais suportado: use '*especificador*:' em vez disso
C4377|tipos nativos são private por padrão. -d1PrivateNativeTypes é preterido
C4378|Deve obter ponteiros de função para executar inicializadores; Considere System::ModuleHandle::ResolveMethodHandle
C4379|Versão *versão* do common language runtime não tem suporte por este compilador. Usando essa versão pode causar resultados inesperados
C4381|'*declaração*': método de interface não será implementado por método não public '*declaração*'
C4382|Lançando '*tipo*': um tipo com clrcall destruidor ou Construtor de cópia só pode ser capturado em /clr: pure módulo
C4383|'*tipo*': o significado de desreferenciar um identificador pode mudar, quando um usuário definido pelo '*operador*' operador existe; escreva o operador como uma função estática para ser explícito sobre o operando
C4384|#pragma '*diretiva*' deve ser usado somente no escopo global
C4393|'*tipo*': const não tem efeito sobre *descrição* membro de dados; ignorado
C4394|'*tipo*': símbolo per-appdomain não deve ser marcado com declspec (*valor*)
C4395|'*tipo*': função de membro será invocada em uma cópia do membro de dados initonly '*tipo*'
C4397|DefaultCharSetAttribute é ignorado
C4398|'*tipo*': objeto global de cada processo poderão não funcionar corretamente com múltiplos appdomains; considere o uso de __declspec(appdomain)
C4399|'*tipo*': símbolo per-process não deve ser marcado com declspec (*valor*) quando compilado com /clr: pure
C4400|'*tipo*': não há suporte para qualificadores const/volatile neste tipo
C4412|'*declaração*': assinatura de função contém o tipo '*tipo*'; Objetos de C++ são seguros para passar entre código puro e combinado ou nativo.
C4429|possíveis incompleto ou formado incorretamente-nome de caractere universal
C4430|faltando especificador de tipo - int assumido. Observação: C++ não suporta default-int
C4431|faltando especificador de tipo - int assumido. Observação: C não suporta default-int
C4434|um construtor static deve possuir acessibilidade private; alterando para acesso privado
C4439|'*tipo*': definição de função com um tipo gerenciado na assinatura deve ter um clrcall convenção de chamada
C4441|convenção de chamada de '*convenção*' ignorado; '*convenção*' usado em vez disso
C4445|'*declaração*': em um tipo gerenciado/WinRT um método virtual não pode ser privado
C4460|CLR/WinRT operador '*tipo*', tem o parâmetro passado por referência. CLR/WinRT operador '*operador*'tem uma semântica diferente do operador de C++'*operador*', você pretendia passar por valor?
C4461|'*tipo*': essa classe tem um finalizador '! *tipo de*', mas nenhum destruidor ' ~*tipo*'
C4470|pragmas de controle de ponto flutuante ignorados sob /clr
C4480|extensão não padrão usada: especificação de tipo subjacente para enumeração '*tipo*'
C4481|extensão não padrão usada: especificador de substituição '*especificador*'
C4482|extensão não padrão usada: enum '*tipo*' usado no nome qualificado
C4483|Erro de sintaxe: esperada palavra-chave C++
C4484|'*tipo*': correspondências de método ref class base '*tipo*', mas não está marcado como 'virtual', 'new' ou 'override'; 'new' (e não 'virtual') é assumido
C4485|'*tipo*': correspondências de método ref class base '*tipo*', mas não está marcado como 'new' ou 'override'; 'new' (e 'virtual') são assumidos
C4486|'*tipo*': um método private virtual de uma classe ref ou classe de valor deve ser marcado como 'sealed'
C4487|'*tipo*': correspondências herdadas de método não virtual '*tipo*', mas não está explicitamente marcado como 'new'
C4488|'*tipo*': requer '*palavra-chave*'palavra-chave para implementar o método de interface'*tipo*'
C4489|'*palavra-chave*': não é permitido em método de interface '*nome*'; especificadores são permitidos apenas em métodos da classe ref classe e o valor de substituição
C4490|'*palavra-chave*': uso incorreto de especificador de substituição; '*tipo*' não coincide com um método de classe ref base
C4538|'*tipo*': não há suporte para qualificadores const/volatile neste tipo
C4559|'*tipo*': redefinição; os ganhos de função declspec (*valor*)
C4565|'*tipo*': redefinição; símbolo foi declarado anteriormente com declspec (*valor*)
C4566|caractere representado por nome de caractere universal '*caractere*' não pode ser representado na página de código atual (*número*)
C4568|'*tipo*': nenhum membro corresponde à assinatura da substituição explícita
C4569|'*tipo*': nenhum membro corresponde à assinatura da substituição explícita
C4570|'*tipo*': não é declarado explicitamente como abstract, mas possui funções abstract
C4571|Informativo: semântica catch alterada desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas
C4572|Atributo [ParamArray] é preterido sob /clr, use '...' em vez disso
C4580|[attribute] é preterido; em vez disso, especifique *especificado*atributo como uma classe base
C4581|comportamento preterido: ' "*nome*"' substituído por '*nome*' para processar atributo
C4606|Aviso #pragma: '*número*' ignorado; Avisos da análise de código não estão associados com níveis de aviso
C4631|MSXML ou XPath indisponível, documento XML de comentários não serão processados. *description*
C4632|Comentário de documento XML: *descrição* -acesso negado: *descrição*
C4633|Comentário de documento XML *descrição*: erro: *descrição*
C4634|Comentário de documento XML *descrição*: não pode ser aplicado: *descrição*
C4635|Comentário de documento XML *descrição*:-XML malformado: *descrição*
C4636|Comentário de documento XML *descrição*: marca requer vazio '*descrição*' atributo.
C4637|Comentário de documento XML *descrição*: \<incluem > marca descartada. *description*
C4638|Comentário de documento XML *descrição*: referência a símbolo desconhecido '*descrição*'.
C4639|Erro MSXML, documento XML de comentários não serão processados. *description*
C4641|Comentário de documento XML tem uma referência cruzada ambígua:
C4678|classe de base*declaração*'é menos acessível que'*nome*'
C4679|'*descrição*': não foi possível importar membro
C4687|'*tipo*': uma classe sealed abstract não pode implementar uma interface '*tipo*'
C4688|'*nome*': lista de restrições contém tipo private de assembly '*declaração*'
C4690|\[ emitidl (pop)]: mais ativações do que envios por push
C4691|'*tipo*': tipo referenciado era esperado no não referenciados *módulo* '*descrição*', tipo definido na unidade de tradução atual usada em vez disso
C4692|'*nome*': assinatura de membro não private contém tipo nativo private de assembly '*declaração*'
C4693|'*tipo*': uma classe sealed abstract não pode ter quaisquer membros de instância*nome*'
C4694|'*tipo*': uma classe sealed abstract não pode ter uma classe base*tipo*'
C4720|relatórios de assembler embutido: '*descrição*'
C4721|'*descrição*': não disponível como um intrínseco
C4722|'*descrição*': destruidor nunca retorna, potencial perda de memória
C4726|ARM arch4/4T suporta apenas '\<cpsr_f > ou \<spsr_f >' com valor imediato
C4727|PCH nomeado *nome* com o mesmo carimbo de hora encontrado no *nome* e *nome*.  Usando primeiro PCH.
C4729|avisos baseados em função muito grande para um gráfico de fluxo
C4730|'*descrição*': misturar _m64 e expressões podem resultar em um código incorreto de ponto flutuante
C4731|'*descrição*': registro de ponteiro de quadro '*registrar*' modificado por código de assembly embutido
C4732|intrínseco '*intrínseco*' não tem suporte nesta arquitetura
C4733|Asm embutido atribuindo para 'FS:0': manipulador não registrado como manipulador seguro
C4734|Mais de 64K números de linha em um COFF depurar seção de informações; interromper a emissão de números de linha de depuração COFF para módulo '*módulo*'
C4738|armazenando o resultado float de 32 bits na memória, possível perda de desempenho
C4739|referência à variável '*variável*' excede seu espaço de armazenamento
C4740|fluxo para dentro ou fora do código asm embutido suprime otimização global
C4742|'*variável*'possui alinhamento diferente '*local*'e'*local*': *número* e *número*
C4743|'*nome*'tem tamanho diferente '*local*'e'*local*': *número* e *número* bytes
C4744|'*nome*'tem tipo diferente '*local*'e'*local*': '*tipo*'e'*tipo*'
C4747|Chamar gerenciado '*tipo*': Código gerenciado não pode ser executado sob bloqueio do carregador, incluindo o ponto de entrada da DLL e chamadas acessadas do ponto de entrada DLL
C4761|incompatibilidade do tamanho integral em argumento; conversão fornecida
C4764|Não é possível alinhar objetos catch maiores que 16 bytes
C4788|'*identificador*': identificador foi truncado para '*número*' caracteres
C4789|buffer '*nome*' de tamanho *número* bytes serão substituídos; *número* bytes serão escritos começando no deslocamento *número*
C4801|Retorno por referência não é verificável: *descrição*
C4819|O arquivo contém um caractere que não pode ser representado na página de código atual (*número*). Salve o arquivo no formato Unicode para evitar a perda de dados
C4826|Conversão de '*tipo*'para'*tipo*' é estendido com sinal. Isso pode causar um comportamento inesperado de tempo de execução.
C4829|Parâmetros possivelmente incorretos para função principal. Considere a possibilidade de ' int principal (Platform:: array\<Platform:: String ^ > ^ argv)'
C4835|'*tipo*': o inicializador para dados exportados não será executado até que o código gerenciado é executado pela primeira vez no host assembly
C4867|'*tipo*': sintaxe não padrão; use '&' para criar um ponteiro para membro
C4936|Este declspec é suportado apenas quando compilado com /clr ou /clr: pure
C4937|'*nome*'e'*nome*'são indistinguíveis como argumentos para'*opção*'
C4938|'*type*': Variável de redução de ponto flutuante pode causar resultados inconsistentes sob /fp: strict ou #pragma fenv_access
C4939|#pragma vtordisp é preterido e será removido em uma versão futura do Visual C++
C4947|'*tipo*': marcado como obsoleto
C4949|pragmas 'managed' e 'unmanaged' são significativos apenas quando compilado com ' / clr [: opção]'
C4950|'*tipo*': marcado como obsoleto
C4955|'*descrição*': importação ignorada; já importado de '*origem*'
C4956|'*tipo*': esse tipo não é verificável
C4957|'*expressão*': conversão explícita de '*tipo*'para'*tipo*' não é verificável
C4958|'*expressão*': aritmética de ponteiro não é verificável
C4959|não é possível definir não gerenciado *classe* '*tipo*' em /CLR: safe porque o acesso aos seus membros produz código não verificável
C4960|'*descrição*' é muito grande para ser analisado
C4961|Nenhum dado de perfil foi mesclado em '*local*', otimizações guiadas por perfil desabilitadas
C4962|'*description*': Otimizações guiadas por perfil desabilitadas porque otimizações fizeram dados de perfil se tornar inconsistente
C4963|'*descrição*': nenhum dado de perfil encontrado; opções de compilação diferentes foram usadas em compilação instrumentada
C4964|Não há opções de otimização foram especificadas; informações de perfil não serão coletadas
C4965|box implícito de inteiro 0; Use nullptr ou conversão explícita
C4970|construtor delegate: objeto de destino ignorado desde '*declaração*' é estático
C4971|Ordem de argumentos: \<objeto de destino >, \<função de destino > para construtor delegate é preterida, use \<função de destino >, \<objeto de destino >
C4972|Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável

## <a name="warnings-introduced-in-visual-c-2003-compiler-version-13103077"></a>Avisos introduzidos no Visual C++ 2003 (versão do compilador 13.10.3077)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:13.00.9466__.

|||
|-|-|
C4343|otimizar #pragma (*descrição*, off) substitui opção /Og
C4344|alteração de comportamento: uso dos resultados de argumentos de modelo explícitos na chamada para '*declaração*'
C4346|'*tipo*': nome dependente não é um tipo
C4348|'*declaração*': redefinição do parâmetro padrão: parâmetro *número*
C4356|'*tipo*': membro de dados estático não pode ser inicializado via classe derivada
C4408|anônimo *struct* não declarou nenhum membro de dados
C4544|'*declaração*': argumento de modelo ignorado nessa declaração de template padrão
C4545|expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos
C4546|faltando lista de argumentos na chamada de função antes da vírgula
C4547|'*expressão*': operador antes da vírgula não tem nenhum efeito; esperado operador com efeito colateral
C4548|expressão antes da vírgula não tem efeito; expressão esperada com efeito colateral
C4549|'*expressão*': operador antes da vírgula não tem nenhum efeito; você pretendia '*expressão*'?
C4628|dígrafos não suportados com -Ze. Sequência de caracteres '*sequência*'não é interpretada como token alternativo para'*token*'
C4629|dígrafo usado, sequência de caracteres '*sequência*'interpretada como token'*token*' (inserir um espaço entre os dois caracteres quando se trata de não o que você pretendia)
C4671|'*descrição*': o construtor de cópia é inacessível
C4676|'*descrição*': o destruidor é inacessível
C4677|'*nome*': assinatura de membro não private contém tipo private de assembly '*declaração*'
C4686|'*tipo*': possível alteração no comportamento, alteração na UDT retorne a convenção de chamada
C4812|estilo de declaração obsoleta: use '*tipo*::*nome*' em vez disso
C4813|'*tipo*': uma função friend de uma classe local deve ter sido declarada anteriormente
C4821|Não é possível determinar o tipo de codificação Unicode, salve o arquivo com assinatura (BOM)
C4822|'*tipo*': função de membro de classe local não tem um corpo
C4823|'*tipo*': usa ponteiros de fixação de desenrolamento, mas semântica não está habilitada. Considere o uso de /EHa
C4913|usuário definido pelo operador binário ',' existe mas nenhuma sobrecarga pôde converter todos os operando, operador binário interno padrão ',' usado
C4948|tipo de retorno de '*declaração*' não coincide com o último tipo de parâmetro do setter correspondente
C4951|'*descrição*' foi editado desde o perfil de dados foram coletados, dados de perfil de função não usados
C4952|'*descrição*': nenhum dado de perfil encontrado no banco de dados do programa '*descrição*'
C4953|Item embutido '*descrição*' foi editado desde o perfil de dados foram coletados, dados de perfil não usados
C4954|'*descrição*': não analisado (contém expressão de switch __int64)

## <a name="warnings-introduced-in-visual-c-2002-compiler-version-13009466"></a>Avisos introduzidos no Visual C++ 2002 (versão do compilador 13.00.9466)

Esses avisos e todos os avisos em versões posteriores são suprimidos usando a opção de compilador __/Wv:12__.

|||
|-|-|
C4096|'*tipo*': interface não é uma interface COM; não será emitida para IDL
C4097|esperado parâmetro de pragma como ' Restore ' ou 'off'
C4165|'HRESULT' está sendo convertido em 'bool'; Tem certeza de que é isso que você deseja?
C4183|'*nome*': faltando tipo de retorno; assumido como uma função de membro retornando 'int'
C4199|*description*
C4255|'*nome*': nenhum protótipo de função fornecido: convertendo '()' para '(void)'
C4256|'*declaração*': construtor de classe com bases virtuais possui '...'; chamadas podem não ser compatíveis com versões anteriores do Visual C++
C4258|'*nome*': definição a partir de loop é ignorada; a definição do escopo delimitador é usada
C4263|'*declaração*': função de membro não substitui nenhuma função de membro virtual da classe base
C4264|'*declaração*': nenhuma substituição disponível para função membro virtual da Base de dados de '*classe*'; função é ocultada
C4265|'*tipo*': classe possui funções virtual, mas não o destruidor é virtual instâncias dessa classe podem não ser destruídas corretamente
C4266|'*declaração*': nenhuma substituição disponível para função membro virtual da Base de dados de '*classe*'; função é ocultada
C4267|'*expressão*': conversão de 'size_t' para '*tipo*', possível perda de dados
C4274|#ident ignored; see documentation for #pragma comment(exestr, 'string')
C4277|item importado '*tipo*::*nome*' existe como membro de dados e o membro da função; membro de dados ignorado
C4278|'*nome*': identificador em biblioteca de tipos '*descrição*' já é uma macro; use o qualificador 'rename'
C4279|'*nome*': identificador em biblioteca de tipos '*descrição*' é uma palavra-chave; use o qualificador 'rename'
C4287|'*expressão*': incompatibilidade de constante unsigned/negativa
C4288|extensão não padrão usada: '*nome*': variável de controle de loop declarada no loop for é usada fora do escopo de loop for; ela entra em conflito com a declaração no escopo externo
C4289|extensão não padrão usada: '*nome*': variável de controle de loop declarada no loop for é usada fora do escopo de loop for
C4293|'*expressão*': shift Contagem negativa ou muito grande, comportamento indefinido
C4295|'*tipo*': matriz é muito pequena para incluir um caractere nulo de terminação
C4296|'*expressão*': a expressão é sempre *valor*
C4297|'*tipo*': função não deveria para lançar uma exceção, mas não
C4298|'*nome*': identificador em biblioteca de tipos '*descrição*' já é uma macro; renomeando para ' _*nome*'
C4299|'*nome*': identificador em biblioteca de tipos '*descrição*' é uma palavra-chave; renomeando para ' _*nome*'
C4302|'*expressão*': truncamento de '*tipo*'para'*tipo*'
C4303|*conversão* de '*tipo*'para'*tipo*' é preterida, use static_cast, try_cast ou dynamic_cast
C4314|esperado parâmetro de pragma como '32' ou '64'
C4315|'*tipo*': ponteiro 'this' para membro '*tipo*' pode não estar alinhado *número* conforme o esperado pelo construtor
C4318|passando constante zero como o comprimento para memset
C4319|'*expressão*': estendendo o zero '*tipo*'para'*tipo*' de tamanho maior
C4321|Gerando automaticamente um IID para interface '*tipo*'
C4322|Gerando automaticamente um CLSID para classe*tipo*'
C4323|reutilizando CLSID registrado para classe*tipo*'
C4324|'*tipo*': estrutura foi preenchida devido ao especificador de alinhamento
C4325|atributos para seção padrão '*descrição*' ignorado
C4326|tipo de retorno de '*nome*'deve ser'*tipo*'em vez de'*tipo*'
C4327|'*expressão*': alinhamento de indireção de LHS (*número*) é maior do que de RHS (*número*)
C4328|'*descrição*': alinhamento de indireção de parâmetro formal *número* (*número*) é maior que o alinhamento de argumento real (*número*)
C4329|especificador de alinhamento é ignorado em enumeração
C4336|Importar a biblioteca de tipos com referência cruzada '*biblioteca*'antes de importar'*descrição*'
C4337|biblioteca de tipos com referência cruzada '*biblioteca*'in'*descrição*' está sendo importada automaticamente
C4338|#pragma *descrição*: seção padrão '*seção*' é usado
C4339|'*tipo*': uso de tipo indefinido detectado em metadados CLR/WinRT - uso desse tipo pode levar a uma exceção de tempo de execução
C4353|extensão não padrão usada: constante 0 como expressão de função.  Use NOOP' função intrínseca
C4370|'*declaração*': layout da classe foi alterado de uma versão anterior do compilador devido a empacotamento melhor
C4371|'*declaração*': layout da classe pode ter alterado de uma versão anterior do compilador devido a empacotamento melhor do membro '*membro*'
C4373|'*tipo*': substituições de função virtual*declaração*', as versões anteriores do compilador não substituíam quando parâmetros diferiam apenas em qualificadores const/volatile
C4387|'*descrição*': foi considerado
C4389|'*expressão*': incompatibilidade de signed/unsigned
C4391|'*declaração*': tipo de retorno incorreto para função intrínseca, esperado '*tipo*'
C4392|'*declaração*': número incorreto de argumentos para função intrínseca, esperado '*número*' argumentos
C4407|conversão entre diferente ponteiro para representações de membro, compilador pode gerar código incorreto
C4420|'*nome*': operador não está disponível, usando '*nome*'; verificação de tempo de execução pode ser comprometida
C4440|redefinição de convenção de chamada de '*descrição*'para'*descrição*' ignorado
C4442|terminador nulo inserido no argumento de Annotation.  Valor será truncado.
C4444|'*nome*': unaligned' de nível superior não está implementado neste contexto
C4526|'*tipo*': função de membro estático não pode substituir função virtual '*declaração*' substituição ignorada, função virtual será ocultada
C4531|Tratamento de exceções de C++ não disponível no Windows CE. Use o tratamento de exceções estruturado
C4532|'*descrição*': ignorar *finalmente* bloco tem um comportamento indefinido durante manipulação de encerramento
C4533|inicialização de '*declaração*' é ignorada por ' goto *declaração*'
C4534|'*declaração*' não será um construtor padrão para *classe* '*tipo*' devido ao argumento padrão
C4535|chamada set_se_translator () requer /EHa
C4536|'*descrição*': nome do tipo excede o limite de metadados de '*número*' caracteres
C4537|'*declaração*': '.' aplicado a tipo não UDT
C4542|Ignorando a geração do arquivo de texto injetado mesclado, não é possível gravar *tipo* arquivo: '*filename*': *erro*
C4543|Injetado suprimido por atributo de texto ' sem\_injected_text'
C4555|expressão não tem efeito; expressão esperada com efeito colateral
C4557|assume' contém efeito '*efeito*'
C4558|valor do operando '*número*'está fora do intervalo'*número* - *número*'
C4561|fastcall' incompatível com o ' / clr' opção: convertendo para stdcall'
C4562|funções totalmente prototipadas são necessárias com o ' / clr' opção: convertendo '()' para '(void)'
C4564|método '*nome*' da *classe* '*tipo*'define parâmetro padrão sem suporte'*parâmetro*'
C4584|'*tipo*': classe base*declaração*'já é uma classe base de'*declaração*'
C4608|Inicializando vários membros de união: '*tipo*'e'*tipo*'
C4619|Aviso #pragma: há um número de aviso '*número*'
C4623|'*tipo*': construtor padrão foi implicitamente definido como excluído
C4624|'*tipo*': destrutor foi implicitamente definido como excluído
C4625|'*tipo*': construtor de cópia foi implicitamente definido como excluído
C4626|'*tipo*': operador de atribuição foi implicitamente definido como excluído
C4645|função declarada com 'noreturn' tem uma instrução return
C4646|função declarada com 'noreturn' tem o tipo de retorno não nulo
C4659|#pragma '*descrição*': uso de segmento reservado '*nome*' tem um comportamento indefinido, use #pragma comment (linker,...)
C4667|'*declaração*': nenhum template de função definido que corresponda à instanciação de forçada
C4668|'*nome*'não está definido como uma macro de pré-processador, substituindo por '0' para'*valor*'
C4669|'*expressão*': conversão não segura: '*tipo*' é um objeto do tipo gerenciado/WinRT
C4674|'*nome*' deve ser declarado como 'static' e ter exatamente um parâmetro
C4680|'*tipo*': coclass não especifica uma interface padrão
C4681|'*tipo*': coclass não especifica uma interface padrão que é uma origem do evento
C4682|'*tipo*': nenhum atributo de parâmetro direcional especificado, padronizando para [in]
C4683|'*declaração*': origem do evento tem um 'out'-parâmetro; tome cuidado ao capturar vários manipuladores de eventos
C4684|'*description*': AVISO!! atributo pode causar a geração de código inválido: use com cuidado
C4685|esperando ' >> ' encontrado ' >> ' durante a análise de parâmetros de modelo
C4700|variável local não inicializada '*nome*' usado
C4701|variável local possivelmente não inicializada '*nome*' usado
C4702|Código inacessível
C4711|função '*nome*' selecionada para expansão inline automática
C4714|função '*declaração*' marcada como forceinline não embutida
C4715|'*função*': nem todos os caminhos de controle retornam um valor
C4716|'*função*': deve retornar um valor
C4717|'*função*': recursivo em todos os caminhos de controle, função causará estouro de pilha de tempo de execução
C4718|'*função*': chamada recursiva não tem efeitos colaterais, excluindo
C4719|Constante Double encontrada com Qfast especificado - use 'f' como um sufixo para indicar precisão simples
C4723|possível divisão por 0
C4724|possível mod por 0
C4725|instrução pode ser incorreta em alguns Pentiums
C4757|subscrito é um valor unsigned grande, você pretendia uma constante negativa?
C4772|#import referenciou um tipo de uma biblioteca de tipos faltando; '*descrição*' usado como um espaço reservado
C4792|função '*função*' declarada usando sysimport e referenciada do código nativo; biblioteca de importação requerida para vincular
C4794|segmento da variável de armazenamento local de thread '*nome*'alterado de'*segmento*'para'*segmento*'
C4798|código nativo gerado para a função de pseudocódigo '*nome*' com manipulador de exceção ou semântica de liberação
C4799|função '*nome*' não possui instrução EMMS
C4803|'*declaração*': o método raise possui uma classe de armazenamento diferente do evento, '*declaração*'
C4810|valor de pragma Pack (show) = = *número*
C4811|valor de pragma conform (forScope, show) = = *valor*
C4820|'*tipo*': '*número*' bytes de preenchimento adicionados após *tipo* '*tipo*'
C4905|cadeia de caracteres largo literal convertida em '*tipo*'
C4906|cadeia de caracteres literal convertida em '*tipo*'
C4912|'*atributo*': atributo possui comportamento indefinido em um UDT aninhado
C4916|para ter um dispid, '*tipo*': deve ser introduzido por uma interface
C4917|'*tipo*': um GUID só pode ser associado uma classe, interface ou namespace
C4918|'*caractere*': caractere inválido na lista de otimização do pragma
C4920|Enum *nome* membro *nome*=*número* já visto em enumeração *nome* como *nome* = *número*
C4921|'*nome*': valor do atributo '*valor*' não deve ser especificado várias vezes
C4925|'*declaração*': método dispinterface não pode ser chamado a partir do script
C4926|'*declaração*': símbolo já definido: atributos ignorados
C4927|conversão ilegal; mais de uma conversão definida pelo usuário foi aplicada implicitamente
C4928|inicialização de cópia ilegal; mais de uma conversão definida pelo usuário foi implicitamente aplicada
C4929|'*descrição*': typelibrary contém uma union; ignorando o qualificador 'embedded_idl'
C4930|'*declaração*': função prototipada não chamada (era uma definição de variável se destina?)
C4931|estamos supondo que a biblioteca de tipos foi criada para o *número*-ponteiros de bit
C4932|Identifier (*descrição*) e Identifier (*descrição*) são indistinguíveis
C4934|'__delegate(multicast)' é preterido, use delegate' em vez disso
C4935|especificador de acesso de assembly modificado de '*descrição*'
C4944|'*nome*': não é possível importar símbolo de '*fonte*': como*declaração*' já existe no escopo atual
C4945|'*nome*': não é possível importar símbolo de '*fonte*': como*declaração*'já foi importado de outro assembly'*origem*'
C4946|reinterpret_cast usado entre classes relacionadas: '*declaração*'e'*declaração*'
C4995|'*nome*': nome foi marcado como #pragma preterido
C4996|'*problema*': *descrição*
C4997|'*tipo*': coclass não implementa uma interface COM ou pseudointerface
C4998|Falha na EXPECTATIVA: *descrição*(*número*)

## <a name="see-also"></a>Consulte também

- [Opção de compilador /wv](../../build/reference/compiler-option-warning-level.md)
- [Avisos do compilador que são desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md)
- [warning](../../preprocessor/warning.md)
