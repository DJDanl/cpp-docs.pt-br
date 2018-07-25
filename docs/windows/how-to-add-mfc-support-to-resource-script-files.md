---
title: 'Como: adicionar suporte MFC para arquivos de Script de recurso | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.resvw.add.MFC
dev_langs:
- C++
helpviewer_keywords:
- rc files, adding MFC support
- .rc files, adding MFC support
- MFC, adding support to resource scripts files
- resource script files, adding MFC support
ms.assetid: 599dfe9d-ad26-4e34-899c-49b56599e37f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 50c0493e630c2b141da1fced6964ffc514c761d4
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33879790"
---
# <a name="how-to-add-mfc-support-to-resource-script-files"></a>Como adicionar suporte MFC a arquivos de script de recurso
Normalmente, quando você cria um aplicativo do MFC para Windows usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), o assistente gera um conjunto básico de arquivos (incluindo um arquivo de script (. rc) de recurso) que contém os principais recursos do Microsoft Foundation classes (MFC). No entanto, se você estiver editando um arquivo. RC para um aplicativo do Windows que não seja baseado em MFC, os seguintes recursos específicos para a estrutura do MFC não estão disponíveis:  
  
-   Assistentes de código MFC (anteriormente chamado de "[ClassWizard MFC](http://msdn.microsoft.com/en-us/98dc2434-ba93-4e0b-b084-1a4bc26cdf1e)")  
  
-   Cadeias de caracteres de prompt do menu  
  
-   Listar conteúdo de controles de caixa de combinação  
  
-   Hospedagem de controles ActiveX  
  
 No entanto, você pode adicionar suporte MFC a arquivos. rc existentes que não possuem.  
  
### <a name="to-add-mfc-support-to-rc-files"></a>Para adicionar suporte MFC a arquivos. rc  
  
1.  Abra o arquivo de script de recurso.  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Em [exibição recursos](../windows/resource-view-window.md), realce a pasta de recursos (por exemplo, MFC.rc).  
  
3.  No [janela propriedades](/visualstudio/ide/reference/properties-window), defina o **modo MFC** propriedade **True**.  
  
    > [!NOTE]
    >  Além de definir esse sinalizador, o arquivo. rc deve fazer parte de um projeto MFC. Por exemplo, apenas configurando **modo MFC** para **True** em um arquivo. rc Win32 projeto não oferece os recursos do MFC.  
  

  
 **Requisitos**  
  
 MFC  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)