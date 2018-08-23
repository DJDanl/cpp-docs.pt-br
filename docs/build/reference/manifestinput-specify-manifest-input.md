---
title: -MANIFESTINPUT (especificar entrada de manifesto) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
ms.assetid: a0b0c21e-1f9b-4d8c-bb3f-178f57fa7f1b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d1b5ed266f1b8929deee3ffb60a10b18b7604afc
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42571916"
---
# <a name="manifestinput-specify-manifest-input"></a>/MANIFESTINPUT (especificar entrada de manifesto)
Especifica um arquivo de entrada de manifesto para incluir no manifesto inserido na imagem.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/MANIFESTINPUT:filename  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 O arquivo de manifesto para incluir no manifesto inserido.  
  
## <a name="remarks"></a>Comentários  
 O **/MANIFESTINPUT** opção especifica o caminho de um arquivo de entrada para usar para criar o manifesto inserido em uma imagem executável. Se você tiver o manifesto de vários arquivos de entrada, use a opção várias vezes — uma vez para cada arquivo de entrada. Os arquivos de entrada de manifesto são mesclados para criar o manifesto inserido. Essa opção requer o **/MANIFEST: inserir** opção.  
  
 Essa opção não pode ser definida diretamente no Visual Studio. Em vez disso, use o **arquivos de manifesto adicionais** propriedade do projeto para especificar os arquivos de manifesto adicionais para incluir. Para obter mais informações, consulte [entrada e saída, ferramenta de manifesto, propriedades de configuração \<Projectname > caixa de diálogo páginas de propriedades](../../ide/input-and-output-manifest-tool.md).  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)