---
title: -WINMDFILE (Especifica o arquivo winmd) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.GenerateWindowsMetadataFile
dev_langs:
- C++
ms.assetid: 062b41b3-14d6-432c-a361-fdb66e918931
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 153e5c0bd42b6fdba59e309483f25f09b86fe9fa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="winmdfile-specify-winmd-file"></a>/WINMDFILE (Especifica o arquivo winmd)
Especifica o nome de arquivo para o arquivo de saída de metadados de tempo de execução do Windows (. winmd) que é gerado pelo [/WINMD](../../build/reference/winmd-generate-windows-metadata.md) opção de vinculador.  
  
```  
/WINMDFILE:filename  
```  
  
## <a name="remarks"></a>Comentários  
 Use o valor especificado em `filename` para substituir o nome do arquivo. winmd padrão (`binaryname`. winmd). Observe que você não adicionar ". winmd" para `filename`.  Se vários valores são listados no **/WINMDFILE** linha de comando, o último deles terá precedência.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **metadados do Windows** página de propriedades.  
  
4.  No **arquivo de metadados do Windows** , digite o local do arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [/WINMD (gera metadados do Windows)](../../build/reference/winmd-generate-windows-metadata.md)   
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)