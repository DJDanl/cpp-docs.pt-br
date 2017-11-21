---
title: "-IDLOUT (nomear arquivos de saída MIDL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /idlout
- VC.Project.VCLinkerTool.MergedIDLBaseFileName
dev_langs: C++
helpviewer_keywords:
- MIDL, output file names
- .idl files, path
- MIDL
- /IDLOUT linker option
- IDL files, path
- -IDLOUT linker option
- IDLOUT linker option
ms.assetid: 10d00a6a-85b4-4de1-8732-e422c6931509
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 83fdc3ce9436a4e3659074236985e101f8836069
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="idlout-name-midl-output-files"></a>/IDLOUT (nomear arquivos de saída MIDL)
```  
/IDLOUT:[path\]filename  
```  
  
## <a name="parameters"></a>Parâmetros  
 *path*  
 Uma especificação de caminho absoluto ou relativo. Especificando um caminho, você afeta somente o local de um arquivo. idl. todos os outros arquivos são colocados no diretório do projeto.  
  
 *filename*  
 Especifica o nome do arquivo. idl criado pelo compilador MIDL. Nenhuma extensão de arquivo é considerado; Especifique *filename*. idl se você quiser que uma extensão. idl.  
  
## <a name="remarks"></a>Comentários  
 A opção /IDLOUT Especifica o nome e a extensão do arquivo. idl.  
  
 O compilador MIDL é chamado pelo vinculador do Visual C++ ao vincular projetos com o [módulo](../../windows/module-cpp.md) atributo.  
  
 /IDLOUT também especifica os nomes de arquivo de outros arquivos de saída associados com o compilador MIDL:  
  
-   *nome do arquivo*. tlb  
  
-   *nome de arquivo*_p.c  
  
-   *nome de arquivo*_i.c  
  
-   *nome do arquivo*. h  
  
 *nome de arquivo* é o parâmetro que você passa para /IDLOUT. Se [/TLBOUT](../../build/reference/tlbout-name-dot-tlb-file.md) for especificado, o arquivo. tlb obterá seu nome de /TLBOUT *filename*.  
  
 Se você não especificar /IDLOUT ou /TLBOUT, o vinculador cria vc70.tlb, vc70.idl, vc70_p.c, vc70_i.c e vc70.h.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **IDL inserido** página de propriedades.  
  
4.  Modificar o **mesclar nome do arquivo Base IDL** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MergedIDLBaseFileName%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [/IGNOREIDL (não processar atributos em MIDL)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)   
 [/MIDL (especificar opções de linha de comando MIDL)](../../build/reference/midl-specify-midl-command-line-options.md)   
 [Compilando um programa atribuído](../../windows/building-an-attributed-program.md)