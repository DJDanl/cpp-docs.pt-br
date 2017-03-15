---
title: "CRowset::Insert | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL.CRowset<TAccessor>.Insert"
  - "CRowset.Insert"
  - "CRowset<TAccessor>.Insert"
  - "CRowset<TAccessor>::Insert"
  - "ATL::CRowset<TAccessor>::Insert"
  - "ATL.CRowset.Insert"
  - "CRowset::Insert"
  - "ATL::CRowset::Insert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método insert"
ms.assetid: 6a64a1c3-10ac-4296-8685-0fd6fe63a13b
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::Insert
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria e inicializa uma nova linha usando dados do acessador.  
  
## Sintaxe  
  
```  
  
      HRESULT Insert(   
   int nAccessor = 0,   
   bool bGetHRow = false    
) throw( );  
```  
  
#### Parâmetros  
 `nAccessor`  
 \[in\] o número de acessador a ser usado para inserir os dados.  
  
 *bGetHRow*  
 \[in\] indica se o identificador para a linha inserida será recuperada.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método exige a interface opcional `IRowsetChange`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetChange** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
 A inserção pode falhar se uma ou mais colunas não são gravável.  Modifique seu mapa de cursor para corrigir isso.  
  
## Exemplo  
 O exemplo a seguir mostra como acessar uma fonte de dados com um conjunto de linhas e insira uma cadeia de caracteres usando uma tabela nesse conjunto de linhas.  
  
 Primeiro, crie uma classe de tabela inserindo um novo objeto de ATL do seu projeto.  Por exemplo, clique com o botão direito do mouse no painel de espaço de trabalho e selecione **New ATL Object**.  Categoria de **Acesso aos Dados** , **Consumidor**selecione.  Crie um objeto do consumidor do tipo **Tabela**. \(Selecionar **Tabela** cria um conjunto de linhas diretamente da tabela; selecione **Comando** cria um conjunto de linhas por um comando SQL.\) Selecione uma fonte de dados, especificando uma tabela a ser usada para acessar a fonte de dados.  Se você chamar seu objeto **CCustomerTable**do consumidor, você implementaria em seu código de inserção como segue:  
  
 [!code-cpp[NVC_OLEDB_Consumer#10](../../data/oledb/codesnippet/CPP/crowset-insert_1.cpp)]  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)