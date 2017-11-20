---
title: Suporte a Unicode no compilador e vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.UseUnicodeResponseFiles
- VC.Project.VCLibrarianTool.UseUnicodeResponseFiles
- VC.Project.VCCLCompilerTool.UseUnicodeResponseFiles
- VC.Project.VCXDCMakeTool.UseUnicodeResponseFiles
dev_langs: C++
helpviewer_keywords: Unicode, Visual C++
ms.assetid: acc1d322-56b9-4696-a30e-2af891a4e288
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 15fefc4cc44edfd67bd8ba89ab68c6965c8639a6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="unicode-support-in-the-compiler-and-linker"></a>Suporte Unicode no compilador e vinculador
Este tópico descreve o suporte a Unicode nas ferramentas de compilação do Visual C++.  
  
 Nomes de arquivos  
 Nomes de arquivo especificado na linha de comando ou em diretivas de compilador (como #include) agora pode conter caracteres Unicode.  
  
 Arquivos de código fonte  
 Agora há suporte para caracteres Unicode em identificadores, macros, literais de cadeia de caracteres e caracteres e nos comentários.  Também há suporte para nomes de caractere universal.  
  
 Unicode pode ser inserido em um arquivo de código fonte nas seguintes codificações:  
  
-   Endian de UTF-16 little com ou sem a marca de ordem de byte (BOM)  
  
-   Endian grande de UTF-16 com ou sem BOM  
  
-   UTF-8 com BOM  
  
 Saída  
 Durante a compilação, o compilador gera o diagnóstico no console em UTF-16.  Os caracteres que podem ser exibidos no seu console dependem as propriedades da janela de console.  É redirecionada para um arquivo de saída do compilador na página de código atual do console ANSI.  
  
 Arquivos de resposta de vinculador e. Arquivos DEF  
 Arquivos de resposta e arquivos DEF podem ser qualquer UTF-16 com uma marca de ordem de bytes ou ANSI.  Anteriormente havia suporte para apenas ANSI.  
  
 despejos de memória. ASM e. COD  
 Por padrão para compatibilidade com MASM, despejos. ASM e. COD estão ANSI.  Use /FAu para saída UTF-8.  Observe que, se você especificar /FAs, a fonte entremeada apenas ser impresso diretamente e pode se parecer com erros, por exemplo, se o código-fonte é UTF-8 e você não especificar /FAsu.  
  
 Você pode habilitar os nomes de arquivo Unicode no ambiente de desenvolvimento (consulte [trabalhando com propriedades de projeto](../../ide/working-with-project-properties.md)), selecionando a ferramenta apropriada e selecionando o **habilitar arquivos de resposta Unicode** propriedade qual é habilitado por padrão. Um motivo que você pode alterar esse padrão é se você modificar o ambiente de desenvolvimento para usar um compilador que não têm Unicode suporte.  
  
## <a name="see-also"></a>Consulte também  
 [Compilar o código C/C++ na linha de comando](../../build/building-on-the-command-line.md)