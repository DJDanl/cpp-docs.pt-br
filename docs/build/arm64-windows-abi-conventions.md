---
title: Visão geral das convenções de ABI ARM64
ms.date: 03/27/2019
ms.openlocfilehash: 4c0f89f97529d4cd70e1449c90b131d25d30f9ee
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62195495"
---
# <a name="overview-of-arm64-abi-conventions"></a>Visão geral das convenções de ABI ARM64

A interface binária de aplicativo básico (ABI) para Windows quando compilado e executados em processadores ARM no modo de 64 bits (ARMv8 ou arquiteturas mais adiante), em grande parte, segue a EABI do ARM padrão AArch64. Este artigo destaca alguns dos principais suposições e alterações do que está documentado na EABI do. Para obter informações sobre a ABI de 32 bits, consulte [convenções de visão geral do ARM ABI](overview-of-arm-abi-conventions.md). Para obter mais informações sobre a EABI padrão do ARM, consulte [Interface binária de aplicativo (ABI) para a arquitetura ARM](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.subset.swdev.abi/index.html) (link externo).

## <a name="definitions"></a>Definições

Com a introdução do suporte de 64 bits, o ARM definiu vários termos:

- **AArch32** – arquitetura (ISA) definida pela ARM, incluindo a execução em modo Thumb de conjunto de instrução de 32 bits herdada.
- **AArch64** – arquitetura (ISA) definida pela ARM de definir a nova instrução de 64 bits.
- **ARMv7** – a especificação da "geração 7ª" hardware ARM, o que inclui apenas o suporte para AArch32. Esta versão do hardware ARM é a primeira versão Windows para ARM com suporte.
- **ARMv8** – a especificação da "geração 8ª" hardware ARM, o que inclui suporte para AArch32 e AArch64.

Windows também usa estes termos:

- **ARM** – refere-se na arquitetura de ARM de 32 bits (AArch32), também conhecido como WoA (Windows em ARM).
- **ARM32** – mesmo que o ARM, acima; usado neste documento para fins de esclarecimento.
- **ARM64** – refere-se na arquitetura do ARM de 64 bits (AArch64). Não há nenhum algo como WoA64.

Por fim, ao fazer referência a tipos de dados, as seguintes definições de ARM são referenciadas:

- **Vetor curto** – um tipo de dados diretamente representável no SIMD, um vetor de bytes de 8 ou 16 bytes válidos de elementos. Ela é alinhada ao seu tamanho, 8 bytes ou 16 bytes, onde cada elemento pode ser 1, 2, 4 ou 8 bytes.
- **HFA (ponto flutuante homogêneos agregado)** – um tipo de dados com 2 a 4 membros idênticos de ponto flutuantes, flutua ou dobra.
- **HVA (homogênea do vetor curto agregado)** – um tipo de dados com os membros de vetor curto de 2 a 4 idênticos.

## <a name="base-requirements"></a>Requisitos base

A versão ARM64 do Windows pressupõe que ele é executado em um ARMv8 ou arquitetura posterior em todos os momentos. Ambos de ponto flutuante e suporte NEON são presumidos como estar presente no hardware.

A especificação de ARMv8 permite suporte completo de aplicativos AArch32. No entanto, o suporte para aplicativos ARM32 existentes na versão ARM64 do Windows não está planejado. (Ou seja, há não há planos para WOW64). Esse suporte está sujeito a reavaliação no futuro, mas é a suposição de trabalho atual.

A especificação de ARMv8 descreve a nova criptografia opcional e opcodes de auxiliar CRC para AArch32 e AArch64. Suporte para eles é opcional no momento, mas recomendado. Para tirar proveito desses opcodes, aplicativos devem primeiro fazer verificações de tempo de execução para sua existência.

## <a name="endianness"></a>Endianness

Como com o ARM32 versão do Windows, no Windows ARM64 é executado em modo little-endian. Alternar a ordenação de bits é difícil de atingir sem suporte ao modo de kernel no AArch64, portanto, é mais fácil de impor.

## <a name="alignment"></a>Alinhamento

Em execução em ARM64 do Windows permite que o hardware de CPU para manipular acessos desalinhados de maneira transparente. Em uma melhoria de AArch32, esse suporte agora também funciona para todos os acessos de inteiro (incluindo acessos de várias palavras) e acessos de ponto flutuantes.

No entanto, os acessos à memória fora do cache (dispositivo) ainda devem sempre ser alinhados. Se o código possivelmente pode ler ou gravar dados desalinhados de memória sem cache, que ele deve certificar-se alinhe todos os acessos.

## <a name="integer-registers"></a>Registros de inteiros

A arquitetura AArch64 dá suporte a 32 registros de inteiros:

| Registro | Volátil? | Função |
| - | - | - |
| x0 | Volátil | Parâmetro/zero registrar 1, o registro de resultado |
| x1-x7 | Volátil | Registre-se de zero/parâmetro 2 a 8 |
| x8-x15 | Volátil | Registros de rascunho |
| x16-x17 | Volátil | Registros de chamada de procedimento intra transitórios |
| x18 | Não volátil | Registro de plataforma: no modo kernel, aponta para KPCR do processador atual; no modo de usuário, aponta para TEB |
| x19-x28 | Não volátil | Registros de rascunho |
| x29/fp | Não volátil | Ponteiro de quadro |
| x30/lr | Não volátil | Registros de link |

Cada registro pode ser acessado como um valor de total de 64 bits (via x0-x30) ou como um valor de 32 bits (via w0 w30). operações de 32 bits zero-estendem seus resultados até 64 bits.

Consulte o parâmetro passando a seção para obter detalhes sobre o uso dos registros de parâmetro.

Ao contrário de AArch32, o contador do programa (PC) e o ponteiro de pilha (SP) não são registros indexados. Eles estão limitados em como eles podem ser acessados. Também Observe que não há nenhum x31 registrar. Essa codificação é usada para fins especiais.

O ponteiro de quadro (x29) é necessário para compatibilidade com a passagem rápida de pilha usados pelo ETW e outros serviços. Ele deve apontar para o anterior {x29, x 30} par na pilha.

## <a name="floating-pointsimd-registers"></a>Registra para SIMD de ponto flutuante

A arquitetura AArch64 também dá suporte a 32 registros para SIMD de ponto flutuante, resumidos abaixo:

| Registro | Volátil? | Função |
| - | - | - |
| v0 | Volátil | Parâmetro/zero registrar 1, o registro de resultado |
| v1-v7 | Volátil | Parâmetro/zero registra 2 a 8 |
| v8-v15 | Não volátil | Registra de zero (somente 64 bits baixos não são voláteis) |
| v16-v31 | Volátil | Registros de rascunho |

Cada registro pode ser acessado como um valor de total de 128 bits (via v0 v31 ou q0 q31). Ele pode ser acessado como um valor de 64 bits (via d0-d31), como um valor de 32 bits (via s0-s31), como um valor de 16 bits (via h0-amp;H31) ou como um valor de 8 bits (via b0-b31). Acessos menores do que 128 bits acessar apenas os bits inferiores do registro completo de 128 bits. Eles deixam os bits restantes inalterados, a menos que especificado o contrário. (É diferente do AArch32, onde os registros menores foram empacotados na parte superior de registros maiores AArch64.)

O registro de controle de ponto flutuante (FPCR) tem certos requisitos sobre os vários campos de bits dentro dele:

| Bits | Significado | Volátil? | Função |
| - | - | - | - |
| 26 | AHP | Não-volátil | Controle de meia precisão alternativo. |
| 25 | DN | Não-volátil | Controle de modo NaN padrão. |
| 24 | FZ | Não volátil | Controle modo Flush-to-zero. |
| 23-22 | RMode | Não volátil | Controle de modo de arredondamento. |
| 15,12-8 | IDE/IXE/etc | Não-volátil | Exceção interceptar os bits de habilitação, deve ser sempre 0. |

## <a name="system-registers"></a>Registros do sistema

Como AArch32, a especificação de AArch64 fornece três "ID do thread" registros controlado pelo sistema:

| Registro | Função |
| - | - |
| TPIDR_EL0 | Reservado. |
| TPIDRRO_EL0 | Contém o número de CPU para o processador atual. |
| TPIDR_EL1 | Aponta para a estrutura KPCR do processador atual. |

## <a name="floating-point-exceptions"></a>Exceções de ponto flutuante

Suporte para exceções de ponto flutuante IEEE é opcional em sistemas de AArch64. Para variações de processador que têm exceções de ponto flutuante de hardware, o kernel do Windows silenciosamente captura as exceções e implicitamente as desabilita no registro FPCR. Esta interceptação garante comportamento normalizado entre variações do processador. Caso contrário, código desenvolvido em uma plataforma sem suporte de exceção pode se localizar levando exceções inesperadas durante a execução em uma plataforma com suporte.

## <a name="parameter-passing"></a>Passagem de parâmetro

Para funções não variadic, a ABI do Windows segue as regras especificadas por ARM para passagem de parâmetro. Essas regras são extraídas diretamente do padrão de chamar procedimento para a arquitetura AArch64:

### <a name="stage-a--initialization"></a>Estágio A – inicialização

Esse estágio é feito exatamente uma vez, antes do início do processamento dos argumentos.

1. O número registrar uso geral (NGRN) próximo é definido como zero.

1. A próxima SIMD e o número de registro de ponto flutuante (NSRN) é definido como zero.

1. O próximo endereço de argumento empilhado (NSAA) é definido como o valor atual do ponteiro de pilha (SP).

### <a name="stage-b--pre-padding-and-extension-of-arguments"></a>Estágio B — pré-enchimento e extensão de argumentos

Para cada argumento na lista, a primeira regra correspondente na lista a seguir é aplicada. Se nenhuma correspondência de regra, o argumento for usado sem modificações.

1. Se o tipo de argumento for um tipo composto cujo tamanho não pode ser determinado estaticamente pelo chamador e o receptor, o argumento é copiado para a memória e o argumento é substituído por um ponteiro para a cópia. (Não há nenhum desses tipos em C/C++, mas eles existem em outros idiomas ou em extensões de linguagem).

1. Se o tipo de argumento for um HFA ou um HVA, o argumento é usado sem modificações.

1. Se o tipo de argumento é um tipo composto maior que 16 bytes, em seguida, o argumento é copiado para a memória alocada pelo chamador e o argumento é substituído por um ponteiro para a cópia.

1. Se o tipo de argumento for um tipo composto, em seguida, o tamanho do argumento é arredondado para o múltiplo de 8 bytes.

### <a name="stage-c--assignment-of-arguments-to-registers-and-stack"></a>Estágio C — atribuição de argumentos a registros e à pilha

Para cada argumento na lista, as seguintes regras são aplicadas em turnos até que o argumento foi alocado. Quando um argumento é atribuído a um registro, todos os bits não usados no registro têm não especificado valor. Se um argumento é atribuído a um slot de pilha, todos os bytes de preenchimento não utilizados têm não for especificado o valor.

1. Se o argumento for uma metade, único, duplo ou ponto flutuante de precisão Quad ou tipo de vetor curto e o NSRN é menor que 8 e o argumento será alocado para os bits menos significativos de registro v\[NSRN]. O NSRN é incrementado em um. O argumento foi alocado.

1. Se o argumento for um HFA ou um HVA e há SIMD não alocado suficiente e registros de ponto flutuante (NSRN + número de membros ≤ 8), o argumento será alocado para SIMD e registra de ponto flutuante, um registro por membro da HFA ou HVA. O NSRN é incrementado pelo número de registros usados. O argumento foi alocado.

1. Se o argumento for um HFA ou um HVA, em seguida, o NSRN é definido como 8, e o tamanho do argumento é arredondado para o múltiplo mais próximo de 8 bytes.

1. Se o argumento for um HFA, um HVA, um tipo de vetor de curto ou de ponto flutuante de precisão de Quad, o NSAA é arredondado para o maior dos 8 ou o alinhamento Natural do tipo do argumento.

1. Se o argumento for um tipo de ponto flutuante de precisão metade ou simples, em seguida, o tamanho do argumento é definido como 8 bytes. O efeito é como se tivesse o argumento foi copiado para os bits menos significativos de um registro de 64 bits, e os bits restantes são preenchidos com valores não especificados.

1. Se o argumento for um HFA, um HVA, meia-, único, duplo- ou ponto flutuante de precisão Quad ou tipo de vetor curto e o argumento é copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento foi alocado.

1. Se o argumento for um tipo de ponteiro ou Integral, o tamanho do argumento é menor ou igual a 8 bytes e o NGRN é menor que 8, o argumento é copiado para os bits menos significativos em x\[NGRN]. O NGRN é incrementado em um. O argumento foi alocado.

1. Se o argumento tem um alinhamento de 16, em seguida, o NGRN é arredondado para o próximo número par.

1. Se o argumento é um tipo Integral, o tamanho do argumento é igual a 16 e o NGRN é menor que 7, o argumento é copiado para x\[NGRN] e x\[NGRN + 1]. x\[NGRN] deve conter a inferior endereçada palavra dupla da representação de memória do argumento. O NGRN é incrementado por dois. O argumento foi alocado.

1. Se o argumento for um tipo composto e o tamanho em palavras duplas do argumento é não mais do que 8 menos NGRN, então o argumento é copiado para registros de uso geral consecutivos, começando em x\[NGRN]. O argumento é passado como se tivesse sido carregada para os registros de um endereço alinhado à palavra dupla, com uma sequência apropriada de instruções de LDR que carregar registros consecutivos da memória. Esse padrão não for especificado o conteúdo de qualquer parte não utilizado dos registros. O NGRN é incrementado pelo número de registros usados. O argumento foi alocado.

1. O NGRN é definido como 8.

1. O NSAA é arredondado para o maior dos 8 ou o alinhamento Natural do tipo do argumento.

1. Se o argumento for um tipo composto, o argumento é copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento foi alocado.

1. Se o tamanho do argumento for menor que 8 bytes, em seguida, o tamanho do argumento é definido como 8 bytes. O efeito é como se o argumento foi copiado para os bits menos significativos de um registro de 64 bits, e os bits restantes foram preenchidos com valores não especificados.

1. O argumento é copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento foi alocado.

### <a name="addendum-variadic-functions"></a>Adendo: Funções Variadic

Funções que usam um número variável de argumentos são tratadas de maneira diferente acima, da seguinte maneira:

1. Todas as composições são tratadas parecidos; nenhum tratamento especial de HFAs ou HVAs.

1. SIMD e registra de ponto flutuante não é usado.

Na verdade, é o mesmo que as regras a seguir C.12–C.15 alocar argumentos em uma pilha imaginário, onde os primeiros 64 bytes da pilha são carregados no x7 x0 e quaisquer argumentos de pilha restantes são colocados normalmente.

## <a name="return-values"></a>Valores de retorno

Valores integrais são retornados em x0.

Valores de ponto flutuante são retornados em s0/d0/v0 conforme apropriado.

Tipos retornados por valor são tratados diferentemente dependendo se eles têm determinadas propriedades. Tipos que têm todas essas propriedades,

- eles são *agregação* por C + + 14 definição padrão, ou seja, eles têm nenhum construtor fornecido pelo usuário, nenhum membro de dados de não estáticos privados ou protegidos, sem classes base e sem funções virtuais, e
- eles têm um operador de atribuição de cópia trivial, e
- eles têm um destruidor trivial,

Use o estilo de retorno a seguir:

- Tipos de menor ou igual a 8 bytes são retornados em x0.
- Tipos de menor ou igual a 16 bytes são retornados em x0 e x1, com x0 contendo os bytes de 8 de ordem inferior.
- Para tipos de maiores que 16 bytes, o chamador deverá reservar um bloco de memória de tamanho suficiente e o alinhamento para conter o resultado. O endereço do bloco de memória deverão ser passado como um argumento adicional para a função em x8. O receptor pode modificar o bloco de memória de resultados a qualquer momento durante a execução da sub-rotina. O receptor não é necessário para preservar o valor armazenado no x8.

Todos os outros tipos usam esta convenção:

- O chamador deverá reservar um bloco de memória de tamanho suficiente e o alinhamento para conter o resultado. O endereço do bloco de memória deverão ser passado como um argumento adicional para a função em x0 e x1 se $ que isso é passado na x0. O receptor pode modificar o bloco de memória de resultados a qualquer momento durante a execução da sub-rotina. Receptor retorna o endereço do bloco de memória na x0.

## <a name="stack"></a>Pilha

Seguindo a ABI Cllique ARM, a pilha deve permanecer 16 bytes alinhado em todos os momentos. AArch64 contém um recurso de hardware que gera falhas de alinhamento de pilha sempre que o SP não está alinhado de 16 bytes e uma carga de SP relativo ou store é feita. Windows é executado com esse recurso habilitado em todos os momentos.

Funções que alocam 4 mil ou mais que vale a pena de pilha devem garantir que cada página antes da página final será tocada em ordem. Esta ação garante que nenhum código poderá "saltar sobre" as páginas de proteção que o Windows usa para expandir a pilha. Normalmente, o toque é feito `__chkstk` auxiliar, que tem uma convenção de chamada personalizada que passa a alocação da pilha total dividida por 16 em x15.

## <a name="red-zone"></a>Zona vermelha

A área de 16 bytes imediatamente abaixo do ponteiro de pilha atual é reservada para uso pela análise e dinâmica de cenários de aplicação de patch. Essa área permite que o código gerado cuidadosamente a ser inserido, que armazena dois registros em [sp, n º 16] e os usa temporariamente para propósitos arbitrários. O kernel do Windows garante que os 16 bytes não são substituídos, se uma exceção ou interrupção for obtida, no modo de usuário e kernel.

## <a name="kernel-stack"></a>Pilha de kernel

A pilha de modo de kernel padrão no Windows é seis páginas (24k). Preste atenção extra para funções com grandes buffers de pilha em modo kernel. Uma interrupção acidente poderia ocorrer com pouco espaço e crie uma verificação de bug de pânico de pilha.

## <a name="stack-walking"></a>Passagem de pilha

O código dentro do Windows é compilado com ponteiros de quadro habilitados ([/Oy-](reference/oy-frame-pointer-omission.md)) para habilitar a passagem rápida de pilha. Em geral, x29 (fp) aponta para o próximo link na cadeia, que é um {fp, lr} par, que indica o ponteiro para o quadro anterior na pilha e o endereço de retorno. Código de terceiros é incentivado habilitar ponteiros de quadro, bem, para permitir aprimorada de criação de perfil e o rastreamento.

## <a name="exception-unwinding"></a>O desenrolamento de exceção

Desenrolamento durante o tratamento de exceção com a assistência com o uso de códigos de desenrolamento. Os códigos de desenrolamento são uma sequência de bytes armazenados na seção. XData do executável. Eles descrevem a operação de prólogo e epílogo de maneira abstrata, de modo que os efeitos do prólogo da função possam ser desfeitos em preparação para backup no quadro de pilha do chamador. Para obter mais informações sobre os códigos de desenrolamento, consulte [tratamento de exceção ARM64](arm64-exception-handling.md).

A EABI do ARM também especifica um modelo de desenrolamento de exceção que usa códigos de desenrolamento. No entanto, a especificação como apresentado é insuficiente para desenrolamento no Windows, que devem manipular casos em que o computador está no meio do prólogo da função ou do epílogo.

Código gerado dinamicamente deve ser descrito com tabelas de função dinâmico via `RtlAddFunctionTable` e funções associadas, para que o código gerado pode participar de manipulação de exceção.

## <a name="cycle-counter"></a>Contador de ciclo

Todas as CPUs ARMv8 são necessários para dar suporte a um contador de ciclo de registrar um registro de 64 bits que configura o Windows para serem legíveis em qualquer nível de exceção, incluindo o modo de usuário. Ele pode ser acessado por meio de PMCCNTR_EL0 especial se registrar usando o opcode MSR no código de assembly, ou o `_ReadStatusReg` intrínseco em C /C++ código.

O contador de ciclo aqui é um verdadeiro contador de ciclo, não um relógio de parede. A frequência de contagem variam de acordo com a frequência do processador. Se você achar que você deve saber a frequência do contador de ciclo, você não deve estar usando o contador de ciclo de. Em vez disso, você deseja medir a hora do relógio, em que você deve usar `QueryPerformanceCounter`.

## <a name="see-also"></a>Consulte também

[Problemas de migração ARM do Visual C++ comuns](common-visual-cpp-arm-migration-issues.md)<br/>
[Tratamento de exceção ARM64](arm64-exception-handling.md)
