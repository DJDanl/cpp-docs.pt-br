---
title: "ARM Assembler Directives | Microsoft Docs"
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
ms.assetid: 9cfa8896-ec10-4e77-855a-3135c40d7d2a
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ARM Assembler Directives
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Na maior parte, o montador ARM Microsoft usa a linguagem de assembly do ARM, documentada no capítulo 7 do [guia de ferramentas do ARM montador](http://go.microsoft.com/fwlink/?LinkId=246102).  No entanto, as implementações Microsoft de algumas diretivas assembly diferem as diretivas de assembly do ARM.  Este artigo explica as diferenças.  
  
## Implementações Microsoft de diretivas de Assembly do ARM  
 ÁREA  
 Montador ARM da Microsoft oferece suporte a esses atributos de área: ALINHAR, código, CODEALIGN, dados, NOINIT, READONLY, READWRITE, POLEGAR, ARM.  
  
 Todos, exceto o POLEGAR e o ARM funcionam conforme documentado na [guia de ferramentas do ARM montador](http://go.microsoft.com/fwlink/?LinkId=246102).  
  
 Montador Microsoft ARM, POLEGAR indica que uma seção de código contém código Thumb e é o padrão para seções de código.  ARM indica que a seção contém código ARM.  
  
 ATTR  
 Sem suporte.  
  
 CODE16  
 Não é suportada porque ele implica a sintaxe do polegar UAL pre, montador Microsoft ARM permite.  Use a diretiva de POLEGAR, juntamente com sintaxe UAL.  
  
 COMUM  
 Não há suporte para a especificação de um alinhamento para a região comum.  
  
 DCDO  
 Sem suporte.  
  
 DN, QN, SN  
 Não há suporte para a especificação de um tipo ou uma pista no registro de alias.  
  
 ENTRADA  
 Sem suporte.  
  
 EQU  
 Não há suporte para a especificação de um tipo de símbolo definido.  
  
 EXPORTAÇÃO e GLOBAL  
 ```  
  
EXPORTsym {[type]}  
  
```  
  
 `sym`é o símbolo a ser exportado.  `[type]`, se especificado, pode ser `[DATA]` para indicar que o símbolo aponta para dados ou `[FUNC]` para indicar que o símbolo aponta para o código.  
  
 GLOBAL é um sinônimo para exportação.  
  
 EXPORTAS  
 Sem suporte.  
  
 MOLDURA  
 Sem suporte.  
  
 FUNÇÃO e PROC  
 Embora a sintaxe assembly suporta a especificação de um personalizado convenção de chamada em procedimentos listando registradores são salvar chamador e aqueles que são chamado salvar, o montador Microsoft ARM aceita a sintaxe mas ignora as listas de registro.  As informações de depuração são produzidas pelo montador suporta padrão convenção de chamada.  
  
 IMPORTAÇÃO e EXTERN  
 ```  
  
IMPORT sym{, WEAK alias{, TYPE t}}  
  
```  
  
 `sym`é o nome do símbolo a ser importado.  
  
 Se FRACO `alias` for especificado, indica que `sym` é um externo fraco.  Não se for encontrada nenhuma definição para ele em tempo de link, em vez disso, todas as referências a ele ligar para `alias`.  
  
 Se tipo de  `t` for especificado, em seguida, `t` indica como o vinculador deve tentar resolver `sym`.  Esses valores para `t` são possíveis:   
1 — Não realize uma pesquisa de biblioteca`sym`   
2 – Realizar uma pesquisa de biblioteca`sym`   
3 —`sym` é um alias de `alias` \(padrão\)  
  
 EXTERNO é um sinônimo para importação, exceto que `sym` é importado apenas se houver referências a ele no assembly atual.  
  
 MACRO  
 Não há suporte para o uso de uma variável para o código de condição de uma macro.  Valores padrão para parâmetros não são suportados de macro.  
  
 NOFP  
 Sem suporte.  
  
 OPT, TTL, SUBT  
 Não é suportada porque o montador ARM Microsoft não produz listagens.  
  
 PRESERVE8  
 Sem suporte.  
  
 RELOC  
 `RELOC n`só podem seguir uma instrução ou uma diretiva de definição de dados.  Não há nenhum "símbolo anônimo" que pode ser realocado.  
  
 EXIGEM  
 Sem suporte.  
  
 REQUIRE8  
 Sem suporte.  
  
 THUMBX  
 Não é suportada porque o montador ARM da Microsoft não suporta o conjunto de instruções Thumb\-2EE.  
  
## Consulte também  
 [ARM Assembler Command\-Line Reference](../../assembler/arm/arm-assembler-command-line-reference.md)   
 [ARM Assembler Diagnostic Messages](../../assembler/arm/arm-assembler-diagnostic-messages.md)