---
title: -WINMDDELAYSIGN (assina parcialmente um winmd) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.WINMDDelaySign
dev_langs:
- C++
ms.assetid: 445cd602-62cb-400a-8e3a-4beb6572724d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5c50480fae1f4f3e7421236615d059a642d1074f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32375552"
---
# <a name="winmddelaysign-partially-sign-a-winmd"></a>/WINMDDELAYSIGN (Assina parcialmente um winmd)
Habilita a assinatura parcial de um arquivo de metadados de tempo de execução do Windows (. winmd), colocando a chave pública no arquivo.  
  
```  
/WINMDDELAYSIGN[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 É semelhante a [/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md) opção de vinculador que é aplicada ao arquivo. winmd. Use **/WINMDDELAYSIGN** se você deseja colocar somente a chave pública no arquivo. winmd. Por padrão, o vinculador age como se **/winmddelaysign: no** foram especificados; ou seja, ele não assinar o arquivo de winmd.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **metadados do Windows** página de propriedades.  
  
4.  No **sinal de atraso de metadados do Windows** lista suspensa, selecione a opção desejada.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)