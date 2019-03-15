---
title: Arquivos .Obj como entrada de vinculador
ms.date: 12/29/2017
helpviewer_keywords:
- linker [C++], OBJ files as input
- object files, linker output
- OMF object files
- LINK tool [C++], .obj files
- COFF files
- OBJ files as linker input
- .obj files as linker input
ms.openlocfilehash: c55c3181c2ddfabddce882a473e56d952a7e5d81
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816393"
---
# <a name="obj-files-as-linker-input"></a>Arquivos .Obj como entrada de vinculador

A ferramenta do vinculador (LINK. EXE) aceita arquivos. obj que estão em comum COFF Object File Format ().

## <a name="remarks"></a>Comentários

A Microsoft fornece uma descrição completa do formato de arquivo comum do objeto. Para obter mais informações, consulte [formato PE](/windows/desktop/Debug/pe-format).

## <a name="unicode-support"></a>Suporte para Unicode

Começando com o Visual Studio 2005, o compilador MSVC Microsoft dá suporte a caracteres Unicode em identificadores, conforme definido pela ISO/IEC C e padrões C++. Versões anteriores do compilador suporte apenas caracteres ASCII em identificadores. Para dar suporte a Unicode nos nomes de funções, classes e estáticos, o compilador e vinculador usam a codificação Unicode UTF-8 para símbolos COFF nos arquivos. obj. A codificação UTF-8 é ele é compatível com codificação ASCII usado por versões anteriores do Visual Studio.

Para obter mais informações sobre o compilador e vinculador, consulte [suporte a Unicode no compilador e vinculador](unicode-support-in-the-compiler-and-linker.md). Para obter mais informações sobre o padrão Unicode, consulte o [Unicode](http://www.unicode.org/) organização.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](link-input-files.md)<br/>
[Opções do vinculador MSVC](linker-options.md)<br/>
[Suporte para Unicode](../../text/support-for-unicode.md)<br/>
[Suporte Unicode no compilador e no vinculador](unicode-support-in-the-compiler-and-linker.md)<br/>
[Padrão Unicode](http://www.unicode.org/)<br/>
[Formato PE](/windows/desktop/Debug/pe-format)
