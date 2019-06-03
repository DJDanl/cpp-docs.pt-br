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
ms.openlocfilehash: 36f41077fcba6b093865625d426b8009f6185e7b
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450583"
---
# <a name="obj-files-as-linker-input"></a>Arquivos .Obj como entrada de vinculador

A ferramenta do vinculador (LINK. EXE) aceita arquivos. obj que estão em comum COFF Object File Format ().

## <a name="remarks"></a>Comentários

A Microsoft fornece uma descrição completa do formato de arquivo comum do objeto. Para obter mais informações, consulte [formato PE](/windows/desktop/Debug/pe-format).

## <a name="unicode-support"></a>Suporte para Unicode

Começando com o Visual Studio 2005, o compilador MSVC Microsoft dá suporte a caracteres Unicode em identificadores, conforme definido pela ISO/IEC C e padrões C++. Versões anteriores do compilador suporte apenas caracteres ASCII em identificadores. Para dar suporte a Unicode nos nomes de funções, classes e estáticos, o compilador e vinculador usam a codificação Unicode UTF-8 para símbolos COFF nos arquivos. obj. A codificação UTF-8 é ele é compatível com codificação ASCII usado por versões anteriores do Visual Studio.

Para obter mais informações sobre o compilador e vinculador, consulte [suporte a Unicode no compilador e vinculador](unicode-support-in-the-compiler-and-linker.md). Para obter mais informações sobre o padrão Unicode, consulte o [Unicode](https://www.unicode.org/) organização.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](link-input-files.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[Suporte para Unicode](../../text/support-for-unicode.md)<br/>
[Suporte Unicode no compilador e no vinculador](unicode-support-in-the-compiler-and-linker.md)<br/>
[Padrão Unicode](https://www.unicode.org/)<br/>
[Formato PE](/windows/desktop/Debug/pe-format)
