---
title: Suporte a Unicode no compilador e vinculador | Microsoft Docs
ms.custom: ''
ms.date: 12/15/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.UseUnicodeResponseFiles
- VC.Project.VCLibrarianTool.UseUnicodeResponseFiles
- VC.Project.VCCLCompilerTool.UseUnicodeResponseFiles
- VC.Project.VCXDCMakeTool.UseUnicodeResponseFiles
dev_langs:
- C++
helpviewer_keywords:
- Unicode, Visual C++
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ec0b84cd62f3fcca378ab55de16006925e685b37
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32376186"
---
# <a name="unicode-support-in-the-compiler-and-linker"></a>Suporte Unicode no compilador e vinculador

A maioria das ferramentas de compilação do Visual C++ suporte Unicode entradas e saídas.

## <a name="filenames"></a>Nomes de arquivos

Nomes de arquivo especificado na linha de comando ou em diretivas de compilador (como `#include`) pode conter caracteres Unicode.

## <a name="source-code-files"></a>Arquivos de código fonte

Caracteres Unicode são suportados em literais de cadeia de caracteres e caracteres, macros, identificadores e nos comentários.  Também há suporte para nomes de caractere universal.

Unicode pode ser inserido em um arquivo de código fonte nas seguintes codificações:

- Endian de UTF-16 little com ou sem a marca de ordem de byte (BOM)

- Endian grande de UTF-16 com ou sem BOM

- UTF-8 com BOM

## <a name="output"></a>Saída

Durante a compilação, o compilador gera o diagnóstico no console em UTF-16.  Os caracteres que podem ser exibidos no seu console dependem as propriedades da janela de console.  É redirecionada para um arquivo de saída do compilador na página de código atual do console ANSI.

## <a name="linker-response-files-and-def-files"></a>Arquivos de resposta de vinculador e. Arquivos DEF

Arquivos de resposta e arquivos DEF podem ser qualquer UTF-16 com BOM ou ANSI.

## <a name="asm-and-cod-dumps"></a>despejos de memória. ASM e. COD

Por padrão para compatibilidade com MASM, despejos. ASM e. COD estão ANSI. Use [/FAu](../../build/reference/fa-fa-listing-file.md) para saída UTF-8. Observe que, se você especificar **/FAs**, a fonte entremeada apenas ser impresso diretamente e pode se parecer com erros, por exemplo, se o código-fonte é UTF-8 e você não especificar **/FAsu**.

## <a name="see-also"></a>Consulte também

[Compilar código C/C++ na linha de comando](../../build/building-on-the-command-line.md)