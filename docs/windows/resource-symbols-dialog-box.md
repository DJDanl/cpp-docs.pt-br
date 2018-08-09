---
title: Caixa de diálogo de símbolos de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.resourcesymbols
dev_langs:
- C++
helpviewer_keywords:
- New Symbol dialog box
- Resource Symbols dialog box
- Change Symbol dialog box
ms.assetid: 9706cde3-1f48-4fcd-bedb-2b03b455e3c1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2bbd7a6048e47f1f2958a438c79b828f5aca5b66
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40020008"
---
# <a name="resource-symbols-dialog-box"></a>Caixa de diálogo Símbolos do Recurso
O **símbolos de recurso** caixa de diálogo permite que você adicione novos símbolos de recurso, altere os símbolos que são exibidos, ou pular para o local no código-fonte em que um símbolo está em uso.  
  
 **Nome**  
 Exibe o nome do símbolo. Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md).  
  
 **Value**  
 Exibe o valor numérico do símbolo. Para obter mais informações, consulte [restrições de valor de símbolo](../windows/symbol-value-restrictions.md).  
  
 **Em uso**  
 Quando selecionado, especifica que o símbolo está sendo usado por um ou mais recursos. Um ou mais recursos são listados na usado pela caixa.  
  
 **Mostrar símbolos somente leitura**  
 Quando selecionado, exibe recursos somente leitura. Por padrão, o **símbolo de recurso** caixa de diálogo exibe somente os recursos pode ser modificados no arquivo de script de recurso, mas com essa opção selecionada, os recursos modificáveis aparecem em negrito e os recursos de somente leitura são exibidos em texto sem formatação.  
  
 **Usado por**  
 Exibe um ou mais recursos usando o símbolo selecionado na lista de símbolos. Para mover para o editor para um determinado recurso, selecione o recurso nas **usado por** caixa e clique em **Exibir uso**. Para obter mais informações, consulte [abrindo o Editor de recursos para um símbolo dado](../windows/opening-the-resource-editor-for-a-given-symbol.md).  
  
 **Novo**  
 Abre o **novo símbolo** caixa de diálogo que permite que você defina o nome e, se necessário, um valor para um novo identificador simbólico do recurso. Para obter mais informações, consulte [criando novos símbolos](../windows/creating-new-symbols.md).  
  
 **Alteração**  
 Abre o **alterar símbolo** caixa de diálogo que permite que você altere o nome ou o valor de um símbolo. Se o símbolo for para um controle ou recurso em uso, o símbolo pode ser alterado somente de editor de recursos correspondente. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).  
  
 **Exibir uso**  
 Abre o recurso que contém o símbolo no editor de recurso correspondente. Para obter mais informações, consulte [abrindo o Editor de recursos para um símbolo dado](../windows/opening-the-resource-editor-for-a-given-symbol.md).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)