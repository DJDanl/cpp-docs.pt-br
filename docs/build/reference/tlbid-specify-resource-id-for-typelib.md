---
title: -TLBID (especificar ID de recurso para TypeLib) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /tlbid
- VC.Project.VCLinkerTool.TypeLibraryResourceID
dev_langs:
- C++
helpviewer_keywords:
- tlb files, specifying resource ID
- -TLBID linker option
- .tlb files, specifying resource ID
- /TLBID linker option
- TLBID linker option
- type libraries, specifying resource ID
ms.assetid: 434b28a2-4656-4d52-ac82-8b18bf486fb2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a552edab9f2de646de3b869bf84467924b5db348
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tlbid-specify-resource-id-for-typelib"></a>/TLBID (especificar ID do recurso para TypeLib)
```  
/TLBID:id  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 `id`  
 Um valor especificado pelo usuário para uma biblioteca de tipos criada pelo vinculador. Ela substitui a ID de recurso padrão de 1.  
  
## <a name="remarks"></a>Comentários  
 Ao compilar um programa que usa atributos, o vinculador criará uma biblioteca de tipos. O vinculador atribuirá uma ID de recurso de 1 para a biblioteca de tipos.  
  
 Se esta ID de recurso está em conflito com um dos recursos existentes, você pode especificar outra ID com /TLBID. O intervalo de valores que você pode passar para `id` é de 1 a 65535.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **IDL inserido** página de propriedades.  
  
4.  Modificar o **ID de recurso TypeLib** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TypeLibraryResourceID%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)