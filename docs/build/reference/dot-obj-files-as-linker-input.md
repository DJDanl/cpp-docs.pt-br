---
title: "Arquivos .Obj como entrada de vinculador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .obj como entrada de vinculador"
  - "arquivos COFF"
  - "ferramenta LINK [C++], Arquivos .obj"
  - "vinculador [C++], arquivos OBJ como entrada"
  - "arquivos OBJ como entrada de vinculador"
  - "arquivos de objeto, saída de vinculador"
  - "arquivos de objeto OMF"
ms.assetid: 3028e423-8b10-4972-8eb4-6e9ae58f0a26
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos .Obj como entrada de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A ferramenta do vinculador \(LINK.EXE\) aceita os arquivos de .obj que estão no formato de arquivo comum \(COFF\) do objeto.  
  
## Comentários  
 O Microsoft fornece um documento para download que define o formato de arquivo comuns do objeto.  Para obter mais informações, examine 8,1 de download ou [Executável portátil da Microsoft e a especificação do formato de arquivo do objeto](http://go.microsoft.com/fwlink/?LinkId=93292)posterior do.  
  
## Suporte a Unicode  
 Iniciando com o Visual Studio 2005, o compilador do Microsoft Visual C\+\+ oferece suporte a caracteres Unicode em identificadores como definidos por padrão o PADRÃO C e C\+\+ 2.0.  As versões anteriores do compilador suportados apenas caracteres ASCII em identificadores.  Para oferecer suporte ao Unicode nos nomes de funções, as classes, e a digitação estática, o compilador e o vinculador Unicode usam codificação UTF\-8 para símbolos de COFF em arquivos de .obj.  A codificação UTF\-8 upstream é compatível com a codificação ASCII usada por versões anteriores do Visual Studio.  
  
 Para obter mais informações sobre o compilador e do vinculador, consulte [Suporte Unicode no compilador e vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md).  Para obter mais informações sobre o padrão Unicode, consulte [Unicode](http://go.microsoft.com/fwlink/?LinkId=37123) a organização.  
  
## Consulte também  
 [Arquivos de entrada LINK](../../build/reference/link-input-files.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [Suporte para Unicode](../../text/support-for-unicode.md)   
 [Suporte Unicode no compilador e vinculador](../../build/reference/unicode-support-in-the-compiler-and-linker.md)   
 [Padrão Unicode](http://go.microsoft.com/fwlink/?LinkId=37123)   
 [Especificação do formato de arquivo do objeto](http://go.microsoft.com/fwlink/?LinkId=93292)