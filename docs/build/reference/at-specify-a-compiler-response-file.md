---
title: '@ (Especificar um arquivo de resposta do compilador) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '@'
dev_langs:
- C++
helpviewer_keywords:
- response files, C/C++ compiler
- '@ compiler option'
- cl.exe compiler, specifying response files
ms.assetid: 400fffee-909d-4f60-bf76-45833e822685
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9c86d49aea2ce7a8d8b438c64cd883b71e5a4646
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720844"
---
# <a name="-specify-a-compiler-response-file"></a>@ (especificar um arquivo de resposta do compilador)

Especifica um arquivo de resposta do compilador.

## <a name="syntax"></a>Sintaxe

> **\@**<em>response_file</em>

## <a name="arguments"></a>Arguments

*response_file*<br/>
Um arquivo de texto que contém os comandos do compilador.

## <a name="remarks"></a>Comentários

Um arquivo de resposta pode conter todos os comandos que você especificaria na linha de comando. Isso pode ser útil se os argumentos de linha de comando excederem 127 caracteres.

Não é possível especificar o **\@** opção dentro de um arquivo de resposta. Ou seja, um arquivo de resposta não é possível inserir outro arquivo de resposta.

Na linha de comando, você pode especificar quantas opções de arquivo de resposta (por exemplo, `@respfile.1 @respfile.2`) como você deseja.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

- Um arquivo de resposta não pode ser especificado de dentro do ambiente de desenvolvimento e deve ser especificado na linha de comando.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Essa opção do compilador não pode ser alterada programaticamente.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
