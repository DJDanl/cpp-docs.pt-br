---
title: "-/DYNAMICBASE (aleatória de layout do espaço de endereço de uso) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: VC.Project.VCLinkerTool.RandomizedBaseAddress
dev_langs: C++
helpviewer_keywords:
- -DYNAMICBASE linker option
- /DYNAMICBASE linker option
- DYNAMICBASE linker option
ms.assetid: 6c0ced8e-fe9c-4b63-b956-eb8a55fbceb2
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2bce480d906210ebd8eb597902c7f1aac855c6ad
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="dynamicbase-use-address-space-layout-randomization"></a>/DYNAMICBASE (usar aleatorização do layout de espaço do endereço)
Especifica se é para gerar uma imagem executável que pode ser baseada aleatoriamente de novo no tempo de carregamento usando o recurso do aleatória (ASLR) de layout do espaço de endereço de [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/DYNAMICBASE[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, /DYNAMICBASE está ativado.  
  
 Esta opção modifica o cabeçalho de um executável para indicar se o aplicativo deve ser baseada aleatoriamente de novo no tempo de carregamento.  
  
 Aleatorização do espaço de endereço é suportada em [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)].  
  
### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **avançado** página de propriedades.  
  
5.  Modificar o **endereço de Base aleatório** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RandomizedBaseAddress%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)