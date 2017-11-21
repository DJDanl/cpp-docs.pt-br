---
title: "-/NXCOMPAT (compatível com prevenção de execução de dados) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /NXCOMPAT
dev_langs: C++
helpviewer_keywords:
- /NXCOMPAT linker option
- -NXCOMPAT linker option
- NXCOMPAT linker option
ms.assetid: 5858e7ff-24d3-4ac3-9046-af2c9e220d9b
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d97b1b84ef6894e4ec161dbcecef47f6b676af23
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="nxcompat-compatible-with-data-execution-prevention"></a>/NXCOMPAT (compatível com Prevenção de Execução de Dados)
Indica que um executável foi testado para ser compatível com o recurso do Windows Data Execution Prevention.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/NXCOMPAT[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, **/NXCOMPAT** está em.  
  
 **/NXCOMPAT: no** pode ser usado para especificar explicitamente um executável como incompatíveis com prevenção de execução de dados.  
  
 Para obter mais informações sobre a prevenção de execução de dados, consulte estes artigos:  
  
-   [Uma descrição detalhada do recurso prevenção de execução de dados (DEP)](http://go.microsoft.com/fwlink/?LinkID=157771) no site do Microsoft Help e suporte  
  
-   [Data Execution Prevention](http://go.microsoft.com/fwlink/?LinkID=157770) no site do MSDN  
  
-   [Prevenção de execução de dados (Windows Embedded)](http://go.microsoft.com/fwlink/?LinkID=157768) no site do MSDN  
  
### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção no **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)