---
title: CDBPropSet::AddProperty | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDBPropSet::AddProperty
- CDBPropSet.AddProperty
- AddProperty
- ATL::CDBPropSet::AddProperty
- ATL.CDBPropSet.AddProperty
dev_langs:
- C++
helpviewer_keywords:
- AddProperty method
ms.assetid: dc9539d3-1ee4-40f3-9281-2068e6d65e93
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7daa1146bbd4e288d20c59f7f1fff8c4bcbbb455
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdbpropsetaddproperty"></a>CDBPropSet::AddProperty
Adiciona uma propriedade para o conjunto de propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```
bool AddProperty(DWORD dwPropertyID,   
   constVARIANT& var,   
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   LPCSTR szValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   LPCWSTR szValue,DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   bool bValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   BYTE bValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   short nValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   long nValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   float fltValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   double dblValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   CY cyValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *dwPropertyID*  
 [in] A ID da propriedade a ser adicionada. Usado para inicializar o **dwPropertyID** do `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
 `var`  
 [in] Uma variante usada para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
 `szValue`  
 [in] Uma cadeia de caracteres usada para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
 `bValue`  
 [in] Um **bytes** ou usado para inicializar o valor da propriedade de valor booliano de `DBPROP` estrutura adicionada ao conjunto de propriedades.  
  
 `nValue`  
 [in] Um valor inteiro usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
 *fltValue*  
 [in] Um valor de ponto flutuante usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
 `dblValue`  
 [in] Um valor de ponto flutuante de precisão dupla usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
 `cyValue`  
 [in] Um valor de moeda CY usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
## <a name="return-value"></a>Valor de retorno  
 **True** se a propriedade foi adicionada com êxito. Caso contrário, **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBPropSet](../../data/oledb/cdbpropset-class.md)   
 [Estrutura DBPROP](https://msdn.microsoft.com/en-us/library/ms717970.aspx)