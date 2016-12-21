---
title: "Classe CCommand | Microsoft Docs"
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
  - "ATL::CCommand"
  - "CCommand"
  - "ATL.CCommand"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CCommand"
ms.assetid: 0760bfc5-b9ee-4aee-8e54-31bd78714d3a
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CCommand
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece métodos para definir e executar um comando.  
  
## Sintaxe  
  
```  
template <  
   class TAccessor = CNoAccessor,  
   template < typename T > class TRowset = CRowset,  
   class TMultiple = CNoMultipleResults   
>  
class CCommand :   
   public CAccessorRowset <  
      TAccessor,   
      TRowset   
   >,  
   public CCommandBase,  
   public TMultiple  
```  
  
#### Parâmetros  
 `TAccessor`  
 O tipo de classe do acessador \(como `CDynamicParameterAccessor`, `CDynamicStringAccessor`, ou `CEnumeratorAccessor`\) que você deseja usar o comando.  A opção é `CNoAccessor`, que especifica os parâmetros ou colunas de saída de suporte da classe não.  
  
 `TRowset`  
 O tipo de classe do conjunto de linhas \(como `CArrayRowset` ou `CNoRowset`\) que você deseja usar o comando.  O padrão é `CRowset`.  
  
 `TMultiple`  
 Para usar comando OLE DB que pode retornar vários resultados, especifique [CMultipleResults](../../data/oledb/cmultipleresults-class.md).  Se não, use [CNoMultipleResults](../../data/oledb/cnomultipleresults-class.md).  Para obter detalhes, consulte [IMultipleResults](https://msdn.microsoft.com/en-us/library/ms721289.aspx).  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Fechar](../Topic/CCommand::Close.md)|Fecha o comando atual.|  
|[GetNextResult](../Topic/CCommand::GetNextResult.md)|Busca o próximo resultado ao usar vários conjuntos de resultados.|  
|[Abrir](../../data/oledb/ccommand-open.md)|Executa e associa o comando.|  
  
### Métodos herdados  
  
|||  
|-|-|  
|[Criar](../../data/oledb/ccommand-create.md)|Cria um novo comando para a sessão especificada, então define o texto do comando.|  
|[CreateCommand](../Topic/CCommand::CreateCommand.md)|Cria um novo comando.|  
|[GetParameterInfo](../Topic/CCommand::GetParameterInfo.md)|Obtém uma lista dos parâmetros de comando, dos nomes, e seus tipos.|  
|[Prepare](../../data/oledb/ccommand-prepare.md)|Valida e otimiza o comando atual.|  
|[ReleaseCommand](../Topic/CCommand::ReleaseCommand.md)|Libera o acessador de parâmetro se necessário, a seguir libera o comando.|  
|[SetParameterInfo](../../data/oledb/ccommand-setparameterinfo.md)|Especifica o tipo nativo de cada parâmetro de comando.|  
|[Unprepare](../../data/oledb/ccommand-unprepare.md)|Descarta o plano de execução real do comando.|  
  
## Comentários  
 Use essa classe quando você precisar executar uma operação de parâmetros com base ou executar um comando.  Se você precisar de simplesmente abrir um conjunto de linhas simples, use [CTable](../../data/oledb/ctable-class.md) em vez disso.  
  
 A classe do acessador que você está usando determina o método de associar parâmetros e dados.  
  
 Observe que você não pode usar procedimentos armazenados com o provedor OLE DB para Jet porque esse provedor não oferecer suporte a procedimentos armazenados \(somente as constantes são permitidas em cadeias de caracteres da consulta\).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)