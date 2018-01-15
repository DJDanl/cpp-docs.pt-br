---
title: Interfaces (ATL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- COM interfaces
- interfaces, COM
ms.assetid: de6c8b12-6230-4fdc-af66-a28b91d5ee55
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bf1dd68a3ca8e6735b07c5bd7247b457bd7d246d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="interfaces-atl"></a>Interfaces (ATL)
Uma interface é a maneira na qual um objeto expõe sua funcionalidade com o mundo exterior. COM, uma interface é uma tabela de ponteiros (como uma vtable C++) para funções implementadas pelo objeto. A tabela representa a interface e as funções que ele aponta são os métodos da interface. Um objeto pode expor interfaces tantos conforme ele escolhe.  
  
 Cada interface é baseada na interface COM fundamentais, [IUnknown](../atl/iunknown.md). Os métodos de **IUnknown** permitir a navegação para outras interfaces expostas pelo objeto.  
  
 Além disso, cada interface é fornecida uma interface exclusiva IID (ID). Este exclusividade facilita dar suporte a controle de versão de interface. Uma nova versão de uma interface é simplesmente uma nova interface, com um IID de novo.  
  
> [!NOTE]
>  IIDs para as interfaces COM e OLE padrão são predefinidos.  
  
## <a name="see-also"></a>Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [Interfaces e objetos COM](http://msdn.microsoft.com/library/windows/desktop/ms690343)

