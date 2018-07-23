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
ms.openlocfilehash: 486d4c6c89a43c9d91c655911fa7fee8a31ebd32
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33880186"
---
# <a name="resource-symbols-dialog-box"></a>Caixa de diálogo Símbolos do Recurso
O **símbolos de recurso** caixa de diálogo permite que você adicionar novos símbolos de recurso, altere os símbolos que são exibidos ou vá para o local no código-fonte em que um símbolo está em uso.  
  
 **Nome**  
 Exibe o nome do símbolo. Para obter mais informações, consulte [restrições de nome de símbolo](../windows/symbol-name-restrictions.md).  
  
 **Value**  
 Exibe o valor numérico do símbolo. Para obter mais informações, consulte [restrições de valor do símbolo](../windows/symbol-value-restrictions.md).  
  
 **Em uso**  
 Quando selecionado, especifica que o símbolo está sendo usado por um ou mais recursos. Um ou mais recursos são listados na usado pela caixa.  
  
 **Mostrar símbolos somente leitura**  
 Quando selecionada, exibe os recursos somente leitura. Por padrão, a caixa de diálogo de símbolo de recurso exibe somente os recursos pode ser modificados no arquivo de script de recurso, mas com esta opção selecionada, recursos modificáveis aparecem em negrito e recursos somente leitura são exibidos em texto sem formatação.  
  
 **Usado por**  
 Exibe um ou mais recursos usando o símbolo selecionado na lista de símbolos. Para mover para o editor para um determinado recurso, selecione o recurso de **usado por** caixa e clique em **Exibir uso**. Para obter mais informações, consulte [abrir o Editor de recurso para um símbolo dado](../windows/opening-the-resource-editor-for-a-given-symbol.md).  
  
 **Novo**  
 Abre a caixa de diálogo Novo símbolo, que permite que você defina o nome e, se necessário, um valor para um novo identificador de recurso simbólico. Para obter mais informações, consulte [criando novos símbolos](../windows/creating-new-symbols.md).  
  
 **Alteração**  
 Abre a caixa de diálogo Alterar símbolo, que permite que você altere o nome ou o valor de um símbolo. Se o símbolo for um controle ou recursos em uso, o símbolo pode ser alterado somente do editor de recurso correspondente. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).  
  
 **Exibir uso**  
 Abre o recurso que contém o símbolo no editor de recurso correspondente. Para obter mais informações, consulte [abrir o Editor de recurso para um símbolo dado](../windows/opening-the-resource-editor-for-a-given-symbol.md).  
  

  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)