---
title: /APPCONTAINER (aplicativo de UWP/Microsoft Store) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
ms.assetid: 9a432db5-7640-460b-ab18-6f61fa7daf6f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eab6a9bd8ac37dec250739e3554c370726dce9eb
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589571"
---
# <a name="appcontainer-microsoft-store-app"></a>/APPCONTAINER (aplicativo da Microsoft Store)
Especifica se o vinculador cria uma imagem executável que deve ser executada em um contêiner de aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/APPCONTAINER[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, /APPCONTAINER está desativado.  
  
 Essa opção modifica um executável para indicar se o aplicativo deve ser executado no ambiente de isolamento do processo de appcontainer. Especifica /APPCONTAINER para um aplicativo que deve ser executados no appcontainer ambiente — por exemplo, um aplicativo de 8.x plataforma Universal do Windows (UWP) ou Windows Phone. (A opção é definida automaticamente no Visual Studio quando você cria um aplicativo Windows Universal de um modelo.) Para um aplicativo da área de trabalho, especifique /appcontainer: no ou apenas omita a opção.  
  
 A opção de /APPCONTAINER foi introduzida no Windows 8.  
  
### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **linha de comando** página de propriedades.  
  
5.  Na **opções adicionais**, insira `/APPCONTAINER` ou `/APPCONTAINER:NO`.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)