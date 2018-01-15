---
title: -NATVIS (Adicionar Natvis ao PDB) | Microsoft Docs
ms.date: 08/10/2017
ms.tgt_pltfrm: 
ms.technology: cpp-tools
ms.topic: article
f1_keywords:
- /natvis
- VC.Project.VCLinkerTool.ImportLIbrary
dev_langs: C++
helpviewer_keywords:
- NATVIS linker option
- /NATVIS linker option
- -NATVIS linker option
- Add Natvis file to PDB
ms.assetid: 8747fc0c-701a-4796-bb4d-818ab4465cca
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 20715b48413a705aa2338e7e37538171e4141cad
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="natvis-add-natvis-to-pdb"></a>/ NATVIS (Adicionar Natvis ao PDB)
  
> / NATVIS:*filename*  
  
## <a name="parameters"></a>Parâmetros  
  
*filename*  
Um arquivo Natvis para adicionar o arquivo PDB. Ele incorpora as visualizações do depurador no arquivo Natvis PDB.  
  
## <a name="remarks"></a>Comentários  
  
A opção /NATVIS incorpora as visualizações do depurador definidas no arquivo Natvis *filename* no arquivo PDB gerado pelo LINK. Isso permite que o depurador exibir as visualizações independentemente do arquivo. natvis. Você pode usar várias opções de /NATVIS para inserir mais de um arquivo Natvis no arquivo PDB gerado.  
  
LINK ignora /NATVIS quando um arquivo PDB não é criado usando um [/Debug](../../build/reference/debug-generate-debug-info.md) opção. Para obter informações sobre criação e uso de arquivos. natvis, consulte [criar exibições personalizadas de objetos nativos no depurador do Visual Studio](/visualstudio/debugger/create-custom-views-of-native-objects).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **linha de comando** página de propriedades no **vinculador** pasta.  
  
3.  Adicione a opção /NATVIS para o **opções adicionais** caixa de texto.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Essa opção não tem um equivalente programático.  
  
## <a name="see-also"></a>Consulte também  
  
[Criar exibições personalizadas de objetos nativos no depurador do Visual Studio](/visualstudio/debugger/create-custom-views-of-native-objects)  
[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)  
[Opções do vinculador](../../build/reference/linker-options.md)