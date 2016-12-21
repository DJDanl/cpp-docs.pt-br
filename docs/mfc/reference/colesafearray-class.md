---
title: "Classe de COleSafeArray | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "COleSafeArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "matrizes [C++], seguro"
  - "Classe de COleSafeArray"
  - "ODBC, matrizes de segurança"
  - "matrizes de segurança"
ms.assetid: f45a5224-5f48-40ec-9ddd-287ef9740150
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleSafeArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe para trabalhar com matrizes do tipo e de dimensão arbitrários.  
  
## Sintaxe  
  
```  
class COleSafeArray : public tagVARIANT  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleSafeArray::COleSafeArray](../Topic/COleSafeArray::COleSafeArray.md)|Constrói um objeto de `COleSafeArray` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleSafeArray::AccessData](../Topic/COleSafeArray::AccessData.md)|Recupera um ponteiro para os dados de matriz.|  
|[COleSafeArray::AllocData](../Topic/COleSafeArray::AllocData.md)|Aloca memória para a matriz.|  
|[COleSafeArray::AllocDescriptor](../Topic/COleSafeArray::AllocDescriptor.md)|Aloca memória para o descritor de matriz seguro.|  
|[COleSafeArray::Attach](../Topic/COleSafeArray::Attach.md)|Fornece o controle da matriz existente de **VARIANT** ao objeto de `COleSafeArray` .|  
|[COleSafeArray::Clear](../Topic/COleSafeArray::Clear.md)|Libera todos os dados em **VARIANT**subjacente.|  
|[COleSafeArray::Copy](../Topic/COleSafeArray::Copy.md)|Cria uma cópia de uma matriz existente.|  
|[COleSafeArray::Create](../Topic/COleSafeArray::Create.md)|Cria uma matriz segura.|  
|[COleSafeArray::CreateOneDim](../Topic/COleSafeArray::CreateOneDim.md)|Cria um objeto unidimensional de `COleSafeArray` .|  
|[COleSafeArray::Destroy](../Topic/COleSafeArray::Destroy.md)|For uma matriz existente.|  
|[COleSafeArray::DestroyData](../Topic/COleSafeArray::DestroyData.md)|Destrói dados em uma matriz segura.|  
|[COleSafeArray::DestroyDescriptor](../Topic/COleSafeArray::DestroyDescriptor.md)|For um descritor de matriz segura.|  
|[COleSafeArray::Detach](../Topic/COleSafeArray::Detach.md)|Dispara a matriz de **VARIANT** do objeto de `COleSafeArray` \(para que os dados não serão liberados.\)|  
|[COleSafeArray::GetByteArray](../Topic/COleSafeArray::GetByteArray.md)|Copia o conteúdo da matriz segura em [CByteArray](../../mfc/reference/cbytearray-class.md).|  
|[COleSafeArray::GetDim](../Topic/COleSafeArray::GetDim.md)|Retorna o número de dimensões na matriz.|  
|[COleSafeArray::GetElement](../Topic/COleSafeArray::GetElement.md)|Recupera um elemento de matriz segura.|  
|[COleSafeArray::GetElemSize](../Topic/COleSafeArray::GetElemSize.md)|Retorna o tamanho, em bytes, de um elemento em uma matriz segura.|  
|[COleSafeArray::GetLBound](../Topic/COleSafeArray::GetLBound.md)|Retorna o limite inferior para qualquer dimensão da matriz segura.|  
|[COleSafeArray::GetOneDimSize](../Topic/COleSafeArray::GetOneDimSize.md)|Retorna o número de elementos no objeto unidimensional de `COleSafeArray` .|  
|[COleSafeArray::GetUBound](../Topic/COleSafeArray::GetUBound.md)|Retorna o limite superior para qualquer dimensão da matriz segura.|  
|[COleSafeArray::Lock](../Topic/COleSafeArray::Lock.md)|Sai a contagem de bloqueio de uma matriz e coloca um ponteiro para os dados de matriz no descritor de matriz.|  
|[COleSafeArray::PtrOfIndex](../Topic/COleSafeArray::PtrOfIndex.md)|Retorna um ponteiro para o elemento indexado.|  
|[COleSafeArray::PutElement](../Topic/COleSafeArray::PutElement.md)|Atribui um único elemento na matriz.|  
|[COleSafeArray::Redim](../Topic/COleSafeArray::Redim.md)|Altera o limite \(mais à direita\) o menos segura significativo de uma matriz.|  
|[COleSafeArray::ResizeOneDim](../Topic/COleSafeArray::ResizeOneDim.md)|Altera o número de elementos em um objeto unidimensional de `COleSafeArray` .|  
|[COleSafeArray::UnaccessData](../Topic/COleSafeArray::UnaccessData.md)|Diminui a contagem de bloqueio de uma matriz e invalida o ponteiro recuperados por `AccessData`.|  
|[COleSafeArray::Unlock](../Topic/COleSafeArray::Unlock.md)|Diminui a contagem de bloqueio de uma matriz para que ele possa ser liberada ou redimensionado.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleSafeArray::operator LPCVARIANT](../Topic/COleSafeArray::operator%20LPCVARIANT.md)|Acessa a estrutura subjacente de **VARIANT** do objeto de `COleSafeArray` .|  
|[COleSafeArray::operator LPVARIANT](../Topic/COleSafeArray::operator%20LPVARIANT.md)|Acessa a estrutura subjacente de **VARIANT** do objeto de `COleSafeArray` .|  
|[COleSafeArray::operator \=](../Topic/COleSafeArray::operator%20=.md)|Valores das cópias em um objeto de `COleSafeArray` \(**SAFEARRAY**, **VARIANT**, `COleVariant`, ou matriz de `COleSafeArray` \).|  
|[\=\= De COleSafeArray::operator](../Topic/COleSafeArray::operator%20==.md)|Compara duas matrizes variantes \(**SAFEARRAY**, **VARIANT**, `COleVariant`, ou arrays de `COleSafeArray` \).|  
|[COleSafeArray::operator \<\<](../Topic/COleSafeArray::operator%20%3C%3C.md)|Saída que o conteúdo de `COleSafeArray` objeto para o contexto do despejo.|  
  
## Comentários  
 `COleSafeArray` deriva da estrutura de **VARIANT** OLE.  As funções de membro do OLE **SAFEARRAY** estão disponíveis através de `COleSafeArray`, bem como um conjunto de funções de membro especificamente projetadas para arrays unidimensionais de bytes.  
  
## Hierarquia de herança  
 `tagVARIANT`  
  
 `COleSafeArray`  
  
## Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleVariant](../../mfc/reference/colevariant-class.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)   
 [Classe de CDatabase](../../mfc/reference/cdatabase-class.md)