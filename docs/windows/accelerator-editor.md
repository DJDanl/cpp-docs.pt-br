---
title: Editor de aceleradores | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.accelerator.F1
dev_langs: C++
helpviewer_keywords:
- accelerator tables [C++], editing
- tables [Visual Studio], accelerator key
- accelerator keys
- resource editors, Accelerator editor
- keyboard shortcuts [C++], Accelerator editor
- Accelerator editor
ms.assetid: 013c30b6-5d61-4f1c-acef-8bd15bed7060
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e078dbd3dc8d462ef4bca6e6f1056afb9ce8724c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="accelerator-editor"></a>Editor de aceleradores
Uma tabela de Aceleradores é um recurso do Windows que contém uma lista de teclas de aceleração (também conhecido como teclas de atalho) e os identificadores de comando que estão associados eles. Um programa pode ter mais de uma tabela do acelerador.  
  
 Normalmente, os aceleradores são usados como atalhos de teclado para comandos de programa que também estão disponíveis em um menu ou barra de ferramentas. No entanto, você pode usar a tabela de aceleradores para definir as combinações de teclas para comandos que não tem um objeto de interface de usuário associado a eles.  
  
 Você pode usar [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925) para capturar a comandos de tecla de aceleração ao código.  
  
 Com o editor de aceleradores, você pode:  
  
-   [Definir propriedades de acelerador](../windows/setting-accelerator-properties.md)  
  
-   [Associar uma tecla de aceleração um Item de Menu](../windows/associating-an-accelerator-key-with-a-menu-item.md)  
  
-   [Editar tabelas de teclas aceleradoras](../windows/editing-accelerator-tables.md)  
  
-   [Use as teclas de aceleração predefinidas](../windows/predefined-accelerator-keys.md)  
  
    > [!TIP]
    >  Ao usar o editor de aceleradores, clique para exibir um menu de atalho de comandos usados com frequência. Os comandos disponíveis dependem de que o ponteiro está apontando.  
  
    > [!NOTE]
    >  Windows não permite que você crie tabelas de teclas aceleradoras vazio. Se você criar uma tabela de aceleradores sem entradas, ele é excluído automaticamente quando você salvar a tabela.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editores de recursos](../windows/resource-editors.md)

