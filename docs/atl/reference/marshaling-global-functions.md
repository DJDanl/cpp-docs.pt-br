---
title: Funções globais de empacotamento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlFreeMarshalStream
- atlbase/ATL::AtlMarshalPtrInProc
- atlbase/ATL::AtlUnmarshalPtr
dev_langs:
- C++
ms.assetid: 877100b5-6ad9-44c5-a2e0-09414f1720d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6d93839002ce5136d735e4740388109e855561fb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="marshaling-global-functions"></a>Marshaling funções globais
Essas funções fornecem suporte para empacotamento e a conversão de dados de marshaling em ponteiros de interface.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AtlFreeMarshalStream](#atlfreemarshalstream)|Libera o marshaling de dados e o `IStream` ponteiro.|  
|[AtlMarshalPtrInProc](#atlmarshalptrinproc)|Cria um novo objeto de fluxo e controla o ponteiro de interface especificado.|  
|[AtlUnmarshalPtr](#atlunmarshalptr)|Converte o marshaling de dados do fluxo em um ponteiro de interface.|  

## <a name="requirements"></a>Requisitos:
**Cabeçalho:** atlbase
  
##  <a name="atlfreemarshalstream"></a>  AtlFreeMarshalStream  
 Libera os dados de marshaling no fluxo e depois libera o ponteiro de fluxo.  

```
HRESULT AtlFreeMarshalStream(IStream* pStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 [in] Um ponteiro para o `IStream` interface no fluxo usado para a realização de marshaling.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [AtlMarshalPtrInProc](#atlmarshalptrinproc).  
  
##  <a name="atlmarshalptrinproc"></a>  AtlMarshalPtrInProc  
 Cria um novo objeto de fluxo, grava o CLSID do proxy no fluxo e realiza o marshaling do ponteiro de interface especificado gravando os dados necessários para inicializar o proxy no fluxo.  
  
```
HRESULT AtlMarshalPtrInProc(
    IUnknown* pUnk,
    const IID& iid,
    IStream** ppStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Um ponteiro para a interface para ser empacotado.  
  
 `iid`  
 [in] O GUID da interface que está sendo empacotado.  
  
 `ppStream`  
 [out] Um ponteiro para o `IStream` interface no novo objeto de fluxo usado para a realização de marshaling.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 O **MSHLFLAGS_TABLESTRONG** sinalizador é definido para o ponteiro pode ser empacotado para vários fluxos. O ponteiro pode também ser desempacotado várias vezes.  
  
 Se falhar de empacotamento, o ponteiro de fluxo é liberado.  
  
 `AtlMarshalPtrInProc` só pode ser usado em um ponteiro para um objeto em processo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#50](../../atl/codesnippet/cpp/marshaling-global-functions_1.cpp)]  
  
##  <a name="atlunmarshalptr"></a>  AtlUnmarshalPtr  
 Converte os dados de marshaling do fluxo em um ponteiro de interface que pode ser usado pelo cliente.  
   
```
HRESULT AtlUnmarshalPtr(
    IStream* pStream,
    const IID& iid,
    IUnknown** ppUnk);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 [in] Um ponteiro para o fluxo que está sendo desempacotado.  
  
 `iid`  
 [in] O GUID da interface que está sendo desempacotada.  
  
 `ppUnk`  
 [out] Um ponteiro para a interface desempacotada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [AtlMarshalPtrInProc](#atlmarshalptrinproc).  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)
