---
title: "Recomendações para escolher entre ATL e MFC | Microsoft Docs"
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
- MFC, ATL support
- ATL, vs. MFC
ms.assetid: 269325bb-11a8-4330-ad2b-a14a2458679e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 079784f1fed84ae073767a4a0b622d3fdbf7384b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recommendations-for-choosing-between-atl-and-mfc"></a>Recomendações para escolher entre ATL e MFC
Ao desenvolver aplicativos e componentes, você pode escolher entre duas abordagens — ATL e MFC (a biblioteca Microsoft Foundation Class).  
  
## <a name="using-atl"></a>Usando a ATL  
 ATL é uma maneira rápida e fácil para criar um componente COM em C++ e manter uma superfície pequena. Use ATL para criar um controle se não precisar de toda a funcionalidade interna que MFC fornece automaticamente.  
  
## <a name="using-mfc"></a>Usando MFC  
 MFC permite que você crie aplicativos completos, controles ActiveX e documentos ativos. Se você já tiver criado um controle com MFC, convém continuar o desenvolvimento em MFC. Ao criar um novo controle, considere o uso de ATL se não precisar de toda a funcionalidade interna do MFC.  
  
## <a name="using-atl-in-an-mfc-project"></a>Usando a ATL em um projeto MFC  
 Você pode adicionar suporte para o uso de ATL em um projeto MFC existente executando um assistente. Para obter detalhes, consulte [adicionar suporte ATL ao seu projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md).  
  
## <a name="see-also"></a>Consulte também  
 [Introdução à ATL](../atl/introduction-to-atl.md)

