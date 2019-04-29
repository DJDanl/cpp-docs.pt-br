---
title: '@ (especificar um arquivo de resposta do compilador)'
ms.date: 11/04/2016
f1_keywords:
- '@'
helpviewer_keywords:
- response files, C/C++ compiler
- '@ compiler option'
- cl.exe compiler, specifying response files
ms.assetid: 400fffee-909d-4f60-bf76-45833e822685
ms.openlocfilehash: c2b5578e1ce1db590bdf5abbff0c91e858803ad7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62272995"
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

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
