---
title: "CDBPropSet::AddProperty | Microsoft Docs"
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
  - "CDBPropSet::AddProperty"
  - "CDBPropSet.AddProperty"
  - "AddProperty"
  - "ATL::CDBPropSet::AddProperty"
  - "ATL.CDBPropSet.AddProperty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AddProperty"
ms.assetid: dc9539d3-1ee4-40f3-9281-2068e6d65e93
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDBPropSet::AddProperty
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Adiciona uma propriedade ao conjunto de propriedades.  
  
## Sintaxe  
  
```  
  
      bool AddProperty(   
   DWORD dwPropertyID,   
   const VARIANT& var,   
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
) throw( );  
bool AddProperty(  
   DWORD dwPropertyID,  
   LPCSTR szValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
) throw( );  
bool AddProperty(  
   DWORD dwPropertyID,  
   LPCWSTR szValue,   
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
) throw( );  
bool AddProperty(  
   DWORD dwPropertyID,  
   bool bValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
) throw( );  
bool AddProperty(  
   DWORD dwPropertyID,  
   BYTE bValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
);  
bool AddProperty(  
   DWORD dwPropertyID,  
   short nValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
);  
bool AddProperty(  
   DWORD dwPropertyID,  
   long nValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
);  
bool AddProperty(  
   DWORD dwPropertyID,  
   float fltValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
);  
bool AddProperty(  
   DWORD dwPropertyID,  
   double dblValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
) throw( );  
bool AddProperty(  
   DWORD dwPropertyID,  
   CY cyValue,  
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED    
) throw( );  
```  
  
#### Parâmetros  
 *dwPropertyID*  
 \[in\] A ID da propriedade a ser adicionada.  Usado para inicializar **dwPropertyID** da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
 `var`  
 \[in\] a variante da usada para inicializar o valor da propriedade da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
 `szValue`  
 \[in\] a cadeia de caracteres da usada para inicializar o valor da propriedade da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
 `bValue`  
 \[in\] A **BYTE** ou valor booliano usado para inicializar o valor da propriedade da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
 `nValue`  
 \[in\] um valor inteiro usado para inicializar o valor da propriedade da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
 *fltValue*  
 \[in\] um valor de ponto flutuante da usado para inicializar o valor da propriedade da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
 `dblValue`  
 \[in\] um valor de ponto flutuante de precisão dupla de usado para inicializar o valor da propriedade da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
 `cyValue`  
 \[in\] um valor de moeda CY usado para inicializar o valor da propriedade da estrutura de `DBPROP` adicionado ao conjunto de propriedades.  
  
## Valor de retorno  
 **true** se a propriedade foi adicionada com êxito.  Caso contrário, **false**.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDBPropSet](../Topic/CDBPropSet%20Class.md)   
 [DBPROP Structure](https://msdn.microsoft.com/en-us/library/ms717970.aspx)