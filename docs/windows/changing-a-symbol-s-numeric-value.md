---
title: Alterando um símbolo&#39;valor numérico de s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.changing.value
dev_langs:
- C++
helpviewer_keywords:
- numeric values
- symbols, numeric values
- numeric values, changing symbols
ms.assetid: 468e903b-9c07-4251-ae09-3b6cb754cc2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ada5ed80a1077dc2fc50494dcf6fcae609b0b0c9
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652426"
---
# <a name="changing-a-symbol39s-numeric-value"></a>Alterando um símbolo&#39;s de valor numérico
Símbolos associados com um único recurso, você pode usar o [janela de propriedades](/visualstudio/ide/reference/properties-window) para alterar o valor do símbolo. Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar o valor de símbolos que não estão atribuídos a um recurso. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).  
  
### <a name="to-change-a-symbol-value-assigned-to-a-single-resource-or-object"></a>Para alterar um valor de símbolo atribuído a um único recurso ou objeto  
  
1.  Na [exibição de recurso](../windows/resource-view-window.md), selecione o recurso.  
  
    > [!NOTE]
    >  Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **propriedades** , digite o nome do símbolo seguido por um sinal de igual e um número inteiro na **ID** caixa, por exemplo:  
  
    ```  
    IDC_EDITNAME=5100  
    ```  
  
 O novo valor é armazenado no arquivo de cabeçalho de símbolo na próxima vez que você salvar o projeto. Somente o nome do símbolo permanece visível na caixa ID. o sinal de igual e o valor não são exibidos depois que eles sejam validados.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, e [passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Restrições de valor de símbolo](../windows/symbol-value-restrictions.md)   
 [IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)