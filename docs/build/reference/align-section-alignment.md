---
title: "-ALINHAR (alinhamento de seção) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.Alignment
- /align
dev_langs: C++
helpviewer_keywords:
- sections, specifying alignment
- ALIGN linker option
- /ALIGN linker option
- -ALIGN linker option
- section alignment
- sections
ms.assetid: f2f8ac24-e90e-4bea-8205-f2960a3b1740
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e620719d5a69c333a45664fba5967a740224d4d5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="align-section-alignment"></a>/ALIGN (alinhamento da seção)
```  
/ALIGN[:number]  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 `number`  
 O valor de alinhamento.  
  
## <a name="remarks"></a>Comentários  
 A opção /ALIGN Especifica o alinhamento de cada seção dentro do espaço de endereçamento linear do programa. O `number` argumento é em bytes e deve ser uma potência de dois. O padrão é 4 KB (4096). O vinculador emite um aviso se o alinhamento produz uma imagem inválida.  
  
 A menos que você estiver escrevendo um aplicativo como um driver de dispositivo, você não precisará modificar o alinhamento.  
  
 É possível modificar o alinhamento de uma seção específica com o parâmetro Alinhar para o [/seção](../../build/reference/section-specify-section-attributes.md) opção.  
  
 O valor do alinhamento especificado não pode ser menor do que o maior alinhamento de seção.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)