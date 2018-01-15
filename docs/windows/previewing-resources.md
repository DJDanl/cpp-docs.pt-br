---
title: "Recursos de visualização | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.resvw.resource.previewing
- vs.resvw.resource.previewing
dev_langs: C++
helpviewer_keywords:
- resources [Visual Studio], viewing
- resource previews
- code, viewing
ms.assetid: d6abda66-0e2b-4ac3-a59a-a57b8c6fb70b
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0eca56e607c916e28afc7bf513d853bcf6d94b81
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="previewing-resources"></a>Visualizando recursos
Visualizar seus recursos permite que você exibir recursos gráficos sem abri-los. Visualizando também é útil para executáveis depois que você tenha compilado-los porque os identificadores de recurso Alterar para números. Como esses identificadores numéricos geralmente não fornecem informações suficientes, visualizar os recursos ajuda a identificá-los rapidamente.  
  
 Você pode visualizar o layout visual dos seguintes tipos de recurso:  
  
-   Bitmap  
  
-   Caixa de diálogo  
  
-   Ícone  
  
-   Menu  
  
-   Cursor  
  
-   Barra de ferramentas  
  
 A função de visualização não se aplica a recursos de aceleração, manifesto, tabela de cadeia de caracteres e informações de versão.  
  
### <a name="to-preview-resources"></a>Para visualizar recursos  
  
1.  Em [exibição recursos](../windows/resource-view-window.md) ou em uma janela de documento, selecione o recurso, por exemplo, IDD_ABOUTBOX.  
  
     **Observação** se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), clique no **páginas de propriedade** botão.  
  
     \- ou -  
  
3.  Sobre o **exibição** menu, clique em **páginas de propriedade**.  
  
     A página de propriedades para o recurso é aberto, exibindo uma visualização do recurso. Você pode, em seguida, use a cima e para as teclas de direção para navegar o controle de árvore na exibição de recursos ou a janela do documento. A página de propriedades serão permaneça aberta e mostrar qualquer recurso que tem o foco e é capaz de ser visualizado.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Como: abrir um arquivo de Script de recurso fora de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)   
 [Editores de recursos](../windows/resource-editors.md)

