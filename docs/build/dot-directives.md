---
title: Diretivas de ponto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, dot directives
- dot directives in NMAKE
ms.assetid: ab35da65-30b6-48b7-87d6-61503d7faf9f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f2f4b984bcfe1aa89fd8e0229c7381c0d01f8685
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714604"
---
# <a name="dot-directives"></a>Diretivas de ponto

Especifique diretivas dot fora de um bloco de descrição, no início de uma linha. Diretivas dot começam com um ponto (. ) e são seguidas por dois-pontos (:). São permitidas espaços e guias. Nomes de diretiva dot diferenciam maiusculas de minúsculas e maiusculas.

|Diretiva|Finalidade|
|---------------|-------------|
|**. IGNORE:**|Ignora os códigos de saída diferente de zero retornados pelos comandos do local que for especificado ao final do makefile. Por padrão, NMAKE é interrompida se um comando retorna um código de saída diferente de zero. Para restaurar a verificação de erros, use **! CMDSWITCHES**. Para ignorar o código de saída para um único comando, use o modificador de traço (-). Para ignorar os códigos de saída para um arquivo inteiro, use / eu.|
|**. PRECIOSOS:** *destinos*|Preserva *destinos* no disco se os comandos para atualizá-los são interrompidos; não tem nenhum efeito se um comando lida com uma interrupção, excluindo o arquivo. Separe os nomes de destino com um ou mais espaços ou tabulações. Por padrão, o NMAKE exclui um destino, se um build é interrompido por CTRL + C ou CTRL + BREAK. Cada uso de **. PRECIOSOS** aplica-se para o makefile inteiro; várias especificações são cumulativas.|
|**. SILENCIOSO:**|Suprime a exibição de comandos executados, do local que for especificado ao final do makefile. Por padrão, NMAKE exibe os comandos que ele chama. Para restaurar o eco, use **! CMDSWITCHES**. Para suprimir o eco de um único comando, use o **@** modificador. Para suprimir o eco de um arquivo inteiro, use/s.|
|**. SUFIXOS:** `list`|Lista de extensões para a correspondência da regra de inferência; predefinidas para incluir as seguintes extensões: .exe. obj. ASM. c. cpp. cxx. BAS. cbl. para obter. PAS. res. rc 1).f .f90|

Para alterar o **. SUFIXOS** listar ordem ou para especificar uma nova lista, limpe a lista e especificar uma nova configuração. Para limpar a lista, não especifique nenhuma extensão após os dois-pontos:

```
.SUFFIXES :
```

Para adicionar sufixos adicionais ao final da lista, especifique

```
.SUFFIXES : suffixlist
```

em que *suffixlist* é uma lista dos sufixos adicionais, separados por um ou mais espaços ou tabulações. Para ver a configuração atual da **. SUFIXOS**, executar NMAKE com /P.

## <a name="see-also"></a>Consulte também

[Referência a NMAKE](../build/nmake-reference.md)