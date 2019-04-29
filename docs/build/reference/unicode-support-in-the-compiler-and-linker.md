---
title: Suporte Unicode no compilador e vinculador
ms.date: 12/15/2017
f1_keywords:
- VC.Project.VCLinkerTool.UseUnicodeResponseFiles
- VC.Project.VCLibrarianTool.UseUnicodeResponseFiles
- VC.Project.VCCLCompilerTool.UseUnicodeResponseFiles
- VC.Project.VCXDCMakeTool.UseUnicodeResponseFiles
helpviewer_keywords:
- Unicode, Visual C++
ms.openlocfilehash: 71458ab345670c0a5715576a7da80c4e6ff2955b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62317322"
---
# <a name="unicode-support-in-the-compiler-and-linker"></a>Suporte Unicode no compilador e vinculador

A maioria das ferramentas de compilação do Visual C++ dão suporte a Unicode entradas e saídas.

## <a name="filenames"></a>Nomes de arquivos

Nomes de arquivo especificados na linha de comando ou em diretivas de compilador (como `#include`) pode conter caracteres Unicode.

## <a name="source-code-files"></a>Arquivos de código-fonte

Caracteres Unicode têm suporte em identificadores, macros, cadeia de caracteres literais e em comentários.  Também há suporte para nomes de caracteres universais.

Unicode pode ser inserida em um arquivo de código fonte nas codificações:

- Endian de UTF-16 pequeno com ou sem marca de ordem de byte (BOM)

- Endian de UTF-16 grande com ou sem BOM

- UTF-8 com BOM

## <a name="output"></a>Saída

Durante a compilação, o compilador gera o diagnóstico no console no UTF-16.  Os caracteres que podem ser exibidos no console dependem as propriedades da janela de console.  Redirecionado para um arquivo de saída do compilador está na página de código atual do console ANSI.

## <a name="linker-response-files-and-def-files"></a>Arquivos de resposta de vinculador e. Arquivos DEF

Arquivos de resposta e arquivos DEF podem ser UTF-16 com uma BOM ou ANSI.

## <a name="asm-and-cod-dumps"></a>despejos de. ASM e. COD

despejos de. ASM e. COD estão em ANSI por padrão para compatibilidade com MASM. Use [/FAu](fa-fa-listing-file.md) para saída UTF-8. Observe que, se você especificar **/FAs**, a origem misturada será diretamente impressa e poderá parecer truncada, por exemplo, se o código-fonte é UTF-8 e você não especificou **/fasu**.

## <a name="see-also"></a>Consulte também

[Uso do conjunto de ferramentas MSVC da linha de comando](../building-on-the-command-line.md)