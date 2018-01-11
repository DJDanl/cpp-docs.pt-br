---
title: "Adicionar caixa de diálogo recurso | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.insertresource
dev_langs: C++
helpviewer_keywords:
- resources [Visual Studio], adding
- Add Resource dialog box
ms.assetid: e9fb6967-738f-47e8-ab58-728cf35b3af0
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fde90f5d7c7822155e36b77c74cd80cdf56b10d2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="add-resource-dialog-box"></a>Caixa de diálogo Adicionar Recurso
Use essa caixa de diálogo para adicionar recursos a um projeto de aplicativo da área de trabalho do Windows do C++.  
  
> [!NOTE]
>  Essas informações não se aplica a recursos em aplicativos da Windows Store. Para obter mais informações sobre isso, consulte [definindo recursos do aplicativo](http://msdn.microsoft.com/en-us/476ea844-632c-4467-9ce3-966be1350dd4).  
  
 **Tipo de recurso**  
 Especifica o tipo de recurso que você deseja criar.  
  
 Você pode expandir as categorias de recurso de caixa de cursor e caixa de diálogo para revelar os recursos adicionais. Esses recursos estão localizados em ...\Microsoft Visual Studio `version`\VC\VCResourceTemplates\\< LCID\>\mfc.rct. Se você adicionar arquivos. rct, você deve colocá-los neste diretório ou você deve especificar um [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md) para eles. Os recursos nesses arquivos, em seguida, são exibidos no nível da segunda sob a categoria apropriada. Não há nenhum limite predefinido para o número de arquivos. rct que você pode adicionar.  
  
 Os recursos mostrados no nível superior no controle de árvore são os recursos padrão que são fornecidos pelo Visual Studio.  
  
 **Novo**  
 Cria um recurso com base no tipo que você selecionou o **tipo de recurso** caixa. O recurso é aberto no editor apropriado. Por exemplo, se você criar um recurso de caixa de diálogo, ele abrirá no [editor de caixa de diálogo](../windows/dialog-editor.md).  
  
 **Importarar**  
 Abre o **importar** caixa de diálogo na qual você pode navegar para um recurso deseja importar para o projeto atual. Você pode importar um bitmap, o ícone, o cursor, o arquivo de recurso HTML, som (. Arquivo de recurso WAV) ou arquivo de recurso personalizado.  
  
 **Personalizado**  
 Abre o [caixa de diálogo novo recurso personalizado](../windows/new-custom-resource-dialog-box.md) no qual você pode criar um recurso personalizado. Recursos personalizados podem ser editados no editor binário.  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Como criar um recurso](../windows/how-to-create-a-resource.md)