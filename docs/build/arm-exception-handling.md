---
title: Tratamento de exceção do ARM | Microsoft Docs
ms.custom: ''
ms.date: 07/11/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: fe0e615f-c033-4ad5-97f4-ff96af45b201
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e4ce0ef6ba923332d03972e2bd8b7ebb1f1cfb9e
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43205697"
---
# <a name="arm-exception-handling"></a>Tratamento de exceção ARM

O Windows baseado em ARM usa o mesmo mecanismo de tratamento de exceção estruturado para exceções geradas por hardware assíncronas e exceções geradas por software síncronas. Os manipuladores de exceção específicos da linguagem são compilados sobre o tratamento de exceção estruturado do Windows usando funções de auxiliares da linguagem. Este documento descreve o tratamento de exceção no Windows em ARM e os auxiliares da linguagem usados pelo código que é gerado pelo assembler Microsoft ARM e o compilador do Visual C++.

## <a name="arm-exception-handling"></a>Tratamento de exceção ARM

Usa o Windows em ARM *códigos de desenrolamento* para controlar o desenrolamento de pilha durante [manipulação de exceção estruturada](https://msdn.microsoft.com/library/windows/desktop/ms680657) (SEH). Os códigos de desenrolamento são uma sequência de bytes armazenados na seção .xdata da imagem executável. Eles descrevem a operação de código de prólogo e epílogo da função de uma maneira abstrata, para que os efeitos do prólogo de uma função possam ser desfeitos na preparação para desenrolar para o registro de ativação do chamador.

A EABI (interface binária do aplicativo inserido) do ARM especifica um modelo de desenrolamento de exceção que usa códigos de desenrolamento, mas que não é suficiente para que o SEH desenrole no Windows, o qual deve manipular casos assíncronos em que o processador esteja no meio do prólogo ou do epílogo de uma função. O Windows também separa o controle de desenrolamento em desenrolamento no nível de função e em desenrolamento de escopo específico da linguagem, o qual é unificado na EABI do ARM. Por esses motivos, o Windows baseado em ARM especifica mais detalhes para os dados e o procedimento de desenrolamento.

### <a name="assumptions"></a>Suposições

As imagens executáveis do Windows baseado em ARM usam o formato PE (executável portátil). Para obter mais informações, consulte [especificação Microsoft PE e COFF](http://go.microsoft.com/fwlink/p/?linkid=84140). As informações de tratamento de exceção são armazenadas nas seções .pdata e .xdata da imagem.

O mecanismo de tratamento de exceção faz determinadas suposições sobre código que segue a ABI para Windows baseado em ARM:

- Quando ocorre uma exceção dentro do corpo de uma função, não importa se as operações de prólogo são desfeitas ou se as operações de epílogo são executadas de uma maneira direta. Ambas devem produzir resultados idênticos.

- Os prólogos e epílogos tendem a refletir um ao outro. Isso pode ser usado para reduzir o tamanho dos metadados necessários para descrever o desenrolamento.

- As funções tendem a ser relativamente pequenas. Várias otimizações contam com isso para uma obter uma compactação de dados eficiente.

- Se uma condição for colocada em um epílogo, ela se aplicará igualmente a todas as instruções do epílogo.

- Se um ponteiro de pilha (SP) for salvo em outro registro no prólogo, esse registro deverá permanecer inalterado por toda a função, de modo que o SP original possa ser recuperado a qualquer momento.

- A menos que o SP seja salvo em outro registro, toda a manipulação dele deverá ocorrer rigorosamente dentro do prólogo e do epílogo.

- Para desenrolar qualquer registro de ativação, estas operações são necessárias:

  - Ajustar r13 (SP) em incrementos de 4 bytes.

  - Remover um ou mais registros de inteiros.

  - Remover um ou mais registros de VFP (ponto flutuante virtual).

  - Copiar um valor de registro arbitrário para r13 (SP).

  - Carregar SP da pilha usando uma pequena operação pós-decremento.

  - Analisar alguns desses tipos de quadro bem definidos.

### <a name="pdata-records"></a>Registros .pdata

Os registros .pdata em uma imagem de formato PE são uma matriz ordenada de itens de comprimento fixo que descrevem cada função de manipulação de pilha. Funções folha, que são funções que não chamam outras funções, não requerem registros .pdata quando não manipulam a pilha. (Ou seja, elas não requerem nenhum armazenamento local e não precisam salvar ou restaurar registros não voláteis). Os registros para essas funções podem ser omitidos a partir da seção .pdata para economizar espaço. Uma operação de desenrolamento de uma dessas funções pode apenas copiar o endereço de retorno do Registro do Link (LR) para o contador do programa (PC) para mover o chamador para cima.

Cada registro .pdata do ARM tem 8 bytes de comprimento. O formato geral de um registro coloca o endereço virtual relativo (RVA) do início da função na primeira palavra de 32 bits, seguido por uma segunda palavra que contém um ponteiro para um bloco .xdata de comprimento variável ou uma palavra compactada que descreve uma sequência de desenrolamento de função canônica, conforme mostrado nesta tabela:

|Deslocamento da palavra|Bits|Finalidade|
|-----------------|----------|-------------|
|0|0-31|*Função RVA iniciar* é o RVA de 32 bits do início da função. Se a função contiver código de posição, o bit baixo deste endereço deverá ser configurado.|
|1|0-1|*Sinalizador* é um campo de 2 bits que indica como interpretar os 30 bits restantes da segunda palavra. pData. Se *sinalizador* for 0, então os bits restantes formam um *RVA de informações de exceção* (com os dois bits baixos sendo implicitamente 0). Se *sinalizador* for diferente de zero, em seguida, os bits restantes formam um *dados de desenrolamento compactados* estrutura.|
|1|2-31|*Informações de exceção RVA* ou *empacotadas desenrolar dados*.<br /><br /> *RVA de informações de exceção* é o endereço da estrutura de informações de exceção de comprimento variável, armazenado na seção. XData. Esses dados devem ser alinhados para 4 bytes.<br /><br /> *Empacotadas desenrolar dados* é a descrição compactada das operações necessárias para desenrolar a partir de uma função, supondo uma forma canônica. Nesse caso, nenhum registro .xdata é necessário.|

### <a name="packed-unwind-data"></a>Dados de desenrolamento compactados

Para funções cujos prólogos e epílogos seguem a forma canônica descrita abaixo, os dados de desenrolamento compactados podem ser usados. Isso elimina a necessidade de um registro .xdata e reduz significativamente o espaço necessário para fornecer dados de desenrolamento. Os prólogos e epílogos canônicos são projetados para atender aos requisitos comuns de uma função simples que não requer um manipulador de exceção e executa suas operações de configuração e desmontagem em uma ordem padrão.

Esta tabela mostra o formato de um registro .pdata que possui dados de desenrolamento compactados:

|Deslocamento da palavra|Bits|Finalidade|
|-----------------|----------|-------------|
|0|0-31|*Função RVA iniciar* é o RVA de 32 bits do início da função. Se a função contiver código de posição, o bit baixo deste endereço deverá ser configurado.|
|1|0-1|*Sinalizador* é um campo de 2 bits que possui estes significados:<br /><br /> -00 = compactado desenrolar dados não usados; bits restantes apontam para o registro. XData.<br />-01 = compactado dados de desenrolamento.<br />-10 = compactado dados no qual a função deve para ter nenhum prólogo de desenrolamento. É útil para descrever fragmentos de função que são descontínuos com o início da função.<br />-11 = reservado.|
|1|2-12|*Função comprimento* é um campo de 11 bits que fornece o comprimento da função inteira em bytes dividido por 2. Se a função tiver mais de 4K bytes, um registro completo de .xdata deverá ser usado no lugar.|
|1|13-14|*RET* é um campo de 2 bits que indica como a função retorna:<br /><br /> -00 = retorno via pop {pc} (o *L* bit de sinalizador deve ser definida como 1 nesse caso).<br />-01 = retorno usando uma ramificação de 16 bits.<br />-10 = retorno usando uma ramificação de 32 bits.<br />-11 = nenhum epílogo em todos os. É útil para descrever um fragmento de função descontínuo que pode conter somente um prólogo, mas cujo epílogo está em outro lugar.|
|1|15|*H* é um sinalizador de 1 bit que indica se a função "hospeda" o parâmetro numérico inteiro registra (r0-r3) enviando-os no início da função e desaloca os 16 bytes de pilha antes de retornar. (0 = não hospeda registros, 1 = hospeda registros.)|
|1|16-18|*Reg* é salvo de um campo de 3 bits que indica o índice do último registro não volátil. Se o *R* bit for 0, então, apenas registros de inteiros estão sendo salvas e devem para estar no intervalo de r4-rN, onde N é igual a 4 + *Reg*. Se o *R* bit for 1, em seguida, registros de ponto flutuante só estão sendo salvas e devem para estar no intervalo de d8-dN, onde N é igual a 8 + *Reg*. A combinação especial de *R* = 1 e *Reg* = 7 indica que nenhum registro será salvo.|
|1|19|*R* é um sinalizador de 1 bit que indica se os registros não voláteis salvos são registros de inteiros (0) ou registros de ponto flutuante (1). Se *R* é definido como 1 e o *Reg* é definido como 7, não há registros não voláteis foram enviados por push.|
|1|20|*L* é um sinalizador de 1 bit que indica se a função salva/restaura LR, junto com outros registros indicados pelo *Reg* campo. (0 = não salva/restaura, 1 = salva/restaura.)|
|1|21|*C* é um sinalizador de 1 bit que indica se a função inclui instruções extras para configurar uma cadeia de quadros de pilha com rapidez percorrer (1) ou não (0). Se este bit estiver configurado, r11 será implicitamente adicionado à lista de registros não voláteis de inteiros salvos. (Consulte as restrições abaixo se o *C* sinalizador é usado.)|
|1|22-31|*Ajuste de pilha* é um campo de 10 bits que indica o número de bytes de pilha que são alocados para esta função, dividido por 4. No entanto, apenas valores entre 0x000-0x3F3 podem ser codificados diretamente. As funções que alocam mais de 4044 bytes de pilha devem usar um registro completo de .xdata. Se o *ajuste de pilha* campo é 0x3F4 ou maior, então os 4 bits baixos têm significado especial:<br /><br /> -Bits 0-1 indicam o número de palavras de ajuste de pilha (1-4) menos 1.<br />-Bit 2 é definido como 1 se o prólogo combinou esse ajuste em sua operação de envio por push.<br />-3 bit é definido como 1 se o epílogo combinou esse ajuste em sua operação pop.|

Devido a possíveis redundâncias nas codificações acima, estas restrições se aplicam:

- Se o *C* sinalizador é definido como 1:

   - O *L* sinalizador também deve ser definido como 1, porque o encadeamento de quadros exigia r11 e LR.

   - r11 não deve ser incluído no conjunto de registros descrito por *Reg*. Ou seja, se r4-r11 é enviados por push, *Reg* deverá descrever apenas r4-r10, pois o *C* o sinalizador implica r11.

- Se o *Ret* campo é definido como 0, o *L* sinalizador deve ser definido como 1.

A violação dessas restrições causará uma sequência incompatível.

Para fins da discussão abaixo, dois pseudossinalizadores são derivados *ajuste de pilha*:

- *PF* ou "dobramento de prólogo" indica que *ajuste de pilha* é 0x3F4 ou maior e o bit 2 está configurado.

- *O EF* ou "dobramento de epílogo" indica que *ajuste de pilha* é 0x3F4 ou maior e o bit 3 está configurado.

Os prólogos para funções canônicas podem ter até 5 instruções (observe que 3a e 3b são mutuamente exclusivas):

|Instrução|Supõe-se que Opcode esteja presente se:|Tamanho|Opcode|Códigos de desenrolamento|
|-----------------|-----------------------------------|----------|------------|------------------|
|1|*H*= = 1|16|`push {r0-r3}`|04|
|2|*C*= = 1 ou *L*= = 1 ou *R*= = 0 ou PF==1 = = 1|16/32|`push {registers}`|80-BF/D0-DF/EC-ED|
|3a|*C*= = 1 e (*L*= = 0 e *R*= = 1 e PF==0 = = 0)|16|`mov r11,sp`|C0-CF/FB|
|3b|*C*= = 1 e (*L*= = 1 ou *R*= = 0 ou PF==1 = = 1)|32|`add r11,sp,#xx`|FC|
|4|*R*= = 1 e *Reg* ! = 7|32|`vpush {d8-dE}`|E0-E7|
|5|*Ajuste de pilha* ! = 0 e PF = = 0|16/32|`sub sp,sp,#xx`|00-7F/E8-EB|

Instrução 1 estará sempre presente se o *H* bit é definido como 1.

Para configurar o encadeamento de quadros, a instrução 3a ou 3b está presente se o *C* bit é definido. Ele será um `mov` de 16 bits se nenhum registro diferente de r11 e LR for enviado por push, caso contrário, será um `add` de 32 bits.

Se um ajuste não dobrado for especificado, a instrução 5 será o ajuste de pilha explícito.

As instruções 2 e 4 são configuradas com base na necessidade de um envio por push. Esta tabela resume quais registros são salvos com base nas *C*, *L*, *R*, e *PF* campos. Em todos os casos, *N* é igual a *Reg* + 4, *eletrônico* é igual a *Reg* + 8, e *S* é igual a (~*Ajuste de pilha*) & 3.

|C|L|R|PF|Registros de inteiro enviados por push|Registros VFP enviados por push|
|-------|-------|-------|--------|------------------------------|--------------------------|
|0|0|0|0|R4-r*N*|nenhum|
|0|0|0|1|r*S*- r*N*|nenhum|
|0|0|1|0|nenhum|D8-d*E*|
|0|0|1|1|r*S*-r3|D8-d*E*|
|0|1|0|0|R4-r*N*, LR|nenhum|
|0|1|0|1|r*S*- r*N*, LR|nenhum|
|0|1|1|0|LR|D8-d*E*|
|0|1|1|1|r*S*-r3, LR|D8-d*E*|
|1|0|0|0|R4-r*N*, r11|nenhum|
|1|0|0|1|r*S*- r*N*, r11|nenhum|
|1|0|1|0|r11|D8-d*E*|
|1|0|1|1|r*S*-r3, r11|D8-d*E*|
|1|1|0|0|R4-r*N*, r11, LR|nenhum|
|1|1|0|1|r*S*- r*N*, r11, LR|nenhum|
|1|1|1|0|r11, LR|D8-d*E*|
|1|1|1|1|r*S*-r3, r11, LR|D8-d*E*|

Os epílogos para funções canônicas seguem uma forma semelhante, mas na ordem inversa e com algumas opções adicionais. O epílogo pode ter até 5 instruções de comprimento e sua forma é estritamente ditada pela forma do prólogo.

|Instrução|Supõe-se que Opcode esteja presente se:|Tamanho|Opcode|
|-----------------|-----------------------------------|----------|------------|
|6|*Ajuste de pilha*! = 0 e *EF*= = 0|16/32|`add   sp,sp,#xx`|
|7|*R*= = 1 e *Reg*! = 7|32|`vpop  {d8-dE}`|
|8|*C*= = 1 ou (*L*= = 1 e *H*= = 0) ou *R*= = 0 ou *EF*= = 1|16/32|`pop   {registers}`|
|9a|*H*= = 1 e *L*= = 0|16|`add   sp,sp,#0x10`|
|9b|*H*= = 1 e *L*= = 1|32|`ldr   pc,[sp],#0x14`|
|10a|*RET*= = 1|16|`bx    reg`|
|10b|*RET*= = 2|32|`b     address`|

A instrução 6 será o ajuste de pilha explícito se um ajuste não dobrado for especificado. Porque *PF* é independente da *EF*, é possível ter a instrução 5 presente sem a instrução 6, ou vice-versa.

Instruções 7 e 8 usam a mesma lógica de prólogo para determinar quais registros são restaurados da pilha, mas com essas duas alterações: primeira, *EF* é usado no lugar de *PF*; segunda, se *Ret*  = 0, então LR será substituído por PC na lista de registros e o epílogo terminará imediatamente.

Se *H* for definida, a instrução 9a ou 9b estará presente. Instrução 9a será usada quando *L* é 0, para indicar que o LR não está na pilha. Nesse caso, a pilha é ajustada manualmente e *Ret* deve ser 1 ou 2 para especificar um retorno explícito. Instrução 9b será usada quando *L* é 1 para indicar um término antecipado para o epílogo e para retornar e ajustar a pilha ao mesmo tempo.

Se o epílogo não tiver terminado ainda, a instrução 10a ou 10b estará presente, para indicar uma ramificação de 16 bits ou 32 bits, com base no valor de *Ret*.

### <a name="xdata-records"></a>Registros .xdata

Quando o formato de desenrolamento compactado for insuficiente para descrever o desenrolamento de uma função, um registro .xdata de comprimento variável deverá ser criado. O endereço desse registro é armazenado na segunda palavra do registro .pdata. O formato do .xdata é um conjunto de palavras de comprimento variável compactado que possui quatro seções:

1. Um cabeçalho com 1 ou 2 palavras que descreve o tamanho geral da estrutura .xdata e fornece dados de função-chave. A segunda palavra estará presente somente se o *contagem de epílogo* e *código palavras* campos são definidos como 0. Os campos estão divididos nesta tabela:

   |Palavra|Bits|Finalidade|
    |----------|----------|-------------|
    |0|0-17|*Função comprimento* é um campo de 18 bits que indica o comprimento total da função em bytes dividido por 2. Se uma função tiver mais de 512 KB, então vários registros de .pdata e .xdata deverão ser usados para descrever a função. Para obter detalhes, consulte a seção Funções Grandes neste documento.|
    |0|18-19|*Vers* é um campo de 2 bits que descreve a versão dos xdata restantes. Apenas a versão 0 está definida atualmente; os valores de 1 a 3 são reservados.|
    |0|20|*X* é um campo de 1 bit que indica a presença (1) ou a ausência (0) de dados de exceção.|
    |0|21|*E* é um campo de 1 bit que indica que as informações que descrevem um único epílogo é compactadas no cabeçalho (1) em vez de exigir o escopo adicional palavras posterior (0).|
    |0|22|*F* é um campo de 1 bit que indica que esse registro descreve um fragmento de função (1) ou uma função completa (0). Um fragmento implica que não há prólogo e que todo o processamento do prólogo deve ser ignorado.|
    |0|23-27|*Contagem de epílogo* é um campo de 5 bits que tem dois significados, dependendo do estado do *eletrônico* bit:<br /><br /> -Se *eletrônico* é 0, esse campo é uma contagem do número total de escopos de exceção descrita na seção 3. Se mais de 31 escopos existem na função, em seguida, esse campo e o *palavras código* campo deve ser definido como 0 para indicar que uma palavra de extensão é necessária.<br />-Se *eletrônico* é 1, este campo especifica o índice do primeiro código de desenrolamento que descreve o epílogo único.|
    |0|28-31|*Palavras de código* é um campo de 4 bits que especifica o número de palavras de 32 bits necessário para conter todos os códigos de desenrolamento na seção 4. Se mais de 15 palavras forem necessárias para mais de 63 bytes de código de desenrolamento, esse campo e o *contagem de epílogo* campo deve ser definido como 0 para indicar que uma palavra de extensão é necessária.|
    |1|0-15|*Estendido a contagem de epílogo* é um campo de 16 bits que fornece mais espaço para codificação de um número excepcionalmente grande de epílogos. A palavra de extensão que contém esse campo estará presente somente se o *contagem de epílogo* e *código palavras* campos da primeira palavra do cabeçalho são definidos como 0.|
    |1|16-23|*Estendido código palavras* é um campo de 8 bits que fornece mais espaço para codificação de um número excepcionalmente grande de palavras de código de desenrolamento. A palavra de extensão que contém esse campo estará presente somente se o *contagem de epílogo* e *código palavras* campos da primeira palavra do cabeçalho são definidos como 0.|
    |1|24-31|Reservado|

2. Depois que os dados de exceção (se o *eletrônico* bit no cabeçalho foi definido como 0) é uma lista de informações sobre escopos de epílogo, que são compactados um para uma palavra e armazenados em ordem crescente de deslocamento inicial. Cada escopo contém estes campos:

   |Bits|Finalidade|
    |----------|-------------|
    |0-17|*Deslocamento de início do epílogo* é um campo de 18 bits que descreve o deslocamento do epílogo, em bytes dividido por 2, em relação ao início da função.|
    |18-19|*Res* é um campo de 2 bits reservado para expansão futura. Seu valor deve ser 0.|
    |20-23|*Condição* é um campo de 4 bits que oferece a condição sob a qual o epílogo é executado. Para epílogos incondicionais, ele deve ser configurado como 0xE, que indica "sempre". (Um epílogo deve ser inteiramente condicional ou inteiramente incondicional, e no modo Posição 2, o epílogo começa com a primeira instrução após o opcode de TI.)|
    |24-31|*Índice de início do epílogo* é um campo de 8 bits que indica o índice de bytes do primeiro código de desenrolamento que descreve este epílogo.|

3. Após a lista de escopos de epílogo, é fornecida uma matriz de bytes que contém códigos de desenrolamento, que são descritos em detalhes na seção Códigos de Desenrolamento neste artigo. Essa matriz é preenchida no final, o mais próximo possível do limite da palavra completa. Os bytes são armazenados em ordem little-endian para que possam ser buscados diretamente no modo little-endian.

4. Se o *X* campo do cabeçalho é 1, os bytes de código de desenrolamento são seguidos pelas informações do manipulador de exceção. Isso consiste em uma *RVA de manipulador de exceção* que contém o endereço do manipulador de exceção, seguido imediatamente pela quantidade de dados exigidos pelo manipulador de exceção (comprimento variável).

O registro .xdata é projetado para que seja possível buscar os primeiros 8 bytes e calcular o tamanho total do registro, sem incluir o comprimento dos dados de exceção de tamanho variável que se segue. Este trecho de código calcula o tamanho do registro:

```cpp
ULONG ComputeXdataSize(PULONG *Xdata)
{
    ULONG EpilogueScopes;
    ULONG Size;
    ULONG UnwindWords;

    if ((Xdata[0] >> 23) != 0) {
        Size = 4;
        EpilogueScopes = (Xdata[0] >> 23) & 0x1f;
        UnwindWords = (Xdata[0] >> 28) & 0x0f;
    } else {
        Size = 8;
        EpilogueScopes = Xdata[1] & 0xffff;
        UnwindWords = (Xdata[1] >> 16) & 0xff;
    }

    if (!(Xdata[0] & (1 << 21))) {
        Size += 4 * EpilogueScopes;
    }
    Size += 4 * UnwindWords;
    if (Xdata[0] & (1 << 20)) {
        Size += 4;
    }
    return Size;
}
```

Embora o prólogo e cada epílogo tenha um índice nos códigos de desenrolamento, a tabela é compartilhada entre eles. Não é incomum que eles possam todos compartilhar os mesmos códigos de desenrolamento. Recomendamos que os gravadores de compiladores sejam otimizados para este caso, pois o maior índice que pode ser especificado é 255, o que limita o número total possível de códigos de desenrolamento para uma função específica.

### <a name="unwind-codes"></a>Códigos de desenrolamento

A matriz de códigos de desenrolamento é um conjunto de sequências de instruções que descreve exatamente como desfazer os efeitos do prólogo, na ordem em que as operações devem ser desfeitas. Os códigos de desenrolamento são um miniconjunto de instruções, codificado como uma cadeia de caracteres de bytes. Quando a execução estiver concluída, o endereço de retorno para a função de chamada estará no registro LR e todos os registros não voláteis serão restaurados para seus valores no momento em que a função foi chamada.

Se fosse garantido que exceções ocorressem sempre somente dentro de um corpo da função e nunca dentro do prólogo ou do epílogo, somente uma sequência de desenrolamento seria necessária. No entanto, o modelo de desenrolamento do Windows requer uma capacidade de desenrolar de dentro de um prólogo ou epílogo executado parcialmente. Para acomodar esse requisito, os códigos de desenrolamento foram projetados cuidadosamente para terem um mapeamento de um para um sem ambiguidade para cada opcode relevante no prólogo e no epílogo. Isso tem várias implicações:

- É possível calcular o comprimento do prólogo e do epílogo contando o número de códigos de desenrolamento. Isso é possível mesmo com instruções de Posição 2 de comprimento variável, pois existem mapeamentos distintos para opcodes de 16 e 32 bits.

- Pela contagem do número de instruções passadas no início de um escopo de epílogo, é possível ignorar o número equivalente de códigos de desenrolamento e executar o restante de uma sequência para concluir o desenrolamento executado parcialmente que o epílogo estava executando.

- Pela contagem do número de instruções antes do final do prólogo, é possível ignorar o número equivalente de códigos de desenrolamento e executar o restante da sequência para desfazer apenas aquelas partes do prólogo que tenham a execução concluída.

A tabela a seguir mostra o mapeamento de códigos de desenrolamento para opcodes. Os códigos mais comuns são os de apenas um byte, enquanto os menos comuns requerem dois, três ou mesmo quatro bytes. Cada código é armazenado do byte mais significativo ao byte menos significativo. A estrutura de código de desenrolamento difere da codificação descrita na EABI do ARM, pois esses códigos de desenrolamento são projetados para ter um mapeamento um para um para os opcodes no prólogo e no epílogo para permitir o desenrolar de prólogos e epílogos executados parcialmente.

|Byte 1|Byte 2|Byte 3|Byte 4|Tamanho de opcode|Explicação|
|------------|------------|------------|------------|------------|-----------------|
|00-7F||||16|`add   sp,sp,#X`<br /><br /> em que X é (código e 0x7F) \* 4|
|80-BF|00-FF|||32|`pop   {r0-r12, lr}`<br /><br /> em que LR será exibido se Código e 0x2000 e r0-r12 forem exibidos se o bit correspondente for configurado em Código e 0x1FFF|
|C0-CF||||16|`mov   sp,rX`<br /><br /> em que X é Código e 0x0F|
|D0-D7||||16|`pop   {r4-rX,lr}`<br /><br /> em que X é (Código e 0x03) + 4 e LR será exibido se Código e 0x04|
|D8-DF||||32|`pop   {r4-rX,lr}`<br /><br /> em que X é (Código e 0x03) + 8 e LR será exibido se Código e 0x04|
|E0-E7||||32|`vpop  {d8-dX}`<br /><br /> em que X é (Código e 0x07) + 8|
|E8-EB|00-FF|||32|`addw  sp,sp,#X`<br /><br /> em que X é (código e 0x03FF) \* 4|
|EC-ED|00-FF|||16|`pop   {r0-r7,lr}`<br /><br /> em que LR será exibido se Código e 0x0100 e r0-r7 forem exibidos se o bit correspondente for configurado em Código e 0x00FF|
|EE|00-0F|||16|Específico da Microsoft|
|EE|10-FF|||16|Disponível|
|EF|00-0F|||32|`ldr   lr,[sp],#X`<br /><br /> em que X é (código e 0x000F) \* 4|
|EF|10-FF|||32|Disponível|
|F0-F4||||-|Disponível|
|F5|00-FF|||32|`vpop  {dS-dE}`<br /><br /> em que S é (Código e 0x00F0) >> 4 e E é Código e 0x000F|
|F6|00-FF|||32|`vpop  {dS-dE}`<br /><br /> em que S é ((Código e 0x00F0) >> 4) + 16 e E é (Código e 0x000F) + 16|
|F7|00-FF|00-FF||16|`add   sp,sp,#X`<br /><br /> em que X é (código e 0x00FFFF) \* 4|
|F8|00-FF|00-FF|00-FF|16|`add   sp,sp,#X`<br /><br /> em que X é (código e 0x00FFFFFF) \* 4|
|F9|00-FF|00-FF||32|`add   sp,sp,#X`<br /><br /> em que X é (código e 0x00FFFF) \* 4|
|FA|00-FF|00-FF|00-FF|32|`add   sp,sp,#X`<br /><br /> em que X é (código e 0x00FFFFFF) \* 4|
|FB||||16|nop (16 bits)|
|FC||||32|nop (32 bits)|
|FD||||16|end + nop de 16 bits no epílogo|
|FE||||32|end + nop de 32 bits no epílogo|
|FF||||-|end|

Isso mostra o intervalo de valores hexadecimais para cada byte em um código de desenrolamento *código*, junto com o tamanho do opcode *Opsize* e a interpretação de instrução original correspondente. As células vazias indicam códigos de desenrolamento mais curtos. Em instruções que tenham valores grandes que abrangem vários bytes, os bits mais significativos são armazenados primeiro. O *Opsize* campo mostra o tamanho do opcode implícito associado com cada operação de Thumb-2. As entradas duplicadas aparentes na tabela com diferentes codificações são usadas para distinguir entre tamanhos de opcode diferentes.

Os códigos de desenrolamento são projetados para que o primeiro byte do código informe o tamanho total em bytes do código e o tamanho do opcode correspondente no fluxo de instruções. Para calcular o tamanho do prólogo ou do epílogo, percorra os códigos de desenrolamento do início da sequência até o final e use a tabela de consulta ou um método semelhante para determinar o comprimento do opcode correspondente.

Os códigos de desenrolamento 0xFD e 0xFE são equivalentes ao código end regular 0xFF, mas é responsável por um opcode nop extra no caso de epílogo, seja de 16 ou 32 bits. Para prólogos, os códigos 0xFD, 0xFE e 0xFF são exatamente equivalentes. Isso é responsável por finais de epílogo comuns `bx lr` ou `b <tailcall-target>`, que não possuem uma instrução de prólogo equivalente. Com isso, aumenta a chance de que sequências de desenrolamento possam ser compartilhadas entre o prólogo e o epílogo.

Em muitos casos, deve ser possível usar o mesmo conjunto de códigos de desenrolamento para o prólogo e todos os epílogos. No entanto, para manipular o desenrolamento de prólogos e epílogos executados parcialmente, você pode ter várias sequências de código de desenrolamento que variam em ordenação ou comportamento. Isso é por que cada epílogo tem seu próprio índice na matriz de desenrolamento para mostrar onde começar a executar.

### <a name="unwinding-partial-prologues-and-epilogues"></a>Desenrolando prólogos e epílogos parciais

O caso de desenrolamento mais comum é quando a exceção ocorre no corpo da função, distante do prólogo e de todos os epílogos. Nesse caso, o desenrolador executa os códigos na matriz de desenrolamento começando no índice 0 e continua até que um opcode final seja detectado.

Quando uma exceção ocorre enquanto um prólogo ou um epílogo estiver em execução, o registro de ativação será construído apenas parcialmente e o desenrolador deverá determinar exatamente o que foi feito, a fim de desfazê-lo corretamente.

Por exemplo, considere esta sequência de prólogo e epílogo:

```asm
0000:   push  {r0-r3}         ; 0x04
0002:   push  {r4-r9, lr}     ; 0xdd
0006:   mov   r7, sp          ; 0xc7
...
0140:   mov   sp, r7          ; 0xc7
0142:   pop   {r4-r9, lr}     ; 0xdd
0146:   add   sp, sp, #16     ; 0x04
0148:   bx    lr
```

Próximo a cada opcode existe o código de desenrolamento apropriado para descrever esta operação. A sequência de códigos de desenrolamento para o prólogo é uma imagem refletida dos códigos de desenrolamento para o epílogo, sem considerar a instrução final. Esse caso é comum e é o motivo pelo qual se supõe que os códigos de desenrolamento do prólogo sejam sempre armazenados na ordem inversa a partir da ordem de execução do prólogo. A seguir, um conjunto comum de códigos de desenrolamento:

```asm
0xc7, 0xdd, 0x04, 0xfd
```

O código 0xFD é um código especial para o final da sequência que significa que o epílogo é uma instrução de 16 bits maior do que o prólogo. Isso torna possível o compartilhamento de códigos de desenrolamento maiores.

No exemplo, se ocorrer uma exceção enquanto o corpo da função entre o prólogo e o epílogo estiver em execução, o desenrolamento iniciará o caso do epílogo, no deslocamento 0 dentro do código de epílogo. Isso corresponde ao deslocamento 0x140 no exemplo. O desenrolador executa a sequência de desenrolamento completa, pois nenhuma limpeza foi feita. Se em vez da exceção, ocorrer uma instrução após o início do código de epílogo, o desenrolador poderá desenrolar com êxito, ignorando o primeiro código de desenrolamento. Um mapeamento um para um entre opcodes e códigos de desenrolamento, se estiver desenrolando a partir da instrução *n* no epílogo, o desenrolador deverá ignorar os primeiros *n* códigos de desenrolamento.

A lógica semelhante funciona na ordem inversa para o prólogo. Se estiver desenrolando a partir do deslocamento 0 no prólogo, nada será executado. Se estiver desenrolando de uma instrução em diante, a sequência de desenrolamento deverá iniciar um código de desenrolamento a partir do final, pois os códigos de desenrolamento do prólogo são armazenados na ordem inversa. Em geral, se estiver desenrolando a partir da instrução *n* no prólogo, desenrolamento deverá iniciar executando em *n* códigos do final da lista de códigos de desenrolamento.

Os códigos de desenrolamento do prólogo e do epílogo nem sempre correspondem exatamente. Nesse caso, a matriz do código de desenrolamento pode precisar conter várias sequências de códigos. Para determinar o deslocamento para começar o processamento dos códigos, use esta lógica:

1. Se estiver desenrolando de dentro do corpo da função, comece executando os códigos de desenrolamento no índice 0 e continue até que um opcode final seja alcançado.

2. Se estiver desenrolando de dentro de um epílogo, use o índice inicial específico do epílogo fornecido pelo escopo do epílogo. Calcule quantos bytes do PC há desde o início do epílogo. Avance os códigos de desenrolamento até que todas as instruções já executadas sejam consideradas. Execute a sequência de desenrolamento iniciando nesse ponto.

3. Se estiver desenrolando de dentro do prólogo, inicie a partir do índice 0 nos códigos de desenrolamento. Calcule o comprimento do código do prólogo a partir da sequência e calcule a quantos bytes o PC está do final do prólogo. Avance os códigos de desenrolamento até que todas as instruções não executadas sejam consideradas. Execute a sequência de desenrolamento iniciando nesse ponto.

Os códigos de desenrolamento do prólogo devem ser sempre os primeiros na matriz. Eles também são os códigos usados para desenrolar no caso geral de desenrolamento de dentro do corpo. Todas as sequências de código específicas do epílogo devem vir imediatamente após a sequência de códigos do prólogo.

### <a name="function-fragments"></a>Fragmentos de função

Para otimização do código, pode ser útil dividir uma função em partes descontínuas. Quando isso é feito, cada fragmento de função requer seu próprio registro .pdata separado e, possivelmente, o registro .xdata.

Supondo que o prólogo da função esteja no início da função e não possa ser dividido, há quatro casos de fragmento de função:

- Somente prólogo; todos os epílogos em outros fragmentos.

- Prólogo e um ou mais epílogos; epílogos adicionais em outros fragmentos.

- Nenhum prólogo ou epílogo; prólogo e um ou mais epílogos em outros fragmentos.

- Epílogos somente; prólogo e, possivelmente, epílogos adicionais em outros fragmentos.

No primeiro caso, somente o prólogo deve ser descrito. Isso pode ser feito no formulário. pData compacto, descrevendo o prólogo normalmente e especificando um *Ret* valor 3 para não indicar nenhum epílogo. No formulário .xdata completo, isso pode ser feito ao fornecer os códigos de desenrolamento do prólogo no índice 0 como de costume, especificando uma contagem de epílogo igual a 0.

O segundo caso funciona exatamente como uma função normal. Se houver apenas um epílogo no fragmento e ele estiver no final do fragmento, um registro .pdata compacto poderá ser usado. Caso contrário, deverá ser usado um registro .xdata completo. Lembre-se de que os deslocamentos especificados para o início do epílogo são relativos ao início do fragmento, e não ao início original da função.

Os terceiro e quarto casos são variantes dos primeiro e segundo casos, respectivamente, exceto que eles não contêm um prólogo. Nessas situações, supõe-se que haja código antes do início do epílogo e ele é considerado parte do corpo da função, que normalmente seria desenrolado desfazendo-se os efeitos do prólogo. Esses casos devem ser, portanto, codificados com um pseudoprólogo, que descreve como desenrolar de dentro do corpo, mas que é tratado como comprimento 0 ao determinar se deve executar um desenrolamento parcial no início do fragmento. Como alternativa, esse pseudoprólogo pode ser descrito ao usar os mesmos códigos de desenrolamento do epílogo, pois eles provavelmente executam operações equivalentes.

No terceiro e quarto casos, a presença de um pseudoprólogo é especificada Configurando o *sinalizador* campo do registro. pData compacto como 2, ou definindo o *F* sinalizador no cabeçalho. XData como 1. Em qualquer dos casos, a verificação do desenrolamento parcial de um prólogo é ignorada e todos os desenrolamentos que não sejam de epílogo são considerados completos.

#### <a name="large-functions"></a>Funções grandes

Os fragmentos podem ser usados para descrever funções com um limite superior a 512 KB imposto pelos campos de bits no cabeçalho .xdata. Para descrever uma função muito grande, divida-a em fragmentos com menos de 512 KB. Cada fragmento deve ser ajustado para que ele não divida um epílogo em várias partes.

Apenas o primeiro fragmento da função contém um prólogo e todos os outros fragmentos são marcados como não tendo prólogo. Dependendo do número de epílogos, cada fragmento pode conter zero ou mais epílogos. Lembre-se que cada escopo de epílogo em um fragmento especifica seu deslocamento inicial com relação ao início do fragmento, e não ao início da função.

Se um fragmento não tiver prólogo nem epílogo, ele ainda exigirá seu próprio registro .pdata e, possivelmente, o registro .xdata para descrever como desenrolar de dentro do corpo da função.

#### <a name="shrink-wrapping"></a>Shrink-wrapping

É um caso especial mais complexo de fragmentos de função *wrapping*, uma técnica para adiar salva desde o início da função para mais tarde na função, para otimizar para casos simples que não requerem salvamento do registro. Esse procedimento pode ser descrito como uma região externa que aloca o espaço de pilha, mas salva um conjunto mínimo de registros e uma região interna que salva e restaura registros adicionais.

```asm
ShrinkWrappedFunction
     push   {r4, lr}          ; A: save minimal non-volatiles
     sub    sp, sp, #0x100    ; A: allocate all stack space up front
     ...                     ; A:
     add    r0, sp, #0xE4     ; A: prepare to do the inner save
     stm    r0, {r5-r11}      ; A: save remaining non-volatiles
     ...                     ; B:
     add    r0, sp, #0xE4     ; B: prepare to do the inner restore
     ldm    r0, {r5-r11}      ; B: restore remaining non-volatiles
     ...                     ; C:
     pop    {r4, pc}          ; C:
```

Geralmente espera-se que as funções shrink-wrapping pré-aloquem o espaço para os salvamentos de registros extras no prólogo regular e, em seguida, executem os salvamentos de registros usando `str` ou `stm`, em vez de `push`. Isso mantém toda a manipulação do ponteiro de pilha no prólogo original da função.

A função shrink-wrapping de exemplo deve ser dividida em três regiões, que são marcadas como A, B e C nos comentários. A primeira região A abrange o início da função até o final dos salvamentos não voláteis adicionais. Um registro .pdata ou .xdata deve ser construído para descrever este fragmento como tendo um prólogo e nenhum epílogo.

A região B intermediária obtém seu próprio registro .pdata ou .xdata que descreve um fragmento que não possui prólogo nem epílogo. No entanto, os códigos de desenrolamento desta região ainda devem estar presentes, pois ela é considerada o corpo da função. Os códigos devem descrever um prólogo composto que representa os registros originais salvos no prólogo da região A e os registros adicionais salvos antes de entrar na região B, como se eles fossem produzidos por uma sequência de operações.

O registro que salva na região B não pode ser considerado como um "prólogo interno", pois o prólogo composto descrito para a região B deve descrever o prólogo da região A e os registros adicionais salvos. Se o fragmento B foi descrito como tendo um prólogo, os códigos de desenrolamento também indicam o tamanho desse prólogo e não há nenhuma maneira de descrever o prólogo composto de modo que ele mapeie um para um com os opcodes que salvam apenas os registros adicionais.

Os salvamentos de registros adicionais devem ser considerados parte da região A, pois até que eles estejam concluídos, o prólogo composto não descreve com precisão o estado da pilha.

A última região C obtém seu próprio registro .pdata ou .xdata, que descreve um fragmento que não possui prólogo, mas possui um epílogo.

Uma abordagem alternativa pode também funcionar se a manipulação de pilha feita antes de entrar na região B puder ser reduzida para uma instrução:

```asm
ShrinkWrappedFunction
     push   {r4, lr}          ; A: save minimal non-volatile registers
     sub    sp, sp, #0xE0     ; A: allocate minimal stack space up front
     ...                     ; A:
     push   {r4-r9}           ; A: save remaining non-volatiles
     ...                     ; B:
     pop    {r4-r9}           ; B: restore remaining non-volatiles
     ...                     ; C:
     pop    {r4, pc}          ; C: restore non-volatile registers
```

O essencial aqui é que em cada limite de instrução, a pilha seja completamente consistente com os códigos de desenrolamento da região. Se ocorrer um desenrolamento antes do envio por push interno neste exemplo, ele será considerado parte da região A e apenas o prólogo da região A será desenrolado. Se o desenrolamento ocorrer após o envio por push interno, ele é considerado parte da região B, que não possui prólogo, mas possui códigos de desenrolamento que descrevem o envio por push interno e o prólogo original da região de uma lógica semelhante A. é mantida para pop interno.

### <a name="encoding-optimizations"></a>Otimizações de codificação

Em função da riqueza dos códigos de desenrolamento e da capacidade de aproveitar formas compactas e expandidas de dados, há muitas oportunidades para otimizar a codificação de forma a reduzir ainda mais o espaço. Com o uso agressivo dessas técnicas, a sobrecarga da rede de descrição de funções e fragmentos usando códigos de desenrolamento pode ser bastante reduzida.

A otimização mais importante é ter cuidado para não confundir os limites de prólogo/epílogo para fins de desenrolamento com limites lógicos de prólogo/epílogo a partir da perspectiva do compilador. Os limites de desenrolamento podem ser reduzidos e adaptados para melhorar a eficiência. Por exemplo, um prólogo pode conter código após a configuração da pilha para realizar verificações adicionais. No entanto, uma vez que toda a manipulação de pilha estiver concluída, não há necessidade de codificar operações adicionais e nada além disso poderá ser removido do prólogo de desenrolamento.

Essa mesma regra se aplica ao comprimento da função. Se houver dados – por exemplo, um conjunto literal – que siga um epílogo em uma função, eles não deverão ser incluídos como parte do comprimento da função. Ao reduzir a função a apenas o código que faz parte da função, haverá muito mais chances de que o epílogo esteja no final e de que um registro .pdata compacto possa ser usado.

Em um prólogo, uma vez que o ponteiro de pilha for salvo em outro registro, geralmente não há necessidade de registrar nenhum opcode adicional. Para desenrolar a função, a primeira coisa que é feita é recuperar o SP a partir do registro salvo e, desse modo, operações adicionais não têm impacto algum no desenrolamento.

Os epílogos de instrução única não precisam ser codificados, seja como escopos ou como códigos de desenrolamento. Se um desenrolamento ocorrer antes de a instrução ser executada, será possível supor que seja de dentro do corpo da função e será suficiente executar apenas os códigos de desenrolamento do prólogo. Se o desenrolamento ocorrer após a única instrução ser executada, por definição, ela ocorrerá em outra região.

Os epílogos com várias instruções não precisam codificar a primeira instrução do epílogo, pelo mesmo motivo do ponto anterior: se o desenrolamento ocorrer antes da instrução ser executada, um desenrolamento completo do prólogo será suficiente. Se o desenrolamento ocorrer após essa instrução, apenas as operações subsequentes deverão ser consideradas.

A reutilização do código de desenrolamento deverá ser agressiva. O índice especificado em cada escopo do epílogo aponta para um ponto inicial arbitrário na matriz de códigos de desenrolamento. Ele não precisa apontar para o início de uma sequência anterior, uma vez que pode apontar para um ponto intermediário. A melhor abordagem aqui é gerar a sequência de códigos desejada e verificar uma correspondência de bytes exata no conjunto já codificado de sequências, usando qualquer correspondência perfeita como um ponto inicial para reutilização.

Se, depois que os epílogos de instrução única forem ignorados, não houver epílogos restantes, considere usar um formulário .pdata compacto, uma que ele se torna muito mais provável na ausência de um epílogo.

## <a name="examples"></a>Exemplos

Nestes exemplos, a base da imagem está em 0x00400000.

### <a name="example-1-leaf-function-no-locals"></a>Exemplo 1: Função folha, sem locais

```asm
Prologue:
  004535F8: B430      push        {r4-r5}
Epilogue:
  00453656: BC30      pop         {r4-r5}
  00453658: 4770      bx          lr
```

.pdata (corrigido, 2 palavras):

- Palavra 0

   - *Função Start RVA* = 0x000535F8 (= 0x004535F8 0x00400000)

- Palavra 1

   - *Sinalizador* = 1, indicando os formatos de prólogo e epílogo canônicos

   - *Função comprimento* = erro:0x31 (= 0x62/2)

   - *RET* = 1, que indica uma retorno de ramificação de 16 bits

   - *H* = 0, indicando os parâmetros não foram hospedados

   - *R*= 0 e *Reg* = 1, que indica push/pop de r4-r5

   - *L* = 0, que indica nenhum salvamento/restauração de LR

   - *C* = 0, indicando que nenhum encadeamento de quadro

   - *Ajuste de pilha* = 0, indicando que nenhum ajuste de pilha

### <a name="example-2-nested-function-with-local-allocation"></a>Exemplo 2: Função aninhada com alocação local

```asm
Prologue:
  004533AC: B5F0      push        {r4-r7, lr}
  004533AE: B083      sub         sp, sp, #0xC
Epilogue:
  00453412: B003      add         sp, sp, #0xC
  00453414: BDF0      pop         {r4-r7, pc}
```

.pdata (corrigido, 2 palavras):

- Palavra 0

   - *Função Start RVA* = 0x000533AC (= 0x004533AC – 0x00400000)

- Palavra 1

   - *Sinalizador* = 1, indicando os formatos de prólogo e epílogo canônicos

   - *Função comprimento* = 0x35 (= 0x6A/2)

   - *RET* = 0, indicando que um pop {pc} retorno

   - *H* = 0, indicando os parâmetros não foram hospedados

   - *R*= 0 e *Reg* = 3, que indica push/pop de r4-r7

   - *L* = 1, indicando o LR foi salvo/restaurado

   - *C* = 0, indicando que nenhum encadeamento de quadro

   - *Ajuste de pilha* = 3 (= 0x0C/4)

### <a name="example-3-nested-variadic-function"></a>Exemplo 3: Função Variadic aninhada

```asm
Prologue:
  00453988: B40F      push        {r0-r3}
  0045398A: B570      push        {r4-r6, lr}
Epilogue:
  004539D4: E8BD 4070 pop         {r4-r6}
  004539D8: F85D FB14 ldr         pc, [sp], #0x14
```

.pdata (corrigido, 2 palavras):

- Palavra 0

   - *Função Start RVA* = 0x00053988 (= 0x00453988 0x00400000)

- Palavra 1

   - *Sinalizador* = 1, indicando os formatos de prólogo e epílogo canônicos

   - *Função comprimento* = 0x2A (= 0x54/2)

   - *RET* = 0, indicando que um pop {pc}-retorno de estilo (nesse caso, um pc de ldr, [sp] PC,[SP],#0x14 retornar)

   - *H* = 1, indicando os parâmetros foram hospedados

   - *R*= 0 e *Reg* = 2, que indica push/pop de r4-r6

   - *L* = 1, indicando o LR foi salvo/restaurado

   - *C* = 0, indicando que nenhum encadeamento de quadro

   - *Ajuste de pilha* = 0, indicando que nenhum ajuste de pilha

### <a name="example-4-function-with-multiple-epilogues"></a>Exemplo 4: Função com vários epílogos

```asm
Prologue:
  004592F4: E92D 47F0 stmdb       sp!, {r4-r10, lr}
  004592F8: B086      sub         sp, sp, #0x18
Epilogues:
  00459316: B006      add         sp, sp, #0x18
  00459318: E8BD 87F0 ldm         sp!, {r4-r10, pc}
  ...
  0045943E: B006      add         sp, sp, #0x18
  00459440: E8BD 87F0 ldm         sp!, {r4-r10, pc}
  ...
  004595D4: B006      add         sp, sp, #0x18
  004595D6: E8BD 87F0 ldm         sp!, {r4-r10, pc}
  ...
  00459606: B006      add         sp, sp, #0x18
  00459608: E8BD 87F0 ldm         sp!, {r4-r10, pc}
  ...
  00459636: F028 FF0F bl          KeBugCheckEx     ; end of function
```

.pdata (corrigido, 2 palavras):

- Palavra 0

   - *Função Start RVA* = 0x000592F4 (= 0x004592F4 0x00400000)

- Palavra 1

   - *Sinalizador* = 0, indicando que o registro. XData está presente (necessário devido a vários epílogos)

   - *endereço. XData* -0x00400000

.xdata (variável, 6 palavras):

- Palavra 0

   - *Função comprimento* = 0x0001A3 (= 0x000346/2)

   - *Vers* = 0, indicando que a primeira versão de xdata

   - *X* = 0, indicando que nenhum dado de exceção

   - *E* = 0, indicando que uma lista de escopos de epílogo

   - *F* = 0, indicando uma descrição completa da função, incluindo o prólogo

   - *Contagem de epílogo* = 0x04, que indica os 4 escopos totais do epílogo

   - *Palavras de código* = 0x01, que indica uma palavra de 32 bits de códigos de desenrolamento

- Palavras de 1 a 4, descrevendo 4 escopos de epílogo em 4 locais. Cada escopo possui um conjunto comum de códigos de desenrolamento, compartilhados com o prólogo, com deslocamento 0x00, e é incondicional, especificando a condição 0x0E (sempre).

- Códigos de desenrolamento, iniciando na Palavra 5: (compartilhado entre o prólogo/epílogo)

   - Código de desenrolamento 0 = 0x06: sp += (6 << 2)

   - Código de desenrolamento 1 = 0xDE: pop {r4-r10, lr}

   - Código de desenrolamento 2 = 0xFF: end

### <a name="example-5-function-with-dynamic-stack-and-inner-epilogue"></a>Exemplo 5: Função com pilha dinâmica e epílogo interno

```asm
Prologue:
  00485A20: B40F      push        {r0-r3}
  00485A22: E92D 41F0 stmdb       sp!, {r4-r8, lr}
  00485A26: 466E      mov         r6, sp
  00485A28: 0934      lsrs        r4, r6, #4
  00485A2A: 0124      lsls        r4, r4, #4
  00485A2C: 46A5      mov         sp, r4
  00485A2E: F2AD 2D90 subw        sp, sp, #0x290
Epilogue:
  00485BAC: 46B5      mov         sp, r6
  00485BAE: E8BD 41F0 ldm         sp!, {r4-r8, lr}
  00485BB2: B004      add         sp, sp, #0x10
  00485BB4: 4770      bx          lr
  ...
  00485E2A: F7FF BE7D b           #0x485B28    ; end of function
```

.pdata (corrigido, 2 palavras):

- Palavra 0

   - *Função Start RVA* = 0x00085A20 (= 0x00485A20 0x00400000)

- Palavra 1

   - *Sinalizador* = 0, indicando que o registro. XData está presente (necessário devido a vários epílogos)

   - *endereço. XData* -0x00400000

.xdata (variável, 3 palavras):

- Palavra 0

   - *Função comprimento* = 0x0001A3 (= 0x000346/2)

   - *Vers* = 0, indicando que a primeira versão de xdata

   - *X* = 0, indicando que nenhum dado de exceção

   - *E* = 0, indicando que uma lista de escopos de epílogo

   - *F* = 0, indicando uma descrição completa da função, incluindo o prólogo

   - *Contagem de epílogo* = 0x001, que indica 1 escopo total do epílogo

   - *Palavras de código* = 0x01, que indica uma palavra de 32 bits de códigos de desenrolamento

- Palavra 1: O escopo do epílogo no deslocamento 0xC6 (= 0x18C/2), iniciando o índice do código de desenrolamento em 0x00 e com uma condição de 0x0E (sempre)

- Códigos de desenrolamento, iniciando na Palavra 2: (compartilhado entre o prólogo/epílogo)

   - Código de desenrolamento 0 = 0xC6: sp = r6

   - Código de desenrolamento 1 = 0xDC: pop {r4-r8, lr}

   - Código de desenrolamento 2 = 0x04: sp += (4 << 2)

   - Código de desenrolamento 3 = 0xFD: end, é considerado uma instrução de 16 bits para o epílogo

### <a name="example-6-function-with-exception-handler"></a>Exemplo 6: Função com manipulador de exceção

```asm
Prologue:
  00488C1C: 0059 A7ED dc.w  0x0059A7ED
  00488C20: 005A 8ED0 dc.w  0x005A8ED0
FunctionStart:
  00488C24: B590      push        {r4, r7, lr}
  00488C26: B085      sub         sp, sp, #0x14
  00488C28: 466F      mov         r7, sp
Epilogue:
  00488C6C: 46BD      mov         sp, r7
  00488C6E: B005      add         sp, sp, #0x14
  00488C70: BD90      pop         {r4, r7, pc}
```

.pdata (corrigido, 2 palavras):

- Palavra 0

   - *Função Start RVA* = 0x00088C24 (= 0x00488C24 0x00400000)

- Palavra 1

   - *Sinalizador* = 0, indicando que o registro. XData está presente (necessário devido a vários epílogos)

   - *endereço. XData* -0x00400000

.xdata (variável, 5 palavras):

- Palavra 0

   - *Função comprimento* = 0x000027 (= 0x00004E/2)

   - *Vers* = 0, indicando que a primeira versão de xdata

   - *X* = 1, que indica os dados de exceção presentes

   - *E* = 1, indicando um único epílogo

   - *F* = 0, indicando uma descrição completa da função, incluindo o prólogo

   - *Contagem de epílogo* = 0x00, que indica o início de códigos de desenrolamento do epílogo com deslocamento 0x00

   - *Palavras de código* = 0x02, que indica duas palavras de 32 bits de códigos de desenrolamento

- Código de desenrolamento, iniciando na Palavra 1:

   - Código de desenrolamento 0 = 0xC7: sp = r7

   - Código de desenrolamento 1 = 0x05: sp += (5 << 2)

   - Código de desenrolamento 2 = 0xED/0x90: pop {r4, r7, lr}

   - Código de desenrolamento 4 = 0xFF: end

- Palavra 3 especifica um manipulador de exceção = 0x0019A7ED (= 0x0059A7ED – 0x00400000)

- As Palavras 4 e acima são dados de exceção embutidos

### <a name="example-7-funclet"></a>Exemplo 7: Funclet

```asm
Function:
  00488C72: B500      push        {lr}
  00488C74: B081      sub         sp, sp, #4
  00488C76: 3F20      subs        r7, #0x20
  00488C78: F117 0308 adds        r3, r7, #8
  00488C7C: 1D3A      adds        r2, r7, #4
  00488C7E: 1C39      adds        r1, r7, #0
  00488C80: F7FF FFAC bl          target
  00488C84: B001      add         sp, sp, #4
  00488C86: BD00      pop         {pc}
```

.pdata (corrigido, 2 palavras):

- Palavra 0

   - *Função Start RVA* = 0x00088C72 (= 0x00488C72 0x00400000)

- Palavra 1

   - *Sinalizador* = 1, indicando os formatos de prólogo e epílogo canônicos

   - *Função comprimento* = 0x0B (= 0x16/2)

   - *RET* = 0, indicando que um pop {pc} retorno

   - *H* = 0, indicando os parâmetros não foram hospedados

   - *R*= 0 e *Reg* = 7, que indica nenhum registro foi salvo/restaurado

   - *L* = 1, indicando o LR foi salvo/restaurado

   - *C* = 0, indicando que nenhum encadeamento de quadro

   - *Ajuste de pilha* = 1, indicando um ajuste de pilha 1 × 4 bytes

## <a name="see-also"></a>Consulte também

[Visão geral das convenções ARM ABI](../build/overview-of-arm-abi-conventions.md)  
[Problemas de migração ARM do Visual C++ comuns](../build/common-visual-cpp-arm-migration-issues.md)  

