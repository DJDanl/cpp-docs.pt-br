---
title: Diretivas do assembler ARM
ms.date: 08/30/2018
ms.assetid: 9cfa8896-ec10-4e77-855a-3135c40d7d2a
ms.openlocfilehash: 9124f893b3334e0893073332c9d5f5a1388373d9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167667"
---
# <a name="arm-assembler-directives"></a>Diretivas do assembler ARM

Na maior parte, o assembler Microsoft ARM usa a linguagem de assembly do ARM, que está documentada na [compilador ARM armasm guia de referência](http://infocenter.arm.com/help/topic/com.arm.doc.dui0802b/index.html). No entanto, as implementações Microsoft de algumas diretivas de assembly diferem das diretivas de assembly do ARM. Este artigo explica as diferenças.

## <a name="microsoft-implementations-of-arm-assembly-directives"></a>Implementações Microsoft de diretivas de Assembly do ARM

- AREA

   O assembler Microsoft ARM dá suporte a estes `AREA` atributos: `ALIGN`, `CODE`, `CODEALIGN`, `DATA`, `NOINIT`, `READONLY`, `READWRITE`, `THUMB`, `ARM`.

   Todos, exceto `THUMB` e `ARM` funcionam conforme documentado na [compilador ARM armasm guia de referência](http://infocenter.arm.com/help/topic/com.arm.doc.dui0802b/index.html).

   No assembler Microsoft ARM, `THUMB` indica que um `CODE` seção contém código Thumb e é o padrão para `CODE` seções.  `ARM` indica que a seção contém código ARM.

- ATTR

   Sem suporte.

- CODE16

   Não tem suporte porque ele implica a sintaxe de Thumb de pré-UAL, que não permite o assembler Microsoft ARM.  Use o `THUMB` diretiva em vez disso, juntamente com a sintaxe do UAL.

- COMUNS

   Não há suporte para a especificação de um alinhamento para a região comuns.

- DCDO

   Sem suporte.

- `DN`, `QN`, `SN`

   Não há suporte para a especificação de um tipo ou uma pista sobre o registro de alias.

- ENTRADA

   Sem suporte.

- EQU

   Não há suporte para a especificação de um tipo para o símbolo definido.

- `EXPORT` e `GLOBAL`

   Especifica as exportações usando esta sintaxe:

   > **EXPORT**|**GLOBAL** <em>sym</em>{**[**<em>type</em>**]**}

   *SYM* é o símbolo a ser exportado.  [*tipo*], se especificado, pode ser `[DATA]` para indicar que o símbolo de pontos de dados ou `[FUNC]` para indicar que o símbolo de pontos de código. `GLOBAL` é um sinônimo de `EXPORT`.

- EXPORTAS

   Sem suporte.

- QUADRO

   Sem suporte.

- `FUNCTION` e `PROC`

   Embora a sintaxe de assembly oferece suporte à especificação de um personalizado convenção de chamada em procedimentos, listando os registros que estão chamador save e aqueles que são o salvamento do computador chamado, o assembler Microsoft ARM aceita a sintaxe, mas ignora as listas de registro.  As informações de depuração que são produzidas pelo assembler dá suporte a apenas o padrão de convenção de chamada.

- `IMPORT` e `EXTERN`

   Especifica as importações usando esta sintaxe:

   > **IMPORTAÇÃO**|**EXTERN** *sym*{**, FRACA** *alias*{**, tipo** *t*}}

   *SYM* é o nome do símbolo a ser importado.

   Se `WEAK` *alias* for especificado, ele indicará que *sym* é um externo fraco. Se nenhuma definição para que ele é encontrada em tempo de vinculação e, em seguida, todas as referências a ele em vez disso, associar a *alias*.

   Se `TYPE` *t* for especificado, então *t* indica como o vinculador deve tentar resolver *sym*.  Esses valores para *t* são possíveis:

   |Valor|Descrição|
   |-|-|
   |1|Não execute uma pesquisa de biblioteca para *sym*|
   |2|Executar uma pesquisa de biblioteca para *sym*|
   |3|*SYM* é um alias para *alias* (padrão)|

   `EXTERN` é um sinônimo de `IMPORT`, exceto que *sym* é importado somente se houver referências a ele no assembly atual.

- MACRO

   Não há suporte para o uso de uma variável para conter o código de condição de uma macro. Valores padrão para parâmetros não têm suporte de macro.

- NOFP

   Sem suporte.

- `OPT`, `TTL`, `SUBT`

   Não tem suporte porque o assembler Microsoft ARM não produz listagens.

- PRESERVE8

   Sem suporte.

- RELOC

   `RELOC n` só pode seguir uma instrução ou uma diretiva de definição de dados. Não há nenhum "símbolo anônimo" que pode ser realocado.

- EXIGIR

   Sem suporte.

- REQUIRE8

   Sem suporte.

- THUMBX

   Não tem suportada porque o assembler Microsoft ARM não suporta o conjunto de instruções do Thumb 2EE.

## <a name="see-also"></a>Consulte também

[Referência de linha de comando do assembler ARM](../../assembler/arm/arm-assembler-command-line-reference.md)<br/>
[Mensagens de diagnóstico do assembler ARM](../../assembler/arm/arm-assembler-diagnostic-messages.md)<br/>
