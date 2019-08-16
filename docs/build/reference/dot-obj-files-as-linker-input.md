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
ms.openlocfilehash: 3e02ccc09ae8c9c2f3df88bc1767ff0188baa1f4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492935"
---
# <a name="obj-files-as-linker-input"></a>Arquivos .Obj como entrada de vinculador

A ferramenta do vinculador (LINK. EXE) aceita arquivos. obj que estão no formato de arquivo de objeto comum (COFF).

## <a name="remarks"></a>Comentários

A Microsoft fornece uma descrição completa do formato de arquivo de objeto comum. Para obter mais informações, consulte [formato PE](/windows/win32/Debug/pe-format).

## <a name="unicode-support"></a>Suporte para Unicode

A partir do Visual Studio 2005, o compilador Microsoft MSVC dá suporte a caracteres Unicode em identificadores, conforme definido pelos padrões ISO C++ /IEC C e. As versões anteriores do compilador suportavam apenas caracteres ASCII em identificadores. Para dar suporte a Unicode nos nomes de funções, classes e estáticas, o compilador e o vinculador usam a codificação Unicode UTF-8 para símbolos COFF nos arquivos. obj. A codificação UTF-8 é compatível de maneira retroativa com a codificação ASCII usada por versões anteriores do Visual Studio.

Para obter mais informações sobre o compilador e o vinculador, consulte [suporte a Unicode no compilador e vinculador](unicode-support-in-the-compiler-and-linker.md). Para obter mais informações sobre o padrão Unicode, consulte a organização [Unicode](https://www.unicode.org/) .

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](link-input-files.md)<br/>
[Opções de vinculador MSVC](linker-options.md)<br/>
[Suporte para Unicode](../../text/support-for-unicode.md)<br/>
[Suporte Unicode no compilador e no vinculador](unicode-support-in-the-compiler-and-linker.md)<br/>
[Padrão Unicode](https://www.unicode.org/)<br/>
[Formato PE](/windows/win32/Debug/pe-format)
