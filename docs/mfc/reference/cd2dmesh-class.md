---
title: Classe CD2DMesh | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CD2DMesh
- AFXRENDERTARGET/CD2DMesh
- AFXRENDERTARGET/CD2DMesh::CD2DMesh
- AFXRENDERTARGET/CD2DMesh::Attach
- AFXRENDERTARGET/CD2DMesh::Create
- AFXRENDERTARGET/CD2DMesh::Destroy
- AFXRENDERTARGET/CD2DMesh::Detach
- AFXRENDERTARGET/CD2DMesh::Get
- AFXRENDERTARGET/CD2DMesh::IsValid
- AFXRENDERTARGET/CD2DMesh::Open
- AFXRENDERTARGET/CD2DMesh::m_pMesh
dev_langs:
- C++
helpviewer_keywords:
- CD2DMesh [MFC], CD2DMesh
- CD2DMesh [MFC], Attach
- CD2DMesh [MFC], Create
- CD2DMesh [MFC], Destroy
- CD2DMesh [MFC], Detach
- CD2DMesh [MFC], Get
- CD2DMesh [MFC], IsValid
- CD2DMesh [MFC], Open
- CD2DMesh [MFC], m_pMesh
ms.assetid: 11a2c78a-1367-40e8-a34f-44aa0509a4c9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ce3ad5cfa7df335b5633dffbdd221bf59f01bb29
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cd2dmesh-class"></a>Classe CD2DMesh
Um wrapper para ID2D1Mesh.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CD2DMesh : public CD2DResource;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DMesh::CD2DMesh](#cd2dmesh)|Constrói um objeto CD2DMesh.|  
|[CD2DMesh:: ~ CD2DMesh](#_dtorcd2dmesh)|O destruidor. Chamado quando um objeto de malha D2D está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DMesh::Attach](#attach)|Conexões existentes de interface de recurso para o objeto|  
|[CD2DMesh::Create](#create)|Cria um CD2DMesh. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|  
|[CD2DMesh::Destroy](#destroy)|Destrói um objeto CD2DMesh. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|  
|[CD2DMesh::Detach](#detach)|Desanexa a interface do recurso do objeto|  
|[CD2DMesh::Get](#get)|Interface de ID2D1Mesh retorna|  
|[CD2DMesh::IsValid](#isvalid)|Verifica a validade do recurso (substitui [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|  
|[CD2DMesh::Open](#open)|Abre a malha de população.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DMesh::Operator ID2D1Mesh *](#operator_id2d1mesh_star)|Interface de ID2D1Mesh retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CD2DMesh::m_pMesh](#m_pmesh)|Um ponteiro para um ID2D1Mesh.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CD2DResource](../../mfc/reference/cd2dresource-class.md)  
  
 `CD2DMesh`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="_dtorcd2dmesh"></a>  CD2DMesh:: ~ CD2DMesh  
 O destruidor. Chamado quando um objeto de malha D2D está sendo destruído.  
  
```  
virtual ~CD2DMesh();
```  
  
##  <a name="attach"></a>  CD2DMesh::Attach  
 Conexões existentes de interface de recurso para o objeto  
  
```  
void Attach(ID2D1Mesh* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Interface de recurso existente. Não pode ser NULL  
  
##  <a name="cd2dmesh"></a>  CD2DMesh::CD2DMesh  
 Constrói um objeto CD2DMesh.  
  
```  
CD2DMesh(
    CRenderTarget* pParentTarget,  
    BOOL bAutoDestroy = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentTarget`  
 Um ponteiro para o destino de renderização.  
  
 `bAutoDestroy`  
 Indica se o objeto será destruído pelo proprietário (pParentTarget).  
  
##  <a name="create"></a>  CD2DMesh::Create  
 Cria um CD2DMesh.  
  
```  
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Um ponteiro para o destino de renderização.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="destroy"></a>  CD2DMesh::Destroy  
 Destrói um objeto CD2DMesh.  
  
```  
virtual void Destroy();
```  
  
##  <a name="detach"></a>  CD2DMesh::Detach  
 Desanexa a interface do recurso do objeto  
  
```  
ID2D1Mesh* Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a interface de recursos separado.  
  
##  <a name="get"></a>  CD2DMesh::Get  
 Interface de ID2D1Mesh retorna  
  
```  
ID2D1Mesh* Get();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1Mesh ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="isvalid"></a>  CD2DMesh::IsValid  
 Verificações de validade de recurso  
  
```  
virtual BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="m_pmesh"></a>  CD2DMesh::m_pMesh  
 Um ponteiro para um ID2D1Mesh.  
  
```  
ID2D1Mesh* m_pMesh;  
```  
  
##  <a name="open"></a>  CD2DMesh::Open  
 Abre a malha de população.  
  
```  
ID2D1TessellationSink* Open();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um ID2D1TessellationSink que é usado para popular a malha.  
  
##  <a name="operator_id2d1mesh_star"></a>  CD2DMesh::Operator ID2D1Mesh *  
 Interface de ID2D1Mesh retorna  
  
```  
operator ID2D1Mesh*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1Mesh ou NULL se o objeto ainda não foi inicializado.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
