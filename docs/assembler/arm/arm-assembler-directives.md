---
title: Diretivas do Assembler ARM | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 9cfa8896-ec10-4e77-855a-3135c40d7d2a
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 44cd4e5c47618a12c5d4ad5edd3bd8bbf9105309
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="arm-assembler-directives"></a>Diretivas do assembler ARM
A maior parte do tempo, o assembler ARM Microsoft usa a linguagem de assembly do ARM, que está documentada no capítulo 7 da [guia de ferramentas do ARM assembler](http://go.microsoft.com/fwlink/p/?linkid=246102). No entanto, as implementações Microsoft algumas diretivas de assembly diferem as diretivas de assembly do ARM. Este artigo explica as diferenças.  
  
## <a name="microsoft-implementations-of-arm-assembly-directives"></a>Microsoft implementações das diretivas de Assembly do ARM  
 ÁREA  
 O assembler ARM Microsoft dá suporte a esses atributos de área: ALINHAR, código, CODEALIGN, dados, NOINIT, READONLY, READWRITE, THUMB, ARM.  
  
 Todos exceto THUMB e ARM funcionam conforme documentado no [guia de ferramentas do ARM assembler](http://go.microsoft.com/fwlink/p/?linkid=246102).  
  
 Em assembler ARM Microsoft, THUMB indica que uma seção de código contém código Thumb e é o padrão para seções de código.  ARM indica que a seção contém código ARM.  
  
 ATTR  
 Sem suporte.  
  
 CODE16  
 Não tem suporte porque isso implica pre-UAL Thumb a sintaxe, que o assembler ARM Microsoft não permite.  Use a diretiva de digital em vez disso, juntamente com a sintaxe do UAL.  
  
 COMUNS  
 Não há suporte para a especificação de um alinhamento para a região comum.  
  
 DCDO  
 Sem suporte.  
  
 DN, QN, SN  
 Não há suporte para a especificação de um tipo ou uma rota no registro de alias.  
  
 ENTRADA  
 Sem suporte.  
  
 EQU  
 Não há suporte para a especificação de um tipo para o símbolo definido.  
  
 EXPORTAÇÃO e GLOBAL  
 ```  
EXPORTsym {[type]}  
```  
  
 `sym`é o símbolo a ser exportado.  `[type]`, se especificado, pode ser `[DATA]` para indicar que o símbolo aponta para dados ou `[FUNC]` para indicar que o símbolo de pontos de código.  
  
 GLOBAL é um sinônimo para exportação.  
  
 EXPORTAS  
 Sem suporte.  
  
 QUADRO  
 Sem suporte.  
  
 FUNÇÃO e PROC  
 Embora a sintaxe de assembly oferece suporte à especificação de um personalizado convenção de chamada em procedimentos, listando os registros de salvamento do chamador e aqueles que são receptor salvamento, do assembler ARM Microsoft aceita a sintaxe e ignora as listas de registro.  As informações de depuração que são produzidas pelo assembler oferece suporte somente a convenção de chamada de padrão.  
  
 IMPORTAÇÃO e EXTERN  
 ```  
IMPORT sym{, WEAK alias{, TYPE t}}  
```  
  
 `sym`é o nome do símbolo a ser importado.  
  
 Se FRACA `alias` for especificado, ele indicará que `sym` é um externo fraco. Se nenhuma definição para ele é encontrada em vez do link, todas as referências a ele em vez disso, associar a `alias`.  
  
 Se tipo `t` for especificado, então `t` indica como o vinculador deve tentar resolver `sym`.  Esses valores para `t` são possíveis:   
1 — não execute uma pesquisa de biblioteca para`sym`  
2 – realizar uma pesquisa de biblioteca para`sym`  
3 –`sym` é um alias para `alias` (padrão)  
  
 EXTERN é um sinônimo para importação, exceto que `sym` são importados apenas se houver referência a ele no assembly atual.  
  
 MACRO  
 Não há suporte para o uso de uma variável para manter o código de condição de uma macro. Valores padrão para parâmetros não têm suporte de macro.  
  
 NOFP  
 Sem suporte.  
  
 ACEITAR, TTL, SUBT  
 Não tem suporte porque o assembler ARM Microsoft não produzir listagens.  
  
 PRESERVE8  
 Sem suporte.  
  
 REALOCAÇÃO  
 `RELOC n`só pode seguir uma instrução ou uma diretiva de definição de dados. Não há nenhum "símbolo anônimo" que pode ser realocado.  
  
 EXIGIR  
 Sem suporte.  
  
 REQUIRE8  
 Sem suporte.  
  
 THUMBX  
 Não tem suportada porque o assembler ARM Microsoft não oferece suporte para o conjunto de instruções Thumb 2EE.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de linha de comando do Assembler ARM](../../assembler/arm/arm-assembler-command-line-reference.md)   
 [Mensagens de diagnóstico do assembler ARM](../../assembler/arm/arm-assembler-diagnostic-messages.md)