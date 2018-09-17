---
title: Visão geral das convenções do ARM ABI | Microsoft Docs
ms.custom: ''
ms.date: 07/11/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 23f4ae8c-3148-4657-8c47-e933a9f387de
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: def07f92cc05828c132ba7d34d3dcc06d4aecf50
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45721442"
---
# <a name="overview-of-arm32-abi-conventions"></a>Visão geral das convenções ABI ARM32

A interface binária do aplicativo (ABI) de código compilado para Windows em processadores ARM é baseada na EABI padrão do ARM. Este artigo destaca diferenças chave entre Windows em ARM e o padrão. Este documento aborda a ABI ARM32. Para obter informações sobre a ABI ARM64, consulte [convenções de visão geral do ARM64 ABI](arm64-windows-abi-conventions.md). Para obter mais informações sobre a EABI padrão do ARM, consulte [Interface binária de aplicativo (ABI) para a arquitetura ARM](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.subset.swdev.abi/index.html) (link externo).

## <a name="base-requirements"></a>Requisitos Base

O Windows em ARM presume estar sendo executado em uma arquitetura ARMv7 continuamente. É necessário haver suporte a ponto flutuante na forma de VFPv3-D32 ou mais recente no hardware. O VFP deve suportar ponto flutuante de precisão única e de precisão dupla no hardware. O tempo de execução do Windows não suporta emulação de ponto flutuante para habilitar execução em hardware não VFP.

Suporte a Extensões Advanced SIMD (NEON)—isso inclui operações de ponto inteiro e flutuante—também deve estar presente no hardware. Não é fornecido suporte de tempo de execução para emulação.

Suporte a divisão de inteiros (UDIV/SDIV) é altamente recomendável mas não exigido. As plataformas sem suporte a divisão de inteiros podem incorrer uma penalidade de desempenho, pois essas operações devem ser capturadas e, possivelmente, atualizadas.

## <a name="endianness"></a>Endianness

O Windows em ARM é executado em modo little-endian. O compilador do Visual C++ e o tempo de execução do Windows sempre esperam dados little-endian. Apesar de a instrução SETEND na arquitetura do conjunto de instruções (ISA) do ARM permitir até mesmo código de modo de usuário para alterar a endianness atual, não é aconselhável fazer isso pois é perigoso para um aplicativo. Se uma exceção é gerada em modo big-endian, o comportamento é imprevisível e pode levar a uma falha do aplicativo em modo de usuário ou em uma verificação de erro em modo kernel.

## <a name="alignment"></a>Alinhamento

Apesar de o Windows habilitar o hardware ARM para manipular acessos inteiros desalinhados de maneira transparente, falhas de alinhamento ainda podem ser geradas em algumas situações. Segue essas regras de alinhamento:

- Cargas e armazenamentos inteiros com tamanho de meia palavra (16-bit) e de palavra inteira (32-bit) não precisam ser alinhados. O hardware os manipula de maneira eficiente e transparente.

- Cargas e armazenamentos de ponto flutuante devem ser alinhados. O kernel manipula cargas e armazenamentos não alinhados de maneira transparente, porém, com sobrecarga significativa.

- Operações Carregar ou armazenar duplo (LDRD/STRD) e múltiplo (LDM/STM) devem ser alinhadas. O kernel manipula a maioria delas de maneira transparente, porém, com sobrecarga significativa.

- Todos os acessos a memória não armazenada em cache devem ser alinhados, mesmo para acessos inteiros. Acessos desalinhados causam uma falha de alinhamento.

## <a name="instruction-set"></a>Conjunto de instruções

O conjunto de instruções para Windows em ARM é estritamente limitado a Thumb-2. Qualquer código executado nessa plataforma é sempre esperado começar e permanecer em modo Thumb. Uma tentativa de alternar para o conjunto de instruções herdado do ARM pode ser bem-sucedida, porém, qualquer exceção ou interrupção que ocorrer pode levar a uma falha do aplicativo em modo de usuário ou a uma verificação de erro em modo kernel.

Um efeito colateral desse requisito é que todos os ponteiros de código devem conter o conjunto de bits inferior. Isso ocorre para quando forem carregados e ramificados via BLX ou BX, o processador permanecerá em modo Thumb e não tentará executar o código de destino como instruções ARM de 32 bits.

### <a name="it-instructions"></a>Instruções de IT

O uso de Instruções de IT em código Thumb-2 não é permitido, exceto para esses casos específicos:

- A Instrução de IT pode ser usada apenas para modificar uma instrução de destino.

- A instrução de destino deve ser uma instrução de 16 bits.

- A instrução de destino deve ser uma das seguintes:

   |Opcodes de 16 bits|Classe|Restrições|
   |---------------------|-----------|------------------|
   |MOV, MVN|Mover|Rm != PC, Rd != PC|
   |LDR, LDR[S]B, LDR[S]H|Carregar da memória|Mas não formulários literais LDR|
   |STR, STRB, STRH|Armazenar na memória||
   |ADD, ADC, RSB, SBC, SUB|Somar ou subtrair|Mas não formulários ADD/SUB SP, SP, imm7<br /><br /> Rm != PC, Rdn != PC, Rdm != PC|
   |CMP, CMN|Comparar|Rm != PC, Rn != PC|
   |MUL|Multiplicar||
   |ASR, LSL, LSR, ROR|Deslocamento de bits||
   |AND, BIC, EOR, ORR, TST|Aritmética de bits||
   |BX|Ramificar para registrar|Rm != PC|

Apesar de CPUs ARMv7 atuais não poderem relatar o uso de formulários de instrução não permitidos, é esperado que as gerações futuras poderão. Se esses formulários forem detectados, qualquer programa que os utilizam podem ser fechados com uma exceção de instrução indefinida.

### <a name="sdivudiv-instructions"></a>Instruções SDIV/udiv

O uso de instruções de divisão de inteiros SDIV e UDIV tem suporte total, mesmo em plataformas sem hardware nativo para manipulá-las. A divisão de sobrecarga por SDIV ou UDIV em um processador Cortex-A9 é de aproximadamente 80 ciclos, além do tempo de divisão geral de 20-250 ciclos, dependendo das entradas.

## <a name="integer-registers"></a>Registros de inteiros

O processador ARM oferece suporte a 16 registros inteiros:

|Registro|Volátil?|Função|
|--------------|---------------|----------|
|r0|Volátil|Parâmetro, resultado, registro de rascunho 1|
|r1|Volátil|Parâmetro, resultado, registro de rascunho 2|
|r2|Volátil|Parâmetro, registro de rascunho 3|
|r3|Volátil|Parâmetro, registro de rascunho 4|
|r4|Não volátil||
|r5|Não volátil||
|r6|Não volátil||
|r7|Não volátil||
|r8|Não volátil||
|r9|Não volátil||
|r10|Não volátil||
|r11|Não volátil|Ponteiro de quadro|
|r12|Volátil|Registro de rascunho de chamada dentro do procedimento|
|r13 (SP)|Não volátil|Ponteiro de pilha|
|r14 (LR)|Não volátil|Registro de link|
|r15 (PC)|Não volátil|Contador de programa|

Para obter detalhes sobre como usar o parâmetro e os registros de valores retornados, consulte a seção Passagem de Parâmetro neste artigo.

O Windows usa r11 para passagem rápida do quadro de pilha. Para obter mais informações, consulte a seção Passagem de Pilha. Devido a esse requisito, o r11 sempre deve apontar para o link superior na cadeia. Não use r11 para propósitos gerais—o código não gerará passagens de pilha corretas durante a análise.

## <a name="vfp-registers"></a>Registros VFP

O Windows tem suporte apenas a variações de ARM com suporte no coprocessador VFPv3-D32. Isso significa que registros de ponto flutuante estão sempre presentes e podem ser considerados para passagem de parâmetro e que o conjunto inteiro de 32 registros está disponível para uso. Os registros VFP e seu uso são resumidos nesta tabela:

|Únicos|Duplos|Quads|Volátil?|Função|
|-------------|-------------|-----------|---------------|----------|
|s0-s3|d0-d1|q0|Volátil|Parâmetros, resultado, registro de rascunho|
|s4-s7|d2-d3|q1|Volátil|Parâmetros, registro de rascunho|
|s8-s11|d4-d5|q2|Volátil|Parâmetros, registro de rascunho|
|s12-s15|d6-d7|q3|Volátil|Parâmetros, registro de rascunho|
|s16-s19|d8-d9|q4|Não volátil||
|s20-s23|d10-d11|q5|Não volátil||
|s24-s27|d12-d13|q6|Não volátil||
|s28-s31|d14-d15|q7|Não volátil||
||d16-d31|q8-q15|Volátil||

A próxima tabela ilustra os campos de status do ponto flutuante e do registro de controle (FPSCR):

|Bits|Significado|Volátil?|Função|
|----------|-------------|---------------|----------|
|31-28|NZCV|Volátil|Sinalizadores de status|
|27|QC|Volátil|Saturação cumulativa|
|26|AHP|Não volátil|Controle de meia precisão alternativo|
|25|DN|Não volátil|Controle de modo NaN padrão|
|24|FZ|Não volátil|Controle de modo Flush-to-zero|
|23-22|RMode|Não volátil|Controle de modo de arredondamento|
|21-20|Passo|Não volátil|Passo do Vetor, deve ser sempre 0|
|18-16|Len|Não volátil|Comprimento do Vetor, deve ser sempre 0|
|15, 12-8|IDE, IXE etc.|Não volátil|Bits de habilitação de captura de exceção, deve ser sempre 0|
|7, 4-0|IDC, IXC etc.|Volátil|Sinalizadores de exceção cumulativa|

## <a name="floating-point-exceptions"></a>Exceções de ponto flutuante

A maior parte do hardware ARM não suporta exceções de ponto flutuante IEEE. Em variações de processador que não contêm exceções de ponto flutuante de hardware, o kernel do Windows silenciosamente captura as exceções e implicitamente as desabilita no registro de FPSCR. Isso garante comportamento normalizado entre variações do processador. Caso contrário, código desenvolvido em uma plataforma que não possui suporte de exceção pode receber exceções inesperadas quando estiver executando em uma plataforma com suporte de exceção.

## <a name="parameter-passing"></a>Passagem de parâmetro

Para funções não variadic, a ABI do Windows em ARM segue as regras do ARM para passagem de parâmetro—isso inclui as extensões VFP e Advanced SIMD. Essas regras seguem a [procedimento padrão de chamada para a arquitetura ARM](http://infocenter.arm.com/help/topic/com.arm.doc.ihi0042c/IHI0042C_aapcs.pdf)consolidado com as extensões VFP. Por padrão, os primeiros quatro argumentos inteiros e até oito argumentos de ponto flutuante ou vetor são passados em registros e argumentos adicionais são passados na pilha. Argumentos são atribuídos a registros ou à pilha usando este procedimento:

### <a name="stage-a-initialization"></a>R: inicialização do estágio

A inicialização é realizada exatamente uma vez, antes do início do processamento do argumento:

1. O Próximo Número de Registro Principal (NCRN) é definido para r0.

2. Os registros VFP são marcados como não alocados.

3. O Próximo Endereço de Argumento Empilhado (NSAA) é definido para o SP atual.

4. Se uma função que retorna um resultado na memória for chamada, o endereço do resultado é colocado em r0 e o NCRN é definido para r1.

### <a name="stage-b-pre-padding-and-extension-of-arguments"></a>Estágio b: pré-enchimento e extensão dos argumentos

Para cada argumento na lista, a primeira regra correspondente da seguinte lista é aplicada:

1. Se o argumento for um tipo composto cujo tamanho não pode ser determinado estaticamente pelo chamador e pelo receptor, o argumento é copiado para a memória e substituído por um ponteiro para a cópia.

2. Se o argumento for um byte ou uma meia palavra de 16 bits, será estendido em zero ou estendido em sinal para uma palavra inteira de 32 bits e tratado como um argumento de 4 bytes.

3. Se o argumento for um tipo composto, seu tamanho é arredondado para cima para o próximo múltiplo de 4.

### <a name="stage-c-assignment-of-arguments-to-registers-and-stack"></a>Estágio c: atribuição de argumentos a registros e à pilha

Para cada argumento na lista, as seguintes regras são aplicadas em turnos até o argumento ser alocado:

1. Se o argumento for um tipo VFP e não houver registros VFP consecutivos não alocados suficientes do tipo adequado, o argumento será alocado para a sequência com menor número de tais registros.

2. Se o argumento for um tipo VFP, todos os registros não alocados restantes serão marcados como não disponíveis. O NSAA é ajustado para cima até ser alinhado corretamente com o tipo de argumento e o argumento ser copiado para a pilha no NSAA ajustado. Em seguida, o NSAA é incrementado pelo tamanho do argumento.

3. Se o argumento exige alinhamento de 8 bytes, o NCRN é arredondado para cima para o próximo número de registro par.

4. Se o tamanho do argumento em palavras de 32 bits não for maior que r4 menos o NCRN, o argumento será copiado nos registros principais, começando no NCRN, com os bits menos significativos ocupando os registros de números inferiores. O NCRN é incrementado pelo número de registros usados.

5. Se o NCRN for menor que r4 e o NSAA for igual ao SP, o argumento será dividido entre registros principais e a pilha. A primeira parte do argumento é copiado para os registros principais, começando no NCRN até e incluindo o r3. O lembrete do argumento é copiado para a pilha, começando no NSAA. O NCRN é definido para r4 e o NSAA é incrementado pelo tamanho do argumento menos a quantidade passada em registros.

6. Se o argumento exige alinhamento de 8 bytes, o NSAA é arredondado para cima para o próximo endereço de 8 bytes alinhado.

7. O argumento é copiado para a memória no NSAA. O NSAA é incrementado pelo tamanho do argumento.

Os registros VFP não são usados para funções variadic e as regras 1 e 2 do Estágio C são ignoradas. Isso significa que uma função variadic pode começar com um push adicional {r0-r3} para preceder os argumentos do registro a qualquer argumento adicional passado pelo chamador e acessar a lista de argumentos inteira diretamente da pilha.

Valores de tipo inteiro são retornados em r0, opcionalmente estendidos para r1 para valores retornados de 64 bits. Valores de tipo SIMD ou ponto flutuante VFP/NEON são retornados em s0, d0 ou q0 conforme adequado.

## <a name="stack"></a>Pilha

A pilha deve permanecer sempre alinhada a 4 bytes e deve se alinhada a 8 bytes em qualquer limite de função. Isso é necessário para suportar o uso frequente de operações sincronizadas em variáveis de pilha de 64 bits. A EABI do ARM declara que a pilha é alinhada a 8 bytes em qualquer interface pública. Para consistência, a ABI do Windows em ARM considera qualquer limite de função como uma interface pública.

Funções que devem usar um ponteiro de quadro—por exemplo, funções que chamam `alloca` ou alteram o ponteiro de pilha dinamicamente—devem manter o ponteiro de quadro em r11 no prólogo da função e deixá-lo inalterado até o epílogo. Funções que não exigem um ponteiro de quadro devem realizar todas as atualizações de pilha no prólogo e deixar o ponteiro de pilha inalterado até o epílogo.

Funções que alocam 4 KB ou mais na pilha devem garantir que cada página antes da página final será tocada em ordem. Isso garante que nenhum código poderá “saltar sobre” as páginas de proteção que o Windows usa para expandir a pilha. Geralmente, isso é feito pelo auxiliar de `__chkstk`, para o qual é passado a alocação de pilha total em bytes dividida por 4 em r4, e que retorna a quantidade final de alocação de pilha em bytes de volta em r4.

### <a name="red-zone"></a>Zona vermelha

A área de 8 bytes imediatamente abaixo do ponteiro de pilha atual é reservada para análise e atualização dinâmica. Isso permite inserir código gerado cuidadosamente, que armazena 2 registros em [sp, #-8] e os usa temporariamente para propósitos arbitrários. O kernel do Windows garante que esses 8 bytes não serão sobrescritos ao ocorrer uma exceção ou interrupção no modo de usuário e no modo kernel.

### <a name="kernel-stack"></a>Pilha de kernel

A pilha padrão de modo kernel no Windows é de três páginas (12 KB). Tenha cuidado para não criar funções que possuem grandes buffers de pilha em modo kernel. Uma interrupção pode ocorrer com muito pouco espaço de pilha e causar uma verificação de erros de pânico de pilha.

## <a name="cc-specifics"></a>Especificações C/C++

Enumerações são tipos inteiros de 32 bits, exceto quando ao menos um valor na enumeração exigir armazenamento de palavra dupla de 64 bits. Nesse caso, a enumeração é promovida para um tipo inteiro de 64 bits.

`wchar_t` é definido como equivalente a `unsigned short`, para preservar a compatibilidade com outras plataformas.

## <a name="stack-walking"></a>Passagem de pilha

O código do Windows é compilado com ponteiros de quadro habilitados ([/Oy (omissão do ponteiro de quadro)](../build/reference/oy-frame-pointer-omission.md)) para habilitar a passagem rápida de pilha. Geralmente, o registro r11 aponta para o próximo link na cadeia, que é um par {r11, lr} que especifica o ponteiro para o quadro anterior na pilha e o endereço de retorno. Também é recomendável habilitar ponteiros de quadro no código para criação de perfis e rastreamento melhorados.

## <a name="exception-unwinding"></a>O desenrolamento de exceção

O desenrolamento de pilha durante manipulação de exceções é habilitado pelo uso de códigos de desenrolamento. Os códigos de desenrolamento são uma sequência de bytes armazenada na seção .xdata da imagem executável. Descrevem a operação do código de prólogo e epílogo da função de maneira abstrata, de modo que os efeitos do prólogo de uma função podem ser desfeitos em preparação para desenrolamento para o quadro de pilha do chamador.

A EABI do ARM especifica um modelo de desenrolamento de exceção que usa códigos de desenrolamento. No entanto, essa especificação não é suficiente para desenrolamento no Windows, que deve manipular casos em que o processador está no meio do prólogo ou epílogo de uma função. Para obter mais informações sobre o Windows sobre desenrolamento e dados de exceção do ARM, consulte [tratamento de exceção ARM](../build/arm-exception-handling.md).

É recomendável descrever o código gerado dinamicamente usando tabelas de função dinâmica especificadas em chamas para `RtlAddFunctionTable` e funções associadas, para o código gerado poder participar da manipulação de exceções.

## <a name="cycle-counter"></a>Contador de ciclo

Processadores ARM executando Windows devem suportar um contador de ciclo, porém, usar o contador diretamente pode causar problemas. Para evitar esses problemas, o Windows em ARM usa um opcode indefinido para solicitar um valor de contador de ciclo de 64 bits normalizado. A partir de C ou C++, use a intrínseca `__rdpmccntr64` para emitir o opcode adequada; a partir de assembly, use a instrução `__rdpmccntr64`. A leitura do contador de ciclo leva aproximadamente 60 ciclos em um Cortex-A9.

O contador é um verdadeiro contador de ciclo, não um relógio; portanto, a frequência de contagem varia com a frequência do processador. Se desejar medir o tempo de relógio decorrido, use `QueryPerformanceCounter`.

## <a name="see-also"></a>Consulte também

[Problemas de migração ARM do Visual C++ comuns](../build/common-visual-cpp-arm-migration-issues.md)<br/>
[Tratamento de exceção do ARM](../build/arm-exception-handling.md)
