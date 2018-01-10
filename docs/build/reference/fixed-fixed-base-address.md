---
title: "-FIXO (endereço básico fixo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /fixed
- VC.Project.VCLinkerTool.FixedBaseAddress
dev_langs: C++
helpviewer_keywords:
- preferred base address for loading program
- /FIXED linker option
- -FIXED linker option
- FIXED linker option
ms.assetid: 929bba5e-b7d8-40ed-943e-056aa3710fc5
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 201a0357d182713c473fd3e259e4e9c2a71abf4e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fixed-fixed-base-address"></a>/FIXED (endereço básico fixo)
```  
/FIXED[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Informa o sistema operacional para carregar o programa somente em seu endereço base preferido. Se o endereço base preferencial não estiver disponível, o sistema operacional não carregar o arquivo. Para obter mais informações, consulte [/BASE (Endereço Básico)](../../build/reference/base-base-address.md).  
  
 /Fixed: é a configuração padrão para uma DLL e /FIXED é a configuração padrão para qualquer outro tipo de projeto.  
  
 Quando /FIXED for especificado, o LINK não gera uma seção de realocação no programa. Em tempo de execução, se o sistema operacional não puder carregar o programa no endereço especificado, ele emite uma mensagem de erro e não carrega o programa.  
  
 Especifique /fixed: para gerar uma seção de realocação do programa.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Digite o nome da opção e a configuração no **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)