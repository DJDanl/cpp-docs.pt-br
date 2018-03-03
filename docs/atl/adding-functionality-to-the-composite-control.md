---
title: Adicionando funcionalidade para o controle composto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- event handlers [C++], ActiveX controls
- composite controls, handling events
- ActiveX controls [C++], events
ms.assetid: 98f85681-9564-480d-af38-03f9733fe58b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6dcf3ffa0c3168c2f96a3ad9bed13ab1213f63da
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-functionality-to-the-composite-control"></a>Adicionando funcionalidade para o controle composto
Depois de inserir os controles necessários para o controle composto, a próxima etapa envolve a adição de novas funcionalidades. Essa nova funcionalidade geralmente se encaixa em duas categorias:  
  
-   Suporte a interfaces adicionais e personalizar o comportamento do seu controle composto com recursos adicionais específicos.  
  
-   Manipulação de eventos do controle ActiveX independente (ou controles).  
  
 A finalidade e o escopo deste artigo, o restante desta seção se concentra somente na manipulação de eventos de controles ActiveX.  
  
> [!NOTE]
>  Se você precisa lidar com mensagens de controles do Windows, consulte [implementando uma janela](../atl/implementing-a-window.md) para obter mais informações sobre a lidar com mensagens no ATL.  
  
 Depois de inserir um controle ActiveX no recurso de caixa de diálogo, clique com botão direito no controle e clique em **Adicionar manipulador de eventos**. Selecione o evento que você deseja manipular e clique em **adicionar e editar**. O código de manipulador de eventos será adicionado para o arquivo do controle. h.  
  
 Pontos de Conexão para controles ActiveX do controle composto automaticamente estão conectados e desconectados por meio de chamadas para [CComCompositeControl::AdviseSinkMap](../atl/reference/ccomcompositecontrol-class.md#advisesinkmap).  
  
## <a name="see-also"></a>Consulte também  
 [Fundamentos do controle composto](../atl/atl-composite-control-fundamentals.md)

