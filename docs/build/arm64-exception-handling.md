---
title: Tratamento de exceção ARM64 | Microsoft Docs
ms.custom: ''
ms.date: 07/11/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7e24997fa2eb6e6e5c3d8438b137e168c2f70b1f
ms.sourcegitcommit: 9ad287c88bdccee2747832659fe50c2e5d682a0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39034732"
---
# <a name="arm64-exception-handling"></a>Tratamento de exceção ARM64

O Windows arm64 usa a mesma mecanismo para exceções geradas por hardware assíncronas e exceções geradas por software síncronas de tratamento de exceções de estruturado. Os manipuladores de exceção específicos da linguagem são compilados sobre o tratamento de exceção estruturado do Windows usando funções de auxiliares da linguagem. Este documento descreve o tratamento de exceção no Windows em ARM64 e os auxiliares da linguagem usados pelo código que é gerado pelo assembler Microsoft ARM e o compilador do Visual C++.

## <a name="goals-and-motivation"></a>Metas e motivação

As convenções de dados de desenrolamento de exceção e essa descrição destinam-se a:

1. Forneça suficiente descrição para permitir o desenrolar sem código de investigação em todos os casos.

   - Analisando o código exige que o código a ser paginada. Isso impede que o desenrolamento em algumas circunstâncias em que é útil (rastreamento, de amostragem, depuração).

   - Analisando o código é complexo; o compilador deve ter cuidado para gerar somente instruções que o desenrolador é capaz de decodificar.

   - Se o desenrolamento não pode ser completamente descrito com o uso de códigos de desenrolamento, em seguida, em alguns casos ele deve voltar para decodificação de instrução. Isso aumenta a complexidade geral e o ideal é que deve ser evitado.

2. Suporte de desenrolamento no prólogo intermediário e de epílogo intermediário.

   - Desenrolamento é usado no Windows por mais de manipulação de exceção, portanto, é essencial que é ser capaz de realizar uma lista exata de desenrolamento até mesmo quando no meio de uma sequência de código de prólogo ou epílogo.

3. Levar uma quantidade mínima de espaço.

   - Os códigos de desenrolamento não devem agregar para aumentar significativamente o tamanho do binário.

   - Como os códigos de desenrolamento são provavelmente a ser bloqueadas na memória, uma superfície pequena garante uma sobrecarga mínima para cada binário carregado.

## <a name="assumptions"></a>Suposições

Estas são as suposições feitas no descrição de tratamento de exceção:

1. Prólogos e epílogos tendem a refletir qualquer um dos outros. Ao aproveitando as vantagens dessa característica comum, o tamanho dos metadados necessários para descrever o desenrolamento pode ser reduzido significativamente. Dentro do corpo da função, não importa se a operações do prólogo são desfeitas ou operações do epílogo são executadas de uma maneira direta. Ambas devem produzir resultados idênticos.

2. Funções em todo o tendem a ser relativamente pequeno. Várias otimizações para espaço contam com isso para alcançar a compactação de dados mais eficiente.

3. Não há nenhum código condicional em epílogos.

4. Dedicada de registro de ponteiro de quadro: se o sp seja salvo em outro registro (r29) no prólogo, que registra permanece inalterado durante todo a função, para que o sp original possa ser recuperado a qualquer momento.

5. A menos que o sp seja salvo em outro registro, toda a manipulação do ponteiro de pilha ocorre estritamente dentro do prólogo e epílogo.

6. O layout do quadro de pilha é organizado, conforme descrito na próxima seção.

## <a name="arm64-stack-frame-layout"></a>Layout de quadro de pilha ARM64

![layout de quadro de pilha](../build/media/arm64-exception-handling-stack-frame.png "layout de quadro de pilha")

Para funções de quadro encadeada, o par de fp e lr pode ser salvos em qualquer posição na área de variável local, dependendo das considerações de otimização. O objetivo é maximizar o número de locais que podem ser alcançadas por uma instrução única, com base em ponteiro de quadro (r29) ou o ponteiro de pilha (sp). No entanto para `alloca` funções, ele deve ser encadeado e r29 deve apontar para a parte inferior da pilha. Para permitir melhor cobertura de register-par-endereçamento-mode, não-volátil registrar aave áreas são posicionadas na parte superior da pilha de rede Local. Aqui estão exemplos que ilustram algumas das sequências de prólogo mais eficientes. Para fins de clareza e melhor localidade de cache, a ordem de armazenamento de registros salvos pelo receptor em todos os Prólogos canônicos é em ordem "cada vez maior para cima". `#framesz` abaixo representa o tamanho da pilha inteira (excluindo alloca área). `#localsz` e `#outsz` indicam o tamanho da área local (incluindo o salvamento área para o \<r29, lr > par) e o tamanho do parâmetro de saída, respectivamente.

1. Encadeadas, #localsz < = 512

    ```asm
        stp    r19,r20,[sp,-96]!        // pre-indexed, save in 1st FP/INT pair
        stp    d8,d9,[sp,16]            // save in FP regs (optional)
        stp    r0,r1,[sp,32]            // home params (optional)
        stp    r2,r3,[sp, 48]
        stp    r4,r5,[sp,64]
        stp    r6,r7,[sp,72]
        stp    r29, lr, [sp, -#localsz]!    // save <r29,lr> at bottom of local area
        mov    r29,sp                   // r29 points to bottom of local
        sub    sp, #outsz               // (optional for #outsz != 0)
    ```

2. Encadeadas, #localsz > 512

    ```asm
        stp    r19,r20,[sp,-96]!        // pre-indexed, save in 1st FP/INT pair
        stp    d8,d9,[sp,16]            // save in FP regs (optional)
        stp    r0,r1,[sp,32]            // home params (optional)
        stp    r2,r3,[sp, 48]
        stp    r4,r5,[sp,64]
        stp    r6,r7,[sp,72]
        sub    sp,#localsz+#outsz       // allocate remaining frame
        stp    r29, lr, [sp, #outsz]    // save <r29,lr> at bottom of local area
        add    r29,sp, #outsz           // setup r29 points to bottom of local area
    ```

3. Sem cadeia, funções de folha (lr não salva)

    ```asm
        stp    r19,r20,[sp, -72]!       // pre-indexed, save in 1st FP/INT reg-pair
        stp    r21,r22,[sp, 16]
        str    r23 [sp,32]
        stp    d8,d9,[sp,40]            // save FP regs (optional)
        stp    d10,d11,[sp,56]
        sub    sp,#framesz-72           // allocate the remaining local area
    ```

   Todos os locais são acessados com base no SP. \<r29, lr > aponta para o quadro anterior. Para o tamanho do quadro < = 512, o "sub sp,..." pode ser otimizada se a área regs salvadas é movida para a parte inferior da pilha. A desvantagem de que é que ele não é consistente com outros layouts acima e salvos regs fazem parte de um intervalo para regs par e o modo de endereçamento deslocamento pré e pós-indexado.

4. Funções sem cadeia, não-folha (lr é salvo na área de Int salvada)

    ```asm
        stp    r19,r20,[sp,-80]!        // pre-indexed, save in 1st FP/INT reg-pair
        stp    r21,r22,[sp,16]          // ...
        stp    r23, lr,[sp, 32]         // save last Int reg and lr
        stp    d8,d9,[sp, 48]           // save FP reg-pair (optional)
        stp    d10,d11,[sp,64]          // ...
        sub    sp,#framesz-80           // allocate the remaining local area
    ```

   Ou, com um número par de registros de Int, salvos

    ```asm
        stp    r19,r20,[sp,-72]!        // pre-indexed, save in 1st FP/INT reg-pair
        stp    r21,r22,[sp,16]          // ...
        str    lr,[sp, 32]              // save lr
        stp    d8,d9,[sp, 40]           // save FP reg-pair (optional)
        stp    d10,d11,[sp,56]          // ...
        sub    sp,#framesz-72           // allocate the remaining local area
    ```

    Somente r19 salvadas:

    ```asm
        sub    sp, sp, #16              // reg save area allocation*
        stp    r19,lr,[sp,0]            // save r19, lr
        sub    sp,#framesz-16           // allocate the remaining local area
    ```

   \* O reg alocação de área de salvamento não será dobrado em stp porque um stp reg-lr previamente indexada não pode ser representado com os códigos de desenrolamento.

   Todos os locais são acessados com base no SP. \<r29 > aponta para o quadro anterior.

5. Encadeadas, #framesz < = 512, #outsz = 0

    ```asm
        stp    r29, lr, [sp, -#framesz]!    // pre-indexed, save <r29,lr>
        mov    r29,sp                       // r29 points to bottom of stack
        stp    r19,r20,[sp, #framesz -32]   // save INT pair
        stp    d8,d9,[sp, #framesz -16]     // save FP pair
    ```

   Em comparação à prólogo de #1 acima, a vantagem é que registrar todas as instruções de salvamento está pronto para ser executado logo após a pilha de apenas uma instrução de alocação. Portanto, não há nenhuma antino dependência de sp que impede o paralelismo de nível de instrução.

6. Encadeadas, tamanho do quadro > 512 (opcional para funções sem alloca)

    ```asm
        stp    r29, lr, [sp, -80]!          // pre-indexed, save <r29,lr>
        stp    r19,r20,[sp,16]              // save in INT regs
        stp    r21,r22,[sp,32]              // ...
        stp    d8,d9,[sp,48]                // save in FP regs
        stp    d10,d11,[sp,64]
        mov    r29,sp                       // r29 points to top of local area
        sub    sp,#framesz-80               // allocate the remaining local area
    ```

   Para fins de otimização, r29 pode ser colocado em qualquer posição em uma rede local para fornecer uma melhor cobertura para "reg par" e pré/pós-indexed deslocamento de modo de endereçamento. Locais abaixo ponteiros de quadro podem ser acessados com base no SP.

7. Encadeadas, tamanho do quadro > 4K, com ou sem alloca(),

    ```asm
        stp    r29, lr, [sp, -80]!          // pre-indexed, save <r29,lr>
        stp    r19,r20,[sp,16]              // save in INT regs
        stp    r21,r22,[sp,32]              // ...
        stp    d8,d9,[sp,48]                // save in FP regs
        stp    d10,d11,[sp,64]
        mov    r29,sp                       // r29 points to top of local area
        mov    r8, #framesz/16
        bl     chkstk
        sub    sp, r8*16                    // allocate remaining frame
                                            // end of prolog
        ...
        sp = alloca                         // more alloca() in body
        ...
                                            // beginning of epilog
        mov    sp,r29                       // sp points to top of local area
        ldp    d10,d11, [sp,64],
        ...
        ldp    r29, lr, [sp], -80           // post-indexed, reload <r29,lr>
    ```

## <a name="arm64-exception-handling-information"></a>Informações de tratamento de exceção ARM64

### <a name="pdata-records"></a>registros. pData

Os registros. pData são uma matriz ordenada de itens de comprimento fixo que descrevem todas as funções de manipulação de pilha em um PE binário. Observe atentamente a frase "manipulação de pilha": funções de folha que não requerem nenhum armazenamento local e que não é preciso salvar/Restaurar registros não voláteis não exigem um registro. pData; eles devem ser explicitamente omitidos para economizar espaço. Um desenrolamento de uma dessas funções pode simplesmente obter o endereço de retorno de LR para mover para cima para o chamador.

Cada registro. pData para ARM64 tem 8 bytes de comprimento. O formato geral de cada registro locais o RVA de 32 bits da função de início da primeira palavra, seguido por um segundo com que contém um ponteiro para um bloco. XData de comprimento variável ou uma palavra compactada que descreve uma sequência de desenrolamento de função canônica.

![layout de registro. pData](../build/media/arm64-exception-handling-pdata-record.png "layout de registro. pData")

Os campos são da seguinte maneira:

- **Função RVA iniciar** é o RVA de 32 bits do início da função.

- **Sinalizador** é um campo de 2 bits que indica como interpretar os 30 bits restantes da segunda palavra. pData. Se **sinalizador** for 0, então os bits restantes formam um **RVA de informações de exceção** (com os dois bits baixos sendo implicitamente 0). Se **sinalizador** for diferente de zero, em seguida, os bits restantes formam um **dados de desenrolamento compactados** estrutura.

- **RVA de informações de exceção** é o endereço da estrutura de informações de exceção de comprimento variável, armazenado na seção. XData. Esses dados devem ser alinhados para 4 bytes.

- **Empacotadas desenrolar dados** é a descrição compactada das operações necessárias para desenrolar a partir de uma função, supondo uma forma canônica. Nesse caso, nenhum registro .xdata é necessário.

### <a name="xdata-records"></a>registros. XData

Quando o formato de desenrolamento compactado for insuficiente para descrever o desenrolamento de uma função, um registro .xdata de comprimento variável deverá ser criado. O endereço desse registro é armazenado na segunda palavra do registro .pdata. O formato do. XData é um conjunto de comprimento variável compactado de palavras:

![layout de registro. XData](../build/media/arm64-exception-handling-xdata-record.png "layout de registro. XData")

Esses dados são divididos em quatro seções:

1. Um 1 ou 2 palavras cabeçalho que descreve o tamanho geral da estrutura e fornecer dados de função-chave. O segundo word só estará presente se os dois os **contagem de epílogo** e **palavras de código** campos são definidos como 0. Esses são os campos de bit no cabeçalho:

   a. **Função comprimento** é um campo de 18 bits que indica o comprimento total da função em bytes dividido por 4. Se uma função for maior que 1 milhão, vários registros de pdata e xdata devem ser usados para descrever a função. Consulte a [funções grandes](#large-functions) seção para obter mais detalhes.

   b. **Vers** é um campo de 2 bits que descreve a versão dos xdata restantes. A partir da redação deste artigo, apenas a versão 0 é definida e, portanto, não são permitidos valores de 1 a 3.

   c. **X** é um campo de 1 bit que indica a presença (1) ou a ausência (0) de dados de exceção.

   d. **E** é um campo de bits que indica que as informações que descrevem um único epílogo é compactado no cabeçalho (1) em vez de exigir o escopo adicional palavras posterior (0).

   e. **Contagem de epílogo** é um campo de 5 bits que tem dois significados, dependendo do estado do **eletrônico** bit:

      1. Se **eletrônico** é definido como 0: Especifica a contagem do número total de escopos de exceção descrita na seção 2. Se mais de 31 escopos existirem na função, em seguida, a **palavras código** campo deve ser definido como 0 para indicar que uma palavra de extensão é necessária.

      2. Se **eletrônico** é definido como 1, em seguida, este campo especifica o índice do primeiro código de desenrolamento que descreve um e apenas epílogo.

   f. **Palavras de código** é um campo de 5 bits que especifica o número de palavras de 32 bits necessários para conter todos os códigos de desenrolamento na seção 4. Se mais de 31 palavras forem necessárias (ou seja, mais de 124 desenrolar bytes de código), em seguida, esse campo deve ser definido como 0 para indicar que uma palavra de extensão é necessária.

   g. **Estendido a contagem de epílogo** e **palavras de código estendido** são campos de 8 e 16 bits, respectivamente, que fornecem mais espaço para codificação de um número excepcionalmente grande de epílogos ou um número excepcionalmente grande de palavras de código de desenrolamento. A palavra de extensão que contém esses campos só estará presente se os dois os **contagem de epílogo** e **código palavras** campos da primeira palavra do cabeçalho são definidos como 0.

2. Depois que os dados de exceção, se **contagem de epílogo** não é zero, é uma lista de informações sobre escopos de epílogo, compactados um para uma palavra e armazenados em ordem crescente de deslocamento inicial. Cada escopo contém os bits do seguintes:

   a. **Deslocamento de início do epílogo** é um campo de 18 bits que descreve o deslocamento em bytes dividido por 4 de epílogo em relação ao início da função

   b. **Res** é um campo de 4 bits reservado para expansão futura. Seu valor deve ser 0.

   c. **Índice de início do epílogo** é um pouco de 10 (2 bits mais que **palavras de código estendido**) campo indicando o índice de bytes do primeiro código que descreve este epílogo de desenrolamento.

3. Depois que a lista de escopos de epílogo trata de uma matriz de bytes que contêm códigos de desenrolamento, descritos em detalhes em uma seção posterior. Essa matriz é preenchida no final, o mais próximo possível do limite da palavra completa. Os bytes são armazenados em ordem little-endian para que possam ser buscados diretamente no modo little-endian.

4. Por fim, após os bytes de código de desenrolamento (e, se o **X** bit no cabeçalho foi definido como 1) é fornecido as informações do manipulador de exceção. Isso consiste em uma única **RVA de manipulador de exceção** fornecendo o endereço do manipulador de exceção em si, seguido imediatamente por uma quantidade de comprimento variável de dados necessários para o manipulador de exceção.

O registro. XData acima foi projetado, que é possível buscar os primeiros 8 bytes e do que calcular o tamanho total do registro (menos o comprimento dos dados de exceção de tamanho variável que segue). O trecho de código a seguir calcula o tamanho do registro:

```cpp
ULONG ComputeXdataSize(PULONG *Xdata)
{
    ULONG EpilogScopes;
    ULONG Size;
    ULONG UnwindWords;

    if ((Xdata[0] >> 27) != 0) {
        Size = 4;
        EpilogScopes = (Xdata[0] >> 22) & 0x1f;
        UnwindWords = (Xdata[0] >> 27) & 0x0f;
    } else {
        Size = 8;
        EpilogScopes = Xdata[1] & 0xffff;
        UnwindWords = (Xdata[1] >> 16) & 0xff;
    }

    Size += 4 * EpilogScopes;
    Size += 4 * UnwindWords;
    if (Xdata[0] & (1 << 20)) {
        Size += 4;        // exception handler RVA
    }
    return Size;
}
```

É importante observar que embora o prólogo e cada epílogo tem seu próprio índice nos códigos de desenrolamento, a tabela é compartilhada entre eles, e é totalmente possível (e não totalmente incomum) que eles possam todos compartilhar os mesmos códigos (consulte o exemplo 2 no Apêndice A, abaixo). Gravadores de compilador devem otimizar para esse caso em particular porque o maior índice que pode ser especificado é 255, limitando o número total de códigos de desenrolamento para uma função específica.

### <a name="unwind-codes"></a>Códigos de desenrolamento

A matriz de códigos de desenrolamento é o pool de sequências que descrevem exatamente como desfazer os efeitos do prólogo, na ordem em que as operações precisam ser desfeita. Os códigos de desenrolamento podem ser pensados como um conjunto de miniconjunto de instruções, codificado como uma cadeia de caracteres de bytes. Quando a execução for concluída, o endereço de retorno para a função de chamada está no registro lr e todos os registros não voláteis são restaurados para os valores no momento em que a função foi chamada.

Se fosse garantido que exceções ocorressem sempre somente dentro de um corpo de função (e nunca com um prólogo ou de qualquer epílogo), apenas uma única sequência seria necessária. No entanto, o modelo de desenrolamento do Windows requer que podemos conseguir desenrolar de dentro de um executado parcialmente prólogo ou epílogo. Para acomodar esse requisito, os códigos de desenrolamento foram projetados cuidadosamente, de modo que eles são mapeados sem ambiguidade 1:1 para cada opcode relevante no prólogo e epílogo. Isso tem várias implicações:

1. Contando o número de códigos de desenrolamento, é possível calcular o comprimento do prólogo e epílogo.

2. Contando o número de instruções passadas no início de um escopo de epílogo, é possível ignorar o número equivalente de códigos de desenrolamento e executar o restante de uma sequência para concluir o executado parcialmente que o epílogo estava executando de desenrolamento.

3. Contando o número de instruções antes do final do prólogo, é possível ignorar o número equivalente de códigos de desenrolamento e executar o restante da sequência para desfazer apenas aquelas partes do prólogo que concluíram a execução.

Os códigos de desenrolamento são codificados de acordo com a tabela a seguir. Todos os códigos de desenrolamento são uma única/de dois bytes, exceto aquele que aloca uma pilha enorme. Há totalmente 21 código de desenrolamento. Cada desenrolamento código mapas exatamente uma instrução no prólogo/epílogo para permitir o desenrolar da executado parcialmente Prólogos e epílogos.

Código de desenrolamento|Bits e a interpretação
|-|-|
`alloc_s`|000xxxxx: alocar pequena pilha com tamanho < 512 (2 ^ 5 * 16).
`save_r19r20_x`|    001zzzzz: salvar \<r19, r20 > par na [Z de sp-# * 8]!, deslocamento previamente indexado > =-248
`save_fplr`|        01zzzzzz: salvar \<r29, lr > emparelhar em [sp + #Z * 8], deslocamento < = 504.
`save_fplr_x`|        10zzzzzz: salvar \<r29, lr > emparelhar em [sp-(#Z + 1) * 8]!, deslocamento previamente indexado > = -512
`alloc_m`|        11000xxx\|xxxxxxxx: alocar pilha grande com tamanho < 16K (2 ^ 11 * 16).
`save_regp`|        110010xx\|xxzzzzzz: salvar r(19+#X) par em [sp + #Z * 8], deslocamento < = 504
`save_regp_x`|        110011xx\|xxzzzzzz: salvar r(19+#X) par em [sp-(#Z + 1) * 8]!, deslocamento previamente indexado > = -512
`save_reg`|        110100xx\|xxzzzzzz: salvar r(19+#X) reg em [sp + #Z * 8], deslocamento < = 504
`save_reg_x`|        x 1101010\|xxxzzzzz: salvar r(19+#X) reg em [sp-(#Z + 1) * 8]!, deslocamento previamente indexado > = -256
`save_lrpair`|         x 1101011\|xxzzzzzz: salvar par \<r19 + 2 *#x10, lr > em [sp + #Z*8], deslocamento < = 504
`save_fregp`|        x 1101100\|xxzzzzzz: salvar d(8+#X) par em [sp + #Z * 8], deslocamento < = 504
`save_fregp_x`|        x 1101101\|xxzzzzzz: salvar d(8+#X) par, em [sp-(#Z + 1) * 8]!, deslocamento previamente indexado > = -512
`save_freg`|        x 1101110\|xxzzzzzz: salvar d(8+#X) reg em [sp + #Z * 8], deslocamento < = 504
`save_freg_x`|        11011110\|xxxzzzzz: salvar d(8+#X) reg em [sp-(#Z + 1) * 8]!, deslocamento previamente indexado > = -256
`alloc_l`|         11100000\|xxxxxxxx\|xxxxxxxx\|xxxxxxxx: alocar pilha grande com tamanho de M < 256 (2 ^ 24 * 16)
`set_fp`|        11100001: configurar r29: com: r29 mov, sp
`add_fp`|        11100010\|xxxxxxxx: configurar r29 com: Adicionar r29, sp, #x10 * 8
`nop`|            11100011: nenhum desenrolar a operação é necessária.
`end`|            11100100: final do código de desenrolamento. Implica ret no epílogo.
`end_c`|        11100101: final do código de desenrolamento no escopo atual de encadeadas.
`save_next`|        11100110: Salvar próximo Int de não-volátil ou FP registrar par.
`arithmetic(add)`|    11100111\| 000zxxxx: adicionar o cookie reg(z) a lr (0 = x28, 1 = sp); adicionar lr, lr, reg(z)
`arithmetic(sub)`|    11100111\| 001zxxxx: sub reg(z) de cookie de lr (0 = x28, 1 = sp); sub lr, lr, reg(z)
`arithmetic(eor)`|    11100111\| 010zxxxx: eor lr com o cookie reg(z) (0 = x28, 1 = sp); eor lr, lr, reg(z)
`arithmetic(rol)`|    11100111\| 0110xxxx: rol simulado de lr com cookie reg (x28); xip0 = neg x28; ror lr, xip0
`arithmetic(ror)`|    11100111\| 100zxxxx: ror lr com o cookie reg(z) (0 = x28, 1 = sp); ror lr, lr, reg(z)
||            11100111: xxxz---:---reservado
||              11101xxx: reservado para casos de pilha personalizados abaixo gerados apenas para rotinas do asm
||              11101001: personalizado stack para MSFT_OP_TRAP_FRAME
||              11101010: personalizado stack para MSFT_OP_MACHINE_FRAME
||              11101011: personalizado stack para MSFT_OP_CONTEXT
||              1111xxxx: reservado

Instruções com valores grandes que abrangem vários bytes, os bits mais significativos são armazenados primeiro. Os códigos de desenrolamento acima são projetados, que simplesmente procurando o primeiro byte do código, é possível saber o tamanho total em bytes do código de desenrolamento. Considerando que cada código de desenrolamento exatamente é mapeado para uma instrução de prólogo/epílogo, para calcular o tamanho do prólogo ou epílogo, tudo o que precisa ser feito é movimentar desde o início da sequência para o final, usando uma tabela de pesquisa ou um dispositivo semelhante para determinar quanto tempo o cor é o opcode está respondendo.

Observe que a endereçamento de deslocamento pós-indexada não é permitida no prólogo. Todos os intervalos de deslocamento (#Z) corresponde à codificação de endereçamento de STP/STR exceto `save_r19r20_x` em quais 248 é suficiente para todos os salvarem áreas (10 registros de Int + 8 registros FP + 8 registros de entrada).

`save_next` deve seguir um salvamento para Int ou volátil FP registrar par: `save_regp`, `save_regp_x`, `save_fregp`, `save_fregp_x`, `save_r19r20_x`, ou em outro `save_next`. Ele salva o próximo par de registro no slot de 16 bytes Avançar na ordem "expandindo". `save-next` seguindo uma `save_next` que denota o último par de registro de Int refere-se ao primeiro par de registro FP.

Desde que o tamanho do regular retornar e saltar instruções são as mesmas, não há nenhuma necessidade de um separado `end` código de desenrolamento para cenários de chamada tail.

`end_c` foi projetado para lidar com fragmentos de função não contíguas para fins de otimização. Um `end_c` que indica o final de códigos de desenrolamento no escopo atual deve ser seguido por outra série de código de desenrolamento terminou com um real `end`. Os códigos de desenrolamento entre `end_c` e `end` representam as operações de prólogo na região do pai (prólogo "fantasma").  Mais detalhes e exemplos são descritos na seção abaixo.

### <a name="packed-unwind-data"></a>Empacotadas dados de desenrolamento

Para funções cuja siga Prólogos e epílogos a forma canônica descrita abaixo, empacotadas desenrolar dados podem ser usados, eliminando a necessidade de um registro. XData inteiramente e reduz significativamente o custo de fornecer dados de desenrolamento. Canonical Prólogos e epílogos são projetados para atender aos requisitos comuns de uma função simple que não requer um manipulador de exceção, e que executa suas operações de configuração e desmontagem em uma ordem padrão.

O formato de um registro. pData com compactado desenrolar dados semelhante ao seguinte:

![dados de desenrolamento de registro. pData com compactado](../build/media/arm64-exception-handling-packed-unwind-data.png "dados de desenrolamento de registro. pData com compactado")

Os campos são da seguinte maneira:

- **Função RVA iniciar** é o RVA de 32 bits do início da função.
- **Sinalizador** é um campo de 2 bits, conforme descrito acima, com os seguintes significados:
  - 00 = compactado desenrolar dados não usados; bits restantes apontam para um registro. XData abaixo
  - 01 = compactado usados conforme descrito abaixo com único prólogo e epílogo no início e no final do escopo de dados de desenrolamento
  - 10 = compactado desenrolar dados usados como descrito abaixo para o código sem qualquer prólogo e epílogo; Isso é útil para descrever os segmentos separados por função.
  - 11 = reservados;
- **Função comprimento** é um campo de 11 bits fornecendo o comprimento da função inteira em bytes dividido por 4. Se a função for maior que 8 KB, um registro. XData completo deve ser usado em vez disso.
- **Tamanho de quadro** é um campo de 9 bits que indica o número de bytes de pilha é alocado para essa função, dividida por 16. Funções que alocam maior que (8k-16) bytes de pilha devem usar um registro. XData completo. Isso inclui a área de variável local, área de parâmetro, área de Int e FP salvos pelo receptor e área de parâmetro inicial de saída, mas excluindo a área de alocação dinâmica.
- **CR** é um sinalizador de 2 bits que indica se a função inclui instruções extras para configurar uma cadeia de quadros e um link de retorno:
  - 00 = função sem cadeia, \<r29, lr > par não é salvo na pilha.
  - 01 = função sem cadeia, \<lr > é salvo na pilha
  - 10 = reservados;
  - 11 = função encadeada, uma instrução de par de loja/carga é usada no prólogo/epílogo \<r29, lr >
- **H** é um sinalizador de 1 bit que indica se a função hospeda o parâmetro numérico inteiro registra (r0-r7), armazenando-os no início da função. (0 = não hospeda registros, 1 = hospeda registros).
- **RegI** é um campo de 4 bits que indica o número de registros INT não-volátil (r19 r28) salvo no local de pilha canônico.
- **RegF** é um campo de 3 bits que indica o número de registros FP não-volátil (d8-d15) salvo no local de pilha canônico. (0 não = nenhum FP register for salva, m > 0: m + 1 registradores FP são salvos). Para a função salvar apenas um desenrolamento de FP, empacotada dados não podem ser aplicados.

Prólogos canônicos que se enquadram nas categorias 1, 2 (sem área de parâmetro de saída), 3 e 4 na seção acima podem ser representados pelo formato de desenrolamento compactado.  Os epílogos para funções canônicas seguem uma forma muito semelhante, exceto **H** não tem nenhum efeito, a `set_fp` instrução for omitida e a ordem das etapas, bem como instruções em cada etapa são revertidas no epílogo. O algoritmo para xdata compactado segue estas etapas detalhadas na tabela a seguir:

Etapa 0: Execute o pré-cálculo do tamanho de cada área.

Etapa 1: Salve registros salvos pelo receptor de Int.

Etapa 2: Esta etapa é específica para o tipo 4 nas seções de início. LR é salvo no final da área de Int.

Etapa 3: Salve registros salvos pelo receptor FP.

Etapa 4: Salve os argumentos de entrada na área de parâmetro inicial.

Etapa 5: Alocar pilha restante, incluindo a rede local, \<r29, lr > par e área de parâmetro de saída. 5a corresponde ao tipo canônico 1. 5b e 5c são para o tipo canônico 2. 5D e 5e são para os dois tipos de 3 e 4 de tipo.

Etapa n º|Valores de sinalizador|n º de instruções|Opcode|Código de desenrolamento
-|-|-|-|-
0|||`#intsz = RegI * 8;`<br/>`if (CR==01) #intsz += 8; // lr`<br/>`#fpsz = RegF * 8;`<br/>`if(RegF) #fpsz += 8;`<br/>`#savsz=((#intsz+#fpsz+8*H)+0xf)&~0xf)`<br/>`#locsz = #famsz - #savsz`|
1|0 < **regI** < = 10|RegI / 2 + **RegI** % 2|`stp r19,r20,[sp,#savsz]!`<br/>`stp r21,r22,[sp,16]`<br/>`...`|`save_regp_x`<br/>`save_regp`<br/>`...`
2|**CR**= = 01 *|1|`str lr,[sp, #intsz-8]`\*|`save_reg`
3|0 < **RegF** < = 7|(RegF + 1) / 2 +<br/>(RegF + 1) % 2).|`stp d8,d9,[sp, #intsz]`\*\*<br/>`stp d10,d11,[sp, #intsz+16]`<br/>`...`<br/>`str d(8+RegF),[sp, #intsz+#fpsz-8]`|`save_fregp`<br/>`...`<br/>`save_freg`
4|**H** = = 1|4|`stp r0,r1,[sp, #intsz+#fpsz]`<br/>`stp r2,r3,[sp, #intsz+#fpsz+16]`<br/>`stp r4,r5,[sp, #intsz+#fpsz+32]`<br/>`stp r6,r7,[sp, #intsz+#fpsz+48]`|`nop`<br/>`nop`<br/>`nop`<br/>`nop`
5a|**CR** = = 11 & & #locsz<br/> < = 512|2|`stp r29,lr,[sp,-#locsz]!`<br/>`mov r29,sp`\*\*\*|`save_fplr_x`<br/>`set_fp`
5b|**CR** = = 11 &AMP; &AMP;<br/>512 < #locsz < = 4088|3|`sub sp,sp, #locsz`<br/>`stp r29,lr,[sp,0]`<br/>`add r29, sp, 0`|`alloc_m`<br/>`save_fplr`<br/>`set_fp`
5c|**CR** = = 11 & & #locsz > 4088|4|`sub sp,sp,4088`<br/>`sub sp,sp, (#locsz-4088)`<br/>`stp r29,lr,[sp,0]`<br/>`add r29, sp, 0`|`alloc_m`<br/>`alloc_s`/`alloc_m`<br/>`save_fplr`<br/>`set_fp`
5D|(**CR** = = 00 \| \| **CR**= = 01) &AMP; &AMP;<br/>#locsz < = 4088|1|`sub sp,sp, #locsz`|`alloc_s`/`alloc_m`
5e|(**CR** = = 00 \| \| **CR**= = 01) &AMP; &AMP;<br/>#locsz > 4088|2|`sub sp,sp,4088`<br/>`sub sp,sp, (#locsz-4088)`|`alloc_m`<br/>`alloc_s`/`alloc_m`

\*: Se **CR** = = 01 e **RegI** é um número ímpar, etapa 2 e a última save_rep na etapa 1 são mesclados em um save_regp.

\*\* Se **RegI** == **CR** = = 0, e **RegF** ! = 0, o stp primeiro para o ponto flutuante faz o pré-decremento.

\*\*\* Nenhuma instrução correspondente a `mov r29, sp` está presente no epílogo. Se uma função exige a restauração de sp de r29 e em seguida, não podemos usar empacotadas dados de desenrolamento.

### <a name="unwinding-partial-prologs-and-epilogs"></a>Epílogos e desenrolamento de Prólogos parciais

A situação de desenrolamento mais comum é que um em que a chamada ou a exceção ocorreu no corpo da função, distante do prólogo e todos os epílogos. Nessa situação, o desenrolamento é simples: o desenrolador simplesmente começa a executar os códigos na matriz de desenrolamento começando no índice 0 e continuando até que um opcode final seja detectado.

É mais difícil corretamente desenrolar no caso em que uma exceção ou interrupção ocorre durante a execução de um prólogo ou epílogo. Nessas situações, o quadro de pilha será construído apenas parcialmente e o truque é determinar exatamente o que foi feito para desfazê-lo corretamente.

Por exemplo, veja esta sequência de prólogo e epílogo:

```asm
0000:    stp    r29, lr, [sp, -256]!        // save_fplr_x  256 (pre-indexed store)
0004:    stp    d8,d9,[sp,224]              // save_fregp 0, 224
0008:    stp    r19,r20,[sp,240]            // save_regp 0, 240
000c:    mov    r29,sp                      // set_fp
         ...
0100:    mov    sp,r29                      // set_fp
0104:    ldp    r19,r20,[sp,240]            // save_regp 0, 240
0108:    ldp    d8,d9,[sp,224]              // save_fregp 0, 224
010c:    ldp    r29, lr, [sp, -256]!        // save_fplr_x  256 (post-indexed load)
0110:    ret     lr                         // end
```

Ao lado de cada opcode é o código de desenrolamento apropriado que descreve esta operação. A primeira coisa a observar é que a série de códigos de desenrolamento do prólogo é uma imagem espelhada exata dos códigos de desenrolamento para o epílogo (sem contar a instrução final de epílogo). Essa é uma situação comum, e por esse motivo, o desenrolamento códigos para o prólogo sempre devem ser armazenados na ordem inversa da ordem de execução do prólogo.

Portanto, para o prólogo e epílogo, continuamos com um conjunto comum de códigos de desenrolamento:

`set_fp`, `save_regp 0,240`, `save_fregp,0,224`, `save_fplr_x_256`, `end`

Começando com o caso de epílogo (mais simples porque ela está em ordem normal), no deslocamento 0 dentro do epílogo (que inicia no deslocamento 0x100 na função), esperaríamos executar a sequência de desenrolamento completa, pois nenhuma limpeza ainda foi feita. Se encontrarmos sozinhos uma instrução em (no deslocamento 2 no epílogo), podemos poderá desenrolar com êxito, ignorando o primeiro código de desenrolamento. Generalizando nessa situação, supondo que um mapeamento de 1:1 entre opcodes e códigos de desenrolamento, podemos pode declarar que, se nós são desenrolamento de instrução n no epílogo, podemos deve ignorar os primeiros códigos de desenrolamento n e começar a executar a partir daí.

Acontece que uma lógica semelhante funciona para o prólogo, exceto na ordem inversa. Se nós são estiver desenrolando de deslocamento 0 no prólogo, queremos executar nada. Se nós desenrolado do deslocamento de 2, que é uma instrução em e, em seguida, podemos desejar iniciar a execução de código de desenrolamento de uma de sequência de desenrolamento do final (Lembre-se de que os códigos são armazenados na ordem inversa). E aqui também podemos pode generalizar que se nós são estiver desenrolando de instrução n no prólogo, devemos começar a execução de códigos de desenrolamento n do final da lista de códigos.

Agora, ele nem sempre é o caso em que os códigos de prólogo e epílogo correspondem exatamente. Por esse motivo, a matriz de desenrolamento talvez seja necessário conter várias sequências de códigos. Para determinar o deslocamento de onde começar o processamento de códigos, use a seguinte lógica:

1. Se estiver desenrolando de dentro do corpo da função, simplesmente começar a executar códigos de desenrolamento no índice 0 e continuar até atingir um opcode "final".

2. Se estiver desenrolando de dentro de um epílogo, use o índice inicial de específicas do epílogo fornecido com o escopo de epílogo como ponto de partida. Computação quantos bytes o PC em questão está desde o início do epílogo. Em seguida, avance para frente por meio de códigos de desenrolamento, ignorando os códigos de desenrolamento até que todas as instruções já executadas sejam consideradas. Em seguida, execute iniciando nesse ponto.

3. Se estiver desenrolando de dentro do prólogo, use o índice 0 como ponto de partida. Calcular o tamanho do código de prólogo da sequência e calcule quantos bytes o PC em questão está do final do prólogo. Em seguida, avance para frente por meio de códigos de desenrolamento, ignorando os códigos de desenrolamento até que todas as instruções que ainda não executadas sejam consideradas. Em seguida, execute iniciando nesse ponto.

Como resultado dessas regras, os códigos de desenrolamento do prólogo devem ser sempre a primeira na matriz, e também os códigos usados para desenrolar no geral caso de desenrolamento de dentro do corpo. Todas as sequências de código específico do epílogo devem vir imediatamente após.

### <a name="function-fragments"></a>Fragmentos de função

Para fins de otimização de código e outros motivos, pode ser preferível para dividir uma função em fragmentos separados (também chamados de regiões). Quando isso for feito, cada fragmento de função resultante requer sua própria pData separado (e possivelmente. XData) registro.

Para fragmento secundário separado que tem seu próprio prólogo, espera-se que nenhum ajuste de pilha é feita em seu prólogo. Todos os espaço necessário para o secundário de pilha regiões devem ser previamente alocadas por sua região pai (ou a região de host chamado). Isso mantém estritamente manipulação do ponteiro de pilha no prólogo original da função.

Um caso típico de fragmentos de função é "separação de código" com que o compilador pode mover uma região de código fora de sua função de host. Há três casos incomuns que poderiam ser resultaram pela separação de código.

#### <a name="example"></a>Exemplo:

- (região 1: começar)

    ```asm
        stp     r29, lr, [sp, -256]!    // save_fplr_x  256 (pre-indexed store)
        stp     r19,r20,[sp,240]        // save_regp 0, 240
        mov     r29,sp                  // set_fp
        ...
    ```

- (região 1: final)
- (região 3: começar)

    ```asm
        ...
    ```

- (3 de região: final)
- (região 2: começar)

    ```asm
    ...
        mov     sp,r29                  // set_fp
        ldp     r19,r20,[sp,240]        // save_regp 0, 240
        ldp     r29, lr, [sp, -256]!    // save_fplr_x  256 (post-indexed load)
        ret     lr                      // end
    ```

- (região 2: final)

1. Somente prólogo (região 1: todos os epílogos estão em regiões separadas):

   Somente o prólogo deve ser descrito. Isso não pode ser representado pelo formato. pData compacto. No caso de. XData completo, isso pode ser representado por definir a contagem de epílogo = 0. Consulte região 1 no exemplo acima.

   Códigos de desenrolamento: `set_fp`, `save_regp 0,240`, `save_fplr_x_256`, `end`.

2. Epílogos somente (região 2: prólogo está na região de host)

   Supõe-se pelo controle de tempo pular para essa região, todos os códigos de prólogo foram executados. Desenrolamento parcial pode acontecer em epílogos da mesma forma como em uma função normal. Esse tipo de região não pode ser representado por. pData compacto. No registro de xdata completo, ele pode ser codificado com um prólogo "fantasma", agrupado por uma `end_c` e `end` par de código de desenrolamento.  O entrelinhamento `end_c` indica o tamanho do prólogo é zero. Índice dos pontos de epílogo único para iniciar o epílogo `set_fp`.

   Código de desenrolamento para região 2: `end_c`, `set_fp`, `save_regp 0,240`, `save_fplr_x_256`, `end`.

3. Não há Prólogos ou epílogos (região 3: Prólogos e epílogos todos os que estão em outros fragmentos):

   . PData compacto formato pode ser aplicado por meio de definir sinalizador = 10. Com o registro. XData completo, contagem de epílogo = 1. Desenrolar código é o mesmo que aqueles para a região 2 acima, mas o índice do começo epílogo também aponta para `end_c`. Desenrolamento parcial nunca ocorrerão nesta região do código.

Outro caso mais complicado de fragmentos de função é "reduzir encapsulamento" com que o compilador pode optar por atrasar a salvar alguns registros salvos pelo receptor até que fora do prólogo da função de entrada.

- (região 1: começar)

    ```asm
        stp     r29, lr, [sp, -256]!    // save_fplr_x  256 (pre-indexed store)
        stp     r19,r20,[sp,240]        // save_regp 0, 240
        mov     r29,sp                  // set_fp
        ...
    ```

- (região 2: começar)

    ```asm
        stp     r21,r22,[sp,224]        // save_regp 2, 224
        ...
        ldp     r21,r22,[sp,224]        // save_regp 2, 224
    ```

- (região 2: final)

    ```asm
        ...
        mov     sp,r29                  // set_fp
        ldp     r19,r20,[sp,240]        // save_regp 0, 240
        ldp     r29, lr, [sp, -256]!    // save_fplr_x  256 (post-indexed load)
        ret     lr                      // end
    ```

- (região 1: final)

No prólogo da região 1, o espaço de pilha é alocado previamente. Observe que essa região 2 terá o mesmo código de desenrolamento que até que ele é movido para fora de sua função de host.

Região 1: `set_fp`, `save_regp 0,240`, `save_fplr_x_256`, `end` com o índice de início do epílogo aponta para `set_fp` como de costume.

Região 2: `save_regp 2, 224`, `end_c`, `set_fp`, `save_regp 0,240`, `save_fplr_x_256`, `end`. Índice de início do epílogo aponta para o primeiro código de desenrolamento `save_regp 2, 224`.

### <a name="large-functions"></a>Funções grandes

Fragmentos podem ser utilizados para descrever funções maiores do que o limite de 1M imposto pelos campos de bits no cabeçalho. XData. Para descrever uma função muito grande, assim, ele simplesmente precisará ser dividido em fragmentos de menor que 1 milhão. Cada fragmento deve ser ajustado para que ele não Divida um epílogo em várias partes.

O primeiro fragmento da função conterá um prólogo; todos os outros fragmentos são marcados como não tendo nenhum prólogo. Dependendo do número de epílogos presentes, cada fragmento pode conter zero ou mais epílogos. Tenha em mente que cada escopo de epílogo em um fragmento especifica seu deslocamento inicial em relação ao início do fragmento, e não ao início da função.

Se um fragmento tem nenhum prólogo e nenhum epílogo, ela ainda requer seu próprio registro. pData (e possivelmente. XData) registro, para descrever como desenrolar de dentro do corpo da função.

## <a name="examples"></a>Exemplos

### <a name="example-1-frame-chained-compact-form"></a>Exemplo 1: Quadro encadeadas, CD-formulário

```asm
|Foo|     PROC
|$LN19|
    str     x19,[sp,#-0x10]!        // save_reg_x
    sub     sp,sp,#0x810            // alloc_m
    stp     fp,lr,[sp]              // save_fplr
    mov     fp,sp                   // set_fp
                                    //  end of prolog
    ...

|$pdata$Foo|
    DCD     imagerel     |$LN19|
    DCD     0x416101ed
    ;Flags[SingleProEpi] functionLength[492] RegF[0] RegI[1] H[0] frameChainReturn[Chained] frameSize[2080]
```

### <a name="example-2-frame-chained-full-form-with-mirror-prolog--epilog"></a>Exemplo 2: Quadro encadeadas, formato por completo com o espelho prólogo e epílogo

```asm
|Bar|     PROC
|$LN19|
    stp     x19,x20,[sp,#-0x10]!    // save_regp_x
    stp     fp,lr,[sp,#-0x90]!      // save_fplr_x
    mov     fp,sp                   // set_fp
                                    // end of prolog
    ...
                                    // begin of epilog, a mirror sequence of Prolog
    mov     sp,fp
    ldp     fp,lr,[sp],#0x90
    ldp     x19,x20,[sp],#0x10
    ret     lr

|$pdata$Bar|
    DCD     imagerel     |$LN19|
    DCD     imagerel     |$unwind$cse2|
|$unwind$Bar|
    DCD     0x1040003d
    DCD     0x1000038
    DCD     0xe42291e1
    DCD     0xe42291e1
    ;Code Words[2], Epilog Count[1], E[0], X[0], Function Length[6660]
    ;Epilog Start Index[0], Epilog Start Offset[56]
    ;set_fp
    ;save_fplr_x
    ;save_r19r20_x
    ;end
```

Observe que o índice de EpilogStart [0] aponta para a mesma sequência de código de desenrolamento do prólogo.

### <a name="example-3-variadic-unchained-function"></a>Exemplo 3: Variadic sem cadeia função

```asm
|Delegate| PROC
|$LN4|
    sub     sp,sp,#0x50
    stp     x19,lr,[sp]
    stp     x0,x1,[sp,#0x10]        // save incoming register to home area
    stp     x2,x3,[sp,#0x20]        // ...
    stp     x4,x5,[sp,#0x30]
    stp     x6,x7,[sp,#0x40]        // end of prolog
    ...
    ldp     x19,lr,[sp]             // beginning of epilog
    add     sp,sp,#0x50
    ret     lr

    AREA    |.pdata|, PDATA
|$pdata$Delegate|
    DCD     imagerel |$LN4|
    DCD     imagerel |$unwind$Delegate|

    AREA    |.xdata|, DATA
|$unwind$Delegate|
    DCD     0x18400012
    DCD     0x200000f
    DCD     0xe3e3e3e3
    DCD     0xe40500d6
    DCD     0xe40500d6
    ;Code Words[3], Epilog Count[1], E[0], X[0], Function Length[18]
    ;Epilog Start Index[4], Epilog Start Offset[15]
    ;nop        // nop for saving in home area
    ;nop        // ditto
    ;nop        // ditto
    ;nop        // ditto
    ;save_lrpair
    ;alloc_s
    ;end
```

Observação: EpilogStart índice [4] aponta para o meio do código de desenrolamento do prólogo (parcialmente matriz de desenrolamento de reutilização).

## <a name="see-also"></a>Consulte também

[Visão geral das convenções de ABI ARM64](arm64-windows-abi-conventions.md)  
[Tratamento de exceção do ARM](../build/arm-exception-handling.md)  
