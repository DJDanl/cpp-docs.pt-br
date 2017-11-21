---
title: . Arquivos obj como entrada de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- linker [C++], OBJ files as input
- object files, linker output
- OMF object files
- LINK tool [C++], .obj files
- COFF files
- OBJ files as linker input
- .obj files as linker input
ms.assetid: 3028e423-8b10-4972-8eb4-6e9ae58f0a26
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ca8346f9ff29d097450eda4d8bfbfee7f7a3f522
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="obj-files-as-linker-input"></a>Arquivos .Obj como entrada de vinculador
A ferramenta do vinculador (LINK. EXE) aceita arquivos. obj que estão no formato de arquivo de objeto comum (COFF).  
  
## <a name="remarks"></a>Comentários  
 A Microsoft fornece um documento para download que define o formato de arquivo de objeto comum. Para obter mais informações, baixe revisão 8.1 ou posterior do [executável portátil da Microsoft e a especificação de formato de arquivo de objeto comum](http://go.microsoft.com/fwlink/?LinkId=93292).  
  
## <a name="unicode-support"></a>Suporte para Unicode  
 A partir do Visual Studio 2005, o compilador do Microsoft Visual C++ dá suporte a caracteres Unicode em identificadores conforme definido pela ISO/IEC C e padrões de C++. Versões anteriores do compilador tem suporte apenas caracteres ASCII em identificadores. Para dar suporte a Unicode nos nomes de funções, classes e estáticos, o compilador e vinculador usam a codificação Unicode UTF-8 para símbolos COFF em arquivos. obj. A codificação UTF-8 é upwardly compatível com codificação ASCII usado por versões anteriores do Visual Studio.  
  
 Para obter mais informações sobre o compilador e vinculador, consulte [suporte Unicode no compilador e vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md). Para obter mais informações sobre o padrão Unicode, consulte o [Unicode](http://go.microsoft.com/fwlink/?LinkId=37123) organização.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de entrada de LINK](../../build/reference/link-input-files.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [Suporte a Unicode](../../text/support-for-unicode.md)   
 [Suporte a Unicode no compilador e vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md)   
 [Padrão Unicode](http://go.microsoft.com/fwlink/?LinkId=37123)   
 [Especificação de formato de arquivo de objeto comum](http://go.microsoft.com/fwlink/?LinkId=93292)