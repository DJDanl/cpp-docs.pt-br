---
title: Comandos em um Makefile | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: commands, makefiles
ms.assetid: 8085517e-42f4-493b-b8f8-44311fc08c64
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c20707f2fc36790fc1b90e9a9df295bcd25f7af3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="commands-in-a-makefile"></a>Comandos em um makefile
Uma regra de bloqueio ou inferência Descrição especifica um bloco de comandos para executar, se a dependência está desatualizada. NMAKE exibe cada comando antes de executá-lo, a menos que /S, **. SILENCIOSA**, **! CMDSWITCHES**, ou @ é usado. NMAKE procura por uma regra de inferência correspondência se um bloco de descrição não é seguido por um bloco de comandos.  
  
 Um bloco de comandos contém um ou mais comandos, cada um em sua própria linha. Nenhuma linha em branco pode aparecer entre a dependência ou regra e o bloco de comandos. No entanto, pode aparecer uma linha que contém somente espaços ou guias; Essa linha é interpretada como um comando nulo e não ocorre nenhum erro. Linhas em branco são permitidas entre as linhas de comando.  
  
 Uma linha de comando começa com um ou mais espaços ou guias. Uma barra invertida (\) seguida por um caractere de nova linha é interpretada como um espaço no comando. Use uma barra invertida no final de uma linha para continuar um comando para a próxima linha. NMAKE interpreta a barra invertida literalmente se qualquer outro caractere, incluindo um espaço ou tabulação, segue a barra invertida.  
  
 Um comando precedido por um ponto e vírgula (;) pode aparecer em uma regra de inferência ou de linha de dependência ou não segue um bloco de comandos:  
  
```  
project.obj : project.c project.h ; cl /c project.c  
```  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Modificadores de comando](../build/command-modifiers.md)  
  
 [Sintaxe de partes de nome de arquivo](../build/filename-parts-syntax.md)  
  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência a NMAKE](../build/nmake-reference.md)