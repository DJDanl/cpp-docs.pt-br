---
title: -APPCONTAINER (aplicativo da Windows Store) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 9a432db5-7640-460b-ab18-6f61fa7daf6f
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 34a1c480e63b5e514e1184d5d3220176b9ba6932
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="appcontainer-windows-store-app"></a>/APPCONTAINER (aplicativo da Windows Store)
Especifica se o vinculador cria uma imagem executável que deve ser executada em um contêiner do aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/APPCONTAINER[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, /APPCONTAINER está desativado.  
  
 Esta opção modifica um executável para indicar se o aplicativo deve ser executado no ambiente de isolamento do processo de appcontainer. Especifique /APPCONTAINER para um aplicativo que deve ser executado no ambiente de appcontainer — por exemplo, um [!INCLUDE[win8_appstore_long](../../build/reference/includes/win8_appstore_long_md.md)] aplicativo. (A opção é definida automaticamente no Visual Studio quando você cria um [!INCLUDE[win8_appstore_long](../../build/reference/includes/win8_appstore_long_md.md)] aplicativo a partir de um modelo.) Para um aplicativo de área de trabalho, especifique /APPCONTAINER:NO ou apenas omitir a opção.  
  
 A opção /APPCONTAINER foi introduzida no [!INCLUDE[win8](../../build/reference/includes/win8_md.md)].  
  
### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **linha de comando** página de propriedades.  
  
5.  Em **opções adicionais**, digite `/APPCONTAINER` ou `/APPCONTAINER:NO`.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)