---
title: "O que a automação remota fornece? | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: Remote Automation, DCOM
ms.assetid: 269ad218-e164-40ef-9b87-25fcc8ba21de
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a4a82b26a1e6c208a584dfd19ebfd4530b4bdf76
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="what-does-remote-automation-provide"></a>O que a automação remota fornece?
Automação remota permite que os programas invocar `IDispatch` implementações em um computador de outro. Ele também dá suporte a outras interfaces necessários para automação, especificamente **IEnumVARIANT** para suporte de coleção. Ele não fornece a capacidade para distribuir qualquer outra interface COM (exceto **IUnknown**, é claro) e, automação regular, ele contém suporte apenas para esses tipos de dados com suporte de automação de empacotamento.  
  
 Este conjunto de recursos permite que um programa acessar os métodos e propriedades, incluindo aqueles que retornam coleções ou mais objetos de automação, de um objeto em execução em um nó de rede acessível. Se o computador cliente também está executando o software apropriado, é possível para o servidor de retorno de chamada para o cliente novamente usando os recursos de automação (isso funciona para clientes de 32 bits e 64 bits somente e é conceitualmente semelhante a eventos, embora ele não usar o mesmo mecanismo).  
  
 Para um aplicativo ser funcionando como um servidor de automação remota, ele deve ser implementado como um executável (ou seja, como um "servidor local" em vez de um "servidor inproc").  
  
## <a name="see-also"></a>Consulte também  
 [Onde entra a automação remota](where-does-remote-automation-fit-in-q.md)   
 [Histórico de DCOM](../mfc/history-of-dcom.md)
