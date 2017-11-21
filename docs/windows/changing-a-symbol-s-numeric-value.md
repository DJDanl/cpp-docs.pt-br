---
title: "Um símbolo &#39; ao alterar o valor numérico de s | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.symbol.changing.value
dev_langs: C++
helpviewer_keywords:
- numeric values
- symbols, numeric values
- numeric values, changing symbols
ms.assetid: 468e903b-9c07-4251-ae09-3b6cb754cc2b
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 97a6def651826ae71cecf33f751f8c0858c691dd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="changing-a-symbol39s-numeric-value"></a>Alterando um símbolo &#39; s numérico valor
Para símbolos associados a um único recurso, você pode usar o [janela propriedades](/visualstudio/ide/reference/properties-window) para alterar o valor do símbolo. Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar o valor de símbolos não atualmente atribuído a um recurso. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).  
  
### <a name="to-change-a-symbol-value-assigned-to-a-single-resource-or-object"></a>Para alterar um valor de símbolo atribuído a um recurso único ou um objeto  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), selecione o recurso.  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **propriedades** , digite o nome do símbolo seguido por um sinal de igual e um número inteiro no **ID** caixa, por exemplo:  
  
    ```  
    IDC_EDITNAME=5100  
    ```  
  
 O novo valor é armazenado no arquivo de cabeçalho de símbolo na próxima vez que você salvar o projeto. Somente o nome do símbolo permanece visível na caixa ID. o sinal de igual e o valor não são exibidos depois que eles são validados.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acesso a recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, e [passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Restrições de valor do símbolo](../windows/symbol-value-restrictions.md)   
 [IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)