---
title: "Usando procedimentos armazenados | Microsoft Docs"
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
  - "modelos de provedor do OLE DB, procedimentos armazenados"
  - "OLE DB, procedimentos armazenados"
  - "procedimentos armazenados, sobre procedimentos armazenados"
  - "procedimentos armazenados, OLE DB"
  - "procedimentos armazenados, Visual C++"
ms.assetid: 90507e4c-eca2-46c9-ad8c-07e10dc1d41b
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando procedimentos armazenados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um procedimento armazenado é um objeto executável armazenado em um base de dados.  Chamar um procedimento armazenado é semelhante a chamar um comando SQL.  Usar procedimentos armazenados na fonte de dados \(em vez de executar ou preparar uma instrução no aplicativo cliente\) pode oferecer várias vantagens, inclusive alto desempenho, menor sobrecarga da rede, e consistência e precisão aprimoradas.  
  
 Um procedimento armazenado pode ter qualquer número \(incluindo zeros\) de parâmetros de entrada ou de saída e pode passar um valor de retorno.  Você pode um dos valores de parâmetro difíceis de código como valores de dados específicos ou para usar um marcador de parâmetro \(um ponto de interrogação “? "\).  
  
> [!NOTE]
>  Os procedimentos armazenados CLR do SQL Server criados usando o Visual C\+\+ deve ser compilados com a opção do compilador de **\/clr:safe** .  
  
 O provedor OLE DB para SQL Server \(SQLOLEDB\) oferece suporte aos seguintes mecanismos que os procedimentos armazenados usam para retornar dados:  
  
-   Cada instrução SELECT no procedimento gerencie um conjunto de resultados.  
  
-   O procedimento pode retornar dados com os parâmetros de saída.  
  
-   O procedimento pode ter um código de retorno de inteiro.  
  
> [!NOTE]
>  Você não pode usar procedimentos armazenados com o provedor OLE DB para Jet porque esse provedor não oferecer suporte aos procedimentos armazenados; somente as constantes são permitidas em cadeias de caracteres da consulta.  
  
## Consulte também  
 [Trabalhando com modelos de consumidor de banco de dados OLE](../../data/oledb/working-with-ole-db-consumer-templates.md)