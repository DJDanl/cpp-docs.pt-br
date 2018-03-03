---
title: "-ATRASO (configurações de importação de carga de atraso) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /delay
- VC.Project.VCLinkerTool.DelayNoBind
- VC.Project.VCLinkerTool.SupportUnloadOfDelayLoadedDLL
- VC.Project.VCLinkerTool.DelayUnload
dev_langs:
- C++
helpviewer_keywords:
- delayed loading of DLLs, /DELAY option
- DELAY linker option
- /DELAY linker option
- -DELAY linker option
ms.assetid: 9334b332-cc58-4dae-b10f-a4c75972d50c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2b9fc1746ae6ac33e3b11c9f57cb83c821affd8a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="delay-delay-load-import-settings"></a>/DELAY (configurações da importação de carga com atraso)
```  
/DELAY:UNLOAD  
/DELAY:NOBIND  
```  
  
## <a name="remarks"></a>Comentários  
 Os controles de opção /DELAY [carregamento atrasado](../../build/reference/linker-support-for-delay-loaded-dlls.md) de DLLs:  
  
-   O qualificador UNLOAD pede para a função de ajuda de carregamento atrasado dar suporte ao descarregamento explícito da DLL. A IAT (tabela de endereço de importação) é redefinida como forma original, invalidando ponteiros IAT e fazendo-os serem substituídos.  
  
     Se você não selecionar UNLOAD, qualquer chamada para [FUnloadDelayLoadedDLL](../../build/reference/explicitly-unloading-a-delay-loaded-dll.md) falhará.  
  
-   O qualificador NOBIND pede para o vinculador não incluir uma IAT associável na imagem final. O padrão é criar a IAT associável para DLLs carregadas com atraso. A imagem resultante não pode ser associada estaticamente. (As imagens com IATs associáveis podem ser associadas estaticamente antes da execução.) Consulte [/ASSOCIAR](../../build/reference/bind.md).  
  
     Se a DLL está associada, a função auxiliar tentará usar as informações associadas em vez de chamar [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212.aspx) em cada um dos imports referenciado. Se o carimbo de data/hora ou o endereço preferido não corresponder aos da DLL carregada, a função auxiliar considerará que a IAT associada está desatualizada e continuará como se a IAT associada não existisse.  
  
     NOBIND aumenta a imagem do programa, mas pode agilizar o tempo de carregamento da DLL. Se você jamais teve a intenção associar a DLL, NOBIND evitará a geração da IAT associada.  
  
 Para especificar as DLLs para carga com atraso, use o [/DELAYLOAD](../../build/reference/delayload-delay-load-import.md) opção.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda **propriedades de configuração**, **vinculador**e, em seguida, selecione **avançado**.  
  
3.  Modificar o **DLL carregada do atraso** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.DelayLoadDLLs%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)