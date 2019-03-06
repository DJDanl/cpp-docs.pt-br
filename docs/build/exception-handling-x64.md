---
title: x64 tratamento de exceção
ms.date: 12/17/2018
helpviewer_keywords:
- C++ exception handling, x64
- exception handling, x64
ms.assetid: 41fecd2d-3717-4643-b21c-65dcd2f18c93
ms.openlocfilehash: 7dab7f3b6593bf4eaed1b8c804deb915677ccf5b
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422969"
---
# <a name="x64-exception-handling"></a>x64 tratamento de exceção

Uma visão geral de tratamento de exceções estruturado e tratamento de exceções de C++, codificação, convenções e o comportamento no x64. Para obter informações gerais sobre o tratamento de exceções, consulte [tratamento de exceções em Visual C++](../cpp/exception-handling-in-visual-cpp.md).

## <a name="unwind-data-for-exception-handling-debugger-support"></a>Desenrolar dados para a manipulação de exceção, suporte do depurador

Várias estruturas de dados são necessárias para a manipulação de exceção e suporte à depuração.

### <a name="struct-runtimefunction"></a>struct RUNTIME_FUNCTION

Tratamento de exceções baseado em tabela requer uma entrada de tabela para todas as funções que alocam espaço na pilha ou chamar outra função (por exemplo, funções de não-folha). Entradas da tabela de função têm o formato:

|||
|-|-|
|ULONG|Endereço de início da função|
|ULONG|Endereço final da função|
|ULONG|Endereço de informações de desenrolamento|

A estrutura RUNTIME_FUNCTION deve ser DWORD alinhado na memória. Todos os endereços são imagem relativa, ou seja, eles são deslocamentos de 32 bits do endereço inicial da imagem que contém a entrada da tabela de função. Essas entradas são classificadas e colocadas na seção. pData de uma imagem PE32 +. Para funções geradas dinamicamente [compiladores JIT], o tempo de execução para dar suporte a essas funções deve usar RtlInstallFunctionTableCallback ou RtlAddFunctionTable para fornecer essas informações para o sistema operacional. Falha ao fazer isso resulta em não-confiável manipulação de exceção e depuração dos processos.

### <a name="struct-unwindinfo"></a>struct UNWIND_INFO

A estrutura de informações de dados de desenrolamento é usada para registrar os efeitos de que uma função tem no ponteiro de pilha e onde os registros não voláteis são salvos na pilha:

|||
|-|-|
|UBYTE: 3|Versão|
|UBYTE: 5|Sinalizadores|
|UBYTE|Tamanho do prólogo|
|UBYTE|Contagem de códigos de desenrolamento|
|UBYTE: 4|Registre-se do quadro|
|UBYTE: 4|Deslocamento do quadro de registro (escalado)|
|USHORT \* n|Matriz de códigos de desenrolamento|
|variável|Qualquer um pode ser do formulário (1) ou (2) a seguir|

(1) manipulador de exceção

|||
|-|-|
|ULONG|Endereço do manipulador de exceção|
|variável|Dados de manipulador específico do idioma (opcional)|

(2) encadeadas informações de desenrolamento

|||
|-|-|
|ULONG|Endereço de início da função|
|ULONG|Endereço final da função|
|ULONG|Endereço de informações de desenrolamento|

A estrutura UNWIND_INFO deve ser DWORD alinhado na memória. Aqui está o que significa que cada campo:

- **Versão**

   Número de versão dos dados de desenrolamento, 1 no momento.

- **Sinalizadores**

   Três sinalizadores são definidos no momento:

   |Sinalizador|Descrição|
   |-|-|
   |`UNW_FLAG_EHANDLER`| A função tem um manipulador de exceção que deve ser chamado durante a procura de funções que precisam examinar exceções.|
   |`UNW_FLAG_UHANDLER`| A função tem um manipulador de término deve ser chamado quando o desenrolamento de uma exceção.|
   |`UNW_FLAG_CHAININFO`| Essa estrutura não é a principal para o procedimento de informações de desenrolamento. Em vez disso, o encadeadas desenrolamento de informações de entrada é o conteúdo de uma entrada RUNTIME_FUNCTION anterior. Para obter informações, consulte [estruturas de informações de desenrolamento Chained](#chained-unwind-info-structures). Se esse sinalizador estiver definido, os sinalizadores UNW_FLAG_EHANDLER e UNW_FLAG_UHANDLER devem ser limpo. Além disso, os campos de alocação de registro e a pilha fixa quadro devem ter os mesmos valores de primário informações de desenrolamento.|

- **Tamanho do prólogo**

   Comprimento do prólogo da função em bytes.

- **Contagem de códigos de desenrolamento**

   O número de slots na matriz de códigos de desenrolamento. Alguns códigos de desenrolamento, por exemplo, UWOP_SAVE_NONVOL, exigem mais de um slot na matriz.

- **Registre-se do quadro**

   Se diferente de zero, em seguida, a função usa um ponteiro de quadro (FP) e esse campo é o número do registro não volátil usado como o ponteiro de quadro, usando a mesma codificação para o campo de informações de operação de nós UNWIND_CODE.

- **Quadro registrar deslocamento (escalado)**

   Se o campo de registro do quadro é diferente de zero, este campo é o deslocamento em escala de RSP que é aplicada a FP registrar quando ela é estabelecida. O registro FP real é definido como RSP + 16 \* esse número, permitindo que os deslocamentos de 0 a 240. Esse deslocamento permite que aponta para o registro FP no meio da alocação da pilha local dinâmico dos quadros de pilha, permitindo melhor densidade do código por meio de instruções mais curtas (mais instruções podem usar o formulário de deslocamento com sinal de 8 bits).

- **Matriz de códigos de desenrolamento**

   Uma matriz de itens que explica o efeito de prólogo nos registros não voláteis e RSP. Consulte a seção sobre UNWIND_CODE para os significados dos itens individuais. Para fins de alinhamento, essa matriz sempre tem um número par de entradas e a entrada final é potencialmente não utilizada. Nesse caso, a matriz é um mais do que o indicado pela contagem de campo de códigos de desenrolamento.

- **Endereço do manipulador de exceção**

   Um ponteiro de relativos a imagem de exceção específicos da linguagem da função ou manipulador de término, se o sinalizador UNW_FLAG_CHAININFO é clara e um dos sinalizadores UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER é definido.

- **Dados do manipulador específico do idioma**

   Dados da função do manipulador de exceção específicos da linguagem. O formato desses dados é não for especificado e completamente determinado pelo manipulador de exceção específico em uso.

- **Encadeadas informações de desenrolamento**

   Se o sinalizador UNW_FLAG_CHAININFO estiver definido, em seguida, a estrutura UNWIND_INFO termina com três UWORDs.  Esses UWORDs representam as informações de RUNTIME_FUNCTION para a função do desenrolamento encadeada.

### <a name="struct-unwindcode"></a>struct UNWIND_CODE

A matriz de código de desenrolamento é usada para registrar a sequência de operações no prólogo que afetam os registros não voláteis e RSP. Cada item de código tem este formato:

|||
|-|-|
|UBYTE|Deslocamento no prólogo|
|UBYTE: 4|Código de operação de desenrolamento|
|UBYTE: 4|Informações de operação|

A matriz é classificada por ordem decrescente de deslocamento no prólogo.

#### <a name="offset-in-prolog"></a>Deslocamento no prólogo

Deslocamento do início do prólogo do fim da instrução que executa esta operação, além de 1 (ou seja, o deslocamento do início da próxima instrução).

#### <a name="unwind-operation-code"></a>Código de operação de desenrolamento

Observação: Determinados códigos de operação requer um deslocamento não assinado com um valor no quadro de pilha local. Esse deslocamento é desde o início, ou seja, o endereço mais baixo da alocação de pilha fixa. Se o campo quadro registrar o UNWIND_INFO for zero, esse deslocamento é from RSP. Se o campo de registrar o quadro for diferente de zero, este é o deslocamento a partir de onde RSP estava localizado quando o registro FP foi estabelecido. Isso é igual a de FP menos o deslocamento do registro FP (16 \* o quadro dimensionado e registrar o deslocamento no UNWIND_INFO). Se um registro de FP for usado, em seguida, qualquer código de desenrolamento levando um deslocamento deve ser usado somente depois que o registro FP é estabelecido no prólogo.

Para todos os opcodes, exceto `UWOP_SAVE_XMM128` e `UWOP_SAVE_XMM128_FAR`, o deslocamento é sempre um múltiplo de 8, porque a pilha de todos os valores de interesse são armazenados em limites de 8 bytes (a pilha em si é sempre alinhado de 16 bytes). Para códigos de operação que assumem um deslocamento curto (menos de 512K), o final USHORT em nós para este código mantém o deslocamento dividido por 8. Para códigos de operação que assumem um deslocamento longo (512K < = < 4GB de deslocamento), os dois nós USHORT finais para que esse código mantêm o deslocamento (no formato little-endian).

Para os opcodes `UWOP_SAVE_XMM128` e `UWOP_SAVE_XMM128_FAR`, o deslocamento é sempre um múltiplo de 16, já que todas as operações MMX de 128 bits devem ocorrer em memória de 16 bytes alinhada. Portanto, um fator de escala de 16 é usado para `UWOP_SAVE_XMM128`, permitindo que os deslocamentos de menos de 1 M.

O código de operação de desenrolamento é um destes valores:

- `UWOP_PUSH_NONVOL` (0) 1 nó

  Enviar por push um registro inteiro não volátil, diminuindo RSP por 8. As informações de operação são o número do registro. Devido às restrições em epílogos, `UWOP_PUSH_NONVOL` códigos de desenrolamento deverão aparecer primeiros no prólogo e sobrenome do mesmo modo, na matriz de código de desenrolamento. Essa ordenação relativa se aplica a todos os outros códigos de desenrolamento, exceto `UWOP_PUSH_MACHFRAME`.

- `UWOP_ALLOC_LARGE` (1) 2 ou 3 nós

  Aloca uma área de grande porte na pilha. Há duas formas. Se as informações de operação for igual a 0 e, em seguida, o tamanho da alocação dividido por 8 é registrado no slot de Avançar, permitindo que uma alocação até 512 K - 8. Se as informações de operação é igual a 1, o tamanho de fora de escala da alocação é registrado nos próximos dois slots no formato little-endian, permitindo que as alocações de até 4GB - 8.

- `UWOP_ALLOC_SMALL` (2) nó 1

  Aloca uma área de pequeno porte na pilha. O tamanho da alocação é o campo de informações de operação \* 8 + 8, permitindo que as alocações de 8 a 128 bytes.

  O código de desenrolamento para uma alocação de pilha sempre deve usar a mais curta possível codificação:

  |**Tamanho de alocação**|**Código de desenrolamento**|
  |-|-|
  |8 a 128 bytes|`UWOP_ALLOC_SMALL`|
  |136 para 512K - 8 bytes|`UWOP_ALLOC_LARGE`, informações de operação = 0|
  |G 512K para 4 – 8 bytes|`UWOP_ALLOC_LARGE`, informações de operação = 1|

- `UWOP_SET_FPREG` (3) 1 nó

  Estabelece o registro de ponteiro de quadro, definindo o registro para alguns deslocamento do RSP atual. O deslocamento é igual ao registrar o quadro deslocamento (escala) campo no UNWIND_INFO \* 16, permitindo que os deslocamentos de 0 a 240. O uso de um deslocamento permite estabelecer um ponteiro de quadro que aponta para o meio da alocação de pilha fixa, ajudando a densidade do código, permitindo que mais acessos a usar formulários de instrução curto. O campo de informações de operação é reservado e não deve ser usado.

- `UWOP_SAVE_NONVOL` (4) 2 nós

  Salve um registro não volátil inteiros na pilha usando uma MOV em vez de um envio por PUSH. Esse código é usado principalmente para *wrapping*, onde um registro não volátil é salvo para a pilha em uma posição que foi alocada anteriormente. As informações de operação são o número do registro. O deslocamento de pilha dimensionado-by-8 é registrado nos próximos slot de código de operação de desenrolamento, conforme descrito na observação acima.

- `UWOP_SAVE_NONVOL_FAR` (5) 3 nós

  Salvar um registro não volátil inteiro na pilha com um deslocamento de tempo, usando um MOV em vez de um envio por PUSH. Esse código é usado principalmente para *wrapping*, onde um registro não volátil é salvo para a pilha em uma posição que foi alocada anteriormente. As informações de operação são o número do registro. O deslocamento de pilha fora de escala é registrado nos próximos dois slots de código de operação de desenrolamento, conforme descrito na observação acima.

- `UWOP_SAVE_XMM128` (8) nós 2

  Salve todos os 128 bits de um não-volátil XMM registrar na pilha. As informações de operação são o número do registro. O deslocamento de pilha dimensionado por 16 é registrado no slot de Avançar.

- `UWOP_SAVE_XMM128_FAR` (9) 3 nós

  Salve todos os 128 bits de um não-volátil XMM registrar na pilha com um deslocamento de tempo. As informações de operação são o número do registro. O deslocamento de pilha fora de escala é registrado nos próximos dois slots.

- `UWOP_PUSH_MACHFRAME` (10) o 1 nó

  Enviar por push um quadro de máquina.  Isso é usado para registrar o efeito de uma exceção ou interrupção de hardware. Há duas formas. Se as informações de operação é igual a 0, um desses quadros foi enviado na pilha:

  |||
  |-|-|
  |RSP+32|SS|
  |RSP+24|RSP antigo|
  |RSP+16|EFLAGS|
  |RSP+8|CS|
  |RSP|RIP|

  Se as informações de operação é igual a 1, em seguida, um desses quadros foi enviado:

  |||
  |-|-|
  |RSP+40|SS|
  |RSP+32|RSP antigo|
  |RSP+24|EFLAGS|
  |RSP+16|CS|
  |RSP+8|RIP|
  |RSP|Código de erro|

  Esse código de desenrolamento sempre aparece em um prólogo fictício, que, na verdade, nunca é executado, mas em vez disso, é exibido antes do ponto de entrada real de uma rotina de interrupção e existe somente para fornecer um local para simular o envio por push de um quadro de máquina. `UWOP_PUSH_MACHFRAME` registra a simulação, que indica que a máquina conceitualmente fez esta operação:

  1. Pop-RIP endereço de retorno da parte superior da pilha em *Temp*
  
  1. SS de envio por push

  1. Enviar por push RSP antigo

  1. Enviar por push EFLAGS

  1. Enviar por push do CS

  1. Enviar por push *Temp*

  1. Enviar por push o código de erro (se as informações de operações é igual a 1)

  Simulated `UWOP_PUSH_MACHFRAME` diminui de operação RSP em 40 (informações de operações é igual a 0) ou 48 (informações de operações é igual a 1).

#### <a name="operation-info"></a>Informações de operação

O significado dos bits de informações de operação depende do código da operação. Para codificar um registro de uso geral (inteiro), esse mapeamento é usado:

|||
|-|-|
|0|RAX|
|1|RCX|
|2|RDX|
|3|RBX|
|4|RSP|
|5|RBP|
|6|RSI|
|7|RDI|
|8 a 15|R8 para R15|

### <a name="chained-unwind-info-structures"></a>Encadeadas estruturas de informações desenroladas

Se o sinalizador UNW_FLAG_CHAININFO for definido, em seguida, uma estrutura de informações de desenrolamento é um secundário, e o campo endereço de exceção-manipulador/encadeadas-info compartilhada contém as informações de desenrolamento primário. Esse código de exemplo recupera o primário informações sobre, supondo que o desenrolamento `unwindInfo` é a estrutura que tem o UNW_FLAG_CHAININFO sinalizador definido.

```cpp
PRUNTIME_FUNCTION primaryUwindInfo = (PRUNTIME_FUNCTION)&(unwindInfo->UnwindCode[( unwindInfo->CountOfCodes + 1 ) & ~1]);
```

Informações encadeadas são úteis em duas situações. Primeiro, ele pode ser usado para segmentos de código não contíguos. Usando as informações encadeadas, você pode reduzir o tamanho das informações necessárias de desenrolamento, porque você não precisará duplicar a matriz de códigos de desenrolamento das informações de desenrolamento primário.

Você também pode usar informações encadeadas para agrupar os salvamentos voláteis. O compilador pode atrasar a salvar alguns registros voláteis até que ele esteja fora do prólogo da função de entrada. Você pode registrar isso fazendo com que as informações de desenrolamento primária para a parte da função antes do código agrupado e, em seguida, configurando encadeadas informações com um tamanho diferente de zero do prólogo, onde os códigos de desenrolamento nas informações encadeadas refletem os salvamentos de registros a não-volátil. Nesse caso, os códigos de desenrolamento são todas as instâncias de UWOP_SAVE_NONVOL. Não há suporte para um agrupamento que salva os registros não voláteis por meio de um envio por PUSH ou modifica o registro RSP por meio de uma alocação de pilha fixa adicional.

Um item UNWIND_INFO que tem UNW_FLAG_CHAININFO conjunto pode conter uma entrada de RUNTIME_FUNCTION cujo item UNWIND_INFO também tem UNW_FLAG_CHAININFO definido, às vezes, chamado *wrapping vários*. Por fim, o encadeadas informações de desenrolamento ponteiros chegarem a um item UNWIND_INFO com UNW_FLAG_CHAININFO desmarcada. Este é o item UNWIND_INFO primário, que aponta para o ponto de entrada do procedimento real.

## <a name="unwind-procedure"></a>Procedimento desenrolado

A matriz de código de desenrolamento é classificada em ordem decrescente. Quando ocorre uma exceção, o contexto completo é armazenado pelo sistema operacional em um registro de contexto. A lógica de expedição de exceção é invocada, que é executada repetidamente estas etapas para localizar um manipulador de exceção:

1. Use o RIP atual armazenado no registro de contexto para pesquisar uma entrada de tabela RUNTIME_FUNCTION que descreve a função atual (ou parte de função, para as entradas UNWIND_INFO encadeadas).

1. Se nenhuma entrada de tabela de função for encontrada, em seguida, ele está em uma função de folha e RSP atende diretamente o ponteiro retornado. O ponteiro retornado no [RSP] é armazenado no contexto atualizado, o RSP simulado é incrementado por 8 e a etapa 1 é repetida.

1. Se for encontrada uma entrada de tabela de função, RIP pode permanecer em três regiões: a) em um epílogo, b) no prólogo ou c) no código que pode ser coberto por um manipulador de exceção.

   - Caso um) se o RIP está dentro de um epílogo, em seguida, controle está deixando a função, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função e os efeitos de epílogo devem ser continuados para calcular o contexto da função do chamador. Para determinar se o RIP está dentro de um epílogo, o fluxo de código do RIP na é examinado. Se esse fluxo de código pode ser correspondido para a parte à direita de um epílogo legítimo, e em seguida, ele está em um epílogo e a parte restante do epílogo é simulada, com o registro de contexto atualizado como cada instrução é processado. Depois disso, a etapa 1 é repetida.

   - Caso b) se o RIP se encontra dentro do prólogo, em seguida, o controle não tem a função inserido, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função e os efeitos do prólogo devem ser desfeitos para calcular o contexto da função do chamador. O RIP está dentro do prólogo, se a distância do início da função para o RIP é menor ou igual ao tamanho do prólogo codificado nas informações de desenrolamento. Os efeitos do prólogo são desenrolados verificar para a frente por meio da matriz de códigos de desenrolamento para a primeira entrada com um deslocamento menor ou igual ao deslocamento do RIP desde o início da função e, em seguida, desfazendo o efeito de todos os itens restantes na matriz de código de desenrolamento. Etapa 1, em seguida, é repetida.

   - Caso c) se o RIP não está dentro do prólogo ou epílogo e a função tem um manipulador de exceção (UNW_FLAG_EHANDLER é definido) e, em seguida, o manipulador de idioma específico é chamado. O manipulador verifica seus dados e funções conforme apropriado de filtro de chamadas. O manipulador de idioma específico pode retornar que a exceção foi identificada ou que a pesquisa deve ser continuada. Ele também pode iniciar um desenrolamento diretamente.

1. Se o manipulador específico do idioma retorna um status manipulado, então a execução é continuada usando o registro de contexto original.

1. Se não há nenhum manipulador específico do idioma ou o manipulador retorna um status "continuar a pesquisa", o registro de contexto deve ser organizado para o estado do chamador. Isso é feito através do processamento de todos os elementos de matriz de código de desenrolamento, desfazendo o efeito de cada. Etapa 1, em seguida, é repetida.

Quando encadeado desenrolar informações estiver envolvida, estas etapas básicas ainda são seguidas. A única diferença é que, enquanto percorrer a matriz de código de desenrolamento para desenrolar efeitos do prólogo, após o final da matriz for atingido, que, em seguida, está vinculado às informações de desenrolamento de pai e a matriz de código de desenrolamento todo lá está sendo movimentada. Essa vinculação continua até que chegam a uma informação de desenrolamento sem o sinalizador UNW_CHAINED_INFO e, em seguida, ele termine a movimentação de sua matriz de código de desenrolamento.

O menor conjunto de dados de desenrolamento é de 8 bytes. Isso representaria uma função que só alocada 128 bytes de pilha ou menos e, possivelmente, salvo um registro não volátil. Isso também é o tamanho de um encadeadas desenrolar a estrutura de informações para um prólogo de comprimento zero com nenhum códigos de desenrolamento.

## <a name="language-specific-handler"></a>Manipulador específico do idioma

O endereço relativo do manipulador específico do idioma está presente no UNWIND_INFO sempre que os sinalizadores UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER são definidos. Conforme descrito na seção anterior, o manipulador de idioma específico é chamado como parte da pesquisa para um manipulador de exceção ou como parte de um desenrolamento. Ele tem esse protótipo:

```cpp
typedef EXCEPTION_DISPOSITION (*PEXCEPTION_ROUTINE) (
    IN PEXCEPTION_RECORD ExceptionRecord,
    IN ULONG64 EstablisherFrame,
    IN OUT PCONTEXT ContextRecord,
    IN OUT PDISPATCHER_CONTEXT DispatcherContext
);
```

**ExceptionRecord** fornece um ponteiro para um registro de exceção, que contém a definição padrão do Win64.

**EstablisherFrame** é o endereço da base de alocação fixa de pilha para essa função.

**ContextRecord** aponta para o contexto de exceção na hora em que a exceção foi gerada (no caso do manipulador de exceção) ou atual "desenrolar" contexto (no caso de manipulador de término).

**DispatcherContext** aponta para o contexto de dispatcher para essa função. Ele tem esta definição:

```cpp
typedef struct _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
    ULONG64 EstablisherFrame;
    ULONG64 TargetIp;
    PCONTEXT ContextRecord;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID HandlerData;
} DISPATCHER_CONTEXT, *PDISPATCHER_CONTEXT;
```

**ControlPc** é o valor de RIP dentro dessa função. Esse valor é um endereço de exceção ou o endereço no qual o controle ficaria a função estabelecer. O RIP é usado para determinar se controle está dentro de alguns constructo protegido dentro dessa função, por exemplo, uma `__try` bloquear `__try` / `__except` ou `__try` / `__finally`.

**ImageBase** é a imagem base (endereço de carregamento) do módulo que contém essa função, a serem adicionados aos deslocamentos de 32 bits usados na entrada de função e informações para registrar endereços relativos de desenrolamento.

**FunctionEntry** fornece um ponteiro para o RUNTIME_FUNCTION que contém a função de entrada de função e endereços relativos de imagem base de informações para essa função de desenrolamento.

**EstablisherFrame** é o endereço da base de alocação fixa de pilha para essa função.

**TargetIp** fornece um endereço de instrução opcional que especifica o endereço de continuação do desenrolamento. Esse endereço será ignorado se **EstablisherFrame** não for especificado.

**ContextRecord** aponta para o contexto de exceção, para uso pelo código de expedição/desenrolamento de exceção do sistema.

**LanguageHandler** aponta para a rotina do manipulador de linguagem específica do idioma que está sendo chamada.

**HandlerData** aponta para os dados de manipulador de idioma específico para essa função.

## <a name="unwind-helpers-for-masm"></a>Auxiliares desenrolados para MASM

Para gravar rotinas de assembly apropriadas, há um conjunto de pseudo-operações que podem ser usados em paralelo com as instruções de assembly real para criar o registro. pData apropriado e. XData. Há também um conjunto de macros que fornecem simplificado uso das operações de pseudo para seus usos mais comuns.

### <a name="raw-pseudo-operations"></a>Operações de pseudo brutas

|Operação de pseudo|Descrição|
|-|-|
|PROC FRAME \[:*ehandler*]|Causas MASM para gerar uma função de tabela de entrada no registro. pData e. XData informações de desenrolamento para uma função do estruturado comportamento de desenrolamento de manipulação de exceção.  Se *ehandler* estiver presente, esse procedimento é inserido no. XData como o manipulador de idioma específico.<br /><br /> Quando o atributo de quadro é usado, ele deve ser seguido por um. Diretiva ENDPROLOG.  Se a função é uma função de folha (conforme definido em [tipos de função](../build/stack-usage.md#function-types)) o atributo de quadro é desnecessário, assim como o restante dessas operações pseudo.|
|. PUSHREG *registrar*|Gera uma entrada de código de desenrolamento UWOP_PUSH_NONVOL para o número do registro especificado usando as atuais no prólogo de deslocamento.<br /><br /> Isso só deve ser usado com registros inteiros não volátil.  Para envios por push de registros voláteis, use um. 8 ALLOCSTACK, em vez disso|
|.SETFRAME *register*, *offset*|Preenchimentos no quadro de registrar o campo e o deslocamento nas informações de desenrolamento usando o registro especificado e o deslocamento. O deslocamento deve ser um múltiplo de 16 e menor ou igual a 240. Essa diretiva também gera uma entrada de código de desenrolamento UWOP_SET_FPREG para o registro especificado usando o deslocamento atual do prólogo.|
|.ALLOCSTACK *size*|Gera um UWOP_ALLOC_SMALL ou um UWOP_ALLOC_LARGE com o tamanho especificado para o deslocamento atual no prólogo.<br /><br /> O *tamanho* operando deve ser um múltiplo de 8.|
|.SAVEREG *register*, *offset*|Gera um UWOP_SAVE_NONVOL ou uma entrada de código de desenrolamento UWOP_SAVE_NONVOL_FAR para o registro especificado e o deslocamento usando o deslocamento atual do prólogo. MASM escolhe a codificação mais eficiente.<br /><br /> *deslocamento* deve ser positivo e um múltiplo de 8. *deslocamento* é relativo a base do quadro do procedimento, que é geralmente em RSP, ou, se usando um ponteiro de quadro, o ponteiro de quadro fora de escala.|
|.SAVEXMM128 *register*, *offset*|Gera um UWOP_SAVE_XMM128 ou uma entrada de código de desenrolamento UWOP_SAVE_XMM128_FAR para o registro de registros de MMX especificado e o deslocamento usando o deslocamento atual do prólogo. MASM escolhe a codificação mais eficiente.<br /><br /> *deslocamento* deve ser positivo e um múltiplo de 16.  *deslocamento* é relativo a base do quadro do procedimento, que é geralmente em RSP, ou, se usando um ponteiro de quadro, o ponteiro de quadro fora de escala.|
|. PUSHFRAME \[ *código*]|Gera uma entrada de código de desenrolamento UWOP_PUSH_MACHFRAME. Se o opcional *código* for especificado, a entrada de código de desenrolamento é fornecida um modificador de 1. Caso contrário, o modificador é 0.|
|.ENDPROLOG|Sinaliza o término das declarações do prólogo.  Deve ocorrer nos primeiros 255 bytes da função.|

Aqui está um prólogo da função de exemplo com o uso correto da maioria dos opcodes:

```MASM
sample PROC FRAME
    db      048h; emit a REX prefix, to enable hot-patching
    push rbp
    .pushreg rbp
    sub rsp, 040h
    .allocstack 040h
    lea rbp, [rsp+020h]
    .setframe rbp, 020h
    movdqa [rbp], xmm7
    .savexmm128 xmm7, 020h ;the offset is from the base of the frame
                           ;not the scaled offset of the frame
    mov [rbp+018h], rsi
    .savereg rsi, 038h
    mov [rsp+010h], rdi
    .savereg rdi, 010h ; you can still use RSP as the base of the frame
                       ; or any other register you choose
    .endprolog

; you can modify the stack pointer outside of the prologue (similar to alloca)
; because we have a frame pointer.
; if we didn’t have a frame pointer, this would be illegal
; if we didn’t make this modification,
; there would be no need for a frame pointer

    sub rsp, 060h

; we can unwind from the next AV because of the frame pointer

    mov rax, 0
    mov rax, [rax] ; AV!

; restore the registers that weren’t saved with a push
; this isn’t part of the official epilog, as described in section 2.5

    movdqa xmm7, [rbp]
    mov rsi, [rbp+018h]
    mov rdi, [rbp-010h]

; Here’s the official epilog

    lea rsp, [rbp-020h]
    pop rbp
    ret
sample ENDP
```

### <a name="masm-macros"></a>Macros MASM

Para simplificar o uso do [brutas operações pseudo](#raw-pseudo-operations), há um conjunto de macros, definidas em ksamd64.inc, que pode ser usado para criar o procedimento típico Prólogos e epílogos.

|Macro|Descrição|
|-|-|
|alloc_stack(n)|Aloca um quadro de pilha de n bytes (usando `sub rsp, n`) e emite informações (. allocstack n) de desenrolamento apropriado|
|save_reg *reg*, *loc*|Salva um registro não volátil *reg* na pilha no RSP deslocamento *loc*e emite informações de desenrolamento apropriado. (.savereg reg, loc)|
|push_reg *reg*|Envia por push a um registro não volátil *reg* na pilha e emite informações de desenrolamento apropriado. (reg. pushreg)|
|rex_push_reg *reg*|Salvar um registro não volátil na pilha usando um envio por push de 2 bytes e emite informações (reg. pushreg), isso deve ser usado se o envio por push for a primeira instrução na função para garantir que a função é para patch a quente de desenrolamento apropriado.|
|save_xmm128 *reg*, *loc*|Salva um registro não volátil de XMM *reg* na pilha no RSP deslocamento *loc*e emite informações (reg. savexmm128, loc) de desenrolamento apropriado|
|set_frame *reg*, *offset*|Define o registro de quadro *reg* seja o RSP + *deslocamento* (usando um `mov`, ou um `lea`) e emite informações (reg .set_frame, deslocamento) de desenrolamento apropriado|
|push_eflags|Envia por push o eflags com um `pushfq` instrução e emite informações (.alloc_stack 8) de desenrolamento apropriado|

Aqui está um prólogo da função de exemplo com o uso correto das macros:

```MASM
SkFrame struct
    Fill    dq ?; fill to 8 mod 16
    SavedRdi dq ?; saved register RDI
    SavedRsi dq ?; saved register RSI
SkFrame ends

sampleFrame struct
    Filldq?; fill to 8 mod 16
    SavedRdidq?; Saved Register RDI
    SavedRsi  dq?; Saved Register RSI
sampleFrame ends

sample2 PROC FRAME
    alloc_stack(sizeof sampleFrame)
    save_reg rdi, sampleFrame.SavedRdi
    save_reg rsi, sampleFrame.SavedRsi
    .end_prolog

; function body

    mov rsi, sampleFrame.SavedRsi[rsp]
    mov rdi, sampleFrame.SavedRdi[rsp]

; Here’s the official epilog

    add rsp, (sizeof sampleFrame)
    ret
sample2 ENDP
```

## <a name="unwind-data-definitions-in-c"></a>Desenrolar definições de dados em C

Aqui está uma descrição de C de dados de desenrolamento:

```C
typedef enum _UNWIND_OP_CODES {
    UWOP_PUSH_NONVOL = 0, /* info == register number */
    UWOP_ALLOC_LARGE,     /* no info, alloc size in next 2 slots */
    UWOP_ALLOC_SMALL,     /* info == size of allocation / 8 - 1 */
    UWOP_SET_FPREG,       /* no info, FP = RSP + UNWIND_INFO.FPRegOffset*16 */
    UWOP_SAVE_NONVOL,     /* info == register number, offset in next slot */
    UWOP_SAVE_NONVOL_FAR, /* info == register number, offset in next 2 slots */
    UWOP_SAVE_XMM128 = 8, /* info == XMM reg number, offset in next slot */
    UWOP_SAVE_XMM128_FAR, /* info == XMM reg number, offset in next 2 slots */
    UWOP_PUSH_MACHFRAME   /* info == 0: no error-code, 1: error-code */
} UNWIND_CODE_OPS;

typedef union _UNWIND_CODE {
    struct {
        UBYTE CodeOffset;
        UBYTE UnwindOp : 4;
        UBYTE OpInfo   : 4;
    };
    USHORT FrameOffset;
} UNWIND_CODE, *PUNWIND_CODE;

#define UNW_FLAG_EHANDLER  0x01
#define UNW_FLAG_UHANDLER  0x02
#define UNW_FLAG_CHAININFO 0x04

typedef struct _UNWIND_INFO {
    UBYTE Version       : 3;
    UBYTE Flags         : 5;
    UBYTE SizeOfProlog;
    UBYTE CountOfCodes;
    UBYTE FrameRegister : 4;
    UBYTE FrameOffset   : 4;
    UNWIND_CODE UnwindCode[1];
/*  UNWIND_CODE MoreUnwindCode[((CountOfCodes + 1) & ~1) - 1];
*   union {
*       OPTIONAL ULONG ExceptionHandler;
*       OPTIONAL ULONG FunctionEntry;
*   };
*   OPTIONAL ULONG ExceptionData[]; */
} UNWIND_INFO, *PUNWIND_INFO;

typedef struct _RUNTIME_FUNCTION {
    ULONG BeginAddress;
    ULONG EndAddress;
    ULONG UnwindData;
} RUNTIME_FUNCTION, *PRUNTIME_FUNCTION;

#define GetUnwindCodeEntry(info, index) \
    ((info)->UnwindCode[index])

#define GetLanguageSpecificDataPtr(info) \
    ((PVOID)&GetUnwindCodeEntry((info),((info)->CountOfCodes + 1) & ~1))

#define GetExceptionHandler(base, info) \
    ((PEXCEPTION_HANDLER)((base) + *(PULONG)GetLanguageSpecificDataPtr(info)))

#define GetChainedFunctionEntry(base, info) \
    ((PRUNTIME_FUNCTION)((base) + *(PULONG)GetLanguageSpecificDataPtr(info)))

#define GetExceptionDataPtr(info) \
    ((PVOID)((PULONG)GetLanguageSpecificData(info) + 1)
```

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)
