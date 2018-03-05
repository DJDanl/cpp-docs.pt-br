---
title: "-SÍMBOLOS | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /symbols
dev_langs:
- C++
helpviewer_keywords:
- symbols, dumping
- public symbols
- symbols, displaying COFF symbol table
- symbol tables
- SYMBOLS dumpbin option
- /SYMBOLS dumpbin option
- -SYMBOLS dumpbin option
ms.assetid: 34bcae90-4561-4c77-a80c-065508dec39a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fb8a1a42bf0bbb3b0bf9b907f93e1c9d0e69cf5b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="symbols"></a>/SYMBOLS
```  
/SYMBOLS  
```  
  
 Esta opção exibe a tabela de símbolos COFF. Tabelas de símbolos existem em todos os arquivos de objeto. Uma tabela de símbolos COFF aparece em um arquivo de imagem apenas se ele está vinculado com /DEBUG.  
  
 A seguir está uma descrição da saída para /SYMBOLS. Informações adicionais sobre o significado de saída /SYMBOLS podem ser localizadas ao pesquisar em Winnt. h (IMAGE_SYMBOL e IMAGE_AUX_SYMBOL), ou documentação COFF.  
  
 Dado o despejo de exemplo a seguir:  
  
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
  
## <a name="remarks"></a>Comentários  
 A seguinte descrição para as linhas que começam com um número de símbolo, descreve as colunas que têm informações relevantes para os usuários:  
  
-   O primeiro número de três dígitos é o número da índice símbolo.  
  
-   Se a terceira coluna contém seções*x*, o símbolo é definido na seção do arquivo de objeto. Mas se UNDEF for exibida, não está definida no objeto e deve ser resolvido em outro lugar.  
  
-   A quinta coluna (estático, externo) informa se o símbolo é visível somente dentro desse objeto, ou se ele é público (visível externamente). Um símbolo estático, _sym, não ser vinculado a um _sym de símbolos públicos; Esses seriam duas instâncias diferentes de funções chamadas _sym.  
  
 A última coluna em uma linha numerada é o nome do símbolo, ambos decorados e não decorados.  
  
 Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)