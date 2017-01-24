---
title: "Conjunto de registros: adicionando registros em massa (ODBC) | Microsoft Docs"
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
  - "adições de registros em massa a conjuntos de registros"
  - "conjunto de registros ODBC, adicionando registros"
  - "conjuntos de registros, adicionando registros"
ms.assetid: 4685f656-14b9-4f10-a1c5-147b2b89a0b4
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conjunto de registros: adicionando registros em massa (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 A classe de MFC [CRecordset](../Topic/CRecordset%20Class.md) tem uma nova otimização que melhora a eficiência quando você estiver adicionando novos registros em massa em uma tabela.  
  
> [!NOTE]
>  Este tópico se aplica a objetos derivados de `CRecordset` no qual a busca de linhas do volume não foi implementado.  Se você estiver usando a linha em massa que pesquisa, consulte [Conjunto de registros: Buscando registros em massa \(ODBC\)](../Topic/Recordset:%20Fetching%20Records%20in%20Bulk%20\(ODBC\).md).  
  
 Uma nova opção para o parâmetro de **dwOptions** à função de membro de [CRecordset::Open](../Topic/CRecordset::Open.md) , **optimizeBulkAdd**, melhora o desempenho quando você estiver adicionando vários registros consecutivamente sem chamar **Requery** ou **Fechar**.  Apenas os campos que estão incorretos antes da primeira chamada de **Atualizar** está marcado como sujo para `AddNew`subsequente\/**Atualizar** chamam.  
  
 Se você estiver usando as classes de base de dados para se beneficiar da função de API ODBC de **::SQLSetPos** para adicionar, editar, excluir e registros, essa otimização é desnecessária.  
  
 Se a biblioteca de cursores ODBC é carregada ou o driver ODBC não oferece suporte para adicionar, editar, excluir e com **::SQLSetPos**, essa otimização deve melhorar o volume adiciona o desempenho.  Para ativar essa otimização, defina o parâmetro de **dwOptions** na chamada de **Abrir** para o conjunto de registros ao seguinte:  
  
```  
appendOnly | optimizeBulkAdd  
```  
  
## Consulte também  
 [Conjunto de registros \(ODBC\)](../../data/odbc/recordset-odbc.md)   
 [Conjunto de registros: adicionando, atualizando e excluindo registros \(ODBC\)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)   
 [Conjunto de registros: bloqueando registros \(ODBC\)](../../data/odbc/recordset-locking-records-odbc.md)