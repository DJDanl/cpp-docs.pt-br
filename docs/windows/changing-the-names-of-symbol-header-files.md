---
title: "Alterando os nomes dos arquivos de cabeçalho de símbolo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.editors.symbol.changing.header
dev_langs:
- C++
helpviewer_keywords:
- resource files, multiple
- Resource Includes dialog box
- symbol header files, changing names
- symbol header files
- header files, changing names
- names [C++], symbol header files
- symbols, symbol header files
- Resource.h
ms.assetid: b948284a-7899-402e-ab12-9f2c8480ca9d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8ccc7cc8662e33e5999ceafbcd8f029e2675341b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changing-the-names-of-symbol-header-files"></a>Alterando os nomes de arquivos de cabeçalho de símbolo
Normalmente, todos os símbolos definições são salvas em Resource.h. No entanto, talvez seja necessário alterar essa incluem o nome de arquivo para que você pode, por exemplo, trabalhar com mais de um arquivo de recurso no mesmo diretório.  
  
### <a name="to-change-the-name-of-the-resource-symbol-header-file"></a>Para alterar o nome do arquivo de cabeçalho de símbolo de recurso  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), clique em seu arquivo. RC e escolha [inclui recursos](../windows/resource-includes-dialog-box.md) no menu de atalho.  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **arquivo de cabeçalho de símbolo** , digite o novo nome para o arquivo de inclusão.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.*  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)   
 [IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)