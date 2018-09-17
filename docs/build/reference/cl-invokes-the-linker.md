---
title: CL invoca o vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- cl
dev_langs:
- C++
helpviewer_keywords:
- compiling source code [C++], without linking
- invoking linker from the compiler
- LINK tool [C++], invoking from CL compiler
- cl.exe compiler [C++], compiling without linking
- cl.exe compiler [C++], controlling linker
ms.assetid: eae47ef7-09eb-40c9-b318-7c714cd452fc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed6c968b86192ae79c0c921f8b3fababc596c9a2
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713824"
---
# <a name="cl-invokes-the-linker"></a>O CL invoca o vinculador

Automaticamente, o CL invoca o vinculador após a compilação, a menos que a opção /c é usada. CL passa para o vinculador os nomes dos arquivos. obj criados durante a compilação e os nomes de quaisquer outros arquivos especificados na linha de comando. O vinculador usa as opções listadas na variável de ambiente LINK. Você pode usar a opção /link para especificar opções do vinculador na linha de comando CL. Opções que se seguem a opção /link substituem aquelas na variável de ambiente LINK. As opções na tabela a seguir suprimir a vinculação.

|Opção|Descrição|
|------------|-----------------|
|/c|Compilar sem vinculação|
|/ / ELETRÔNICO, /EP, P|Pré-processa sem compilar ou vincular|
|/Zg|Gerar protótipos de função|
|/Zs|Verificar sintaxe|

Para obter mais detalhes sobre a vinculação, consulte [opções de vinculador](../../build/reference/linker-options.md).

## <a name="example"></a>Exemplo

Suponha que você está compilando arquivos de origem C três: Main. c, MOD1.c e MOD2.c. Cada arquivo inclui uma chamada para uma função definida em um arquivo diferente:

- Main. c chama a função `func1` MOD1.c e a função `func2` em MOD2.c.

- MOD1.c chama as funções de biblioteca padrão `printf_s` e `scanf_s`.

- MOD2.c chama funções gráficas denominadas `myline` e `mycircle`, que é definido em uma biblioteca denominada MYGRAPH.lib.

Para compilar esse programa, compilar com a seguinte linha de comando:

```
CL MAIN.c MOD1.C MOD2.C MYGRAPH.lib
```

CL primeiro compila os arquivos de origem C e cria os arquivos de objeto Main, MOD1.obj e MOD2.obj. O compilador coloca o nome da biblioteca padrão em cada arquivo. obj. Para obter mais detalhes, consulte [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md).

CL passa os nomes dos arquivos. obj, juntamente com o nome MYGRAPH.lib, para o vinculador. O vinculador resolve as referências externas da seguinte maneira:

1. No Main, a referência ao `func1` é resolvido usando a definição no MOD1.obj; a referência ao `func2` é resolvido usando a definição no MOD2.obj.

1. No MOD1.obj, as referências aos `printf_s` e `scanf_s` são resolvidos usando as definições na biblioteca que localiza o vinculador chamada dentro do MOD1.obj.

1. No MOD2.obj, as referências aos `myline` e `mycircle` são resolvidos usando as definições no MYGRAPH.lib.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)