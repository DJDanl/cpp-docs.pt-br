---
title: Alterando os nomes dos arquivos de cabeçalho de símbolo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 953ac59958748bd58fa7e9027c595bf7905e5f27
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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