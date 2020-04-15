---
title: Regras de modo do lote
ms.date: 11/04/2016
helpviewer_keywords:
- inference rules in NMAKE
- NMAKE program, inference rules
- batch-mode inference rules in NMAKE
ms.assetid: 0650b547-ef19-4455-9bba-fa567dcf88f2
ms.openlocfilehash: 38402e7b8a937cebb823ce13fa1ac01fc1099878
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328404"
---
# <a name="batch-mode-rules"></a>Regras de modo do lote

```
{frompath}.fromext{topath}.toext::
   commands
```

As regras de inferência em modo de lote fornecem apenas uma invocação da regra de inferência quando os comandos N passam por essa regra de inferência. Sem regras de inferência em modo de lote, exigiria que os comandos N fossem invocados. N é o número de dependentes que desencadeiam a regra da inferência.

Os arquivos que contêm regras de inferência em modo de lote devem usar a versão 1.62 do NMAKE ou superior. Para verificar a versão NMAKE, execute a _NMAKE_VER macro disponível com a versão 1.62 ou superior do NMAKE. Esta macro retorna uma seqüência representando a versão do produto Visual C++.

A única diferença sintática da regra de inferência padrão é que a regra de inferência em modo de lote é terminada com um duplo cólon (::).

> [!NOTE]
> A ferramenta que está sendo invocada deve ser capaz de lidar com vários arquivos. A regra de inferência `$<` do modo de lote deve ser usada como macro para acessar arquivos dependentes.

As regras de inferência do modo de lote podem acelerar o processo de construção. É mais rápido fornecer arquivos para o compilador em lote, porque o driver do compilador é invocado apenas uma vez. Por exemplo, o compilador C e C++ tem melhor desempenho ao manusear um conjunto de arquivos porque ele pode permanecer residente de memória durante o processo.

O exemplo a seguir mostra como usar as regras de inferência em modo de lote:

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

O NMAKE produz a seguinte saída sem regras de inferência em modo de lote:

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

A NMAKE produz o seguinte resultado com as regras de inferência em modo de lote:

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

## <a name="see-also"></a>Confira também

[Regras de inferência](inference-rules.md)
