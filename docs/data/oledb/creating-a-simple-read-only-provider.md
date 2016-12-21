---
title: "Criando um provedor somente leitura simples | Microsoft Docs"
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
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um provedor somente leitura simples
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando você criou um provedor OLE DB que usa o assistente do assistente de projeto de ATL e do provedor OLE DB de ATL, você pode adicionar outra funcionalidade que você deseja dar suporte.  Inicie criar seu provedor por meio do exame do tipo de dados que você estiver enviando ao consumidor e sob quais circunstâncias.  É especialmente importante determinar se você precisa suporte a comandos, transações, e outros objetos opcionais.  Uma implementação e um conjunto de testes antecipadamente da velocidade do bom design.  
  
 O exemplo é apresentado em duas partes:  
  
-   A primeira parte mostra como [crie um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.  
  
-   A segunda parte mostra como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando a interface de `IRowsetLocate` .  
  
## Consulte também  
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)