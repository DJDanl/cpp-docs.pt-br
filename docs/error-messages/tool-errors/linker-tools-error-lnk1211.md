---
title: Ferramentas de vinculador LNK1211 erro | Microsoft Docs
ms.date: 12/05/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1211
dev_langs:
- C++
helpviewer_keywords:
- LNK1211
ms.assetid: 607400eb-4180-4892-817f-eedfa628af61
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 57948556ae7b94b9a1788b7cb4453646b5b504f1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33300378"
---
# <a name="linker-tools-error-lnk1211"></a>Erro das Ferramentas de Vinculador LNK1211

> informações de tipo precompilado não encontradas; '*filename*' não vinculado ou sobrescrito

O *filename* arquivo de objeto, compilado usando [/Yc](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando LINK ou foi substituído.

Se você estiver criando uma biblioteca de depuração que usa cabeçalhos pré-compilados e se você especificar **/Yc** e [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), Visual C++ gera um arquivo de objeto pré-compilado que contém informações de depuração. O erro ocorre somente quando você armazena o arquivo de objeto pré-compilado em uma biblioteca, use a biblioteca para criar uma imagem executável e os arquivos de objeto referenciadas não possuem transitivas referências para qualquer uma das funções que define o arquivo de objeto pré-compilado.

Há dois métodos para solucionar essa situação:

- Especifique o [/Yd](../../build/reference/yd-place-debug-information-in-object-file.md) opção de compilador para adicionar as informações de depuração de cabeçalho pré-compilado para cada objeto de módulo. Esse método é menos recomendado porque geralmente produz módulos de objeto grande que podem aumentar o tempo necessário para vincular o aplicativo.

- Especifique [/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) e passar o nome de qualquer cadeia de caracteres arbitrária, quando você cria um arquivo de cabeçalho pré-compilado que não contém nenhuma definição de função. Isso instrui o compilador para criar um símbolo no arquivo de objeto pré-compilado e emitir uma referência a esse símbolo em cada arquivo de objeto que usavam o arquivo de cabeçalho pré-compilado que está associado com o arquivo de objeto pré-compilado.

Quando você compila um módulo com **/Yc** e **/Yl**, o compilador cria um símbolo semelhante a `__@@_PchSym_@00@...@symbol_name`, onde as reticências (...) representa uma cadeia de caracteres gerada pelo compilador e armazena no módulo de objeto. Qualquer arquivo de origem que você compile com esse cabeçalho pré-compilado refere-se para o símbolo especificado, o que faz com que o vinculador para incluir o módulo de objeto e suas informações de depuração da biblioteca.
