---
title: -MIDL (especificar opções de linha de comando MIDL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- /midl
- VC.Project.VCLinkerTool.MidlCommandFile
dev_langs:
- C++
helpviewer_keywords:
- -MIDL linker option
- MIDL
- /MIDL linker option
- MIDL linker option
- MIDL, command line options
ms.assetid: 22dc259e-b34c-4ed3-a380-4beb734482c1
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f8e842f4cf0f9c52945c04739879d0132eb34171
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="midl-specify-midl-command-line-options"></a>/MIDL (especificar opções de linha de comando MIDL)
```  
/MIDL:@file  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 `file`  
 O nome do arquivo que contém [opções de linha de comando MIDL](http://msdn.microsoft.com/library/windows/desktop/aa366839).  
  
## <a name="remarks"></a>Comentários  
 Todas as opções para a conversão de um arquivo IDL para um arquivo TLB devem ser fornecidas em `file`; Opções de linha de comando MIDL não podem ser especificadas na linha de comando do vinculador. Se /MIDL não for especificado, o compilador MIDL será invocado com o nome de arquivo IDL e nenhuma outra opção.  
  
 O arquivo deve conter uma opção de linha de comando MIDL por linha.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **IDL inserido** página de propriedades.  
  
4.  Modificar o **comandos de MIDL** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MidlCommandFile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [/IDLOUT (nomear arquivos de saída MIDL)](../../build/reference/idlout-name-midl-output-files.md)   
 [/IGNOREIDL (não processar atributos em MIDL)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)   
 [/TLBOUT (nome. Arquivos TLB)](../../build/reference/tlbout-name-dot-tlb-file.md)   
 [Compilando um programa atribuído](../../windows/building-an-attributed-program.md)