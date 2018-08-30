---
title: . Arquivos obj como entrada de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 12/29/2017
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- linker [C++], OBJ files as input
- object files, linker output
- OMF object files
- LINK tool [C++], .obj files
- COFF files
- OBJ files as linker input
- .obj files as linker input
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ffbc1d7fc7f74121c37c9e80a538ec60f2265701
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43219556"
---
# <a name="obj-files-as-linker-input"></a>Arquivos .Obj como entrada de vinculador

A ferramenta do vinculador (LINK. EXE) aceita arquivos. obj que estão em comum COFF Object File Format ().

## <a name="remarks"></a>Comentários

A Microsoft fornece uma descrição completa do formato de arquivo comum do objeto. Para obter mais informações, consulte [formato PE](/windows/desktop/Debug/pe-format).

## <a name="unicode-support"></a>Suporte para Unicode

Começando com o Visual Studio 2005, o compilador Microsoft Visual C++ dá suporte a caracteres Unicode em identificadores, conforme definido pela ISO/IEC C e padrões do C++. Versões anteriores do compilador suporte apenas caracteres ASCII em identificadores. Para dar suporte a Unicode nos nomes de funções, classes e estáticos, o compilador e vinculador usam a codificação Unicode UTF-8 para símbolos COFF nos arquivos. obj. A codificação UTF-8 é ele é compatível com codificação ASCII usado por versões anteriores do Visual Studio.

Para obter mais informações sobre o compilador e vinculador, consulte [suporte a Unicode no compilador e vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md). Para obter mais informações sobre o padrão Unicode, consulte o [Unicode](http://go.microsoft.com/fwlink/p/?linkid=37123) organização.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](../../build/reference/link-input-files.md)  
[Opções do vinculador](../../build/reference/linker-options.md)  
[Suporte para Unicode](../../text/support-for-unicode.md)  
[Suporte Unicode no compilador e no vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md)  
[Padrão Unicode](http://go.microsoft.com/fwlink/p/?linkid=37123)  
[Formato PE](/windows/desktop/Debug/pe-format)  
