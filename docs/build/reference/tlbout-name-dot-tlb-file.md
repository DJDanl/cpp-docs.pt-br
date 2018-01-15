---
title: -TLBOUT (nome. Arquivos TLB) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.TypeLibraryFile
- /tlbout
dev_langs: C++
helpviewer_keywords:
- tlb files, renaming
- TLBOUT linker option
- /TLBOUT linker option
- .tlb files, renaming
- -TLBOUT linker option
ms.assetid: 0df6d078-2e48-46c9-a1a5-02674d85dce8
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2c898121a4ac29cc05022504ebfe33949b44eca7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tlbout-name-tlb-file"></a>/TLBOUT (nomear arquivo .TLB)
```  
/TLBOUT:[path\]filename  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *path*  
 Uma especificação de caminho absoluto ou relativo para onde o arquivo. tlb deve ser criado.  
  
 *filename*  
 Especifica o nome do arquivo. tlb criado pelo compilador MIDL. Nenhuma extensão de arquivo é considerado; Especifique *filename*. tlb se você quiser que uma extensão. tlb.  
  
## <a name="remarks"></a>Comentários  
 A opção /TLBOUT Especifica o nome e a extensão do arquivo. tlb.  
  
 O compilador MIDL é chamado pelo vinculador do Visual C++ ao vincular projetos com o [módulo](../../windows/module-cpp.md) atributo.  
  
 Se /TLBOUT não for especificado, o arquivo. tlb terá seu nome de [/IDLOUT](../../build/reference/idlout-name-midl-output-files.md) *filename*. Se /IDLOUT não for especificado, o arquivo. tlb será chamado vc70.tlb.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **IDL inserido** página de propriedades.  
  
4.  Modificar o **biblioteca de tipos** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryFile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [/IGNOREIDL (não processar atributos em MIDL)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)   
 [/MIDL (especificar opções de linha de comando MIDL)](../../build/reference/midl-specify-midl-command-line-options.md)   
 [Compilando um programa atribuído](../../windows/building-an-attributed-program.md)