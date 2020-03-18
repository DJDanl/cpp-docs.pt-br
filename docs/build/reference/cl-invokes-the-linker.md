---
title: O CL invoca o vinculador
ms.date: 11/04/2016
helpviewer_keywords:
- compiling source code [C++], without linking
- invoking linker from the compiler
- LINK tool [C++], invoking from CL compiler
- cl.exe compiler [C++], compiling without linking
- cl.exe compiler [C++], controlling linker
ms.assetid: eae47ef7-09eb-40c9-b318-7c714cd452fc
ms.openlocfilehash: 1f9bb466ae89b8e3491b027a98b28935e7c8b523
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440188"
---
# <a name="cl-invokes-the-linker"></a>O CL invoca o vinculador

O CL invoca automaticamente o vinculador após a compilação, a menos que a opção/c seja usada. CL passa para o vinculador os nomes de arquivos. obj criados durante a compilação e os nomes de quaisquer outros arquivos especificados na linha de comando. O vinculador usa as opções listadas na variável de ambiente do LINK. Você pode usar a opção/link para especificar opções de vinculador na linha de comando CL. As opções que seguem a opção/link substituem aquelas na variável de ambiente de LINK. As opções na tabela a seguir suprimim a vinculação.

|{1&gt;Opção&lt;1}|Descrição|
|------------|-----------------|
|/c|Compilar sem vincular|
|/E, /EP, /P|Pré-processar sem compilar ou vincular|
|/Zg|Gerar protótipos de função|
|/Zs|Verificar sintaxe|

Para obter mais detalhes sobre a vinculação, consulte [Opções do vinculador MSVC](linker-options.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Suponha que você esteja compilando três arquivos de origem C: MAIN. c, MOD1. c e MOD2. c. Cada arquivo inclui uma chamada para uma função definida em um arquivo diferente:

- MAIN. c chama a função `func1` em MOD1. c e a função `func2` em MOD2. c.

- MOD1. c chama as funções de biblioteca padrão `printf_s` e `scanf_s`.

- MOD2. c chama funções gráficas chamadas `myline` e `mycircle`, que são definidas em uma biblioteca chamada MYGRAPH. lib.

Para compilar este programa, compile com a seguinte linha de comando:

```
CL MAIN.c MOD1.C MOD2.C MYGRAPH.lib
```

O CL primeiro compila os arquivos de origem C e cria os arquivos de objeto MAIN. obj, MOD1. obj e MOD2. obj. O compilador coloca o nome da biblioteca padrão em cada arquivo. obj. Para obter mais detalhes, consulte [usar biblioteca de tempo de execução](md-mt-ld-use-run-time-library.md).

CL passa os nomes dos arquivos. obj, juntamente com o nome MYGRAPH. lib, para o vinculador. O vinculador resolve as referências externas da seguinte maneira:

1. No MAIN. obj, a referência a `func1` é resolvida usando a definição em MOD1. obj; a referência a `func2` é resolvida usando a definição em MOD2. obj.

1. No MOD1. obj, as referências a `printf_s` e `scanf_s` são resolvidas usando as definições na biblioteca que o vinculador encontra nomeado em MOD1. obj.

1. No MOD2. obj, as referências a `myline` e `mycircle` são resolvidas usando as definições em MYGRAPH. lib.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Definindo opções do compilador](compiler-command-line-syntax.md)
