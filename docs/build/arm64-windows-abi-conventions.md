---
title: Visão geral das convenções de ABI ARM64
ms.date: 03/22/2019
ms.openlocfilehash: 5dddc26285606b771a3939be19dff5b9ad53f3c7
ms.sourcegitcommit: 42e65c171aaa17a15c20b155d22e3378e27b4642
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2019
ms.locfileid: "58356186"
---
# <a name="overview-of-arm64-abi-conventions"></a>Visão geral das convenções de ABI ARM64

A ABI para Windows quando compilado e execute em processadores ARM no modo de 64 bits (ARMv8 ou arquiteturas mais adiante), na maioria dos casos, a básica segue EABI do ARM padrão AArch64. Este artigo destaca alguns dos principais suposições e alterações do que está documentado na EABI do. Para obter informações sobre a ABI de 32 bits, consulte [convenções de visão geral do ARM ABI](overview-of-arm-abi-conventions.md). Para obter mais informações sobre a EABI padrão do ARM, consulte [Interface binária de aplicativo (ABI) para a arquitetura ARM](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.subset.swdev.abi/index.html) (link externo).

## <a name="definitions"></a>Definições

Com a introdução do suporte de 64 bits, o ARM definiu vários termos:

- **AArch32** – arquitetura (ISA) definida pela ARM, incluindo a execução em modo Thumb de conjunto de instrução de 32 bits herdada.
- **AArch64** – arquitetura (ISA) definida pela ARM de definir a nova instrução de 64 bits.
- **ARMv7** – a especificação da "geração 7ª" hardware ARM, o que inclui apenas o suporte para AArch32. Essa é a versão do hardware ARM que a primeira versão do Windows para ARM com suporte.
- **ARMv8** – a especificação da "geração 8ª" hardware ARM, o que inclui suporte para AArch32 e AArch64.

Essas definições, além de Windows usamos esses termos:

- **ARM** – refere-se na arquitetura do ARM de 32 bits (AArch32). Isso é às vezes, chamado WoA (Windows em ARM).
- **ARM32** – mesmo que o ARM, acima; usado neste documento para fins de esclarecimento.
- **ARM64** – refere-se na arquitetura do ARM de 64 bits (AArch64). Não há nenhum algo como WoA64.

Por fim, ao fazer referência a tipos de dados, as seguintes definições de ARM são referenciadas:

- **Vetor curto** – isso é um tipo de dados que é representado diretamente em SIMD; ou seja, um vetor de elementos, alinhado ao seu tamanho (bytes 8 ou 16), onde cada elemento pode ser 1, 2, 4 ou 8 bytes válidos 8 ou 16 bytes
- **HFA (ponto flutuante homogêneos agregado)** – este é um tipo de dados com 2 a 4 ponto flutuantes membros idênticos (floats ou duplos)
- **HVA (homogênea do vetor curto agregado)** – este é um tipo de dados com membros idênticos de vetor curto 2 a 4

## <a name="base-requirements"></a>Requisitos base

A versão ARM64 do Windows pressupõe que ele é executado em um ARMv8 ou arquitetura posterior em todos os momentos. Ambos de ponto flutuante e suporte NEON são presumidos como estar presente no hardware.

Embora a especificação de ARMv8 permite suporte completo de aplicativos AArch32, existem atualmente não há planos para oferecer suporte à execução de aplicativos de ARM32 existentes na versão ARM64 do Windows (ou seja, não há planos para WOW64). Isso está sujeito à reavaliação no futuro, mas é a suposição de trabalho atual.

A especificação de ARMv8 descreve a nova criptografia opcional e opcodes de auxiliar CRC para AArch32 e AArch64. Suporte para eles é opcional no momento, mas recomendado. Código que desejam tirar proveito desses opcodes deve executar verificações de tempo de execução para sua existência.

## <a name="endianness"></a>Endianness

Como com o ARM32 versão do Windows, no Windows ARM64 é executado em modo little-endian. Alternar a ordenação de bits é difícil de atingir sem suporte ao modo de kernel no AArch64, portanto, é mais fácil de impor.

## <a name="alignment"></a>Alinhamento

Em execução em ARM64 do Windows permite que o hardware de CPU para manipular acessos desalinhados de maneira transparente. Em uma melhoria de AArch32, esse suporte agora também funciona para todos os acessos de inteiro (incluindo acessos de várias palavras) e acessos de ponto flutuantes.

No entanto, os acessos à memória fora do cache (dispositivo) ainda devem sempre ser alinhados. Isso significa que, se houver código que pode ser aberto em ler/gravar dados desalinhados da memória sem cache, ele deve executar as coisas seguras e certifique-se de que todos os acessos estão alinhados.

## <a name="integer-registers"></a>Registros de inteiros

A arquitetura AArch64 dá suporte a 32 registros de inteiros, resumidos abaixo:

|Registro|Volátil?|Função|
|-|-|-|
x0|Volátil|Parâmetro/zero registrar 1, o registro de resultado
x1-x7|Volátil|Registre-se de zero/parâmetro 2 a 8
x8-x15|Volátil|Registros de rascunho
x16-x17|Volátil|Registros de chamada de procedimento intra transitórios
x18|Não volátil|Registro de plataforma: no modo kernel, aponta para KPCR do processador atual; no modo de usuário, aponta para TEB
x19-x28|Não volátil|Registros de rascunho
x29/fp|Não volátil|Ponteiro de quadro
x30/lr|Não volátil|Registros de link

Cada registro pode ser acessado como um valor de total de 64 bits (via x0-x30) ou como um valor de 32 bits (via w0 w30). operações de 32 bits zero-estendem seus resultados até 64 bits.

Consulte o parâmetro passando a seção para obter detalhes sobre o uso dos registros de parâmetro.

Observe que diferentemente AArch32, PC e SP não são indexadas de registros e, portanto, são limitados em como eles podem ser acessados. Também Observe que não há nenhum x31 registrar (que codificação é usada para fins especiais).

O uso do ponteiro do quadro (x29) é necessário para compatibilidade com rápida movimentação de pilhas usada pelo ETW e outros serviços. Ele deve apontar para o anterior {x29, x 30} par na pilha.

## <a name="floating-pointsimd-registers"></a>Registra para SIMD de ponto flutuante

A arquitetura AArch64 também dá suporte a 32 registros para SIMD de ponto flutuante, resumidos abaixo:

Registro|Volátil?|Função
|-|-|-|
v0|Volátil|Parâmetro/zero registrar 1, o registro de resultado
v1-v7|Volátil|Parâmetro/zero registra 2 a 8
v8-v15|Não volátil|Rascunho de registros (Observe que apenas os 64 bits baixos não são voláteis)
v16-v31|Volátil|Registros de rascunho

Cada registro pode ser acessado como um valor de 128 bits completo (via v0 v31 ou q0 q31), como um valor de 64 bits (via d0-d31), como um valor de 32 bits (via s0-s31), como um valor de 16 bits (via h0-amp;H31) ou como um valor de 8 bits (via b0-b31). Acessos menores do que 128 bits acessar apenas os bits inferiores do registro completo de 128 bits e deixe os bits restantes inalterados, a menos que especificado o contrário. (Observe que isso é significativamente diferente da AArch32, onde os registros menores foram empacotados na parte superior de registros maiores).

Além dos registros de dados, o registro de controle de ponto flutuante (FPCR) tem certos requisitos sobre os vários campos de bits dentro dele:

Bits|Significado|Volátil?|Função
|-|-|-|-|
26|AHP|Não-volátil|Controle de meia precisão alternativo
25|DN|Não-volátil|Controle de modo NaN padrão
24|FZ|Não volátil|Controle de modo Flush-to-zero
23-22|RMode|Não volátil|Controle de modo de arredondamento
15,12-8|IDE/IXE/etc|Não-volátil|Bits de habilitação de captura de exceção, deve ser sempre 0

## <a name="system-registers"></a>Registros do sistema

Como AArch32, a especificação de AArch64 fornece três controlado pelo sistema "ID do thread" registros que são alocados/usado da seguinte maneira:

Registro|Função
|-|-|
TPIDR_EL0|Reservado
TPIDRRO_EL0|Contém o número de CPU para o processador atual
TPIDR_EL1|Aponta para a estrutura KPCR do processador atual

## <a name="floating-point-exceptions"></a>Exceções de ponto flutuante

Suporte para exceções de ponto flutuante IEEE é opcional em sistemas de AArch64. Para variações de processador que têm exceções de ponto flutuante de hardware, o kernel do Windows silenciosamente captura as exceções e implicitamente as desabilita no registro FPCR. Isso é para garantir comportamento normalizado entre variações do processador (caso contrário, o código desenvolvido em uma plataforma sem suporte de exceção pode se localizar levando exceções inesperadas durante a execução em uma plataforma com suporte).

## <a name="parameter-passing"></a>Passagem de parâmetro

Para funções não variadic, a ABI do Windows segue as regras especificadas por ARM para passagem de parâmetro. Essas regras são extraídas diretamente do padrão de chamar procedimento para a arquitetura AArch64:

### <a name="stage-a--initialization"></a>Estágio A – inicialização

Esse estágio é executado exatamente uma vez, antes de começa o processamento dos argumentos.

1. O número registrar uso geral (NGRN) próximo é definido como zero.

1. A próxima SIMD e o número de registro de ponto flutuante (NSRN) é definido como zero.

1. O próximo endereço de argumento empilhado (NSAA) é definido como o valor atual do ponteiro de pilha (SP).

### <a name="stage-b--pre-padding-and-extension-of-arguments"></a>Estágio B — pré-enchimento e extensão de argumentos

Para cada argumento na lista, a primeira regra correspondente na lista a seguir é aplicada. Se nenhuma correspondência de regra que o argumento é usado sem modificações.

1. Se o tipo de argumento for um tipo composto cujo tamanho não pode ser determinado estaticamente pelo chamador e o receptor, o argumento é copiado para a memória e o argumento é substituído por um ponteiro para a cópia. (Não há nenhum desses tipos em C/C++, mas eles existem em outros idiomas ou em extensões de linguagem).

1. Se o tipo de argumento for um HFA ou um HVA, o argumento é usado sem modificações.

1. Se o tipo de argumento for um tipo composto que é maior que 16 bytes, em seguida, o argumento é copiado para a memória alocada pelo chamador e o argumento é substituído por um ponteiro para a cópia.

1. Se o tipo de argumento é um tipo composto, em seguida, o tamanho do argumento é arredondado para o múltiplo de 8 bytes.

### <a name="stage-c--assignment-of-arguments-to-registers-and-stack"></a>Estágio C — atribuição de argumentos a registros e à pilha

Para cada argumento na lista as seguintes regras são aplicadas por sua vez até que o argumento foi alocado. Quando um argumento é atribuído a um registro de todos os bits não usados no registro têm não especificado valor. Quando um argumento é atribuído a um slot de pilha todos os bytes de preenchimento não utilizados têm não for especificado o valor.

1. Se o argumento for uma metade, único, duplo ou ponto flutuante de precisão Quad ou tipo de vetor curto e o NSRN é menor que 8, em seguida, o argumento será alocado para os bits menos significativos do registro v [NSRN]. O NSRN é incrementado em um. O argumento foi alocado.

1. Se o argumento for um HFA ou um HVA e há SIMD não alocado suficiente e registros de ponto flutuante (NSRN + número de membros ≤ 8), o argumento será alocado para SIMD e registra de ponto flutuante (com um registro por membro da HFA ou HVA). O NSRN é incrementado pelo número de registros usados. O argumento foi alocado.

1. Se o argumento for um HFA ou um HVA o NSRN é definido como 8, e o tamanho do argumento é arredondado para o múltiplo mais próximo de 8 bytes.

1. Se o argumento for um HFA, um HVA, um vetor curto ou de ponto flutuante de precisão Quad digite, em seguida, o NSAA é arredondado até o maior dos 8 ou o alinhamento Natural do tipo do argumento.

1. Se o argumento for um tipo de ponto flutuante de precisão metade ou simples, em seguida, o tamanho do argumento é definido como 8 bytes. O efeito é como se tivesse o argumento foi copiado para os bits menos significativos de um registro de 64 bits e os bits restantes preenchidos com valores não especificados.

1. Se o argumento for um HFA, um HVA, meia-, único, duplo - ou ponto flutuante de precisão Quad ou tipo de vetor curto e o argumento é copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento foi alocado.

1. Se o argumento for um tipo de ponteiro ou Integral, o tamanho do argumento é menor que ou igual a 8 bytes e o NGRN é menor do que 8, o argumento é copiado para os bits menos significativos em x [NGRN]. O NGRN é incrementado em um. O argumento foi alocado.

1. Se o argumento tem um alinhamento de 16, em seguida, o NGRN é arredondado para o próximo número par.

1. Se o argumento é um tipo Integral, o tamanho do argumento é igual a 16 e o NGRN é menor que 7, o argumento é copiado para x [NGRN] e x [NGRN + 1]. x [NGRN] deve conter a inferior endereçada palavra dupla da representação de memória do argumento. O NGRN é incrementado por dois. O argumento foi alocado.

1. Se o argumento for um tipo composto e o tamanho em palavras duplas do argumento não é maior que 8 menos NGRN, então o argumento é copiado para registros de uso geral consecutivos, começando em x [NGRN]. O argumento é passado como se tivesse sido carregada para os registros de um endereço alinhado à palavra dupla com uma sequência apropriada de LDR instruções carregar registros consecutivos de memória (o conteúdo de qualquer parte não utilizado dos registros é não especificado Por esse padrão). O NGRN é incrementado pelo número de registros usados. O argumento foi alocado.

1. O NGRN é definido como 8.

1. O NSAA é arredondado para o maior dos 8 ou o alinhamento Natural do tipo do argumento...

1. Se o argumento for um tipo composto, em seguida, o argumento é copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento foi alocado.

1. Se o tamanho do argumento for menor que 8 bytes, em seguida, o tamanho do argumento é definido como 8 bytes. O efeito é como se o argumento foi copiado para os bits menos significativos de um registro de 64 bits e os bits restantes preenchidos com valores não especificados.

1. O argumento é copiado para a memória no NSAA ajustado. O NSAA é incrementado pelo tamanho do argumento. O argumento foi alocado.

### <a name="addendum-variadic-functions"></a>Adendo: Funções Variadic

Funções que usam um número variável de argumentos são tratadas de maneira diferente acima, da seguinte maneira:

1. Todas as composições são tratadas parecidos; nenhum tratamento especial de HFAs ou HVAs.

1. SIMD e registra de ponto flutuante não serão usado.

Efetivamente, isso equivale a C.12–C.15 para alocar os argumentos para uma pilha imaginário, onde os primeiros 64 bytes da pilha são carregados no x7 x0 e quaisquer argumentos de pilha restantes são colocados normalmente regras a seguir.

## <a name="return-values"></a>Valores de retorno

Valores integrais são retornados em x0. Valores de ponto flutuante são retornados em s0/d0/v0 conforme apropriado.

Para retornar-por-valor que não pode ser passado por meio de registros, o chamador deverá reservar um bloco de memória de tamanho suficiente e o alinhamento para conter o resultado. O endereço do bloco de memória deverão ser passado como um argumento adicional para a função em x8 de tipo POD ou x0 (ou x1 se $ que isso é passado na x0) para o tipo não POD. O receptor pode modificar o bloco de memória de resultados a qualquer momento durante a execução da sub-rotina (não há nenhum requisito para o receptor preservar o valor armazenado no x8, mas para o endereço desse buffer, não com POD também deve ser retornado em x0 pelo receptor da chamada).

## <a name="stack"></a>Pilha

Seguindo a ABI Cllique ARM, a pilha deve permanecer 16 bytes alinhado em todos os momentos. AArch64 contém um recurso de hardware que gera o alinhamento de pilha falhas sempre que uma carga de SP relativo ou store é feita e SP é 16 bytes não alinhadas. Windows é executado com esse recurso habilitado em todos os momentos.

Funções que alocam 4 mil ou mais que vale a pena de pilha devem garantir que cada página antes da página final será tocada em ordem, não garantindo assim a nenhum código poderá "saltar sobre" as páginas de proteção que o Windows usa para expandir a pilha. Normalmente, isso é feito `__chkstk` auxiliar, que tem uma convenção de chamada personalizada que passa a alocação da pilha total dividida por 16 em x15.

## <a name="red-zone"></a>Zona vermelha

A área de 16 bytes imediatamente abaixo do ponteiro de pilha atual é reservada para uso pela análise e dinâmica de cenários de aplicação de patch. Isso permite que o código gerado cuidadosamente a ser inserido que armazena 2 registros em [sp, n º 16] e os usa temporariamente para propósitos arbitrários. O kernel do Windows garante que os 16 bytes não serão substituídos se uma exceção ou interrupção for obtida, no modo de usuário e kernel.

## <a name="kernel-stack"></a>Pilha de kernel

A pilha de modo de kernel padrão no Windows é seis páginas (24k). Preste atenção extra para funções com grandes buffers de pilha em modo kernel. Uma interrupção acidente poderia ocorrer com muito pouco espaço e crie uma verificação de bugs de pânico de pilha.

## <a name="stack-walking"></a>Passagem de pilha

O código dentro do Windows é compilado com ponteiros de quadro habilitados ([/Oy-](reference/oy-frame-pointer-omission.md)) para habilitar a passagem rápida de pilha. A conclusão de que isso é que x29 (fp) em geral aponta para o próximo link na cadeia, que é um {fp, lr} que indica o ponteiro para o quadro anterior na pilha e o endereço de retorno de par. Código de terceiros é incentivado habilitar ponteiros de quadros também para permitir aprimorada de criação de perfil e o rastreamento.

## <a name="exception-unwinding"></a>O desenrolamento de exceção

Desenrolamento durante o tratamento de exceção com a assistência com o uso de códigos de desenrolamento. Os códigos de desenrolamento são uma sequência de bytes armazenados na seção. XData do executável que descrevem a operação do prólogo e epílogo de maneira abstrata, de modo que os efeitos do prólogo da função possam ser desfeitos em preparação para fazer backup para o quadro de pilha do chamador. Para obter mais informações sobre os códigos de desenrolamento, consulte [tratamento de exceção ARM64](arm64-exception-handling.md).

A EABI do ARM Especifica também um modelo de desenrolamento de exceção que aproveita os códigos de desenrolamento. No entanto, a especificação como apresentado não é suficiente para desenrolamento no Windows, que devem manipular casos em que o computador está no meio do prólogo ou epílogo de uma função.

Código gerado dinamicamente deve ser descrito com tabelas de função dinâmico via `RtlAddFunctionTable` e funções associadas, para que o código gerado pode participar de manipulação de exceção.

## <a name="cycle-counter"></a>Contador de ciclo

Todas as CPUs ARMv8 são necessários para dar suporte a um ciclo de registro do contador. Isso é um registro de 64 bits que configura o Windows para serem legíveis em qualquer nível de exceção (incluindo o modo de usuário). Ele pode ser acessado por meio de PMCCNTR_EL0 especial se registrar usando o opcode MSR no código de assembly, ou o `_ReadStatusReg` intrínseco no código C/C++.

Observe que o contador de ciclo aqui é um verdadeiro contador de ciclo, não um relógio de parede e, portanto, a frequência de contagem variam de acordo com a frequência do processador. Se você achar que você deve saber a frequência do contador de ciclo, você não deverá usar o contador de ciclo. Em vez disso, você deseja medir a hora do relógio, em que você deve usar `QueryPerformanceCounter`.

## <a name="see-also"></a>Consulte também

[Problemas de migração ARM do Visual C++ comuns](common-visual-cpp-arm-migration-issues.md)<br/>
[Tratamento de exceção ARM64](arm64-exception-handling.md)
