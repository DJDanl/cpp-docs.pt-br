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
ms.openlocfilehash: 420b01263320cf86df3f99da4523cc2b8bb4d4b6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168831"
---
# <a name="unicode-support-in-the-compiler-and-linker"></a>Suporte Unicode no compilador e vinculador

A maioria C++ das ferramentas de Build do Visual oferece suporte a entradas e saídas Unicode.

## <a name="filenames"></a>Nomes de arquivos

Os nomes de fileespecificados na linha de comando ou nas diretivas do compilador (como `#include`) podem conter caracteres Unicode.

## <a name="source-code-files"></a>Arquivos de código-fonte

Há suporte para caracteres Unicode em identificadores, macros, cadeias de caracteres e literais de caracteres e em comentários.  Também há suporte para nomes de caracteres universais.

O Unicode pode ser inserido em um arquivo de código-fonte nas seguintes codificações:

- UTF-16 little endian com ou sem marca de ordem de byte (BOM)

- Big endian UTF-16 com ou sem BOM

- UTF-8 with BOM

## <a name="output"></a>Saída

Durante a compilação, o compilador gera diagnósticos para o console em UTF-16.  Os caracteres que podem ser exibidos no console dependem das propriedades da janela do console.  A saída do compilador redirecionada para um arquivo está na página de código do console ANSI atual.

## <a name="linker-response-files-and-def-files"></a>Arquivos de resposta do vinculador e. Arquivos DEF

Arquivos de resposta e arquivos DEF podem ser UTF-16 com uma BOM ou ANSI.

## <a name="asm-and-cod-dumps"></a>despejos. asm e. COD

os despejos. asm e. COD estão em ANSI por padrão para compatibilidade com MASM. Use [/FAU](fa-fa-listing-file.md) para saída UTF-8. Observe que, se você especificar **/FAS**, a fonte intermisturada será impressa diretamente e poderá parecer distorcida, por exemplo, se o código-fonte for UTF-8 e você não tiver especificado **/FAsu**.

## <a name="see-also"></a>Confira também

[Uso do conjunto de ferramentas MSVC da linha de comando](../building-on-the-command-line.md)
