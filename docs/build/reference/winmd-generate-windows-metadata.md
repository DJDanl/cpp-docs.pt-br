---
title: -WINMD (gera metadados do Windows) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: VC.Project.VCLinkerTool.GenerateWindowsMetadata
dev_langs: C++
ms.assetid: bcfb4901-411e-4c9e-9f78-23028b6e5fcc
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 903ab6875457aa8c069c47a2be7f8ff1f5c884a9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="winmd-generate-windows-metadata"></a>/WINMD (Gera metadados do Windows
Habilita a geração de um arquivo de metadados de tempo de execução do Windows (. winmd).  
  
```  
/WINMD[:{NO|ONLY}]  
```  
  
## <a name="remarks"></a>Comentários  
 /WINMD  
 A configuração padrão para [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. O vinculador gere o arquivo executável binário e o arquivo de metadados. winmd.  
  
 /WINMD:NO  
 O vinculador gere o arquivo binário executável, mas não é um arquivo. winmd.  
  
 /WINMD: SOMENTE  
 O vinculador gerará somente o arquivo. winmd, mas não o arquivo executável binário.  
  
 Por padrão, o nome do arquivo de saída tem a forma `binaryname`. winmd. Para especificar um nome de arquivo diferente, use o [/WINMDFILE](../../build/reference/winmdfile-specify-winmd-file.md) opção.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **metadados do Windows** página de propriedades.  
  
4.  No **gerar metadados do Windows** lista suspensa, selecione a opção desejada.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)