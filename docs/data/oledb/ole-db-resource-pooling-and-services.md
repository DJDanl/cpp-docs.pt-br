---
title: "Pooling de recursos e servi&#231;os de banco de dados OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Provedores OLE DB, sondagem de recursos"
  - "Serviços OLE DB [OLE DB]"
  - "Serviços OLE DB [OLE DB], requisitos de provedor"
  - "OLE DB, sondagem de recursos"
  - "sondagem de recursos [OLE DB], requisitos de provedor"
  - "provedores de serviço [OLE DB]"
ms.assetid: 360c36e2-25ae-4caf-8ee7-d4a6b6898f68
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Pooling de recursos e servi&#231;os de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para funcionar bem com OLE DB que clusters, ou com qualquer serviço do OLE DB, o provedor deve oferecer suporte à agregação de todos os objetos.  Este é um requisito do OLE DB 1,5 ou um provedor posterior.  É crítica para aproveitar serviços.  Os provedores que não dão suporte à agregação não podem ser agrupados e nenhum serviço adicional são fornecidos.  
  
 Para serem clusterizados, os provedores devem oferecer suporte ao modelo livre de thread.  O pool de recursos determina o modelo de thread do provedor de acordo com a propriedade de **DBPROP\_THREADMODEL** .  
  
 Se o provedor tiver um estado global de conexão que possa mudar quando a fonte de dados está em um estado inicializado, deverá dar suporte à nova propriedade de **DBPROP\_RESETDATASOURCE** .  Esta propriedade é chamado antes de uma conexão for reutilizada e fornece ao provedor a oportunidade de limpar o estado antes de seu uso seguir.  Se o provedor não poderá limpar qualquer estado associado à conexão, pode retornar **DBPROPSTATUS\_NOTSETTABLE** da propriedade e a conexão não será reutilizadas.  
  
 Os provedores que se conectam a um base de dados remoto e podem detectar se essa conexão poderá ser perdida devem oferecer suporte à propriedade de **DBPROP\_CONNECTIONSTATUS** .  Esta propriedade fornece aos serviços de OLE DB a capacidade de detectar conexões inoperantes e para ter certeza de que os não são retornados ao pool.  
  
 Finalmente, a inscrição automática da transação geralmente não funcionará a menos que seja implementada no mesmo nível de clustering ocorre.  Os provedores que dão suporte à inscrição automática próprios de transação devem oferecer suporte ao desabilitar essa assinatura expõe a propriedade de **DBPROP\_INIT\_OLEDBSERVICES** e desabilitando a assinatura se **DBPROPVAL\_OS\_TXNENLISTMENT** será anulado a seleção.  
  
## Consulte também  
 [Técnicas de provedor avançadas](../Topic/Advanced%20Provider%20Techniques.md)