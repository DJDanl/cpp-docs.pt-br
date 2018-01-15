---
title: "Alterando as propriedades de várias teclas de aceleração | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- keyboard shortcuts [C++], property changing
- accelerator tables [C++], changing properties
ms.assetid: b55c9bd6-b430-48bb-b942-0e6f21d7abf9
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8fbe5ab2202da457c8970d84d304ec97fdedd4a1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changing-the-properties-of-multiple-accelerator-keys"></a>Alterando as propriedades de várias teclas de aceleração
### <a name="to-change-the-properties-of-multiple-accelerator-keys"></a>Para alterar as propriedades de várias teclas de aceleração  
  
1.  Abra a tabela de teclas aceleradoras clicando duas vezes em seu ícone no [exibição recursos](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Selecione as teclas de aceleração que você deseja alterar, mantendo o **CTRL** da chave que você clica em cada um deles.  
  
3.  Vá para o [janela propriedades](/visualstudio/ide/reference/properties-window) e digite os valores que você deseja que todos os aceleradores selecionados para compartilhar.  
  
    > [!NOTE]
    >  Cada valor de modificador aparece como uma propriedade booleana na janela Propriedades. Se você alterar um [modificador](../windows/accelerator-modifier-property.md) valor na janela Propriedades, a tabela de aceleradores trata o modificador new como uma adição a quaisquer modificadores que anteriormente estavam lá. Por isso, se você definir quaisquer valores de modificador, você precisará definir todos eles para garantir que cada Acelerador compartilha as mesmas configurações de modificador.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editando tabelas de aceleradores](../windows/editing-accelerator-tables.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)