---
title: Tratamento de exceções x64
ms.date: 10/14/2019
helpviewer_keywords:
- C++ exception handling, x64
- exception handling, x64
ms.assetid: 41fecd2d-3717-4643-b21c-65dcd2f18c93
ms.openlocfilehash: eff4f1a22512b597b5479dbcaabcc9d5fc93c940
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303202"
---
# <a name="x64-exception-handling"></a>Tratamento de exceções x64

Uma visão geral do tratamento de exceção C++ estruturada e da manipulação de exceções e o comportamento da codificação no x64. Para obter informações gerais sobre manipulação de exceção, consulte [tratamento de C++exceção no Visual ](../cpp/exception-handling-in-visual-cpp.md).

## <a name="unwind-data-for-exception-handling-debugger-support"></a>Desenrolar dados para tratamento de exceções, suporte a depurador

Várias estruturas de dados são necessárias para tratamento de exceções e suporte à depuração.

### <a name="struct-runtime_function"></a>struct RUNTIME_FUNCTION

A manipulação de exceção baseada em tabela requer uma entrada de tabela para todas as funções que alocam espaço de pilha ou que chamam outra função (por exemplo, funções não-folha). As entradas da tabela de funções têm o formato:

|||
|-|-|
|ULONG|Endereço de início da função|
|ULONG|Endereço final da função|
|ULONG|Endereço de informações de desenrolamento|

A estrutura de RUNTIME_FUNCTION deve ser alinhada em DWORD na memória. Todos os endereços são relativos à imagem, ou seja, são deslocamentos de 32 bits do endereço inicial da imagem que contém a entrada da tabela de funções. Essas entradas são classificadas e colocadas na seção. pData de uma imagem do PE32 +. Para funções geradas dinamicamente [compiladores JIT], o tempo de execução para dar suporte a essas funções deve usar RtlInstallFunctionTableCallback ou RtlAddFunctionTable para fornecer essas informações ao sistema operacional. Se não fizer isso, isso resultará em manipulação de exceção não confiável e depuração de processos.

### <a name="struct-unwind_info"></a>struct UNWIND_INFO

A estrutura de informações de dados de desenrolar é usada para registrar os efeitos que uma função tem no ponteiro de pilha e onde os registros não voláteis são salvos na pilha:

|||
|-|-|
|UBYTE: 3|Version|
|UBYTE: 5|Sinalizadores|
|UBYTE|Tamanho do prólogo|
|UBYTE|Contagem de códigos de liberação|
|UBYTE: 4|Registro de quadro|
|UBYTE: 4|Deslocamento de registro de quadro (dimensionado)|
|USHORT \* n|Matriz de códigos de liberação|
|variável|Pode ser do formato (1) ou (2) abaixo|

(1) manipulador de exceção

|||
|-|-|
|ULONG|Endereço do manipulador de exceção|
|variável|Dados de manipulador específicos do idioma (opcional)|

(2) informações de desenrolamento encadeadas

|||
|-|-|
|ULONG|Endereço de início da função|
|ULONG|Endereço final da função|
|ULONG|Endereço de informações de desenrolamento|

A estrutura de UNWIND_INFO deve ser alinhada em DWORD na memória. Veja o que cada campo significa:

- **Versão**

   Número de versão dos dados de desenrolamento, atualmente 1.

- **Sinalizadores**

   Três sinalizadores estão definidos no momento:

   |Sinalizador|Descrição|
   |-|-|
   |`UNW_FLAG_EHANDLER`| A função tem um manipulador de exceção que deve ser chamado ao procurar funções que precisam examinar exceções.|
   |`UNW_FLAG_UHANDLER`| A função tem um manipulador de terminação que deve ser chamado ao desenrolar uma exceção.|
   |`UNW_FLAG_CHAININFO`| Esta estrutura de informações de desenrolamento não é a principal para o procedimento. Em vez disso, a entrada de informações de desenrolamento encadeada é o conteúdo de uma entrada de RUNTIME_FUNCTION anterior. Para obter informações, consulte [estruturas de informações de desenrolamento encadeadas](#chained-unwind-info-structures). Se esse sinalizador for definido, os sinalizadores de UNW_FLAG_EHANDLER e de UNW_FLAG_UHANDLER devem ser desmarcados. Além disso, os campos registro de quadro e alocação de pilha fixa devem ter os mesmos valores das informações de desenrolação primária.|

- **Tamanho do prólogo**

   Comprimento do prólogo da função em bytes.

- **Contagem de códigos de liberação**

   O número de slots na matriz de códigos de desenrolamento. Alguns códigos de liberação, por exemplo, UWOP_SAVE_NONVOL, exigem mais de um slot na matriz.

- **Registro de quadro**

   Se for diferente de zero, a função usará um ponteiro de quadro (FP) e esse campo será o número do registro não volátil usado como ponteiro de quadro, usando a mesma codificação para o campo de informações de operação de nós de UNWIND_CODE.

- **Deslocamento de registro de quadro (dimensionado)**

   Se o campo de registro de quadro for diferente de zero, esse campo será o deslocamento dimensionado do RSP que é aplicado ao registro de FP quando ele é estabelecido. O registro de FP real é definido como RSP + 16 \* esse número, permitindo deslocamentos de 0 a 240. Esse deslocamento permite apontar o registro de FP para o meio da alocação de pilha local para quadros de pilha dinâmico, permitindo uma melhor densidade de código por meio de instruções mais curtas. (Ou seja, mais instruções podem usar o formato de deslocamento de 8 bits assinado.)

- **Matriz de códigos de liberação**

   Uma matriz de itens que explica o efeito do prólogo nos registros não voláteis e no RSP. Consulte a seção sobre UNWIND_CODE para obter os significados de itens individuais. Para fins de alinhamento, essa matriz sempre tem um número par de entradas e a entrada final é potencialmente não utilizada. Nesse caso, a matriz é uma vez mais longa do que o indicado pelo campo contagem de códigos de liberação.

- **Endereço do manipulador de exceção**

   Um ponteiro relativo à imagem para o manipulador de exceção ou término específico do idioma da função, se o sinalizador UNW_FLAG_CHAININFO estiver claro e um dos sinalizadores UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER estiver definido.

- **Dados de manipulador específicos do idioma**

   Os dados de manipulador de exceção específicos do idioma da função. O formato desses dados não é especificado e completamente determinado pelo manipulador de exceção específico em uso.

- **Informações de desenrolamento encadeadas**

   Se o sinalizador UNW_FLAG_CHAININFO for definido, a estrutura de UNWIND_INFO terminará com três UWORDs.  Esses UWORDs representam as informações de RUNTIME_FUNCTION para a função do desenrolamento encadeado.

### <a name="struct-unwind_code"></a>struct UNWIND_CODE

A matriz de código de desenrolamento é usada para registrar a sequência de operações no prólogo que afetam os registros não voláteis e RSP. Cada item de código tem este formato:

|||
|-|-|
|UBYTE|Deslocamento no prólogo|
|UBYTE: 4|Desenrolar código de operação|
|UBYTE: 4|Informações da operação|

A matriz é classificada por ordem decrescente de deslocamento no prólogo.

#### <a name="offset-in-prolog"></a>Deslocamento no prólogo

Offset (do início do prólogo) do final da instrução que executa essa operação, mais 1 (ou seja, o deslocamento do início da próxima instrução).

#### <a name="unwind-operation-code"></a>Desenrolar código de operação

Observação: determinados códigos de operação exigem um deslocamento não assinado para um valor no quadro de pilha local. Esse deslocamento é desde o início, ou seja, o endereço mais baixo da alocação de pilha fixa. Se o campo de registro de quadro na UNWIND_INFO for zero, esse deslocamento será de RSP. Se o campo de registro de quadro for diferente de zero, esse deslocamento será de onde o RSP estava localizado quando o registro de FP foi estabelecido. Ele é igual ao registro de FP menos o deslocamento de registro de FP (16 \* o deslocamento de registro de quadro dimensionado na UNWIND_INFO). Se um registro de FP for usado, qualquer código de desenrolar que faça um deslocamento só deverá ser usado depois que o registro de FP for estabelecido no prólogo.

Para todos os opcodes, exceto `UWOP_SAVE_XMM128` e `UWOP_SAVE_XMM128_FAR`, o deslocamento é sempre um múltiplo de 8, porque todos os valores de pilha de interesse são armazenados em limites de 8 bytes (a pilha em si é sempre alinhada em 16 bytes). Para os códigos de operação que usam um deslocamento curto (menos de 512K), o USHORT final nos nós para esse código contém o deslocamento dividido por 8. Para os códigos de operação que usam um deslocamento longo (512K < = offset < 4GB), os dois nós de USHORT finais desse código contêm o deslocamento (no formato little-endian).

Para os opcodes `UWOP_SAVE_XMM128` e `UWOP_SAVE_XMM128_FAR`, o deslocamento é sempre um múltiplo de 16, pois todas as operações de XMM de 128 bits devem ocorrer na memória alinhada de 16 bytes. Portanto, um fator de escala de 16 é usado para `UWOP_SAVE_XMM128`, permitindo deslocamentos de menos de 1M.

O código de operação de desenrolamento é um destes valores:

- `UWOP_PUSH_NONVOL` (0) 1 nó

  Envie um registro inteiro não volátil, decrementando RSP por 8. As informações da operação são o número do registro. Devido às restrições em epilogs, `UWOP_PUSH_NONVOL` códigos de liberação devem aparecer primeiro no prólogo e, por fim, por último na matriz de código de desenrolamento. Essa ordenação relativa se aplica a todos os outros códigos de desenrolação, exceto `UWOP_PUSH_MACHFRAME`.

- `UWOP_ALLOC_LARGE` (1) 2 ou 3 nós

  Aloque uma área de tamanho grande na pilha. Há dois formulários. Se as informações da operação forem iguais a 0, o tamanho da alocação dividida por 8 será registrado no próximo slot, permitindo uma alocação de até 512K-8. Se as informações da operação forem iguais a 1, o tamanho não dimensionado da alocação será registrado nos próximos dois slots no formato little-endian, permitindo alocações de até 4 GB-8.

- `UWOP_ALLOC_SMALL` (2) 1 nó

  Aloque uma área de tamanho pequeno na pilha. O tamanho da alocação é o campo de informações da operação \* 8 + 8, permitindo alocações de 8 a 128 bytes.

  O código de desenrolamento para uma alocação de pilha sempre deve usar a menor codificação possível:

  |**Tamanho da alocação**|**Código de desenrolamento**|
  |-|-|
  |8 a 128 bytes|`UWOP_ALLOC_SMALL`|
  |136 a 512K-8 bytes|`UWOP_ALLOC_LARGE`, informações da operação = 0|
  |512K a 4G-8 bytes|`UWOP_ALLOC_LARGE`, informações da operação = 1|

- `UWOP_SET_FPREG` (3) 1 nó

  Estabeleça o registro do ponteiro do quadro definindo o registro para algum deslocamento do RSP atual. O deslocamento é igual ao campo deslocamento de registro de quadro (dimensionado) no UNWIND_INFO \* 16, permitindo deslocamentos de 0 a 240. O uso de um deslocamento permite o estabelecimento de um ponteiro de quadro que aponta para o meio da alocação de pilha fixa, ajudando a densidade de código, permitindo que mais acessos usem formulários de instruções curtas. O campo informações da operação é reservado e não deve ser usado.

- `UWOP_SAVE_NONVOL` (4) 2 nós

  Salve um registro inteiro não volátil na pilha usando uma MOV em vez de um PUSH. Esse código é usado principalmente para *reduzir a disposição*, onde um registro não volátil é salvo na pilha em uma posição que foi alocada anteriormente. As informações da operação são o número do registro. O deslocamento de pilha dimensionado por 8 é registrado no próximo slot de código de operação desenrolar, conforme descrito na observação acima.

- `UWOP_SAVE_NONVOL_FAR` (5) 3 nós

  Salve um registro inteiro não volátil na pilha com um deslocamento longo, usando um MOV em vez de um PUSH. Esse código é usado principalmente para *reduzir a disposição*, onde um registro não volátil é salvo na pilha em uma posição que foi alocada anteriormente. As informações da operação são o número do registro. O deslocamento de pilha não dimensionado é registrado nos próximos dois slots de código de operação desenrolar, conforme descrito na observação acima.

- `UWOP_SAVE_XMM128` (8) 2 nós

  Salve todos os 128 bits de um registro XMM não volátil na pilha. As informações da operação são o número do registro. O deslocamento de pilha dimensionado por 16 é registrado no próximo slot.

- `UWOP_SAVE_XMM128_FAR` (9) 3 nós

  Salve todos os 128 bits de um registro XMM não volátil na pilha com um deslocamento longo. As informações da operação são o número do registro. O deslocamento de pilha não dimensionado é registrado nos dois slots seguintes.

- `UWOP_PUSH_MACHFRAME` (10) 1 nó

  Enviar por push um quadro de máquina.  Esse código de desenrolação é usado para registrar o efeito de uma interrupção ou de uma exceção de hardware. Há dois formulários. Se as informações da operação forem iguais a 0, um desses quadros será enviado por push na pilha:

  |||
  |-|-|
  |RSP+32|SS|
  |RSP + 24|RSP antigo|
  |RSP+16|EFLAGS|
  |RSP+8|CS|
  |RSP|MÚSICA|

  Se as informações da operação forem iguais a 1, um desses quadros será enviado por push:

  |||
  |-|-|
  |RSP+40|SS|
  |RSP+32|RSP antigo|
  |RSP + 24|EFLAGS|
  |RSP+16|CS|
  |RSP+8|MÚSICA|
  |RSP|Código de erro|

  Esse código de desenrolação sempre aparece em um prólogo fictício, que nunca é executado de fato, mas é exibido antes do ponto de entrada real de uma rotina de interrupção e existe apenas para fornecer um local para simular o envio por push de um quadro de máquina. `UWOP_PUSH_MACHFRAME` registra essa simulação, que indica que a máquina fez essa operação conceitualmente:

  1. Endereço de retorno de RIP pop de cima da pilha para *Temp*
  
  1. Push SS

  1. Enviar RSP antigo

  1. Enviar por push EFLAGS

  1. Enviar por push CS

  1. Enviar por push *temporário*

  1. Código de erro de push (se as informações op forem iguais a 1)

  A operação simulada `UWOP_PUSH_MACHFRAME` Decrementa o RSP por 40 (as informações de op são iguais a 0) ou 48 (as informações de op são iguais a 1).

#### <a name="operation-info"></a>Informações da operação

O significado dos bits de informações da operação depende do código da operação. Para codificar um registro de finalidade geral (inteiro), esse mapeamento é usado:

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

### <a name="chained-unwind-info-structures"></a>Estruturas de informações de desenrolamento encadeadas

Se o sinalizador de UNW_FLAG_CHAININFO for definido, uma estrutura de informações de desenrolação será secundária, e o campo de endereço de manipulador de exceção compartilhado/encadeadod-info conterá as informações de desenrolação primária. Esse código de exemplo recupera as informações primárias de desenrolamento, supondo que `unwindInfo` é a estrutura que tem o sinalizador de UNW_FLAG_CHAININFO definido.

```cpp
PRUNTIME_FUNCTION primaryUwindInfo = (PRUNTIME_FUNCTION)&(unwindInfo->UnwindCode[( unwindInfo->CountOfCodes + 1 ) & ~1]);
```

As informações encadeadas são úteis em duas situações. Primeiro, ele pode ser usado para segmentos de código não contíguos. Usando informações encadeadas, você pode reduzir o tamanho das informações de desenrolamento necessárias, porque não é necessário duplicar a matriz de códigos de desenrolação das informações de desenrolação primárias.

Você também pode usar informações encadeadas para agrupar os salvamentos de registro volátil. O compilador pode atrasar o salvamento de alguns registros voláteis até que esteja fora do prólogo da entrada de função. Você pode gravá-los tendo informações primárias de desenrolamento para a parte da função antes do código agrupado e, em seguida, configurando informações encadeadas com um tamanho diferente de zero de prólogo, em que os códigos de liberação nas informações encadeadas refletem as gravações dos registros não voláteis. Nesse caso, os códigos de liberação são todas as instâncias de UWOP_SAVE_NONVOL. Um agrupamento que salva registros não voláteis usando um PUSH ou modifica o registro de RSP usando uma alocação de pilha fixa adicional não tem suporte.

Um item de UNWIND_INFO que tem UNW_FLAG_CHAININFO definido pode conter uma entrada de RUNTIME_FUNCTION cujo item de UNWIND_INFO também tem UNW_FLAG_CHAININFO definido, às vezes chamado de *vários enrolamentos de redução*. Eventualmente, os ponteiros de informações de desenrolamento encadeados chegam a um UNWIND_INFO item que tem UNW_FLAG_CHAININFO limpo. Este é o item de UNWIND_INFO primário, que aponta para o ponto de entrada do procedimento real.

## <a name="unwind-procedure"></a>Procedimento de desenrolamento

A matriz de código de desenrolação é classificada em ordem decrescente. Quando ocorre uma exceção, o contexto completo é armazenado pelo sistema operacional em um registro de contexto. A lógica de expedição de exceção é invocada, que executa repetidamente essas etapas para encontrar um manipulador de exceção:

1. Use o RIP atual armazenado no registro de contexto para pesquisar uma RUNTIME_FUNCTION entrada de tabela que descreve a função atual (ou parte da função, para entradas de UNWIND_INFO encadeadas).

1. Se nenhuma entrada de tabela de função for encontrada, ela estará em uma função folha e RSP endereçará diretamente o ponteiro de retorno. O ponteiro de retorno em [RSP] é armazenado no contexto atualizado, o RSP simulado é incrementado por 8 e a etapa 1 é repetida.

1. Se uma entrada de tabela de função for encontrada, o RIP poderá ficar dentro de três regiões: a) em um epílogo, b) no prólogo ou c) no código que pode ser coberto por um manipulador de exceção.

   - Case a) se o RIP estiver dentro de um epílogo, então o controle está deixando a função, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função, e os efeitos de epílogo devem ser continuados para computar o contexto da função do chamador. Para determinar se o RIP está dentro de um epílogo, o fluxo de código do RIP em diante é examinado. Se esse fluxo de código puder corresponder à parte à direita de um epílogo legítimo, ele estará em um epílogo, e a parte restante do epílogo será simulada, com o registro de contexto atualizado conforme cada instrução é processada. Após esse processamento, a etapa 1 é repetida.

   - Caso b) se o RIP estiver dentro do prólogo, o controle não inseriu a função, não pode haver nenhum manipulador de exceção associado a essa exceção para essa função, e os efeitos do prólogo devem ser desfeitos para computar o contexto da função do chamador. O RIP estará dentro do prólogo se a distância da função iniciar para o RIP for menor ou igual ao tamanho de prólogo codificado nas informações de desenrolamento. Os efeitos do prólogo são rebobinados por meio da digitalização por meio da matriz de códigos de liberação para a primeira entrada com um deslocamento menor ou igual ao deslocamento do RIP do início da função e, em seguida, desfazendo o efeito de todos os itens restantes na matriz de código de desenrolamento. A etapa 1 é repetida.

   - Caso c) se o RIP não estiver em um prólogo ou epílogo, e a função tiver um manipulador de exceção (UNW_FLAG_EHANDLER estiver definido), o manipulador específico do idioma será chamado. O manipulador examina seus dados e chama as funções de filtro conforme apropriado. O manipulador específico de linguagem pode retornar que a exceção foi tratada ou que a pesquisa deve ser continuada. Ele também pode iniciar um desenrolamento diretamente.

1. Se o manipulador específico de idioma retornar um status manipulado, a execução continuará usando o registro de contexto original.

1. Se não houver um manipulador específico de idioma ou o manipulador retornar um status "continuar pesquisando", o registro de contexto deverá ser rebobinado para o estado do chamador. Isso é feito pelo processamento de todos os elementos da matriz de código de desenrolamento, desfazendo o efeito de cada um. A etapa 1 é repetida.

Quando informações de desenrolamento encadeados estiverem envolvidas, essas etapas básicas ainda serão seguidas. A única diferença é que, ao movimentar a matriz de código de liberação para desenrolar os efeitos de um prólogo, quando o final da matriz for atingido, ele será vinculado às informações de desenrolamento pai e toda a matriz de código de desenrolação encontrada. Essa vinculação continua até chegar a uma informação desenrolada sem o sinalizador UNW_CHAINED_INFO e, em seguida, termina de percorrer sua matriz de códigos de desenrolamento.

O menor conjunto de dados de desenrolamento é de 8 bytes. Isso representaria uma função que alocou apenas 128 bytes de pilha ou menos, e possivelmente salvou um registro não volátil. Também é o tamanho de uma estrutura de informações de desenrolamento encadeada para um prólogo de comprimento zero sem códigos de desenrolamento.

## <a name="language-specific-handler"></a>Manipulador específico a um idioma

O endereço relativo do manipulador específico do idioma está presente no UNWIND_INFO sempre que os sinalizadores UNW_FLAG_EHANDLER ou UNW_FLAG_UHANDLER estão definidos. Conforme descrito na seção anterior, o manipulador específico do idioma é chamado como parte da pesquisa de um manipulador de exceção ou como parte de um desenrolamento. Ele tem este protótipo:

```cpp
typedef EXCEPTION_DISPOSITION (*PEXCEPTION_ROUTINE) (
    IN PEXCEPTION_RECORD ExceptionRecord,
    IN ULONG64 EstablisherFrame,
    IN OUT PCONTEXT ContextRecord,
    IN OUT PDISPATCHER_CONTEXT DispatcherContext
);
```

**ExceptionRecord** fornece um ponteiro para um registro de exceção, que tem a definição de Win64 padrão.

**EstablisherFrame** é o endereço da base da alocação de pilha fixa para essa função.

**ContextRecord** aponta para o contexto de exceção no momento em que a exceção foi gerada (no caso do manipulador de exceção) ou no contexto "desenrolar" atual (no caso do manipulador de terminação).

**DispatcherContext** aponta para o contexto do Dispatcher para essa função. Ele tem essa definição:

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

**ControlPc** é o valor de RIP dentro dessa função. Esse valor é um endereço de exceção ou o endereço no qual o controle deixou a função de estabelecimento. O RIP é usado para determinar se o controle está dentro de uma construção protegida dentro dessa função, por exemplo, um bloco de `__try` para `__try`/`__except` ou `__try`/de `__finally`.

**ImageBase** é a base da imagem (endereço de carregamento) do módulo que contém essa função, a ser adicionada aos deslocamentos de 32 bits usados na entrada da função e informações de desenrolamento para registrar endereços relativos.

**FunctionEntry** fornece um ponteiro para a entrada da função RUNTIME_FUNCTION que contém a função e desenrolar os endereços relativos à base de dados de informações para essa função.

**EstablisherFrame** é o endereço da base da alocação de pilha fixa para essa função.

**TargetIp** Fornece um endereço de instrução opcional que especifica o endereço de continuação do desenrolamento. Esse endereço será ignorado se **EstablisherFrame** não for especificado.

**ContextRecord** aponta para o contexto de exceção, para uso pelo código de expedição/desenrolação de exceção do sistema.

**LanguageHandler** aponta para a rotina do manipulador de linguagem específica a um idioma que está sendo chamada.

**HandlerData** aponta para os dados de manipulador específicos do idioma para essa função.

## <a name="unwind-helpers-for-masm"></a>Desenrolar auxiliares para MASM

Para escrever rotinas de assembly adequadas, há um conjunto de pseudovariáveis que podem ser usadas em paralelo com as instruções de assembly reais para criar o. pData e. xdata apropriado. Além disso, há um conjunto de macros que fornecem uso simplificado das pseudovariáveis para seus usos mais comuns.

### <a name="raw-pseudo-operations"></a>Pseudo operações brutas

|Pseudo operação|Descrição|
|-|-|
|\[do quadro PROC:*ehandler*]|Faz com que o MASM gere uma entrada de tabela de função em. pData e desenrola informações em. xdata para o comportamento de desenrolamento de manipulação de exceção estruturada de uma função.  Se *ehandler* estiver presente, esse proc será inserido em. xdata como o manipulador específico de idioma.<br /><br /> Quando o atributo de quadro é usado, ele deve ser seguido por um. Diretiva endprólogo.  Se a função for uma função folha (conforme definido em [tipos de função](../build/stack-usage.md#function-types)), o atributo de quadro será desnecessário, assim como o restante dessas pseudovariáveis.|
|. *Registro* de pushreg|Gera uma entrada de código de desenrolação UWOP_PUSH_NONVOL para o número de registro especificado usando o deslocamento atual no prólogo.<br /><br /> Use-o somente com registros inteiros não voláteis.  Para envios por push de registros voláteis, use um. ALLOCSTACK 8, em vez disso|
|. *Registro*do SETFRAME, *deslocamento*|Preenche o campo de registro de quadro e o deslocamento nas informações de desenrolamento usando o registro e o deslocamento especificados. O deslocamento deve ser um múltiplo de 16 e menor ou igual a 240. Essa diretiva também gera uma entrada de código de desenrolação UWOP_SET_FPREG para o registro especificado usando o deslocamento de prólogo atual.|
|. *Tamanho* do ALLOCSTACK|Gera um UWOP_ALLOC_SMALL ou um UWOP_ALLOC_LARGE com o tamanho especificado para o deslocamento atual no prólogo.<br /><br /> O operando de *tamanho* deve ser um múltiplo de 8.|
|.SAVEREG *register*, *offset*|Gera um UWOP_SAVE_NONVOL ou uma UWOP_SAVE_NONVOL_FAR entrada de código de desenrolamento para o registro e o deslocamento especificados usando o deslocamento de prólogo atual. MASM escolhe a codificação mais eficiente.<br /><br /> o *deslocamento* deve ser positivo e um múltiplo de 8. o *deslocamento* é relativo à base do quadro do procedimento, que geralmente está em RSP ou, se estiver usando um ponteiro de quadro, o ponteiro de quadro não dimensionado.|
|. SAVEXMM128 *registro*, *deslocamento*|Gera um UWOP_SAVE_XMM128 ou uma UWOP_SAVE_XMM128_FAR entrada de código de desenrolamento para o registro XMM especificado e o deslocamento usando o deslocamento de prólogo atual. MASM escolhe a codificação mais eficiente.<br /><br /> o *deslocamento* deve ser positivo e um múltiplo de 16.  o *deslocamento* é relativo à base do quadro do procedimento, que geralmente está em RSP ou, se estiver usando um ponteiro de quadro, o ponteiro de quadro não dimensionado.|
|. PUSHFRAME \[*código*]|Gera uma entrada de código de desenrolação UWOP_PUSH_MACHFRAME. Se o *código* opcional for especificado, a entrada de código de liberação receberá um modificador de 1. Caso contrário, o modificador será 0.|
|.ENDPROLOG|Sinaliza o fim das declarações de prólogo.  Deve ocorrer nos primeiros 255 bytes da função.|

Aqui está um prólogo de função de exemplo com uso adequado da maioria dos opcodes:

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
; if we didn't have a frame pointer, this would be illegal
; if we didn't make this modification,
; there would be no need for a frame pointer

    sub rsp, 060h

; we can unwind from the next AV because of the frame pointer

    mov rax, 0
    mov rax, [rax] ; AV!

; restore the registers that weren't saved with a push
; this isn't part of the official epilog, as described in section 2.5

    movdqa xmm7, [rbp]
    mov rsi, [rbp+018h]
    mov rdi, [rbp-010h]

; Here's the official epilog

    lea rsp, [rbp+020h] ; deallocate both fixed and dynamic portions of the frame
    pop rbp
    ret
sample ENDP
```

Para obter mais informações sobre o exemplo de epílogo, consulte [código epílogo](prolog-and-epilog.md#epilog-code) em [prólogo x64 e epílogo](prolog-and-epilog.md).

### <a name="masm-macros"></a>MASM macros

Para simplificar o uso das [pseudo operações brutas](#raw-pseudo-operations), há um conjunto de macros, definido em ksamd64. Inc, que pode ser usado para criar prólogos de procedimento típicos e epilogues.

|Macro|Descrição|
|-|-|
|alloc_stack(n)|Aloca um quadro de pilha de n bytes (usando `sub rsp, n`) e emite as informações de desenrolação apropriadas (. allocstack n)|
|save_reg *reg*, *loc*|Salva um *reg* de registro não volátil na pilha em RSP offset *Loc*e emite as informações de desenrolação apropriadas. (. savereg reg, loc)|
|push_reg *reg*|Envia por push um *reg* de registro não volátil na pilha e emite as informações de desenrolação apropriadas. (. pushreg reg)|
|rex_push_reg *reg*|Salva um registro não volátil na pilha usando um envio por push de 2 bytes e emite as informações de desenrolação apropriadas (. pushreg reg).  Use esta macro se o push for a primeira instrução na função, para garantir que a função seja de patches de acesso.|
|save_xmm128 *reg*, *loc*|Salva um *reg* de registro XMM não volátil na pilha em RSP offset *Loc*e emite as informações de desenrolação apropriadas (. savexmm128 reg, loc)|
|set_frame *reg*, *offset*|Define o registro de quadro *reg* como o RSP + *offset* (usando um `mov`ou um `lea`) e emite as informações de desenrolação apropriadas (. set_frame reg, offset)|
|push_eflags|Envia o EFLAGS com uma instrução `pushfq` e emite as informações de desenrolação apropriadas (. alloc_stack 8)|

Aqui está um prólogo de função de exemplo com o uso adequado das macros:

```MASM
sampleFrame struct
    Fill     dq ?; fill to 8 mod 16
    SavedRdi dq ?; Saved Register RDI
    SavedRsi dq ?; Saved Register RSI
sampleFrame ends

sample2 PROC FRAME
    alloc_stack(sizeof sampleFrame)
    save_reg rdi, sampleFrame.SavedRdi
    save_reg rsi, sampleFrame.SavedRsi
    .end_prolog

; function body

    mov rsi, sampleFrame.SavedRsi[rsp]
    mov rdi, sampleFrame.SavedRdi[rsp]

; Here's the official epilog

    add rsp, (sizeof sampleFrame)
    ret
sample2 ENDP
```

## <a name="unwind-data-definitions-in-c"></a>Desenrolar definições de dados em C

Aqui está uma descrição de C dos dados de desenrolamento:

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
