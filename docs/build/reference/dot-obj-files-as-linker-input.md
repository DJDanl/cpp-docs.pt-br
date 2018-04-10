---
title: . Arquivos obj como entrada de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 12/29/2017
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
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
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9a2896822e97bdbb5ffdf8f869e67beadc1675b7
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="obj-files-as-linker-input"></a>Arquivos .Obj como entrada de vinculador

A ferramenta do vinculador (LINK. EXE) aceita arquivos. obj que estão no formato de arquivo de objeto comum (COFF).

## <a name="remarks"></a>Comentários

A Microsoft fornece uma descrição completa do formato de arquivo comuns do objeto. Para obter mais informações, consulte [formato PE](https://msdn.microsoft.com/library/windows/desktop/ms680547).

## <a name="unicode-support"></a>Suporte para Unicode

A partir do Visual Studio 2005, o compilador do Microsoft Visual C++ dá suporte a caracteres Unicode em identificadores conforme definido pela ISO/IEC C e padrões de C++. Versões anteriores do compilador tem suporte apenas caracteres ASCII em identificadores. Para dar suporte a Unicode nos nomes de funções, classes e estáticos, o compilador e vinculador usam a codificação Unicode UTF-8 para símbolos COFF em arquivos. obj. A codificação UTF-8 é upwardly compatível com codificação ASCII usado por versões anteriores do Visual Studio.

Para obter mais informações sobre o compilador e vinculador, consulte [suporte Unicode no compilador e vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md). Para obter mais informações sobre o padrão Unicode, consulte o [Unicode](http://go.microsoft.com/fwlink/p/?linkid=37123) organização.

## <a name="see-also"></a>Consulte também

[Arquivos de entrada de LINK](../../build/reference/link-input-files.md)  
[Opções do vinculador](../../build/reference/linker-options.md)  
[Suporte para Unicode](../../text/support-for-unicode.md)  
[Suporte Unicode no compilador e no vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md)  
[Padrão Unicode](http://go.microsoft.com/fwlink/p/?linkid=37123)  
[Formato PE](https://msdn.microsoft.com/library/windows/desktop/ms680547)  
