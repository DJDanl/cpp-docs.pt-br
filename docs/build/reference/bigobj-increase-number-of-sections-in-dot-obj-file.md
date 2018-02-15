---
title: "-bigobj (aumentar o número de seções. Arquivo obj) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /bigobj
dev_langs:
- C++
helpviewer_keywords:
- -bigobj compiler option [C++]
- /bigobj compiler option [C++]
- bigobj compiler option [C++]
ms.assetid: ba94d602-4015-4a8d-86ec-49241ab74c12
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 178206536522630616bfae0506bfa3edec98068c
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="bigobj-increase-number-of-sections-in-obj-file"></a>/bigobj (aumentar número de seções no arquivo .Obj)
**/bigobj** aumenta o número de seções que pode conter um arquivo de objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/bigobj  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, um arquivo de objeto pode conter até 65.536 (2 ^ 16) seções endereçável. Esse é o caso, não importando qual plataforma de destino é especificada. **/bigobj** aumenta a capacidade desse endereço 4.294.967.296 (2 ^ 32).  
  
 A maioria dos módulos nunca irá gerar um arquivo. obj que contém mais de 65.536 seções. No entanto, código gerado por máquina ou código que faz uso intenso de bibliotecas de modelos pode exigir arquivos. obj que podem conter mais seções. **/bigobj** é habilitado por padrão em projetos do Windows UWP (plataforma Universal) porque o código XAML geradas por computador inclui um grande número de cabeçalhos. Se você desabilitar essa opção em um projeto de aplicativo UWP será provável que encontre um erro do compilador C1128.  
  
 Vinculadores fornecido antes do Visual C++ 2005 não é possível ler os arquivos. obj produzidas com **/bigobj**.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)