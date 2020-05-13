---
title: Visão geral das convenções ARM64 ABI
ms.date: 03/27/2019
ms.openlocfilehash: 07d58bbd64795235ad63a7b26b6f18fcffdcd1d2
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74303260"
---
# <a name="overview-of-arm64-abi-conventions"></a>Visão geral das convenções ARM64 ABI

A interface binária básica do aplicativo (ABI) para Windows quando compilada e executada em processadores ARM no modo de 64 bits (arquiteturas ARMv8 ou posteriores), na maioria das vezes, segue a AArch64 EABI padrão do ARM. Este artigo destaca algumas das principais suposições e alterações do que está documentado no EABI. Para obter informações sobre a ABI de 32 bits, consulte [visão geral das convenções do ARM Abi](overview-of-arm-abi-conventions.md). Para obter mais informações sobre o EABI ARM padrão, consulte [Abi (interface binária de aplicativo) para a arquitetura ARM](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.subset.swdev.abi/index.html) (link externo).

## <a name="definitions"></a>Definições

Com a introdução do suporte de 64 bits, o ARM definiu vários termos:

- **AArch32** – a arquitetura de conjunto de instruções (ISA) de 32 bits herdada definida pelo ARM, incluindo a execução do modo Thumb.
- **AArch64** – a nova arquitetura de conjunto de instruções (ISA) de 64 bits definida pelo ARM.
- **ARMv7** – a especificação do hardware ARM de "7ª geração", que inclui apenas o suporte para AArch32. Esta versão do hardware ARM é a primeira versão do Windows para ARM com suporte.
- **ARMv8** – a especificação do hardware ARM "de 8 gerações", que inclui suporte para AArch32 e AArch64.

O Windows também usa estes termos:

- **ARM** – refere-se à AArch32 (arquitetura ARM de 32 bits), às vezes conhecida como WoA (Windows no ARM).
- **ARM32** – igual ao ARM, acima; usado neste documento para fins de clareza.
- **ARM64** – refere-se à arquitetura ARM de 64 bits (AArch64). Não há nada como WoA64.

Por fim, ao fazer referência a tipos de dados, as seguintes definições do ARM são referenciadas:

- **Curto-vector** – um tipo de dados que é imediatamente representável em SIMD, um vetor de 8 bytes ou 16 bytes de elementos. Ele está alinhado ao seu tamanho, de 8 bytes ou 16 bytes, em que cada elemento pode ser 1, 2, 4 ou 8 bytes.
- **HFA (agregação de ponto flutuante homogêneo)** – um tipo de dados com 2 a 4 membros de ponto flutuante idênticos, flutuantes ou duplos.
- **HVA (agregação de vetor curto homogêneo)** – um tipo de dados com 2 a 4 membros de vetores pequenos idênticos.

## <a name="base-requirements"></a>Requisitos base

A versão ARM64 do Windows pressupõe que ele seja executado em uma arquitetura ARMv8 ou posterior em todos os momentos. O suporte a ponto flutuante e NEON é presumido estar presente no hardware.

A especificação ARMv8 descreve os novos opcodes auxiliares de CRC e criptografia opcional para AArch32 e AArch64. O suporte para eles é opcional no momento, mas recomendado. Para aproveitar esses opcodes, os aplicativos devem primeiro fazer verificações de tempo de execução para sua existência.

## <a name="endianness"></a>Endianness

Assim como acontece com a versão ARM32 do Windows, no ARM64 Windows é executado no modo little-endian. É difícil realizar a alternância de endian sem o suporte do modo kernel no AArch64, portanto, é mais fácil de se impor.

## <a name="alignment"></a>Alinhamento

O Windows em execução no ARM64 permite que o hardware de CPU manipule os acessos desalinhados de forma transparente. Em uma melhoria do AArch32, esse suporte agora também funciona para todos os acessos inteiros (incluindo acessos de várias palavras) e para acessos de ponto flutuante.

No entanto, os acessos à memória não armazenada em cache (dispositivo) ainda devem ser sempre alinhados. Se o código puder possivelmente ler ou gravar dados desalinhados de memória não armazenada em cache, ele deverá se certificar de alinhar todos os acessos.

Alinhamento de layout padrão para locais:

| Tamanho em Bytes | Alinhamento em bytes |
| - | - |
| 1 | 1 |
| 2 | 2 |
| 3, 4 | 4 |
| > 4 | 8 |

Alinhamento de layout padrão para globais e estáticos:

| Tamanho em Bytes | Alinhamento em bytes |
| - | - |
| 1 | 1 |
| 2 - 7 | 4 |
| 8 - 63 | 8 |
| >= 64 | 16 |

## <a name="integer-registers"></a>Registros de inteiro

A arquitetura AArch64 dá suporte a registros de inteiro 32:

| Registrar  | Volátil? | Função |
| - | - | - |
| x0 | Volátil | Parâmetro/Registro transitório 1, registro de resultados |
| X1-120 | Volátil | Parâmetro/Registro transitório 2-8 |
| x8-X15 | Volátil | Registros de rascunho |
| X16-X17 | Volátil | Intra-Procedure-chamar os registros de rascunho |
| x18 | Não volátil | Registro de plataforma: no modo kernel, aponta para KPCR para o processador atual; no modo de usuário, aponta para TEB |
| x19-x28 | Não volátil | Registros de rascunho |
| x29/FP | Não volátil | Ponteiro de quadro |
| X30/LR | Não volátil | Registros de link |

Cada registro pode ser acessado como um valor de 64 bits completo (via x0-X30) ou como um valor de 32 bits (via W0-W30). operações de 32 bits zero-Estenda seus resultados até 64 bits.

Consulte a seção passagem de parâmetro para obter detalhes sobre o uso dos registros de parâmetro.

Ao contrário de AArch32, o contador de programa (PC) e o ponteiro de pilha (SP) não são registros indexados. Eles são limitados em como eles podem ser acessados. Observe também que não há nenhum registro de X31. Essa codificação é usada para fins especiais.

O ponteiro de quadro (x29) é necessário para compatibilidade com movimentação de pilha rápida usada pelo ETW e outros serviços. Ele deve apontar para o par {x29, X30} anterior na pilha.

## <a name="floating-pointsimd-registers"></a>Registros de ponto flutuante/SIMD

A arquitetura AArch64 também dá suporte a 32 registros de ponto flutuante/SIMD, resumidos abaixo:

| Registrar  | Volátil? | Função |
| - | - | - |
| V0 | Volátil | Parâmetro/Registro transitório 1, registro de resultados |
| v1-v7 | Volátil | O parâmetro/os registros de rascunho 2-8 |
| V8-v15 | Não volátil | Registros de rascunho (somente os bits de 64 baixos são não-voláteis) |
| v16-v31 | Volátil | Registros de rascunho |

Cada registro pode ser acessado como um valor de 128 bits completo (via V0-V31 ou q0-q31). Ele pode ser acessado como um valor de 64 bits (via D0-D31), como um valor de 32 bits (via S0-S31), como um valor de 16 bits (via H0-H31) ou como um valor de 8 bits (via B0-B31). Acessos menores que 128 bits acessam apenas os bits inferiores do registro completo de bit 128. Eles deixam os bits restantes intocados, a menos que especificado de outra forma. (AArch64 é diferente de AArch32, em que os registradores menores foram empacotados sobre os registros maiores.)

O FPCR (registro de controle de ponto flutuante) tem determinados requisitos em vários bitfields dentro dele:

| Bits | Significado | Volátil? | Função |
| - | - | - | - |
| 26 | AHP | Não volátil | Controle de metade de precisão alternativo. |
| 25 | DN | Não volátil | Controle de modo NaN padrão. |
| 24 | FZ | Não volátil | Controle de modo flush-to-zero. |
| 23-22 | RMode | Não volátil | Controle de modo de arredondamento. |
| 15, 12-8 | IDE/IXE/etc. | Não volátil | A interceptação de exceção habilita bits, sempre deve ser 0. |

## <a name="system-registers"></a>Registros do sistema

Assim como o AArch32, a especificação AArch64 fornece três registros "thread ID" controlados pelo sistema:

| Registrar  | Função |
| - | - |
| TPIDR_EL0 | Reservado. |
| TPIDRRO_EL0 | Contém o número de CPU para o processador atual. |
| TPIDR_EL1 | Aponta para a estrutura KPCR do processador atual. |

## <a name="floating-point-exceptions"></a>Exceções de ponto flutuante

O suporte para exceções de ponto flutuante de IEEE é opcional em sistemas AArch64. Para variantes de processador que têm exceções de ponto flutuante de hardware, o kernel do Windows captura silenciosamente as exceções e as desabilita implicitamente no registro FPCR. Essa interceptação garante o comportamento normalizado nas variantes do processador. Caso contrário, o código desenvolvido em uma plataforma sem suporte de exceção pode fazer com que ele não faça exceções inesperadas ao ser executado em uma plataforma com suporte.

## <a name="parameter-passing"></a>Passagem de parâmetro

Para funções não Variadic, a ABI do Windows segue as regras especificadas pelo ARM para passagem de parâmetro. Essas regras são extraídas diretamente do padrão de chamada de procedimento para a arquitetura AArch64:

### <a name="stage-a--initialization"></a>Etapa A – inicialização

Esse estágio é feito exatamente uma vez, antes de o processamento dos argumentos começar.

1. O número do próximo registro de finalidade geral (NGRN) é definido como zero.

1. A próxima SIMD e o número de registro de ponto flutuante (NSRN) são definidos como zero.

1. O próximo endereço de argumento empilhado (NSAA) é definido como o valor do ponteiro de pilha atual (SP).

### <a name="stage-b--pre-padding-and-extension-of-arguments"></a>Estágio B – pré-preenchimento e extensão de argumentos

Para cada argumento na lista, a primeira regra de correspondência da lista a seguir é aplicada. Se nenhuma regra corresponder, o argumento será usado sem modificações.

1. Se o tipo de argumento for um tipo composto cujo tamanho não pode ser determinado estaticamente pelo chamador e pelo receptor, o argumento será copiado para a memória e o argumento será substituído por um ponteiro para a cópia. (Não há tipos desse tipo em C/C++, mas eles existem em outras linguagens ou em extensões de linguagem).

1. Se o tipo de argumento for um HFA ou um HVA, o argumento será usado sem modificações.

1. Se o tipo de argumento for um tipo composto maior que 16 bytes, o argumento será copiado para a memória alocada pelo chamador e o argumento será substituído por um ponteiro para a cópia.

1. Se o tipo de argumento for um tipo composto, o tamanho do argumento será arredondado para o múltiplo mais próximo de 8 bytes.

### <a name="stage-c--assignment-of-arguments-to-registers-and-stack"></a>Estágio C – atribuição de argumentos para registros e pilha

Para cada argumento na lista, as regras a seguir são aplicadas por vez até que o argumento tenha sido alocado. Quando um argumento é atribuído a um registro, todos os bits não utilizados no registro têm um valor não especificado. Se um argumento for atribuído a um slot de pilha, os bytes de preenchimento não utilizados terão um valor não especificado.

1. Se o argumento for um tipo de ponto flutuante de uma ou de vetor de precisão simples ou de quatro pontos, e o NSRN for menor que 8, o argumento será alocado para os bits menos significativos de Register v\[NSRN]. O NSRN é incrementado em um. O argumento agora foi alocado.

1. Se o argumento for um HFA ou um HVA, e houver registros de ponto flutuante e SIMD não alocados suficientes (NSRN + número de membros ≤ 8), o argumento será alocado para os registros SIMD e de ponto flutuante, um registrador por membro de HFA ou HVA. O NSRN é incrementado pelo número de registros usados. O argumento agora foi alocado.

1. Se o argumento for um HFA ou um HVA, o NSRN será definido como 8 e o tamanho do argumento será arredondado para o múltiplo mais próximo de 8 bytes.

1. Se o argumento for um HFA, um HVA, um ponto flutuante de precisão quádrupla ou um tipo de vetor curto, o NSAA será arredondado para o maior de 8 ou o alinhamento natural do tipo do argumento.

1. Se o argumento for um tipo de ponto flutuante de meia ou precisão única, o tamanho do argumento será definido como 8 bytes. O efeito é como se o argumento tivesse sido copiado para os bits menos significativos de um registro de 64 bits e os bits restantes são preenchidos com valores não especificados.

1. Se o argumento for um HFA, um HVA, um ponto flutuante meio-, um único, um duplo ou um tipo de vetor curto, o argumento será copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento agora foi alocado.

1. Se o argumento for um tipo integral ou de ponteiro, o tamanho do argumento será menor ou igual a 8 bytes, e o NGRN será menor que 8, o argumento será copiado para os bits menos significativos em x\[NGRN]. O NGRN é incrementado em um. O argumento agora foi alocado.

1. Se o argumento tiver um alinhamento de 16, o NGRN será arredondado para o próximo número par.

1. Se o argumento for um tipo integral, o tamanho do argumento será igual a 16 e o NGRN será menor que 7, o argumento será copiado para x\[NGRN] e x\[NGRN + 1]. x\[NGRN] deve conter a palavra-chave mais baixa abordada da representação de memória do argumento. O NGRN é incrementado em dois. O argumento agora foi alocado.

1. Se o argumento for um tipo composto e o tamanho em palavras duplas do argumento não for maior que 8 menos NGRN, o argumento será copiado em registros de uso geral consecutivos, começando em x\[NGRN]. O argumento é passado como se tivesse sido carregado nos registros de um endereço alinhado em palavras duplas, com uma sequência apropriada de instruções de LDR que carregam registros consecutivos da memória. O conteúdo de qualquer parte não utilizada dos registros não é especificado por esse padrão. O NGRN é incrementado pelo número de registros usados. O argumento agora foi alocado.

1. O NGRN é definido como 8.

1. O NSAA é arredondado para o maior de 8 ou o alinhamento natural do tipo do argumento.

1. Se o argumento for um tipo composto, o argumento será copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento agora foi alocado.

1. Se o tamanho do argumento for menor que 8 bytes, o tamanho do argumento será definido como 8 bytes. O efeito é como se o argumento fosse copiado para os bits menos significativos de um registro de 64 bits, e os bits restantes foram preenchidos com valores não especificados.

1. O argumento é copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento agora foi alocado.

### <a name="addendum-variadic-functions"></a>Adendo: funções Variadic

As funções que usam um número variável de argumentos são tratadas de forma diferente do anterior, da seguinte maneira:

1. Todas as composições são tratadas da mesma forma; nenhum tratamento especial de HFAs ou HVAs.

1. Os registros SIMD e de ponto flutuante não são usados.

Efetivamente, é o mesmo das seguintes regras C. 12 – C. 15 para alocar argumentos para uma pilha imaginária, em que os primeiros 64 bytes da pilha são carregados em x0-120, e todos os argumentos restantes da pilha são colocados normalmente.

## <a name="return-values"></a>Valores retornados

Valores integrais são retornados em x0.

Valores de ponto flutuante são retornados em S0, D0 ou V0, conforme apropriado.

Os valores HFA e HVA são retornados em S0-S3, D0-D3 ou V0-v3, conforme apropriado.

Os tipos retornados pelo valor são tratados de forma diferente, dependendo se eles têm determinadas propriedades. Tipos que têm todas essas propriedades,

- Eles são *agregados* pela definição padrão de c++ 14, ou seja, eles não têm construtores fornecidos pelo usuário, nenhum membro de dados não estático privado ou protegido, nenhuma classe base e nenhuma função virtual e
- Eles têm um operador de atribuição de cópia trivial e
- Eles têm um destruidor trivial,

Use o seguinte estilo de retorno:

- Tipos menores ou iguais a 8 bytes são retornados em x0.
- Tipos menores ou iguais a 16 bytes são retornados em x0 e X1, com x0 que contém os 8 bytes de ordem inferior.
- Para tipos maiores que 16 bytes, o chamador deve reservar um bloco de memória de tamanho e alinhamento suficientes para manter o resultado. O endereço do bloco de memória deve ser passado como um argumento adicional para a função em x8. O receptor pode modificar o bloco de memória de resultado a qualquer momento durante a execução da sub-rotina. O receptor não é necessário para preservar o valor armazenado em x8.

Todos os outros tipos usam esta Convenção:

- O chamador deve reservar um bloco de memória de tamanho e alinhamento suficientes para manter o resultado. O endereço do bloco de memória deve ser passado como um argumento adicional para a função em x0 ou x1 se $this for passado em x0. O receptor pode modificar o bloco de memória de resultado a qualquer momento durante a execução da sub-rotina. O receptor retorna o endereço do bloco de memória em x0.

## <a name="stack"></a>Pilha

Seguindo a ABI colocada pelo ARM, a pilha deve permanecer alinhada em 16 bytes em todos os momentos. O AArch64 contém um recurso de hardware que gera falhas de alinhamento de pilha sempre que o SP não está alinhado em 16 bytes e uma carga ou um repositório relativo ao SP é feito. O Windows é executado com esse recurso habilitado em todos os momentos.

Funções que alocam 4K ou mais de pilha devem garantir que cada página antes da página final seja tocada na ordem. Essa ação garante que nenhum código possa "saltar" nas páginas de proteção que o Windows usa para expandir a pilha. Normalmente, o toque é feito pelo `__chkstk` auxiliar, que tem uma Convenção de chamada personalizada que passa a alocação de pilha total dividida por 16 em X15.

## <a name="red-zone"></a>Zona vermelha

A área de 16 bytes imediatamente abaixo do ponteiro de pilha atual é reservada para uso por cenários de análise e aplicação dinâmica de patches. Essa área permite que o código com cuidado gerado seja inserido, que armazena dois registros em [SP, #-16] e os usa temporariamente para fins arbitrários. O kernel do Windows garante que esses 16 bytes não sejam substituídos se uma exceção ou interrupção for executada, no modo de usuário e kernel.

## <a name="kernel-stack"></a>Pilha do kernel

A pilha de modo kernel padrão no Windows é de seis páginas (24K). Preste atenção extra às funções com buffers de pilha grandes no modo kernel. Uma interrupção mal demorada poderia surgir com pouco espaço e criar uma verificação de bug de pane de pilha.

## <a name="stack-walking"></a>Movimentação de pilha

O código dentro do Windows é compilado com ponteiros de quadro habilitados ([/Oy-](reference/oy-frame-pointer-omission.md)) para habilitar a movimentação de pilha rápida. Geralmente, x29 (FP) aponta para o próximo link na cadeia, que é um par {FP, LR}, que indica o ponteiro para o quadro anterior na pilha e o endereço de retorno. O código de terceiros é incentivado a habilitar ponteiros de quadro também, para permitir uma melhor criação de perfil e rastreamento.

## <a name="exception-unwinding"></a>Desenrolamento de exceção

O desenrolamento durante a manipulação de exceção é assistido pelo uso de códigos de liberação. Os códigos de liberação são uma sequência de bytes armazenados na seção. xdata do executável. Eles descrevem a operação do prólogo e do epílogo de maneira abstrata, de modo que os efeitos do prólogo de uma função possam ser desfeitos na preparação para fazer backup no quadro de pilhas do chamador. Para obter mais informações sobre os códigos de liberação, consulte [manipulação de exceção do ARM64](arm64-exception-handling.md).

O EABI ARM também especifica um modelo de desenrolamento de exceção que usa códigos de liberação. No entanto, a especificação como apresentada é insuficiente para o desenrolamento no Windows, que deve lidar com casos em que o PC está no meio de um prólogo de função ou epílogo.

O código gerado dinamicamente deve ser descrito com tabelas de função dinâmicas `RtlAddFunctionTable` via e funções associadas, para que o código gerado possa participar da manipulação de exceção.

## <a name="cycle-counter"></a>Contador de ciclo

Todas as CPUs ARMv8 são necessárias para dar suporte a um registro de contador de ciclo, um registro de 64 bits que o Windows configura para ser legível em qualquer nível de exceção, incluindo o modo de usuário. Ele pode ser acessado por meio do registro de PMCCNTR_EL0 especial, usando o opcode de MSR no `_ReadStatusReg` código do assembly ou o intrínseco no código C/C++.

O contador de ciclo aqui é um contador de ciclo verdadeiro, não um relógio de parede. A frequência de contagem vai variar com a frequência do processador. Se você sentir que deve saber a frequência do contador de ciclo, você não deve estar usando o contador de ciclo. Em vez disso, você deseja medir o tempo do relógio de parede, para `QueryPerformanceCounter`o qual você deve usar.

## <a name="see-also"></a>Confira também

[Problemas de migração ARM do Visual C++](common-visual-cpp-arm-migration-issues.md)<br/>
[Manipulação de exceção do ARM64](arm64-exception-handling.md)
