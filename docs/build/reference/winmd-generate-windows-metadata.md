---
title: -WINMD (gera metadados do Windows) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.GenerateWindowsMetadata
dev_langs:
- C++
ms.assetid: bcfb4901-411e-4c9e-9f78-23028b6e5fcc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0d3e628713c8228675db3b34e70d670c88152462
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32376173"
---
# <a name="winmd-generate-windows-metadata"></a>/WINMD (Gera metadados do Windows
Habilita a geração de um arquivo de metadados de tempo de execução do Windows (. winmd).  
  
```  
/WINMD[:{NO|ONLY}]  
```  
  
## <a name="remarks"></a>Comentários  
 /WINMD  
 A configuração padrão para aplicativos de plataforma Universal do Windows. O vinculador gere o arquivo executável binário e o arquivo de metadados. winmd.  
  
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