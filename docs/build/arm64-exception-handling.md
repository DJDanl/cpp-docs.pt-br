---
title: Tratamento de exceção do ARM64
description: Descreve as convenções de tratamento de exceção e os dados usados pelo Windows no ARM64.
ms.date: 11/19/2018
ms.openlocfilehash: 2304c04c5e9be31299e30bb48771f7c9777d1cd5
ms.sourcegitcommit: b9aaaebe6e7dc5a18fe26f73cc7cf5fce09262c1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/20/2020
ms.locfileid: "77504485"
---
# <a name="arm64-exception-handling"></a>Tratamento de exceção do ARM64

O Windows no ARM64 usa o mesmo mecanismo estruturado de tratamento de exceções para exceções assíncronas geradas por hardware e exceções síncronas geradas por software. Os manipuladores de exceção específicos da linguagem são compilados sobre o tratamento de exceção estruturado do Windows usando funções de auxiliares da linguagem. Este documento descreve a manipulação de exceções no Windows no ARM64, e os auxiliares de linguagem usados pelo código gerado pelo compilador do Microsoft ARM Assembler e do MSVC.

## <a name="goals-and-motivation"></a>Metas e motivação

As convenções de desenrolamento de exceção, e esta descrição, são destinadas a:

1. Forneça uma descrição suficiente para permitir o desenrolamento sem a investigação de código em todos os casos.

   - A análise do código exige que o código seja paginado. Isso evita o desenrolamento em algumas circunstâncias em que é útil (rastreamento, amostragem, depuração).

   - A análise do código é complexa; o compilador deve ter cuidado para gerar apenas instruções que o desenrolador pode decodificar.

   - Se o desenrolamento não puder ser totalmente descrito por meio do uso de códigos de liberação, em alguns casos ele deverá voltar à decodificação de instrução. Isso aumenta a complexidade geral e, idealmente, deve ser evitado.

1. Suporte ao desenrolamento em Mid-prólogo e mid-epílogo.

   - O desenrolamento é usado no Windows para mais do que a manipulação de exceção. É essencial que o código possa desenrolar com precisão mesmo quando estiver no meio de um prólogo ou uma sequência de código epílogo.

1. Ocupar uma quantidade mínima de espaço.

   - Os códigos de liberação não devem agregar para aumentar significativamente o tamanho binário.

   - Como os códigos de liberação provavelmente serão bloqueados na memória, uma pequena superfície garante uma sobrecarga mínima para cada binário carregado.

## <a name="assumptions"></a>Suposições

Essas suposições são feitas na descrição da manipulação de exceção:

1. O Prologs e o epilogs tendem a ser espelhados. Aproveitando essa característica comum, o tamanho dos metadados necessários para descrever o desenrolamento pode ser bastante reduzido. No corpo da função, não importa se as operações do prólogo são desfeitas ou se as operações do epílogo são feitas de forma direta. Ambas devem produzir resultados idênticos.

1. As funções tendem a ser relativamente pequenas. Várias otimizações de espaço dependem desse fato para alcançar o empacotamento mais eficiente de dados.

1. Não há código condicional em epilogs.

1. Registro de ponteiro de quadro dedicado: se o SP for salvo em outro registro (x29) no prólogo, esse registro permanecerá inalterado durante toda a função. Isso significa que o SP original pode ser recuperado a qualquer momento.

1. A menos que o SP seja salvo em outro registro, toda a manipulação do ponteiro de pilha ocorre estritamente dentro do prólogo e do epílogo.

1. O layout do quadro de pilhas é organizado conforme descrito na próxima seção.

## <a name="arm64-stack-frame-layout"></a>Layout de quadro de pilha ARM64

![layout de registro de ativação](media/arm64-exception-handling-stack-frame.png "layout de registro de ativação")

Para funções encadeadas de quadro, o par FP e LR pode ser salvo em qualquer posição na área variável local, dependendo das considerações de otimização. O objetivo é maximizar o número de locais que podem ser alcançados por uma única instrução com base no ponteiro do quadro (x29) ou no ponteiro de pilha (SP). No entanto `alloca` , para funções, ela deve ser encadeada e x29 deve apontar para a parte inferior da pilha. Para permitir uma melhor cobertura de modo de endereçamento de pares de registro, as áreas de salvamento de registro não volátil são posicionadas na parte superior da pilha de área local. Aqui estão exemplos que ilustram várias das sequências de prólogo mais eficientes. Para fins de clareza e melhor localidade de cache, a ordem de armazenamento de registros salvos por receptor em todos os Prologs canônicos está na ordem "crescente". `#framesz`abaixo representa o tamanho da pilha inteira (excluindo a área alloca). `#localsz`e `#outsz` denotam o tamanho da área local (incluindo a \<área de salvamento do x29, LR> pair) e o tamanho do parâmetro de saída, respectivamente.

1. Encadeado, #localsz \<= 512

    ```asm
        stp    x19,x20,[sp,#-96]!        // pre-indexed, save in 1st FP/INT pair
        stp    d8,d9,[sp,#16]            // save in FP regs (optional)
        stp    x0,x1,[sp,#32]            // home params (optional)
        stp    x2,x3,[sp,#48]
        stp    x4,x5,[sp,#64]
        stp    x6,x7,[sp,#72]
        stp    x29,lr,[sp,#-localsz]!   // save <x29,lr> at bottom of local area
        mov    x29,sp                   // x29 points to bottom of local
        sub    sp,sp,#outsz             // (optional for #outsz != 0)
    ```

1. Encadeado, #localsz > 512

    ```asm
        stp    x19,x20,[sp,#-96]!        // pre-indexed, save in 1st FP/INT pair
        stp    d8,d9,[sp,#16]            // save in FP regs (optional)
        stp    x0,x1,[sp,#32]            // home params (optional)
        stp    x2,x3,[sp,#48]
        stp    x4,x5,[sp,#64]
        stp    x6,x7,[sp,#72]
        sub    sp,sp,#(localsz+outsz)   // allocate remaining frame
        stp    x29,lr,[sp,#outsz]       // save <x29,lr> at bottom of local area
        add    x29,sp,#outsz            // setup x29 points to bottom of local area
    ```

1. Não encadeadas, funções de folha (LR não salvas)

    ```asm
        stp    x19,x20,[sp,#-80]!       // pre-indexed, save in 1st FP/INT reg-pair
        stp    x21,x22,[sp,#16]
        str    x23,[sp,#32]
        stp    d8,d9,[sp,#40]           // save FP regs (optional)
        stp    d10,d11,[sp,#56]
        sub    sp,sp,#(framesz-80)      // allocate the remaining local area
    ```

   Todos os locais são acessados com base no SP. \<x29, LR> aponta para o quadro anterior. Para o tamanho \<do quadro = 512, o "sub-SP,..." pode ser otimizado para fora se a área regs salva for movida para a parte inferior da pilha. A desvantagem é que não é consistente com outros layouts acima, e regs salvos fazem parte do intervalo para o modo de endereçamento de deslocamento de regs e pré e pós-indexado.

1. Funções não encadeadas e não folha (a LR é salva na área de salvamento de int)

    ```asm
        stp    x19,x20,[sp,#-80]!       // pre-indexed, save in 1st FP/INT reg-pair
        stp    x21,x22,[sp,#16]         // ...
        stp    x23,lr,[sp,#32]          // save last Int reg and lr
        stp    d8,d9,[sp,#48]           // save FP reg-pair (optional)
        stp    d10,d11,[sp,#64]         // ...
        sub    sp,sp,#(framesz-80)      // allocate the remaining local area
    ```

   Ou, com o número par de registros int salvos,

    ```asm
        stp    x19,x20,[sp,#-80]!       // pre-indexed, save in 1st FP/INT reg-pair
        stp    x21,x22,[sp,#16]         // ...
        str    lr,[sp,#32]              // save lr
        stp    d8,d9,[sp,#40]           // save FP reg-pair (optional)
        stp    d10,d11,[sp,#56]         // ...
        sub    sp,sp,#(framesz-80)      // allocate the remaining local area
    ```

   Somente x19 salvos:

    ```asm
        sub    sp,sp,#16                // reg save area allocation*
        stp    x19,lr,[sp]              // save x19, lr
        sub    sp,sp,#(framesz-16)      // allocate the remaining local area
    ```

   \*A alocação da área de salvamento do reg não é dobrada no STP porque um STP do reg-LR previamente indexado não pode ser representado com os códigos de liberação.

   Todos os locais são acessados com base no SP. \<x29> aponta para o quadro anterior.

1. Encadeados, \<#framesz = 512, #outsz = 0

    ```asm
        stp    x29,lr,[sp,#-framesz]!       // pre-indexed, save <x29,lr>
        mov    x29,sp                       // x29 points to bottom of stack
        stp    x19,x20,[sp,#(framesz-32)]   // save INT pair
        stp    d8,d9,[sp,#(framesz-16)]     // save FP pair
    ```

   Em comparação com o primeiro exemplo de prólogo acima, a vantagem aqui é que todas as instruções de gravação de registro estão prontas para execução após apenas uma instrução de alocação de pilha. Isso significa que não há antidependência no SP que impeça o paralelismo de nível de instrução.

1. Encadeados, tamanho do quadro > 512 (opcional para funções sem alloca)

    ```asm
        stp    x29,lr,[sp,#-80]!            // pre-indexed, save <x29,lr>
        stp    x19,x20,[sp,#16]             // save in INT regs
        stp    x21,x22,[sp,#32]             // ...
        stp    d8,d9,[sp,#48]               // save in FP regs
        stp    d10,d11,[sp,#64]
        mov    x29,sp                       // x29 points to top of local area
        sub    sp,sp,#(framesz-80)          // allocate the remaining local area
    ```

   Para fins de otimização, o x29 pode ser colocado em qualquer posição na área local para fornecer uma melhor cobertura para o modo de endereçamento de deslocamento de "reg-pair" e/post-Indexed. Locais abaixo de ponteiros de quadro podem ser acessados com base no SP.

1. Encadeados, tamanho do quadro > 4K, com ou sem alloca (),

    ```asm
        stp    x29,lr,[sp,#-80]!            // pre-indexed, save <x29,lr>
        stp    x19,x20,[sp,#16]             // save in INT regs
        stp    x21,x22,[sp,#32]             // ...
        stp    d8,d9,[sp,#48]               // save in FP regs
        stp    d10,d11,[sp,#64]
        mov    x29,sp                       // x29 points to top of local area
        mov    x15,#(framesz/16)
        bl     __chkstk
        sub    sp,sp,x15,lsl#4              // allocate remaining frame
                                            // end of prolog
        ...
        sub    sp,sp,#alloca                // more alloca() in body
        ...
                                            // beginning of epilog
        mov    sp,x29                       // sp points to top of local area
        ldp    d10,d11,[sp,#64]
        ...
        ldp    x29,lr,[sp],#80              // post-indexed, reload <x29,lr>
    ```

## <a name="arm64-exception-handling-information"></a>Informações de manipulação de exceção do ARM64

### <a name="pdata-records"></a>registros de. pData

Os registros. pData são uma matriz ordenada de itens de comprimento fixo que descrevem cada função de manipulação de pilha em um binário PE. A frase "Stack-Manipulation" é significativa: funções de folha que não exigem nenhum armazenamento local e não precisam salvar/restaurar registros não voláteis, não exigem um registro. pData. Esses registros devem ser omitidos explicitamente para economizar espaço. Um desenrolamento de uma dessas funções pode obter o endereço de retorno diretamente do LR para mover para o chamador.

Cada registro. pData para ARM64 tem 8 bytes de comprimento. O formato geral de cada registro coloca o RVA de 32 bits da função iniciar na primeira palavra, seguido por uma segunda palavra que contém um ponteiro para um bloco de comprimento variável. xdata ou uma palavra compactada que descreve uma sequência de desenrolamento de função canônica.

![. pData layout de registro](media/arm64-exception-handling-pdata-record.png ". pData layout de registro")

Os campos são os seguintes:

- O **RVA de início de função** é o rva de 32 bits do início da função.

- **Sinalizador** é um campo de 2 bits que indica como interpretar os 30 bits restantes da segunda palavra. pData. Se o **sinalizador** for 0, os bits restantes formam um **RVA de informações de exceção** (com os dois bits mais baixos implicitamente). Se o **sinalizador** for diferente de zero, os bits restantes formam uma estrutura de **dados de desenrolamentos compactados** .

- **RVA de informações de exceção** é o endereço da estrutura de informações de exceção de comprimento variável, armazenada na seção. xdata. Esses dados devem ser alinhados para 4 bytes.

- Os **dados desenrolados compactados** são uma descrição compactada das operações necessárias para desenrolar de uma função, supondo uma forma canônica. Nesse caso, nenhum registro .xdata é necessário.

### <a name="xdata-records"></a>registros de. xdata

Quando o formato de desenrolamento compactado for insuficiente para descrever o desenrolamento de uma função, um registro .xdata de comprimento variável deverá ser criado. O endereço desse registro é armazenado na segunda palavra do registro .pdata. O formato de. xdata é um conjunto de palavras de tamanho variável empacotado:

![. xdata layout de registro](media/arm64-exception-handling-xdata-record.png ". xdata layout de registro")

Esses dados são divididos em quatro seções:

1. Um cabeçalho de 1 ou 2 palavras que descreve o tamanho geral da estrutura e fornece dados de função de chave. A segunda palavra só estará presente se os campos **contagem de epílogo** e **palavras de código** estiverem definidos como 0. O cabeçalho tem estes campos de bits:

   a. O **comprimento da função** é um campo de 18 bits. Indica o comprimento total da função em bytes, dividido por 4. Se uma função for maior que 1 milhão, vários registros. pData e. xdata deverão ser usados para descrever a função. Para obter mais informações, consulte a seção [funções grandes](#large-functions) .

   b. O **verso** é um campo de 2 bits. Ele descreve a versão do. xdata restante. Atualmente, somente a versão 0 é definida; portanto, os valores de 1-3 não são permitidos.

   c. **X** é um campo de 1 bit. Indica a presença (1) ou a ausência (0) de dados de exceção.

   d. **E** é um campo de 1 bit. Ele indica que as informações que descrevem um único epílogo são incluídas no cabeçalho (1) em vez de exigir palavras de escopo adicionais posteriormente (0).

   e. A **contagem epílogo** é um campo de 5 bits que tem dois significados, dependendo do estado de **E** bit:

      1. Se **E** for 0, ele especificará a contagem do número total de escopos epílogo descritos na seção 2. Se houver mais de 31 escopos na função, o campo de **palavras de código** deverá ser definido como 0 para indicar que uma palavra de extensão é necessária.

      2. Se **E** for 1, esse campo especificará o índice do primeiro código de desenrolação que descreve o único e epílogo.

   f. **Palavras de código** é um campo de 5 bits que especifica o número de palavras de 32 bits necessárias para conter todos os códigos de liberação na seção 3. Se mais de 31 palavras forem necessárias (ou seja, se houver mais de 124 bytes de código de desenrolação), esse campo deverá ser 0 para indicar que uma palavra de extensão é necessária.

   g. A **contagem de epílogo estendida** e as **palavras de código estendido** são campos de 16 e 8 bits, respectivamente. Eles fornecem mais espaço para codificar um número muito grande de epilogs ou um número incomum de palavras de código de desenrolação. A palavra de extensão que contém esses campos só estará presente se os campos **contagem de epílogo** e palavras de **código** na primeira palavra de cabeçalho forem 0.

1. Se a **contagem de epílogo** não for zero, uma lista de informações sobre escopos epílogo, empacotada uma para uma palavra, vem após o cabeçalho e o cabeçalho estendido opcional. Eles são armazenados em ordem de aumento de deslocamento de início. Cada escopo contém os seguintes bits:

   a. O **deslocamento de início do epílogo** é um campo de 18 bits que tem o deslocamento em bytes, dividido por 4, do epílogo em relação ao início da função.

   b. **Res** é um campo de 4 bits reservado para expansão futura. Seu valor deve ser 0.

   c. **Epílogo o índice inicial** é um campo de 10 bits (2 mais bits do que as **palavras de código estendido**). Indica o índice de bytes do primeiro código de desenrolação que descreve esse epílogo.

1. Depois que a lista de escopos epílogo é uma matriz de bytes que contém códigos de liberação, descritos em detalhes em uma seção posterior. Essa matriz é preenchida no final, o mais próximo possível do limite da palavra completa. Os códigos de liberação são gravados nessa matriz. Eles começam com o mais próximo do corpo da função e se movem para as bordas da função. Os bytes para cada código de desenrolamento são armazenados na ordem big-endian para que possam ser buscados diretamente, começando com o byte mais significativo primeiro, que identifica a operação e o comprimento do restante do código.

1. Finalmente, após os bytes de código de liberação, se o **X** bit no cabeçalho tiver sido definido como 1, o virá as informações do manipulador de exceção. Ele consiste em um único **RVA do manipulador de exceção** que fornece o endereço do próprio manipulador de exceção. Ele é seguido imediatamente por uma quantidade de comprimento variável de dados exigida pelo manipulador de exceção.

O registro. xdata foi projetado para que seja possível buscar os primeiros 8 bytes e usá-los para calcular o tamanho total do registro, menos o comprimento dos dados de exceção de tamanho variável a seguir. O trecho de código a seguir computa o tamanho do registro:

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

Embora o prólogo e cada epílogo tenha seu próprio índice nos códigos de liberação, a tabela é compartilhada entre eles. É totalmente possível (e não totalmente incomum) que todos eles possam compartilhar os mesmos códigos. (Para obter um exemplo, consulte o exemplo 2 na seção [exemplos](#examples) .) Os gravadores de compilador devem otimizar para esse caso, em particular, porque o maior índice que pode ser especificado é 255, o que limita o número total de códigos de liberação para uma função específica.

### <a name="unwind-codes"></a>Códigos de liberação

A matriz de códigos de liberação é o pool de sequências que descrevem exatamente como desfazer os efeitos do prólogo, armazenados na mesma ordem em que as operações precisam ser desfeitas. Os códigos de liberação podem ser considerados como um pequeno conjunto de instruções, codificados como uma cadeia de caracteres de bytes. Quando a execução for concluída, o endereço de retorno para a função de chamada estará no registro de LR. E todos os registros não voláteis são restaurados para seus valores no momento em que a função foi chamada.

Se houver garantia de que as exceções ocorreram apenas dentro de um corpo de função e nunca em um prólogo ou em qualquer epílogo, apenas uma única sequência seria necessária. No entanto, o modelo de desenrolamento do Windows requer que o código possa desenrolar de um prólogo ou epílogo parcialmente executado. Para atender a esse requisito, os códigos de desenrolação foram cuidadosamente projetados para mapear de forma não ambígua 1:1 para cada opcode relevante no prólogo e no epílogo. Esse design tem várias implicações:

1. Contando o número de códigos de liberação, é possível calcular o comprimento do prólogo e do epílogo.

1. Contando o número de instruções após o início de um escopo epílogo, é possível ignorar o número equivalente de códigos de liberação. Em seguida, podemos executar o restante de uma sequência para concluir o desenrolamento parcialmente executado feito pelo epílogo.

1. Contando o número de instruções antes do final do prólogo, é possível ignorar o número equivalente de códigos de liberação. Em seguida, podemos executar o restante da sequência para desfazer apenas as partes do prólogo que concluíram a execução.

Os códigos de liberação são codificados de acordo com a tabela a seguir. Todos os códigos de desenrolamento são um byte único/duplo, exceto aquele que aloca uma pilha enorme. Totalmente, há 21 códigos de desenrolamento. Cada código de desenrolamento mapeia exatamente uma instrução no prólogo/epílogo, para permitir o desenrolamento de Prologs e de epilogs parcialmente executados.

|Código de desenrolamento|Bits e interpretação|
|-|-|
|`alloc_s`|000xxxxx: alocar pilha pequena com \< o tamanho 512 (2 ^ 5 * 16).|
|`save_r19r20_x`|    001zzzzz: salvar \<x19, X20> par em `[sp-#Z*8]!`, deslocamento previamente indexado >=-248 |
|`save_fplr`|        01zzzzzz: Salve \<x29, LR> par em `[sp+#Z*8]`, offset \<= 504. |
|`save_fplr_x`|        10zzzzzz: salvar \<x29, LR> par em `[sp-(#Z+1)*8]!`, deslocamento previamente indexado >=-512 |
|`alloc_m`|        11000xxx'xxxxxxxx: alocar pilha grande com \< o tamanho 16K (2 ^ 11 * 16). |
|`save_regp`|        110010xx'xxzzzzzz: salvar o par x (19 + #X) `[sp+#Z*8]`em, \<offset = 504 |
|`save_regp_x`|        110011xx'xxzzzzzz: Economize o par x (19 + #X) `[sp-(#Z+1)*8]!`em, deslocamento previamente indexado >=-512 |
|`save_reg`|        110100xx'xxzzzzzz: salvar reg x (19 + #X) em `[sp+#Z*8]`, offset \<= 504 |
|`save_reg_x`|        1101010x'xxxzzzzz: salvar reg x (19 + #X) em `[sp-(#Z+1)*8]!`, deslocamento previamente indexado >=-256 |
|`save_lrpair`|         1101011x'xxzzzzzz: salvar o \<par x (19 + 2 * #X), LR> `[sp+#Z*8]`em, \<offset = 504 |
|`save_fregp`|        1101100x'xxzzzzzz: salvar par d (8 + #X) em `[sp+#Z*8]`, offset \<= 504 |
|`save_fregp_x`|        1101101x'xxzzzzzz: salvar par d (8 + #X), em `[sp-(#Z+1)*8]!`, deslocamento previamente indexado >=-512 |
|`save_freg`|        1101110x'xxzzzzzz: salvar reg d (8 + #X) em `[sp+#Z*8]`, offset \<= 504 |
|`save_freg_x`|        11011110 ' xxxzzzzz: salvar reg d (8 + #X) em `[sp-(#Z+1)*8]!`, deslocamento previamente indexado >=-256 |
|`alloc_l`|         11100000 ' xxxxxxxx'xxxxxxxx'xxxxxxxx: alocar uma pilha grande \< com o tamanho 256M (2 ^ 24 * 16) |
|`set_fp`|        11100001: configurar x29: com:`mov x29,sp` |
|`add_fp`|        11100010 ' xxxxxxxx: configurar x29 com:`add x29,sp,#x*8` |
|`nop`|            11100011: nenhuma operação de desenrolamento é necessária. |
|`end`|            11100100: fim do código de desenrolamento. Implica RET em epílogo. |
|`end_c`|        11100101: fim do código de desenrolamento no escopo atual encadeado. |
|`save_next`|        11100110: Salve o próximo par de registros int ou FP não volátil. |
|`arithmetic(add)`|    11100111 ' 000zxxxx: Adicionar cookie reg (z) a LR (0 = x28, 1 = SP);`add lr, lr, reg(z)` |
|`arithmetic(sub)`|    11100111 ' 001zxxxx: sub cookie reg (z) de LR (0 = x28, 1 = SP);`sub lr, lr, reg(z)` |
|`arithmetic(eor)`|    11100111 ' 010zxxxx: EOR LR com cookie reg (z) (0 = x28, 1 = SP);`eor lr, lr, reg(z)` |
|`arithmetic(rol)`|    11100111 ' 0110xxxx: rol Simulated de LR com cookie reg (x28); xip0 = neg x28;`ror lr, xip0` |
|`arithmetic(ror)`|    11100111 ' 100zxxxx: ROR LR com cookie reg (z) (0 = x28, 1 = SP);`ror lr, lr, reg(z)` |
| |            11100111: xxxz----:----reservado |
| |              11101xxx: reservado para os casos de pilha personalizados abaixo gerados somente para rotinas de ASM |
| |              11101000: pilha personalizada para MSFT_OP_TRAP_FRAME |
| |              11101001: pilha personalizada para MSFT_OP_MACHINE_FRAME |
| |              11101010: pilha personalizada para MSFT_OP_CONTEXT |
| |              11101100: pilha personalizada para MSFT_OP_CLEAR_UNWOUND_TO_CALL |
| |              1111xxxx: reservado |

Em instruções com valores grandes que abrangem vários bytes, os bits mais significativos são armazenados primeiro. Esse design possibilita a localização do tamanho total em bytes do código de desenrolação pesquisando apenas o primeiro byte do código. Como cada código de desenrolação é mapeado exatamente para uma instrução em um prólogo ou epílogo, você pode calcular o tamanho do prólogo ou do epílogo. Você pode percorrer o início da sequência até o final e usar uma tabela de pesquisa ou dispositivo semelhante para determinar quanto tempo o opcode correspondente é.

O endereçamento de deslocamento após o índice não é permitido em um prólogo. Todos os intervalos de deslocamento (#Z) correspondem à codificação de endereçamento STP `save_r19r20_x`/Str, exceto, em que 248 é suficiente para todas as áreas de salvamento (10 registros int + 8 registros de FP + 8 registros de entrada).

`save_next`é necessário seguir um par de registro de gravação volátil de int `save_regp`ou `save_regp_x`FP `save_fregp`: `save_fregp_x`, `save_r19r20_x`,,, `save_next`ou outro. Ele salva o próximo par de registro no próximo slot de 16 bytes na ordem "crescente". Um `save_next` refere-se ao primeiro par de registro de FP quando `save-next` segue o que denota o último par de registros int.

Como o tamanho das instruções de retorno e de salto regulares são os mesmos, não há necessidade de um `end` código de desenrolamento separado para cenários de chamada final.

`end_c`foi projetado para manipular fragmentos de função não contíguos para fins de otimização. Um `end_c` que indica o fim dos códigos de desenrolamento no escopo atual deve ser seguido por outra série de código de desenrolação terminada com um real `end`. Os códigos de liberação `end_c` entre `end` e representam as operações de prólogo na região pai (prólogo "fantasma").  Mais detalhes e exemplos são descritos na seção abaixo.

### <a name="packed-unwind-data"></a>Dados de desenrolamento compactados

Para funções cujos Prologs e epilogs seguem o formato canônico descrito abaixo, os dados de desenrolamento compactados podem ser usados. Ele elimina a necessidade de um registro. xdata totalmente e reduz significativamente o custo de fornecer dados desenrolados. Os Prologs canônicos e os epilogs são projetados para atender aos requisitos comuns de uma função simples: um que não requer um manipulador de exceção e que faça suas operações de configuração e desmontagem em uma ordem padrão.

O formato de um registro. pData com dados de desenrolamento compactados tem esta aparência:

![. pData registro com dados de desenrolamento compactados](media/arm64-exception-handling-packed-unwind-data.png ". pData registro com dados de desenrolamento compactados")

Os campos são os seguintes:

- O **RVA de início de função** é o rva de 32 bits do início da função.
- **Sinalizador** é um campo de 2 bits, conforme descrito acima, com os seguintes significados:
  - 00 = dados de desenrolamento compactados não usados; bits restantes apontam para um registro. xdata
  - 01 = dados de desenrolamento compactados usados com um único prólogo e epílogo no início e no final do escopo
  - 10 = dados de desenrolamento compactados usados para o código sem nenhum prólogo e epílogo. Útil para descrever segmentos de função separados
  - 11 = reservado.
- O **comprimento da função** é um campo de 11 bits que fornece o comprimento da função inteira em bytes, dividido por 4. Se a função for maior que 8K, um registro Full. xdata deverá ser usado em seu lugar.
- O **tamanho do quadro** é um campo de 9 bits que indica o número de bytes de pilha alocados para essa função, dividido por 16. Funções que alocam mais de (8K-16) bytes de pilha devem usar um registro Full. xdata. Ele inclui a área da variável local, a área de parâmetros de saída, a área de chamada int e FP salvas e a área de parâmetros de página inicial, mas exclui a área de alocação dinâmica.
- **CR** é um sinalizador de 2 bits que indica se a função inclui instruções adicionais para configurar uma cadeia de quadros e o link de retorno:
  - 00 = função não encadeada, \<x29, o par de> LR não é salvo na pilha.
  - 01 = função não encadeada, \<a LR> é salva na pilha
  - 10 = reservado;
  - 11 = função encadeada, uma instrução de par de armazenamento/carga é usada em prólogo \</epílogo x29, LR>
- **H** é um sinalizador de 1 bit que indica se a função coloca o parâmetro inteiro registrado (x0-120) armazenando-os no início da função. (0 = não registra os registros em casa, 1 = residências).
- **RegI** é um campo de 4 bits que indica o número de registros int não volátil (x19-x28) salvos no local da pilha canônica.
- **RegF** é um campo de 3 bits que indica o número de registros FP não voláteis (D8-D15) salvos no local da pilha canônica. (RegF = 0: nenhum registro de FP é salvo; RegF>0: RegF + 1 registros de FP são salvos). Os dados de desenrolamento compactados não podem ser usados para a função que salvam apenas um registro de FP.

Os logs canônicos que se enquadram nas categorias 1, 2 (sem a área de parâmetro de saída), 3 e 4 na seção acima podem ser representados pelo formato de desenrolamento embalado.  O epilogs para funções canônicas segue um formato semelhante, exceto **H** não tem efeito, `set_fp` a instrução é omitida e a ordem das etapas e as instruções em cada etapa são revertidas no epílogo. O algoritmo para o pacote. xdata segue estas etapas, detalhadas na tabela a seguir:

Etapa 0: pré-computação do tamanho de cada área.

Etapa 1: salvar int Callum-registros salvos.

Etapa 2: esta etapa é específica para o tipo 4 nas seções iniciais. a LR é salva no final da área de int.

Etapa 3: salvar os registros de chamada FP-Saved.

Etapa 4: salvar os argumentos de entrada na área de parâmetros de início.

Etapa 5: alocar a pilha restante, incluindo a \<área local, x29, LR> par e a área de parâmetro de saída. 5a corresponde ao tipo canônico 1. 5b e 5C são para o tipo canônico 2. 5D e 5e são para o tipo 3 e o tipo 4.

Etapa nº|Valores de sinalizador|n º de instruções|Opcode|Código de desenrolamento
-|-|-|-|-
0|||`#intsz = RegI * 8;`<br/>`if (CR==01) #intsz += 8; // lr`<br/>`#fpsz = RegF * 8;`<br/>`if(RegF) #fpsz += 8;`<br/>`#savsz=((#intsz+#fpsz+8*8*H)+0xf)&~0xf)`<br/>`#locsz = #famsz - #savsz`|
1|0 < **RegI** <= 10|RegIt/2 + **regi** %2|`stp x19,x20,[sp,#savsz]!`<br/>`stp x21,x22,[sp,#16]`<br/>`...`|`save_regp_x`<br/>`save_regp`<br/>`...`
2|**CR**= = 01 *|1|`str lr,[sp,#(intsz-8)]`\*|`save_reg`
3|0 < **RegF** <= 7|(RegF + 1)/2 +<br/>(RegF + 1) %2)|`stp d8,d9,[sp,#intsz]`\*\*<br/>`stp d10,d11,[sp,#(intsz+16)]`<br/>`...`<br/>`str d(8+RegF),[sp,#(intsz+fpsz-8)]`|`save_fregp`<br/>`...`<br/>`save_freg`
4|**H** = = 1|4|`stp x0,x1,[sp,#(intsz+fpsz)]`<br/>`stp x2,x3,[sp,#(intsz+fpsz+16)]`<br/>`stp x4,x5,[sp,#(intsz+fpsz+32)]`<br/>`stp x6,x7,[sp,#(intsz+fpsz+48)]`|`nop`<br/>`nop`<br/>`nop`<br/>`nop`
5a|**CR** = = 11 &&  # locsz<br/> <= 512|2|`stp x29,lr,[sp,#-locsz]!`<br/>`mov x29,sp`\*\*\*|`save_fplr_x`<br/>`set_fp`
5b|**CR** = = 11 &&<br/>512 < #locsz <= 4080|3|`sub sp,sp,#locsz`<br/>`stp x29,lr,[sp,0]`<br/>`add x29,sp,0`|`alloc_m`<br/>`save_fplr`<br/>`set_fp`
5C|**CR** = = 11 &&  # locsz > 4080|4|`sub sp,sp,4080`<br/>`sub sp,sp,#(locsz-4080)`<br/>`stp x29,lr,[sp,0]`<br/>`add x29,sp,0`|`alloc_m`<br/>`alloc_s`/`alloc_m`<br/>`save_fplr`<br/>`set_fp`
5D|(**CR** = = 00 \| \| **CR**= = 01)  &&<br/>#locsz <= 4080|1|`sub sp,sp,#locsz`|`alloc_s`/`alloc_m`
5E|(**CR** = = 00 \| \| **CR**= = 01)  &&<br/>#locsz > 4080|2|`sub sp,sp,4080`<br/>`sub sp,sp,#(locsz-4080)`|`alloc_m`<br/>`alloc_s`/`alloc_m`

\*Se **CR** = = 01 e **RegI** for um número ímpar, a etapa 2 e a última save_rep na etapa 1 serão mescladas em uma save_regp.

\*\*Se **RegI** == **CR** = = 0 e **RegF** ! = 0, o primeiro STP para o ponto flutuante fará a predecrementação.

\*\*\*Nenhuma instrução correspondente a `mov x29,sp` está presente no epílogo. Os dados desenrolados compactados não poderão ser usados se uma função exigir a restauração do SP de x29.

### <a name="unwinding-partial-prologs-and-epilogs"></a>Desenrolar Prologs parciais e epilogs

A situação de desenrolamento mais comum é aquela na qual ocorre a exceção ou chamada no corpo da função, longe do prólogo e de todos os epilogs. Nessa situação, o desenrolamento é simples: o desenrolador simplesmente começa a executar os códigos na matriz de desenrolamento que começa no índice 0 e continua até que um opcode final seja detectado.

É mais difícil desenrolar corretamente no caso em que ocorre uma exceção ou interrupção durante a execução de um prólogo ou epílogo. Nessas situações, o quadro de pilhas é apenas parcialmente construído. O problema é determinar exatamente o que foi feito, para desfazê-lo corretamente.

Por exemplo, use este prólogo e a sequência epílogo:

```asm
0000:    stp    x29,lr,[sp,#-256]!          // save_fplr_x  256 (pre-indexed store)
0004:    stp    d8,d9,[sp,#224]             // save_fregp 0, 224
0008:    stp    x19,x20,[sp,#240]           // save_regp 0, 240
000c:    mov    x29,sp                      // set_fp
         ...
0100:    mov    sp,x29                      // set_fp
0104:    ldp    x19,x20,[sp,#240]           // save_regp 0, 240
0108:    ldp    d8,d9,[sp,224]              // save_fregp 0, 224
010c:    ldp    x29,lr,[sp],#256            // save_fplr_x  256 (post-indexed load)
0110:    ret    lr                          // end
```

Ao lado de cada opcode está o código de liberação apropriado que descreve essa operação. Você pode ver como a série de códigos de liberação para o prólogo é uma imagem de espelho exata dos códigos de liberação para o epílogo (não contando a instrução final do epílogo). É uma situação comum, e é por isso que sempre assumimos que os códigos de desenrolação do prólogo são armazenados na ordem inversa da ordem de execução do prólogo.

Portanto, para o prólogo e o epílogo, deixamos um conjunto comum de códigos de desenrolamento:

`set_fp`, `save_regp 0,240`, `save_fregp,0,224`, `save_fplr_x_256`, `end`

O caso epílogo é simples, pois está em ordem normal. Começando com o deslocamento 0 dentro do epílogo (que começa no deslocamento 0x100 na função), esperamos executar a sequência de liberação completa, pois nenhuma limpeza foi feita ainda. Se encontrarmos uma instrução em (no deslocamento 2 no epílogo), podemos desenrolar com êxito ignorando o primeiro código de desenrolamento. Podemos generalizar essa situação e assumir um mapeamento de 1:1 entre opcodes e códigos de desenrolamento. Em seguida, para começar a desenrolar da instrução *n* no epílogo, devemos ignorar os primeiros *n* códigos de desenrolamento e começar a executar a partir daí.

Acontece que uma lógica semelhante funciona para o prólogo, exceto em ordem inversa. Se começarmos a desenrolar do deslocamento 0 no prólogo, queremos executar nada. Se desenrolar do deslocamento 2, que é uma instrução no, queremos começar a executar a sequência de liberação um código de liberação a partir do final. (Lembre-se de que os códigos são armazenados em ordem inversa). E aqui também podemos generalizar: se começarmos a desenrolar da instrução n no prólogo, devemos começar a executar n códigos de desenrolamento a partir do final da lista de códigos.

Nem sempre é o caso de os códigos prólogo e epílogo coincidirem exatamente. É por isso que a matriz de desenrolamento pode precisar conter várias sequências de códigos. Para determinar o deslocamento de onde começar a processar códigos, use a seguinte lógica:

1. Se estiver desenrolando no corpo da função, comece a executar códigos de liberação no índice 0 e continue até atingir um opcode "final".

1. Se estiver desenrolando de dentro de um epílogo, use o índice inicial específico de epílogo fornecido com o escopo epílogo como um ponto de partida. Calcule quantos bytes o PC em questão é do início do epílogo. Em seguida, avance pelos códigos de liberação, ignorando códigos de liberação até que todas as instruções já executadas sejam contadas. Em seguida, execute a partir desse ponto.

1. Se estiver desenrolando no prólogo, use o índice 0 como ponto de partida. Calcule o comprimento do código de prólogo da sequência e, em seguida, calcule quantos bytes o PC em questão é do final do prólogo. Em seguida, avance pelos códigos de liberação, ignorando códigos de liberação até que todas as instruções ainda não executadas sejam contadas. Em seguida, execute a partir desse ponto.

Essas regras significam que os códigos de liberação para o prólogo devem sempre ser o primeiro na matriz. E também são os códigos usados para desenrolar no caso geral de desenrolar de dentro do corpo. As sequências de código específicas do epílogo devem seguir imediatamente após.

### <a name="function-fragments"></a>Fragmentos de função

Para fins de otimização de código e outros motivos, pode ser preferível dividir uma função em fragmentos separados (também chamadas de regiões). Quando dividida, cada fragmento de função resultante requer seu próprio registro. pData (e possivelmente. xdata) separado.

Para cada fragmento secundário separado que tenha seu próprio prólogo, espera-se que nenhum ajuste de pilha seja feito em seu prólogo. Todo o espaço de pilha exigido por uma região secundária deve ser previamente alocado por sua região pai (ou chamada de região de host). Isso mantém estritamente a manipulação do ponteiro de pilha no prólogo original da função.

Um caso típico de fragmentos de função é "separação de código" com esse compilador pode mover uma região de código para fora de sua função de host. Há três casos incomuns que podem ser resultantes pela separação de código.

#### <a name="example"></a>Exemplo

- (região 1: início)

    ```asm
        stp     x29,lr,[sp,#-256]!      // save_fplr_x  256 (pre-indexed store)
        stp     x19,x20,[sp,#240]       // save_regp 0, 240
        mov     x29,sp                  // set_fp
        ...
    ```

- (região 1: fim)

- (região 3: início)

    ```asm
        ...
    ```

- (região 3: fim)

- (região 2: início)

    ```asm
        ...
        mov     sp,x29                  // set_fp
        ldp     x19,x20,[sp,#240]       // save_regp 0, 240
        ldp     x29,lr,[sp],#256        // save_fplr_x  256 (post-indexed load)
        ret     lr                      // end
    ```

- (região 2: fim)

1. Somente Prólogo (região 1: todas as epilogs estão em regiões separadas):

   Somente o prólogo deve ser descrito. Isso não pode ser representado no formato Compact. pData. No caso Full. xdata, ele pode ser representado pela definição de epílogo Count = 0. Consulte a região 1 no exemplo acima.

   Códigos de liberação `set_fp`: `save_regp 0,240`, `save_fplr_x_256`, `end`,.

1. Somente epilogs (região 2: prólogo está na região do host)

   Supõe-se que, pelo controle de tempo que salta nessa região, todos os códigos de prólogo foram executados. O desenrolamento parcial pode ocorrer em epilogs da mesma maneira que em uma função normal. Esse tipo de região não pode ser representado por Compact. pData. No registro Full. xdata, ele pode ser codificado com um prólogo "fantasma", com colchetes por `end_c` um `end` par de códigos e desenrolar.  A entrelinha `end_c` indica que o tamanho de prólogo é zero. Epílogo o índice inicial dos pontos de epílogo únicos `set_fp`para.

   Código de desenrolamento para `end_c`a `set_fp`região `save_regp 0,240`2 `save_fplr_x_256`: `end`,,,,.

1. Nenhum Prologs ou epilogs (região 3: os logs e todas as epilogs estão em outros fragmentos):

   O formato Compact. pData pode ser aplicado por meio da configuração Flag = 10. Com o registro Full. xdata, contagem de epílogo = 1. O código de desenrolamento é o mesmo que o código para a região 2 acima, mas o `end_c`índice de início epílogo também aponta para. O desenrolamento parcial nunca ocorrerá nesta região de código.

Outro caso mais complicado de fragmentos de função é "disposição de redução". O compilador pode optar por atrasar o salvamento de alguns registradores do receptor salvo até fora do prólogo da entrada da função.

- (região 1: início)

    ```asm
        stp     x29,lr,[sp,#-256]!      // save_fplr_x  256 (pre-indexed store)
        stp     x19,x20,[sp,#240]       // save_regp 0, 240
        mov     x29,sp                  // set_fp
        ...
    ```

- (região 2: início)

    ```asm
        stp     x21,x22,[sp,#224]       // save_regp 2, 224
        ...
        ldp     x21,x22,[sp,#224]       // save_regp 2, 224
    ```

- (região 2: fim)

    ```asm
        ...
        mov     sp,x29                  // set_fp
        ldp     x19,x20,[sp,#240]       // save_regp 0, 240
        ldp     x29,lr,[sp],#256        // save_fplr_x  256 (post-indexed load)
        ret     lr                      // end
    ```

- (região 1: fim)

No prólogo da região 1, o espaço da pilha é pré-alocado. Você pode ver que a região 2 terá o mesmo código de desenrolação mesmo que ele seja movido para fora de sua função de host.

A região 1 `set_fp`: `save_regp 0,240`, `save_fplr_x_256`, `end` , com o índice de início `set_fp` epílogo aponta para como de costume.

Região 2: `save_regp 2, 224`, `end_c` `set_fp` `save_regp 0,240`,,, `save_fplr_x_256`, `end`. Epílogo Iniciar índice aponta para o primeiro código `save_regp 2, 224`de desenrolar.

### <a name="large-functions"></a>Funções grandes

Os fragmentos podem ser usados para descrever funções maiores do que o limite de 1M imposto pelos campos de bits no cabeçalho. xdata. Para descrever uma função muito grande como essa, ela precisa ser dividida em fragmentos menores que 1 milhão. Cada fragmento deve ser ajustado para que ele não divida um epílogo em várias partes.

Somente o primeiro fragmento da função conterá um prólogo; todos os outros fragmentos são marcados como sem prólogo. Dependendo do número de epilogs presentes, cada fragmento pode conter zero ou mais epilogs. Tenha em mente que cada escopo de epílogo em um fragmento especifica seu deslocamento inicial relativo ao início do fragmento, não ao início da função.

Se um fragmento não tiver prólogo e nenhum epílogo, ele ainda exigirá seu próprio registro. pData (e possivelmente. xdata) para descrever como desenrolar de dentro do corpo da função.

## <a name="examples"></a>Exemplos

### <a name="example-1-frame-chained-compact-form"></a>Exemplo 1: estrutura encadeada, formato compacto

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

### <a name="example-2-frame-chained-full-form-with-mirror-prolog--epilog"></a>Exemplo 2: encadeamento de quadros, formulário completo com prólogo de espelho & epílogo

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

Epílogo Start index [0] aponta para a mesma sequência de código de desenrolamento de prólogo.

### <a name="example-3-variadic-unchained-function"></a>Exemplo 3: Variadic função não encadeada

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

Epílogo Start index [4] aponta para o meio do código de desenrolamento de prólogo (parcialmente, reutiliza a matriz de desenrolamento).

## <a name="see-also"></a>Confira também

[Visão geral das convenções da ABI ARM64](arm64-windows-abi-conventions.md)<br/>
[Manipulação de exceção do ARM](arm-exception-handling.md)
