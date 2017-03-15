---
title: "struct UNWIND_CODE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 104955d8-7e33-4c5a-b0c6-3254648f0af3
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# struct UNWIND_CODE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A matriz de código de desenrolamento é usada para registrar a sequência de operações no prólogo que afetam os registros e o RSP permanentes.  Cada item de código possui o seguinte formato:  
  
|||  
|-|-|  
|UBYTE|Deslocamento no prolog|  
|UBYTE: 4|Desenrole o código de operação|  
|UBYTE: 4|Informações da operação|  
  
 A matriz é ordenada por ordem decrescente de deslocamento no prólogo.  
  
 **Deslocamento no prolog**  
 Desloque do início de prólogo final da instrução que executa essa operação, mais 1 \(isto é, o deslocamento do início da próxima instrução\).  
  
 **Desenrolar código de operação**  
 Observação: Alguns códigos de operação requerem um deslocamento sem sinal para um valor no quadro de pilha local.  Esse deslocamento é o início \(o menor\) endereço de alocação de pilha fixa.  Se o campo do registro do quadro no UNWIND\_INFO é zero, esse deslocamento é de RSP.  Se o campo do registro do quadro é diferente de zero, este é o deslocamento de onde RSP foi encontrado ao registro de FP foi estabelecido.  Isso é igual ao registro de FP menos o deslocamento do registro de FP \(16 \* o registro dimensionado do quadro deslocado no UNWIND\_INFO\).  Se um registro de FP é usado, então qualquer desenrola o código que utiliza um deslocamento deve ser usado somente após o registro de FP é estabelecida no prólogo.  
  
 Para todos os opcodes exceto UWOP\_SAVE\_XMM128 e UWOP\_SAVE\_XMM128\_FAR, o deslocamento será sempre um a partir de 8, porque o heap todos valores de interesse são armazenados em 8 limites de byte \(a pilha em si é sempre o byte alinhado 16\).  Para códigos de operação que têm um deslocamento abreviada \(menor que 512K\), o USHORT final em nós para que contém esse código o deslocamento se dividiu por 8.  Para códigos de operação que têm um deslocamento longo \(\<\= 512K deslocado \< 4GB\), os dois nós finais de USHORT para esse código contém o deslocamento \(no formato pequeno \- endian\).  
  
 Para os UWOP\_SAVE\_XMM128 opcodes e UWOP\_SAVE\_XMM128\_FAR, o deslocamento será sempre um a partir de 16, desde que todas as operações de 128 MMX de bit devem ocorrer na memória alinhada 16 bytes.  Portanto, um fator de escala de 16 é usado para UWOP\_SAVE\_XMM128, permitindo deslocamentos de menos de 1M.  
  
 O código de operação de desenrolamento é um dos seguintes:  
  
 UWOP\_PUSH\_NONVOL \(0\) 1 nó  
  
 Empurre permanente um registro inteiro, decrescendo RSP por 8.  Informações da operação é o número de registro.  Observe que, devido às restrições em epílogos, UWOP\_PUSH\_NONVOL desenrolam códigos devem aparecer primeiro no prólogo e correspondentemente, último na matriz de código de desenrolamento.  Este pedido de relativo se aplica a todos os outros códigos desenrola exceto UWOP\_PUSH\_MACHFRAME.  
  
 1\) 2 Ou 3 \(nó de UWOP\_ALLOC\_LARGE  
  
 Atribua uma área maior redimensionada na pilha.  Há duas formas.  Se a informação da operação é igual a 0, então o tamanho de alocação dividido por 8 é gravado no slot seguir, permitindo uma alocação até 512K – 8.  Se a informação da operação é igual a 1, então o tamanho não sofrem escala de alocação é gravado nos dois seguintes slots no formato pequeno \- endian, permitindo alocações até 4GB – 8.  
  
 UWOP\_ALLOC\_SMALL \(2\) 1 nó  
  
 Atribua uma área pequeno\- redimensionada na pilha.  O tamanho de alocação é o campo de informações da operação \* 8 \+ 8, permitindo alocações de 8 a 128 bytes.  
  
 O código de desenrolamento para uma alocação de pilha sempre deve usar a codificação mais curta possível:  
  
|||  
|-|-|  
|**Tamanho de alocação**|**Desenrole o código**|  
|8 a 128 bytes|UWOP\_ALLOC\_SMALL|  
|136 bytes para 512K\-8|UWOP\_ALLOC\_LARGE, informações da operação \= 0|  
|512K em bytes 4G\-8|UWOP\_ALLOC\_LARGE, informações da operação \= 1|  
  
 UWOP\_SET\_FPREG \(3\) 1 nó  
  
 Estabeleça o registro do ponteiro de quadro definindo o registro a qualquer deslocamento de RSP atual.  O deslocamento é igual ao campo de deslocamento de registro do quadro \(dimensionado\) no UNWIND\_INFO \* 16, permitindo que deslocam 0 a 240.  O uso de um deslocamento permite estabelecer um ponteiro de quadro que aponta para o meio de alocação de pilha fixa, ajudando densidade de código permitindo que acessa mais curtas usar formulários de declaração.  Observe que o campo de informações da operação é reservado e não deve ser usado.  
  
 UWOP\_SAVE\_NONVOL \(4\) 2 nós  
  
 Salvar um registro permanente inteiro na pilha usando um MOV em vez de um ENVIO.  Isso é usado primariamente psiquiatra\- envolvendo, onde o registro é salvo permanente à pilha em uma posição que é atribuída anteriormente.  Informações da operação é o número de registro.  O deslocamento da pilha scaled\-by\-8 é gravado no seguinte desenrola o encaixe de código de operação, como descrito em observação acima.  
  
 UWOP\_SAVE\_NONVOL\_FAR \(5\) 3 nós  
  
 Salvar um registro permanente inteiro na pilha com um deslocamento longo, usando um MOV em vez de um ENVIO.  Isso é usado primariamente psiquiatra\- envolvendo, onde o registro é salvo permanente à pilha em uma posição que é atribuída anteriormente.  Informações da operação é o número de registro.  O deslocamento não sofrem escala de pilha é identificado nos dois seguintes desenrola slots de código de operação, como descrito em observação acima.  
  
 UWOP\_SAVE\_XMM128 \(8\) 2 nós  
  
 Salve todos os 128 bits de um registro permanente de MMX na pilha.  Informações da operação é o número de registro.  O deslocamento da pilha scaled\-by\-16 é gravado no slot seguir.  
  
 UWOP\_SAVE\_XMM128\_FAR \(9\) 3 nós  
  
 Salve todos os 128 bits de um registro permanente de MMX na pilha com um deslocamento longo.  Informações da operação é o número de registro.  O deslocamento não sofrem escala de pilha é identificado nos dois slots seguir.  
  
 UWOP\_PUSH\_MACHFRAME \(10\) 1 nó  
  
 Empurre um quadro do computador.  Isso é usado para registrar o efeito de uma interrupção ou uma exceção de hardware.  Há duas formas.  Se a informação da operação é igual a 0, o seguinte é empurrado na pilha:  
  
|||  
|-|-|  
|RSP\+32|SS|  
|RSP\+24|RSP antigo|  
|RSP\+16|EFLAGS|  
|RSP\+8|CS|  
|RSP|RASGO|  
  
 Se a informação da operação é igual a 1, então o seguinte é empurrado em vez disso:  
  
|||  
|-|-|  
|RSP\+40|SS|  
|RSP\+32|RSP antigo|  
|RSP\+24|EFLAGS|  
|RSP\+16|CS|  
|RSP\+8|RASGO|  
|RSP|Código de erro|  
  
 Isso desenrola o código aparecerá sempre em um prólogo fictício, que nunca seja executado realmente mas aparece em vez antes do ponto de entrada real de uma rotina de interrupção, e existe somente para fornecer um local para simular o envio de um quadro do computador.  Registros de UWOP\_PUSH\_MACHFRAME que a simulação, que indica o computador fez conceitual o seguinte:  
  
 Aparecer o endereço de retorno de RASGO de parte superior da pilha *em Temp*  
  
 Empurre SS  
  
 Empurre RSP antigo  
  
 Empurre EFLAGS  
  
 Empurre o CS  
  
 Empurre o *Temp*  
  
 Empurre o código de erro \(iguais se os op 1 de informações\)  
  
 A operação simulada de UWOP\_PUSH\_MACHFRAME diminui RSP por 40 \(informações op é igual a 0\) ou por 48 \(informações op é igual a 1\).  
  
 **Informações de operação**  
 O significado desses 4 bits depende do código de operação.  Para codificar um registro comumente usados \(inteiro\), o seguinte mapeamento é usado:  
  
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
  
## Consulte também  
 [Dados desenrolados para tratamento de exceções, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)