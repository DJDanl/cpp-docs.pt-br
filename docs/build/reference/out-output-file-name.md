---
title: -OUT (nome de arquivo de saída) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.OutputFile
- /out
dev_langs:
- C++
helpviewer_keywords:
- output files, name linker option
- -OUT linker option
- OUT linker option
- /OUT C++ linker option
- linker [C++], output files
ms.assetid: 976210a4-e51f-4cfb-af5e-c16344455834
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0fd9ec1b1631104355e076071370f627a36b4037
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32376099"
---
# <a name="out-output-file-name"></a>/OUT (nome do arquivo de saída)
```  
/OUT:filename  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *filename*  
 Um nome de usuário especificado para o arquivo de saída. Ele substitui o nome padrão.  
  
## <a name="remarks"></a>Comentários  
 A opção /OUT sobrescreve o nome padrão e o local do programa que o vinculador cria.  
  
 Por padrão, o vinculador forma o nome de arquivo usando o nome base do arquivo. obj primeiro especificado e a extensão apropriada (.exe ou. dll).  
  
 Essa opção o nome de base padrão para uma biblioteca .mapfile ou importação. Para obter detalhes, consulte [Gerar Mapfile](../../build/reference/map-generate-mapfile.md) (/Map) e [/IMPLIB](../../build/reference/implib-name-import-library.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **geral** página de propriedades.  
  
4.  Modificar o **arquivo de saída** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OutputFile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)