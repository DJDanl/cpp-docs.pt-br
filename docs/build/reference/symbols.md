---
title: "/SYMBOLS | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/symbols"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /SYMBOLS (dumpbin)"
  - "símbolos públicos"
  - "tabelas de símbolos"
  - "opção dumpbin SYMBOLS"
  - "opção dumpbin -SYMBOLS"
  - "símbolos, exibindo tabela de símbolos COFF"
  - "símbolos, despejando"
ms.assetid: 34bcae90-4561-4c77-a80c-065508dec39a
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /SYMBOLS
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/SYMBOLS  
```  
  
 Esta opção exibe a tabela de símbolo de COFF.  As tabelas de símbolo existem em todos os arquivos do objeto.  Uma tabela de símbolo de COFF aparece em um arquivo de imagem somente se estiver vinculada com \/DEBUG.  
  
 Veja a seguir uma descrição de saída para \/SYMBOLS.  Informações adicionais no significado de saída de \/SYMBOLS pode ser encontrada por vista em winnt.h \(IMAGE\_SYMBOL e IMAGE\_AUX\_SYMBOL\), ou pela documentação de COFF.  
  
 Dada a seguinte despejo de exemplo:  
  
```  
Dump of file main.obj  
File Type: COFF OBJECT  
  
COFF    SYMBOL    TABLE  
000    00000000   DEBUG      notype      Filename      | .file  
      main.cpp  
002   000B1FDB   ABS      notype      Static      | @comp.id  
003   00000000   SECT1      notype      Static      | .drectve  
      Section length       26, #relocs   0, #linenums    0, checksum 722C964F  
005   00000000   SECT2      notype      Static      | .text  
      Section length      23, #relocs      1, #linenums    0, checksum 459FF65F, selection    1 (pick no duplicates)  
007   00000000   SECT2      notype ()   External      | _main  
008   00000000   UNDEF      notype ()   External      | ?MyDump@@YAXXZ (void __cdecl MyDump(void))  
  
String Table Size = 0x10 bytes  
  
Summary  
  
      26 .drectve  
      23 .text  
```  
  
## Comentários  
 A descrição, para as linhas que comecem com um número de símbolo, descreve as colunas que têm informações relevantes para usuários:  
  
-   O primeiro número de três dígitos é o índice\/número de símbolo.  
  
-   Se a terceira coluna contém SECT*x*, o símbolo é definido nessa seção do arquivo de objeto.  Mas se UNDEF aparece, não é definido no objeto e deve ser resolvido em outro lugar.  
  
-   A quinta coluna \(estáticos, externos\) informa se o símbolo é visível somente dentro desse objeto, ou se é public \(visível externamente\).  Um símbolo estático, \_sym, não seria vinculado a um \_sym público do símbolo; essas serão duas instâncias nomeadas diferentes das funções \_sym.  
  
 A última coluna em uma linha numerada é o nome de símbolo, decorado e undecorated.  
  
 Somente a opção de DUMPBIN de [\/HEADERS](../../build/reference/headers.md) está disponível para uso em arquivos gerados com a opção do compilador de [\/GL](../../build/reference/gl-whole-program-optimization.md) .  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)