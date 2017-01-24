---
title: "CRowset::FindNextRow | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL.CRowset.FindNextRow"
  - "CRowset<TAccessor>.FindNextRow"
  - "ATL::CRowset::FindNextRow"
  - "CRowset::FindNextRow"
  - "CRowset<TAccessor>::FindNextRow"
  - "CRowset.FindNextRow"
  - "ATL.CRowset<TAccessor>.FindNextRow"
  - "ATL::CRowset<TAccessor>::FindNextRow"
  - "FindNextRow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método FindNextRow"
ms.assetid: 36484df9-3625-4f15-bf69-db73a8d91c55
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::FindNextRow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Localiza a próxima linha de correspondência depois que o indicador especificado.  
  
## Sintaxe  
  
```  
  
      HRESULT FindNextRow(   
   DBCOMPAREOP op,   
   BYTE* pData,   
   DBTYPE wType,   
   DBLENGTH nLength,   
   BYTE bPrecision,   
   BYTE bScale,   
   BOOL bSkipCurrent = TRUE,   
   CBookmarkBase* pBookmark = NULL    
) throw( );  
```  
  
#### Parâmetros  
 `op`  
 \[in\] a operação a ser usado na comparação de valores de linha.  Para obter os valores, consulte [IRowsetFind::FindNextRow](https://msdn.microsoft.com/en-us/library/ms723091.aspx).  
  
 `pData`  
 \[in\] de ponteiro para o valor a ser correspondido.  
  
 `wType`  
 \[in\] indica o tipo de dados da parte do valor do buffer.  Para obter informações sobre os indicadores de tipo, consulte [Tipos de dados](https://msdn.microsoft.com/en-us/library/ms723969.aspx)*na referência do programador do* OLE DB em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `nLength`  
 \[in\] o tamanho, em bytes, da estrutura de dados do consumidor alocada para o valor de dados.  Para obter detalhes, consulte a descrição de **cbMaxLen** em [Estruturas DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx)*na referência do programador de OLE DB.*  
  
 `bPrecision`  
 \[in\] a precisão máxima utilizada para obter dados.  Usado somente se `wType` é `DBTYPE_NUMERIC`.  Para obter mais informações, consulte [Conversões que envolvem DBTYPE\_NUMERIC ou DBTYPE\_DECIMAL](https://msdn.microsoft.com/en-us/library/ms719714.aspx)*na referência do programador de OLE DB*.  
  
 `bScale`  
 \[in\] a escala usada para obter dados.  Usado somente se `wType` é `DBTYPE_NUMERIC` ou **DBTYPE\_DECIMAL**.  Para obter mais informações, consulte [Conversões que envolvem DBTYPE\_NUMERIC ou DBTYPE\_DECIMAL](https://msdn.microsoft.com/en-us/library/ms719714.aspx)*na referência do programador de OLE DB*.  
  
 *bSkipCurrent*  
 \[in\] o número de linhas indicador no qual iniciar a pesquisa.  
  
 `pBookmark`  
 \[in\] o medidor para a posição na qual iniciar a pesquisa.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método exige a interface opcional **IRowsetFind**, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetFind** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
 Para obter informações sobre como usar o marca um endereço da Internet\) dos consumidores, consulte [Usando indicadores](../../data/oledb/using-bookmarks.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [DBBINDING Structures](https://msdn.microsoft.com/en-us/library/ms716845.aspx)