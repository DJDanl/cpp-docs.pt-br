---
title: Regras de modo de lote | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- inference rules in NMAKE
- NMAKE program, inference rules
- batch-mode inference rules in NMAKE
ms.assetid: 0650b547-ef19-4455-9bba-fa567dcf88f2
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: be8c00009e285ec84f42ae6f53c578a3084432de
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="batch-mode-rules"></a>Regras de modo do lote
```  
{frompath}.fromext{topath}.toext::  
   commands  
```  
  
 Regras de inferência de modo de lote fornecem apenas uma invocação da regra de inferência quando comandos de N passam por essa regra de inferência de tipos. Sem regras de inferência de modo de lote, ela requer que os comandos de N a ser invocado. N é o número de dependentes que disparam a regra de inferência de tipos.  
  
 Makefiles que contêm regras de inferência de modo de lote deve usar NMAKE versão 1,62 ou superior. Para verificar a versão NMAKE, execute a macro _NMAKE_VER disponível com a versão NMAKE 1,62 ou superior. Esta macro retorna uma cadeia de caracteres que representa a versão de produto do Visual C++.  
  
 A diferença sintática somente da regra de inferência padrão é que a regra de inferência de modo de lote é encerrada com um dois-pontos duplos (:).  
  
> [!NOTE]
>  A ferramenta está sendo chamada deve ser capaz de lidar com vários arquivos. A regra de inferência de modo de lote deve usar `$<` como a macro para acessar arquivos dependentes.  
  
 As regras de inferência de modo de lote podem acelerar o processo de compilação. É mais rápido para fornecer os arquivos para o compilador em lote, porque o driver do compilador é chamado apenas uma vez. Por exemplo, o compilador C e C++ executa melhor ao lidar com um conjunto de arquivos porque ele pode permanecer residente durante o processo de memória.  
  
 O exemplo a seguir mostra como usar regras de inferência de modo de lote:  
  
```  
#  
# sample makefile to illustrate batch-mode inference rules  
#  
O = .  
S = .  
Objs = $O/foo1.obj $O/foo2.obj $O/foo2.obj $O/foo3.obj $O/foo4.obj  
CFLAGS = -nologo  
  
all : $(Objs)  
  
!ifdef NOBatch  
{$S}.cpp{$O}.obj:  
!else  
{$S}.cpp{$O}.obj::  
!endif  
   $(CC) $(CFLAGS) -Fd$O\ -c $<  
  
$(Objs) :  
  
#end of makefile  
```  
  
 NMAKE produz a seguinte saída sem regras de inferência de modo de lote:  
  
```  
E:\tmp> nmake -f test.mak -a NOBatch=1  
  
Microsoft (R) Program Maintenance Utility   Version 7.00.0000  
Copyright (C) Microsoft Corp 1988-2001. All rights reserved.  
        cl -nologo -Fd.\ -c .\foo1.cpp  
foo1.cpp  
        cl -nologo -Fd.\ -c .\foo2.cpp  
foo2.cpp  
        cl -nologo -Fd.\ -c .\foo3.cpp  
foo3.cpp  
        cl -nologo -Fd.\ -c .\foo4.cpp  
foo4.cpp  
```  
  
 NMAKE produz o seguinte resultado com as regras de inferência de modo de lote:  
  
```  
E:\tmp> nmake -f test.mak -a  
  
Microsoft (R) Program Maintenance Utility   Version 7.00.0000  
Copyright (C) Microsoft Corp 1988-2001. All rights reserved.  
  
        cl -nologo -Fd.\ -c .\foo1.cpp .\foo2.cpp .\foo3.cpp .\foo4.cpp  
foo1.cpp  
foo2.cpp  
foo3.cpp  
foo4.cpp  
Generating Code...  
```  
  
## <a name="see-also"></a>Consulte também  
 [Regras de inferência](../build/inference-rules.md)