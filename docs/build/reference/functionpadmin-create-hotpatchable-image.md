---
title: -FUNCTIONPADMIN (Criar imagem Hotpatchable) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /functionpadmin
dev_langs: C++
helpviewer_keywords:
- -FUNCTIONPADMIN linker option
- /FUNCTIONPADMIN linker option
ms.assetid: 25b02c13-1add-4fbd-add9-fcb30eb2cae7
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f737cdb412420ffb87664024b2314941e67b045b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="functionpadmin-create-hotpatchable-image"></a>/FUNCTIONPADMIN (Criar imagem hotpatchable)
Prepara uma imagem para patch instantâneo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/FUNCTIONPADMIN[:space]  
```  
  
## <a name="remarks"></a>Comentários  
 onde,  
  
 `space` (opcional)  
 A quantidade de preenchimento para adicionar ao início de cada função, 5, 6 ou 16.  x86 imagens exigem cinco bytes de preenchimento, x64 imagens exigem 6 bytes e imagens criadas para a família de processadores Itanium exigem 16 bytes de preenchimento no início de cada função.  
  
 Por padrão, o compilador adicionará a quantidade correta de espaço para a imagem, com base no tipo de máquina da imagem.  
  
 Em ordem para o vinculador para produzir uma imagem hotpatchable, os arquivos. obj devem foram compilados com [/hotpatch (Criar imagem de Hotpatchable)](../../build/reference/hotpatch-create-hotpatchable-image.md).  
  
 Quando você compilar e vincular uma imagem com uma única chamada de cl.exe, **/hotpatch** implica **/functionpadmin**.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção para o **opções adicionais** caixa.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)