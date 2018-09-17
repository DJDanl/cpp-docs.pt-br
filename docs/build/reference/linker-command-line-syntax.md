---
title: Sintaxe da linha de comando do vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- linker [C++], syntax
- linker command line [C++]
- LINK tool [C++], command-line syntax
ms.assetid: e2a31e17-77bd-4e74-9305-75b105b26539
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5f1e891d91b96c5f29fb01dae5b1b8b9d731cdf3
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718311"
---
# <a name="linker-command-line-syntax"></a>Sintaxe da linha de comando do vinculador

Para executar o LINK. EXE, use a seguinte sintaxe de comando:

```
LINK arguments
```

O `arguments` incluem opções e nomes de arquivo e podem ser especificados em qualquer ordem. As opções são processadas primeiro e, em seguida, arquivos. Use um ou mais espaços ou tabulações para separar os argumentos.

> [!NOTE]
>  Você pode iniciar essa ferramenta apenas de prompt de comando do Visual Studio. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.

Na linha de comando, uma opção consiste em um especificador de opção, um traço (-) ou uma barra (/), seguido do nome da opção. Nomes de opção não podem ser abreviados. Algumas opções têm um argumento, especificado após dois-pontos (:). Sem espaços ou tabulações são permitidas dentro de uma especificação de opção, exceto em uma cadeia de caracteres entre aspas na opção /COMMENT. Especifica argumentos numéricos em decimal ou notação de linguagem C. Nomes de opções e seus argumentos de palavra-chave ou nome de arquivo não diferenciam maiusculas de minúsculas, mas identificadores como argumentos diferenciam maiusculas de minúsculas.

Para passar um arquivo para o vinculador, especifique o nome do arquivo na linha de comando após o comando LINK. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo, e você pode usar curingas no nome do arquivo. Se você omitir a extensão de nome de arquivo e o ponto (.), o LINK pressupõe. obj com a finalidade de localizar o arquivo. LINK não usa extensões de nome de arquivo ou a falta delas fazer suposições sobre o conteúdo de arquivos; ele determina o tipo de arquivo examinando-a e processa de acordo.

link.exe retorna zero para êxito (sem erros).  Caso contrário, o vinculador retorna o número do erro que interrompeu o link.  Por exemplo, se o vinculador gera LNK1104, o vinculador retorna 1104.  Da mesma forma, o menor número de erro retornado em um erro pelo vinculador é 1000.  Um valor de retorno de 128 representa um problema de configuração com o sistema operacional ou um arquivo. config; o carregador não foi carregado link.exe ou c2.dll.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)