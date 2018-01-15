---
title: -MANIFESTINPUT (especificar entrada de manifesto) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: a0b0c21e-1f9b-4d8c-bb3f-178f57fa7f1b
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e1eec78675845e3f738bb0b6b440b3a71f1fd572
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="manifestinput-specify-manifest-input"></a>/MANIFESTINPUT (especificar entrada de manifesto)
Especifica um arquivo de manifesto de entrada para incluir no manifesto do que é inserido na imagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/MANIFESTINPUT:filename  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 O arquivo de manifesto para incluir no manifesto inserido.  
  
## <a name="remarks"></a>Comentários  
 O **/MANIFESTINPUT** opção especifica o caminho de um arquivo de entrada a ser usado para criar o manifesto inserido em uma imagem executável. Se você tiver o manifesto de vários arquivos de entrada, use a opção várias vezes, uma vez para cada arquivo de entrada. Os arquivos de manifesto de entrada são mesclados para criar o manifesto inserido. Essa opção requer o **/manifesto: inserir** opção.  
  
 Essa opção não pode ser definida diretamente em [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)]. Em vez disso, use o **arquivos de manifesto adicionais** propriedade do projeto para especificar os arquivos de manifesto adicionais para incluir. Para obter mais informações, consulte [entrada e saída, a ferramenta de manifesto, propriedades de configuração, \<Projectname > caixa de diálogo de páginas de propriedade](../../ide/input-and-output-manifest-tool.md).  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)