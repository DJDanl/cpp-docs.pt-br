---
title: "Criando um provedor de banco de dados OLE | Microsoft Docs"
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
  - "modelos de provedor do OLE DB, criando provedores"
  - "Provedores OLE DB, criando"
ms.assetid: f73017c3-c89f-41a6-a306-ea992cf6092c
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um provedor de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A maneira recomendada de criar um provedor OLE DB é usar os assistentes para criar um projeto de ATL COM e um provedor e modificar os arquivos usando os modelos OLE DB.  Como você personaliza o provedor, você pode comentar propriedades não desejadas e adicionar interfaces opcionais.  
  
 As etapas básicas são as seguintes:  
  
1.  Use o assistente de projeto de ATL para criar os arquivos de projeto básicos e o assistente do provedor OLE DB de ATL para criar o provedor \( **ATL OLE DB Provider** a partir da pasta do Visual C\+\+ em **Adicionar Classe**\).  
  
2.  Modifique o código no método de `Execute` em CMyProviderRS.h.  Para obter um exemplo, consulte [Cadeias de caracteres de leitura em um provedor OLE DB](../Topic/Reading%20Strings%20into%20the%20OLE%20DB%20Provider.md).  
  
3.  Editar os mapas da propriedade em MyProviderDS.h, em MyProviderSess.h e, em MyProviderRS.h.  O assistente cria os mapas da propriedade que contém todas as propriedades que um provedor pode implementar.  Examine os mapas de propriedade e remover ou comente das propriedades que seu provedor não precisa dar suporte.  
  
4.  Atualizar o PROVIDER\_COLUMN\_MAP, que pode ser encontrado em MyProviderRS.h.  Para obter um exemplo, consulte [Armazenando cadeias de caracteres do provedor OLE DB](../../data/oledb/storing-strings-in-the-ole-db-provider.md).  
  
5.  Quando você estiver pronto para testar o provedor, você pode testar tentando localizar o provedor em uma enumeração do provedor.  Para obter exemplos de código de teste que localiza um provedor em uma enumeração, consulte os exemplos de [CATDB](http://msdn.microsoft.com/pt-br/003d516b-2bf6-444e-8be5-4ebaa0b66046) e de [DBVIEWER](http://msdn.microsoft.com/pt-br/07620f99-c347-4d09-9ebc-2459e8049832) ou o exemplo em [Implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md).  
  
6.  Adicionar todas as interfaces que você deseja adicionais.  Para obter um exemplo, consulte [Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).  
  
    > [!NOTE]
    >  Por padrão, os assistentes para gerenciar o código que é o nível 0 OLE DB correspondente.  Para assegurar que seu aplicativo permaneça o nível compatível com o 0, não remova qualquer uma das interfaces script gerado de código.  
  
## Consulte também  
 [CATDB](http://msdn.microsoft.com/pt-br/003d516b-2bf6-444e-8be5-4ebaa0b66046)   
 [DBVIEWER](http://msdn.microsoft.com/pt-br/07620f99-c347-4d09-9ebc-2459e8049832)