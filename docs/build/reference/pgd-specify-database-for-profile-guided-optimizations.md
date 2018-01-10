---
title: "-PGD (especificar o banco de dados para otimizações guiadas por perfil) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: VC.Project.VCLinkerTool.ProfileGuidedDatabase
dev_langs: C++
helpviewer_keywords:
- -PGD linker option
- /PGD linker option
ms.assetid: 9f312498-493b-461f-886f-92652257e443
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cb61395d9f3b8c98e17e3683a7c3897b9315d78b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pgd-specify-database-for-profile-guided-optimizations"></a>/PGD (especificar banco de dados para otimizações orientadas por perfil)
/ PGD:`filename`  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 `filename`  
 Especifica o nome do arquivo. PGD que será usado para armazenar informações sobre o programa em execução.  
  
## <a name="remarks"></a>Comentários  
 Ao usar [/LTCG:PGINSTRUMENT](../../build/reference/ltcg-link-time-code-generation.md), use /PGD para especificar um nome não padrão ou local para o arquivo. PGD. Se você não especificar /PGD, o nome do arquivo. PGD será o mesmo que o nome (.exe ou. dll) do arquivo de saída e será criado no mesmo diretório do qual o link foi invocado.  
  
 Ao usar /LTCG:PGOPTIMIZE, use /PGD para especificar o nome do arquivo. PGD para usar para criar a imagem otimizada.  
  
 Para obter mais informações, consulte [Otimização Guiada por perfil](../../build/reference/profile-guided-optimizations.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **otimização** página de propriedades.  
  
5.  Modificar o **banco de dados do perfil interativa** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ProfileGuidedDatabase%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)