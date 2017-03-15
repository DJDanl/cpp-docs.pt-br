---
title: "CDBErrorInfo::GetAllErrorInfo | Microsoft Docs"
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
  - "ATL.CDBErrorInfo.GetAllErrorInfo"
  - "CDBErrorInfo::GetAllErrorInfo"
  - "ATL::CDBErrorInfo::GetAllErrorInfo"
  - "GetAllErrorInfo"
  - "CDBErrorInfo.GetAllErrorInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetAllErrorInfo"
ms.assetid: 630049fa-d296-497a-bbf6-f5d3d71d271d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDBErrorInfo::GetAllErrorInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna todos os tipos de informações de erro contidos em um registro de erro.  
  
## Sintaxe  
  
```  
  
      HRESULT GetAllErrorInfo(  
   ULONG ulRecordNum,  
   LCID lcid,  
   BSTR* pbstrDescription,  
   BSTR* pbstrSource = NULL,  
   GUID* pguid = NULL,  
   DWORD* pdwHelpContext = NULL,  
   BSTR* pbstrHelpFile = NULL  
) const throw( );  
```  
  
#### Parâmetros  
 *ulRecordNum*  
 \[in\] o número de base zero do registro para o qual as informações de erro.  
  
 `lcid`  
 \[in\] a ID de localidade para o qual as informações de erro é retornada.  
  
 `pbstrDescription`  
 \[out\] ponteiro da uma descrição de texto do erro ou NULL se a localidade não tem suporte.  Consulte Comentários.  
  
 `pbstrSource`  
 \[out\] de ponteiro para uma cadeia de caracteres que contém o nome do componente que gerou o erro.  
  
 `pguid`  
 \[out\] ponteiro da GUID da interface que definiu o erro.  
  
 *pdwHelpContext*  
 \[out\] ponteiro da ID de contexto da ajuda para o erro.  
  
 *pbstrHelpFile*  
 \[out\] de ponteiro para uma cadeia de caracteres que contém o caminho para o arquivo de ajuda que descreve o erro.  
  
## Valor de retorno  
 se`S_OK` com êxito.  Consulte [IErrorRecords::GetErrorInfo](https://msdn.microsoft.com/en-us/library/ms711230.aspx)*na referência do programador de OLE DB* para outros valores de retorno.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Comentários  
 O valor de saída de `pbstrDescription` é obtido chamando IErrorInfo::GetDescription internamente, que define o valor COMO NULL se a localidade não tem suporte, ou se ambas as condições forem verdadeiras:  
  
1.  o valor de `lcid` não é E.U EUA e.  
  
2.  o valor de `lcid` não é igual ao valor retornado por GetUserDefaultLCID.  
  
## Consulte também  
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)